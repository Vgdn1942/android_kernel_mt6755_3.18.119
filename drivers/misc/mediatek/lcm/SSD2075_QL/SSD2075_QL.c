#define LOG_TAG "LCM"

#ifndef BUILD_LK
#include <linux/string.h>
#include <linux/kernel.h>
#endif

#include "lcm_drv.h"

#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
#include "lcm_common.h"
#include "lcm_i2c.h"
#endif

#ifdef BUILD_LK
#include <platform/upmu_common.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
/*#include <mach/mt_pm_ldo.h>*/
#ifdef CONFIG_MTK_LEGACY
#include <mach/mt_gpio.h>
#endif
#endif
#ifdef CONFIG_MTK_LEGACY
#include <cust_gpio_usage.h>
#endif
#ifndef CONFIG_FPGA_EARLY_PORTING
#if defined(CONFIG_MTK_LEGACY)
#include <cust_i2c.h>
#endif
#endif

#ifdef BUILD_LK
#define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
#define LCM_LOGI(fmt, args...)  printk("[MaJian]"fmt, ##args)   //pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

static const unsigned int BL_MIN_LEVEL = 20;
static LCM_UTIL_FUNCS lcm_util;
extern int agold_lcm_power_on(void);
extern int agold_lcm_power_down(void);
#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
extern int lcm_i2c_set_vol_value(int vop_value, int von_value);
extern int lcm_i2c_bias_en(int enable);
#endif
extern int lcm_id_index(int b);

#define SET_RESET_PIN(v)	(lcm_util.set_reset_pin((v)))
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

/* static unsigned char lcd_id_pins_value = 0xFF; */
static const unsigned char LCD_MODULE_ID = 0x01;
#define FRAME_WIDTH				(720)
#define FRAME_HEIGHT			(1280)


#define LCM_ID_SSD2075 (0x2075)

#define REGFLAG_DELAY			0xFFFC
#define REGFLAG_UDELAY			0xFFFB
#define REGFLAG_END_OF_TABLE	0xFFFD
#define REGFLAG_RESET_LOW		0xFFFE
#define REGFLAG_RESET_HIGH		0xFFFF



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


static void init_lcm_registers(void)
{
	unsigned int data_array[16];

    data_array[0] = 0x00023902;                          
	data_array[1] = 0x0000A3E1;                 
	dsi_set_cmdq(data_array, 2, 1);
	//MDELAY(1);

	data_array[0] = 0x00023902;                          
	data_array[1] = 0x000000B3;                 
	dsi_set_cmdq(data_array, 2, 1);
	//MDELAY(1);


	data_array[0] = 0x00053902;                          
	data_array[1] = 0x000F16B6; 
	data_array[2] = 0x00000077; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00093902;                          
	data_array[1] = 0x0B0A00B8; //0x0B0A00B8;
	data_array[2] = 0x110D0B00; //0x110D0B00;
	data_array[3] = 0x00000004; 
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);

	data_array[0] = 0x00073902;                          
	data_array[1] = 0x110804B9; // 0x110804B9;
	data_array[2] = 0x000FFFFF;  //0x00FFFFFF  0x000FFFFF;
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00093902;                          
	data_array[1] = 0x100E0EBA; 
	data_array[2] = 0x14121210;  //0x14121210;
	data_array[3] = 0x00000014;  //0x00000014;
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);

	data_array[0] = 0x00093902;                          
	data_array[1] = 0xA1A1A1BB; 
	data_array[2] = 0xA0A0A0A1; 
	data_array[3] = 0x000000A0; 
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);


	data_array[0] = 0x00093902;                          
	data_array[1] = 0x000000BC; 
	data_array[2] = 0x00000000; 
	data_array[3] = 0x00000000; 
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);

	data_array[0] = 0x00093902;                          
	data_array[1] = 0x110F0FBD; 
	data_array[2] = 0x15131311; 
	data_array[3] = 0x00000015; 
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);


	data_array[0] = 0x00093902;                          
	data_array[1] = 0xA1A1A1BE; 
	data_array[2] = 0xA0A0A0A1; 
	data_array[3] = 0x000000A0; 
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);


	data_array[0] = 0x00093902;                          
	data_array[1] = 0x000000BF; 
	data_array[2] = 0x00000000; 
	data_array[3] = 0x00000000; 
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);


	data_array[0] = 0x00043902;                          
	data_array[1] = 0x121E16B1;  //modified  14+3             
	dsi_set_cmdq(data_array, 2, 1); 
	//MDELAY(1);


	data_array[0] = 0x00063902;                          
	data_array[1] = 0x020301E0; //VSA
	data_array[2] = 0x00000100; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

/*
	data_array[0] = 0x00073902;                          
	data_array[1] = 0x1E0000D0; 
	data_array[2] = 0x00352D27; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);


	data_array[0] = 0x00063902;                          
	data_array[1] = 0x1A272DD1; 
	data_array[2] = 0x00000A1B; 
	dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);


	data_array[0] = 0x00073902;                          
	data_array[1] = 0x1E0000D2; 
	data_array[2] = 0x00352D27; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);


	data_array[0] = 0x00063902;                          
	data_array[1] = 0x1A272DD3; 
	data_array[2] = 0x00000A1B; 
	dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);


	data_array[0] = 0x00073902;                          
	data_array[1] = 0x1E0000D4; 
	data_array[2] = 0x00352D27; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);


	data_array[0] = 0x00063902;                          
	data_array[1] = 0x1A272DD5; 
	data_array[2] = 0x00000A1B; 
	dsi_set_cmdq(data_array, 3, 1);  
	//MDELAY(1);

	data_array[0] = 0x00073902;                          
	data_array[1] = 0x1E0000D6; 
	data_array[2] = 0x00352D27; 
	dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	data_array[0] = 0x00063902;                          
	data_array[1] = 0x1A272DD7; 
	data_array[2] = 0x00000A1B; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00073902;                          
	data_array[1] = 0x1E0000D8; 
	data_array[2] = 0x00352D27; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00063902;                          
	data_array[1] = 0x1A272DD9; 
	data_array[2] = 0x00000A1B; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00073902;                          
	data_array[1] = 0x1E0000DA; 
	data_array[2] = 0x00352D27;  
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00063902;                          
	data_array[1] = 0x1A272DDB; 
	data_array[2] = 0x00000A1B; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
*/
#if 0   //default
data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D0; 
	data_array[2] = 0x00160A05; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
	data_array[0] = 0x00063902;                          
    data_array[1] = 0x333F10D1; 
	data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	
	data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D2; 
	data_array[2] = 0x00160A05; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
	data_array[0] = 0x00063902;                          
    data_array[1] = 0x333F10D3; 
	data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	
	data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D4; 
	data_array[2] = 0x00160A05; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
	data_array[0] = 0x00063902;                          
    data_array[1] = 0x333F10D5; 
	data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1);  
	//MDELAY(1);

	data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D6; 
	data_array[2] = 0x00160A05; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	data_array[0] = 0x00063902;                          
    data_array[1] = 0x333F10D7; 
	data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D8; 
	data_array[2] = 0x00160A05; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00063902;                          
    data_array[1] = 0x333F10D9; 
	data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000DA; 
	data_array[2] = 0x00160A05;  
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
 
	data_array[0] = 0x00063902;                          
    data_array[1] = 0x333F10DB; 
	data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
#elif 0  //gama1.9
    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D0; 
    data_array[2] = 0x00120603; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0BD1; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	
    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D2; 
    data_array[2] = 0x00120603; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0BD3; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D4; 
    data_array[2] = 0x00120603; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0BD5; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1);  
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D6; 
    data_array[2] = 0x00120603; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0BD7; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D8; 
    data_array[2] = 0x00120603; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0BD9; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000DA; 
    data_array[2] = 0x00120603; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
 
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0BDB; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
#elif 0   //gama 2.0
    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D0; 
    data_array[2] = 0x00120803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0CD1; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	
    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D2; 
    data_array[2] = 0x00120803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0CD3; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D4; 
    data_array[2] = 0x00120803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0CD5; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1);  
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D6; 
    data_array[2] = 0x00120803; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0CD7; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D8; 
    data_array[2] = 0x00120803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0CD9; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000DA; 
    data_array[2] = 0x00120803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
 
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0CDB; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
#elif 1
    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D0; 
    data_array[2] = 0x00130803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0DD1; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	
    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D2; 
    data_array[2] = 0x00130803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0DD3; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D4; 
    data_array[2] = 0x00130803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0DD5; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1);  
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D6; 
    data_array[2] = 0x00130803; 
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0DD7; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000D8; 
    data_array[2] = 0x00130803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0DD9; 
    data_array[2] = 0x00000523;
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

    data_array[0] = 0x00073902;                          
    data_array[1] = 0x050000DA; 
    data_array[2] = 0x00130803; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);
 
    data_array[0] = 0x00063902;                          
    data_array[1] = 0x353F0DDB; 
    data_array[2] = 0x00000523; 
    dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);	
	data_array[0] = 0x00053902;                          
	data_array[1] = 0xFF00D870; 
	data_array[2] = 0x00000080; 
	dsi_set_cmdq(data_array, 3, 1); 
	//MDELAY(1);

	data_array[0] = 0x00023902;                          
	data_array[1] = 0x000001FF;                 
	dsi_set_cmdq(data_array, 2, 1); 
	MDELAY(1);

	// add cmd-c6 
	data_array[0] = 0x00033902; 						 
	data_array[1] = 0x003388C6; 				
	dsi_set_cmdq(data_array, 2, 1); 
	MDELAY(1);
	//add end

	//legen modify 
	data_array[0] = 0x00033902;                          
	data_array[1] = 0x00309DDE; //00309DDE
	//data_array[2] = 0x00130D0C; 
	dsi_set_cmdq(data_array, 2, 1);


	data_array[0] = 0x00023902;                          
	data_array[1] = 0x00000014; 
	//data_array[2] = 0x00130D0C; 
	dsi_set_cmdq(data_array, 2, 1);
	//legen modify end


	data_array[0] = 0x00023902;                          
	data_array[1] = 0x000007E9;                 
	dsi_set_cmdq(data_array, 2, 1); 
	MDELAY(1);

	data_array[0] = 0x00033902;                          
	data_array[1] = 0x001060ED;                 
	dsi_set_cmdq(data_array, 2, 1); 
	//MDELAY(1);

	data_array[0] = 0x00023902;                          
	data_array[1] = 0x000012EC;                 
	dsi_set_cmdq(data_array, 2, 1); 
	//MDELAY(1);

	data_array[0] = 0x00053902;                          
	data_array[1] = 0x347B77CD; 
	data_array[2] = 0x00000008; 
	dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	data_array[0] = 0x00083902;                          
	data_array[1] = 0x340D03C3;     //0x340503C3  0x340D03C3
	data_array[2] = 0x54440105; 
	dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

#if 0
	data_array[0] = 0x00063902; 
	data_array[1] = 0x360302C4;  //0x701303c4 //0x700302C4  //0x3d0302C4
	data_array[2] = 0x00004b3d;  //0x00005C70   4b  47   4a彩色OK  45
    dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);
#elif 0
	data_array[0] = 0x00063902; 
	data_array[1] = 0x3D0302C4;  //0x701303c4 //0x700302C4  //0x3d0302C4
	data_array[2] = 0x00005A3D;  //0x00005C70   4b  47   4a彩色OK  45
    dsi_set_cmdq(data_array, 3, 1);
#else
	data_array[0] = 0x00063902; 
	data_array[1] = 0x350302C4;  //0x701303c4 //0x700302C4  //0x3d0302C4
	data_array[2] = 0x0000483d;  //0x00005C70   4b  47   4a彩色OK  45 49 47 48
    dsi_set_cmdq(data_array, 3, 1);
#endif

	data_array[0] = 0x00043902;                          
	data_array[1] = 0x0080DFCB;   //0x0080DACB     //line<20130109>wangyanhui           
	dsi_set_cmdq(data_array, 2, 1); 
	//MDELAY(1);

	data_array[0] = 0x00033902;                          
	data_array[1] = 0x002815EA;                 
	dsi_set_cmdq(data_array, 2, 1); 
	//MDELAY(1);

	data_array[0] = 0x00053902;                          
	data_array[1] = 0x000038F0; 
	data_array[2] = 0x00000000; 
	dsi_set_cmdq(data_array, 3, 1);
	//MDELAY(1);

	data_array[0] = 0x00043902;                          
	data_array[1] = 0x820060C9;                 
	dsi_set_cmdq(data_array, 2, 1);
	//MDELAY(1);

	data_array[0] = 0x00093902;                          
	data_array[1] = 0x050500B5;
	data_array[2] = 0x2040041E;                          
	data_array[3] = 0x000000FC;                 
	dsi_set_cmdq(data_array, 4, 1);
	//MDELAY(1);

	data_array[0] = 0x00023902;                          
	data_array[1] = 0x00000236;                 
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(1);//wait for PLL to lock 

	//1 Do not delete 0x11, 0x29 here
	data_array[0] = 0x00110500; // Sleep Out
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);

	data_array[0] = 0x00290500; // Display On
	dsi_set_cmdq(data_array, 1, 1);
	
	
	data_array[0] = 0x00053902;                          
	data_array[1] = 0xFFFF18F0;  
	data_array[2] = 0x00000000;  	
	dsi_set_cmdq(data_array, 3, 1);
	
#endif
}

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

static struct LCM_setting_table lcm_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 20, {}},

    // Sleep Mode On
	{0x10, 0, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


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

	/* Highly depends on LCD driver capability. */
	params->dsi.packet_size = 256;
	/* video mode timing */

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->physical_width	= 58;
	params->physical_height	= 104;

	params->dsi.vertical_sync_active 					= 3;	
	params->dsi.vertical_backporch					    = 12;		//4		
	params->dsi.vertical_frontporch					    = 8;	//20	
	params->dsi.vertical_active_line    				= FRAME_HEIGHT;

	params->dsi.horizontal_sync_active 					= 4;	//2	
	params->dsi.horizontal_backporch 					= 100;		//118		
	params->dsi.horizontal_frontporch 					= 100;	//118
	params->dsi.horizontal_active_pixel 				= FRAME_WIDTH;
	/* params->dsi.ssc_disable = 1; */
	params->dsi.PLL_CLOCK = 235;
	
	params->dsi.HS_PRPR									=3;//4//
	params->dsi.CLK_HS_POST 							= 22;
	params->dsi.DA_HS_EXIT 								=35;
	params->dsi.LPX=13;
	
}

static void lcm_init(void)
{	
	LCM_LOGI("lcm_init enter\n");

	agold_lcm_power_on();
	MDELAY(25);
	
	SET_RESET_PIN(1);
	MDELAY(5);    //>1ms
	SET_RESET_PIN(0);
	MDELAY(40);  // >30ms
	SET_RESET_PIN(1);
	MDELAY(120);    // >60ms
	
	
//	push_table(init_setting, sizeof(init_setting) / sizeof(struct LCM_setting_table), 1);
	init_lcm_registers();
}

static void lcm_resume(void)
{
	//LCM_LOGI("lcm_resume enter\n");
	lcm_init();
}

static void lcm_suspend(void)
{
	LCM_LOGI("lcm_suspend enter\n");
	push_table(lcm_sleep_mode_in_setting, sizeof(lcm_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
	agold_lcm_power_down();	
}

static unsigned int lcm_compare_id(void)
{
    unsigned int id0,id1,id;
	unsigned char buffer[10];
	unsigned int array[16];  

	SET_RESET_PIN(1);
   	MDELAY(2);   // > 1ms
	SET_RESET_PIN(0);
	MDELAY(40); // >30ms
	SET_RESET_PIN(1);
	MDELAY(120);  // >60ma     

	array[0] = 0x00023700;// return byte number
	dsi_set_cmdq(array, 1, 1);
	//MDELAY(10);

	read_reg_v2(0xA1, buffer, 2);
	id0 = buffer[0]; 
	id1 = buffer[1];
	id=(id0<<8)|id1;
	
#ifdef BUILD_LK
	printf("[Jason]LK ssd2075 id0 = 0x%02x,id1 = 0x%02x,id = 0x%04x\n", id0,id1,id);
//	printf("[Jason] buf[10] = 0x%020x\n", buffer);//buffer = 0x00000000000046076274 0x0000000000004607626c
#endif

	return (id == LCM_ID_SSD2075)?1:0;
}

LCM_DRIVER SSD2075_QL_lcm_drv = {
	.name = "SSD2075_QL",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id	= lcm_compare_id,

};
