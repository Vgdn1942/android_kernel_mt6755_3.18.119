/* JMT101 Swipe Sensor Driver
 *
 * Copyright (c) 2014 J-Metrics <darwinyu@j-metrics.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License Version 2
 * as published by the Free Software Foundation.
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/spi/spi.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/kernel.h>
#include <linux/poll.h>
#include <linux/sched.h>
#include <linux/irq.h>
#include <asm/irq.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/spi/spi.h>
#include <../../../../../../kernel-3.18/drivers/spi/mediatek/mt6755/mt_spi.h>

/* MTK header */
#include "mt_spi.h"
#include "mt_spi_hal.h"
#include "mt_gpio.h"
#include "mach/gpio_const.h"


#define _ARM64
#define CONFIG_ARCH_MTXXXX
#include <linux/gpio.h>

#include <linux/delay.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/poll.h>
#include <linux/spinlock.h>
#include <linux/mm.h>
#include <linux/ioctl.h>

#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#else
#include <linux/notifier.h>
#endif

#ifdef CONFIG_COMPAT
#include <linux/compat.h>
#endif

#ifdef CONFIG_OF
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#endif

/* -------------------------------------------------------------------- */
/* jmt101 basic definition settings                                 */
/* -------------------------------------------------------------------- */
#define DRIVER_VERSION                  "1.1.0.3"
#define JMT101_DEV_NAME                 "jmt101"
#define JMT101_CLASS_NAME               "fpsensor"
#define JMT101_WORKER_THREAD_NAME       "jmt101worker"
#define JMT101_WAIT_INT_THREAD_NAME	    "jmt101_wait_int_thread"
#define JMT101_INPUT_DEV_NAME           "jmt-input"
#define JMT101_WAKEUP_KEY               KEY_WAKEUP
#define JMT101_CAMERA_KEY               KEY_CAMERA

/* -------------------------------------------------------------------- */
/* jmt sensor commands and registers                                 */
/* -------------------------------------------------------------------- */
#define JMT101_TRACE_MASK              0xFF
#define JMT101_TRACE_DPATTERN          0x01
#define JMT101_TRACE_SPATTERN          0x02
#define JMT101_TRACE_DEVERR            0x04

/* -------------------------------------------------------------------- */
/* jmt101 driver constants                                              */
/* -------------------------------------------------------------------- */
#define JMT101_MAJOR                   235
#define FRAME_MAX_LEN                   16384
#define JMT_SPI_CLOCK_SPEED         (16 * 1000 * 1000)
#define JMT_VER_ADDR                0xff
#define JMT_HEARTBEAT_COUNT         8000
#define JMT_HIST_LEN                16
#define JMT_HISTOGRAM_TOO_WHITE     950
#define JMT_TOGGLE_RESET            0x01
#define JMT_INTENSITY_TOO_WHITE     1
#define JMT_INTENSITY_WHITE         60
#define JMT_INTENSITY_MEAN_WHITE    160
#define JMT_INTENSITY_NORMAL        180
#define JMT_INTENSITY_MEAN_BLACK    200
#define JMT_INTENSITY_BLACK         245
#define JMT_INTENSITY_TOO_BLACK     255

#define JMT_TOGGLE_RESET            0x01
#define JMT_SWITCH_CALIBRATE        0x01
#define JMT_SWITCH_TIMESTAMP        0x02
#define JMT_SWITCH_PARAMETER        0x04

#define JMT_REG_FRAME_DATA          0xD0
#define JMT_REG_SOFTWARE_RESET      0xD1
#define JMT_REG_MODE_SELECT         0xD2
#define JMT_REG_STATUS              0xD3
#define JMT_REG_POWER_CTRL          0xE4
#define JMT_REG_VER_ID_MINOR        0xFD
#define JMT_REG_VER_ID_MAJOR        0xFF

#define JMT_IMAGE_BUFFER_SIZE       (256 * 128 * 8 + 1)
//#define JMT_TX_BUFFER_SIZE          (128 * 128)
#define JMT_TX_BUFFER_SIZE          0//(128 * 128)
#define JMT_FRAME_READY_LIMIT       5000
#define JMT101A_FRAME_WIDTH             128
#define JMT101A_POS_GAIN                (JMT101A_FRAME_WIDTH - 2)
#define JMT101A_POS_VRT                 (JMT101A_POS_GAIN + 1)
#define JMT101A_POS_VRB                 (JMT101A_POS_GAIN + 2)
#define JMT101A_POS_OFFSET              (JMT101A_POS_GAIN + 3)
#define JMT101A_POS_TIMESTAMP           (JMT101A_FRAME_WIDTH + JMT101A_FRAME_WIDTH - 2)
#define JMT101B_POS_GAIN                (JMT101A_FRAME_WIDTH - 1)
#define JMT101B_POS_VRT                 (JMT101A_FRAME_WIDTH*2 - 1)
#define JMT101B_POS_VRB                 (JMT101A_FRAME_WIDTH*3 - 1)
#define JMT101B_POS_OFFSET              (JMT101A_FRAME_WIDTH*4 - 1)
#define JMT101B_POS_TIMESTAMP1          (JMT101A_FRAME_WIDTH*5 - 1)
#define JMT101B_POS_TIMESTAMP2          (JMT101A_FRAME_WIDTH*6 - 1)
#define JMT101B_POS_TIMESTAMP3          (JMT101A_FRAME_WIDTH*7 - 1)
#define JMT101B_POS_TIMESTAMP4          (JMT101A_FRAME_WIDTH*8 - 1)
/* -------------------------------------------------------------------- */

#define JMT_BASE_IO_OFFSET              0
#define JMT101_IOCTL_MAGIC_NO           0xFC
#define JMT_IOCTL_BASE(x)               JMT_BASE_IO_OFFSET+x
#define JMT_IOCTL_START_CAPTURE         _IO(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(0))
#define JMT_IOCTL_ABORT_CAPTURE         _IO(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(1))
#define JMT_IOCTL_READ_REGISTER         _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(2), unsigned int)
#define JMT_IOCTL_WRITE_REGISTER        _IOW(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(3), unsigned int)
#define JMT_IOCTL_SOFT_RESET            _IOW(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(5), unsigned int)
#define JMT_IOCTL_INIT_REG              _IOW(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(6), unsigned int)
#define JMT_IOCTL_READ_ATTR             _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(9), unsigned int)
#define JMT_IOCTL_RV                    _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(10), unsigned int)
#define JMT_IOCTL_SET_REG               _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(11), unsigned int)
#define JMT_IOCTL_SET_OP                _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(12), unsigned int)
#define JMT_IOCTL_SET_CLOCK_SPEED       _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(13), unsigned int)
#define JMT_IOCTL_WRITE_ATTR            _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(14), unsigned int)
#define JMT_IOCTL_SET_VR                _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(15), unsigned int)
#define JMT_IOCTL_READ_RAW              _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(16), unsigned int)
#define JMT_IOCTL_READ_DATA             _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(17), unsigned int)
#define JMT_IOCTL_TEST_UEVENT           _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(18), unsigned int)
#define JMT_IOCTL_WAIT_TOUCH            _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(19), unsigned int)
#define JMT_IOCTL_CANCEL_WAIT_TOUCH     _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(20), unsigned int)
#define JMT_IOCTL_SET_SUSPEND           _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(21), unsigned int)
#define JMT_IOCTL_SYSTEM_WAKE_UP        _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(22), unsigned int)
#define JMT_IOCTL_SET_KEY_EVENT         _IOWR(JMT101_IOCTL_MAGIC_NO, JMT_IOCTL_BASE(23), unsigned int)

#define N_SPI_MINORS			32	/* ... up to 256 */
#define READ_MAX_SIZE 16385


/* -------------------------------------------------------------------- */
/* jmt101 data types                                                    */
/* -------------------------------------------------------------------- */
struct jmt101_platform_data {
    u32 irq_gpio;
    u32 reset_gpio;
};

static DECLARE_BITMAP(minors, N_SPI_MINORS);
struct sensor_attr{
    unsigned int    sensor_width;
    unsigned int    sensor_height;
    unsigned int    sensor_size;
    unsigned int    frame_width;
    unsigned int    frame_height;
    unsigned int    frame_size;
    unsigned int    max_frames;
    unsigned char   frame_ready_limit;
    unsigned long long  buffer_size;
    unsigned long long  buffer_limit;
    unsigned char   intensity_too_white;
    unsigned char   intensity_white;
    unsigned char   intensity_mean_white;
    unsigned char   intensity_normal;
    unsigned char   intensity_mean_black;
    unsigned char   intensity_black;
    unsigned char   intensity_too_black;
    unsigned char   vrt_vrb_gap;
    unsigned char   version;
    unsigned char   hw_dvr;
};

struct jmt_op{
    u8 creg;
    u8 cread;
    u8 cwrite;
};

#ifdef CONFIG_ARCH_MTXXXX
static struct mt_chip_conf spi_conf_mt6577 = {
   .setuptime = 3,
   .holdtime = 3,
   .high_time = 4,  // for mt6589, 100000khz/(4+4) = 125000khz
   .low_time = 4,
   .cs_idletime = 2,
   .ulthgh_thrsh = 0,
   .cpol = 1,
   .cpha = 1,
   .rx_mlsb = 1,
   .tx_mlsb = 1,
   .tx_endian = 0,
   .rx_endian = 0,
   .com_mod = DMA_TRANSFER,
   .pause = 0,
   .finish_intr = 1,
   .deassert = 0,
   .ulthigh = 0,
   .tckdly = 0,
};
#endif

enum {
   JMT101_THREAD_IDLE_MODE = 0,
   JMT101_THREAD_CAPTURE_MODE,
   JMT101_THREAD_NAV_MODE,
   JMT101_THREAD_EXIT
};
struct jmt101_data {
   struct spi_device *spi;
   struct class *class;
   struct device *device;
   struct cdev cdev;
   struct tasklet_struct tl;
   dev_t devno;
   u32 spi_speed;
   u32 reset_gpio;
   u32 irq_gpio;
   u32 irq;
   u32 data_offset;
   u32 avail_data;
   wait_queue_head_t waiting_data_avail;
   int interrupt_done;
   wait_queue_head_t waiting_interrupt_return;
   struct semaphore mutex;
   struct semaphore int_mutex;
   u8 *huge_buffer;
   u32 current_frame;
   int capture_done;
   int frame_retry;

#ifdef CONFIG_HAS_EARLYSUSPEND
   struct early_suspend early_suspend;
#endif
   struct jmt_op jop;
   struct sensor_attr sa;
   u32 wait_touch_exist;
   struct input_dev 	*input;
#ifdef CONFIG_QB_INT
   u32 handle;
#endif
 bool wakeup;
   // struct input_dev *input;
    spinlock_t		spi_lock;
    //struct wake_lock wake_lock;
    struct work_struct jmt_int_work;
    struct workqueue_struct * p_jmt_wq;
    struct list_head	device_entry;
    unsigned		users;
    struct pinctrl *pin_ctrl;

};


/* -------------------------------------------------------------------- */
/* global variables                                                     */
/* -------------------------------------------------------------------- */
static struct class *jmt_class = NULL;
struct img_data{
	unsigned int data_len;
	unsigned char* data;
};
enum {
   REG_GAIN,
   REG_VRT,
   REG_VRB,
   REG_DCOFFSET
};

static LIST_HEAD(device_list);
static DEFINE_MUTEX(device_list_lock);
static u8*  spi_common_buf = NULL;
static u8*  spi_reg;
static u8*  spi_cmd;
static u8*  spi_buf;
static u8   suspended;
u8 data_buf [READ_MAX_SIZE];
unsigned int g_data_len=0;
unsigned int g_data_len2=0;
int	cancel_flag = 0;
unsigned int fp_detect_irq = 0;
struct pinctrl *fp_pinctrl;
struct pinctrl_state *finger_rst_low = 0, *finger_rst_high = 0;
struct pinctrl_state *finger_power_low = 0, *finger_power_high = 0;
static unsigned int jmt_major = 0;
struct cdev jmt_cdev;
u8* jmt_tmp_buf = NULL;
u8* jmt_rd_buf  = NULL;
/* -------------------------------------------------------------------- */
/* 0xE0 Gain, 0xE1 VRT, 0xE2 VRB, 0xE6 DC offset                        */
/* -------------------------------------------------------------------- */

static u8 regs_table[][2] = {
   {0xE0, 0x00},
   {0xE1, 0x00},
   {0xE2, 0x00},
   {0xE6, 0x00}
};

/* -------------------------------------------------------------------- */
/* function prototypes                                                  */
/* -------------------------------------------------------------------- */
static int __init jmt101_init (void);
static void __exit jmt101_exit (void);
static int jmt101_probe (struct spi_device *spi);
static int jmt101_remove (struct spi_device *spi);
static int jmt101_suspend (struct device *dev);
static int jmt101_resume (struct device *dev);

static int jmt101_open (struct inode *inode, struct file *file);
static ssize_t jmt101_write (struct file *file, const char *buff, size_t count, loff_t *ppos);
static ssize_t jmt101_read (struct file *file, char *buff, size_t count, loff_t *ppos);
static int jmt101_release (struct inode *inode, struct file *file);
static unsigned int jmt101_poll (struct file *file, poll_table *wait);
static long jmt101_ioctl (struct file *filp, unsigned int cmd, unsigned long arg);
static long jmt101_compat_ioctl (struct file *filp, unsigned int cmd, unsigned long arg);

#ifdef CONFIG_HAS_EARLYSUSPEND
static void jmt101_early_suspend (struct early_suspend *h);
static void jmt101_late_resume (struct early_suspend *h);
#endif
static int jmt101_spi_rd_reg (struct jmt101_data *jmt101, u8 addr, u8 *value);
static int jmt101_spi_wr_reg (struct jmt101_data *jmt101, u8 addr, u8 value);

/* -------------------------------------------------------------------- */
/* External interface                                                   */
/* -------------------------------------------------------------------- */


static const struct dev_pm_ops jmt101_pm = {
   .suspend = jmt101_suspend,
   .resume = jmt101_resume
};

#ifdef CONFIG_OF
static const struct of_device_id jmt101_of_match[] = {
    {.compatible = "mediatek,fingerprint",},
    {},
};
#endif

static struct spi_driver jmt101_driver = {
   .driver = {
      .name = JMT101_DEV_NAME,
      .bus = &spi_bus_type,
      .owner = THIS_MODULE,
#ifdef CONFIG_OF
       .of_match_table = jmt101_of_match,
#endif
      .pm = &jmt101_pm,
   },
   .probe = jmt101_probe,
   .remove = jmt101_remove,
};

static const struct file_operations jmt101_fops = {
   .owner = THIS_MODULE,
   .open = jmt101_open,
   .write = jmt101_write,
   .read = jmt101_read,
   .release = jmt101_release,
   .poll = jmt101_poll,
   .unlocked_ioctl = jmt101_ioctl,
#ifdef CONFIG_COMPAT	//for platform 64bit
   .compat_ioctl = jmt101_compat_ioctl,
#endif
};


/* -------------------------------------------------------------------- */
/* devfs                                                                */
/* -------------------------------------------------------------------- */


/* -------------------------------------------------------------------- */
static int jmt101_spi_rd_reg (struct jmt101_data *jmt101, u8 addr, u8 *value)
{
    int error;

    struct spi_message m;

    struct spi_transfer tr_reg = {
        .cs_change = 1,
        .delay_usecs = 0,
        .speed_hz = jmt101->spi_speed,
        .tx_buf = spi_reg,
        .rx_buf = NULL,
        .len = 2,
        .tx_dma = 0,
        .rx_dma = 0,
        .bits_per_word = 8,
    };

    struct spi_transfer tr_dat = {
        .cs_change = 0,
        .delay_usecs = 0,
        .speed_hz = jmt101->spi_speed,
        .tx_buf = spi_cmd,
        .rx_buf = spi_buf,
        .len = 2,
        .tx_dma = 0,
        .rx_dma = 0,
        .bits_per_word = 8,
    };
    /* select register */
    // Charles edited, Date: 2014_0905
    //
    spi_reg[0] = jmt101->jop.creg;
    spi_reg[1] = addr;

    /* read value */
    // Charles edited, Date: 2014_0905
    spi_cmd[0] = jmt101->jop.cread;
    spi_cmd[1] = 0x00;
    spi_buf[1] = 0x00;

    spi_message_init (&m);
    spi_message_add_tail (&tr_reg, &m);
    spi_message_add_tail (&tr_dat, &m);

    error = spi_sync(jmt101->spi, &m);
    if (error) {
        //printk(KERN_ALERT "spi_sync failed: 0x%x\n", error);
        //dev_err (&jmt101->spi->dev, "spi_sync failed.\n");
    }
    *value = spi_buf[1];
    return (error);
}

/* -------------------------------------------------------------------- */
static int jmt101_spi_wr_reg (struct jmt101_data *jmt101, u8 addr, u8 value)
{
   int error;

   struct spi_message m;

   struct spi_transfer tr_reg = {
      .cs_change = 1,
      .delay_usecs = 0,
      .speed_hz = jmt101->spi_speed,
      .tx_buf = spi_reg,
      .rx_buf = NULL,
      .len = 2,
      .tx_dma = 0,
      .rx_dma = 0,
      .bits_per_word = 8,
   };

   struct spi_transfer tr_dat = {
      .cs_change = 0,
      .delay_usecs = 0,
      .speed_hz = jmt101->spi_speed,
      .tx_buf = spi_cmd,
      .rx_buf = NULL,
      .len = 2,
      .tx_dma = 0,
      .rx_dma = 0,
      .bits_per_word = 8,
   };

   /* select register */
   spi_reg[0] = jmt101->jop.creg;
   spi_reg[1] = addr;

   /* write value */
   spi_cmd[0] = jmt101->jop.cwrite;
   spi_cmd[1] = value;

   spi_message_init (&m);
   spi_message_add_tail (&tr_reg, &m);
   spi_message_add_tail (&tr_dat, &m);

   error = spi_sync(jmt101->spi, &m);
   if (error) {
      //dev_err (&jmt101->spi->dev, "spi_sync failed.\n");
   }

   return (error);
}


// ......+.........+.........+.........+.........+.........+.........+.........+
/* up left -> down left, left -> right col by col                             */
// ......+.........+.........+.........+.........+.........+.........+.........+

/* -------------------------------------------------------------------- */
int jmt101_send_uevent(struct device* dev)
{
	struct kobject *jmt_kobj = &dev->kobj;
	char* uevent_env_str[2] = {"JMT101_STATE=WAKEUP", NULL};
	int ret = kobject_uevent_env(jmt_kobj, KOBJ_CHANGE, uevent_env_str);	
	if(ret){
		//dev_err(dev, "%s: Send uevent failed, ret=%d\n", __func__, ret);
	}

	return 0;
}

static void jmt_interrupt_work(struct work_struct *work)
{
    struct jmt101_data *jmt101 = container_of(work, struct jmt101_data, jmt_int_work);
    jmt101_send_uevent( &jmt101->spi->dev);
}
 
/* -------------------------------------------------------------------- */
irqreturn_t jmt101_interrupt (int irq, void *_jmt101)// < ---
{
   	struct jmt101_data *jmt101 = _jmt101;
   	//printk ("[jmt101]%s: send uevent\n", __func__);
   	jmt101_send_uevent(&jmt101->spi->dev);
   	return IRQ_NONE;
}

/* -------------------------------------------------------------------- */
static int jmt101_open (struct inode *inode, struct file *file)
{
    int error = -ENXIO;
    struct jmt101_data *jmt101;
    mutex_lock(&device_list_lock);
    list_for_each_entry(jmt101, &device_list, device_entry) {
        if (jmt101->devno == inode->i_rdev) {
            error = 0;
            break;
        }
    }
    
    if (error == 0) {
        jmt101->users++;
        file->private_data = jmt101;
        nonseekable_open(inode, file);
    }

    mutex_unlock(&device_list_lock);
    return error;
}

/* -------------------------------------------------------------------- */
static int jmt101_release (struct inode *inode, struct file *file)
{
    struct jmt101_data	*jmt101;
    //pr_err("%s %d\n",__func__,__LINE__);

    mutex_lock(&device_list_lock);
    jmt101 = file->private_data;
    file->private_data = NULL;

    jmt101->users--;
    if (!jmt101->users) {
        int		dofree;
        spin_lock_irq(&jmt101->spi_lock);
        dofree = (jmt101->spi == NULL);
        spin_unlock_irq(&jmt101->spi_lock);
        
        if (dofree)
            kfree(jmt101);
    }
    mutex_unlock(&device_list_lock);
   return (0);
}

/* -------------------------------------------------------------------- */
static ssize_t jmt101_read (struct file *file, char *buff,
        size_t count, loff_t *ppos)
{
   return -ENOTTY;
}

/* -------------------------------------------------------------------- */
static ssize_t jmt101_write (struct file *file, const char *buff,
   size_t count, loff_t *ppos)
{
   return -ENOTTY;
}

/* -------------------------------------------------------------------- */
static unsigned int jmt101_poll (struct file *file, poll_table *wait)
{
   unsigned int ret = 0;
   return ret;
}



#ifdef QC_INT
int qualcomm_read_data(struct jmt101_data* jmt101, unsigned long arg)
{
    int error;
    struct spi_message spi_mess;
    struct spi_transfer tr_reg;
    struct spi_transfer tr_dat1;
    long not_copy_len=0;
    
    if(!g_data_len){
        //dev_err (&jmt101->spi->dev, " data_len=%d, data_len2=%d, speed=%d\n", g_data_len, jmt101->spi_speed);
        return -1;
    }
    
    memset (&tr_reg, 0, sizeof(struct spi_transfer));
    /* select register */
    spi_reg[0] = jmt101->jop.creg;
    spi_reg[1] = JMT_REG_FRAME_DATA;
    tr_reg.cs_change = 1;
    tr_reg.delay_usecs = 0;
    tr_reg.speed_hz = jmt101->spi_speed;
    tr_reg.tx_buf   = spi_reg;
    tr_reg.rx_buf   = NULL;
    tr_reg.len      = 2;
    spi_message_init (&spi_mess);
    spi_message_add_tail (&tr_reg, &spi_mess);
    error = spi_sync(jmt101->spi, &spi_mess);
    if (error) {
        //dev_err (&jmt101->spi->dev, "spi_sync tr_reg failed.\n");
        return error;
    }
    
    memset (spi_cmd, 0x00, JMT_TX_BUFFER_SIZE+1);
    spi_cmd[0] = jmt101->jop.cread;
    spi_cmd[1] = 0xFF;
    memset (data_buf, 0x00, READ_MAX_SIZE);
    memset (&tr_dat1, 0, sizeof(struct spi_transfer));
    tr_dat1.cs_change = 1;
    tr_dat1.delay_usecs = 0;
    tr_dat1.speed_hz    = jmt101->spi_speed;
    tr_dat1.tx_buf      = spi_cmd;
    tr_dat1.rx_buf      = data_buf; 
    tr_dat1.len         = g_data_len+1;
    spi_message_init (&spi_mess);
    spi_message_add_tail (&tr_dat1, &spi_mess);
    error = spi_sync(jmt101->spi, &spi_mess);
    if (error) {
        //dev_err (&jmt101->spi->dev, "spi_sync tr_dat1 failed.\n");
        return error;
    }
    
    if ( (not_copy_len = copy_to_user((void __user*)arg, data_buf+1, g_data_len)) != 0) {
        //dev_err (&jmt101->spi->dev, "copy to user arg failed , not_copy_len=%ld", not_copy_len);
        error = -EFAULT;
    }
    return error;
}
#else
int common_read_data(struct jmt101_data* jmt101, unsigned long arg)
{
	int error;
	struct spi_message spi_mess;
	struct spi_transfer tr_reg;
	struct spi_transfer tr_dat1;
	struct spi_transfer tr_dat2;

	if((!g_data_len) && (!g_data_len2)){
		//dev_err (&jmt101->spi->dev, " data_len=%d, data_len2=%d, speed=%d\n", g_data_len, g_data_len2, jmt101->spi_speed);
		return -1;
	}

	memset (&tr_reg, 0, sizeof(struct spi_transfer));
	memset (&tr_dat1, 0, sizeof(struct spi_transfer));
	memset (&tr_dat2, 0, sizeof(struct spi_transfer));

	/* select register */
	spi_reg[0] = jmt101->jop.creg;
	spi_reg[1] = JMT_REG_FRAME_DATA;

	tr_reg.cs_change = 1;
	tr_reg.delay_usecs = 0;
	tr_reg.speed_hz = jmt101->spi_speed;
	tr_reg.tx_buf = spi_reg;
	tr_reg.rx_buf = NULL;
	tr_reg.len = 2;

	spi_message_init (&spi_mess);
	spi_message_add_tail (&tr_reg, &spi_mess);


	memset (spi_cmd, 0x00, JMT_TX_BUFFER_SIZE+1);
	spi_cmd[0] = jmt101->jop.cread;
	spi_cmd[1] = 0xFF;
	memset (data_buf, 0x00, READ_MAX_SIZE);
	tr_dat1.cs_change = 1;
	tr_dat1.delay_usecs = 0;
	tr_dat1.speed_hz = jmt101->spi_speed;
	tr_dat1.tx_buf = spi_cmd;
	tr_dat1.rx_buf = data_buf;
	tr_dat1.len = g_data_len+1;
////dev_err (&jmt101->spi->dev, ".spi_message_add_tail 1\n");
	spi_message_add_tail (&tr_dat1, &spi_mess);
	if(g_data_len2){
		tr_dat2.cs_change = 1;
		tr_dat2.delay_usecs = 0;
		tr_dat2.speed_hz = jmt101->spi_speed;
		tr_dat2.tx_buf = spi_cmd;
		tr_dat2.rx_buf = jmt_rd_buf;
		tr_dat2.len = g_data_len2+1;
////dev_err (&jmt101->spi->dev, ".spi_message_add_tail 2\n");
		spi_message_add_tail (&tr_dat2, &spi_mess);
	}
	////dev_err (&jmt101->spi->dev, "spi_sync call, data_len=%d, data_len2=%d speed=%d\n", g_data_len, g_data_len2, tr_dat2.speed_hz);
	error = spi_sync(jmt101->spi, &spi_mess);
	if (error) {
		//dev_err (&jmt101->spi->dev, "spi_sync failed.\n");
		return error;
	}
	if(g_data_len2) memcpy(data_buf+g_data_len+1, jmt_rd_buf + 1, g_data_len2);
	if (error) {
		//dev_err (&jmt101->spi->dev, "jmt101_ioctl error : %X\n", error);

	} else {
		long not_copy_len=0;
		if ( (not_copy_len = copy_to_user((void __user*)arg, data_buf+1, (g_data_len+g_data_len2))) != 0) {
			//dev_err (&jmt101->spi->dev, "copy to user arg failed , not_copy_len=%ld", not_copy_len);
			error = -EFAULT;
		}
	}
////dev_err (&jmt101->spi->dev, "%s: return error =%d\n", __func__, error);
	return error;
}
#endif

/* -------------------------------------------------------------------- */
static long jmt101_ioctl (struct file *filp, unsigned int cmd,
        unsigned long arg) {

    int error = -1;
    struct jmt101_data *jmt101 = filp->private_data;
    unsigned int user_regval;
    u8 m_reg;
    u8 m_val;

    switch (cmd) {
        case JMT_IOCTL_READ_REGISTER:
            if (copy_from_user(&user_regval, (void __user*)arg, sizeof(user_regval)) != 0) {
                error = -EFAULT;
                break;
            }

            m_reg = (user_regval >> 16) & 0xFF;

            if (down_interruptible(&jmt101->mutex)) return -ERESTARTSYS;
            error = jmt101_spi_rd_reg(jmt101, m_reg, &m_val);

            up (&jmt101->mutex);
            if (error) {
                //dev_err (&jmt101->spi->dev, "jmt101_ioctl cmd : %X error : %X\n", cmd, error);

            } else {
                user_regval = m_val;
                if (copy_to_user((void __user*)arg, &user_regval, sizeof(user_regval)) != 0) {
                    error = -EFAULT;
                }
            }
            break;

        case JMT_IOCTL_WRITE_REGISTER:
            if (get_user(user_regval, (unsigned int __user *)arg)) {
                error = -EFAULT;
                break;
            }

            m_reg = (user_regval >> 16) & 0xFF;
            m_val = user_regval & 0xFF;

            if (down_interruptible(&jmt101->mutex)) return -ERESTARTSYS;
            error = jmt101_spi_wr_reg(jmt101, m_reg, m_val);
            up (&jmt101->mutex);
            if (error) {
                //dev_err (&jmt101->spi->dev, "jmt101_ioctl cmd : %X error : %X\n", cmd, error);
            }
            break;

        case JMT_IOCTL_WRITE_ATTR:
	{
		struct sensor_attr* p_sa = NULL;
		if (copy_from_user(&jmt101->sa, (void __user*)arg, sizeof(jmt101->sa)) != 0) {
			error = -EFAULT;
			break;
		}

		p_sa =(struct sensor_attr*) &jmt101->sa;
		if(p_sa->frame_size >= 1024){
			g_data_len = (p_sa->frame_size/1024)*1024-1;
			g_data_len2 = (p_sa->frame_size%1024)+1;
		}else{
			g_data_len = p_sa->frame_size;
			g_data_len2 = 0;
		}
		if(!jmt_rd_buf)     jmt_rd_buf  = (u8 *)__get_free_pages(GFP_KERNEL, get_order(FRAME_MAX_LEN));
		if(!jmt_tmp_buf)    jmt_tmp_buf = (u8 *)kmalloc(FRAME_MAX_LEN, GFP_KERNEL);
		error=0;
		break;
	}
        case JMT_IOCTL_READ_ATTR:
            if (get_user(user_regval, (unsigned int __user *)arg)) {
                error = -EFAULT;
                ////printk("%s: get_user failed       \n",__func__  );
                break;
            }	
            if (copy_to_user((void __user*)arg, &jmt101->sa, sizeof(jmt101->sa)) != 0) {
                    error = -EFAULT;
            }
            ////dev_err (&jmt101->spi->dev, "JMT_IOCTL_READ_ATTR : [%.2X %.2X]\n", m_reg, m_val);
            error=0;
            break;
        
	case JMT_IOCTL_SET_OP:
	{
		struct jmt_op* pop = NULL;
		if (get_user(user_regval, (unsigned int __user *)arg)) {
			////printk("%s: INIt_REG  get user failed      \n",__func__  );
			error = -EFAULT;
			break;
		}	
		pop= (struct jmt_op*)arg;
		memcpy(&jmt101->jop, pop, sizeof(struct jmt_op));
		error=0;
		break;
	}
	case JMT_IOCTL_SET_CLOCK_SPEED:
	{
		if (get_user(user_regval, (unsigned int __user *)arg)) {
			error = -EFAULT;
			break;
		}	
		jmt101->spi_speed = user_regval;

		error=0;
		break;
	}
        case JMT_IOCTL_SET_VR:
	{
		u8* vr_regs = NULL;
		if (get_user(user_regval, (unsigned int __user *)arg)) {
			error = -EFAULT;
			break;
		}	
		vr_regs = (u8*)arg;
		regs_table[0][1] = vr_regs[0];
		regs_table[1][1] = vr_regs[1];
		regs_table[2][1] = vr_regs[2];
		regs_table[3][1] = vr_regs[3];
		error=0;
		break;
	}
	case JMT_IOCTL_TEST_UEVENT:
            jmt101_send_uevent(&jmt101->spi->dev);
            error=0;
            break;

    	case JMT_IOCTL_WAIT_TOUCH:
            error =0;
            break;
    	case JMT_IOCTL_CANCEL_WAIT_TOUCH:
    		if (!down_interruptible(&jmt101->int_mutex)) {
    			cancel_flag  =1;
    			up (&jmt101->int_mutex);
    		}
    		if(jmt101->wait_touch_exist){
    			jmt101->wait_touch_exist = 0;
    			wake_up_interruptible (&jmt101->waiting_interrupt_return);
    		}
    		error =0;
    		break;

    	case JMT_IOCTL_SET_SUSPEND:
    		if (get_user(user_regval, (unsigned int __user *)arg)) {
                    	error = -EFAULT;
                    	break;
                	}
    		suspended = user_regval;
    		//dev_err (&jmt101->spi->dev, "suspended =%d \n", suspended);
    		error = 0;
    		break;	

    	case JMT_IOCTL_READ_DATA:
#ifdef QC_INT
        	error = qualcomm_read_data(jmt101, arg);
#else
        	error = common_read_data(jmt101, arg);
#endif
	break;
        case JMT_IOCTL_SYSTEM_WAKE_UP:
            //printk ("[jmt101]%s: System wake up by IO control\n", __func__);
            input_report_key(jmt101->input, JMT101_WAKEUP_KEY, 1);
            input_sync(jmt101->input);			
            input_report_key(jmt101->input, JMT101_WAKEUP_KEY, 0);
            input_sync(jmt101->input);  
    		error = 0;
            break;
        case JMT_IOCTL_SET_KEY_EVENT:
             input_report_key(jmt101->input, JMT101_CAMERA_KEY, 1);
            input_sync(jmt101->input);			
            input_report_key(jmt101->input, JMT101_CAMERA_KEY, 0);
            input_sync(jmt101->input);  
    		error = 0;
            break;
    	default:
            //dev_err (&jmt101->spi->dev, "UNKNOW IO error = ENOTTY");
            error = -ENOTTY;
            break;
        }

    
    return error;
}


#ifdef CONFIG_COMPAT
static long
jmt101_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    return jmt101_ioctl(filp, cmd, (unsigned long)compat_ptr(arg));
}
#else
#define  jmt101_compat_ioctl        NULL
#endif

/* -------------------------------------------------------------------- */
static int jmt101_cleanup (struct jmt101_data *jmt101)
{
   if (!IS_ERR_OR_NULL(jmt101->device))
      device_destroy (jmt101->class, jmt101->devno);

   class_destroy (jmt101->class);

#ifdef CONFIG_QB_INT
	if(jmt101->handle) sw_gpio_irq_free(jmt101->handle); 
#endif
    
    disable_irq(fp_detect_irq);

   if (jmt101->huge_buffer) {
       kfree(jmt101->huge_buffer);
   }

   if (spi_common_buf) {
      kfree (spi_common_buf);
   }

   if (jmt101) {
      kfree (jmt101);
   }
    
   if(jmt_tmp_buf) kfree(jmt_tmp_buf);
		
   if (jmt_rd_buf) {
      free_pages ((unsigned long)jmt_rd_buf, get_order(jmt101->sa.frame_size));
   }
   return 0;
}
    
/* -------------------------------------------------------------------- */
#ifdef CONFIG_QB_INT
u32 jmt101_isr(void*para)
{
	struct jmt101_data *jmt101 = (struct jmt101_data*)para;
	//dev_err(&jmt101->spi->dev, " jmt101_isr >>>>>>>>>>>>>>>INT\n" );
      	jmt101->interrupt_done = 1;
      	wake_up_interruptible (&jmt101->waiting_interrupt_return);
	return 0;
}
#endif
/* -------------------------------------------------------------------- */

static int spi_dts_gpio_init(struct jmt101_data *jmt101)
{
    int ret = 0;   
    struct device_node *node;
    //printk("[MaJian][%s][line:%d] test 0, pin_ctl =%p \n", __func__, __LINE__, jmt101->pin_ctrl);
    
    node = of_find_compatible_node(NULL, NULL,"mediatek,fingerprint");
    if(node)
    {
        finger_rst_low = pinctrl_lookup_state(jmt101->pin_ctrl, "finger_rst_low");
        if (IS_ERR(finger_rst_low))
        {
            ret = PTR_ERR(finger_rst_low);
            //printk("fp cannot find fp_pinctrl finger_rst_low\n");
            return -1;
        }
        
        finger_rst_high = pinctrl_lookup_state(jmt101->pin_ctrl, "finger_rst_high");
        if (IS_ERR(finger_rst_high))
        {
            ret = PTR_ERR(finger_rst_high);
            //printk("fp cannot find fp_pinctrl finger_rst_high\n");
            return -1;
        }
        
        finger_power_low = pinctrl_lookup_state(jmt101->pin_ctrl, "finger_power_low");
        if (IS_ERR(finger_power_low))
        {
            ret = PTR_ERR(finger_power_low);
            //printk("fp cannot find fp_pinctrl finger_power_low\n");
            return -1;
        }
        
        finger_power_high = pinctrl_lookup_state(jmt101->pin_ctrl, "finger_power_high");
        if (IS_ERR(finger_power_high)) 
        {
            ret = PTR_ERR(finger_power_high);
            //printk("fp cannot find fp_pinctrl finger_power_high\n");
            return -1;
        }	
        
        fp_pinctrl = jmt101->pin_ctrl;
    }
    else
    {
        //printk("fp cannot find node\n");
        return -1;
    }
    
    return 0;
}


static int jmt_int_init(struct jmt101_data *jmt101)
{
    int ret = 0;
    struct device_node *node = NULL;
    
    node = of_find_matching_node(node, jmt101_of_match);
    if (node)
    {
        fp_detect_irq = irq_of_parse_and_map(node, 0);
        //printk("fp_irq number %d\n", fp_detect_irq);
        ret = request_irq(fp_detect_irq, jmt101_interrupt, IRQF_TRIGGER_RISING, "jmt_interrupt", jmt101);
        
        if (ret > 0)
        {
            //printk("fingerprint request_irq IRQ LINE NOT AVAILABLE!.\n");
        }
    }
    else
    {
        //printk("fingerprint request_irq can not find fp eint device node!.\n");
    }

    enable_irq(fp_detect_irq);
    return 0;
}

static int jmt101_probe (struct spi_device *spi)
{
    int error;
    struct jmt101_data *jmt101 = NULL;
	unsigned long		minor;
    error = 0;

    jmt101 = kzalloc(sizeof(*jmt101), GFP_KERNEL);
    if (!jmt101) {
        //dev_err (&spi->dev, "failed to allocate memory for struct jmt101_data\n");
        return -ENOMEM;
    }
   //jmt101->huge_buffer = (u8 *)__get_free_pages(GFP_KERNEL, get_order(JMT_IMAGE_BUFFER_SIZE));
   jmt101->huge_buffer = kzalloc(JMT_IMAGE_BUFFER_SIZE, GFP_KERNEL);
   if (!jmt101->huge_buffer) {
      //dev_err (&spi->dev, "failed to get free pages\n");
      kfree (jmt101);
      return -ENOMEM;
   }

   spi_common_buf = kzalloc(JMT_TX_BUFFER_SIZE + 12, GFP_KERNEL);
   if (!spi_common_buf) {
       //dev_err (&spi->dev, "failed to get spi_common_buf\n");
       kfree(jmt101->huge_buffer);
       kfree (jmt101);
       return -ENOMEM;
   }

   /* 4 bytes alignment */
#ifdef _ARM64
    spi_reg = (u8 *)((u64)(spi_common_buf + 3) & ~ 0x03);
#else
    spi_reg = (u8 *)((u32)(spi_common_buf + 3) & ~ 0x03);
#endif
    spi_cmd = spi_reg + JMT_TX_BUFFER_SIZE + 4;
    spi_buf = spi_cmd + 4;

    jmt101->spi = spi;
        // enable work item
    jmt101->p_jmt_wq= create_singlethread_workqueue("jmt_int_wq");
    INIT_WORK(&jmt101->jmt_int_work, jmt_interrupt_work);

    
#ifdef QC_INT
    //pr_err ("%s: configure interrupt\n", __func__);
    /* Configure qualcomm interrupt settings*/
    if( (error = configure_qualcomm_intrrupt(jmt101))) goto err;
#endif

    INIT_LIST_HEAD(&jmt101->device_entry);
    mutex_lock(&device_list_lock);
    /* Configure SPI*/
#ifdef CONFIG_ARCH_MTXXXX
   jmt101->spi->controller_data = (void*)&spi_conf_mt6577;
#endif
    jmt101->spi->mode = SPI_MODE_3;
    jmt101->spi->bits_per_word = 8;
    jmt101->spi->max_speed_hz = JMT_SPI_CLOCK_SPEED;

    //pr_err ("%s: spi_setup\n", __func__);
    /* setup spi */
    error = spi_setup(jmt101->spi);
    if (error) {
        //dev_err (&jmt101->spi->dev, "spi_setup failed\n");
        goto err;
    }

    //pr_err ("%s: device_create\n", __func__);
    minor = find_first_zero_bit(minors, N_SPI_MINORS);
    if (minor < N_SPI_MINORS) {
        //struct device *dev;
        
        jmt101->devno = MKDEV(jmt_major, minor);
        jmt101->device = device_create(jmt_class, &spi->dev, jmt101->devno,
                            jmt101, "%s", JMT101_DEV_NAME);
        error = IS_ERR(jmt101->device) ? PTR_ERR(jmt101->device) : 0;
    } else {
        dev_dbg(&spi->dev, "no minor number available!\n");
        error = -ENODEV;
    }
    if (error == 0) {
        set_bit(minor, minors);
        list_add(&jmt101->device_entry, &device_list);
    }
    spin_lock_init(&jmt101->spi_lock);
    //pr_err ("%s: get device node\n", __func__);

    jmt101->spi->dev.of_node=of_find_compatible_node(NULL, NULL, "mediatek,fingerprint");
    
    jmt101->pin_ctrl = devm_pinctrl_get(&jmt101->spi->dev);
    //pr_err ("%s: get device pin_ctl=%p\n", __func__, jmt101->pin_ctrl);

    if (IS_ERR(jmt101->pin_ctrl))
    {
        error = PTR_ERR(jmt101->pin_ctrl);
        //dev_err(&spi->dev, "fwq Cannot find fp pctrl!\n");
        return error;
    }
    
    jmt101->spi_speed = JMT_SPI_CLOCK_SPEED;
    
    spi_dts_gpio_init(jmt101);
    
 
    pinctrl_select_state(fp_pinctrl,finger_rst_low);
    msleep(20);
    pinctrl_select_state(fp_pinctrl,finger_rst_high);
    msleep(20);    
    pinctrl_select_state(fp_pinctrl,finger_power_low);
    msleep(20);
    pinctrl_select_state(fp_pinctrl,finger_power_high);
    msleep(100);
    mutex_unlock(&device_list_lock);
    
    /* semaphore, thread settings*/
    sema_init (&jmt101->mutex, 0);
    
    /* identifier for suspend/resume ...*/
    suspended = 0;
    //pr_err ("%s: jmt_int_init()\n", __func__);

    jmt_int_init(jmt101);

 /* input system initial */
   jmt101->input = input_allocate_device();
   if(jmt101->input == NULL) {
       //dev_err (&jmt101->spi->dev, "jmt101_probe - input_allocate_device failed.\n");
       goto err;
   }
   __set_bit(EV_KEY, jmt101->input->evbit);
   __set_bit(JMT101_WAKEUP_KEY, jmt101->input->keybit);
   __set_bit(JMT101_CAMERA_KEY, jmt101->input->keybit);
    
   jmt101->input->name = JMT101_INPUT_DEV_NAME;
   if(input_register_device(jmt101->input)) {

       //dev_err (&jmt101->spi->dev, "jmt101_probe - input_register_device failed.\n");
       goto err;
   }
#ifdef CONFIG_HAS_EARLYSUSPEND
    jmt101->early_suspend.suspend = jmt101_early_suspend,
    jmt101->early_suspend.resume = jmt101_late_resume,
    jmt101->early_suspend.level = EARLY_SUSPEND_LEVEL_BLANK_SCREEN + 1,
    register_early_suspend (&jmt101->early_suspend);
#endif


	//mt_spi_set_mod();
    up (&jmt101->mutex);
err:
    if(error == 0){
        spi_set_drvdata (spi, jmt101);
    }else kfree(jmt101);

    //pr_err ("[jmt101]%s: OUT ret=%d\n", __func__, error);
    return error;
}


#ifdef CONFIG_HAS_EARLYSUSPEND
/* -------------------------------------------------------------------- */
static void jmt101_early_suspend (struct early_suspend *h)
{
   //printk ("[jmt101]%s:\n", __func__);
   suspended = 1;
}

/* -------------------------------------------------------------------- */
static void jmt101_late_resume (struct early_suspend *h)
{
   //printk ("[jmt101]%s:\n", __func__);
   suspended = 0;
}
#endif
/* -------------------------------------------------------------------- */

static int jmt101_remove (struct spi_device *spi)
{
    struct jmt101_data *jmt101 = spi_get_drvdata(spi);
    //pr_err("%s: IN\n", __func__);

    /* make sure ops on existing fds can abort cleanly */
    spin_lock_irq(&jmt101->spi_lock);
    jmt101->spi = NULL;
    spi_set_drvdata(spi, NULL);
    spin_unlock_irq(&jmt101->spi_lock);
    mutex_lock(&device_list_lock);
    list_del(&jmt101->device_entry);
    device_destroy(jmt_class, jmt101->devno);
    clear_bit(MINOR(jmt101->devno), minors);
    spi_set_drvdata (spi, NULL);
    input_unregister_device(jmt101->input);
    if (jmt101->users == 0) jmt101_cleanup (jmt101);
	mutex_unlock(&device_list_lock);
    return 0;
}


/* -------------------------------------------------------------------- */
static int jmt101_suspend (struct device *dev)
{
    	//printk ("[jmt101]%s: IN\n", __func__);
	return 0;
}

/* -------------------------------------------------------------------- */
static int jmt101_resume (struct device *dev)
{
    	//printk ("[jmt101]%s: IN\n", __func__);
   	return 0;
}

/* -------------------------------------------------------------------- */
static struct spi_board_info jmt101  __initdata = {
    .modalias = "jmt101",
    .platform_data = NULL,
    .mode = SPI_MODE_3,
    .max_speed_hz = 16 * 1000 * 1000,
    .bus_num = 0,
    .chip_select = 0,

};

static int __init jmt101_init (void)
{
    int error;
    dev_t devno;
    //pr_err ("%s: start ...\n", __func__);
    
    BUILD_BUG_ON(N_SPI_MINORS > 256);

    //error = register_chrdev_region(jmt101->devno, 1, JMT101_DEV_NAME);
    if ((error = alloc_chrdev_region(&devno, 0, 256, JMT101_DEV_NAME)) < 0) {
        //pr_err ("%s - register_chrdev_region failed.\n", __func__);
        goto jmt101_init_err;
    }
    
    jmt_major = MAJOR(devno);
    cdev_init (&jmt_cdev, &jmt101_fops);
    jmt_cdev.owner = THIS_MODULE;
    
    if ((error = cdev_add(&jmt_cdev, MKDEV(jmt_major, 0), N_SPI_MINORS)) < 0) {
        //pr_err("%s: cdev_add failed.\n", __func__);
        goto jmt101_init_err;
    }
    
    jmt_class = class_create(THIS_MODULE, JMT101_CLASS_NAME);
    if (IS_ERR(jmt_class)) {
        //pr_err ("%s: failed to create class.\n", __func__);
        unregister_chrdev(jmt_major, jmt101_driver.driver.name);
        error =  PTR_ERR(jmt_class);
        goto jmt101_init_err;
    }
	
   error = spi_register_board_info(&jmt101, 1);
   if (error < 0){
		//printk("[jmt101] spi_register_board_info fail!\n");
		return -ENODEV;
    }
    if ( (error = spi_register_driver(&jmt101_driver)) < 0){
        class_destroy(jmt_class);
        unregister_chrdev(jmt_major, jmt101_driver.driver.name);
    }
    
jmt101_init_err:
    //pr_err ("%s: end error =%d...\n", __func__, error);
    return error;
}

/* -------------------------------------------------------------------- */

static void __exit jmt101_exit (void)
{
    cdev_del (&jmt_cdev);
    spi_unregister_driver (&jmt101_driver);
    class_destroy(jmt_class);
    unregister_chrdev(jmt_major, jmt101_driver.driver.name);
}

module_init (jmt101_init);
module_exit (jmt101_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("J-Matrics <darwinyu@j-metrics.com>");
MODULE_DESCRIPTION("JMT fingerprint driver");
