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


#define REGFLAG_DELAY		0xFFFC
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

{0xB9,3,{0xFF,0x83,0x98}},

{0xB1,11,{0x28,0x12,0x92,0x01,0x02,0x33,0x53,0x33,0xD7,0xC6,
		  0x0D}},

{0xB2,10,{0x40,0x00,0xAE,0x1C,0x0B,0x45,0x11,0x00,0x00,0x00}},

{0xB4,25,{0x00,0xFF,0x03,0xBF,0x06,0x7F,0x00,0x00,0x03,0x05,
		  0x95,0x22,0x05,0x3A,0x03,0x98,0x06,0xA8,0x00,0x00,
		  0x03,0x05,0x98,0x3A,0x10}},

{0xD3,35,{0x20,0x00,0x00,0x00,0x00,0x00,0x3C,0x01,0x10,0x00,
		  0x32,0x10,0x07,0x00,0x07,0x54,0x17,0x8D,0x07,0x8D,
		  0x00,0x00,0x00,0x00,0x00,0x37,0x03,0x09,0x09,0x3B,
		  0x00,0x00,0x00,0x0C,0X40}},            

{0xD5,40,{0x18,0x18,0x18,0x18,0x18,0x18,0x20,0x21,0x18,0x18,
		  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,
		  0x0A,0x0B,0x18,0x18,0x18,0x18,0x1A,0x1A,0x1B,0x1B,
		  0x24,0x25,0x18,0x18,0x18,0x18,0x18,0x18,0x26,0x27}},

{0xD6,40,{0x18,0x18,0x18,0x18,0x18,0x18,0x25,0x24,0x18,0x18,
		  0x03,0x02,0x01,0x00,0x0B,0x0A,0x09,0x08,0x07,0x06,
		  0x05,0x04,0x18,0x18,0x18,0x18,0x1A,0x1A,0x1B,0x1B,
		  0x21,0x20,0x18,0x18,0x18,0x18,0x18,0x18,0x27,0x26}},

{0xD8,20,{0x03,0x3F,0xFC,0x3F,0xFF,0x03,0x3F,0xFC,0x3F,0xFF,
		  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0xBD,1,{0x01}},                            

{0xD8,20,{0x03,0x3F,0xFC,0x3F,0xFF,0x03,0x3F,0xFC,0x3F,0xFF,
		  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
					 
{0xBD,1,{0x02}},                            

{0xD8,10,{0x03,0x3F,0xFC,0x3F,0xFF,0x03,0x3F,0xFC,0x3F,0xFF}},

{0xBD,1,{0x00}},                            

{0xE0,58,{0x01,0x18,0x25,0x2C,0x30,0x35,0x38,0x37,0x71,0x80,
		  0x92,0x92,0x99,0xAB,0xAE,0xB3,0xC0,0xBF,0xBC,0xC5,
	      0xD5,0x74,0x76,0x7F,0x7F,0x7E,0x7C,0x7C,0x7E,0x01,
		  0x18,0x25,0x2C,0x30,0x35,0x38,0x37,0x71,0x80,0x92,
		  0x92,0x99,0xAB,0xAE,0xB3,0xC0,0xBF,0xBC,0xC5,0xD5,
		  0x62,0x60,0x63,0x66,0x69,0x70,0x77,0x7E}},

{0xCC,1,{0x02}},

{0xB6,3,{0x22,0x22,0xE3}},

{0x11,0,{0x00}},    
{REGFLAG_DELAY,180,{}},                                

{0x29,0,{0x00}},//Display ON 
{REGFLAG_DELAY,10,{}},	

{REGFLAG_END_OF_TABLE, 0x00, {}}

};

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{	
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

	params->dsi.vertical_sync_active = 4;
	params->dsi.vertical_backporch = 14;
	params->dsi.vertical_frontporch = 22;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 16;
	params->dsi.horizontal_backporch = 48;
	params->dsi.horizontal_frontporch = 16;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;


	params->dsi.PLL_CLOCK = 409;	//420
	params->dbi.te_hs_delay_cnt = 0x89;
}

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
			/*case 0x46:
					table[i].para_list[0]=buffer1;
					dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
					buffer1=buffer1+2;
					break;*/
            case REGFLAG_END_OF_TABLE :
                break;
				
            default:
				dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
				//MDELAY(2);
       	}
    }
	
}

static void lcm_init(void)
{	
	SET_RESET_PIN(0);
	MDELAY(10);
	agold_lcm_power_on();
	MDELAY(50);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(10);
//	SET_RESET_PIN(1);
//	MDELAY(100);
	
	//init_lcm_registers();
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{	
	//LCM_LOGI("[cp]lcm_resume enter\n");
	
//	lcm_initialization_setting[15].para_list[0]+=0x02;
	lcm_init();
}

static void lcm_suspend(void)
{	
	//push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	unsigned int data_array[16];

	data_array[0]=0x00280500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(30);//40

	data_array[0] = 0x00100500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(100);//50
/************************/
	SET_RESET_PIN(1);
	MDELAY(20);
	SET_RESET_PIN(0);
	MDELAY(10);
/**********************/
	agold_lcm_power_down();

}

/*
extern int lcm_id_index(int b);
static unsigned int lcm_compare_id(void)
{
	int id = 0;
	int b = 0;
	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);
	id=lcm_id_index(b);
	if(id==7)
	{
	}
	else
	{
		return 0;
	}
}
*/

static void lcm_init_power(void)
{
	LCM_LOGI("[cp]lcm_init_power enter\n");
}


LCM_DRIVER HX8398_MS_J550056Q2H_lcm_drv = {
	.name = "HX8398_MS_J550056Q2H",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	//.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
