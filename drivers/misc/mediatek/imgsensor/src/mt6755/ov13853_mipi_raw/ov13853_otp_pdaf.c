#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
//#include <linux/xlog.h>
//#include <asm/system.h>

#include <linux/proc_fs.h>


#include <linux/dma-mapping.h>

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"


#include "ov13853mipiraw_Sensor.h"


#if defined(AGOLD_CAMERA_VERSION)
#include "agold_camera_info.h"
#define BG_Ratio_Typical cur_bg_ratio
#define RG_Ratio_Typical cur_rg_ratio
#else
#define BG_Ratio_Typical 0x269
#define RG_Ratio_Typical 0x275
#endif


/****************************Modify Following Strings for Debug****************************/
#define PFX "OV13853_camera_pdaf"
//#define LOG_1 LOG_INF("OV13853,MIPI 4LANE\n")
//#define LOG_2 LOG_INF("preview 2096*1552@30fps,640Mbps/lane; video 4192*3104@30fps,1.2Gbps/lane; capture 13M@30fps,1.2Gbps/lane\n")
/****************************   Modify end    *******************************************/

#define LOG_INF(format, args...)    pr_err(PFX "[%s] " format, __FUNCTION__, ##args)

//#include "ov13853_otp.h"
struct otp_pdaf_struct {
unsigned char pdaf_flag; //bit[7]--0:empty; 1:Valid
unsigned char data1[496];//output data1
unsigned char data2[806];//output data2
unsigned char data3[102];//output data3
unsigned char pdaf_checksum;//checksum of pd, SUM(0x0801~0x0D7C)%255+1

};

typedef struct {
	u8    	proc1_data[496];		 // 0x791---0x980
//	u8     	proc1_checksum;	                //  0x981
//        u8     	proc2_flag;                     //  0x982
	u8    	proc2_data[876];		//  0x0983------0x0ca8
//	u8     	proc2_checksum;	                 // 0x0ca9
}PDAF_MTK_TYPE;


extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);
extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);

extern void kdSetI2CSpeed(u16 i2cSpeed);


static kal_uint8 g_ov13853mipi_write_id = 0x0;  //i2c address

#define OV13853_EEPROM_READ_ID  0xB1
#define OV13853_EEPROM_WRITE_ID   0xB0
#define I2C_SPEED        400  //CAT24C512 can support 1Mhz

#define START_OFFSET     0x800

#define Delay(ms)  mdelay(ms)
//static unsigned char OV13853MIPI_WRITE_ID = (0xA0 >> 1);
#define MAX_OFFSET       0x0E62
#define DATA_SIZE 4096
//BYTE eeprom_data[DATA_SIZE]= {0};
static bool get_done = false;
static int last_size = 0;
static int last_offset = 0;

typedef union {
        u8 Data[DATA_SIZE];
        PDAF_MTK_TYPE       MtkPdafData;
} PDAF_DATA_UNIO;

PDAF_DATA_UNIO ov13853_pdaf_data = {{0}};

kal_uint16 OV13853_read_i2c(kal_uint32 addr)
{
    kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,g_ov13853mipi_write_id);
    return get_byte;
}



kal_uint16 OV13853_write_i2c(u16 addr, u32 para)
{
		iWriteReg((u16) addr , (u32) para , 1, g_ov13853mipi_write_id);
		return 1;
}



/*
//read pdaf data
int read_otp_pdaf_data(kal_uint16 addr, BYTE* data, kal_uint32 size)
{
	int i = 0;
	LOG_INF("addr :%x, size:%d, \n", addr, size);
	addr = 0x800;
	for (i=0; i<1404;i++)
	{
		data[i] = OV13853_R2A_read_i2c(addr);
		addr++;
		LOG_INF("data[%d] :%x, addr:%x, \n", i, data[i], addr);
    }
	return 0;
}
*/

////

static bool OV13853_selective_read_eeprom(kal_uint16 addr, BYTE* data)
{
	char pu_send_cmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    if(addr > MAX_OFFSET)
        return false;
	kdSetI2CSpeed(I2C_SPEED);

	if(iReadRegI2C(pu_send_cmd, 2, (u8*)data, 1, OV13853_EEPROM_WRITE_ID)<0)
		return false;
    return true;
}


static bool OV13853_read_eeprom(kal_uint16 addr, BYTE* data, kal_uint32 size ){
	int i = 0;
	int offset = addr;

    for(i=0;i<size;i++)
    {
	    if(!OV13853_selective_read_eeprom(offset+i, data+i))
	    {
		    LOG_INF("read_eeprom 0x%0x %d fail \n",offset, data[i]);
		    return false;
	    }
		LOG_INF("read_eeprom 0x%0x 0x%x\n",offset, data[i]);
    }

    return true;
}

bool read_otp_pdaf_data( kal_uint16 addr, BYTE* data, kal_uint32 size){

	LOG_INF("read_otp_pdaf_data enter");
	if(!get_done || last_size != size || last_offset != addr) {
		//if(!_read_eeprom(addr, eeprom_data, size)){
		if(!OV13853_read_eeprom(addr, data, size)){
			get_done = 0;
            last_size = 0;
            last_offset = 0;
			LOG_INF("read_otp_pdaf_data fail");
			return false;
		}
	}
	//memcpy(data, eeprom_data, size);
	LOG_INF("read_otp_pdaf_data end");
    return true;
}


static bool apply_awb_otp(void)
{
    kal_uint8 awb_flag = 0,tempdata = 0;
    int addr = 0x0020;
    int i,rg,bg,R_gain,B_gain,G_gain,Base_gain;
    int check_sum = 0;
    kal_uint8  data[12];

    #if defined (AGOLD_CAMERA_VERSION)	//Add by Lancelot 2014-06-10
	BG_Ratio_Typical=agold_get_bg_ratio(g_cur_cam_sensor-1);
	RG_Ratio_Typical=agold_get_rg_ratio(g_cur_cam_sensor-1);
    #endif

    OV13853_selective_read_eeprom(addr,&awb_flag);
    LOG_INF("zbl awb_flag = 0x%x\n",awb_flag);
    if(awb_flag & 0x80)
    {
        LOG_INF("awb flag right\n");
        for(i=0x0021;i<=0x0036;i++)
        {
         OV13853_selective_read_eeprom(i,&tempdata);
         check_sum += tempdata;
        }
        check_sum = check_sum%255+1;
        OV13853_selective_read_eeprom(0x0037,&tempdata);
        LOG_INF("awb check_sum = 0x%x,tempdata = 0x%x\n",check_sum,tempdata);
        if(check_sum == tempdata)
        {
             LOG_INF("awb checksum ok!!\n");
             OV13853_read_eeprom(addr,data,12);
             rg = (data[2]<<2)|(data[1]&0x03);
             bg = (data[4]<<2)|(data[3]&0x03);

             LOG_INF("zbl rg=0x%x,bg=0x%x\n",rg,bg);

             R_gain = (RG_Ratio_Typical*1000)/rg;
             B_gain = (BG_Ratio_Typical*1000)/bg;
             G_gain = 1000;

             if(R_gain<1000||B_gain<1000)
             {
                if(R_gain<B_gain)
                    Base_gain = R_gain;
                else
                    Base_gain = B_gain;
             }
             else
             {
                Base_gain = G_gain;
             }

             R_gain = 0x400*R_gain/(Base_gain);
             B_gain = 0x400*B_gain/(Base_gain);
             G_gain = 0x400*G_gain/(Base_gain);

             if(R_gain>0x400)
             {
                OV13853_write_i2c(0x5056,R_gain>>8);
                OV13853_write_i2c(0x5057,R_gain&0x00ff);
             }
             if(G_gain>0x400)
             {
                OV13853_write_i2c(0x5058,G_gain>>8);
                OV13853_write_i2c(0x5059,G_gain&0x00ff);
             }
             if(B_gain>0x400)
             {
                OV13853_write_i2c(0x505A,B_gain>>8);
                OV13853_write_i2c(0x505B,B_gain&0x00ff);
             }
        }
        else
        {
            LOG_INF("checksum data failed\n");
            return false;
        }
    }
    else
    {
        LOG_INF("read awb data failed\n");
        return false;
    }
    return true;
}



void ov13853_update_otp(void)
{
    if(!apply_awb_otp())
    LOG_INF("apply awb data failed\n");

}



kal_bool OV13853CheckLensVersion(kal_uint8 i2c_write_id)
{
    static int checkVersion = 0;
    kal_uint8  otp_flag = 0;
	//kal_uint8  ret = 0;
	kal_uint8  data[12] ={0};


    g_ov13853mipi_write_id = i2c_write_id;

    if(!checkVersion)
    {

	OV13853_selective_read_eeprom(0x0000,&otp_flag);
	LOG_INF("ov13853_EEPROM_READ_ID:0x%x ,otp_flag =0x%2x\n", OV13853_EEPROM_WRITE_ID ,otp_flag);

	if (otp_flag!=0x80)
	{
	    LOG_INF("OV13853 Read OTP failed!!---- \n");
            return KAL_FALSE;
	}


	OV13853_read_eeprom(0x0001,data,10);
#if defined(AGOLD_CAMERA_VERSION)
	agold_camera_info[g_cur_cam_sensor-1].mf_id = data[3];
	agold_camera_info[g_cur_cam_sensor-1].date[0] = data[0];  //year
	agold_camera_info[g_cur_cam_sensor-1].date[1] = data[1];  //month
	agold_camera_info[g_cur_cam_sensor-1].date[2] = data[2];  //data
	agold_camera_info[g_cur_cam_sensor-1].lens_id = data[4];
	agold_camera_info[g_cur_cam_sensor-1].sen_id = data[5];

	    LOG_INF("[ov13853][zl]otp_log read mf_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].mf_id);
	    LOG_INF("[ov13853][zl]otp_log read lens_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].lens_id);
	    LOG_INF("[ov13853][zl]otp_log read soft_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].sen_id);
#endif
	    checkVersion = 1;
	}
	return KAL_TRUE;
}

kal_bool read_ov13853_otp_pdaf( kal_uint16 addr, BYTE* data, kal_uint32 size)
{
	int i;

	LOG_INF("read 3m2 eeprom, size = %d\n", size);
    OV13853_read_eeprom(0x0801,ov13853_pdaf_data.MtkPdafData.proc1_data,496);
	memcpy(data, ov13853_pdaf_data.MtkPdafData.proc1_data,496);
	for(i = 0; i < 496; i++){
		LOG_INF("ov13853_pdaf_data.MtkPdafData.proc1_data[ %d]= %d   \n", i,ov13853_pdaf_data.MtkPdafData.proc1_data[i]);
	}
    OV13853_read_eeprom(0x09F1,ov13853_pdaf_data.MtkPdafData.proc2_data,876);
	memcpy(data+496, ov13853_pdaf_data.MtkPdafData.proc2_data,876);
	for(i = 0; i < 876; i++){
		LOG_INF("ov13853_pdaf_data.MtkPdafData.proc2_data[ %d]= %d   \n", i,ov13853_pdaf_data.MtkPdafData.proc2_data[i]);
	}

    return KAL_TRUE;
}
































//
