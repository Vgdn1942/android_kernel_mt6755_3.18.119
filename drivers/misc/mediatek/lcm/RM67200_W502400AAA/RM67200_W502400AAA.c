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


static void RM67200_DCS_write_1A_1P(unsigned char cmd, unsigned char para)
{
    unsigned int data_array[16];

    data_array[0] = (0x00022902);
    data_array[1] = (0x00000000 | (para << 8) | (cmd));
    dsi_set_cmdq(data_array, 2, 1);

}

static void RM67200_DCS_write_1A_0P(unsigned char cmd)
{
    unsigned int data_array[16];

    data_array[0]=(0x00000500 | (cmd<<16));
    dsi_set_cmdq(data_array, 1, 1);

}

static void init_lcm_registers(void)
{
#if 0
RM67200_DCS_write_1A_1P(0xFE,0x21);
RM67200_DCS_write_1A_1P(0x04,0x00);
RM67200_DCS_write_1A_1P(0x00,0x00);
RM67200_DCS_write_1A_1P(0x2A,0x00);
RM67200_DCS_write_1A_1P(0x26,0x00);
RM67200_DCS_write_1A_1P(0x54,0x00);
RM67200_DCS_write_1A_1P(0x50,0x00);
RM67200_DCS_write_1A_1P(0x7B,0x00);
RM67200_DCS_write_1A_1P(0x77,0x00);
RM67200_DCS_write_1A_1P(0xA2,0x00);
RM67200_DCS_write_1A_1P(0x9D,0x00);
RM67200_DCS_write_1A_1P(0xC9,0x00);
RM67200_DCS_write_1A_1P(0xC5,0x00);
RM67200_DCS_write_1A_1P(0x01,0x64);
RM67200_DCS_write_1A_1P(0x27,0x64);
RM67200_DCS_write_1A_1P(0x51,0x64);
RM67200_DCS_write_1A_1P(0x78,0x64);
RM67200_DCS_write_1A_1P(0x9E,0x64);
RM67200_DCS_write_1A_1P(0xC6,0x64);
RM67200_DCS_write_1A_1P(0x02,0x91);
RM67200_DCS_write_1A_1P(0x28,0x91);
RM67200_DCS_write_1A_1P(0x52,0x91);
RM67200_DCS_write_1A_1P(0x79,0x91);
RM67200_DCS_write_1A_1P(0x9F,0x91);
RM67200_DCS_write_1A_1P(0xC7,0x91);
RM67200_DCS_write_1A_1P(0x03,0xAE);
RM67200_DCS_write_1A_1P(0x29,0xAE);
RM67200_DCS_write_1A_1P(0x53,0xAE);
RM67200_DCS_write_1A_1P(0x7A,0xAE);
RM67200_DCS_write_1A_1P(0xA0,0xAE);
RM67200_DCS_write_1A_1P(0xC8,0xAE);
RM67200_DCS_write_1A_1P(0x09,0x00);
RM67200_DCS_write_1A_1P(0x05,0xC9);
RM67200_DCS_write_1A_1P(0x31,0x00);
RM67200_DCS_write_1A_1P(0x2B,0xC9);
RM67200_DCS_write_1A_1P(0x5A,0x00);
RM67200_DCS_write_1A_1P(0x55,0xC9);
RM67200_DCS_write_1A_1P(0x80,0x00);
RM67200_DCS_write_1A_1P(0x7C,0xC9);
RM67200_DCS_write_1A_1P(0xA7,0x00);
RM67200_DCS_write_1A_1P(0xA3,0xC9);
RM67200_DCS_write_1A_1P(0xCE,0x00);
RM67200_DCS_write_1A_1P(0xCA,0xC9);
RM67200_DCS_write_1A_1P(0x06,0xDC);
RM67200_DCS_write_1A_1P(0x2D,0xDC);
RM67200_DCS_write_1A_1P(0x56,0xDC);
RM67200_DCS_write_1A_1P(0x7D,0xDC);
RM67200_DCS_write_1A_1P(0xA4,0xDC);
RM67200_DCS_write_1A_1P(0xCB,0xDC);
RM67200_DCS_write_1A_1P(0x07,0xEE);
RM67200_DCS_write_1A_1P(0x2F,0xEE);
RM67200_DCS_write_1A_1P(0x58,0xEE);
RM67200_DCS_write_1A_1P(0x7E,0xEE);
RM67200_DCS_write_1A_1P(0xA5,0xEE);
RM67200_DCS_write_1A_1P(0xCC,0xEE);
RM67200_DCS_write_1A_1P(0x08,0xFF);
RM67200_DCS_write_1A_1P(0x30,0xFF);
RM67200_DCS_write_1A_1P(0x59,0xFF);
RM67200_DCS_write_1A_1P(0x7F,0xFF);
RM67200_DCS_write_1A_1P(0xA6,0xFF);
RM67200_DCS_write_1A_1P(0xCD,0xFF);
RM67200_DCS_write_1A_1P(0x0E,0x55);
RM67200_DCS_write_1A_1P(0x0A,0x0D);
RM67200_DCS_write_1A_1P(0x36,0x55);
RM67200_DCS_write_1A_1P(0x32,0x0D);
RM67200_DCS_write_1A_1P(0x5F,0x55);
RM67200_DCS_write_1A_1P(0x5B,0x0D);
RM67200_DCS_write_1A_1P(0x85,0x55);
RM67200_DCS_write_1A_1P(0x81,0x0D);
RM67200_DCS_write_1A_1P(0xAD,0x55);
RM67200_DCS_write_1A_1P(0xA9,0x0D);
RM67200_DCS_write_1A_1P(0xD3,0x55);
RM67200_DCS_write_1A_1P(0xCF,0x0D);
RM67200_DCS_write_1A_1P(0x0B,0x3E);
RM67200_DCS_write_1A_1P(0x33,0x3E);
RM67200_DCS_write_1A_1P(0x5C,0x3E);
RM67200_DCS_write_1A_1P(0x82,0x3E);
RM67200_DCS_write_1A_1P(0xAA,0x3E);
RM67200_DCS_write_1A_1P(0xD0,0x3E);
RM67200_DCS_write_1A_1P(0x0C,0x65);
RM67200_DCS_write_1A_1P(0x34,0x65);
RM67200_DCS_write_1A_1P(0x5D,0x65);
RM67200_DCS_write_1A_1P(0x83,0x65);
RM67200_DCS_write_1A_1P(0xAB,0x65);
RM67200_DCS_write_1A_1P(0xD1,0x65);
RM67200_DCS_write_1A_1P(0x0D,0xA2);
RM67200_DCS_write_1A_1P(0x35,0xA2);
RM67200_DCS_write_1A_1P(0x5E,0xA2);
RM67200_DCS_write_1A_1P(0x84,0xA2);
RM67200_DCS_write_1A_1P(0xAC,0xA2);
RM67200_DCS_write_1A_1P(0xD2,0xA2);
RM67200_DCS_write_1A_1P(0x13,0x6A);
RM67200_DCS_write_1A_1P(0x0F,0xD2);
RM67200_DCS_write_1A_1P(0x3B,0x6A);
RM67200_DCS_write_1A_1P(0x37,0xD2);
RM67200_DCS_write_1A_1P(0x64,0x6A);
RM67200_DCS_write_1A_1P(0x60,0xD2);
RM67200_DCS_write_1A_1P(0x8A,0x6A);
RM67200_DCS_write_1A_1P(0x86,0xD2);
RM67200_DCS_write_1A_1P(0xB2,0x6A);
RM67200_DCS_write_1A_1P(0xAE,0xD2);
RM67200_DCS_write_1A_1P(0xD8,0x6A);
RM67200_DCS_write_1A_1P(0xD4,0xD2);
RM67200_DCS_write_1A_1P(0x10,0x1B);
RM67200_DCS_write_1A_1P(0x38,0x1B);
RM67200_DCS_write_1A_1P(0x61,0x1B);
RM67200_DCS_write_1A_1P(0x87,0x1B);
RM67200_DCS_write_1A_1P(0xAF,0x1B);
RM67200_DCS_write_1A_1P(0xD5,0x1B);
RM67200_DCS_write_1A_1P(0x11,0x54);
RM67200_DCS_write_1A_1P(0x39,0x54);
RM67200_DCS_write_1A_1P(0x62,0x54);
RM67200_DCS_write_1A_1P(0x88,0x54);
RM67200_DCS_write_1A_1P(0xB0,0x54);
RM67200_DCS_write_1A_1P(0xD6,0x54);
RM67200_DCS_write_1A_1P(0x12,0x56);
RM67200_DCS_write_1A_1P(0x3A,0x56);
RM67200_DCS_write_1A_1P(0x63,0x56);
RM67200_DCS_write_1A_1P(0x89,0x56);
RM67200_DCS_write_1A_1P(0xB1,0x56);
RM67200_DCS_write_1A_1P(0xD7,0x56);
RM67200_DCS_write_1A_1P(0x18,0xAB);
RM67200_DCS_write_1A_1P(0x14,0x88);
RM67200_DCS_write_1A_1P(0x42,0xAB);
RM67200_DCS_write_1A_1P(0x3D,0x88);
RM67200_DCS_write_1A_1P(0x69,0xAB);
RM67200_DCS_write_1A_1P(0x65,0x88);
RM67200_DCS_write_1A_1P(0x8F,0xAB);
RM67200_DCS_write_1A_1P(0x8B,0x88);
RM67200_DCS_write_1A_1P(0xB7,0xAB);
RM67200_DCS_write_1A_1P(0xB3,0x88);
RM67200_DCS_write_1A_1P(0xDD,0xAB);
RM67200_DCS_write_1A_1P(0xD9,0x88);
RM67200_DCS_write_1A_1P(0x15,0xBC);
RM67200_DCS_write_1A_1P(0x3F,0xBC);
RM67200_DCS_write_1A_1P(0x66,0xBC);
RM67200_DCS_write_1A_1P(0x8C,0xBC);
RM67200_DCS_write_1A_1P(0xB4,0xBC);
RM67200_DCS_write_1A_1P(0xDA,0xBC);
RM67200_DCS_write_1A_1P(0x16,0xE2);
RM67200_DCS_write_1A_1P(0x40,0xE2);
RM67200_DCS_write_1A_1P(0x67,0xE2);
RM67200_DCS_write_1A_1P(0x8D,0xE2);
RM67200_DCS_write_1A_1P(0xB5,0xE2);
RM67200_DCS_write_1A_1P(0xDB,0xE2);
RM67200_DCS_write_1A_1P(0x17,0x10);
RM67200_DCS_write_1A_1P(0x41,0x10);
RM67200_DCS_write_1A_1P(0x68,0x10);
RM67200_DCS_write_1A_1P(0x8E,0x10);
RM67200_DCS_write_1A_1P(0xB6,0x10);
RM67200_DCS_write_1A_1P(0xDC,0x10);
RM67200_DCS_write_1A_1P(0x1D,0xFF);
RM67200_DCS_write_1A_1P(0x19,0x2D);
RM67200_DCS_write_1A_1P(0x47,0xFF);
RM67200_DCS_write_1A_1P(0x43,0x2D);
RM67200_DCS_write_1A_1P(0x6E,0xFF);
RM67200_DCS_write_1A_1P(0x6A,0x2D);
RM67200_DCS_write_1A_1P(0x94,0xFF);
RM67200_DCS_write_1A_1P(0x90,0x2D);
RM67200_DCS_write_1A_1P(0xBC,0xFF);
RM67200_DCS_write_1A_1P(0xB8,0x2D);
RM67200_DCS_write_1A_1P(0xE2,0xFF);
RM67200_DCS_write_1A_1P(0xDE,0x2D);
RM67200_DCS_write_1A_1P(0x1A,0x52);
RM67200_DCS_write_1A_1P(0x44,0x52);
RM67200_DCS_write_1A_1P(0x6B,0x52);
RM67200_DCS_write_1A_1P(0x91,0x52);
RM67200_DCS_write_1A_1P(0xB9,0x52);
RM67200_DCS_write_1A_1P(0xDF,0x52);
RM67200_DCS_write_1A_1P(0x1B,0x63);
RM67200_DCS_write_1A_1P(0x45,0x63);
RM67200_DCS_write_1A_1P(0x6C,0x63);
RM67200_DCS_write_1A_1P(0x92,0x63);
RM67200_DCS_write_1A_1P(0xBA,0x63);
RM67200_DCS_write_1A_1P(0xE0,0x63);
RM67200_DCS_write_1A_1P(0x1C,0x72);
RM67200_DCS_write_1A_1P(0x46,0x72);
RM67200_DCS_write_1A_1P(0x6D,0x72);
RM67200_DCS_write_1A_1P(0x93,0x72);
RM67200_DCS_write_1A_1P(0xBB,0x72);
RM67200_DCS_write_1A_1P(0xE1,0x72);
RM67200_DCS_write_1A_1P(0x22,0xFF);
RM67200_DCS_write_1A_1P(0x1E,0x7F);
RM67200_DCS_write_1A_1P(0x4C,0xFF);
RM67200_DCS_write_1A_1P(0x48,0x7F);
RM67200_DCS_write_1A_1P(0x73,0xFF);
RM67200_DCS_write_1A_1P(0x6F,0x7F);
RM67200_DCS_write_1A_1P(0x99,0xFF);
RM67200_DCS_write_1A_1P(0x95,0x7F);
RM67200_DCS_write_1A_1P(0xC1,0xFF);
RM67200_DCS_write_1A_1P(0xBD,0x7F);
RM67200_DCS_write_1A_1P(0xE7,0xFF);
RM67200_DCS_write_1A_1P(0xE3,0x7F);
RM67200_DCS_write_1A_1P(0x1F,0x91);
RM67200_DCS_write_1A_1P(0x49,0x91);
RM67200_DCS_write_1A_1P(0x70,0x91);
RM67200_DCS_write_1A_1P(0x96,0x91);
RM67200_DCS_write_1A_1P(0xBE,0x91);
RM67200_DCS_write_1A_1P(0xE4,0x91);
RM67200_DCS_write_1A_1P(0x20,0xA8);
RM67200_DCS_write_1A_1P(0x4A,0xA8);
RM67200_DCS_write_1A_1P(0x71,0xA8);
RM67200_DCS_write_1A_1P(0x97,0xA8);
RM67200_DCS_write_1A_1P(0xBF,0xA8);
RM67200_DCS_write_1A_1P(0xE5,0xA8);
RM67200_DCS_write_1A_1P(0x21,0xB6);
RM67200_DCS_write_1A_1P(0x4B,0xB6);
RM67200_DCS_write_1A_1P(0x72,0xB6);
RM67200_DCS_write_1A_1P(0x98,0xB6);
RM67200_DCS_write_1A_1P(0xC0,0xB6);
RM67200_DCS_write_1A_1P(0xE6,0xB6);
RM67200_DCS_write_1A_1P(0x25,0xF0);
RM67200_DCS_write_1A_1P(0x23,0xE3);
RM67200_DCS_write_1A_1P(0x4F,0xF0);
RM67200_DCS_write_1A_1P(0x4D,0xE3);
RM67200_DCS_write_1A_1P(0x76,0xF0);
RM67200_DCS_write_1A_1P(0x74,0xE3);
RM67200_DCS_write_1A_1P(0x9C,0xF0);
RM67200_DCS_write_1A_1P(0x9A,0xE3);
RM67200_DCS_write_1A_1P(0xC4,0xF0);
RM67200_DCS_write_1A_1P(0xC2,0xE3);
RM67200_DCS_write_1A_1P(0xEA,0xF0);
RM67200_DCS_write_1A_1P(0xE8,0xE3);
RM67200_DCS_write_1A_1P(0x24,0xE8);
RM67200_DCS_write_1A_1P(0x4E,0xE8);
RM67200_DCS_write_1A_1P(0x75,0xE8);
RM67200_DCS_write_1A_1P(0x9B,0xE8);
RM67200_DCS_write_1A_1P(0xC3,0xE8);
RM67200_DCS_write_1A_1P(0xE9,0xE8);
RM67200_DCS_write_1A_1P(0xFE,0x23);
RM67200_DCS_write_1A_1P(0x7D,0x2D);
RM67200_DCS_write_1A_1P(0x7E,0x2D);
RM67200_DCS_write_1A_1P(0x7F,0x2D);
RM67200_DCS_write_1A_1P(0x80,0x00);
RM67200_DCS_write_1A_1P(0x81,0x04);
RM67200_DCS_write_1A_1P(0x82,0x0A);
RM67200_DCS_write_1A_1P(0x83,0x35);
RM67200_DCS_write_1A_1P(0xFE,0x23);
RM67200_DCS_write_1A_1P(0x76,0x04);
RM67200_DCS_write_1A_1P(0x77,0x04);
RM67200_DCS_write_1A_1P(0x78,0x00);
RM67200_DCS_write_1A_1P(0x79,0x00);
RM67200_DCS_write_1A_1P(0x7D,0x14);
RM67200_DCS_write_1A_1P(0x7E,0x14);
RM67200_DCS_write_1A_1P(0x7F,0x14);
RM67200_DCS_write_1A_1P(0x80,0x04);
RM67200_DCS_write_1A_1P(0x81,0x04);
RM67200_DCS_write_1A_1P(0x82,0x04);
RM67200_DCS_write_1A_1P(0x83,0x20);
RM67200_DCS_write_1A_1P(0x84,0x0B);
RM67200_DCS_write_1A_1P(0x5C,0x77);
RM67200_DCS_write_1A_1P(0x5D,0x77);
RM67200_DCS_write_1A_1P(0x5E,0x77);
RM67200_DCS_write_1A_1P(0x5F,0x07);
RM67200_DCS_write_1A_1P(0x60,0x17);
RM67200_DCS_write_1A_1P(0x61,0x27);
RM67200_DCS_write_1A_1P(0x62,0x27);
RM67200_DCS_write_1A_1P(0x63,0x17);
RM67200_DCS_write_1A_1P(0x64,0x07);
RM67200_DCS_write_1A_1P(0x65,0x77);
RM67200_DCS_write_1A_1P(0x66,0x77);
RM67200_DCS_write_1A_1P(0x67,0x77);
RM67200_DCS_write_1A_1P(0xFE,0x00);
RM67200_DCS_write_1A_1P(0xFE,0x3D);
RM67200_DCS_write_1A_1P(0x23,0x2C);
RM67200_DCS_write_1A_1P(0xFE,0x20);
RM67200_DCS_write_1A_1P(0x1A,0x9F);//95
RM67200_DCS_write_1A_1P(0xFE,0x20);
RM67200_DCS_write_1A_1P(0x26,0x30);
RM67200_DCS_write_1A_1P(0xFE,0x3D);
RM67200_DCS_write_1A_1P(0x20,0x71);
RM67200_DCS_write_1A_1P(0xFE,0x00);
RM67200_DCS_write_1A_1P(0x35,0x00);
#else
RM67200_DCS_write_1A_1P(0xFE,0x21);
RM67200_DCS_write_1A_1P(0x04,0x00);
RM67200_DCS_write_1A_1P(0x00,0x00);
RM67200_DCS_write_1A_1P(0x2A,0x00);
RM67200_DCS_write_1A_1P(0x26,0x00);
RM67200_DCS_write_1A_1P(0x54,0x00);
RM67200_DCS_write_1A_1P(0x50,0x00);
RM67200_DCS_write_1A_1P(0x7B,0x00);
RM67200_DCS_write_1A_1P(0x77,0x00);
RM67200_DCS_write_1A_1P(0xA2,0x00);
RM67200_DCS_write_1A_1P(0x9D,0x00);
RM67200_DCS_write_1A_1P(0xC9,0x00);
RM67200_DCS_write_1A_1P(0xC5,0x00);
RM67200_DCS_write_1A_1P(0x01,0x76);
RM67200_DCS_write_1A_1P(0x27,0x76);
RM67200_DCS_write_1A_1P(0x51,0x76);
RM67200_DCS_write_1A_1P(0x78,0x76);
RM67200_DCS_write_1A_1P(0x9E,0x76);
RM67200_DCS_write_1A_1P(0xC6,0x76);
RM67200_DCS_write_1A_1P(0x02,0xA4);
RM67200_DCS_write_1A_1P(0x28,0xA4);
RM67200_DCS_write_1A_1P(0x52,0xA4);
RM67200_DCS_write_1A_1P(0x79,0xA4);
RM67200_DCS_write_1A_1P(0x9F,0xA4);
RM67200_DCS_write_1A_1P(0xC7,0xA4);
RM67200_DCS_write_1A_1P(0x03,0xC3);
RM67200_DCS_write_1A_1P(0x29,0xC3);
RM67200_DCS_write_1A_1P(0x53,0xC3);
RM67200_DCS_write_1A_1P(0x7A,0xC3);
RM67200_DCS_write_1A_1P(0xA0,0xC3);
RM67200_DCS_write_1A_1P(0xC8,0xC3);
RM67200_DCS_write_1A_1P(0x09,0x05);
RM67200_DCS_write_1A_1P(0x05,0xDD);
RM67200_DCS_write_1A_1P(0x31,0x05);
RM67200_DCS_write_1A_1P(0x2B,0xDD);
RM67200_DCS_write_1A_1P(0x5A,0x05);
RM67200_DCS_write_1A_1P(0x55,0xDD);
RM67200_DCS_write_1A_1P(0x80,0x05);
RM67200_DCS_write_1A_1P(0x7C,0xDD);
RM67200_DCS_write_1A_1P(0xA7,0x05);
RM67200_DCS_write_1A_1P(0xA3,0xDD);
RM67200_DCS_write_1A_1P(0xCE,0x05);
RM67200_DCS_write_1A_1P(0xCA,0xDD);
RM67200_DCS_write_1A_1P(0x06,0xF1);
RM67200_DCS_write_1A_1P(0x2D,0xF1);
RM67200_DCS_write_1A_1P(0x56,0xF1);
RM67200_DCS_write_1A_1P(0x7D,0xF1);
RM67200_DCS_write_1A_1P(0xA4,0xF1);
RM67200_DCS_write_1A_1P(0xCB,0xF1);
RM67200_DCS_write_1A_1P(0x07,0x03);
RM67200_DCS_write_1A_1P(0x2F,0x03);
RM67200_DCS_write_1A_1P(0x58,0x03);
RM67200_DCS_write_1A_1P(0x7E,0x03);
RM67200_DCS_write_1A_1P(0xA5,0x03);
RM67200_DCS_write_1A_1P(0xCC,0x03);
RM67200_DCS_write_1A_1P(0x08,0x13);
RM67200_DCS_write_1A_1P(0x30,0x13);
RM67200_DCS_write_1A_1P(0x59,0x13);
RM67200_DCS_write_1A_1P(0x7F,0x13);
RM67200_DCS_write_1A_1P(0xA6,0x13);
RM67200_DCS_write_1A_1P(0xCD,0x13);
RM67200_DCS_write_1A_1P(0x0E,0x55);
RM67200_DCS_write_1A_1P(0x0A,0x22);
RM67200_DCS_write_1A_1P(0x36,0x55);
RM67200_DCS_write_1A_1P(0x32,0x22);
RM67200_DCS_write_1A_1P(0x5F,0x55);
RM67200_DCS_write_1A_1P(0x5B,0x22);
RM67200_DCS_write_1A_1P(0x85,0x55);
RM67200_DCS_write_1A_1P(0x81,0x22);
RM67200_DCS_write_1A_1P(0xAD,0x55);
RM67200_DCS_write_1A_1P(0xA9,0x22);
RM67200_DCS_write_1A_1P(0xD3,0x55);
RM67200_DCS_write_1A_1P(0xCF,0x22);
RM67200_DCS_write_1A_1P(0x0B,0x54);
RM67200_DCS_write_1A_1P(0x33,0x54);
RM67200_DCS_write_1A_1P(0x5C,0x54);
RM67200_DCS_write_1A_1P(0x82,0x54);
RM67200_DCS_write_1A_1P(0xAA,0x54);
RM67200_DCS_write_1A_1P(0xD0,0x54);
RM67200_DCS_write_1A_1P(0x0C,0x7B);
RM67200_DCS_write_1A_1P(0x34,0x7B);
RM67200_DCS_write_1A_1P(0x5D,0x7B);
RM67200_DCS_write_1A_1P(0x83,0x7B);
RM67200_DCS_write_1A_1P(0xAB,0x7B);
RM67200_DCS_write_1A_1P(0xD1,0x7B);
RM67200_DCS_write_1A_1P(0x0D,0xB8);
RM67200_DCS_write_1A_1P(0x35,0xB8);
RM67200_DCS_write_1A_1P(0x5E,0xB8);
RM67200_DCS_write_1A_1P(0x84,0xB8);
RM67200_DCS_write_1A_1P(0xAC,0xB8);
RM67200_DCS_write_1A_1P(0xD2,0xB8);
RM67200_DCS_write_1A_1P(0x13,0x6A);
RM67200_DCS_write_1A_1P(0x0F,0xE8);
RM67200_DCS_write_1A_1P(0x3B,0x6A);
RM67200_DCS_write_1A_1P(0x37,0xE8);
RM67200_DCS_write_1A_1P(0x64,0x6A);
RM67200_DCS_write_1A_1P(0x60,0xE8);
RM67200_DCS_write_1A_1P(0x8A,0x6A);
RM67200_DCS_write_1A_1P(0x86,0xE8);
RM67200_DCS_write_1A_1P(0xB2,0x6A);
RM67200_DCS_write_1A_1P(0xAE,0xE8);
RM67200_DCS_write_1A_1P(0xD8,0x6A);
RM67200_DCS_write_1A_1P(0xD4,0xE8);
RM67200_DCS_write_1A_1P(0x10,0x31);
RM67200_DCS_write_1A_1P(0x38,0x31);
RM67200_DCS_write_1A_1P(0x61,0x31);
RM67200_DCS_write_1A_1P(0x87,0x31);
RM67200_DCS_write_1A_1P(0xAF,0x31);
RM67200_DCS_write_1A_1P(0xD5,0x31);
RM67200_DCS_write_1A_1P(0x11,0x69);
RM67200_DCS_write_1A_1P(0x39,0x69);
RM67200_DCS_write_1A_1P(0x62,0x69);
RM67200_DCS_write_1A_1P(0x88,0x69);
RM67200_DCS_write_1A_1P(0xB0,0x69);
RM67200_DCS_write_1A_1P(0xD6,0x69);
RM67200_DCS_write_1A_1P(0x12,0x6B);
RM67200_DCS_write_1A_1P(0x3A,0x6B);
RM67200_DCS_write_1A_1P(0x63,0x6B);
RM67200_DCS_write_1A_1P(0x89,0x6B);
RM67200_DCS_write_1A_1P(0xB1,0x6B);
RM67200_DCS_write_1A_1P(0xD7,0x6B);
RM67200_DCS_write_1A_1P(0x18,0xAB);
RM67200_DCS_write_1A_1P(0x14,0x9D);
RM67200_DCS_write_1A_1P(0x42,0xAB);
RM67200_DCS_write_1A_1P(0x3D,0x9D);
RM67200_DCS_write_1A_1P(0x69,0xAB);
RM67200_DCS_write_1A_1P(0x65,0x9D);
RM67200_DCS_write_1A_1P(0x8F,0xAB);
RM67200_DCS_write_1A_1P(0x8B,0x9D);
RM67200_DCS_write_1A_1P(0xB7,0xAB);
RM67200_DCS_write_1A_1P(0xB3,0x9D);
RM67200_DCS_write_1A_1P(0xDD,0xAB);
RM67200_DCS_write_1A_1P(0xD9,0x9D);
RM67200_DCS_write_1A_1P(0x15,0xD5);
RM67200_DCS_write_1A_1P(0x3F,0xD5);
RM67200_DCS_write_1A_1P(0x66,0xD5);
RM67200_DCS_write_1A_1P(0x8C,0xD5);
RM67200_DCS_write_1A_1P(0xB4,0xD5);
RM67200_DCS_write_1A_1P(0xDA,0xD5);
RM67200_DCS_write_1A_1P(0x16,0xF9);
RM67200_DCS_write_1A_1P(0x40,0xF9);
RM67200_DCS_write_1A_1P(0x67,0xF9);
RM67200_DCS_write_1A_1P(0x8D,0xF9);
RM67200_DCS_write_1A_1P(0xB5,0xF9);
RM67200_DCS_write_1A_1P(0xDB,0xF9);
RM67200_DCS_write_1A_1P(0x17,0x2B);
RM67200_DCS_write_1A_1P(0x41,0x2B);
RM67200_DCS_write_1A_1P(0x68,0x2B);
RM67200_DCS_write_1A_1P(0x8E,0x2B);
RM67200_DCS_write_1A_1P(0xB6,0x2B);
RM67200_DCS_write_1A_1P(0xDC,0x2B);
RM67200_DCS_write_1A_1P(0x1D,0xFF);
RM67200_DCS_write_1A_1P(0x19,0x4B);
RM67200_DCS_write_1A_1P(0x47,0xFF);
RM67200_DCS_write_1A_1P(0x43,0x4B);
RM67200_DCS_write_1A_1P(0x6E,0xFF);
RM67200_DCS_write_1A_1P(0x6A,0x4B);
RM67200_DCS_write_1A_1P(0x94,0xFF);
RM67200_DCS_write_1A_1P(0x90,0x4B);
RM67200_DCS_write_1A_1P(0xBC,0xFF);
RM67200_DCS_write_1A_1P(0xB8,0x4B);
RM67200_DCS_write_1A_1P(0xE2,0xFF);
RM67200_DCS_write_1A_1P(0xDE,0x4B);
RM67200_DCS_write_1A_1P(0x1A,0x73);
RM67200_DCS_write_1A_1P(0x44,0x73);
RM67200_DCS_write_1A_1P(0x6B,0x73);
RM67200_DCS_write_1A_1P(0x91,0x73);
RM67200_DCS_write_1A_1P(0xB9,0x73);
RM67200_DCS_write_1A_1P(0xDF,0x73);
RM67200_DCS_write_1A_1P(0x1B,0x80);
RM67200_DCS_write_1A_1P(0x45,0x80);
RM67200_DCS_write_1A_1P(0x6C,0x80);
RM67200_DCS_write_1A_1P(0x92,0x80);
RM67200_DCS_write_1A_1P(0xBA,0x80);
RM67200_DCS_write_1A_1P(0xE0,0x80);
RM67200_DCS_write_1A_1P(0x1C,0x8C);
RM67200_DCS_write_1A_1P(0x46,0x8C);
RM67200_DCS_write_1A_1P(0x6D,0x8C);
RM67200_DCS_write_1A_1P(0x93,0x8C);
RM67200_DCS_write_1A_1P(0xBB,0x8C);
RM67200_DCS_write_1A_1P(0xE1,0x8C);
RM67200_DCS_write_1A_1P(0x22,0xFF);
RM67200_DCS_write_1A_1P(0x1E,0x9D);
RM67200_DCS_write_1A_1P(0x4C,0xFF);
RM67200_DCS_write_1A_1P(0x48,0x9D);
RM67200_DCS_write_1A_1P(0x73,0xFF);
RM67200_DCS_write_1A_1P(0x6F,0x9D);
RM67200_DCS_write_1A_1P(0x99,0xFF);
RM67200_DCS_write_1A_1P(0x95,0x9D);
RM67200_DCS_write_1A_1P(0xC1,0xFF);
RM67200_DCS_write_1A_1P(0xBD,0x9D);
RM67200_DCS_write_1A_1P(0xE7,0xFF);
RM67200_DCS_write_1A_1P(0xE3,0x9D);
RM67200_DCS_write_1A_1P(0x1F,0xAA);
RM67200_DCS_write_1A_1P(0x49,0xAA);
RM67200_DCS_write_1A_1P(0x70,0xAA);
RM67200_DCS_write_1A_1P(0x96,0xAA);
RM67200_DCS_write_1A_1P(0xBE,0xAA);
RM67200_DCS_write_1A_1P(0xE4,0xAA);
RM67200_DCS_write_1A_1P(0x20,0xC0);
RM67200_DCS_write_1A_1P(0x4A,0xC0);
RM67200_DCS_write_1A_1P(0x71,0xC0);
RM67200_DCS_write_1A_1P(0x97,0xC0);
RM67200_DCS_write_1A_1P(0xBF,0xC0);
RM67200_DCS_write_1A_1P(0xE5,0xC0);
RM67200_DCS_write_1A_1P(0x21,0xE2);
RM67200_DCS_write_1A_1P(0x4B,0xE2);
RM67200_DCS_write_1A_1P(0x72,0xE2);
RM67200_DCS_write_1A_1P(0x98,0xE2);
RM67200_DCS_write_1A_1P(0xC0,0xE2);
RM67200_DCS_write_1A_1P(0xE6,0xE2);
RM67200_DCS_write_1A_1P(0x25,0xF0);
RM67200_DCS_write_1A_1P(0x23,0xE8);
RM67200_DCS_write_1A_1P(0x4F,0xF0);
RM67200_DCS_write_1A_1P(0x4D,0xE8);
RM67200_DCS_write_1A_1P(0x76,0xF0);
RM67200_DCS_write_1A_1P(0x74,0xE8);
RM67200_DCS_write_1A_1P(0x9C,0xF0);
RM67200_DCS_write_1A_1P(0x9A,0xE8);
RM67200_DCS_write_1A_1P(0xC4,0xF0);
RM67200_DCS_write_1A_1P(0xC2,0xE8);
RM67200_DCS_write_1A_1P(0xEA,0xF0);
RM67200_DCS_write_1A_1P(0xE8,0xE8);
RM67200_DCS_write_1A_1P(0x24,0xE8);
RM67200_DCS_write_1A_1P(0x4E,0xE8);
RM67200_DCS_write_1A_1P(0x75,0xE8);
RM67200_DCS_write_1A_1P(0x9B,0xE8);
RM67200_DCS_write_1A_1P(0xC3,0xE8);
RM67200_DCS_write_1A_1P(0xE9,0xE8);
RM67200_DCS_write_1A_1P(0xFE,0x23);
RM67200_DCS_write_1A_1P(0x76,0x04);
RM67200_DCS_write_1A_1P(0x77,0x04);
RM67200_DCS_write_1A_1P(0x78,0x00);
RM67200_DCS_write_1A_1P(0x79,0x00);
RM67200_DCS_write_1A_1P(0x7D,0x2D);  //14
RM67200_DCS_write_1A_1P(0x7E,0x2D);  //14
RM67200_DCS_write_1A_1P(0x7F,0x2D);  //14
RM67200_DCS_write_1A_1P(0x80,0x00);  //04
RM67200_DCS_write_1A_1P(0x81,0x04);  
RM67200_DCS_write_1A_1P(0x82,0x0A);  //04
RM67200_DCS_write_1A_1P(0x83,0x35);  //20
RM67200_DCS_write_1A_1P(0x84,0x0B);
RM67200_DCS_write_1A_1P(0x5C,0x77);
RM67200_DCS_write_1A_1P(0x5D,0x77);
RM67200_DCS_write_1A_1P(0x5E,0x77);
RM67200_DCS_write_1A_1P(0x5F,0x00);
RM67200_DCS_write_1A_1P(0x60,0x11);
RM67200_DCS_write_1A_1P(0x61,0x22);
RM67200_DCS_write_1A_1P(0x62,0x22);
RM67200_DCS_write_1A_1P(0x63,0x11);
RM67200_DCS_write_1A_1P(0x64,0x00);
RM67200_DCS_write_1A_1P(0x65,0x77);
RM67200_DCS_write_1A_1P(0x66,0x77);
RM67200_DCS_write_1A_1P(0x67,0x77);
RM67200_DCS_write_1A_1P(0xFE,0x3D);
RM67200_DCS_write_1A_1P(0x23,0x2C);
RM67200_DCS_write_1A_1P(0xFE,0x20);
RM67200_DCS_write_1A_1P(0x49,0xE0);
RM67200_DCS_write_1A_1P(0x50,0xB8);//88
RM67200_DCS_write_1A_1P(0x51,0xB8);//88
RM67200_DCS_write_1A_1P(0xFE,0x20);
RM67200_DCS_write_1A_1P(0x26,0x30);
RM67200_DCS_write_1A_1P(0xFE,0x3D);
RM67200_DCS_write_1A_1P(0x20,0x71);
RM67200_DCS_write_1A_1P(0xFE,0x00);
RM67200_DCS_write_1A_1P(0x35,0x00);

#endif
//REGW 0xBA,0x02
RM67200_DCS_write_1A_0P(0x11);
MDELAY(120);    

RM67200_DCS_write_1A_0P(0x29);
MDELAY(20);
};




/*static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
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
}*/


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

	params->dsi.mode = BURST_VDO_MODE;//SYNC_PULSE_VDO_MODE;BURST_VDO_MODE
	params->dsi.switch_mode = CMD_MODE;
	params->dsi.switch_mode_enable = 0;

	params->physical_width  = 62;
	params->physical_height = 110;

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

	params->dsi.vertical_sync_active = 2;  //6
	params->dsi.vertical_backporch = 8;  //30
	params->dsi.vertical_frontporch = 8;  //36
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 2;
	params->dsi.horizontal_backporch = 30;  //60
	params->dsi.horizontal_frontporch = 15;  //72
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	
	params->dsi.ssc_disable = 1;  // ssc disable control (1: disable, 0: enable, default: 0)
	params->dsi.PLL_CLOCK = 401;
}



static void lcm_init(void)
{
	LCM_LOGI("lcm_init enter\n");
	agold_lcm_power_on();
	
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(120);
	//push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
	init_lcm_registers();
}

static void lcm_resume(void)
{
	LCM_LOGI("lcm_resume enter\n");
	lcm_init();
}

static void lcm_suspend(void)
{
	unsigned int data_array[16];
	LCM_LOGI("lcm_suspend enter\n");
 
    data_array[0]=0x00280500; // Display Off
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(120);

    data_array[0] = 0x00100500; // Sleep In
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(120);

    SET_RESET_PIN(0);
    MDELAY(20);
	
	agold_lcm_power_down();
}


static unsigned int lcm_compare_id(void)
{
	unsigned int id1 = 0;
	unsigned int id2 = 0;		
	unsigned int id3 = 0;	

//ic start
	unsigned int id=0;
	unsigned char buffer[3];
	unsigned int array[16];  
//ic end

	LCM_LOGI("[Chenpeng]lcm_compare_id\n");
#if defined(BUILD_LK)
	LCM_LOGI("[Chenpeng]lk read id\n");
	id1 = mt_get_gpio_in(GPIO_LCD_ID1_PIN);
	id2 = mt_get_gpio_in(GPIO_LCD_ID2_PIN);
	id3 = mt_get_gpio_in(GPIO_LCD_ID3_PIN);

	printf("[Chenpeng]nt35596 0x%x\n",id1);
	printf("[Chenpeng]nt35596 0x%x\n",id2);	
	printf("[Chenpeng]nt35596 0x%x\n",id3);		
#else
	LCM_LOGI("nt35596 0x%x\n",id1);		
#endif			
	
	if((id1 == 1) && (id2 == 0) && (id3 == 0)){//ic start
			agold_lcm_power_on();
			
			SET_RESET_PIN(1);
			MDELAY(10);
			SET_RESET_PIN(0);
			MDELAY(20);
			SET_RESET_PIN(1);
			MDELAY(120);

			array[0] = 0x00033700;// read id return two byte,version and id
			dsi_set_cmdq(array, 3, 1);
			read_reg_v2(0xDB, buffer, 2);

			id = buffer[0];
			LCM_LOGD("RM67200_W502400AAA read id=0x%x\n", id);

			if(id == 0x72)
		    	return 1;
		    else
		        return 0;
	}//ic start
	else
		return 0;
}

static void lcm_init_power(void)
{
	LCM_LOGI("lcm_init_power enter\n");
}


LCM_DRIVER RM67200_W502400AAA_lcm_drv = {
	.name = "RM67200_W502400AAA",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
