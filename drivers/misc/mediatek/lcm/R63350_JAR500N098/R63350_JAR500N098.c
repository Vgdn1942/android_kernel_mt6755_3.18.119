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

static const unsigned int BL_MIN_LEVEL = 20;
static LCM_UTIL_FUNCS lcm_util;
extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);
#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
extern int lcm_i2c_set_vol_value(int vop_value, int von_value);
extern int lcm_i2c_bias_en(int enable);
#endif

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
#define FRAME_WIDTH				(1080)
#define FRAME_HEIGHT			(1920)


#define REGFLAG_DELAY			0xFFFC
#define REGFLAG_UDELAY			0xFFFB
#define REGFLAG_END_OF_TABLE	0xFFFD
#define REGFLAG_RESET_LOW		0xFFFE
#define REGFLAG_RESET_HIGH		0xFFFF



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

	{0xB0,1,{0x04}},

{0xD6,1,{0x01}},

{0xB3,6,{0x14,0x00,0x00,0x00,0x00,0x00}},

{0xB4,2,{0x0C,0x00}},

{0xB6,3,{0x4B,0xCB,0x00}},

{0xC1,34,{0x04,0x60,0x00,0x20,0x29,0x41,0x22,0xFB,0xF0,0xFF,0xFF,0x9B,0x7B,0xCF,0xB5,0xFF,0xFF,0x87,0x8C,0xC5,0x11,0x54,0x02,0x00,0x00,0x00,0x00,0x00,0x22,0x11,0x02,0x21,0x00,0xFF,0x11}},

{0xC2,8,{0x31,0xF7,0x80,0x08,0x08,0x00,0x00,0x08}},

{0xC4,11,{0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04}},

{0xC6,21,{0xC8,0x3C,0x3C,0x07,0x01,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x1A,0x07,0xC8}},

{0xC7,30,{0x0A,0x1C,0x24,0x2C,0x3A,0x48,0x51,0x5F,0x43,0x4A,0x54,0x60,0x68,0x6E,0x7C,0x00,0x16,0x1D,0x28,0x36,0x44,0x4F,0x5F,0x43,0x4A,0x56,0x62,0x6A,0x70,0x7C}},

{0xCB,15,{0x7F,0xE1,0x87,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00}},

{0xCC,1,{0x32}},

{0xD0,10,{0x11,0x00,0x00,0x56,0xD7,0x40,0x19,0x19,0x09,0x00}},

{0xD1,4,{0x04,0x40,0x0A,0x0F}},

{0xD3,26,{0x1B,0x33,0xBB,0xBB,0xB3,0x33,0x33,0x33,0x33,0x00,0x01,0x00,0x00,0xD8,0xA0,0x0C,0x3F,0x3F,0x33,0x33,0x72,0x12,0x8A,0x57,0x3D,0xBC}},

{0xD5,7,{0x06,0x00,0x00,0x01,0x3B,0x01,0x3B}},
{REGFLAG_DELAY, 10, {}},
{0xDE,1,{0x00}},

	{0x29,0,{0x00}},
	{REGFLAG_DELAY, 120, {}},
	{0x11,0,{0x00}},
	{REGFLAG_DELAY, 120, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
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

	/* Highly depends on LCD driver capability. */
	params->dsi.packet_size = 256;
	/* video mode timing */

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active = 3;
	params->dsi.vertical_backporch = 6;
	params->dsi.vertical_frontporch = 9;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 40;
	params->dsi.horizontal_backporch = 90;
	params->dsi.horizontal_frontporch = 16;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 420;
}

static void lcm_init(void)
{	
	LCM_LOGI("lcm_init enter\n");
#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_set_vol_value(5000, 5000);
	lcm_i2c_bias_en(1);
#endif	
	
	MDELAY(15);
	SET_RESET_PIN(1);
	MDELAY(20);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(120);
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
	MDELAY(150);
	
	#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_bias_en(0);
	#endif

	MDELAY(10);
		
}

static void lcm_init_power(void)
{
	LCM_LOGI("lcm_init_power enter\n");
}


LCM_DRIVER R63350_JAR500N098_lcm_drv = {
	.name = "R63350_JAR500N098",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.init_power = lcm_init_power,

};
