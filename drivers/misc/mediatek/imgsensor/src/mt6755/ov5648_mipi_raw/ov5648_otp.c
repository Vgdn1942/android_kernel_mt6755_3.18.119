#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/slab.h>
//#include <linux/xlog.h>
#include <asm/atomic.h>
#include <linux/types.h>

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"

//#include "ov5648_otp.h"

#define LOG_INF(format, args...)	printk("[%s] " format, __FUNCTION__, ##args)


extern int g_cur_cam_sensor;

extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);

static unsigned char OV5648MIPI_WRITE_ID = 0X00;
kal_uint8 bank_index=0;


struct otp_struct {
	int module_integrator_id;
	int lens_id;
	int rg_ratio;
	int bg_ratio;
	int user_data[2];
	int light_rg;
	int light_bg;
};


static kal_uint16 OV5648MIPI_write_cmos_sensor(kal_uint16 addr, kal_uint16 para)
{
		iWriteReg((u16) addr , (u32) para , 1, OV5648MIPI_WRITE_ID);
		return 1;
}


static kal_uint16 OV5648MIPI_read_cmos_sensor(kal_uint16 addr)
{
    kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,OV5648MIPI_WRITE_ID);
    return get_byte;
}

// index: index of otp group. (1, 2, 3)
// return:	0, group index is empty
// 	1, group index has invalid data
//	2, group index has valid data
static int check_otp(int index)
{
	int flag, i;
	int rg, bg;

	if (index == 1)
	{
		// read otp --Bank 0
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x00);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x0f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
		flag = OV5648MIPI_read_cmos_sensor(0x3d05);
		rg = OV5648MIPI_read_cmos_sensor(0x3d07);
		bg = OV5648MIPI_read_cmos_sensor(0x3d08);
	}
	else if (index == 2)
	{
		// read otp --Bank 0
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x00);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x0f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
		flag = OV5648MIPI_read_cmos_sensor(0x3d0e);
		// read otp --Bank 1
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x10);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x1f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
		rg = OV5648MIPI_read_cmos_sensor(0x3d00);
		bg = OV5648MIPI_read_cmos_sensor(0x3d01);
	}
	else if (index == 3)
	{
		// read otp --Bank 1
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x10);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x1f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
		flag = OV5648MIPI_read_cmos_sensor(0x3d07);
		rg = OV5648MIPI_read_cmos_sensor(0x3d09);
		bg = OV5648MIPI_read_cmos_sensor(0x3d0a);
	}
	flag = flag & 0x80;

	// clear otp buffer
	for (i=0;i<16;i++) {
		OV5648MIPI_write_cmos_sensor(0x3d00 + i, 0x00);
	}

	printk("check_otp() = 0x%x, 0x%x, 0x%x\r\n", flag, rg, bg);

	if (flag) {
	    LOG_INF("[OV5648][zl]otp bank %d is invalid \n",index);
		return 1;
	}
	else
	{
		if (rg == 0 && bg == 0)
		{
		    LOG_INF("[OV5648][zl]otp bank %d is emtpy \n",index);
			return 0;
		}
		else
		{
			return 2;
		}
	}
}



kal_uint16 OV5648MIPI_read_module_info(kal_uint16 index,kal_uint8 *data)
{
    kal_uint16 i;
//	kal_uint16 rg = 0, bg = 0;
//    OV5648MIPI_WRITE_ID = write_id;
    kal_uint8 flag=0;

	//clear otp buffer
	for(i = 0; i < 16; i++)
	{
        OV5648MIPI_write_cmos_sensor(0x3d00 + i, 0x00);
	}

  if(index == 1) //Group 1
    {
    	//read otp bank 0
        OV5648MIPI_write_cmos_sensor(0x3d84,0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85,0x00); //OTP start address, bank 0
		OV5648MIPI_write_cmos_sensor(0x3d86,0x0f); //OTP end address
	    OV5648MIPI_write_cmos_sensor(0x3d81,0x01); //OTP Read Enable

		msleep(5); // delay 50ms
        data[0] = OV5648MIPI_read_cmos_sensor(0x3d05);
        data[1] = OV5648MIPI_read_cmos_sensor(0x3d06);
		data[2] = OV5648MIPI_read_cmos_sensor(0x3d09);
		//rg = (OV5648MIPI_read_cmos_sensor(0x3d0a) << 8) + OV5648MIPI_read_cmos_sensor(0x3d0b);
		//bg = (OV5648MIPI_read_cmos_sensor(0x3d0c) << 8) + OV5648MIPI_read_cmos_sensor(0x3d0d);
    }
     else if(index == 2)  //Group 2
    {
    	//read otp bank 1
        OV5648MIPI_write_cmos_sensor(0x3d84,0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85,0x00); //OTP start address, bank 0
		OV5648MIPI_write_cmos_sensor(0x3d86,0x0f); //OTP end address
	    OV5648MIPI_write_cmos_sensor(0x3d81,0x01); //OTP Read Enable

		msleep(5); // delay 50ms
		data[0] = OV5648MIPI_read_cmos_sensor(0x3d0e);
        data[1] = OV5648MIPI_read_cmos_sensor(0x3d0f);

        OV5648MIPI_write_cmos_sensor(0x3d84,0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85,0x10); //OTP start address, bank 1
		OV5648MIPI_write_cmos_sensor(0x3d86,0x1f); //OTP end address
	    OV5648MIPI_write_cmos_sensor(0x3d81,0x01); //OTP Read Enable
	    msleep(5);
		data[2] = OV5648MIPI_read_cmos_sensor(0x3d02);
		//rg = (OV5648MIPI_read_cmos_sensor(0x3d07) << 8) + OV5648MIPI_read_cmos_sensor(0x3d08);
		//bg = (OV5648MIPI_read_cmos_sensor(0x3d09) << 8) + OV5648MIPI_read_cmos_sensor(0x3d0a);
    }
    else if(index == 3) //Group 3
    {
    	//read otp bank 0
        OV5648MIPI_write_cmos_sensor(0x3d84,0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85,0x10); //OTP start address, bank 0
		OV5648MIPI_write_cmos_sensor(0x3d86,0x1f); //OTP end address
	    OV5648MIPI_write_cmos_sensor(0x3d81,0x01); //OTP Read Enable

		msleep(50); // delay 50ms
        data[0] = OV5648MIPI_read_cmos_sensor(0x3d07);
        data[1] = OV5648MIPI_read_cmos_sensor(0x3d08);
        data[2] = OV5648MIPI_read_cmos_sensor(0x3d0b);
		//rg = (OV5648MIPI_read_cmos_sensor(0x3d07) << 8) + OV5648MIPI_read_cmos_sensor(0x3d0b);
		//bg = (OV5648MIPI_read_cmos_sensor(0x3d0c) << 8) + OV5648MIPI_read_cmos_sensor(0x3d0d);
    }
	else
	{
        LOG_INF("invalid index!");
        return 0;
	}



	//disable otp read
	OV5648MIPI_write_cmos_sensor(0x3d81,0x00);

	//clear otp buffer
	for(i=0; i<16; i++)
	{
        OV5648MIPI_write_cmos_sensor(0x3d00 + i, 0x00);
	}

	LOG_INF("[OV5648][zl]otp moudule_id:0x%x \n",data[0]);

	flag=data[0]&0x80;
	if (flag==0x80)
	{
	LOG_INF("[OV5648][zl]otp bank %d is invalid \n",index);
	return 0;
	}
	else if(data[0]==0)
	{
	LOG_INF("[OV5648][zl]otp bank %d is emtpy \n",index);
	return 0;
	}
	else
	{
    LOG_INF("[OV5648][zl]otp_log read mf_id, %d ,id=0x%2x\n", index ,data[0]&0x7f);
    data[0] &= 0x7f;
    return 1;
    }
}

// index: index of otp group. (1, 2, 3)
// return:	0,
static int read_otp(int index, struct otp_struct *otp_ptr)
{
	int i, temp;

	// read otp into buffer
	if (index == 1)
	{
		// read otp --Bank 0
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x00);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x0f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
//		(*otp_ptr).module_integrator_id = (OV5648MIPI_read_cmos_sensor(0x3d05) & 0x7f);
//		(*otp_ptr).lens_id = OV5648MIPI_read_cmos_sensor(0x3d06);
		temp = OV5648MIPI_read_cmos_sensor(0x3d0b);
		(*otp_ptr).rg_ratio = (OV5648MIPI_read_cmos_sensor(0x3d07)<<2) + ((temp>>6) & 0x03);
		(*otp_ptr).bg_ratio = (OV5648MIPI_read_cmos_sensor(0x3d08)<<2) + ((temp>>4) & 0x03);
		(*otp_ptr).light_rg = (OV5648MIPI_read_cmos_sensor(0x3d0c)<<2) + ((temp>>2) & 0x03);
		(*otp_ptr).light_bg = (OV5648MIPI_read_cmos_sensor(0x3d0d)<<2) + (temp & 0x03);
		(*otp_ptr).user_data[0] = OV5648MIPI_read_cmos_sensor(0x3d09);
		(*otp_ptr).user_data[1] = OV5648MIPI_read_cmos_sensor(0x3d0a);
	}
	else if (index == 2)
	{
		// read otp --Bank 0
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x00);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x0f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
//		(*otp_ptr).module_integrator_id = (OV5648MIPI_read_cmos_sensor(0x3d0e) & 0x7f);
//		(*otp_ptr).lens_id = OV5648MIPI_read_cmos_sensor(0x3d0f);
		// read otp --Bank 1
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x10);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x1f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
		temp = OV5648MIPI_read_cmos_sensor(0x3d04);
		(*otp_ptr).rg_ratio = (OV5648MIPI_read_cmos_sensor(0x3d00)<<2) + ((temp>>6) & 0x03);
		(*otp_ptr).bg_ratio = (OV5648MIPI_read_cmos_sensor(0x3d01)<<2) + ((temp>>4) & 0x03);
		(*otp_ptr).light_rg = (OV5648MIPI_read_cmos_sensor(0x3d05)<<2) + ((temp>>2) & 0x03);
		(*otp_ptr).light_bg = (OV5648MIPI_read_cmos_sensor(0x3d06)<<2) + (temp & 0x03);
		(*otp_ptr).user_data[0] = OV5648MIPI_read_cmos_sensor(0x3d02);
		(*otp_ptr).user_data[1] = OV5648MIPI_read_cmos_sensor(0x3d03);
	}
	else if (index == 3)
	{
		// read otp --Bank 1
		OV5648MIPI_write_cmos_sensor(0x3d84, 0xc0);
		OV5648MIPI_write_cmos_sensor(0x3d85, 0x10);
		OV5648MIPI_write_cmos_sensor(0x3d86, 0x1f);
		OV5648MIPI_write_cmos_sensor(0x3d81, 0x01);
		msleep(5);
//		(*otp_ptr).module_integrator_id = (OV5648MIPI_read_cmos_sensor(0x3d07) & 0x7f);
//		(*otp_ptr).lens_id = OV5648MIPI_read_cmos_sensor(0x3d08);
		temp = OV5648MIPI_read_cmos_sensor(0x3d0d);
		(*otp_ptr).rg_ratio = (OV5648MIPI_read_cmos_sensor(0x3d09)<<2) + ((temp>>6) & 0x03);
		(*otp_ptr).bg_ratio = (OV5648MIPI_read_cmos_sensor(0x3d0a)<<2) + ((temp>>4) & 0x03);
		(*otp_ptr).light_rg = (OV5648MIPI_read_cmos_sensor(0x3d0e)<<2) + ((temp>>2) & 0x03);
		(*otp_ptr).light_bg = (OV5648MIPI_read_cmos_sensor(0x3d0f)<<2) + (temp & 0x03);
		(*otp_ptr).user_data[0] = OV5648MIPI_read_cmos_sensor(0x3d0b);
		(*otp_ptr).user_data[1] = OV5648MIPI_read_cmos_sensor(0x3d0c);
	}


	// clear otp buffer
	for (i=0;i<16;i++) {
		OV5648MIPI_write_cmos_sensor(0x3d00 + i, 0x00);
	}

	return 0;
}


// R_gain, sensor red gain of AWB, 0x400 =1
// G_gain, sensor green gain of AWB, 0x400 =1
// B_gain, sensor blue gain of AWB, 0x400 =1
// return 0;
static int update_awb_gain(int R_gain, int G_gain, int B_gain)
{
	if (R_gain>0x400) {
		OV5648MIPI_write_cmos_sensor(0x5186, R_gain>>8);
		OV5648MIPI_write_cmos_sensor(0x5187, R_gain & 0x00ff);
	}

	if (G_gain>0x400) {
		OV5648MIPI_write_cmos_sensor(0x5188, G_gain>>8);
		OV5648MIPI_write_cmos_sensor(0x5189, G_gain & 0x00ff);
	}

	if (B_gain>0x400) {
		OV5648MIPI_write_cmos_sensor(0x518a, B_gain>>8);
		OV5648MIPI_write_cmos_sensor(0x518b, B_gain & 0x00ff);
	}
	return 0;
}

static int BG_Ratio_Typical = 0x135;
static int RG_Ratio_Typical = 0x168;


int update_otp(void)
{
	struct otp_struct current_otp = { 0 };
	int i;
	int otp_index;
	int temp;
	int R_gain, G_gain, B_gain, G_gain_R, G_gain_B;
	int rg,bg;

	// R/G and B/G of current camera module is read out from sensor OTP

	for(i=1;i<=3;i++) {
		temp = check_otp(i);
		if (temp == 2) {
			otp_index = i;
			break;
		}
	}

	if (i>3) {
		// no valid wb OTP data
		return 1;
	}

	read_otp(bank_index, &current_otp);

	if(current_otp.light_rg==0) {
		// no light source information in OTP
		rg = current_otp.rg_ratio;
	}
	else {
		// light source information found in OTP
		rg = current_otp.rg_ratio * (current_otp.light_rg +512) / 1024;
	}

	if(current_otp.light_bg==0) {
		// no light source information in OTP
		bg = current_otp.bg_ratio;
	}
	else {
		// light source information found in OTP
		bg = current_otp.bg_ratio * (current_otp.light_bg +512) / 1024;
	}

	//calculate G gain
	//0x400 = 1x gain
	if(bg < BG_Ratio_Typical) {
		if (rg< RG_Ratio_Typical) {
			// current_otp.bg_ratio < BG_Ratio_typical &&?
			// current_otp.rg_ratio < RG_Ratio_typical
			G_gain = 0x400;
			B_gain = 0x400 * BG_Ratio_Typical / bg;
			R_gain = 0x400 * RG_Ratio_Typical / rg;
		}
		else {
			// current_otp.bg_ratio < BG_Ratio_typical &&?
			// current_otp.rg_ratio >= RG_Ratio_typical
			R_gain = 0x400;
			G_gain = 0x400 * rg / RG_Ratio_Typical;
			B_gain = G_gain * BG_Ratio_Typical /bg;
		}
	}
	else {
		if (rg < RG_Ratio_Typical) {
			// current_otp.bg_ratio >= BG_Ratio_typical &&?
			// current_otp.rg_ratio < RG_Ratio_typical
			B_gain = 0x400;
			G_gain = 0x400 * bg / BG_Ratio_Typical;
			R_gain = G_gain * RG_Ratio_Typical / rg;
		}
		else {
			// current_otp.bg_ratio >= BG_Ratio_typical &&?
			// current_otp.rg_ratio >= RG_Ratio_typical
			G_gain_B = 0x400 * bg / BG_Ratio_Typical;
			G_gain_R = 0x400 * rg / RG_Ratio_Typical;

			if(G_gain_B > G_gain_R ) {
				B_gain = 0x400;
				G_gain = G_gain_B;
				R_gain = G_gain * RG_Ratio_Typical /rg;
			}
			else {
				R_gain = 0x400;
				G_gain = G_gain_R;
				B_gain = G_gain * BG_Ratio_Typical / bg;
			}
		}
	}
	//before OTP update
	LOG_INF("reg[0x5186] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5186));
	LOG_INF("reg[0x5187] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5187));
	LOG_INF("reg[0x5188] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5188));
	LOG_INF("reg[0x5189] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5189));
	LOG_INF("reg[0x518a] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x518a));
	LOG_INF("reg[0x518b] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x518b));
	LOG_INF("RG_Ratio_Typical = %x\r\n", RG_Ratio_Typical);
	LOG_INF("BG_Ratio_Typical = %x\r\n", BG_Ratio_Typical);
	LOG_INF("RG = %x\r\n", rg);
	LOG_INF("BG = %x\r\n", bg);

	update_awb_gain(R_gain, G_gain, B_gain);
  //after
	LOG_INF("reg[0x5186] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5186));
	LOG_INF("reg[0x5187] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5187));
	LOG_INF("reg[0x5188] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5188));
	LOG_INF("reg[0x5189] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x5189));
	LOG_INF("reg[0x518a] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x518a));
	LOG_INF("reg[0x518b] = %x\r\n", OV5648MIPI_read_cmos_sensor(0x518b));

	return 0;
}


void OV5648CheckLensVersion(kal_uint8  write_id)
{
    kal_uint8 data[3]={0};
    kal_uint8 i = 0;
	//struct otp_struct current_otp = { 0 };
	OV5648MIPI_WRITE_ID = write_id;
    for(i=1; i<=3; i++)
	{
       if(OV5648MIPI_read_module_info(i,data)==1)
       {
        bank_index = i;
        break;
       }
	}
	LOG_INF("[zbl] module id=0x%x\n",data[0]);
	LOG_INF("[zbl] lens_id=0x%x,sensid=0x%x\n",data[1],data[2]);
}

