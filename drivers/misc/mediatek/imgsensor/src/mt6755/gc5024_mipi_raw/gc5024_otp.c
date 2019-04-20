#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/slab.h>
#include <asm/atomic.h>
#include <linux/types.h>

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"
#include "gc5024mipi_Sensor.h"

#include "agold_camera_info.h"

#define LOG_INF(format, args...)	printk("[%s] " format, __FUNCTION__, ##args)




#define RG_TYPICAL    			0x0090
#define BG_TYPICAL				0x0095
#define INFO_ROM_START			0x08
#define INFO_WIDTH       		0x07
#define WB_ROM_START           	0x78
#define WB_WIDTH         		0x02



extern int g_cur_cam_sensor;

extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);
extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);

static unsigned char GC5024_WRITE_ID = 0X00;


static struct otp_info{
	kal_uint16 module_id;
	kal_uint16 lens_id;
	kal_uint16 vcm_id;
	kal_uint16 vcm_driver_id;
	kal_uint16 year;
	kal_uint16 month;
	kal_uint16 day;
	kal_uint16 rg_gain;
	kal_uint16 bg_gain;
	kal_uint16 wb_flag;// 0:Empty 1:Success 2:Invalid	
}otp_info;


typedef enum{
	otp_close=0,
	otp_open,
}otp_state;



static void gc5024_write_cmos_sensor(kal_uint16 addr, kal_uint16 para)
{

        char pu_send_cmd[2] = {(char)(addr & 0xFF), (char)(para & 0xFF)};
		iWriteRegI2C(pu_send_cmd, 2, GC5024_WRITE_ID);
}



static kal_uint16 gc5024_read_cmos_sensor(kal_uint16 addr)
{

    kal_uint16 get_byte=0;

	char pu_send_cmd[1] = {(char)(addr & 0xFF) };
	iReadRegI2C(pu_send_cmd, 1, (u8*)&get_byte, 1, GC5024_WRITE_ID);
 
    return get_byte;
}


static kal_uint8 gc5024_read_otp(kal_uint8 addr)
{
	kal_uint8 value;

	gc5024_write_cmos_sensor(0xfe,0x00);
	gc5024_write_cmos_sensor(0xd5,addr);
	mdelay(5);
	gc5024_write_cmos_sensor(0xf3,0x20);
	
	value = gc5024_read_cmos_sensor(0xd7);

	return value;
}


void gc5024_read_otp_info(void)
{
	kal_uint8 flag;
	kal_uint8 index;
	kal_uint8 info_start_add,wb_start_add;

	flag = gc5024_read_otp(0x00);
    LOG_INF("gc5024 otp_flag = 0x%x\n",flag);
//INFO&WB
	for(index=0;index<2;index++)
	{
		switch((flag>>(4 + 2 * index))&0x03)
		{
		case 0x00:
			LOG_INF("GC5024_OTP_INFO group%d is Empty !!\n", index + 1);
			break;
		case 0x01:
			info_start_add = INFO_ROM_START + index * INFO_WIDTH*8;
			otp_info.module_id = gc5024_read_otp(info_start_add);
			otp_info.lens_id = gc5024_read_otp(info_start_add + 8*1); 
			otp_info.vcm_driver_id = gc5024_read_otp(info_start_add + 8*2);
			otp_info.vcm_id = gc5024_read_otp(info_start_add + 8*3);
			otp_info.year = gc5024_read_otp(info_start_add + 8*4);
			otp_info.month = gc5024_read_otp(info_start_add + 8*5);
			otp_info.day = gc5024_read_otp(info_start_add + 8*6);
			break;
		case 0x02:
			LOG_INF("GC5024_OTP_INFO group%d is Invalid !!\n", index + 1);
			break;
		default :
			break;
		}
		
		switch((flag>>(2 * index))&0x03)
		{
		case 0x00:
			LOG_INF("GC5024_OTP_WB group%d is Empty !!\n", index + 1);
			otp_info.wb_flag = otp_info.wb_flag|0x00;
			break;
		case 0x01:
			LOG_INF("GC5024_OTP_WB group%d is Valid !!\n", index + 1);						
			wb_start_add = WB_ROM_START + index * WB_WIDTH*8;
			otp_info.rg_gain = gc5024_read_otp(wb_start_add);
			otp_info.bg_gain = gc5024_read_otp(wb_start_add + 1*8); 
			otp_info.wb_flag = otp_info.wb_flag|0x01;
			break;
		case 0x02:
			LOG_INF("GC5024_OTP_WB group%d is Invalid !!\n", index + 1);			
			otp_info.wb_flag = otp_info.wb_flag|0x02;
			break;
		default :
			break;
		}
	}

	/*print otp information*/
	LOG_INF("GC5024_OTP_INFO:module_id=0x%x\n",otp_info.module_id);
	LOG_INF("GC5024_OTP_INFO:lens_id=0x%x\n",otp_info.lens_id);
	LOG_INF("GC5024_OTP_INFO:vcm_id=0x%x\n",otp_info.vcm_id);
	LOG_INF("GC5024_OTP_INFO:vcm_driver_id=0x%x\n",otp_info.vcm_driver_id);
	LOG_INF("GC5024_OTP_INFO:data=%d-%d-%d\n",otp_info.year,otp_info.month,otp_info.day);
	LOG_INF("GC5024_OTP_WB:r/g=0x%x\n",otp_info.rg_gain);
	LOG_INF("GC5024_OTP_WB:b/g=0x%x\n",otp_info.bg_gain);
	
}


static void gc5024_update_awb(void)
{
	kal_uint16 r_gain_current = 0 , g_gain_current = 0 , b_gain_current = 0 , base_gain = 0;
	kal_uint16 r_gain = 128 , g_gain = 128 , b_gain = 128 ;
	if( otp_info.rg_gain || otp_info.bg_gain )
	{ 
	    r_gain_current = 0x80 * RG_TYPICAL /otp_info.rg_gain;
	    b_gain_current = 0x80 * BG_TYPICAL/otp_info.bg_gain;
	    g_gain_current = 0x80;
	
	    base_gain = (r_gain_current<b_gain_current) ? r_gain_current : b_gain_current;
	    base_gain = (base_gain<g_gain_current) ? base_gain : g_gain_current;
	    LOG_INF("GC5024_OTP_UPDATE_AWB:r_gain_current = 0x%x , b_gain_current = 0x%x , base_gain = 0x%x \n",r_gain_current,b_gain_current,base_gain);
	
	    r_gain = 0x80 * r_gain_current / base_gain;
	    g_gain = 0x80 * g_gain_current / base_gain;
	    b_gain = 0x80 * b_gain_current / base_gain;
	    LOG_INF("GC5024_OTP_UPDATE_AWB:r_gain = 0x%x , g_gain = 0x%x , b_gain = 0x%x \n",r_gain,g_gain,b_gain);

	    /*TODO*/
	    if(0x01==(otp_info.wb_flag&0x01))
	    {
		    gc5024_write_cmos_sensor(0xfe,0x00);
		    gc5024_write_cmos_sensor(0xb9,g_gain);
		    gc5024_write_cmos_sensor(0xbb,r_gain);
		    gc5024_write_cmos_sensor(0xbd,b_gain);
		    gc5024_write_cmos_sensor(0xbf,g_gain);
   	    }
    }
    
}

void gc5024_update_otp(void)
{
	gc5024_update_awb();	
}

static void gc5024_enable_otp(otp_state state)
{
	kal_uint8 otp_clk,otp_en;
	gc5024_write_cmos_sensor(0xf7,0x01);
	gc5024_write_cmos_sensor(0xf9,0xae);
	gc5024_write_cmos_sensor(0xfc,0xae);
	otp_clk = gc5024_read_cmos_sensor(0xfa);
	otp_en= gc5024_read_cmos_sensor(0xd4);	
	if(state)	
	{ 
		otp_clk = otp_clk | 0x10;
		otp_en = otp_en | 0x80;
		mdelay(5);
		gc5024_write_cmos_sensor(0xfa,otp_clk);	// 0xfa[6]:OTP_CLK_en
		gc5024_write_cmos_sensor(0xd4,otp_en);	// 0xd4[7]:OTP_en	
	    otp_clk = gc5024_read_cmos_sensor(0xfa);
	    otp_en = gc5024_read_cmos_sensor(0xd4);
		LOG_INF("GC5024_OTP: Enable OTP!\n");		
	}
	else			
	{
		otp_en = otp_en & 0x7f;
		otp_clk = otp_clk & 0xef;
		mdelay(5);
		gc5024_write_cmos_sensor(0xd4,otp_en);
		gc5024_write_cmos_sensor(0xfa,otp_clk);

		LOG_INF("GC5024_OTP: Disable OTP!\n");
	}
}

void GC5024CheckLensVersion(kal_uint8  write_id)
{	
    static kal_uint8 check_flag = 0;
    
    GC5024_WRITE_ID = write_id;
 
    LOG_INF("GC5024CheckLensVersion enter! write_id = 0x%x\n",write_id);   
    gc5024_enable_otp(otp_open);
    

    if(!check_flag)
    {
    LOG_INF("zbl read gc5024 otp data\n");
        gc5024_read_otp_info();
        check_flag = 1;
    }
    
	gc5024_enable_otp(otp_close);
    agold_camera_info[g_cur_cam_sensor-1].mf_id = otp_info.module_id;
	agold_camera_info[g_cur_cam_sensor-1].lens_id = otp_info.lens_id;
	agold_camera_info[g_cur_cam_sensor-1].sen_id = otp_info.vcm_id;
}









































