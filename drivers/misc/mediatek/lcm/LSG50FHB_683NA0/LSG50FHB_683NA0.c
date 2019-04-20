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

#define LCM_ID_R63311 (0x90)

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

extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);

static LCM_UTIL_FUNCS lcm_util = {0};
//static unsigned int lcm_backlight_control(unsigned int level);
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

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};



static struct LCM_setting_table lcm_initialization_setting[] = {
{0xb0, 1, {0x04}},
{0xb3, 6, {0x14, 0x00, 0x00, 0x20, 0x00, 0x00}},
{0xb4, 2, {0x0c, 0x00}},
{0xb6, 2, {0x3a, 0xc3}},
{0xb7, 1, {0x00}},
{0xb8, 25, {0x18, 0x80, 0x18, 0x18, 0xCF, 0x1F, 0x00, 0x0C, 0x10, 0x5C, 0x10, 0xAC, 0x10, 0x0C, 0x10, 0xDA, 0x6D, 0xFF, 0xFF, 0x10, 0x67, 0x89, 0xAF, 0xD6, 0xFF}},
{0xb9, 7,  {0x0F, 0x18, 0x04, 0x40, 0x9F, 0x1F, 0x80}},
{0xbA, 7,  {0x0F, 0x18, 0x04, 0x40, 0x9F, 0x1F, 0xD7}},
{0xbB, 2, {0x00, 0x10}},
{0xC0, 2, {0x00, 0x00}},
{0xC1, 34, {0x84, 0x60, 0x40, 0x80, 0x84, 0x21, 0x8A, 0x01, 0x00, 0x1C, 0x94, 0xD4, 0x62, 0x6C, 0xA9, 0x84, 0x0E, 0x00, 0xC0, 0x14, 0x31, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x11, 0x13, 0x02, 0x02, 0x00}},
{0xc2, 7, {0x31, 0xf7, 0x80, 0x05, 0x08, 0x00, 0x00}},
{0xc4, 22, {0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06}},
{0xc6, 40, {0x07, 0x6C, 0x04, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x17, 0x07, 0x00, 0x01, 0x73, 0x6c, 0x04, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x17, 0x07}},
{0xc7, 24, {0x00, 0x09, 0x10, 0x19, 0x26, 0x3F, 0x33, 0x47, 0x59, 0x66, 0x70, 0x7F, 0x00, 0x09, 0x10, 0x19, 0x26, 0x3F, 0x33, 0x47, 0x59, 0x66, 0x70, 0x7F}},
{0xc8, 24, {0x00, 0x0B, 0x12, 0x1B, 0x28, 0x3F, 0x33, 0x47, 0x57, 0x65, 0x6F, 0x7F, 0x00, 0x0B, 0x12, 0x1B, 0x28, 0x3F, 0x33, 0x47, 0x57, 0x65, 0x6F, 0x7F}},
{0xc9, 24, {0x00, 0x0A, 0x10, 0x19, 0x26, 0x3E, 0x32, 0x46, 0x57, 0x65, 0x6F, 0x7F, 0x00, 0x0A, 0x10, 0x19, 0x26, 0x3E, 0x32, 0x46, 0x57, 0x65, 0x6F, 0x7F}},
{0xCA, 32, {0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x08, 0x20, 0x80, 0x80, 0x0A, 0x4A, 0x37, 0xA0, 0x55, 0xF8, 0x0C, 0x0C, 0x20, 0x10, 0x3F, 0x3F, 0x00, 0x00, 0x10, 0x10, 0x3F, 0x3F, 0x3F, 0x3F}},
{0xCB, 9, {0x7F, 0xfc, 0x3f, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xc0}},
{0xCC, 1, {0x2B}},
{0xCD, 3, {0x00, 0x00, 0xFF}},
{0xCE, 7,  {0x00, 0x06, 0x88, 0xC1, 0x00, 0x1E, 0x04}},
{0xCF, 5,  {0x00, 0x00, 0xC1, 0x05, 0x3F}},
{0xD0, 14, {0x00, 0x00, 0x19, 0x18, 0x99, 0x9D, 0x1D, 0x01, 0x8D, 0x00, 0xBB, 0x0D, 0x86, 0x01}},
{0xD1, 29, {0x20, 0x00, 0x00, 0x04, 0x08, 0x0C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x04, 0x20, 0x00, 0x00, 0x04, 0x08, 0x0C, 0x10, 0x00, 0x00, 0x3C, 0x06, 0x40, 0x00, 0x32, 0x31}},
{0xD2, 3,  {0x5C, 0x00, 0x00}},
{0xD3, 26, {0x1b, 0x33, 0xbb, 0xcc, 0xc4, 0x33, 0x33, 0x33, 0x00, 0x01, 0x00, 0xa0, 0x78, 0xa0, 0x00, 0x2B, 0x33, 0x33, 0x22, 0x70, 0x02, 0x2B, 0x03, 0x3d, 0xbf, 0x00}},
{0xd5, 7, {0x06, 0x00, 0x00, 0x01, 0x3d, 0x01, 0x3d}},//40,3d,45,48,4a,55,4E,52,3a,36,33
{0xD7, 20, {0x84, 0xF8, 0x7F, 0xA8, 0xCE, 0x38, 0xFC, 0xC1, 0x83, 0xE7, 0x8F, 0x1F, 0x3C, 0x10, 0xFA, 0xC3, 0x0F, 0x04, 0x41, 0x20}},
{0xD8, 6,  {0x00, 0x80, 0x80, 0x40, 0x42, 0x21}},

{0xD9, 2, {0x00, 0x00}},
{0xDD, 2, {0x10, 0x8C}},
{0xDE, 6,  {0x00, 0xFF, 0x07, 0x10, 0x00, 0x73}},



{0x29,0,{0x00}},
{REGFLAG_DELAY, 20, {}},
{0x11,0,{0x00}},
{REGFLAG_DELAY, 200, {}},
{0xb7,2,{0x6b,0x03}},
{REGFLAG_DELAY, 20, {}},
{REGFLAG_END_OF_TABLE, 0x00, {}}

		
};


static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 20, {}},//100

    // Sleep Mode On
	{0x10, 0, {0x00}},
	{REGFLAG_DELAY, 120, {}},       //200
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

		params->physical_width  = 62 ;
		params->physical_height = 110;

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
		params->dsi.word_count=FRAME_WIDTH*3;	//FRAME_WIDTH

		
		params->dsi.vertical_sync_active				=2;//20;//0x2;// 0x2;//
		params->dsi.vertical_backporch					=7;//20;//0x3;// 0x3;//=>{0XD3,1,{0X05}} VBP(lcm) = vertical_sync_active + vertical_backporch
		params->dsi.vertical_frontporch					=4;//10;// 0x4; //=>{0XD4,1,{0X04}} VFP
		params->dsi.vertical_active_line				= FRAME_HEIGHT; //1920

		params->dsi.horizontal_sync_active				=5;//50;// 0x05;// 50  2
		params->dsi.horizontal_backporch				=60;//60;//100;//0x3C;
		params->dsi.horizontal_frontporch				=80;//80;//94;//100;//80;// 0x5E;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		//params->dsi.esd_check_enable = 1;
		//params->dsi.customization_esd_check_enable = 1;

	   // params->dsi.lcm_esd_check_table[0].cmd          = 0x0A;
		//params->dsi.lcm_esd_check_table[0].count        = 1;
		//params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;
	    //params->dsi.LPX=8; 

	  //  params->dsi.noncont_clock				= TRUE;//ddp_dsi.c \D6\D0 hstx_cklp_en=FALSE \B8\C4ΪTRUE
		//params->dsi.noncont_clock_period				= 2; 


	    //params->dsi.LPX=8; 

		// Bit rate calculation
		//1 Every lane speed
		//params->dsi.pll_div1=0;		// div1=0,1,2,3;div1_real=1,2,4,4 ----0: 546Mbps  1:273Mbps
		//params->dsi.pll_div2=1;		// div2=0,1,2,3;div1_real=1,2,4,4	
		//params->dsi.fbk_div =15;    // fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)	
		params->dsi.PLL_CLOCK = 410;

}

static void lcm_init(void)
{
	agold_lcm_power_on();

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
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);

	MDELAY(5);
	SET_RESET_PIN(1); // page 142
	MDELAY(10); 
	SET_RESET_PIN(0);
	MDELAY(10); 	// page 142
	SET_RESET_PIN(1);
	MDELAY(30);  

	agold_lcm_power_down();
}


static void lcm_resume(void)
{
	//lcm_initialization_setting[141].para_list[0]-=0x01;
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

LCM_DRIVER LSG50FHB_683NA0_lcm_drv = 
{
    	.name		= "LSG50FHB_683NA0",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	//.compare_id     = lcm_compare_id,
	//.esd_check = lcm_esd_check,
	//.esd_recover = lcm_esd_recover,
	//.set_backlight  = lcm_backlight_control,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
    };
