/*
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * * VERSION      	DATE			AUTHOR          Note
 *    1.0		  2013-7-16			Focaltech        initial  based on MTK platform
 *
 */

#include "tpd.h"

#include "tpd_custom_fts.h"
#ifdef FTS_CTL_IIC
#include "focaltech_ctl.h"
#endif
#ifdef TPD_SYSFS_DEBUG
#include "focaltech_ex_fun.h"
#endif
#ifdef TPD_PROXIMITY
#include <linux/hwmsensor.h>
#include <linux/hwmsen_dev.h>
#include <linux/sensors_io.h>
#endif

#include <linux/wait.h>

extern unsigned DISP_GetScreenHeight(void);
extern unsigned DISP_GetScreenWidth(void);

#if defined(TPD_ADD_GESTURE)
#define FTS_GESTRUE
extern char *tpd_get_gesture(char *buf_from);
#endif

#ifdef FTS_GESTRUE
#include "ft_gesture_lib.h"
extern u8 *ft_gpDMABuf_va;
short pointnum = 0;
unsigned long time_stamp = 0;
#define FTS_GESTRUE_POINTS 512
static bool g_gesture_active_flag = false;
extern unsigned char g_single_gesture_flag[31];
unsigned short coordinate_x[150] = {0}; //存放X坐标
unsigned short coordinate_y[150] = {0}; //存放Y坐标
unsigned char *buff_en=NULL;
extern int g_gesture_support;
extern int g_gesture_flag;

#endif

extern int fts_i2c_Write_byte(struct i2c_client *client, char reg, int writelen, char *value);
struct Upgrade_Info fts_updateinfo[] =
{
    {0x55,"FT5x06",TPD_MAX_POINTS_5,AUTO_CLB_NEED,50, 30, 0x79, 0x03, 1, 2000},
    {0x08,"FT5606",TPD_MAX_POINTS_5,AUTO_CLB_NEED,50, 30, 0x79, 0x06, 100, 2000},
	{0x0a,"FT5x16",TPD_MAX_POINTS_5,AUTO_CLB_NEED,50, 30, 0x79, 0x07, 1, 1500},
	{0x05,"FT6208",TPD_MAX_POINTS_2,AUTO_CLB_NONEED,60, 30, 0x79, 0x05, 10, 2000},
	{0x06,"FT6x06",TPD_MAX_POINTS_2,AUTO_CLB_NONEED,100, 30, 0x79, 0x08, 10, 2000},
	{0x36,"FT6x36",TPD_MAX_POINTS_2,AUTO_CLB_NONEED,100, 30, 0x79, 0x18, 10, 2000},//CHIP ID error
	{0x55,"FT5x06i",TPD_MAX_POINTS_5,AUTO_CLB_NEED,50, 30, 0x79, 0x03, 1, 2000},
	{0x14,"FT5336",TPD_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000},
	{0x13,"FT3316",TPD_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000},
	{0x12,"FT5436i",TPD_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000},
	{0x11,"FT5336i",TPD_MAX_POINTS_5,AUTO_CLB_NONEED,30, 30, 0x79, 0x11, 10, 2000},
	{0x54,"FT5x46",TPD_MAX_POINTS_5,AUTO_CLB_NONEED,2, 2, 0x54, 0x2c, 10, 2000},
};

struct Upgrade_Info fts_updateinfo_curr;

#ifdef TPD_PROXIMITY
#define APS_ERR(fmt,arg...)           	printk("<<proximity>> "fmt"\n",##arg)
#define TPD_PROXIMITY_DEBUG(fmt,arg...) printk("<<proximity>> "fmt"\n",##arg)
#define TPD_PROXIMITY_DMESG(fmt,arg...) printk("<<proximity>> "fmt"\n",##arg)

static u8 tpd_proximity_flag 			= 0;
static u8 tpd_proximity_flag_one 		= 0; //add for tpd_proximity by wangdongfang
static u8 tpd_proximity_detect 			= 1;//0-->close ; 1--> far away
#endif

extern int g_open_handler;
struct i2c_client *i2c_client = NULL;
struct task_struct *thread = NULL;

static struct proc_dir_entry *proc=NULL;
static ssize_t tpd_version_read_proc(struct file *file, char __user *page, size_t size, loff_t *ppos);

static int tpd_halt =0;
static int boot_mode = 0;

static DECLARE_WAIT_QUEUE_HEAD(waiter);
static DEFINE_MUTEX(i2c_access);


static irqreturn_t tpd_eint_interrupt_handler(int irq, void *dev_id);
// start:Here maybe need port to different platform,like MT6575/MT6577
//extern void mt65xx_eint_unmask(unsigned int line);
//extern void mt65xx_eint_mask(unsigned int line);
//extern void mt65xx_eint_set_hw_debounce(unsigned int eint_num, unsigned int ms);
//extern unsigned int mt65xx_eint_set_sens(unsigned int eint_num, unsigned int sens);
//extern void mt65xx_eint_registration(unsigned int eint_num, unsigned int is_deb_en, unsigned int pol, void (EINT_FUNC_PTR)(void), unsigned int is_auto_umask);
// End:Here maybe need port to different platform,like MT6575/MT6577

static int tpd_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int tpd_remove(struct i2c_client *client);
static int touch_event_handler(void *unused);
static int tpd_i2c_detect(struct i2c_client *client, struct i2c_board_info *info);

static int tpd_flag 					= 0;
static int point_num 					= 0;
static int p_point_num 					= 0;

unsigned int ft_irq = 0;
unsigned int tpd_rst_gpio_number = 0;
unsigned int tpd_int_gpio_number = 0;
//#define TPD_CLOSE_POWER_IN_SLEEP
#define TPD_OK 							0
//register define
#define DEVICE_MODE 					0x00
#define GEST_ID 						0x01
#define TD_STATUS 						0x02
//point1 info from 0x03~0x08
//point2 info from 0x09~0x0E
//point3 info from 0x0F~0x14
//point4 info from 0x15~0x1A
//point5 info from 0x1B~0x20
//register define

#define TPD_RESET_ISSUE_WORKAROUND

#define TPD_MAX_RESET_COUNT 			3
//extern int tpd_mstar_status ;  // compatible mstar and ft6306 chenzhecong

#if (defined(TPD_WARP_START) && defined(TPD_WARP_END))
static int tpd_wb_start_local[TPD_WARP_CNT] = TPD_WARP_START;
static int tpd_wb_end_local[TPD_WARP_CNT]   = TPD_WARP_END;
#endif
#if (defined(TPD_HAVE_CALIBRATION) && !defined(TPD_CUSTOM_CALIBRATION))
static int tpd_calmat_local[8]     = TPD_CALIBRATION_MATRIX;
static int tpd_def_calmat_local[8] = TPD_CALIBRATION_MATRIX;
#endif

#if defined(CTP_FOR_HAND)
static void tpd_handler2(int temp)
{

	#if 1
	int ret = 0;
	u8 buf[2];
	buf[0]=0xc0;
	buf[1]=temp;
	msleep(150);
	if( 0 > (ret = i2c_master_send(i2c_client, buf, 2)))
	{
		printk("[FTS] write reg[0xc0] fail, ret = %d\n",ret);
	}
	#else
    int rett = 0;
    if( 1==temp)
    {

       rett = fts_i2c_Write_byte(i2c_client, 0xc0, 1, &temp);
       if(rett<0)
		TPD_DEBUG("[qrp] %s i2c write file: %d\n", __func__, rett);
    }
    else
    {
        temp =0;
        fts_i2c_Write_byte(i2c_client, 0xc0, 1, &temp);

    }
	#endif
}
#endif
static ssize_t tpd_version_read_proc(struct file *file, char __user *page, size_t size, loff_t *ppos)
{
	char *ptr=page;
    char fw_version ;
	if((i2c_smbus_read_i2c_block_data(i2c_client, 0xA6, 1, &fw_version))< 0)
	{
		TPD_DEBUG("[FTS]read tpd firmware version failed\n");
	}
	ptr+=sprintf(ptr,"[FTS] fw_version=0x%x!!!\n",fw_version);
	return (ptr-page);
}

static const struct file_operations ft_tpd_version_fops =
{
    .write = NULL,
    .read = tpd_version_read_proc,
};

#ifdef FTS_GESTRUE
static void check_gesture(int gesture_id)
{
	int flag = 1;
	char gesture_tmp[16];
	if(g_gesture_active_flag != true)
	{
		switch(gesture_id)
    	{

			case 0x20:
			if(g_single_gesture_flag[3] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"left");
				TPD_DEBUG("Input Gesture 'left'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			case 0x21:
			if(g_single_gesture_flag[4] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"right");
				TPD_DEBUG("Input Gesture 'right'\n");
		    }
		    else
		    {
		    	flag = 0;
		        strcpy(gesture_tmp,"default");
		    }
			break;

			case 0x22:
			if(g_single_gesture_flag[1] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"up");
				TPD_DEBUG("Input Gesture 'up'\n");
		    }
		    else
		    {
		    	flag = 0;
				strcpy(gesture_tmp,"default");
		    }
			break;

			case 0x23:
			if(g_single_gesture_flag[2] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"down");
				TPD_DEBUG("Input Gesture 'down'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			case 0x24:
			if(g_single_gesture_flag[0] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"doubletap");
				TPD_DEBUG("Input Gesture 'doubletap'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			case 0x30:
			if(g_single_gesture_flag[9] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"o");
				TPD_DEBUG("Input Gesture 'o'\n");
		    }
		    else
		    {
		    	flag = 0;
		        strcpy(gesture_tmp,"default");
		    }
			break;

			case 0x31:
			if(g_single_gesture_flag[12] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"w");
				TPD_DEBUG("Input Gesture 'w'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			case 0x32:
			if(g_single_gesture_flag[8] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"m");
				TPD_DEBUG("Input Gesture 'm'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			case 0x33:
			if(g_single_gesture_flag[6] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"e");
				TPD_DEBUG("Input Gesture 'e'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			case 0x34:
			if(g_single_gesture_flag[5] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"c");
				TPD_DEBUG("Input Gesture 'c'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			#ifdef LEMU_ADD_GESTURE_Z
			case 0x65:
			#else
			case 0x41:
			#endif
			TPD_DEBUG("Input Gesture '0x65'\n");
			if(g_single_gesture_flag[13] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"z");
				TPD_DEBUG("Input Gesture 'z'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;

			case 0x46:
			if(g_single_gesture_flag[10] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"s");
				TPD_DEBUG("Input Gesture 's'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;
			case 0x54:
			if(g_single_gesture_flag[11] && g_gesture_flag)
			{
				flag = 1;
				strcpy(gesture_tmp,"v");
				TPD_DEBUG("Input Gesture 'v'\n");
			}
			else
			{
				flag = 0;
			    strcpy(gesture_tmp,"default");
			}
			break;
			default:
				flag = 0;
				strcpy(gesture_tmp,"default");
				TPD_DEBUG("There input char is not match\n");
			break;
		}
		TPD_DEBUG("Bruce gesture_tmp = %s\n",gesture_tmp);
		if (flag == 1)
		{
			g_gesture_active_flag = true;
			tpd_get_gesture(gesture_tmp);
			msleep(10);

			input_report_key(tpd->dev, KEY_TV, 1);

			input_sync(tpd->dev);
			msleep(10);
			input_report_key(tpd->dev, KEY_TV, 0);
			input_sync(tpd->dev);

		}
	}
}
#ifdef TP_FT5346_FOR_GESTURE
#else
static int fts_i2c_Read_BIGGER_255(struct i2c_client *client, char *writebuf,
		    int writelen, char *readbuf, int readlen)
{
    int ret1 =0;
    int ret2 =0 ;
	if( readlen < 230 )
	{
	    ret1=	fts_i2c_Read(client, writebuf, writelen,  readbuf,readlen);
	    TPD_DEBUG("  received length in fts_i2c_Read_BIGGER_255 is   %d\n",(ret1));
	}
	else
	{
	    ret1 =	fts_i2c_Read(client, writebuf,writelen,readbuf,230);
	    TPD_DEBUG("  ret1 received length in fts_i2c_Read_BIGGER_255 is   %d\n",(ret1));
	    ret2 =	fts_i2c_Read(client, writebuf,0       ,readbuf+230,(readlen-230));
		//ret1 = i2c_read_bytes_dma(i2c_client, *writebuf, readbuf+230, (readlen-230);
	    TPD_DEBUG(" ret2  received length in fts_i2c_Read_BIGGER_255 is   %d\n",(ret2));
	}

	return (ret1+ ret2) ;
}
#endif
static int tpd_gesture_handle2(void)
{
	unsigned char buf[FTS_GESTRUE_POINTS * 2] = { 0 };
	int ret = -1;
	int gestrue_id = 0;
	buf[0] = 0xd3;

	ret = i2c_smbus_read_i2c_block_data(i2c_client, 0xD3, 8, buf);
	#ifdef TP_FT5346_FOR_GESTURE

	if (ret < 0)
	{
	    TPD_DEBUG("[qrp] line:%d read error\n",__LINE__);
		return ret;
	}
	else
	{
		//gestrue_id = 0x24;
		gestrue_id = buf[0];

	}
	TPD_DEBUG("gestrue_id =  %02X \n ",gestrue_id);
    check_gesture(gestrue_id);
 	return 0;
 	#else

	if (ret < 0)
	{
	    TPD_DEBUG("[qrp] line:%d read error\n",__LINE__);
		return ret;
	}
	if (0x24 == buf[0])
	{
		gestrue_id = 0x24;
		check_gesture(gestrue_id);
		return -1;
	}
	pointnum = (short)(buf[1]) & 0xff;
	buf[0] = 0xd3;

    TPD_DEBUG("pointnum = %d\n", pointnum);

    ret = fts_i2c_Read_BIGGER_255(i2c_client,buf,1,buf,(pointnum*4+8));
	TPD_DEBUG("fts_i2c_Read_BIGGER_255  return count is %d\n",ret);

    if (ret < 0)
	{
	    TPD_DEBUG("qrp fts_i2c_Read_BIGGER_255 error\n");
		return ret;
	}

	gestrue_id = fetch_object_sample(buf,pointnum);
	TPD_DEBUG("gestrue_id =  %02X \n ",gestrue_id);
    check_gesture(gestrue_id);
 	return 0;
 	#endif
}
#endif
struct touch_info
{
    int y[10];
    int x[10];
    int p[10];
    int id[10];
};

static const struct i2c_device_id ft5406_tpd_id[] = {{TPD_NAME,0},{}};
static unsigned short force[] = {0, 0x70, I2C_CLIENT_END, I2C_CLIENT_END};
static const unsigned short *const forces[] = { force, NULL };

static const struct of_device_id ft5406_dt_match[] =
{
	{.compatible = "mediatek,cap_touch"},
	{},
};
MODULE_DEVICE_TABLE(of, ft5406_dt_match);

static struct i2c_driver tpd_i2c_driver =
{
	.driver =
	{
		.of_match_table = ft5406_dt_match,
		.name = "FT5406_MT",
	},
	.probe = tpd_probe,
	.remove = tpd_remove,
	.id_table = ft5406_tpd_id,
	.detect = tpd_i2c_detect,
	.address_list = (const unsigned short *) forces,
};


static  void tpd_down(int x, int y, int p, int id)
{
#ifdef TPD_HAVE_BUTTON
	if((0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3))||(0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2)))
    {
		if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && x>=TPD_RES_Y)
		{
			int temp;
			temp = y;
			y = x;
			x = TPD_RES_X-temp;
			tpd_button(x, y, 1);
			return;
		}
		else if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && y>=TPD_RES_Y)
		{
			tpd_button(x, y, 1);
			return;
		}
	}
	else if((0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3)))
	{
		if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && y>=TPD_RES_Y)
		{

			tpd_button(TPD_RES_X-x, TPD_RES_Y-y, 1);

			return;
		}
	}
    else
	{
		if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && y>=TPD_RES_Y)
		{
			tpd_button(x, y, 1);
			return;
		}
	}
#endif
	// input_report_abs(tpd->dev, ABS_PRESSURE, p);
	input_report_key(tpd->dev, BTN_TOUCH, 1);
/*
	if ((!p) && (!id))
	{
		//for virtual button
		input_report_abs(tpd->dev, ABS_MT_PRESSURE, 100);
		input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, 100);
	}
	else
	{
		input_report_abs(tpd->dev, ABS_MT_PRESSURE, p);
		input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, p);
		input_report_abs(tpd->dev, ABS_MT_TRACKING_ID, id);
	}
*/

	input_report_abs(tpd->dev, ABS_MT_PRESSURE, 100);
	input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, 100);
	input_report_abs(tpd->dev, ABS_MT_TRACKING_ID, id);

    input_report_abs(tpd->dev, ABS_MT_POSITION_X, x);
	input_report_abs(tpd->dev, ABS_MT_POSITION_Y, y);

	input_mt_sync(tpd->dev);
	TPD_EM_PRINT(x, y, x, y, p-1, 1);
}

static  void tpd_up(int x, int y)
{
	//input_report_abs(tpd->dev, ABS_PRESSURE, 0);
	input_report_key(tpd->dev, BTN_TOUCH, 0);
	//input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, 0);
	//input_report_abs(tpd->dev, ABS_MT_POSITION_X, x);
	//input_report_abs(tpd->dev, ABS_MT_POSITION_Y, y);
	//TPD_DEBUG("U[%4d %4d %4d] ", x, y, 0);
	input_mt_sync(tpd->dev);
	TPD_EM_PRINT(x, y, x, y, 0, 0);
#ifdef TPD_HAVE_BUTTON
	if((0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3))||(0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2)))
    {
		if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && x>=TPD_RES_Y)
		{
			int temp;
			temp = y;
			y = x;
			x = TPD_RES_X-temp;
			tpd_button(x, y, 0);
			return;
		}
		else if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && y>=TPD_RES_Y)
		{
			tpd_button(x, y, 0);
			return;
		}
	}
	else if((0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3)))
	{
		if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && y>=TPD_RES_Y)
		{
			tpd_button(TPD_RES_X-x, TPD_RES_Y-y, 0);
			return;
		}
	}
    else
	{
		if((boot_mode==FACTORY_BOOT || boot_mode==RECOVERY_BOOT) && y>=TPD_RES_Y)
		{
			tpd_button(x, y, 0);
			return;
		}
	}
#endif
}

static int tpd_touchinfo(struct touch_info *cinfo, struct touch_info *pinfo)
{
	int i = 0;
	//#if (TPD_MAX_POINTS==2)
	//	char data[35] = {0};
	//#else
	//	char data[16] = {0};
	//#endif
	char data[128] = {0};
    u16 high_byte,low_byte;

	char reg = 0x0;
	p_point_num = point_num;
	if (tpd_halt)
	{
		TPD_DMESG( "tpd_touchinfo return ..\n");
		return false;
	}
	mutex_lock(&i2c_access);

    reg = 0x00;
	//TPD_DEBUG("[shipl] tpd_touchinfo ,i2c_client.addr = 0x%x, &reg = %p\n",i2c_client->addr, &reg);

	//i2c_write_bytes_dma(i2c_client, reg, &reg, 1);
	//i2c_read_bytes_dma(i2c_client, reg, data, 64);
	fts_i2c_Read(i2c_client, &reg, 1, data, 64);
	mutex_unlock(&i2c_access);
	//TPD_DEBUG("received raw data from touch panel as following:\n");
	//TPD_DEBUG("[data[0]=%x,data[1]= %x ,data[2]=%x ,data[3]=%x ,data[4]=%x ,data[5]=%x]\n",data[0],data[1],data[2],data[3],data[4],data[5]);
	//TPD_DEBUG("[data[9]=%x,data[10]= %x ,data[11]=%x ,data[12]=%x]\n",data[9],data[10],data[11],data[12]);
	//TPD_DEBUG("[data[15]=%x,data[16]= %x ,data[17]=%x ,data[18]=%x]\n",data[15],data[16],data[17],data[18]);

	/*get the number of the touch points*/
	point_num= data[2] & 0x0f;

	//TPD_DEBUG("point_num =%d\n",point_num);

	for(i = 0; i < point_num; i++)
	{
		cinfo->p[i] = data[3+6*i] >> 6; //event flag
     	cinfo->id[i] = data[3+6*i+2]>>4; //touch id
	   	/*get the X coordinate, 2 bytes*/
		high_byte = data[3+6*i];
		high_byte <<= 8;
		high_byte &= 0x0f00;
		low_byte = data[3+6*i + 1];
		cinfo->x[i] = high_byte |low_byte;

		//cinfo->x[i] =  cinfo->x[i] * 480 >> 11; //calibra

		/*get the Y coordinate, 2 bytes*/

		high_byte = data[3+6*i+2];
		high_byte <<= 8;
		high_byte &= 0x0f00;
		low_byte = data[3+6*i+3];
		cinfo->y[i] = high_byte |low_byte;

		#if defined(TPD_COMPAT_LCM_RESOLUTION)
		cinfo->x[i] = cinfo->x[i]*DISP_GetScreenWidth()/TPD_RES_X;
		cinfo->y[i] = cinfo->y[i]*DISP_GetScreenHeight()/TPD_RES_Y;
		#endif


		 //cinfo->y[i]=  cinfo->y[i] * 800 >> 11;
	}
	//TPD_DEBUG(" cinfo->x[0] = %d, cinfo->y[0] = %d, cinfo->p[0] = %d\n", cinfo->x[0], cinfo->y[0], cinfo->p[0]);
	//TPD_DEBUG(" cinfo->x[1] = %d, cinfo->y[1] = %d, cinfo->p[1] = %d\n", cinfo->x[1], cinfo->y[1], cinfo->p[1]);
	//TPD_DEBUG(" cinfo->x[2]= %d, cinfo->y[2]= %d, cinfo->p[2] = %d\n", cinfo->x[2], cinfo->y[2], cinfo->p[2]);

	return true;
};

#ifdef TPD_PROXIMITY
int tpd_read_ps(void)
{
	tpd_proximity_detect;
	return 0;
}

static int tpd_get_ps_value(void)
{
	return tpd_proximity_detect;
}

static int tpd_enable_ps(int enable)
{
	u8 state;
	int ret = -1;

	i2c_smbus_read_i2c_block_data(i2c_client, 0xB0, 1, &state);
	TPD_DEBUG("[proxi_5206]read: 999 0xb0's value is 0x%02X\n", state);
	if (enable)
	{
		state |= 0x01;
		tpd_proximity_flag = 1;
		TPD_PROXIMITY_DEBUG("[proxi_5206]ps function is on\n");
	}
	else
	{
		state &= 0x00;
		tpd_proximity_flag = 0;
		TPD_PROXIMITY_DEBUG("[proxi_5206]ps function is off\n");
	}

	ret = fts_i2c_Write_byte(i2c_client, 0xB0, 1, &state);
	TPD_PROXIMITY_DEBUG("[proxi_5206]write: 0xB0's value is 0x%02X\n", state);
	return 0;
}

int tpd_ps_operate(void* self, uint32_t command, void* buff_in, int size_in,
		void* buff_out, int size_out, int* actualout)
{
	int err = 0;
	int value;

	hwm_sensor_data *sensor_data;
	TPD_DEBUG("[proxi_5206]command = 0x%02X\n", command);
	switch (command)
	{
		case SENSOR_DELAY:
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				APS_ERR("Set delay parameter error!\n");
				err = -EINVAL;
			}
			// Do nothing
			break;

		case SENSOR_ENABLE:
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				APS_ERR("Enable sensor parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				value = *(int *)buff_in;
				if(value)
				{
					if((tpd_enable_ps(1) != 0))
					{
						APS_ERR("enable ps fail: %d\n", err);
						return -1;
					}
				}
				else
				{
					if((tpd_enable_ps(0) != 0))
					{
						APS_ERR("disable ps fail: %d\n", err);
						return -1;
					}
				}
			}
			break;

		case SENSOR_GET_DATA:
			if((buff_out == NULL) || (size_out< sizeof(hwm_sensor_data)))
			{
				APS_ERR("get sensor data parameter error!\n");
				err = -EINVAL;
			}
			else
			{

				sensor_data = (hwm_sensor_data *)buff_out;

				if((err = tpd_read_ps()))
				{
					err = -1;;
				}
				else
				{
					sensor_data->values[0] = tpd_get_ps_value();
					TPD_PROXIMITY_DEBUG("huang sensor_data->values[0] 1082 = %d\n", sensor_data->values[0]);
					sensor_data->value_divide = 1;
					sensor_data->status = SENSOR_STATUS_ACCURACY_MEDIUM;
				}

			}
			break;
		default:
			APS_ERR("proxmy sensor operate function no this parameter %d!\n", command);
			err = -1;
			break;
	}

	return err;
}
#endif

static int touch_event_handler(void *unused)
{

   	struct touch_info cinfo, pinfo;
	int i=0;

	struct sched_param param = { .sched_priority = 4 };
	sched_setscheduler(current, SCHED_RR, &param);
#ifdef TPD_PROXIMITY
	int err;
	hwm_sensor_data sensor_data;
	u8 proximity_status;
	u8 state;
#endif

	do
	{
		enable_irq(ft_irq);
		set_current_state(TASK_INTERRUPTIBLE);
		wait_event_interruptible(waiter,tpd_flag!=0);

		tpd_flag = 0;

		set_current_state(TASK_RUNNING);
    #ifdef FTS_GESTRUE
		if( g_gesture_flag && (tpd_halt==1))
			 tpd_gesture_handle2();
	#endif
#ifdef TPD_PROXIMITY
		if (tpd_proximity_flag == 1)
		{
			i2c_smbus_read_i2c_block_data(i2c_client, 0xB0, 1, &state);
			TPD_PROXIMITY_DEBUG("proxi_5206 0xB0 state value is 1131 0x%02X\n", state);

			if(!(state&0x01))
			{
				tpd_enable_ps(1);
			}

			i2c_smbus_read_i2c_block_data(i2c_client, 0x01, 1, &proximity_status);
			TPD_PROXIMITY_DEBUG("proxi_5206 0x01 value is 1139 0x%02X\n", proximity_status);

			if (proximity_status == 0xC0)
			{
				tpd_proximity_detect = 0;
			}
			else if(proximity_status == 0xE0)
			{
				tpd_proximity_detect = 1;
			}

			TPD_PROXIMITY_DEBUG("tpd_proximity_detect 1149 = %d\n", tpd_proximity_detect);

			if ((err = tpd_read_ps()))
			{
				TPD_PROXIMITY_DMESG("proxi_5206 read ps data 1156: %d\n", err);
			}
			sensor_data.values[0] = tpd_get_ps_value();
			sensor_data.value_divide = 1;
			sensor_data.status = SENSOR_STATUS_ACCURACY_MEDIUM;
			if ((err = hwmsen_get_interrupt_data(ID_PROXIMITY, &sensor_data)))
			{
				TPD_PROXIMITY_DMESG(" proxi_5206 call hwmsen_get_interrupt_data failed= %d\n", err);
			}
		}
#endif

		if (tpd_touchinfo(&cinfo, &pinfo))
		{
		    //TPD_DEBUG("point_num = %d\n",point_num);
			TPD_DEBUG_SET_TIME;
			if(point_num >0)
			{
			    for(i =0; i<point_num; i++)//only support 3 point
			    {
			    	 tpd_down(cinfo.x[i], cinfo.y[i],cinfo.p[i], cinfo.id[i]);
			       // tpd_down(cinfo.x[i]*1080/540, cinfo.y[i]*1920/960, cinfo.p[i], cinfo.id[i]);
					printk("[psw]chifo.x[i] = %d,chifo.y[i] = %d,cinfo.id[i] = %d\n",cinfo.x[i], cinfo.y[i], cinfo.id[i]);
			    }
			    input_sync(tpd->dev);
			}
			else
    		{
			    tpd_up(cinfo.x[0], cinfo.y[0]);
        	    //TPD_DEBUG("release --->\n");
        	    //input_mt_sync(tpd->dev);
        	    input_sync(tpd->dev);
        	}
        }
 	}while(!kthread_should_stop());

	return 0;
}

static int tpd_i2c_detect(struct i2c_client *client, struct i2c_board_info *info)
{
	strcpy(info->type, TPD_DEVICE);

	return 0;
}

static irqreturn_t tpd_eint_interrupt_handler(int irq, void *dev_id)
{
	TPD_DEBUG("TPD interrupt has been triggered\n");
	tpd_flag = 1;
	wake_up_interruptible(&waiter);
	return IRQ_HANDLED;
}

static int tpd_irq_registration(void)
{
	struct device_node *node = NULL;
	int ret = 0;
	u32 ints[2] = { 0, 0 };

	TPD_DEBUG("Device Tree Tpd_irq_registration!");

	node = of_find_matching_node(node, touch_of_match);
	if (node)
	{
		of_property_read_u32_array(node, "debounce", ints, ARRAY_SIZE(ints));
		gpio_set_debounce(ints[0], ints[1]);
		ft_irq = irq_of_parse_and_map(node, 0);
		ret = request_irq(ft_irq, (irq_handler_t) tpd_eint_interrupt_handler, IRQF_TRIGGER_FALLING, "TOUCH_PANEL-eint", NULL);
		if (ret > 0)
		{
			ret = -1;
		}
	}
	else
	{
		TPD_DEBUG("tpd request_irq can not find touch eint device node!.");
		ret = -1;
	}
	TPD_DEBUG("[%s]irq:%d, debounce:%d-%d:", __func__, ft_irq, ints[0], ints[1]);
	return ret;
}

void focaltech_get_upgrade_array(void)
{
	u8 chip_id;
	u32 i;

	i2c_smbus_read_i2c_block_data(i2c_client,FT_REG_CHIP_ID,1,&chip_id);

	TPD_DEBUG("%s chip_id = %x\n", __func__, chip_id);
    //TPD_DEBUG("[Bruce trace]%s force chip_id = %x\n", __func__, chip_id);
    #if defined(DFL_C221_FOR_TRULY)
    chip_id = 0x12;
    #endif
	for(i=0;i<sizeof(fts_updateinfo)/sizeof(struct Upgrade_Info);i++)
	{
		if(chip_id==fts_updateinfo[i].CHIP_ID)
		{
			memcpy(&fts_updateinfo_curr, &fts_updateinfo[i], sizeof(struct Upgrade_Info));
			break;
		}
	}

	if(i >= sizeof(fts_updateinfo)/sizeof(struct Upgrade_Info))
	{
		memcpy(&fts_updateinfo_curr, &fts_updateinfo[0], sizeof(struct Upgrade_Info));
	}
}

static int tpd_probe(struct i2c_client *client, const struct i2c_device_id *id)
{

	int retval = TPD_OK;
	char data,fw_version;
	//int reset_count = 0;
 	client->addr = 0x38;
//reset_proc:
	i2c_client = client;
	//power on

	retval = regulator_enable(tpd->reg);
	msleep(100);
/*
	retval = gpio_request_one(tpd_rst_gpio_number, GPIOF_OUT_INIT_LOW,"touchp_reset");
	if (retval < 0)
	{
		printk("[psw]Unable to request gpio reset_pin\n");
		return -1;
	}
*/
	tpd_gpio_output(GPIO_CTP_RST_PIN, 1);
	mdelay(2);
	tpd_gpio_output(GPIO_CTP_RST_PIN, 0);
	mdelay(2);
	tpd_gpio_output(GPIO_CTP_RST_PIN, 1);
	mdelay(2);


/*	retval = gpio_request_one(tpd_int_gpio_number, GPIOF_IN,"tpd_int");
	if (retval < 0)
	{
		TPD_DMESG("Unable to request gpio int_pin\n");
		gpio_free(tpd_rst_gpio_number);
		return -1;
	}
 	gpio_direction_input(tpd_int_gpio_number);
*/

	msleep(400);

 	boot_mode = get_boot_mode();

	if((i2c_smbus_read_i2c_block_data(i2c_client, 0x00, 1, &data))< 0)
	{
		TPD_DEBUG("[psw]I2C transfer error, line: %d\n", __LINE__);
/*
#ifdef TPD_RESET_ISSUE_WORKAROUND
        if ( reset_count < TPD_MAX_RESET_COUNT )
        {
            reset_count++;
            printk("[chenpeng][ft5406] [LINE=%d][reset_count=%d]\n",__LINE__,reset_count);
            goto reset_proc;
        }
#endif
*/
		tpd_load_status = -1;
		return -1;
	}

	tpd_irq_registration();
	enable_irq(ft_irq);

	if((i2c_smbus_read_i2c_block_data(i2c_client, 0xA6, 1, &fw_version))>= 0)
	{
		TPD_DEBUG("[FTS]fw_version = 0x%x\n",fw_version);
	}
	#if defined(CTP_FOR_HAND)
	tpd_handler2(g_open_handler);
	#endif

	tpd_load_status = 1;

	focaltech_get_upgrade_array();

	#ifdef FTS_APK_DEBUG
	ft5x0x_create_apk_debug_channel(client);
	#endif
	#ifdef TPD_SYSFS_DEBUG
	fts_create_sysfs(i2c_client);
	#endif
	#ifdef FTS_GESTRUE

    if(!ft_gpDMABuf_va)
	{
		TPD_DMESG("dme malloc error\n");

	    data = 0x01;
		retval = fts_i2c_Write_byte(i2c_client, 0xd0, 1, &data);
		printk(" %s, wrinte i2c reg0xd0 ,data=%d, retval=%d\n", __FUNCTION__,data,retval);

		/*All gesture on*/
		data = 0xff;
		retval = fts_i2c_Write_byte(i2c_client, 0xd1, 1, &data);
		printk(" %s, wrinte i2c reg0xd0 ,data=%d, retval=%d\n", __FUNCTION__,data,retval);

		data = 0x1f;
		retval = fts_i2c_Write_byte(i2c_client, 0xd2, 1, &data);
		printk(" %s, wrinte i2c reg0xd0 ,data=%d, retval=%d\n", __FUNCTION__,data,retval);

	    data = 0xff;
		retval = fts_i2c_Write_byte(i2c_client, 0xd5, 1, &data);
		printk(" %s, wrinte i2c reg0xd0 ,data=%d, retval=%d\n", __FUNCTION__,data,retval);

		data = 0xff;
		retval = fts_i2c_Write_byte(i2c_client, 0xd6, 1, &data);
		printk(" %s, wrinte i2c reg0xd0 ,data=%d, retval=%d\n", __FUNCTION__,data,retval);

		data = 0xff;
		retval = fts_i2c_Write_byte(i2c_client, 0xd7, 1, &data);
		printk(" %s, wrinte i2c reg0xd0 ,data=%d, retval=%d\n", __FUNCTION__,data,retval);

		dev_dbg(&client->dev,"%s Allocate DMA I2C Buffer failed!\n",__func__);
		return -EIO;
	}

	g_gesture_support=0X3F7F;

    input_set_capability(tpd->dev, EV_KEY, KEY_POWER);//Bruce
    input_set_capability(tpd->dev, EV_KEY, KEY_TV);
    #endif

	#ifdef FTS_CTL_IIC
	if (ft_rw_iic_drv_init(i2c_client) < 0)
		TPD_DMESG("%s:[FTS] create fts control iic driver failed\n",__func__);
	#endif

	#ifdef VELOCITY_CUSTOM_FT5206
	if((retval = misc_register(&tpd_misc_device)))
	{
		TPD_DEBUG("mtk_tpd: tpd_misc_device register failed\n");

	}
	#endif

	#ifdef TPD_FT_AUTO_UPGRADE
	TPD_DEBUG("********************Enter CTP Auto Upgrade********************\n");
	fts_ctpm_auto_upgrade(i2c_client);
	#endif

	thread = kthread_run(touch_event_handler, 0, TPD_DEVICE);
	if (IS_ERR(thread))
	{
		retval = PTR_ERR(thread);
		TPD_DMESG(TPD_DEVICE " failed to create kernel thread: %d\n", retval);
	}

	TPD_DMESG("FTS Touch Panel Device Probe %s\n", (retval < TPD_OK) ? "FAIL" : "PASS");

	if((proc=proc_create("tpd_version",0664,NULL,&ft_tpd_version_fops))==NULL)
	{
		TPD_DEBUG("tpd_version proc_create error\n");
	}

#ifdef TPD_PROXIMITY
	struct hwmsen_object obj_ps;

	obj_ps.polling = 0;//interrupt mode
	obj_ps.sensor_operate = tpd_ps_operate;
	if((retval = hwmsen_attach(ID_PROXIMITY, &obj_ps)))
	{
		APS_ERR("proxi_fts attach fail = %d\n", retval);
	}
	else
	{
		APS_ERR("proxi_fts attach ok = %d\n", retval);
	}
#endif
   return 0;

 }

static int tpd_remove(struct i2c_client *client)
{

	#ifdef FTS_APK_DEBUG
	ft5x0x_release_apk_debug_channel();
	#endif
   	#ifdef TPD_SYSFS_DEBUG
	fts_release_sysfs(client);
	#endif

	#ifdef FTS_CTL_IIC
	ft_rw_iic_drv_exit();
	#endif

	TPD_DEBUG("TPD removed\n");

   	return 0;
}

static int tpd_power_enable(int enable)
{
	int ret = 0;
	TPD_DEBUG("Device Tree get regulator!");
#if !defined CONFIG_MTK_LEGACY

	//tpd->reg = regulator_get(tpd->tpd_dev, "vtouch");
	ret = regulator_set_voltage(tpd->reg, 2800000, 2800000);	/*set 2.8v*/
	if (ret) {
		TPD_DEBUG("regulator_set_voltage(%d) failed!\n", ret);
		return -1;
	}
	if(enable)
	{
		ret = regulator_enable(tpd->reg);	/*enable regulator*/
		if (ret)
		{
			TPD_DEBUG("regulator_enable() failed!\n");
		}
	}
	else
	{
		ret = regulator_disable(tpd->reg);	/*disable regulator*/
		if (ret)
		{
			TPD_DEBUG("regulator_disable() failed!\n");
		}
	}
#endif
	return ret;
}

static int tpd_local_init(void)
{
	int retval;

	tpd->reg = regulator_get(tpd->tpd_dev, "vtouch");
    if (IS_ERR(tpd->reg)) {
        TPD_DEBUG("regulator_get() failed.");
        return 0;
    }
	retval = regulator_set_voltage(tpd->reg, 2800000, 2800000);
	if (retval != 0)
	{
		TPD_DEBUG("Failed to set reg-vgp6 voltage: %d\n", retval);
		return -1;
	}
   	if(i2c_add_driver(&tpd_i2c_driver)!=0)
   	{
  		TPD_DEBUG("FTS unable to add i2c driver.\n");
      	return -1;
    }
    if(tpd_load_status == -1)
    {
    	TPD_DEBUG("FTS add error touch panel driver.\n");
    	tpd_power_enable(0);
    	i2c_del_driver(&tpd_i2c_driver);
    	return -1;
    }

#ifdef TPD_HAVE_BUTTON
	if (tpd_dts_data.use_tpd_button)
	{
		/*initialize tpd button data*/
		tpd_button_setting(tpd_dts_data.tpd_key_num, tpd_dts_data.tpd_key_local,
		tpd_dts_data.tpd_key_dim_local);
	}
#endif

#if (defined(TPD_WARP_START) && defined(TPD_WARP_END))
    TPD_DO_WARP = 1;
    memcpy(tpd_wb_start, tpd_wb_start_local, TPD_WARP_CNT*4);
    memcpy(tpd_wb_end, tpd_wb_start_local, TPD_WARP_CNT*4);
#endif

#if (defined(TPD_HAVE_CALIBRATION) && !defined(TPD_CUSTOM_CALIBRATION))
    memcpy(tpd_calmat, tpd_def_calmat_local, 8*4);
    memcpy(tpd_def_calmat, tpd_def_calmat_local, 8*4);
#endif
    TPD_DMESG("end %s, %d\n", __FUNCTION__, __LINE__);
    tpd_type_cap = 1;
    return 0;
}

static void tpd_resume( struct device *h )
{
	int ret = 0;
	char data;
	tpd_halt = 0;

#ifdef TPD_PROXIMITY
	if (tpd_proximity_flag == 1)
	{
		if(tpd_proximity_flag_one == 1)
		{
			tpd_proximity_flag_one = 0;
			TPD_DMESG(TPD_DEVICE " tpd_proximity_flag_one \n");
			return;
		}

	}
#endif

    ret = fts_i2c_Write_byte(i2c_client, 0xd0, 1, &data);
    if(ret!=0)
    {
        TPD_DMESG(" %s, wrinte i2c reg0xd0 ,data=%d, ret=%d\n", __FUNCTION__,data,ret);
    }

   	TPD_DMESG("TPD wake up\n");

    tpd_gpio_output(GPIO_CTP_RST_PIN, 0);
    msleep(2);
    tpd_gpio_output(GPIO_CTP_RST_PIN, 1);

	enable_irq(ft_irq);
	msleep(30);
	/* for resume debug
	if((i2c_smbus_read_i2c_block_data(i2c_client, 0x00, 1, &data))< 0)
	{
		TPD_DMESG("resume I2C transfer error, line: %d\n", __LINE__);
	}
	*/
	tpd_up(0,0);
	input_sync(tpd->dev);
	TPD_DMESG("TPD wake up done\n");
#if defined(CTP_FOR_HAND)
	tpd_handler2(g_open_handler);
#endif
#if defined(CTP_HALL_SENSITIVITY)
	int state = 0;
	int state_compare = 0;
	int i = 0;
	if(1 == sensitivity_state)//hall close
	{
		#if defined(CTP_SET_PANDA_SENSITIVTY)
		state = 0xB0;
		#elif defined(CTP_SET_FOCALTECH_SENSITIVTY)
		state = 1;
		#endif
	}else if(0 == sensitivity_state)//hall far
	{
		#if defined(CTP_SET_PANDA_SENSITIVTY)
		state = 0xB1;
		#elif defined(CTP_SET_FOCALTECH_SENSITIVTY)
		state = 0;
		#endif

	}
	disable_irq(ft_irq);
	#if defined(CTP_SET_PANDA_SENSITIVTY)
	struct i2c_msg msg[] =
	{
		{
			.addr	= i2c_client->addr,
			.flags	= 0,
			.len	= 1,
			.buf	= &state,
		},
	};
	//send command three times
	i2c_transfer(i2c_client->adapter, msg, 1);
	msleep(50);
	i2c_transfer(i2c_client->adapter, msg, 1);
	msleep(50);
	i2c_transfer(i2c_client->adapter, msg, 1);
	msleep(50);

	#elif defined(CTP_SET_FOCALTECH_SENSITIVTY)
	if ((ret = fts_i2c_Write_byte(i2c_client, 0xc1, 1, &state)) < 0)
		TPD_DEBUG("%s i2c write error: %d\n", __func__, ret);
	msleep(100);
	i2c_smbus_read_i2c_block_data(i2c_client, 0xc1, 1, &state_compare);
	if(state_compare != state)
	{
		for(i=0;i<5;i++)
		{
			fts_i2c_Write_byte(i2c_client, 0xc1, 1, &state);
			msleep(100);
			i2c_smbus_read_i2c_block_data(i2c_client, 0xc1, 1, &state_compare);
			if(state_compare == state)
				break;
		}
		TPD_DEBUG("[mu] state_compare = %d\n", state_compare);
		if(state_compare != state)
			return -1;
	}
	msleep(100);
	#endif
	//#endif
	enable_irq(ft_irq);
#endif

}

static void tpd_suspend( struct device *h )
{
	// int retval = TPD_OK;
	static char data = 0x3;
	int ret = 0;
    tpd_halt = 1;
#ifdef TPD_PROXIMITY
	if (tpd_proximity_flag == 1)
	{
		tpd_proximity_flag_one = 1;
	}
#endif

	tpd_power_enable(0);
	msleep(10);
	tpd_power_enable(1);
	msleep(100);
#if defined(CTP_FOR_HAND)
	tpd_handler2(g_open_handler);

#endif

	tpd_gpio_output(GPIO_CTP_RST_PIN, 1);
	mdelay(2);
	tpd_gpio_output(GPIO_CTP_RST_PIN, 0);
	mdelay(2);
	tpd_gpio_output(GPIO_CTP_RST_PIN, 1);
	mdelay(300);

TPD_DMESG("TPD enter sleep\n");

#ifdef FTS_GESTRUE
	g_gesture_active_flag = false;

	if(g_gesture_flag)
	{
		//init_para(540,960,100,0,0);
		data = 0x01;
		ret = fts_i2c_Write_byte(i2c_client, 0xd0, 1, &data);
		printk(" %s, wrinte i2c reg0xd0 ,data=%d, ret=%d\n", __FUNCTION__,data,ret);

		/*All gesture on*/
		data = 0xff;
		ret = fts_i2c_Write_byte(i2c_client, 0xd1, 1, &data);
		printk(" %s, wrinte i2c reg0xd1 ,data=%d, ret=%d\n", __FUNCTION__,data,ret);

		data = 0x1f;
		ret = fts_i2c_Write_byte(i2c_client, 0xd2, 1, &data);
		printk(" %s, wrinte i2c reg0xd2 ,data=%d, ret=%d\n", __FUNCTION__,data,ret);

		data = 0xff;
		ret = fts_i2c_Write_byte(i2c_client, 0xd5, 1, &data);
		printk(" %s, wrinte i2c reg0xd5 ,data=%d, retval=%d\n", __FUNCTION__,data,ret);

		data = 0xff;
		ret = fts_i2c_Write_byte(i2c_client, 0xd6, 1, &data);
		printk(" %s, wrinte i2c reg0xd6 ,data=%d, retval=%d\n", __FUNCTION__,data,ret);

		data = 0xff;
		ret = fts_i2c_Write_byte(i2c_client, 0xd7, 1, &data);
		printk(" %s, wrinte i2c reg0xd6 ,data=%d, retval=%d\n", __FUNCTION__,data,ret);
	}
	else
	{

	mutex_lock(&i2c_access);
	ret = fts_i2c_Write_byte(i2c_client, 0xA5, 1, &data);  //TP enter sleep mode
	mutex_unlock(&i2c_access);

	disable_irq(ft_irq);
	}
#else

	mutex_lock(&i2c_access);
	ret = fts_i2c_Write_byte(i2c_client, 0xA5, 1, &data);  //TP enter sleep mode
	mutex_unlock(&i2c_access);

	disable_irq(ft_irq);
#endif
	TPD_DMESG("TPD enter sleep done\n");
}
//qrp
#if defined(CTP_HALL_SENSITIVITY)
int tpd_set_sensitivity(unsigned long arg)
{
	int ret = 0;
	int state = 0;
	int state_compare = 0;//compare with state
	int i = 0;
	//arg = 1, set high sensitivity, else set normal
	if(arg)
	{
		sensitivity_state = 1;
		#if defined(CTP_SET_PANDA_SENSITIVTY)
		state = 0xB0;
		#elif defined(CTP_SET_FOCALTECH_SENSITIVTY)
		state = 1;
		#endif
	}
	else
	{
		sensitivity_state = 0;
		#if defined(CTP_SET_PANDA_SENSITIVTY)
		state = 0xB1;
		#elif defined(CTP_SET_FOCALTECH_SENSITIVTY)
		state = 0;
		#endif

	}
	TPD_DEBUG("[mu] arg = %d, state = %d\n", arg, state);
	disable_irq(ft_irq);
	#if defined(CTP_SET_PANDA_SENSITIVTY)
	struct i2c_msg msg[] =
	{
		{
			.addr	= i2c_client->addr,
			.flags	= 0,
			.len	= 1,
			.buf	= &state,
		},
	};
	//send command three times
	i2c_transfer(i2c_client->adapter, msg, 1);
	msleep(50);
	i2c_transfer(i2c_client->adapter, msg, 1);
	msleep(50);
	i2c_transfer(i2c_client->adapter, msg, 1);
	msleep(50);
	#elif defined(CTP_SET_FOCALTECH_SENSITIVTY)
	if ((ret = fts_i2c_Write_byte(i2c_client, 0xc1, 1, &state)) < 0)
		TPD_DEBUG("%s i2c write error: %d\n", __func__, ret);
	msleep(100);
	i2c_smbus_read_i2c_block_data(i2c_client, 0xc1, 1, &state_compare);
	if(state_compare != state)
	{
		for(i=0;i<5;i++)
		{
			fts_i2c_Write_byte(i2c_client, 0xc1, 1, &state);
			msleep(100);
			i2c_smbus_read_i2c_block_data(i2c_client, 0xc1, 1, &state_compare);
			if(state_compare == state)
				break;
		}
		TPD_DEBUG("[mu] state_compare = %d\n", state_compare);
		if(state_compare != state)
			return -1;
	}
	#endif

	enable_irq(ft_irq);

	return 0;
}
#endif
#ifdef HARDWARE_INFO
static int ft_get_fw_ver(void)
{
	u8 ver = 0;
	int i = 0;
	while(i<5)
	{
		if(i2c_smbus_read_i2c_block_data(i2c_client, 0xA6, 1, &ver) < 0)
		{
			TPD_DEBUG("[Bruce] read focaltek firmware fail: %u\n", ver);
			return -1;
		}
		if(ver != 0xA6 )
			break;
		i++;
	}

	return ver;
}
#endif
 static struct tpd_driver_t tpd_device_driver =
{
	.tpd_device_name = TPD_NAME,
	.tpd_local_init = tpd_local_init,
	.suspend = tpd_suspend,
	.resume = tpd_resume,
#ifdef TPD_HAVE_BUTTON
	.tpd_have_button = 1,
#else
	.tpd_have_button = 0,
#endif
#ifdef HARDWARE_INFO
	.get_tp_fw_ver = ft_get_fw_ver,
#endif
#if defined(CTP_FOR_HAND)
	.tpd_handler = tpd_handler2,
#endif
};
 /* called when loaded into kernel */
static int __init tpd_driver_init(void)
{
	tpd_get_dts_info();
	if(tpd_driver_add(&tpd_device_driver) < 0)
		TPD_DMESG("add FTS driver failed\n");
	 return 0;
}

 /* should never be called */
static void __exit tpd_driver_exit(void)
{
	tpd_driver_remove(&tpd_device_driver);
}

module_init(tpd_driver_init);
module_exit(tpd_driver_exit);

