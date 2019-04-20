/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#define LOG_TAG "LCM"

#ifndef BUILD_LK
#include <linux/string.h>
#include <linux/kernel.h>
#endif

#include "lcm_drv.h"

#ifdef BUILD_LK
#include <platform/upmu_common.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
#include <linux/gpio.h>
#include <mt-plat/mt_gpio.h>
#endif

#if defined(BUILD_LK)
	#define LCM_DEBUG  printf
	#define LCM_FUNC_TRACE() printf("huyl [uboot] %s\n",__func__)
#else
	#define LCM_DEBUG  printk
	#define LCM_FUNC_TRACE() printk("huyl [kernel] %s\n",__func__)
#endif
// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  (1080)
#define FRAME_HEIGHT (1920)

#define LCM_ID_NT35590 (0x90)

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif


// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

#define REGFLAG_DELAY             							0XFE
#define REGFLAG_END_OF_TABLE      							0x100   // END OF REGISTERS MARKER

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	        lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)   

#define   LCM_DSI_CMD_MODE							0

extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};



static struct LCM_setting_table lcm_initialization_setting[] = {

{0xff, 1, {0xee}},
{0xfb, 1, {0x01}},
{0x18, 1, {0x40}},
{REGFLAG_DELAY, 10, {}},
{0x18, 1, {0x00}},

{0xff, 1, {0x05}},
{0xfb, 1, {0x01}},
{0xc5, 1, {0x01}},
{REGFLAG_DELAY, 20, {}},
{0xff, 1, {0xee}},
{0xfb, 1, {0x01}},
{0x1f, 1, {0x45}},
{0x24, 1, {0x4f}},
{0x38, 1, {0xc8}},
{0x39, 1, {0x2c}},
{0x1e, 1, {0xbb}},
{0x1d, 1, {0x0f}},
{0x7e, 1, {0xb1}},
{0xff, 1, {0x00}},
{0xfb, 1, {0x01}},
{0x35, 1, {0x01}},
{0xff, 1, {0x01}},
{0xfb, 1, {0x01}},
{0x00, 1, {0x01}},
{0x01, 1, {0x55}},
{0x02, 1, {0x40}},
{0x05, 1, {0x40}},
{0x06, 1, {0x4a}},
{0x07, 1, {0x24}},
{0x08, 1, {0x0c}},
{0x0b, 1, {0x87}},
{0x0c, 1, {0x87}},
{0x0e, 1, {0xb0}},
{0x0f, 1, {0xb3}},
{0x11, 1, {0x10}},
{0x12, 1, {0x10}},
{0x13, 1, {0x05}},
{0x14, 1, {0x4a}},
{0x15, 1, {0x18}},
{0x16, 1, {0x18}},
{0x18, 1, {0x00}},
{0x19, 1, {0x77}},
{0x1a, 1, {0x55}},
{0x1b, 1, {0x13}},
{0x1c, 1, {0x00}},
{0x1d, 1, {0x00}},
{0x1e, 1, {0x13}},
{0x1f, 1, {0x00}},
{0x23, 1, {0x00}},
{0x24, 1, {0x00}},
{0x25, 1, {0x00}},
{0x26, 1, {0x00}},
{0x27, 1, {0x00}},
{0x28, 1, {0x00}},
{0x35, 1, {0x00}},
{0x66, 1, {0x00}},
{0x58, 1, {0x82}},
{0x59, 1, {0x02}},
{0x5a, 1, {0x02}},
{0x5b, 1, {0x02}},
{0x5c, 1, {0x82}},
{0x5d, 1, {0x82}},
{0x5e, 1, {0x02}},
{0x5f, 1, {0x02}},
{0x72, 1, {0x31}},
{0xff, 1, {0x05}},
{0xfb, 1, {0x01}},
{0x00, 1, {0x01}},
{0x01, 1, {0x0b}},
{0x02, 1, {0x0c}},
{0x03, 1, {0x09}},
{0x04, 1, {0x0a}},
{0x05, 1, {0x00}},
{0x06, 1, {0x0f}},
{0x07, 1, {0x10}},
{0x08, 1, {0x00}},
{0x09, 1, {0x00}},
{0x0a, 1, {0x00}},
{0x0b, 1, {0x00}},
{0x0c, 1, {0x00}},
{0x0d, 1, {0x13}},
{0x0e, 1, {0x15}},
{0x0f, 1, {0x17}},
{0x10, 1, {0x01}},
{0x11, 1, {0x0b}},
{0x12, 1, {0x0c}},
{0x13, 1, {0x09}},
{0x14, 1, {0x0a}},
{0x15, 1, {0x00}},
{0x16, 1, {0x0f}},
{0x17, 1, {0x10}},
{0x18, 1, {0x00}},
{0x19, 1, {0x00}},
{0x1a, 1, {0x00}},
{0x1b, 1, {0x00}},
{0x1c, 1, {0x00}},
{0x1d, 1, {0x13}},
{0x1e, 1, {0x15}},
{0x1f, 1, {0x17}},
{0x20, 1, {0x00}},
{0x21, 1, {0x03}},
{0x22, 1, {0x01}},
{0x23, 1, {0x40}},
{0x24, 1, {0x40}},
{0x25, 1, {0xed}},
{0x29, 1, {0x58}},
{0x2a, 1, {0x12}},
{0x2b, 1, {0x01}},
{0x4b, 1, {0x06}},
{0x4c, 1, {0x11}},
{0x4d, 1, {0x20}},
{0x4e, 1, {0x02}},
{0x4f, 1, {0x02}},
{0x50, 1, {0x20}},
{0x51, 1, {0x61}},
{0x52, 1, {0x01}},
{0x53, 1, {0x63}},
{0x54, 1, {0x77}},
{0x55, 1, {0xed}},
{0x5b, 1, {0x00}},
{0x5c, 1, {0x00}},
{0x5d, 1, {0x00}},
{0x5e, 1, {0x00}},
{0x5f, 1, {0x15}},
{0x60, 1, {0x75}},
{0x61, 1, {0x00}},
{0x62, 1, {0x00}},
{0x63, 1, {0x00}},
{0x64, 1, {0x00}},
{0x65, 1, {0x00}},
{0x66, 1, {0x00}},
{0x67, 1, {0x00}},
{0x68, 1, {0x04}},
{0x69, 1, {0x00}},
{0x6a, 1, {0x00}},
{0x6c, 1, {0x40}},
{0x75, 1, {0x01}},
{0x76, 1, {0x01}},
{0x7a, 1, {0x80}},
{0x7b, 1, {0xc5}},
{0x7c, 1, {0xd8}},
{0x7d, 1, {0x60}},
{0x7f, 1, {0x15}},
{0x80, 1, {0x81}},
{0x83, 1, {0x05}},
{0x93, 1, {0x08}},
{0x94, 1, {0x10}},
{0x8a, 1, {0x00}},
{0x9b, 1, {0x0f}},
{0xea, 1, {0xff}},
{0xec, 1, {0x00}},
{0xff, 1, {0x01}},
{0xfb, 1, {0x01}},
{0x75, 1, {0x00}},
{0x76, 1, {0x18}},
{0x77, 1, {0x00}},
{0x78, 1, {0x38}},
{0x79, 1, {0x00}},
{0x7a, 1, {0x65}},
{0x7b, 1, {0x00}},
{0x7c, 1, {0x84}},
{0x7d, 1, {0x00}},
{0x7e, 1, {0x9b}},
{0x7f, 1, {0x00}},
{0x80, 1, {0xaf}},
{0x81, 1, {0x00}},
{0x82, 1, {0xc1}},
{0x83, 1, {0x00}},
{0x84, 1, {0xd2}},
{0x85, 1, {0x00}},
{0x86, 1, {0xdf}},
{0x87, 1, {0x01}},
{0x88, 1, {0x11}},
{0x89, 1, {0x01}},
{0x8a, 1, {0x38}},
{0x8b, 1, {0x01}},
{0x8c, 1, {0x76}},
{0x8d, 1, {0x01}},
{0x8e, 1, {0xa7}},
{0x8f, 1, {0x01}},
{0x90, 1, {0xf3}},
{0x91, 1, {0x02}},
{0x92, 1, {0x2f}},
{0x93, 1, {0x02}},
{0x94, 1, {0x30}},
{0x95, 1, {0x02}},
{0x96, 1, {0x66}},
{0x97, 1, {0x02}},
{0x98, 1, {0xa0}},
{0x99, 1, {0x02}},
{0x9a, 1, {0xc5}},
{0x9b, 1, {0x02}},
{0x9c, 1, {0xf8}},
{0x9d, 1, {0x03}},
{0x9e, 1, {0x1b}},
{0x9f, 1, {0x03}},
{0xa0, 1, {0x46}},
{0xa2, 1, {0x03}},
{0xa3, 1, {0x52}},
{0xa4, 1, {0x03}},
{0xa5, 1, {0x62}},
{0xa6, 1, {0x03}},
{0xa7, 1, {0x71}},
{0xa9, 1, {0x03}},
{0xaa, 1, {0x83}},
{0xab, 1, {0x03}},
{0xac, 1, {0x94}},
{0xad, 1, {0x03}},
{0xae, 1, {0xa3}},
{0xaf, 1, {0x03}},
{0xb0, 1, {0xad}},
{0xb1, 1, {0x03}},
{0xb2, 1, {0xcc}},
{0xb3, 1, {0x00}},
{0xb4, 1, {0x18}},
{0xb5, 1, {0x00}},
{0xb6, 1, {0x38}},
{0xb7, 1, {0x00}},
{0xb8, 1, {0x65}},
{0xb9, 1, {0x00}},
{0xba, 1, {0x84}},
{0xbb, 1, {0x00}},
{0xbc, 1, {0x9b}},
{0xbd, 1, {0x00}},
{0xbe, 1, {0xaf}},
{0xbf, 1, {0x00}},
{0xc0, 1, {0xc1}},
{0xc1, 1, {0x00}},
{0xc2, 1, {0xd2}},
{0xc3, 1, {0x00}},
{0xc4, 1, {0xdf}},
{0xc5, 1, {0x01}},
{0xc6, 1, {0x11}},
{0xc7, 1, {0x01}},
{0xc8, 1, {0x38}},
{0xc9, 1, {0x01}},
{0xca, 1, {0x76}},
{0xcb, 1, {0x01}},
{0xcc, 1, {0xa7}},
{0xcd, 1, {0x01}},
{0xce, 1, {0xf3}},
{0xcf, 1, {0x02}},
{0xd0, 1, {0x2f}},
{0xd1, 1, {0x02}},
{0xd2, 1, {0x30}},
{0xd3, 1, {0x02}},
{0xd4, 1, {0x66}},
{0xd5, 1, {0x02}},
{0xd6, 1, {0xa0}},
{0xd7, 1, {0x02}},
{0xd8, 1, {0xc5}},
{0xd9, 1, {0x02}},
{0xda, 1, {0xf8}},
{0xdb, 1, {0x03}},
{0xdc, 1, {0x1b}},
{0xdd, 1, {0x03}},
{0xde, 1, {0x46}},
{0xdf, 1, {0x03}},
{0xe0, 1, {0x52}},
{0xe1, 1, {0x03}},
{0xe2, 1, {0x62}},
{0xe3, 1, {0x03}},
{0xe4, 1, {0x71}},
{0xe5, 1, {0x03}},
{0xe6, 1, {0x83}},
{0xe7, 1, {0x03}},
{0xe8, 1, {0x94}},
{0xe9, 1, {0x03}},
{0xea, 1, {0xa3}},
{0xeb, 1, {0x03}},
{0xec, 1, {0xad}},
{0xed, 1, {0x03}},
{0xee, 1, {0xcc}},
{0xef, 1, {0x00}},
{0xf0, 1, {0x18}},
{0xf1, 1, {0x00}},
{0xf2, 1, {0x38}},
{0xf3, 1, {0x00}},
{0xf4, 1, {0x65}},
{0xf5, 1, {0x00}},
{0xf6, 1, {0x84}},
{0xf7, 1, {0x00}},
{0xf8, 1, {0x9b}},
{0xf9, 1, {0x00}},
{0xfa, 1, {0xaf}},
{0xff, 1, {0x02}},
{0xfb, 1, {0x01}},
{0x00, 1, {0x00}},
{0x01, 1, {0xc1}},
{0x02, 1, {0x00}},
{0x03, 1, {0xd2}},
{0x04, 1, {0x00}},
{0x05, 1, {0xdf}},
{0x06, 1, {0x01}},
{0x07, 1, {0x11}},
{0x08, 1, {0x01}},
{0x09, 1, {0x38}},
{0x0a, 1, {0x01}},
{0x0b, 1, {0x76}},
{0x0c, 1, {0x01}},
{0x0d, 1, {0xa7}},
{0x0e, 1, {0x01}},
{0x0f, 1, {0xf3}},
{0x10, 1, {0x02}},
{0x11, 1, {0x2f}},
{0x12, 1, {0x02}},
{0x13, 1, {0x30}},
{0x14, 1, {0x02}},
{0x15, 1, {0x66}},
{0x16, 1, {0x02}},
{0x17, 1, {0xa0}},
{0x18, 1, {0x02}},
{0x19, 1, {0xc5}},
{0x1a, 1, {0x02}},
{0x1b, 1, {0xf8}},
{0x1c, 1, {0x03}},
{0x1d, 1, {0x1b}},
{0x1e, 1, {0x03}},
{0x1f, 1, {0x46}},
{0x20, 1, {0x03}},
{0x21, 1, {0x52}},
{0x22, 1, {0x03}},
{0x23, 1, {0x62}},
{0x24, 1, {0x03}},
{0x25, 1, {0x71}},
{0x26, 1, {0x03}},
{0x27, 1, {0x83}},
{0x28, 1, {0x03}},
{0x29, 1, {0x94}},
{0x2a, 1, {0x03}},
{0x2b, 1, {0xa3}},
{0x2d, 1, {0x03}},
{0x2f, 1, {0xad}},
{0x30, 1, {0x03}},
{0x31, 1, {0xcc}},
{0x32, 1, {0x00}},
{0x33, 1, {0x18}},
{0x34, 1, {0x00}},
{0x35, 1, {0x38}},
{0x36, 1, {0x00}},
{0x37, 1, {0x65}},
{0x38, 1, {0x00}},
{0x39, 1, {0x84}},
{0x3a, 1, {0x00}},
{0x3b, 1, {0x9b}},
{0x3d, 1, {0x00}},
{0x3f, 1, {0xaf}},
{0x40, 1, {0x00}},
{0x41, 1, {0xc1}},
{0x42, 1, {0x00}},
{0x43, 1, {0xd2}},
{0x44, 1, {0x00}},
{0x45, 1, {0xdf}},
{0x46, 1, {0x01}},
{0x47, 1, {0x11}},
{0x48, 1, {0x01}},
{0x49, 1, {0x38}},
{0x4a, 1, {0x01}},
{0x4b, 1, {0x76}},
{0x4c, 1, {0x01}},
{0x4d, 1, {0xa7}},
{0x4e, 1, {0x01}},
{0x4f, 1, {0xf3}},
{0x50, 1, {0x02}},
{0x51, 1, {0x2f}},
{0x52, 1, {0x02}},
{0x53, 1, {0x30}},
{0x54, 1, {0x02}},
{0x55, 1, {0x66}},
{0x56, 1, {0x02}},
{0x58, 1, {0xa0}},
{0x59, 1, {0x02}},
{0x5a, 1, {0xc5}},
{0x5b, 1, {0x02}},
{0x5c, 1, {0xf8}},
{0x5d, 1, {0x03}},
{0x5e, 1, {0x1b}},
{0x5f, 1, {0x03}},
{0x60, 1, {0x46}},
{0x61, 1, {0x03}},
{0x62, 1, {0x52}},
{0x63, 1, {0x03}},
{0x64, 1, {0x62}},
{0x65, 1, {0x03}},
{0x66, 1, {0x71}},
{0x67, 1, {0x03}},
{0x68, 1, {0x83}},
{0x69, 1, {0x03}},
{0x6a, 1, {0x94}},
{0x6b, 1, {0x03}},
{0x6c, 1, {0xa3}},
{0x6d, 1, {0x03}},
{0x6e, 1, {0xad}},
{0x6f, 1, {0x03}},
{0x70, 1, {0xcc}},
{0x71, 1, {0x00}},
{0x72, 1, {0x18}},
{0x73, 1, {0x00}},
{0x74, 1, {0x38}},
{0x75, 1, {0x00}},
{0x76, 1, {0x65}},
{0x77, 1, {0x00}},
{0x78, 1, {0x84}},
{0x79, 1, {0x00}},
{0x7a, 1, {0x9b}},
{0x7b, 1, {0x00}},
{0x7c, 1, {0xaf}},
{0x7d, 1, {0x00}},
{0x7e, 1, {0xc1}},
{0x7f, 1, {0x00}},
{0x80, 1, {0xd2}},
{0x81, 1, {0x00}},
{0x82, 1, {0xdf}},
{0x83, 1, {0x01}},
{0x84, 1, {0x11}},
{0x85, 1, {0x01}},
{0x86, 1, {0x38}},
{0x87, 1, {0x01}},
{0x88, 1, {0x76}},
{0x89, 1, {0x01}},
{0x8a, 1, {0xa7}},
{0x8b, 1, {0x01}},
{0x8c, 1, {0xf3}},
{0x8d, 1, {0x02}},
{0x8e, 1, {0x2f}},
{0x8f, 1, {0x02}},
{0x90, 1, {0x30}},
{0x91, 1, {0x02}},
{0x92, 1, {0x66}},
{0x93, 1, {0x02}},
{0x94, 1, {0xa0}},
{0x95, 1, {0x02}},
{0x96, 1, {0xc5}},
{0x97, 1, {0x02}},
{0x98, 1, {0xf8}},
{0x99, 1, {0x03}},
{0x9a, 1, {0x1b}},
{0x9b, 1, {0x03}},
{0x9c, 1, {0x46}},
{0x9d, 1, {0x03}},
{0x9e, 1, {0x52}},
{0x9f, 1, {0x03}},
{0xa0, 1, {0x62}},
{0xa2, 1, {0x03}},
{0xa3, 1, {0x71}},
{0xa4, 1, {0x03}},
{0xa5, 1, {0x83}},
{0xa6, 1, {0x03}},
{0xa7, 1, {0x94}},
{0xa9, 1, {0x03}},
{0xaa, 1, {0xa3}},
{0xab, 1, {0x03}},
{0xac, 1, {0xad}},
{0xad, 1, {0x03}},
{0xae, 1, {0xcc}},
{0xaf, 1, {0x00}},
{0xb0, 1, {0x18}},
{0xb1, 1, {0x00}},
{0xb2, 1, {0x38}},
{0xb3, 1, {0x00}},
{0xb4, 1, {0x65}},
{0xb5, 1, {0x00}},
{0xb6, 1, {0x84}},
{0xb7, 1, {0x00}},
{0xb8, 1, {0x9b}},
{0xb9, 1, {0x00}},
{0xba, 1, {0xaf}},
{0xbb, 1, {0x00}},
{0xbc, 1, {0xc1}},
{0xbd, 1, {0x00}},
{0xbe, 1, {0xd2}},
{0xbf, 1, {0x00}},
{0xc0, 1, {0xdf}},
{0xc1, 1, {0x01}},
{0xc2, 1, {0x11}},
{0xc3, 1, {0x01}},
{0xc4, 1, {0x38}},
{0xc5, 1, {0x01}},
{0xc6, 1, {0x76}},
{0xc7, 1, {0x01}},
{0xc8, 1, {0xa7}},
{0xc9, 1, {0x01}},
{0xca, 1, {0xf3}},
{0xcb, 1, {0x02}},
{0xcc, 1, {0x2f}},
{0xcd, 1, {0x02}},
{0xce, 1, {0x30}},
{0xcf, 1, {0x02}},
{0xd0, 1, {0x66}},
{0xd1, 1, {0x02}},
{0xd2, 1, {0xa0}},
{0xd3, 1, {0x02}},
{0xd4, 1, {0xc5}},
{0xd6, 1, {0xf8}},
{0xd7, 1, {0x03}},
{0xd8, 1, {0x1b}},
{0xd9, 1, {0x03}},
{0xda, 1, {0x46}},
{0xdb, 1, {0x03}},
{0xdc, 1, {0x52}},
{0xdd, 1, {0x03}},
{0xde, 1, {0x62}},
{0xdf, 1, {0x03}},
{0xe0, 1, {0x71}},
{0xe1, 1, {0x03}},
{0xe2, 1, {0x83}},
{0xe3, 1, {0x03}},
{0xe4, 1, {0x94}},
{0xe5, 1, {0x03}},
{0xe6, 1, {0xa3}},
{0xe7, 1, {0x03}},
{0xe8, 1, {0xad}},
{0xe9, 1, {0x03}},
{0xea, 1, {0xcc}},
{0xff, 1, {0x01}},
{0xfb, 1, {0x01}},
{0xff, 1, {0x02}},
{0xfb, 1, {0x01}},
{0xff, 1, {0x04}},
{0xfb, 1, {0x01}},
{0xff, 1, {0x00}},
{0xd3, 1, {0x05}},
{0xd4, 1, {0x04}},
{0xbc, 2, {0x01, 0x00}},
{0xbf, 1, {0x11}},

/*{REGFLAG_DELAY, 10, {}},

{0x11, 1, {0x00}},
{REGFLAG_DELAY, 120, {}},

{0x29, 1, {0x00}},
{REGFLAG_DELAY, 20, {}},

{REGFLAG_END_OF_TABLE, 0x00, {}}
*/


{0x11, 0, {0x00}},

{REGFLAG_DELAY, 120, {}},

{0x29, 0, {0x00}},

{REGFLAG_END_OF_TABLE, 0x00, {}}	


};


static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
/*
	// Display off sequence
	{0x28, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},

    // Sleep Mode On
	{0x10, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
*/
    {0xFF,1,{0x01}}, 
    {0xB1,1,{0x03}}, 
    {0xB2,1,{0xFF}}, 
    {0xED,1,{0x03}}, 
    {0xEE,1,{0xFF}}, 
    {0xFF,1,{0x02}}, 
    {0xFB,1,{0x01}}, 
    {0x30,1,{0x03}}, 
    {0x31,1,{0xFF}}, 
    {0x6F,1,{0x03}}, 
    {0x70,1,{0xFF}}, 
    {0xAD,1,{0x03}}, 
    {0xAE,1,{0xFF}}, 
    {0xE9,1,{0x03}}, 
    {0xEA,1,{0xFF}}, 
    {0xFF,1,{0x00}}, 

    {0x28, 0, {0x00}},
	//{REGFLAG_DELAY, 120, {}},
    {0xFF,1,{0x01}}, 
    {0x11,1,{0x72}}, 
    {0xFF,1,{0x00}}, 
    
    // Sleep Mode On
	// {0x10, 0, {0x00}},
	// {REGFLAG_DELAY, 120, {}},
    {REGFLAG_END_OF_TABLE, 0x00, {}}
};


static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

    for(i = 0; i < count; i++) {
		
        unsigned cmd;
        cmd = table[i].cmd;
		
        switch (cmd) {
			
            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;
				
            case REGFLAG_END_OF_TABLE :
                break;
				
            default:
				dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
				//MDELAY(2);
       	}
    }
	
}




// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{

		memset(params, 0, sizeof(LCM_PARAMS));
	
		params->type   = LCM_TYPE_DSI;

		params->width  = FRAME_WIDTH;
		params->height = FRAME_HEIGHT;

		// enable tearing-free
		params->dbi.te_mode 				= LCM_DBI_TE_MODE_DISABLED;
		//params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;

        #if (LCM_DSI_CMD_MODE)
		params->dsi.mode   = CMD_MODE;
        #else
		params->dsi.mode   = SYNC_PULSE_VDO_MODE; //SYNC_PULSE_VDO_MODE;//BURST_VDO_MODE; 
        #endif
	
		// DSI
		/* Command mode setting */
		//1 Three lane or Four lane
		params->dsi.LANE_NUM				= LCM_FOUR_LANE;
		//The following defined the fomat for data coming from LCD engine.
		params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
		params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
		params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
		params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

		// Highly depends on LCD driver capability.
		// Not support in MT6573
		params->dsi.packet_size=256;

		// Video mode setting		
		params->dsi.intermediat_buffer_num = 0;//because DSI/DPI HW design change, this parameters should be 0 when video mode in MT658X; or memory leakage

		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
		params->dsi.word_count=FRAME_WIDTH*3;	

		
		params->dsi.vertical_sync_active				= 0x3;// 3    2
		params->dsi.vertical_backporch					= 0x1;// 20   1
		params->dsi.vertical_frontporch					= 0x20;//0x1; // 1  12
		params->dsi.vertical_active_line				= FRAME_HEIGHT;

#if 0
        // Bakup
		params->dsi.horizontal_sync_active				= 0x0B;// 50  2
		params->dsi.horizontal_backporch				= 0x10;
		params->dsi.horizontal_frontporch				= 0x10;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;
#else
        // Val get from MTK, #5294!!!
		params->dsi.horizontal_sync_active				= 0x05;// 50  2
		params->dsi.horizontal_backporch				= 0x30;//3c
		params->dsi.horizontal_frontporch				= 0x50;//5e
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;
#endif

	    //params->dsi.LPX=8; 

		// Bit rate calculation
		//1 Every lane speed
		//params->dsi.pll_select=1;
		//params->dsi.compatibility_for_nvk = 1;		// this parameter would be set to 1 if DriverIC is NTK's and when force match DSI clock for NTK's
		//params->dsi.pll_div1=0;		// div1=0,1,2,3;div1_real=1,2,4,4 ----0: 546Mbps  1:273Mbps
		//params->dsi.pll_div2=1;		// div2=0,1,2,3;div1_real=1,2,4,4	
		//params->dsi.fbk_div =31;    // fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)
		params->dsi.PLL_CLOCK = 220;		

}

static void lcm_init(void)
{
	agold_lcm_power_on();

/*		
	mt_set_gpio_mode(GPIO_LCM_PWR_EN, 0);
	mt_set_gpio_dir(GPIO_LCM_PWR_EN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCM_PWR_EN, GPIO_OUT_ONE);
*/	

	MDELAY(10);
	SET_RESET_PIN(1); // page 142
	MDELAY(5); 
	SET_RESET_PIN(0);
	MDELAY(5); 	// page 142
	SET_RESET_PIN(1);
	MDELAY(5); 
	SET_RESET_PIN(0);
	MDELAY(5); 	// page 142
	SET_RESET_PIN(1);
	MDELAY(30);  

	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend_shut_down(void)
{
	unsigned int data_array[8];

	data_array[0]= 0x00002200;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(10);
	
	data_array[0]= 0x00023902;
	data_array[1]= 0x00000028;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(10);
	
	data_array[0]= 0x00023902;
	data_array[1]= 0x00000010;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(120);
}

static void lcm_suspend(void)
{
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	lcm_suspend_shut_down();

	MDELAY(5);
	SET_RESET_PIN(1); // page 142
	MDELAY(10); 
	SET_RESET_PIN(0);
	MDELAY(1); 	// page 142
	//SET_RESET_PIN(1);
	MDELAY(120);  
/*
	mt_set_gpio_mode(GPIO_LCM_PWR_EN, 0);
	mt_set_gpio_dir(GPIO_LCM_PWR_EN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCM_PWR_EN, GPIO_OUT_ZERO); 
*/	
	agold_lcm_power_down();
}

static void lcm_resume(void)
{
	lcm_init(); 
}
         
#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);
	
	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x00290508; //HW bug, so need send one HS packet
	dsi_set_cmdq(data_array, 1, 1);
	
	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);

}
#endif


LCM_DRIVER S99198_lcm_drv = 
{
    .name			= "S99198",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	//.compare_id     = lcm_compare_id,
	//.esd_check = lcm_esd_check,
	//.esd_recover = lcm_esd_recover,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
    };
