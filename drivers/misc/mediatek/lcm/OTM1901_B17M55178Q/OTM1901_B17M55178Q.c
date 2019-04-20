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

#ifdef BUILD_LK
#define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
#define LCM_LOGI(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

#define LCM_ID_NT35695 (0xf5)
#define GPIO_LCD_PWR_LDO_PIN		11
#define GPIO_LCD_RESET_PIN		158
#define GPIO_LCD_PWR_SWITCH_PIN		86 

static const unsigned int BL_MIN_LEVEL = 20;
static LCM_UTIL_FUNCS lcm_util;
extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);

#define SET_RESET_PIN(v)	(lcm_util.set_reset_pin((v)))
#define SET_GPIO_OUT(n, v)	(lcm_util.set_gpio_out((n), (v)))
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

#define set_gpio_lcd_enp(cmd) \
		lcm_util.set_gpio_lcd_enp_bias(cmd)


/* static unsigned char lcd_id_pins_value = 0xFF; */
static const unsigned char LCD_MODULE_ID = 0x01;
#define FRAME_WIDTH										(1080)
#define FRAME_HEIGHT									(1920)


#define REGFLAG_DELAY		0xFFFCd
#define REGFLAG_UDELAY	0xFFFB
#define REGFLAG_END_OF_TABLE	0xFFFD
#define REGFLAG_RESET_LOW	0xFFFE
#define REGFLAG_RESET_HIGH	0xFFFF



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

static struct LCM_setting_table lcm_initialization_setting[] = {

	{0x00,1,{0x00}},
	{0xFF,3,{0x19,0x01,0x01}},//Enable command2
	 
	{0x00,1,{0x80}},
	{0xFF,2,{0x19,0x01}},
	 
	{0x00,1,{0x00}},
	{0x1C,1,{0x33}},//bypass mode
	 
	{0x00,1,{0xA0}},
	{0xC1,1,{0xE8}},//Video mode sync
	 
	{0x00,1,{0xA7}},
	{0xC1,1,{0x00}},
	 
	{0x00,1,{0x90}},
	{0xC0,6,{0x00,0x2F,0x00,0x00,0x00,0x01}},
	 
	{0x00,1,{0xC0}},
	{0xC0,6,{0x00,0x2F,0x00,0x00,0x00,0x01}},
	 
	{0x00,1,{0x9A}},
	{0xC0,1,{0x1E}},
	 
	{0x00,1,{0xAC}},
	{0xC0,1,{0x06}},
	 
	{0x00,1,{0xDC}},
	{0xC0,1,{0x06}},
	 
	{0x00,1,{0x92}},
	{0xE9,1,{0x00}},
	 
	{0x00,1,{0x90}},
	{0xF3,1,{0x01}},
	 
	{0x00,1,{0x93}},
	{0xC5,1,{0x1E}},//VGH=9V
	 
	{0x00,1,{0x95}},
	{0xC5,1,{0x32}},//VGL=-9V
	 
	{0x00,1,{0x97}},
	{0xC5,1,{0x19}},//VGHO=8.5V
	
	{0x00,1,{0x99}},
	{0xC5,1,{0x1E}},//VGLO=-7V
	 
	{0x00,1,{0x9B}},
	{0xC5,3,{0x22,0x20,0x55}},//charge pump 1 line (default)
	 
//	{0x00,1,{0x00}},
//	{0xD9,2,{0x00,0xAA}},//VCOM=-0.3V
	 
	{0x00,1,{0x00}},
	{0xD8,2,{0x23,0x23}},//GVDDP/GVDDN=4.6V
	 
	{0x00,1,{0xB3}},
	{0xC0,1,{0xCC}},
	 
	{0x00,1,{0xBC}},
	{0xC0,1,{0x00}},//Pixel base column inversion
	 
	{0x00,1,{0x84}},
	{0xC4,1,{0x22}},
	 
	{0x00,1,{0x80}},
	{0xC4,1,{0x16}},//Source=HiZ at Vblanking

	//Panel Timing
	{0x00,1,{0x80}},
	{0xC0,14,{0x00,0x7C,0x00,0x08,0x08,0x00,0x7C,0x08,0x08,0x00,0x7C,0x00,0x08,0x08}},

	{0x00,1,{0xF0}},
	{0xC3,6,{0x22,0x00,0x00,0x00,0x00,0x0C}},

	{0x00,1,{0xA0}},
	{0xC0,7,{0x00,0x00,0x1E,0x00,0x00,0x17,0x06}},
	 
	{0x00,1,{0xD0}},
	{0xC0,7,{0x00,0x00,0x1E,0x00,0x00,0x17,0x06}},
	 
	{0x00,1,{0x90}},
	{0xC2,8,{0x83,0x01,0x74,0x36,0x82,0x01,0x74,0x36}},

	{0x00,1,{0xA0}},
	{0xC2,4,{0x83,0x00,0x00,0xD0}},

	{0x00,1,{0x80}},
	{0xC3,12,{0x82,0x02,0x03,0x00,0x13,0x04,0x81,0x02,0x03,0x00,0x13,0x04}},

	{0x00,1,{0x90}},
	{0xC3,12,{0x80,0x02,0x03,0x00,0x13,0x04,0x01,0x02,0x03,0x00,0x13,0x04}},

	{0x00,1,{0x80}},
	{0xCC,15,{0x09,0x0A,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x0B,0x28,0x28,0x28,0x28}},

	{0x00,1,{0x90}},
	{0xCC,15,{0x0A,0x09,0x14,0x13,0x12,0x11,0x15,0x16,0x17,0x18,0x0B,0x28,0x28,0x28,0x28}}, 

	{0x00,1,{0xA0}},
	{0xCC,15,{0x1D,0x1E,0x1F,0x19,0x1A,0x1B,0x1C,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27}},

	{0x00,1,{0xB0}},
	{0xCC,8,{0x01,0x02,0x03,0x05,0x06,0x07,0x04,0x08}},

	{0x00,1,{0xC0}},
	{0xCC,12,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77}},

	{0x00,1,{0xD0}},
	{0xCC,12,{0xFF,0x0F,0x30,0x00,0x05,0x00,0x00,0x00,0x33,0x03,0x00,0x77}}, 

	{0x00,1,{0x80}},
	{0xCB,15,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCF,0x00,0x00,0x00,0x00}}, 

	{0x00,1,{0x90}},
	{0xCB,15,{0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

	{0x00,1,{0xA0}},
	{0xCB,15,{0x15,0x15,0x15,0x15,0x15,0x15,0x00,0x00,0x00,0x00,0xEA,0x00,0x00,0x00,0x00}},

	{0x00,1,{0xB0}},
	{0xCB,15,{0x00,0x15,0xD5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}, 

	{0x00,1,{0xC0}},
	{0xCB,8,{0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x77}}, 

	{0x00,1,{0xD0}},
	{0xCB,8,{0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x77}},

	{0x00,1,{0xE0}},
	{0xCB,8,{0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x77}},

	{0x00,1,{0xF0}},
	{0xCB,8,{0x11,0x11,0x11,0x00,0x00,0x00,0x77,0x77}},

	{0x00,1,{0x80}},
	{0xCD,15,{0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x06,0x04,0x0B,0x11,0x12,0x02}}, 

	{0x00,1,{0x90}},
	{0xCD,11,{0x3F,0x3F,0x3F,0x25,0x25,0x25,0x21,0x20,0x1F,0x25,0x25}},

	{0x00,1,{0xA0}},
	{0xCD,15,{0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x05,0x03,0x0B,0x11,0x12,0x01}}, 

	{0x00,1,{0xB0}},
	{0xCD,11,{0x3F,0x3F,0x3F,0x25,0x25,0x25,0x21,0x20,0x1F,0x25,0x25}},

	{0x00,1,{0x00}},
	{0xE1,24,{0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,
	0x5e,0x4c,0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},
	
	{0x00,1,{0x00}},
	{0xE2,24,{0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,
	0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},

	{0x00,1,{0x00}},
	{0xE3,24,{0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,
	0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},
	
	{0x00,1,{0x00}},
	{0xE4,24,{0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,
	0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},

	{0x00,1,{0x00}},
	{0xE5,24,{0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,
	0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}},
	
	{0x00,1,{0x00}},
	{0xE6,24,{0x1a,0x1f,0x22,0x2a,0x30,0x36,0x40,0x50,0x58,0x6a,0x77,0x80,0x79,0x73,0x6e,0x5e,0x4c,
	0x3a,0x2d,0x25,0x1c,0x0f,0x07,0x03}}, 

	{0x00,1,{0xD4}},//LTPS Ground Period for Gate Precharge
	{0xC3,4,{0x01,0x01,0x01,0x01}},
	 
	{0x00,1,{0xF7}},//LTPS CKH EQ Setting
	{0xC3,4,{0x04,0x16,0x00,0x00}},
	 
	{0x00,1,{0xD0}},//AVDDR/AVEER regulatior Disable
	{0xF5,4,{0x00,0x00,0x00,0x00}},

	{0x00,1,{0x81}},
	{0xA5,1,{0x06}},

	{0x00,1,{0x82}},
	{0xC4,1,{0xf0}},

	{0x00,1,{0x84}},
	{0xC4,1,{0x22}},

	{0x00,1,{0x92}},
	{0xC5,1,{0xc0}},

	{0x00,1,{0x94}},
	{0xC5,1,{0x90}},

	{0x00,1,{0xc1}},
	{0xC5,1,{0x66}},

	{0x00,1,{0x89}},
	{0xF3,1,{0x5A}},

	{0x00,1,{0x90}},
	{0xF3,1,{0x01}},

	{0x00,1,{0x82}},
	{0xA5,1,{0x1F}},

	{0x00,1,{0xC2}},  
	{0xC5,1,{0x1E}},    //1E

	{0x00,1,{0xA8}},  
	{0xC4,1,{0x12}},

	{0x00,1,{0xA0}},  
	{0xC4,4,{0x30,0x26,0x04,0x3A}},

	{0x00,1,{0xA4}},  
	{0xC4,4,{0x30,0x26,0x84,0x3A}},

	{0x00,1,{0xE1}},  
	{0xF5,1,{0x45}},

	//{0x00,1,{0xA8}},  
	//{0xC4,1,{0x12}},   //12

	{0x00,1,{0x00}},
	{0xFF,3,{0xFF,0xFF,0xFF}},

	{0x11, 0, {0x00}},
	{REGFLAG_DELAY, 150, {}},
	{0x29, 0,{0x00}},
	{REGFLAG_DELAY, 150, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}  


};

/*
static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
	// Display off sequence
	data_array[0]=0x00280500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(50);

	data_array[0] = 0x00100500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);
};
*/

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{	
	unsigned int i;
	unsigned cmd;
	
	LCM_LOGI("[cp]static void push_table\n");
	for (i = 0; i < count; i++) {
		cmd = table[i].cmd;

		switch (cmd) {

		case REGFLAG_DELAY:
			if (table[i].count <= 10)
				MDELAY(table[i].count);
			else
				MDELAY(table[i].count);
			break;

		case REGFLAG_UDELAY:
			UDELAY(table[i].count);
			break;

		case REGFLAG_END_OF_TABLE:
			break;

		default:
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
		}
	}
}

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{	
	LCM_LOGI("[cp]lcm_get_params\n");
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;
	params->physical_width  = 68 ;
	params->physical_height = 121;

	params->dsi.mode = SYNC_PULSE_VDO_MODE;
	params->dsi.switch_mode = CMD_MODE;
	params->dsi.switch_mode_enable = 0;

	/* DSI */
	/* Command mode setting */
	params->dsi.LANE_NUM = LCM_FOUR_LANE;
	/* The following defined the fomat for data coming from LCD engine. */
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format = LCM_DSI_FORMAT_RGB888;
	params->dbi.io_driving_current      = LCM_DRIVING_CURRENT_4MA;

	/* Highly depends on LCD driver capability. */
	params->dsi.packet_size = 256;
	/* video mode timing */

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;
	
	params->dsi.vertical_sync_active				= 2;//5
	params->dsi.vertical_backporch					= 6;
	params->dsi.vertical_frontporch					= 8;
	params->dsi.vertical_active_line				= FRAME_HEIGHT; 
		
	params->dsi.horizontal_sync_active				= 4;
	params->dsi.horizontal_backporch				= 32;//66
	params->dsi.horizontal_frontporch				= 32;//70
	params->dsi.horizontal_active_pixel		       		= FRAME_WIDTH;
		
	params->dsi.PLL_CLOCK = 400;	//420 450

	
	
	params->dbi.te_hs_delay_cnt = 0x89;
}



static void lcm_init(void)
{	
	LCM_LOGI("[cp]lcm_init enter\n");

	agold_lcm_power_on();

	SET_RESET_PIN(1);
	MDELAY(20);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(120);
	
	push_table(lcm_initialization_setting,
		   sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
	
	//init_lcm_registers();
	//push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{	
	LCM_LOGI("[cp]lcm_resume enter\n");
	#ifndef BUILD_LK
	mt_set_gpio_mode(0x80000000 | 157, GPIO_MODE_01);
	mt_set_gpio_dir(0x80000000 | 157, GPIO_DIR_OUT);
	#endif
	lcm_init();
}

static void lcm_suspend(void)
{	
	//push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	unsigned int data_array[16];

	data_array[0]=0x00280500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(40);

	data_array[0] = 0x00100500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);
/*
data_array[0] = 0x00043902;
data_array[1] = 0x9983ffb9;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x00023902;
data_array[1] = 0x000002b1;
dsi_set_cmdq(data_array, 2, 1);

	LCM_LOGI("[cp]lcm_suspend enter\n");
	
*/
	//MDELAY(15);
	//SET_RESET_PIN(1);
	//MDELAY(10);
	//SET_RESET_PIN(0);
	//MDELAY(10);
	//SET_RESET_PIN(1);

	LCM_LOGI("[cp]SET_RESET_PIN_LATER\n");

	//MDELAY(20);//MDELAY(500);
	agold_lcm_power_down();
	#ifndef BUILD_LK
	mt_set_gpio_mode(0x80000000 | 157, GPIO_MODE_00);
	mt_set_gpio_dir(0x80000000 | 157, GPIO_DIR_IN);
	#endif

	//MDELAY(1500);
	LCM_LOGI("[cp]agold_lcm_power_down_later\n");
}

static unsigned int lcm_compare_id(void)
{
	unsigned int id1 = 0,id2 = 0;
	unsigned char buffer[5];
	unsigned int array[16];

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);

	array[0] = 0x00023700;	/* read id return two byte,version and id */
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xA1, buffer, 5);
	id1 = buffer[2];
	id2 = buffer[3];		/* we only need ID */

	if((id1 == 0x19) && (id2 == 0x01))
	{
	     return 1;
	}
	else
	{
	     return 0;
	}
}

static void lcm_init_power(void)
{
	LCM_LOGI("[cp]lcm_init_power enter\n");
}


LCM_DRIVER OTM1901_B17M55178Q_lcm_drv = {
	.name = "OTM1901_B17M55178Q",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};