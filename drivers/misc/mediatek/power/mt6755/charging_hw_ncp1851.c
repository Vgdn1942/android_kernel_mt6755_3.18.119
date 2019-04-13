/*****************************************************************************
 *
 * Filename:
 * ---------
 *    charging_pmic.c
 *
 * Project:
 * --------
 *   ALPS_Software
 *
 * Description:
 * ------------
 *   This file implements the interface between BMT and ADC scheduler.
 *
 * Author:
 * -------
 *  Oscar Liu
 *
 *============================================================================
  * $Revision:   1.0  $
 * $Modtime:   11 Aug 2005 10:28:16  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/hal/peripheral/inc/bmt_chr_setting.h-arc  $
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <mt-plat/charging.h>
#include "ncp1851.h"
#include <mt-plat/upmu_common.h>
#include <mt-plat/upmu_common.h>
#include <mach/upmu_hw.h>
#include <mach/upmu_sw.h>
#include <linux/delay.h>
#include <mach/mt_sleep.h>
#include <mt-plat/mt_boot.h>
#include <linux/spinlock.h>
#include <mt-plat/mt_gpio.h>
#include <linux/wakelock.h>
#include <linux/gpio.h>
#include <mt6311.h>
#include "mtk_bif_intf.h"
//#include <mach/upmu_sw.h>
 // ============================================================ //
 //define
 // ============================================================ //
#define STATUS_OK	0
#define STATUS_UNSUPPORTED	-1
#define GETARRAYNUM(array) (sizeof(array)/sizeof(array[0]))
extern unsigned int mt6311_get_chip_id(void);
 extern int is_mt6311_exist(void);
 extern int is_mt6311_sw_ready(void);
extern int hw_charging_get_charger_type(void);
static CHARGER_TYPE g_charger_type = CHARGER_UNKNOWN;

static unsigned int g_input_current;

#define GPIO_PWR_AVAIL_WLC 61

 // ============================================================ //
 //global variable
 // ============================================================ //

int gpio_off_dir  = GPIO_DIR_OUT;
int gpio_off_out  = GPIO_OUT_ONE;
int gpio_on_dir   = GPIO_DIR_OUT;
int gpio_on_out   = GPIO_OUT_ZERO;
#if defined(CONFIG_MTK_WIRELESS_CHARGER_SUPPORT)
#define WIRELESS_CHARGER_EXIST_STATE 0

    #if defined(GPIO_PWR_AVAIL_WLC)
        unsigned int wireless_charger_gpio_number = GPIO_PWR_AVAIL_WLC; 
    #else
        unsigned int wireless_charger_gpio_number = 0; 
    #endif
    
#endif



kal_bool charging_type_det_done = KAL_TRUE;

//As 82 platform mach/charging.h could not cover all voltage setting, just hardcoded below settings
#if 0
const unsigned int VBAT_CV_VTH[]=
{
	3300000,    3325000,    3350000,    3375000,
	3400000,    3425000,    3450000,    3475000,
	3500000,    3525000,    3550000,    3575000,
	3600000,    3625000,    3650000,    3675000,
	3700000,    3725000,    3750000,    3775000,
	3800000,    3825000,    3850000,    3875000,
	3900000,    3925000,    3950000,    3975000,
	4000000,    4025000,    4050000,    4075000,
	4100000,    4125000,    4150000,    4175000,
	4200000,    4225000,    4250000,    4275000,
	4300000,    4325000,    4350000,    4375000,
	4400000,    4425000,    4450000,    4475000,
};
#else
const unsigned int VBAT_CV_VTH[]=
{
	BATTERY_VOLT_03_500000_V,   BATTERY_VOLT_03_520000_V,	BATTERY_VOLT_03_540000_V,   BATTERY_VOLT_03_560000_V,
	BATTERY_VOLT_03_580000_V,   BATTERY_VOLT_03_600000_V,	BATTERY_VOLT_03_620000_V,   BATTERY_VOLT_03_640000_V,
	BATTERY_VOLT_03_660000_V,	BATTERY_VOLT_03_680000_V,	BATTERY_VOLT_03_700000_V,	BATTERY_VOLT_03_720000_V,
	BATTERY_VOLT_03_740000_V,	BATTERY_VOLT_03_760000_V,	BATTERY_VOLT_03_780000_V,	BATTERY_VOLT_03_800000_V,
	BATTERY_VOLT_03_820000_V,	BATTERY_VOLT_03_840000_V,	BATTERY_VOLT_03_860000_V,	BATTERY_VOLT_03_880000_V,
	BATTERY_VOLT_03_900000_V,	BATTERY_VOLT_03_920000_V,	BATTERY_VOLT_03_940000_V,	BATTERY_VOLT_03_960000_V,
	BATTERY_VOLT_03_980000_V,	BATTERY_VOLT_04_000000_V,	BATTERY_VOLT_04_020000_V,	BATTERY_VOLT_04_040000_V,
	BATTERY_VOLT_04_060000_V,	BATTERY_VOLT_04_080000_V,	BATTERY_VOLT_04_100000_V,	BATTERY_VOLT_04_120000_V,
	BATTERY_VOLT_04_140000_V,   BATTERY_VOLT_04_160000_V,	BATTERY_VOLT_04_180000_V,   BATTERY_VOLT_04_200000_V,
	BATTERY_VOLT_04_220000_V,   BATTERY_VOLT_04_240000_V,	BATTERY_VOLT_04_260000_V,   BATTERY_VOLT_04_280000_V,
	BATTERY_VOLT_04_300000_V,   BATTERY_VOLT_04_320000_V,	BATTERY_VOLT_04_340000_V,   BATTERY_VOLT_04_360000_V,	
	BATTERY_VOLT_04_380000_V,   BATTERY_VOLT_04_400000_V,	BATTERY_VOLT_04_420000_V,   BATTERY_VOLT_04_440000_V	
	
};
#endif
const unsigned int CS_VTH[]=
{
	CHARGE_CURRENT_400_00_MA,   CHARGE_CURRENT_500_00_MA,	CHARGE_CURRENT_600_00_MA, CHARGE_CURRENT_700_00_MA,
	CHARGE_CURRENT_800_00_MA,   CHARGE_CURRENT_900_00_MA,	CHARGE_CURRENT_1000_00_MA, CHARGE_CURRENT_1100_00_MA,
	CHARGE_CURRENT_1200_00_MA,   CHARGE_CURRENT_1300_00_MA,	CHARGE_CURRENT_1400_00_MA, CHARGE_CURRENT_1500_00_MA,
	CHARGE_CURRENT_1600_00_MA,
}; 

 const unsigned int INPUT_CS_VTH[]=
 {
	 CHARGE_CURRENT_100_00_MA,  CHARGE_CURRENT_500_00_MA,  CHARGE_CURRENT_900_00_MA,
	 CHARGE_CURRENT_1500_00_MA,  CHARGE_CURRENT_MAX
 }; 

 const unsigned int VCDT_HV_VTH[]=
 {
	  BATTERY_VOLT_04_200000_V, BATTERY_VOLT_04_250000_V,	  BATTERY_VOLT_04_300000_V,   BATTERY_VOLT_04_350000_V,
	  BATTERY_VOLT_04_400000_V, BATTERY_VOLT_04_450000_V,	  BATTERY_VOLT_04_500000_V,   BATTERY_VOLT_04_550000_V,
	  BATTERY_VOLT_04_600000_V, BATTERY_VOLT_06_000000_V,	  BATTERY_VOLT_06_500000_V,   BATTERY_VOLT_07_000000_V,
	  BATTERY_VOLT_07_500000_V, BATTERY_VOLT_08_500000_V,	  BATTERY_VOLT_09_500000_V,   BATTERY_VOLT_10_500000_V		  
 };

 // ============================================================ //
 // function prototype
 // ============================================================ //
 
 
 // ============================================================ //
 //extern variable
 // ============================================================ //
 
 // ============================================================ //
 //extern function
 // ============================================================ //
 extern unsigned int upmu_get_reg_value(unsigned int reg);
 extern bool mt_usb_is_device(void);
 extern void Charger_Detect_Init(void);
 extern void Charger_Detect_Release(void);
extern int hw_charging_get_charger_type(void);
 extern void mt_power_off(void);
extern unsigned int mt6311_get_chip_id(void);
extern int is_mt6311_exist(void);
extern int is_mt6311_sw_ready(void);
 
 // ============================================================ //
 unsigned int charging_value_to_parameter(const unsigned int *parameter, const unsigned int array_size, const unsigned int val)
{
	if (val < array_size)
	{
		return parameter[val];
	}
	else
	{
		battery_xlog_printk(BAT_LOG_CRTI, "Can't find the parameter \r\n");	
		return parameter[0];
	}
}

 
 unsigned int charging_parameter_to_value(const unsigned int *parameter, const unsigned int array_size, const unsigned int val)
{
	unsigned int i;

    battery_xlog_printk(BAT_LOG_CRTI, "array_size = %d \r\n", array_size);
    
	for(i=0;i<array_size;i++)
	{
		if (val == *(parameter + i))
		{
				return i;
		}
	}

    battery_xlog_printk(BAT_LOG_CRTI, "whl NO register value match. val=%d\r\n", val);
	//TODO: ASSERT(0);	// not find the value
	return 0;
}


 static unsigned int bmt_find_closest_level(const unsigned int *pList,unsigned int number,unsigned int level)
 {
	 unsigned int i;
	 unsigned int max_value_in_last_element;
 
	 if(pList[0] < pList[1])
		 max_value_in_last_element = KAL_TRUE;
	 else
		 max_value_in_last_element = KAL_FALSE;
 
	 if(max_value_in_last_element == KAL_TRUE)
	 {
		 for(i = (number-1); i != 0; i--)	 //max value in the last element
		 {
			 if(pList[i] <= level)
			 {
				 return pList[i];
			 }	  
		 }

 		 battery_xlog_printk(BAT_LOG_CRTI, "Can't find closest level, small value first \r\n");
		 return pList[0];
		 //return CHARGE_CURRENT_0_00_MA;
	 }
	 else
	 {
		 for(i = 0; i< number; i++)  // max value in the first element
		 {
			 if(pList[i] <= level)
			 {
				 return pList[i];
			 }	  
		 }

		 battery_xlog_printk(BAT_LOG_CRTI, "Can't find closest level, large value first \r\n"); 	 
		 return pList[number -1];
  		 //return CHARGE_CURRENT_0_00_MA;
	 }
 }


#if 0
static void hw_bc11_dump_register(void)
{
	unsigned int reg_val = 0;
	unsigned int reg_num = CHR_CON18;
	unsigned int i = 0;

	for(i=reg_num ; i<=CHR_CON19 ; i+=2)
	{
		reg_val = upmu_get_reg_value(i);
		battery_xlog_printk(BAT_LOG_FULL, "Chr Reg[0x%x]=0x%x \r\n", i, reg_val);
	}
}


 static void hw_bc11_init(void)
 {
	 Charger_Detect_Init();
		 
	 //RG_BC11_BIAS_EN=1	
	 upmu_set_rg_bc11_bias_en(0x1);
	 //RG_BC11_VSRC_EN[1:0]=00
	 upmu_set_rg_bc11_vsrc_en(0x0);
	 //RG_BC11_VREF_VTH = [1:0]=00
	 upmu_set_rg_bc11_vref_vth(0x0);
	 //RG_BC11_CMP_EN[1.0] = 00
	 upmu_set_rg_bc11_cmp_en(0x0);
	 //RG_BC11_IPU_EN[1.0] = 00
	 upmu_set_rg_bc11_ipu_en(0x0);
	 //RG_BC11_IPD_EN[1.0] = 00
	 upmu_set_rg_bc11_ipd_en(0x0);
	 //BC11_RST=1
	 upmu_set_rg_bc11_rst(0x1);
	 //BC11_BB_CTRL=1
	 upmu_set_rg_bc11_bb_ctrl(0x1);
 
 	 //msleep(10);
 	 mdelay(50);

	 if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	 {
    		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_init() \r\n");
		hw_bc11_dump_register();
	 }	
	 
 }
 
 
 static U32 hw_bc11_DCD(void)
 {
	 U32 wChargerAvail = 0;
 
	 //RG_BC11_IPU_EN[1.0] = 10
	 upmu_set_rg_bc11_ipu_en(0x2);
	 //RG_BC11_IPD_EN[1.0] = 01
	 upmu_set_rg_bc11_ipd_en(0x1);
	 //RG_BC11_VREF_VTH = [1:0]=01
	 upmu_set_rg_bc11_vref_vth(0x1);
	 //RG_BC11_CMP_EN[1.0] = 10
	 upmu_set_rg_bc11_cmp_en(0x2);
 
	 //msleep(20);
	 mdelay(80);

 	 wChargerAvail = upmu_get_rgs_bc11_cmp_out();
	 
	 if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	 {
		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_DCD() \r\n");
		hw_bc11_dump_register();
	 }
	 
	 //RG_BC11_IPU_EN[1.0] = 00
	 upmu_set_rg_bc11_ipu_en(0x0);
	 //RG_BC11_IPD_EN[1.0] = 00
	 upmu_set_rg_bc11_ipd_en(0x0);
	 //RG_BC11_CMP_EN[1.0] = 00
	 upmu_set_rg_bc11_cmp_en(0x0);
	 //RG_BC11_VREF_VTH = [1:0]=00
	 upmu_set_rg_bc11_vref_vth(0x0);
 
	 return wChargerAvail;
 }
 
 
 static U32 hw_bc11_stepA1(void)
 {
	U32 wChargerAvail = 0;
	  
	//RG_BC11_IPU_EN[1.0] = 10
	upmu_set_rg_bc11_ipu_en(0x2);
	//RG_BC11_VREF_VTH = [1:0]=10
	upmu_set_rg_bc11_vref_vth(0x2);
	//RG_BC11_CMP_EN[1.0] = 10
	upmu_set_rg_bc11_cmp_en(0x2);
 
	//msleep(80);
	mdelay(80);
 
	wChargerAvail = upmu_get_rgs_bc11_cmp_out();
 
	if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	{
		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_stepA1() \r\n");
		hw_bc11_dump_register();
	}
 
	//RG_BC11_IPU_EN[1.0] = 00
	upmu_set_rg_bc11_ipu_en(0x0);
	//RG_BC11_CMP_EN[1.0] = 00
	upmu_set_rg_bc11_cmp_en(0x0);
 
	return  wChargerAvail;
 }
 
 
 static U32 hw_bc11_stepB1(void)
 {
	U32 wChargerAvail = 0;
	  
	//RG_BC11_IPU_EN[1.0] = 01
	//upmu_set_rg_bc11_ipu_en(0x1);
	upmu_set_rg_bc11_ipd_en(0x1);      
	//RG_BC11_VREF_VTH = [1:0]=10
	//upmu_set_rg_bc11_vref_vth(0x2);
	upmu_set_rg_bc11_vref_vth(0x0);
	//RG_BC11_CMP_EN[1.0] = 01
	upmu_set_rg_bc11_cmp_en(0x1);
 
	//msleep(80);
	mdelay(80);
 
	wChargerAvail = upmu_get_rgs_bc11_cmp_out();
 
	if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	{
		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_stepB1() \r\n");
		hw_bc11_dump_register();
	}
 
	//RG_BC11_IPU_EN[1.0] = 00
	upmu_set_rg_bc11_ipu_en(0x0);
	//RG_BC11_CMP_EN[1.0] = 00
	upmu_set_rg_bc11_cmp_en(0x0);
	//RG_BC11_VREF_VTH = [1:0]=00
	upmu_set_rg_bc11_vref_vth(0x0);
 
	return  wChargerAvail;
 }
 
 
 static U32 hw_bc11_stepC1(void)
 {
	U32 wChargerAvail = 0;
	  
	//RG_BC11_IPU_EN[1.0] = 01
	upmu_set_rg_bc11_ipu_en(0x1);
	//RG_BC11_VREF_VTH = [1:0]=10
	upmu_set_rg_bc11_vref_vth(0x2);
	//RG_BC11_CMP_EN[1.0] = 01
	upmu_set_rg_bc11_cmp_en(0x1);
 
	//msleep(80);
	mdelay(80);
 
	wChargerAvail = upmu_get_rgs_bc11_cmp_out();
 
	if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	{
		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_stepC1() \r\n");
		hw_bc11_dump_register();
	}
 
	//RG_BC11_IPU_EN[1.0] = 00
	upmu_set_rg_bc11_ipu_en(0x0);
	//RG_BC11_CMP_EN[1.0] = 00
	upmu_set_rg_bc11_cmp_en(0x0);
	//RG_BC11_VREF_VTH = [1:0]=00
	upmu_set_rg_bc11_vref_vth(0x0);
 
	return  wChargerAvail;
 }
 
 
 static U32 hw_bc11_stepA2(void)
 {
	U32 wChargerAvail = 0;
	  
	//RG_BC11_VSRC_EN[1.0] = 10 
	upmu_set_rg_bc11_vsrc_en(0x2);
	//RG_BC11_IPD_EN[1:0] = 01
	upmu_set_rg_bc11_ipd_en(0x1);
	//RG_BC11_VREF_VTH = [1:0]=00
	upmu_set_rg_bc11_vref_vth(0x0);
	//RG_BC11_CMP_EN[1.0] = 01
	upmu_set_rg_bc11_cmp_en(0x1);
 
	//msleep(80);
	mdelay(80);
 
	wChargerAvail = upmu_get_rgs_bc11_cmp_out();
 
	if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	{
		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_stepA2() \r\n");
		hw_bc11_dump_register();
	}
 
	//RG_BC11_VSRC_EN[1:0]=00
	upmu_set_rg_bc11_vsrc_en(0x0);
	//RG_BC11_IPD_EN[1.0] = 00
	upmu_set_rg_bc11_ipd_en(0x0);
	//RG_BC11_CMP_EN[1.0] = 00
	upmu_set_rg_bc11_cmp_en(0x0);
 
	return  wChargerAvail;
 }
 
 
 static U32 hw_bc11_stepB2(void)
 {
	U32 wChargerAvail = 0;
 
	//RG_BC11_IPU_EN[1:0]=10
	upmu_set_rg_bc11_ipu_en(0x2);
	//RG_BC11_VREF_VTH = [1:0]=10
	upmu_set_rg_bc11_vref_vth(0x1);
	//RG_BC11_CMP_EN[1.0] = 01
	upmu_set_rg_bc11_cmp_en(0x1);
 
	//msleep(80);
	mdelay(80);
 
	wChargerAvail = upmu_get_rgs_bc11_cmp_out();
 
	if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	{
		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_stepB2() \r\n");
		hw_bc11_dump_register();
	}
 
	//RG_BC11_IPU_EN[1.0] = 00
	upmu_set_rg_bc11_ipu_en(0x0);
	//RG_BC11_CMP_EN[1.0] = 00
	upmu_set_rg_bc11_cmp_en(0x0);
	//RG_BC11_VREF_VTH = [1:0]=00
	upmu_set_rg_bc11_vref_vth(0x0);
 
	return  wChargerAvail;
 }
 
 
 static void hw_bc11_done(void)
 {
	//RG_BC11_VSRC_EN[1:0]=00
	upmu_set_rg_bc11_vsrc_en(0x0);
	//RG_BC11_VREF_VTH = [1:0]=0
	upmu_set_rg_bc11_vref_vth(0x0);
	//RG_BC11_CMP_EN[1.0] = 00
	upmu_set_rg_bc11_cmp_en(0x0);
	//RG_BC11_IPU_EN[1.0] = 00
	upmu_set_rg_bc11_ipu_en(0x0);
	//RG_BC11_IPD_EN[1.0] = 00
	upmu_set_rg_bc11_ipd_en(0x0);
	//RG_BC11_BIAS_EN=0
	upmu_set_rg_bc11_bias_en(0x0); 
 
	Charger_Detect_Release();

	if(Enable_BATDRV_LOG == BAT_LOG_FULL)
	{
		battery_xlog_printk(BAT_LOG_FULL, "hw_bc11_done() \r\n");
		hw_bc11_dump_register();
	}
    
 }
#endif
#ifdef AGOLD_LED_AW2013
extern bool aw2013_is_exist(void);
#endif
extern int ncp1851_read_byte(unsigned char cmd, unsigned char *returnData);
extern unsigned int ncp1851_config_interface_liao (unsigned char RegNum, unsigned char val);
void agold_charger_led_disp(unsigned int enable)
{
	unsigned char data = 0 ;
	int ret =0;
   ret=ncp1851_read_byte(0x00,&data);

#if defined(AGOLD_DELETE_LED_KERNEL)
	ncp1851_config_interface_liao(0x00,(data&(~0x40)));//that is 24158's whl
	return;
#endif
#ifdef AGOLD_LED_AW2013
	if(aw2013_is_exist())
	{
		ncp1851_config_interface_liao(0x00,(data|0x40)); //that is 24158's whl
		return;
	}
#endif
	if(enable)
	{
		ncp1851_config_interface_liao(0x00,data|0x40); //0x80  turn on charger led display that is 24158's whl
	}
	else
	{
		ncp1851_config_interface_liao(0x00,(data&(~0x40))); //0x80  shutdown charger led display that is 24158's whl
	}
	
	
}

#if 0
static unsigned int is_chr_det(void)
 {
	 unsigned int val=0;
   
	 val = upmu_get_rgs_chrdet();
 
	 battery_xlog_printk(BAT_LOG_CRTI,"[is_chr_det] %d\n", val);
	 
	 return val;
 }
#endif
 static unsigned int charging_hw_init(void *data)
{
    unsigned int ncp1851_status;
 	unsigned int status = STATUS_OK;

    if (Enable_BATDRV_LOG == 1) {
        printk("[BATTERY:ncp1851] ChargerHwInit_ncp1851\n" );
    }

    ncp1851_status = ncp1851_get_chip_status();

    //upmu_set_rg_bc11_bb_ctrl(1);    //BC11_BB_CTRL    
    //upmu_set_rg_bc11_rst(1);        //BC11_RST

    ncp1851_set_otg_en(0x0);
    ncp1851_set_ntc_en(0x0);
    ncp1851_set_trans_en(0);
    ncp1851_set_tj_warn_opt(0x1);
    ncp1851_set_jeita_opt(0x1);
//  ncp1851_set_int_mask(0x0); //disable all interrupt
    ncp1851_set_int_mask(0x1); //enable all interrupt for boost mode status monitor
    ncp1851_set_tchg_rst(0x1); //reset charge timer
#ifdef NCP1851_PWR_PATH
    ncp1851_set_pwr_path(0x1);
#else
    ncp1851_set_pwr_path(0x0);
#endif

   
    if((ncp1851_status == 0x8) || (ncp1851_status == 0x9) || (ncp1851_status == 0xA)) //WEAK WAIT, WEAK SAFE, WEAK CHARGE
	{
        ncp1851_set_ctrl_vbat(0x1C); //VCHG = 4.0V
	}
	else if(ncp1851_status == 0x4)
	{
	#if defined(HIGH_BATTERY_VOLTAGE_SUPPORT)
        ncp1851_set_ctrl_vbat(0x2E); //VCHG = 4.45V chenlang add 20150323 for high vchg
    #else		
        ncp1851_set_ctrl_vbat(0x28); //VCHG = 4.3V to decrease charge time
	#endif
	}
    else
	{
	#if defined(HIGH_BATTERY_VOLTAGE_SUPPORT)
        ncp1851_set_ctrl_vbat(0x2A); //VCHG = 4.35V chenlang add 20150323 for high vchg
	#else
        ncp1851_set_ctrl_vbat(0x24); //VCHG = 4.2V
	#endif
	}	

    ncp1851_set_ieoc(0x6); // terminate current = 250mA for ICS optimized suspend power

    ncp1851_set_iweak(0x3); //weak charge current = 300mA

    ncp1851_set_ctrl_vfet(0x3); // VFET = 3.4V
    ncp1851_set_vchred(0x2); //reduce 200mV (JEITA)
    ncp1851_set_ichred(0x0); //reduce 400mA (JEITA)
    ncp1851_set_batcold(0x5);
    ncp1851_set_bathot(0x3);
    ncp1851_set_batchilly(0x0);
    ncp1851_set_batwarm(0x0);
/*
 #if defined(CONFIG_MTK_WIRELESS_CHARGER_SUPPORT)
		if(wireless_charger_gpio_number!=0)
		{
			mt_set_gpio_mode(wireless_charger_gpio_number,0); // 0:GPIO mode
			mt_set_gpio_dir(wireless_charger_gpio_number,0); // 0: input, 1: output
		}
#endif
*/
	
	return status;
}

 static unsigned int charging_dump_register(void *data)
 {
 	unsigned int status = STATUS_OK;

    battery_xlog_printk(BAT_LOG_CRTI, "charging_dump_register\r\n");

    ncp1851_dump_register();
   	
	return status;
 }	


 static unsigned int charging_enable(void *data)
 {
 	unsigned int status = STATUS_OK;
	unsigned int enable = *(unsigned int*)(data);

	if(KAL_TRUE == enable)
	{
		ncp1851_set_chg_en(0x1); // charger enable
		//Set SPM = 1
#ifdef GPIO_SWCHARGER_EN_PIN

		mt_set_gpio_mode(GPIO_SWCHARGER_EN_PIN, GPIO_MODE_00);
		mt_set_gpio_dir(GPIO_SWCHARGER_EN_PIN, GPIO_DIR_OUT);
		mt_set_gpio_out(GPIO_SWCHARGER_EN_PIN, GPIO_OUT_ONE);

#endif
	}
	else
	{
#if defined(CONFIG_USB_MTK_HDRC_HCD)
   		if(mt_usb_is_device())
#endif 			
    	{
			ncp1851_set_chg_en(0x0); // charger disable
    	}
	}
		
	return status;
 }


 static unsigned int charging_set_cv_voltage(void *data)
 {
 	unsigned int status = STATUS_OK;
	unsigned short int register_value;
	unsigned int cv_value = *(unsigned int *)(data);	
	unsigned int array_size;
	unsigned int set_chr_cv;	

	#if defined(HIGH_BATTERY_VOLTAGE_SUPPORT)
		cv_value = BATTERY_VOLT_04_350000_V;
	#endif


	//use nearest value
	if(BATTERY_VOLT_04_200000_V == cv_value)
		cv_value = 4208000;
		
	printk("##### charging_set_cv_voltage = %d\n", cv_value);	
	
	array_size = GETARRAYNUM(VBAT_CV_VTH);
	set_chr_cv = bmt_find_closest_level(VBAT_CV_VTH, array_size, cv_value);
	
	register_value = charging_parameter_to_value(VBAT_CV_VTH, GETARRAYNUM(VBAT_CV_VTH), set_chr_cv);
	
	printk("##### set_chr_cv = %d, register_value = %d\n", set_chr_cv, register_value);

#if 1
    ncp1851_set_ctrl_vbat(register_value);
#else
    //PCB workaround
   /* if(mt6325_upmu_get_swcid() == PMIC6325_E1_CID_CODE)
    {
        ncp1851_set_ctrl_vbat(0x14); //3.8v
        battery_xlog_printk(BAT_LOG_CRTI,"[charging_set_cv_voltage] set low CV by 6325 E1\n");
    }
    else
*/
    {
        if(is_mt6311_exist())
        {

            if(mt6311_get_chip_id()==PMIC6311_E1_CID_CODE)
            {
                ncp1851_set_ctrl_vbat(0x14); //3.8v
                battery_xlog_printk(BAT_LOG_CRTI,"[charging_set_cv_voltage] set low CV by 6311 E1\n");
            }
            else

            {
                ncp1851_set_ctrl_vbat(register_value);
            }
        }
        else
        {
            ncp1851_set_ctrl_vbat(register_value);
        } 
    }  

#endif
	return status;
 } 	


 static unsigned int charging_get_current(void *data)
 {
    unsigned int status = STATUS_OK;
    
    unsigned char ret_val=0;    
	    
    //Get current level
	ret_val = ncp1851_get_ichg();
    //ncp1851_read_interface(NCP1851_CON15, &ret_val, CON15_ICHG_MASK, CON15_ICHG_SHIFT);						    
    //Parsing
    ret_val = (ret_val*100) + 400;
	
    return status;
 }


 static unsigned int charging_set_current(void *data)
 {
 	unsigned int status = STATUS_OK;
	unsigned int set_chr_current;
	unsigned int array_size;
	unsigned int register_value;
	unsigned int current_value = *(unsigned int *)data;
	
	array_size = GETARRAYNUM(CS_VTH);
	set_chr_current = bmt_find_closest_level(CS_VTH, array_size, current_value);
	register_value = charging_parameter_to_value(CS_VTH, array_size ,set_chr_current);

	printk("[xfl]func:%s,line:%d,current_value=%d,register_value=%d\n", __func__, __LINE__, current_value, register_value);
	//current set by SW and disable automatic charge current
	ncp1851_set_aicl_en(0x1); //enable AICL
	ncp1851_set_ichg(register_value);       	
	
	return status;
 } 	
 

 static unsigned int charging_set_input_current(void *data)
 {
 	unsigned int status = STATUS_OK;
	unsigned int set_chr_current;
	unsigned int array_size;
	unsigned int register_value;
    
	array_size = GETARRAYNUM(INPUT_CS_VTH);
	set_chr_current = bmt_find_closest_level(INPUT_CS_VTH, array_size, *(unsigned int *)data);
	register_value = charging_parameter_to_value(INPUT_CS_VTH, array_size ,set_chr_current);

	printk("[xfl]func:%s,line:%d,input_current_value=%d,register_value=%d\n", __func__, __LINE__, set_chr_current, register_value);	
        
	ncp1851_set_iinlim(register_value);
	ncp1851_set_iinset_pin_en(0x0); //Input current limit and AICL control by I2C
	ncp1851_set_iinlim_en(0x1); //enable input current limit
	ncp1851_set_aicl_en(0x1); //enable AICL

	g_input_current = set_chr_current;
	return status;
 } 	


 static unsigned int charging_get_charging_status(void *data)
 {
 	unsigned int status = STATUS_OK;
	unsigned int ret_val;

	ret_val = ncp1851_get_chip_status();
	//check whether chargeing DONE
	if ((ret_val&0x6)==0x6)
	{
		*(unsigned int *)data = KAL_TRUE;
	} else {
		*(unsigned int *)data = KAL_FALSE;
	}
	
	return status;
 } 	

void kick_charger_wdt(void)
{
	//kick pmic wdt?
    //upmu_set_rg_chrwdt_td(0x0);           // CHRWDT_TD, 4s
    //upmu_set_rg_chrwdt_int_en(1);         // CHRWDT_INT_EN
    //upmu_set_rg_chrwdt_en(1);             // CHRWDT_EN
    //upmu_set_rg_chrwdt_wr(1);             // CHRWDT_WR
	ncp1851_set_wdto_dis(0x1);
	ncp1851_set_wdto_dis(0x0);

}

 static unsigned int charging_reset_watch_dog_timer(void *data)
 {
	 unsigned int status = STATUS_OK;
 
     battery_xlog_printk(BAT_LOG_CRTI, "charging_reset_watch_dog_timer\r\n");
 
	 kick_charger_wdt();
	 return status;
 }
 
 
  static unsigned int charging_set_hv_threshold(void *data)
  {
	 unsigned int status = STATUS_OK;
 
	 unsigned int set_hv_voltage;
	 unsigned int array_size;
	 unsigned short int register_value;
	 unsigned int voltage = *(unsigned int*)(data);
	 
	 array_size = GETARRAYNUM(VCDT_HV_VTH);
	 set_hv_voltage = bmt_find_closest_level(VCDT_HV_VTH, array_size, voltage);
	 register_value = charging_parameter_to_value(VCDT_HV_VTH, array_size ,set_hv_voltage);    
	 pmic_set_register_value(PMIC_RG_VCDT_HV_VTH,register_value);
	 return status;
  }
 
 
  static unsigned int charging_get_hv_status(void *data)
  {
	   unsigned int status = STATUS_OK;
	   #if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)
		  *(kal_bool*)(data) = 0;
		  battery_xlog_printk(BAT_LOG_CRTI,"[charging_get_hv_status] charger ok for bring up.\n");
       #else
		  //*(kal_bool*)(data) = mt6325_upmu_get_rgs_vcdt_hv_det();
		 *(kal_bool*)(data) = pmic_get_register_value(PMIC_RGS_VCDT_HV_DET);
       #endif
	   
	   return status;
  }


 static unsigned int charging_get_battery_status(void *data)
 {
	   unsigned int status = STATUS_OK;
 
 	   //upmu_set_baton_tdet_en(1);	
	   //upmu_set_rg_baton_en(1);
	   	 unsigned int val = 0;
#if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)
		 *(kal_bool*)(data) = 0; // battery exist
		 battery_xlog_printk(BAT_LOG_CRTI,"[charging_get_battery_status] battery exist for bring up.\n");
#else
	val=pmic_get_register_value(PMIC_BATON_TDET_EN);
	battery_xlog_printk(BAT_LOG_FULL,"[charging_get_battery_status] BATON_TDET_EN = %d\n", val);
	if (val) {
	pmic_set_register_value(PMIC_BATON_TDET_EN,1);
	pmic_set_register_value(PMIC_RG_BATON_EN,1);
	*(kal_bool*)(data) = pmic_get_register_value(PMIC_RGS_BATON_UNDET);
	} else {
		*(kal_bool*)(data) =  KAL_FALSE;
	}
#endif
	   return status;
 }


 static unsigned int charging_get_charger_det_status(void *data)
 {
	   unsigned int status = STATUS_OK;
 
	   //*(kal_bool*)(data) = upmu_get_rgs_chrdet();
	   	 unsigned int val = 0;
	 
#if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)
		 val = 1;
		 battery_xlog_printk(BAT_LOG_CRTI,"[charging_get_charger_det_status] charger exist for bring up.\n"); 
#else    
	 	 val = pmic_get_register_value(PMIC_RGS_CHRDET);
#endif
		 
		 *(kal_bool*)(data) = val;
		 if(val == 0)
			 g_charger_type = CHARGER_UNKNOWN;
	   
	   return status;
 }


kal_bool charging_type_detection_done(void)
{
	 return charging_type_det_done;
}

//extern CHARGER_TYPE hw_charger_type_detection(void);

 static unsigned int charging_get_charger_type(void *data)
 {

#if 0
	 unsigned int status = STATUS_OK;
	 CHARGER_TYPE charger_type = CHARGER_UNKNOWN;
	#if defined(CONFIG_POWER_EXT)
		 *(CHARGER_TYPE*)(data) = STANDARD_HOST;
	#else
		 charging_type_det_done = KAL_FALSE;	
		 charger_type = hw_charging_get_charger_type();
		 battery_xlog_printk(BAT_LOG_CRTI, "charging_get_charger_type = %d\r\n", charger_type);
	 
		 *(CHARGER_TYPE*)(data) = charger_type;
		 charging_type_det_done = KAL_TRUE;
		 g_charger_type = *(CHARGER_TYPE*)(data);
	#endif
    return status;

	
#else 
			unsigned int status = STATUS_OK;
			 
	#if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)
			*(CHARGER_TYPE*)(data) = STANDARD_HOST;
	#else
		
		#if defined(CONFIG_MTK_WIRELESS_CHARGER_SUPPORT)
			int wireless_state = 0;
			if(wireless_charger_gpio_number!=0)
			{
				wireless_state = gpio_get_value(wireless_charger_gpio_number);
				if(wireless_state == WIRELESS_CHARGER_EXIST_STATE)
				{
					*(CHARGER_TYPE*)(data) = WIRELESS_CHARGER;
					battery_xlog_printk(BAT_LOG_CRTI, "WIRELESS_CHARGER!\n");
					return status;
				}
			}
			else
			{
				battery_xlog_printk(BAT_LOG_CRTI, "wireless_charger_gpio_number=%d\n", wireless_charger_gpio_number);
			}
		
			if(g_charger_type!=CHARGER_UNKNOWN && g_charger_type!=WIRELESS_CHARGER)
			{
				*(CHARGER_TYPE*)(data) = g_charger_type;
				battery_xlog_printk(BAT_LOG_CRTI, "return %d!\n", g_charger_type);
				return status;
			}
		#endif
/*
		if(is_chr_det()==0)
			{
				g_charger_type = CHARGER_UNKNOWN; 
				*(CHARGER_TYPE*)(data) = CHARGER_UNKNOWN;
				battery_xlog_printk(BAT_LOG_CRTI, "[charging_get_charger_type] return CHARGER_UNKNOWN\n");
				return status;
			}
*/		
		charging_type_det_done = KAL_FALSE;
		*(CHARGER_TYPE*)(data) = hw_charging_get_charger_type();
			//*(CHARGER_TYPE*)(data) = STANDARD_HOST;
			//*(CHARGER_TYPE*)(data) = STANDARD_CHARGER;
	
		charging_type_det_done = KAL_TRUE;
	
		g_charger_type = *(CHARGER_TYPE*)(data);

#endif

#endif
	 return status;
}

static unsigned int charging_get_is_pcm_timer_trigger(void *data)
{
    unsigned int status = STATUS_OK;
#if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)
    *(kal_bool*)(data) = KAL_FALSE;
#else 
    if(slp_get_wake_reason() == WR_PCM_TIMER)
        *(kal_bool*)(data) = KAL_TRUE;
    else
        *(kal_bool*)(data) = KAL_FALSE;

    battery_xlog_printk(BAT_LOG_CRTI, "slp_get_wake_reason=%d\n", slp_get_wake_reason());
 #endif   
    return status;
}

static unsigned int charging_set_platform_reset(void *data)
{
    unsigned int status = STATUS_OK;
#if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)    
#else 
    battery_xlog_printk(BAT_LOG_CRTI, "charging_set_platform_reset\n");
 
    //arch_reset(0,NULL);
#endif
    return status;
}

static unsigned int charging_get_platfrom_boot_mode(void *data)
{
    unsigned int status = STATUS_OK;
  #if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)   
#else  
    *(unsigned int*)(data) = get_boot_mode();

    battery_xlog_printk(BAT_LOG_CRTI, "get_boot_mode=%d\n", get_boot_mode());
  #endif   
    return status;
}

static unsigned int charging_set_power_off(void *data)
{
    unsigned int status = STATUS_OK;
  #if defined(CONFIG_POWER_EXT) || defined(CONFIG_MTK_FPGA)
#else
    //battery_xlog_printk(BAT_LOG_CRTI, "charging_set_power_off=%d\n");
    mt_power_off();
 #endif    
    return status;
}
static unsigned int charging_get_power_source(void *data)
{
	return STATUS_UNSUPPORTED;
}

static unsigned int charging_get_csdac_full_flag(void *data)
{
	return STATUS_UNSUPPORTED;	
}

static unsigned int charging_set_ta_current_pattern(void *data)
{
	return STATUS_UNSUPPORTED;	
}

static unsigned int charging_set_error_state(void *data)
{
	return STATUS_UNSUPPORTED;
}

static unsigned int charging_diso_init(void *data)
{
	unsigned int status = STATUS_OK;

#if defined(MTK_DUAL_INPUT_CHARGER_SUPPORT)
	struct device_node *node;
	DISO_ChargerStruct *pDISO_data = (DISO_ChargerStruct *) data;

	int ret;
	/* Initialization DISO Struct */
	pDISO_data->diso_state.cur_otg_state = DISO_OFFLINE;
	pDISO_data->diso_state.cur_vusb_state = DISO_OFFLINE;
	pDISO_data->diso_state.cur_vdc_state = DISO_OFFLINE;

	pDISO_data->diso_state.pre_otg_state = DISO_OFFLINE;
	pDISO_data->diso_state.pre_vusb_state = DISO_OFFLINE;
	pDISO_data->diso_state.pre_vdc_state = DISO_OFFLINE;

	pDISO_data->chr_get_diso_state = KAL_FALSE;

	pDISO_data->hv_voltage = VBUS_MAX_VOLTAGE;

	/* Initial AuxADC IRQ */
	DISO_IRQ.vdc_measure_channel.number = AP_AUXADC_DISO_VDC_CHANNEL;
	DISO_IRQ.vusb_measure_channel.number = AP_AUXADC_DISO_VUSB_CHANNEL;
	DISO_IRQ.vdc_measure_channel.period = AUXADC_CHANNEL_DELAY_PERIOD;
	DISO_IRQ.vusb_measure_channel.period = AUXADC_CHANNEL_DELAY_PERIOD;
	DISO_IRQ.vdc_measure_channel.debounce = AUXADC_CHANNEL_DEBOUNCE;
	DISO_IRQ.vusb_measure_channel.debounce = AUXADC_CHANNEL_DEBOUNCE;

	/* use default threshold voltage, if use high voltage,maybe refine */
	DISO_IRQ.vusb_measure_channel.falling_threshold = VBUS_MIN_VOLTAGE / 1000;
	DISO_IRQ.vdc_measure_channel.falling_threshold = VDC_MIN_VOLTAGE / 1000;
	DISO_IRQ.vusb_measure_channel.rising_threshold = VBUS_MIN_VOLTAGE / 1000;
	DISO_IRQ.vdc_measure_channel.rising_threshold = VDC_MIN_VOLTAGE / 1000;

	node = of_find_compatible_node(NULL, NULL, "mediatek,AUXADC");
	if (!node) {
		battery_log(BAT_LOG_CRTI, "[diso_adc]: of_find_compatible_node failed!!\n");
	} else {
		pDISO_data->irq_line_number = irq_of_parse_and_map(node, 0);
		battery_log(BAT_LOG_FULL, "[diso_adc]: IRQ Number: 0x%x\n",
			    pDISO_data->irq_line_number);
	}

	mt_irq_set_sens(pDISO_data->irq_line_number, MT_EDGE_SENSITIVE);
	mt_irq_set_polarity(pDISO_data->irq_line_number, MT_POLARITY_LOW);

	ret = request_threaded_irq(pDISO_data->irq_line_number, diso_auxadc_irq_handler,
				   pDISO_data->irq_callback_func, IRQF_ONESHOT, "DISO_ADC_IRQ",
				   NULL);

	if (ret) {
		battery_log(BAT_LOG_CRTI, "[diso_adc]: request_irq failed.\n");
	} else {
		set_vdc_auxadc_irq(DISO_IRQ_DISABLE, 0);
		set_vusb_auxadc_irq(DISO_IRQ_DISABLE, 0);
		battery_log(BAT_LOG_FULL, "[diso_adc]: diso_init success.\n");
	}

#if defined(MTK_DISCRETE_SWITCH) && defined(MTK_DSC_USE_EINT)
	battery_log(BAT_LOG_CRTI, "[diso_eint]vdc eint irq registitation\n");
	mt_eint_set_hw_debounce(CUST_EINT_VDC_NUM, CUST_EINT_VDC_DEBOUNCE_CN);
	mt_eint_registration(CUST_EINT_VDC_NUM, CUST_EINTF_TRIGGER_LOW, vdc_eint_handler, 0);
	mt_eint_mask(CUST_EINT_VDC_NUM);
#endif
#endif

	return status;
}

static unsigned int charging_get_diso_state(void *data)
{
	unsigned int status = STATUS_OK;

#if defined(MTK_DUAL_INPUT_CHARGER_SUPPORT)
	int diso_state = 0x0;
	DISO_ChargerStruct *pDISO_data = (DISO_ChargerStruct *) data;

	_get_diso_interrupt_state();
	diso_state = g_diso_state;
	battery_log(BAT_LOG_FULL, "[do_chrdet_int_task] current diso state is %s!\n",
		    DISO_state_s[diso_state]);
	if (((diso_state >> 1) & 0x3) != 0x0) {
		switch (diso_state) {
		case USB_ONLY:
			set_vdc_auxadc_irq(DISO_IRQ_DISABLE, 0);
			set_vusb_auxadc_irq(DISO_IRQ_DISABLE, 0);
#ifdef MTK_DISCRETE_SWITCH
#ifdef MTK_DSC_USE_EINT
			mt_eint_unmask(CUST_EINT_VDC_NUM);
#else
			set_vdc_auxadc_irq(DISO_IRQ_ENABLE, 1);
#endif
#endif
			pDISO_data->diso_state.cur_vusb_state = DISO_ONLINE;
			pDISO_data->diso_state.cur_vdc_state = DISO_OFFLINE;
			pDISO_data->diso_state.cur_otg_state = DISO_OFFLINE;
			break;
		case DC_ONLY:
			set_vdc_auxadc_irq(DISO_IRQ_DISABLE, 0);
			set_vusb_auxadc_irq(DISO_IRQ_DISABLE, 0);
			set_vusb_auxadc_irq(DISO_IRQ_ENABLE, DISO_IRQ_RISING);
			pDISO_data->diso_state.cur_vusb_state = DISO_OFFLINE;
			pDISO_data->diso_state.cur_vdc_state = DISO_ONLINE;
			pDISO_data->diso_state.cur_otg_state = DISO_OFFLINE;
			break;
		case DC_WITH_USB:
			set_vdc_auxadc_irq(DISO_IRQ_DISABLE, 0);
			set_vusb_auxadc_irq(DISO_IRQ_DISABLE, 0);
			set_vusb_auxadc_irq(DISO_IRQ_ENABLE, DISO_IRQ_FALLING);
			pDISO_data->diso_state.cur_vusb_state = DISO_ONLINE;
			pDISO_data->diso_state.cur_vdc_state = DISO_ONLINE;
			pDISO_data->diso_state.cur_otg_state = DISO_OFFLINE;
			break;
		case DC_WITH_OTG:
			set_vdc_auxadc_irq(DISO_IRQ_DISABLE, 0);
			set_vusb_auxadc_irq(DISO_IRQ_DISABLE, 0);
			pDISO_data->diso_state.cur_vusb_state = DISO_OFFLINE;
			pDISO_data->diso_state.cur_vdc_state = DISO_ONLINE;
			pDISO_data->diso_state.cur_otg_state = DISO_ONLINE;
			break;
		default:	/* OTG only also can trigger vcdt IRQ */
			pDISO_data->diso_state.cur_vusb_state = DISO_OFFLINE;
			pDISO_data->diso_state.cur_vdc_state = DISO_OFFLINE;
			pDISO_data->diso_state.cur_otg_state = DISO_ONLINE;
			battery_log(BAT_LOG_FULL, " switch load vcdt irq triggerd by OTG Boost!\n");
			break;	/* OTG plugin no need battery sync action */
		}
	}

	if (DISO_ONLINE == pDISO_data->diso_state.cur_vdc_state)
		pDISO_data->hv_voltage = VDC_MAX_VOLTAGE;
	else
		pDISO_data->hv_voltage = VBUS_MAX_VOLTAGE;
#endif

	return status;
}

static unsigned int charging_set_vindpm(void *data)
{
	unsigned int status = STATUS_OK;
	//unsigned int v = *(unsigned int *) data;

	//bq25890_set_VINDPM(v);

	return status;
}

static unsigned int charging_set_vbus_ovp_en(void *data)
{
	unsigned int status = STATUS_OK;
	unsigned int e = *(unsigned int *) data;

	pmic_set_register_value(MT6351_PMIC_RG_VCDT_HV_EN, e);

	return status;
}

static unsigned int charging_get_bif_vbat(void *data)
{
	unsigned int status = STATUS_OK;
#ifdef CONFIG_MTK_BIF_SUPPORT
	int vbat = 0;

	/* turn on VBIF28 regulator*/
	/*bif_init();*/

	/*change to HW control mode*/
	/*pmic_set_register_value(MT6351_PMIC_RG_VBIF28_ON_CTRL, 0);
	pmic_set_register_value(MT6351_PMIC_RG_VBIF28_EN, 1);*/
	if (bif_checked != 1 || bif_exist == 1) {
		bif_ADC_enable();

		vbat = bif_read16(MW3790_VBAT);
		*(unsigned int *) (data) = vbat;
	}
	/*turn off LDO and change SW control back to HW control */
	/*pmic_set_register_value(MT6351_PMIC_RG_VBIF28_EN, 0);
	pmic_set_register_value(MT6351_PMIC_RG_VBIF28_ON_CTRL, 1);*/
#else
	*(unsigned int *) (data) = 0;
#endif
	return status;
}

static unsigned int charging_set_chrind_ck_pdn(void *data)
{
	unsigned int status = STATUS_OK;
	unsigned int pwr_dn;

	pwr_dn = *(unsigned int *) data;

	pmic_set_register_value(PMIC_RG_DRV_CHRIND_CK_PDN, pwr_dn);

	return status;
}

static unsigned int charging_sw_init(void *data)
{
	unsigned int status = STATUS_OK;
	/*put here anything needed to be init upon battery_common driver probe*/
#ifdef CONFIG_MTK_BIF_SUPPORT
	int vbat;

	vbat = 0;
	if (bif_checked != 1) {
		bif_init();
		charging_get_bif_vbat(&vbat);
		if (vbat != 0) {
			battery_log(BAT_LOG_CRTI, "[BIF]BIF battery detected.\n");
			bif_exist = 1;
		} else
			battery_log(BAT_LOG_CRTI, "[BIF]BIF battery _NOT_ detected.\n");
		bif_checked = 1;
	}
#endif
	return status;
}

static unsigned int charging_enable_safetytimer(void *data)
{

	unsigned int status = STATUS_OK;
	/*
	unsigned int en;

	en = *(unsigned int *) data;
	//bq25890_en_chg_timer(en);
*/
	return status;
}

static unsigned int charging_set_hiz_swchr(void *data)
{
	unsigned int status = STATUS_OK;
/*	
	unsigned int en;

	en = *(unsigned int *) data;
	bq25890_set_en_hiz(en);
*/
	return status;
}

static unsigned int charging_get_bif_tbat(void *data)
{
	unsigned int status = STATUS_OK;
#ifdef CONFIG_MTK_BIF_SUPPORT
	int tbat = 0;
	int ret;
	int tried = 0;

	mdelay(50);

	if (bif_exist == 1) {
		do {
			bif_ADC_enable();
			ret = bif_read8(MW3790_TBAT, &tbat);
			tried++;
			mdelay(50);
			if (tried > 3)
				break;
		} while (ret != 1);

		if (tried <= 3)
			*(int *) (data) = tbat;
		else
			status =  STATUS_UNSUPPORTED;
	}
#endif
	return status;
}

static unsigned int charging_get_bif_is_exist(void *data)
{
	int bif_exist = 0;

	bif_exist = mtk_bif_is_hw_exist();
	*(bool *)data = bif_exist;

	return 0;
}

static unsigned int charging_set_ta20_reset(void *data)
{
	
	return STATUS_OK;
}

static unsigned int charging_set_ta20_current_pattern(void *data)
{
	
	return STATUS_OK;
}

static unsigned int charging_set_dp(void *data)
{
	int status = STATUS_OK;

	return status;
}

static unsigned int charging_get_charger_temperature(void *data)
{
	return STATUS_UNSUPPORTED;
}

static unsigned int charging_set_boost_current_limit(void *data)
{
	int ret = 0;

	return ret;
}

static unsigned int charging_enable_otg(void *data)
{
	int ret = 0;
	return ret;
}

static unsigned int charging_enable_power_path(void *data)
{
	int ret = 0;

	return ret;
}

static unsigned int charging_get_input_current(void *data)
{
	int ret = 0;

	*((u32 *)data) = g_input_current;

	return ret;
}

static unsigned int charging_enable_direct_charge(void *data)
{
	return -ENOTSUPP;
}

static unsigned int charging_get_is_power_path_enable(void *data)
{
	int ret = 0;

	return ret;
}

static unsigned int charging_get_is_safetytimer_enable(void *data)
{
	int ret = 0;

	return ret;
}

static unsigned int charging_set_pwrstat_led_en(void *data)
{
	int ret = 0;
	unsigned int led_en;

	led_en = *(unsigned int *) data;

	pmic_set_register_value(PMIC_CHRIND_MODE, 0x2); /* register mode */
	pmic_set_register_value(PMIC_CHRIND_EN_SEL, !led_en); /* 0: Auto, 1: SW */
	pmic_set_register_value(PMIC_CHRIND_EN, led_en);

	return ret;
}

static unsigned int charging_get_ibus(void *data)
{
	return -ENOTSUPP;
}

static unsigned int charging_get_vbus(void *data)
{
	return -ENOTSUPP;
}

static unsigned int charging_reset_dc_watch_dog_timer(void *data)
{
	return -ENOTSUPP;
}

static unsigned int charging_run_aicl(void *data)
{
	return -ENOTSUPP;
}

static unsigned int charging_set_ircmp_resistor(void *data)
{
	return 0;
}

static unsigned int charging_set_ircmp_volt_clamp(void *data)
{

	return 0;
}

 static unsigned int (* const charging_func[CHARGING_CMD_NUMBER])(void *data)=
 {
 	  charging_hw_init
	,charging_dump_register
	,charging_enable
	,charging_set_cv_voltage
	,charging_get_current
	,charging_set_current
	,charging_set_input_current
	,charging_get_charging_status
	,charging_reset_watch_dog_timer
	,charging_set_hv_threshold
	,charging_get_hv_status
	,charging_get_battery_status
	,charging_get_charger_det_status
	,charging_get_charger_type
	,charging_get_is_pcm_timer_trigger
	,charging_set_platform_reset
	,charging_get_platfrom_boot_mode
	,charging_set_power_off
    ,charging_get_power_source
	,charging_get_csdac_full_flag
	,charging_set_ta_current_pattern
	,charging_set_error_state
	,charging_diso_init
	,charging_get_diso_state
	,charging_set_vindpm
	,charging_set_vbus_ovp_en
	,charging_get_bif_vbat 
	,charging_set_chrind_ck_pdn 
	,charging_sw_init 
	,charging_enable_safetytimer
	,charging_set_hiz_swchr 
	,charging_get_bif_tbat
	,charging_set_ta20_reset
	,charging_set_ta20_current_pattern
    ,charging_set_dp
	,charging_get_charger_temperature
	,charging_set_boost_current_limit
	,charging_enable_otg
	,charging_enable_power_path
	,charging_get_bif_is_exist
	,charging_get_input_current
	,charging_enable_direct_charge
	,charging_get_is_power_path_enable
	,charging_get_is_safetytimer_enable
	,charging_set_pwrstat_led_en
	,charging_get_ibus, charging_get_vbus
	,charging_reset_dc_watch_dog_timer
	,charging_run_aicl
	,charging_set_ircmp_resistor
	,charging_set_ircmp_volt_clamp
 };

 
 /*
 * FUNCTION
 *		Internal_chr_control_handler
 *
 * DESCRIPTION															 
 *		 This function is called to set the charger hw
 *
 * CALLS  
 *
 * PARAMETERS
 *		None
 *	 
 * RETURNS
 *		
 *
 * GLOBALS AFFECTED
 *	   None
 */
 signed int chr_control_interface(CHARGING_CTRL_CMD cmd, void *data)
 {
	 unsigned int status;
	 if(cmd < CHARGING_CMD_NUMBER)
		 status = charging_func[cmd](data);
	 else
		 return STATUS_UNSUPPORTED;
 
	 return status;
 }


