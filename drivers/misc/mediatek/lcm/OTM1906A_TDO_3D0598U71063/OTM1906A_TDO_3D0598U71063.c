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
extern int lcm_id_index(int b);
#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
extern int lcm_i2c_set_vol_value(int vop_value, int von_value);
extern int lcm_i2c_bias_en(int enable);
#endif
static unsigned int lcm_compare_id(void);

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
#define FRAME_WIDTH				(1080)
#define FRAME_HEIGHT			(1920)


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
	int data_array[20];

	data_array[0] = 0x00002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00042902;
	data_array[1] = 0x010619ff;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00032902;
	data_array[1] = 0x000619ff;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00082902;
	data_array[1] = 0x000000a4;
	data_array[2] = 0x00820002;
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00052902;
	data_array[1] = 0x01000fa5;
	data_array[2] = 0x00000008;
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000f2902;
	data_array[1] = 0x008000c0;
	data_array[2] = 0x80000604;
	data_array[3] = 0x80000604;
	data_array[4] = 0x00060400;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xa0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00082902;
	data_array[1] = 0x000500c0;
	data_array[2] = 0x041b0205;
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0xd0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00082902;
	data_array[1] = 0x000500c0;
	data_array[2] = 0x041b0205;
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00032902;
	data_array[1] = 0x001111c1;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x400184c2;
	data_array[2] = 0x17018240;
	data_array[3] = 0x00000018;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0x90002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x000000c2;
	data_array[2] = 0x08010200;
	data_array[3] = 0x0801020f;
	data_array[4] = 0x0000000f;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xb0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x000184c2;
	data_array[2] = 0x03820008;
	data_array[3] = 0x83000800;
	data_array[4] = 0x00080002;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xc0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x000481c2;
	data_array[2] = 0x00000008;
	data_array[3] = 0x00000000;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xd0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x010082c2;
	data_array[2] = 0x02848102;
	data_array[3] = 0x33010003;
	data_array[4] = 0x00370033;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xa0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x400184c3;
	data_array[2] = 0x17018240;
	data_array[3] = 0x00000018;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xb0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000f2902;
	data_array[1] = 0x000000c3;
	data_array[2] = 0x00018400;
	data_array[3] = 0x03820008;
	data_array[4] = 0x00000800;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xc0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x000283c3;
	data_array[2] = 0x04810008;
	data_array[3] = 0x00000800;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xe0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00052902;
	data_array[1] = 0x003333c3;
	data_array[2] = 0x00000037;
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000c2902;
	data_array[1] = 0x000000cb;
	data_array[2] = 0x00003000;
	data_array[3] = 0x00000000;
	dsi_set_cmdq(data_array, 4, 1);

	data_array[0] = 0x90002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x000000cb;
	data_array[2] = 0x000000c0;
	data_array[3] = 0x00000000;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xa0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x000000cb;
	data_array[2] = 0x000000bf;
	data_array[3] = 0x00ff0000;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xb0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x000000cb;
	data_array[2] = 0x00000000;
	data_array[3] = 0x00777700;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xc0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x151115cb;
	data_array[2] = 0x15151515;
	data_array[3] = 0x01010115;
	data_array[4] = 0x01010101;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xd0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x013d01cb;
	data_array[2] = 0x000101ff;
	data_array[3] = 0x00000000;
	data_array[4] = 0x11011101;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xe0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x001101cb;
	data_array[2] = 0x00010001;
	data_array[3] = 0x00777701;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xf0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000c2902;
	data_array[1] = 0x55fff3cb;
	data_array[2] = 0x03c07f55;
	data_array[3] = 0x02000333;
	dsi_set_cmdq(data_array, 4, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x180908cc;
	data_array[2] = 0x0e0d0c19;
	data_array[3] = 0x0707070f;
	data_array[4] = 0x00000007;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0x90002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x080918cc;
	data_array[2] = 0x0d0e0f19;
	data_array[3] = 0x0707070c;
	data_array[4] = 0x00000007;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xa0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x161514cc;
	data_array[2] = 0x1e1d1c17;
	data_array[3] = 0x0707201f;
	data_array[4] = 0x00070707;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xb0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00092902;
	data_array[1] = 0x030201cc;
	data_array[2] = 0x07060504;
	data_array[3] = 0x00000007;
	dsi_set_cmdq(data_array, 4, 1);

	data_array[0] = 0xc0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x000000cc;
	data_array[2] = 0x00000000;
	data_array[3] = 0x00000000;
	data_array[4] = 0x00454500;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xd0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x000000cc;
	data_array[2] = 0x00000000;
	data_array[3] = 0x00000000;
	data_array[4] = 0x33333333;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xe0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x000d2902;
	data_array[1] = 0x003333cc;
	data_array[2] = 0x00000000;
	data_array[3] = 0x00000000;
	data_array[4] = 0x00000000;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x121101cd;
	data_array[2] = 0x18040807;
	data_array[3] = 0x2309031a;
	data_array[4] = 0x1e1d2323;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0x90002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00042902;
	data_array[1] = 0x23231fcd;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0xa0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00102902;
	data_array[1] = 0x121101cd;
	data_array[2] = 0x18040605;
	data_array[3] = 0x23090317;
	data_array[4] = 0x1e1d2323;
	dsi_set_cmdq(data_array, 5, 1);

	data_array[0] = 0xb0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00042902;
	data_array[1] = 0x23231fcd;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x91002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00032902;
	data_array[1] = 0x001e14c5;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0xa1002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00032902;
	data_array[1] = 0x001e14c5;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00002300;
	dsi_set_cmdq(data_array, 1, 1);
/*
	data_array[0] = 0x00092902;
	data_array[1] = 0x009000d9;
	data_array[2] = 0x00900090;
	data_array[3] = 0x00000090;
	dsi_set_cmdq(data_array, 4, 1);
*/
	data_array[0] = 0x00002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00032902;
	data_array[1] = 0x001b1bd8;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00002300;
	dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x00001500;
dsi_set_cmdq(data_array, 1, 1);

data_array[0] = 0x00193902;
data_array[1] = 0x312401E1;
data_array[2] = 0x564A443C;
data_array[3] = 0x8A817368;
data_array[4] = 0x60656991;
data_array[5] = 0x2C374455;
data_array[6] = 0x10151F26;
data_array[7] = 0x0000000F;
dsi_set_cmdq(data_array, 8, 1);

data_array[0] = 0x00001500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00193902;
data_array[1] = 0x312401E2;
data_array[2] = 0x564A443C;
data_array[3] = 0x8A817368;
data_array[4] = 0x60656991;
data_array[5] = 0x2C374455;
data_array[6] = 0x10151F26;
data_array[7] = 0x0000000F;
dsi_set_cmdq(data_array, 8, 1);

data_array[0] = 0x00001500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00193902;
data_array[1] = 0x312401E3;
data_array[2] = 0x564A443C;
data_array[3] = 0x8A817368;
data_array[4] = 0x60656991;
data_array[5] = 0x2C374455;
data_array[6] = 0x10151F26;
data_array[7] = 0x0000000F;
dsi_set_cmdq(data_array, 8, 1);

data_array[0] = 0x00001500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00193902;
data_array[1] = 0x312401E4;
data_array[2] = 0x564A443C;
data_array[3] = 0x8A817368;
data_array[4] = 0x60656991;
data_array[5] = 0x2C374455;
data_array[6] = 0x10151F26;
data_array[7] = 0x0000000F;
dsi_set_cmdq(data_array, 8, 1);

data_array[0] = 0x00001500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00193902;
data_array[1] = 0x312401E5;
data_array[2] = 0x564A443C;
data_array[3] = 0x8A817368;
data_array[4] = 0x60656991;
data_array[5] = 0x2C374455;
data_array[6] = 0x10151F26;
data_array[7] = 0x0000000F;
dsi_set_cmdq(data_array, 8, 1);

data_array[0] = 0x00001500;
dsi_set_cmdq(data_array, 1, 1);
data_array[0] = 0x00193902;
data_array[1] = 0x312401E6;
data_array[2] = 0x564A443C;
data_array[3] = 0x8A817368;
data_array[4] = 0x60656991;
data_array[5] = 0x2C374455;
data_array[6] = 0x10151F26;
data_array[7] = 0x0000000F;
dsi_set_cmdq(data_array, 8, 1);

	data_array[0] = 0xb3002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x88c02300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0xa0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00082902;
	data_array[1] = 0x380433b3;
	data_array[2] = 0x20008007;
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0xe1002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x16f52300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x81002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x16f52300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x83002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x16f52300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x80002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x81c42300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x81002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x01a52300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0xa0002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00042902;
	data_array[1] = 0x11c000c1;
	dsi_set_cmdq(data_array, 2, 1);

	data_array[0] = 0x00002300;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00042902;
	data_array[1] = 0x000000ff;
	dsi_set_cmdq(data_array, 2, 1);

//CE
/*
data_array[0] = 0x00022902;
data_array[1] = 0x0000a000;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x000d2902;
data_array[1] = 0x000000d6;
data_array[2] = 0x00000000;
data_array[3] = 0x00000000;
data_array[4] = 0x00000000;
dsi_set_cmdq(data_array, 5, 1);

data_array[0] = 0x00022902;
data_array[1] = 0x0000b000;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x000d2902;
data_array[1] = 0x000000d6;
data_array[2] = 0x00000000;
data_array[3] = 0x4d000000;
data_array[4] = 0x00000080;
dsi_set_cmdq(data_array, 5, 1);

data_array[0] = 0x00022902;
data_array[1] = 0x0000c000;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x000d2902;
data_array[1] = 0x00002bd6;
data_array[2] = 0x00000000;
data_array[3] = 0x33000000;
data_array[4] = 0x00000055;
dsi_set_cmdq(data_array, 5, 1);

data_array[0] = 0x00022902;
data_array[1] = 0x0000d000;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x000d2902;
data_array[1] = 0x001a2bd6;
data_array[2] = 0x00000000;
data_array[3] = 0x1a000000;
data_array[4] = 0x0000002b;
dsi_set_cmdq(data_array, 5, 1);

data_array[0] = 0x00022902;
data_array[1] = 0x00000000;
dsi_set_cmdq(data_array, 2, 1);

data_array[0] = 0x00022902;
data_array[1] = 0x00008381;//可对83进行更改，00关，80弱，81中，83强
dsi_set_cmdq(data_array, 2, 1);
*/

	data_array[0] = 0x00110500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(120);

	data_array[0] = 0x00290500;
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(20);
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

	params->dsi.mode = SYNC_PULSE_VDO_MODE;//SYNC_EVENT_VDO_MODE;//BURST_VDO_MODEBURST_VDO_MODE//CMD_MODE
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
	//params->dbi.io_driving_current      = LCM_DRIVING_CURRENT_4MA;//xfl
	params->dsi.ssc_disable = 1;//xfl

	/* Highly depends on LCD driver capability. */
	params->dsi.packet_size = 256;
	/* video mode timing */

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active = 6;
	params->dsi.vertical_backporch = 14;
	params->dsi.vertical_frontporch = 14;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 20;
	params->dsi.horizontal_backporch = 60;
	params->dsi.horizontal_frontporch = 60;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	/* params->dsi.ssc_disable = 1; */
	params->dsi.PLL_CLOCK = 440;//xfl 480
}


static void lcm_init(void)
{	
	LCM_LOGI("lcm_init enter\n");
	#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_bias_en(1);
	lcm_i2c_set_vol_value(5000, 5000);
	#endif

	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(5);
	SET_RESET_PIN(1);
	MDELAY(10);
	init_lcm_registers();
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
	
	#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
	lcm_i2c_bias_en(0);
	#endif
	MDELAY(10);
}

static unsigned int lcm_compare_id(void)
{
/*
	unsigned int id = 0;
	unsigned char buffer[2];
	unsigned int array[16];

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);

	array[0] = 0x00023700;
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0x0A, buffer, 2);
	id = buffer[0];
*/
	int ver = -1;
	ver = lcm_id_index(0);
	#ifdef BUILD_LK
		printf("%s, LK NT35596 OTM1906A id = %d\n", __func__, ver);
	#else
		printk("%s, kernel NT35596 id = %d\n", __func__, ver);
	#endif
	if (0 == ver)
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

static void lcm_update(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
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

	data_array[0] = 0x00053902;
	data_array[1] = (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00053902;
	data_array[1] = (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2] = (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);
}


LCM_DRIVER OTM1906A_TDO_3D0598U71063_lcm_drv = {
	.name = "OTM1906A_TDO_3D0598U71063",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id	= lcm_compare_id,
	.update         = lcm_update,
	.init_power = lcm_init_power,

};
