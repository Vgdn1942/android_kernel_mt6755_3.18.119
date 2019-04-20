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
#include <linux/errno.h>
#include <linux/time.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include "kd_camera_typedef.h"
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/version.h>
#include <linux/gpio.h>
#ifdef CONFIG_COMPAT
#include <linux/fs.h>
#include <linux/compat.h>
#endif
#include "kd_flashlight.h"
#include "kd_flashlight_type.h"

#include <mt-plat/upmu_common.h>
/******************************************************************************
 * Debug configuration
******************************************************************************/
/* availible parameter */
/* ANDROID_LOG_ASSERT */
/* ANDROID_LOG_ERROR */
/* ANDROID_LOG_WARNING */
/* ANDROID_LOG_INFO */
/* ANDROID_LOG_DEBUG */
/* ANDROID_LOG_VERBOSE */
#define TAG_NAME "[sub_strobe.c]"
#define PK_DBG_NONE(fmt, arg...)    do {} while (0)
#define PK_DBG_FUNC(fmt, arg...)    pr_debug(TAG_NAME "%s: " fmt, __func__ , ##arg)
#define PK_WARN(fmt, arg...)        pr_warn(TAG_NAME "%s: " fmt, __func__ , ##arg)
#define PK_NOTICE(fmt, arg...)      pr_notice(TAG_NAME "%s: " fmt, __func__ , ##arg)
#define PK_INFO(fmt, arg...)        pr_info(TAG_NAME "%s: " fmt, __func__ , ##arg)
#define PK_TRC_FUNC(f)              pr_debug(TAG_NAME "<%s>\n", __func__)
#define PK_TRC_VERBOSE(fmt, arg...) pr_debug(TAG_NAME fmt, ##arg)
#define PK_ERROR(fmt, arg...)       pr_err(TAG_NAME "%s: " fmt, __func__ , ##arg)

#define DEBUG_LEDS_STROBE
#ifdef DEBUG_LEDS_STROBE
#define PK_DBG PK_DBG_FUNC
#define PK_VER PK_TRC_VERBOSE
#define PK_ERR PK_ERROR
#else
#define PK_DBG(a, ...)
#define PK_VER(a, ...)
#define PK_ERR(a, ...)
#endif

static struct work_struct workTimeOut;
static DEFINE_SPINLOCK(g_substrobeSMPLock); /* cotta-- SMP proection */
static u32 strobe_Res=0;
static u32 strobe_Timeus = 0;
static int gDuty=0;
static int g_timeOutTimeMs=0;

//static int gLedDuty[18]={0,32,64,96,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
static struct hrtimer g_timeOutTimer;


static int SUB_FL_Enable(void);
static int SUB_FL_Disable(void);
static int SUB_FL_Init(void);
static int SUB_FL_Uninit(void);
static int SUB_FL_dim_duty(kal_uint32 duty);
static void work_timeOutFunc(struct work_struct *data);
static enum hrtimer_restart ledTimeOutCallback(struct hrtimer *timer);
static void timerInit(void);
static void isink_chanel_init(void);

#if defined(AGOLD_SUB_FLASHLIGHT_USE_GPIO)
#define SUB_FLASHLIGHT_EN_PIN 47
#else
static void set_isink(int en , kal_uint32 duty);
static int gIsTorch[18]={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#endif

static int SUB_FL_Enable(void)
{
#if defined(AGOLD_SUB_FLASHLIGHT_USE_GPIO)
	int i = 0;
    gpio_set_value(SUB_FLASHLIGHT_EN_PIN ,1);
    udelay(25);
    for(i = 0; i <= 5; i++)
    {
    	gpio_set_value(SUB_FLASHLIGHT_EN_PIN ,0);
    	udelay(5);
    	gpio_set_value(SUB_FLASHLIGHT_EN_PIN ,1);
    	udelay(5);
    }

#else
	if(gIsTorch[gDuty]==1)
		set_isink(1 , 55);
	else
		set_isink(1 , 60);
		PK_DBG(" SUB_FL_Enable line=%d\n",__LINE__);

#endif

	return 0;
}

static int SUB_FL_Disable(void)
{
#if defined(AGOLD_SUB_FLASHLIGHT_USE_GPIO)
	gpio_set_value(SUB_FLASHLIGHT_EN_PIN ,0);
#else
	set_isink(0,0);

		PK_DBG(" SUB_FL_Disable line=%d\n",__LINE__);
#endif
	return 0;
}

void set_FL_enable(int enable)
{
#if defined(AGOLD_SUB_FLASHLIGHT_USE_GPIO)
	if(enable)
		gpio_set_value(SUB_FLASHLIGHT_EN_PIN ,1);
	else
	    gpio_set_value(SUB_FLASHLIGHT_EN_PIN ,0);
#else
	if(enable)
	{
		set_isink(1 , 60);
	}
	else
	{
		set_isink(0,0);
	}
#endif
	
}

EXPORT_SYMBOL(set_FL_enable);
#if defined(AGOLD_SUB_FLASHLIGHT_USE_GPIO)

		

#else

static void set_isink(int en , kal_uint32 duty)
{


	PK_DBG("enter set inink!en = %d\n",en);
	if(en)
	{
		//pmic_set_register_value(PMIC_ISINK_CH0_EN, 1);
		pmic_set_register_value(PMIC_ISINK_CH1_EN, 1);
		pmic_set_register_value(PMIC_ISINK_CH4_EN, 1);
		pmic_set_register_value(PMIC_ISINK_CH5_EN, 1);
	}
	else
	{
		//pmic_set_register_value(PMIC_ISINK_CH0_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH1_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH4_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH5_EN, 0);
	}

}
#endif
static void isink_chanel_init(void)
{
#if defined(AGOLD_SUB_FLASHLIGHT_USE_GPIO)


#else
	//isink0
/*
	pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN, 0x0);	// Disable power down
	pmic_set_register_value(PMIC_RG_DRV_ISINK0_CK_PDN, 0);
	pmic_set_register_value(PMIC_RG_DRV_ISINK0_CK_CKSEL, 0);
	pmic_set_register_value(PMIC_ISINK_CH0_MODE, 0);
	pmic_set_register_value(PMIC_ISINK_CH0_STEP, 3);	// 16mA
	pmic_set_register_value(PMIC_ISINK_DIM0_DUTY, 15);
	pmic_set_register_value(PMIC_ISINK_DIM0_FSEL, 0);	// 1KHz
*/

	//isink1
	pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN, 0x0);	/* Disable power down */
	pmic_set_register_value(PMIC_RG_DRV_ISINK1_CK_PDN, 0);
	pmic_set_register_value(PMIC_RG_DRV_ISINK1_CK_CKSEL, 0);
	pmic_set_register_value(PMIC_ISINK_CH1_MODE, 0);
	pmic_set_register_value(PMIC_ISINK_CH1_STEP, 3);	/* 16mA */
	pmic_set_register_value(PMIC_ISINK_DIM1_DUTY, 15);
	pmic_set_register_value(PMIC_ISINK_DIM1_FSEL, 0);	/* 1KHz */	

	//isink2
	pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN, 0x0);	/* Disable power down */
	pmic_set_register_value(PMIC_RG_DRV_ISINK4_CK_PDN, 0);
	pmic_set_register_value(PMIC_RG_DRV_ISINK4_CK_CKSEL, 0);
	pmic_set_register_value(PMIC_ISINK_CH4_MODE, 0);
	pmic_set_register_value(PMIC_ISINK_CH4_STEP, 3);	/* 16mA */
	pmic_set_register_value(PMIC_ISINK_DIM4_DUTY, 15);
	pmic_set_register_value(PMIC_ISINK_DIM4_FSEL, 0);	/* 1KHz */

	//isink3
	pmic_set_register_value(PMIC_RG_DRV_32K_CK_PDN, 0x0);	/* Disable power down */
	pmic_set_register_value(PMIC_RG_DRV_ISINK5_CK_PDN, 0);
	pmic_set_register_value(PMIC_RG_DRV_ISINK5_CK_CKSEL, 0);
	pmic_set_register_value(PMIC_ISINK_CH5_MODE, 0);
	pmic_set_register_value(PMIC_ISINK_CH5_STEP, 3);	/* 16mA */
	pmic_set_register_value(PMIC_ISINK_DIM5_DUTY, 15);
	pmic_set_register_value(PMIC_ISINK_DIM5_FSEL, 0);	/* 1KHz */

	//enables
	//pmic_set_register_value(PMIC_ISINK_CH0_EN, 0);
	pmic_set_register_value(PMIC_ISINK_CH1_EN, 0);
	pmic_set_register_value(PMIC_ISINK_CH4_EN, 0);
	pmic_set_register_value(PMIC_ISINK_CH5_EN, 0);
#endif
}

static int SUB_FL_Init(void)
{
	isink_chanel_init();
	PK_DBG(" SUB_FL_Init line=%d\n",__LINE__);
	return 0;
}

static int SUB_FL_Uninit(void)
{
	SUB_FL_Disable();
	return 0;
}

static int SUB_FL_dim_duty(kal_uint32 duty)
{
	if(duty>17)
		duty=17;
	if(duty<0)
		duty=0;
	gDuty=duty;
	//set_isink(1 , gLedDuty[duty]);
	PK_DBG(" SUB_FL_dim_duty line=%d\n",__LINE__);
	return 0;
}

static void work_timeOutFunc(struct work_struct *data)
{
	SUB_FL_Disable();
	PK_DBG("ledTimeOut_callback\n");
}
static enum hrtimer_restart ledTimeOutCallback(struct hrtimer *timer)
{
	schedule_work(&workTimeOut);
	return HRTIMER_NORESTART;
}

static void timerInit(void)
{
	INIT_WORK(&workTimeOut, work_timeOutFunc);
	g_timeOutTimeMs=1000; //1s
	hrtimer_init( &g_timeOutTimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL );
	g_timeOutTimer.function=ledTimeOutCallback;
}



static int sub_strobe_ioctl(unsigned int cmd, unsigned long arg)
{
	int i4RetValue = 0;
	int ior_shift;
	int iow_shift;
	int iowr_shift;
	PK_DBG("sub flashlight ioctl\n");
	ior_shift = cmd - (_IOR(FLASHLIGHT_MAGIC,0, int));
	iow_shift = cmd - (_IOW(FLASHLIGHT_MAGIC,0, int));
	iowr_shift = cmd - (_IOWR(FLASHLIGHT_MAGIC,0, int));
	PK_DBG("sub_flashlight_ioctl() line=%d ior_shift=%d, iow_shift=%d iowr_shift=%d arg=%d\n",__LINE__, ior_shift, iow_shift, iowr_shift, (int)arg);
	switch(cmd)
	{

		case FLASH_IOC_SET_TIME_OUT_TIME_MS:
			PK_DBG("SUB_FLASH_IOC_SET_TIME_OUT_TIME_MS: %d\n",(int)arg);
			g_timeOutTimeMs=arg;
		break;


		case FLASH_IOC_SET_DUTY :
			PK_DBG("SUB_FLASHLIGHT_DUTY: %d\n",(int)arg);
			SUB_FL_dim_duty(arg);
			break;


		case FLASH_IOC_SET_STEP:
			PK_DBG("SUB_FLASH_IOC_SET_STEP: %d\n",(int)arg);
			break;

		case FLASH_IOC_SET_ONOFF :
			PK_DBG("SUB_FLASHLIGHT_ONOFF: %d\n",(int)arg);
			if(arg==1)
			{
		     	if(g_timeOutTimeMs!=0)
				{
					ktime_t ktime;
					ktime = ktime_set( 0, g_timeOutTimeMs*1000000 );
					hrtimer_start( &g_timeOutTimer, ktime, HRTIMER_MODE_REL );
				}
				SUB_FL_Enable();
			}
			else
			{
				SUB_FL_Disable();
				hrtimer_cancel( &g_timeOutTimer );
			}
			break;
		default :
			PK_DBG(" SUB_No such command \n");
			i4RetValue = -EPERM;
			break;
	}
	return i4RetValue;
}

static int sub_strobe_open(void *pArg)
{
	int i4RetValue = 0;
	PK_DBG("sub falshlight open\n");

	if (0 == strobe_Res)
	{
	  SUB_FL_Init();
	  timerInit();
	}
	PK_DBG("SUB_constant_flashlight_open line=%d\n", __LINE__);
	spin_lock_irq(&g_substrobeSMPLock);

	if(strobe_Res)
	{
		PK_DBG(" SUB_busy!\n");
		i4RetValue = -EBUSY;
	}
	else
	{
		strobe_Res += 1;
	}

	spin_unlock_irq(&g_substrobeSMPLock);
	PK_DBG("SUB_constant_flashlight_open line=%d\n", __LINE__);

	return i4RetValue;
}

static int sub_strobe_release(void *pArg)
{
	PK_DBG("sub flashlight release\n");
	if (strobe_Res)
	{
		spin_lock_irq(&g_substrobeSMPLock);

		strobe_Res = 0;
		strobe_Timeus = 0;

		/* LED On Status */

		spin_unlock_irq(&g_substrobeSMPLock);

		SUB_FL_Uninit();
}

	PK_DBG(" SUB_Done\n");
	return 0;

}

FLASHLIGHT_FUNCTION_STRUCT subStrobeFunc = {
	sub_strobe_open,
	sub_strobe_release,
	sub_strobe_ioctl
};


MUINT32 subStrobeInit(PFLASHLIGHT_FUNCTION_STRUCT *pfFunc)
{
	if (pfFunc != NULL)
		*pfFunc = &subStrobeFunc;
	return 0;
}
