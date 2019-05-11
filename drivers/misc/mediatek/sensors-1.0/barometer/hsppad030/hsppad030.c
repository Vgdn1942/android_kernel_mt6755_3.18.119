/* drivers/i2c/chips/hsppad030.c - HSPPAD030 motion sensor driver
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/interrupt.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/irq.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/kobject.h>
#include <linux/platform_device.h>
#include <linux/atomic.h>
#include <linux/module.h>
#include <linux/math64.h>

#include <cust_baro.h>
#include "hsppad030.h"
#include <barometer.h>

#define HSPPAD030_DEV_NAME        "HSPPAD030"

static const struct i2c_device_id hsppad030_i2c_id[] = {{HSPPAD030_DEV_NAME,0},{}};
static int hsppad030_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id); 
static int hsppad030_i2c_remove(struct i2c_client *client);
static int hsppad030_i2c_detect(struct i2c_client *client, struct i2c_board_info *info);
static int hsppad030_resume(struct i2c_client *client);
static int hsppad030_suspend(struct i2c_client *client, pm_message_t msg); 
static int hsppad030_release(struct inode *inode, struct file *file);
static int  hsppad030_local_init(void);
static int  hsppad030_local_remove(void);

struct baro_hw baro_cust;
static struct baro_hw *hw = &baro_cust;

static struct baro_init_info hsppad030_init_info = {
		.name = "hsppad030",
		.init = hsppad030_local_init,
		.uninit = hsppad030_local_remove,
	
};

#ifdef CONFIG_OF
static const struct of_device_id baro_of_match[] = {
	{.compatible = "mediatek,PRESSURE"},
	{},
};
#endif

static struct i2c_driver hsppad030_i2c_driver = {
    .driver = {
        .name           = HSPPAD030_DEV_NAME,
#ifdef CONFIG_OF
        .of_match_table = baro_of_match,
#endif     
    },
	.probe      		= hsppad030_i2c_probe,
	.remove    			= hsppad030_i2c_remove,
	.detect				= hsppad030_i2c_detect,
    .suspend            = hsppad030_suspend,
    .resume             = hsppad030_resume,
	.id_table = hsppad030_i2c_id,
};

typedef enum {
    BAR_TRC_READ  = 0x01,
    BAR_TRC_RAWDATA = 0x02,
    BAR_TRC_IOCTL   = 0x04,
    BAR_TRC_FILTER  = 0x08,
} BAR_TRC;

#define C_MAX_FIR_LENGTH (32)
#define HSPPAD030_DATA_NUM 2

struct data_filter {
    u32 raw[C_MAX_FIR_LENGTH][HSPPAD030_DATA_NUM];
    int sum[HSPPAD030_DATA_NUM];
    int num;
    int idx;
};


struct hsppad030_i2c_data {
    struct i2c_client *client;
    struct baro_hw *hw;
    struct hwmsen_convert   cvt;
    
    /*misc*/
    struct data_resolution *reso;
    atomic_t                trace;
    atomic_t                suspend;
    /*data*/
    int status;
	int t_raw;
	int p_raw;
	int T;
    int P; // compensated pressure value
    u32   data[2];
	atomic_t				filter;
#if defined(CONFIG_HSPPAD030_LOWPASS)
    atomic_t                firlen;
    atomic_t                fir_en;
    struct data_filter      fir;
#endif 
	
};

static struct i2c_client *hsppad030_i2c_client = NULL;
static struct hsppad030_i2c_data *obj_i2c_data = NULL;
static bool g_get_rawdata = false;

#define BARO_TAG				 "<BAROMETER> "
#define BAR_FUN(f)				 printk(BARO_TAG"%s\n", __func__)
#define BAR_ERR(fmt, args...)	 printk(BARO_TAG"%s %d : "fmt, __func__, __LINE__, ##args)
#define BAR_LOG(fmt, args...)	 printk(BARO_TAG fmt, ##args)

static int hsppad030_i2c_send(struct i2c_client *client,char cmd)
{
    u8 databuf[10];    
	int res = 0;
	memset(databuf, 0, sizeof(u8)*10);    
	databuf[0] = cmd;    
	res = i2c_master_send(client, databuf, 0x1);
	if(res < 0)
	{
		BAR_ERR("hsppad030_i2c_send fail!! res = %d\n",res);
	}
	return res;
}

static int hsppad030_i2c_recv(struct i2c_client *client,u8 *data,u8 len)
{
    int res = 0;
    if(NULL == data)
    {
		return -1;
		BAR_ERR("hsppad030_i2c_recv NULL pointer!!\n");
    }	  
	res = i2c_master_recv(client, data, len);
	
	if(res < 0)
	{
		BAR_ERR("hsppad030_i2c_recv fail!! res = %d\n",res);
		res = -1;
	}
	return res;
}


static int HSPPAD030_ReadPressureData(struct i2c_client *client, int *buf)
{
	u8 baro[5];
	int res = 0;
	
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	if(NULL == client)
	{
		*buf = 0;
		return -2;
	}
	else
	{	
		res  = hsppad030_i2c_send(client,0xAC);
		if(res < 0)
		{
			BAR_ERR(" I2c send 0xAC Error == end.\n");
			
			return res;
		}
		mdelay(15);
		res = hsppad030_i2c_recv(client, baro, 5);
		if(res < 0)
		{
			printk("Agold spl][HSPPAD030] I2c recv data Error.\n");
			return res;
		}
		
		obj_i2c_data->status = (int)baro[0]; 
		obj_i2c_data->p_raw = (int)(baro[2] | (baro[1] << 8));
		obj_i2c_data->t_raw = (int)(baro[4] | (baro[3] << 8));

		obj_i2c_data->P = (int)((obj_i2c_data->p_raw * 60*100 / 65535) + 50*100); //100倍
		obj_i2c_data->T = obj_i2c_data->t_raw * 125 /65535 - 40;
		
		if(g_get_rawdata)
		{
			buf[0] = obj_i2c_data->p_raw;
			buf[1] = obj_i2c_data->t_raw;
			
			printk("[MaJian]%s[line:%d] P_raw:%d T_raw:%d \n", __func__, __LINE__, buf[0], buf[1]);
		}
		else
		{
			buf[0] = obj_i2c_data->P;
			buf[1] = obj_i2c_data->T;
			
			printk("[MaJian]%s[line:%d] P:%d T:%d \n", __func__, __LINE__, buf[0], buf[1]);
		}
		/*res  = hsppad030_i2c_send(client,0xAC);
		if(res < 0)
		{
			BAR_ERR(" I2c send 0xAC Error.\n");
			return res;
		}	
		*/	
	}
	return 0;
}

static int HSPPAD030_client_Init(struct i2c_client *client, int reset_cali)
{
	int err =0;
	int buf[2] = {0,0};
	
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	err = HSPPAD030_ReadPressureData(client, buf);
	if(err)
	{
		BAR_ERR("HSPPAD030_client_Init read data error.\n");
		return err;
	}
	return 0;
}

static ssize_t hsppad030_show_chipinfo(struct device_driver *ddri, char *buf)
{  
	ssize_t len = 0;

	len += snprintf(buf+len,PAGE_SIZE-len,"hsppad030\n");
	
	return len;       
}

static ssize_t show_sensordata_value(struct device_driver *ddri, char *buf)
{
	struct i2c_client *client = hsppad030_i2c_client;
	int strbuf[1] = {0};

	
	if(NULL == client)
	{
		BAR_ERR("i2c client is null!!\n");
		return 0;
	}
	HSPPAD030_ReadPressureData(client, strbuf);

	printk("[Agold spl] Read sensor data OK. Pression: %d\n",strbuf[0]);
	return snprintf(buf, PAGE_SIZE, "P: %d\n", strbuf[0]);               
}

static ssize_t show_trace_value(struct device_driver *ddri, char *buf)
{
	ssize_t res;
	struct hsppad030_i2c_data *obj = obj_i2c_data;
	BAR_LOG(" show_trace_value \n");
	if (obj == NULL)
	{
		BAR_ERR("i2c_data obj is null!!\n");
		return 0;
	}
	
	res = snprintf(buf, PAGE_SIZE, "0x%04X\n", atomic_read(&obj->trace));     
	return res;    
}

static ssize_t store_trace_value(struct device_driver *ddri, const char *buf, size_t count)
{
    
	struct hsppad030_i2c_data *obj = obj_i2c_data;
	int trace;
	BAR_LOG(" store_trace_value \n");
	if (obj == NULL)
	{
		BAR_ERR("i2c_data obj is null!!\n");
		return 0;
	}
	
	if(1 == sscanf(buf, "0x%x", &trace))
	{
		atomic_set(&obj->trace, trace);
	}	
	else
	{
		BAR_ERR("invalid content: '%s', length = %ld\n", buf, count);
	}
	
	return count;    
}

static ssize_t show_status_value(struct device_driver *ddri, char *buf)
{
	ssize_t len = 0;  
	BAR_LOG(" show_status_value \n");
	
	return len;    
}

static DRIVER_ATTR(chipinfo,             S_IRUGO, hsppad030_show_chipinfo,      NULL);
static DRIVER_ATTR(sensordata, 			 S_IWUSR | S_IRUGO, show_sensordata_value,    NULL);
static DRIVER_ATTR(trace,      			 S_IWUSR | S_IRUGO, show_trace_value,         store_trace_value);
static DRIVER_ATTR(status,               S_IRUGO, show_status_value,        NULL);

static struct driver_attribute *hsppad030_attr_list[] = {
	&driver_attr_chipinfo,     /*chip information*/
	&driver_attr_sensordata,   /*dump sensor data*/
	&driver_attr_trace,        /*trace log*/
	&driver_attr_status,       /*enable or disable*/     
};

static int hsppad030_create_attr(struct device_driver *driver) 
{
	int idx, err = 0;
	int num = (int)(sizeof(hsppad030_attr_list)/sizeof(hsppad030_attr_list[0]));
	if (driver == NULL)
	{
		return -EINVAL;
	}

	for(idx = 0; idx < num; idx++)
	{
		if((err = driver_create_file(driver, hsppad030_attr_list[idx])))
		{            
			BAR_ERR("driver_create_file (%s) = %d\n", hsppad030_attr_list[idx]->attr.name, err);
			break;
		}
	}    
	return err;
}

static int hsppad030_delete_attr(struct device_driver *driver)
{
	int idx ,err = 0;
	int num = (int)(sizeof(hsppad030_attr_list)/sizeof(hsppad030_attr_list[0]));

	if(driver == NULL)
	{
		return -EINVAL;
	}
	
	for(idx = 0; idx < num; idx++)
	{
		driver_remove_file(driver, hsppad030_attr_list[idx]);
	}

	return err;
}

static int barometer_operate(void* self, uint32_t command, void* buff_in, int size_in,
		void* buff_out, int size_out, int* actualout)
{
	int err = 0;
	int value;	
	struct hsppad030_i2c_data *priv = (struct hsppad030_i2c_data*)self;
	struct hwm_sensor_data* barometer_data;
	int buff[3];
	
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	switch (command)
	{
		case SENSOR_DELAY:
			//no need to set delay
			//hsppad030 slowest out put rate is 121 Hz
			//and the slowest out put rate is highest  accuracy
			break;

		case SENSOR_ENABLE:
			// no need to enable ,hsppad030 do not support enable or disable
			// hsppad030 is always enabled, and if no data output the current consumption is 0.00002mA
			if((buff_in == NULL) || (size_in < sizeof(int)))
			{
				BAR_ERR("Enable sensor parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				value = *(int *)buff_in;
				if(value == 0)
				{
					//clear filter buffer
					//memset(&(priv->fir), 0, sizeof(struct data_filter));
				}		
			}
			break;

		case SENSOR_GET_DATA:
			if((buff_out == NULL) || (size_out< sizeof(struct hwm_sensor_data)))
			{		
				BAR_ERR("get sensor data parameter error!\n");
				err = -EINVAL;
			}
			else
			{
				barometer_data = (struct hwm_sensor_data *)buff_out;
				err = HSPPAD030_ReadPressureData(priv->client, buff);
					
				if(err)
				{
					BAR_ERR("get sensor data error!\n");
					return -1;
				}	
				barometer_data->values[0] = buff[0];	
				barometer_data->status = SENSOR_STATUS_ACCURACY_MEDIUM;				
				barometer_data->value_divide = 1;
			}
			break;
		default:
			BAR_ERR("temperature operate function no this parameter %d!\n", command);
			err = -1;
			break;
	}
	
	return err;
}

static int hsppad030_open(struct inode *inode, struct file *file)
{
	file->private_data = hsppad030_i2c_client;

	if(file->private_data == NULL)
	{
		BAR_ERR("null pointer!!\n");
		return -EINVAL;
	}
	return nonseekable_open(inode, file);
}

static int hsppad030_release(struct inode *inode, struct file *file)
{
	file->private_data = NULL;
	return 0;
}

static long hsppad030_unlock_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct i2c_client *client = (struct i2c_client*)file->private_data;
	int strbuf[3];
	s32 dat=0;
	void __user *data;
	int err = 0;
	
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);

	if(_IOC_DIR(cmd) & _IOC_READ)
	{
		err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
	}
	else if(_IOC_DIR(cmd) & _IOC_WRITE)
	{
		err = !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));
	}

	if(err)
	{
		BAR_ERR("access error: %08X, (%2d, %2d)\n", cmd, _IOC_DIR(cmd), _IOC_SIZE(cmd));
		return -EFAULT;
	}

	switch(cmd)
	{
		case BAROMETER_IOCTL_INIT:
			BAR_LOG("BAROSENSOR_IOCTL_INIT\n");
			HSPPAD030_client_Init(client, 0);			
			break;

		case BAROMETER_IOCTL_READ_CHIPINFO:
			 BAR_LOG("BAROSENSOR_IOCTL_READ_CHIPINFO\n");
			
			break;	  

		case BAROMETER_GET_PRESS_DATA:
			data = (void __user *) arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}	
			HSPPAD030_ReadPressureData(client, strbuf);

			dat = strbuf[0];
			BAR_LOG("dat = %d\n",dat);
			if(copy_to_user(data, &dat, sizeof(dat)))
			{
				err = -EFAULT;
				break;	  
			}				 
			break;
		case BAROMETER_GET_TEMP_DATA:
			data = (void __user *) arg;
			if(data == NULL)
			{
				err = -EINVAL;
				break;	  
			}	
			HSPPAD030_ReadPressureData(client, strbuf);

			dat = strbuf[1];
			BAR_LOG("dat = %d\n",dat);
			if(copy_to_user(data, &dat, sizeof(dat)))
			{
				err = -EFAULT;
				break;	  
			}				 
			break;

		default:
			BAR_ERR("unknown IOCTL: 0x%08x\n", cmd);
			err = -ENOIOCTLCMD;
			break;
			
	}

	return err;
}


static int hsppad030_open_report_data(int open)
{
	//should queuq work to report event if  is_report_input_direct=true
	return 0;
}

static int hsppad030_enable_nodata(int en)
{
	return  0;
}

static int hsppad030_set_delay(u64 ns)
{
	return 0;
}

int get_temprerature_data(void)
{
	struct i2c_client *client = hsppad030_i2c_client;
	int strbuf[2] = {0, 0};
	
	g_get_rawdata = true;
	if(NULL == client)
	{
		BAR_ERR("i2c client is null!!\n");
		return 0;
	}
	
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	HSPPAD030_ReadPressureData(client, strbuf);
	
	return strbuf[1];
}
EXPORT_SYMBOL(get_temprerature_data);

static int hsppad030_get_data(int *value, int *status)
{
	struct i2c_client *client = hsppad030_i2c_client;
	int strbuf[2] = {0, 0};
	
	g_get_rawdata = true;
	if(NULL == client)
	{
		BAR_ERR("i2c client is null!!\n");
		return 0;
	}
	
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	HSPPAD030_ReadPressureData(client, strbuf);
	*value = strbuf[0];
	*status = SENSOR_STATUS_ACCURACY_MEDIUM;
	return 0;
}

static int hsppad030_get_raw_data(int type, int *value)
{
	struct i2c_client *client = hsppad030_i2c_client;
	int strbuf[2] = {0, 0};
	
	g_get_rawdata = true;
	if(NULL == client)
	{
		BAR_ERR("i2c client is null!!\n");
		return 0;
	}
	
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	HSPPAD030_ReadPressureData(client, strbuf);
	*value = strbuf[0];
	return 0;
}


static struct file_operations hsppad030_fops = {
	.owner = THIS_MODULE,
	.open = hsppad030_open,
	.release = hsppad030_release,
	.unlocked_ioctl = hsppad030_unlock_ioctl,
};

static struct miscdevice hsppad030_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "barometer",
	.fops = &hsppad030_fops,
};

static int hsppad030_suspend(struct i2c_client *client, pm_message_t msg) 
{
	struct hsppad030_i2c_data *obj = i2c_get_clientdata(client);    
	int err = 0;

	BAR_FUN();
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);    

	if(msg.event == PM_EVENT_SUSPEND)
	{   
		if(obj == NULL)
		{
			BAR_ERR("null pointer!!\n");
			return -EINVAL;
		}
		atomic_set(&obj->suspend, 1);
		    
	}
	return err;
}

static int hsppad030_resume(struct i2c_client *client)
{
	struct hsppad030_i2c_data *obj = i2c_get_clientdata(client);  
	      
	BAR_FUN();
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);

	if(obj == NULL)
	{
		BAR_ERR("null pointer!!\n");
		return -EINVAL;
	}

	atomic_set(&obj->suspend, 0);

	return 0;
}


static int hsppad030_i2c_detect(struct i2c_client *client, struct i2c_board_info *info) 
{    
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	strcpy(info->type, HSPPAD030_DEV_NAME);
	return 0;
}

static int hsppad030_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	struct i2c_client *new_client;
	struct hsppad030_i2c_data *obj;
	struct hwmsen_object obj_press;
	struct baro_control_path ctl={0};
	struct baro_data_path data={0};
	int err = 0;
	BAR_FUN();

	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	if(!(obj = kzalloc(sizeof(*obj), GFP_KERNEL)))
	{
		err = -ENOMEM;
		goto exit;
	}
	
	memset(obj, 0, sizeof(struct hsppad030_i2c_data));

	obj->hw = hw;

	obj_i2c_data = obj;
	obj->client = client;
	new_client = obj->client;
	i2c_set_clientdata(new_client,obj);
	
	atomic_set(&obj->trace, 0);
	atomic_set(&obj->suspend, 0);
#ifdef CONFIG_HSPPAD030_LOWPASS

    atomic_set(&obj->filter, 1);
	if(obj->hw->firlen > C_MAX_FIR_LENGTH)
	{
		atomic_set(&obj->firlen, C_MAX_FIR_LENGTH);
	}	
	else
	{
		atomic_set(&obj->firlen, obj->hw->firlen);
	}
	
	if(atomic_read(&obj->firlen) > 0)
	{
		atomic_set(&obj->fir_en, 1);
	}
	BAR_LOG("hsppad030_device  filter len =%d \n",atomic_read(&obj->firlen));
#endif


	hsppad030_i2c_client = new_client;	

	err = HSPPAD030_client_Init(new_client, 1);
	if(err)
	{
		goto exit_init_failed;
	}

	err = misc_register(&hsppad030_device);
	if(err)
	{
		BAR_ERR("hsppad030_device register failed\n");
		goto exit_misc_device_register_failed;
	}
	
	err = hsppad030_create_attr(&hsppad030_init_info.platform_diver_addr->driver);
	if(err)
	{
		BAR_ERR("create attribute err = %d\n", err);
		goto exit_create_attr_failed;
	}
    
//*************************add data path ************************* 
	ctl.open_report_data= hsppad030_open_report_data;
	ctl.enable_nodata = hsppad030_enable_nodata;
	ctl.set_delay  = hsppad030_set_delay;
	ctl.is_report_input_direct = false;
    ctl.is_support_batch = false;
    ctl.is_report_input_direct = false;
    ctl.is_use_common_factory = false;
 

	err = baro_register_control_path(&ctl);
	if(err)
	{
	 	BAR_ERR("register acc control path err\n");
		goto exit_create_attr_failed;
	}
	
	data.get_data = hsppad030_get_data;
	data.vender_div = 1;

	data.get_raw_data = hsppad030_get_raw_data;
	
	err = baro_register_data_path(&data);
	if(err)
	{
	 	BAR_ERR("register acc data path err\n");
		goto exit_create_attr_failed;
	}
	err = batch_register_support_info(ID_PRESSURE,ctl.is_support_batch, 1000, 0);
    if(err)
    {
        BAR_ERR("register gsensor batch support err = %d\n", err);
        goto exit_create_attr_failed;
    }

//**************************************************************** 
	obj_press.self = obj;
    obj_press.polling = 1;
    obj_press.sensor_operate = barometer_operate;
    
    err = hwmsen_attach(ID_PRESSURE, &obj_press);
	if(err)
	{
		BAR_ERR("attach fail = %d\n", err);
		goto exit_kfree;
	}

	printk("%s: OK\n", __func__); 
 
	return 0;

	exit_create_attr_failed:
	misc_deregister(&hsppad030_device);
	exit_misc_device_register_failed:
	exit_init_failed:
	exit_kfree:
	kfree(obj);
	exit:
	BAR_ERR("%s: err = %d\n", __func__, err);        
	return err;
}

static int hsppad030_i2c_remove(struct i2c_client *client)
{
	int err = 0;	
	
	err = hsppad030_delete_attr(&(hsppad030_init_info.platform_diver_addr->driver));
	if(err)
	{
		BAR_ERR("hsppad030_delete_attr fail: %d\n", err);
	}
	
	if((err = misc_deregister(&hsppad030_device)))
	{
		BAR_ERR("misc_deregister fail: %d\n", err);
	}

	if((err = hwmsen_detach(ID_PRESSURE)))
	{
		BAR_ERR("hwmsen_detach ID_PRESSURE fail: %d\n", err);
	}
	    

	hsppad030_i2c_client = NULL;
	i2c_unregister_device(client);
	kfree(i2c_get_clientdata(client));
	return 0;
}

/*----------------------------------------------------------------------------*/
static int hsppad030_local_remove(void)
{

    BAR_FUN(); 
    printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);   
  
    i2c_del_driver(&hsppad030_i2c_driver);
    return 0;
}

static int  hsppad030_local_init(void)
{

	BAR_FUN();
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	if(i2c_add_driver(&hsppad030_i2c_driver))
	{
		BAR_ERR("add driver error\n");
		return -1;
	}
	
	return 0;
}

/*----------------------------------------------------------------------------*/

static int __init hsppad030_init(void)
{
	const char *name = "mediatek,hsppad030";
	printk("[MaJian]%s [line: %d]\n", __func__,__LINE__);
	
	hw = get_baro_dts_func(name, hw);
	if (!hw) 
	{
		BAR_ERR("get_alsps_dts_func fail\n");
		return 0;
	}

	baro_driver_add(&hsppad030_init_info);

	return 0;    
}

static void __exit hsppad030_exit(void)
{
	BAR_FUN();
}

module_init(hsppad030_init);
module_exit(hsppad030_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("HSPPAD030 I2C driver");
MODULE_AUTHOR("shipeilong@agold.com");
