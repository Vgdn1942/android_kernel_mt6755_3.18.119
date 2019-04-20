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

	data_array[0] = 0x00043902;
data_array[1] = 0x9983ffb9;
dsi_set_cmdq(data_array, 2, 1);
data_array[0] = 0x00103902;
data_array[1] = 0x6c0402b1;
data_array[2] = 0x3332018c;
data_array[3] = 0x685e1111;
data_array[4] = 0x02027356;
dsi_set_cmdq(data_array, 5, 1);
data_array[0] = 0x000C3902;
data_array[1] = 0x808000b2;
data_array[2] = 0x5a0705ae;
data_array[3] = 0x00101011;
dsi_set_cmdq(data_array, 4, 1);
data_array[0] = 0x002e3902;
data_array[1] = 0x009804b4;
data_array[2] = 0x00a000a0;
data_array[3] = 0x00000800;
data_array[4] = 0x02240002;
data_array[5] = 0x06330c04;
data_array[6] = 0x96080000;
data_array[7] = 0x00a00088;
data_array[8] = 0x080000a0;
data_array[9] = 0x00020000;
data_array[10] = 0x0c040228;
data_array[11] = 0xa4040000;
data_array[12] = 0x00000008;
dsi_set_cmdq(data_array, 13, 1);
data_array[0] = 0x00223902;
data_array[1] = 0x000000d3;
data_array[2] = 0x06000000;
data_array[3] = 0x05103200;
data_array[4] = 0x00000500;
data_array[5] = 0x00000000;
data_array[6] = 0x00000000;
data_array[7] = 0x05050001;
data_array[8] = 0x00000003;
data_array[9] = 0x00004005;
dsi_set_cmdq(data_array, 10, 1);
data_array[0] = 0x00213902;
data_array[1] = 0x001818d5;
data_array[2] = 0x00000000;
data_array[3] = 0x18191900;
data_array[4] = 0x00000018;
data_array[5] = 0x00000000;
data_array[6] = 0x03000100;
data_array[7] = 0x2f212002;
data_array[8] = 0x3130302f;
data_array[9] = 0x00000031;
dsi_set_cmdq(data_array, 10, 1);
data_array[0] = 0x00213902;
data_array[1] = 0x401818d6;
data_array[2] = 0x40404040;
data_array[3] = 0x19181840;
data_array[4] = 0x40404019;
data_array[5] = 0x40404040;
data_array[6] = 0x00030240;
data_array[7] = 0x2f202101;
data_array[8] = 0x3130302f;
data_array[9] = 0x00000031;
dsi_set_cmdq(data_array, 10, 1);
data_array[0] = 0x00113902;
data_array[1] = 0x000000d8;
data_array[2] = 0x00000000;
data_array[3] = 0x00000000;
data_array[4] = 0x00000000;
data_array[5] = 0x00000000;
dsi_set_cmdq(data_array, 6, 1);
data_array[0] = 0x01bd1500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00113902;
data_array[1] = 0x000000d8;
data_array[2] = 0x00000000;
data_array[3] = 0x00000000;
data_array[4] = 0x00000000;
data_array[5] = 0x00000000;
dsi_set_cmdq(data_array, 6, 1);
data_array[0] = 0x02bd1500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00093902;
data_array[1] = 0x0a00c0d8;
data_array[2] = 0x0a00c0bf;
data_array[3] = 0x000000bf;
dsi_set_cmdq(data_array, 4, 1);
data_array[0] = 0x00bd1500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00373902;
data_array[1] = 0x1c1101e0;
data_array[2] = 0x4d413517;
data_array[3] = 0x645c5249;
data_array[4] = 0x7f78716b;
data_array[5] = 0x8e8f8683;
data_array[6] = 0x9c958a97;
data_array[7] = 0x65594f50;
data_array[8] = 0x171c1101;
data_array[9] = 0x494d4135;
data_array[10] = 0x6b645c52;
data_array[11] = 0x827f7870;
data_array[12] = 0x968f8e86;
data_array[13] = 0x519b9688;
data_array[14] = 0x00655a4e;
dsi_set_cmdq(data_array, 15, 1);
data_array[0] = 0x00033902;
data_array[1] = 0x009595b6;//8c8c
dsi_set_cmdq(data_array, 2, 1);
data_array[0] = 0x08cc1500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0xaad21500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00110500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(120);
data_array[0] = 0x00290500;
dsi_set_cmdq(data_array, 1, 1);
MDELAY(10);
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
	params->dsi.PLL_CLOCK = 420;
	params->dbi.te_hs_delay_cnt = 0x89;
}



static void lcm_init(void)
{	
	SET_RESET_PIN(0);
	MDELAY(10);
	agold_lcm_power_on();
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(20);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(100);
	
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

	data_array[0]=0x00280500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(30);//40

	data_array[0] = 0x00100500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(100);//50

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
	if(id==7)
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


LCM_DRIVER HX8399_C_CSHMDS11487QR_lcm_drv = {
	.name = "HX8399_C_CSHMDS11487QR",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
