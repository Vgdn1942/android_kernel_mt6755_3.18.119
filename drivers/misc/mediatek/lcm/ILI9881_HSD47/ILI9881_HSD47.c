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


static void ILI9881_DCS_write_1A_1P(unsigned char cmd, unsigned char para)
{
  unsigned int data_array[16];
  data_array[0] =(0x00001500| (para<<24)|(cmd<<16));
  dsi_set_cmdq(data_array, 1, 1);

}

static void init_lcm_registers(void)
{
unsigned int data_array[16];
data_array[0] = 0x00042902;
data_array[1] = 0x038198FF;
dsi_set_cmdq(data_array, 2, 1);
ILI9881_DCS_write_1A_1P(0x01,0x00),
ILI9881_DCS_write_1A_1P(0x02,0x00),
ILI9881_DCS_write_1A_1P(0x03,0x72),
ILI9881_DCS_write_1A_1P(0x04,0x00),
ILI9881_DCS_write_1A_1P(0x05,0x00),
ILI9881_DCS_write_1A_1P(0x06,0x09),
ILI9881_DCS_write_1A_1P(0x07,0x00),
ILI9881_DCS_write_1A_1P(0x08,0x00),
ILI9881_DCS_write_1A_1P(0x09,0x01),
ILI9881_DCS_write_1A_1P(0x0a,0x00),
ILI9881_DCS_write_1A_1P(0x0b,0x00),
ILI9881_DCS_write_1A_1P(0x0c,0x01),
ILI9881_DCS_write_1A_1P(0x0d,0x00),
ILI9881_DCS_write_1A_1P(0x0e,0x00),
ILI9881_DCS_write_1A_1P(0x0f,0x00),
ILI9881_DCS_write_1A_1P(0x10,0x00),
ILI9881_DCS_write_1A_1P(0x11,0x00),
ILI9881_DCS_write_1A_1P(0x12,0x00),
ILI9881_DCS_write_1A_1P(0x13,0x00),
ILI9881_DCS_write_1A_1P(0x14,0x00),
ILI9881_DCS_write_1A_1P(0x15,0x00),
ILI9881_DCS_write_1A_1P(0x16,0x00),
ILI9881_DCS_write_1A_1P(0x17,0x00),
ILI9881_DCS_write_1A_1P(0x18,0x00),
ILI9881_DCS_write_1A_1P(0x19,0x00),
ILI9881_DCS_write_1A_1P(0x1a,0x00),
ILI9881_DCS_write_1A_1P(0x1b,0x00),
ILI9881_DCS_write_1A_1P(0x1c,0x00),
ILI9881_DCS_write_1A_1P(0x1d,0x00),
ILI9881_DCS_write_1A_1P(0x1e,0x40),
ILI9881_DCS_write_1A_1P(0x1f,0x80),
ILI9881_DCS_write_1A_1P(0x20,0x05),

ILI9881_DCS_write_1A_1P(0x21,0x02),
ILI9881_DCS_write_1A_1P(0x22,0x00),
ILI9881_DCS_write_1A_1P(0x23,0x00),
ILI9881_DCS_write_1A_1P(0x24,0x00),
ILI9881_DCS_write_1A_1P(0x25,0x00),
ILI9881_DCS_write_1A_1P(0x26,0x00),
ILI9881_DCS_write_1A_1P(0x27,0x00),
ILI9881_DCS_write_1A_1P(0x28,0x33),
ILI9881_DCS_write_1A_1P(0x29,0x02),
ILI9881_DCS_write_1A_1P(0x2a,0x00),
ILI9881_DCS_write_1A_1P(0x2b,0x00),

ILI9881_DCS_write_1A_1P(0x2b,0x00),
ILI9881_DCS_write_1A_1P(0x2c,0x00),
ILI9881_DCS_write_1A_1P(0x2d,0x00),
ILI9881_DCS_write_1A_1P(0x2e,0x00),
ILI9881_DCS_write_1A_1P(0x2f,0x00),
ILI9881_DCS_write_1A_1P(0x30,0x00),
ILI9881_DCS_write_1A_1P(0x31,0x00),
ILI9881_DCS_write_1A_1P(0x32,0x00),
ILI9881_DCS_write_1A_1P(0x33,0x00),
ILI9881_DCS_write_1A_1P(0x34,0x04),
ILI9881_DCS_write_1A_1P(0x35,0x00),
ILI9881_DCS_write_1A_1P(0x36,0x00),
ILI9881_DCS_write_1A_1P(0x37,0x00),
ILI9881_DCS_write_1A_1P(0x38,0x3C),
ILI9881_DCS_write_1A_1P(0x39,0x00),
ILI9881_DCS_write_1A_1P(0x3a,0x40),



ILI9881_DCS_write_1A_1P(0x3b,0x40),
ILI9881_DCS_write_1A_1P(0x3c,0x00),
ILI9881_DCS_write_1A_1P(0x3d,0x00),
ILI9881_DCS_write_1A_1P(0x3e,0x00),
ILI9881_DCS_write_1A_1P(0x3f,0x00),
ILI9881_DCS_write_1A_1P(0x40,0x00),
ILI9881_DCS_write_1A_1P(0x41,0x00),
ILI9881_DCS_write_1A_1P(0x42,0x00),
ILI9881_DCS_write_1A_1P(0x43,0x00),
ILI9881_DCS_write_1A_1P(0x44,0x00),
ILI9881_DCS_write_1A_1P(0x50,0x01),
ILI9881_DCS_write_1A_1P(0x51,0x23),
ILI9881_DCS_write_1A_1P(0x52,0x45),
ILI9881_DCS_write_1A_1P(0x53,0x67),
ILI9881_DCS_write_1A_1P(0x54,0x89),
ILI9881_DCS_write_1A_1P(0x55,0xab),
ILI9881_DCS_write_1A_1P(0x56,0x01),
ILI9881_DCS_write_1A_1P(0x57,0x23),
ILI9881_DCS_write_1A_1P(0x58,0x45),
ILI9881_DCS_write_1A_1P(0x59,0x67),
ILI9881_DCS_write_1A_1P(0x5a,0x89),
ILI9881_DCS_write_1A_1P(0x5b,0xab),
ILI9881_DCS_write_1A_1P(0x5c,0xcd),
ILI9881_DCS_write_1A_1P(0x5d,0xef),
ILI9881_DCS_write_1A_1P(0x5e,0x11),

ILI9881_DCS_write_1A_1P(0x5f,0x01),
ILI9881_DCS_write_1A_1P(0x60,0x00),
ILI9881_DCS_write_1A_1P(0x61,0x15),
ILI9881_DCS_write_1A_1P(0x62,0x14),
ILI9881_DCS_write_1A_1P(0x63,0x0E),
ILI9881_DCS_write_1A_1P(0x64,0x0F),
ILI9881_DCS_write_1A_1P(0x65,0x0C),
ILI9881_DCS_write_1A_1P(0x66,0x0D),
ILI9881_DCS_write_1A_1P(0x67,0x06),
ILI9881_DCS_write_1A_1P(0x68,0x02),
ILI9881_DCS_write_1A_1P(0x69,0x02),
ILI9881_DCS_write_1A_1P(0x6a,0x02),
ILI9881_DCS_write_1A_1P(0x6b,0x02),
ILI9881_DCS_write_1A_1P(0x6c,0x02),
ILI9881_DCS_write_1A_1P(0x6d,0x02),
ILI9881_DCS_write_1A_1P(0x6e,0x07),
ILI9881_DCS_write_1A_1P(0x6f,0x02),
ILI9881_DCS_write_1A_1P(0x70,0x02),
ILI9881_DCS_write_1A_1P(0x71,0x02),
ILI9881_DCS_write_1A_1P(0x72,0x02),
ILI9881_DCS_write_1A_1P(0x73,0x02),
ILI9881_DCS_write_1A_1P(0x74,0x02),
ILI9881_DCS_write_1A_1P(0x75,0x01),
ILI9881_DCS_write_1A_1P(0x76,0x00),
ILI9881_DCS_write_1A_1P(0x77,0x14),
ILI9881_DCS_write_1A_1P(0x78,0x15),
ILI9881_DCS_write_1A_1P(0x79,0x0E),
ILI9881_DCS_write_1A_1P(0x7a,0x0F),
ILI9881_DCS_write_1A_1P(0x7b,0x0C),
ILI9881_DCS_write_1A_1P(0x7c,0x0D),
ILI9881_DCS_write_1A_1P(0x7D,0x06),
ILI9881_DCS_write_1A_1P(0x7E,0x02),
ILI9881_DCS_write_1A_1P(0x7F,0x02),
ILI9881_DCS_write_1A_1P(0x80,0x02),
ILI9881_DCS_write_1A_1P(0x81,0x02),
ILI9881_DCS_write_1A_1P(0x82,0x02),
ILI9881_DCS_write_1A_1P(0x83,0x02),
ILI9881_DCS_write_1A_1P(0x84,0x07),
ILI9881_DCS_write_1A_1P(0x85,0x02),
ILI9881_DCS_write_1A_1P(0x86,0x02),
ILI9881_DCS_write_1A_1P(0x87,0x02),
ILI9881_DCS_write_1A_1P(0x88,0x02),
ILI9881_DCS_write_1A_1P(0x89,0x02),
ILI9881_DCS_write_1A_1P(0x8A,0x02),

data_array[0] = 0x00042902;
data_array[1] = 0x048198FF;
dsi_set_cmdq(data_array, 2, 1);
ILI9881_DCS_write_1A_1P(0x6C,0x15),
ILI9881_DCS_write_1A_1P(0x6E,0x3B),
ILI9881_DCS_write_1A_1P(0x6F,0xB3),
ILI9881_DCS_write_1A_1P(0x3A,0x94),
ILI9881_DCS_write_1A_1P(0x8D,0x1A),
ILI9881_DCS_write_1A_1P(0x87,0xBA),

ILI9881_DCS_write_1A_1P(0x26,0x76),
ILI9881_DCS_write_1A_1P(0xB2,0xD1),
ILI9881_DCS_write_1A_1P(0xB5,0x06),


data_array[0] = 0x00042902;
data_array[1] = 0x018198FF;
dsi_set_cmdq(data_array, 2, 1);
ILI9881_DCS_write_1A_1P(0x22,0x09),
ILI9881_DCS_write_1A_1P(0x31,0x00),
ILI9881_DCS_write_1A_1P(0x53,0x84),
ILI9881_DCS_write_1A_1P(0x55,0x90),
ILI9881_DCS_write_1A_1P(0x50,0x98),
ILI9881_DCS_write_1A_1P(0x51,0x98),
ILI9881_DCS_write_1A_1P(0x60,0x28),
ILI9881_DCS_write_1A_1P(0xA0,0x08),
ILI9881_DCS_write_1A_1P(0xA1,0x10),

ILI9881_DCS_write_1A_1P(0xA2,0x18),
ILI9881_DCS_write_1A_1P(0xA3,0x0E),

ILI9881_DCS_write_1A_1P(0xA4,0x0D),
ILI9881_DCS_write_1A_1P(0xA5,0x1E),
ILI9881_DCS_write_1A_1P(0xA6,0x12),
ILI9881_DCS_write_1A_1P(0xA7,0x16),
ILI9881_DCS_write_1A_1P(0xA8,0x4F),
ILI9881_DCS_write_1A_1P(0xA9,0x1A),
ILI9881_DCS_write_1A_1P(0xAA,0x26),
ILI9881_DCS_write_1A_1P(0xAB,0x50),
ILI9881_DCS_write_1A_1P(0xAC,0x1A),
ILI9881_DCS_write_1A_1P(0xAD,0x18),
ILI9881_DCS_write_1A_1P(0xAE,0x4A),

ILI9881_DCS_write_1A_1P(0xAF,0x1C),
ILI9881_DCS_write_1A_1P(0xB0,0x1C),

ILI9881_DCS_write_1A_1P(0xB1,0x54),
ILI9881_DCS_write_1A_1P(0xB2,0x65),
ILI9881_DCS_write_1A_1P(0xB3,0x39),
ILI9881_DCS_write_1A_1P(0xC0,0x08),
ILI9881_DCS_write_1A_1P(0xC1,0x10),
ILI9881_DCS_write_1A_1P(0xC2,0x18),
ILI9881_DCS_write_1A_1P(0xC3,0x0E),
ILI9881_DCS_write_1A_1P(0xC4,0x0D),
ILI9881_DCS_write_1A_1P(0xC5,0x1E),
ILI9881_DCS_write_1A_1P(0xC6,0x12),
ILI9881_DCS_write_1A_1P(0xC7,0x16),
ILI9881_DCS_write_1A_1P(0xC8,0x4F),


ILI9881_DCS_write_1A_1P(0xC9,0x1A),

ILI9881_DCS_write_1A_1P(0xCA,0x26),
ILI9881_DCS_write_1A_1P(0xCB,0x50),
ILI9881_DCS_write_1A_1P(0xCC,0x1A),
ILI9881_DCS_write_1A_1P(0xCD,0x18),
ILI9881_DCS_write_1A_1P(0xCE,0x4A),
ILI9881_DCS_write_1A_1P(0xCF,0x1C),
ILI9881_DCS_write_1A_1P(0xD0,0x1C),
ILI9881_DCS_write_1A_1P(0xD1,0x54),
ILI9881_DCS_write_1A_1P(0xD2,0x65),
ILI9881_DCS_write_1A_1P(0xD3,0x39),

data_array[0] = 0x00042902;
data_array[1] = 0x008198FF;
dsi_set_cmdq(data_array, 2, 1);

ILI9881_DCS_write_1A_1P(0x35,0x00),
ILI9881_DCS_write_1A_1P(0x36,0x03),

data_array[0]=0x00110500; // Display Off
dsi_set_cmdq(data_array, 1, 1);
MDELAY(120);
data_array[0]=0x00290500; // Display Off
dsi_set_cmdq(data_array, 1, 1);
MDELAY(20);

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
	params->dbi.te_hs_delay_cnt = 0x89;
	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active = 8;
	params->dsi.vertical_backporch = 24;
	params->dsi.vertical_frontporch = 16;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 20;
	params->dsi.horizontal_backporch = 100;
	params->dsi.horizontal_frontporch = 100;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.ssc_disable = 1;  // ssc disable control (1: disable, 0: enable, default: 0)
	params->dsi.PLL_CLOCK = 235;	//420 219

}

static void lcm_init(void)
{
	LCM_LOGI("[cp]lcm_init enter\n");
	SET_RESET_PIN(0);
	MDELAY(10);
	lcm_power_on();
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(5);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(120);

	init_lcm_registers();
}

static void lcm_resume(void)
{
	LCM_LOGI("[cp]lcm_resume enter\n");
	lcm_init();
}

static void lcm_suspend(void)
{
	unsigned int data_array[16];
	MDELAY(20);
	data_array[0]=0x00280500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(20);

	data_array[0] = 0x00100500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);

	lcm_power_down();

}

static unsigned int lcm_compare_id(void)
{

	unsigned int id1 = 0;
	unsigned int id2 = 0;
	unsigned int id3 = 0;

#if defined(BUILD_LK)
	id1 = mt_get_gpio_in(GPIO_LCD_ID1_PIN);
	id2 = mt_get_gpio_in(GPIO_LCD_ID2_PIN);
	id3 = mt_get_gpio_in(GPIO_LCD_ID3_PIN);
#endif

	if((id1 == 0) && (id2 == 1) && (id3 == 0))
		return 1;
	else
		return 0;

}

static void lcm_init_power(void)
{
	LCM_LOGI("[cp]lcm_init_power enter\n");
}


LCM_DRIVER ILI9881_HSD47_lcm_drv = {
	.name = "ILI9881_HSD47",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
