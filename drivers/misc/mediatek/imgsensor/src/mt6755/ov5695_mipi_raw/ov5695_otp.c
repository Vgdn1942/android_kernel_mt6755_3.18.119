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
#include "agold_camera_info.h"


#define LOG_INF(format, args...)	printk("[%s] " format, __FUNCTION__, ##args)


extern int g_cur_cam_sensor;

extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);

static unsigned char OV5695MIPI_WRITE_ID = 0X00;


struct otp_struct {
	int module_integrator_id;
	int lens_id;
	kal_uint16 rg_ratio;
	kal_uint16 bg_ratio;
	int user_data[2];
	int light_rg;
	int light_bg;
}otp_ptr;


static kal_uint16 OV5695MIPI_write_cmos_sensor(kal_uint16 addr, kal_uint16 para)
{
		iWriteReg((u16) addr , (u32) para , 1, OV5695MIPI_WRITE_ID);
		return 1;
}


static kal_uint16 OV5695MIPI_read_cmos_sensor(kal_uint16 addr)
{
    kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,OV5695MIPI_WRITE_ID);
    return get_byte;
}

static int BG_Ratio_Typical = 0x139;
static int RG_Ratio_Typical = 0x133;

int ov5695_select_group(kal_uint8 flag)
{
	if(flag>>6 == 0x01)
		return 1;
	else
	{
		if((flag&0x30)>>4 == 0x01)
			return 2;
		else
		{
			if((flag&0x0c)>>2 == 0x01)
				return 3;
			else
				return 0;
		}
	}		
}


void awb_otp(void)
{
	kal_uint16 rg,bg,R_gain,G_gain,B_gain,Base_gain;
	
	rg = otp_ptr.rg_ratio;
	bg = otp_ptr.bg_ratio;

	R_gain = (RG_Ratio_Typical*1000)/rg;
	B_gain = (BG_Ratio_Typical*1000)/bg;
	G_gain = 1000;
	printk("[zhangpeng],R_gain = %x\n",R_gain);
	printk("[zhangpeng],B_gain = %x\n",B_gain);
	printk("[zhangpeng],G_gain = %x\n",G_gain);

	if(R_gain < 1000||B_gain < 1000)
	{	
		if(R_gain < B_gain)
			Base_gain = R_gain;
		else
			Base_gain = B_gain;
	}
	else
	{
		Base_gain = G_gain;
	}
	printk("[zhangpeng],Base_gain = %x\n",Base_gain);	


	R_gain = 0x400*R_gain/(Base_gain);
	B_gain = 0x400*B_gain/(Base_gain);
	G_gain = 0x400*G_gain/(Base_gain);
	printk("[zhangpeng],R_gain = %x\n",R_gain);
	printk("[zhangpeng],B_gain = %x\n",B_gain);
	printk("[zhangpeng],G_gain = %x\n",G_gain);


	if(R_gain > 0x400)
	{
		OV5695MIPI_write_cmos_sensor(0x5019,R_gain>>8);
		OV5695MIPI_write_cmos_sensor(0x501a,R_gain&0xff);
	}

	if(G_gain > 0x400)
	{
		OV5695MIPI_write_cmos_sensor(0x501b,G_gain>>8);
		OV5695MIPI_write_cmos_sensor(0x501c,G_gain&0xff);
	}

	if(B_gain > 0x400)
	{
		OV5695MIPI_write_cmos_sensor(0x501d,B_gain>>8);
		OV5695MIPI_write_cmos_sensor(0x501e,B_gain&0xff);
	}	
}

void ov5695_update_otp(void)
{
	kal_uint8 data[2]={0};
	kal_uint8 i = 0;
	kal_uint8 flag;
	int group;
	kal_uint16 addr; 

	for(i = 0; i < 16; i++)
	{
        OV5695MIPI_write_cmos_sensor(0x700c + i, 0x00);
	}

	OV5695MIPI_write_cmos_sensor(0x0100,0x01);//sensor stream on

	OV5695MIPI_write_cmos_sensor(0x3d85,0x17);
	OV5695MIPI_write_cmos_sensor(0x3d84,0xc0);
	OV5695MIPI_write_cmos_sensor(0x3d88,0x70);//OTP start address
	OV5695MIPI_write_cmos_sensor(0x3d89,0x0c);
	OV5695MIPI_write_cmos_sensor(0x3d8a,0x70); //OTP end address
	OV5695MIPI_write_cmos_sensor(0x3d8b,0x1b); 
	OV5695MIPI_write_cmos_sensor(0x3d81,0x01); //OTP Read Enable
        
	msleep(5); // delay 5ms
	
	flag = OV5695MIPI_read_cmos_sensor(0x700c);
	printk("[zhangpeng],flag = %x\n",flag);

	group = ov5695_select_group(flag);
	printk("[zhangpeng],group = %d\n",group);

	if(!group)
	{
		printk("no group can use\n");
		return;	
	}
	else if(group == 1)
	{
		addr = 0x700d;
	}
	else if(group == 2)
	{
		addr = 0x7012;
	}
	else
	{
		addr = 0x7017;
	}

	data[0] = OV5695MIPI_read_cmos_sensor(addr+2);
	data[1] = OV5695MIPI_read_cmos_sensor(addr+3);
	data[2] = OV5695MIPI_read_cmos_sensor(addr+4);
	printk("[zhangpeng],AWB_RG_MSB =%x\n",data[0]);
	printk("[zhangpeng],AWB_BG_MSB =%x\n",data[1]);
	printk("[zhangpeng],AWB_LSB =%x\n",data[2]);

	otp_ptr.rg_ratio = (data[0]<<2) + (data[2]>>6);
	otp_ptr.bg_ratio = (data[1]<<2) + ((data[2]>>4)&0x03);
	printk("[zhangpeng],rg_ratio = %x\n",otp_ptr.rg_ratio);
	printk("[zhangpeng],bg_ratio = %x\n",otp_ptr.bg_ratio);

	awb_otp();

	for(i = 0; i < 16; i++)
	{
        OV5695MIPI_write_cmos_sensor(0x700c + i, 0x00);
	}

	OV5695MIPI_write_cmos_sensor(0x0100,0x00);//sensor stream off
}


void OV5695CheckLensVersion(kal_uint8  write_id)
{
	kal_uint8 data[2]={0};
	kal_uint8 i = 0;
	kal_uint8 flag;
	int group;
	kal_uint16 addr;

	OV5695MIPI_WRITE_ID = write_id;

	for(i = 0; i < 16; i++)
	{
        OV5695MIPI_write_cmos_sensor(0x700c + i, 0x00);
	}

	OV5695MIPI_write_cmos_sensor(0x0100,0x01);//sensor stream on
	

    OV5695MIPI_write_cmos_sensor(0x3d84,0xc0);
	OV5695MIPI_write_cmos_sensor(0x3d88,0x70);//OTP start address
	OV5695MIPI_write_cmos_sensor(0x3d89,0x0c);
	OV5695MIPI_write_cmos_sensor(0x3d8a,0x70); //OTP end address
	OV5695MIPI_write_cmos_sensor(0x3d8b,0x1b); 
	OV5695MIPI_write_cmos_sensor(0x3d81,0x01); //OTP Read Enable
        
	msleep(5); // delay 5ms
	
	flag = OV5695MIPI_read_cmos_sensor(0x700c);
	printk("[zhangpeng],flag = %x\n",flag);

	group = ov5695_select_group(flag);
	printk("[zhangpeng],group = %d\n",group);
		
	if(!group)
	{
		printk("no group can use\n");
		return;	
	}
	else if(group == 1)
	{
		addr = 0x700d;
	}
	else if(group == 2)
	{
		addr = 0x7012;
	}
	else
	{
		addr = 0x7017;
	}
	
	data[0] = OV5695MIPI_read_cmos_sensor(addr);
	data[1] = OV5695MIPI_read_cmos_sensor(addr+1);
	

	LOG_INF("[zhangpeng] module id=0x%x\n",data[0]);
	LOG_INF("[zhangpeng] lens_id=0x%x\n",data[1]);

	agold_camera_info[g_cur_cam_sensor-1].mf_id = data[0];
	agold_camera_info[g_cur_cam_sensor-1].lens_id = data[1];
	
	
	OV5695MIPI_write_cmos_sensor(0x3d81,0x00);
	for(i = 0; i < 16; i++)
	{
        OV5695MIPI_write_cmos_sensor(0x700c + i, 0x00);
	}
	OV5695MIPI_write_cmos_sensor(0x0100,0x00);//sensor stream off
}














