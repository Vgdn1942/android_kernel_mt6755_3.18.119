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

static void init_lcm_registers(void)
{
	unsigned int data_array[16];

data_array[0] = 0x04b02300;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x81d62300;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x00072902;
data_array[1] = 0x000014b3;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);

data_array[0] = 0x00032902;
data_array[1] = 0x00000cb4;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x00032902;
data_array[1] = 0x00db4bb6;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x00232902;
data_array[1] = 0x006004c1;
data_array[2] = 0xc9f3983f;
data_array[3] = 0xffffff17;
data_array[4] = 0xb9ac635d;
data_array[5] = 0xe5ffffff;
data_array[6] = 0xf80c7f8f;
data_array[7] = 0x00000000;
data_array[8] = 0x02026a00;
data_array[9] = 0x00010022;
dsi_set_cmdq(data_array, 10, 1);

data_array[0] = 0x00092902;
data_array[1] = 0x80f731c2;
data_array[2] = 0x00000808;
data_array[3] = 0x00000008;
dsi_set_cmdq(data_array, 4, 1);

data_array[0] = 0x000c2902;
data_array[1] = 0x000070c4;
data_array[2] = 0x00000000;
data_array[3] = 0x06010000;
dsi_set_cmdq(data_array, 4, 1);

data_array[0] = 0x00162902;
data_array[1] = 0x7601c8c6;
data_array[2] = 0x00006a06;
data_array[3] = 0x00000000;
data_array[4] = 0x00000000;
data_array[5] = 0x1c0a0000;
data_array[6] = 0x0000c807;
dsi_set_cmdq(data_array, 7, 1);

data_array[0] = 0x00102902;
data_array[1] = 0x07e0aecb;
data_array[2] = 0x80010075;
data_array[3] = 0x00000000;
data_array[4] = 0x0000e000;
dsi_set_cmdq(data_array, 5, 1);

data_array[0] = 0x0ecc2300;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x001f2902;
data_array[1] = 0x110a00c7;
data_array[2] = 0x443a2b1c;
data_array[3] = 0x4f413853;
data_array[4] = 0x766f685e;
data_array[5] = 0x1c110a00;
data_array[6] = 0x53443a2b;
data_array[7] = 0x5e4f4138;
data_array[8] = 0x00766f68;
dsi_set_cmdq(data_array, 9, 1);

data_array[0] = 0x000b2902;
data_array[1] = 0x000011d0;
data_array[2] = 0x1940d454;
data_array[3] = 0x00000919;
dsi_set_cmdq(data_array, 4, 1);

data_array[0] = 0x00052902;
data_array[1] = 0x184004d1;
data_array[2] = 0x0000000f;
dsi_set_cmdq(data_array, 3, 1);

data_array[0] = 0x001b2902;
data_array[1] = 0xbb331bd3;
data_array[2] = 0x3333b3bb;
data_array[3] = 0x01003333;
data_array[4] = 0xa0d80000;
data_array[5] = 0x33434308;
data_array[6] = 0x8a127233;
data_array[7] = 0x00bc3d57;
dsi_set_cmdq(data_array, 8, 1);

data_array[0] = 0x00052902;
data_array[1] = 0x04411bd4;
data_array[2] = 0x00000000;
dsi_set_cmdq(data_array, 3, 1);

data_array[0] = 0x00082902;
data_array[1] = 0x000006d5;
data_array[2] = 0x39013901;
dsi_set_cmdq(data_array, 3, 1);

data_array[0] = 0x00361500;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x04b02300;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x05372300;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0xbf142300;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x00290500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(120);

data_array[0] = 0x00110500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(150);
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
	params->physical_width  = 68 ;
	params->physical_height = 121;

	params->dsi.mode = BURST_VDO_MODE;// SYNC_PULSE_VDO_MODE
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
	params->dsi.vertical_backporch = 6;
	params->dsi.vertical_frontporch = 9;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 40;
	params->dsi.horizontal_backporch = 90;
	params->dsi.horizontal_frontporch = 16;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 420;
	params->dbi.te_hs_delay_cnt = 0x89;
}



static void lcm_init(void)
{	
	agold_lcm_power_on();
	MDELAY(50);
	//SET_RESET_PIN(1);
	//MDELAY(100);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(120);
	
	init_lcm_registers();
	//push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{	
	//LCM_LOGI("[cp]lcm_resume enter\n");
	lcm_init();
}

static void lcm_suspend(void)
{	
	//push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	unsigned int data_array[16];
	
	data_array[0] = 0x00222300;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);//40
	
	data_array[0]=0x00280500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(30);//40

	data_array[0] = 0x04b02300;
	dsi_set_cmdq(data_array, 1, 1);
	
	data_array[0] = 0x001b2902;
	data_array[1] = 0xbb3313d3;
	data_array[2] = 0x3333b3b3;
	data_array[3] = 0x01003333;
	data_array[4] = 0xa0d80000;
	data_array[5] = 0x33373708;
	data_array[6] = 0x8a127233;
	data_array[7] = 0x00bc3d57;
	dsi_set_cmdq(data_array, 8, 1);
	MDELAY(200);//50
	
	data_array[0] = 0x00100500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(200);//50
	
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(120);
	
	agold_lcm_power_down();

}

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
	if(id==2)
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


LCM_DRIVER TDO_BD0546U71067_lcm_drv = {
	.name = "TDO_BD0546U71067",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
