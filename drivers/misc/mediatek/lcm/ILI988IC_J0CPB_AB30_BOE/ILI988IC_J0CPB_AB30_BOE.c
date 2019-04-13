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

{0xFF,03,{0x98,0x81,0x03}},

{0x01,01,{0x00}},
{0x02,01,{0x00}},
{0x03,01,{0x73}},
{0x04,01,{0x00}},
{0x05,01,{0x00}},
{0x06,01,{0x09}},
{0x07,01,{0x00}},
{0x08,01,{0x00}},
{0x09,01,{0x01}},
{0x0A,01,{0x01}},
{0x0B,01,{0x01}},
{0x0C,01,{0x01}},
{0x0D,01,{0x01}},
{0x0E,01,{0x01}},
{0x0F,01,{0x26}},
{0x10,01,{0x26}},
{0x11,01,{0x00}},
{0x12,01,{0x00}},
{0x13,01,{0x00}},
{0x14,01,{0x00}},
{0x15,01,{0x00}},
{0x16,01,{0x00}},
{0x17,01,{0x00}},
{0x18,01,{0x00}},
{0x19,01,{0x00}},
{0x1A,01,{0x00}},
{0x1B,01,{0x00}},
{0x1C,01,{0x00}},
{0x1D,01,{0x00}},
{0x1E,01,{0x40}},
{0x1F,01,{0xC1}},
{0x20,01,{0x06}},
{0x21,01,{0x01}},
{0x22,01,{0x06}},
{0x23,01,{0x01}},
{0x24,01,{0x8C}},
{0x25,01,{0x8C}},
{0x26,01,{0x00}},
{0x27,01,{0x00}},
{0x28,01,{0x33}},
{0x29,01,{0x03}},
{0x2A,01,{0x88}},
{0x2B,01,{0x00}},
{0x2C,01,{0x0A}},
{0x2D,01,{0x0A}},
{0x2E,01,{0x05}},
{0x2F,01,{0x05}},
{0x30,01,{0x00}},
{0x31,01,{0x00}},
{0x32,01,{0x30}},
{0x33,01,{0x02}},
{0x34,01,{0xA3}},
{0x35,01,{0x0A}},
{0x36,01,{0x03}},
{0x37,01,{0x00}},
{0x38,01,{0x00}},
{0x39,01,{0x00}},
{0x3A,01,{0x00}},
{0x3B,01,{0x00}},
{0x3C,01,{0x00}},
{0x3D,01,{0x00}},
{0x3E,01,{0x00}},
{0x3F,01,{0x00}},
{0x40,01,{0x00}},
{0x41,01,{0x00}},
{0x42,01,{0x00}},
{0x43,01,{0x08}},
{0x44,01,{0x00}},

{0x50,01,{0x01}},
{0x51,01,{0x23}},
{0x52,01,{0x45}},
{0x53,01,{0x67}},
{0x54,01,{0x89}},
{0x55,01,{0xab}},
{0x56,01,{0x01}},
{0x57,01,{0x23}},
{0x58,01,{0x45}},
{0x59,01,{0x67}},
{0x5a,01,{0x89}},
{0x5b,01,{0xab}},
{0x5c,01,{0xcd}},
{0x5d,01,{0xef}},

{0x5e,01,{0x11}},
{0x5f,01,{0x17}},     //GOUT_L[1]_GCL_R
{0x60,01,{0x00}},     //GOUT_L[2]_VSD
{0x61,01,{0x0E}},     //GOUT_L[3]_CLK1R
{0x62,01,{0x0F}},     //GOUT_L[4]_CLK2R
{0x63,01,{0x0C}},     //GOUT_L[5]_CLK3R
{0x64,01,{0x0D}},     //GOUT_L[6]_CLK4R
{0x65,01,{0x02}},     //GOUT_L[7]_VGL
{0x66,01,{0x02}},     //GOUT_L[8]_VGL
{0x67,01,{0x02}},     //GOUT_L[9]_VGL
{0x68,01,{0x02}},     //GOUT_L[10]
{0x69,01,{0x02}},     //GOUT_L[11]
{0x6a,01,{0x02}},     //GOUT_L[12]
{0x6b,01,{0x02}},     //GOUT_L[13]
{0x6c,01,{0x02}},     //GOUT_L[14]
{0x6d,01,{0x02}},     //GOUT_L[15]
{0x6e,01,{0x02}},     //GOUT_L[16]
{0x6f,01,{0x02}},     //GOUT_L[17]
{0x70,01,{0x02}},     //GOUT_L[18]
{0x71,01,{0x16}},     //GOUT_L[19]_GCH
{0x72,01,{0x01}},     //GOUT_L[20]_VDS
{0x73,01,{0x06}},     //GOUT_L[21]_STV1R
{0x74,01,{0x07}},     //GOUT_L[22]_STV2R

{0x75,01,{0x17}},     //GOUT_R[1]_GCL_L
{0x76,01,{0x00}},     //GOUT_R[2]_VSD
{0x77,01,{0x0E}},     //GOUT_R[3]_CLK1L
{0x78,01,{0x0F}},     //GOUT_R[4]_CLK2L
{0x79,01,{0x0C}},     //GOUT_R[5]_CLK3L
{0x7a,01,{0x0D}},     //GOUT_R[6]_CLK4L
{0x7b,01,{0x0F}},     //GOUT_R[7]_VGL
{0x7c,01,{0x0F}},     //GOUT_R[8]_VGL
{0x7d,01,{0x02}},     //GOUT_R[9]_VGL
{0x7e,01,{0x02}},     //GOUT_R[10]
{0x7f,01,{0x02}},     //GOUT_R[11]
{0x80,01,{0x02}},     //GOUT_R[12]
{0x81,01,{0x02}},     //GOUT_R[13]
{0x82,01,{0x02}},     //GOUT_R[14]
{0x83,01,{0x02}},     //GOUT_R[15]
{0x84,01,{0x02}},     //GOUT_R[16]
{0x85,01,{0x02}},     //GOUT_R[17]
{0x86,01,{0x02}},     //GOUT_R[18]
{0x87,01,{0x06}},     //GOUT_R[19]_GCH
{0x88,01,{0x01}},     //GOUT_R[20]_VDS
{0x89,01,{0x06}},     //GOUT_R[21]_STV1L
{0x8A,01,{0x07}},     //GOUT_R[22]_STV2L


//CMD_Page 4
{0xFF,03,{0x98,0x81,0x04}},
{0x6C,01,{0x15}},
{0x6E,01,{0x1A}},               //di_pwr_reg=0 VGH clamp 1A=>12.13V
{0x6F,01,{0xA5}},               // reg vcl + pumping ratio VGH=2.5x VGL=-2.5x
{0x8D,01,{0x1F}},               //VGL clamp 20 =>-12.21V
{0x87,01,{0xBA}},               //ESD
{0x26,01,{0x76}},               //ESD
{0xB2,01,{0xD1}},               //ESD
{0x3B,01,{0x98}},   //SHIFT CLK
{0x3A,01,{0x92}},   //POWER SAVING
{0x35,01,{0x17}},   //P4_35=17 HZ_OPT
{0xB5,01,{0x27}},   //P4_B5=37 GMA BIAS
{0x31,01,{0x75}},   //P4_31=75 SRC BIAS
{0x30,01,{0x03}},   //P4_30=00 SRC OUTPUT BIAS
{0x38,01,{0x01}},   //CTOT
{0x39,01,{0x00}},   //CTOT

//CMD_Page 1
{0xFF,03,{0x98,0x81,0x01}},
{0x22,01,{0x0A}},               //BGR, SS // 0Bは苯//0Aタ苯
{0x31,01,{0x00}},
{0x50,01,{0xA6}},               //VREG1OUT=4.704V
{0x51,01,{0xA1}},               //VREG2OUT=-4.704V
{0x53,01,{0x55}},               //VCOM1
{0x55,01,{0x55}},               //VCOM2
{0x60,01,{0x14}},
{0x61,01,{0x01}},
{0x62,01,{0x20}},
{0x63,01,{0x10}},
/*
{0xA0,01,{0x08}},		//VP255	Gamma P
{0xA1,01,{0x16}},		//VP251
{0xA2,01,{0x20}},		//VP247
{0xA3,01,{0x13}},		//VP243
{0xA4,01,{0x14}},               //VP239
{0xA5,01,{0x26}},               //VP231
{0xA6,01,{0x18}},               //VP219
{0xA7,01,{0x1C}},               //VP203
{0xA8,01,{0x6B}},               //VP175
{0xA9,01,{0x1C}},               //VP144
{0xAA,01,{0x27}},               //VP111
{0xAB,01,{0x66}},               //VP80
{0xAC,01,{0x19}},               //VP52
{0xAD,01,{0x16}},               //VP36
{0xAE,01,{0x4C}},               //VP24
{0xAF,01,{0x22}},               //VP16
{0xB0,01,{0x27}},               //VP12
{0xB1,01,{0x56}},               //VP8
{0xB2,01,{0x66}},               //VP4
{0xB3,01,{0x39}},               //VP0

{0xC0,01,{0x08}},		//VN255 GAMMA N
{0xC1,01,{0x16}},               //VN251
{0xC2,01,{0x20}},               //VN247
{0xC3,01,{0x13}},               //VN243
{0xC4,01,{0x14}},               //VN239
{0xC5,01,{0x26}},               //VN231
{0xC6,01,{0x18}},               //VN219
{0xC7,01,{0x1C}},               //VN203
{0xC8,01,{0x6B}},               //VN175
{0xC9,01,{0x1C}},               //VN144
{0xCA,01,{0x27}},               //VN111
{0xCB,01,{0x66}},               //VN80
{0xCC,01,{0x19}},               //VN52
{0xCD,01,{0x16}},               //VN36
{0xCE,01,{0x4C}},               //VN24
{0xCF,01,{0x22}},               //VN16
{0xD0,01,{0x27}},               //VN12
{0xD1,01,{0x56}},               //VN8
{0xD2,01,{0x66}},               //VN4
{0xD3,01,{0x39}},               //VN0
*/
////gamma2.4

{0xA0,01,{0x08}},		//VP255	Gamma P
{0xA1,01,{0x3F}},		//VP251
{0xA2,01,{0x4D}},		//VP247
{0xA3,01,{0x14}},		//VP243
{0xA4,01,{0x17}},              //VP239
{0xA5,01,{0x2A}},               //VP231
{0xA6,01,{0x1F}},               //VP219
{0xA7,01,{0x1E}},               //VP203
{0xA8,01,{0xBE}},              //VP175
{0xA9,01,{0x26}},              //VP144
{0xAA,01,{0x31}},               //VP111
{0xAB,01,{0xA0}},               //VP80
{0xAC,01,{0x20}},               //VP52
{0xAD,01,{0x1F}},               //VP36
{0xAE,01,{0x53}},               //VP24
{0xAF,01,{0x2C}},              //VP16
{0xB0,01,{0x27}},               //VP12
{0xB1,01,{0x58}},               //VP8
{0xB2,01,{0x5B}},               //VP4
{0xB3,01,{0x39}},               //VP0

{0xC0,01,{0x08}},		//VN255 GAMMA N
{0xC1,01,{0x14}},               //VN251
{0xC2,01,{0x28}},              //VN247
{0xC3,01,{0x1F}},              //VN243
{0xC4,01,{0x20}},              //VN239
{0xC5,01,{0x30}},               //VN231
{0xC6,01,{0x22}},               //VN219
{0xC7,01,{0x23}},              //VN203
{0xC8,01,{0xA4}},              //VN175
{0xC9,01,{0x17}},               //VN144
{0xCA,01,{0x23}},               //VN111
{0xCB,01,{0x93}},               //VN80
{0xCC,01,{0x1B}},               //VN52
{0xCD,01,{0x21}},               //VN36
{0xCE,01,{0x5B}},               //VN24
{0xCF,01,{0x2E}},               //VN16
{0xD0,01,{0x36}},               //VN12
{0xD1,01,{0x4B}},               //VN8
{0xD2,01,{0x53}},              //VN4
{0xD3,01,{0x39}},               //VN0

{0xFF,03,{0x98,0x81,0x00}},
{0x11,0,{0x00}},
{REGFLAG_DELAY, 120, {}},
{0x29,0,{0x00}},
{0x35,0,{0x00}},
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
	params->dsi.PLL_CLOCK = 210;//208;


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

	LCM_LOGI("[chenpeng]lcm_compare_id\n");
#if defined(BUILD_LK)
	LCM_LOGI("[chenpeng]lk read id\n");
	id1 = mt_get_gpio_in(GPIO_LCD_ID1_PIN);
	id2 = mt_get_gpio_in(GPIO_LCD_ID2_PIN);
	id3 = mt_get_gpio_in(GPIO_LCD_ID3_PIN);

	printf("[chenpeng]ili9881c 0x%x\n",id1);
	printf("[chenpeng]ili9881c 0x%x\n",id2);
	printf("[chenpeng]ili9881c 0x%x\n",id3);
#else
	LCM_LOGI("ili9881c 0x%x\n",id1);
#endif

	if((id1 == 1) && (id2 == 0) && (id3 == 1))
		return 1;
	else
		return 0;

}


static void lcm_init_power(void)
{
	LCM_LOGI("lcm_init_power enter\n");
}


LCM_DRIVER ILI988IC_J0CPB_AB30_BOE_lcm_drv = {
	.name = "ILI988IC_J0CPB_AB30_BOE",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
