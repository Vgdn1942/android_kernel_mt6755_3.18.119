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

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/time.h>
#include "kd_flashlight.h"
#include <asm/io.h>
#include <asm/uaccess.h>
#include "kd_flashlight_type.h"
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/version.h>
#include <linux/mutex.h>
#include <linux/i2c.h>
#include <linux/leds.h>

#include <mt-plat/mt_boot_common.h>

#include <mt_gpio.h>
#include <gpio_const.h>
#include <linux/proc_fs.h>

#define STROBE_DEVICE_ID 0x63
#define LM3643_REG_ENABLE       	0x01
#define LM3643_REG_FLASH_LED1  		0x03
#define LM3643_REG_FLASH_LED2  		0x04
#define LM3643_REG_TORCH_LED1  		0x05
#define LM3643_REG_TORCH_LED2  		0x06
#define LM3643_REG_TIMING           0x08

/******************************************************************************
 * Debug configuration
******************************************************************************/

#define TAG_NAME "[leds_strobe.c]"
#define PK_DBG_FUNC(fmt, arg...)    pr_debug(TAG_NAME "%s: " fmt, __func__ , ##arg)

#define DEBUG_LEDS_STROBE
#ifdef DEBUG_LEDS_STROBE
	#define PK_DBG PK_DBG_FUNC
#else
	#define PK_DBG(a, ...)
#endif

/******************************************************************************
 * local variables
******************************************************************************/
static DEFINE_SPINLOCK(g_strobeSMPLock);
static DEFINE_MUTEX(g_strobeSem);
static u32 strobe_Res;
static u32 strobe_Timeus;
static BOOL g_strobe_On;
static int g_timeOutTimeMs;
static int torch_flag=1;
static int boot_mode = 0;
static struct work_struct workTimeOut;
static struct i2c_client *LM3643_i2c_client;
static struct i2c_driver LM3643_i2c_driver;

static struct pinctrl *pinctrl = NULL;
static struct pinctrl_state *strobe_hwen_low = NULL;
static struct pinctrl_state *strobe_hwen_high = NULL;
static struct pinctrl_state *strobe_strobe_low = NULL;
static struct pinctrl_state *strobe_strobe_high = NULL;

/*****************************************************************************
Functions
*****************************************************************************/
static void work_timeOutFunc(struct work_struct *data);
static int strobe_probe(struct platform_device *pdev);
int setDuty_lm3643_1(int duty);
int setDuty_lm3643_2(int duty);
static int writeReg(int reg, int data);
static int readReg(int reg);
int sub_flash_en(int a);
int FL_dim_duty(kal_uint32 duty);
int FL_Enable(void);
int FL_Disable(void);
int FL_Init(void);
int FL_Uninit(void);
//[20150829][chenpeng][兼容aw3643][start]
#define FLASHLIGHT_COMPATIBLE

#ifdef FLASHLIGHT_COMPATIBLE
unsigned char flashlight_ic = 0;
static char lm3643_g_TorchDutyCode[26] =	{ 0x06, 0x0F, 0x17, 0x1F, 0x27, 0x2F,
											0x37, 0x00, 0x00, 0x00, 0x00, 0x00,
											0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
											0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
											0x00, 0x00 };
#endif
//[20150829][chenpeng][兼容aw3643][end]

struct LM3643_platform_data {
	u8 torch_pin_enable;	/* 1:  TX1/TORCH pin isa hardware TORCH enable */
	u8 pam_sync_pin_enable;	/* 1:  TX2 Mode The ENVM/TX2 is a PAM Sync. on input */
	u8 thermal_comp_mode_enable;	/* 1: LEDI/NTC pin in Thermal Comparator Mode */
	u8 strobe_pin_disable;	/* 1 : STROBE Input disabled */
	u8 vout_mode_enable;	/* 1 : Voltage Out Mode enable */
};

struct LM3643_chip_data {
	struct i2c_client *client;

	/* struct led_classdev cdev_flash; */
	/* struct led_classdev cdev_torch; */
	/* struct led_classdev cdev_indicator; */

	struct LM3643_platform_data *pdata;
	struct mutex lock;

	u8 last_flag;
	u8 no_pdata;
};

/*****************************************************************************
Dual-flash functions
*****************************************************************************/
enum
{
	e_DutyNum = 26,
};

static bool g_IsTorch[26] = 	{ 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
				  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				  0, 0, 0, 0, 0, 0 };
static char g_TorchDutyCode[26] =	{ 0x0F, 0x20, 0x31, 0x42, 0x52, 0x63,
					  0x74, 0x00, 0x00, 0x00, 0x00, 0x00,
					  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					  0x00, 0x00 };

static char g_FlashDutyCode[26] =	{ 0x01, 0x03, 0x05, 0x07, 0x09, 0x0B,
					  0x0D, 0x10, 0x14, 0x19, 0x1D, 0x21,
					  0x25, 0x2A, 0x2E, 0x32, 0x37, 0x3B,
					  0x3F, 0x43, 0x48, 0x4C, 0x50, 0x54,
					  0x59, 0x5D };

static char g_EnableReg;
static int g_duty1 = -1;
static int g_duty2 = -1;
static char ledinit_status = 0;

static int i2c_write_reg(struct i2c_client *client, u8 reg, u8 val)
{
	int ret = 0;
	struct LM3643_chip_data *chip = i2c_get_clientdata(client);

	mutex_lock(&chip->lock);
	ret = i2c_smbus_write_byte_data(client, reg, val);
	mutex_unlock(&chip->lock);

	if (ret < 0)
		PK_DBG("failed writing at 0x%02x\n", reg);
	return ret;
}

static int i2c_read_reg(struct i2c_client *client, u8 reg)
{
	int val=0;
	struct LM3643_chip_data *chip = i2c_get_clientdata(client);

	mutex_lock(&chip->lock);
	val = i2c_smbus_read_byte_data(client, reg);
	mutex_unlock(&chip->lock);


	return val;
}
//[20150829][chenpeng][兼容aw3643][start]
#ifdef FLASHLIGHT_COMPATIBLE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AW3643 Debug file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static ssize_t lm3643_get_reg(struct device* cd,struct device_attribute *attr, char* buf);
static ssize_t lm3643_set_reg(struct device* cd, struct device_attribute *attr,const char* buf, size_t len);
static ssize_t lm3643_set_hwen(struct device* cd, struct device_attribute *attr,const char* buf, size_t len);
static ssize_t lm3643_get_hwen(struct device* cd, struct device_attribute *attr, char* buf);

static DEVICE_ATTR(reg, 0660, lm3643_get_reg,  lm3643_set_reg);
static DEVICE_ATTR(hwen, 0660, lm3643_get_hwen,  lm3643_set_hwen);

static ssize_t lm3643_get_reg(struct device* cd,struct device_attribute *attr, char* buf)
{
	unsigned char reg_val;
	unsigned char i;
	ssize_t len = 0;

	for(i=0;i<0x0E;i++)
	{
		reg_val = i2c_read_reg(LM3643_i2c_client, i);
		len += snprintf(buf+len, PAGE_SIZE-len, "reg%2X = 0x%2X, ", i,reg_val);
	}

	len += snprintf(buf+len, PAGE_SIZE-len, "\r\n");
	
	return len;
}

static ssize_t lm3643_set_reg(struct device* cd, struct device_attribute *attr, const char* buf, size_t len)
{
	unsigned int databuf[2];
	if(2 == sscanf(buf,"%x %x",&databuf[0], &databuf[1]))
	{
		i2c_write_reg(LM3643_i2c_client,databuf[0],databuf[1]);
	}
	return len;
}

static ssize_t lm3643_get_hwen(struct device* cd,struct device_attribute *attr, char* buf)
{
	ssize_t len = 0;
	len += snprintf(buf+len, PAGE_SIZE-len, "lm3643_hwen_on(void)\n");
	len += snprintf(buf+len, PAGE_SIZE-len, "echo 1 > hwen\n");
	len += snprintf(buf+len, PAGE_SIZE-len, "\n");
	len += snprintf(buf+len, PAGE_SIZE-len, "lm3643_hwen_off(void)\n");
	len += snprintf(buf+len, PAGE_SIZE-len, "echo 0 > hwen\n");
	len += snprintf(buf+len, PAGE_SIZE-len, "\n");

	return len;
}

static ssize_t lm3643_set_hwen(struct device* cd, struct device_attribute *attr, const char* buf, size_t len)
{
	unsigned int databuf[16];

	sscanf(buf,"%d",&databuf[0]);
	if(databuf[0] == 0) {			// OFF
	//flashlight_gpio_set(FLASHLIGHT_PIN_HWEN, STATE_LOW);
	pinctrl_select_state(pinctrl,strobe_hwen_low);

	} else {						// ON
		//flashlight_gpio_set(FLASHLIGHT_PIN_HWEN, STATE_HIGH);
	pinctrl_select_state(pinctrl,strobe_hwen_high);
	}

	return len;
}

static int lm3643_create_sysfs(struct i2c_client *client)
{
	int err;
	struct device *dev = &(client->dev);

	err = device_create_file(dev, &dev_attr_reg);
	err = device_create_file(dev, &dev_attr_hwen);

	return err;
}
#endif
//[20150829][chenpeng][兼容aw3643][end]


static int LM3643_chip_init(struct LM3643_chip_data *chip)
{

	//mt_set_gpio_out(GPIO_CAMERA_FLASH_EN_PIN, GPIO_OUT_ONE);
	pinctrl_select_state(pinctrl,strobe_hwen_high);
	return 0;
}
  
static int LM3643_gpio_init(struct platform_device *pdev)
{
	int ret = 0;

	struct device_node *node = NULL;
	PK_DBG("strobe [%s][line:%d] test 0 \n", __func__, __LINE__);
	
	node = of_find_compatible_node(NULL, NULL,"mediatek,strobe");
	if(node)
	{
		pinctrl = devm_pinctrl_get(&pdev->dev);
		strobe_hwen_low = pinctrl_lookup_state(pinctrl, "strobe_hwen_gpio_l");
		if (IS_ERR(strobe_hwen_low)) 
		{
			ret = PTR_ERR(strobe_hwen_low);
			PK_DBG("strobe cannot find pinctrl strobe_hwen_low\n");
			return -1;
		}
	
		strobe_hwen_high = pinctrl_lookup_state(pinctrl, "strobe_hwen_gpio_h");
		if (IS_ERR(strobe_hwen_high)) 
		{
			ret = PTR_ERR(strobe_hwen_high);
			PK_DBG("strobe cannot find pinctrl strobe_hwen_high\n");
			return -1;
		}

		strobe_strobe_low = pinctrl_lookup_state(pinctrl, "strobe_strobe_gpio_l");
		if (IS_ERR(strobe_strobe_low)) 
		{
			ret = PTR_ERR(strobe_strobe_low);
			PK_DBG("strobe cannot find pinctrl strobe_strobe_low\n");
			return -1;
		}
	
		strobe_strobe_high = pinctrl_lookup_state(pinctrl, "strobe_strobe_gpio_h");
		if (IS_ERR(strobe_strobe_high)) 
		{
			ret = PTR_ERR(strobe_strobe_high);
			PK_DBG("strobe cannot find pinctrl strobe_strobe_high\n");
			return -1;
		}
	}
	else
	{
		PK_DBG("strobe cannot find node\n");
		return -1;
	}
	
	return 0;
}


int test_flashEnable_LM3643_1(void)
{
	int temp = 0;
	
	temp = readReg(LM3643_REG_ENABLE);

	PK_DBG("fun:%s, reg[1]:0x%x\n", __func__, temp);
	
	if(torch_flag)
		 writeReg(LM3643_REG_ENABLE, temp|0x09);
	else
         writeReg(LM3643_REG_ENABLE, temp|0x0D);
	return 0;
}

int test_flashDisable_LM3643_1(void)
{
	int temp = 0;
	temp = readReg(LM3643_REG_ENABLE);
	PK_DBG("fun:%s, reg[1]:0x%x\n", __func__, temp);
    writeReg(LM3643_REG_ENABLE, temp&0xFE);
    
	return 0;
}

int test_flashEnable_LM3643_2(void)
{
	int temp = 0;
	
	temp=readReg(LM3643_REG_ENABLE);
	PK_DBG("fun:%s, reg[1]:0x%x\n", __func__, temp);
	
	if(torch_flag)
		 writeReg(LM3643_REG_ENABLE, temp|0x0A);
	else
         writeReg(LM3643_REG_ENABLE, temp|0x0E);

	return 0;
}

int test_flashDisable_LM3643_2(void)
{
	int temp = 0;
	temp = readReg(LM3643_REG_ENABLE);
	PK_DBG("fun:%s, reg[1]:0x%x\n", __func__, temp);
    writeReg(LM3643_REG_ENABLE, temp&0xFD);

	return 0;
}

int test_setDuty_LM3643_1(int duty)
{

	if(duty<0)
		duty=0;
	else if(duty>=e_DutyNum)
		duty=e_DutyNum-1;
	g_duty1=duty;
	
	if(torch_flag)
		writeReg(LM3643_REG_TORCH_LED1, g_TorchDutyCode[duty]);
	else
	    writeReg(LM3643_REG_FLASH_LED1, g_FlashDutyCode[duty]);
	       
	PK_DBG(" setDuty_LM3643_1 line=%d\n",__LINE__);

	return 0;
}

int test_setDuty_LM3643_2(int duty)
{

	if(duty<0)
		duty=0;
	else if(duty>=e_DutyNum)
		duty=e_DutyNum-1;
	g_duty2=duty;
	
	if(torch_flag)
		writeReg(LM3643_REG_TORCH_LED2, g_TorchDutyCode[duty]);
	else 
       writeReg(LM3643_REG_FLASH_LED2, g_FlashDutyCode[duty]);   
	PK_DBG(" setDuty_LM3643_2 line=%d\n",__LINE__);

	return 0;
}

static ssize_t show_chipinfo_value(struct device_driver *ddri, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "LM3643\n"); 
}

static ssize_t show_ledinit_value(struct device_driver *ddri, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "LM3643 ledinit status=%d\n",ledinit_status); 
}

static ssize_t store_ledinit_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int en = 0;
	if(1 == sscanf(buf,"%d",&en))
	{
		if(en)
		{
			FL_Init();
			ledinit_status = 1;
		}
		else
		{
			FL_Uninit();
			ledinit_status = 0;
        }	
	}
	else
	{
		PK_DBG("fun %s input error\n",__func__);
	}
	return count; 
}

static ssize_t show_led1en_value(struct device_driver *ddri, char *buf)
{
	char regv = 0;
	regv = readReg(0x01) & 0x01;
	return snprintf(buf, PAGE_SIZE, "LM3643 led1 en=%d\n",regv); 
}

static ssize_t show_led2en_value(struct device_driver *ddri, char *buf)
{
	char regv = 0;
	regv = (readReg(0x01) >> 1) & 0x01;
	return snprintf(buf, PAGE_SIZE, "LM3643 led2 en=%d\n",regv); 
}

static ssize_t store_led1en_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int en = 0;
	if(1 == sscanf(buf,"%d",&en))
	{
		if(en)
			test_flashEnable_LM3643_1();
		else
			test_flashDisable_LM3643_1();
	}
	else
	{
		PK_DBG("fun %s input error\n",__func__);
	}
	return count; 
}

static ssize_t store_led2en_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int en = 0;
	if(1 == sscanf(buf,"%d",&en))
	{
		if(en)
			test_flashEnable_LM3643_2();
		else
			test_flashDisable_LM3643_2();
	}
	else
	{
		PK_DBG("fun %s input error\n",__func__);
	}
	return count; 
}

static ssize_t show_led1duty_value(struct device_driver *ddri, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "LM3643 led1 duty=%d\n",g_duty1); 
}

static ssize_t show_led2duty_value(struct device_driver *ddri, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "LM3643 led2 duty=%d\n",g_duty2); 
}

static ssize_t store_led1duty_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int duty = 0;
	if(1 == sscanf(buf,"%d",&duty))
	{
		if(duty < 0 || duty > 25)
			duty = 0;
		g_duty1 = duty;
		test_setDuty_LM3643_1(duty);
	}
	else
	{
		PK_DBG("fun %s input error\n",__func__);
	}
	return count;
}

static ssize_t store_led2duty_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int duty = 0;
	if(1 == sscanf(buf,"%d",&duty))
	{
		if(duty < 0 || duty > 25)
			duty = 0;
		g_duty2 = duty;
		test_setDuty_LM3643_2(duty);
	}
	else
	{
		PK_DBG("fun %s input error\n",__func__);
	}
	return count;
}

static ssize_t show_ledmode_value(struct device_driver *ddri, char *buf)
{
	char mflash[] = "flash mode";
	char mtorch[] = "torch mode";
	if(torch_flag)
		return snprintf(buf, PAGE_SIZE, "LM3643 led mode=%s\n",mtorch); 
	else
		return snprintf(buf, PAGE_SIZE, "LM3643 led mode=%s\n",mflash); 
}

static ssize_t store_ledmode_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int mode = 0;
	if(1 == sscanf(buf,"%d",&mode))
	{
		if(mode > 0)
			torch_flag = 1;
		else
			torch_flag = 0;
	}
	else
	{
		PK_DBG("fun %s input error\n",__func__);
	}
	return count;
}

static ssize_t show_register_value(struct device_driver *ddri, char *buf)
{
	int i = 0;
	int val[12];
	char v[250];
	int len = 0;
	memset(val, 0, sizeof(val));
	memset(v, 0, sizeof(v));

	for(i=0; i<12; i++)
	{
		val[i] = readReg(i);
		len += sprintf(&v[0]+len,"reg[%x] = 0x%x\n",i,val[i]);
	}
	return snprintf(buf, PAGE_SIZE, "%s\n",v);
}

static ssize_t store_register_value(struct device_driver *ddri, const char *buf, size_t count)
{
	int val = 0 ,reg = 0;
	if(2 == sscanf(buf,"0x%x 0x%x",&reg ,&val))
	{
		writeReg(reg,val);
	}
	else
	{
		PK_DBG("fun %s input error\n",__func__);
	}
	return count;
}

static DRIVER_ATTR(chipinfo, S_IRUGO, show_chipinfo_value,  NULL);
static DRIVER_ATTR(led1en, S_IWUSR | S_IRUGO, show_led1en_value,  store_led1en_value);
static DRIVER_ATTR(led2en, S_IWUSR | S_IRUGO, show_led2en_value,  store_led2en_value);
static DRIVER_ATTR(led1duty, S_IWUSR | S_IRUGO, show_led1duty_value,  store_led1duty_value);
static DRIVER_ATTR(led2duty, S_IWUSR | S_IRUGO, show_led2duty_value,  store_led2duty_value);
static DRIVER_ATTR(ledinit, S_IWUSR | S_IRUGO, show_ledinit_value,  store_ledinit_value);
static DRIVER_ATTR(ledmode, S_IWUSR | S_IRUGO, show_ledmode_value,  store_ledmode_value);
static DRIVER_ATTR(reg, S_IWUSR | S_IRUGO, show_register_value,  store_register_value);

static struct driver_attribute *lm3643_attr_list[] = {
	&driver_attr_chipinfo,
	&driver_attr_led1en,
	&driver_attr_led2en,
	&driver_attr_led1duty,
	&driver_attr_led2duty,
	&driver_attr_ledmode,
	&driver_attr_reg,
	&driver_attr_ledinit,
};


static int lm3643_create_attr(struct device_driver *driver) 
{
	int idx, err = 0;
	int num = (int)(sizeof(lm3643_attr_list)/sizeof(lm3643_attr_list[0]));
	if (driver == NULL)
	{
		return -EINVAL;
	}

	for(idx = 0; idx < num; idx++)
	{
		if(0 != (err = driver_create_file(driver, lm3643_attr_list[idx])))
		{            
			PK_DBG("driver_create_file (%s) = %d\n", lm3643_attr_list[idx]->attr.name, err);
			break;
		}
	}    
	return err;
}


static int LM3643_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct LM3643_chip_data *chip;
	struct LM3643_platform_data *pdata = client->dev.platform_data;

	int err = -1;
//[20150829][chenpeng][兼容aw3643][start]
#ifdef FLASHLIGHT_COMPATIBLE
	unsigned char cnt = 5;
	unsigned char reg;
#endif
//[20150829][chenpeng][兼容aw3643][end]
	PK_DBG("LM3643_probe start--->.\n");

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		err = -ENODEV;
		PK_DBG("LM3643 i2c functionality check fail.\n");
		return err;
	}

	chip = kzalloc(sizeof(struct LM3643_chip_data), GFP_KERNEL);
	chip->client = client;

	mutex_init(&chip->lock);
	i2c_set_clientdata(client, chip);

	if (pdata == NULL) {	/* values are set to Zero. */
		PK_DBG("LM3643 Platform data does not exist\n");
		pdata = kzalloc(sizeof(struct LM3643_platform_data), GFP_KERNEL);
		chip->pdata = pdata;
		chip->no_pdata = 1;
	}

	chip->pdata = pdata;

	if (LM3643_chip_init(chip) < 0)
		goto err_chip_init;

	LM3643_i2c_client = client;

//[20150829][chenpeng][兼容aw3643][start]
#ifdef FLASHLIGHT_COMPATIBLE
	// HWEN High
	//flashlight_gpio_set(FLASHLIGHT_PIN_HWEN, STATE_HIGH);
	pinctrl_select_state(pinctrl,strobe_hwen_high);
	msleep(10);
	while(cnt > 0)
	{
		reg = i2c_read_reg(client, 0x00);
		PK_DBG("lm3643 reg0 = 0x%x",reg);
		if(reg == 0x36)
		{
			PK_DBG("lm3643 Flashlight IC is AW364x \n");
			flashlight_ic = 1;
			lm3643_create_sysfs(client);
			break;
		}
		else
		{
			PK_DBG("lm3643 Flashlight IC is not AW364x \n");
		}
		cnt --;
		msleep(10);
	}
	// HWEN Low
	//flashlight_gpio_set(FLASHLIGHT_PIN_HWEN, STATE_LOW);
	pinctrl_select_state(pinctrl,strobe_hwen_low);
	msleep(1);
#endif
//[20150829][chenpeng][兼容aw3643][end]


	if(0 != (err = lm3643_create_attr(&LM3643_i2c_driver.driver)))
	{
		PK_DBG("create attribute err = %d\n", err);
		goto err_chip_init;
	}

	PK_DBG("LM3643 Initializing is done\n");

	return 0;

err_chip_init:
	i2c_set_clientdata(client, NULL);
	kfree(chip);
	PK_DBG("LM3643 probe is failed\n");
	return -ENODEV;
}

static int LM3643_remove(struct i2c_client *client)
{
	struct LM3643_chip_data *chip = i2c_get_clientdata(client);

	if (chip->no_pdata)
		kfree(chip->pdata);
	kfree(chip);
	return 0;
}

#define LM3643_NAME "leds-LM3643"
static const struct i2c_device_id LM3643_id[] = {
	{LM3643_NAME, 0},
	{}
};

#ifdef CONFIG_OF
static const struct of_device_id LM3643_of_match[] = {
	{.compatible = "mediatek,strobe_main"},
	{},
};
#endif

static struct i2c_driver LM3643_i2c_driver = {
	.driver = {
		   .name = LM3643_NAME,
#ifdef CONFIG_OF
		   .of_match_table = LM3643_of_match,
#endif
		   },
	.probe = LM3643_probe,
	.remove = LM3643_remove,
	.id_table = LM3643_id,
};

#ifdef CONFIG_OF
struct of_device_id strobe_of_match[] = {
	{ .compatible = "mediatek,strobe", },
	{},
};
#endif

static int strobe_remove(struct platform_device *pdev)
{
	PK_DBG("strobe_remove\n");
	return 0;
}

static struct platform_driver strobe_driver = {
	.remove = strobe_remove,
	.shutdown = NULL,
	.probe = strobe_probe,
	.driver = {
		.name = "strobe",
		#ifdef CONFIG_OF
		.of_match_table = strobe_of_match,
		#endif
	},
};

static ssize_t  strobe_write_proc(struct file *file, const char *buffer, size_t count, loff_t *data)
{
 
    char regBuf[64] = {'\0'};
    int timeout = 0;
	int duty = 0;
    
    u32 u4CopyBufSize = (count < (sizeof(regBuf) - 1)) ? (count) : (sizeof(regBuf) - 1); 

    if (copy_from_user(regBuf, buffer, u4CopyBufSize))
    return -EFAULT;

    if (sscanf(regBuf, "%d %d", &timeout, &duty) ==2)
	{
		FL_dim_duty(duty);
		FL_Enable();
		udelay(timeout);
		FL_Disable();
	}
	
    return count;
}

static struct file_operations strobe_fops = { 
    .read  = NULL,
    .write = strobe_write_proc
};

static int strobe_probe(struct platform_device *pdev)
{
	PK_DBG("start strobe_probe.\n");

	LM3643_gpio_init(pdev);

	#ifdef AGOLD_FLASHLIGHT_USE_LM3643
	return i2c_add_driver(&LM3643_i2c_driver);
	#endif
	
	//agold xfl single flashlight debug
	proc_create("agold_strobe", 0664, NULL, &strobe_fops);

	return 0;
}

static int __init LM3643_init(void)
{
	PK_DBG("LM3643_init\n");

	if (platform_driver_register(&strobe_driver))
	{
		PK_DBG("platform_driver_registe strobe failed!\n");
		return -1;
	}

	
	return 0;
}

static void __exit LM3643_exit(void)
{
	i2c_del_driver(&LM3643_i2c_driver);
}


module_init(LM3643_init);
module_exit(LM3643_exit);

MODULE_DESCRIPTION("Flash driver for LM3643");
MODULE_AUTHOR("pw <pengwei@mediatek.com>");
MODULE_LICENSE("GPL v2");


static int LM3643_write_reg(struct i2c_client *client, u8 reg, u8 val)
{
	return i2c_write_reg(client, reg, val);
}

static int LM3643_read_reg(struct i2c_client *client, u8 reg)
{
	int val;

	val = i2c_read_reg(client, reg);
	PK_DBG("LM3643_read_reg reg=0x%x val=0x%x\n", reg, val);
	return val;
}

int flashEnable_lm3643_1(void)
{
	int ret;
	char buf[2];

	//xfl
	boot_mode = get_boot_mode();
	
	if(boot_mode == FACTORY_BOOT)
	{
		g_duty1 = 10;
		setDuty_lm3643_1(g_duty1);
		g_EnableReg |= (0x09);
	}
	else if (g_IsTorch[g_duty1] == 1) /* LED1 in torch mode */
	{
		g_EnableReg |= (0x09);
	}
	else
		g_EnableReg |= (0x0D);

	buf[0] = 0x01; /* Enable Register */
	buf[1] = g_EnableReg;


	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);
	return ret;
}

int flashEnable_lm3643_2(void)
{
	int ret;
	char buf[2];

	//xfl
	boot_mode = get_boot_mode();

	if(boot_mode == FACTORY_BOOT)
	{
		g_duty2 = 10;
		g_duty1 = 10;
		setDuty_lm3643_1(g_duty1);
		setDuty_lm3643_2(g_duty2);
		g_EnableReg |= (0x0B);
	}
	else if (g_IsTorch[g_duty2] == 1) /* LED2 in torch mode */
	{
		g_EnableReg |= (0x0A);
	}
	else
		g_EnableReg |= (0x0E);

	buf[0] = 0x01; /* Enable Register */
	buf[1] = g_EnableReg;

	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);
	return ret;
}

int flashDisable_lm3643_1(void)
{
	int ret;
	char buf[2];

	buf[0] = 0x01; /* Enable Register */
	if ((g_EnableReg&0x02) == 0x02) /* LED2 enabled */
		g_EnableReg &= (~0x01);
	else
		g_EnableReg &= (~0x0D);
	buf[1] = g_EnableReg;
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);
	return ret;
}

int flashDisable_lm3643_2(void)
{
	int ret;
	char buf[2];

	buf[0] = 0x01; /* Enable Register */
	if ((g_EnableReg&0x01) == 0x01) /* LED1 enabled */
		g_EnableReg &= (~0x02);
	else
		g_EnableReg &= (~0x0E);
	buf[1] = g_EnableReg;
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);
	return ret;
}

int setDuty_lm3643_1(int duty)
{
	int ret;
	char buf[2];

	if (duty < 0)
		duty = 0;
	else if (duty >= e_DutyNum)
		duty = e_DutyNum-1;

	g_duty1 = duty;
	buf[0] = 0x05; /* LED1 Torch Brightness Register */
	buf[1] = g_TorchDutyCode[duty];
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);

	buf[0] = 0x03; /* LED1 Flash Brightness Register */
	buf[1] = g_FlashDutyCode[duty];
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);
	return ret;
}

int setDuty_lm3643_2(int duty)
{
	int ret;
	char buf[2];

	if (duty < 0)
		duty = 0;
	else if (duty >= e_DutyNum)
		duty = e_DutyNum-1;

	g_duty2 = duty;
	buf[0] = 0x06; /* LED2 Torch Brightness Register */
	buf[1] = g_TorchDutyCode[duty];
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);

	buf[0] = 0x04; /* LED2 Flash Brightness Register */
	buf[1] = g_FlashDutyCode[duty];
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);
	return ret;
}

static int writeReg(int reg, int data)
{
	int ret = 0;
	ret = LM3643_write_reg(LM3643_i2c_client, reg, data);
	
	return ret;
}

static int readReg(int reg)
{
	int ret = 0;
	ret = LM3643_read_reg(LM3643_i2c_client, reg);
	
	return ret;
}

int sub_flash_en(int enable)
{
	
	PK_DBG("sub_flash_en enable:%d\n", enable);
	if(enable == 1)
	{
		#ifdef AGOLD_FLASHLIGHT_USE_LM3643
		writeReg(0x01, 0x09);
		writeReg(0x03, 0xB0);
		#else
		pinctrl_select_state(pinctrl,strobe_strobe_low);
		pinctrl_select_state(pinctrl,strobe_hwen_high);
		#endif
	}
	else
	{
		#ifdef AGOLD_FLASHLIGHT_USE_LM3643
		writeReg(0x01, 0x00);		
		#else
		pinctrl_select_state(pinctrl,strobe_hwen_low);
		#endif
	}

	return 0;
} 

int init_lm3643(void)
{
	int ret;
	char buf[2];

	//flashlight_gpio_set(FLASHLIGHT_PIN_HWEN, STATE_HIGH);
	//mt_set_gpio_out(GPIO_CAMERA_FLASH_EN_PIN, GPIO_OUT_ONE);
	pinctrl_select_state(pinctrl,strobe_hwen_high);

	buf[0] = 0x01; /* Enable Register */
	buf[1] = 0x00;
	g_EnableReg = buf[1];
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);

	buf[0] = 0x03; /* LED1 Flash Brightness Register */
	buf[1] = 0x3F;
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);

	buf[0] = 0x05; /* LED2 Flash Brightness Register */
	buf[1] = 0x3F;
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);

	buf[0] = 0x08; /* Timing Configuration Register */
//[20150829][chenpeng][兼容aw3643][start]
#ifndef FLASHLIGHT_COMPATIBLE
	buf[1] = 0x1F;
#else
	if(flashlight_ic == 1)
	{

	    PK_DBG("lm3643  AW364x Timing Config, Torch Dutu Config, line=%d\n", __LINE__);
	    buf[1] = 0x19;
            memcpy(g_TorchDutyCode, lm3643_g_TorchDutyCode, sizeof(g_TorchDutyCode));
	}
	else
	{
	    PK_DBG("lm3643  lm3643 Timing Config, line=%d\n", __LINE__);
	    buf[1] = 0x1F;
	}
#endif
//[20150829][chenpeng][兼容aw3643][end]
	ret = LM3643_write_reg(LM3643_i2c_client, buf[0], buf[1]);
	return ret;
}

int FL_Enable(void)
{
	PK_DBG(" FL_Enable line=%d\n", __LINE__);
	#ifdef AGOLD_FLASHLIGHT_USE_LM3643
	return flashEnable_lm3643_1();
	#endif

	pinctrl_select_state(pinctrl,strobe_strobe_high);//gpio7 ENF

	return 0;
}



int FL_Disable(void)
{
	PK_DBG(" FL_Disable line=%d\n", __LINE__);
	#ifdef AGOLD_FLASHLIGHT_USE_LM3643
	return flashDisable_lm3643_1();
	#endif

	pinctrl_select_state(pinctrl,strobe_strobe_low);//gpio7 ENF
	pinctrl_select_state(pinctrl,strobe_hwen_low);//gpio100 ENM

	return 0;
}

int FL_dim_duty(kal_uint32 duty)
{
	int i = 0;

	PK_DBG(" FL_dim_duty line=%d\n", __LINE__);
	#ifdef AGOLD_FLASHLIGHT_USE_LM3643
	return setDuty_lm3643_1(duty);
	#endif

	if(duty == 0)
	{
		pinctrl_select_state(pinctrl,strobe_hwen_high);//gpio100 ENM
	}
	else
	{
		//[agold][xfl][20160519][cotrol flash current]
		pinctrl_select_state(pinctrl,strobe_hwen_low);//gpio100 ENM
		pinctrl_select_state(pinctrl,strobe_strobe_low);//gpio7 ENF
		udelay(50);
		pinctrl_select_state(pinctrl,strobe_strobe_high);//gpio7 ENF
		udelay(200);
		for (i=1; i < duty; i++)
		{
			pinctrl_select_state(pinctrl,strobe_strobe_low);//gpio7 ENF
			udelay(50);
			pinctrl_select_state(pinctrl,strobe_strobe_high);//gpio7 ENF
			udelay(100);
		}
	}
	
	return 0;
}

int FL_Init(void)
{
	PK_DBG(" FL_Init line=%d\n", __LINE__);
	#ifdef AGOLD_FLASHLIGHT_USE_LM3643
	return init_lm3643();
	#endif

	return 0;
}

int FL_Uninit(void)
{
	FL_Disable();
	#ifdef AGOLD_FLASHLIGHT_USE_LM3643
	pinctrl_select_state(pinctrl,strobe_hwen_low);
	#endif

	return 0;
}

/*****************************************************************************
User interface
*****************************************************************************/

static void work_timeOutFunc(struct work_struct *data)
{
	FL_Disable();
	PK_DBG("ledTimeOut_callback\n");
}



enum hrtimer_restart ledTimeOutCallback(struct hrtimer *timer)
{
	schedule_work(&workTimeOut);
	return HRTIMER_NORESTART;
}
static struct hrtimer g_timeOutTimer;
void timerInit(void)
{
	static int init_flag;

	if (init_flag == 0) {
		init_flag = 1;
		INIT_WORK(&workTimeOut, work_timeOutFunc);
		g_timeOutTimeMs = 1000;
		hrtimer_init(&g_timeOutTimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
		g_timeOutTimer.function = ledTimeOutCallback;
	}
}



static int constant_flashlight_ioctl(unsigned int cmd, unsigned long arg)
{
	int i4RetValue = 0;
	int ior_shift;
	int iow_shift;
	int iowr_shift;

	ior_shift = cmd - (_IOR(FLASHLIGHT_MAGIC, 0, int));
	iow_shift = cmd - (_IOW(FLASHLIGHT_MAGIC, 0, int));
	iowr_shift = cmd - (_IOWR(FLASHLIGHT_MAGIC, 0, int));
/*	PK_DBG
	    ("LM3643 constant_flashlight_ioctl() line=%d ior_shift=%d, iow_shift=%d iowr_shift=%d arg=%d\n",
	     __LINE__, ior_shift, iow_shift, iowr_shift, (int)arg);
*/
	switch (cmd) {

	case FLASH_IOC_SET_TIME_OUT_TIME_MS:
		PK_DBG("FLASH_IOC_SET_TIME_OUT_TIME_MS: %d\n", (int)arg);
		g_timeOutTimeMs = arg;
		break;


	case FLASH_IOC_SET_DUTY:
		PK_DBG("FLASHLIGHT_DUTY: %d\n", (int)arg);
		FL_dim_duty(arg);
		break;


	case FLASH_IOC_SET_STEP:
		PK_DBG("FLASH_IOC_SET_STEP: %d\n", (int)arg);

		break;

	case FLASH_IOC_SET_ONOFF:
		PK_DBG("FLASHLIGHT_ONOFF: %d\n", (int)arg);
		if (arg == 1) {

			int s;
			int ms;

			if (g_timeOutTimeMs > 1000) {
				s = g_timeOutTimeMs / 1000;
				ms = g_timeOutTimeMs - s * 1000;
			} else {
				s = 0;
				ms = g_timeOutTimeMs;
			}

			if (g_timeOutTimeMs != 0) {
				ktime_t ktime;

				ktime = ktime_set(s, ms * 1000000);
				hrtimer_start(&g_timeOutTimer, ktime, HRTIMER_MODE_REL);
			}
			FL_Enable();
		} else {
			FL_Disable();
			hrtimer_cancel(&g_timeOutTimer);
		}
		break;
	default:
		PK_DBG(" No such command\n");
		i4RetValue = -EPERM;
		break;
	}
	return i4RetValue;
}




static int constant_flashlight_open(void *pArg)
{
	int i4RetValue = 0;

	PK_DBG("constant_flashlight_open line=%d\n", __LINE__);

	if (0 == strobe_Res) {
		FL_Init();
		timerInit();
	}
	PK_DBG("constant_flashlight_open line=%d\n", __LINE__);
	spin_lock_irq(&g_strobeSMPLock);


	if (strobe_Res) {
		PK_DBG(" busy!\n");
		i4RetValue = -EBUSY;
	} else {
		strobe_Res += 1;
	}


	spin_unlock_irq(&g_strobeSMPLock);
	PK_DBG("constant_flashlight_open line=%d\n", __LINE__);

	return i4RetValue;

}


static int constant_flashlight_release(void *pArg)
{
	PK_DBG(" constant_flashlight_release\n");

	if (strobe_Res) {
		spin_lock_irq(&g_strobeSMPLock);

		strobe_Res = 0;
		strobe_Timeus = 0;

		/* LED On Status */
		g_strobe_On = FALSE;

		spin_unlock_irq(&g_strobeSMPLock);

		FL_Uninit();
	}

	PK_DBG(" Done\n");

	return 0;

}


FLASHLIGHT_FUNCTION_STRUCT constantFlashlightFunc = {
	constant_flashlight_open,
	constant_flashlight_release,
	constant_flashlight_ioctl
};


MUINT32 constantFlashlightInit(PFLASHLIGHT_FUNCTION_STRUCT *pfFunc)
{
	if (pfFunc != NULL)
		*pfFunc = &constantFlashlightFunc;
	return 0;
}
EXPORT_SYMBOL(constantFlashlightInit);


/* LED flash control for high current capture mode*/
ssize_t strobe_VDIrq(void)
{

	return 0;
}
EXPORT_SYMBOL(strobe_VDIrq);
