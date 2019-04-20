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
unsigned int data_array[16]={0};
void NT35532_DCS_write_1A_1P(unsigned char cmd, unsigned char para)
{
  unsigned int data_array[16];
  //unsigned char buffer;
  data_array[0] =(0x00022902);
  data_array[1] =(0x00000000| (para<<8)|(cmd));
  dsi_set_cmdq(data_array, 2, 1);
  //MDELAY(1);
}

#define NT35532_DCS_write_1A_0P(cmd)							data_array[0]=(0x00000500 | (cmd<<16)); \
                                                 dsi_set_cmdq(data_array, 1, 1);

static void init_lcm_registers(void)
{
NT35532_DCS_write_1A_1P(0xFF,0x00);

NT35532_DCS_write_1A_1P(0xBA,0x03);
NT35532_DCS_write_1A_1P(0x36,0x00);
NT35532_DCS_write_1A_1P(0xB0,0x00);
NT35532_DCS_write_1A_1P(0xD3,0x08);
NT35532_DCS_write_1A_1P(0xD4,0x0E);
NT35532_DCS_write_1A_1P(0xD5,0x0F);
NT35532_DCS_write_1A_1P(0xD6,0x48);
NT35532_DCS_write_1A_1P(0xD7,0x00);
NT35532_DCS_write_1A_1P(0xD9,0x00);
NT35532_DCS_write_1A_1P(0xFB,0x01);
NT35532_DCS_write_1A_1P(0xFF,0xEE);
NT35532_DCS_write_1A_1P(0x40,0x00);
NT35532_DCS_write_1A_1P(0x41,0x00);
NT35532_DCS_write_1A_1P(0x42,0x00);

NT35532_DCS_write_1A_1P(0xFB,0x01);

NT35532_DCS_write_1A_1P(0xFF,0x01);
NT35532_DCS_write_1A_1P(0xFB,0x01);
NT35532_DCS_write_1A_1P(0x01,0x55);
NT35532_DCS_write_1A_1P(0x04,0x0C);
NT35532_DCS_write_1A_1P(0x05,0x3A);
NT35532_DCS_write_1A_1P(0x06,0x10); //50
NT35532_DCS_write_1A_1P(0x07,0xD0);
NT35532_DCS_write_1A_1P(0x0A,0x0F);
NT35532_DCS_write_1A_1P(0x0D,0x7F);
NT35532_DCS_write_1A_1P(0x0E,0x7F);
NT35532_DCS_write_1A_1P(0x0F,0x70);
NT35532_DCS_write_1A_1P(0x10,0x63);
NT35532_DCS_write_1A_1P(0x11,0x3C);
NT35532_DCS_write_1A_1P(0x12,0x5C);
//NT35532_DCS_write_1A_1P(0x13,0x4B);
//NT35532_DCS_write_1A_1P(0x14,0x40);
NT35532_DCS_write_1A_1P(0x15,0x60);
NT35532_DCS_write_1A_1P(0x16,0x11);
NT35532_DCS_write_1A_1P(0x17,0x11);
NT35532_DCS_write_1A_1P(0x5B,0xCA);
NT35532_DCS_write_1A_1P(0x5C,0x00);
NT35532_DCS_write_1A_1P(0x5D,0x00);
NT35532_DCS_write_1A_1P(0x5F,0x1B);
NT35532_DCS_write_1A_1P(0x60,0xD5);
NT35532_DCS_write_1A_1P(0x61,0xF7);
NT35532_DCS_write_1A_1P(0x6C,0xAB);
NT35532_DCS_write_1A_1P(0x6D,0x44);

//3Gamma2.5
NT35532_DCS_write_1A_1P(0xFF,0x01);
NT35532_DCS_write_1A_1P(0xFB,0x01);

NT35532_DCS_write_1A_1P(0x75,0x00);
NT35532_DCS_write_1A_1P(0x76,0x08);
NT35532_DCS_write_1A_1P(0x77,0x00);
NT35532_DCS_write_1A_1P(0x78,0x49);
NT35532_DCS_write_1A_1P(0x79,0x00);
NT35532_DCS_write_1A_1P(0x7A,0x7A);
NT35532_DCS_write_1A_1P(0x7B,0x00);
NT35532_DCS_write_1A_1P(0x7C,0x98);
NT35532_DCS_write_1A_1P(0x7D,0x00);
NT35532_DCS_write_1A_1P(0x7E,0xAF);
NT35532_DCS_write_1A_1P(0x7F,0x00);
NT35532_DCS_write_1A_1P(0x80,0xC3);
NT35532_DCS_write_1A_1P(0x81,0x00);
NT35532_DCS_write_1A_1P(0x82,0xD7);
NT35532_DCS_write_1A_1P(0x83,0x00);
NT35532_DCS_write_1A_1P(0x84,0xE4);
NT35532_DCS_write_1A_1P(0x85,0x00);
NT35532_DCS_write_1A_1P(0x86,0xF3);
NT35532_DCS_write_1A_1P(0x87,0x01);
NT35532_DCS_write_1A_1P(0x88,0x23);
NT35532_DCS_write_1A_1P(0x89,0x01);
NT35532_DCS_write_1A_1P(0x8A,0x48);
NT35532_DCS_write_1A_1P(0x8B,0x01);
NT35532_DCS_write_1A_1P(0x8C,0x85);
NT35532_DCS_write_1A_1P(0x8D,0x01);
NT35532_DCS_write_1A_1P(0x8E,0xB4);
NT35532_DCS_write_1A_1P(0x8F,0x01);
NT35532_DCS_write_1A_1P(0x90,0xFD);
NT35532_DCS_write_1A_1P(0x91,0x02);
NT35532_DCS_write_1A_1P(0x92,0x3A);
NT35532_DCS_write_1A_1P(0x93,0x02);
NT35532_DCS_write_1A_1P(0x94,0x3B);
NT35532_DCS_write_1A_1P(0x95,0x02);
NT35532_DCS_write_1A_1P(0x96,0x6F);
NT35532_DCS_write_1A_1P(0x97,0x02);
NT35532_DCS_write_1A_1P(0x98,0xAE);
NT35532_DCS_write_1A_1P(0x99,0x02);
NT35532_DCS_write_1A_1P(0x9A,0xD3);
NT35532_DCS_write_1A_1P(0x9B,0x03);
NT35532_DCS_write_1A_1P(0x9C,0x08);
NT35532_DCS_write_1A_1P(0x9D,0x03);
NT35532_DCS_write_1A_1P(0x9E,0x29);
NT35532_DCS_write_1A_1P(0x9F,0x03);
NT35532_DCS_write_1A_1P(0xA0,0x5C);
NT35532_DCS_write_1A_1P(0xA2,0x03);
NT35532_DCS_write_1A_1P(0xA3,0x67);
NT35532_DCS_write_1A_1P(0xA4,0x03);
NT35532_DCS_write_1A_1P(0xA5,0x6F);
NT35532_DCS_write_1A_1P(0xA6,0x03);
NT35532_DCS_write_1A_1P(0xA7,0x89);
NT35532_DCS_write_1A_1P(0xA9,0x03);
NT35532_DCS_write_1A_1P(0xAA,0xA3);
NT35532_DCS_write_1A_1P(0xAB,0x03);
NT35532_DCS_write_1A_1P(0xAC,0xBD);
NT35532_DCS_write_1A_1P(0xAD,0x03);
NT35532_DCS_write_1A_1P(0xAE,0xC0);
NT35532_DCS_write_1A_1P(0xAF,0x03);
NT35532_DCS_write_1A_1P(0xB0,0xE5);
NT35532_DCS_write_1A_1P(0xB1,0x03);
NT35532_DCS_write_1A_1P(0xB2,0xF5);

NT35532_DCS_write_1A_1P(0xB3,0x00);
NT35532_DCS_write_1A_1P(0xB4,0x08);
NT35532_DCS_write_1A_1P(0xB5,0x00);
NT35532_DCS_write_1A_1P(0xB6,0x49);
NT35532_DCS_write_1A_1P(0xB7,0x00);
NT35532_DCS_write_1A_1P(0xB8,0x7A);
NT35532_DCS_write_1A_1P(0xB9,0x00);
NT35532_DCS_write_1A_1P(0xBA,0x98);
NT35532_DCS_write_1A_1P(0xBB,0x00);
NT35532_DCS_write_1A_1P(0xBC,0xAF);
NT35532_DCS_write_1A_1P(0xBD,0x00);
NT35532_DCS_write_1A_1P(0xBE,0xC3);
NT35532_DCS_write_1A_1P(0xBF,0x00);
NT35532_DCS_write_1A_1P(0xC0,0xD7);
NT35532_DCS_write_1A_1P(0xC1,0x00);
NT35532_DCS_write_1A_1P(0xC2,0xE4);
NT35532_DCS_write_1A_1P(0xC3,0x00);
NT35532_DCS_write_1A_1P(0xC4,0xF3);
NT35532_DCS_write_1A_1P(0xC5,0x01);
NT35532_DCS_write_1A_1P(0xC6,0x23);
NT35532_DCS_write_1A_1P(0xC7,0x01);
NT35532_DCS_write_1A_1P(0xC8,0x48);
NT35532_DCS_write_1A_1P(0xC9,0x01);
NT35532_DCS_write_1A_1P(0xCA,0x85);
NT35532_DCS_write_1A_1P(0xCB,0x01);
NT35532_DCS_write_1A_1P(0xCC,0xB4);
NT35532_DCS_write_1A_1P(0xCD,0x01);
NT35532_DCS_write_1A_1P(0xCE,0xFD);
NT35532_DCS_write_1A_1P(0xCF,0x02);
NT35532_DCS_write_1A_1P(0xD0,0x3A);
NT35532_DCS_write_1A_1P(0xD1,0x02);
NT35532_DCS_write_1A_1P(0xD2,0x3B);
NT35532_DCS_write_1A_1P(0xD3,0x02);
NT35532_DCS_write_1A_1P(0xD4,0x6F);
NT35532_DCS_write_1A_1P(0xD5,0x02);
NT35532_DCS_write_1A_1P(0xD6,0xAE);
NT35532_DCS_write_1A_1P(0xD7,0x02);
NT35532_DCS_write_1A_1P(0xD8,0xD3);
NT35532_DCS_write_1A_1P(0xD9,0x03);
NT35532_DCS_write_1A_1P(0xDA,0x08);
NT35532_DCS_write_1A_1P(0xDB,0x03);
NT35532_DCS_write_1A_1P(0xDC,0x29);
NT35532_DCS_write_1A_1P(0xDD,0x03);
NT35532_DCS_write_1A_1P(0xDE,0x5C);
NT35532_DCS_write_1A_1P(0xDF,0x03);
NT35532_DCS_write_1A_1P(0xE0,0x67);
NT35532_DCS_write_1A_1P(0xE1,0x03);
NT35532_DCS_write_1A_1P(0xE2,0x6F);
NT35532_DCS_write_1A_1P(0xE3,0x03);
NT35532_DCS_write_1A_1P(0xE4,0x89);
NT35532_DCS_write_1A_1P(0xE5,0x03);
NT35532_DCS_write_1A_1P(0xE6,0xA3);
NT35532_DCS_write_1A_1P(0xE7,0x03);
NT35532_DCS_write_1A_1P(0xE8,0xBD);
NT35532_DCS_write_1A_1P(0xE9,0x03);
NT35532_DCS_write_1A_1P(0xEA,0xC0);
NT35532_DCS_write_1A_1P(0xEB,0x03);
NT35532_DCS_write_1A_1P(0xEC,0xE5);
NT35532_DCS_write_1A_1P(0xED,0x03);
NT35532_DCS_write_1A_1P(0xEE,0xF5);

NT35532_DCS_write_1A_1P(0xEF,0x00);
NT35532_DCS_write_1A_1P(0xF0,0x08);
NT35532_DCS_write_1A_1P(0xF1,0x00);
NT35532_DCS_write_1A_1P(0xF2,0x44);
NT35532_DCS_write_1A_1P(0xF3,0x00);
NT35532_DCS_write_1A_1P(0xF4,0x76);
NT35532_DCS_write_1A_1P(0xF5,0x00);
NT35532_DCS_write_1A_1P(0xF6,0x96);
NT35532_DCS_write_1A_1P(0xF7,0x00);
NT35532_DCS_write_1A_1P(0xF8,0xAE);
NT35532_DCS_write_1A_1P(0xF9,0x00);
NT35532_DCS_write_1A_1P(0xFA,0xC3);

NT35532_DCS_write_1A_1P(0xFF,0x02);
NT35532_DCS_write_1A_1P(0xFB,0x01);

NT35532_DCS_write_1A_1P(0x00,0x00);
NT35532_DCS_write_1A_1P(0x01,0xD4);
NT35532_DCS_write_1A_1P(0x02,0x00);
NT35532_DCS_write_1A_1P(0x03,0xE4);
NT35532_DCS_write_1A_1P(0x04,0x00);
NT35532_DCS_write_1A_1P(0x05,0xF3);
NT35532_DCS_write_1A_1P(0x06,0x01);
NT35532_DCS_write_1A_1P(0x07,0x23);
NT35532_DCS_write_1A_1P(0x08,0x01);
NT35532_DCS_write_1A_1P(0x09,0x48);
NT35532_DCS_write_1A_1P(0x0A,0x01);
NT35532_DCS_write_1A_1P(0x0B,0x84);
NT35532_DCS_write_1A_1P(0x0C,0x01);
NT35532_DCS_write_1A_1P(0x0D,0xB4);
NT35532_DCS_write_1A_1P(0x0E,0x01);
NT35532_DCS_write_1A_1P(0x0F,0xFE);
NT35532_DCS_write_1A_1P(0x10,0x02);
NT35532_DCS_write_1A_1P(0x11,0x38);
NT35532_DCS_write_1A_1P(0x12,0x02);
NT35532_DCS_write_1A_1P(0x13,0x3A);
NT35532_DCS_write_1A_1P(0x14,0x02);
NT35532_DCS_write_1A_1P(0x15,0x70);
NT35532_DCS_write_1A_1P(0x16,0x02);
NT35532_DCS_write_1A_1P(0x17,0xAB);
NT35532_DCS_write_1A_1P(0x18,0x02);
NT35532_DCS_write_1A_1P(0x19,0xD3);
NT35532_DCS_write_1A_1P(0x1A,0x03);
NT35532_DCS_write_1A_1P(0x1B,0x08);
NT35532_DCS_write_1A_1P(0x1C,0x03);
NT35532_DCS_write_1A_1P(0x1D,0x2C);
NT35532_DCS_write_1A_1P(0x1E,0x03);
NT35532_DCS_write_1A_1P(0x1F,0x59);
NT35532_DCS_write_1A_1P(0x20,0x03);
NT35532_DCS_write_1A_1P(0x21,0x68);
NT35532_DCS_write_1A_1P(0x22,0x03);
NT35532_DCS_write_1A_1P(0x23,0x71);
NT35532_DCS_write_1A_1P(0x24,0x03);
NT35532_DCS_write_1A_1P(0x25,0x8A);
NT35532_DCS_write_1A_1P(0x26,0x03);
NT35532_DCS_write_1A_1P(0x27,0xA4);
NT35532_DCS_write_1A_1P(0x28,0x03);
NT35532_DCS_write_1A_1P(0x29,0xBE);
NT35532_DCS_write_1A_1P(0x2A,0x03);
NT35532_DCS_write_1A_1P(0x2B,0xE4);
NT35532_DCS_write_1A_1P(0x2D,0x03);
NT35532_DCS_write_1A_1P(0x2F,0xF2);
NT35532_DCS_write_1A_1P(0x30,0x03);
NT35532_DCS_write_1A_1P(0x31,0xFB);

NT35532_DCS_write_1A_1P(0x32,0x00);
NT35532_DCS_write_1A_1P(0x33,0x08);
NT35532_DCS_write_1A_1P(0x34,0x00);
NT35532_DCS_write_1A_1P(0x35,0x44);
NT35532_DCS_write_1A_1P(0x36,0x00);
NT35532_DCS_write_1A_1P(0x37,0x76);
NT35532_DCS_write_1A_1P(0x38,0x00);
NT35532_DCS_write_1A_1P(0x39,0x96);
NT35532_DCS_write_1A_1P(0x3A,0x00);
NT35532_DCS_write_1A_1P(0x3B,0xAE);
NT35532_DCS_write_1A_1P(0x3D,0x00);
NT35532_DCS_write_1A_1P(0x3F,0xC3);
NT35532_DCS_write_1A_1P(0x40,0x00);
NT35532_DCS_write_1A_1P(0x41,0xD4);
NT35532_DCS_write_1A_1P(0x42,0x00);
NT35532_DCS_write_1A_1P(0x43,0xE4);
NT35532_DCS_write_1A_1P(0x44,0x00);
NT35532_DCS_write_1A_1P(0x45,0xF3);
NT35532_DCS_write_1A_1P(0x46,0x01);
NT35532_DCS_write_1A_1P(0x47,0x23);
NT35532_DCS_write_1A_1P(0x48,0x01);
NT35532_DCS_write_1A_1P(0x49,0x48);
NT35532_DCS_write_1A_1P(0x4A,0x01);
NT35532_DCS_write_1A_1P(0x4B,0x84);
NT35532_DCS_write_1A_1P(0x4C,0x01);
NT35532_DCS_write_1A_1P(0x4D,0xB4);
NT35532_DCS_write_1A_1P(0x4E,0x01);
NT35532_DCS_write_1A_1P(0x4F,0xFE);
NT35532_DCS_write_1A_1P(0x50,0x02);
NT35532_DCS_write_1A_1P(0x51,0x38);
NT35532_DCS_write_1A_1P(0x52,0x02);
NT35532_DCS_write_1A_1P(0x53,0x3A);
NT35532_DCS_write_1A_1P(0x54,0x02);
NT35532_DCS_write_1A_1P(0x55,0x70);
NT35532_DCS_write_1A_1P(0x56,0x02);
NT35532_DCS_write_1A_1P(0x58,0xAB);
NT35532_DCS_write_1A_1P(0x59,0x02);
NT35532_DCS_write_1A_1P(0x5A,0xD3);
NT35532_DCS_write_1A_1P(0x5B,0x03);
NT35532_DCS_write_1A_1P(0x5C,0x08);
NT35532_DCS_write_1A_1P(0x5D,0x03);
NT35532_DCS_write_1A_1P(0x5E,0x2C);
NT35532_DCS_write_1A_1P(0x5F,0x03);
NT35532_DCS_write_1A_1P(0x60,0x59);
NT35532_DCS_write_1A_1P(0x61,0x03);
NT35532_DCS_write_1A_1P(0x62,0x68);
NT35532_DCS_write_1A_1P(0x63,0x03);
NT35532_DCS_write_1A_1P(0x64,0x71);
NT35532_DCS_write_1A_1P(0x65,0x03);
NT35532_DCS_write_1A_1P(0x66,0x8A);
NT35532_DCS_write_1A_1P(0x67,0x03);
NT35532_DCS_write_1A_1P(0x68,0xA4);
NT35532_DCS_write_1A_1P(0x69,0x03);
NT35532_DCS_write_1A_1P(0x6A,0xBE);
NT35532_DCS_write_1A_1P(0x6B,0x03);
NT35532_DCS_write_1A_1P(0x6C,0xE4);
NT35532_DCS_write_1A_1P(0x6D,0x03);
NT35532_DCS_write_1A_1P(0x6E,0xF2);
NT35532_DCS_write_1A_1P(0x6F,0x03);
NT35532_DCS_write_1A_1P(0x70,0xFB);

NT35532_DCS_write_1A_1P(0x71,0x00);
NT35532_DCS_write_1A_1P(0x72,0x02);
NT35532_DCS_write_1A_1P(0x73,0x00);
NT35532_DCS_write_1A_1P(0x74,0x34);
NT35532_DCS_write_1A_1P(0x75,0x00);
NT35532_DCS_write_1A_1P(0x76,0x64);
NT35532_DCS_write_1A_1P(0x77,0x00);
NT35532_DCS_write_1A_1P(0x78,0x85);
NT35532_DCS_write_1A_1P(0x79,0x00);
NT35532_DCS_write_1A_1P(0x7A,0x9D);
NT35532_DCS_write_1A_1P(0x7B,0x00);
NT35532_DCS_write_1A_1P(0x7C,0xB2);
NT35532_DCS_write_1A_1P(0x7D,0x00);
NT35532_DCS_write_1A_1P(0x7E,0xC4);
NT35532_DCS_write_1A_1P(0x7F,0x00);
NT35532_DCS_write_1A_1P(0x80,0xD4);
NT35532_DCS_write_1A_1P(0x81,0x00);
NT35532_DCS_write_1A_1P(0x82,0xE3);
NT35532_DCS_write_1A_1P(0x83,0x01);
NT35532_DCS_write_1A_1P(0x84,0x15);
NT35532_DCS_write_1A_1P(0x85,0x01);
NT35532_DCS_write_1A_1P(0x86,0x3C);
NT35532_DCS_write_1A_1P(0x87,0x01);
NT35532_DCS_write_1A_1P(0x88,0x7A);
NT35532_DCS_write_1A_1P(0x89,0x01);
NT35532_DCS_write_1A_1P(0x8A,0xAB);
NT35532_DCS_write_1A_1P(0x8B,0x01);
NT35532_DCS_write_1A_1P(0x8C,0xF8);
NT35532_DCS_write_1A_1P(0x8D,0x02);
NT35532_DCS_write_1A_1P(0x8E,0x35);
NT35532_DCS_write_1A_1P(0x8F,0x02);
NT35532_DCS_write_1A_1P(0x90,0x37);
NT35532_DCS_write_1A_1P(0x91,0x02);
NT35532_DCS_write_1A_1P(0x92,0x6C);
NT35532_DCS_write_1A_1P(0x93,0x02);
NT35532_DCS_write_1A_1P(0x94,0xAA);
NT35532_DCS_write_1A_1P(0x95,0x02);
NT35532_DCS_write_1A_1P(0x96,0xD2);
NT35532_DCS_write_1A_1P(0x97,0x03);
NT35532_DCS_write_1A_1P(0x98,0x0B);
NT35532_DCS_write_1A_1P(0x99,0x03);
NT35532_DCS_write_1A_1P(0x9A,0x36);
NT35532_DCS_write_1A_1P(0x9B,0x03);
NT35532_DCS_write_1A_1P(0x9C,0x7D);
NT35532_DCS_write_1A_1P(0x9D,0x03);
NT35532_DCS_write_1A_1P(0x9E,0xA7);
NT35532_DCS_write_1A_1P(0x9F,0x03);
NT35532_DCS_write_1A_1P(0xA0,0xFB);
NT35532_DCS_write_1A_1P(0xA2,0x03);
NT35532_DCS_write_1A_1P(0xA3,0xFB);
NT35532_DCS_write_1A_1P(0xA4,0x03);
NT35532_DCS_write_1A_1P(0xA5,0xFB);
NT35532_DCS_write_1A_1P(0xA6,0x03);
NT35532_DCS_write_1A_1P(0xA7,0xFC);
NT35532_DCS_write_1A_1P(0xA9,0x03);
NT35532_DCS_write_1A_1P(0xAA,0xFE);
NT35532_DCS_write_1A_1P(0xAB,0x03);
NT35532_DCS_write_1A_1P(0xAC,0xFE);
NT35532_DCS_write_1A_1P(0xAD,0x03);
NT35532_DCS_write_1A_1P(0xAE,0xFE);

NT35532_DCS_write_1A_1P(0xAF,0x00);
NT35532_DCS_write_1A_1P(0xB0,0x02);
NT35532_DCS_write_1A_1P(0xB1,0x00);
NT35532_DCS_write_1A_1P(0xB2,0x34);
NT35532_DCS_write_1A_1P(0xB3,0x00);
NT35532_DCS_write_1A_1P(0xB4,0x64);
NT35532_DCS_write_1A_1P(0xB5,0x00);
NT35532_DCS_write_1A_1P(0xB6,0x85);
NT35532_DCS_write_1A_1P(0xB7,0x00);
NT35532_DCS_write_1A_1P(0xB8,0x9D);
NT35532_DCS_write_1A_1P(0xB9,0x00);
NT35532_DCS_write_1A_1P(0xBA,0xB2);
NT35532_DCS_write_1A_1P(0xBB,0x00);
NT35532_DCS_write_1A_1P(0xBC,0xC4);
NT35532_DCS_write_1A_1P(0xBD,0x00);
NT35532_DCS_write_1A_1P(0xBE,0xD4);
NT35532_DCS_write_1A_1P(0xBF,0x00);
NT35532_DCS_write_1A_1P(0xC0,0xE3);
NT35532_DCS_write_1A_1P(0xC1,0x01);
NT35532_DCS_write_1A_1P(0xC2,0x15);
NT35532_DCS_write_1A_1P(0xC3,0x01);
NT35532_DCS_write_1A_1P(0xC4,0x3C);
NT35532_DCS_write_1A_1P(0xC5,0x01);
NT35532_DCS_write_1A_1P(0xC6,0x7A);
NT35532_DCS_write_1A_1P(0xC7,0x01);
NT35532_DCS_write_1A_1P(0xC8,0xAB);
NT35532_DCS_write_1A_1P(0xC9,0x01);
NT35532_DCS_write_1A_1P(0xCA,0xF8);
NT35532_DCS_write_1A_1P(0xCB,0x02);
NT35532_DCS_write_1A_1P(0xCC,0x35);
NT35532_DCS_write_1A_1P(0xCD,0x02);
NT35532_DCS_write_1A_1P(0xCE,0x37);
NT35532_DCS_write_1A_1P(0xCF,0x02);
NT35532_DCS_write_1A_1P(0xD0,0x6C);
NT35532_DCS_write_1A_1P(0xD1,0x02);
NT35532_DCS_write_1A_1P(0xD2,0xAA);
NT35532_DCS_write_1A_1P(0xD3,0x02);
NT35532_DCS_write_1A_1P(0xD4,0xD2);
NT35532_DCS_write_1A_1P(0xD5,0x03);
NT35532_DCS_write_1A_1P(0xD6,0x0B);
NT35532_DCS_write_1A_1P(0xD7,0x03);
NT35532_DCS_write_1A_1P(0xD8,0x36);
NT35532_DCS_write_1A_1P(0xD9,0x03);
NT35532_DCS_write_1A_1P(0xDA,0x7D);
NT35532_DCS_write_1A_1P(0xDB,0x03);
NT35532_DCS_write_1A_1P(0xDC,0xA7);
NT35532_DCS_write_1A_1P(0xDD,0x03);
NT35532_DCS_write_1A_1P(0xDE,0xFB);
NT35532_DCS_write_1A_1P(0xDF,0x03);
NT35532_DCS_write_1A_1P(0xE0,0xFB);
NT35532_DCS_write_1A_1P(0xE1,0x03);
NT35532_DCS_write_1A_1P(0xE2,0xFB);
NT35532_DCS_write_1A_1P(0xE3,0x03);
NT35532_DCS_write_1A_1P(0xE4,0xFC);
NT35532_DCS_write_1A_1P(0xE5,0x03);
NT35532_DCS_write_1A_1P(0xE6,0xFE);
NT35532_DCS_write_1A_1P(0xE7,0x03);
NT35532_DCS_write_1A_1P(0xE8,0xFE);
NT35532_DCS_write_1A_1P(0xE9,0x03);
NT35532_DCS_write_1A_1P(0xEA,0xFE);

NT35532_DCS_write_1A_1P(0xFF,0x05);

NT35532_DCS_write_1A_1P(0xFB,0x01);
NT35532_DCS_write_1A_1P(0x00,0x3F);
NT35532_DCS_write_1A_1P(0x01,0x3F);
NT35532_DCS_write_1A_1P(0x02,0x3F);
NT35532_DCS_write_1A_1P(0x03,0x3F);
NT35532_DCS_write_1A_1P(0x04,0x38);
NT35532_DCS_write_1A_1P(0x05,0x3F);
NT35532_DCS_write_1A_1P(0x06,0x3F);
NT35532_DCS_write_1A_1P(0x07,0x19);
NT35532_DCS_write_1A_1P(0x08,0x1D);
NT35532_DCS_write_1A_1P(0x09,0x3F);
NT35532_DCS_write_1A_1P(0x0A,0x3F);
NT35532_DCS_write_1A_1P(0x0B,0x1B);
NT35532_DCS_write_1A_1P(0x0C,0x17);
NT35532_DCS_write_1A_1P(0x0D,0x3F);
NT35532_DCS_write_1A_1P(0x0E,0x3F);
NT35532_DCS_write_1A_1P(0x0F,0x08);
NT35532_DCS_write_1A_1P(0x10,0x3F);
NT35532_DCS_write_1A_1P(0x11,0x10);
NT35532_DCS_write_1A_1P(0x12,0x3F);
NT35532_DCS_write_1A_1P(0x13,0x3F);
NT35532_DCS_write_1A_1P(0x14,0x3F);
NT35532_DCS_write_1A_1P(0x15,0x3F);
NT35532_DCS_write_1A_1P(0x16,0x3F);
NT35532_DCS_write_1A_1P(0x17,0x3F);
NT35532_DCS_write_1A_1P(0x18,0x38);
NT35532_DCS_write_1A_1P(0x19,0x18);
NT35532_DCS_write_1A_1P(0x1A,0x1C);
NT35532_DCS_write_1A_1P(0x1B,0x3F);
NT35532_DCS_write_1A_1P(0x1C,0x3F);
NT35532_DCS_write_1A_1P(0x1D,0x1A);
NT35532_DCS_write_1A_1P(0x1E,0x16);
NT35532_DCS_write_1A_1P(0x1F,0x3F);
NT35532_DCS_write_1A_1P(0x20,0x3F);
NT35532_DCS_write_1A_1P(0x21,0x3F);
NT35532_DCS_write_1A_1P(0x22,0x3F);
NT35532_DCS_write_1A_1P(0x23,0x06);
NT35532_DCS_write_1A_1P(0x24,0x3F);
NT35532_DCS_write_1A_1P(0x25,0x0E);
NT35532_DCS_write_1A_1P(0x26,0x3F);
NT35532_DCS_write_1A_1P(0x27,0x3F);
NT35532_DCS_write_1A_1P(0x54,0x06);
NT35532_DCS_write_1A_1P(0x55,0x05);
NT35532_DCS_write_1A_1P(0x56,0x04);
NT35532_DCS_write_1A_1P(0x58,0x03);
NT35532_DCS_write_1A_1P(0x59,0x1B);
NT35532_DCS_write_1A_1P(0x5A,0x1B);
NT35532_DCS_write_1A_1P(0x5B,0x01);
NT35532_DCS_write_1A_1P(0x5C,0x32);
NT35532_DCS_write_1A_1P(0x5E,0x18);
NT35532_DCS_write_1A_1P(0x5F,0x20);
NT35532_DCS_write_1A_1P(0x60,0x2B);
NT35532_DCS_write_1A_1P(0x61,0x2C);
NT35532_DCS_write_1A_1P(0x62,0x18);
NT35532_DCS_write_1A_1P(0x63,0x01);
NT35532_DCS_write_1A_1P(0x64,0x32);
NT35532_DCS_write_1A_1P(0x65,0x00);
NT35532_DCS_write_1A_1P(0x66,0x44);
NT35532_DCS_write_1A_1P(0x67,0x11);
NT35532_DCS_write_1A_1P(0x68,0x01);
NT35532_DCS_write_1A_1P(0x69,0x01);
NT35532_DCS_write_1A_1P(0x6A,0x04);
NT35532_DCS_write_1A_1P(0x6B,0x2C);
NT35532_DCS_write_1A_1P(0x6C,0x08);
NT35532_DCS_write_1A_1P(0x6D,0x08);
NT35532_DCS_write_1A_1P(0x78,0x00);
NT35532_DCS_write_1A_1P(0x79,0x00);
NT35532_DCS_write_1A_1P(0x7E,0x00);
NT35532_DCS_write_1A_1P(0x7F,0x00);
NT35532_DCS_write_1A_1P(0x80,0x00);
NT35532_DCS_write_1A_1P(0x81,0x00);
NT35532_DCS_write_1A_1P(0x8D,0x00);
NT35532_DCS_write_1A_1P(0x8E,0x00);
NT35532_DCS_write_1A_1P(0x8F,0xC0);
NT35532_DCS_write_1A_1P(0x90,0x73);
NT35532_DCS_write_1A_1P(0x91,0x10);
NT35532_DCS_write_1A_1P(0x92,0x07);
NT35532_DCS_write_1A_1P(0x96,0x11);
NT35532_DCS_write_1A_1P(0x97,0x14);
NT35532_DCS_write_1A_1P(0x98,0x00);
NT35532_DCS_write_1A_1P(0x99,0x00);
NT35532_DCS_write_1A_1P(0x9A,0x00);
NT35532_DCS_write_1A_1P(0x9B,0x61);
NT35532_DCS_write_1A_1P(0x9C,0x15);
NT35532_DCS_write_1A_1P(0x9D,0x30);
NT35532_DCS_write_1A_1P(0x9F,0x0F);
NT35532_DCS_write_1A_1P(0xA2,0xB0);
NT35532_DCS_write_1A_1P(0xA7,0x0A);
NT35532_DCS_write_1A_1P(0xA9,0x00);
NT35532_DCS_write_1A_1P(0xAA,0x70);
NT35532_DCS_write_1A_1P(0xAB,0xDA);
NT35532_DCS_write_1A_1P(0xAC,0xFF);
NT35532_DCS_write_1A_1P(0xAE,0xF4);
NT35532_DCS_write_1A_1P(0xAF,0x40);
NT35532_DCS_write_1A_1P(0xB0,0x7F);
NT35532_DCS_write_1A_1P(0xB1,0x16);
NT35532_DCS_write_1A_1P(0xB2,0x53);
NT35532_DCS_write_1A_1P(0xB3,0x00);
NT35532_DCS_write_1A_1P(0xB4,0x2A);
NT35532_DCS_write_1A_1P(0xB5,0x3A);
NT35532_DCS_write_1A_1P(0xB6,0xF0);
NT35532_DCS_write_1A_1P(0xBC,0x85);
NT35532_DCS_write_1A_1P(0xBD,0xF4);
NT35532_DCS_write_1A_1P(0xBE,0x33);
NT35532_DCS_write_1A_1P(0xBF,0x13);
NT35532_DCS_write_1A_1P(0xC0,0x77);
NT35532_DCS_write_1A_1P(0xC1,0x77);
NT35532_DCS_write_1A_1P(0xC2,0x77);
NT35532_DCS_write_1A_1P(0xC3,0x77);
NT35532_DCS_write_1A_1P(0xC4,0x77);
NT35532_DCS_write_1A_1P(0xC5,0x77);
NT35532_DCS_write_1A_1P(0xC6,0x77);
NT35532_DCS_write_1A_1P(0xC7,0x77);
NT35532_DCS_write_1A_1P(0xC8,0xAA);
NT35532_DCS_write_1A_1P(0xC9,0x2A);
NT35532_DCS_write_1A_1P(0xCA,0x00);
NT35532_DCS_write_1A_1P(0xCB,0xAA);
NT35532_DCS_write_1A_1P(0xCC,0x92);
NT35532_DCS_write_1A_1P(0xCD,0x00);
NT35532_DCS_write_1A_1P(0xCE,0x18);
NT35532_DCS_write_1A_1P(0xCF,0x88);
NT35532_DCS_write_1A_1P(0xD0,0xAA);
NT35532_DCS_write_1A_1P(0xD1,0x00);
NT35532_DCS_write_1A_1P(0xD2,0x00);
NT35532_DCS_write_1A_1P(0xD3,0x00);
NT35532_DCS_write_1A_1P(0xD6,0x02);
NT35532_DCS_write_1A_1P(0xD7,0x31);
NT35532_DCS_write_1A_1P(0xD8,0x7E);
NT35532_DCS_write_1A_1P(0xED,0x00);
NT35532_DCS_write_1A_1P(0xEE,0x00);
NT35532_DCS_write_1A_1P(0xEF,0x70);
NT35532_DCS_write_1A_1P(0xFA,0x03);
NT35532_DCS_write_1A_1P(0xFF,0x00);

	data_array[0]=0x00110500; // Display Off
	dsi_set_cmdq(data_array, 1, 1);
MDELAY(100);
	data_array[0]=0x00290500; // Display Off
	dsi_set_cmdq(data_array, 1, 1);
//MDELAY(20);
}


/*
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
*/

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

	params->dsi.mode = BURST_VDO_MODE;
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

	params->dsi.vertical_sync_active = 2;//2,12,2
	params->dsi.vertical_backporch = 6;//12,20,14
	params->dsi.vertical_frontporch = 14;//13,20,16
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 8;//20;//10,12,8
	params->dsi.horizontal_backporch = 60;//80,40,16
	params->dsi.horizontal_frontporch = 72;//60;//80,40,24,
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 430;//450;//450,250
	
	params->dsi.ssc_disable = 1;  // ssc disable control (1: disable, 0: enable, default: 0)

    params->dsi.clk_lp_per_line_enable=1;
    params->dsi.esd_check_enable = 1;
    params->dsi.customization_esd_check_enable = 1;

    params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
    params->dsi.lcm_esd_check_table[0].count = 1;
    params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9C;
	   params->dsi.noncont_clock = 1; 
      params->dsi.noncont_clock_period = 2; 
}



static void lcm_init(void)
{
	LCM_LOGI("lcm_init enter\n");
	agold_lcm_power_on();
	
	SET_RESET_PIN(1);
	//MDELAY(20);
	SET_RESET_PIN(0);
	//MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(10);
	//push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
	init_lcm_registers();
	//LCM_LOGI("[cp] %s,reg[%x]: = %x\n", __func__, init_setting[9].cmd,init_setting[9].para_list[0]);
}

static void lcm_resume(void)
{
	//LCM_LOGI("lcm_resume enter\n");
	//init_setting[30].para_list[0]-=0x01;
	//init_setting[31].para_list[0]-=0x01;
	
   // LCM_LOGI("VCOM is :%d",init_setting[30].para_list[0]);
   // LCM_LOGI("VCOM is :%d",init_setting[31].para_list[0]);
	//LCM_LOGI("[cp] %s,reg[%x]: = %x\n", __func__, init_setting[9].cmd,init_setting[9].para_list[0]);
	lcm_init();
}

static void lcm_suspend(void)
{ 	
	unsigned int data_array[16];
	LCM_LOGI("lcm_suspend enter\n");
	data_array[0]=0x00280500; // Display Off
	dsi_set_cmdq(data_array, 1, 1);
	
	data_array[0] = 0x00100500; // Sleep In
	dsi_set_cmdq(data_array, 1, 1);

	MDELAY(120);
	SET_RESET_PIN(0);
	MDELAY(60);
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
	
	id = lcm_id_index(b);
	
	#ifdef BUILD_LK
	printf("Jason in lk B55027X2NA id = %d\n", id);	
	#else
	printk("Jason in kernel B55027X2NA id = %d\n", id);
	#endif
	
	return (id==5) ? 1:0;
	
}


static void lcm_init_power(void)
{
	LCM_LOGI("[cp]lcm_init_power enter\n");
}


LCM_DRIVER B55027X2NA_lcm_drv = {
	.name = "B55027X2NA",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};

