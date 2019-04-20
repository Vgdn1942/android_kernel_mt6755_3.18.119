#define LOG_TAG "LCM"

#ifndef BUILD_LK
#include <linux/string.h>
#include <linux/kernel.h>
#endif
#include "lcm_drv.h"

#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
#include "lcm_common.h"
#include "lcm_i2c.h"
#endif

#ifdef BUILD_LK
#include <platform/upmu_common.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
/*#include <mach/mt_pm_ldo.h>*/
#ifdef CONFIG_MTK_LEGACY
#include <mach/mt_gpio.h>
#endif
#endif
#ifdef CONFIG_MTK_LEGACY
#include <cust_gpio_usage.h>
#endif
#ifndef CONFIG_FPGA_EARLY_PORTING
#if defined(CONFIG_MTK_LEGACY)
#include <cust_i2c.h>
#endif
#endif

#ifdef BUILD_LK
#define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
#define LCM_LOGI(fmt, args...)  printk("[MaJian]"fmt, ##args)   //pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif
// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------
static const unsigned int BL_MIN_LEVEL = 20;
static LCM_UTIL_FUNCS lcm_util;
extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);
extern int lcm_id_index(int b);
#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
extern int lcm_i2c_set_vol_value(int vop_value, int von_value);
extern int lcm_i2c_bias_en(int enable);
#endif
//static unsigned int lcm_compare_id(void);

#define SET_RESET_PIN(v)	(lcm_util.set_reset_pin((v)))
#define MDELAY(n)		(lcm_util.mdelay(n))
#define UDELAY(n)		(lcm_util.udelay(n))



#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) \
	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) \
		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd) lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums) \
		lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd) \
	  lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size) \
		lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

/* static unsigned char lcd_id_pins_value = 0xFF; */
static const unsigned char LCD_MODULE_ID = 0x01;

#define LCM_ID_OTM1911A		0x40

#define FRAME_WIDTH				(1080)
#define FRAME_HEIGHT			(1920)


#define REGFLAG_DELAY			0xFFFC
#define REGFLAG_UDELAY			0xFFFB
#define REGFLAG_END_OF_TABLE	0xFFFD
#define REGFLAG_RESET_LOW		0xFFFE
#define REGFLAG_RESET_HIGH		0xFFFF

#define   LCM_DSI_CMD_MODE		0

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[64];
};
/*
static struct LCM_setting_table lcm_initialization_setting[] = {

	{0x00, 1,  {0x00}},
	{0xFF, 3,  {0x19,0x01,0x01}},

	{0x00, 1,  {0x80}},
	{0xFF, 2,  {0x19,0x01}},

	{REGFLAG_DELAY, 10,  {}},

	{0x00, 1,  {0x00}},
	{0x1C, 1,  {0x33}},//video mode

	{0x00, 1,  {0xA0}},
	{0xC1, 1,  {0x00}},//external vsync

	{0x00, 1,  {0x00}},
	{0x35, 1,  {0x00}},//TE

	{0x00, 1,  {0x00}},
	{0x51, 1,  {0xFF}},
	{0x53, 1,  {0x2C}},
	{0x53, 1,  {0x01}},//cabc


	{0x11, 0,  {}}, //SLPOUT
	{REGFLAG_DELAY, 120,  {}},//wait 120ms
	{0x29, 0,  {}},
	{REGFLAG_DELAY, 10,  {}},//wait 10ms
	{REGFLAG_END_OF_TABLE, 0x00, {}}		
};
*/

static struct LCM_setting_table lcm_initialization_setting[] = {

	{0x00, 1,  {0x00}},
	{0xFF, 3,  {0x19,0x11,0x01}},//Enable command2

	{0x00, 1,  {0x80}},
	{0xFF, 2,  {0x19,0x11}},

	{0x00, 1,  {0x92}},
	{0xB3, 2,  {0x18,0x04}},//Panel Mode, swap G

	{0x00, 1,  {0x8A}},
	{0xC0, 1,  {0x04}},//lqj 0x05->0x04 for the display direction 

	{0x00, 1,  {0x8B}},
	{0xC0, 1,  {0x00}},//Panel Driving Mode

	{0x00, 1,  {0x80}},
	{0xC4, 2,  {0x41,0x02}},

	{0x00, 1,  {0x00}},
	{0xD8, 2,  {0x21,0x21}},//GVDDP/GVDDN=+/-4.5V

	{0x00, 1,  {0x00}},
	{0xD9, 2,  {0xB0,0x00}},//VCOM

	{0x00, 1,  {0x00}},
	{0xE0, 1,  {0x00}},//Gamma Separate Change

	{0x00, 1,  {0x90}},
	{0xC5, 1,  {0x88}},//GAP 

	{0x00, 1,  {0x91}},
	{0xC5, 1,  {0x80}},//SAP 

	{0x00, 1,  {0x83}},//VGH=9.2V 
	{0xC5, 1,  {0x9f}},

	{0x00, 1,  {0x84}},//VGL=-5.9V, 
	{0xC5, 1,  {0x93}},

	{0x00, 1,  {0xA0}},//VGHO=9.0V, 
	{0xC5, 1,  {0x9E}},

	{0x00, 1,  {0xA1}},//VGLO=-5.6V,
	{0xC5, 1,  {0x90}},

	//-----------------------------------------------
	{0x00, 1,  {0xB1}},//Gamma Calibration control disable
	{0xC5, 1,  {0x08}},

	{0x00, 1,  {0xB2}},//Gamma chop = 2line/2frame
	{0xC5, 1,  {0x22}},

	///////////////////////////GOP////////////////////////////

	//TCON
	{0x00, 1,  {0x80}},
	{0xC0, 5,  {0x61,0x00,0x08,0x08,0x61}},

	//CKH
	{0x00, 1,  {0x94}},
	{0xC0, 7,  {0x00,0x00,0x00,0x00,0x00,0x16,0x04}},

	//vst
	{0x00, 1,  {0x80}},
	{0xc2, 6,  {0x82,0x00,0x02,0x89,0x80,0x00}},


	//CKV
	{0x00, 1,  {0xb0}},
	{0xc2, 14,  {0x80,0x08,0x00,0x02,0x89,0x80,0x08,0x11,0x80,0x08,0x22,0x80,0x08,0x33}},

	{0x00, 1,  {0xc0}},
	{0xc2, 14,  {0x80,0x08,0x44,0x02,0x89,0x80,0x08,0x55,0x80,0x08,0x66,0x80,0x08,0x77}},

	{0x00, 1,  {0xd0}},
	{0xC2, 4,  {0x77,0x77,0x77,0x77}},

	//vend
	{0x00, 1,  {0xe0}},
	{0xc2, 6,  {0x00,0x00,0x00,0x00,0x00,0x00}},

	//rst
	{0x00, 1,  {0xf5}},
	{0xc2, 5,  {0x00,0x00,0x03,0x00,0x00}},

	//cic
	{0x00, 1,  {0x90}},
	{0xCB, 3,  {0x00,0x30,0x10}},

	{0x00, 1,  {0xC0}},
	{0xCB, 12,  {0x00,0x04,0x04,0x04,0x04,0x04,0x30,0x00,0x04,0x00,0x05,0x30}},

	{0x00, 1,  {0xf0}},
	{0xCB, 3,  {0x00,0x30,0xf0}},

	{0x00, 1,  {0x80}},
	{0xcd, 1,  {0x05}},

	//ckh_pch
	{0x00, 1,  {0xf5}},
	{0xc2, 5,  {0x11,0x01,0x0c,0x00,0x00}},

	{0x00, 1,  {0x80}},
	{0xa5, 2,  {0x0c,0x00}},

	//ckh    
	{0x00, 1,  {0xC0}},
	{0x94, 7,  {0x0a,0x01,0x08,0x08,0x01,0x08,0x06}},	

	//------------------------------------------------------------------------------------/////////////////////////////////////////////////////////////////
	{0x00, 1,  {0x00}},
	{0xE1, 37,  {0x00,0x2d,0x82,0xcd,0x00,0xfb,0x28,0x6e,0xa1,0x54,0x8e,0xc1,0xe5,0x1b,0x95,0x4d,0x7a,0xf3,0x10,0x9a,0x3d,0x69,0x86,0xa3,0xaa,0xcb,0xce,0x00,0x34,0xfa,0x57,0x75,0xfb,0xff,0xff,0xff,0x03}},
	{0x00, 1,  {0x00}},
	{0xE2, 37,  {0x00,0x2d,0x82,0xcd,0x00,0xfb,0x28,0x6e,0xa1,0x54,0x8e,0xc1,0xe5,0x1b,0x95,0x4d,0x7a,0xf3,0x10,0x9a,0x3d,0x69,0x86,0xa3,0xaa,0xcb,0xce,0x00,0x34,0xfa,0x57,0x75,0xfb,0xff,0xff,0xff,0x03}},
	{0x00, 1,  {0x00}},
	{0xE3, 37,  {0x00,0x2d,0x82,0xcd,0x00,0xfb,0x28,0x6e,0xa1,0x54,0x8e,0xc1,0xe5,0x1b,0x95,0x4d,0x7a,0xf3,0x10,0x9a,0x3d,0x69,0x86,0xa3,0xaa,0xcb,0xce,0x00,0x34,0xfa,0x57,0x75,0xfb,0xff,0xff,0xff,0x03}},
	{0x00, 1,  {0x00}},
	{0xE4, 37,  {0x00,0x2d,0x82,0xcd,0x00,0xfb,0x28,0x6e,0xa1,0x54,0x8e,0xc1,0xe5,0x1b,0x95,0x4d,0x7a,0xf3,0x10,0x9a,0x3d,0x69,0x86,0xa3,0xaa,0xcb,0xce,0x00,0x34,0xfa,0x57,0x75,0xfb,0xff,0xff,0xff,0x03}},
	{0x00, 1,  {0x00}},
	{0xE5, 37,  {0x00,0x2d,0x82,0xcd,0x00,0xfb,0x28,0x6e,0xa1,0x54,0x8e,0xc1,0xe5,0x1b,0x95,0x4d,0x7a,0xf3,0x10,0x9a,0x3d,0x69,0x86,0xa3,0xaa,0xcb,0xce,0x00,0x34,0xfa,0x57,0x75,0xfb,0xff,0xff,0xff,0x03}},
	{0x00, 1,  {0x00}},
	{0xE6, 37,  {0x00,0x2d,0x82,0xcd,0x00,0xfb,0x28,0x6e,0xa1,0x54,0x8e,0xc1,0xe5,0x1b,0x95,0x4d,0x7a,0xf3,0x10,0x9a,0x3d,0x69,0x86,0xa3,0xaa,0xcb,0xce,0x00,0x34,0xfa,0x57,0x75,0xfb,0xff,0xff,0xff,0x03}},

	{0x00, 1,  {0x90}},
	{0xC5, 1,  {0x45}},//GAP 8->4 ; AP 8->5, 20160420修正 For Power Saving Setting Modify 

	{0x00, 1,  {0x91}},
	{0xC5, 1,  {0xA0}},//SAP 8->A, 20160420修正 For special pattern horizontal band

	{0x00, 1,  {0x86}},//CKH EQ=3, 20160322修正 For Power Saving Setting Modify  
	{0xC3, 1,  {0x33}},

	{0x00, 1,  {0x90}},//CKH EQ=3, 20160322修正 For Power Saving Setting Modify  
	{0xC3, 1,  {0x30}},

	{0x00, 1,  {0x92}},//CKH EQ=3, 20160322修正 For Power Saving Setting Modify  
	{0xC3, 1,  {0x03}},

	{0x11, 0,  {}}, //SLPOUT
	{REGFLAG_DELAY, 120,  {}},//wait 120ms
	{0x29, 0,  {}},
	{REGFLAG_DELAY, 10,  {}},//wait 10ms
	{REGFLAG_END_OF_TABLE, 0x00, {}}							
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
    unsigned int i;

    for(i = 0; i < count; i++)
    {
        unsigned cmd;
        cmd = table[i].cmd;

        switch (cmd) {

            case REGFLAG_DELAY :
                if(table[i].count <= 10)
                    MDELAY(table[i].count);
                else
                    MDELAY(table[i].count);
                break;
				
			case REGFLAG_UDELAY :
				UDELAY(table[i].count);
				break;

            case REGFLAG_END_OF_TABLE :
                break;

            default:
                dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
        }
    }
}

// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS * util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS * params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode = CMD_MODE;
#else
	params->dsi.mode = BURST_VDO_MODE;
#endif

	// DSI
	/* Command mode setting */
	//1 Three lane or Four lane
	params->dsi.LANE_NUM = LCM_FOUR_LANE;
	//The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format = LCM_DSI_FORMAT_RGB888;

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active = 1;
	params->dsi.vertical_backporch = 5;
	params->dsi.vertical_frontporch = 6;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 4;
	params->dsi.horizontal_backporch = 50;//42
	params->dsi.horizontal_frontporch = 50;//42
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	//params->dsi.pll_select=1;     //0: MIPI_PLL; 1: LVDS_PLL
	// Bit rate calculation
	//1 Every lane speed
	params->dsi.PLL_CLOCK = 455;//450

}

static void lcm_init(void)
{	
	LCM_LOGI("lcm_init enter\n");
	#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_bias_en(1);
	lcm_i2c_set_vol_value(5000, 5000);
	#endif

	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(120);
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);

}

static void lcm_suspend(void)
{
	unsigned int data_array[16];

	data_array[0] = 0x00280500;	// Display Off
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00100500;	// Sleep In
	dsi_set_cmdq(data_array, 1, 1);
	
	MDELAY(15);
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(10);
	
	#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_bias_en(0);
	#endif
	MDELAY(10);

}


static void lcm_resume(void)
{
	lcm_init();
}

static unsigned int lcm_compare_id(void)
{
		unsigned int id = 0;
		unsigned char buffer[2];
		unsigned int array[16];
		SET_RESET_PIN(1);  //NOTE:should reset LCM firstly
		SET_RESET_PIN(0);
		MDELAY(1);
		SET_RESET_PIN(1);
		MDELAY(150);
	
	//	push_table(lcm_compare_id_setting, sizeof(lcm_compare_id_setting) / sizeof(struct LCM_setting_table), 1);
	
		array[0] = 0x00023700;// read id return two byte,version and id
		dsi_set_cmdq(array, 1, 1);
		read_reg_v2(0xDA, buffer, 1);
	
		id = buffer[0]; //we only need ID
      #ifdef BUILD_UBOOT
		printf("%s,  id otm1911A= 0x%08x\n", __func__, id);
	  #endif
		return (LCM_ID_OTM1911A == id)?1:0;


}

#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
		       unsigned int width, unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0 >> 8) & 0xFF);
	unsigned char x0_LSB = (x0 & 0xFF);
	unsigned char x1_MSB = ((x1 >> 8) & 0xFF);
	unsigned char x1_LSB = (x1 & 0xFF);
	unsigned char y0_MSB = ((y0 >> 8) & 0xFF);
	unsigned char y0_LSB = (y0 & 0xFF);
	unsigned char y1_MSB = ((y1 >> 8) & 0xFF);
	unsigned char y1_LSB = (y1 & 0xFF);

	unsigned int data_array[16];

	data_array[0] = 0x00053902;
	data_array[1] =
	    (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00053902;
	data_array[1] =
	    (y1_MSB << 24) | (y0_LSB << 16) | (y0_MSB << 8) | 0x2b;
	data_array[2] = (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);

}
#endif

LCM_DRIVER otm1911a_fhd_dsi_vdo_zhbohui_lcm_drv = {
	.name = "otm1911a_fhd_dsi_vdo_zhbohui",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
#if (LCM_DSI_CMD_MODE)
	.update = lcm_update,
#endif
};
