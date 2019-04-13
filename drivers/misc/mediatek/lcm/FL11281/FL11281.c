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
#define REGFLAG_DELAY		0xFFFC
#define REGFLAG_UDELAY	0xFFFB
#define REGFLAG_END_OF_TABLE	0xFFFD
#define REGFLAG_RESET_LOW	0xFFFE
#define REGFLAG_RESET_HIGH	0xFFFF
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
       {0xB9,3,{0xF1,0x12,0x81}},

{0xBA,27,{0x33, 0x81, 0x05, 0xF9, 0x0A, 0x0A, 0x02, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x44, 0x25, 0x00, 0x91, 0x0A, 0x00,
          0x00, 0x02, 0x4F, 0x11, 0x00, 0x00, 0x37}},

{0xB8,1,{0xA6}},

{0xB0,1,{0x01}},

{0xB3,11,{0x02,0x00,0x06,0x06,0x07,0x0B,0x1E,0x1E,0x00,0x00,
          0x00,0x03,0xFF,0x00,0x00,0x00,0x00}},

{0xC0,9,{0x73,0x73,0x50,0x50,0x00,0x00,0x08,0x30,0x00}},

{0xBC,1,{0x46}},

{0xBF,2,{0x02,0x11}},

{0xCC,1,{0x0B}},

{0xB4,1,{0x00}},

{0xB2,1,{0xC8}},

{0xE3,10,{0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xC0,0x14}},

{0xB1,10,{0x21,0x56,0xE3,0x1E,0x1E,0x33,0x77,0x01,0x9B,0x0C}},

{0xB5,2,{0x09,0x09}},

{0xB6,2,{0xA1,0xA1}},

{0xE9,63,{0x04,0x00,0x04,0x00,0x00,0x08,0x80,0x12,0x31,0x00,
					0x38,0x08,0x0A,0x80,0x37,0x18,0x10,0x00,0xB0,0x00,
					0x00,0x00,0x10,0x00,0xB0,0x00,0x00,0x00,0x20,0x64,
					0x02,0x84,0x88,0x88,0x88,0x88,0x88,0x89,0x48,0x31,
					0x75,0x13,0x85,0x88,0x88,0x88,0x88,0x88,0x89,0x58,
					0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					0x00,0x00,0x00}},

{0xEA,48,{0x02,0x1A,0x00,0x00,0x57,0x13,0x31,0x85,0x88,0x88,
					0x88,0x88,0x88,0x98,0x58,0x46,0x02,0x20,0x84,0x88,
					0x88,0x88,0x88,0x88,0x98,0x48,0x00,0x14,0x00,0x00,
					0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},

{0xE0,34,{0x00,0x0D,0x13,0x24,0x22,0x3F,0x4B,0x43,0x07,0x0A,
					0x0E,0x13,0x15,0x13,0x15,0x14,0x1A,0x00,0x0D,0x13,
					0x24,0x22,0x3F,0x4B,0x43,0x07,0x0A,0x0E,0x13,0x15,
					0x13,0x15,0x14,0x1A}},

    {0x11, 0, {}},

	{REGFLAG_DELAY, 250, {}},	//120
	{0x29,0,{0x00}},
	{REGFLAG_DELAY, 50, {}},	//60

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

//int NUM=0x00;

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;

	//NUM=NUM+0x01;

    for(i = 0; i < count; i++) {

        unsigned cmd;
        cmd = table[i].cmd;
        switch (cmd) {

            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;

            case REGFLAG_END_OF_TABLE :
                break;

			//case 0XB6:
			//	table[i].para_list[0]=table[i].para_list[0]+NUM;
			//	table[i].para_list[1]=table[i].para_list[1]+NUM;
			//	dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
			//	break;

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


	params->dsi.vertical_sync_active = 2;//
	params->dsi.vertical_backporch = 12;//
	params->dsi.vertical_frontporch = 14;//
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 20;
	params->dsi.horizontal_backporch = 90;
	params->dsi.horizontal_frontporch = 90;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 230;
	params->dsi.ssc_disable = 0;

    /*params->dsi.clk_lp_per_line_enable=1;
    params->dsi.esd_check_enable = 1;
    params->dsi.customization_esd_check_enable = 1;

    params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
    params->dsi.lcm_esd_check_table[0].count = 1;
    params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9C;
    params->dsi.cont_clock = 0;
	   params->dsi.noncont_clock = 1;
      params->dsi.noncont_clock_period = 2; */
}

static void lcm_init(void)
{
	lcm_power_on();

	MDELAY(2);
	SET_RESET_PIN(1);
	MDELAY(2);	//20
	SET_RESET_PIN(0);
	MDELAY(2); //20
	SET_RESET_PIN(1);
	MDELAY(60); 	//100

	push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend(void)
{
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);

	MDELAY(120);

	SET_RESET_PIN(0);
	MDELAY(2);
	lcm_power_down();
	MDELAY(2);
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
/*
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
*/

	unsigned int id0,id1,id2;
	unsigned char buffer[5];
	unsigned int array[16];

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);

	array[0] = 0x00033700;// read id return two byte,version and id
	dsi_set_cmdq(array, 3, 1);
	read_reg_v2(0x04, buffer, 3);

	id0 = buffer[0]; //we only need ID
	id1 = buffer[1];
	id2 = buffer[2];

	#ifdef BUILD_LK
		printf("%s, LK 111111111111  id0=%d id1=%d id2=%d\n", __func__, id0,id1,id2);
	#else
		printk("%s, kernel 2222222222 id0=%d id1=%d id2=%d\n", __func__, id0,id1,id2);
	#endif
	if(id0 == 0x18)
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

LCM_DRIVER FL11281_lcm_drv = {
    .name		= "FL11281",
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
