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

#include <agold_lcm_drv.h>

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

#define FRAME_WIDTH  (720)
#define FRAME_HEIGHT (1280)

#define LCM_ID_JD9365 (0x9365)

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


{0xE0,01,{0x00}},
{0xE1,01,{0x93}},
{0xE2,01,{0x65}},
{0xE3,01,{0xF8}},

{0xE0,01,{0x04}},
{0x2D,01,{0x03}},
{0x2B,01,{0x2B}},
{0x2E,01,{0x44}},
{0xE0,01,{0x00}},

{0x55,01,{0x00}},
{0xE6,01,{0x02}},
{0xE7,01,{0x02}},

{0x70,01,{0x10}},
{0x71,01,{0x13}},
{0x72,01,{0x06}},
{0x75,01,{0x03}},

{0xE0,01,{0x01}},


{0x00,01,{0x00}},
{0x01,01,{0xD2}},//vcom:c0,da,d1,d2,d0,cf
{0x03,01,{0x00}},
{0x04,01,{0x9F}},


{0x0A,01,{0x07}},
{0x0C,01,{0x74}},


{0x17,01,{0x00}},
{0x18,01,{0xC7}},//E7
{0x19,01,{0x01}},
{0x1A,01,{0x00}},
{0x1B,01,{0xC7}},//E7
{0x1C,01,{0x01}},


{0x1F,01,{0x3E}},
{0x20,01,{0x3D}},
{0x21,01,{0x3d}},
{0x22,01,{0xF8}},


{0x37,01,{0x09}},
{0x38,01,{0x05}},
{0x39,01,{0x08}},
{0x3A,01,{0x12}},
{0x3C,01,{0x78}},
{0x3D,01,{0xFF}},
{0x3E,01,{0xFF}},
{0x3F,01,{0xFF}},



{0x40,01,{0x04}},
{0x41,01,{0xA0}},

{0x43,01,{0x09}},
{0x44,01,{0x07}},
{0x45,01,{0x30}},
{0x4B,01,{0x04}},

{0x55,01,{0x01}},
{0x56,01,{0x01}},
{0x57,01,{0x69}},
{0x58,01,{0x0A}},
{0x59,01,{0x0A}},
{0x5A,01,{0x2A}},
{0x5B,01,{0x1B}},
{0x5C,01,{0x16}},


{0x5D,01,{0x7F}},
{0x5E,01,{0x61}},
{0x5F,01,{0x50}},
{0x60,01,{0x42}},
{0x61,01,{0x3B}},
{0x62,01,{0x2C}},
{0x63,01,{0x2E}},
{0x64,01,{0x15}},
{0x65,01,{0x2B}},
{0x66,01,{0x28}},
{0x67,01,{0x25}},
{0x68,01,{0x41}},
{0x69,01,{0x2D}},
{0x6A,01,{0x35}},
{0x6B,01,{0x27}},
{0x6C,01,{0x24}},
{0x6D,01,{0x1A}},
{0x6E,01,{0x12}},
{0x6F,01,{0x01}},
{0x70,01,{0x7F}},
{0x71,01,{0x61}},
{0x72,01,{0x50}},
{0x73,01,{0x42}},
{0x74,01,{0x3B}},
{0x75,01,{0x2C}},
{0x76,01,{0x2E}},
{0x77,01,{0x15}},
{0x78,01,{0x2B}},
{0x79,01,{0x28}},
{0x7A,01,{0x25}},
{0x7B,01,{0x41}},
{0x7C,01,{0x2D}},
{0x7D,01,{0x35}},
{0x7E,01,{0x27}},
{0x7F,01,{0x24}},
{0x80,01,{0x1A}},
{0x81,01,{0x12}},
{0x82,01,{0x01}},



{0xE0,01,{0x02}},


{0x00,01,{0x00}},
{0x01,01,{0x04}},
{0x02,01,{0x06}},
{0x03,01,{0x08}},
{0x04,01,{0x0A}},
{0x05,01,{0x1F}},
{0x06,01,{0x1F}},
{0x07,01,{0x1F}},
{0x08,01,{0x1F}},
{0x09,01,{0x1F}},
{0x0A,01,{0x1F}},
{0x0B,01,{0x1F}},
{0x0C,01,{0x1F}},
{0x0D,01,{0x1F}},
{0x0E,01,{0x1F}},
{0x0F,01,{0x1E}},
{0x10,01,{0x1E}},
{0x11,01,{0x1E}},
{0x12,01,{0x1F}},
{0x13,01,{0x1E}},
{0x14,01,{0x1F}},
{0x15,01,{0x10}},


{0x16,01,{0x01}},
{0x17,01,{0x05}},
{0x18,01,{0x07}},
{0x19,01,{0x09}},
{0x1A,01,{0x0B}},
{0x1B,01,{0x1F}},
{0x1C,01,{0x1F}},
{0x1D,01,{0x1F}},
{0x1E,01,{0x1F}},
{0x1F,01,{0x1F}},
{0x20,01,{0x1F}},
{0x21,01,{0x1F}},
{0x22,01,{0x1F}},
{0x23,01,{0x1F}},
{0x24,01,{0x1F}},
{0x25,01,{0x1E}},
{0x26,01,{0x1E}},
{0x27,01,{0x1E}},
{0x28,01,{0x1F}},
{0x29,01,{0x1E}},
{0x2A,01,{0x1F}},
{0x2B,01,{0x11}},


{0x2C,01,{0x11}},
{0x2D,01,{0x0B}},
{0x2E,01,{0x09}},
{0x2F,01,{0x07}},
{0x30,01,{0x05}},
{0x31,01,{0x1F}},
{0x32,01,{0x1F}},
{0x33,01,{0x1F}},
{0x34,01,{0x1F}},
{0x35,01,{0x1F}},
{0x36,01,{0x1F}},
{0x37,01,{0x1F}},
{0x38,01,{0x1F}},
{0x39,01,{0x1F}},
{0x3A,01,{0x1F}},
{0x3B,01,{0x1E}},
{0x3C,01,{0x1E}},
{0x3D,01,{0x1E}},
{0x3E,01,{0x1F}},
{0x3F,01,{0x1F}},
{0x40,01,{0x1E}},
{0x41,01,{0x01}},


{0x42,01,{0x10}},
{0x43,01,{0x0A}},
{0x44,01,{0x08}},
{0x45,01,{0x06}},
{0x46,01,{0x04}},
{0x47,01,{0x1F}},
{0x48,01,{0x1F}},
{0x49,01,{0x1F}},
{0x4A,01,{0x1F}},
{0x4B,01,{0x1F}},
{0x4C,01,{0x1F}},
{0x4D,01,{0x1F}},
{0x4E,01,{0x1F}},
{0x4F,01,{0x1F}},
{0x50,01,{0x1F}},
{0x51,01,{0x1E}},
{0x52,01,{0x1E}},
{0x53,01,{0x1E}},
{0x54,01,{0x1F}},
{0x55,01,{0x1F}},
{0x56,01,{0x1E}},
{0x57,01,{0x00}},



{0x58,01,{0x00}},
{0x59,01,{0x00}},
{0x5A,01,{0x00}},
{0x5B,01,{0x10}},
{0x5C,01,{0x01}},
{0x5D,01,{0x30}},
{0x5E,01,{0x01}},
{0x5F,01,{0x02}},
{0x60,01,{0x30}},
{0x61,01,{0x01}},
{0x62,01,{0x02}},
{0x63,01,{0x03}},
{0x64,01,{0x6B}},
{0x65,01,{0x55}},
{0x66,01,{0x0B}},
{0x67,01,{0x73}},
{0x68,01,{0x07}},
{0x69,01,{0x06}},
{0x6A,01,{0x70}},
{0x6B,01,{0x00}},
{0x6C,01,{0x00}},
{0x6D,01,{0x04}},
{0x6E,01,{0x04}},
{0x6F,01,{0x88}},
{0x70,01,{0x00}},
{0x71,01,{0x00}},
{0x72,01,{0x06}},
{0x73,01,{0x7B}},
{0x74,01,{0x00}},
{0x75,01,{0x87}},
{0x76,01,{0x00}},
{0x77,01,{0x5D}},
{0x78,01,{0x18}},
{0x79,01,{0x1F}},
{0x7A,01,{0x00}},
{0x7B,01,{0x00}},
{0x7C,01,{0x00}},
{0x7D,01,{0x03}},
{0x7E,01,{0x7B}},

{0xE0,01,{0x04}},
{0x09,01,{0x10}},
{0x2B,01,{0x2B}},
{0x2E,01,{0x44}},


{0xE0,01,{0x00}},
{0xE6,01,{0x02}},
{0xE7,01,{0x02}},
{0x55,01,{0x90}},
                                  
{0x11,1,{0x00}},                   
{REGFLAG_DELAY, 120, {}},         
                                  
{0x29,1,{0x00}},                  
                                  
{REGFLAG_DELAY, 10, {}}, 
         
{REGFLAG_END_OF_TABLE, 0x00, {}}   

};


static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 10, {}},

    // Sleep Mode On
	{0x10, 0, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
/*
static struct LCM_setting_table lcm_compare_id_setting[] = {
	// Display off sequence
	
	{REGFLAG_DELAY, 10, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
*/

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


		params->dsi.vertical_sync_active				= 4;// 3    2
		params->dsi.vertical_backporch					= 6;//0x20;// 20   1
		params->dsi.vertical_frontporch					= 16;//0x40; // 1  12
		params->dsi.vertical_active_line				= FRAME_HEIGHT;

		params->dsi.horizontal_sync_active				= 24;//0x05;// 50  2
		params->dsi.horizontal_backporch				= 50;//100;//0x30;//3c
		params->dsi.horizontal_frontporch				= 50;//100;//0x40;//50
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		// Bit rate calculation
		//1 Every lane speed
		//params->dsi.pll_div1=0;		// div1=0,1,2,3;div1_real=1,2,4,4 ----0: 546Mbps  1:273Mbps
		//params->dsi.pll_div2=1;		// div2=0,1,2,3;div1_real=1,2,4,4	
		//params->dsi.fbk_div =16;    // fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)	
		
		params->dsi.PLL_CLOCK = 200;//220
		
		//params->physical_width  = 68 ;
        //params->physical_height = 121; 

}

static void lcm_init(void)
{


	agold_lcm_power_on();
	MDELAY(60);
	SET_RESET_PIN(1);
	MDELAY(20); 
	SET_RESET_PIN(0);
	MDELAY(30);
	
	SET_RESET_PIN(1);
	MDELAY(120);      

	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}



static void lcm_suspend(void)
{
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	MDELAY(60);
	SET_RESET_PIN(1);
	MDELAY(20); 
	SET_RESET_PIN(0);
	MDELAY(20); 
	
	SET_RESET_PIN(1);
	MDELAY(120);   
	agold_lcm_power_down();  
}


static void lcm_resume(void)
{
	//lcm_initialization_setting[18].para_list[0]+=0x01;
	
   // LCM_DEBUG("VCOM is :%d",lcm_initialization_setting[18].para_list[0]);
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
/*
static unsigned int lcm_compare_id(void)
{
	 unsigned int id1 = 0, id2 = 0,id;
    unsigned char buffer[4];
    unsigned int data_array[16];
     
    SET_RESET_PIN(1);    //NOTE:should reset LCM firstly
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(20);
    SET_RESET_PIN(1);
    MDELAY(100);

    data_array[0] = 0x00023700;
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(10);

    read_reg_v2(0x04, buffer, 2);
    id1= buffer[0]; //0x93
    id2= buffer[1]; //0x67
    
    id=(id1 << 8) | id2;

#if defined(BUILD_LK)
    printf("jd9365 id=%x, %x %x\n", id, id1, id2);
#else
    printk("jd9365 id=%x, %x %x\n", id, id1, id2);
#endif
    return (LCM_ID_JD9365 == id) ? 1 : 0;


   return 1;

}
*/
LCM_DRIVER SKZD_50087P_J01_lcm_drv = 
{
    .name			= "SKZD_50087P_J01",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
//	.compare_id     = lcm_compare_id,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
    };

