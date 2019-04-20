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


	{0XFF,3,{0x78,0x07,0x01}},	   //Page1
	{0X42,1,{0x11}},	   //VGH=x4 VGL=x4
	{0X43,1,{0xA3}},	   //VGH_CLP = 9.5V
	{0X44,1,{0xA8}},	   //VGL_CLP = -9V
      
	{0X45,1,{0x19}},	   //VGHO  = 8.5 V
	{0X46,1,{0x28}},	   //VGLO  = -8.0V
         
	{0X4A,1,{0x12}},	   //disable VSPR
	{0X4B,1,{0x12}},	   //disable VSNR
         
	{0X50,1,{0x5F}},	   //GVDDP  = 4.9V
	{0X51,1,{0x5F}},	   //GVDDN  = -4.9V
         
	{0XB3,1,{0x70}},	   //VGHO setting
	{0XB4,1,{0x70}},	   //VGLO setting
        
	{0XA2,1,{0x01}},	   //VCOM1
	{0XA3,1,{0x1C}},	   //VCOM1

	//GIP & SOURCE
	{0XFF,3,{0x78,0x07,0x01}},	   //Page1
	{0X22,1,{0x06}},	   //SS&NW
	{0X36,1,{0x00}},       //2   mux 6
	{0X63,1,{0x04}},       //SDT
	{0X64,1,{0x08}},
	{0X6C,1,{0x45}},	   //PRC & PRCB
	{0X6D,1,{0x00}},	   //PCT2
	{0X5A,1,{0x66}},	   //LVD setting 4.2
    {0X59,1,{0x35}},   	   //LVD setting 1.5
    {0X57,1,{0x89}},
    
    {0XFF,3,{0x78,0x07,0x07}},   //Page7
    {0XCA,1,{0x23}},	   //abnormal power off
    
	{0XFF,3,{0x78,0x07,0x06}},   //Page6
	{0X00,1,{0x43}},       //
	{0X01,1,{0x12}},       //
	{0X02,1,{0x43}},       //jhc
	{0X03,1,{0x43}},       //jhc
	{0X04,1,{0x03}},       //
	{0X05,1,{0x12}},       //
	{0X06,1,{0x08}},       //
	{0X07,1,{0x0A}},       //
	{0X08,1,{0x83}},       //
	{0X09,1,{0x02}},      //
	{0X0A,1,{0x30}},       //
	{0X0B,1,{0x10}},       //
	{0X0C,1,{0x08}},       //
	{0X0D,1,{0x08}},       //
	{0X0E,1,{0x00}},       //
	{0X0F,1,{0x00}},       //
	{0X10,1,{0x00}},
	{0X11,1,{0x00}},
	{0X12,1,{0x00}},
	{0X13,1,{0x00}},
	{0X14,1,{0x84}},       //
	{0X15,1,{0x84}},      //
           
	{0X31,1,{0x08}},     // GOUTR_01_FW STV
	{0X32,1,{0x01}},     // GOUTR_02_FW U2D
	{0X33,1,{0x00}},     // GOUTR_03_FW D2U
	{0X34,1,{0x11}},    // GOUTR_04_FW CLK_L
	{0X35,1,{0x13}},    // GOUTR_05_FW XCLK_L
	{0X36,1,{0x26}},     // GOUTR_06_FW RST
	{0X37,1,{0x22}},    // GOUTR_07_FW XDONB = GAS
	{0X38,1,{0x02}},     // GOUTR_08_FW CTRL jhc
	{0X39,1,{0x0C}},     // GOUTR_09_FW V_END
	{0X3A,1,{0x02}},    // GOUTR_10_FW CTRL
	{0X3B,1,{0x02}},     // GOUTR_11_FW CTRL
	{0X3C,1,{0x02}},     // GOUTR_12_FW CTRL
	{0X3D,1,{0x02}},     // GOUTR_13_FW CTRL
	{0X3E,1,{0x28}},     // GOUTR_14_FW SWR
	{0X3F,1,{0x29}},     // GOUTR_15_FW SWG
	{0X40,1,{0x2A}},    // GOUTR_16_FW SWB
           
	{0X41,1,{0x08}},     // GOUTL_01_FW STV
	{0X42,1,{0x01}},     // GOUTL_02_FW U2D
	{0X43,1,{0x00}},     // GOUTL_03_FW D2U
	{0X44,1,{0x10}},    // GOUTL_04_FW CLK_R
	{0X45,1,{0x12}},    // GOUTL_05_FW XCLK_R
	{0X46,1,{0x26}},     // GOUTL_06_FW RST
	{0X47,1,{0x22}},    // GOUTL_07_FW XDONB = GAS
	{0X48,1,{0x02}},    // GOUTL_08_FW CTRL jhc
	{0X49,1,{0x0C}},    // GOUTL_09_FW V_END
	{0X4A,1,{0x02}},    // GOUTL_10_FW CTRL
	{0X4B,1,{0x02}},    // GOUTL_11_FW CTRL
	{0X4C,1,{0x02}},     // GOUTL_12_FW CTRL
	{0X4D,1,{0x02}},    // GOUTL_13_FW CTRL
	{0X4E,1,{0x28}},     // GOUTL_14_FW SWR
	{0X4F,1,{0x29}},     // GOUTL_15_FW SWG
	{0X50,1,{0x2A}},    // GOUTL_16_FW SWB
           
	{0X61,1,{0x0C}},     // GOUTR_01_BW STV
	{0X62,1,{0x01}},     // GOUTR_02_BW U2D
	{0X63,1,{0x00}},     // GOUTR_03_BW D2U
	{0X64,1,{0x12}},    // GOUTR_04_BW CLK_L
	{0X65,1,{0x10}},     // GOUTR_05_BW XCLK_L
	{0X66,1,{0x26}},     // GOUTR_06_BW RST
	{0X67,1,{0x22}},     // GOUTR_07_BW XCONB = GAS
	{0X68,1,{0x02}},     // GOUTR_08_BW CTRL jhc
	{0X69,1,{0x08}},     // GOUTR_09_BW V_END
	{0X6A,1,{0x02}},     // GOUTR_10_BW CTRL
	{0X6B,1,{0x02}},     // GOUTR_11_BW CTRL
	{0X6C,1,{0x02}},     // GOUTR_12_BW CTRL
	{0X6D,1,{0x02}},    // GOUTR_13_BW CTRL
	{0X6E,1,{0x28}},     // GOUTR_14_BW SWR
	{0X6F,1,{0x29}},    // GOUTR_15_BW SWG
	{0X70,1,{0x2A}},    // GOUTR_16_BW SWG
   
	{0X71,1,{0x0C}},     // GOUTL_01_BW STV
	{0X72,1,{0x01}},     // GOUTL_02_BW U2D
	{0X73,1,{0x00}},    // GOUTL_03_BW D2U
	{0X74,1,{0x13}},     // GOUTL_04_BW CLK_R
	{0X75,1,{0x11}},     // GOUTL_05_BW XCLK_R
	{0X76,1,{0x26}},     // GOUTL_06_BW RST
	{0X77,1,{0x22}},     // GOUTL_07_BW XDONB = GAS
	{0X78,1,{0x02}},     // GOUTL_08_BW CTRL jhc
	{0X79,1,{0x08}},    // GOUTL_09_BW V_END
	{0X7A,1,{0x02}},    // GOUTL_10_BW CRTL
	{0X7B,1,{0x02}},    // GOUTL_11_BW CTRL
	{0X7C,1,{0x02}},    // GOUTL_12_BW CTRL
	{0X7D,1,{0x02}},     // GOUTL_13_BW CTRL
	{0X7E,1,{0x28}},    // GOUTL_14_BW SWR
	{0X7F,1,{0x29}},     // GOUTL_15_BW SWG
	{0X80,1,{0x2A}},     // GOUTL_16_BW SWB
   
	{0XD0,1,{0x01}},
	{0XD1,1,{0x01}},
	{0XD2,1,{0x10}},      //jhc
	{0XD3,1,{0x00}},
	{0XD4,1,{0x00}},
	{0XD5,1,{0x00}},
	{0XD6,1,{0x00}},
	{0XD7,1,{0x00}},
	{0XD8,1,{0x00}},
	{0XD9,1,{0x00}},
	{0XDA,1,{0x00}},
	{0XDB,1,{0x47}},
	{0XDC,1,{0x02}},     //jhc
	{0XDD,1,{0x55}},
    
	{0X96,1,{0x80}},
	{0X97,1,{0x33}},      //jhc
	{0XA0,1,{0x10}},     //T8
	{0XA1,1,{0x00}},     //T7P  Pre-CKH
	{0XA2,1,{0x08}},     //T9P  T9= non overlap time
	{0XA3,1,{0x1E}},     //T7 = CHK width 1.9us
	{0XA7,1,{0x00}},
	{0XA6,1,{0x32}},
	{0XA7,1,{0x03}},
	{0XAE,1,{0x14}},
	{0XE5,1,{0x80}},
	//===CKH Modulation====
	//SSD2828_Gen_1A_1P(0XB1,0x33);
	{0XB2,1,{0x04}},
	{0XB3,1,{0x04}},
	//SSD2828_Gen_1A_1P(0XB4,0x33);
	//SSD2828_Gen_1A_1P(0XB5,0x08);
	//SSD2828_Gen_1A_1P(0XB6,0x08);
	
	//============Gamma START=============
	{0XFF,3,{0x78,0x07,0x02}},

	{0X00,1,{0x01}},
	{0X01,1,{0x9B}},
	{0X02,1,{0x01}},
	{0X03,1,{0x9E}},
	{0X04,1,{0x01}},
	{0X05,1,{0xA2}},
	{0X06,1,{0x01}},
	{0X07,1,{0xA6}},
	{0X08,1,{0x01}},
	{0X09,1,{0xAA}},
	{0X0A,1,{0x01}},
	{0X0B,1,{0xAE}},
	{0X0C,1,{0x01}},
	{0X0D,1,{0xB2}},
	{0X0E,1,{0x01}},
	{0X0F,1,{0xB6}},
	{0X10,1,{0x01}},
	{0X11,1,{0xB9}},
	{0X12,1,{0x01}},
	{0X13,1,{0xC7}},
	{0X14,1,{0x01}},
	{0X15,1,{0xD4}},
	{0X16,1,{0x01}},
	{0X17,1,{0xEB}},
	{0X18,1,{0x01}},
	{0X19,1,{0xFF}},
	{0X1A,1,{0x02}},
	{0X1B,1,{0x24}},
	{0X1C,1,{0x02}},
	{0X1D,1,{0x46}},
	{0X1E,1,{0x02}},
	{0X1F,1,{0x47}},
	{0X20,1,{0x02}},
	{0X21,1,{0x6D}},
	{0X22,1,{0x02}},
	{0X23,1,{0x9E}},
	{0X24,1,{0x02}},
	{0X25,1,{0xC1}},
	{0X26,1,{0x02}},
	{0X27,1,{0xF2}},
	{0X28,1,{0x03}},
	{0X29,1,{0x12}},
	{0X2A,1,{0x03}},
	{0X2B,1,{0x3D}},
	{0X2C,1,{0x03}},
	{0X2D,1,{0x4A}},
	{0X2E,1,{0x03}},
	{0X2F,1,{0x58}},
	{0X30,1,{0x03}},
	{0X31,1,{0x67}},
	{0X32,1,{0x03}},
	{0X33,1,{0x7A}},
	{0X34,1,{0x03}},
	{0X35,1,{0x90}},
	{0X36,1,{0x03}},
	{0X37,1,{0xAF}},
	{0X38,1,{0x03}},
	{0X39,1,{0xD4}},
	{0X3A,1,{0x03}},
	{0X3B,1,{0xE6}},
	{0X3C,1,{0x01}},
	
	{0X3D,1,{0x9B}},
	{0X3E,1,{0x01}},
	{0X3F,1,{0x9E}},
	{0X40,1,{0x01}},
	{0X41,1,{0xA2}},
	{0X42,1,{0x01}},
	{0X43,1,{0xA6}},
	{0X44,1,{0x01}},
	{0X45,1,{0xAA}},
	{0X46,1,{0x01}},
	{0X47,1,{0xAE}},
	{0X48,1,{0x01}},
	{0X49,1,{0xB2}},
	{0X4A,1,{0x01}},
	{0X4B,1,{0xB6}},
	{0X4C,1,{0x01}},
	{0X4D,1,{0xB9}},
	{0X4E,1,{0x01}},
	{0X4F,1,{0xC7}},
	{0X50,1,{0x01}},
	{0X51,1,{0xD4}},
	{0X52,1,{0x01}},
	{0X53,1,{0xEB}},
	{0X54,1,{0x01}},
	{0X55,1,{0xFF}},
	{0X56,1,{0x02}},
	{0X57,1,{0x24}},
	{0X58,1,{0x02}},
	{0X59,1,{0x46}},
	{0X5A,1,{0x02}},
	{0X5B,1,{0x47}},
	{0X5C,1,{0x02}},
	{0X5D,1,{0x6D}},
	{0X5E,1,{0x02}},
	{0X5F,1,{0x9E}},
	{0X60,1,{0x02}},
	{0X61,1,{0xC1}},
	{0X62,1,{0x02}},
	{0X63,1,{0xF2}},
	{0X64,1,{0x03}},
	{0X65,1,{0x12}},
	{0X66,1,{0x03}},
	{0X67,1,{0x3D}},
	{0X68,1,{0x03}},
	{0X69,1,{0x4A}},
	{0X6A,1,{0x03}},
	{0X6B,1,{0x58}},
	{0X6C,1,{0x03}},
	{0X6D,1,{0x67}},
	{0X6E,1,{0x03}},
	{0X6F,1,{0x7A}},
	{0X70,1,{0x03}},
	{0X71,1,{0x90}},
	{0X72,1,{0x03}},
	{0X73,1,{0xAF}},
	{0X74,1,{0x03}},
	{0X75,1,{0xD4}},
	{0X76,1,{0x03}},
	{0X77,1,{0xE6}},


	{0X78,1,{0x01}},
	{0X79,1,{0x01}},

	{0XFF,3,{0x78,0x07,0x03}},

	{0X00,1,{0x01}},
	{0X01,1,{0x5F}},
	{0X02,1,{0x01}},
	{0X03,1,{0x62}},
	{0X04,1,{0x01}},
	{0X05,1,{0x69}},
	{0X06,1,{0x01}},
	{0X07,1,{0x6F}},
	{0X08,1,{0x01}},
	{0X09,1,{0x76}},
	{0X0A,1,{0x01}},
	{0X0B,1,{0x7B}},
	{0X0C,1,{0x01}},
	{0X0D,1,{0x81}},
	{0X0E,1,{0x01}},
	{0X0F,1,{0x87}},
	{0X10,1,{0x01}},
	{0X11,1,{0x8D}},
	{0X12,1,{0x01}},
	{0X13,1,{0xA0}},
	{0X14,1,{0x01}},
	{0X15,1,{0xB2}},
	{0X16,1,{0x01}},
	{0X17,1,{0xD0}},
	{0X18,1,{0x01}},
	{0X19,1,{0xEA}},
	{0X1A,1,{0x02}},
	{0X1B,1,{0x15}},
	{0X1C,1,{0x02}},
	{0X1D,1,{0x3B}},
	{0X1E,1,{0x02}},
	{0X1F,1,{0x3C}},
	{0X20,1,{0x02}},
	{0X21,1,{0x63}},
	{0X22,1,{0x02}},
	{0X23,1,{0x95}},
	{0X24,1,{0x02}},
	{0X25,1,{0xB7}},
	{0X26,1,{0x02}},
	{0X27,1,{0xE8}},
	{0X28,1,{0x03}},
	{0X29,1,{0x08}},
	{0X2A,1,{0x03}},
	{0X2B,1,{0x32}},
	{0X2C,1,{0x03}},
	{0X2D,1,{0x3F}},
	{0X2E,1,{0x03}},
	{0X2F,1,{0x4D}},
	{0X30,1,{0x03}},
	{0X31,1,{0x5C}},
	{0X32,1,{0x03}},
	{0X33,1,{0x6F}},
	{0X34,1,{0x03}},
	{0X35,1,{0x85}},
	{0X36,1,{0x03}},
	{0X37,1,{0xA6}},
	{0X38,1,{0x03}},
	{0X39,1,{0xD1}},
	{0X3A,1,{0x03}},
	{0X3B,1,{0xE6}},
	
	{0X3C,1,{0x01}},
	{0X3D,1,{0x5F}},
	{0X3E,1,{0x01}},
	{0X3F,1,{0x62}},
	{0X40,1,{0x01}},
	{0X41,1,{0x69}},
	{0X42,1,{0x01}},
	{0X43,1,{0x6F}},
	{0X44,1,{0x01}},
	{0X45,1,{0x76}},
	{0X46,1,{0x01}},
	{0X47,1,{0x7B}},
	{0X48,1,{0x01}},
	{0X49,1,{0x81}},
	{0X4A,1,{0x01}},
	{0X4B,1,{0x87}},
	{0X4C,1,{0x01}},
	{0X4D,1,{0x8D}},
	{0X4E,1,{0x01}},
	{0X4F,1,{0xA0}},
	{0X50,1,{0x01}},
	{0X51,1,{0xB2}},
	{0X52,1,{0x01}},
	{0X53,1,{0xD0}},
	{0X54,1,{0x01}},
	{0X55,1,{0xEA}},
	{0X56,1,{0x02}},
	{0X57,1,{0x15}},
	{0X58,1,{0x02}},
	{0X59,1,{0x3B}},
	{0X5A,1,{0x02}},
	{0X5B,1,{0x3C}},
	{0X5C,1,{0x02}},
	{0X5D,1,{0x63}},
	{0X5E,1,{0x02}},
	{0X5F,1,{0x95}},
	{0X60,1,{0x02}},
	{0X61,1,{0xB7}},
	{0X62,1,{0x02}},
	{0X63,1,{0xE8}},
	{0X64,1,{0x03}},
	{0X65,1,{0x08}},
	{0X66,1,{0x03}},
	{0X67,1,{0x32}},
	{0X68,1,{0x03}},
	{0X69,1,{0x3F}},
	{0X6A,1,{0x03}},
	{0X6B,1,{0x4D}},
	{0X6C,1,{0x03}},
	{0X6D,1,{0x5C}},
	{0X6E,1,{0x03}},
	{0X6F,1,{0x6F}},
	{0X70,1,{0x03}},
	{0X71,1,{0x85}},
	{0X72,1,{0x03}},
	{0X73,1,{0xA6}},
	{0X74,1,{0x03}},
	{0X75,1,{0xD1}},
	{0X76,1,{0x03}},
	{0X77,1,{0xE6}},
   
   
	{0X78,1,{0x01}},
	{0X79,1,{0x01}},
    
	{0XFF,3,{0x78,0x07,0x04}},

	{0X00,1,{0x01}},
	{0X01,1,{0x36}},
	{0X02,1,{0x01}},
	{0X03,1,{0x3C}},
	{0X04,1,{0x01}},
	{0X05,1,{0x45}},
	{0X06,1,{0x01}},
	{0X07,1,{0x4E}},
	{0X08,1,{0x01}},
	{0X09,1,{0x57}},
	{0X0A,1,{0x01}},
	{0X0B,1,{0x5F}},
	{0X0C,1,{0x01}},
	{0X0D,1,{0x66}},
	{0X0E,1,{0x01}},
	{0X0F,1,{0x6D}},
	{0X10,1,{0x01}},
	{0X11,1,{0x74}},
	{0X12,1,{0x01}},
	{0X13,1,{0x8D}},
	{0X14,1,{0x01}},
	{0X15,1,{0xA2}},
	{0X16,1,{0x01}},
	{0X17,1,{0xC5}},
	{0X18,1,{0x01}},
	{0X19,1,{0xE1}},
	{0X1A,1,{0x02}},
	{0X1B,1,{0x0F}},
	{0X1C,1,{0x02}},
	{0X1D,1,{0x37}},
	{0X1E,1,{0x02}},
	{0X1F,1,{0x38}},
	{0X20,1,{0x02}},
	{0X21,1,{0x5F}},
	{0X22,1,{0x02}},
	{0X23,1,{0x91}},
	{0X24,1,{0x02}},
	{0X25,1,{0xB4}},
	{0X26,1,{0x02}},
	{0X27,1,{0xE6}},
	{0X28,1,{0x03}},
	{0X29,1,{0x08}},
	{0X2A,1,{0x03}},
	{0X2B,1,{0x36}},
	{0X2C,1,{0x03}},
	{0X2D,1,{0x45}},
	{0X2E,1,{0x03}},
	{0X2F,1,{0x56}},
	{0X30,1,{0x03}},
	{0X31,1,{0x67}},
	{0X32,1,{0x03}},
	{0X33,1,{0x79}},
	{0X34,1,{0x03}},
	{0X35,1,{0x8D}},
	{0X36,1,{0x03}},
	{0X37,1,{0xAD}},
	{0X38,1,{0x03}},
	{0X39,1,{0xD3}},
	{0X3A,1,{0x03}},
	{0X3B,1,{0xE6}},
	
	{0X3C,1,{0x01}},
	{0X3D,1,{0x36}},
	{0X3E,1,{0x01}},
	{0X3F,1,{0x3C}},
	{0X40,1,{0x01}},
	{0X41,1,{0x45}},
	{0X42,1,{0x01}},
	{0X43,1,{0x4E}},
	{0X44,1,{0x01}},
	{0X45,1,{0x57}},
	{0X46,1,{0x01}},
	{0X47,1,{0x5F}},
	{0X48,1,{0x01}},
	{0X49,1,{0x66}},
	{0X4A,1,{0x01}},
	{0X4B,1,{0x6D}},
	{0X4C,1,{0x01}},
	{0X4D,1,{0x74}},
	{0X4E,1,{0x01}},
	{0X4F,1,{0x8D}},
	{0X50,1,{0x01}},
	{0X51,1,{0xA2}},
	{0X52,1,{0x01}},
	{0X53,1,{0xC5}},
	{0X54,1,{0x01}},
	{0X55,1,{0xE1}},
	{0X56,1,{0x02}},
	{0X57,1,{0x0F}},
	{0X58,1,{0x02}},
	{0X59,1,{0x37}},
	{0X5A,1,{0x02}},
	{0X5B,1,{0x38}},
	{0X5C,1,{0x02}},
	{0X5D,1,{0x5F}},
	{0X5E,1,{0x02}},
	{0X5F,1,{0x91}},
	{0X60,1,{0x02}},
	{0X61,1,{0xB4}},
	{0X62,1,{0x02}},
	{0X63,1,{0xE6}},
	{0X64,1,{0x03}},
	{0X65,1,{0x08}},
	{0X66,1,{0x03}},
	{0X67,1,{0x36}},
	{0X68,1,{0x03}},
	{0X69,1,{0x45}},
	{0X6A,1,{0x03}},
	{0X6B,1,{0x56}},
	{0X6C,1,{0x03}},
	{0X6D,1,{0x67}},
	{0X6E,1,{0x03}},
	{0X6F,1,{0x79}},
	{0X70,1,{0x03}},
	{0X71,1,{0x8D}},
	{0X72,1,{0x03}},
	{0X73,1,{0xAD}},
	{0X74,1,{0x03}},
	{0X75,1,{0xD3}},
	{0X76,1,{0x03}},
	{0X77,1,{0xE6}},

	{0X78,1,{0x01}},
	{0X79,1,{0x01}},

	{0XFF,3,{0x78,0x07,0x00}},	   //Page0


	{REGFLAG_DELAY, 10, {}},
	{0x11, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 10, {}},
	{0x35, 1, {0x00}},
	{REGFLAG_DELAY, 10, {}}
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
	unsigned int id = 0;
	unsigned char buffer[2];
	unsigned int array[16];

	SET_RESET_PIN(1);
	MDELAY(10);

	SET_RESET_PIN(0);
	MDELAY(10);

	SET_RESET_PIN(1);
	MDELAY(10);

	array[0] = 0x00023700;	/* read id return two byte,version and id */
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xDB, buffer, 2);
	id = buffer[0];		/* we only need ID */

	if(id == 0x80)
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
	LCM_LOGI("lcm_init_power enter\n");
}


LCM_DRIVER ILI7807D_ZMA55AB25723A_lcm_drv = {
	.name = "ILI7807D_ZMA55AB25723A",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
