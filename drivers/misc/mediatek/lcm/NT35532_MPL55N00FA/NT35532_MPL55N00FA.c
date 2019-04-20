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
/*
static void NT35532_DCS_write_1A_1P(unsigned char cmd, unsigned char para)
{
  unsigned int data_array[16];
  //unsigned char buffer;
  data_array[0] =(0x00022902);
  data_array[1] =(0x00000000| (para<<8)|(cmd));
  dsi_set_cmdq(data_array, 2, 1);
  //MDELAY(1);
}
*/

static struct LCM_setting_table init_setting[] = {

{0xFF,1,{0x00}},
{0x36,1,{0x00}},
{0xB0,1,{0x00}},
{0xBA,1,{0x03}},
{0xD3,1,{0x08}},
{0xD4,1,{0x0E}},
{0xD5,1,{0x0F}},
{0xD6,1,{0x48}},
{0xD7,1,{0x00}},
{0xD9,1,{0x00}},
{0xFF,1,{0xEE}},
{0xFB,1,{0x01}},
{0x40,1,{0x00}},
{0x41,1,{0x00}},
{0x42,1,{0x00}},
{0xFF,1,{0x01}},
{0xFB,1,{0x01}},
{0xFF,1,{0x02}},
{0xFB,1,{0x01}},
{0xFF,1,{0x05}},
{0xFB,1,{0x01}},
{0xFF,1,{0x01}},
{0x01,1,{0x55}},
{0x04,1,{0x0C}},
{0x05,1,{0x3A}},
{0x06,1,{0x50}},
{0x07,1,{0xD0}},
{0x0A,1,{0x0F}},
{0x0C,1,{0x06}},
{0x0D,1,{0x7F}},
{0x0E,1,{0x7F}},
{0x0F,1,{0x70}},
{0x10,1,{0x63}},
{0x11,1,{0x3C}},
{0x12,1,{0x5C}},
{0x13,1,{0x46}},
{0x14,1,{0x46}},
{0x15,1,{0x60}},
{0x16,1,{0x11}},
{0x17,1,{0x11}},
{0x1C,1,{0xA3}},
{0x5B,1,{0xCA}},
{0x5C,1,{0x00}},
{0x5D,1,{0x00}},
{0x5F,1,{0x1B}},
{0x60,1,{0xD5}},
{0x61,1,{0xF7}},
{0x6C,1,{0xAB}},
{0x6D,1,{0x44}},
{0xFF,1,{0x05}},
{0x00,1,{0x3F}},
{0x01,1,{0x3F}},
{0x02,1,{0x3F}},
{0x03,1,{0x3F}},
{0x04,1,{0x38}},
{0x05,1,{0x3F}},
{0x06,1,{0x3F}},
{0x07,1,{0x19}},
{0x08,1,{0x1D}},
{0x09,1,{0x3F}},
{0x0A,1,{0x3F}},
{0x0B,1,{0x1B}},
{0x0C,1,{0x17}},
{0x0D,1,{0x3F}},
{0x0E,1,{0x3F}},
{0x0F,1,{0x08}},
{0x10,1,{0x3F}},
{0x11,1,{0x10}},
{0x12,1,{0x3F}},
{0x13,1,{0x3F}},
{0x14,1,{0x3F}},
{0x15,1,{0x3F}},
{0x16,1,{0x3F}},
{0x17,1,{0x3F}},
{0x18,1,{0x38}},
{0x19,1,{0x18}},
{0x1A,1,{0x1C}},
{0x1B,1,{0x3F}},
{0x1C,1,{0x3F}},
{0x1D,1,{0x1A}},
{0x1E,1,{0x16}},
{0x1F,1,{0x3F}},
{0x20,1,{0x3F}},
{0x21,1,{0x3F}},
{0x22,1,{0x3F}},
{0x23,1,{0x06}},
{0x24,1,{0x3F}},
{0x25,1,{0x0E}},
{0x26,1,{0x3F}},
{0x27,1,{0x3F}},      
{0x54,1,{0x06}},
{0x55,1,{0x05}},
{0x56,1,{0x04}},
{0x58,1,{0x03}},
{0x59,1,{0x1B}},
{0x5A,1,{0x1B}},
{0x5B,1,{0x01}},
{0x5C,1,{0x32}},
{0x5E,1,{0x18}},
{0x5F,1,{0x20}},
{0x60,1,{0x2B}},
{0x61,1,{0x2C}},
{0x62,1,{0x18}},
{0x63,1,{0x01}},
{0x64,1,{0x32}},
{0x65,1,{0x00}},
{0x66,1,{0x44}},
{0x67,1,{0x11}},
{0x68,1,{0x01}},
{0x69,1,{0x01}},
{0x6A,1,{0x04}},
{0x6B,1,{0x2C}},
{0x6C,1,{0x08}},
{0x6D,1,{0x08}},
{0x78,1,{0x00}},
{0x79,1,{0x00}},
{0x7E,1,{0x00}},
{0x7F,1,{0x00}},
{0x80,1,{0x00}},
{0x81,1,{0x00}},
{0x8D,1,{0x00}},
{0x8E,1,{0x00}},
{0x8F,1,{0xC0}},
{0x90,1,{0x73}},
{0x91,1,{0x10}},
{0x92,1,{0x07}},
{0x96,1,{0x11}},
{0x97,1,{0x14}},
{0x98,1,{0x00}},
{0x99,1,{0x00}},
{0x9A,1,{0x00}},
{0x9B,1,{0x61}},
{0x9C,1,{0x15}},
{0x9D,1,{0x30}},
{0x9F,1,{0x0F}},
{0xA2,1,{0xB0}},
{0xA7,1,{0x0A}},
{0xA9,1,{0x00}},
{0xAA,1,{0x70}},
{0xAB,1,{0xDA}},
{0xAC,1,{0xFF}},
{0xAE,1,{0xF4}},
{0xAF,1,{0x40}},
{0xB0,1,{0x7F}},
{0xB1,1,{0x16}},
{0xB2,1,{0x53}},
{0xB3,1,{0x00}},
{0xB4,1,{0x2A}},
{0xB5,1,{0x3A}},
{0xB6,1,{0xF0}},
{0xBC,1,{0x85}},
{0xBD,1,{0xF4}},
{0xBE,1,{0x33}},
{0xBF,1,{0x13}},
{0xC0,1,{0x77}},
{0xC1,1,{0x77}},
{0xC2,1,{0x77}},
{0xC3,1,{0x77}},
{0xC4,1,{0x77}},
{0xC5,1,{0x77}},
{0xC6,1,{0x77}},
{0xC7,1,{0x77}},
{0xC8,1,{0xAA}},
{0xC9,1,{0x2A}},
{0xCA,1,{0x00}},
{0xCB,1,{0xAA}},
{0xCC,1,{0x92}},
{0xCD,1,{0x00}},
{0xCE,1,{0x18}},
{0xCF,1,{0x88}},
{0xD0,1,{0xAA}},
{0xD1,1,{0x00}},
{0xD2,1,{0x00}},
{0xD3,1,{0x00}},
{0xD6,1,{0x02}},
{0xD7,1,{0x31}},
{0xD8,1,{0x7E}},
{0xED,1,{0x00}},
{0xEE,1,{0x00}},
{0xEF,1,{0x70}},
{0xFA,1,{0x03}},


{0xFF,1,{0x00}},

{0x11, 0, {0x00}},
{REGFLAG_DELAY, 120, {}},
{0x29, 0, {0x00}},
{REGFLAG_DELAY, 20, {}},

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
	
	
	params->physical_width = 68;
	params->physical_height = 121;
	
	/* video mode timing */

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active = 2;//2,12,2
	params->dsi.vertical_backporch = 6;//12,20,14
	params->dsi.vertical_frontporch = 14;//13,20,16
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 8;//20;//10,12,8
	params->dsi.horizontal_backporch = 50;//80,40,16
	params->dsi.horizontal_frontporch = 60;//60;//80,40,24,
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 450;//430
	
/*
	params->dsi.ssc_disable = 1;  // ssc disable control (1: disable, 0: enable, default: 0)

    params->dsi.clk_lp_per_line_enable=1;
    params->dsi.esd_check_enable = 1;
    params->dsi.customization_esd_check_enable = 1;

    params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
    params->dsi.lcm_esd_check_table[0].count = 1;
    params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9C;
	   params->dsi.noncont_clock = 1; 
      params->dsi.noncont_clock_period = 2; 
     
*/
}



static void lcm_init(void)
{
	LCM_LOGI("lcm_init enter\n");

	agold_lcm_power_on();
	
	SET_RESET_PIN(1);
	MDELAY(100);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(100);
	//init_lcm_registers();
	push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
	//LCM_LOGI("[cp] %s,reg[%x]: = %x\n", __func__, init_setting[9].cmd,init_setting[9].para_list[0]);
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

	MDELAY(120);
	SET_RESET_PIN(0);
	MDELAY(60);
	agold_lcm_power_down();
	
}

/*
static unsigned int lcm_compare_id(void)
{
	unsigned int id1=0;
	unsigned int id2=0;
	unsigned int id3=0;
	unsigned int id4=0;
	unsigned char buffer[4];
	unsigned int array[16];  

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);
	
	SET_RESET_PIN(1);
	MDELAY(20); 
	array[0] = 0x00033700;// read id return three byte, manufacture id,version id and driver id
	dsi_set_cmdq(array, 3, 1);
	read_reg_v2(0xDA, buffer, 1);
	read_reg_v2(0xDB, buffer+1, 1);
	read_reg_v2(0xDC, buffer+2, 1);
	read_reg_v2(0xF4, buffer+3, 1);
	id1 = buffer[0];	//0x00
	id2 = buffer[1];	//0x80
	id3 = buffer[2];	//0x00
	id4 = buffer[3];	//0x32
	#ifdef BUILD_LK
	printf("[Jason] NT35532_LB055331 read id1=0x%x,id2=0x%0x,id3=0x%0x\n id4=0x%0x", id1,id2,id3,id4);		
	#endif
	
	return 0;

}
*/
static void lcm_init_power(void)
{
	LCM_LOGI("[cp]lcm_init_power enter\n");
}


LCM_DRIVER NT35532_MPL55N00FA_lcm_drv = {
	.name = "NT35532_MPL55N00FA",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
//	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,

};
