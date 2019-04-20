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
#include "nled_driver.h"
/******************************************************************************
 * configuration
*******************************************************************************/
/*----------------------------------------------------------------------------*/

#define SN3191_DEV_NAME     "snled"
/*----------------------------------------------------------------------------*/
#define SN3191_TAG                  "[LED] "
#define SN3191_FUN(f)               pr_err(SN3191_TAG"%s\n", __func__)
#define SN3191_ERR(fmt, args...)    pr_err(SN3191_TAG"%s %d : "fmt, __func__, __LINE__, ##args)
#define SN3191_LOG(fmt, args...)    pr_err(SN3191_TAG fmt, ##args)
#define SN3191_DBG(fmt, args...)    pr_err(SN3191_TAG fmt, ##args)

#define I2C_FLAG_WRITE	0
#define I2C_FLAG_READ	1

#define SN3191							0X88
#define SN3191_IOCTL_SETRGB_BRIGHNESS       _IOW(SN3191, 0x03,SN3191_LED_DATA)

/******************************************************************************
 * extern functions
*******************************************************************************/
extern int register_nled_driver(struct nled_driver *nled_driver);
static const struct i2c_device_id sn3191_i2c_id[] = { {SN3191_DEV_NAME, 0}, {} };
//struct i2c_board_info __initdata i2c_sn3191={ I2C_BOARD_INFO("snled", (0x68))};

static int sn3191_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int sn3191_i2c_remove(struct i2c_client *client);
static int sn3191_i2c_detect(struct i2c_client *client, struct i2c_board_info *info);
static int sn3191_i2c_suspend(struct i2c_client *client, pm_message_t msg);
static int sn3191_i2c_resume(struct i2c_client *client);
static int sn3191_local_init(void);
static int sn3191_remove(void);

static struct i2c_client *sn3191_i2c_client;
static struct pinctrl *pinctrl1;
static struct pinctrl_state *led_en_output1;

static DEFINE_MUTEX(sn3191_mutex);

typedef struct
{
    int   level;
    int     red;
    int   green;
    int    blue;
    int delayon;
   int delayoff;       
}SN3191_LED_DATA;

#ifdef CONFIG_OF
static const struct of_device_id snled_of_match[] = {
	{ .compatible = "mediatek,LED", },
	{},
};
#endif
static struct i2c_driver sn3191_i2c_driver = {
	.probe = sn3191_i2c_probe,
	.remove = sn3191_i2c_remove,
	.detect = sn3191_i2c_detect,
	.suspend = sn3191_i2c_suspend,
	.resume = sn3191_i2c_resume,
	.id_table = sn3191_i2c_id,
	.driver = {
		   .name = SN3191_DEV_NAME,
			#ifdef CONFIG_OF
			.of_match_table = snled_of_match,
			#endif
		   },
};

int sn3191_i2c_read_cmos_sensor(struct i2c_client *client, char *buf, int count)
{
	int res = 0;
	mutex_lock(&sn3191_mutex);
	client->addr &= I2C_MASK_FLAG;

	res = i2c_master_send(client, buf, count>>8);
	client->addr &= I2C_MASK_FLAG;

	if (res < 0)
		goto EXIT_ERR;
		
		
	res = i2c_master_recv(client, buf, count&0xFF);
    if (res != 1) {
        SN3191_ERR("[LED] I2C read failed!!\n");
        return -1;
    }
    mutex_unlock(&sn3191_mutex);
	return res;
EXIT_ERR:
	mutex_unlock(&sn3191_mutex);
	SN3191_ERR("sn3191_i2c_master_operate fail\n");
	return res;
}

int sn3191_i2c_write_cmos_sensor(struct i2c_client *client, char *buf, int count)
{
	int res = 0;
	mutex_lock(&sn3191_mutex);
	client->addr &= I2C_MASK_FLAG;

	res = i2c_master_send(client, buf, count);
	client->addr &= I2C_MASK_FLAG;

	if (res < 0)
		goto EXIT_ERR;
	mutex_unlock(&sn3191_mutex);
	return res;
EXIT_ERR:
	mutex_unlock(&sn3191_mutex);
	SN3191_ERR("sn3191_i2c_master_operate fail\n");
	return res;
}

static int WriteByte(int addr, int data)
{
	u8 databuf[2];
	
	databuf[0] = addr & 0xFF;
	databuf[1] = data & 0xFF; 
	sn3191_i2c_write_cmos_sensor(sn3191_i2c_client, databuf, 0x2);  //set interrupt mode
		
	return 0;
}

static int sn3191_init_client(struct i2c_client *client)
{
	WriteByte(0x00, 0x00);
	WriteByte(0x1D, 0x00);

	return 0;
}


static int sn3191_open(struct inode *inode, struct file *file)
{

	file->private_data = sn3191_i2c_client;
	SN3191_FUN();

	if(file->private_data == NULL)
	{
		SN3191_ERR("null pointer!!\n");
		return -EINVAL;
	}
	return nonseekable_open(inode, file);
}

static int sn3191_release(struct inode *inode, struct file *file)
{
	file->private_data = NULL;
	return 0;
}


static int sn3191_led_enable(bool enable)
{
	if (sn3191_i2c_client == NULL)
	{
		SN3191_ERR("i2c_data obj is null!!\n");
		return -1;
	}

	if (enable)
	{	
		SN3191_DBG("enable\n");
		WriteByte(0x00, 0x20);//软件关断 bit5
		WriteByte(0x01, 0x20);//呼吸停滞模式,使能RM(bit5),停滞时间HT(bit4),0：T2处停滞,1:T4处停滞
		WriteByte(0x02, 0x20);//一次编程模式 bit5
		WriteByte(0x03, 0x00);//最大电流42mA
		WriteByte(0x04, 0x97);//pwm控制
		WriteByte(0x07, 0x00);//pwm更新
		WriteByte(0x0A, 0x00);//T0:启动时间
		WriteByte(0x10, 0x02);//T1:上升时间,T2:保持时间
		WriteByte(0x16, 0x44);//T3:下降时间,T4:关闭时间
		WriteByte(0x1C, 0x00);//时间更新,合OAH，10H，16H生效
		WriteByte(0x1D, 0x01);//LED开关
	}
	else
	{
		SN3191_DBG("disable\n");
		WriteByte(0x00, 0x00);
		WriteByte(0x1D, 0x00);
	}
	
	return 0;
}

int sn3191_set_led(long data, int level)
{
	int err = 0;
	if(level)
	{
		err = sn3191_led_enable(true);
	}
	else
	{
		err = sn3191_led_enable(false);
	}

	return err;
}

int sn3191_blink_set(long data, unsigned long on, unsigned long off)
{
	SN3191_DBG("xfl sn3191_blink_set enter, on:%ld, off:%ld\n", on, off);

	if (on && off)
	{
		WriteByte(0x01, 0x00);//呼吸停滞模式,使能RM(bit5),停滞时间HT(bit4),0：T2处停滞,1:T4处停滞
		WriteByte(0x0A, 0x00);//T0:启动时间
		WriteByte(0x10, 0x02);//T1:上升时间,T2:保持时间
		WriteByte(0x16, 0x44);//T3:下降时间,T4:关闭时间
		WriteByte(0x1C, 0x00);//时间更新,合OAH，10H，16H生效
	}
	else
	{
		WriteByte(0x01, 0x20);//呼吸停滞模式,使能RM(bit5),停滞时间HT(bit4),0：T2处停滞,1:T4处停滞
		WriteByte(0x0A, 0x00);//T0:启动时间
		WriteByte(0x10, 0x02);//T1:上升时间,T2:保持时间
		WriteByte(0x16, 0x44);//T3:下降时间,T4:关闭时间
		WriteByte(0x1C, 0x00);//时间更新,合OAH，10H，16H生效
	}
	
	return 0;
}

static int sn3191_set_rgb(int level,int red,int green,int blue,int delayon,int delayoff)
{
	return sn3191_set_led(0, level);
}

static long sn3191_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int err = 0;
	void __user *data = (void __user*)arg;
	
	SN3191_LED_DATA led_data = {0};
	SN3191_DBG(" SN3191_unlocked_ioctl  cmd = %d \n",cmd);
	
	switch(cmd)
	{
        case SN3191_IOCTL_SETRGB_BRIGHNESS:
			if (copy_from_user(&led_data, data, sizeof(led_data)))
			{
				SN3191_ERR(" SN3191_IOCTL_SETRGB_BRIGHNESS copy_from_user error !\n");
				return -1;	  
			}
	
            err = sn3191_set_rgb(led_data.level, led_data.red, led_data.green,
									led_data.blue, led_data.delayon, led_data.delayoff);
			if (err)
			{
				SN3191_ERR("ioctl SETRGB_BRIGHNESS error\n");
			}
			 
            break;
		default:
			break;
	}
	return err;
}

static struct file_operations sn3191_fops = {
	.owner = THIS_MODULE,
	.open = sn3191_open,
	.release = sn3191_release,
	.unlocked_ioctl = sn3191_unlocked_ioctl,
};

static struct miscdevice sn3191_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "sn3191",
	.fops = &sn3191_fops,
};

static int sn3191_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int err = 0;

	client->addr = 0x68;
	
	mutex_lock(&sn3191_mutex);
	sn3191_i2c_client = client;
	sn3191_i2c_client->timing = 100;
	mutex_unlock(&sn3191_mutex);
	
	err = sn3191_init_client(client);

	if (misc_register(&sn3191_device))
	{
		SN3191_ERR("sn3191_device register failed\n");
		return -1;
	}
	
	if (err)
		return -1;
	
	return 0;
	
}

static int sn3191_i2c_remove(struct i2c_client *client)
{
	
	return 0;

}

static int sn3191_i2c_suspend(struct i2c_client *client, pm_message_t msg)
{

	//WriteByte(0x00, 0x01);
	return 0;
}

static int sn3191_i2c_resume(struct i2c_client *client)
{

 	//WriteByte(0x00, 0x20);
	return 0;
}

static int sn3191_i2c_detect(struct i2c_client *client, struct i2c_board_info *info)
{

	strcpy(info->type, SN3191_DEV_NAME);
	
	return 0;

}

static int sn3191_remove(void)
{

	i2c_del_driver(&sn3191_i2c_driver);
	
	return 0;
}


static int sn3191_local_init(void)
{
	if (i2c_add_driver(&sn3191_i2c_driver)) {
		SN3191_ERR("add driver error\n");
		return -1;
	}

	return 0;
}

static ssize_t  agold_write_proc(struct file *file, const char *buffer, size_t count, loff_t *data)
{
 
    char regBuf[64] = {'\0'};
    int sensorReg = 0;
    int sensorData = 0;
    
    u32 u4CopyBufSize = (count < (sizeof(regBuf) - 1)) ? (count) : (sizeof(regBuf) - 1); 

    if (copy_from_user(regBuf, buffer, u4CopyBufSize))
    return -EFAULT;

    if (sscanf(regBuf, "%x %x",  &sensorReg, &sensorData) == 2) 
    {
   		WriteByte(sensorReg, sensorData);
    }
    else if (sscanf(regBuf, "%x",  &sensorReg) == 1) 
    {
   		if(sensorReg == 1)
   		{
   			WriteByte(0x00, 0x20);
			WriteByte(0x1D, 0x01);
   		}
   		else
   		{
   			WriteByte(0x00, 0x00);
			WriteByte(0x1D, 0x00);
   		}
    }

    return count;
}

static ssize_t agold_debug_proc(struct file *file, char __user *page, size_t size, loff_t *ppos)
{
    return 0;
}

static struct file_operations ft_debug_fops = { 
    .read  = agold_debug_proc,
    .write = agold_write_proc
};

static int led_probe(struct platform_device *pdev)
{
	int ret = 0;
	
	sn3191_local_init();
	
	pinctrl1 = devm_pinctrl_get(&pdev->dev);
	if (IS_ERR(pinctrl1)) 
	{
		ret = PTR_ERR(pinctrl1);
		dev_err(&pdev->dev, "fwq Cannot find  pinctrl1!\n");
		return ret;
	}
	led_en_output1 = pinctrl_lookup_state(pinctrl1, "led_en_output1");
	pinctrl_select_state(pinctrl1, led_en_output1);
	
	proc_create("sn3191_debug", 0664, NULL, &ft_debug_fops);
	
	return 0;
}

static int led_remove(struct platform_device *pdev)
{

	return 0;
}

#ifdef CONFIG_OF
struct of_device_id led_of_match[] = {
	{ .compatible = "mediatek, sn3191", },
	{},
};
#endif
static struct platform_driver led_driver = {
	.remove = led_remove,
	.shutdown = NULL,
	.probe = led_probe,
	.driver = {
		.name = "sn3191",
		#ifdef CONFIG_OF
		.of_match_table = led_of_match,
		#endif
	},
};

struct nled_driver nled_driver = {
	.name = "sn3191",
	.led_set_brightness = sn3191_set_led,
	.led_set_blink = sn3191_blink_set,
};

static int __init sn3191_init(void)
{
	int err = 0;
	
	//i2c_register_board_info(1, &i2c_sn3191, 1);
	
	if (platform_driver_register(&led_driver))
	{
		SN3191_ERR("platform_driver_registe hall failed!\n");
		return -1;
	}

	err = register_nled_driver(&nled_driver);
	if (err)
	{
		SN3191_ERR("register nled_driver failed\n");
	}

	return 0;
}

static void __exit sn3191_exit(void)
{
	sn3191_remove();
}

module_init(sn3191_init);
module_exit(sn3191_exit);

MODULE_AUTHOR("ma chongze");
MODULE_DESCRIPTION("sn3191 driver");
MODULE_LICENSE("GPL");
