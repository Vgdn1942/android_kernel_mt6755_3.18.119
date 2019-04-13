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

extern int lcm_power_on(void);
extern int lcm_power_down(void);

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
#define FRAME_WIDTH										(720)
#define FRAME_HEIGHT									(1280)


#define LCM_IC_ID 0x9881

#define REGFLAG_DELAY		0x1FE
#define REGFLAG_UDELAY	0x1FD
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

	{0xFF,	3,	{0x98,0x81,0x03}},

{0x01,	1,	{0x08}},

{0x02,	1,	{0x00}},

{0x03,	1,	{0x73}},

{0x04,	1,	{0x73}},

{0x05,	1,	{0x14}},

{0x06,	1,	{0x06}},

{0x07,	1,	{0x02}},

{0x08,	1,	{0x05}},

{0x09,	1,	{0x00}},

{0x0a,	1,	{0x0c}},

{0x0b,	1,	{0x00}},

{0x0c,	1,	{0x1c}},

{0x0d,	1,	{0x1c}},

{0x0e,	1,	{0x00}},

{0x0f,	1,	{0x0c}},

{0x10,	1,	{0x0c}},

{0x11,	1,	{0x01}},

{0x12,	1,	{0x01}},

{0x13,	1,	{0x1b}},

{0x14,	1,	{0x0b}},

{0x15,	1,	{0x00}},

{0x16,	1,	{0x00}},

{0x17,	1,	{0x00}},

{0x18,	1,	{0x00}},

{0x19,	1,	{0x00}},

{0x1a,	1,	{0x00}},

{0x1b,	1,	{0x00}},

{0x1c,	1,	{0x00}},

{0x1d,	1,	{0x00}},

{0x1e,	1,	{0xC8}},

{0x1f,	1,	{0x80}},

{0x20,	1,	{0x02}},

{0x21,	1,	{0x00}},

{0x22,	1,	{0x02}},

{0x23,	1,	{0x00}},

{0x24,	1,	{0x00}},

{0x25,	1,	{0x00}},

{0x26,	1,	{0x00}},

{0x27,	1,	{0x00}},

{0x28,	1,	{0xFB}},

{0x29,	1,	{0x43}},

{0x2a,	1,	{0x00}},

{0x2b,	1,	{0x00}},

{0x2c,	1,	{0x07}},

{0x2d,	1,	{0x07}},

{0x2e,	1,	{0xFF}},

{0x2f,	1,	{0xFF}},

{0x30,	1,	{0x11}},

{0x31,	1,	{0x00}},

{0x32,	1,	{0x00}},

{0x33,	1,	{0x00}},

{0x34,	1,	{0x84}},

{0x35,	1,	{0x80}},

{0x36,	1,	{0x07}},

{0x37,	1,	{0x00}},

{0x38,	1,	{0x00}},

{0x39,	1,	{0x00}},

{0x3a,	1,	{0x00}},

{0x3b,	1,	{0x00}},

{0x3c,	1,	{0x00}},

{0x3d,	1,	{0x00}},

{0x3e,	1,	{0x00}},

{0x3f,	1,	{0x00}},

{0x40,	1,	{0x88}},

{0x41,	1,	{0x88}},

{0x42,	1,	{0x00}},

{0x43,	1,	{0x80}},

{0x44,	1,	{0x08}},

{0x50,	1,	{0x01}},

{0x51,	1,	{0x23}},

{0x52,	1,	{0x45}},

{0x53,	1,	{0x67}},

{0x54,	1,	{0x89}},

{0x55,	1,	{0xAB}},

{0x56,	1,	{0x01}},

{0x57,	1,	{0x23}},

{0x58,	1,	{0x45}},

{0x59,	1,	{0x67}},

{0x5a,	1,	{0x89}},

{0x5b,	1,	{0xAB}},

{0x5c,	1,	{0xCD}},

{0x5d,	1,	{0xEF}},

{0x5e,	1,	{0x10}},

{0x5f,	1,	{0x02}},

{0x60,	1,	{0x02}},

{0x61,	1,	{0x02}},

{0x62,	1,	{0x02}},

{0x63,	1,	{0x02}},

{0x64,	1,	{0x02}},

{0x65,	1,	{0x02}},

{0x66,	1,	{0x08}},

{0x67,	1,	{0x09}},

{0x68,	1,	{0x02}},

{0x69,	1,	{0x10}},

{0x6a,	1,	{0x12}},

{0x6b,	1,	{0x11}},

{0x6c,	1,	{0x13}},

{0x6d,	1,	{0x0C}},

{0x6e,	1,	{0x0E}},

{0x6f,	1,	{0x0D}},

{0x70,	1,	{0x0F}},

{0x71,	1,	{0x06}},

{0x72,	1,	{0x07}},

{0x73,	1,	{0x02}},

{0x74,	1,	{0x02}},

{0x75,	1,	{0x02}},

{0x76,	1,	{0x02}},

{0x77,	1,	{0x02}},

{0x78,	1,	{0x02}},

{0x79,	1,	{0x02}},

{0x7a,	1,	{0x02}},

{0x7b,	1,	{0x02}},

{0x7c,	1,	{0x07}},

{0x7d,	1,	{0x06}},

{0x7e,	1,	{0x02}},

{0x7f,	1,	{0x11}},

{0x80,	1,	{0x13}},

{0x81,	1,	{0x10}},

{0x82,	1,	{0x12}},

{0x83,	1,	{0x0F}},

{0x84,	1,	{0x0D}},

{0x85,	1,	{0x0E}},

{0x86,	1,	{0x0C}},

{0x87,	1,	{0x09}},

{0x88,	1,	{0x08}},

{0x89,	1,	{0x02}},

{0x8a,	1,	{0x02}},

{0xFF,	3,	{0x98,0x81,0x04}},

{0x6C,	1,	{0x15}},

{0x6E,	1,	{0x2A}},

{0x6F,	1,	{0x35}},

{0x3A,	1,	{0xA4}},

{0x8D,	1,	{0x1A}},

{0x87,	1,	{0xBA}},

{0x26,	1,	{0x76}},

{0xB2,	1,	{0xD1}},

{0x69,	1,	{0x57}},


{0x33,	1,	{0x44}},

{0x88,	1,	{0x0b}},
{0xFF,	3,	{0x98,0x81,0x01}},

{0x22,	1,	{0x0A}},

{0x31,	1,	{0x00}},

{0x53,	1,	{0x77}},//75

{0x55,	1,	{0x8f}},//8f

{0x50,	1,	{0x96}},

{0x51,	1,	{0x96}},

{0x60,	1,	{0x14}},

//{0xB6,	1,	{0x0A}},

{0xA0,	1,	{0x1f}},

{0xA1,	1,	{0x3a}},

{0xA2,	1,	{0x4a}},

{0xA3,	1,	{0x15}},

{0xA4,	1,	{0x19}},

{0xA5,	1,	{0x2d}},

{0xA6,	1,	{0x22}},

{0xA7,	1,	{0x23}},

{0xA8,	1,	{0xbb}},

{0xA9,	1,	{0x20}},

{0xAA,	1,	{0x2b}},

{0xAB,	1,	{0x9d}},

{0xAC,	1,	{0x1B}},

{0xAD,	1,	{0x1A}},

{0xAE,	1,	{0x4e}},

{0xAF,	1,	{0x23}},

{0xB0,	1,	{0x29}},

{0xB1,	1,	{0x59}},

{0xB2,	1,	{0x65}},

{0xB3,	1,	{0x39}},

{0xC0,	1,	{0x00}},

{0xC1,	1,	{0x3a}},

{0xC2,	1,	{0x4a}},

{0xC3,	1,	{0x15}},

{0xC4,	1,	{0x19}},

{0xC5,	1,	{0x2d}},

{0xC6,	1,	{0x22}},

{0xC7,	1,	{0x23}},

{0xC8,	1,	{0xba}},

{0xC9,	1,	{0x20}},

{0xCA,	1,	{0x2b}},

{0xCB,	1,	{0x9d}},

{0xCC,	1,	{0x1b}},

{0xCD,	1,	{0x1b}},

{0xCE,	1,	{0x4f}},

{0xCF,	1,	{0x23}},

{0xD0,	1,	{0x28}},

{0xD1,	1,	{0x5a}},

{0xD2,	1,	{0x65}},

{0xD3,	1,	{0x39}},

{0xFF,	3,	{0x98,0x81,0x00}},

{0x35,	1,	{0x00}},


{0x11,	0,	{0x00}},

{REGFLAG_DELAY, 120, {}},



{0x29,	0,	{0x00}},



{REGFLAG_DELAY, 50, {}},

{REGFLAG_END_OF_TABLE, 0x00, {}}

};


static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {

    // Display off sequence
    {0x28, 1, {0x00}},
    {REGFLAG_DELAY, 20, {}},
    // Sleep Mode On
    {0x10, 1, {0x00}},
    {REGFLAG_DELAY, 120, {}},

    {REGFLAG_END_OF_TABLE, 0x00, {}}
};


static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;
	unsigned cmd;

	LCM_LOGI("static void push_table\n");
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
	LCM_LOGI("lcm_get_params\n");
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;
	params->physical_width  = 58 ;
	params->physical_height = 103;

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

	params->dsi.vertical_sync_active				= 8; //8;	//2;
	params->dsi.vertical_backporch					= 24; //18;	//14;
	params->dsi.vertical_frontporch					= 16; //20;	//16;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active				= 10;	//2;
	params->dsi.horizontal_backporch = 60;
	params->dsi.horizontal_frontporch = 60;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;


	params->dsi.HS_TRAIL = 20;
	params->dsi.PLL_CLOCK = 220;//208;


	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 1;
	params->dsi.lcm_esd_check_table[0].cmd          = 0x0a;
	params->dsi.lcm_esd_check_table[0].count        = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9C;
}

static void lcm_init(void)
{
	LCM_LOGI("[cp]lcm_init enter\n");
	SET_RESET_PIN(0);
	MDELAY(10);
	lcm_power_on();
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(120);

	push_table(lcm_initialization_setting,
		   sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);

}

static void lcm_resume(void)
{
	lcm_init();
}

static void lcm_suspend(void)
{
	LCM_LOGI("[cp]lcm_power_down_later\n");

	push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);

	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);

	lcm_power_down();
}

static unsigned int lcm_compare_id(void)
{
	unsigned int id1 = 0;
	unsigned int id2 = 0;
	unsigned int id3 = 0;

	LCM_LOGI("[Jason]lcm_compare_id\n");
#if defined(BUILD_LK)
	LCM_LOGI("[Jason]lk read id\n");
	id1 = mt_get_gpio_in(GPIO_LCD_ID1_PIN);
	id2 = mt_get_gpio_in(GPIO_LCD_ID2_PIN);
	id3 = mt_get_gpio_in(GPIO_LCD_ID3_PIN);

	printf("[Jason]ili9881c 0x%x\n",id1);
	printf("[Jason]ili9881c 0x%x\n",id2);
	printf("[Jason]ili9881c 0x%x\n",id3);
#else
	LCM_LOGI("ili9881c 0x%x\n",id1);
#endif

	if((id1 == 0) && (id2 == 1) && (id3 == 1))
		return 1;
	else
		return 0;

}


static void lcm_init_power(void)
{
	LCM_LOGI("lcm_init_power enter\n");
}


LCM_DRIVER ILI988IC_S047HAB003_A00_lcm_drv = {
	.name = "ILI988IC_S047HAB003_A00",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
