#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include "kd_camera_hw.h"
#include "cam_cal.h"
#include "cam_cal_define.h"
#include "imx214otp.h"
//#include <asm/system.h>  // for SMP
#include <linux/dma-mapping.h>

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h" 
#include "kd_imgsensor_errcode.h"

static kal_uint8 g_imx214mipi_write_id = 0x0;  //i2c address 


// add by Suny , for IMX214  otp
// ++
extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);
#define IMX214MIPI_write_cmos_sensor(addr, para) iWriteReg((u16) addr , (u32) para , 1, g_imx214mipi_write_id)
#define SENSORDB(fmt, arg...) printk( "[IMX214MIPIRaw] "  fmt, ##arg)
static kal_uint16 IMX214MIPI_read_cmos_sensor(kal_uint32 addr)
{
	kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,g_imx214mipi_write_id);
    return get_byte;
}


#define  IMX214_OTP_SUPPORT
#ifdef IMX214_OTP_SUPPORT
//read otp data by the given page
//tempbank:the first group for read
//address:the first address for read
//iBuffer:the return data buffer
//buffersize: buffer size

static kal_bool IMX214MIPI_ReadOtp(int tempbank,kal_uint16 address,kal_uint8* iBuffer,int buffersize)
{
	kal_uint16 reVal;
	kal_uint16 reg;
	int i = 0;
	int k = 0;
	printk("%s\n",__func__);
	while (k<buffersize)
	{
		i=0;
		IMX214MIPI_write_cmos_sensor(0x0A02, tempbank);
		IMX214MIPI_write_cmos_sensor(0x0A00, 0x01);
		msleep(100);
		reg = IMX214MIPI_read_cmos_sensor(0x0A01);
		if ((reg & 0x01) ==0x01)
		{
			printk("read otp failed!\n");
		}
		else
		{
			printk("read otp success!\n");
			return KAL_FALSE;
		}

		while(i<64)
		{
			reVal = IMX214MIPI_read_cmos_sensor(address+i);
			*(iBuffer+k) = reVal;
			i++;
			k++;
			if (k>=buffersize)
			{
				break;
			}
		}
		tempbank++;
	}

	return KAL_TRUE;
}
											//ljj  start
#if defined(AGOLD_CAMERA_VERSION)

#include "agold_camera_info.h"

#define BG_Ratio_Typical_Value  cur_bg_ratio
#define RG_Ratio_Typical_Value  cur_rg_ratio
#else
#define BG_Ratio_Typical_Value 0x269
#define RG_Ratio_Typical_Value 0x275
#endif

static void TestAWBforIMX214(kal_uint16 RoverG_dec,kal_uint16 BoverG_dec,kal_uint16 GboverGr_dec)
{
	kal_uint16 RoverG_dec_base,BoverG_dec_base;//GboverGr_dec_base;			
	kal_uint16 R_test,B_test,G_test;
	kal_uint16 R_test_H3,R_test_L8,B_test_H3,B_test_L8,G_test_H3,G_test_L8;
	kal_uint32 G_test_R, G_test_B;
#if defined (AGOLD_CAMERA_VERSION)	//Add by Lancelot 2014-06-10
	BG_Ratio_Typical_Value=agold_get_bg_ratio(g_cur_cam_sensor-1);
	RG_Ratio_Typical_Value=agold_get_rg_ratio(g_cur_cam_sensor-1);
#endif		
	RoverG_dec_base = RG_Ratio_Typical_Value;//the typcical value			
	BoverG_dec_base = BG_Ratio_Typical_Value;//the typcical value			
	//GboverGr_dec_base = ;//the typcical value					//ljj end
	SENSORDB("[ljj] g_cur_cam_sensor = 0x%x\n",g_cur_cam_sensor);
	SENSORDB("[ljj] RoverG_dec_base = 0x%x\n",RoverG_dec_base);
	SENSORDB("[ljj] BoverG_dec_base = 0x%x\n",BoverG_dec_base);
	
	
	
	if(BoverG_dec < BoverG_dec_base)
	{
		if (RoverG_dec < RoverG_dec_base)
		{
			G_test = 0x100;
			B_test = 0x100 * BoverG_dec_base / BoverG_dec;
			R_test = 0x100 * RoverG_dec_base / RoverG_dec;
		}
		else
		{
			R_test = 0x100;
			G_test = 0x100 * RoverG_dec / RoverG_dec_base;
			B_test = G_test * BoverG_dec_base / BoverG_dec;
		}
	}
	else
	{
		if (RoverG_dec < RoverG_dec_base)
		{
			B_test = 0x100;
			G_test = 0x100 * BoverG_dec / BoverG_dec_base;
			R_test = G_test * RoverG_dec_base / RoverG_dec;
		}
		else
		{
			G_test_B = BoverG_dec * 0x100 / BoverG_dec_base;
			G_test_R = RoverG_dec * 0x100 / RoverG_dec_base;
			if(G_test_B > G_test_R )
			{
				B_test = 0x100;
				G_test = G_test_B;
				R_test = G_test_B * RoverG_dec_base / RoverG_dec;
			}
			else
			{
				R_test = 0x100;
				G_test = G_test_R;
				B_test = G_test_R * BoverG_dec_base / BoverG_dec;
			}
		}
	}
	if(R_test < 0x100)
	{
		R_test = 0x100;
	}
	if(G_test < 0x100)
	{
		G_test = 0x100;
	}
	if(B_test < 0x100)
	{
		B_test = 0x100;
	}
	R_test_H3 =( R_test>>8)&0x0F;
	R_test_L8 = R_test &0xFF;
	B_test_H3 = (B_test>>8)&0x0F;
	B_test_L8 = B_test &0xFF;
	G_test_H3 = (G_test>>8)&0x0F;
	G_test_L8 = G_test &0xFF;
	
	//reset the digital gain
	IMX214MIPI_write_cmos_sensor(0x020F,G_test_L8);
	IMX214MIPI_write_cmos_sensor(0x0211,R_test_L8);
	IMX214MIPI_write_cmos_sensor(0x0213,B_test_L8);
	IMX214MIPI_write_cmos_sensor(0x0215,G_test_L8);
	
	SENSORDB("R_test=0x%x,G_test=0x%x,B_test=0x%x",R_test,G_test,B_test);
}


//read module information and awb data
kal_bool IMX214MIPI_ReadIDFromOtp(kal_uint8 i2c_write_id)
{
	kal_uint16 awbGroupbank[] = {0x00,0x01,0x02};//the three fist group for AWB data
	kal_uint16 address = 0x0A04;
//	kal_uint16 MID = 0x01;
	//kal_uint16 r,g;
	int i;
	kal_uint8 Temp[42]={0};
	kal_uint16 temp3;
	int index = -1;
	
	int tempbank = 0; 
	g_imx214mipi_write_id = i2c_write_id;
	printk("[ljj] g_imx214mipi_write_id = 0x%x \n",g_imx214mipi_write_id);


	//1.check valid group
	for(i=0;i<3;i++)
	{
		//select OTP page address for read
		IMX214MIPI_write_cmos_sensor(0x0A02,awbGroupbank[i]);//select page
		//turn on OTP read mode
		IMX214MIPI_write_cmos_sensor(0x0A00,0x01);//read mode:0x0A00 = 0x01 
		//check status(bit0:0x01 read ready)
		temp3 = IMX214MIPI_read_cmos_sensor(0x0A01);//Status check : 0x0A01 = 0x01 (bit0 1:read ready)
		if ((temp3&0x01) ==0x01)
		{
			printk("read OTP AWB successfully !\n");
		}
		else
		{	
			printk("[ljj] temp3 = 0x%x\n",temp3);
			//return KAL_FALSE;
		}
		
		//0x0A04-0x0A43 are the register address area for each page
		//check program flag by read ox0A04
		temp3 = IMX214MIPI_read_cmos_sensor(0x0A04);
		//program flag is not zero,the current group is valid
		if (temp3==1)
		{
			index = i;
			printk("[fj],index = %d\n",index);
			break;
		}
	}
	if (index == -1)
	{
		printk("OTP flag is all 0\n");
		return KAL_FALSE;
	}
	tempbank = awbGroupbank[index];
	//2.read data from the valid group
	
	if(KAL_FALSE == IMX214MIPI_ReadOtp(tempbank,address,Temp,42))
	{
		printk("read otp failed! \n");
		return KAL_FALSE;
	}
	
	//3.check sum
/*	kal_uint16 sum=0;
	for(i=2;i<42;i++)
	{

		sum = sum + Temp[i];
	}
	if (Temp[1] != (sum%255)+1)
	{
		SENSORDB("OTP AWB DATA ERROR");
		return KAL_FALSE;
	}
*/	
	//4.check module information
	printk("[IMX214][ljj] g_cur_cam_sensor=%d\n", g_cur_cam_sensor);
	if(g_cur_cam_sensor==1 || g_cur_cam_sensor ==2)
	{
		//OTP MAGIC
		index++;
		agold_camera_info[g_cur_cam_sensor-1].otp_magic = index;
		agold_camera_info[g_cur_cam_sensor-1].otp_magic = (agold_camera_info[g_cur_cam_sensor-1].otp_magic << 4) | index;

        #ifdef AGOLD_IMX214_OTPMAP_TYPE1 
		agold_camera_info[g_cur_cam_sensor-1].mf_id   = Temp[1];	//0x0A05 
		agold_camera_info[g_cur_cam_sensor-1].lens_id = Temp[2];	//0x0A06
		agold_camera_info[g_cur_cam_sensor-1].sen_id = Temp[10];	//0x0A0E
		#elif defined AGOLD_IMX214_OTPMAP_TYPE2
		agold_camera_info[g_cur_cam_sensor-1].mf_id   = Temp[1];	//0x0A05 
		agold_camera_info[g_cur_cam_sensor-1].lens_id = Temp[5];	//0x0A09
		agold_camera_info[g_cur_cam_sensor-1].sen_id = Temp[6];	    //0x0A0A
		#else
		//OTP M-ID Lens-ID  Soft-ID  , date: year, month, day	
		agold_camera_info[g_cur_cam_sensor-1].date[0] = Temp[3];	//0x0A07 
		agold_camera_info[g_cur_cam_sensor-1].date[1] = Temp[4];	//0x0A08 
		agold_camera_info[g_cur_cam_sensor-1].date[2] = Temp[5];	//0x0A09 
		agold_camera_info[g_cur_cam_sensor-1].mf_id   = Temp[6];	//0x0A0A 
		agold_camera_info[g_cur_cam_sensor-1].lens_id = Temp[7];	//0x0A0B 
		agold_camera_info[g_cur_cam_sensor-1].sen_id = Temp[9];		//0x0A0D
        #endif
		printk("[IMX214][ljj]otp_log read mf_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].mf_id);
		printk("[IMX214][ljj]otp_log read lens_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].lens_id);		
		printk("[dafa]otp_log read sen_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].sen_id);
	
	}

	return KAL_TRUE;
}


//read module information and awb data
 kal_bool IMX214MIPI_ReadAWBFromOtp(void)
{
	kal_uint16 awbGroupbank[] = {0x00,0x01,0x02};//the three fist group for AWB data
	kal_uint16 address = 0x0A04;
//	kal_uint16 MID = 0x01;
	kal_uint16 r=0,g=0,b=0;
	int i;
	kal_uint8 Temp[42]={0};
	kal_uint16 temp3;
	int index = -1;
	
	int tempbank = awbGroupbank[index];
	//1.check valid group
	for(i=0;i<3;i++)
	{
		//select OTP page address for read
		IMX214MIPI_write_cmos_sensor(0x0A02,awbGroupbank[i]);//select page
		//turn on OTP read mode
		IMX214MIPI_write_cmos_sensor(0x0A00,0x01);//read mode:0x0A00 = 0x01 
		//check status(bit0:0x01 read ready)
		temp3 = IMX214MIPI_read_cmos_sensor(0x0A01);//Status check : 0x0A01 = 0x01 (bit0 1:read ready)
		if ((temp3&0x01) ==0x01)
		{
			SENSORDB("read OTP AWB successfully !\n");
		}
		else
		{
			SENSORDB("read OTP AWB fail !\n");
			SENSORDB("[ljj] temp3 = 0x%x\n",temp3);
			//return KAL_FALSE;
		}
		
		//0x0A04-0x0A43 are the register address area for each page
		//check program flag by read ox0A04
		temp3 = IMX214MIPI_read_cmos_sensor(0x0A04);
		//program flag is not zero,the current group is valid
		if (temp3==1)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		SENSORDB("OTP flag is all 0\n");
		return KAL_FALSE;
	}
	
	//2.read data from the valid group
	
	if(KAL_FALSE == IMX214MIPI_ReadOtp(tempbank,address,Temp,42))
	{
		SENSORDB("read otp failed! \n");
		return KAL_FALSE;
	}
	
	//3.check sum
/*	kal_uint16 sum=0;
	for(i=2;i<42;i++)
	{
		sum = sum + Temp[i];
	}
	if (Temp[1] != (sum%255)+1)
	{
		SENSORDB("OTP AWB DATA ERROR");
		return KAL_FALSE;
	}
*/	
	//4.check module information
	printk("[IMX214][ljj] g_cur_cam_sensor=%d\n", g_cur_cam_sensor);
	
	//4.get awb data
	#ifdef AGOLD_IMX214_OTPMAP_TYPE1
	r = (Temp[3]<<8)|Temp[4];
	b = (Temp[5]<<8)|Temp[6];

	#elif defined AGOLD_IMX214_OTPMAP_TYPE2
	r = (Temp[9]<<8)|Temp[10];
	b = (Temp[11]<<8)|Temp[12];
	
	#else
	r = (Temp[15]<<8)|Temp[16];
	b = (Temp[17]<<8)|Temp[18];
	g = (Temp[19]<<8)|Temp[20];
	#endif
	SENSORDB("mid=0x%x",Temp[6]);
	SENSORDB("r=0x%x,g=0x%x,b=0x%x",r,g,b);
	
	//5.set new digital gain value
	TestAWBforIMX214(r,b,g);
	return KAL_TRUE;
}


//read AF data
/*
static kal_bool IMX214MIPI_ReadAFFromOtp()
{
	kal_uint16 AFGroupbank[] = {0x0B,0x0A,0x09};//the three fist group for AF data
	kal_uint16 address=0x0A04;
	int i;
	kal_uint8 Temp[32]={0};
	kal_uint16 temp3,temp4;
	int index = -1;
	
	//1.check valid group
	for(i=0;i<3;i++)
	{
		//select OTP page address for read
		IMX214MIPI_write_cmos_sensor(0x0A02,AFGroupbank[i]);//select page
		//turn on OTP read mode
		IMX214MIPI_write_cmos_sensor(0x0A00,0x01);//read mode:0x0A00 = 0x01 
		//check status(bit0:0x01 read ready)
		temp3 = IMX214MIPI_read_cmos_sensor(0x0A01);//Status check : 0x0A01 = 0x01 (bit0 1:read ready)
		if ((temp3&0x01) ==0x01)
		{
			SENSORDB("Read OTP AWB ok !\n");//ÏÔÊŸ
		}
		else
		{
			SENSORDB("Read OTP AWB error!");
			return KAL_FALSE;
		}
		
		//0x0A04-0x0A43 are the register address area for each page
		//check program flag by read ox0A04
		temp3 = IMX214MIPI_read_cmos_sensor(0x0A04);
		temp4 = IMX214MIPI_read_cmos_sensor(0x0A14);
		//program flag is not zero,the current group is valid
		if (temp3==1&&temp4==1)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		SENSORDB("not exsit AF data");
		return KAL_FALSE;
	}
	
	//2.read AF  Macro data from the valid group
	int tempbank = AFGroupbank[index];
	if(KAL_FALSE == IMX214MIPI_ReadOtp(tempbank,address,Temp,32))
	{
		SENSORDB("I2C ERROR when reading Otp");
		return KAL_FALSE;
	}
	
	//3.check sum of Macro
	kal_uint16 sum=0;
	for(i=2;i<7;i++)
	{
		sum = sum + Temp[i];
	}
	if (Temp[1] != (sum%255)+1)
	{
		SENSORDB("AF Macro data error");
		return KAL_FALSE;
	}
	
	//4.check sum of Infinity
	kal_uint16 sum1=0;
	for(i=18;i<23;i++)
	{
		sum1 = sum1 + Temp[i];
	}
	if (Temp[17] != (sum1%255)+1)
	{
		SENSORDB("AF Infinity data error");
		return KAL_FALSE;
	}

	return KAL_TRUE;
}
*/

#endif
