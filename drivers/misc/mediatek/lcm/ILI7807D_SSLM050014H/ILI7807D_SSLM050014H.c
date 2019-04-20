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
#define LCM_LOGI(fmt, args...)  pr_err("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_err("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

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

static struct LCM_setting_table init_setting[] = {
    {0xFF,03,{0x78,0x07,0x01}},	                 //Page1
    {0x42,01,{0x11}},	                 //VGH=x4 VGL=x4
    {0x43,01,{0x99}},	                 //VGH_CLP = 8.5V  disable
    {0x44,01,{0xA3}},	                 //VGL_CLP = -8.5V   disable

    {0x45,01,{0x19}},	                 //VGHO = 8.5V
    {0x46,01,{0x2D}},	                 //VGLO = -8.5V

    {0x4A,01,{0x02}},	                 //VSPR short to VSP
    {0x4B,01,{0x02}},	                 //VSNR short to VSN

    {0x50,01,{0x29}},	                 //GVDDP = 3.82V
    {0x51,01,{0x29}},	                 //GVDDN = -3.82V

    {0xA2,01,{0x01}},	                 //VCOM1 = - 0.32V
    {0xA3,01,{0x1C}},	                 //VCOM1 = - 0.32V

    {0xB3,01,{0x60}},	                 //VGHO short to VGH
    {0xB4,01,{0x60}},	                 //VGLO short to VGL


    {0xFF,03,{0x78,0x07,0x01}},	                 //Page1
    {0x22,01,{0x06}},	                 //SS&NW
    {0x36,01,{0x00}},	               
    {0x64,01,{0x08}},
    {0x6C,01,{0x45}},	                 //PRC & PRCB
    {0x6D,01,{0x00}},	                 //PCT2
    {0x5A,01,{0x33}},	                 //LVD 

    {0xFF,03,{0x78,0x07,0x06}},	                 //Page6
    {0x00,01,{0x41}},
    {0x01,01,{0x01}},
    {0x02,01,{0x44}},
    {0x03,01,{0x44}},
    {0x04,01,{0x02}},
    {0x05,01,{0x01}},                        // auo c
    {0x06,01,{0x08}},
    {0x07,01,{0x81}},                        // aui c
    {0x08,01,{0x00}},
    {0x09,01,{0x00}},
    {0x0A,01,{0x10}},
    {0x0B,01,{0x30}},
    {0x0C,01,{0x08}},
    {0x0D,01,{0x08}},
    {0x0E,01,{0x00}},
    {0x0F,01,{0x00}},
    {0x10,01,{0x00}},
    {0x11,01,{0x00}},
    {0x12,01,{0x00}},
    {0x13,01,{0x00}},
    {0x14,01,{0x00}},
    {0x15,01,{0x00}},

    {0x31,01,{0x08}},
    {0x32,01,{0x01}},
    {0x33,01,{0x00}},
    {0x34,01,{0x11}},
    {0x35,01,{0x10}},
    {0x36,01,{0x26}},
    {0x37,01,{0x22}},
    {0x38,01,{0x22}},
    {0x39,01,{0x0C}},
    {0x3A,01,{0x02}},
    {0x3B,01,{0x02}},
    {0x3C,01,{0x02}},
    {0x3D,01,{0x02}},
    {0x3E,01,{0x28}},
    {0x3F,01,{0x29}},
    {0x40,01,{0x2A}},

    {0x41,01,{0x08}},
    {0x42,01,{0x01}},
    {0x43,01,{0x00}},
    {0x44,01,{0x11}},
    {0x45,01,{0x10}},
    {0x46,01,{0x26}},
    {0x47,01,{0x22}},
    {0x48,01,{0x02}},
    {0x49,01,{0x0C}},
    {0x4A,01,{0x02}},
    {0x4B,01,{0x02}},
    {0x4C,01,{0x02}},
    {0x4D,01,{0x02}},
    {0x4E,01,{0x28}},
    {0x4F,01,{0x29}},
    {0x50,01,{0x2A}},

    {0x61,01,{0x0C}},
    {0x62,01,{0x01}},
    {0x63,01,{0x00}},
    {0x64,01,{0x10}},
    {0x65,01,{0x11}},
    {0x66,01,{0x26}},
    {0x67,01,{0x22}},
    {0x68,01,{0x22}},
    {0x69,01,{0x08}},
    {0x6A,01,{0x02}},
    {0x6B,01,{0x02}},
    {0x6C,01,{0x02}},
    {0x6D,01,{0x02}},
    {0x6E,01,{0x28}},
    {0x6F,01,{0x29}},
    {0x70,01,{0x2A}},

    {0x71,01,{0x0C}},
    {0x72,01,{0x01}},
    {0x73,01,{0x00}},
    {0x74,01,{0x10}},
    {0x75,01,{0x11}},
    {0x76,01,{0x26}},
    {0x77,01,{0x22}},
    {0x78,01,{0x02}},
    {0x79,01,{0x08}},
    {0x7A,01,{0x02}},
    {0x7B,01,{0x02}},
    {0x7C,01,{0x02}},
    {0x7D,01,{0x02}},
    {0x7E,01,{0x28}},
    {0x7F,01,{0x29}},
    {0x80,01,{0x2A}},

    {0xD0,01,{0x01}},
    {0xD1,01,{0x01}},
    {0xD2,01,{0x10}},
    {0xD3,01,{0x00}},
    {0xD4,01,{0x00}},
    {0xD5,01,{0x00}},
    {0xD6,01,{0x00}},
    {0xD7,01,{0x00}},
    {0xD8,01,{0x00}},
    {0xD9,01,{0x00}},
    {0xDA,01,{0x00}},
    {0xDB,01,{0x47}},
    {0xDC,01,{0x06}},
    {0xDD,01,{0x55}},
    {0x96,01,{0x00}},
    {0x97,01,{0x12}},
    {0xA0,01,{0x10}},
    {0xA1,01,{0x00}},
    {0xA2,01,{0x08}},
    {0xA3,01,{0x1E}},
    {0xA7,01,{0x00}},
    {0xE5,01,{0x80}},
    {0xB2,01,{0x00}},
    {0xB3,01,{0x00}},

    {0xE3,01,{0x00}},    
    {0x10,01,{0x05}}, 
    {0x11,01,{0x05}},
    {0x12,01,{0x05}},
    {0x13,01,{0x05}},

    {0xFF,03,{0x78,0x07,0x02}},

    {0x00,01,{0x00}},    //255
    {0x01,01,{0x17}},    //255
    {0x02,01,{0x00}},    //254
    {0x03,01,{0x25}},    //254
    {0x04,01,{0x00}},    //252
    {0x05,01,{0x40}},    //252
    {0x06,01,{0x00}},    //250
    {0x07,01,{0x56}},    //250
    {0x08,01,{0x00}},    //248
    {0x09,01,{0x69}},    //248
    {0x0A,01,{0x00}},    //246
    {0x0B,01,{0x7B}},    //246
    {0x0C,01,{0x00}},    //244
    {0x0D,01,{0x8B}},    //244
    {0x0E,01,{0x00}},    //242
    {0x0F,01,{0x9A}},    //242
    {0x10,01,{0x00}},    //240
    {0x11,01,{0xA8}},    //240
    {0x12,01,{0x00}},    //232
    {0x13,01,{0xD7}},    //232
    {0x14,01,{0x00}},    //224
    {0x15,01,{0xFE}},    //224
    {0x16,01,{0x01}},    //208
    {0x17,01,{0x3E}},    //208
    {0x18,01,{0x01}},    //192
    {0x19,01,{0x70}},    //192
    {0x1A,01,{0x01}},    //160
    {0x1B,01,{0xC0}},    //160
    {0x1C,01,{0x01}},    //128
    {0x1D,01,{0xFF}},    //128
    {0x1E,01,{0x02}},    //127
    {0x1F,01,{0x01}},    //127
    {0x20,01,{0x02}},    //95
    {0x21,01,{0x39}},    //95
    {0x22,01,{0x02}},    //63
    {0x23,01,{0x75}},    //63
    {0x24,01,{0x02}},    //47
    {0x25,01,{0x9C}},    //47
    {0x26,01,{0x02}},    //31
    {0x27,01,{0xD2}},    //31
    {0x28,01,{0x02}},    //23
    {0x29,01,{0xF5}},    //23
    {0x2A,01,{0x03}},    //15
    {0x2B,01,{0x22}},    //15
    {0x2C,01,{0x03}},    //13
    {0x2D,01,{0x30}},    //13
    {0x2E,01,{0x03}},    //11
    {0x2F,01,{0x40}},    //11
    {0x30,01,{0x03}},    //9
    {0x31,01,{0x52}},    //9
    {0x32,01,{0x03}},    //7
    {0x33,01,{0x65}},    //7
    {0x34,01,{0x03}},    //5
    {0x35,01,{0x7D}},    //5
    {0x36,01,{0x03}},    //3
    {0x37,01,{0xA2}},    //3
    {0x38,01,{0x03}},    //1
    {0x39,01,{0xCF}},    //1
    {0x3A,01,{0x03}},    //0
    {0x3B,01,{0xE6}},    //0

    {0x3C,01,{0x00}},    //255
    {0x3D,01,{0x17}},    //255
    {0x3E,01,{0x00}},    //254
    {0x3F,01,{0x25}},    //254
    {0x40,01,{0x00}},    //252
    {0x41,01,{0x40}},    //252
    {0x42,01,{0x00}},    //250
    {0x43,01,{0x56}},    //250
    {0x44,01,{0x00}},    //248
    {0x45,01,{0x69}},    //248
    {0x46,01,{0x00}},    //246
    {0x47,01,{0x7B}},    //246
    {0x48,01,{0x00}},    //244
    {0x49,01,{0x8B}},    //244
    {0x4A,01,{0x00}},    //242
    {0x4B,01,{0x9A}},    //242
    {0x4C,01,{0x00}},    //240
    {0x4D,01,{0xA8}},    //240
    {0x4E,01,{0x00}},    //232
    {0x4F,01,{0xD7}},    //232
    {0x50,01,{0x00}},    //224
    {0x51,01,{0xFE}},    //224
    {0x52,01,{0x01}},    //208
    {0x53,01,{0x3E}},    //208
    {0x54,01,{0x01}},    //192
    {0x55,01,{0x70}},    //192
    {0x56,01,{0x01}},    //160
    {0x57,01,{0xC0}},    //160
    {0x58,01,{0x01}},    //128
    {0x59,01,{0xFF}},    //128
    {0x5A,01,{0x02}},    //127
    {0x5B,01,{0x01}},    //127
    {0x5C,01,{0x02}},    //95
    {0x5D,01,{0x39}},    //95
    {0x5E,01,{0x02}},    //63
    {0x5F,01,{0x75}},    //63
    {0x60,01,{0x02}},    //47
    {0x61,01,{0x9C}},    //47
    {0x62,01,{0x02}},    //31
    {0x63,01,{0xD2}},    //31
    {0x64,01,{0x02}},    //23
    {0x65,01,{0xF5}},    //23
    {0x66,01,{0x03}},    //15
    {0x67,01,{0x22}},    //15
    {0x68,01,{0x03}},    //13
    {0x69,01,{0x30}},    //13
    {0x6A,01,{0x03}},    //11
    {0x6B,01,{0x40}},    //11
    {0x6C,01,{0x03}},    //9
    {0x6D,01,{0x52}},    //9
    {0x6E,01,{0x03}},    //7
    {0x6F,01,{0x65}},    //7
    {0x70,01,{0x03}},    //5
    {0x71,01,{0x7D}},    //5
    {0x72,01,{0x03}},    //3
    {0x73,01,{0xA2}},    //3
    {0x74,01,{0x03}},    //1
    {0x75,01,{0xCF}},    //1
    {0x76,01,{0x03}},    //0
    {0x77,01,{0xE6}},    //0

    {0x78,01,{0x01}},
    {0x79,01,{0x01}},

    {0xFF,03,{0x78,0x07,0x03}},

    {0x00,01,{0x00}},    //255
    {0x01,01,{0x13}},    //255
    {0x02,01,{0x00}},    //254
    {0x03,01,{0x22}},    //254
    {0x04,01,{0x00}},    //252
    {0x05,01,{0x3C}},    //252
    {0x06,01,{0x00}},    //250
    {0x07,01,{0x52}},    //250
    {0x08,01,{0x00}},    //248
    {0x09,01,{0x66}},    //248
    {0x0A,01,{0x00}},    //246
    {0x0B,01,{0x77}},    //246
    {0x0C,01,{0x00}},    //244
    {0x0D,01,{0x88}},    //244
    {0x0E,01,{0x00}},    //242
    {0x0F,01,{0x97}},    //242
    {0x10,01,{0x00}},    //240
    {0x11,01,{0xA4}},    //240
    {0x12,01,{0x00}},    //232
    {0x13,01,{0xD4}},    //232
    {0x14,01,{0x00}},    //224
    {0x15,01,{0xFC}},    //224
    {0x16,01,{0x01}},    //208
    {0x17,01,{0x3B}},    //208
    {0x18,01,{0x01}},    //192
    {0x19,01,{0x6E}},    //192
    {0x1A,01,{0x01}},    //160
    {0x1B,01,{0xBF}},    //160
    {0x1C,01,{0x01}},    //128
    {0x1D,01,{0xFF}},    //128
    {0x1E,01,{0x02}},    //127
    {0x1F,01,{0x01}},    //127
    {0x20,01,{0x02}},    //95
    {0x21,01,{0x3A}},    //95
    {0x22,01,{0x02}},    //63
    {0x23,01,{0x78}},    //63
    {0x24,01,{0x02}},    //47
    {0x25,01,{0xA1}},    //47
    {0x26,01,{0x02}},    //31
    {0x27,01,{0xD9}},    //31
    {0x28,01,{0x02}},    //23
    {0x29,01,{0xFE}},    //23
    {0x2A,01,{0x03}},    //15
    {0x2B,01,{0x2E}},    //15
    {0x2C,01,{0x03}},    //13
    {0x2D,01,{0x3C}},    //13
    {0x2E,01,{0x03}},    //11
    {0x2F,01,{0x4B}},    //11
    {0x30,01,{0x03}},    //9
    {0x31,01,{0x5B}},    //9
    {0x32,01,{0x03}},    //7
    {0x33,01,{0x6F}},    //7
    {0x34,01,{0x03}},    //5
    {0x35,01,{0x86}},    //5
    {0x36,01,{0x03}},    //3
    {0x37,01,{0xA7}},    //3
    {0x38,01,{0x03}},    //1
    {0x39,01,{0xD1}},    //1
    {0x3A,01,{0x03}},    //0
    {0x3B,01,{0xE6}},    //0

    {0x3C,01,{0x00}},    //255
    {0x3D,01,{0x13}},    //255
    {0x3E,01,{0x00}},    //254
    {0x3F,01,{0x22}},    //254
    {0x40,01,{0x00}},    //252
    {0x41,01,{0x3C}},    //252
    {0x42,01,{0x00}},    //250
    {0x43,01,{0x52}},    //250
    {0x44,01,{0x00}},    //248
    {0x45,01,{0x66}},    //248
    {0x46,01,{0x00}},    //246
    {0x47,01,{0x77}},    //246
    {0x48,01,{0x00}},    //244
    {0x49,01,{0x88}},    //244
    {0x4A,01,{0x00}},    //242
    {0x4B,01,{0x97}},    //242
    {0x4C,01,{0x00}},    //240
    {0x4D,01,{0xA4}},    //240
    {0x4E,01,{0x00}},    //232
    {0x4F,01,{0xD4}},    //232
    {0x50,01,{0x00}},    //224
    {0x51,01,{0xFC}},    //224
    {0x52,01,{0x01}},    //208
    {0x53,01,{0x3B}},    //208
    {0x54,01,{0x01}},    //192
    {0x55,01,{0x6E}},    //192
    {0x56,01,{0x01}},    //160
    {0x57,01,{0xBF}},    //160
    {0x58,01,{0x01}},    //128
    {0x59,01,{0xFF}},    //128
    {0x5A,01,{0x02}},    //127
    {0x5B,01,{0x01}},    //127
    {0x5C,01,{0x02}},    //95
    {0x5D,01,{0x3A}},    //95
    {0x5E,01,{0x02}},    //63
    {0x5F,01,{0x78}},    //63
    {0x60,01,{0x02}},    //47
    {0x61,01,{0xA1}},    //47
    {0x62,01,{0x02}},    //31
    {0x63,01,{0xD9}},    //31
    {0x64,01,{0x02}},    //23
    {0x65,01,{0xFE}},    //23
    {0x66,01,{0x03}},    //15
    {0x67,01,{0x2E}},    //15
    {0x68,01,{0x03}},    //13
    {0x69,01,{0x3C}},    //13
    {0x6A,01,{0x03}},    //11
    {0x6B,01,{0x4B}},    //11
    {0x6C,01,{0x03}},    //9
    {0x6D,01,{0x5B}},    //9
    {0x6E,01,{0x03}},    //7
    {0x6F,01,{0x6F}},    //7
    {0x70,01,{0x03}},    //5
    {0x71,01,{0x86}},    //5
    {0x72,01,{0x03}},    //3
    {0x73,01,{0xA7}},    //3
    {0x74,01,{0x03}},    //1
    {0x75,01,{0xD1}},    //1
    {0x76,01,{0x03}},    //0
    {0x77,01,{0xE6}},    //0

    {0x78,01,{0x01}},
    {0x79,01,{0x01}},

    {0xFF,03,{0x78,0x07,0x04}},

    {0x00,01,{0x00}},    //255
    {0x01,01,{0x0D}},    //255
    {0x02,01,{0x00}},    //254
    {0x03,01,{0x1C}},    //254
    {0x04,01,{0x00}},    //252
    {0x05,01,{0x35}},    //252
    {0x06,01,{0x00}},    //250
    {0x07,01,{0x4C}},    //250
    {0x08,01,{0x00}},    //248
    {0x09,01,{0x5F}},    //248
    {0x0A,01,{0x00}},    //246
    {0x0B,01,{0x71}},    //246
    {0x0C,01,{0x00}},    //244
    {0x0D,01,{0x82}},    //244
    {0x0E,01,{0x00}},    //242
    {0x0F,01,{0x91}},    //242
    {0x10,01,{0x00}},    //240
    {0x11,01,{0x9E}},    //240
    {0x12,01,{0x00}},    //232
    {0x13,01,{0xCF}},    //232
    {0x14,01,{0x00}},    //224
    {0x15,01,{0xF7}},    //224
    {0x16,01,{0x01}},    //208
    {0x17,01,{0x38}},    //208
    {0x18,01,{0x01}},    //192
    {0x19,01,{0x6B}},    //192
    {0x1A,01,{0x01}},    //160
    {0x1B,01,{0xBD}},    //160
    {0x1C,01,{0x01}},    //128
    {0x1D,01,{0xFD}},    //128
    {0x1E,01,{0x01}},    //127
    {0x1F,01,{0xFF}},    //127
    {0x20,01,{0x02}},    //95
    {0x21,01,{0x38}},    //95
    {0x22,01,{0x02}},    //63
    {0x23,01,{0x75}},    //63
    {0x24,01,{0x02}},    //47
    {0x25,01,{0x9D}},    //47
    {0x26,01,{0x02}},    //31
    {0x27,01,{0xD6}},    //31
    {0x28,01,{0x02}},    //23
    {0x29,01,{0xFF}},    //23
    {0x2A,01,{0x03}},    //15
    {0x2B,01,{0x3F}},    //15
    {0x2C,01,{0x03}},    //13
    {0x2D,01,{0x4B}},    //13
    {0x2E,01,{0x03}},    //11
    {0x2F,01,{0x59}},    //11
    {0x30,01,{0x03}},    //9
    {0x31,01,{0x67}},    //9
    {0x32,01,{0x03}},    //7
    {0x33,01,{0x79}},    //7
    {0x34,01,{0x03}},    //5
    {0x35,01,{0x8B}},    //5
    {0x36,01,{0x03}},    //3
    {0x37,01,{0xA9}},    //3
    {0x38,01,{0x03}},    //1
    {0x39,01,{0xD2}},    //1
    {0x3A,01,{0x03}},    //0
    {0x3B,01,{0xE6}},    //0

    {0x3C,01,{0x00}},    //255
    {0x3D,01,{0x0D}},    //255
    {0x3E,01,{0x00}},    //254
    {0x3F,01,{0x1C}},    //254
    {0x40,01,{0x00}},    //252
    {0x41,01,{0x35}},    //252
    {0x42,01,{0x00}},    //250
    {0x43,01,{0x4C}},    //250
    {0x44,01,{0x00}},    //248
    {0x45,01,{0x5F}},    //248
    {0x46,01,{0x00}},    //246
    {0x47,01,{0x71}},    //246
    {0x48,01,{0x00}},    //244
    {0x49,01,{0x82}},    //244
    {0x4A,01,{0x00}},    //242
    {0x4B,01,{0x91}},    //242
    {0x4C,01,{0x00}},    //240
    {0x4D,01,{0x9E}},    //240
    {0x4E,01,{0x00}},    //232
    {0x4F,01,{0xCF}},    //232
    {0x50,01,{0x00}},    //224
    {0x51,01,{0xF7}},    //224
    {0x52,01,{0x01}},    //208
    {0x53,01,{0x38}},    //208
    {0x54,01,{0x01}},    //192
    {0x55,01,{0x6B}},    //192
    {0x56,01,{0x01}},    //160
    {0x57,01,{0xBD}},    //160
    {0x58,01,{0x01}},    //128
    {0x59,01,{0xFD}},    //128
    {0x5A,01,{0x01}},    //127
    {0x5B,01,{0xFF}},    //127
    {0x5C,01,{0x02}},    //95
    {0x5D,01,{0x38}},    //95
    {0x5E,01,{0x02}},    //63
    {0x5F,01,{0x75}},    //63
    {0x60,01,{0x02}},    //47
    {0x61,01,{0x9D}},    //47
    {0x62,01,{0x02}},    //31
    {0x63,01,{0xD6}},    //31
    {0x64,01,{0x02}},    //23
    {0x65,01,{0xFF}},    //23
    {0x66,01,{0x03}},    //15
    {0x67,01,{0x3F}},    //15
    {0x68,01,{0x03}},    //13
    {0x69,01,{0x4B}},    //13
    {0x6A,01,{0x03}},    //11
    {0x6B,01,{0x59}},    //11
    {0x6C,01,{0x03}},    //9
    {0x6D,01,{0x67}},    //9
    {0x6E,01,{0x03}},    //7
    {0x6F,01,{0x79}},    //7
    {0x70,01,{0x03}},    //5
    {0x71,01,{0x8B}},    //5
    {0x72,01,{0x03}},    //3
    {0x73,01,{0xA9}},    //3
    {0x74,01,{0x03}},    //1
    {0x75,01,{0xD2}},    //1
    {0x76,01,{0x03}},    //0
    {0x77,01,{0xE6}},    //0

    {0x78,01,{0x01}},
    {0x79,01,{0x01}},

    {0xFF,03,{0x78,07,00}},
	{0x11, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 20, {}},

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
	LCM_LOGI("lcm_get_params\n");
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

	params->dsi.vertical_sync_active				= 8;
	params->dsi.vertical_backporch					= 24;
	params->dsi.vertical_frontporch					= 24;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active				= 8;//10;
	params->dsi.horizontal_backporch 				= 90;//100;
	params->dsi.horizontal_frontporch 				= 100;//100
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;

	params->dsi.ssc_disable = 1;  // ssc disable control (1: disable, 0: enable, default: 0)

	params->dsi.PLL_CLOCK = 480;//475;
}



static void lcm_init(void)
{
	LCM_LOGI("lcm_init enter\n");
	agold_lcm_power_on();
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(50);
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
	MDELAY(10);
	
	agold_lcm_power_down();
}

static unsigned int lcm_compare_id(void)
{
	unsigned int id1 = 0;
	unsigned int id2 = 0;		
	unsigned int id3 = 0;	

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
	
	if((id1 == 0) && (id2 == 0) && (id3 == 0))
		return 1;
	else
		return 0;
}

static void lcm_init_power(void)
{
	LCM_LOGI("lcm_init_power enter\n");
}


LCM_DRIVER ILI7807D_SSLM050014H_lcm_drv = {
	.name = "ILI7807D_SSLM050014H",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
