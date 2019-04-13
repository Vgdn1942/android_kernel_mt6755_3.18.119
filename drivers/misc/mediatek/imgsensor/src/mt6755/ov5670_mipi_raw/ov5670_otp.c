#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
//#include <linux/xlog.h>
#include <linux/proc_fs.h>


#include <linux/dma-mapping.h>

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"

#include "ov5670mipi_Sensor.h"

#define BG_Ratio_Typical 0x269
#define RG_Ratio_Typical 0x275

extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);

#define PFX "OV5670_OTP"
#define LOG_INF(format, args...)	printk(PFX "[%s] " format, __FUNCTION__, ##args)

static struct otp_struct {
	int flag; // bit[7]: info, bit[6]:wb
	int module_integrator_id;
	int lens_id;
	int production_year;
	int production_month;
	int production_day;
	int rg_ratio;
	int bg_ratio;
};

static unsigned char OV5670MIPI_WRITE_ID = 0X00;

static kal_uint16 OV5670_read_i2c(kal_uint32 addr)
{
    kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,OV5670MIPI_WRITE_ID);
    return get_byte;
}

static kal_uint16 OV5670_write_i2c(u16 addr, u32 para)
{
		iWriteReg((u16) addr , (u32) para , 1, OV5670MIPI_WRITE_ID);
		return 1;
}

// return value:
// bit[7]: 0 no otp info, 1 valid otp info
// bit[6]: 0 no otp wb, 1 valib otp wb
static int read_otp(struct otp_struct *otp_ptr)
{
    int otp_flag, addr, temp, i;
    //set 0x5002[3] to 0
    int temp1;
    temp1 = OV5670_read_i2c(0x5002);
    OV5670_write_i2c(0x5002, (0x00 & 0x08) | (temp1 & (~0x08)));
    // read OTP into buffer
    OV5670_write_i2c(0x3d84, 0xC0);
    OV5670_write_i2c(0x3d88, 0x70); // OTP start address
    OV5670_write_i2c(0x3d89, 0x10);
    OV5670_write_i2c(0x3d8A, 0x70); // OTP end address
    OV5670_write_i2c(0x3d8B, 0x29);
    OV5670_write_i2c(0x3d81, 0x01); // load otp into buffer
    mdelay(5);
    // OTP into
    otp_flag = OV5670_read_i2c(0x7010);
    addr = 0;
    if((otp_flag & 0xc0) == 0x40)
    {
        addr = 0x7011; // base address of info group 1
    }
    else if((otp_flag & 0x30) == 0x10)
    {
        addr = 0x7016; // base address of info group 2
    }
    else if((otp_flag & 0x0c) == 0x04)
    {
        addr = 0x701b; // base address of info group 3
    }
    if(addr != 0)
    {
        (*otp_ptr).flag = 0x80; // valid base info in OTP
        (*otp_ptr).module_integrator_id = OV5670_read_i2c( addr );
        (*otp_ptr).lens_id = OV5670_read_i2c( addr + 1);
        (*otp_ptr).production_year = OV5670_read_i2c( addr + 2);
        (*otp_ptr).production_month = OV5670_read_i2c( addr + 3);
        (*otp_ptr).production_day = OV5670_read_i2c( addr + 4);
    }
    else
    {
        (*otp_ptr).flag = 0x00; // not info in OTP
        (*otp_ptr).module_integrator_id = 0;
        (*otp_ptr).lens_id = 0;
        (*otp_ptr).production_year = 0;
        (*otp_ptr).production_month = 0;
        (*otp_ptr).production_day = 0;
    }
    // OTP WB Calibration
    otp_flag = OV5670_read_i2c(0x7020);
    addr = 0;
    if((otp_flag & 0xc0) == 0x40)
    {
        addr = 0x7021; // base address of WB Calibration group 1
    }
    else if((otp_flag & 0x30) == 0x10)
    {
        addr = 0x7024; // base address of WB Calibration group 2
    }
    else if((otp_flag & 0x0c) == 0x04)
    {
        addr = 0x7027; // base address of WB Calibration group 3
    }
    if(addr != 0)
    {
        (*otp_ptr).flag |= 0x40;
        temp = OV5670_read_i2c( addr + 2);
        (*otp_ptr).rg_ratio = (OV5670_read_i2c(addr)<<2) + ((temp>>6) & 0x03);
        (*otp_ptr).bg_ratio = (OV5670_read_i2c( addr + 1)<<2) + ((temp>>4) & 0x03);
    }
    else
    {
        (*otp_ptr).rg_ratio = 0;
        (*otp_ptr).bg_ratio = 0;
    }
    for(i=0x7010;i<=0x7029;i++)
    {
        OV5670_write_i2c(i,0); // clear OTP buffer, recommended use continuous write to accelarate
    }
    //set 0x5002[3] to ¡°1¡±
    temp1 = OV5670_read_i2c(0x5002);
    OV5670_write_i2c(0x5002, (0x02 & 0x08) | (temp1 & (~0x08)));
    return (*otp_ptr).flag;
}

// return value:
// bit[7]: 0 no otp info, 1 valid otp info
// bit[6]: 0 no otp wb, 1 valib otp wb
static int apply_otp(struct otp_struct *otp_ptr)
{
    int rg, bg, R_gain, G_gain, B_gain, Base_gain;

    // apply OTP WB Calibration
    if ((*otp_ptr).flag & 0x40)
    {
        rg = (*otp_ptr).rg_ratio;
        bg = (*otp_ptr).bg_ratio;
        LOG_INF("ov5670 rg=0x%x, bg=0x%x\n",rg,bg);
        //calculate G gain
        R_gain = (RG_Ratio_Typical*1000) / rg;
        B_gain = (BG_Ratio_Typical*1000) / bg;
        G_gain = 1000;
        if (R_gain < 1000 || B_gain < 1000)
        {
            if (R_gain < B_gain)
            Base_gain = R_gain;
            else
            Base_gain = B_gain;
        }
        else
        {
            Base_gain = G_gain;
        }
        R_gain = 0x400 * R_gain / (Base_gain);
        B_gain = 0x400 * B_gain / (Base_gain);
        G_gain = 0x400 * G_gain / (Base_gain);
        // update sensor WB gain
        if (R_gain>0x400)
        {
            OV5670_write_i2c(0x5032, R_gain>>8);
            OV5670_write_i2c(0x5033, R_gain & 0x00ff);
        }
        if (G_gain>0x400)
        {
            OV5670_write_i2c(0x5034, G_gain>>8);
            OV5670_write_i2c(0x5035, G_gain & 0x00ff);
        }
        if (B_gain>0x400)
        {
            OV5670_write_i2c(0x5036, B_gain>>8);
            OV5670_write_i2c(0x5037, B_gain & 0x00ff);
        }
    }
    return (*otp_ptr).flag;
}

void ov5670_otp_cali(void)
{
	struct otp_struct current_otp;
	memset(&current_otp, 0, sizeof(struct otp_struct));
	read_otp(&current_otp);
	apply_otp(&current_otp);
}

void OV5670CheckLensVersion(kal_uint8 i2c_write_id)
{
    int index = 0;
	static int checkVersion = 0;
    int temp1,otp_flag,retVal;
    printk("OV5670CheckLensVersion: enter! \n");

    OV5670MIPI_WRITE_ID = i2c_write_id;

    if(g_cur_cam_sensor==1 || g_cur_cam_sensor ==2)
    {
        if(!checkVersion)
        {
            OV5670_write_i2c(0x0100,0x01);// ; stream on

            temp1 = OV5670_read_i2c(0x5002);
            OV5670_write_i2c(0x5002, (0x00 & 0x08) | (temp1 & (~0x08)));
            // read OTP into buffer
            OV5670_write_i2c(0x3d84, 0xC0);
            OV5670_write_i2c(0x3d88, 0x70); // OTP start address
            OV5670_write_i2c(0x3d89, 0x10);
            OV5670_write_i2c(0x3d8A, 0x70); // OTP end address
            OV5670_write_i2c(0x3d8B, 0x29);
            OV5670_write_i2c(0x3d81, 0x01); // load otp into buffer
            mdelay(5);
            // OTP into
            otp_flag = OV5670_read_i2c(0x7010);
            LOG_INF("ov5670 otp_flag = 0x%x\n",otp_flag);
            for(index = 1; index <= 3; index++)
			{
				retVal = otp_flag;
				retVal = (retVal >> (8-2*index)) & 0x03;
				printk("otp_log read otp info flag,index=%d,retVal=%d\n", index, retVal);
				if((retVal & 0x01) && !(retVal & 0x02))
				{
					break;
				}
			}

			for(index = 0x7010; index <= 0x7029; index++)
			{
				OV5670_write_i2c(index, 0x00);
			}

			temp1 = OV5670_read_i2c(0x5002);
            OV5670_write_i2c(0x5002, (0x02 & 0x08) | (temp1 & (~0x08)));
            checkVersion = 1;
            OV5670_write_i2c(0x0100,0x00);
        }
    }
}

