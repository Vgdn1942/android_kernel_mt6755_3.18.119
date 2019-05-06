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

#include "mt65xx_lcm_list.h"
#include <lcm_drv.h>
#ifdef BUILD_LK
#include <platform/disp_drv_platform.h>
#else
#include <linux/delay.h>
/* #include <mach/mt_gpio.h> */
#endif
LCM_DSI_MODE_CON lcm_dsi_mode;

/* used to identify float ID PIN status */
#define LCD_HW_ID_STATUS_LOW      0
#define LCD_HW_ID_STATUS_HIGH     1
#define LCD_HW_ID_STATUS_FLOAT 0x02
#define LCD_HW_ID_STATUS_ERROR  0x03

#ifdef BUILD_LK
#define LCD_DEBUG(fmt)  dprintf(CRITICAL, fmt)
#else
#define LCD_DEBUG(fmt, args...)  pr_debug("[KERNEL/LCM]"fmt, ##args)
#endif

/*************************/
//static LCM_UTIL_FUNCS lcm_util;
//#define set_gpio_lcd_enp(cmd) lcm_util.set_gpio_lcd_enp_bias(cmd)
#define LCM_POWER_PIN 11
#ifndef BUILD_LK
#include <linux/gpio.h>
#endif
int lcm_power_on(void)
{
	#ifdef BUILD_LK
	mt_set_gpio_mode(GPIO_LCD_BIAS_ENP_PIN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCD_BIAS_ENP_PIN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCD_BIAS_ENP_PIN, GPIO_OUT_ONE);
	#else
	//set_gpio_lcd_enp(1);
	gpio_set_value(LCM_POWER_PIN, 1);
	#endif
	return 0;
}
int lcm_power_down(void)
{
	#ifdef BUILD_LK
	mt_set_gpio_mode(GPIO_LCD_BIAS_ENP_PIN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCD_BIAS_ENP_PIN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCD_BIAS_ENP_PIN, GPIO_OUT_ZERO);
	#else
	//set_gpio_lcd_enp(0);
	gpio_set_value(LCM_POWER_PIN, 0);
	#endif
	return 0;
}
/*************************/

LCM_DRIVER *lcm_driver_list[] = {
#if defined(FL11281)
	&FL11281_lcm_drv,
#endif
#if defined(NT35521_SHM047160B)
	&NT35521_SHM047160B_lcm_drv,
#endif
#if defined(SHM047160A)
	&SHM047160A_lcm_drv,
#endif
#if defined(ILI988IC_S047HAB003_A00)
	&ILI988IC_S047HAB003_A00_lcm_drv,
#endif
#if defined(ILI9881_HSD47)
	&ILI9881_HSD47_lcm_drv,
#endif
#if defined(ILI988IC_J0CPB_AB30_BOE)
	&ILI988IC_J0CPB_AB30_BOE_lcm_drv,
#endif
};

unsigned char lcm_name_list[][128] = {
#if defined(FL11281)
	"FL11281",
#endif
#if defined(NT35521_SHM047160B)
	"NT35521_SHM047160B",
#endif
#if defined(SHM047160A)
	"SHM047160A",
#endif
#if defined(ILI988IC_S047HAB003_A00)
	"ILI988IC_S047HAB003_A00",
#endif
#if defined(ILI9881_HSD47)
	"ILI9881_HSD47",
#endif
#if defined(ILI988IC_J0CPB_AB30_BOE)
	"ILI988IC_J0CPB_AB30_BOE",
#endif
};

#define LCM_COMPILE_ASSERT(condition) LCM_COMPILE_ASSERT_X(condition, __LINE__)
#define LCM_COMPILE_ASSERT_X(condition, line) LCM_COMPILE_ASSERT_XX(condition, line)
#define LCM_COMPILE_ASSERT_XX(condition, line) char assertion_failed_at_line_##line[(condition) ? 1 : -1]

unsigned int lcm_count = sizeof(lcm_driver_list) / sizeof(LCM_DRIVER *);
LCM_COMPILE_ASSERT(0 != sizeof(lcm_driver_list) / sizeof(LCM_DRIVER *));

