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

#define GPIO_LCD_ID1_PIN		(89 | 0x80000000)
#define FRAME_WIDTH  (1080)
#define FRAME_HEIGHT (1920)

#ifdef BUILD_LK
#define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
#define LCM_LOGI(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))
#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))
#define REGFLAG_DELAY             							0XFE
#define REGFLAG_END_OF_TABLE      							0x100   // END OF REGISTERS MARKER

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	        lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)   

#define   LCM_DSI_CMD_MODE							0

extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);

static LCM_UTIL_FUNCS lcm_util = {0};
//static unsigned int lcm_esd_test = 0;      ///only for ESD test
struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

static struct LCM_setting_table lcm_initialization_setting[] = {

		{0xFF,1,{0X05}},
	{0xFB,1,{0X01}},
	{0xC5,1,{0X01}}, //TURN ON 

    
		     

	{0xFF,1,{0XEE}},//CMD page select
	{0xFB,1,{0X01}},//NON-RELOAD CMD
	{0x1F,1,{0X45}},
	{0x24,1,{0X4F}},
	{0x38,1,{0XC8}},
	{0x39,1,{0X2C}},
	{0x1E,1,{0XBB}},
	{0x1D,1,{0X0F}},
	{0x7E,1,{0XB1}},
	  
	{0xFF,1,{0X00}}, //CMD page select 
	{0xFB,1,{0X01}}, //NON-RELOAD CMD  
	{0x35,1,{0X01}},
	   
	{0xFF,1,{0X01}},//CMD page select 
	{0xFB,1,{0X01}},//NON-RELOAD CMD  
	{0x00,1,{0X01}},
	{0x01,1,{0X55}},
	{0x02,1,{0X40}},
	{0x05,1,{0X40}},
	{0x06,1,{0X4A}},
	{0x07,1,{0X24}},
	{0x08,1,{0X0C}},
	{0x0B,1,{0X87}},
	{0x0C,1,{0X87}},
	{0x0E,1,{0XB0}},
	{0x0F,1,{0XB3}},
	{0x11,1,{0X10}},
	{0x12,1,{0X10}},
	{0x13,1,{0X05}},
	{0x14,1,{0X4A}},
	{0x15,1,{0X18}},
	{0x16,1,{0X18}},
	{0x18,1,{0X00}},
	{0x19,1,{0X77}},
	{0x1A,1,{0X55}},
	{0x1B,1,{0X13}},
	{0x1C,1,{0X00}},
	{0x1D,1,{0X00}},
	{0x1E,1,{0X13}},
	{0x1F,1,{0X00}},
	{0x23,1,{0X00}},
	{0x24,1,{0X00}},
	{0x25,1,{0X00}},
	{0x26,1,{0X00}},
	{0x27,1,{0X00}},
	{0x28,1,{0X00}},
	{0x35,1,{0X00}},
	{0x66,1,{0X00}},
	{0x58,1,{0X82}},
	{0x59,1,{0X02}},
	{0x5A,1,{0X02}},
	{0x5B,1,{0X02}},
	{0x5C,1,{0X82}},
	{0x5D,1,{0X82}},
	{0x5E,1,{0X02}},
	{0x5F,1,{0X02}},
	{0x72,1,{0X31}},
		                               
	{0xFF,1,{0X05}},//CMD page select 
	{0xFB,1,{0X01}},//NON-RELOAD CMD  
	{0x00,1,{0X01}},
	{0x01,1,{0X0B}},
	{0x02,1,{0X0C}},
	{0x03,1,{0X09}},
	{0x04,1,{0X0A}},
	{0x05,1,{0X00}},
	{0x06,1,{0X0F}},
	{0x07,1,{0X10}},
	{0x08,1,{0X00}},
	{0x09,1,{0X00}},
	{0x0A,1,{0X00}},
	{0x0B,1,{0X00}},
	{0x0C,1,{0X00}},
	{0x0D,1,{0X13}},
	{0x0E,1,{0X15}},
	{0x0F,1,{0X17}},
	{0x10,1,{0X01}},
	{0x11,1,{0X0B}},
	{0x12,1,{0X0C}},
	{0x13,1,{0X09}},
	{0x14,1,{0X0A}},
	{0x15,1,{0X00}},
	{0x16,1,{0X0F}},
	{0x17,1,{0X10}},
	{0x18,1,{0X00}},
	{0x19,1,{0X00}},
	{0x1A,1,{0X00}},
	{0x1B,1,{0X00}},
	{0x1C,1,{0X00}},
	{0x1D,1,{0X13}},
	{0x1E,1,{0X15}},
	{0x1F,1,{0X17}},
	{0x20,1,{0X00}},
	{0x21,1,{0X03}},
	{0x22,1,{0X01}},
	{0x23,1,{0X40}},
	{0x24,1,{0X40}},
	{0x25,1,{0XED}},
	{0x29,1,{0X58}},
	{0x2A,1,{0X12}},
	{0x2B,1,{0X01}},
	{0x4B,1,{0X06}},
	{0x4C,1,{0X11}},
	{0x4D,1,{0X20}},
	{0x4E,1,{0X02}},
	{0x4F,1,{0X02}},
	{0x50,1,{0X20}},
	{0x51,1,{0X61}},
	{0x52,1,{0X01}},
	{0x53,1,{0X63}},
	{0x54,1,{0X77}},
	{0x55,1,{0XED}},
	{0x5B,1,{0X00}},
	{0x5C,1,{0X00}},
	{0x5D,1,{0X00}},
	{0x5E,1,{0X00}},
	{0x5F,1,{0X15}},
	{0x60,1,{0X75}},
	{0x61,1,{0X00}},
	{0x62,1,{0X00}},
	{0x63,1,{0X00}},
	{0x64,1,{0X00}},
	{0x65,1,{0X00}},
	{0x66,1,{0X00}},
	{0x67,1,{0X00}},
	{0x68,1,{0X04}},
	{0x69,1,{0X00}},
	{0x6A,1,{0X00}},
	{0x6C,1,{0X40}},
	{0x75,1,{0X01}},
	{0x76,1,{0X01}},
	{0x7A,1,{0X80}},
	{0x7B,1,{0XC5}},
	{0x7C,1,{0XD8}},
	{0x7D,1,{0X60}},
	{0x7F,1,{0X15}},
	{0x80,1,{0X81}},
	{0x83,1,{0X05}},
	{0x93,1,{0X08}},
	{0x94,1,{0X10}},
	{0x8A,1,{0X00}},
	{0x9B,1,{0X0F}},
	{0xEA,1,{0XFF}},
	{0xEC,1,{0X00}},
		                               
	{0xFF,1,{0X01}},//CMD page select 
	{0xFB,1,{0X01}},//NON-RELOAD CMD  
	{0x75,1,{0X00}},//Gamma R+ 
	{0x76,1,{0X18}},
	{0x77,1,{0X00}},
	{0x78,1,{0X38}},
	{0x79,1,{0X00}},
	{0x7A,1,{0X65}},
	{0x7B,1,{0X00}},
	{0x7C,1,{0X84}},
	{0x7D,1,{0X00}},
	{0x7E,1,{0X9B}},
	{0x7F,1,{0X00}},
	{0x80,1,{0XAF}},
	{0x81,1,{0X00}},
	{0x82,1,{0XC1}},
	{0x83,1,{0X00}},
	{0x84,1,{0XD2}},
	{0x85,1,{0X00}},
	{0x86,1,{0XDF}},
	{0x87,1,{0X01}},
	{0x88,1,{0X11}},
	{0x89,1,{0X01}},
	{0x8A,1,{0X38}},
	{0x8B,1,{0X01}},
	{0x8C,1,{0X76}},
	{0x8D,1,{0X01}},
	{0x8E,1,{0XA7}},
	{0x8F,1,{0X01}},
	{0x90,1,{0XF3}},
	{0x91,1,{0X02}},
	{0x92,1,{0X2F}},
	{0x93,1,{0X02}},
	{0x94,1,{0X30}},
	{0x95,1,{0X02}},
	{0x96,1,{0X66}},
	{0x97,1,{0X02}},
	{0x98,1,{0XA0}},
	{0x99,1,{0X02}},
	{0x9A,1,{0XC5}},
	{0x9B,1,{0X02}},
	{0x9C,1,{0XF8}},
	{0x9D,1,{0X03}},
	{0x9E,1,{0X1B}},
	{0x9F,1,{0X03}},
	{0xA0,1,{0X46}},
	{0xA2,1,{0X03}},
	{0xA3,1,{0X52}},
	{0xA4,1,{0X03}},
	{0xA5,1,{0X62}},
	{0xA6,1,{0X03}},
	{0xA7,1,{0X71}},
	{0xA9,1,{0X03}},
	{0xAA,1,{0X83}},
	{0xAB,1,{0X03}},
	{0xAC,1,{0X94}},
	{0xAD,1,{0X03}},
	{0xAE,1,{0XA3}},
	{0xAF,1,{0X03}},
	{0xB0,1,{0XAD}},
	{0xB1,1,{0X03}},
	{0xB2,1,{0XCC}},
		                              
	{0xB3,1,{0X00}},//Gamma R- 
	{0xB4,1,{0X18}},
	{0xB5,1,{0X00}},
	{0xB6,1,{0X38}},
	{0xB7,1,{0X00}},
	{0xB8,1,{0X65}},
	{0xB9,1,{0X00}},
	{0xBA,1,{0X84}},
	{0xBB,1,{0X00}},
	{0xBC,1,{0X9B}},
	{0xBD,1,{0X00}},
	{0xBE,1,{0XAF}},
	{0xBF,1,{0X00}},
	{0xC0,1,{0XC1}},
	{0xC1,1,{0X00}},
	{0xC2,1,{0XD2}},
	{0xC3,1,{0X00}},
	{0xC4,1,{0XDF}},
	{0xC5,1,{0X01}},
	{0xC6,1,{0X11}},
	{0xC7,1,{0X01}},
	{0xC8,1,{0X38}},
	{0xC9,1,{0X01}},
	{0xCA,1,{0X76}},
	{0xCB,1,{0X01}},
	{0xCC,1,{0XA7}},
	{0xCD,1,{0X01}},
	{0xCE,1,{0XF3}},
	{0xCF,1,{0X02}},
	{0xD0,1,{0X2F}},
	{0xD1,1,{0X02}},
	{0xD2,1,{0X30}},
	{0xD3,1,{0X02}},
	{0xD4,1,{0X66}},
	{0xD5,1,{0X02}},
	{0xD6,1,{0XA0}},
	{0xD7,1,{0X02}},
	{0xD8,1,{0XC5}},
	{0xD9,1,{0X02}},
	{0xDA,1,{0XF8}},
	{0xDB,1,{0X03}},
	{0xDC,1,{0X1B}},
	{0xDD,1,{0X03}},
	{0xDE,1,{0X46}},
	{0xDF,1,{0X03}},
	{0xE0,1,{0X52}},
	{0xE1,1,{0X03}},
	{0xE2,1,{0X62}},
	{0xE3,1,{0X03}},
	{0xE4,1,{0X71}},
	{0xE5,1,{0X03}},
	{0xE6,1,{0X83}},
	{0xE7,1,{0X03}},
	{0xE8,1,{0X94}},
	{0xE9,1,{0X03}},
	{0xEA,1,{0XA3}},
	{0xEB,1,{0X03}},
	{0xEC,1,{0XAD}},
	{0xED,1,{0X03}},
	{0xEE,1,{0XCC}},
		                               
	{0xEF,1,{0X00}},//Gamma G+ 
	{0xF0,1,{0X18}},
	{0xF1,1,{0X00}},
	{0xF2,1,{0X38}},
	{0xF3,1,{0X00}},
	{0xF4,1,{0X65}},
	{0xF5,1,{0X00}},
	{0xF6,1,{0X84}},
	{0xF7,1,{0X00}},
	{0xF8,1,{0X9B}},
	{0xF9,1,{0X00}},
	{0xFA,1,{0XAF}},
	{0xFF,1,{0X02}}, //CMD page select
	{0xFB,1,{0X01}}, //NON-RELOAD CMD 
	{0x00,1,{0X00}},
	{0x01,1,{0XC1}},
	{0x02,1,{0X00}},
	{0x03,1,{0XD2}},
	{0x04,1,{0X00}},
	{0x05,1,{0XDF}},
	{0x06,1,{0X01}},
	{0x07,1,{0X11}},
	{0x08,1,{0X01}},
	{0x09,1,{0X38}},
	{0x0A,1,{0X01}},
	{0x0B,1,{0X76}},
	{0x0C,1,{0X01}},
	{0x0D,1,{0XA7}},
	{0x0E,1,{0X01}},
	{0x0F,1,{0XF3}},
	{0x10,1,{0X02}},
	{0x11,1,{0X2F}},
	{0x12,1,{0X02}},
	{0x13,1,{0X30}},
	{0x14,1,{0X02}},
	{0x15,1,{0X66}},
	{0x16,1,{0X02}},
	{0x17,1,{0XA0}},
	{0x18,1,{0X02}},
	{0x19,1,{0XC5}},
	{0x1A,1,{0X02}},
	{0x1B,1,{0XF8}},
	{0x1C,1,{0X03}},
	{0x1D,1,{0X1B}},
	{0x1E,1,{0X03}},
	{0x1F,1,{0X46}},
	{0x20,1,{0X03}},
	{0x21,1,{0X52}},
	{0x22,1,{0X03}},
	{0x23,1,{0X62}},
	{0x24,1,{0X03}},
	{0x25,1,{0X71}},
	{0x26,1,{0X03}},
	{0x27,1,{0X83}},
	{0x28,1,{0X03}},
	{0x29,1,{0X94}},
	{0x2A,1,{0X03}},
	{0x2B,1,{0XA3}},
	{0x2D,1,{0X03}},
	{0x2F,1,{0XAD}},
	{0x30,1,{0X03}},
	{0x31,1,{0XCC}},
		                                
	{0x32,1,{0X00}},//Gamma G- 
	{0x33,1,{0X18}},
	{0x34,1,{0X00}},
	{0x35,1,{0X38}},
	{0x36,1,{0X00}},
	{0x37,1,{0X65}},
	{0x38,1,{0X00}},
	{0x39,1,{0X84}},
	{0x3A,1,{0X00}},
	{0x3B,1,{0X9B}},
	{0x3D,1,{0X00}},
	{0x3F,1,{0XAF}},
	{0x40,1,{0X00}},
	{0x41,1,{0XC1}},
	{0x42,1,{0X00}},
	{0x43,1,{0XD2}},
	{0x44,1,{0X00}},
	{0x45,1,{0XDF}},
	{0x46,1,{0X01}},
	{0x47,1,{0X11}},
	{0x48,1,{0X01}},
	{0x49,1,{0X38}},
	{0x4A,1,{0X01}},
	{0x4B,1,{0X76}},
	{0x4C,1,{0X01}},
	{0x4D,1,{0XA7}},
	{0x4E,1,{0X01}},
	{0x4F,1,{0XF3}},
	{0x50,1,{0X02}},
	{0x51,1,{0X2F}},
	{0x52,1,{0X02}},
	{0x53,1,{0X30}},
	{0x54,1,{0X02}},
	{0x55,1,{0X66}},
	{0x56,1,{0X02}},
	{0x58,1,{0XA0}},
	{0x59,1,{0X02}},
	{0x5A,1,{0XC5}},
	{0x5B,1,{0X02}},
	{0x5C,1,{0XF8}},
	{0x5D,1,{0X03}},
	{0x5E,1,{0X1B}},
	{0x5F,1,{0X03}},
	{0x60,1,{0X46}},
	{0x61,1,{0X03}},
	{0x62,1,{0X52}},
	{0x63,1,{0X03}},
	{0x64,1,{0X62}},
	{0x65,1,{0X03}},
	{0x66,1,{0X71}},
	{0x67,1,{0X03}},
	{0x68,1,{0X83}},
	{0x69,1,{0X03}},
	{0x6A,1,{0X94}},
	{0x6B,1,{0X03}},
	{0x6C,1,{0XA3}},
	{0x6D,1,{0X03}},
	{0x6E,1,{0XAD}},
	{0x6F,1,{0X03}},
	{0x70,1,{0XCC}},
		                              
	{0x71,1,{0X00}},//Gamma B+ 
	{0x72,1,{0X18}},
	{0x73,1,{0X00}},
	{0x74,1,{0X38}},
	{0x75,1,{0X00}},
	{0x76,1,{0X65}},
	{0x77,1,{0X00}},
	{0x78,1,{0X84}},
	{0x79,1,{0X00}},
	{0x7A,1,{0X9B}},
	{0x7B,1,{0X00}},
	{0x7C,1,{0XAF}},
	{0x7D,1,{0X00}},
	{0x7E,1,{0XC1}},
	{0x7F,1,{0X00}},
	{0x80,1,{0XD2}},
	{0x81,1,{0X00}},
	{0x82,1,{0XDF}},
	{0x83,1,{0X01}},
	{0x84,1,{0X11}},
	{0x85,1,{0X01}},
	{0x86,1,{0X38}},
	{0x87,1,{0X01}},
	{0x88,1,{0X76}},
	{0x89,1,{0X01}},
	{0x8A,1,{0XA7}},
	{0x8B,1,{0X01}},
	{0x8C,1,{0XF3}},
	{0x8D,1,{0X02}},
	{0x8E,1,{0X2F}},
	{0x8F,1,{0X02}},
	{0x90,1,{0X30}},
	{0x91,1,{0X02}},
	{0x92,1,{0X66}},
	{0x93,1,{0X02}},
	{0x94,1,{0XA0}},
	{0x95,1,{0X02}},
	{0x96,1,{0XC5}},
	{0x97,1,{0X02}},
	{0x98,1,{0XF8}},
	{0x99,1,{0X03}},
	{0x9A,1,{0X1B}},
	{0x9B,1,{0X03}},
	{0x9C,1,{0X46}},
	{0x9D,1,{0X03}},
	{0x9E,1,{0X52}},
	{0x9F,1,{0X03}},
	{0xA0,1,{0X62}},
	{0xA2,1,{0X03}},
	{0xA3,1,{0X71}},
	{0xA4,1,{0X03}},
	{0xA5,1,{0X83}},
	{0xA6,1,{0X03}},
	{0xA7,1,{0X94}},
	{0xA9,1,{0X03}},
	{0xAA,1,{0XA3}},
	{0xAB,1,{0X03}},
	{0xAC,1,{0XAD}},
	{0xAD,1,{0X03}},
	{0xAE,1,{0XCC}},
		                                
	{0xAF,1,{0X00}},//Gamma B- 
	{0xB0,1,{0X18}},
	{0xB1,1,{0X00}},
	{0xB2,1,{0X38}},
	{0xB3,1,{0X00}},
	{0xB4,1,{0X65}},
	{0xB5,1,{0X00}},
	{0xB6,1,{0X84}},
	{0xB7,1,{0X00}},
	{0xB8,1,{0X9B}},
	{0xB9,1,{0X00}},
	{0xBA,1,{0XAF}},
	{0xBB,1,{0X00}},
	{0xBC,1,{0XC1}},
	{0xBD,1,{0X00}},
	{0xBE,1,{0XD2}},
	{0xBF,1,{0X00}},
	{0xC0,1,{0XDF}},
	{0xC1,1,{0X01}},
	{0xC2,1,{0X11}},
	{0xC3,1,{0X01}},
	{0xC4,1,{0X38}},
	{0xC5,1,{0X01}},
	{0xC6,1,{0X76}},
	{0xC7,1,{0X01}},
	{0xC8,1,{0XA7}},
	{0xC9,1,{0X01}},
	{0xCA,1,{0XF3}},
	{0xCB,1,{0X02}},
	{0xCC,1,{0X2F}},
	{0xCD,1,{0X02}},
	{0xCE,1,{0X30}},
	{0xCF,1,{0X02}},
	{0xD0,1,{0X66}},
	{0xD1,1,{0X02}},
	{0xD2,1,{0XA0}},
	{0xD3,1,{0X02}},
	{0xD4,1,{0XC5}},
	{0xD5,1,{0X02}},
	{0xD6,1,{0XF8}},
	{0xD7,1,{0X03}},
	{0xD8,1,{0X1B}},
	{0xD9,1,{0X03}},
	{0xDA,1,{0X46}},
	{0xDB,1,{0X03}},
	{0xDC,1,{0X52}},
	{0xDD,1,{0X03}},
	{0xDE,1,{0X62}},
	{0xDF,1,{0X03}},
	{0xE0,1,{0X71}},
	{0xE1,1,{0X03}},  
	{0xE2,1,{0X83}},
	{0xE3,1,{0X03}},
	{0xE4,1,{0X94}},
	{0xE5,1,{0X03}},
	{0xE6,1,{0XA3}},
	{0xE7,1,{0X03}},
	{0xE8,1,{0XAD}},
	{0xE9,1,{0X03}},
	{0xEA,1,{0XCC}},
		                             
	{0xFF,1,{0X01}},//CMD page select
	{0xFB,1,{0X01}},//NON-RELOAD CMD 
	{0xFF,1,{0X02}},//CMD page select
	{0xFB,1,{0X01}},//NON-RELOAD CMD 
	{0xFF,1,{0X04}},//CMD page select
	{0xFB,1,{0X01}},//NON-RELOAD CMD 
	{0xFF,1,{0X00}},//CMD page select  
	   
	{0xD3,1,{0X05}},
	{0xD4,1,{0X04}},
	   
	{0x11, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
//{0xFF, 1, {0x00}},


	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}	

};

static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 10, {}},

    // Sleep Mode On
	{0x10, 0, {0x00}},
	
	{0x4f,01,{0x01}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

    for(i = 0; i < count; i++) {
		
        unsigned cmd;
        cmd = table[i].cmd;
		
        switch (cmd) {
			
            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;
				
            case REGFLAG_END_OF_TABLE :
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
	
		params->type   = LCM_TYPE_DSI;

		params->width  = FRAME_WIDTH;
		params->height = FRAME_HEIGHT;

		// enable tearing-free
		params->dbi.te_mode 				= LCM_DBI_TE_MODE_DISABLED;
		//params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;

        #if (LCM_DSI_CMD_MODE)
		params->dsi.mode   = CMD_MODE;
        #else
		params->dsi.mode   = SYNC_PULSE_VDO_MODE; //SYNC_PULSE_VDO_MODE;//BURST_VDO_MODE; 
        #endif
	
		// DSI
		/* Command mode setting */
		//1 Three lane or Four lane
		params->dsi.LANE_NUM				= LCM_FOUR_LANE;
		//The following defined the fomat for data coming from LCD engine.
		params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
		params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
		params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
		params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

		// Highly depends on LCD driver capability.
		// Not support in MT6573
		params->dsi.packet_size=256;

		// Video mode setting		
		params->dsi.intermediat_buffer_num = 0;
		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
		params->dsi.word_count=FRAME_WIDTH*3;	//FRAME_WIDTH

		
		params->dsi.vertical_sync_active				= 2;// 3    2
		params->dsi.vertical_backporch					= 4;// 20   1
		params->dsi.vertical_frontporch					= 16; // 1  12
		params->dsi.vertical_active_line				= FRAME_HEIGHT;

		params->dsi.horizontal_sync_active				= 20;// 50  2
		params->dsi.horizontal_backporch				= 100;
		params->dsi.horizontal_frontporch				= 100;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		params->dsi.PLL_CLOCK=420;//210
}
static void lcm_init(void)
{
	agold_lcm_power_on();
 
	MDELAY(30);

	SET_RESET_PIN(1);
	MDELAY(20); 
	SET_RESET_PIN(0);
	MDELAY(20); 
	
	SET_RESET_PIN(1);
	MDELAY(120);    
	
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}



static void lcm_suspend(void)
{
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	
    LCM_LOGD("reg 0x4f:%d", lcm_initialization_setting[15].para_list[0]);

	SET_RESET_PIN(0);
	MDELAY(100); 
	SET_RESET_PIN(1);
	MDELAY(120);    
	agold_lcm_power_down();
}


static void lcm_resume(void)
{
	lcm_init();
}
         
#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);
	
	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x00290508; //HW bug, so need send one HS packet
	dsi_set_cmdq(data_array, 1, 1);
	
	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);

}
#endif

static unsigned int lcm_compare_id(void)
{
	unsigned int id=0;
	unsigned char buffer[3];
	unsigned int array[16];  

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);
	
	SET_RESET_PIN(1);
	MDELAY(20); 

	array[0] = 0x00033700;// read id return two byte,version and id
	dsi_set_cmdq(array, 3, 1);
	read_reg_v2(0xDA, buffer, 2);

	id = buffer[0];
	LCM_LOGD("SHM047160A read id=0x%x\n", id);

	if(id == 0x83)
    	return 1;
    else
        return 0;
}

/*
static unsigned int lcm_esd_check(void)
{
  #ifndef BUILD_LK
	char  buffer[3];
	int   array[4];

	if(lcm_esd_test)
	{
		lcm_esd_test = 0;
		return 1;
	}

	array[0] = 0x00013700;
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0x36, buffer, 1);
	if(buffer[0]==0x90)
	{
		return 0;
	}
	else
	{			 
		return 1;
	}
 #endif
}
*/

/*
static unsigned int lcm_esd_recover(void)
{
	lcm_init();
	lcm_resume();

	return 1;
}
*/

LCM_DRIVER SF500A_8452A_lcm_drv = 
{
        .name		= "SF500A_8452A",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
	//.esd_check = lcm_esd_check,
	//.esd_recover = lcm_esd_recover,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
    };
