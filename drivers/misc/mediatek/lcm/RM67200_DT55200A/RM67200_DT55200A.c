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

extern int lcm_i2c_set_vol_value(int vop_value, int von_value);
extern int lcm_i2c_bias_en(int enable);

#if defined(BUILD_LK)
	#define LCM_DEBUG  printf
	#define LCM_FUNC_TRACE() printf(" [uboot] %s\n",__func__)
#else
	#define LCM_DEBUG  printk
	#define LCM_FUNC_TRACE() printk(" [kernel] %s\n",__func__)
#endif
// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------


#define FRAME_WIDTH  (1080)
#define FRAME_HEIGHT (1920)


#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif

//static unsigned int lcm_esd_test = FALSE;      ///only for ESD test

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

#define REGFLAG_DELAY             							0XFFFE
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

#define RM67200_IDENT (0x0072)

struct LCM_setting_table {
    unsigned short cmd;
    unsigned char count;
    unsigned char para_list[128];
};



static struct LCM_setting_table lcm_initialization_setting[] = {
	
{0xFE, 1, {0x21}},
{0x04, 1, {0x00}},
{0x00, 1, {0x64}},
{0x2A, 1, {0x00}},
{0x26, 1, {0x64}},
{0x54, 1, {0x00}},
{0x50, 1, {0x64}},
{0x7B, 1, {0x00}},
{0x77, 1, {0x64}},
{0xA2, 1, {0x00}},
{0x9D, 1, {0x64}},
{0xC9, 1, {0x00}},
{0xC5, 1, {0x64}},
{0x01, 1, {0x6F}},
{0x27, 1, {0x6F}},
{0x51, 1, {0x6F}},
{0x78, 1, {0x6F}},
{0x9E, 1, {0x6F}},
{0xC6, 1, {0x6F}},
{0x02, 1, {0x84}},
{0x28, 1, {0x84}},
{0x52, 1, {0x84}},
{0x79, 1, {0x84}},
{0x9F, 1, {0x84}},
{0xC7, 1, {0x84}},
{0x03, 1, {0x97}},
{0x29, 1, {0x97}},
{0x53, 1, {0x97}},
{0x7A, 1, {0x97}},
{0xA0, 1, {0x97}},
{0xC8, 1, {0x97}},
{0x09, 1, {0x00}},
{0x05, 1, {0xA7}},
{0x31, 1, {0x00}},
{0x2B, 1, {0xA7}},
{0x5A, 1, {0x00}},
{0x55, 1, {0xA7}},
{0x80, 1, {0x00}},
{0x7C, 1, {0xA7}},
{0xA7, 1, {0x00}},
{0xA3, 1, {0xA7}},
{0xCE, 1, {0x00}},
{0xCA, 1, {0xA7}},
{0x06, 1, {0xB6}},
{0x2D, 1, {0xB6}},
{0x56, 1, {0xB6}},
{0x7D, 1, {0xB6}},
{0xA4, 1, {0xB6}},
{0xCB, 1, {0xB6}},
{0x07, 1, {0xC4}},
{0x2F, 1, {0xC4}},
{0x58, 1, {0xC4}},
{0x7E, 1, {0xC4}},
{0xA5, 1, {0xC4}},
{0xCC, 1, {0xC4}},
{0x08, 1, {0xD1}},
{0x30, 1, {0xD1}},
{0x59, 1, {0xD1}},
{0x7F, 1, {0xD1}},
{0xA6, 1, {0xD1}},
{0xCD, 1, {0xD1}},
{0x0E, 1, {0x15}},
{0x0A, 1, {0xDD}},
{0x36, 1, {0x15}},
{0x32, 1, {0xDD}},
{0x5F, 1, {0x15}},
{0x5B, 1, {0xDD}},
{0x85, 1, {0x15}},
{0x81, 1, {0xDD}},
{0xAD, 1, {0x15}},
{0xA9, 1, {0xDD}},
{0xD3, 1, {0x15}},
{0xCF, 1, {0xDD}},
{0x0B, 1, {0x06}},
{0x33, 1, {0x06}},
{0x5C, 1, {0x06}},
{0x82, 1, {0x06}},
{0xAA, 1, {0x06}},
{0xD0, 1, {0x06}},
{0x0C, 1, {0x29}},
{0x34, 1, {0x29}},
{0x5D, 1, {0x29}},
{0x83, 1, {0x29}},
{0xAB, 1, {0x29}},
{0xD1, 1, {0x29}},
{0x0D, 1, {0x62}},
{0x35, 1, {0x62}},
{0x5E, 1, {0x62}},
{0x84, 1, {0x62}},
{0xAC, 1, {0x62}},
{0xD2, 1, {0x62}},
{0x13, 1, {0x5A}},
{0x0F, 1, {0x90}},
{0x3B, 1, {0x5A}},
{0x37, 1, {0x90}},
{0x64, 1, {0x5A}},
{0x60, 1, {0x90}},
{0x8A, 1, {0x5A}},
{0x86, 1, {0x90}},
{0xB2, 1, {0x5A}},
{0xAE, 1, {0x90}},
{0xD8, 1, {0x5A}},
{0xD4, 1, {0x90}},
{0x10, 1, {0xDA}},
{0x38, 1, {0xDA}},
{0x61, 1, {0xDA}},
{0x87, 1, {0xDA}},
{0xAF, 1, {0xDA}},
{0xD5, 1, {0xDA}},
{0x11, 1, {0x16}},
{0x39, 1, {0x16}},
{0x62, 1, {0x16}},
{0x88, 1, {0x16}},
{0xB0, 1, {0x16}},
{0xD6, 1, {0x16}},
{0x12, 1, {0x17}},
{0x3A, 1, {0x17}},
{0x63, 1, {0x17}},
{0x89, 1, {0x17}},
{0xB1, 1, {0x17}},
{0xD7, 1, {0x17}},
{0x18, 1, {0xAA}},
{0x14, 1, {0x4E}},
{0x42, 1, {0xAA}},
{0x3D, 1, {0x4E}},
{0x69, 1, {0xAA}},
{0x65, 1, {0x4E}},
{0x8F, 1, {0xAA}},
{0x8B, 1, {0x4E}},
{0xB7, 1, {0xAA}},
{0xB3, 1, {0x4E}},
{0xDD, 1, {0xAA}},
{0xD9, 1, {0x4E}},
{0x15, 1, {0x8A}},
{0x3F, 1, {0x8A}},
{0x66, 1, {0x8A}},
{0x8C, 1, {0x8A}},
{0xB4, 1, {0x8A}},
{0xDA, 1, {0x8A}},
{0x16, 1, {0xB1}},
{0x40, 1, {0xB1}},
{0x67, 1, {0xB1}},
{0x8D, 1, {0xB1}},
{0xB5, 1, {0xB1}},
{0xDB, 1, {0xB1}},
{0x17, 1, {0xE6}},
{0x41, 1, {0xE6}},
{0x68, 1, {0xE6}},
{0x8E, 1, {0xE6}},
{0xB6, 1, {0xE6}},
{0xDC, 1, {0xE6}},
{0x1D, 1, {0xFF}},
{0x19, 1, {0x09}},
{0x47, 1, {0xFF}},
{0x43, 1, {0x09}},
{0x6E, 1, {0xFF}},
{0x6A, 1, {0x09}},
{0x94, 1, {0xFF}},
{0x90, 1, {0x09}},
{0xBC, 1, {0xFF}},
{0xB8, 1, {0x09}},
{0xE2, 1, {0xFF}},
{0xDE, 1, {0x09}},
{0x1A, 1, {0x3A}},
{0x44, 1, {0x3A}},
{0x6B, 1, {0x3A}},
{0x91, 1, {0x3A}},
{0xB9, 1, {0x3A}},
{0xDF, 1, {0x3A}},
{0x1B, 1, {0x4A}},
{0x45, 1, {0x4A}},
{0x6C, 1, {0x4A}},
{0x92, 1, {0x4A}},
{0xBA, 1, {0x4A}},
{0xE0, 1, {0x4A}},
{0x1C, 1, {0x5B}},
{0x46, 1, {0x5B}},
{0x6D, 1, {0x5B}},
{0x93, 1, {0x5B}},
{0xBB, 1, {0x5B}},
{0xE1, 1, {0x5B}},
{0x22, 1, {0xFF}},
{0x1E, 1, {0x6E}},
{0x4C, 1, {0xFF}},
{0x48, 1, {0x6E}},
{0x73, 1, {0xFF}},
{0x6F, 1, {0x6E}},
{0x99, 1, {0xFF}},
{0x95, 1, {0x6E}},
{0xC1, 1, {0xFF}},
{0xBD, 1, {0x6E}},
{0xE7, 1, {0xFF}},
{0xE3, 1, {0x6E}},
{0x1F, 1, {0x85}},
{0x49, 1, {0x85}},
{0x70, 1, {0x85}},
{0x96, 1, {0x85}},
{0xBE, 1, {0x85}},
{0xE4, 1, {0x85}},
{0x20, 1, {0xA0}},
{0x4A, 1, {0xA0}},
{0x71, 1, {0xA0}},
{0x97, 1, {0xA0}},
{0xBF, 1, {0xA0}},
{0xE5, 1, {0xA0}},
{0x21, 1, {0xC1}},
{0x4B, 1, {0xC1}},
{0x72, 1, {0xC1}},
{0x98, 1, {0xC1}},
{0xC0, 1, {0xC1}},
{0xE6, 1, {0xC1}},
{0x25, 1, {0xF0}},
{0x23, 1, {0xEA}},
{0x4F, 1, {0xF0}},
{0x4D, 1, {0xEA}},
{0x76, 1, {0xF0}},
{0x74, 1, {0xEA}},
{0x9C, 1, {0xF0}},
{0x9A, 1, {0xEA}},
{0xC4, 1, {0xF0}},
{0xC2, 1, {0xEA}},
{0xEA, 1, {0xF0}},
{0xE8, 1, {0xEA}},
{0x24, 1, {0xFF}},
{0x4E, 1, {0xFF}},
{0x75, 1, {0xFF}},
{0x9B, 1, {0xFF}},
{0xC3, 1, {0xFF}},
{0xE9, 1, {0xFF}},
{0xFE, 1, {0x3D}},
{0x00, 1, {0x05}},
{0xFE, 1, {0x23}},
{0x08, 1, {0xC1}},
{0x0A, 1, {0x60}},
{0x0B, 1, {0x00}},
{0x0C, 1, {0x01}},
{0x0D, 1, {0x80}},
{0x0E, 1, {0x81}},
{0x10, 1, {0x00}},
{0x11, 1, {0x20}},
{0x12, 1, {0x03}},
{0x13, 1, {0x80}},
{0x86, 1, {0x81}},
{0x88, 1, {0x00}},
{0x89, 1, {0x20}},
{0x8A, 1, {0x04}},
{0x8B, 1, {0x80}},
{0x14, 1, {0x81}},
{0x16, 1, {0x18}},
{0x17, 1, {0x00}},
{0x18, 1, {0x03}},
{0x19, 1, {0x04}},
{0x1A, 1, {0xC0}},
{0x1B, 1, {0x04}},
{0x1C, 1, {0x81}},
{0x1E, 1, {0x18}},
{0x1F, 1, {0x00}},
{0x20, 1, {0x05}},
{0x21, 1, {0x06}},
{0x22, 1, {0xC0}},
{0x23, 1, {0x04}},
{0x51, 1, {0xFF}},
{0x52, 1, {0x54}},
{0x53, 1, {0x36}},
{0x54, 1, {0x00}},
{0x55, 1, {0xCB}},
{0x56, 1, {0xBC}},
{0x58, 1, {0x12}},
{0x59, 1, {0xFF}},
{0x5A, 1, {0xFF}},
{0x5B, 1, {0xFF}},
{0x68, 1, {0xFF}},
{0x69, 1, {0xFF}},
{0x6A, 1, {0xFF}},
{0x6B, 1, {0x21}},
{0x6C, 1, {0xBC}},
{0x6D, 1, {0xCB}},
{0x6E, 1, {0x00}},
{0x6F, 1, {0x45}},
{0x70, 1, {0x63}},
{0x71, 1, {0xFF}},
{0x5F, 1, {0x22}},
{0x60, 1, {0x11}},
{0x61, 1, {0x00}},
{0x62, 1, {0x00}},
{0x63, 1, {0x11}},
{0x64, 1, {0x22}},
{0x33, 1, {0x88}},
{0x34, 1, {0x88}},
{0x35, 1, {0x88}},
{0x36, 1, {0x88}},
{0x39, 1, {0xFF}},
{0x3A, 1, {0xF7}},
{0xFE, 1, {0x00}},
{0xFE, 1, {0x20}},
{0x31, 2, {0x22, 0x00}},
{0x32, 2, {0x22, 0x00}},
{0x44, 2, {0x1E, 0x00}},
{0x45, 2, {0x1E, 0x00}},
{0x46, 2, {0x1A, 0x00}},
{0x47, 2, {0x1A, 0x00}},
{0x26, 2, {0x30, 0x00}},
{0xFE, 1, {0x3D}},
{0x55, 2, {0x78, 0x00}},
{0x20, 2, {0x71, 0x00}},
{0xFE, 1, {0x00}},
{0x35, 2, {0x00, 0x00}},
	

{0x11, 0,{0x00}},
{REGFLAG_DELAY, 120, {}},

{0x29, 0,{0x00}},
{REGFLAG_DELAY, 20, {}},

{REGFLAG_END_OF_TABLE, 0x00, {}}
	
};


static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 100, {}},

    // Sleep Mode On
	{0x10, 0, {0x00}},
	{REGFLAG_DELAY, 100, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

    for(i = 0; i < count; i++) {
		
        unsigned cmd;
        cmd = table[i].cmd;
		
        switch (cmd) {
/*
			case 0xD9:
				table[i].para_list[0]=vcom;
				dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
				vcom+=2;
				break;
			*/
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
		params->dsi.LANE_NUM		    = LCM_FOUR_LANE;
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
		params->dsi.word_count=720*3;	
		/** for VR****************/
		params->physical_width = 68;
		params->physical_height = 121;
		/*******************************/
		params->dsi.vertical_sync_active				= 2;
		params->dsi.vertical_backporch					= 12;	//14
		params->dsi.vertical_frontporch					= 16;
		params->dsi.vertical_active_line				= FRAME_HEIGHT; //1280+32 = 1312

		params->dsi.horizontal_sync_active				= 10;
		params->dsi.horizontal_backporch				= 30;
		params->dsi.horizontal_frontporch				= 30;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;	//720+110 = 830

	    	//params->dsi.LPX=8; 
	
		params->dsi.PLL_CLOCK = 400; //	200

}

static void lcm_init(void)
{
	LCM_DEBUG("Jason in %s line:%d \n", __func__, __LINE__);
	#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_bias_en(1);
//	lcm_i2c_set_vol_value(5000, 5000);
	#endif

	MDELAY(30);

	SET_RESET_PIN(1);
	MDELAY(20); 
	SET_RESET_PIN(0);
	MDELAY(20); 
	
	SET_RESET_PIN(1);
	MDELAY(120);      

	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
	
}



static void lcm_suspend(void)
{
	//lcm_initialization_setting[30].para_list[0] +=5;
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);

	#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_bias_en(0);
	#endif
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

extern int lcm_id_index(int b);

static unsigned int lcm_compare_id(void)
{
	int id = 0;
	int b = 0;
	
	int id2 = 0;
	unsigned char buffer[3];
	unsigned int array[16];
	
	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);
	SET_RESET_PIN(1);
	MDELAY(20);
	
//	MDELAY()
	array[0] = 0x00FE1500;	//page 0
	dsi_set_cmdq(array, 1, 1);
	array[0] = 0x00023700;// set return byte number
	dsi_set_cmdq(array, 1, 1);
	read_reg_v2(0x04, buffer, 2);
	id2 = buffer[1];
	

	id = lcm_id_index(b);
	
	#ifdef BUILD_LK
	printf("Jason in lk rm67200, id = %d id2 = 0x%x \n", id, id2);	
	#else
	printk("Jason in kernel rm67200, id = %d\n", id);
	#endif
	return (id==1) ? 1:0;
}

/*
static unsigned int lcm_esd_check(void)
{
  #ifndef BUILD_LK
	char  buffer[3];
	int   array[4];

	if(lcm_esd_test)
	{
		lcm_esd_test = FALSE;
		return TRUE;
	}

	array[0] = 0x00013700;
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0x36, buffer, 1);
	if(buffer[0]==0x90)
	{
		return FALSE;
	}
	else
	{			 
		return TRUE;
	}
 #endif

}
*/
/*
static unsigned int lcm_esd_recover(void)
{
	lcm_init();
	lcm_resume();

	return TRUE;
}
*/

LCM_DRIVER RM67200_DT55200A_lcm_drv = 
{
    .name		= "RM67200_DT55200A",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
	//.esd_check = lcm_esd_check,
	//.esd_recover = lcm_esd_recover,
	//.set_backlight  = lcm_backlight_control,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
    };
