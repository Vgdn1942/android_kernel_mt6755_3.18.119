#ifndef TOUCHPANEL_H__
#define TOUCHPANEL_H__

#include <linux/hrtimer.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
//#include <linux/io.h>
#ifdef CONFIG_MTK_BOOT
#include "mt_boot_common.h"
#endif

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/bitops.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/byteorder/generic.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include <linux/interrupt.h>
#include <linux/time.h>
//#include <linux/rtpm_prio.h>

#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>

#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/suspend.h>


struct Upgrade_Info {
	u8 CHIP_ID;
	u8 FTS_NAME[20];
	u8 TPD_MAX_POINTS;
	u8 AUTO_CLB;
	u16 delay_aa;		/*delay of write FT_UPGRADE_AA */
	u16 delay_55;		/*delay of write FT_UPGRADE_55 */
	u8 upgrade_id_1;	/*upgrade id 1 */
	u8 upgrade_id_2;	/*upgrade id 2 */
	u16 delay_readid;	/*delay of read id */
	u16 delay_earse_flash; /*delay of earse flash*/
};

//#define TPD_HAVE_BUTTON	// if have virtual key,need define the MACRO


#define TPD_BUTTON_HEIGH 		(100)
#define TPD_KEY_COUNT 			3
#define TPD_KEYS 				{KEY_MENU,KEY_BACK,KEY_HOME}
#define TPD_KEYS_DIM 			{{60,AGOLD_TPD_RES_Y*850/800,120,TPD_BUTTON_HEIGH},\
								{180,AGOLD_TPD_RES_Y*850/800,120,TPD_BUTTON_HEIGH},\
								{300,AGOLD_TPD_RES_Y*850/800,120,TPD_BUTTON_HEIGH}}

#define TPD_NAME    "FT5406_MT"

/* Pre-defined definition */
#define TPD_POWER_SOURCE         MT6328_POWER_LDO_VGP1 //MT6323_POWER_LDO_VGP1
//#define TPD_PROXIMITY					// if need the PS funtion,enable this MACRO
#define TPD_TYPE_CAPACITIVE
#define TPD_TYPE_RESISTIVE
#define TPD_I2C_NUMBER           		0
#define TPD_WAKEUP_TRIAL         		60
#define TPD_WAKEUP_DELAY         		100

#define TPD_DELAY                		(2*HZ/100)
#define TPD_CALIBRATION_MATRIX  		{962,0,0,0,1600,0,0,0};

//#define TPD_HAVE_CALIBRATION
//#define TPD_HAVE_TREMBLE_ELIMINATION
#define GPIO_CTP_RST_PIN         (10| 0x80000000)

/******************************************************************************/
/*Chip Device Type*/
#define IC_FT5X06						0	/*x=2,3,4*/
#define IC_FT5606						1	/*ft5506/FT5606/FT5816*/
#define IC_FT5316						2	/*ft5x16*/
#define IC_FT6208						3  	/*ft6208*/
#define IC_FT6x06     					4	/*ft6206/FT6306*/
#define IC_FT5x06i     					5	/*ft5306i*/
#define IC_FT5x36     					6	/*ft5336/ft5436/FT5436i*/


/*register address*/
#define FT_REG_CHIP_ID				0xA3    //chip ID 
#define FT_REG_FW_VER				0xA6   //FW  version 
#define FT_REG_VENDOR_ID			0xA8   // TP vendor ID 
#define GTP_ADDR_LENGTH             1
#define IIC_MAX_TRANSFER_SIZE         8

#define TPD_MAX_POINTS_2                        2
#define TPD_MAX_POINTS_5                        5
#define TPD_MAXPOINTS_10                        10
#define AUTO_CLB_NEED                           1
#define AUTO_CLB_NONEED                         0

#define TPD_SYSFS_DEBUG
#define FTS_CTL_IIC
#define FTS_APK_DEBUG
#ifdef TPD_SYSFS_DEBUG
//#define AGOLD_TPD_FT_AUTO_UPGRADE				// if need upgrade CTP FW when POWER ON,pls enable this MACRO
#endif

#define FTS_DBG
#ifdef FTS_DBG
#define DBG(fmt, args...) 				printk("[FTS]" fmt, ## args)
#else
#define DBG(fmt, args...) 				do{}while(0)
#endif

#endif /* TOUCHPANEL_H__ */
