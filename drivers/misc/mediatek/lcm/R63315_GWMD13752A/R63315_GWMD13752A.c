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


static struct LCM_setting_table init_setting[] = {
{0xB0, 1, {0x04}},
{0xD6, 1, {0x01}},
{0xB3, 6, {0x14, 0x00, 0x00, 0x00, 0x00, 0x00}},
{0xB6, 2, {0x3A, 0xc3}},
{0xC0, 1, {0x00}},
{0xC1, 34, {0x84, 0x60, 0x10, 0xEB, 0xFF, 0x6F, 0xCE, 0xFF, 0xFF, 0x17, 0x12, 0x58, 0x73, 0xAE, 0x31, 0x20, 0xC6, 0xFF, 0xFF, 0x1F, 			0xF3, 0xFF, 0x5F, 0x10, 0x10, 0x10, 0x10, 0x00, 0x62, 0x01, 0x22, 0x22, 0x00, 0x01}},
{0xC2, 7, {0x31, 0xf7, 0x80, 0x06, 0x08, 0x80, 0x00}},
{0xC4, 22, {0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 			0x0C, 0x06}},
{0xC6, 40, {0xC8, 0x08, 0x67, 0x08, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x18, 0x08, 			0xC8, 0x08, 0x67, 0x08, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x18, 0x08}},
{0xC7, 30, {0x00, 0x12, 0x1B, 0x24, 0x32, 0x3F, 0x49, 0x58, 0x3B, 0x42, 0x4D, 0x59, 0x63, 0x69, 0x70, 0x00, 0x12, 0x1B, 0x24, 0x32, 			0x3F, 0x49, 0x58, 0x3B, 0x42, 0x4D, 0x59, 0x63, 0x69, 0x70}},
{0xC8, 19, {0x01, 0x00, 0x00, 0x00, 0x00, 0xEC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00}},
{0xCB, 9, {0x31, 0xFC, 0x3F, 0x8C, 0x00, 0x00, 0x00, 0x00, 0xc0}},
{0xCC, 1, {0x0B}},
{0xD0, 10, {0x11, 0x81, 0xBB, 0x19, 0x99, 0x4C, 0x19, 0x19, 0x0C, 0x00}},

{0xD3, 25, {0x1B, 0x33, 0xBB, 0xBB, 0xB3, 0x33, 0x33, 0x33, 0x01, 0x01, 0x00, 0xA0, 0xD8, 0xA0, 0x0D, 0x48, 0x48, 0x44, 0x3B, 0x22, 			0x72, 0x07, 0x3D, 0xBF, 0x33}},

{0xD5, 7, {0x06, 0x00, 0x00, 0x01, 0x43, 0x01, 0x43}},

{0xDD, 2, {0x31, 0X93}},
{0xDE, 4, {0x00, 0x3F, 0xFF, 0x10}},

{0x36, 1, {0x00}},
{0x3A, 1, {0x77}},

{0x29, 0,{0x00}},
{REGFLAG_DELAY, 20, {}},
{0x11, 0,{0x00}},
{REGFLAG_DELAY, 120, {}},
//{REGFLAG_END_OF_TABLE, 0x00, {}}	
};




static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;
	unsigned cmd;

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
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

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

	params->dsi.vertical_sync_active = 2;
	params->dsi.vertical_backporch = 5;
	params->dsi.vertical_frontporch = 14;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 10;
	params->dsi.horizontal_backporch = 20;
	params->dsi.horizontal_frontporch = 40;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 400;
}



static void lcm_init(void)
{
	LCM_LOGI("lcm_init enter\n");
	agold_lcm_power_on();
	
	#ifdef BUILD_LK
	lcm_util.set_gpio_mode(GPIO_LCD_PWR_SWITCH_PIN, 0);
	lcm_util.set_gpio_dir(GPIO_LCD_PWR_SWITCH_PIN, 1); 
	lcm_util.set_gpio_pull_enable(GPIO_LCD_PWR_SWITCH_PIN, 0); 
	SET_GPIO_OUT(GPIO_LCD_PWR_SWITCH_PIN, 1);
	MDELAY(5);
	#else
	gpio_set_value(GPIO_LCD_PWR_SWITCH_PIN, 1);
	#endif

	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(5);
	SET_RESET_PIN(1);
	MDELAY(10);
	push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{
	LCM_LOGI("lcm_resume enter\n");
	lcm_init();
}

static void lcm_suspend(void)
{
	LCM_LOGI("lcm_suspend enter\n");

	MDELAY(15);
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(10);
	
	agold_lcm_power_down();
	
	#ifdef BUILD_LK
	lcm_util.set_gpio_mode(GPIO_LCD_PWR_SWITCH_PIN, 0);
	lcm_util.set_gpio_dir(GPIO_LCD_PWR_SWITCH_PIN, 1); 
	lcm_util.set_gpio_pull_enable(GPIO_LCD_PWR_SWITCH_PIN, 0); 
	SET_GPIO_OUT(GPIO_LCD_PWR_SWITCH_PIN, 0);
	MDELAY(15);
	#else
	gpio_set_value(GPIO_LCD_PWR_SWITCH_PIN, 0);
	#endif
}

extern int lcm_id_index(int b);
static unsigned int lcm_compare_id(void)
{
	int id = 0;
	int b = 0;
	//unsigned char buffer[2];
	//unsigned int array[16];
	LCM_LOGI("[cp]lcm_compare_id\n");
	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);
	id=lcm_id_index(b);
	#ifdef BUILD_LK	
	LCM_LOGI("[cp]lk %s,lcm_id_index: = %d\n", __func__, id);
	#else
	LCM_LOGI("[cp] %s,lcm_id_index: = %d\n", __func__, id);
	#endif
	if(id==0)
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
	LCM_LOGI("lcm_init_power enter\n");
}


LCM_DRIVER R63315_GWMD13752A_lcm_drv = {
	.name = "R63315_GWMD13752A",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
