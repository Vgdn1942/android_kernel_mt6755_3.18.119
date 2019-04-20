#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <linux/types.h>


#define PFX "S5K3M2_pdafotp"
#define LOG_INF(format, args...)    pr_debug(PFX "[%s] " format, __FUNCTION__, ##args)

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"



//#if defined(AGOLD_CAMERA_VERSION)

//#include "agold_camera_info.h"
#define BoverGr_dec_base 0x22d  //cur_bg_ratio
#define RoverGr_dec_base 0x332  //cur_rg_ratio
/* 
#else  
#define BoverGr_dec_base 0x22d
#define RoverGr_dec_base 0x332
#endif  
*/
#define GboverGr_dec_base 0x405

#define AWB1X 0x100

extern int g_cur_cam_sensor;

extern int iReadRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u8 * a_pRecvData, u16 a_sizeRecvData, u16 i2cId);
extern int iWriteRegI2C(u8 *a_pSendData , u16 a_sizeSendData, u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);
extern void kdSetI2CSpeed(u16 i2cSpeed);
//extern int iBurstWriteReg_multi(u8 *pData, u32 bytes, u16 i2cId, u16 transfer_length);
extern int iMultiReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId, u8 number);


#define USHORT             unsigned short
#define BYTE               unsigned char
#define Sleep(ms) mdelay(ms)

#define S5K3M2_EEPROM_READ_ID  0xA0   //0xA2
#define S5K3M2_EEPROM_WRITE_ID 0xA1   //  0xA3
#define S5K3M2_I2C_SPEED        100  
#define S5K3M2_MAX_OFFSET		0xFFFF

#define DATA_SIZE 2048
BYTE s5k3m2_eeprom_data[DATA_SIZE]= {0};
//static bool get_done = false;
//static int last_size = 0;
//static int last_offset = 0;



static kal_uint8 g_s5k3m2mipi_write_id = 0x0;  //i2c address 


typedef struct {
//        u8     	proc1_flag;                      // 0x0x790
	u8    	proc1_data[496];		 // 0x791---0x980
//	u8     	proc1_checksum;	                //  0x981
//        u8     	proc2_flag;                     //  0x982     
	u8    	proc2_data[806];		//  0x0983------0x0ca8
//	u8     	proc2_checksum;	                 // 0x0ca9
//        u8     	proc3_flag;                     // 0x0caa
	u8    	proc3_data[102];		// 0x0cab --- 0x0d10
//	u8     	proc3_checksum;	                // 0x0D11
}PDAF_MTK_TYPE;


 
#define s5k3m2_write_cmos_sensor(addr, para) iWriteReg((u16) addr , (u32) para , 1, g_s5k3m2mipi_write_id)

typedef union {
        u8 Data[DATA_SIZE];
        PDAF_MTK_TYPE       MtkPdafData;
} PDAF_DATA_UNIO;

PDAF_DATA_UNIO s5k3m2_pdaf_data = {{0}};

/*
static bool selective_read_eeprom(kal_uint16 addr, BYTE* data)
{
	char pu_send_cmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    if(addr > S5K3M2_MAX_OFFSET)
        return false;
	kdSetI2CSpeed(S5K3M2_I2C_SPEED);

	if(iReadRegI2C(pu_send_cmd, 2, (u8*)data, 1, S5K3M2_EEPROM_READ_ID)<0)
		return false;
    return true;
}
*/

/**********************************************************************/
/*
static bool _read_3m2_eeprom(kal_uint16 addr, BYTE* data, kal_uint32 size ){
	int i = 0;
	int offset = addr;
	for(i = 0; i < size; i++) {
		if(!selective_read_eeprom(offset, &data[i])){
			return false;
		}
		LOG_INF("read_eeprom 0x%0x %d\n",offset, data[i]);
		offset++;
	}
	get_done = true;
	last_size = size;
	last_offset = addr;
    return true;
}
*/
/***************************************************************************/

static int read_cmos_sensor(kal_uint16 slave_id,kal_uint32 addr,u8* data)
{
    char puSendCmd[2] = {(char)(addr >> 8) , (char)(addr & 0xFF) };
    return iReadRegI2C(puSendCmd , 2, data, 1, slave_id);
}


int read_s5k3m2_eeprom(u8 slv_id, u16 offset, u8* data)
{
    int ret = 0;
    ret = read_cmos_sensor(slv_id,offset,data);
//    CAM_CALINF("s5k3m2 read_s5k3m2_eeprom= %x %x\n",offset, *data);
    return ret;
}

int read_s5k3m2_eeprom_size(u8 slv_id, u16 offset, u8* data,int size)
{
	int i = 0;
	for(i = 0; i < size; i++){
		if(read_s5k3m2_eeprom(slv_id, offset+i, data+i) != 0)
			return -1;
	}
	return 0;
}


/**********************************************************************/
void read_otpmodule_id(kal_uint8 * module_id)
{
	kal_uint8  otp_flag = 0;	   
	 
	read_cmos_sensor( S5K3M2_EEPROM_READ_ID,0x0000,&otp_flag);  
	LOG_INF("[S5K3M2][zl] S5K3M2_EEPROM_READ_ID:0x%x ,otp_flag =0x%2x\n", S5K3M2_EEPROM_READ_ID ,otp_flag);
	
/*	if (otp_flag!=0x01)
	{
	    LOG_INF("[zl][s5k3m2] Read OTP failed!!---- \n");  
            return ;
	}
*/
	
	
	read_cmos_sensor( S5K3M2_EEPROM_READ_ID,0x0001,module_id);  
	LOG_INF("[S5K3M2][zbl] S5K3M2_EEPROM_READ_MODULE_ID:0x%x ,module_id =0x%2x\n", S5K3M2_EEPROM_READ_ID ,*module_id);	

	return; 

}

kal_bool S5K3M2CheckLensVersion(void)
{

	kal_uint8  otp_flag = 0;
	
	kal_uint8  data[12] ={0};

	read_cmos_sensor( S5K3M2_EEPROM_READ_ID,0x0000,&otp_flag);  
	LOG_INF("[S5K3M2][zl] S5K3M2_EEPROM_READ_ID:0x%x ,otp_flag =0x%2x\n", S5K3M2_EEPROM_READ_ID ,otp_flag);
	
	if (otp_flag!=0x01)
	{
	    LOG_INF("[zl][s5k3m2] Read OTP failed!!---- \n");  
            return KAL_FALSE;
	}

	read_s5k3m2_eeprom_size(S5K3M2_EEPROM_READ_ID, 0x0001,data,10);	
/*
	agold_camera_info[g_cur_cam_sensor-1].mf_id = data[0];
	agold_camera_info[g_cur_cam_sensor-1].date[0] = data[2];  //year
	agold_camera_info[g_cur_cam_sensor-1].date[1] = data[3];  //month
	agold_camera_info[g_cur_cam_sensor-1].date[2] = data[4];  //data	
	agold_camera_info[g_cur_cam_sensor-1].lens_id = data[6];
	agold_camera_info[g_cur_cam_sensor-1].sen_id = data[9];	


	LOG_INF("[S5K3M2][zl]otp_log read mf_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].mf_id);
	LOG_INF("[S5K3M2][zl]otp_log read lens_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].lens_id);
	LOG_INF("[S5K3M2][zl]otp_log read soft_id,id=0x%2x\n", agold_camera_info[g_cur_cam_sensor-1].sen_id);
*/
	return KAL_TRUE;
	
}



kal_bool update_awb_gain(kal_uint8 i2c_write_id)
{
	kal_uint16 RoverGr_dec;
    	kal_uint16 BoverGr_dec;
    	kal_uint16 GboverGr_dec;

	kal_uint16 R_test;
    	kal_uint16 B_test;
    	kal_uint16 Gr_test;
    	kal_uint16 Gb_test;
	kal_uint16 Gb_test1=0;
 	kal_uint16 Gr_test1=0;
		
	kal_uint8  awb_flag = 0;
	kal_uint8  data[12] ={0};


	g_s5k3m2mipi_write_id = i2c_write_id;
	LOG_INF("[zl] g_s5k3m2mipi_write_id = 0x%x \n",g_s5k3m2mipi_write_id);



	read_cmos_sensor( S5K3M2_EEPROM_READ_ID,0x001c,&awb_flag);  
	LOG_INF("[zl][s5k3m2]awb_flag =0x%2x\n", awb_flag);
	
	if (awb_flag!=0x01)
	{
	    LOG_INF("[zl][s5k3m2] Read awb failed!!---- \n");  
             return KAL_FALSE;
	}

	read_s5k3m2_eeprom_size(S5K3M2_EEPROM_READ_ID, 0x001d,data,12);	

	RoverGr_dec = (data[0]<<8)|data[1];
	BoverGr_dec = (data[2]<<8)|data[3];
	GboverGr_dec = (data[4]<<8)|data[5];

	 LOG_INF("[zl][s5k3m2] RoverG:0x%2x \n",RoverGr_dec);  
	 LOG_INF("[zl][s5k3m2] BoverG:0x%2x \n",BoverGr_dec);  
	 LOG_INF("[zl][s5k3m2] GboverGr:0x%2x \n",GboverGr_dec); 
	 LOG_INF("[zl][s5k3m2] RoverG_dec_base:0x%2x \n",RoverGr_dec_base);  
	 LOG_INF("[zl][s5k3m2] BoverG_dec_base:0x%2x \n",BoverGr_dec_base);   
	 LOG_INF("[zl][s5k3m2] GboverGr_base:0x%2x \n",GboverGr_dec_base);  
  

 if (RoverGr_dec_base==0 || BoverGr_dec_base==0 || GboverGr_dec_base==0)
    {
        return KAL_FALSE;
    }
    if (RoverGr_dec==0 || BoverGr_dec==0 || GboverGr_dec==0)
    {
        return KAL_FALSE;
    }
    if (AWB1X==0)
    {
        return KAL_FALSE;
    }

    
    if (GboverGr_dec<GboverGr_dec_base)
    {
        Gr_test1 = AWB1X;
        Gb_test1 = AWB1X *GboverGr_dec_base/GboverGr_dec;
    }
    else
    {
        Gb_test1 = AWB1X;
        Gr_test1 = AWB1X *GboverGr_dec/GboverGr_dec_base;
    }
    

    if(BoverGr_dec < BoverGr_dec_base) 
    {
        if (RoverGr_dec < RoverGr_dec_base)
        {
            Gr_test = AWB1X;
            B_test = AWB1X * BoverGr_dec_base / BoverGr_dec;
            R_test = AWB1X * RoverGr_dec_base / RoverGr_dec; 
        }
        else 
        {
            R_test = AWB1X;
            Gr_test = AWB1X * RoverGr_dec / RoverGr_dec_base;
            B_test = Gr_test * BoverGr_dec_base / BoverGr_dec;
        }
    }
    else 
    {
        if (RoverGr_dec < RoverGr_dec_base)
        {
            B_test = AWB1X;
            Gr_test = AWB1X * BoverGr_dec / BoverGr_dec_base;
            R_test = Gr_test * RoverGr_dec_base / RoverGr_dec;
        }
        else
        {
            USHORT Gr_test_R, Gr_test_B;
            Gr_test_B = AWB1X * BoverGr_dec / BoverGr_dec_base;
            Gr_test_R = AWB1X * RoverGr_dec / RoverGr_dec_base;
            if(Gr_test_B > Gr_test_R )
            {
                B_test = AWB1X;
                Gr_test = Gr_test_B;
                R_test = Gr_test * RoverGr_dec_base / RoverGr_dec;
            }
            else
            {
                R_test = AWB1X;
                Gr_test = Gr_test_R;
                B_test = Gr_test * BoverGr_dec_base / BoverGr_dec;
            }
        }
    }

	    //
	    R_test = R_test*Gr_test1/AWB1X;
	    B_test = B_test*Gr_test1/AWB1X;
	    Gr_test = Gr_test*Gr_test1/AWB1X;
	    Gb_test = Gr_test*Gb_test1/AWB1X;
	
	//write awb to sensor
	 s5k3m2_write_cmos_sensor(0x6028,0x4000); 
	 s5k3m2_write_cmos_sensor(0x602a,0x020e); 
	 s5k3m2_write_cmos_sensor(0x6f12,Gr_test); 
	 s5k3m2_write_cmos_sensor(0x602a,0x0210); 
	 s5k3m2_write_cmos_sensor(0x6f12,R_test); 
	 s5k3m2_write_cmos_sensor(0x602a,0x0212); 
	 s5k3m2_write_cmos_sensor(0x6f12,B_test); 
	 s5k3m2_write_cmos_sensor(0x602a,0x0214); 
	 s5k3m2_write_cmos_sensor(0x6f12,Gb_test); 

   	 return KAL_TRUE;
}




/*****************************************************************/


kal_bool read_s5k3m2_otp_eeprom( kal_uint16 addr, BYTE* data, kal_uint32 size)
{
	int i;
	//addr_1 = 0x0800;
	//int total_size = 1404;
	size = 1404;
	addr=0xa0;
 	
        

	LOG_INF("read 3m2 eeprom, size = %d\n", size);
	

       	read_s5k3m2_eeprom_size(addr,0x0791,s5k3m2_pdaf_data.MtkPdafData.proc1_data,496);
	memcpy(data, s5k3m2_pdaf_data.MtkPdafData.proc1_data,496);
	for(i = 0; i < 496; i++){
		LOG_INF("s5k3m2_pdaf_data.MtkPdafData.proc1_data[ %d]= %d   \n", i,s5k3m2_pdaf_data.MtkPdafData.proc1_data[i]);	
	}	

       	read_s5k3m2_eeprom_size(addr,0x0983,s5k3m2_pdaf_data.MtkPdafData.proc2_data,806);	
	memcpy(data+496, s5k3m2_pdaf_data.MtkPdafData.proc2_data,806);
	for(i = 0; i < 806; i++){
		LOG_INF("s5k3m2_pdaf_data.MtkPdafData.proc2_data[ %d]= %d   \n", i,s5k3m2_pdaf_data.MtkPdafData.proc2_data[i]);	
	}	

        read_s5k3m2_eeprom_size(addr,0x0cab,s5k3m2_pdaf_data.MtkPdafData.proc3_data,102);
        memcpy(data+496+806, s5k3m2_pdaf_data.MtkPdafData.proc3_data,102);	
	for(i = 0; i < 102; i++){
		LOG_INF("s5k3m2_pdaf_data.MtkPdafData.proc3_data[ %d]= %d   \n", i,s5k3m2_pdaf_data.MtkPdafData.proc3_data[i]);	
	}	
	//c220v35_psmemcpy(data, &s5k3m2_pdaf_data.Data, size);

    return KAL_TRUE;
}



