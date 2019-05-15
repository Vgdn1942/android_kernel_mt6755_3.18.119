#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/types.h>
#include <mt-plat/mt_boot.h>
#include <linux/proc_fs.h>
#include <linux/dma-mapping.h>

#include "kd_camera_typedef.h"
#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"

#include "ov8858mipiraw_Sensor.h"



struct otp_struct {
int flag; // bit[7]: info, bit[6]:wb, bit[5]:vcm, bit[4]:lenc
int module_integrator_id;
int lens_id;
int production_year;
int production_month;
int production_day;
int rg_ratio;
int bg_ratio;
int lenc[240];
int checksum;
int VCM_start;
int VCM_end;
int VCM_dir;
};


#if defined(CONFIG_MTK_CAMERA_VERSION)
#include "agold_camera_info.h"
#endif






//extern int g_cur_cam_sensor;
extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);



static int apply_otp(struct otp_struct *otp_ptr);
static int read_otp(struct otp_struct *otp_ptr);


#define PFX "OV8858_OTP"

#ifdef LOG_ON
#define LOG_INF(format, args...)	pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)
#else
#define LOG_INF(format, args...)
#endif


#define Delay(ms)  mdelay(ms)

#define RG_Ratio_Typical 0x145
#define BG_Ratio_Typical 0x116


static unsigned char OV8858MIPI_WRITE_ID = 0X00;


static kal_uint16 OV8858_R2A_read_i2c(kal_uint32 addr)
{
    kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,OV8858MIPI_WRITE_ID);
    return get_byte;
}

static kal_uint16 OV8858_R2A_write_i2c(kal_uint16 addr, kal_uint32 para)
{
		iWriteReg((u16) addr , (u32) para , 1, OV8858MIPI_WRITE_ID);
		return 1;
}

static int apply_otp(struct otp_struct *otp_ptr);
static int read_otp(struct otp_struct *otp_ptr);















// return value:
// bit[7]: 0 no otp info, 1 valid otp info
// bit[6]: 0 no otp wb, 1 valib otp wb
// bit[5]: 0 no otp vcm, 1 valid otp vcm
// bit[4]: 0 no otp lenc/invalid otp lenc, 1 valid otp lenc
int read_otp(struct otp_struct *otp_ptr)
{
    int otp_flag, addr, temp, i;
    int checksum2=0;
    int temp1;

    OV8858_R2A_write_i2c(0x100 , 0x01);
    //set 0x5002[3] to “0”
    temp1 = OV8858_R2A_read_i2c(0x5002);
    OV8858_R2A_write_i2c(0x5002, (0x00 & 0x08) | (temp1 & (~0x08)));
    // read OTP into buffer
    OV8858_R2A_write_i2c(0x3d84, 0xC0);
    OV8858_R2A_write_i2c(0x3d88, 0x70); // OTP start address
    OV8858_R2A_write_i2c(0x3d89, 0x10);
    OV8858_R2A_write_i2c(0x3d8A, 0x72); // OTP end address
    OV8858_R2A_write_i2c(0x3d8B, 0x0a);
    OV8858_R2A_write_i2c(0x3d81, 0x01); // load otp into buffer
    Delay(10);
    // OTP base information and WB calibration data
    otp_flag = OV8858_R2A_read_i2c(0x7010);
    LOG_INF("[zbl] module info otp_flag = %d\n",otp_flag);
    addr = 0;
    if((otp_flag & 0xc0) == 0x40)
    {
        addr = 0x7011; // base address of info group 1
    }
    else if((otp_flag & 0x30) == 0x10)
    {
        addr = 0x7019; // base address of info group 2
    }
    if(addr != 0)
    {
        (*otp_ptr).flag = 0xC0; // valid info and AWB in OTP
        (*otp_ptr).module_integrator_id = OV8858_R2A_read_i2c(addr);
        (*otp_ptr).lens_id = OV8858_R2A_read_i2c( addr + 1);
        (*otp_ptr).production_year = OV8858_R2A_read_i2c( addr + 2);
        (*otp_ptr).production_month = OV8858_R2A_read_i2c( addr + 3);
        (*otp_ptr).production_day = OV8858_R2A_read_i2c(addr + 4);
        temp = OV8858_R2A_read_i2c(addr + 7);
        (*otp_ptr).rg_ratio = (OV8858_R2A_read_i2c(addr + 5)<<2) + ((temp>>6) & 0x03);
        (*otp_ptr).bg_ratio = (OV8858_R2A_read_i2c(addr + 6)<<2) + ((temp>>4) & 0x03);
    }
    else
    {
        (*otp_ptr).flag = 0x00; // not info and AWB in OTP
        (*otp_ptr).module_integrator_id = 0;
        (*otp_ptr).lens_id = 0;
        (*otp_ptr).production_year = 0;
        (*otp_ptr).production_month = 0;
        (*otp_ptr).production_day = 0;
        (*otp_ptr).rg_ratio = 0;
        (*otp_ptr).bg_ratio = 0;
    }

    // OTP VCM Calibration
    otp_flag = OV8858_R2A_read_i2c(0x7021);
    LOG_INF("[zbl] VCM info otp_flag = %d\n",otp_flag);
    addr = 0;
    if((otp_flag & 0xc0) == 0x40)
    {
        addr = 0x7022; // base address of VCM Calibration group 1
    }
    else if((otp_flag & 0x30) == 0x10)
    {
        addr = 0x7025; // base address of VCM Calibration group 2
    }
    if(addr != 0)
    {
        (*otp_ptr).flag |= 0x20;
        temp = OV8858_R2A_read_i2c(addr + 2);
        (* otp_ptr).VCM_start = (OV8858_R2A_read_i2c(addr)<<2) | ((temp>>6) & 0x03);
        (* otp_ptr).VCM_end = (OV8858_R2A_read_i2c(addr + 1) << 2) | ((temp>>4) & 0x03);
        (* otp_ptr).VCM_dir = (temp>>2) & 0x03;
    }
    else
    {
        (* otp_ptr).VCM_start = 0;
        (* otp_ptr).VCM_end = 0;
        (* otp_ptr).VCM_dir = 0;
    }

    // OTP Lenc Calibration
    otp_flag = OV8858_R2A_read_i2c(0x7028);
    LOG_INF("[zbl] Lenc info otp_flag = %d\n",otp_flag);
    addr = 0;

    if((otp_flag & 0xc0) == 0x40)
    {
        addr = 0x7029; // base address of Lenc Calibration group 1
    }
    else if((otp_flag & 0x30) == 0x10)
    {
        addr = 0x711a; // base address of Lenc Calibration group 2
    }
    if(addr != 0)
    {
        for(i=0;i<240;i++)
        {
            (* otp_ptr).lenc[i]=OV8858_R2A_read_i2c(addr + i);
            checksum2 += (* otp_ptr).lenc[i];
        }
        checksum2 = (checksum2)%255 +1;
        (* otp_ptr).checksum = OV8858_R2A_read_i2c(addr + 240);
        if((* otp_ptr).checksum == checksum2)
        {
            (*otp_ptr).flag |= 0x10;
        }
    }
    else
    {
        for(i=0;i<240;i++)
        {
            (* otp_ptr).lenc[i]=0;
        }
    }
    for(i=0x7010;i<=0x720a;i++)
    {
        OV8858_R2A_write_i2c(i,0); // clear OTP buffer, recommended use continuous write to accelarate
    }
    //set 0x5002[3] to “1”
    temp1 = OV8858_R2A_read_i2c(0x5002);
    OV8858_R2A_write_i2c(0x5002, (0x08 & 0x08) | (temp1 & (~0x08)));
    return (*otp_ptr).flag;
}







// return value:
// bit[7]: 0 no otp info, 1 valid otp info
// bit[6]: 0 no otp wb, 1 valib otp wb
// bit[5]: 0 no otp vcm, 1 valid otp vcm
// bit[4]: 0 no otp lenc, 1 valid otp lenc
int apply_otp(struct otp_struct *otp_ptr)
{
    int rg, bg, R_gain, G_gain, B_gain, Base_gain, temp, i;
    // apply OTP WB Calibration
    if ((*otp_ptr).flag & 0x40)
    {
        rg = (*otp_ptr).rg_ratio;
        bg = (*otp_ptr).bg_ratio;
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
            OV8858_R2A_write_i2c(0x5032, R_gain>>8);
            OV8858_R2A_write_i2c(0x5033, R_gain & 0x00ff);
        }
        if (G_gain>0x400)
        {
            OV8858_R2A_write_i2c(0x5034, G_gain>>8);
            OV8858_R2A_write_i2c(0x5035, G_gain & 0x00ff);
        }
        if (B_gain>0x400)
        {
            OV8858_R2A_write_i2c(0x5036, B_gain>>8);
            OV8858_R2A_write_i2c(0x5037, B_gain & 0x00ff);
        }
    }
    // apply OTP Lenc Calibration
    if ((*otp_ptr).flag & 0x10)
    {
        temp = OV8858_R2A_read_i2c(0x5000);
        temp = 0x80 | temp;
        OV8858_R2A_write_i2c(0x5000, temp);
        for(i=0;i<240;i++)
        {
            OV8858_R2A_write_i2c(0x5800 + i, (*otp_ptr).lenc[i]);
        }
    }
    return (*otp_ptr).flag;
}




void otp_cali(void)
{
	struct otp_struct current_otp;
//	OV8858MIPI_WRITE_ID = writeid;
	memset(&current_otp, 0, sizeof(struct otp_struct));
	read_otp(&current_otp);
	apply_otp(&current_otp);
}






void OV8858CheckLensVersion(int writeid)
{
	int i = 0;
	static int checkVersion = 0;
	int otp_flag, index;
	int retVal = 0;
//	int nFlagAddress = OTP_DRV_START_ADDR;
//	int start_addr, end_addr;
	int temp1;
    int data[8] = { 0 };

    LOG_INF("OV8858CheckLensVersion: enter! \n");
	//printk("[Lancelot]g_cur_cam_sensor=%d\n", g_cur_cam_sensor);
	OV8858MIPI_WRITE_ID = writeid;
	LOG_INF("[zbl] write_id = %d\n",writeid);
	if(!checkVersion)
	{
	    OV8858_R2A_write_i2c(0x100 , 0x01);
        temp1 = OV8858_R2A_read_i2c(0x5002);
        OV8858_R2A_write_i2c(0x5002, (temp1 & (~0x08)));
        // read OTP into buffer
        OV8858_R2A_write_i2c(0x3d84, 0xC0);
        OV8858_R2A_write_i2c(0x3d88, 0x70); // OTP start address
        OV8858_R2A_write_i2c(0x3d89, 0x10);
        OV8858_R2A_write_i2c(0x3d8A, 0x72); // OTP end address
        OV8858_R2A_write_i2c(0x3d8B, 0x0a);
        OV8858_R2A_write_i2c(0x3d81, 0x01); // load otp into buffer
        Delay(10);

		otp_flag = OV8858_R2A_read_i2c(0x7010);
		LOG_INF("read info flag (0x7010)=0x%02x\n", otp_flag);



		for(index = 1; index <= 3; index++)
		{
			retVal = otp_flag;
			retVal = (retVal >> (8-2*index)) & 0x03;
			LOG_INF("otp_log read otp info flag,index=%d,retVal=%d\n", index, retVal);
			if((retVal & 0x01) && !(retVal & 0x02))
			{
			    LOG_INF("[zbl] read retval = %x",retVal);
				break;
			}
		}

		if(index <= 3)
		{
		    #if defined(CONFIG_MTK_CAMERA_VERSION)
			    agold_camera_info[g_cur_cam_sensor-1].mf_id =  OV8858_R2A_read_i2c(0x7011 + 8*(index-1));	//0x7221 0x7226 0x722B
			    agold_camera_info[g_cur_cam_sensor-1].lens_id =  OV8858_R2A_read_i2c(0x7012 + 8*(index-1));	//0x7222 0x7227 0x722C
			    agold_camera_info[g_cur_cam_sensor-1].date[0] =  OV8858_R2A_read_i2c(0x7013 + 8*(index-1));	//0x7223 0x7228 0x722D
			    agold_camera_info[g_cur_cam_sensor-1].date[1] =  OV8858_R2A_read_i2c(0x7014 + 8*(index-1));	//0x7224 0x7229 0x701E
			    agold_camera_info[g_cur_cam_sensor-1].date[2] =  OV8858_R2A_read_i2c(0x7015 + 8*(index-1));	//0x7225 0x722A 0x722F
			#endif
			data[0] = OV8858_R2A_read_i2c(0x7011 + 8*(index-1));
			data[1] = OV8858_R2A_read_i2c(0x7012 + 8*(index-1));
			data[2] = OV8858_R2A_read_i2c(0x7013 + 8*(index-1));
			data[3] = OV8858_R2A_read_i2c(0x7014 + 8*(index-1));
			data[4] = OV8858_R2A_read_i2c(0x7015 + 8*(index-1));
			LOG_INF("[zbl] moduleid = 0x%x, lensid = 0x%x, years = 0x%x, month = 0x%x, day = 0x%x\n",
			        data[0],data[1],data[2],data[3],data[4]);
		}
		else
		{
			LOG_INF("[OV13850OTP]invalid info data\n");
		}

		for(i=0x7010;i<=0x720a;i++)
        {
            OV8858_R2A_write_i2c(i,0); // clear OTP buffer, recommended use continuous write to accelarate
        }

/*
		LOG_INF("get otp info %x %x %d.%d.%d %x %x\n",
			    agold_camera_info[g_cur_cam_sensor-1].mf_id,
			    agold_camera_info[g_cur_cam_sensor-1].lens_id,
			    agold_camera_info[g_cur_cam_sensor-1].date[0],
			    agold_camera_info[g_cur_cam_sensor-1].date[1],
			    agold_camera_info[g_cur_cam_sensor-1].date[2],
			   );
*/

		checkVersion = 1;

		//set 0x5002[3] to “1”
        temp1 = OV8858_R2A_read_i2c(0x5002);
        OV8858_R2A_write_i2c(0x5002, (0x08 & 0x08) | (temp1 & (~0x08)));
	}
	OV8858_R2A_write_i2c(0x0100,0x00);// ; stream off

}

