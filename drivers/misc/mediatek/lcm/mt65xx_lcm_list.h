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

#ifndef __MT65XX_LCM_LIST_H__
#define __MT65XX_LCM_LIST_H__

#include <lcm_drv.h>

extern LCM_DRIVER FL11281_lcm_drv;
extern LCM_DRIVER NT35521_SHM047160B_lcm_drv;
extern LCM_DRIVER SHM047160A_lcm_drv;
extern LCM_DRIVER ILI988IC_S047HAB003_A00_lcm_drv;
extern LCM_DRIVER ILI9881_HSD47_lcm_drv;
extern LCM_DRIVER ILI988IC_J0CPB_AB30_BOE_lcm_drv;
#ifdef BUILD_LK
extern void mdelay(unsigned long msec);
#endif

#endif
