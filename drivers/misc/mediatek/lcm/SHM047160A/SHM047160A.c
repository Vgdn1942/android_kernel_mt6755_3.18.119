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

static void init_lcm_registers(void)
{
	unsigned int data_array[16];
	data_array[0] = 0x00043902;
	data_array[1] = 0x9483ffb9;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00073902;
	data_array[1] = 0x680363ba;
	data_array[2] = 0x00c0b26b;
	dsi_set_cmdq(data_array, 3, 1);


	data_array[0] = 0x000b3902;
	data_array[1] = 0x6e0e50b1;
	data_array[2] = 0x71543309;
	data_array[3] = 0x00434e71;
	dsi_set_cmdq(data_array, 4, 1);


	data_array[0] = 0x00073902;
	data_array[1] = 0x648000b2;
	data_array[2] = 0x002f0705;
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00163902;
	data_array[1] = 0x017201b4;
	data_array[2] = 0x01720172;
	data_array[3] = 0x0075860c;
	data_array[4] = 0x0172013f;
	data_array[5] = 0x01720172;
	data_array[6] = 0x0000860c;
	dsi_set_cmdq(data_array, 07, 1);

	data_array[0] = 0x00223902;
	data_array[1] = 0x060000d3;
	data_array[2] = 0x10010106;
	data_array[3] = 0x00103200;
	data_array[4] = 0x15320000;
	data_array[5] = 0x32043504;
	data_array[6] = 0x14051415;
	data_array[7] = 0x00003337;
	data_array[8] = 0x37070037;
	data_array[9] = 0x00004005;
	dsi_set_cmdq(data_array, 10, 1);

	data_array[0] = 0x002d3902;
	data_array[1] = 0x181818d5;
	data_array[2] = 0x18181818;
	data_array[3] = 0x18181818;
	data_array[4] = 0x25181818;
	data_array[5] = 0x18262724;
	data_array[6] = 0x43464718;
	data_array[7] = 0x45404142;
	data_array[8] = 0x01040544;
	data_array[9] = 0x03060700;
	data_array[10] = 0x23202102;
	data_array[11] = 0x18181822;
	data_array[12] = 0x00000018;
	dsi_set_cmdq(data_array, 13, 1);

	data_array[0] = 0x002d3902;
	data_array[1] = 0x181818d6;
	data_array[2] = 0x18181818;
	data_array[3] = 0x18181818;
	data_array[4] = 0x22181818;
	data_array[5] = 0x18212023;
	data_array[6] = 0x04010018;
	data_array[7] = 0x02070605;
	data_array[8] = 0x06030203;
	data_array[9] = 0x04010007;
	data_array[10] = 0x24272605;
	data_array[11] = 0x18181825;
	data_array[12] = 0x00000018;
	dsi_set_cmdq(data_array, 13, 1);

	data_array[0] = 0x003b3902;
	data_array[1] = 0x1d0f00e0;
	data_array[2] = 0x3532282b;
	data_array[3] = 0x8b796e33;
	data_array[4] = 0x9f9e8d89;
	data_array[5] = 0xa0a8ac9d;
	data_array[6] = 0x5b64b7ac;
	data_array[7] = 0x6c63655d;
	data_array[8] = 0x0f007f71;
	data_array[9] = 0x26281d1d;
	data_array[10] = 0x6954292b;
	data_array[11] = 0x9c877b79;
	data_array[12] = 0xc0b8aba3;
	data_array[13] = 0x5ed7c6ba;
	data_array[14] = 0x67636361;
	data_array[15] = 0x007f716c;
	dsi_set_cmdq(data_array, 16, 1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x00000bcc;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00033902;
	data_array[1] = 0x00311fc0;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00033902;
	data_array[1] = 0x006565b6;//57,7A,43,60,65,6B,75,78,79,85,68,47//47,57,50,53,55,4a
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x000001bd;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x000000b1;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x000000bd;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x000002d4;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00083902;
	data_array[1] = 0x508140bf;
	data_array[2] = 0x01fc1a00;
	dsi_set_cmdq(data_array, 03, 1);


	data_array[0] = 0x00110500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);

	data_array[0] = 0x000d3902;
	data_array[1] = 0x648000b2;
	data_array[2] = 0x002f0705;
	data_array[3] = 0xc0000000;
	data_array[4] = 0x00000018;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0x00290500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(10);
}

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

		params->dsi.PLL_CLOCK = 220;
}

static void lcm_init(void)
{
	lcm_power_on();

	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(20);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(100);

	init_lcm_registers();
}



static void lcm_suspend(void)
{
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);

	lcm_power_down();
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

unsigned int id1 = 0;
	unsigned int id2 = 0;
	unsigned int id3 = 0;

	LCM_LOGI("[Jason]lcm_compare_id\n");
#if defined(BUILD_LK)
	LCM_LOGI("[Jason]lk read id\n");
	id1 = mt_get_gpio_in(GPIO_LCD_ID1_PIN);
	id2 = mt_get_gpio_in(GPIO_LCD_ID2_PIN);
	id3 = mt_get_gpio_in(GPIO_LCD_ID3_PIN);

	printf("[Jason]SHM047160A 0x%x\n",id1);
	printf("[Jason]SHM047160A 0x%x\n",id2);
	printf("[Jason]SHM047160A 0x%x\n",id3);
#else
	LCM_LOGI("ili9881c 0x%x\n",id1);
#endif

	if((id1 == 0) && (id2 == 0) && (id3 == 0))
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

LCM_DRIVER SHM047160A_lcm_drv = {
    .name		= "SHM047160A",
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
