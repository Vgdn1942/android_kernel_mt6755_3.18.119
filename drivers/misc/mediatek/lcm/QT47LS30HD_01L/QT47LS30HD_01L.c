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
extern int lcm_id_index(int b);

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
#define FRAME_WIDTH				(720)
#define FRAME_HEIGHT			(1280)


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


{0xE1,1,{0xA3}},

{0xB3,1,{0x00}},

{0xB6,4,{0x16,0x0F,0x00,0x77}},


{0xB8,8,{0x00,0x0A,0x0B,0x00,0x0B,0x0D,0x11,0x04}},

{0xB9,6,{0x04,0x08,0x11,0xFF,0xFF,0x0F}},

{0xBA,8,{0x0E,0x0E,0x10,0x10,0x12,0x12,0x14,0x14}},

{0xBB,8,{0xA1,0xA1,0xA1,0xA1,0xA0,0xA0,0xA0,0xA0}},

{0xBC,8,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0xBD,8,{0x0F,0x0F,0x11,0x11,0x13,0x13,0x15,0x15}},

{0xBe,8,{0xA1,0xA1,0xA1,0xA1,0xA0,0xA0,0xA0,0xA0}},

{0xBF,8,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0xB1,3,{0x16,0x1E,0x12}},

{0xE0,5,{0x01,0x03,0x02,0x00,0x01}},


//gamma2.2
{0xD0,6,{0x00,0x00,0x05,0x03,0x08,0x13}},

{0xD1,5,{0x0D,0x3F,0x35,0x23,0x05}},

{0xD2,6,{0x00,0x00,0x05,0x03,0x08,0x13}},

{0xD3,5,{0x0D,0x3F,0x35,0x23,0x05}},

{0xD4,6,{0x00,0x00,0x05,0x03,0x08,0x13}},

{0xD5,5,{0x0D,0x3F,0x35,0x23,0x05}},

{0xD6,6,{0x00,0x00,0x05,0x03,0x08,0x13}},

{0xD7,5,{0x0D,0x3F,0x35,0x23,0x05}},

{0xD8,6,{0x00,0x00,0x05,0x03,0x08,0x13}},

{0xD9,5,{0x0D,0x3F,0x35,0x23,0x05}},

{0xDA,6,{0x00,0x00,0x05,0x03,0x08,0x13}},

{0xDB,5,{0x0D,0x3F,0x35,0x23,0x05}},

{0x70,4,{0xD8,0x00,0xFF,0x80}},

{0xFF,1,{0x01}},

{0xC6,2,{0x88,0x33}},

{0xDE,2,{0x9D,0x30}},

{0x14,1,{0x00}},

{0xE9,1,{0x07}},

{0xED,2,{0x60,0x10}},

{0xEC,1,{0x12}},

{0xCD,4,{0x77,0x7B,0x34,0x08}},

{0xC3,7,{0x03,0x0D,0x34,0x05,0x01,0x44,0x54}},

{0xC4,5,{0x02,0x03,0x35,0x3D,0x53}},//48

{0xCB,3,{0xBF,0x80,0x00}},

{0xEA,2,{0x15,0x28}},

{0xF0,4,{0x38,0x00,0x00,0x00}},

{0xC9,3,{0x60,0x00,0x82}},

{0xb5,8,{0x00,0x05,0x05,0x1e,0x04,0x40,0x20,0xfc}},

{0x36,1,{0x02}},	

{0xf0,4,{0x18,0xff,0xff,0x00}},
{0x11, 1, {0x00}},
{REGFLAG_DELAY, 120, {}},

{0x29, 1, {0x00}},
{REGFLAG_DELAY, 50, {}},

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

			params->dsi.vertical_sync_active				= 4;// 3    2
		params->dsi.vertical_backporch					= 1;// 20   1
		params->dsi.vertical_frontporch					= 40; // 1  12
		params->dsi.vertical_active_line				= FRAME_HEIGHT;

		params->dsi.horizontal_sync_active				= 4;// 50  2
		params->dsi.horizontal_backporch				= 100;
		params->dsi.horizontal_frontporch				= 100;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		params->dsi.PLL_CLOCK=240;//210
}

static void lcm_init(void)
{	
	LCM_LOGI("lcm_init enter\n");
	agold_lcm_power_on();
	MDELAY(100);
	SET_RESET_PIN(1);
	MDELAY(20);
	SET_RESET_PIN(0);
	MDELAY(60);
	SET_RESET_PIN(1);
	MDELAY(150);
	push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{
	LCM_LOGI("lcm_resume enter\n");
	init_setting[35].para_list[4]-=0x02;
	lcm_init();
}

static void lcm_suspend(void)
{
	LCM_LOGI("lcm_suspend enter\n");

	MDELAY(15);
	SET_RESET_PIN(1);
	MDELAY(20);
	SET_RESET_PIN(0);
	MDELAY(60);
	SET_RESET_PIN(1);
	MDELAY(150);
	agold_lcm_power_down();
		
}

static void lcm_init_power(void)
{
	LCM_LOGI("lcm_init_power enter\n");
}
/*
static unsigned int lcm_compare_id(void)
{
	int ver = -1;
	ver = lcm_id_index(0);
	#ifdef BUILD_LK
		printf("%s, LK NT35596 id = %d\n", __func__, ver);
	#else
		printk("%s, kernel NT35596 id = %d\n", __func__, ver);
	#endif
	if (6 == ver)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
*/
LCM_DRIVER QT47LS30HD_01L_lcm_drv = {
	.name = "QT47LS30HD_01L",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	//.compare_id	= lcm_compare_id,
	.init_power = lcm_init_power,

};
