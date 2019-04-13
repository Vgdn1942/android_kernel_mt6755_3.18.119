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

#define GPIO_LCD_ID1_PIN		(89 | 0x80000000)
#define FRAME_WIDTH  (720)
#define FRAME_HEIGHT (1280)

#define GPIO_LCD_PWR_LDO_PIN		11
#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))
#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))
#define REGFLAG_DELAY             							0XFE
#define REGFLAG_END_OF_TABLE      							0x100   // END OF REGISTERS MARKER
#define   LCM_DSI_CMD_MODE							0

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	        lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

//static unsigned int lcm_esd_test = 0;
static LCM_UTIL_FUNCS lcm_util = {0};

extern int lcm_power_on(void);
extern int lcm_power_down(void);

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};
static struct LCM_setting_table init_setting[] = {

{0xF0, 5, {0x55,0xAA,0x52,0x08,0x00}},
{0xB1, 2, {0x78,0x21 }},	//21
{0xB6, 1, {0x01 }},
{0xB8, 4, {0x01,0x02,0x08,0x02 }},
{0xBB, 2, {0x11,0x11 }},
{0xBC, 2, {0x00,0x00 }},	//00
{0xBD, 5, {0x01,0xA3,0x20,0x10,0x01}},
{0xC8, 1, {0x80}},

{0xF0, 5, {0x55,0xAA,0x52,0x08,0x01}},

{0xB0, 2, {0x0F,0x0F}}, 	//0f	5v ->5.2V
{0xB1, 2, {0x0F,0x0F}}, 	//0f

{0xB3, 2, {0x28,0x28}}, 	//19

{0xB4, 2, {0x19,0x19}}, 	//0F

{0xB5, 2, {0x05,0x05}},

{0xB9, 2, {0x36,0x36}},

{0xBA, 2, {0x26,0x26}},

{0xBC, 2, {0x64,0x00}}, 	//64
{0xBD, 2, {0x6C,0x00}},


{0xBE, 2, {0x5A}},	//35 46	4A 48 52 4C 4E
					//4D 4A	(50 60) (70 40 差) (65 55)4F
					//5A 5C (5A)

{0xC0, 1, {0x0C}},
{0xCA, 1, {0x00}},

{0xF0, 5, {0x55,0xAA,0x52,0x08,0x02}},
{0xEE, 1, {0x01}},
{0xB0, 16,{0x00,0xAF,0x00,0xB9,0x00,0xCC,0x00,0xDD,0x00,0xEC,0x01,0x06,0x01,0x1B,0x01,0x40}},
{0xB1, 16,{0x01,0x5F,0x01,0x94,0x01,0xC0,0x02,0x05,0x02,0x3D,0x02,0x3F,0x02,0x71,0x02,0xAA}},
{0xB2, 16,{0x02,0xD2,0x02,0xFC,0x03,0x1B,0x03,0x45,0x03,0x60,0x03,0x7E,0x03,0x92,0x03,0xA8}},
{0xB3, 4, {0x03,0xBC,0x03,0xFF}},

{0xF0, 5, {0x55,0xAA,0x52,0x08,0x03}},
{0xB0, 2, {0x20,0x00 }},
{0xB1, 2, {0x20,0x00 }},
{0xB2, 5, {0x04,0x00,0x52,0x01,0x51}},
{0xB3, 5, {0x04,0x00,0x52,0x01,0x51}},
{0xB6, 5, {0x04,0x00,0x52,0x01,0x51}},
{0xB7, 5, {0x04,0x00,0x52,0x01,0x51}},
{0xBA, 5, {0x44,0x00,0x60,0x01,0x72}},
{0xBB, 5, {0x44,0x00,0x60,0x01,0x72}},
{0xBC, 5, {0x53,0x00,0x03,0x00,0x48}},
{0xBD, 5, {0x53,0x00,0x03,0x00,0x48}},
{0xC4, 1, {0x40 }},
{0xC5, 1, {0x40 }},

{0xF0, 5, {0x55,0xAA,0x52,0x08,0x05}},
{0xB0, 2, {0x17,0x06 }},
{0xB8, 1, {0x00 }},
{0xBD, 5, {0x0F,0x03,0x03,0x00,0x03 }},
{0xB1, 2, {0x17,0x06}},
{0xB9, 1, {0x00}},
{0xB2, 2, {0x17,0x06}},
{0xBA, 1, {0x00 }},
{0xB3, 2, {0x17,0x06 }},
{0xBB, 1, {0x00 }},
{0xB4, 2, {0x17,0x06}},
{0xB5, 2, {0x17,0x06}},
{0xB6, 2, {0x17,0x06}},
{0xB7, 2, {0x17,0x06}},
{0xBC, 1, {0x00 }},
{0xE5, 1, {0x06 }},
{0xE6, 1, {0x06 }},
{0xE7, 1, {0x06 }},
{0xE8, 1, {0x06 }},
{0xE9, 1, {0x0A }},
{0xEA, 1, {0x06 }},
{0xEB, 1, {0x06 }},
{0xEC, 1, {0x06 }},
{0xED, 1, {0x30 }},
{0xC0, 1, {0x07 }},
{0xC1, 1, {0x05 }},
{0xC4, 1, {0x82 }},
{0xC5, 1, {0x80 }},
{0xC8, 3, {0x03,0x20 }},
{0xC9, 3, {0x01,0x21 }},
{0xCA, 3, {0x03,0x20 }},
{0xCB, 3, {0x07,0x20 }},
{0xD1, 11,{0x03,0x05,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
{0xD2, 11,{0x03,0x05,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
{0xD3, 11,{0x00,0x05,0x04,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
{0xD4, 11,{0x00,0x05,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0xF0, 5, {0x55,0xAA,0x52,0x08,0x06}},
{0xB0, 2, {0x2E,0x2E}},
{0xB1, 2, {0x2E,0x2E}},
{0xB2, 2, {0x2E,0x2E}},
{0xB3, 2, {0x2E,0x09}},
{0xB4, 2, {0x0B,0x23}},
{0xB5, 2, {0x1D,0x1F}},
{0xB6, 2, {0x11,0x17}},
{0xB7, 2, {0x13,0x19}},
{0xB8, 2, {0x01,0x03}},
{0xB9, 2, {0x2E,0x2E}},
{0xBA, 2, {0x2E,0x2E}},
{0xBB, 2, {0x02,0x00}},
{0xBC, 2, {0x18,0x12}},
{0xBD, 2, {0x16,0x10}},
{0xBE, 2, {0x1E,0x1C}},
{0xBF, 2, {0x22,0x0A}},
{0xC0, 2, {0x08,0x2E}},
{0xC1, 2, {0x2E,0x2E}},
{0xC2, 2, {0x2E,0x2E}},
{0xC3, 2, {0x2E,0x2E}},
{0xE5, 2, {0x25,0x24}},
{0xC4, 2, {0x2E,0x2E}},
{0xC5, 2, {0x2E,0x2E}},
{0xC6, 2, {0x2E,0x2E}},
{0xC7, 2, {0x2E,0x02}},
{0xC8, 2, {0x00,0x24}},
{0xC9, 2, {0x1E,0x1C}},
{0xCA, 2, {0x18,0x12}},
{0xCB, 2, {0x16,0x10}},
{0xCC, 2, {0x0A,0x08}},
{0xCD, 2, {0x2E,0x2E}},
{0xCE, 2, {0x2E,0x2E}},
{0xCF, 2, {0x09,0x0B}},
{0xD0, 2, {0x11,0x17}},
{0xD1, 2, {0x13,0x19}},
{0xD2, 2, {0x1D,0x1F}},
{0xD3, 2, {0x25,0x01}},
{0xD4, 2, {0x03,0x2E}},
{0xD5, 2, {0x2E,0x2E}},
{0xD6, 2, {0x2E,0x2E}},
{0xD7, 2, {0x2E,0x2E}},
{0xE6, 2, {0x22,0x23}},
{0xD8, 5, {0x00,0x00,0x00,0x00,0x00}},
{0xD9, 5, {0x00,0x00,0x00,0x00,0x00}},
{0xE7, 1, {0x00}},

	{0x11,0,{0x00}},
	{REGFLAG_DELAY, 120, {}},	//120
	{0x29,0,{0x00}},
	{REGFLAG_DELAY, 20, {}},	//60

	{REGFLAG_END_OF_TABLE, 0x00, {}}

};

static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 20, {}},

    // Sleep Mode On
	{0x10, 0, {0x00}},
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

		params->physical_width  = 62 ;
		params->physical_height = 110;

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
		params->dsi.word_count=720*3;


		params->dsi.vertical_sync_active				= 8;// 3    2  0x3
		params->dsi.vertical_backporch					= 16;// 20   1 0x8
		params->dsi.vertical_frontporch					= 16;//0x10; // 1  12  0x8
		params->dsi.vertical_active_line				= FRAME_HEIGHT;

		params->dsi.horizontal_sync_active				= 4;// 50  2  0xb
		params->dsi.horizontal_backporch				= 65;  //  0x40
		params->dsi.horizontal_frontporch				= 65;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		params->dsi.PLL_CLOCK = 221;	//jishu
		params->dsi.ssc_disable = 1; //（关闭展频）
}

static void lcm_init(void)
{
	lcm_power_on();

	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(10);	//20
	SET_RESET_PIN(0);
	MDELAY(10); //20
	SET_RESET_PIN(1);
	MDELAY(50); 	//100

	push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend(void)
{
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);

	lcm_power_down();
}


static void lcm_resume(void)
{
//	init_setting[18].para_list[0]-=0x05;
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

unsigned int id1 = 0;
	unsigned int id2 = 0;
	unsigned int id3 = 0;

	LCM_LOGI("[Jason]lcm_compare_id\n");
#if defined(BUILD_LK)
	LCM_LOGI("[Jason]lk read id\n");
	id1 = mt_get_gpio_in(GPIO_LCD_ID1_PIN);
	id2 = mt_get_gpio_in(GPIO_LCD_ID2_PIN);
	id3 = mt_get_gpio_in(GPIO_LCD_ID3_PIN);

	printf("[Jason]SHM047160B 0x%x\n",id1);
	printf("[Jason]SHM047160B 0x%x\n",id2);
	printf("[Jason]SHM047160B 0x%x\n",id3);
#else
	LCM_LOGI("ili9881c 0x%x\n",id1);
#endif

	if((id1 == 1) && (id2 == 0) && (id3 == 0))
		return 1;
	else
		return 0;

/*
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
*/
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

LCM_DRIVER NT35521_SHM047160B_lcm_drv = {
    .name		= "NT35521_SHM047160B",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
	//.esd_check = lcm_esd_check,
	//.esd_recover = lcm_esd_recover,
	//.set_backlight  = lcm_backlight_control,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
};
