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
//#include <asm/system.h>  // for SMP
#include <linux/dma-mapping.h>

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"

static kal_uint8 imx219mipi_write_id = 0x0;  //i2c address


// add by Suny , for IMX219  otp
// ++
extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);
#define IMX219MIPI_write_cmos_sensor(addr, para) iWriteReg((u16) addr , (u32) para , 1, imx219mipi_write_id)
#define SENSORDB(fmt, arg...) printk( "[IMX219MIPIRaw] "  fmt, ##arg)
static kal_uint16 IMX219MIPI_read_cmos_sensor(kal_uint32 addr)
{
	kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,imx219mipi_write_id);
    return get_byte;
}


#define  IMX219_OTP_SUPPORT
#ifdef IMX219_OTP_SUPPORT
//read otp data by the given page
//tempbank:the first group for read
//address:the first address for read
//iBuffer:the return data buffer
//buffersize: buffer size

/*static kal_bool IMX219MIPI_ReadOtp(int tempbank,kal_uint16 address,kal_uint8* iBuffer,int buffersize)
{
	kal_uint16 reVal;
	kal_uint16 reg;
	int i = 0;
	int k = 0;
	while (k<buffersize)
	{
		i=0;
		IMX219MIPI_write_cmos_sensor(0x3202, tempbank);
		IMX219MIPI_write_cmos_sensor(0x3200, 0x01);
		msleep(100);
		reg = IMX219MIPI_read_cmos_sensor(0x3201);
		if ((reg & 0x01) ==0x01)
		{
			SENSORDB("read otp failed!\n");
		}
		else
		{
			SENSORDB("read otp success!\n");
			return KAL_FALSE;
		}

		while(i<64)
		{
			reVal = IMX219MIPI_read_cmos_sensor(address+i);
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
	*/										//ljj  start
#if defined(CONFIG_MTK_CAMERA_VERSION)

#include "agold_camera_info.h"

#define BG_Ratio_Typical_Value  cur_bg_ratio
#define RG_Ratio_Typical_Value  cur_rg_ratio
#else
#define BG_Ratio_Typical_Value 0x15f
#define RG_Ratio_Typical_Value 0x175
#endif



//read module information and awb data
kal_bool IMX219MIPI_ReadIDFromOtp(kal_uint8 i2c_write_id)
{

//	kal_uint16 MID = 0x01;
	int i;
	//kal_uint8 Temp[22]={0};
	kal_uint16 flag;
	//int retVal,index = 0;
	int temp;

	imx219mipi_write_id = i2c_write_id;
	SENSORDB("[fj] imx219mipi_write_id = 0x%x \n",imx219mipi_write_id);
    IMX219MIPI_write_cmos_sensor(0x0100,0x00);
	msleep(5);
	//1.check valid group

	//turn on OTP read mode
	IMX219MIPI_write_cmos_sensor(0x3302,0x01);
	IMX219MIPI_write_cmos_sensor(0x3303,0x2C);
	IMX219MIPI_write_cmos_sensor(0x012A,0x0C);
	IMX219MIPI_write_cmos_sensor(0x021B,0x00);
	IMX219MIPI_write_cmos_sensor(0x3300,0x00);
	IMX219MIPI_write_cmos_sensor(0x3200,0x01);


	flag = IMX219MIPI_read_cmos_sensor(0x3201);//Status check : 0x0A01 = 0x01 (bit0 1:read ready)
	if ((flag&0x01) ==0x01)
	{
	    SENSORDB("[fj] read ready flag =0x%x\n",flag);
	}
	else
	{
		SENSORDB("[fj] flag = 0x%x\n",flag);//bit1 1:write ready,  bit2 0:normal 1:data error exists
		return KAL_FALSE;
	}
	//select OTP page address for read
	IMX219MIPI_write_cmos_sensor(0x3202,0x00);//select page
	//check status(bit0:0x01 read ready)

    //4.check module information
    SENSORDB("[IMX219][fj] g_cur_cam_sensor=%d\n", g_cur_cam_sensor);
    if(g_cur_cam_sensor==1 || g_cur_cam_sensor ==2)
    {
		for(temp = 0; temp < 3; temp++)
		{
			flag = IMX219MIPI_read_cmos_sensor(0x3204 + temp*9);
			if((flag&0x03) == 0x01)
			{
				printk("[fj],group %d is valid\n",temp+1);
				break;
			}else if((flag&0x03) == 0x00){
				printk("[fj],group %d is empty\n",temp+1);
			}else{
				printk("[fj],group %d is invalid\n",temp+1);
			}

		 }
         printk("[fj],group +++++++++++=%d\n",temp+1);

	    agold_camera_info[g_cur_cam_sensor-1].mf_id   = IMX219MIPI_read_cmos_sensor(0x3205+temp*9);	//0x3205 0x320e 0x3217
	    agold_camera_info[g_cur_cam_sensor-1].lens_id = IMX219MIPI_read_cmos_sensor(0x3206+temp*9);	//0x3206 0x320f 0x3218
        //agold_camera_info[g_cur_cam_sensor-1].sen_id =  IMX219MIPI_read_cmos_sensor(0x321a+(index-1)*31);
	    SENSORDB("[IMX219][fj]otp_log read mf_id,id=0x%x,addr=0x%4x\n", agold_camera_info[g_cur_cam_sensor-1].mf_id, (0x3205+temp*9));
	    SENSORDB("[IMX219][fj]otp_log read lens_id,id=0x%x,addr=0x%4x\n", agold_camera_info[g_cur_cam_sensor-1].lens_id, (0x3206+temp*9));
		for(i = 0;i< 9;i++)
		{
			SENSORDB("[IMX219][fj]id=0x%x,addr=0x%4x\n", IMX219MIPI_read_cmos_sensor(0x3205+i+temp*9), (0x3205+i+temp*9));
		}
	    //SENSORDB("[dafa]otp_log read sen_id,id=0x%2x,addr=0x%4x\n", agold_camera_info[g_cur_cam_sensor-1].sen_id, (0x321a+(index-1)*31));

    }

    return KAL_TRUE;
}

static void IMX219_update(kal_uint16 RoverG_dec,kal_uint16 BoverG_dec,kal_uint16 GboverGr_dec)
{
	kal_uint16 RoverG_dec_base,BoverG_dec_base;//GboverGr_dec_base;
	kal_uint16 R_test,B_test,G_test;
	kal_uint16 R_test_H8,R_test_L8,B_test_H8,B_test_L8,G_test_H8,G_test_L8;
	kal_uint32 G_test_R, G_test_B;
/*#if defined (CONFIG_MTK_CAMERA_VERSION)	//Add by Lancelot 2014-06-10
	BG_Ratio_Typical_Value = agold_get_bg_ratio(g_cur_cam_sensor-1);
	RG_Ratio_Typical_Value = agold_get_rg_ratio(g_cur_cam_sensor-1);
#endif
	RoverG_dec_base = RG_Ratio_Typical_Value;//the typcical value
	BoverG_dec_base = BG_Ratio_Typical_Value;//the typcical value
	//GboverGr_dec_base = ;//the typcical value					//ljj end
	*/
	RoverG_dec_base = 0x15f;//the typcical value
	BoverG_dec_base = 0x175;//the typcical value

	printk("[fj] g_cur_cam_sensor = 0x%x\n",g_cur_cam_sensor);
	printk("[fj] RoverG_dec_base = 0x%x\n",RoverG_dec_base);
	printk("[fj] BoverG_dec_base = 0x%x\n",BoverG_dec_base);
	printk("[fj],%s\n",__func__);


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
	R_test_H8 =( R_test>>8)&0xFF;
	R_test_L8 = R_test &0xFF;
	B_test_H8 = (B_test>>8)&0xFF;
	B_test_L8 = B_test &0xFF;
	G_test_H8 = (G_test>>8)&0xFF;
	G_test_L8 = G_test &0xFF;

	//reset the digital gain
	IMX219MIPI_write_cmos_sensor(0x020e,G_test_H8);
	IMX219MIPI_write_cmos_sensor(0x020F,G_test_L8);
	IMX219MIPI_write_cmos_sensor(0x0210,R_test_H8);
	IMX219MIPI_write_cmos_sensor(0x0211,R_test_L8);
	IMX219MIPI_write_cmos_sensor(0x0212,B_test_H8);
	IMX219MIPI_write_cmos_sensor(0x0213,B_test_L8);
	IMX219MIPI_write_cmos_sensor(0x0214,G_test_H8);
	IMX219MIPI_write_cmos_sensor(0x0215,G_test_L8);

	printk("R_test=0x%x,G_test=0x%x,B_test=0x%x",R_test,G_test,B_test);
}

kal_bool imx219_update_awb(kal_uint8 i2c_write_id)
{
	//kal_uint16 MID = 0x01;
	//int i;
	//kal_uint8 Temp[22]={0};
	kal_uint16 flag;
	kal_uint16 RG_MSB,BG_MSB,AWB_LSB;
	kal_uint16  RG = 0,BG = 0,GbGr = 0;
	int temp;

	imx219mipi_write_id = i2c_write_id;
	printk("[fj] imx219mipi_write_id = 0x%x \n",imx219mipi_write_id);
	printk("[fj],%s\n",__func__);
    IMX219MIPI_write_cmos_sensor(0x0100,0x00);
	msleep(5);
	//1.check valid group

	//turn on OTP read mode
	IMX219MIPI_write_cmos_sensor(0x3302,0x01);
	IMX219MIPI_write_cmos_sensor(0x3303,0x2C);
	IMX219MIPI_write_cmos_sensor(0x012A,0x0C);
	IMX219MIPI_write_cmos_sensor(0x021B,0x00);
	IMX219MIPI_write_cmos_sensor(0x3300,0x00);
	IMX219MIPI_write_cmos_sensor(0x3200,0x01);


	flag = IMX219MIPI_read_cmos_sensor(0x3201);//Status check : 0x0A01 = 0x01 (bit0 1:read ready)
	if ((flag&0x01) ==0x01)
	{
	    printk("[fj] read ready flag =0x%x\n",flag);
	}
	else
	{
		printk("[fj] flag = 0x%x\n",flag);//bit1 1:write ready,  bit2 0:normal 1:data error exists
		return KAL_FALSE;
	}
	//select OTP page address for read
	IMX219MIPI_write_cmos_sensor(0x3202,0x00);//select page
	//check status(bit0:0x01 read ready)

    //4.check module information
    printk("[IMX219][fj] g_cur_cam_sensor=%d\n", g_cur_cam_sensor);
    if(g_cur_cam_sensor==1 || g_cur_cam_sensor ==2)
    {
		for(temp = 0; temp < 3; temp++)
		{
			flag = IMX219MIPI_read_cmos_sensor(0x3204 + temp*9);
			if((flag&0x03) == 0x01)
			{
				printk("[fj],group %d is valid\n",temp+1);
				break;
			}else if((flag&0x03) == 0x00){
				printk("[fj],group %d is empty\n",temp+1);
			}else{
				printk("[fj],group %d is invalid\n",temp+1);
			}

		}
    printk("[fj],group +++++++++++=%d\n",temp+1);

	RG_MSB = IMX219MIPI_read_cmos_sensor(0x320A + temp*9);
	BG_MSB = IMX219MIPI_read_cmos_sensor(0x320B + temp*9);
	AWB_LSB = IMX219MIPI_read_cmos_sensor(0x320C + temp*9);

	RG = (RG_MSB<<2)|((AWB_LSB>>6)&0x03);
	BG = (BG_MSB<<2)|((AWB_LSB>>4)&0x03);

	printk("RG=0x%x,BG=0x%x,GbGr=0x%x",RG,BG,GbGr);
	IMX219_update(RG,BG,GbGr);

	if(temp==0)
	{
		printk("LSC one times:temp=%x",temp);
		IMX219MIPI_write_cmos_sensor(0x0190,0x01);
		IMX219MIPI_write_cmos_sensor(0x0192,0x00);
		IMX219MIPI_write_cmos_sensor(0x0191,0x00);
		IMX219MIPI_write_cmos_sensor(0x0193,0x00);
		IMX219MIPI_write_cmos_sensor(0x01a4,0x03);
	}
	else if(temp==1)
		 {
				printk("LSC two times:temp=%x",temp);
				IMX219MIPI_write_cmos_sensor(0x0190,0x01);
				IMX219MIPI_write_cmos_sensor(0x0192,0x01);
				IMX219MIPI_write_cmos_sensor(0x0191,0x00);
				IMX219MIPI_write_cmos_sensor(0x0193,0x00);
				IMX219MIPI_write_cmos_sensor(0x01a4,0x03);
		}
		else if(temp==2)
			{
				printk("LSC third times:temp=%x",temp);
				IMX219MIPI_write_cmos_sensor(0x0190,0x01);
				IMX219MIPI_write_cmos_sensor(0x0192,0x02);
				IMX219MIPI_write_cmos_sensor(0x0191,0x00);
				IMX219MIPI_write_cmos_sensor(0x0193,0x00);
				IMX219MIPI_write_cmos_sensor(0x01a4,0x03);
			}
			else
			{
				printk("LSC Fali times:temp=%x",temp);
			}


	}
	return KAL_TRUE;
}


#endif
