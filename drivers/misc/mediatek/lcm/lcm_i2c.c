/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
#ifndef BUILD_LK
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/init.h>                  
#include <linux/list.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/irq.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/string.h>
#include <linux/wait.h>
#endif

#ifdef BUILD_LK
#include <platform/upmu_common.h>
#include <platform/upmu_hw.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#else
#ifdef CONFIG_MTK_LEGACY
#include <mach/mt_pm_ldo.h>	/* hwPowerOn */
#include <mt-plat/upmu_common.h>
#include <mach/upmu_sw.h>
#include <mach/upmu_hw.h>
#endif
#endif
#ifdef CONFIG_MTK_LEGACY
#include <mach/mt_gpio.h>
#include <cust_gpio_usage.h>
#include <cust_i2c.h>
#endif

#include "lcm_define.h"
#include "lcm_drv.h"
#include "lcm_i2c.h"

//[agold][xfl][20160311][start]
#include <linux/gpio.h>
#if defined(AGOLD_3DLCM_SUPPURT)
#include <linux/miscdevice.h>
#include <mt-plat/mt_pwm.h>
#include <mach/mt_pwm_hal.h>
#include <linux/proc_fs.h>
#endif
//[agold][xfl][20160311][end]

/*****************************************************************************
 * Define
 *****************************************************************************/
#ifndef CONFIG_FPGA_EARLY_PORTING
#ifdef CONFIG_MTK_LEGACY
#define LCM_I2C_ADDR 0x3E
#define LCM_I2C_BUSNUM  I2C_I2C_LCD_BIAS_CHANNEL	/* for I2C channel 0 */
#define LCM_I2C_ID_NAME "ds4801"
#else
#define LCM_I2C_ADDR 0x3E //7bits address
#define LCM_I2C_BUSNUM  1	
#define LCM_I2C_ID_NAME "I2C_LCD_BIAS"
#endif

//[agold][xfl][20160311][start]
static int lcm_vop_en_pin = -1;
static int lcm_von_en_pin = -1;
#if defined(AGOLD_3DLCM_SUPPURT)
#define DS4801							0X91
#define DS4801_IOC_PWM_ENABLE				_IO(DS4801, 0x01)
#define DS4801_IOC_PWM_DISABLE				_IO(DS4801, 0x02)
#define DS4801_IOC_PWM_SETFREQ				_IOW(DS4801, 0x03, int)
#define COMPAT_DS4801_IOC_PWM_ENABLE		_IO(DS4801, 0x01)
#define COMPAT_DS4801_IOC_PWM_DISABLE		_IO(DS4801, 0x02)
#define COMPAT_DS4801_IOC_PWM_SETFREQ	    _IOW(DS4801, 0x03, int)

static int lcm_tn_en_pin = -1;
static int g_freq = 0;
static int g_duty = 0;
#endif
//[agold][xfl][20160311][end]

//[agold][xfl][20160527][for G3 yunshi]
#ifdef AGOLD_3DLCM_BACKLIGHT_CONTRL
int g_3dlcm_en = 0;
#endif

#ifdef CONFIG_MTK_LEGACY
static struct i2c_board_info _lcm_i2c_board_info __initdata = {
	I2C_BOARD_INFO(LCM_I2C_ID_NAME, LCM_I2C_ADDR)
};
#else
static const struct of_device_id lcm_i2c_of_match[] = {
	{
	 	.compatible = "mediatek,I2C_LCD_BIAS",
	},
};
//[agold][xfl][20160311][start]
static const struct of_device_id lcm_bias_of_match[] = {
	{
	 	.compatible = "mediatek,LCD_BIAS",
	},
};
//[agold][xfl][20160311][end]		
#endif

static struct i2c_client *_lcm_i2c_client;


/*****************************************************************************
 * Function Prototype
 *****************************************************************************/
//[agold][xfl][20160311][start]
static int _lcm_i2c_write_bytes(unsigned char addr, unsigned char value);
//[agold][xfl][20160311][end]
static int _lcm_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int _lcm_i2c_remove(struct i2c_client *client);

/*****************************************************************************
 * Data Structure
 *****************************************************************************/
struct _lcm_i2c_dev {
	struct i2c_client *client;
};

static const struct i2c_device_id _lcm_i2c_id[] = {
	{LCM_I2C_ID_NAME, 0},
	{}
};

//[agold][xfl][20160311][start]
int lcm_i2c_bias_en(int enable)
{
	if (enable)
	{
		gpio_set_value(lcm_vop_en_pin, 1);
		gpio_set_value(lcm_von_en_pin, 1);
	}
	else
	{
		gpio_set_value(lcm_vop_en_pin, 0);
		gpio_set_value(lcm_von_en_pin, 0);
	}
	return 0;
}

static int lcm_bias_get_gpio_info(void)
{	

	struct device_node *node=NULL;
	int ret;
	
	node = of_find_compatible_node(NULL, NULL, "mediatek,LCD_BIAS");
	if (node) 
	{		
		ret = of_property_read_u32(node , "vop_en_pin", &lcm_vop_en_pin);
		if (ret)
		{
			pr_err("read node lcm_vop_en_pin error!\n");
		}

		ret = of_property_read_u32(node , "von_en_pin", &lcm_von_en_pin);
		if (ret)
		{
			pr_err("read node lcm_von_en_pin error!\n");
		}

		#if defined(AGOLD_3DLCM_SUPPURT)
		ret = of_property_read_u32(node , "tn_en_pin", &lcm_tn_en_pin);
		if (ret)
		{
			pr_err("read node lcm_tn_en_pin error!\n");
		}
		#endif
		
		pr_debug("vop:%d, von:%d\n", lcm_vop_en_pin, lcm_von_en_pin);
	}
	else
	{
		pr_err("read node error!\n");
	}
	
	return 0;
}

int lcm_i2c_set_vol_value(int vop_value, int von_value)
{
	unsigned char vop_val = 0;
	unsigned char von_val = 0;	
		
	if((vop_value > VOL_H) || (vop_value < VOL_L) || (von_value > VOL_H) || (von_value < VOL_L))
	{
		pr_err("[LCM][I2C] value out of range(4000-6000) \n");
		return -1;
	}
	else
	{
		vop_val = (unsigned char)((vop_value-VOL_L)/100);
		von_val = (unsigned char)((von_value-VOL_L)/100);
		
		_lcm_i2c_write_bytes(VOP_ADDRESS, vop_val);
		_lcm_i2c_write_bytes(VON_ADDRESS, von_val);
	}
	
	return 0;
}

#if defined(AGOLD_3DLCM_SUPPURT)
int raster_set_pwm(int freq, int duty)
{
	unsigned short data_width = 0;
	unsigned short thresh = 0;	

	struct pwm_spec_config pwm_setting1 = {
	    .pwm_no = PWM1, // Rev A
		.mode = PWM_MODE_OLD,
		.clk_src = PWM_CLK_OLD_MODE_32K,
		.pmic_pad = false,
		.PWM_MODE_OLD_REGS.IDLE_VALUE = IDLE_FALSE,
		.PWM_MODE_OLD_REGS.GUARD_VALUE = 0,
		.PWM_MODE_OLD_REGS.GDURATION = 0,
		.PWM_MODE_OLD_REGS.WAVE_NUM = 0,              
		.clk_div = CLK_DIV2,          
	};

	struct pwm_spec_config pwm_setting2 = {
	    .pwm_no = PWM2, // Rev B
		.mode = PWM_MODE_OLD,
		.clk_src = PWM_CLK_OLD_MODE_32K,
		.pmic_pad = false,
		.PWM_MODE_OLD_REGS.IDLE_VALUE = IDLE_FALSE,
		.PWM_MODE_OLD_REGS.GUARD_VALUE = 0,
		.PWM_MODE_OLD_REGS.GDURATION = 0,
		.PWM_MODE_OLD_REGS.WAVE_NUM = 0,             
		.clk_div = CLK_DIV2,        
	};
	
	if (freq < 1)
	{
		freq = 1;
	}
	else if (freq > 1000)
	{
		freq = 1000;
	}

	if (duty < 10)
	{
		duty = 10;
	}
	else if (duty > 90)
	{
		duty = 100;
	}	

	g_freq = freq;
	g_duty = duty;

	freq *=4;

	data_width = (32000/freq*CLK_DIV2)-1;
	thresh = (data_width*duty)/100;

	pwm_setting1.PWM_MODE_OLD_REGS.DATA_WIDTH = data_width;
	pwm_setting1.PWM_MODE_OLD_REGS.THRESH = thresh;
	pwm_setting2.PWM_MODE_OLD_REGS.DATA_WIDTH = data_width;
	pwm_setting2.PWM_MODE_OLD_REGS.THRESH = thresh;
	
	pwm_set_spec_config(&pwm_setting1);
	pwm_set_spec_config(&pwm_setting2);	

	mt_set_pwm_3dlcm_base_hal(PWM1);
	mt_set_pwm_3dlcm_inv(PWM2, 1);
	mt_set_pwm_3dlcm_enable(1);

	return 0;
}

ssize_t agold_3dlcm_read_proc(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
	char *page = NULL;
    char *ptr = NULL;
    int len, err = -1;

	page = kmalloc(PAGE_SIZE, GFP_KERNEL);	
	if (!page) 
	{		
		kfree(page);		
		return -ENOMEM;	
	}

    ptr = page; 
    ptr += sprintf(ptr, "3dlcm freq:%d, duty:%d\n", g_freq, g_duty);
	len = ptr - page; 			 	
	if(*ppos >= len)
	{		
		kfree(page); 		
		return 0; 	
	}	
	err = copy_to_user(buffer,(char *)page,len); 			
	*ppos += len; 	
	if(err) 
	{		
	    kfree(page); 		
		return err; 	
	}	
	kfree(page); 	
	return len;	
}

static ssize_t  agold_3dlcm_write_proc(struct file *file, const char *buffer, size_t count, loff_t *data)
{
 
    char temp[64] = {'\0'};
    int freq = 0;
    int duty = 0;
    
    u32 size = (count < (sizeof(temp) - 1)) ? (count) : (sizeof(temp) - 1); 

    if (copy_from_user(temp, buffer, size))
	{
	    return -EFAULT;
	}

    if (sscanf(temp, "%d %d",  &freq, &duty) == 2) 
    {
		if (freq == 0)
		{
			gpio_set_value(lcm_tn_en_pin, 0);
		}
		else
		{
			gpio_set_value(lcm_tn_en_pin, 1);
	   		raster_set_pwm(freq, duty);
		}
    }

    return count;
}


static struct file_operations agold_3dlcm_fops = { 
    .read  = agold_3dlcm_read_proc,
    .write = agold_3dlcm_write_proc
};

static long ds4801_unlocked_ioctl(struct file *file, unsigned int cmd,unsigned long arg)
{
	void __user *ptr = (void __user *)arg;
	int freq = 0;

	switch (cmd)
	{
		case DS4801_IOC_PWM_ENABLE:
			gpio_set_value(lcm_tn_en_pin, 1);
			raster_set_pwm(60, 50);
			//[agold][xfl][20160527][for G3 yunshi]
			#ifdef AGOLD_3DLCM_BACKLIGHT_CONTRL
			g_3dlcm_en = 1;
			#endif
			break;
		case DS4801_IOC_PWM_DISABLE:
			gpio_set_value(lcm_tn_en_pin, 0);
			//[agold][xfl][20160527][for G3 yunshi]
			#ifdef AGOLD_3DLCM_BACKLIGHT_CONTRL
			g_3dlcm_en = 0;
			#endif
			break;
		case DS4801_IOC_PWM_SETFREQ:
			if (copy_from_user(&freq, ptr, sizeof(freq))) 
			{
				pr_err("unlocked ioctl copy_from_user fail !\n");			
				return -EFAULT;
			}
			raster_set_pwm(freq, 50);
			break;
		default:
			pr_err("ioctl %s not supported = 0x%04x", __FUNCTION__, cmd);
			return -ENOIOCTLCMD;
			break;
		}

	return 0;
}

#ifdef CONFIG_COMPAT
static long ds4801_compat_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	
	if(!file->f_op || !file->f_op->unlocked_ioctl)
	{
		pr_err("file->f_op OR file->f_op->unlocked_ioctl is null!\n");
		return -ENOTTY;
	}

	switch(cmd)
	{
		case COMPAT_DS4801_IOC_PWM_ENABLE:
		case COMPAT_DS4801_IOC_PWM_DISABLE:
		case COMPAT_DS4801_IOC_PWM_SETFREQ:
			return file->f_op->unlocked_ioctl(file, cmd, (unsigned long)compat_ptr(arg));
		default:
			pr_err("%s not supported = 0x%04x", __FUNCTION__, cmd);
			return -ENOIOCTLCMD;
	}
}
#endif

static int ds4801_open(struct inode *inode, struct file *file)
{
	return nonseekable_open(inode, file);
}

static int ds4801_release(struct inode *inode, struct file *file)
{
	return 0;
}

static struct file_operations ds4801_fops = {
	//.owner = THIS_MODULE,
	.open = ds4801_open,
	.release = ds4801_release,
	.unlocked_ioctl = ds4801_unlocked_ioctl,
	#ifdef CONFIG_COMPAT
	.compat_ioctl = ds4801_compat_ioctl,
	#endif
};

static struct miscdevice ds4801_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "agold_lcm3d",
    .fops = &ds4801_fops,
};
#endif
//[agold][xfl][20160311][end]

static struct i2c_driver _lcm_i2c_driver = {
	.id_table = _lcm_i2c_id,
	.probe = _lcm_i2c_probe,
	.remove = _lcm_i2c_remove,
	/*.detect = _lcm_i2c_detect, */
	.driver = {
		   //.owner = THIS_MODULE,
		   .name = LCM_I2C_ID_NAME,
			#ifdef CONFIG_MTK_LEGACY
			#else
		   .of_match_table = lcm_i2c_of_match,
			#endif
		   },
};

static int _lcm_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	//[agold][xfl][20160311][start]
	#if defined(AGOLD_3DLCM_SUPPURT)
	int err = 0;
	#endif
	pr_debug("[LCM][I2C] _lcm_i2c_probe\n");
	pr_debug("[LCM][I2C] NT: info==>name=%s addr=0x%x\n", client->name, client->addr);
	_lcm_i2c_client = client;

	lcm_bias_get_gpio_info();

	#if defined(AGOLD_3DLCM_SUPPURT)
	err = misc_register(&ds4801_device);
	if(err)
	{
		pr_err("3dlcm_device register failed\n");
	}
	pr_debug("3dlcm_device register success\n");
	proc_create("agold_3dlcm", 0664, NULL, &agold_3dlcm_fops);
	#endif
	//[agold][xfl][20160311][end]

	return 0;
}

static int _lcm_i2c_remove(struct i2c_client *client)
{
	pr_debug("[LCM][I2C] _lcm_i2c_remove\n");
	_lcm_i2c_client = NULL;
	i2c_unregister_device(client);
	return 0;
}

static int _lcm_i2c_write_bytes(unsigned char addr, unsigned char value)
{
	int ret = 0;
	struct i2c_client *client = _lcm_i2c_client;
	char write_data[2] = { 0 };

	if (client == NULL) {
		pr_debug("ERROR!! _lcm_i2c_client is null\n");
		return 0;
	}

	write_data[0] = addr;
	write_data[1] = value;
	ret = i2c_master_send(client, write_data, 2);
	if (ret < 0)
		pr_err("[LCM][ERROR] _lcm_i2c write data fail !!\n");

	return ret;
}

static int __init _lcm_i2c_init(void)
{
	pr_debug("[LCM][I2C] _lcm_i2c_init\n");
	#ifdef CONFIG_MTK_LEGACY
	i2c_register_board_info(LCM_I2C_BUSNUM, &_lcm_i2c_board_info, 1);
	pr_debug("[LCM][I2C] _lcm_i2c_init2\n");
	#endif
	i2c_add_driver(&_lcm_i2c_driver);

	pr_debug("[LCM][I2C] _lcm_i2c_init success\n");

	return 0;
}


static void __exit _lcm_i2c_exit(void)
{
	pr_debug("[LCM][I2C] _lcm_i2c_exit\n");
	i2c_del_driver(&_lcm_i2c_driver);
}
#endif


static LCM_STATUS _lcm_i2c_check_data(char type, const LCM_DATA_T2 *t2)
{
	switch (type) {
	case LCM_I2C_WRITE:
		if (t2->cmd > 0xFF) {
			pr_err("[LCM][ERROR] %s/%d: %d\n", __func__, __LINE__, t2->cmd);
			return LCM_STATUS_ERROR;
		}
		if (t2->data > 0xFF) {
			pr_err("[LCM][ERROR] %s/%d: %d\n", __func__, __LINE__, t2->data);
			return LCM_STATUS_ERROR;
		}
		break;

	default:
		pr_err("[LCM][ERROR] %s/%d: %d\n", __func__, __LINE__, type);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}

 
LCM_STATUS lcm_i2c_set_data(char type, const LCM_DATA_T2 *t2)
{
	unsigned int ret_code = 0;

	/* check parameter is valid */
	if (LCM_STATUS_OK == _lcm_i2c_check_data(type, t2)) {
		switch (type) {
		case LCM_I2C_WRITE:
			pr_debug("[LCM][I2C] %s/%d: %d, 0x%x, 0x%x\n", __func__, __LINE__, type,
				 t2->cmd, t2->data);
			ret_code =
			    _lcm_i2c_write_bytes((unsigned char)t2->cmd, (unsigned char)t2->data);
			break;
		default:
			pr_err("[LCM][ERROR] %s/%d: %d\n", __func__, __LINE__, type);
			return LCM_STATUS_ERROR;
		}
	} else {
		pr_err("[LCM][ERROR] %s/%d: %d, 0x%x, 0x%x\n", __func__, __LINE__, type, t2->cmd,
		       t2->data);
		return LCM_STATUS_ERROR;
	}

	if (ret_code < 0) {
		pr_err("[LCM][ERROR] %s/%d: 0x%x, 0x%x, %d\n", __func__, __LINE__,
		       (unsigned int)t2->cmd, (unsigned int)t2->data, ret_code);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}

#ifndef CONFIG_FPGA_EARLY_PORTING
module_init(_lcm_i2c_init);
module_exit(_lcm_i2c_exit);

MODULE_AUTHOR("Joey Pan");
MODULE_DESCRIPTION("MTK LCM I2C Driver");
MODULE_LICENSE("GPL");
#endif

#endif
