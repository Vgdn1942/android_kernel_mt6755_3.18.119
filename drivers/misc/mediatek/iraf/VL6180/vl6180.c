/*
 * Author: yucong xiong <yucong.xion@mediatek.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/interrupt.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/kobject.h>
#include <linux/platform_device.h>
#include <asm/atomic.h>
#include <asm/io.h>
#include "vl6180.h"
#include <linux/sched.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/proc_fs.h>   //proc file use
#include <generated/autoconf.h>
#include <linux/regulator/consumer.h>
#include <linux/gpio.h>
#include <linux/fs.h>
#include <linux/types.h>
/******************************************************************************
 * configuration
*******************************************************************************/
/*----------------------------------------------------------------------------*/

#define VL6180_DEV_NAME     "vl6180"
#define IRAF_DEVICE         "iraf"
/*----------------------------------------------------------------------------*/
#define IRAF_TAG                  "[IRAF] "
#define IRAF_FUN(fmt, args...)    pr_err(IRAF_TAG fmt, ##args)
#define IRAF_ERR(fmt, args...)    pr_err(IRAF_TAG"%s %d : "fmt, __func__, __LINE__, ##args)
#define IRAF_LOG(fmt, args...)    pr_err(IRAF_TAG fmt, ##args)
#define IRAF_DBG(fmt, args...)    pr_err(IRAF_TAG fmt, ##args)

#define I2C_FLAG_WRITE	0
#define I2C_FLAG_READ	1

char g_laser_buf[10] = {0};

static int g_work_flag = 0;

/******************************************************************************
 * extern functions
*******************************************************************************/

static const struct i2c_device_id vl6180_i2c_id[] = { {VL6180_DEV_NAME, 0}, {} };
struct i2c_board_info __initdata i2c_vl6180={ I2C_BOARD_INFO("vl6180", (0x29))};

static int vl6180_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int vl6180_i2c_remove(struct i2c_client *client);
static int vl6180_i2c_detect(struct i2c_client *client, struct i2c_board_info *info);
static int vl6180_i2c_suspend(struct i2c_client *client, pm_message_t msg);
static int vl6180_i2c_resume(struct i2c_client *client);

static int vl6180_enable(int enable);
static int vl6180_reset(struct platform_device *pdev, int reset);
static int vl6180_offset_calibration(void);
static int vl6180_get_range(void);
static int vl6180_cross_talk_calibration(void);
static int vl6180_check_chipID(void);

static struct pinctrl *pinctrl1;
static struct pinctrl_state *iraf_en_output1;
static struct pinctrl_state *iraf_en_output0;

static int   temp_sensordata = 0x62;

#ifdef CONFIG_OF
static const struct of_device_id i2c_iraf_of_match[] = {
	{.compatible = "mediatek,IRAF"},
	{},
};
#endif

static struct i2c_driver vl6180_i2c_driver = {
	.probe = vl6180_i2c_probe,
	.remove = vl6180_i2c_remove,
	.detect = vl6180_i2c_detect,
	.suspend = vl6180_i2c_suspend,
	.resume = vl6180_i2c_resume,
	.id_table = vl6180_i2c_id,
	.driver = {
		   .name = VL6180_DEV_NAME,
			#ifdef CONFIG_OF
			.of_match_table = i2c_iraf_of_match,
			#endif
		   },
};

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
static struct i2c_client *vl6180_i2c_client;
static struct platform_device *g_pdev;

static int vl6180_init(void);
static int vl6180_remove(void);
/*----------------------------------------------------------------------------*/
static DEFINE_MUTEX(vl6180_mutex);

int vl6180_i2c_read_sensor(struct i2c_client *client, char *buf, int count)
{
	int res = 0;
	mutex_lock(&vl6180_mutex);
	client->addr &= I2C_MASK_FLAG;

	res = i2c_master_send(client, buf, count>>8);
	client->addr &= I2C_MASK_FLAG;

	if (res < 0)
		goto EXIT_ERR;
		
		
	res = i2c_master_recv(client, buf, count&0xFF);
    if (res != 1) 
    {
        IRAF_ERR("[IRAF] I2C read failed!!\n");
        return -1;
    }
    mutex_unlock(&vl6180_mutex);
	return res;
EXIT_ERR:
	mutex_unlock(&vl6180_mutex);
	IRAF_ERR("vl6180_i2c_master_operate fail\n");
	return res;
}

int vl6180_i2c_write_sensor(struct i2c_client *client, char *buf, int count)
{
	int res = 0;
	mutex_lock(&vl6180_mutex);
	client->addr &= I2C_MASK_FLAG;

	res = i2c_master_send(client, buf, count);
	client->addr &= I2C_MASK_FLAG;

	if (res < 0)
		goto EXIT_ERR;
	mutex_unlock(&vl6180_mutex);
	return res;
EXIT_ERR:
	mutex_unlock(&vl6180_mutex);
	IRAF_ERR("vl6180_i2c_master_operate fail\n");
	return res;
}

static int vl6180_write_reg(struct i2c_client *client, int addr, int data)
{
	u8 databuf[3];
	
	databuf[0] = addr >> 8;
	databuf[1] = addr & 0xFF;
	databuf[2] = data & 0xFF; 
	
	vl6180_i2c_write_sensor(client, databuf, 0x3);  

	return 0;
}

/*----------------------------------------------------------------------------*/
static int vl6180_open(struct inode *inode, struct file *file)
{
	int ret = 0;

	return ret;
}
/*----------------------------------------------------------------------------*/
static int vl6180_release(struct inode *inode, struct file *file)
{
	
	return 0;
}
/*----------------------------------------------------------------------------*/


static long vl6180_unlocked_ioctl(struct file *file, unsigned int cmd,unsigned long arg)

{
	void __user *argp = (void __user *)arg;
	int enable = 0;
	int reset  = 0;
	int calibration_mode = 0;
	int      range_value = 0;
	int     factory_test = 0;
	
	printk("[vl6180] %s\n", __func__);
	switch (cmd)
	{
		case KDIRAFIOC_T_OPEN:
			
			break;
		case KDIRAFIOC_T_CLOSE:
		
			break;
		case KDIRAFIOC_T_RESET:
			printk("[vl6180] KDIRAFIOC_T_RESET\n");
			if(argp == NULL)
			{
				printk(KERN_ERR "IO parameter pointer is NULL!\r\n");
				break;
			}
			if(copy_from_user(&reset, argp, sizeof(reset)))
			{
				printk("copy_from_user failed.");
				return -EFAULT;
			}
			else
			{
				vl6180_reset(g_pdev, reset);
			}
			break;
		case KDIRAFIOC_T_ENABLE:
			printk("[vl6180] KDIRAFIOC_T_ENABLE\n");
			if(argp == NULL)
			{
				printk(KERN_ERR "IO parameter pointer is NULL!\r\n");
				break;
			}
			if(copy_from_user(&enable, argp, sizeof(enable)))
			{
				printk("[vl6180]copy_from_user failed.");
				return -EFAULT;
			}
			else
			{
				printk("[vl6180]copy_from_user success.");
				vl6180_enable(enable);
				
				g_work_flag = enable;				
			}

			break;
		case KDIRAFIOC_T_GET_RANGE:
			printk("[vl6180] KDIRAFIOC_T_GET_RANGE\n");
			range_value = vl6180_get_range();
			if(copy_to_user(argp, &range_value, sizeof(range_value)))
			{
				printk(KERN_ERR "copy_to_user failed.");
				return -EFAULT;
			}
			break;
		case KDIRAFIOC_T_CALIBRATION:
		    if(argp == NULL)
			{
				printk(KERN_ERR "IO parameter pointer is NULL!\r\n");
				break;
			}
			if(copy_from_user(&calibration_mode, argp, sizeof(enable)))
			{
				printk("copy_from_user failed.");
				return -EFAULT;
			}
			if (calibration_mode)
			{
				if (vl6180_offset_calibration())
				printk("[vl6180] offet calibration success!\n");
			}
			else
			{
				if (vl6180_cross_talk_calibration())
					printk("[vl6180] cross talk calibration success!\n");
			}
			break;
		case KDIRAFIOC_T_FACTORY_TEST:
			printk("[vl6180] KDIRAFIOC_T_FACTORY_TEST\n");
			factory_test = vl6180_check_chipID();
			if(copy_to_user(argp, &factory_test, sizeof(factory_test)))
			{
				printk(KERN_ERR "copy_to_user failed.");
				return -EFAULT;
			}
			break;
		default:
			printk(KERN_ERR "command err!\n");
			break;
	}

	return 0;
}

#ifdef CONFIG_COMPAT
static long vl6180_compat_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	long ret = 0;
	
	void __user *arg64 = compat_ptr(arg);
	
	if(!file->f_op || !file->f_op->unlocked_ioctl)
	{
		printk(KERN_ERR "file->f_op OR file->f_op->unlocked_ioctl is null!\n");
		return -ENOTTY;
	}
	
	switch(cmd)
	{
		case KDIRAFIOC_T_OPEN:
			ret = file->f_op->unlocked_ioctl(file, KDIRAFIOC_T_OPEN, (unsigned long)arg64);
			if(ret < 0)
			{
				printk(KERN_ERR "COMPAT_KDIRAFIOC_T_OPEN is failed!\n");
			}
			break;
		case KDIRAFIOC_T_CLOSE:
			ret = file->f_op->unlocked_ioctl(file, KDIRAFIOC_T_CLOSE, (unsigned long)arg64);
			if(ret < 0)
			{
				printk(KERN_ERR "COMPAT_KDIRAFIOC_T_CLOSE is failed!\n");
			}
			break;
		case KDIRAFIOC_T_RESET:
			ret = file->f_op->unlocked_ioctl(file, KDIRAFIOC_T_RESET, (unsigned long)arg64);
			if(ret < 0)
			{
				printk(KERN_ERR "COMPAT_KDIRAFIOC_T_RESET is failed!\n");
			}
			break;
		case KDIRAFIOC_T_ENABLE:
			ret = file->f_op->unlocked_ioctl(file, KDIRAFIOC_T_ENABLE, (unsigned long)arg64);
			if(ret < 0)
			{
				printk(KERN_ERR "COMPAT_KDIRAFIOC_T_ENABLE is failed!\n");
			}
			break;
		case KDIRAFIOC_T_GET_RANGE:
			ret = file->f_op->unlocked_ioctl(file, KDIRAFIOC_T_GET_RANGE, (unsigned long)arg64);
			if(ret < 0)
			{
				printk(KERN_ERR "KDIRAFIOC_T_GET_RANGE is failed!\n");
			}
			break;
		case KDIRAFIOC_T_CALIBRATION:
			ret = file->f_op->unlocked_ioctl(file, KDIRAFIOC_T_GET_RANGE, (unsigned long)arg64);
			if(ret < 0)
			{
				printk(KERN_ERR "KDIRAFIOC_T_GET_RANGE is failed!\n");
			}
			break;
		case KDIRAFIOC_T_FACTORY_TEST:
			ret = file->f_op->unlocked_ioctl(file, KDIRAFIOC_T_FACTORY_TEST, (unsigned long)arg64);
			if(ret < 0)
			{
				printk(KERN_ERR "KDIRAFIOC_T_FACTORY_TEST is failed!\n");
			}
		default:
			printk(KERN_ERR "%s not supported = 0x%04x", __FUNCTION__, cmd);
			break;		
		}
		return ret;
}

#endif

static struct file_operations vl6180_fops = {
	//.owner = THIS_MODULE,
	.open = vl6180_open,
	.release = vl6180_release,
	.unlocked_ioctl = vl6180_unlocked_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = vl6180_compat_ioctl,
#endif
};

static struct miscdevice vl6180_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "iraf",
    .fops = &vl6180_fops,
};

static int vl6180_init_calibration(void)
{
	u8 databuf[3] = {0};
	
	databuf[0] = VL6180_REG_PART_TO_PART >> 8;
	databuf[1] = VL6180_REG_PART_TO_PART & 0xFF;
	databuf[2] = 0;
	
	vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);
	databuf[0] = databuf[0] / 3;
	vl6180_write_reg(vl6180_i2c_client, VL6180_REG_PART_TO_PART, databuf[0]);
	
	databuf[0] = VL6180_REG_IGNORE_THRESHOLD >> 8;
	databuf[1] = VL6180_REG_IGNORE_THRESHOLD & 0xFF;
	databuf[2] = 0;
	
	vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);
	if (databuf[0])
	{
		vl6180_write_reg(vl6180_i2c_client, VL6180_REG_RANGE_AMB_HIGH , databuf[0]);
	}
	
	databuf[0] = VL6180_REG_BLOCK_THRESHOLD >> 8;
	databuf[1] = VL6180_REG_BLOCK_THRESHOLD & 0xFF;
	databuf[2] = 0;
	
	vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);
	if (databuf[0])
	{
		vl6180_write_reg(vl6180_i2c_client, VL6180_REG_RANGE_AMB_LOW , databuf[0]);
	}
	
	return 0;
}

static int vl6180_init_client(struct i2c_client *client)
{
	printk("[mcz]Init start\n");
#if 0
	vl6180_write_reg(client, 0x207, 0x01);
	vl6180_write_reg(client, 0x208, 0x01);
	vl6180_write_reg(client, 0x133, 0x01);
	vl6180_write_reg(client, 0x096, 0x00);
	vl6180_write_reg(client, 0x097, 0xFD);
	vl6180_write_reg(client, 0x0E3, 0x00);
	vl6180_write_reg(client, 0x0E4, 0x04);
	vl6180_write_reg(client, 0x0E5, 0x02);
	vl6180_write_reg(client, 0x0E6, 0x01);
	vl6180_write_reg(client, 0x0E7, 0x03);
	vl6180_write_reg(client, 0x0F5, 0x02);
	vl6180_write_reg(client, 0x0D9, 0x05);
	vl6180_write_reg(client, 0x0DB, 0xCE);
	vl6180_write_reg(client, 0x0DC, 0x03);
	vl6180_write_reg(client, 0x0DD, 0xF8);
	vl6180_write_reg(client, 0x09F, 0x00);
	vl6180_write_reg(client, 0x0A3, 0x3C);
	vl6180_write_reg(client, 0x0B7, 0x00);
	vl6180_write_reg(client, 0x0BB, 0x3C);
	vl6180_write_reg(client, 0x0B2, 0x09);
	vl6180_write_reg(client, 0x0CA, 0x09);
	vl6180_write_reg(client, 0x198, 0x01);
	vl6180_write_reg(client, 0x1B0, 0x17);
	vl6180_write_reg(client, 0x1AD, 0x00);
	vl6180_write_reg(client, 0x0FF, 0x05);
	vl6180_write_reg(client, 0x100, 0x05);
	vl6180_write_reg(client, 0x199, 0x05);
	vl6180_write_reg(client, 0x109, 0x07);
	vl6180_write_reg(client, 0x10A, 0x30);
	vl6180_write_reg(client, 0x03F, 0x46);
	vl6180_write_reg(client, 0x1A6, 0x1B);
	vl6180_write_reg(client, 0x1AC, 0x3E);
	vl6180_write_reg(client, 0x1A7, 0x1F);
	vl6180_write_reg(client, 0x103, 0x01);
	vl6180_write_reg(client, 0x030, 0x00);
	
	vl6180_write_reg(client, 0x01B, 0x0A);
	vl6180_write_reg(client, 0x03E, 0x0A);
	vl6180_write_reg(client, 0x131, 0x04);
	vl6180_write_reg(client, 0x011, 0x10);
	vl6180_write_reg(client, 0x014, 0x24);
	vl6180_write_reg(client, 0x031, 0xFF);
	vl6180_write_reg(client, 0x0D2, 0x01);
	vl6180_write_reg(client, 0x0F2, 0x01);		
	
//******    Extended range settings   ********//	
#else	
	vl6180_write_reg(client, 0x207, 0x01);
	vl6180_write_reg(client, 0x208, 0x01);
	vl6180_write_reg(client, 0x133, 0x01);
	vl6180_write_reg(client, 0x096, 0x00);
	vl6180_write_reg(client, 0x097, 0x54);
	vl6180_write_reg(client, 0x0E3, 0x00);
	vl6180_write_reg(client, 0x0E4, 0x04);
	vl6180_write_reg(client, 0x0E5, 0x02);
	
	vl6180_write_reg(client, 0x0E6, 0x01);
	vl6180_write_reg(client, 0x0E7, 0x03);
	vl6180_write_reg(client, 0x0F5, 0x02);
	vl6180_write_reg(client, 0x0D9, 0x05);
	vl6180_write_reg(client, 0x0DB, 0xCE);
	vl6180_write_reg(client, 0x0DC, 0x03);
	vl6180_write_reg(client, 0x0DD, 0xF8);
	vl6180_write_reg(client, 0x09F, 0x00);
	
	vl6180_write_reg(client, 0x0A3, 0x28);
	vl6180_write_reg(client, 0x0B7, 0x00);
	vl6180_write_reg(client, 0x0BB, 0x28);
	vl6180_write_reg(client, 0x0B2, 0x09);
	vl6180_write_reg(client, 0x0CA, 0x09);
	vl6180_write_reg(client, 0x198, 0x01);
	vl6180_write_reg(client, 0x1B0, 0x17);
	vl6180_write_reg(client, 0x1AD, 0x00);
	
	vl6180_write_reg(client, 0x0FF, 0x05);
	vl6180_write_reg(client, 0x100, 0x05);
	vl6180_write_reg(client, 0x199, 0x05);
	vl6180_write_reg(client, 0x109, 0x07);
	vl6180_write_reg(client, 0x10A, 0x30);
	vl6180_write_reg(client, 0x03F, 0x46);
	vl6180_write_reg(client, 0x1A6, 0x1B);
	vl6180_write_reg(client, 0x1AC, 0x3E);
	
	vl6180_write_reg(client, 0x1A7, 0x1F);
	vl6180_write_reg(client, 0x103, 0x01);
	vl6180_write_reg(client, 0x030, 0x00);
	vl6180_write_reg(client, 0x01B, 0x0A);
	vl6180_write_reg(client, 0x03E, 0x0A);
	vl6180_write_reg(client, 0x131, 0x04);
	vl6180_write_reg(client, 0x011, 0x10);
	vl6180_write_reg(client, 0x014, 0x24);
	
	vl6180_write_reg(client, 0x031, 0xFF);
	vl6180_write_reg(client, 0x011, 0x10);
	vl6180_write_reg(client, 0x014, 0x24);
	vl6180_write_reg(client, 0x031, 0xFF);
	vl6180_write_reg(client, 0x0D2, 0x01);
	vl6180_write_reg(client, 0x0F2, 0x01);
	vl6180_write_reg(client, 0x01C, 0x3F);
	vl6180_write_reg(client, 0x02C, 0xFF);
#endif
	printk("[mcz]Init end\n");
	vl6180_init_calibration();

	return 0;
}

static int vl6180_get_range(void)
{

	u8 databuf[3] = {0};
	int range_value = 0;
	printk("[vl6180] %s\n", __func__);
	databuf[0] = VL6180_REG_RANGE_VALUE >> 8;
	databuf[1] = VL6180_REG_RANGE_VALUE & 0xFF;
	databuf[2] = 0;
	
	vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);
	
	if (databuf[0] < 0xFF)
		range_value = databuf[0] * 3;
	else
		range_value = 500;
	
	return range_value;
}

static int vl6180_offset_calibration(void)
{
	int i = 0;
	int raw_sum = 0;
	u8 databuf[3] = {0};
	int offset = 0;
	
	//--- Manual offset calibration procedure start ---//
	
	vl6180_write_reg(vl6180_i2c_client, 0x024, 0x00);   //Clear the system calibration procedure
	
	for (i = 0; i < 20; i++)
	{
		databuf[0] = VL6180_REG_RAW_VALUE >> 8;
		databuf[1] = VL6180_REG_RAW_VALUE & 0xFF;
		databuf[2] = 0;
		
		vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);
		mdelay(10);
		raw_sum += databuf[0];
	}
	
	raw_sum = raw_sum / 20;
	offset = (100 - (raw_sum * 3)) / 3;                  //Calculate the offset required
	
	vl6180_write_reg(vl6180_i2c_client, 0x024, offset);  //Apply offset
	IRAF_FUN("calculate the offset is %x\n", offset);   
	
	//--- Manual offset calibration procedure end ---//
		
	return 1;
}

static int vl6180_cross_talk_calibration(void)
{
	int i = 0;
	int raw_sum = 0;
	u8 databuf[3] = {0};
	int cross_talk = 0;
	
	//---  Cross talk calibration procedure start ---//
	
	vl6180_write_reg(vl6180_i2c_client, 0x01e, 0x00);   //Ensure SYSRANGE_CROSSTALK_COMPENSATION_RATE is set to zero
	for (i = 0; i < 20; i++)
	{
		databuf[0] = VL6180_REG_RAW_VALUE >> 8;
		databuf[1] = VL6180_REG_RAW_VALUE & 0xFF;
		databuf[2] = 0;
		
		vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);
		mdelay(10);
		raw_sum += databuf[0];
	}
	
	raw_sum = raw_sum / 20;
	databuf[0] = VL6180_REG_RETURN_RATE >> 8;
	databuf[1] = VL6180_REG_RETURN_RATE & 0xFF;
	databuf[2] = 0;
	vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201); 
	cross_talk = databuf[0] * (1- raw_sum*3/400);             //Calculate the cross talk
	
	vl6180_write_reg(vl6180_i2c_client, 0x01e, cross_talk);   //Apply crosstalk
	IRAF_FUN("calculate the cross_talk is %x\n", cross_talk);
	   
	//---  Cross talk calibration procedure end  ---//	
	return 1;
}

static int vl6180_check_chipID(void)
{
	u8 databuf[3] = {0};
	u8 retry = 0;
	
	databuf[0] = VL6180_REG_ID >> 8;
	databuf[1] = VL6180_REG_ID & 0xFF;
	databuf[2] = 0x00;
	
	while (retry++ < 5)
	{
		vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);
    	msleep(10);
	}	
	IRAF_FUN("Get iD = 0x%x\n", databuf[0]);
	
	if (VL6180_CHIP_ID == databuf[0])
	{
		return VL6180_CHIP_ID;
	}
	
	return VL6180_ERR;
}


static ssize_t agold_laser_show(struct kobject *kobj, struct kobj_attribute *attr,char *buf)
{
	return snprintf(buf,sizeof(g_laser_buf), g_laser_buf);
}

static ssize_t agold_laser_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	memset(g_laser_buf, 0, sizeof(g_laser_buf));
	snprintf(g_laser_buf, sizeof(g_laser_buf),buf);
	return count;
}

static struct kobj_attribute agold_laser_attribute = {
	.attr = {.name = "laser", .mode = 0666},
	.show = agold_laser_show,
	.store = agold_laser_store,
};
static int agold_create_laser_file(void)
{
	
	int ret=0;
	
	struct kobject * kobject_laser;
	kobject_laser = kobject_create_and_add("agold_laser", NULL);
	if (! kobject_laser)
	{
		printk("create laser_file error!\n");
		return -1;
	}
	ret = sysfs_create_file(kobject_laser, &agold_laser_attribute.attr);
	if (ret) {
		kobject_put(kobject_laser);
		printk("create file error\n");
		return -1;
	}
	
	strcpy(g_laser_buf,"1");

	return 0;
}

/*-----------------------------------i2c operations----------------------------------*/
static int vl6180_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int err = 0;
	
	mutex_lock(&vl6180_mutex);
	vl6180_i2c_client = client;
	vl6180_i2c_client->timing = 100;
	mutex_unlock(&vl6180_mutex);
	
	err = vl6180_check_chipID();	
	
	if (err == VL6180_ERR)
	    return VL6180_ERR;
	
	err = vl6180_init_client(client);
	if (err)
		return VL6180_ERR;
		
	err = misc_register(&vl6180_device);
	if(err)
	{
		printk(KERN_ERR "vl6180_device register failed\n");
		return VL6180_ERR;	
	}
		
	agold_create_laser_file();
	
	return 0;
	
}

static int vl6180_i2c_remove(struct i2c_client *client)
{
	
	return 0;

}

static int vl6180_i2c_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	strcpy(info->type, VL6180_DEV_NAME);
	
	return 0;
}

static int vl6180_i2c_suspend(struct i2c_client *client, pm_message_t msg)
{

	if (g_work_flag)
	{
		vl6180_enable(0);
		
		vl6180_reset(g_pdev, 0);
	}

	return 0;
}

static int vl6180_i2c_resume(struct i2c_client *client)
{

	if (g_work_flag)
	{
		vl6180_enable(1);
		
		vl6180_reset(g_pdev, 1);	
	}

	return 0;
}

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
static int vl6180_remove(void)
{
	i2c_del_driver(&vl6180_i2c_driver);
	
	return 0;
}


static int vl6180_enable(int enable)
{
	printk("[vl6180] %s enable = %d\n", __func__, enable);
	
	
	if (enable)
	{
		vl6180_write_reg(vl6180_i2c_client, 0x2D, 0x00);
		vl6180_write_reg(vl6180_i2c_client, VL6180_REG_MODE, 0x00);
		mdelay(10);
		vl6180_write_reg(vl6180_i2c_client, VL6180_REG_MODE, 0x03);
	}
	else
	{
		vl6180_write_reg(vl6180_i2c_client, VL6180_REG_MODE, 0x00);
	}
	
	printk("[vl6180] %s enable ss = %d\n", __func__, enable);
	
	return 0;
	
}

static int vl6180_power_on(void)
{

	/*--------------------------------------------*/
	/*  C239 Project power pin connect to VIO28   */
	/*           So, no power on                  */
	/*--------------------------------------------*/
	
	return VL6180_SUCCESS;
}

static int vl6180_power_off(void)
{

	/*--------------------------------------------*/
	/*  C239 Project power pin connect to VIO28   */
	/*           So, no power off                 */
	/*--------------------------------------------*/
		
	return VL6180_SUCCESS;
}

/*----------------------------------------------------------------------------*/

static int vl6180_reset(struct platform_device *pdev, int reset)
{
	int ret = 0;

	pinctrl1 = devm_pinctrl_get(&pdev->dev);
	if (IS_ERR(pinctrl1)) {
		ret = PTR_ERR(pinctrl1);
		dev_err(&pdev->dev, "fwq Cannot find  pinctrl1!\n");
		return ret;
	}
	printk("[vl6180] reset = %d\n", reset);
	if (reset == 1)
	{
	
		iraf_en_output1 = pinctrl_lookup_state(pinctrl1, "iraf_en_output1");
		if (IS_ERR(pinctrl1)) {
			ret = PTR_ERR(iraf_en_output1);
			dev_err(&pdev->dev, "fwq Cannot find pinctrl iraf_en_output1 %d!\n", ret);
		}

		pinctrl_select_state(pinctrl1, iraf_en_output1);
	}
	else
	{
		iraf_en_output0 = pinctrl_lookup_state(pinctrl1, "iraf_en_output0");
		if (IS_ERR(pinctrl1)) {
			ret = PTR_ERR(iraf_en_output0);
			dev_err(&pdev->dev, "fwq Cannot find pinctrl iraf_en_output0 %d!\n", ret);
		}

		pinctrl_select_state(pinctrl1, iraf_en_output0);
	}

	return 0;
}
static ssize_t  agold_write_proc(struct file *file, const char *buffer, size_t count,
                                     loff_t *data)
{
    
    char regBuf[64] = {'\0'};
    int sensorReg = 0;
    int sensorData = 0;
    
    u32 u4CopyBufSize = (count < (sizeof(regBuf) - 1)) ? (count) : (sizeof(regBuf) - 1); 

    if (copy_from_user(regBuf, buffer, u4CopyBufSize))
    return -EFAULT;

    if (sscanf(regBuf, "%x %x",  &sensorReg, &sensorData) == 2) 
    {
   		vl6180_write_reg(vl6180_i2c_client, sensorReg, sensorData);
    }
    else if (sscanf(regBuf, "%x", &sensorReg) == 1) 
    {
    	temp_sensordata = sensorReg;
    }

    return count;
}
static ssize_t agold_read_proc(struct file *file, char __user *page, size_t size, loff_t *ppos)

{
    char *ptr = page;
    u8 databuf[3];
    
    if (*ppos)  // CMD call again
    {
        return 0;
    }
    
    
    ptr += sprintf(ptr, "==== iraf init value====\n");

    databuf[0] = temp_sensordata >> 8;
	databuf[1] = temp_sensordata & 0xFF;
	
	vl6180_i2c_read_sensor(vl6180_i2c_client, databuf, 0x201);

    ptr += sprintf(ptr, "%d mm", databuf[0]);
    ptr += sprintf(ptr, "\n");

    *ppos += ptr - page;
    
    return (ptr - page);
}

static struct file_operations ft_debug_fops = { 
    .read  = agold_read_proc,
    .write = agold_write_proc
};

static int iraf_probe(struct platform_device *pdev)
{
	int err = 0;
	g_pdev = pdev;
	
	vl6180_power_on();
	vl6180_reset(pdev, 1);
	
	err = i2c_add_driver(&vl6180_i2c_driver);
	if (err) 
	{
		IRAF_ERR("add driver error\n");
		return VL6180_ERR_I2C;
	}
	
	proc_create("iraf_debug", 0664, NULL, &ft_debug_fops);
	
	return 0;
}

static int iraf_remove(struct platform_device *pdev)
{
	vl6180_power_off();
	//vl6180_reset(pdev, 0);
	
	return 0;
}

#ifdef CONFIG_OF
struct of_device_id iraf_of_match[] = {
	{ .compatible = "mediatek, iraf", },
	{},
};
#endif
static struct platform_driver iraf_driver = {
	.remove = iraf_remove,
	.shutdown = NULL,
	.probe = iraf_probe,
	.driver = {
		.name = "iraf",
		#ifdef CONFIG_OF
		.of_match_table = iraf_of_match,
		#endif
	},
};
/*----------------------------------------------------------------------------*/
static int __init vl6180_init(void)
{

	i2c_register_board_info(IRAF_I2C_BUS_NUM, &i2c_vl6180, 1);
	
	if (platform_driver_register(&iraf_driver))
	{
		IRAF_ERR("platform_driver_registe hall failed!\n");
		return -1;
	}

	return 0;
}

/*----------------------------------------------------------------------------*/
static void __exit vl6180_exit(void)
{
	vl6180_remove();
}

/*----------------------------------------------------------------------------*/
module_init(vl6180_init);
module_exit(vl6180_exit);
/*----------------------------------------------------------------------------*/
MODULE_AUTHOR("Alex.Ma");
MODULE_DESCRIPTION("vl6180 driver");
MODULE_LICENSE("GPL");
