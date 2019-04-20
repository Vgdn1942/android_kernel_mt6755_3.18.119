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

#define GPIO_LCD_ID1_PIN	89
#define GPIO_LCD_ID2_PIN	87
#define GPIO_LCD_ID3_PIN	88

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

	{ 0XB9, 3, {0xFF,0x83,0x99} },
	
	{ 0XBA, 4, {0X63,0X03,0X68,0X73} },

	{ 0XB1, 15, {0x02,0x04,0x6D,0x8D,
			    0x01,0x32,0x33,0x11,
				0x11,0x5A,0x5F,0x56,
				0x73,0x02,0x02} },

	{ 0XB2, 11, {0x00,0x80,0x80,0xAE,
				 0x05,0x07,0x5A,0x11,
				 0x10,0x10,0x00} },

	{ 0XB4, 44, {0x00,0xFF,0x10,0x18,
			   0x04,0x9A,0x00,0x00,
			   0x06,0x00,0x02,0x04,
			   0x00,0x24,0x02,0x04,
			   0x0A,0x21,0x03,0x00,
			   0x00,0x02,0x9F,0x88,
			   0x10,0x18,0x04,0x9A,
			   0x00,0x00,0x08,0x00,
	  		   0x02,0x04,0x00,0x24,
			   0x02,0x04,0x0A,0x00,
			   0x00,0x02,0x9F,0x12} },

	{ 0XD3, 33,{0x00,0x00,0x00,0x00,
			   0x00,0x00,0x30,0x00,
			   0x00,0x00,0x05,0x00,
			   0x05,0x00,0x07,0x88,
			   0x07,0x88,0x00,0x00,
			   0x00,0x00,0x00,0x15,
			   0x00,0x00,0x00,0x01,
			   0x00,0x00,0x00,0x05,0x40} },

	{ 0XD5, 32, {0x20,0x20,0x19,0x19,
			     0x18,0x18,0x01,0x01,
				 0x00,0x00,0x25,0x25,
				 0x18,0x18,0x18,0x18,
				 0x24,0x24,0x18,0x18,
				 0x18,0x18,0x18,0x18,
				 0x18,0x18,0x2F,0x2F,
				 0x30,0x30,0x31,0x31} },

	{ 0XD6, 32, {0x24,0x24,0x18,0x18,
				 0x19,0x19,0x00,0x00,
				 0x01,0x01,0x25,0x25,
				 0x18,0x18,0x18,0x18,
				 0x20,0x20,0x18,0x18,
				 0x18,0x18,0x18,0x18,
				 0x18,0x18,0x2F,0x2F,
				 0x30,0x30,0x31,0x31} },

	{ 0XD8, 16, {0xAA,0x8A,0xAA,0xAA,
				 0xAA,0x8A,0xAA,0xAA,
				 0xAA,0x8A,0xAA,0xAA,
				 0xAA,0x8A,0xAA,0xAA} },

	{ 0XBD, 1, {0X01} },

	{ 0XD8, 16, {0xFF,0xFC,0xC0,0x3F,
				 0xFF,0xFC,0xC0,0x3F,
				 0xFF,0xFC,0xC0,0x3F,
				 0xFF,0xFC,0xC0,0x3F} },

	{ 0XBD, 1, {0X02} },

	{ 0XD8, 8, {0xFF,0xFC,0xC0,0x3F,
				0xFF,0xFC,0xC0,0x3F} },

	{ 0XBD, 1, {0X00} },

	{ 0XB6, 2, {0X86,0X86} },
	
	{ 0XCC, 1, {0X04} },

	{ 0XE0, 54,{0x1C,0x33,0x3E,0x35,
				0x75,0x7B,0x85,0x7E,
				0x84,0x8B,0x93,0x97,
				0x9C,0xA1,0xA7,0xA8,
				0xAA,0xB1,0xB4,0xBC,
				0xAB,0xB9,0xBB,0x60,
				0x5E,0x68,0x77,0x1C,
				0x33,0x3E,0x35,0x75,
				0x7B,0x85,0x7E,0x84,
				0x8B,0x93,0x97,0x9C,
				0xA1,0xA7,0xA8,0xAA,
				0xB1,0xB4,0xBC,0xAB,
				0xB9,0xBB,0x60,0x5E,
				0x68,0x77} },

	{ 0xD0, 1, {0X39} },

	{ 0x11, 0, {} },
	{ REGFLAG_DELAY, 120, {} },


	

	{ 0x29, 0, {} },
	{ REGFLAG_DELAY, 10, {} },

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

	params->dsi.vertical_sync_active = 3;
	params->dsi.vertical_backporch = 4;
	params->dsi.vertical_frontporch = 9;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 40;
	params->dsi.horizontal_backporch = 90;
	params->dsi.horizontal_frontporch = 16;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 500;	//420
	params->dbi.te_hs_delay_cnt = 0x89;
}



static void lcm_init(void)
{	
	LCM_LOGI("[cp]lcm_init enter\n");
	SET_RESET_PIN(0);
	MDELAY(10);
	agold_lcm_power_on();
	MDELAY(50);
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

	//MDELAY(1500);
	LCM_LOGI("[cp]agold_lcm_power_down_later\n");
}

static unsigned int lcm_compare_id(void)
{
	int id = 0,id1 = 0,id2 = 0 ,id3 = 0;
	
	LCM_LOGI("[cp]lcm_compare_id\n");
	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);
	
	#ifdef BUILD_LK
	id1=mt_get_gpio_in(GPIO_LCD_ID1_PIN);
	id2=mt_get_gpio_in(GPIO_LCD_ID2_PIN);
	id3=mt_get_gpio_in(GPIO_LCD_ID3_PIN);	
	#else
	id1=gpio_get_value(GPIO_LCD_ID1_PIN);
	id2=gpio_get_value(GPIO_LCD_ID2_PIN);
	id3=gpio_get_value(GPIO_LCD_ID3_PIN);
	#endif
	
	id=(id1<<2)|(id2<<1)|(id3);	
	
	#ifdef BUILD_LK	
	LCM_LOGI("[cp]lk %s,lcm_id_index: = %d\n", __func__, id);
	#else	
	LCM_LOGI("[cp] %s,lcm_id_index: = %d\n", __func__, id);	
	#endif
	
	if(id==2)//7
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


LCM_DRIVER HX8399C_S99519_lcm_drv = {
	.name = "HX8399C_S99519",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
