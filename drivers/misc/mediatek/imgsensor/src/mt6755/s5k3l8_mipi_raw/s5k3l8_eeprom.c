#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/slab.h>



/*===FEATURE SWITH===*/
 // #define FPTPDAFSUPPORT   //for pdaf switch
 // #define FANPENGTAO   //for debug log
 #define LOG_INF LOG_INF_LOD
/*===FEATURE SWITH===*/

/****************************Modify Following Strings for Debug****************************/
#define PFX "S5K3L8PDAF"
#define LOG_INF_NEW(format, args...)    pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)
#define LOG_INF_LOD(format, args...)    pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)
#define LOG_1 LOG_INF("S5K3L8,MIPI 4LANE\n")
#define SENSORDB LOG_INF
/****************************   Modify end    *******************************************/

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"

extern int g_cur_cam_sensor;

extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);
extern void kdSetI2CSpeed(u16 i2cSpeed);
//extern int iBurstWriteReg_multi(u8 *pData, u32 bytes, u16 i2cId, u16 transfer_length);
extern int iMultiReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId, u8 number);


#define USHORT             unsigned short
#define BYTE               unsigned char
#define Sleep(ms)          mdelay(ms)

#ifndef CAMERA_EEPROM_ID_B0
int S5K3L8_EEPROM_READ_ID = 0xA0;
#else
#define S5K3L8_EEPROM_READ_ID  0xB0
#endif

#define S5K3L8_EEPROM_WRITE_ID 0xA1   //  0xA3
#define S5K3L8_I2C_SPEED        100
#define S5K3L8_MAX_OFFSET		0xFFFF
static int s5k3l8_write_id;

#define DATA_SIZE 2048
//BYTE s5k3l8_eeprom_data[DATA_SIZE]= {0};
//static bool get_done = false;
//static int last_size = 0;
//static int last_offset = 0;




#define GAIN_DEFAULT       0x0100
#define GbGr_ratio_Typical  1027

#define RGr_ratio_Typical   0x21d
#define BGr_ratio_Typical   0x210

typedef struct S5K3L8_MIPI_otp_struct{
	kal_uint16 RGr_ratio;
	kal_uint16 BGr_ratio;
	kal_uint16 GbGr_ratio;
}S5K3L8_OTP_TYPE;




#define s5k3l8_write_cmos_sensor(addr, para) iWriteReg((u16) addr , (u32) para , 1, g_s5k3l8mipi_write_id)
//static kal_uint8 g_s5k3l8mipi_write_id = 0x0;  //i2c address

typedef struct {
//        u8     	proc1_flag;                      // 0x0x790
	u8    	proc1_data[496];		 // 0x791---0x980
//	u8     	proc1_checksum;	                //  0x981
//        u8     	proc2_flag;                     //  0x982
	u8    	proc2_data[908];		//  0x0983------0x0ca8
//	u8     	proc2_checksum;	                 // 0x0ca9
//        u8     	proc3_flag;                     // 0x0caa
//	u8    	proc3_data[102];		// 0x0cab --- 0x0d10
//	u8     	proc3_checksum;	                // 0x0D11
}PDAF_MTK_TYPE;



typedef union {
        u8 Data[DATA_SIZE];
        PDAF_MTK_TYPE       MtkPdafData;
} PDAF_DATA_UNIO;

PDAF_DATA_UNIO s5k3l8_pdaf_data = {{0}};

/***************************************************************************/

static int read_cmos_sensor(kal_uint16 slave_id,kal_uint32 addr,u8* data)
{
    char puSendCmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    kdSetI2CSpeed(S5K3L8_I2C_SPEED);
    return iReadRegI2C(puSendCmd , 2, data, 1, slave_id);
}


int read_s5k3l8_eeprom(u8 slv_id, u16 offset, u8* data)
{
    int ret = 0;
    ret = read_cmos_sensor(slv_id,offset,data);
    return ret;
}

int read_s5k3l8_eeprom_size(u8 slv_id, u16 offset, u8* data,int size)
{
	int i = 0;
	for(i = 0; i < size; i++){
		if(read_s5k3l8_eeprom(slv_id, offset+i, data+i) != 0)
			return -1;
	}
	return 0;
}

/**********************************************************************/
static kal_uint8 eeprom_read(kal_uint32 addr)
{
    kal_uint8 get_byte=0;
    char pu_send_cmd[2] = {(char)(addr >> 8), (char)(addr & 0xFF) };
    iReadRegI2C(pu_send_cmd, 2, (u8*)&get_byte, 1, S5K3L8_EEPROM_READ_ID);
    return get_byte;
}

static void write_cmos_sensor_byte(kal_uint32 addr, kal_uint32 para)
{
    char pu_send_cmd[3] = {(char)(addr >> 8), (char)(addr & 0xFF), (char)(para & 0xFF)};

    iWriteRegI2C(pu_send_cmd, 3, s5k3l8_write_id);
}

void S5K3L8_MIPI_read_otp_wb(S5K3L8_OTP_TYPE *otp)
{
   	kal_uint16 RGr_ratio, BGr_ratio, GbGr_ratio;
   	#ifdef S5K3L8_OTP_JLX
  	RGr_ratio = (eeprom_read(0x0C2B)<<8) | eeprom_read(0x0C2C);
  	BGr_ratio = (eeprom_read(0x0C2D)<<8) | eeprom_read(0x0C2E);
  	GbGr_ratio = (eeprom_read(0x0C2F)<<8) | eeprom_read(0x0C30);
  	#elif defined S5K3P8_OTP_BYD
  	RGr_ratio = (eeprom_read(0x0041) | (eeprom_read(0x0042)<<8));
  	BGr_ratio = (eeprom_read(0x0043) | (eeprom_read(0x0044)<<8));
  	GbGr_ratio = (eeprom_read(0x0045) | (eeprom_read(0x0046)<<8));
  	#else 												//elif defined S5K3P8_OTP_SY
  	RGr_ratio = (eeprom_read(0x001D)<<8) | eeprom_read(0x001D);
  	BGr_ratio = (eeprom_read(0x001F)<<8) | eeprom_read(0x0020);
  	GbGr_ratio = (eeprom_read(0x0021)<<8) | eeprom_read(0x0022);
  	#endif
  	printk("[fj],RGr_ratio = 0x%x,BGr_ratio = 0x%x,GbGr_ratio = 0x%x\n",RGr_ratio,BGr_ratio,GbGr_ratio);
   	otp->RGr_ratio = RGr_ratio;
   	otp->BGr_ratio = BGr_ratio;
   	otp->GbGr_ratio = GbGr_ratio;
}

void S5K3L8_MIPI_write_otp_wb(S5K3L8_OTP_TYPE *otp)
{
    int R_gain, B_gain, Gb_gain, Gr_gain, Base_gain;
    kal_uint16 RGr_ratio, BGr_ratio, GbGr_ratio;

    RGr_ratio = otp->RGr_ratio;
    BGr_ratio = otp->BGr_ratio;
    GbGr_ratio = otp->GbGr_ratio;

    R_gain = (RGr_ratio_Typical*1000) / RGr_ratio;
	B_gain = (BGr_ratio_Typical*1000) / BGr_ratio;
	Gb_gain = (GbGr_ratio_Typical*1000) / GbGr_ratio;
	Gr_gain = 1000;
	Base_gain = R_gain;
	if(Base_gain>B_gain) Base_gain = B_gain;
	if(Base_gain>Gb_gain) Base_gain = Gb_gain;
	if(Base_gain>Gr_gain) Base_gain = Gr_gain;
	R_gain = 0x100 * R_gain / Base_gain;
	B_gain = 0x100 * B_gain / Base_gain;
	Gb_gain = 0x100 * Gb_gain / Base_gain;
	Gr_gain = 0x100 * Gr_gain / Base_gain;
	write_cmos_sensor_byte(0x3058,0x01);
	if(Gr_gain>0x100)
		{
		    write_cmos_sensor_byte(0x020E,Gr_gain>>8);
            write_cmos_sensor_byte(0x020F,Gr_gain&0xff);
		}
	if(R_gain>0x100)
		{
		    write_cmos_sensor_byte(0x0210,R_gain>>8);
            write_cmos_sensor_byte(0x0211,R_gain&0xff);
		}
	if(B_gain>0x100)
		{
		    write_cmos_sensor_byte(0x0212,B_gain>>8);
            write_cmos_sensor_byte(0x0213,B_gain&0xff);
		}
	if(Gb_gain>0x100)
		{
		    write_cmos_sensor_byte(0x0214,Gb_gain>>8);
            write_cmos_sensor_byte(0x0215,Gb_gain&0xff);
		}

  	printk("S5K3L8_OTP:Gr_gain=0x%x\n",Gr_gain);
	LOG_INF("S5K3L8_OTP:R_gain=0x%x\n",R_gain);
	LOG_INF("S5K3L8_OTP:B_gain=0x%x\n",B_gain);
	LOG_INF("S5K3L8_OTP:Gb_gain=0x%x\n",Gb_gain);
	LOG_INF("S5K3L8_OTP:End.\n");
}

void S5K3L8_MIPI_update_wb_register_from_otp(void)
{
   S5K3L8_OTP_TYPE current_otp;
   S5K3L8_MIPI_read_otp_wb(&current_otp);
   S5K3L8_MIPI_write_otp_wb(&current_otp);
}


/**********************************************************************/

kal_bool read_s5k3l8_otp_eeprom( kal_uint16 addr, BYTE* data, kal_uint32 size)
{
	int i;
	//addr_1 = 0x0800;
	//int total_size = 1404;
	size = 1404;
	addr=0xa0;



	LOG_INF("read 3m2 eeprom, size = %d\n", size);

    #ifdef S5K3L8_OTP_JLX
    read_s5k3l8_eeprom_size(addr,0x1801,s5k3l8_pdaf_data.MtkPdafData.proc1_data,496);
    #elif defined S5K3P8_OTP_BYD
    read_s5k3l8_eeprom_size(addr,0x0841,s5k3l8_pdaf_data.MtkPdafData.proc1_data,496);
    #else                                     //elif defined S5K3P8_OTP_SY
    read_s5k3l8_eeprom_size(addr,0x0791,s5k3l8_pdaf_data.MtkPdafData.proc1_data,496);
    #endif

	memcpy(data, s5k3l8_pdaf_data.MtkPdafData.proc1_data,496);
	for(i = 0; i < 496; i++){
		printk("s5k3l8_pdaf_data.MtkPdafData.proc1_data[ %d]= %d   \n", i,s5k3l8_pdaf_data.MtkPdafData.proc1_data[i]);
	}

    #ifdef S5K3L8_OTP_JLX
    read_s5k3l8_eeprom_size(addr,0x19F1,s5k3l8_pdaf_data.MtkPdafData.proc2_data,908);
    #elif defined S5K3P8_OTP_BYD
    read_s5k3l8_eeprom_size(addr,0xa31,s5k3l8_pdaf_data.MtkPdafData.proc2_data,908);
    #else 										//elif defined S5K3P8_OTP_SY
    read_s5k3l8_eeprom_size(addr,0x0983,s5k3l8_pdaf_data.MtkPdafData.proc2_data,908);
    #endif
	memcpy(data+496, s5k3l8_pdaf_data.MtkPdafData.proc2_data,908);
	for(i = 0; i < 908; i++){
		printk("s5k3l8_pdaf_data.MtkPdafData.proc2_data[ %d]= %d   \n", i,s5k3l8_pdaf_data.MtkPdafData.proc2_data[i]);
	}

        /*read_s5k3l8_eeprom_size(addr,0x0cab,s5k3l8_pdaf_data.MtkPdafData.proc3_data,102);
        memcpy(data+496+806, s5k3l8_pdaf_data.MtkPdafData.proc3_data,102);
	for(i = 0; i < 102; i++){
		LOG_INF("s5k3l8_pdaf_data.MtkPdafData.proc3_data[ %d]= %d   \n", i,s5k3l8_pdaf_data.MtkPdafData.proc3_data[i]);
	}	*/
	//c220v35_psmemcpy(data, &s5k3l8_pdaf_data.Data, size);

    return KAL_TRUE;
}

/***************************************/
bool s5k3l8CheckLensVersion(int id)
{
    kal_uint8 otp_flag = 0;
    kal_uint8 data[8] = { 0 };
    s5k3l8_write_id=id;
    #ifdef S5K3L8_OTP_JLX
    read_cmos_sensor( S5K3L8_EEPROM_READ_ID,0x0c00,&otp_flag);
    #elif defined S5K3P8_OTP_BYD
    read_cmos_sensor( S5K3L8_EEPROM_READ_ID,0x0000,&otp_flag);
	otp_flag = otp_flag>>7;
	#else 					//elif defined S5K3P8_OTP_SY
	read_cmos_sensor( S5K3L8_EEPROM_READ_ID,0x0000,&otp_flag);
	#endif
    printk("read s5k3l8 otp flag = %d\n", otp_flag);

    if(!otp_flag)
    {
        LOG_INF("[fj]read otp B0 failed,read otp A0 failed!\n");
	#ifdef JK_S5K3L8_COMPATIBLE
	S5K3L8_EEPROM_READ_ID=0xB0;
		read_cmos_sensor( S5K3L8_EEPROM_READ_ID,0x0000,&otp_flag);
    	printk("read s5k3l8 otp flag = %d\n", otp_flag);
    	if(!otp_flag)
	#endif
        return false;
    }

    #ifdef S5K3L8_OTP_JLX
   	read_s5k3l8_eeprom_size(S5K3L8_EEPROM_READ_ID,0x0c01,data,8);
    #elif defined S5K3P8_OTP_BYD
    read_s5k3l8_eeprom_size(S5K3L8_EEPROM_READ_ID, 0x0004,data,8);
	#else                           //    #elif defined S5K3P8_OTP_SY
	read_s5k3l8_eeprom_size(S5K3L8_EEPROM_READ_ID, 0x0001,data,8);
    #endif

    printk("read s5k3l8 otp year = %d\n", data[5]);
    printk("read s5k3l8 otp month = %d\n", data[6]);
    printk("read s5k3l8 otp day = %d\n", data[7]);
    printk("read s5k3l8 otp mid = %d\n", data[0]);
    printk("read s5k3l8 otp Lens_ID = %d\n", data[1]);
	printk("read s5k3l8 otp sen_id = %d\n", data[2]);
    printk("read s5k3l8 otp VCM_ID = %d\n", data[3]);
    printk("read s5k3l8 otp VCM_Driver_ID = %d\n", data[4]);

//    LOG_INF("[fj]read s5k3l8 otp corlo temperature = %d\n", data[8]);

    return true;
}

