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

static void NT35532_DCS_write_1A_1P(unsigned char cmd, unsigned char para)
{
	unsigned int data_array[16] = {0};
	data_array[0] = (0x00022902);
	data_array[1] = (0x00000000 | (para<<8) | (cmd));
	dsi_set_cmdq(data_array, 2, 1);
}


static void init_lcm_registers(void)
{
unsigned int data_array[16]={0};

NT35532_DCS_write_1A_1P(0xFF,0x01);
//MDELAY(20);


NT35532_DCS_write_1A_1P(0xFB,0x01);

NT35532_DCS_write_1A_1P(0x00,0x01);
NT35532_DCS_write_1A_1P(0x01,0x55);
NT35532_DCS_write_1A_1P(0x02,0x59);
NT35532_DCS_write_1A_1P(0x04,0x0C);
NT35532_DCS_write_1A_1P(0x05,0x3A);
NT35532_DCS_write_1A_1P(0x06,0x41);
NT35532_DCS_write_1A_1P(0x07,0xc1);
//NT35532_DCS_write_1A_1P(0x0D,0x93);
//NT35532_DCS_write_1A_1P(0x0E,0x93);

NT35532_DCS_write_1A_1P(0x0D,0x79);		//49 69	//对比度	 		93=>49  对比度增强
NT35532_DCS_write_1A_1P(0x0E,0x79);

NT35532_DCS_write_1A_1P(0x0F,0x68);
NT35532_DCS_write_1A_1P(0x10,0x03);
NT35532_DCS_write_1A_1P(0x11,0x3C);
NT35532_DCS_write_1A_1P(0x12,0x50);

//NT35532_DCS_write_1A_1P(0x13,0x6d);//0x75	6a	65 	7A 80
//NT35532_DCS_write_1A_1P(0x14,0x6d);//0x75	6a	65	7A 80
//NT35532_DCS_write_1A_1P(0x13,0x70);
//NT35532_DCS_write_1A_1P(0x14,0x70);
NT35532_DCS_write_1A_1P(0x15,0x60);
NT35532_DCS_write_1A_1P(0x16,0x13);
NT35532_DCS_write_1A_1P(0x17,0x13);
// Gamma Dithering
//NT35532_DCS_write_1A_1P(0x68,0x13);
NT35532_DCS_write_1A_1P(0x6D,0x33);

#if 0
// R+ Gamma Setting                             
NT35532_DCS_write_1A_1P(0x75,0x00);                               
NT35532_DCS_write_1A_1P(0x76,0x00);          
NT35532_DCS_write_1A_1P(0x77,0x00);                                           
NT35532_DCS_write_1A_1P(0x78,0x1E);                                           
NT35532_DCS_write_1A_1P(0x79,0x00);                                           
NT35532_DCS_write_1A_1P(0x7A,0x4B);                                           
NT35532_DCS_write_1A_1P(0x7B,0x00);                                           
NT35532_DCS_write_1A_1P(0x7C,0x6E);                                           
NT35532_DCS_write_1A_1P(0x7D,0x00);                                           
NT35532_DCS_write_1A_1P(0x7E,0x88);                                           
NT35532_DCS_write_1A_1P(0x7F,0x00);                                           
NT35532_DCS_write_1A_1P(0x80,0x9F);                                           
NT35532_DCS_write_1A_1P(0x81,0x00);                                           
NT35532_DCS_write_1A_1P(0x82,0xB3);                                           
NT35532_DCS_write_1A_1P(0x83,0x00);                                          
NT35532_DCS_write_1A_1P(0x84,0xC5);                                           
NT35532_DCS_write_1A_1P(0x85,0x00);                                           
NT35532_DCS_write_1A_1P(0x86,0xD5);                                           
NT35532_DCS_write_1A_1P(0x87,0x01);                                           
NT35532_DCS_write_1A_1P(0x88,0x09);                                           
NT35532_DCS_write_1A_1P(0x89,0x01);                                           
NT35532_DCS_write_1A_1P(0x8A,0x31);                                           
NT35532_DCS_write_1A_1P(0x8B,0x01);                                           
NT35532_DCS_write_1A_1P(0x8C,0x6B);                                           
NT35532_DCS_write_1A_1P(0x8D,0x01);                                           
NT35532_DCS_write_1A_1P(0x8E,0x97);                                           
NT35532_DCS_write_1A_1P(0x8F,0x01);                                           
NT35532_DCS_write_1A_1P(0x90,0xD8);                                           
NT35532_DCS_write_1A_1P(0x91,0x02);                                           
NT35532_DCS_write_1A_1P(0x92,0x0C);                                           
NT35532_DCS_write_1A_1P(0x93,0x02);                                           
NT35532_DCS_write_1A_1P(0x94,0x0D);                                           
NT35532_DCS_write_1A_1P(0x95,0x02);                                           
NT35532_DCS_write_1A_1P(0x96,0x3F);                                           
NT35532_DCS_write_1A_1P(0x97,0x02);                                           
NT35532_DCS_write_1A_1P(0x98,0x77);                                           
NT35532_DCS_write_1A_1P(0x99,0x02);                                           
NT35532_DCS_write_1A_1P(0x9A,0x9C);                                           
NT35532_DCS_write_1A_1P(0x9B,0x02);                                           
NT35532_DCS_write_1A_1P(0x9C,0xCF);                                          
NT35532_DCS_write_1A_1P(0x9D,0x02);                                           
NT35532_DCS_write_1A_1P(0x9E,0xF0);                                           
NT35532_DCS_write_1A_1P(0x9F,0x03);                                           
NT35532_DCS_write_1A_1P(0xA0,0x1C);                                           
NT35532_DCS_write_1A_1P(0xA2,0x03);                                           
NT35532_DCS_write_1A_1P(0xA3,0x29);                                           
NT35532_DCS_write_1A_1P(0xA4,0x03);                                           
NT35532_DCS_write_1A_1P(0xA5,0x37);                                           
NT35532_DCS_write_1A_1P(0xA6,0x03);                                           
NT35532_DCS_write_1A_1P(0xA7,0x47);                                           
NT35532_DCS_write_1A_1P(0xA9,0x03);                                          
NT35532_DCS_write_1A_1P(0xAA,0x58);                                           
NT35532_DCS_write_1A_1P(0xAB,0x03);                                           
NT35532_DCS_write_1A_1P(0xAC,0x6C);                                           
NT35532_DCS_write_1A_1P(0xAD,0x03);                                           
NT35532_DCS_write_1A_1P(0xAE,0x80);                                           
NT35532_DCS_write_1A_1P(0xAF,0x03);                                           
NT35532_DCS_write_1A_1P(0xB0,0xF4);                                           
NT35532_DCS_write_1A_1P(0xB1,0x03);                                           
NT35532_DCS_write_1A_1P(0xB2,0xFF);                                           
                                                            
// R- Gamma Setting                                         
NT35532_DCS_write_1A_1P(0xB3,0x00);                            
NT35532_DCS_write_1A_1P(0xB4,0x00);                                                    
NT35532_DCS_write_1A_1P(0xB5,0x00);                            
NT35532_DCS_write_1A_1P(0xB6,0x1E);                            
NT35532_DCS_write_1A_1P(0xB7,0x00);                            
NT35532_DCS_write_1A_1P(0xB8,0x4B);                            
NT35532_DCS_write_1A_1P(0xB9,0x00);                            
NT35532_DCS_write_1A_1P(0xBA,0x6E);                            
NT35532_DCS_write_1A_1P(0xBB,0x00);                            
NT35532_DCS_write_1A_1P(0xBC,0x88);                            
NT35532_DCS_write_1A_1P(0xBD,0x00);                            
NT35532_DCS_write_1A_1P(0xBE,0x9F);                            
NT35532_DCS_write_1A_1P(0xBF,0x00);                            
NT35532_DCS_write_1A_1P(0xC0,0xB3);                            
NT35532_DCS_write_1A_1P(0xC1,0x00);                            
NT35532_DCS_write_1A_1P(0xC2,0xC5);                            
NT35532_DCS_write_1A_1P(0xC3,0x00);                            
NT35532_DCS_write_1A_1P(0xC4,0xD5);                            
NT35532_DCS_write_1A_1P(0xC5,0x01);                            
NT35532_DCS_write_1A_1P(0xC6,0x09);                            
NT35532_DCS_write_1A_1P(0xC7,0x01);                            
NT35532_DCS_write_1A_1P(0xC8,0x31);                            
NT35532_DCS_write_1A_1P(0xC9,0x01);                            
NT35532_DCS_write_1A_1P(0xCA,0x6B);                            
NT35532_DCS_write_1A_1P(0xCB,0x01);                            
NT35532_DCS_write_1A_1P(0xCC,0x97);                            
NT35532_DCS_write_1A_1P(0xCD,0x01);                            
NT35532_DCS_write_1A_1P(0xCE,0xD8);                            
NT35532_DCS_write_1A_1P(0xCF,0x02);                            
NT35532_DCS_write_1A_1P(0xD0,0x0C);                            
NT35532_DCS_write_1A_1P(0xD1,0x02);                            
NT35532_DCS_write_1A_1P(0xD2,0x0D);                            
NT35532_DCS_write_1A_1P(0xD3,0x02);                            
NT35532_DCS_write_1A_1P(0xD4,0x3F);                            
NT35532_DCS_write_1A_1P(0xD5,0x02);                            
NT35532_DCS_write_1A_1P(0xD6,0x77);                            
NT35532_DCS_write_1A_1P(0xD7,0x02);                            
NT35532_DCS_write_1A_1P(0xD8,0x9C);                            
NT35532_DCS_write_1A_1P(0xD9,0x02);                            
NT35532_DCS_write_1A_1P(0xDA,0xCF);                            
NT35532_DCS_write_1A_1P(0xDB,0x02);                            
NT35532_DCS_write_1A_1P(0xDC,0xF0);                            
NT35532_DCS_write_1A_1P(0xDD,0x03);                            
NT35532_DCS_write_1A_1P(0xDE,0x1C);                            
NT35532_DCS_write_1A_1P(0xDF,0x03);                            
NT35532_DCS_write_1A_1P(0xE0,0x29);                            
NT35532_DCS_write_1A_1P(0xE1,0x03);                            
NT35532_DCS_write_1A_1P(0xE2,0x37);                            
NT35532_DCS_write_1A_1P(0xE3,0x03);                            
NT35532_DCS_write_1A_1P(0xE4,0x47);                            
NT35532_DCS_write_1A_1P(0xE5,0x03);                            
NT35532_DCS_write_1A_1P(0xE6,0x58);                            
NT35532_DCS_write_1A_1P(0xE7,0x03);                            
NT35532_DCS_write_1A_1P(0xE8,0x6C);                            
NT35532_DCS_write_1A_1P(0xE9,0x03);                            
NT35532_DCS_write_1A_1P(0xEA,0x80);                            
NT35532_DCS_write_1A_1P(0xEB,0x03);                            
NT35532_DCS_write_1A_1P(0xEC,0xF4);                            
NT35532_DCS_write_1A_1P(0xED,0x03);                            
NT35532_DCS_write_1A_1P(0xEE,0xFF);                            
                                          
// G+ Gamma Setting                       
NT35532_DCS_write_1A_1P(0xEF,0x00);                            
NT35532_DCS_write_1A_1P(0xF0,0x00);                                                    
NT35532_DCS_write_1A_1P(0xF1,0x00);                            
NT35532_DCS_write_1A_1P(0xF2,0x1E);                            
NT35532_DCS_write_1A_1P(0xF3,0x00);                            
NT35532_DCS_write_1A_1P(0xF4,0x4B);                            
NT35532_DCS_write_1A_1P(0xF5,0x00);                            
NT35532_DCS_write_1A_1P(0xF6,0x6E);                            
NT35532_DCS_write_1A_1P(0xF7,0x00);                            
NT35532_DCS_write_1A_1P(0xF8,0x88);                            
NT35532_DCS_write_1A_1P(0xF9,0x00);                            
NT35532_DCS_write_1A_1P(0xFA,0x9F);                            
                 
                 
                                          
                                          
// Switch to CMD2_Page1 (Gamma)           
NT35532_DCS_write_1A_1P(0xFF,0x02);                            
//MDELAY(50); 
                                          
NT35532_DCS_write_1A_1P(0xFB,0x01);                            
                                          
// G+ Gamma Setting                       
NT35532_DCS_write_1A_1P(0x00,0x00);                            
NT35532_DCS_write_1A_1P(0x01,0xB3);                            
NT35532_DCS_write_1A_1P(0x02,0x00);                            
NT35532_DCS_write_1A_1P(0x03,0xC5);                            
NT35532_DCS_write_1A_1P(0x04,0x00);                            
NT35532_DCS_write_1A_1P(0x05,0xD5);                            
NT35532_DCS_write_1A_1P(0x06,0x01);                            
NT35532_DCS_write_1A_1P(0x07,0x09);                            
NT35532_DCS_write_1A_1P(0x08,0x01);                            
NT35532_DCS_write_1A_1P(0x09,0x31);                            
NT35532_DCS_write_1A_1P(0x0A,0x01);                            
NT35532_DCS_write_1A_1P(0x0B,0x6B);                            
NT35532_DCS_write_1A_1P(0x0C,0x01);                            
NT35532_DCS_write_1A_1P(0x0D,0x97);                            
NT35532_DCS_write_1A_1P(0x0E,0x01);                            
NT35532_DCS_write_1A_1P(0x0F,0xD8);                            
NT35532_DCS_write_1A_1P(0x10,0x02);                            
NT35532_DCS_write_1A_1P(0x11,0x0C);                            
NT35532_DCS_write_1A_1P(0x12,0x02);                            
NT35532_DCS_write_1A_1P(0x13,0x0D);                            
NT35532_DCS_write_1A_1P(0x14,0x02);                            
NT35532_DCS_write_1A_1P(0x15,0x3F);                            
NT35532_DCS_write_1A_1P(0x16,0x02);                            
NT35532_DCS_write_1A_1P(0x17,0x77);                            
NT35532_DCS_write_1A_1P(0x18,0x02);                            
NT35532_DCS_write_1A_1P(0x19,0x9C);                            
NT35532_DCS_write_1A_1P(0x1A,0x02);                            
NT35532_DCS_write_1A_1P(0x1B,0xCF);                            
NT35532_DCS_write_1A_1P(0x1C,0x02);                            
NT35532_DCS_write_1A_1P(0x1D,0xF0);                            
NT35532_DCS_write_1A_1P(0x1E,0x03);                            
NT35532_DCS_write_1A_1P(0x1F,0x1C);                            
NT35532_DCS_write_1A_1P(0x20,0x03);                            
NT35532_DCS_write_1A_1P(0x21,0x29);                            
NT35532_DCS_write_1A_1P(0x22,0x03);                            
NT35532_DCS_write_1A_1P(0x23,0x37);                            
NT35532_DCS_write_1A_1P(0x24,0x03);                            
NT35532_DCS_write_1A_1P(0x25,0x47);                            
NT35532_DCS_write_1A_1P(0x26,0x03);                            
NT35532_DCS_write_1A_1P(0x27,0x58);                            
NT35532_DCS_write_1A_1P(0x28,0x03);                            
NT35532_DCS_write_1A_1P(0x29,0x6C);                            
NT35532_DCS_write_1A_1P(0x2A,0x03);                            
NT35532_DCS_write_1A_1P(0x2B,0x80);                            
NT35532_DCS_write_1A_1P(0x2D,0x03);                            
NT35532_DCS_write_1A_1P(0x2F,0xF4);                            
NT35532_DCS_write_1A_1P(0x30,0x03);                            
NT35532_DCS_write_1A_1P(0x31,0xFF);                            
                                          
// G- Gamma Setting                       
NT35532_DCS_write_1A_1P(0x32,0x00);                            
NT35532_DCS_write_1A_1P(0x33,0x00);                                                     
NT35532_DCS_write_1A_1P(0x34,0x00);                            
NT35532_DCS_write_1A_1P(0x35,0x1E);                            
NT35532_DCS_write_1A_1P(0x36,0x00);                            
NT35532_DCS_write_1A_1P(0x37,0x4B);                            
NT35532_DCS_write_1A_1P(0x38,0x00);                            
NT35532_DCS_write_1A_1P(0x39,0x6E);                            
NT35532_DCS_write_1A_1P(0x3A,0x00);                            
NT35532_DCS_write_1A_1P(0x3B,0x88);                            
NT35532_DCS_write_1A_1P(0x3D,0x00);                            
NT35532_DCS_write_1A_1P(0x3F,0x9F);                            
NT35532_DCS_write_1A_1P(0x40,0x00);                            
NT35532_DCS_write_1A_1P(0x41,0xB3);                            
NT35532_DCS_write_1A_1P(0x42,0x00);                            
NT35532_DCS_write_1A_1P(0x43,0xC5);                            
NT35532_DCS_write_1A_1P(0x44,0x00);                            
NT35532_DCS_write_1A_1P(0x45,0xD5);                            
NT35532_DCS_write_1A_1P(0x46,0x01);                            
NT35532_DCS_write_1A_1P(0x47,0x09);                            
NT35532_DCS_write_1A_1P(0x48,0x01);                            
NT35532_DCS_write_1A_1P(0x49,0x31);                            
NT35532_DCS_write_1A_1P(0x4A,0x01);                            
NT35532_DCS_write_1A_1P(0x4B,0x6B);                            
NT35532_DCS_write_1A_1P(0x4C,0x01);                            
NT35532_DCS_write_1A_1P(0x4D,0x97);                            
NT35532_DCS_write_1A_1P(0x4E,0x01);                            
NT35532_DCS_write_1A_1P(0x4F,0xD8);                            
NT35532_DCS_write_1A_1P(0x50,0x02);                            
NT35532_DCS_write_1A_1P(0x51,0x0C);                            
NT35532_DCS_write_1A_1P(0x52,0x02);                            
NT35532_DCS_write_1A_1P(0x53,0x0D);                            
NT35532_DCS_write_1A_1P(0x54,0x02);                            
NT35532_DCS_write_1A_1P(0x55,0x3F);                            
NT35532_DCS_write_1A_1P(0x56,0x02);                            
NT35532_DCS_write_1A_1P(0x58,0x77);                            
NT35532_DCS_write_1A_1P(0x59,0x02);                            
NT35532_DCS_write_1A_1P(0x5A,0x9C);                            
NT35532_DCS_write_1A_1P(0x5B,0x02);                            
NT35532_DCS_write_1A_1P(0x5C,0xCF);                            
NT35532_DCS_write_1A_1P(0x5D,0x02);                            
NT35532_DCS_write_1A_1P(0x5E,0xF0);                            
NT35532_DCS_write_1A_1P(0x5F,0x03);                            
NT35532_DCS_write_1A_1P(0x60,0x1C);                            
NT35532_DCS_write_1A_1P(0x61,0x03);                            
NT35532_DCS_write_1A_1P(0x62,0x29);                            
NT35532_DCS_write_1A_1P(0x63,0x03);                            
NT35532_DCS_write_1A_1P(0x64,0x37);                            
NT35532_DCS_write_1A_1P(0x65,0x03);                            
NT35532_DCS_write_1A_1P(0x66,0x47);                            
NT35532_DCS_write_1A_1P(0x67,0x03);                            
NT35532_DCS_write_1A_1P(0x68,0x58);                            
NT35532_DCS_write_1A_1P(0x69,0x03);                            
NT35532_DCS_write_1A_1P(0x6A,0x6C);                            
NT35532_DCS_write_1A_1P(0x6B,0x03);                            
NT35532_DCS_write_1A_1P(0x6C,0x80);                            
NT35532_DCS_write_1A_1P(0x6D,0x03);                            
NT35532_DCS_write_1A_1P(0x6E,0xF4);                            
NT35532_DCS_write_1A_1P(0x6F,0x03);                            
NT35532_DCS_write_1A_1P(0x70,0xFF);                            
                                          
// B+ Gamma Setting                       
NT35532_DCS_write_1A_1P(0x71,0x00);                            
NT35532_DCS_write_1A_1P(0x72,0x00);                                                  
NT35532_DCS_write_1A_1P(0x73,0x00);                            
NT35532_DCS_write_1A_1P(0x74,0x1E);                            
NT35532_DCS_write_1A_1P(0x75,0x00);                            
NT35532_DCS_write_1A_1P(0x76,0x4B);                            
NT35532_DCS_write_1A_1P(0x77,0x00);                            
NT35532_DCS_write_1A_1P(0x78,0x6E);                            
NT35532_DCS_write_1A_1P(0x79,0x00);                            
NT35532_DCS_write_1A_1P(0x7A,0x88);                            
NT35532_DCS_write_1A_1P(0x7B,0x00);                            
NT35532_DCS_write_1A_1P(0x7C,0x9F);                            
NT35532_DCS_write_1A_1P(0x7D,0x00);                            
NT35532_DCS_write_1A_1P(0x7E,0xB3);                            
NT35532_DCS_write_1A_1P(0x7F,0x00);                            
NT35532_DCS_write_1A_1P(0x80,0xC5);                            
NT35532_DCS_write_1A_1P(0x81,0x00);                            
NT35532_DCS_write_1A_1P(0x82,0xD5);                            
NT35532_DCS_write_1A_1P(0x83,0x01);                            
NT35532_DCS_write_1A_1P(0x84,0x09);                            
NT35532_DCS_write_1A_1P(0x85,0x01);                            
NT35532_DCS_write_1A_1P(0x86,0x31);                            
NT35532_DCS_write_1A_1P(0x87,0x01);                            
NT35532_DCS_write_1A_1P(0x88,0x6B);                            
NT35532_DCS_write_1A_1P(0x89,0x01);                            
NT35532_DCS_write_1A_1P(0x8A,0x97);                            
NT35532_DCS_write_1A_1P(0x8B,0x01);                            
NT35532_DCS_write_1A_1P(0x8C,0xD8);                            
NT35532_DCS_write_1A_1P(0x8D,0x02);                            
NT35532_DCS_write_1A_1P(0x8E,0x0C);                            
NT35532_DCS_write_1A_1P(0x8F,0x02);                            
NT35532_DCS_write_1A_1P(0x90,0x0D);                            
NT35532_DCS_write_1A_1P(0x91,0x02);                            
NT35532_DCS_write_1A_1P(0x92,0x3F);                            
NT35532_DCS_write_1A_1P(0x93,0x02);                            
NT35532_DCS_write_1A_1P(0x94,0x77);                            
NT35532_DCS_write_1A_1P(0x95,0x02);                            
NT35532_DCS_write_1A_1P(0x96,0x9C);                            
NT35532_DCS_write_1A_1P(0x97,0x02);                            
NT35532_DCS_write_1A_1P(0x98,0xCF);                            
NT35532_DCS_write_1A_1P(0x99,0x02);                            
NT35532_DCS_write_1A_1P(0x9A,0xF0);                            
NT35532_DCS_write_1A_1P(0x9B,0x03);                            
NT35532_DCS_write_1A_1P(0x9C,0x1C);                            
NT35532_DCS_write_1A_1P(0x9D,0x03);                            
NT35532_DCS_write_1A_1P(0x9E,0x29);                            
NT35532_DCS_write_1A_1P(0x9F,0x03);                            
NT35532_DCS_write_1A_1P(0xA0,0x37);                            
NT35532_DCS_write_1A_1P(0xA2,0x03);                            
NT35532_DCS_write_1A_1P(0xA3,0x47);                            
NT35532_DCS_write_1A_1P(0xA4,0x03);                            
NT35532_DCS_write_1A_1P(0xA5,0x58);                            
NT35532_DCS_write_1A_1P(0xA6,0x03);                            
NT35532_DCS_write_1A_1P(0xA7,0x6C);                            
NT35532_DCS_write_1A_1P(0xA9,0x03);                            
NT35532_DCS_write_1A_1P(0xAA,0x80);                            
NT35532_DCS_write_1A_1P(0xAB,0x03);                            
NT35532_DCS_write_1A_1P(0xAC,0xF4);                            
NT35532_DCS_write_1A_1P(0xAD,0x03);                            
NT35532_DCS_write_1A_1P(0xAE,0xFF);                            
                                          
// B- Gamma Setting                       
NT35532_DCS_write_1A_1P(0xAF,0x00);                            
NT35532_DCS_write_1A_1P(0xB0,0x00);                                                 
NT35532_DCS_write_1A_1P(0xB1,0x00);                            
NT35532_DCS_write_1A_1P(0xB2,0x1E);                            
NT35532_DCS_write_1A_1P(0xB3,0x00);                            
NT35532_DCS_write_1A_1P(0xB4,0x4B);                            
NT35532_DCS_write_1A_1P(0xB5,0x00);                            
NT35532_DCS_write_1A_1P(0xB6,0x6E);                            
NT35532_DCS_write_1A_1P(0xB7,0x00);                            
NT35532_DCS_write_1A_1P(0xB8,0x88);                            
NT35532_DCS_write_1A_1P(0xB9,0x00);                            
NT35532_DCS_write_1A_1P(0xBA,0x9F);                            
NT35532_DCS_write_1A_1P(0xBB,0x00);                            
NT35532_DCS_write_1A_1P(0xBC,0xB3);                            
NT35532_DCS_write_1A_1P(0xBD,0x00);                            
NT35532_DCS_write_1A_1P(0xBE,0xC5);                            
NT35532_DCS_write_1A_1P(0xBF,0x00);                            
NT35532_DCS_write_1A_1P(0xC0,0xD5);                            
NT35532_DCS_write_1A_1P(0xC1,0x01);                            
NT35532_DCS_write_1A_1P(0xC2,0x09);                            
NT35532_DCS_write_1A_1P(0xC3,0x01);                            
NT35532_DCS_write_1A_1P(0xC4,0x31);                            
NT35532_DCS_write_1A_1P(0xC5,0x01);                            
NT35532_DCS_write_1A_1P(0xC6,0x6B);                            
NT35532_DCS_write_1A_1P(0xC7,0x01);                            
NT35532_DCS_write_1A_1P(0xC8,0x97);                            
NT35532_DCS_write_1A_1P(0xC9,0x01);
NT35532_DCS_write_1A_1P(0xCA,0xD8);
NT35532_DCS_write_1A_1P(0xCB,0x02);
NT35532_DCS_write_1A_1P(0xCC,0x0C);
NT35532_DCS_write_1A_1P(0xCD,0x02);
NT35532_DCS_write_1A_1P(0xCE,0x0D);
NT35532_DCS_write_1A_1P(0xCF,0x02);
NT35532_DCS_write_1A_1P(0xD0,0x3F);
NT35532_DCS_write_1A_1P(0xD1,0x02);
NT35532_DCS_write_1A_1P(0xD2,0x77);
NT35532_DCS_write_1A_1P(0xD3,0x02);
NT35532_DCS_write_1A_1P(0xD4,0x9C);
NT35532_DCS_write_1A_1P(0xD5,0x02);
NT35532_DCS_write_1A_1P(0xD6,0xCF);
NT35532_DCS_write_1A_1P(0xD7,0x02);
NT35532_DCS_write_1A_1P(0xD8,0xF0);
NT35532_DCS_write_1A_1P(0xD9,0x03);
NT35532_DCS_write_1A_1P(0xDA,0x1C);
NT35532_DCS_write_1A_1P(0xDB,0x03);
NT35532_DCS_write_1A_1P(0xDC,0x29);
NT35532_DCS_write_1A_1P(0xDD,0x03);
NT35532_DCS_write_1A_1P(0xDE,0x37);
NT35532_DCS_write_1A_1P(0xDF,0x03);
NT35532_DCS_write_1A_1P(0xE0,0x47);
NT35532_DCS_write_1A_1P(0xE1,0x03);
NT35532_DCS_write_1A_1P(0xE2,0x58);
NT35532_DCS_write_1A_1P(0xE3,0x03);
NT35532_DCS_write_1A_1P(0xE4,0x6C);
NT35532_DCS_write_1A_1P(0xE5,0x03);
NT35532_DCS_write_1A_1P(0xE6,0x80);
NT35532_DCS_write_1A_1P(0xE7,0x03);
NT35532_DCS_write_1A_1P(0xE8,0xF4);
NT35532_DCS_write_1A_1P(0xE9,0x03);
NT35532_DCS_write_1A_1P(0xEA,0xFF);

#else

NT35532_DCS_write_1A_1P(0x75,0x00);
NT35532_DCS_write_1A_1P(0x76,0x23);
NT35532_DCS_write_1A_1P(0x77,0x00);
NT35532_DCS_write_1A_1P(0x78,0x24);
NT35532_DCS_write_1A_1P(0x79,0x00);
NT35532_DCS_write_1A_1P(0x7A,0x42);
NT35532_DCS_write_1A_1P(0x7B,0x00);
NT35532_DCS_write_1A_1P(0x7C,0x5D);
NT35532_DCS_write_1A_1P(0x7D,0x00);
NT35532_DCS_write_1A_1P(0x7E,0x71);
NT35532_DCS_write_1A_1P(0x7F,0x00);
NT35532_DCS_write_1A_1P(0x80,0x83);
NT35532_DCS_write_1A_1P(0x81,0x00);
NT35532_DCS_write_1A_1P(0x82,0x95);
NT35532_DCS_write_1A_1P(0x83,0x00);
NT35532_DCS_write_1A_1P(0x84,0xA4);
NT35532_DCS_write_1A_1P(0x85,0x00);
NT35532_DCS_write_1A_1P(0x86,0xBB);
NT35532_DCS_write_1A_1P(0x87,0x00);
NT35532_DCS_write_1A_1P(0x88,0xE2);
NT35532_DCS_write_1A_1P(0x89,0x01);
NT35532_DCS_write_1A_1P(0x8A,0x0B);
NT35532_DCS_write_1A_1P(0x8B,0x01);
NT35532_DCS_write_1A_1P(0x8C,0x4E);
NT35532_DCS_write_1A_1P(0x8D,0x01);
NT35532_DCS_write_1A_1P(0x8E,0x7E);
NT35532_DCS_write_1A_1P(0x8F,0x01);
NT35532_DCS_write_1A_1P(0x90,0xCA);
NT35532_DCS_write_1A_1P(0x91,0x02);
NT35532_DCS_write_1A_1P(0x92,0x03);
NT35532_DCS_write_1A_1P(0x93,0x01);
NT35532_DCS_write_1A_1P(0x94,0xFD);
NT35532_DCS_write_1A_1P(0x95,0x02);
NT35532_DCS_write_1A_1P(0x96,0x35);
NT35532_DCS_write_1A_1P(0x97,0x02);
NT35532_DCS_write_1A_1P(0x98,0x70);
NT35532_DCS_write_1A_1P(0x99,0x02);
NT35532_DCS_write_1A_1P(0x9A,0x94);
NT35532_DCS_write_1A_1P(0x9B,0x02);
NT35532_DCS_write_1A_1P(0x9C,0xC2);
NT35532_DCS_write_1A_1P(0x9D,0x02);
NT35532_DCS_write_1A_1P(0x9E,0xE3);
NT35532_DCS_write_1A_1P(0x9F,0x03);
NT35532_DCS_write_1A_1P(0xA0,0x10);
NT35532_DCS_write_1A_1P(0xA2,0x03);
NT35532_DCS_write_1A_1P(0xA3,0x1A);
NT35532_DCS_write_1A_1P(0xA4,0x03);
NT35532_DCS_write_1A_1P(0xA5,0x2C);
NT35532_DCS_write_1A_1P(0xA6,0x03);
NT35532_DCS_write_1A_1P(0xA7,0x40);
NT35532_DCS_write_1A_1P(0xA9,0x03);
NT35532_DCS_write_1A_1P(0xAA,0x4C);
NT35532_DCS_write_1A_1P(0xAB,0x03);
NT35532_DCS_write_1A_1P(0xAC,0x78);
NT35532_DCS_write_1A_1P(0xAD,0x03);
NT35532_DCS_write_1A_1P(0xAE,0x9A);
NT35532_DCS_write_1A_1P(0xAF,0x03);
NT35532_DCS_write_1A_1P(0xB0,0xCA);
NT35532_DCS_write_1A_1P(0xB1,0x03);
NT35532_DCS_write_1A_1P(0xB2,0xDA);
NT35532_DCS_write_1A_1P(0xB3,0x00);
NT35532_DCS_write_1A_1P(0xB4,0x23);
NT35532_DCS_write_1A_1P(0xB5,0x00);
NT35532_DCS_write_1A_1P(0xB6,0x24);
NT35532_DCS_write_1A_1P(0xB7,0x00);
NT35532_DCS_write_1A_1P(0xB8,0x42);
NT35532_DCS_write_1A_1P(0xB9,0x00);
NT35532_DCS_write_1A_1P(0xBA,0x5D);
NT35532_DCS_write_1A_1P(0xBB,0x00);
NT35532_DCS_write_1A_1P(0xBC,0x71);
NT35532_DCS_write_1A_1P(0xBD,0x00);
NT35532_DCS_write_1A_1P(0xBE,0x83);
NT35532_DCS_write_1A_1P(0xBF,0x00);
NT35532_DCS_write_1A_1P(0xC0,0x95);
NT35532_DCS_write_1A_1P(0xC1,0x00);
NT35532_DCS_write_1A_1P(0xC2,0xA4);
NT35532_DCS_write_1A_1P(0xC3,0x00);
NT35532_DCS_write_1A_1P(0xC4,0xBB);
NT35532_DCS_write_1A_1P(0xC5,0x00);
NT35532_DCS_write_1A_1P(0xC6,0xDE);
NT35532_DCS_write_1A_1P(0xC7,0x01);
NT35532_DCS_write_1A_1P(0xC8,0x03);
NT35532_DCS_write_1A_1P(0xC9,0x01);
NT35532_DCS_write_1A_1P(0xCA,0x3A);
NT35532_DCS_write_1A_1P(0xCB,0x01);
NT35532_DCS_write_1A_1P(0xCC,0x6A);
NT35532_DCS_write_1A_1P(0xCD,0x01);
NT35532_DCS_write_1A_1P(0xCE,0xB2);
NT35532_DCS_write_1A_1P(0xCF,0x01);
NT35532_DCS_write_1A_1P(0xD0,0xF5);
NT35532_DCS_write_1A_1P(0xD1,0x01);
NT35532_DCS_write_1A_1P(0xD2,0xFD);
NT35532_DCS_write_1A_1P(0xD3,0x02);
NT35532_DCS_write_1A_1P(0xD4,0x35);
NT35532_DCS_write_1A_1P(0xD5,0x02);
NT35532_DCS_write_1A_1P(0xD6,0x74);
NT35532_DCS_write_1A_1P(0xD7,0x02);
NT35532_DCS_write_1A_1P(0xD8,0x9C);
NT35532_DCS_write_1A_1P(0xD9,0x02);
NT35532_DCS_write_1A_1P(0xDA,0xD2);
NT35532_DCS_write_1A_1P(0xDB,0x02);
NT35532_DCS_write_1A_1P(0xDC,0xFB);
NT35532_DCS_write_1A_1P(0xDD,0x03);
NT35532_DCS_write_1A_1P(0xDE,0x2E);
NT35532_DCS_write_1A_1P(0xDF,0x03);
NT35532_DCS_write_1A_1P(0xE0,0x46);
NT35532_DCS_write_1A_1P(0xE1,0x03);
NT35532_DCS_write_1A_1P(0xE2,0x50);
NT35532_DCS_write_1A_1P(0xE3,0x03);
NT35532_DCS_write_1A_1P(0xE4,0x62);
NT35532_DCS_write_1A_1P(0xE5,0x03);
NT35532_DCS_write_1A_1P(0xE6,0x7E);
NT35532_DCS_write_1A_1P(0xE7,0x03);
NT35532_DCS_write_1A_1P(0xE8,0x98);
NT35532_DCS_write_1A_1P(0xE9,0x03);
NT35532_DCS_write_1A_1P(0xEA,0xAA);
NT35532_DCS_write_1A_1P(0xEB,0x03);
NT35532_DCS_write_1A_1P(0xEC,0xCA);
NT35532_DCS_write_1A_1P(0xED,0x03);
NT35532_DCS_write_1A_1P(0xEE,0xDA);
NT35532_DCS_write_1A_1P(0xEF,0x00);
NT35532_DCS_write_1A_1P(0xF0,0x23);
NT35532_DCS_write_1A_1P(0xF1,0x00);
NT35532_DCS_write_1A_1P(0xF2,0x24);
NT35532_DCS_write_1A_1P(0xF3,0x00);
NT35532_DCS_write_1A_1P(0xF4,0x42);
NT35532_DCS_write_1A_1P(0xF5,0x00);
NT35532_DCS_write_1A_1P(0xF6,0x5D);
NT35532_DCS_write_1A_1P(0xF7,0x00);
NT35532_DCS_write_1A_1P(0xF8,0x71);
NT35532_DCS_write_1A_1P(0xF9,0x00);
NT35532_DCS_write_1A_1P(0xFA,0x83);
NT35532_DCS_write_1A_1P(0xFF,0x02);
NT35532_DCS_write_1A_1P(0xFB,0x01);
NT35532_DCS_write_1A_1P(0x00,0x00);
NT35532_DCS_write_1A_1P(0x01,0x95);
NT35532_DCS_write_1A_1P(0x02,0x00);
NT35532_DCS_write_1A_1P(0x03,0xA4);
NT35532_DCS_write_1A_1P(0x04,0x00);
NT35532_DCS_write_1A_1P(0x05,0xBB);
NT35532_DCS_write_1A_1P(0x06,0x00);
NT35532_DCS_write_1A_1P(0x07,0xE2);
NT35532_DCS_write_1A_1P(0x08,0x01);
NT35532_DCS_write_1A_1P(0x09,0x0B);
NT35532_DCS_write_1A_1P(0x0A,0x01);
NT35532_DCS_write_1A_1P(0x0B,0x4E);
NT35532_DCS_write_1A_1P(0x0C,0x01);
NT35532_DCS_write_1A_1P(0x0D,0x7E);
NT35532_DCS_write_1A_1P(0x0E,0x01);
NT35532_DCS_write_1A_1P(0x0F,0xCA);
NT35532_DCS_write_1A_1P(0x10,0x02);
NT35532_DCS_write_1A_1P(0x11,0x03);
NT35532_DCS_write_1A_1P(0x12,0x01);
NT35532_DCS_write_1A_1P(0x13,0xFD);
NT35532_DCS_write_1A_1P(0x14,0x02);
NT35532_DCS_write_1A_1P(0x15,0x35);
NT35532_DCS_write_1A_1P(0x16,0x02);
NT35532_DCS_write_1A_1P(0x17,0x70);
NT35532_DCS_write_1A_1P(0x18,0x02);
NT35532_DCS_write_1A_1P(0x19,0x94);
NT35532_DCS_write_1A_1P(0x1A,0x02);
NT35532_DCS_write_1A_1P(0x1B,0xC2);
NT35532_DCS_write_1A_1P(0x1C,0x02);
NT35532_DCS_write_1A_1P(0x1D,0xE3);
NT35532_DCS_write_1A_1P(0x1E,0x03);
NT35532_DCS_write_1A_1P(0x1F,0x10);
NT35532_DCS_write_1A_1P(0x20,0x03);
NT35532_DCS_write_1A_1P(0x21,0x18);
NT35532_DCS_write_1A_1P(0x22,0x03);
NT35532_DCS_write_1A_1P(0x23,0x2C);
NT35532_DCS_write_1A_1P(0x24,0x03);
NT35532_DCS_write_1A_1P(0x25,0x40);
NT35532_DCS_write_1A_1P(0x26,0x03);
NT35532_DCS_write_1A_1P(0x27,0x4C);
NT35532_DCS_write_1A_1P(0x28,0x03);
NT35532_DCS_write_1A_1P(0x29,0x78);
NT35532_DCS_write_1A_1P(0x2A,0x03);
NT35532_DCS_write_1A_1P(0x2B,0x9A);
NT35532_DCS_write_1A_1P(0x2D,0x03);
NT35532_DCS_write_1A_1P(0x2F,0xCA);
NT35532_DCS_write_1A_1P(0x30,0x03);
NT35532_DCS_write_1A_1P(0x31,0xDA);
NT35532_DCS_write_1A_1P(0x32,0x00);
NT35532_DCS_write_1A_1P(0x33,0x23);
NT35532_DCS_write_1A_1P(0x34,0x00);
NT35532_DCS_write_1A_1P(0x35,0x24);
NT35532_DCS_write_1A_1P(0x36,0x00);
NT35532_DCS_write_1A_1P(0x37,0x42);
NT35532_DCS_write_1A_1P(0x38,0x00);
NT35532_DCS_write_1A_1P(0x39,0x5D);
NT35532_DCS_write_1A_1P(0x3A,0x00);
NT35532_DCS_write_1A_1P(0x3B,0x71);
NT35532_DCS_write_1A_1P(0x3D,0x00);
NT35532_DCS_write_1A_1P(0x3F,0x83);
NT35532_DCS_write_1A_1P(0x40,0x00);
NT35532_DCS_write_1A_1P(0x41,0x95);
NT35532_DCS_write_1A_1P(0x42,0x00);
NT35532_DCS_write_1A_1P(0x43,0xA4);
NT35532_DCS_write_1A_1P(0x44,0x00);
NT35532_DCS_write_1A_1P(0x45,0xBB);
NT35532_DCS_write_1A_1P(0x46,0x00);
NT35532_DCS_write_1A_1P(0x47,0xDE);
NT35532_DCS_write_1A_1P(0x48,0x01);
NT35532_DCS_write_1A_1P(0x49,0x03);
NT35532_DCS_write_1A_1P(0x4A,0x01);
NT35532_DCS_write_1A_1P(0x4B,0x3A);
NT35532_DCS_write_1A_1P(0x4C,0x01);
NT35532_DCS_write_1A_1P(0x4D,0x6A);
NT35532_DCS_write_1A_1P(0x4E,0x01);
NT35532_DCS_write_1A_1P(0x4F,0xB2);
NT35532_DCS_write_1A_1P(0x50,0x01);
NT35532_DCS_write_1A_1P(0x51,0xF5);
NT35532_DCS_write_1A_1P(0x52,0x01);
NT35532_DCS_write_1A_1P(0x53,0xFD);
NT35532_DCS_write_1A_1P(0x54,0x02);
NT35532_DCS_write_1A_1P(0x55,0x35);
NT35532_DCS_write_1A_1P(0x56,0x02);
NT35532_DCS_write_1A_1P(0x58,0x74);
NT35532_DCS_write_1A_1P(0x59,0x02);
NT35532_DCS_write_1A_1P(0x5A,0x9C);
NT35532_DCS_write_1A_1P(0x5B,0x02);
NT35532_DCS_write_1A_1P(0x5C,0xD2);
NT35532_DCS_write_1A_1P(0x5D,0x02);
NT35532_DCS_write_1A_1P(0x5E,0xFB);
NT35532_DCS_write_1A_1P(0x5F,0x03);
NT35532_DCS_write_1A_1P(0x60,0x2E);
NT35532_DCS_write_1A_1P(0x61,0x03);
NT35532_DCS_write_1A_1P(0x62,0x46);
NT35532_DCS_write_1A_1P(0x63,0x03);
NT35532_DCS_write_1A_1P(0x64,0x50);
NT35532_DCS_write_1A_1P(0x65,0x03);
NT35532_DCS_write_1A_1P(0x66,0x62);
NT35532_DCS_write_1A_1P(0x67,0x03);
NT35532_DCS_write_1A_1P(0x68,0x7E);
NT35532_DCS_write_1A_1P(0x69,0x03);
NT35532_DCS_write_1A_1P(0x6A,0x98);
NT35532_DCS_write_1A_1P(0x6B,0x03);
NT35532_DCS_write_1A_1P(0x6C,0xAA);
NT35532_DCS_write_1A_1P(0x6D,0x03);
NT35532_DCS_write_1A_1P(0x6E,0xCA);
NT35532_DCS_write_1A_1P(0x6F,0x03);
NT35532_DCS_write_1A_1P(0x70,0xDA);
NT35532_DCS_write_1A_1P(0x71,0x00);
NT35532_DCS_write_1A_1P(0x72,0x23);
NT35532_DCS_write_1A_1P(0x73,0x00);
NT35532_DCS_write_1A_1P(0x74,0x24);
NT35532_DCS_write_1A_1P(0x75,0x00);
NT35532_DCS_write_1A_1P(0x76,0x42);
NT35532_DCS_write_1A_1P(0x77,0x00);
NT35532_DCS_write_1A_1P(0x78,0x5D);
NT35532_DCS_write_1A_1P(0x79,0x00);
NT35532_DCS_write_1A_1P(0x7A,0x71);
NT35532_DCS_write_1A_1P(0x7B,0x00);
NT35532_DCS_write_1A_1P(0x7C,0x83);
NT35532_DCS_write_1A_1P(0x7D,0x00);
NT35532_DCS_write_1A_1P(0x7E,0x95);
NT35532_DCS_write_1A_1P(0x7F,0x00);
NT35532_DCS_write_1A_1P(0x80,0xA4);
NT35532_DCS_write_1A_1P(0x81,0x00);
NT35532_DCS_write_1A_1P(0x82,0xBB);
NT35532_DCS_write_1A_1P(0x83,0x00);
NT35532_DCS_write_1A_1P(0x84,0xE2);
NT35532_DCS_write_1A_1P(0x85,0x01);
NT35532_DCS_write_1A_1P(0x86,0x0B);
NT35532_DCS_write_1A_1P(0x87,0x01);
NT35532_DCS_write_1A_1P(0x88,0x4E);
NT35532_DCS_write_1A_1P(0x89,0x01);
NT35532_DCS_write_1A_1P(0x8A,0x7E);
NT35532_DCS_write_1A_1P(0x8B,0x01);
NT35532_DCS_write_1A_1P(0x8C,0xCA);
NT35532_DCS_write_1A_1P(0x8D,0x02);
NT35532_DCS_write_1A_1P(0x8E,0x03);
NT35532_DCS_write_1A_1P(0x8F,0x01);
NT35532_DCS_write_1A_1P(0x90,0xFD);
NT35532_DCS_write_1A_1P(0x91,0x02);
NT35532_DCS_write_1A_1P(0x92,0x35);
NT35532_DCS_write_1A_1P(0x93,0x02);
NT35532_DCS_write_1A_1P(0x94,0x70);
NT35532_DCS_write_1A_1P(0x95,0x02);
NT35532_DCS_write_1A_1P(0x96,0x94);
NT35532_DCS_write_1A_1P(0x97,0x02);
NT35532_DCS_write_1A_1P(0x98,0xC2);
NT35532_DCS_write_1A_1P(0x99,0x02);
NT35532_DCS_write_1A_1P(0x9A,0xE3);
NT35532_DCS_write_1A_1P(0x9B,0x03);
NT35532_DCS_write_1A_1P(0x9C,0x10);
NT35532_DCS_write_1A_1P(0x9D,0x03);
NT35532_DCS_write_1A_1P(0x9E,0x18);
NT35532_DCS_write_1A_1P(0x9F,0x03);
NT35532_DCS_write_1A_1P(0xA0,0x2C);
NT35532_DCS_write_1A_1P(0xA2,0x03);
NT35532_DCS_write_1A_1P(0xA3,0x40);
NT35532_DCS_write_1A_1P(0xA4,0x03);
NT35532_DCS_write_1A_1P(0xA5,0x4C);
NT35532_DCS_write_1A_1P(0xA6,0x03);
NT35532_DCS_write_1A_1P(0xA7,0x78);
NT35532_DCS_write_1A_1P(0xA9,0x03);
NT35532_DCS_write_1A_1P(0xAA,0x9A);
NT35532_DCS_write_1A_1P(0xAB,0x03);
NT35532_DCS_write_1A_1P(0xAC,0xCA);
NT35532_DCS_write_1A_1P(0xAD,0x03);
NT35532_DCS_write_1A_1P(0xAE,0xDA);
NT35532_DCS_write_1A_1P(0xAF,0x00);
NT35532_DCS_write_1A_1P(0xB0,0x23);
NT35532_DCS_write_1A_1P(0xB1,0x00);
NT35532_DCS_write_1A_1P(0xB2,0x24);
NT35532_DCS_write_1A_1P(0xB3,0x00);
NT35532_DCS_write_1A_1P(0xB4,0x42);
NT35532_DCS_write_1A_1P(0xB5,0x00);
NT35532_DCS_write_1A_1P(0xB6,0x5D);
NT35532_DCS_write_1A_1P(0xB7,0x00);
NT35532_DCS_write_1A_1P(0xB8,0x71);
NT35532_DCS_write_1A_1P(0xB9,0x00);
NT35532_DCS_write_1A_1P(0xBA,0x83);
NT35532_DCS_write_1A_1P(0xBB,0x00);
NT35532_DCS_write_1A_1P(0xBC,0x95);
NT35532_DCS_write_1A_1P(0xBD,0x00);
NT35532_DCS_write_1A_1P(0xBE,0xA4);
NT35532_DCS_write_1A_1P(0xBF,0x00);
NT35532_DCS_write_1A_1P(0xC0,0xBB);
NT35532_DCS_write_1A_1P(0xC1,0x00);
NT35532_DCS_write_1A_1P(0xC2,0xDE);
NT35532_DCS_write_1A_1P(0xC3,0x01);
NT35532_DCS_write_1A_1P(0xC4,0x03);
NT35532_DCS_write_1A_1P(0xC5,0x01);
NT35532_DCS_write_1A_1P(0xC6,0x3A);
NT35532_DCS_write_1A_1P(0xC7,0x01);
NT35532_DCS_write_1A_1P(0xC8,0x6A);
NT35532_DCS_write_1A_1P(0xC9,0x01);
NT35532_DCS_write_1A_1P(0xCA,0xB2);
NT35532_DCS_write_1A_1P(0xCB,0x01);
NT35532_DCS_write_1A_1P(0xCC,0xF5);
NT35532_DCS_write_1A_1P(0xCD,0x01);
NT35532_DCS_write_1A_1P(0xCE,0xFD);
NT35532_DCS_write_1A_1P(0xCF,0x02);
NT35532_DCS_write_1A_1P(0xD0,0x35);
NT35532_DCS_write_1A_1P(0xD1,0x02);
NT35532_DCS_write_1A_1P(0xD2,0x74);
NT35532_DCS_write_1A_1P(0xD3,0x02);
NT35532_DCS_write_1A_1P(0xD4,0x9C);
NT35532_DCS_write_1A_1P(0xD5,0x02);
NT35532_DCS_write_1A_1P(0xD6,0xD2);
NT35532_DCS_write_1A_1P(0xD7,0x02);
NT35532_DCS_write_1A_1P(0xD8,0xFB);
NT35532_DCS_write_1A_1P(0xD9,0x03);
NT35532_DCS_write_1A_1P(0xDA,0x2E);
NT35532_DCS_write_1A_1P(0xDB,0x03);
NT35532_DCS_write_1A_1P(0xDC,0x46);
NT35532_DCS_write_1A_1P(0xDD,0x03);
NT35532_DCS_write_1A_1P(0xDE,0x50);
NT35532_DCS_write_1A_1P(0xDF,0x03);
NT35532_DCS_write_1A_1P(0xE0,0x62);
NT35532_DCS_write_1A_1P(0xE1,0x03);
NT35532_DCS_write_1A_1P(0xE2,0x7E);
NT35532_DCS_write_1A_1P(0xE3,0x03);
NT35532_DCS_write_1A_1P(0xE4,0x98);
NT35532_DCS_write_1A_1P(0xE5,0x03);
NT35532_DCS_write_1A_1P(0xE6,0xA8);
NT35532_DCS_write_1A_1P(0xE7,0x03);
NT35532_DCS_write_1A_1P(0xE8,0xCA);
NT35532_DCS_write_1A_1P(0xE9,0x03);
NT35532_DCS_write_1A_1P(0xEA,0xDA);


#endif


// Switch to CMD2_Page4 (GIP Timing)
NT35532_DCS_write_1A_1P(0xFF,0x05);
//MDELAY(50);

NT35532_DCS_write_1A_1P(0xD7,0x31);   //new add
NT35532_DCS_write_1A_1P(0xD8,0x7E);   //new add
MDELAY(50);
NT35532_DCS_write_1A_1P(0xD6,0x11);   //new add

// Don\A1\A6t reload MTP
NT35532_DCS_write_1A_1P(0xFB,0x01);

// CGOUT Pin Register Table
NT35532_DCS_write_1A_1P(0x00,0x35);
NT35532_DCS_write_1A_1P(0x01,0x08);
NT35532_DCS_write_1A_1P(0x02,0x06);
NT35532_DCS_write_1A_1P(0x03,0x04);
NT35532_DCS_write_1A_1P(0x04,0x34);
NT35532_DCS_write_1A_1P(0x05,0x22);
NT35532_DCS_write_1A_1P(0x06,0x22);
NT35532_DCS_write_1A_1P(0x07,0x1E);
NT35532_DCS_write_1A_1P(0x08,0x1E);
NT35532_DCS_write_1A_1P(0x09,0x1A);
NT35532_DCS_write_1A_1P(0x0A,0x1A);
NT35532_DCS_write_1A_1P(0x0B,0x16);
NT35532_DCS_write_1A_1P(0x0C,0x16);
NT35532_DCS_write_1A_1P(0x0D,0x05);
NT35532_DCS_write_1A_1P(0x0E,0x40);
NT35532_DCS_write_1A_1P(0x0F,0x40);
NT35532_DCS_write_1A_1P(0x10,0x40);
NT35532_DCS_write_1A_1P(0x11,0x40);
NT35532_DCS_write_1A_1P(0x12,0x40);
NT35532_DCS_write_1A_1P(0x13,0x40);
NT35532_DCS_write_1A_1P(0x14,0x35);
NT35532_DCS_write_1A_1P(0x15,0x09);
NT35532_DCS_write_1A_1P(0x16,0x07);
NT35532_DCS_write_1A_1P(0x17,0x04);
NT35532_DCS_write_1A_1P(0x18,0x34);
NT35532_DCS_write_1A_1P(0x19,0x24);
NT35532_DCS_write_1A_1P(0x1A,0x24);
NT35532_DCS_write_1A_1P(0x1B,0x20);
NT35532_DCS_write_1A_1P(0x1C,0x20);
NT35532_DCS_write_1A_1P(0x1D,0x1C);
NT35532_DCS_write_1A_1P(0x1E,0x1C);
NT35532_DCS_write_1A_1P(0x1F,0x18);
NT35532_DCS_write_1A_1P(0x20,0x18);
NT35532_DCS_write_1A_1P(0x21,0x05);
NT35532_DCS_write_1A_1P(0x22,0x40);
NT35532_DCS_write_1A_1P(0x23,0x40);
NT35532_DCS_write_1A_1P(0x24,0x40);
NT35532_DCS_write_1A_1P(0x25,0x40);
NT35532_DCS_write_1A_1P(0x26,0x40);
NT35532_DCS_write_1A_1P(0x27,0x40);
NT35532_DCS_write_1A_1P(0x28,0x35);
NT35532_DCS_write_1A_1P(0x29,0x07);
NT35532_DCS_write_1A_1P(0x2A,0x09);
NT35532_DCS_write_1A_1P(0x2B,0x04);
NT35532_DCS_write_1A_1P(0x2D,0x34);
NT35532_DCS_write_1A_1P(0x2F,0x18);
NT35532_DCS_write_1A_1P(0x30,0x18);
NT35532_DCS_write_1A_1P(0x31,0x1C);
NT35532_DCS_write_1A_1P(0x32,0x1C);
NT35532_DCS_write_1A_1P(0x33,0x20);
NT35532_DCS_write_1A_1P(0x34,0x20);
NT35532_DCS_write_1A_1P(0x35,0x24);
NT35532_DCS_write_1A_1P(0x36,0x24);
NT35532_DCS_write_1A_1P(0x37,0x05);
NT35532_DCS_write_1A_1P(0x38,0x40);
NT35532_DCS_write_1A_1P(0x39,0x40);
NT35532_DCS_write_1A_1P(0x3A,0x40);
NT35532_DCS_write_1A_1P(0x3B,0x40);
NT35532_DCS_write_1A_1P(0x3D,0x40);
NT35532_DCS_write_1A_1P(0x3F,0x40);
NT35532_DCS_write_1A_1P(0x40,0x35);
NT35532_DCS_write_1A_1P(0x41,0x06);
NT35532_DCS_write_1A_1P(0x42,0x08);
NT35532_DCS_write_1A_1P(0x43,0x04);
NT35532_DCS_write_1A_1P(0x44,0x34);
NT35532_DCS_write_1A_1P(0x45,0x16);
NT35532_DCS_write_1A_1P(0x46,0x16);
NT35532_DCS_write_1A_1P(0x47,0x1A);
NT35532_DCS_write_1A_1P(0x48,0x1A);
NT35532_DCS_write_1A_1P(0x49,0x1E);
NT35532_DCS_write_1A_1P(0x4A,0x1E);
NT35532_DCS_write_1A_1P(0x4B,0x22);
NT35532_DCS_write_1A_1P(0x4C,0x22);
NT35532_DCS_write_1A_1P(0x4D,0x05);
NT35532_DCS_write_1A_1P(0x4E,0x40);
NT35532_DCS_write_1A_1P(0x4F,0x40);
NT35532_DCS_write_1A_1P(0x50,0x40);
NT35532_DCS_write_1A_1P(0x51,0x40);
NT35532_DCS_write_1A_1P(0x52,0x40);
NT35532_DCS_write_1A_1P(0x53,0x40);
            
// GIP Timin0CRegister Setting
NT35532_DCS_write_1A_1P(0x54,0x0C);
NT35532_DCS_write_1A_1P(0x55,0x0A);
NT35532_DCS_write_1A_1P(0x56,0x08);
NT35532_DCS_write_1A_1P(0x58,0x06);
NT35532_DCS_write_1A_1P(0x59,0x1B);
NT35532_DCS_write_1A_1P(0x5A,0x1B);
NT35532_DCS_write_1A_1P(0x5B,0x49);
NT35532_DCS_write_1A_1P(0x5C,0x0D);
NT35532_DCS_write_1A_1P(0x5D,0x01);
NT35532_DCS_write_1A_1P(0x65,0x00);
NT35532_DCS_write_1A_1P(0x66,0x44);
NT35532_DCS_write_1A_1P(0x67,0x00);
NT35532_DCS_write_1A_1P(0x68,0x49);
NT35532_DCS_write_1A_1P(0x69,0x0D);
NT35532_DCS_write_1A_1P(0x6A,0x0A);
NT35532_DCS_write_1A_1P(0x6B,0x24);
NT35532_DCS_write_1A_1P(0x6C,0x08);
NT35532_DCS_write_1A_1P(0x6D,0x00);
NT35532_DCS_write_1A_1P(0x76,0x00);
NT35532_DCS_write_1A_1P(0x77,0x00);
NT35532_DCS_write_1A_1P(0x78,0x02);
NT35532_DCS_write_1A_1P(0x79,0x00);
NT35532_DCS_write_1A_1P(0x7A,0x0A);
NT35532_DCS_write_1A_1P(0x7B,0x05);
NT35532_DCS_write_1A_1P(0x7C,0x40);
NT35532_DCS_write_1A_1P(0x7D,0x0D);
NT35532_DCS_write_1A_1P(0x7E,0x33);
NT35532_DCS_write_1A_1P(0x7F,0x33);
NT35532_DCS_write_1A_1P(0x80,0x33);
NT35532_DCS_write_1A_1P(0x81,0x00);
NT35532_DCS_write_1A_1P(0x82,0x00);
NT35532_DCS_write_1A_1P(0x83,0x00);
NT35532_DCS_write_1A_1P(0x84,0x70);
NT35532_DCS_write_1A_1P(0x85,0xFF);
NT35532_DCS_write_1A_1P(0x86,0xFF);
NT35532_DCS_write_1A_1P(0xBB,0xCC);
            
// GIP Power33n/Off Sequence Register Setting
NT35532_DCS_write_1A_1P(0xB7,0xFF);
NT35532_DCS_write_1A_1P(0xB8,0x00);
NT35532_DCS_write_1A_1P(0xBA,0x13);
NT35532_DCS_write_1A_1P(0xBC,0x95);
NT35532_DCS_write_1A_1P(0xBD,0xAA);
NT35532_DCS_write_1A_1P(0xBE,0x08);
NT35532_DCS_write_1A_1P(0xBF,0xA3);
NT35532_DCS_write_1A_1P(0xC8,0x00);
NT35532_DCS_write_1A_1P(0xC9,0x00);
NT35532_DCS_write_1A_1P(0xCA,0x00);
NT35532_DCS_write_1A_1P(0xCB,0x00);
NT35532_DCS_write_1A_1P(0xCC,0x12);
NT35532_DCS_write_1A_1P(0xCF,0x44);
NT35532_DCS_write_1A_1P(0xD0,0x00);
NT35532_DCS_write_1A_1P(0xD1,0x00);
NT35532_DCS_write_1A_1P(0xD4,0x15);
NT35532_DCS_write_1A_1P(0xD5,0xBF);
// RTNA Sett95g
NT35532_DCS_write_1A_1P(0x90,0x78);
            
// BP,FP SetA3ng
NT35532_DCS_write_1A_1P(0x91,0x10);
NT35532_DCS_write_1A_1P(0x92,0x10);
NT35532_DCS_write_1A_1P(0x97,0x08);//?           
// Source EQ00etting
NT35532_DCS_write_1A_1P(0x98,0x00);
NT35532_DCS_write_1A_1P(0x99,0x00);

NT35532_DCS_write_1A_1P(0x9B,0x68);//?
NT35532_DCS_write_1A_1P(0x9C,0x0A);//?

NT35532_DCS_write_1A_1P(0xFF,0x00);

      
	data_array[0]=0x00110500; // Display Off
	dsi_set_cmdq(data_array, 1, 1);
MDELAY(120);
	data_array[0]=0x00290500; // Display Off
	dsi_set_cmdq(data_array, 1, 1);
MDELAY(20);
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

	params->physical_width = 68;
	params->physical_height = 121;

	params->dsi.vertical_sync_active = 2;//
	params->dsi.vertical_backporch = 14;//6	8 10
	params->dsi.vertical_frontporch = 14;//
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 20;//8
	params->dsi.horizontal_backporch = 100;//60
	params->dsi.horizontal_frontporch = 110;//72
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 480;//430//450

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
//MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(120);	//*
//	push_table(lcm_initialization_setting,sizeof(lcm_initialization_setting)/sizeof(struct LCM_setting_table), 1);
	init_lcm_registers();	
}

static void lcm_resume(void)
{
	lcm_init();
}

static void lcm_suspend(void)
{ 	
	unsigned int data_array[16];
	LCM_LOGI("lcm_suspend enter\n");
	data_array[0]=0x00280500; // Display Off
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(20);
	data_array[0] = 0x00100500; // Sleep In
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);	//*
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
	
//	MDELAY()

	id = lcm_id_index(b);
	
	#ifdef BUILD_LK
	printf("Jason in lk XL0553250B1, id = %d\n", id);	
	#else
	printk("Jason in kernel XL0553250B1, id = %d\n", id);
	#endif
	return (id==1) ? 1:0;
}


LCM_DRIVER XL0553250B1_lcm_drv = {
	.name = "XL0553250B1",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	//.init_power = lcm_init_power,

};

