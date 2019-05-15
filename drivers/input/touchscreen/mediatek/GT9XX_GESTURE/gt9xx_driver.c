/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2012. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*
 * Version: V2.0
 * Release Date: 2013/08/28
 * Contact: andrew@goodix.com, meta@goodix.com
 * Revision Record:
 *      V1.4:
 *          1. New Heartbeat/ESD-protect Mechanism(external watchdog)
 *          2. doze mode, sliding wakeup
 *          3. config length verification & 3 more config groups(GT9 Sensor_ID: 0 ~ 5)
 *          4. charger status switch
 *                  By Meta, 2013/03/11
 *      V1.6:
 *          1. pen/stylus support
 *          2. slide wakeup, new esd optimization
 *                  By Meta, 2013/04/18
 *      V1.8:
 *          1. read double check & fixed config support
 *          2. other optimizations
 *                  By Meta, 2013/06/08
 *      V2.0:
 *          1. compatible with GT9XXF
 *          2. I2C DMA support
 *                  By Meta, 2013/08/28
 *      V2.2:
 *          1. update gt9xx_config to compatible with Linux 3.10
 *          2. gesture wakeup
 *          3. pen separate input device, active-pen button support
 *          4. coordinates & keys optimization
 *          5. no longer support GT915S
 *                  By Meta, 2014/01/14
 */

#include "tpd.h"
#include "tpd_gt9xx_common.h"
#if GTP_SUPPORT_I2C_DMA
#include <linux/dma-mapping.h>
#endif
#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/suspend.h>
#include "gt9xx_config.h"

extern unsigned int DISP_GetScreenHeight(void);
extern unsigned int DISP_GetScreenWidth(void);
extern struct tpd_device *tpd;
static int tpd_flag = 0;
int gtp_tpd_halt = 0;
static struct task_struct *thread = NULL;
static DECLARE_WAIT_QUEUE_HEAD(waiter);

static int hall_resume=1;

unsigned int touch_irq = 0;

#define TPD_CONFIG_REG_BASE     0x8047

#if (GTP_HAVE_TOUCH_KEY && TPD_HAVE_BUTTON)
#error GTP_HAVE_TOUCH_KEY and TPD_HAVE_BUTTON are mutually exclusive.
#endif

#if GTP_HAVE_TOUCH_KEY
const u16 gt9x_touch_key_array[] = GTP_KEY_TAB;
#endif

static int ONLY_ONCE=0;
#if GTP_GESTURE_WAKEUP
typedef enum
{
    DOZE_DISABLED = 0,
    DOZE_ENABLED = 1,
    DOZE_WAKEUP = 2,
}DOZE_T;
static DOZE_T doze_status = DOZE_DISABLED;
static s8 gtp_enter_doze(struct i2c_client *client);

#endif
#if (defined(TPD_WARP_START) && defined(TPD_WARP_END))
static int tpd_wb_start_local[TPD_WARP_CNT] = TPD_WARP_START;
static int tpd_wb_end_local[TPD_WARP_CNT]   = TPD_WARP_END;
#endif

#if (defined(TPD_HAVE_CALIBRATION) && !defined(TPD_CUSTOM_CALIBRATION))
//static int tpd_calmat_local[8]     = TPD_CALIBRATION_MATRIX;
static int tpd_def_calmat_local[8] = TPD_CALIBRATION_MATRIX;
#endif

#if GTP_SUPPORT_I2C_DMA
static s32 i2c_dma_write(struct i2c_client *client, u16 addr, u8 *txbuf, s32 len);
static s32 i2c_dma_read(struct i2c_client *client, u16 addr, u8 *rxbuf, s32 len);

static u8 *gpDMABuf_va = NULL;
static dma_addr_t gpDMABuf_pa = 0;
#endif
void gtp_reset_guitar(struct i2c_client *client, s32 ms);
static irqreturn_t tpd_eint_interrupt_handler(int irq, void *desc);
static int touch_event_handler(void *unused);
static int tpd_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int tpd_i2c_detect(struct i2c_client *client, struct i2c_board_info *info);
static int tpd_i2c_remove(struct i2c_client *client);
s32 gtp_i2c_read_dbl_check(struct i2c_client *client, u16 addr, u8 *rxbuf, int len);

#if GTP_GESTURE_WAKEUP
extern int g_gesture_support;
extern int g_gesture_flag;
extern u8 g_single_gesture_flag[31];

extern char *agold_tpd_get_gesture(char *buf_from);
#endif

#if GTP_CREATE_WR_NODE
extern s32 init_wr_node(struct i2c_client *);
extern void uninit_wr_node(void);
#endif

//agold shipeilong add start
static int tpd_power_enable(int enable);
//agold shipeilond end

struct i2c_client *i2c_client_point = NULL;
static const struct i2c_device_id tpd_i2c_id[] = {{"gt9xx", 0}, {}};
static unsigned short force[] = {0, 0xBA, I2C_CLIENT_END, I2C_CLIENT_END};
static const unsigned short *const forces[] = { force, NULL };
static const struct of_device_id tpd_of_match[] = {
	{.compatible = "mediatek,cap_touch"},
	{},
};
static struct i2c_driver tpd_i2c_driver =
{
    .probe = tpd_i2c_probe,
    .remove = tpd_i2c_remove,
    .detect = tpd_i2c_detect,
	.driver.name = "gt9xx",
    .driver = {
		   .name = "gt9xx",
		   .of_match_table = tpd_of_match,
		   },
    .id_table = tpd_i2c_id,
    .address_list = (const unsigned short *) forces,
};


static u8 config[GTP_CONFIG_MAX_LENGTH + GTP_ADDR_LENGTH]
    = {GTP_REG_CONFIG_DATA >> 8, GTP_REG_CONFIG_DATA & 0xff};

#pragma pack(1)
typedef struct
{
    u16 pid;                 //product id   //
    u16 vid;                 //version id   //
} st_tpd_info;
#pragma pack()

st_tpd_info tpd_info;
u8 int_type = 0;
u32 abs_x_max = 0;
u32 abs_y_max = 0;
u8 gtp_rawdiff_mode = 0;
u8 cfg_len = 0;
u8 grp_cfg_version = 0;
u8 fixed_config = 0;
u8 pnl_init_error = 0;

/* proc file system */
s32 i2c_read_bytes(struct i2c_client *client, u16 addr, u8 *rxbuf, int len);
s32 i2c_write_bytes(struct i2c_client *client, u16 addr, u8 *txbuf, int len);

static ssize_t gt91xx_config_read_proc(struct file *, char __user *, size_t, loff_t *);
static ssize_t gt91xx_config_write_proc(struct file *, const char __user *, size_t, loff_t *);

static struct proc_dir_entry *gt91xx_config_proc = NULL;
static const struct file_operations config_proc_ops = {
    .owner = THIS_MODULE,
    .read = gt91xx_config_read_proc,
    .write = gt91xx_config_write_proc,
};

//extern u8 load_fw_process;

static int tpd_i2c_detect(struct i2c_client *client, struct i2c_board_info *info)
{
    strcpy(info->type, "mtk-tpd");
    return 0;
}


static ssize_t gt91xx_config_read_proc(struct file *file, char __user *page, size_t size, loff_t *ppos)
{
    char *ptr = page;
    char temp_data[GTP_CONFIG_MAX_LENGTH + 2] = {0};
    int i;

    if (*ppos)  // CMD call again
    {
        return 0;
    }

    ptr += sprintf(ptr, "==== GT9XX config init value====\n");

    for (i = 0 ; i < GTP_CONFIG_MAX_LENGTH ; i++)
    {
        ptr += sprintf(ptr, "0x%02X ", config[i + 2]);

        if (i % 8 == 7)
            ptr += sprintf(ptr, "\n");
    }

    ptr += sprintf(ptr, "\n");

    ptr += sprintf(ptr, "==== GT9XX config real value====\n");
    i2c_read_bytes(i2c_client_point, GTP_REG_CONFIG_DATA, temp_data, GTP_CONFIG_MAX_LENGTH);

    for (i = 0 ; i < GTP_CONFIG_MAX_LENGTH ; i++)
    {
        ptr += sprintf(ptr, "0x%02X ", temp_data[i]);

        if (i % 8 == 7)
            ptr += sprintf(ptr, "\n");
    }
    *ppos += ptr - page;
    return (ptr - page);
}

static ssize_t gt91xx_config_write_proc(struct file *filp, const char __user *buffer, size_t count, loff_t *off)
{
    s32 ret = 0;

    GTP_DEBUG("write count %zu\n", count);

    if (count > GTP_CONFIG_MAX_LENGTH)
    {
        GTP_ERROR("size not match [%d:%zu]\n", GTP_CONFIG_MAX_LENGTH, count);
        return -EFAULT;
    }

    if (copy_from_user(&config[2], buffer, count))
    {
        GTP_ERROR("copy from user fail\n");
        return -EFAULT;
    }

    abs_x_max = (config[RESOLUTION_LOC + 1] << 8) + config[RESOLUTION_LOC];
    abs_y_max = (config[RESOLUTION_LOC + 3] << 8) + config[RESOLUTION_LOC + 2];
    int_type = (config[TRIGGER_LOC]) & 0x03;

    if (ret < 0)
    {
        GTP_ERROR("send config failed.");
    }

    return count;
}


s32 _do_i2c_read(struct i2c_client *client, struct i2c_msg *msgs, u16 addr, u8 *buffer, s32 len)
{
	s32 ret = -1;
	s32 pos = 0;
	s32 data_length = len;
	s32 transfer_length = 0;
	u8 *data = NULL;
	u16 address = addr;

	data =
	    kmalloc(IIC_MAX_TRANSFER_SIZE <
			   (len + GTP_ADDR_LENGTH) ? IIC_MAX_TRANSFER_SIZE : (len + GTP_ADDR_LENGTH), GFP_KERNEL);
	if (data == NULL)
		return ERROR_MEM;
	msgs[1].buf = data;

	while (pos != data_length) {
		if ((data_length - pos) > IIC_MAX_TRANSFER_SIZE)
			transfer_length = IIC_MAX_TRANSFER_SIZE;
		else
			transfer_length = data_length - pos;
		msgs[0].buf[0] = (address >> 8) & 0xFF;
		msgs[0].buf[1] = address & 0xFF;
		msgs[1].len = transfer_length;

		ret = i2c_transfer(client->adapter, msgs, 2);
		if (ret != 2) {
			GTP_INFO("I2c Transfer error! (%d)", ret);
			kfree(data);
			return ERROR_IIC;
		}
		memcpy(&buffer[pos], msgs[1].buf, transfer_length);
		pos += transfer_length;
		address += transfer_length;
	}

	kfree(data);
	return 0;
}

s32 _do_i2c_write(struct i2c_client *client, struct i2c_msg *msg, u16 addr, u8 *buffer, s32 len)
{
	s32 ret = -1;
	s32 pos = 0;
	s32 data_length = len;
	s32 transfer_length = 0;
	u8 *data = NULL;
	u16 address = addr;

	data =
	    kmalloc(IIC_MAX_TRANSFER_SIZE <
			   (len + GTP_ADDR_LENGTH) ? IIC_MAX_TRANSFER_SIZE : (len + GTP_ADDR_LENGTH), GFP_KERNEL);
	if (data == NULL)
		return ERROR_MEM;

	msg->buf = data;

	while (pos != data_length) {
		if ((data_length - pos) > (IIC_MAX_TRANSFER_SIZE - GTP_ADDR_LENGTH))
			transfer_length = IIC_MAX_TRANSFER_SIZE - GTP_ADDR_LENGTH;
		else
			transfer_length = data_length - pos;

		msg->buf[0] = (address >> 8) & 0xFF;
		msg->buf[1] = address & 0xFF;
		msg->len = transfer_length + GTP_ADDR_LENGTH;
		memcpy(&msg->buf[GTP_ADDR_LENGTH], &buffer[pos], transfer_length);

		ret = i2c_transfer(client->adapter, msg, 1);
		if (ret != 1) {
			GTP_INFO("I2c Transfer error! (%d)", ret);
			kfree(data);
			return ERROR_IIC;
		}
		pos += transfer_length;
		address += transfer_length;
	}

	kfree(data);
	return 0;
}

#if GTP_SUPPORT_I2C_DMA
struct mutex dma_mutex;
DEFINE_MUTEX(dma_mutex);
/*
static s32 i2c_dma_read(struct i2c_client *client, u16 addr, u8 *rxbuf, s32 len)
{
    int ret;
    s32 retry = 0;
    u8 buffer[2];

    struct i2c_msg msg[2] =
    {
        {
            .addr = (client->addr & I2C_MASK_FLAG),
            .flags = 0,
            .buf = buffer,
            .len = 2,
            .timing = I2C_MASTER_CLOCK
        },
        {
            .addr = (client->addr & I2C_MASK_FLAG),
            .ext_flag = (client->ext_flag | I2C_ENEXT_FLAG | I2C_DMA_FLAG),
            .flags = I2C_M_RD,
            .buf = (u8*)gpDMABuf_pa,
            .len = len,
            .timing = I2C_MASTER_CLOCK
        },
    };

    buffer[0] = (addr >> 8) & 0xFF;
    buffer[1] = addr & 0xFF;

    if (rxbuf == NULL)
        return -1;

    //GTP_DEBUG("dma i2c read: 0x%04X, %d bytes(s)", addr, len);
    for (retry = 0; retry < 5; ++retry)
    {
        ret = i2c_transfer(client->adapter, &msg[0], 2);
        if (ret < 0)
        {
            continue;
        }
        memcpy(rxbuf, gpDMABuf_va, len);
        return 0;
    }
    GTP_ERROR("Dma I2C Read Error: 0x%04X, %d byte(s), err-code: %d", addr, len, ret);
    return ret;
}
*/

static s32 i2c_dma_write(struct i2c_client *client, u16 addr, u8 *buffer, s32 len)
{
	s32 ret = 0;
	s32 pos = 0;
	s32 transfer_length;
	u16 address = addr;

	struct i2c_msg msg = {
		.flags = !I2C_M_RD,
		.ext_flag = (client->ext_flag | I2C_ENEXT_FLAG | I2C_DMA_FLAG),
		.addr = (client->addr & I2C_MASK_FLAG),
		.timing = I2C_MASTER_CLOCK,
		.buf = (u8 *)(uintptr_t)gpDMABuf_pa,
	};

	mutex_lock(&dma_mutex);
	while (pos != len) {
		if (len - pos > (IIC_DMA_MAX_TRANSFER_SIZE - GTP_ADDR_LENGTH))
			transfer_length = IIC_DMA_MAX_TRANSFER_SIZE - GTP_ADDR_LENGTH;
		else
			transfer_length = len - pos;

		gpDMABuf_va[0] = (address >> 8) & 0xFF;
		gpDMABuf_va[1] = address & 0xFF;
		memcpy(&gpDMABuf_va[GTP_ADDR_LENGTH], &buffer[pos], transfer_length);

		msg.len = transfer_length + GTP_ADDR_LENGTH;
		if (1) {
			ret = i2c_transfer(client->adapter, &msg, 1);
			if (ret != 1) {
				GTP_INFO("I2c Transfer error! (%d)", ret);
				ret = ERROR_IIC;
				break;
			}
		} else {
			printk("[xfl]I2c dma error\n");
			ret = ERROR_IIC;
			break;
		}
		ret = 0;
		pos += transfer_length;
		address += transfer_length;
	}
	mutex_unlock(&dma_mutex);
	return ret;
}


/*
static s32 i2c_dma_write(struct i2c_client *client, u16 addr, u8 *txbuf, s32 len)
{
    int ret;
    s32 retry = 0;
    u8 *wr_buf = gpDMABuf_va;

    struct i2c_msg msg =
    {
        .addr = (client->addr & I2C_MASK_FLAG),
        .ext_flag = (client->ext_flag | I2C_ENEXT_FLAG | I2C_DMA_FLAG),
        .flags = 0,
        .buf = (u8*)gpDMABuf_pa,
        .len = 2 + len,
        .timing = I2C_MASTER_CLOCK
    };

    wr_buf[0] = (u8)((addr >> 8) & 0xFF);
    wr_buf[1] = (u8)(addr & 0xFF);

    if (txbuf == NULL)
       {
          TPD_DEBUG("whl agold txbuf==NULL");
        return -1;

        }

    //GTP_DEBUG("dma i2c write: 0x%04X, %d bytes(s)", addr, len);
    memcpy(wr_buf+2, txbuf, len);
    for (retry = 0; retry < 5; ++retry)
    {
        ret = i2c_transfer(client->adapter, &msg, 1);
        if (ret < 0)
        {
            TPD_DEBUG("whl agold retry=%d\n",retry);
            continue;

        }

        return 0;
    }
    GTP_ERROR("Dma I2C Write Error: 0x%04X, %d byte(s), err-code: %d", addr, len, ret);
    return ret;
}
*/
static s32 i2c_dma_read(struct i2c_client *client, u16 addr, u8 *buffer, s32 len)
{
	s32 ret = ERROR;
	s32 pos = 0;
	s32 transfer_length;
	u16 address = addr;
	u8 addr_buf[GTP_ADDR_LENGTH] = { 0 };

	struct i2c_msg msgs[2] = {
		{
		 .flags = 0,	/*!I2C_M_RD,*/
		 .addr = (client->addr & I2C_MASK_FLAG),
		 .timing = I2C_MASTER_CLOCK,
		 .len = GTP_ADDR_LENGTH,
		 .buf = addr_buf,
		 },
		{
		 .flags = I2C_M_RD,
		 .ext_flag = (client->ext_flag | I2C_ENEXT_FLAG | I2C_DMA_FLAG),
		 .addr = (client->addr & I2C_MASK_FLAG),
		 .timing = I2C_MASTER_CLOCK,
		 .buf = (u8 *)(uintptr_t)gpDMABuf_pa,
		},
	};
	mutex_lock(&dma_mutex);
	while (pos != len) {
		if (len - pos > IIC_DMA_MAX_TRANSFER_SIZE)
			transfer_length = IIC_DMA_MAX_TRANSFER_SIZE;
		else
			transfer_length = len - pos;

		msgs[0].buf[0] = (address >> 8) & 0xFF;
		msgs[0].buf[1] = address & 0xFF;
		msgs[1].len = transfer_length;

		ret = i2c_transfer(client->adapter, msgs, 2);
		if (ret != 2) {
			GTP_ERROR("I2C Transfer error! (%d)", ret);
			ret = ERROR_IIC;
			break;
		}
		ret = 0;
		memcpy(&buffer[pos], gpDMABuf_va, transfer_length);
		pos += transfer_length;
		address += transfer_length;
	};
	mutex_unlock(&dma_mutex);
	return ret;
}

static s32 i2c_read_bytes_dma(struct i2c_client *client, u16 addr, u8 *rxbuf, s32 len)
{
    s32 left = 0;
    s32 read_len = 0;
    u8 *rd_buf = NULL;
    s32 ret = 0;
	rd_buf = rxbuf;

	left = len;
    //GTP_DEBUG("Read bytes dma: 0x%04X, %d byte(s)", addr, len);
    while (left > 0)
    {
        if (left > GTP_DMA_MAX_TRANSACTION_LENGTH)
        {
            read_len = GTP_DMA_MAX_TRANSACTION_LENGTH;
        }
        else
        {
            read_len = left;
        }
        ret = i2c_dma_read(client, addr, rd_buf, read_len);
        if (ret < 0)
        {
            GTP_ERROR("dma read failed");
            return -1;
        }

        left -= read_len;
        addr += read_len;
        rd_buf += read_len;
    }
    return 0;
}


static s32 i2c_write_bytes_dma(struct i2c_client *client, u16 addr, u8 *txbuf, s32 len)
{

    s32 ret = 0;
    s32 write_len = 0;
    s32 left = len;
    u8 *wr_buf = txbuf;

    GTP_INFO("xfl Write bytes dma: 0x%04X, %d byte(s)", addr, len);
    while (left > 0)
    {
        if (left > GTP_DMA_MAX_I2C_TRANSFER_SIZE)
        {
            write_len = GTP_DMA_MAX_I2C_TRANSFER_SIZE;
        }
        else
        {
            write_len = left;
        }
        ret = i2c_dma_write(client, addr, wr_buf, write_len);

        if (ret < 0)
        {
            GTP_ERROR("dma i2c write failed!");
            return -1;
        }

        left -= write_len;
        addr += write_len;
        wr_buf += write_len;
    }
    return 0;
}

#endif

/*
int i2c_read_bytes_non_dma(struct i2c_client *client, u16 addr, u8 *rxbuf, int len)
{
    u8 buffer[GTP_ADDR_LENGTH];
    u8 retry;
    u16 left = len;
    u16 offset = 0;

    struct i2c_msg msg[2] =
    {
        {
            .addr = ((client->addr &I2C_MASK_FLAG) | (I2C_ENEXT_FLAG)),
            //.addr = ((client->addr &I2C_MASK_FLAG) | (I2C_PUSHPULL_FLAG)),
            .flags = 0,
            .buf = buffer,
            .len = GTP_ADDR_LENGTH,
            .timing = I2C_MASTER_CLOCK
        },
        {
            .addr = ((client->addr &I2C_MASK_FLAG) | (I2C_ENEXT_FLAG)),
            //.addr = ((client->addr &I2C_MASK_FLAG) | (I2C_PUSHPULL_FLAG)),
            .flags = I2C_M_RD,
            .timing = I2C_MASTER_CLOCK
        },
    };

    if (rxbuf == NULL)
        return -1;

    //GTP_DEBUG("i2c_read_bytes to device %02X address %04X len %d\n", client->addr, addr, len);

    while (left > 0)
    {
        buffer[0] = ((addr + offset) >> 8) & 0xFF;
        buffer[1] = (addr + offset) & 0xFF;

        msg[1].buf = &rxbuf[offset];

        if (left > MAX_TRANSACTION_LENGTH)
        {
            msg[1].len = MAX_TRANSACTION_LENGTH;
            left -= MAX_TRANSACTION_LENGTH;
            offset += MAX_TRANSACTION_LENGTH;
        }
        else
        {
            msg[1].len = left;
            left = 0;
        }

        retry = 0;

        while (i2c_transfer(client->adapter, &msg[0], 2) != 2)
        {
            retry++;
            if (retry == 5)
            {
                GTP_ERROR("I2C read 0x%X length=%d failed\n", addr + offset, len);
                return -1;
            }
        }
    }

    return 0;
}
*/

static s32 i2c_read_bytes_non_dma(struct i2c_client *client, u16 addr, u8 *buffer, s32 len)
{
	int ret;
	u8 addr_buf[GTP_ADDR_LENGTH] = { (addr >> 8) & 0xFF, addr & 0xFF };

	struct i2c_msg msgs[2] = {
		{
#ifdef CONFIG_MTK_I2C_EXTENSION
		 .addr = ((client->addr & I2C_MASK_FLAG) | (I2C_ENEXT_FLAG)),
		 .timing = I2C_MASTER_CLOCK,
#else
		 .addr = client->addr,
#endif
		 .flags = 0,
		 .buf = addr_buf,
		 .len = GTP_ADDR_LENGTH,
		},
		{
#ifdef CONFIG_MTK_I2C_EXTENSION
		 .addr = ((client->addr & I2C_MASK_FLAG) | (I2C_ENEXT_FLAG)),
		 .timing = I2C_MASTER_CLOCK,
#else
		 .addr = client->addr,
#endif
		 .flags = I2C_M_RD,
		},
	};

	ret = _do_i2c_read(client, msgs, addr, buffer, len);
	return ret;
}

int i2c_read_bytes(struct i2c_client *client, u16 addr, u8 *rxbuf, int len)
{
#if GTP_SUPPORT_I2C_DMA
    return i2c_read_bytes_dma(client, addr, rxbuf, len);
#else
    return i2c_read_bytes_non_dma(client, addr, rxbuf, len);
#endif
}

s32 gtp_i2c_read(struct i2c_client *client, u8 *buf, s32 len)
{
    s32 ret = -1;
    u16 addr = (buf[0] << 8) + buf[1];

    ret = i2c_read_bytes_non_dma(client, addr, &buf[2], len - 2);

    if (!ret)
    {
        return 2;
    }
    else
    {
		#if GTP_GESTURE_WAKEUP
       	if (DOZE_ENABLED == doze_status)
       {
            return ret;
       }
   		#endif
        gtp_reset_guitar(client, 20);
        return ret;
    }
}


s32 gtp_i2c_read_dbl_check(struct i2c_client *client, u16 addr, u8 *rxbuf, int len)
{
    u8 buf[16] = {0};
    u8 confirm_buf[16] = {0};
    u8 retry = 0;

    while (retry++ < 3)
    {
        memset(buf, 0xAA, 16);
        buf[0] = (u8)(addr >> 8);
        buf[1] = (u8)(addr & 0xFF);
        gtp_i2c_read(client, buf, len + 2);

        memset(confirm_buf, 0xAB, 16);
        confirm_buf[0] = (u8)(addr >> 8);
        confirm_buf[1] = (u8)(addr & 0xFF);
        gtp_i2c_read(client, confirm_buf, len + 2);

        if (!memcmp(buf, confirm_buf, len+2))
        {
            memcpy(rxbuf, confirm_buf+2, len);
            return SUCCESS;
        }
    }
    GTP_ERROR("i2c read 0x%04X, %d bytes, double check failed!", addr, len);
    return FAIL;
}

/*
int i2c_write_bytes_non_dma(struct i2c_client *client, u16 addr, u8 *txbuf, int len)
{
    u8 buffer[MAX_TRANSACTION_LENGTH];
    u16 left = len;
    u16 offset = 0;
    u8 retry = 0;

    struct i2c_msg msg =
    {
        .addr = ((client->addr &I2C_MASK_FLAG) | (I2C_ENEXT_FLAG)),
        //.addr = ((client->addr &I2C_MASK_FLAG) | (I2C_PUSHPULL_FLAG)),
        .flags = 0,
        .buf = buffer,
        .timing = I2C_MASTER_CLOCK,
    };


    if (txbuf == NULL)
        return -1;

    //GTP_DEBUG("i2c_write_bytes to device %02X address %04X len %d\n", client->addr, addr, len);

    while (left > 0)
    {
        retry = 0;

        buffer[0] = ((addr + offset) >> 8) & 0xFF;
        buffer[1] = (addr + offset) & 0xFF;

        if (left > MAX_I2C_TRANSFER_SIZE)
        {
            memcpy(&buffer[GTP_ADDR_LENGTH], &txbuf[offset], MAX_I2C_TRANSFER_SIZE);
            msg.len = MAX_TRANSACTION_LENGTH;
            left -= MAX_I2C_TRANSFER_SIZE;
            offset += MAX_I2C_TRANSFER_SIZE;
        }
        else
        {
            memcpy(&buffer[GTP_ADDR_LENGTH], &txbuf[offset], left);
            msg.len = left + GTP_ADDR_LENGTH;
            left = 0;
        }

        while (i2c_transfer(client->adapter, &msg, 1) != 1)
        {
            retry++;
            if (retry == 5)
            {
                GTP_ERROR("I2C write 0x%X%X length=%d failed\n", buffer[0], buffer[1], len);
                return -1;
            }
        }
    }

    return 0;
}
*/
static s32 i2c_write_bytes_non_dma(struct i2c_client *client, u16 addr, u8 *buffer, s32 len)
{
	s32 ret;

	struct i2c_msg msg = {
		.flags = 0,
#ifdef CONFIG_MTK_I2C_EXTENSION
		.addr = (client->addr & I2C_MASK_FLAG) | (I2C_ENEXT_FLAG),	/*remain*/
		.timing = I2C_MASTER_CLOCK,
#else
		.addr = client->addr,  /*remain*/
#endif
	};

	ret = _do_i2c_write(client, &msg, addr, buffer, len);
	return ret;
}

int i2c_write_bytes(struct i2c_client *client, u16 addr, u8 *txbuf, int len)
{
#if GTP_SUPPORT_I2C_DMA
    return i2c_write_bytes_dma(client, addr, txbuf, len);
#else
    return i2c_write_bytes_non_dma(client, addr, txbuf, len);
#endif
}

s32 gtp_i2c_write(struct i2c_client *client, u8 *buf, s32 len)
{
    s32 ret = -1;
    u16 addr = (buf[0] << 8) + buf[1];

    ret = i2c_write_bytes_non_dma(client, addr, &buf[2], len - 2);

    if (!ret)
    {
        return 1;
    }
    else
    {
	#if GTP_GESTURE_WAKEUP
        if (DOZE_ENABLED == doze_status)
        {
            return ret;
        }
    #endif
        gtp_reset_guitar(client, 20);
        return ret;
    }
}



/*******************************************************
Function:
    Read goodix touchscreen version function.

Input:
    client: i2c client struct.
    version:address to store version info

Output:
    Executive outcomes.0---succeed.
*******************************************************/
s32 gtp_read_version(struct i2c_client *client, u16 *version)
{
    s32 ret = -1;
    s32 i;
    u8 buf[8] = {GTP_REG_VERSION >> 8, GTP_REG_VERSION & 0xff};

    GTP_INFO("gtp_read_version enter\n");

    ret = gtp_i2c_read(client, buf, sizeof(buf));

    if (ret < 0)
    {
        GTP_ERROR("GTP read version failed");
        return ret;
    }

    if (version)
    {
        *version = (buf[7] << 8) | buf[6];
    }

    tpd_info.vid = *version;
    tpd_info.pid = 0x00;

    for (i = 0; i < 4; i++)
    {
        if (buf[i + 2] < 0x30)break;

        tpd_info.pid |= ((buf[i + 2] - 0x30) << ((3 - i) * 4));
    }

    if (buf[5] == 0x00)
    {
        GTP_INFO("IC VERSION: %c%c%c_%02x%02x",
             buf[2], buf[3], buf[4], buf[7], buf[6]);
    }
    else
    {
        GTP_INFO("IC VERSION:%c%c%c%c_%02x%02x",
             buf[2], buf[3], buf[4], buf[5], buf[7], buf[6]);
    }
    return ret;
}

static s8 gtp_i2c_test(struct i2c_client *client)
{
    u8 retry = 0;
    s8 ret = -1;
    u32 hw_info = 0;

    GTP_DEBUG_FUNC();
//[AGOLD][20151104][chenpeng][start]去除循环解决55n编译多个TP时关机冲不了电
  //  while (retry++ < 3)
  //  {
        ret = i2c_read_bytes(client, GTP_REG_HW_INFO, (u8 *)&hw_info, sizeof(hw_info));

        if ((!ret) && (hw_info == 0x00900600))       //20121212//change by chenpeng0x00900600
        {
            return ret;


        GTP_INFO("GTP_REG_HW_INFO : %08X", hw_info);
        GTP_INFO("GTP i2c test failed time %d.", retry);
        msleep(10);
        }
 //   }
//[AGOLD][20151104][chenpeng][end]去除循环解决55n编译多个TP时关机冲不了电
    return -1;
}



/*******************************************************
Function:
    Set INT pin  as input for FW sync.

Note:
  If the INT is high, It means there is pull up resistor attached on the INT pin.
  Pull low the INT pin manaully for FW sync.
*******************************************************/
void gtp_int_sync(s32 ms)
{
    TPD_DEBUG("[zhangjing] %s \n",__func__);
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
    msleep(ms);
    GTP_GPIO_AS_INT(GTP_INT_PORT);
}

void gtp_reset_guitar(struct i2c_client *client, s32 ms)
{
    GTP_INFO("GTP RESET!\n");
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 0);
    msleep(ms);
    GTP_GPIO_OUTPUT(GTP_INT_PORT, client->addr == 0x14);
    msleep(2);
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 1);
    msleep(20);                      //must >= 6ms
    gtp_int_sync(50);
}

static int tpd_power_on(struct i2c_client *client)
{
    int ret = 0;
 //   int reset_count = 0;

//reset_proc:
	/*[Agold][MaJian][20161115]start*/
#ifdef AGOLD_CTP_POWER_EN
	GTP_GPIO_OUTPUT(GTP_PWR_PORT, 0);
	msleep(10);
	GTP_GPIO_OUTPUT(GTP_PWR_PORT, 1);
#endif
	/*[Agold][MaJian][20161115]end*/

    GTP_GPIO_OUTPUT(GTP_RST_PORT, 0);
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
    msleep(10);

   // hwPowerDown(TPD_POWER_SOURCE,"TP");
    //msleep(100);
    //hwPowerOn(TPD_POWER_SOURCE, VOL_2800, "TP");

    gtp_reset_guitar(client, 20);

    ret = gtp_i2c_test(client);

    if (ret < 0)
    {
        GTP_ERROR("I2C communication ERROR!");
/*
        if (reset_count < TPD_MAX_RESET_COUNT)
        {
            reset_count++;
            goto reset_proc;
        }
        */
    }
    return ret;
}

static int tpd_irq_registration(void)
{
	struct device_node *node = NULL;
	int ret = 0;
	u32 ints[2] = { 0, 0 };

	GTP_INFO("Device Tree Tpd_irq_registration!");

	node = of_find_matching_node(node, touch_of_match);
	if (node) {
		of_property_read_u32_array(node, "debounce", ints, ARRAY_SIZE(ints));
		gpio_set_debounce(ints[0], ints[1]);
		touch_irq = irq_of_parse_and_map(node, 0);
		ret = request_irq(touch_irq, (irq_handler_t) tpd_eint_interrupt_handler, IRQF_TRIGGER_FALLING, "TOUCH_PANEL-eint", NULL);
		if (ret > 0) {
			ret = -1;
		}
	} else {
		GTP_ERROR("tpd request_irq can not find touch eint device node!.");
		ret = -1;
	}
	GTP_INFO("[%s]irq:%d, debounce:%d-%d:", __func__, touch_irq, ints[0], ints[1]);
	return ret;
}

static s32 tpd_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
    s32 err = 0;
    s32 ret = 0;
#if GTP_HAVE_TOUCH_KEY
	s32 idx = 0;
#endif
	u8 buf[3] = {GTP_REG_SENSOR_ID >> 8,GTP_REG_SENSOR_ID & 0xff,0};
    u16 version_info;

    i2c_client_point = client;
    ret = tpd_power_on(client);

    if (ret < 0)
    {
        GTP_ERROR("I2C communication ERROR!");
        return -1;
    }

    ret = gtp_read_version(client, &version_info);

    if (ret < 0)
    {
    	tpd_load_status = -1;
        GTP_ERROR("Read version failed.");
        return -1;
    }

    // Create proc file system
    gt91xx_config_proc = proc_create(GT91XX_CONFIG_PROC_FILE, 0666, NULL, &config_proc_ops);
    if (gt91xx_config_proc == NULL)
    {
        GTP_ERROR("create_proc_entry %s failed\n", GT91XX_CONFIG_PROC_FILE);
    }
    else
    {
        GTP_INFO("create proc entry %s success", GT91XX_CONFIG_PROC_FILE);
    }

#if GTP_CREATE_WR_NODE
    init_wr_node(client);
#endif

    thread = kthread_run(touch_event_handler, 0, TPD_DEVICE);

    if (IS_ERR(thread))
    {
        err = PTR_ERR(thread);
        GTP_INFO(TPD_DEVICE " failed to create kernel thread: %d\n", err);
    }

#if GTP_HAVE_TOUCH_KEY
	for (idx = 0; idx < GTP_MAX_KEY_NUM; idx++) {
		input_set_capability(tpd->dev, EV_KEY, gt9x_touch_key_array[idx]);
	}
#endif

#if GTP_GESTURE_WAKEUP
    g_gesture_support = 0x7E7F;
    input_set_capability(tpd->dev, EV_KEY, KEY_POWER);
    input_set_capability(tpd->dev, EV_KEY, KEY_TV);
#endif
/*
    // set INT mode
    mt_set_gpio_mode(GPIO_CTP_EINT_PIN, GPIO_CTP_EINT_PIN_M_EINT);
    mt_set_gpio_dir(GPIO_CTP_EINT_PIN, GPIO_DIR_IN);
    mt_set_gpio_pull_enable(GPIO_CTP_EINT_PIN, GPIO_PULL_DISABLE);

    msleep(50);

    if(0)
    	mt_eint_registration(CUST_EINT_TOUCH_PANEL_NUM, EINTF_TRIGGER_RISING, tpd_eint_interrupt_handler, 1);
    else
    	mt_eint_registration(CUST_EINT_TOUCH_PANEL_NUM, EINTF_TRIGGER_FALLING, tpd_eint_interrupt_handler, 1);

    disable_irq(touch_irq);
*/

	ret = gtp_i2c_read(client, buf, sizeof(buf));
	if (ret < 0)
    {
    	tpd_load_status = -1;
        GTP_ERROR("Read vendor_ID failed.");
        return -1;
    }
	GTP_INFO("[geng] vendor_id = %02x\n",buf[2]);
#if defined(AGOLD_GTP_WRITE_CFG) && !defined(AGOLD_CTP_CONFIG_COMPATIBLE)

		err = i2c_write_bytes(client, TPD_CONFIG_REG_BASE, cfg_data, sizeof(cfg_data));
		if (err)
		{
			GTP_INFO("[Agold TPD] fail to write tpd cfg %d\n", err );
			return err;
		}
		GTP_INFO("[geng] write cfg cs\n");

#endif

#if defined(AGOLD_GTP_WRITE_CFG) && defined(AGOLD_CTP_CONFIG_COMPATIBLE)
	if (buf[2] == 0x02)
	{
		err = i2c_write_bytes(client, TPD_CONFIG_REG_BASE, cfg_data, sizeof(cfg_data));
		if (err)
		{
			GTP_INFO("[Agold TPD] fail to write tpd cfg %d\n", err );
			return err;
		}
		GTP_INFO("[geng] write cfg cs\n");
	}
	else if (buf[2] == 0x00)
	{
		err = i2c_write_bytes(client, TPD_CONFIG_REG_BASE, cfg_data_1, sizeof(cfg_data));
		if (err)
		{
			GTP_INFO("[Agold TPD] fail to write tpd cfg %d\n", err );
			return err;
		}
		GTP_INFO("[geng] write cfg xl\n");
	}
#endif

	tpd_irq_registration();
	//enable_irq(touch_irq);

    tpd_load_status = 1;

    return 0;
}

static irqreturn_t tpd_eint_interrupt_handler(int irq, void *desc)
{
    tpd_flag = 1;
    wake_up_interruptible(&waiter);
	return IRQ_HANDLED;
}
static int tpd_i2c_remove(struct i2c_client *client)
{
/*
#if GTP_CREATE_WR_NODE
    uninit_wr_node();
#endif
*/
    return 0;
}

static void tpd_down(s32 x, s32 y, s32 size, s32 id)
{
	#if TPD_HAVE_BUTTON
	if(0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3) || 0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2))
    {
		if((get_boot_mode()==FACTORY_BOOT/* || get_boot_mode()==RECOVERY_BOOT */) && x>=AGOLD_TPD_RES_Y)
		{
			int temp;
			temp = y;
			y = x;
			x = AGOLD_TPD_RES_X-temp;
			tpd_button(x, y, 1);
			return;
		}
		else if((get_boot_mode()==FACTORY_BOOT/* || get_boot_mode()==RECOVERY_BOOT */) && y>=AGOLD_TPD_RES_Y)
		{
			tpd_button(x, y, 1);
			return;
		}
	}
    else
	{
		if((get_boot_mode()==FACTORY_BOOT/* || get_boot_mode()==RECOVERY_BOOT */) && y>=AGOLD_TPD_RES_Y)
		{
			tpd_button(x, y, 1);
			return;
		}
	}
	#endif

    input_report_key(tpd->dev, BTN_TOUCH, 1);

	if ((!size) && (!id))
	{
		/* for virtual button */
		input_report_abs(tpd->dev, ABS_MT_PRESSURE, 100);
		input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, 100);
	}
	else
	{
		input_report_abs(tpd->dev, ABS_MT_PRESSURE, size);
		input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, size);
		input_report_abs(tpd->dev, ABS_MT_TRACKING_ID, id);
	}

    #ifndef AGOLD_CTP_ROTATION_S16
    if((0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3)) && (y <= AGOLD_TPD_RES_Y))
	{
	 	input_report_abs(tpd->dev, ABS_MT_POSITION_X, AGOLD_TPD_RES_X-x);
	 	input_report_abs(tpd->dev, ABS_MT_POSITION_Y, AGOLD_TPD_RES_Y-y);
	}
	else
	#endif
	{
		input_report_abs(tpd->dev, ABS_MT_POSITION_X, x);
		input_report_abs(tpd->dev, ABS_MT_POSITION_Y, y);
	  }
    input_mt_sync(tpd->dev);
    TPD_EM_PRINT(x, y, x, y, id, 1);

}

static void tpd_up(s32 x, s32 y, s32 id)
{
    input_report_key(tpd->dev, BTN_TOUCH, 0);
    input_mt_sync(tpd->dev);
    TPD_EM_PRINT(x, y, x, y, id, 0);

}

static int touch_event_handler(void *unused)
{
    struct sched_param param = { .sched_priority = 4 };
    u8  end_cmd[3] = {GTP_READ_COOR_ADDR >> 8, GTP_READ_COOR_ADDR & 0xFF, 0};
    u8  point_data[2 + 1 + 8 * GTP_MAX_TOUCH + 1] = {GTP_READ_COOR_ADDR >> 8, GTP_READ_COOR_ADDR & 0xFF};
    u8  touch_num = 0;
    u8  finger = 0;
    static u8 pre_touch = 0;
    static u8 pre_key = 0;
#if GTP_GESTURE_WAKEUP
    char gesture_tmp[16];
    int flag_s=0;
#endif

    u8  key_value = 0;
    u8 *coor_data = NULL;
    s32 input_x = 0;
    s32 input_y = 0;
    s32 input_w = 0;
    s32 id = 0;
    s32 i  = 0;
    s32 ret = -1;
#if GTP_HAVE_TOUCH_KEY
    static u8  last_key = 0;
#elif TPD_HAVE_BUTTON
    static u8  last_key = 0;
    u32 key_x = 0, key_y = 0, key_z = 0;
#endif

#if GTP_GESTURE_WAKEUP
    u8 doze_buf[3] = {0x81, 0x4B};
#endif

    sched_setscheduler(current, SCHED_RR, &param);
    do
    {
        set_current_state(TASK_INTERRUPTIBLE);

        while (gtp_tpd_halt)
        {
#if GTP_GESTURE_WAKEUP
            if (DOZE_ENABLED == doze_status)
            {
                break;
            }
#endif
            tpd_flag = 0;
            msleep(20);
        }

        wait_event_interruptible(waiter, tpd_flag != 0);
        tpd_flag = 0;
        TPD_DEBUG_SET_TIME;
        set_current_state(TASK_RUNNING);

#if GTP_GESTURE_WAKEUP
        if (DOZE_ENABLED == doze_status)
        {
            ret = gtp_i2c_read(i2c_client_point, doze_buf, 3);
            GTP_DEBUG("0x814B = 0x%02X", doze_buf[2]);
            if (ret > 0)
            {
                memset(gesture_tmp,0,sizeof(gesture_tmp));  // add by whl
                flag_s=0;
                /*------------------------------------------------------------------------------- */

                   switch(doze_buf[2])
                           {
                             case 'a':if(g_single_gesture_flag[17]==1){strcpy(gesture_tmp,"a");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'a'\n");break;
                             case 'b':if(g_single_gesture_flag[18]==1){strcpy(gesture_tmp,"b");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'b'\n");break;
                             case 'c':if(g_single_gesture_flag[5]==1){strcpy(gesture_tmp,"c");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'c'\n");break;
                             case 'd':if(g_single_gesture_flag[19]==1){strcpy(gesture_tmp,"d");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'd'\n");break;
                             case 'e':if(g_single_gesture_flag[6]==1){strcpy(gesture_tmp,"e");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'e'\n");break;
                             case 'g':if(g_single_gesture_flag[20]==1){strcpy(gesture_tmp,"g");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'g'\n");break;
                             case 'h':if(g_single_gesture_flag[21]==1){strcpy(gesture_tmp,"h");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'h'\n");break;
                             case 'm':if(g_single_gesture_flag[8]==1){strcpy(gesture_tmp,"m");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'm'\n");break;
                             case 'o':if(g_single_gesture_flag[9]==1){strcpy(gesture_tmp,"o");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'o'\n");break;
                             case 'q':if(g_single_gesture_flag[22]==1){strcpy(gesture_tmp,"q");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'q'\n");break;
                             case 's':if(g_single_gesture_flag[10]==1){strcpy(gesture_tmp,"s");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 's'\n");break;
                             case 'v':if(g_single_gesture_flag[11]==1){strcpy(gesture_tmp,"v");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'v'\n");break;
                             case 'w':if(g_single_gesture_flag[12]==1){strcpy(gesture_tmp,"w");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'w'\n");break;
                             case 'y':if(g_single_gesture_flag[23]==1){strcpy(gesture_tmp,"y");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'y'\n");break;
                             case 'z':if(g_single_gesture_flag[13]==1){strcpy(gesture_tmp,"z");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'z'\n");break;
                             case 0x5E:if(g_single_gesture_flag[14]==1){strcpy(gesture_tmp,"reversev");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture '^'\n");break;
                             case 0xAA:if(g_single_gesture_flag[4]==1){strcpy(gesture_tmp,"right");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture '-->'\n");break;
                             case 0xBB:if(g_single_gesture_flag[3]==1){strcpy(gesture_tmp,"left");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture '<--'\n");break;
                             case 0xAB:if(g_single_gesture_flag[2]==1){strcpy(gesture_tmp,"down");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'down'\n");break;
                             case 0xBA:if(g_single_gesture_flag[1]==1){strcpy(gesture_tmp,"up");flag_s=1;}
                                      TPD_DEBUG("whl Input Gesture 'up'\n");break;
                             case 0xCC:if(g_single_gesture_flag[0]==1){strcpy(gesture_tmp,"doubletap");flag_s=1;}
                                      TPD_DEBUG("whl double_click\n");break;
                             default:  strcpy(gesture_tmp,"default");flag_s=0;doze_buf[2] = 0x00;gtp_i2c_write(i2c_client_point, doze_buf, 3);
                                       gtp_enter_doze(i2c_client_point);TPD_DEBUG("whl default\n");break;
                            }
                    if (flag_s==1 && ONLY_ONCE==1)
                    {
                    	ONLY_ONCE=0;
		            	doze_status = DOZE_WAKEUP;

				    	agold_tpd_get_gesture(gesture_tmp);

						input_report_key(tpd->dev, KEY_TV, 1);
						input_sync(tpd->dev);
						mdelay(5);
						input_report_key(tpd->dev, KEY_TV, 0);
						input_sync(tpd->dev);

                    }

                                          		            // clear 0x814B
		            doze_buf[2] = 0x00;
		            gtp_i2c_write(i2c_client_point, doze_buf, 3);

           /*------------------------------------------------------------------------------- */
            }
            continue;
        }
#endif
        ret = gtp_i2c_read(i2c_client_point, point_data, 12);
        if (ret < 0)
        {
            GTP_ERROR("whl agold I2C transfer error. errno:%d\n ", ret);
            goto exit_work_func;
        }
        finger = point_data[GTP_ADDR_LENGTH];

        if (finger == 0x00)
        {
            continue;
        }

        if ((finger & 0x80) == 0)
        {
            disable_irq(touch_irq);
            GTP_ERROR("buffer not ready");
            continue;
        }

        touch_num = finger & 0x0f;

        if (touch_num > GTP_MAX_TOUCH)
        {
            goto exit_work_func;
        }

        if (touch_num > 1)
        {
            u8 buf[8 * GTP_MAX_TOUCH] = {(GTP_READ_COOR_ADDR + 10) >> 8, (GTP_READ_COOR_ADDR + 10) & 0xff};

            ret = gtp_i2c_read(i2c_client_point, buf, 2 + 8 * (touch_num - 1));
            memcpy(&point_data[12], &buf[2], 8 * (touch_num - 1));
        }

	 	key_value = point_data[3 + 8 * touch_num];
        pre_key = key_value;
#if TPD_HAVE_BUTTON
        TPD_DEBUG("pre_touch:%02x, finger:%02x, pre_key = 0x%02x, last_key = 0x%02x\n", pre_touch, finger,pre_key, last_key);
#endif
        if (touch_num)
        {
            for (i = 0; i < touch_num; i++)
            {
                coor_data = &point_data[i * 8 + 3];

                id = coor_data[0] & 0x0F;
                input_x  = coor_data[1] | coor_data[2] << 8;
                input_y  = coor_data[3] | coor_data[4] << 8;
                input_w  = coor_data[5] | coor_data[6] << 8;
				GTP_DEBUG("point[i] = %d, input_x = %d, input_y = %d input_w  = %d\n",i, input_x,input_y,input_w );
		        tpd_down(input_x, input_y, input_w, id);
            }
        }
        else
        {
            if (pre_touch)
            {
                GTP_DEBUG("Touch Release!");
		   		tpd_up(input_x, input_y, id);
            }
        }
#if GTP_HAVE_TOUCH_KEY
		if ((pre_key) || (last_key)) {
			for (i = 0; i < GTP_MAX_KEY_NUM; i++) {
				input_report_key(tpd->dev, gt9x_touch_key_array[i], pre_key & (0x01 << i));
			}
			if (pre_key) {
			    last_key = 0;
				GTP_DEBUG("Key Down.");
			} else if (last_key) {
				GTP_DEBUG("Key Up.");
			}
//		last_key = pre_key;
		}

		last_key = pre_key;
#elif TPD_HAVE_BUTTON
    	if (pre_key)
    	{
			if (pre_key & 0x01) {
				key_x=60;
				key_y=AGOLD_TPD_RES_Y*850/800;
			}
			else if(pre_key & 0x02) {
				key_x=300;
				key_y=AGOLD_TPD_RES_Y*850/800;
			}
			else if(pre_key & 0x04) {
				key_x=180;
				key_y=AGOLD_TPD_RES_Y*850/800;
			}
			else if(pre_key & 0x08) {
				key_x=420;
				key_y=AGOLD_TPD_RES_Y*850/800;
			}

		    last_key = 0;
			TPD_DEBUG("[Key][Down] key_x = %d, key_y = %d, key_z = %d,pre_key=%d \n",key_x, key_y, key_z,pre_key);
			tpd_down(key_x, key_y, key_z, pre_key);
    	}
		else if (last_key) {
			TPD_DEBUG("[Key][Up]>>>>>>>>>>>>\n");
			tpd_up(key_x, key_y, 0);

			if((get_boot_mode()==FACTORY_BOOT/* || get_boot_mode()==RECOVERY_BOOT */) && tpd->btn_state) {
				tpd_button(key_x, key_y, 0);
			}
				//input_report_key(tpd->dev, BTN_TOUCH, last_key);
		}

		last_key = pre_key;
		//input_report_key(tpd->dev, BTN_TOUCH, key);
#endif
        pre_touch = touch_num;
        input_sync(tpd->dev);

exit_work_func:
        if (!gtp_rawdiff_mode)
        {
            ret = gtp_i2c_write(i2c_client_point, end_cmd, 3);

            if (ret < 0)
            {
                GTP_INFO("I2C write end_cmd  error!");
            }
        }

    } while (!kthread_should_stop());

    return 0;
}
#ifdef AGOLD_HARDWARE_INFO
static int ft_get_fw_ver(void)
{
	u8 ver = 0;
	int i = 0;
	while(i<5)
	{
		if(i2c_read_bytes(i2c_client_point, GTP_REG_CONFIG_DATA, &ver, 1) < 0)
		{
			TPD_DEBUG("[Bruce] read Goodix cfg ver fail: %u\n", ver);
			return -1;
		}
		i++;
	}

	return ver;
}
#endif
#if defined(AGOLD_CTP_FOR_HAND)
static void tpd_handler2(int temp)
{
	int err = 0;
	printk("[gengdong] enter GT9XX_GESTURE: tpd_handler \n");

	if(i2c_client_point == NULL)
	{
		GTP_ERROR("i2c_client_point == NULL !!\n");
	}else
	{
		if(0 == temp)
		{
			// ljj:驱动下发NORMAL模式固件。
			TPD_DEBUG("[gengdong]  TPD_SET_CFG_FOR_NORMAL  ~~~  \n");
			err = i2c_write_bytes(i2c_client_point, TPD_CONFIG_REG_BASE, cfg_data, sizeof(cfg_data));
			if (err) {
				TPD_DEBUG("[gengdong] fail to write tpd normal cfg %d\n", err );
			}
		}else if(1 == temp)
		{
			// ljj:驱动下发手套模式固件。
			TPD_DEBUG("[gengdong]  TPD_SET_CFG_FOR_HAND  ~~~  \n");
			err = i2c_write_bytes(i2c_client_point, TPD_CONFIG_REG_BASE, cfg_data_hand, sizeof(cfg_data_hand));
			if (err) {
				TPD_DEBUG("[gengdong] fail to write tpd hand cfg %d\n", err );
			}
		}else{
			printk("[gengdong]  error!  should not print this ! \n");
		}
	}
}
#endif

//agold shipeilong add start
static int tpd_power_enable(int enable)
{
	int ret = 0;
	GTP_INFO("Device Tree get regulator!");
/*[Agold][MaJian]20161115*/
#ifndef AGOLD_CTP_POWER_EN
#if !defined CONFIG_MTK_LEGACY

	//tpd->reg = regulator_get(tpd->tpd_dev, "vtouch");
	ret = regulator_set_voltage(tpd->reg, 2800000, 2800000);	/*set 2.8v*/
	if (ret) {
		GTP_ERROR("regulator_set_voltage(%d) failed!\n", ret);
		return -1;
	}
	if(enable)
	{
		ret = regulator_enable(tpd->reg);	/*enable regulator*/
		if (ret)
		{
			GTP_INFO("regulator_enable() failed!\n");
		}
	}
	else
	{
		ret = regulator_disable(tpd->reg);	/*disable regulator*/
		if (ret)
		{
			GTP_INFO("regulator_disable() failed!\n");
		}
	}
#endif
#endif
	return ret;
}
//agold shipeilong end

static int tpd_local_init(void)
{
/*[Agold][MaJian]20161128*/
#ifndef AGOLD_CTP_POWER_EN
#if !defined CONFIG_MTK_LEGACY
	int ret;

	GTP_INFO("xfl Device Tree get regulator!");
	tpd->reg = regulator_get(tpd->tpd_dev, "vtouch");
	//TPD_DEBUG("[geng_gt1x] regulator_get tpd->reg=0x%x\n",tpd->reg);
    if (IS_ERR(tpd->reg)) {
        TPD_DEBUG("regulator_get() failed.");
        return 0;
    }
	ret = regulator_set_voltage(tpd->reg, 2800000, 2800000);	/*set 2.8v*/
	if (ret) {
		GTP_ERROR("xfl regulator_set_voltage(%d) failed!\n", ret);
		return -1;
	}

	ret = regulator_enable(tpd->reg);	/*enable regulator*/
	if (ret)
	{
		GTP_INFO("xfl regulator_enable() failed!\n");
	}
#endif
#endif

#if GTP_SUPPORT_I2C_DMA
	tpd->dev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
    gpDMABuf_va = (u8 *)dma_alloc_coherent(&tpd->dev->dev, GTP_DMA_MAX_TRANSACTION_LENGTH, &gpDMABuf_pa, GFP_KERNEL);
    if(!gpDMABuf_va){
        GTP_INFO("[Error] Allocate DMA I2C Buffer failed!\n");
    }
    memset(gpDMABuf_va, 0, GTP_DMA_MAX_TRANSACTION_LENGTH);
#endif
    if (i2c_add_driver(&tpd_i2c_driver) != 0)
    {
        GTP_INFO("unable to add i2c driver.\n");
        return -1;
    }

    if (tpd_load_status == -1) //if(tpd_load_status == 0) // disable auto load touch driver for linux3.0 porting
    {
        GTP_INFO("add error touch panel driver.\n");
        //[Agold][Jason][20171031] 释放2.8v
        tpd_power_enable(0);
        i2c_del_driver(&tpd_i2c_driver);
        return -1;
    }

#if (GTP_HAVE_TOUCH_KEY || TPD_HAVE_BUTTON)
	if (tpd_dts_data.use_tpd_button) {
		/*initialize tpd button data*/
		tpd_button_setting(tpd_dts_data.tpd_key_num, tpd_dts_data.tpd_key_local,
		tpd_dts_data.tpd_key_dim_local);
	}
#endif

#if (defined(TPD_WARP_START) && defined(TPD_WARP_END))
    TPD_DO_WARP = 1;
    memcpy(tpd_wb_start, tpd_wb_start_local, TPD_WARP_CNT * 4);
    memcpy(tpd_wb_end, tpd_wb_start_local, TPD_WARP_CNT * 4);
#endif

#if (defined(TPD_HAVE_CALIBRATION) && !defined(TPD_CUSTOM_CALIBRATION))
    memcpy(tpd_calmat, tpd_def_calmat_local, 8 * 4);
    memcpy(tpd_def_calmat, tpd_def_calmat_local, 8 * 4);
#endif

    // set vendor string
    tpd->dev->id.vendor = 0x00;
    tpd->dev->id.product = tpd_info.pid;
    tpd->dev->id.version = tpd_info.vid;

    GTP_INFO("end %s, %d\n", __FUNCTION__, __LINE__);
    tpd_type_cap = 1;

    return 0;
}

#if GTP_GESTURE_WAKEUP
static s8 gtp_enter_doze(struct i2c_client *client)
{
    s8 ret = -1;
    s8 retry = 0;
    u8 i2c_control_buf[3] = {(u8)(GTP_REG_SLEEP >> 8), (u8)GTP_REG_SLEEP, 8};

    GTP_DEBUG_FUNC();

    GTP_DEBUG("Entering gesture mode...");
    while(retry++ < 5)
    {
        i2c_control_buf[0] = 0x80;
        i2c_control_buf[1] = 0x46;
        ret = gtp_i2c_write(client, i2c_control_buf, 3);
        if (ret < 0)
        {
            GTP_DEBUG("Failed to set gesture flag into 0x8046, %d", retry);
            continue;
        }
        i2c_control_buf[0] = 0x80;
        i2c_control_buf[1] = 0x40;
        ret = gtp_i2c_write(client, i2c_control_buf, 3);
        if (ret > 0)
        {
            doze_status = DOZE_ENABLED;
            GTP_INFO("Gesture mode enabled.");
            return ret;
        }
        msleep(10);
    }
    GTP_ERROR("GTP send gesture cmd failed.");
    return ret;
}

#endif

/*******************************************************
Function:
    Eter sleep function.

Input:
    client:i2c_client.

Output:
    Executive outcomes.0--success,non-0--fail.
*******************************************************/
static s8 gtp_enter_sleep(struct i2c_client *client)
{
#if GTP_POWER_CTRL_SLEEP

    GTP_GPIO_OUTPUT(GTP_RST_PORT, 0);
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
    msleep(10);

    //hwPowerDown(TPD_POWER_SOURCE, "TP");
    GTP_INFO("GTP enter sleep by poweroff!");
    return 0;

#else
    {
        s8 ret = -1;
        s8 retry = 0;
        #if defined(AGOLD_GTP_REG_SLEEP_FOR_GT5688)//add by chenpeng
        u8 i2c_control_buf[5] = {(u8)(GTP_REG_SLEEP >> 8), (u8)GTP_REG_SLEEP, 5,0,0xFB};

        #else
        u8 i2c_control_buf[3] = {(u8)(GTP_REG_SLEEP >> 8), (u8)GTP_REG_SLEEP, 5,};
        #endif
        GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
        msleep(5);

        while (retry++ < 5)
        {
			#if defined(AGOLD_GTP_REG_SLEEP_FOR_GT5688)//add by chenpeng
           		ret = gtp_i2c_write(client, i2c_control_buf, 5);
			#else
          		ret = gtp_i2c_write(client, i2c_control_buf, 3);
          #endif
            if (ret > 0)
            {
                GTP_INFO("GTP enter sleep!");

                return ret;
            }

            msleep(10);
        }

        GTP_ERROR("GTP send sleep cmd failed.");
        return ret;
    }
#endif
}

/*******************************************************
Function:
    Wakeup from sleep mode Function.

Input:
    client:i2c_client.

Output:
    Executive outcomes.0--success,non-0--fail.
*******************************************************/
static s8 gtp_wakeup_sleep(struct i2c_client *client)
{
    u8 retry = 0;
    s8 ret = -1;

    GTP_DEBUG("GTP wakeup begin.");

#if (GTP_POWER_CTRL_SLEEP)
    while (retry++ < 5)
    {
        ret = tpd_power_on(client);

        if (ret < 0)
        {
            GTP_ERROR("I2C Power on ERROR!");
            continue;
        }
        GTP_INFO("Ic wakeup by poweron");
        return 0;
    }
#else

    TPD_DEBUG("whl ges+++++ ");
    while (retry++ < 10)
    {
    #if GTP_GESTURE_WAKEUP
        if (DOZE_WAKEUP != doze_status)
        {
            GTP_INFO("Powerkey wakeup.");
        }
        else
        {
            GTP_INFO("whl Gesture wakeup.");
        }
        doze_status = DOZE_DISABLED;


        gtp_reset_guitar(client, 20);

    #else
        TPD_DEBUG("whl ------else");
        GTP_GPIO_OUTPUT(GTP_INT_PORT, 1);
        msleep(5);
    #endif

        ret = gtp_i2c_test(client);

        if (ret >= 0)
        {
            GTP_INFO("GTP wakeup sleep.");
        #if (!GTP_GESTURE_WAKEUP)
            {
                gtp_int_sync(25);
		        #if GTP_ESD_PROTECT
		        gtp_init_ext_watchdog(client);
		        #endif
            }
        #endif

            return ret;
        }
        gtp_reset_guitar(client, 20);
    }
#endif
    GTP_ERROR("GTP wakeup sleep failed.");
    return ret;
}

/* Function to manage low power suspend */
static void tpd_suspend(struct device *h)
{
    s32 ret = -1;
    hall_resume=0;
    ONLY_ONCE=1;
    GTP_INFO("System suspend.");

    gtp_tpd_halt = 1;

	//agold shipeilong add start
	tpd_power_enable(0);
	msleep(30);
	tpd_power_enable(1);
	msleep(10);
	ret = tpd_power_on(i2c_client_point);
    if (ret < 0)
    {
        GTP_ERROR("I2C communication ERROR!");
    }
    //agold shipeilong end

#if GTP_GESTURE_WAKEUP
       //g_gesture_flag=0;//add by whl
    if(g_gesture_flag==1)
    {
    	ret = gtp_enter_doze(i2c_client_point);
    }
    else
#endif
    {
		disable_irq(touch_irq);
    	ret = gtp_enter_sleep(i2c_client_point);
    }

    if (ret < 0)
    {
        GTP_ERROR("GTP early suspend failed.");
    }
    // to avoid waking up while not sleeping, delay 48 + 10ms to ensure reliability
    msleep(58);
	//disable_irq(touch_irq);
}

/* Function to manage power-on resume */
static void tpd_resume(struct device *h)
{
    s32 ret = -1;
    GTP_INFO("System resume.");

 //   if(load_fw_process == 0)
//    {
        ret = gtp_wakeup_sleep(i2c_client_point);

        if (ret < 0)
        {
            GTP_ERROR("GTP later resume failed.");
        }
  //  }

    hall_resume=1;
#if GTP_GESTURE_WAKEUP
    doze_status = DOZE_DISABLED;

	if(g_gesture_flag != 1)
	{
		enable_irq(touch_irq);
	}
#else
	enable_irq(touch_irq);
#endif
    gtp_tpd_halt = 0;

}
static struct tpd_driver_t tpd_device_driver =
{
    .tpd_device_name = "GT9XX_GESTURE",
    .tpd_local_init = tpd_local_init,
    .suspend = tpd_suspend,
    .resume = tpd_resume,
#if defined(AGOLD_CTP_FOR_HAND)
	.tpd_handler = tpd_handler2,
#endif
#ifdef AGOLD_HARDWARE_INFO
	.get_tp_fw_ver = ft_get_fw_ver,
#endif
};

/* called when loaded into kernel */
static int __init tpd_driver_init(void)
{
    GTP_INFO("MediaTek gt91xx touch panel driver init\n");
	tpd_get_dts_info();
    if (tpd_driver_add(&tpd_device_driver) < 0)
        GTP_INFO("add generic driver failed\n");

    return 0;
}

/* should never be called */
static void __exit tpd_driver_exit(void)
{
    GTP_INFO("MediaTek gt91xx touch panel driver exit\n");
    tpd_driver_remove(&tpd_device_driver);
}

module_init(tpd_driver_init);
module_exit(tpd_driver_exit);

