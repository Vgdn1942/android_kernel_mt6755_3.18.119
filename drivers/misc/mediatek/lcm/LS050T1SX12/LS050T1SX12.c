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


#define GPIO_LCM_BIA_EN 	89

#define FRAME_WIDTH  (1080)
#define FRAME_HEIGHT (1920)


#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif

//static unsigned int lcm_esd_test = FALSE;      ///only for ESD test

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

#define REGFLAG_DELAY             							0XFE
#define REGFLAG_END_OF_TABLE      							0x100   // END OF REGISTERS MARKER

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	        lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)   

#define   LCM_DSI_CMD_MODE							0

struct LCM_setting_table {
    unsigned cmd;
    unsigned char count;
    unsigned char para_list[64];
};

static struct LCM_setting_table lcm_initialization_setting[] = {

/*
{0xFF,1,{0x20}},
{0xFB,1,{0x01}},
{0xFF,1,{0x21}},
{0xFB,1,{0x01}},
{0xFF,1,{0x23}},
{0xFB,1,{0x01}},
{0xFF,1,{0x24}},
{0xFB,1,{0x01}},

{0xFF,1,{0x20}},

{0x00,1,{0x01}},
{0x01,1,{0x55}},
{0x02,1,{0x55}},
{0x03,1,{0x55}},
{0x05,1,{0x50}},
{0x06,1,{0x9D}},
{0x07,1,{0x93}},
{0x08,1,{0x0D}},
{0x0B,1,{0x9B}},
{0x0C,1,{0x9B}},
{0x0E,1,{0xAF}},
{0x0F,1,{0x9A}},
{0x11,1,{0x11}},
{0x12,1,{0x11}},
{0x13,1,{0x03}},

{0x30,1,{0x67}},

{0x58,1,{0x85}},
{0x59,1,{0x00}},
{0x5A,1,{0x05}},
{0x5B,1,{0x00}},
{0x5C,1,{0x85}},
{0x5D,1,{0x00}},
{0x5E,1,{0x05}},
{0x5F,1,{0x00}},
{0x69,1,{0x99}},
{0x6D,1,{0x33}},

{0xFF,1,{0x10}},

{0xFF,1,{0x24}},

{0x01,1,{0x03}},
{0x02,1,{0x05}},
{0x05,1,{0x0B}},
{0x06,1,{0x0C}},
{0x07,1,{0x01}},
{0x08,1,{0x0F}},
{0x09,1,{0x8F}},
{0x0D,1,{0x17}},
{0x0E,1,{0x15}},
{0x0F,1,{0x13}},
{0x11,1,{0x04}},
{0x12,1,{0x06}},
{0x15,1,{0x0B}},
{0x16,1,{0x0C}},
{0x17,1,{0x01}},
{0x18,1,{0x0F}},
{0x19,1,{0x8F}},
{0x1D,1,{0x17}},
{0x1E,1,{0x15}},
{0x1F,1,{0x13}},

{0x20,1,{0x05}},
{0x21,1,{0x00}},
{0x22,1,{0x00}},
{0x23,1,{0x00}},
{0x24,1,{0x71}},
{0x25,1,{0x6D}},
{0x26,1,{0x00}},
{0x27,1,{0x71}},

{0x29,1,{0xD0}},
{0x2A,1,{0x2B}},

{0x2F,1,{0x02}},
{0x30,1,{0x02}},
{0x31,1,{0x00}},
{0x32,1,{0x6A}},
{0x33,1,{0x00}},
{0x34,1,{0x06}},
{0x35,1,{0x6B}},
{0x36,1,{0x00}},
{0x37,1,{0x2D}},
{0x38,1,{0x08}},
{0x39,1,{0x06}},
{0x3A,1,{0x6B}},

{0x5b,1,{0xC4}},
{0x5c,1,{0x00}},
{0x5F,1,{0x74}},
{0x60,1,{0x74}},
{0x63,1,{0xB0}},
{0x72,1,{0x00}},

{0x74,1,{0x08}},
{0x75,1,{0x1E}},
{0x76,1,{0x04}},
{0x77,1,{0x00}},
{0x78,1,{0x0C}},
{0x79,1,{0x00}},
{0x7A,1,{0x80}},
{0x7B,1,{0xa2}},
{0x7C,1,{0xD8}},
{0x7D,1,{0x60}},
{0x7E,1,{0x08}},
{0x7F,1,{0x1E}},
{0x80,1,{0x0C}},
{0x81,1,{0x04}},
{0x82,1,{0x00}},
{0x83,1,{0x00}},
{0x84,1,{0x04}},
{0x85,1,{0x04}},
{0x86,1,{0x1B}},
{0x87,1,{0x1B}},
{0x88,1,{0x1B}},
{0x89,1,{0x1B}},
{0x8A,1,{0x33}},
{0x8B,1,{0xF0}},
{0x90,1,{0x78}},
{0x91,1,{0x44}},
{0x92,1,{0x78}},
{0x93,1,{0x04}},
{0x94,1,{0x06}},

{0x98,1,{0x00}},
{0x99,1,{0x00}},
{0x9B,1,{0x0F}},
{0x9C,1,{0x00}},
{0x9D,1,{0xB0}},
{0xA0,1,{0x00}},

{0xB3,1,{0x2A}},
{0xB4,1,{0x2A}},
{0xB5,1,{0x05}},
{0xBA,1,{0xA2}},

{0xC4,1,{0x60}},
{0xC5,1,{0x30}},
{0xC6,1,{0x09}},

{0xE3,1,{0x02}},

{0xFF,1,{0x23}},

{0x08,1,{0x09}},
{0x46,1,{0x85}},

{0xFF,1,{0x10}},
//{0xBB,1,{0x10}},
{0xBB,1,{0x03}},
*/

/* bist mode
{0xFF,1,{0x24}},
{0xEA,1,{0xFF}},
{0xEC,1,{0x01}},
*/

//	测试架点亮代码

  	{0xFF,1,{0x10}},
	{0xBB,1,{0x13}},

    {0xB0,1,{0x03}},
    {0x3B,5,{0x03,0x06,0x04,0x3c,0x66}},
  	{0xFF,1,{0x10}},
  	{0x35,1,{0x00}},
  	{0x51,1,{0xFF}},
  	{0x53,1,{0x24}},  	
  	{0xFF,1,{0xF0}}, 
  	{0x92,1,{0x01}},
  	{0x13,1,{0x01}},
  	{0xFF,1,{0x10}}, 
  	   	  	 	
  {0x11,1,{0x00}},
  {REGFLAG_DELAY, 120, {}},
  {0x29,0,{0x00}},
  {REGFLAG_DELAY, 50, {}},

  {REGFLAG_END_OF_TABLE, 0x00, {}}

};


static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {	
	
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 20, {}},
	
    // Sleep Mode On
	{0x10, 0, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	
	{0xFF,1,{0x10}},
	{0x4F,1,{0x01}},	// deep sleep
	{REGFLAG_DELAY, 30, {}},
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
				//MDELAY(2);
       	}
    }
	
}


// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

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

	params->dsi.mode = BURST_VDO_MODE;	//CMD_MODE
//	params->dsi.mode = SYNC_PULSE_VDO_MODE;
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

	params->physical_width = 62;
	params->physical_height = 110;

	params->dsi.vertical_sync_active = 2;//
	params->dsi.vertical_backporch = 6;//6
	params->dsi.vertical_frontporch = 4;//4
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 10;//20
	params->dsi.horizontal_backporch = 60;//60
	params->dsi.horizontal_frontporch = 102;//102
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.PLL_CLOCK = 430;//430//450

}

//extern int lcm_i2c_set_vol_value(int vop, int von);

static void lcm_init(void)
{
	LCM_LOGI("Jason in %s line: %d \n", __func__, __LINE__);
	agold_lcm_power_on();

#if defined(BUILD_LK)
	mt_set_gpio_mode(GPIO_LCD_ID1_PIN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCD_ID1_PIN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCD_ID1_PIN, GPIO_OUT_ONE);
#else
	gpio_set_value(GPIO_LCM_BIA_EN, 1);
#endif

	MDELAY(10);	
	
//	lcm_i2c_set_vol_value(5000, 5000);
//	MDELAY(5000);		
//	lcm_i2c_set_vol_value(5000, 5000);
	MDELAY(20);
//	while(1);
	
	MDELAY(60);
	SET_RESET_PIN(1);
	MDELAY(10); 
	SET_RESET_PIN(0);
	MDELAY(20);
	
	SET_RESET_PIN(1);
	MDELAY(120);      

	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}



static void lcm_suspend(void)
{
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	MDELAY(60);
//	SET_RESET_PIN(1);
//	MDELAY(20); 
	SET_RESET_PIN(0);
	MDELAY(20); 
	
//	SET_RESET_PIN(1);
//	MDELAY(120);   

#if defined(BUILD_LK)
	mt_set_gpio_mode(GPIO_LCD_ID1_PIN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCD_ID1_PIN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCD_ID1_PIN, GPIO_OUT_ZERO);
#else
	gpio_set_value(GPIO_LCM_BIA_EN, 0);
#endif
	MDELAY(10);
	agold_lcm_power_down();  
}


static void lcm_resume(void)
{
	//lcm_initialization_setting[18].para_list[0]+=0x01;
	
   // LCM_DEBUG("VCOM is :%d",lcm_initialization_setting[18].para_list[0]);
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
//	unsigned int id3 = 0;
    unsigned char buffer[4];
    unsigned int data_array[16];
     
    SET_RESET_PIN(1);    //NOTE:should reset LCM firstly
    MDELAY(10);
    SET_RESET_PIN(0);
    MDELAY(20);
    SET_RESET_PIN(1);
    MDELAY(100);

    data_array[0] = 0x00023700;
    dsi_set_cmdq(data_array, 1, 1);
    MDELAY(10);

    read_reg_v2(0xF4, buffer, 1);
    id1= buffer[0]; 
    
    data_array[0] = 0x10FF1500;
    dsi_set_cmdq(data_array, 1, 1);
    
    read_reg_v2(0xBB, buffer, 1);
    id2= buffer[0]; 

/*
	read_reg_v2(0xDA, buffer, 1);
	read_reg_v2(0xDB, buffer+1, 1);
	read_reg_v2(0xDC, buffer+2, 1);
	id1= buffer[0]; 
    id2= buffer[1]; 
    id3= buffer[2];
*/
#if defined(BUILD_LK)
    printf("LS050T1SX12 id1=0x%2x , id2 = 0x%x\n", id1, id2);
#else
    printk("LS050T1SX12 id1=0x%2x , id2 = 0x%x\n", id1, id2);
#endif


   return 0;

}

LCM_DRIVER LS050T1SX12_lcm_drv = 
{
    .name			= "LS050T1SX12",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
    };

