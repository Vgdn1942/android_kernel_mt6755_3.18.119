
#include <linux/hrtimer.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
//#include <linux/io.h>
#ifdef CONFIG_MTK_BOOT
#include "mt_boot_common.h"
#endif

#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/bitops.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/byteorder/generic.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include <linux/interrupt.h>
#include <linux/time.h>
#include <linux/rtpm_prio.h>

#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#include <linux/jiffies.h>
#include "tpd.h"
#include "tpd_custom_S2202.h"

#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/suspend.h>

#include "mt_gpio.h"
#if 0
#define S2202_SLAVE_ADDR		0x22
#define S2202_GPIO_RESET_PIN    (86)
#define S2202_GPIO_IRQ_PIN      (75)
#endif
#if defined(AGOLD_CTP_FOR_XS_CHARGE_SHIELD_PEN)
static struct timer_list r_tpd_timer;
static int tpd_timer_event = 0;
static struct task_struct *timer_thread = NULL;
static DECLARE_WAIT_QUEUE_HEAD(tp_timer_waiter);
static charge_mode = 0;
extern kal_bool upmu_is_chr_det(void);
#endif
static unsigned int touch_irq = 0;
static struct i2c_client *g_client = NULL;
#ifdef TPD_UPDATE_FIRMWARE
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/namei.h>
#include <linux/vmalloc.h>
#include <asm/system_misc.h>
extern int upgrate_percent;// mcz 20130606

static ssize_t update_firmware_show(struct kobject *kobj, struct kobj_attribute *attr,char *buf);
static ssize_t update_firmware_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);

static int ts_firmware_file(void);
static int i2c_update_firmware(struct i2c_client *client);

/* we changed the mode of these files and directories
 * the meet the requirements of Android Gingerbread CTS tests
 */
static struct kobj_attribute update_firmware_attribute = {
	.attr = {.name = "update_firmware", .mode = 0664},
	.show = update_firmware_show,
	.store = update_firmware_store,
};
#endif /* TPD_UPDATE_FIRMWARE */


#ifdef TPD_HAVE_BUTTON//TPD_HAVE_TOUCH_KEY
static int tpd_keys_local[TPD_KEY_COUNT] = TPD_KEYS;
static int tpd_keys_dim_local[TPD_KEY_COUNT][4] = TPD_KEYS_DIM;
//const u16 touch_key_array[] = { KEY_MENU, KEY_BACK};
//#define TPD_TOUCH_KEY_NUM ( sizeof( touch_key_array )/sizeof( touch_key_array[0] ) )
#endif

#if (defined(TPD_WARP_START) && defined(TPD_WARP_END))
static int tpd_wb_start_local[TPD_WARP_CNT] = TPD_WARP_START;
static int tpd_wb_end_local[TPD_WARP_CNT]   = TPD_WARP_END;
#endif

#if (defined(TPD_HAVE_CALIBRATION) && !defined(TPD_CUSTOM_CALIBRATION))
static int tpd_calmat_local[8]     = TPD_CALIBRATION_MATRIX;
static int tpd_def_calmat_local[8] = TPD_CALIBRATION_MATRIX;
#endif

struct point {
	int x;
	int raw_x;
	int y;
	int raw_y;
	int z;
	int status;
};

struct function_descriptor {
	__u8 queryBase;
	__u8 commandBase;
	__u8 controlBase;
	__u8 dataBase;
	__u8 intSrc;
#define FUNCTION_VERSION(x) ((x >> 5) & 3)
#define INTERRUPT_SOURCE_COUNT(x) (x & 7)

	__u8 functionNumber;
};


struct tpd_data {
	struct i2c_client *client;
	struct work_struct  work;
	struct point *cur_points;
	struct point *pre_points;
	u8 points_supported;
	u8 data_base;
	u8 data_length;
	u8 *data;
};

extern struct tpd_device *tpd;
static struct tpd_data *ts = NULL;
static struct workqueue_struct *mtk_tpd_wq;
static struct function_descriptor fd_01;
static struct function_descriptor fd_34;
static u8 boot_mode;

/* Register */
#define FD_ADDR_MAX    	0xE9
#define FD_ADDR_MIN    	0x05
#define FD_BYTE_COUNT 	6


/* Function extern */
static irqreturn_t tpd_eint_interrupt_handler(int irq, void *desc);
//extern void mt_eint_unmask(unsigned int line);
//extern void mt_eint_mask(unsigned int line);
//extern void mt65xx_eint_set_hw_debounce(kal_uint8 eintno, kal_uint32 ms);
//extern kal_uint32 mt65xx_eint_set_sens(kal_uint8 eintno, kal_bool sens);
//extern void mt65xx_eint_registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (EINT_FUNC_PTR)(void), kal_bool auto_umask);
static int tpd_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int tpd_detect(struct i2c_client *client, struct i2c_board_info *info);
static int tpd_remove(struct i2c_client *client);
static void tpd_work_func(struct work_struct *work);
static int tpd_i2c_read_data(struct i2c_client *client, u8 command, char *buf, int count);
static int tpd_i2c_write_byte_data(struct i2c_client *client, u8 command, u8 data);
static void tpd_down(int x, int y, int p, int trackid);
static void tpd_up(int x, int y, int trackid);
static int tpd_power(struct i2c_client *client, int on);
static void tpd_clear_interrupt(struct i2c_client *client);


static const struct i2c_device_id tpd_id[] = {{TPD_DEVICE,0},{}};
static unsigned short force[] = {0,0x40,I2C_CLIENT_END,I2C_CLIENT_END};
static const unsigned short * const forces[] = { force, NULL };
//static struct i2c_client_address_data addr_data = { .forces = forces, };
//static struct i2c_board_info __initdata i2c_tpd={ I2C_BOARD_INFO("mtk-tpd", (0x40>>1))};

static const struct of_device_id S2202_dt_match[] = 
{
	{.compatible = "mediatek,cap_touch"},
	{},
};
MODULE_DEVICE_TABLE(of, S2202_dt_match);


static struct i2c_driver tpd_i2c_driver = {
	.driver = {
		.of_match_table = S2202_dt_match,
		.name = TPD_DEVICE,
		//.owner = THIS_MODULE,
	},
	.probe = tpd_probe,
	.remove = tpd_remove,
	.id_table = tpd_id,
	.detect = tpd_detect,
	.address_list = (const unsigned short*) forces,
	//.address_data = &addr_data,
};

static int tpd_i2c_read_data(struct i2c_client *client, u8 command, char *buf, int count)
{
	int ret = 0;
	u16 old_flag = client->addr;

	client->addr = (client->addr & I2C_MASK_FLAG) | I2C_WR_FLAG | I2C_RS_FLAG;

	buf[0] = command;
	ret = i2c_master_send(client, buf, (count << 8 | 1));

	client->addr = old_flag;
	return ret;
}
static int tpd_i2c_write_byte_data(struct i2c_client *client, u8 command, u8 data)
{
	int ret = 0;
	u8 buf[2] = {command, data};

	ret = i2c_master_send(client, buf, 2);
	return ret;
}

static void tpd_down(int x, int y, int p, int trackid)
{
#ifdef TPD_HAVE_BUTTON
	if((0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "270", 3))||(0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "90", 2)))
    {
    	TPD_DEBUG("[wangxing] rotation\n");
		if(boot_mode!=NORMAL_BOOT && x>=TPD_RES_Y) 
		{ 
			int temp;
			temp = y;
			y = x;
			x = TPD_RES_X-temp;
			tpd_button(x, y, 1);
			return;
		}
		else if(boot_mode!=NORMAL_BOOT && y>=TPD_RES_Y)
		{
			tpd_button(x, y, 1);
			return;		
		}
	}
    else
	{	
		TPD_DEBUG("[wangxing] else \n");
		if(boot_mode!=NORMAL_BOOT && y>=TPD_RES_Y) 
		{ 
			TPD_DEBUG("[wangxing] factory mode \n" );
			tpd_button(x, y, 1);
			return;
		}
	}
#endif
	input_report_abs(tpd->dev, ABS_MT_TRACKING_ID, trackid);
	input_report_abs(tpd->dev, ABS_PRESSURE, p);
	input_report_key(tpd->dev, BTN_TOUCH, 1);
	input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, 1);

	/*[AGOLD][xxd][begin]*/
	if((0 == strncmp(MTK_LCM_PHYSICAL_ROTATION, "180", 3)) && y <= AGOLD_TPD_RES_Y && boot_mode ==NORMAL_BOOT)
	{
	 input_report_abs(tpd->dev, ABS_MT_POSITION_X, AGOLD_TPD_RES_X-x);
	 input_report_abs(tpd->dev, ABS_MT_POSITION_Y, AGOLD_TPD_RES_Y-y);
	}
	else
	{
       /*[AGOLD][end]*/
	input_report_abs(tpd->dev, ABS_MT_POSITION_X, x);
	input_report_abs(tpd->dev, ABS_MT_POSITION_Y, y);
        }

	input_mt_sync(tpd->dev);
#if 0
	#ifdef TPD_HAVE_BUTTON
	if (NORMAL_BOOT != boot_mode)
	{
		tpd_button(x, y, 1);
	}
	#endif
#endif
	//TPD_DEBUG("D[%4d %4d %4d]\n", x, y, p);
	//TPD_DOWN_DEBUG_TRACK(x,y);
}

static void tpd_up(int x, int y,int trackid)
{

#if defined(AGOLD_CONFIG_FOR_APP_CANNOT_WORK_NORMAL)
	//input_report_abs(tpd->dev, ABS_MT_TRACKING_ID, trackid);
	//input_report_abs(tpd->dev, ABS_PRESSURE, 0);
	input_report_key(tpd->dev, BTN_TOUCH, 0);
	//input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, 0);
	//input_report_abs(tpd->dev, ABS_MT_POSITION_X, x);
	//input_report_abs(tpd->dev, ABS_MT_POSITION_Y, y);
	input_mt_sync(tpd->dev);
#else
	//input_report_abs(tpd->dev, ABS_MT_TRACKING_ID, trackid);
	//input_report_abs(tpd->dev, ABS_PRESSURE, 0);
	input_report_key(tpd->dev, BTN_TOUCH, 0);
	//input_report_abs(tpd->dev, ABS_MT_TOUCH_MAJOR, 0);
	//input_report_abs(tpd->dev, ABS_MT_POSITION_X, x);
	//input_report_abs(tpd->dev, ABS_MT_POSITION_Y, y);
	input_mt_sync(tpd->dev);

#endif
#if 0
	#ifdef TPD_HAVE_BUTTON
	if (NORMAL_BOOT != boot_mode)
	{
		tpd_button(x, y, 0);
	}
	#endif
#endif
	//TPD_DEBUG("U[%4d %4d %4d]\n", x, y, 0);
	//TPD_UP_DEBUG_TRACK(x,y);
}


static void tpd_work_func(struct work_struct *work)
{
	u8 i = 0 ;
	u8 finger_status = 0;
	u8 finger_status_reg = 0;
	u8 loop = ts->data_length / 8;
	u8 fsr_len = (ts->points_supported + 3) / 4;
	u8 *pdata = ts->data;
	u8 *finger_reg = NULL;
	struct point *ppt = NULL;

#ifdef TPD_HAVE_BUTTON//TPD_HAVE_TOUCH_KEY
    static u8  last_key = 0,key = 0, touch_num = 0;
    //int idx;
#endif

	tpd_clear_interrupt(ts->client);

	for (i = 0; i < loop; i++)
        { 
		tpd_i2c_read_data(ts->client, ts->data_base + 8*i, ts->data + 8*i, 8);
	}

	if (ts->data_length % 8)
        { 
		tpd_i2c_read_data(ts->client, ts->data_base + 8*i, ts->data + 8*i, ts->data_length % 8);
	}

	for (i = 0; i < ts->points_supported; i++)
    {
		if (!(i % 4))
			finger_status_reg = pdata[i / 4];

		finger_status = (finger_status_reg >> ((i % 4) * 2)) & 3;
		#if defined(AGOLD_CTP_FOR_XS_CHARGE_SHIELD_PEN)
		if(charge_mode && finger_status == 2)
			finger_status = 0;
		#endif

		ppt = &ts->cur_points[i];
		ppt->status = finger_status;
		if (finger_status)
		{
			last_key = 0;  
			touch_num = 0;
			finger_reg = &pdata[fsr_len + 5 * i];

			ppt->raw_x = ppt->x = ((finger_reg[0] << 4) | (finger_reg[2] & 0x0F));
			ppt->raw_y = ppt->y = ((finger_reg[1] << 4) | ((finger_reg[2] >> 4) & 0x0F));
			ppt->z = finger_reg[4];

			#ifdef TPD_HAVE_CALIBRATION
			tpd_calibrate(&ppt->x, &ppt->y);
			#endif

			TPD_DEBUG("finger [%d] status [%d]  ", i, finger_status);
			TPD_DEBUG("[qnmd]rot ppt->x = %d, ppt->y = %d, ppt->p = %d, trackid = %d\n",ppt->x, ppt->y, ppt->z, i);
			tpd_down(ppt->x, ppt->y, ppt->z, i);
			//TPD_EM_PRINT(ppt->raw_x, ppt->raw_y, ppt->x, ppt->y, ppt->z, 1);
		}
	
		else
		{
			ppt = &ts->pre_points[i];
			//last_point = ppt->status;				
			if (ppt->status)
			{
				TPD_DEBUG("finger [%d] status [%d] \n", i, ppt->status);
				tpd_up(ppt->x, ppt->y, i); 
				//TPD_EM_PRINT(ppt->raw_x, ppt->raw_y, ppt->x, ppt->y, ppt->z, 0);
			}
		}
	
	}
	
#ifdef TPD_HAVE_BUTTON//TPD_HAVE_TOUCH_KEY
    tpd_i2c_write_byte_data(ts->client, 0xFF, 0x02);
    tpd_i2c_read_data(ts->client,0x00 , &key, 1);
    TPD_DEBUG("[mtk-tpd][trace] STATUS : %x\n", key);
    key = key & 0x0f;
	 
    if (key)
    {
		
    	if(key&0x01)
		{
			ppt->x=60;
			ppt->y=TPD_RES_Y*850/800;   		
		}
		else if(key&0x02)
		{
			ppt->x=300;
			ppt->y=TPD_RES_Y*850/800;   		
		}
		else if(key&0x04)
		{
			ppt->x=180;
			ppt->y=TPD_RES_Y*850/800;  		
		}
		else if(key&0x08)
		{
			ppt->x=420;
			ppt->y=TPD_RES_Y*850/800;   		
		}
        last_key = 0;  
		TPD_DEBUG("[Key][Down] ppt->x = %d, ppt->y = %d, ppt->p = %d\n",ppt->x, ppt->y, ppt->z);
		tpd_down(ppt->x, ppt->y, ppt->z, key);	
    }
	else if(last_key)
	{
		TPD_DEBUG("[Key][Up]>>>>>>>>>>>>\n");
		tpd_up(0, 0, i);
	#ifdef TPD_HAVE_BUTTON
		if(boot_mode!=NORMAL_BOOT && tpd->btn_state) 
		{ 
			tpd_button(ppt->x, ppt->y, 0);
		}
	#endif
		//input_report_key(tpd->dev, BTN_TOUCH, last_key);
	}

	last_key = key;
    tpd_i2c_write_byte_data(ts->client, 0xFF, 0x00);
	//input_report_key(tpd->dev, BTN_TOUCH, key);
#endif	
	input_sync(tpd->dev);
	ppt = ts->pre_points;
	ts->pre_points = ts->cur_points;
	ts->cur_points = ppt;

}

static irqreturn_t tpd_eint_interrupt_handler(int irq, void *desc)
{
	TPD_DEBUG("TPD interrupt has been triggered\n");
	queue_work(mtk_tpd_wq, &ts->work);
	return IRQ_HANDLED;
}

static int tpd_power(struct i2c_client *client, int on)
{
	int ret = 0;
	//int i = 0;
	//u8 temp = 0;

	if (on)
    {
        ret = tpd_i2c_write_byte_data(client, fd_01.controlBase, 0x80);/*sensor on*/
		if (ret < 0)
        {
        	TPD_DMESG("Error sensor can not wake up\n");
			return ret;
        }

        ret = tpd_i2c_write_byte_data(client, fd_01.commandBase, 0x01);/*touchscreen reset*/
        if (ret < 0)
        {
            TPD_DMESG("Error chip can not reset\n");
			return ret;
        }

        msleep(200); /* wait for device reset; */
	}
	else
    {
		ret = tpd_i2c_write_byte_data(client, fd_01.controlBase, 0x81); /* set touchscreen to deep sleep mode*/
		if (ret < 0)
        {
            TPD_DMESG("Error touch can not enter very-low power state\n");
			return ret;
        }
	}

	return ret;
}

static int tpd_detect (struct i2c_client *client, struct i2c_board_info *info)
{
	strcpy(info->type, TPD_DEVICE);
	return 0;
}

static int tpd_remove(struct i2c_client *client)
{
	TPD_DEBUG("TPD removed\n");
	return 0;
}

static void tpd_clear_interrupt(struct i2c_client *client)
{
	int i = 0;
	for( i = 5; i >0 ; i--)
    {
        if(i2c_smbus_read_byte_data(ts->client, 0x14) >= 0)
        {
            break;
        }
    }
}

static int tpd_rmi4_read_pdt(struct tpd_data *ts)
{
	int ret = 0;
	int nFd = 0;
	u8 fd_reg = 0;
	u8 query = 0;
	struct function_descriptor fd = {0};
	//u8 bufpdt[6] = {0};
	for (fd_reg = FD_ADDR_MAX; fd_reg >= FD_ADDR_MIN; fd_reg -= FD_BYTE_COUNT)
    {
		ret = tpd_i2c_read_data(ts->client, fd_reg, (unsigned char *)&fd, FD_BYTE_COUNT);
		if (ret < 0)
		{
			TPD_DMESG("Error I2C read failed querying RMI4 $%02X capabilities\n", ts->client->addr);
			return ret;
		}
		if (!fd.functionNumber)
        {
			/* End of PDT */
			ret = nFd;
			TPD_DMESG("Error Read %d functions from PDT\n", fd.functionNumber);
			break;
		}

		++nFd;

		switch (fd.functionNumber)
		{
            case 0x34:
                fd_34.queryBase = fd.queryBase;
                fd_34.dataBase = fd.dataBase;
                fd_34.controlBase = fd.controlBase;
                break;

			case 0x01: /* Interrupt */
                fd_01.queryBase = fd.queryBase;
                fd_01.dataBase = fd.dataBase;
                fd_01.commandBase = fd.commandBase;
                fd_01.controlBase = fd.controlBase;
				break;

			case 0x11: /* 2D */
				ts->data_base = fd.dataBase;
				ret = tpd_i2c_read_data(ts->client, fd.queryBase+1, &query, 1);
				if (ret < 0)
				{
					TPD_DMESG("Error reading F11 query registers\n");
				}

				ts->points_supported = (query & 7) + 1;
				if (ts->points_supported == 6)
					ts->points_supported = 10;

				ts->pre_points = kzalloc(ts->points_supported * sizeof(struct point), GFP_KERNEL);
				if (ts->pre_points == NULL)
				{
			        TPD_DMESG("Error zalloc failed!\n");
					ret = -ENOMEM;
					return ret;
				}

				ts->cur_points = kzalloc(ts->points_supported * sizeof(struct point), GFP_KERNEL);
				if (ts->cur_points == NULL)
				{
			        TPD_DMESG("Error zalloc failed!\n");
					ret = -ENOMEM;
					return ret;
				}

				ts->data_length = ((ts->points_supported + 3) / 4) + 5 * ts->points_supported;
				ts->data = kzalloc(ts->data_length, GFP_KERNEL);
				if (ts->data == NULL)
				{
			        TPD_DMESG("Error zalloc failed!\n");
					ret = -ENOMEM;
					return ret;
				}

				TPD_DEBUG("%d fingers\n", ts->points_supported);
				break;

 			case 0x30: /* GPIO */
				/*ts->hasF30 = true;

				ts->f30.data_offset = fd.dataBase;
				ts->f30.interrupt_offset = interruptCount / 8;
				ts->f30.interrupt_mask = ((1 < INTERRUPT_SOURCE_COUNT(fd.intSrc)) - 1) << (interruptCount % 8);

				ret = i2c_transfer(ts->client->adapter, query_i2c_msg, 2);
				if (ret < 0)
					TPD_DEBUG(KERN_ERR "Error reading F30 query registers\n");


				ts->f30.points_supported = query[1] & 0x1F;
				ts->f30.data_length = data_length = (ts->f30.points_supported + 7) / 8;*/

				break;
			default:
				break;
		}
	}

	return ret;
}

#if defined(AGOLD_CTP_FOR_XS_CHARGE_SHIELD_PEN)
static void tpd_timer_isr(void)
{
	tpd_timer_event = 1;
	wake_up_interruptible(&tp_timer_waiter);
	mod_timer(&r_tpd_timer, jiffies + HZ ); //1s
}

static int tp_timer_handler(void)
{
	static int error_data[3] = {0}, pen_close = 0x00, pen_open = 0x03, tmp_data = 0;
	do{
		wait_event_interruptible(tp_timer_waiter,( tpd_timer_event == 1));
		tpd_timer_event = 0;
		if(KAL_TRUE == upmu_is_chr_det())
		{
			//TPD_DEBUG("charging............\n");
			charge_mode = 1;
			i2c_smbus_read_i2c_block_data(g_client, 0x6c, 1, &tmp_data);
			//TPD_DEBUG("[mcz]tmp_data = 0x%x\n",tmp_data);
			if(0 != tmp_data)
				i2c_smbus_write_i2c_block_data(g_client, 0x6c, 1, &pen_close);
		}else{
			//TPD_DEBUG("NOT charging............\n");
			charge_mode = 0;
			i2c_smbus_read_i2c_block_data(g_client, 0x6c, 1, &tmp_data);
			//TPD_DEBUG("[mcz]tmp_data = 0x%x\n",tmp_data);
			if(0x03 != tmp_data)
				i2c_smbus_write_i2c_block_data(g_client, 0x6c, 1, &pen_open);
		
		}
	}while(!kthread_should_stop());
	return 0;
}
#endif
int S2202_fw_version = 0;

static int tpd_irq_registration(void)
{
	struct device_node *node = NULL;
	int ret = 0;
	u32 ints[2] = { 0, 0 };

	TPD_DEBUG("Device Tree Tpd_irq_registration!");

	node = of_find_matching_node(node, touch_of_match);
	if (node) {
		of_property_read_u32_array(node, "debounce", ints, ARRAY_SIZE(ints));
		gpio_set_debounce(ints[0], ints[1]);
		touch_irq = irq_of_parse_and_map(node, 0);
		ret = request_irq(touch_irq, (irq_handler_t) tpd_eint_interrupt_handler, IRQF_TRIGGER_FALLING, "TOUCH_PANEL-eint", NULL);
		if (ret > 0) {
			ret = -1;
		}
	} else {
		TPD_DEBUG("tpd request_irq can not find touch eint device node!.");
		ret = -1;
	}
	TPD_DEBUG("[%s]irq:%d, debounce:%d-%d:", __func__, touch_irq, ints[0], ints[1]);
	return ret;
}

#define GPIO_CTP_EINT_PIN (0x80000000 | 1)

static int tpd_probe(struct i2c_client *client, const struct i2c_device_id *id)
{

	int ret = 0;

	client->addr = 0x20;
	//tpd_gpio_as_int(GPIO_CTP_INT_PIN);
	
	
#if !defined CONFIG_MTK_LEGACY

	if(tpd->reg == NULL)
	{
		tpd->reg = regulator_get(tpd->tpd_dev, "vtouch");
	}
	ret = regulator_set_voltage(tpd->reg, 2800000, 2800000);	/*set 2.8v*/
	if (ret) {
		TPD_DEBUG("JH_xfl regulator_set_voltage(%d) failed!\n", ret);
		return -1;
	}

	ret = regulator_enable(tpd->reg);	/*enable regulator*/
	if (ret)
	{
		TPD_DEBUG("JH_xfl regulator_enable() failed!\n");
	}
#endif

	gpio_set_value(GPIO_CTP_RST_PIN,0);
	msleep(10);
	gpio_set_value(GPIO_CTP_RST_PIN,1);
	msleep(50);
	ts = kzalloc(sizeof(*ts), GFP_KERNEL);
	if (ts == NULL)
    {
        TPD_DMESG("Error zalloc failed!\n");
        ret = -ENOMEM;
		goto err_alloc_data_failed;
	}
	ts->client = client;
	i2c_set_clientdata(client, ts);

	ret = tpd_rmi4_read_pdt(ts);
	if (ret <= 0)
    {
		if (ret == 0)
			TPD_DMESG("Empty PDT\n");
		
		tpd_load_status = -1;
		TPD_DMESG("Error identifying device (%d)\n", ret);
		ret = -ENODEV;
		goto err_pdt_read_failed;
	}
	S2202_fw_version = i2c_smbus_read_byte_data(client,fd_34.controlBase+3);
	TPD_DEBUG("[mcz] JH_S2202_fw_version = 0x%x\n",S2202_fw_version);
	ret = tpd_power(client, 1);
    if (ret < 0)
    {
        TPD_DMESG("Error poweron failed\n");
        goto err_power_on_failed;
    }

	tpd_clear_interrupt(client);

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
    {
		TPD_DMESG("Error need I2C_FUNC_I2C\n");
		ret = -ENODEV;
		goto err_check_functionality_failed;
	}

    mtk_tpd_wq = create_singlethread_workqueue("mtk_tpd_wq");
    if (!mtk_tpd_wq)
    {
        TPD_DMESG("Error Could not create work queue mtk_tpd_wq: no memory");
        ret = -ENOMEM;
        goto error_wq_creat_failed;
    }

	INIT_WORK(&ts->work, tpd_work_func);
   	g_client = client;
#ifdef TPD_UPDATE_FIRMWARE

    for (i = 0 ; i < 3; i++)
    {
        ret = ts_firmware_file();
        if (!ret)
        {
			break;
        }
    }
#endif /* TPD_UPDATE_FIRMWARE */

#ifdef TPD_HAVE_TOUCH_KEY
    for (idx = 0; idx < TPD_TOUCH_KEY_NUM; idx++)
    {
        input_set_capability(tpd->dev, EV_KEY, touch_key_array[idx]);
    }
#endif

	mt_set_gpio_mode(GPIO_CTP_EINT_PIN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_CTP_EINT_PIN, GPIO_DIR_IN);
	mt_set_gpio_pull_enable(GPIO_CTP_EINT_PIN, GPIO_PULL_ENABLE);
	mt_set_gpio_pull_select(GPIO_CTP_EINT_PIN, GPIO_PULL_UP);


	tpd_irq_registration();

	enable_irq(touch_irq);
#if 1
	tpd_load_status = 1;
	TPD_DMESG("%s: Touch Panel Device Probe %s\n", __func__, (ret < 0) ? "FAIL" : "PASS");
#endif
#if defined(AGOLD_CTP_FOR_XS_CHARGE_SHIELD_PEN)
    memset((void*)&r_tpd_timer, 0, sizeof(r_tpd_timer));
    r_tpd_timer.expires  = jiffies + 1000/(1000/HZ);   // wait 1s to stable
    r_tpd_timer.function = tpd_timer_isr;     
    r_tpd_timer.data     = 0;
    init_timer(&r_tpd_timer);
    add_timer(&r_tpd_timer);
    
    timer_thread = kthread_run(tp_timer_handler,0,"tp_timer");
	if (IS_ERR(timer_thread))
	{ 
		ret = PTR_ERR(timer_thread );
		TPD_DEBUG("timer_thread: failed to create kernel thread: %d\n", ret);
	}
#endif
	return 0;

err_pdt_read_failed:
err_check_functionality_failed:
err_power_on_failed:
error_wq_creat_failed:
    if(NULL != ts)
    {
        kfree(ts);
    }

err_alloc_data_failed:

	return ret;
}

#ifdef TPD_UPDATE_FIRMWARE
struct RMI4_FDT{
    unsigned char m_QueryBase;
    unsigned char m_CommandBase;
    unsigned char m_ControlBase;
    unsigned char m_DataBase;
    unsigned char m_IntSourceCount;
    unsigned char m_ID;
};

static int RMI4_read_PDT(struct i2c_client *client)
{
	// Read config data
	struct RMI4_FDT temp_buf;
	struct RMI4_FDT m_PdtF34Flash;
	struct RMI4_FDT m_PdtF01Common;
	struct i2c_msg msg[2];
	unsigned short start_addr;
	int ret = 0;
	memset(&m_PdtF34Flash,0,sizeof(struct RMI4_FDT));
	memset(&m_PdtF01Common,0,sizeof(struct RMI4_FDT));

	for(start_addr = 0xe9; start_addr > 10; start_addr -= sizeof(struct RMI4_FDT))
	{


		tpd_i2c_read_data(client, start_addr, &temp_buf, FD_BYTE_COUNT);//print temp_buf
		if(temp_buf.m_ID == 0x34)
		{
			memcpy(&m_PdtF34Flash,&temp_buf,sizeof(struct RMI4_FDT ));
		}
		else if(temp_buf.m_ID == 0x01)
		{
			memcpy(&m_PdtF01Common,&temp_buf,sizeof(struct RMI4_FDT ));
		}
		else if (temp_buf.m_ID == 0)  //end of PDT
		{
			break;
		}
	  }

	if((m_PdtF01Common.m_CommandBase != fd_01.commandBase) || (m_PdtF34Flash.m_QueryBase != fd_34.queryBase))
	{
		TPD_DEBUG("%s:%d: RIM4 PDT has changed!!!\n",__FUNCTION__,__LINE__);

		ret = tpd_rmi4_read_pdt(ts);
		if(ret < 0)
		{
			TPD_DEBUG("read pdt error:!\n");
			return -1;
		}

		return 0;
	}

	return 0;

}

//to be improved .......
int RMI4_wait_attn_hw(struct i2c_client * client,int udleay)
{
	int loop_count=0;
	int ret=0;

	do{
		mdelay(udleay);
		ret = i2c_smbus_read_byte_data(client,fd_34.dataBase+18);//read Flash Control
		// Clear the attention assertion by reading the interrupt status register
		i2c_smbus_read_byte_data(client,fd_01.dataBase+1);//read the irq Interrupt Status
	}while(loop_count++ < 0x10 && (ret != 0x80));

	if(loop_count >= 0x10)
	{
		TPD_DEBUG("RMI4 wait attn timeout:ret=0x%x\n",ret);
		return -1;
	}
	return 0;
}

int RMI4_disable_program_hw(struct i2c_client *client)
{
	unsigned char cdata;
	unsigned int loop_count=0;

	TPD_DEBUG("RMI4 disable program...\n");
	// Issue a reset command
	i2c_smbus_write_byte_data(client,fd_01.commandBase,0x01);

	// Wait for ATTN to be asserted to see if device is in idle state
	RMI4_wait_attn_hw(client,20);

	// Read F01 Status flash prog, ensure the 6th bit is '0'
	do{
		cdata = i2c_smbus_read_byte_data(client,fd_01.dataBase);
		udelay(2);
	} while(((cdata & 0x40) != 0) && (loop_count++ < 10));

	//Rescan the Page Description Table
	return RMI4_read_PDT(client);
}

static int RMI4_enable_program(struct i2c_client *client)
{
	unsigned short bootloader_id = 0 ;
	int ret = -1;
	TPD_DEBUG("RMI4 enable program...\n");
	// Read and write bootload ID
	bootloader_id = i2c_smbus_read_word_data(client,fd_34.queryBase);
	i2c_smbus_write_word_data(client,fd_34.dataBase+2,bootloader_id);//write Block Data 0

	// Issue Enable flash command
	if(i2c_smbus_write_byte_data(client, fd_34.dataBase+18, 0x0F) < 0) //write Flash Control
	{
		TPD_DEBUG("RMI enter flash mode error\n");
		return -1;
	}
	ret = RMI4_wait_attn_hw(client,12);

	//Rescan the Page Description Table
	RMI4_read_PDT(client);
	return ret;
}

static unsigned long ExtractLongFromHeader(const unsigned char* SynaImage)
{
  	return((unsigned long)SynaImage[0] +
         (unsigned long)SynaImage[1]*0x100 +
         (unsigned long)SynaImage[2]*0x10000 +
         (unsigned long)SynaImage[3]*0x1000000);
}

static int RMI4_check_firmware(struct i2c_client *client,const unsigned char *pgm_data)
{
	unsigned long checkSumCode;
	unsigned long m_firmwareImgSize;
	unsigned long m_configImgSize;
	unsigned short m_bootloadImgID;
	unsigned short bootloader_id;
	const unsigned char *SynaFirmware;
	unsigned char m_firmwareImgVersion;
	unsigned short UI_block_count;
	unsigned short CONF_block_count;
	unsigned short fw_block_size;
	

	
  	SynaFirmware = pgm_data;
	checkSumCode = ExtractLongFromHeader(&(SynaFirmware[0]));
	m_bootloadImgID = (unsigned int)SynaFirmware[4] + (unsigned int)SynaFirmware[5]*0x100;
	m_firmwareImgVersion = SynaFirmware[7];
	m_firmwareImgSize    = ExtractLongFromHeader(&(SynaFirmware[8]));
	m_configImgSize      = ExtractLongFromHeader(&(SynaFirmware[12]));

	UI_block_count  = i2c_smbus_read_word_data(client,fd_34.queryBase+5); //read Firmware Block Count 0
	fw_block_size = i2c_smbus_read_word_data(client,fd_34.queryBase+3);   //read Block Size 0
	CONF_block_count = i2c_smbus_read_word_data(client,fd_34.queryBase+7);//read Configuration Block Count 0
	bootloader_id = i2c_smbus_read_word_data(client,fd_34.queryBase);

	return (m_firmwareImgVersion != 0 || bootloader_id == m_bootloadImgID) ? 0 : -1;

}


static int RMI4_write_image(struct i2c_client *client,unsigned char type_cmd,const unsigned char *pgm_data)
{
	unsigned short block_size;
	unsigned short img_blocks;
	unsigned short block_index;
	const unsigned char * p_data;
	int i;

	block_size = i2c_smbus_read_word_data(client,fd_34.queryBase+3);//read Block Size 0

	switch(type_cmd )
	{
		case 0x02:
			img_blocks = i2c_smbus_read_word_data(client,fd_34.queryBase+5);	//read UI Firmware
			break;
		case 0x06:
			img_blocks = i2c_smbus_read_word_data(client,fd_34.queryBase+7);	//read Configuration Block Count 0
			break;
		default:
			TPD_DEBUG("image type error\n");
			goto error;
	}

	p_data = pgm_data;

	for(block_index = 0; block_index < img_blocks; ++block_index)
	{
		//TPD_DEBUG("#");
		// Write Block Number
		if(i2c_smbus_write_word_data(client, fd_34.dataBase,block_index) < 0)
		{
			TPD_DEBUG("write block number error\n");
			goto error;
		}

		for(i=0;i<block_size;i++)
		{
			if(i2c_smbus_write_byte_data(client, fd_34.dataBase+2+i, *(p_data+i)) < 0) //write Block Data
			{
				TPD_DEBUG("RMI4_write_image: block %d data 0x%x error\n",block_index,*p_data);
				goto error;
			}
			udelay(15);
		}

		p_data += block_size;

		// Issue Write Firmware or configuration Block command
		if(i2c_smbus_write_word_data(client, fd_34.dataBase+18, type_cmd) < 0) //write Flash Control
		{
			TPD_DEBUG("issue write command error\n");
			goto error;
		}

		// Wait ATTN. Read Flash Command register and check error
		if(RMI4_wait_attn_hw(client,5) != 0)
		{
			goto error;
		}
		if(img_blocks > 32){
			upgrate_percent = (block_index*100)/img_blocks;
			if ((block_index % 200) == 0)
        	{
              TPD_DEBUG("[mcz] upgrade the %dth img_block.\n", block_index);
        	}
		}
		if(99 == upgrate_percent)
			upgrate_percent = 100;
		//TPD_DEBUG("upgrate_percent = %d%%\n",upgrate_percent);
	}

	return 0;
error:
	return -1;
}


static int RMI4_program_configuration(struct i2c_client *client,const unsigned char *pgm_data )
{
	int ret;
	unsigned short block_size;
	unsigned short ui_blocks;

	TPD_DEBUG("\nRMI4 program Config firmware...\n");
	block_size = i2c_smbus_read_word_data(client,fd_34.queryBase+3);//read Block Size 0
	ui_blocks = i2c_smbus_read_word_data(client,fd_34.queryBase+5);	//read Firmware Block Count 0

	if(RMI4_write_image(client, 0x06,pgm_data+ui_blocks*block_size ) < 0)
	{
		TPD_DEBUG("write configure image error\n");
		return -1;
	}

	ret = i2c_smbus_read_byte_data(client,fd_34.dataBase+18);	//read Flash Control
	return ((ret & 0xF0) == 0x80 ? 0 : ret);
}

static int RMI4_program_firmware(struct i2c_client *client,const unsigned char *pgm_data)
{
	int ret=0;
	unsigned short bootloader_id;

	TPD_DEBUG("RMI4 program UI firmware...\n");

	//read and write back bootloader ID
	bootloader_id = i2c_smbus_read_word_data(client,fd_34.queryBase);
	i2c_smbus_write_word_data(client,fd_34.dataBase+2, bootloader_id ); //write Block Data0

	//issue erase commander
	if(i2c_smbus_write_byte_data(client, fd_34.dataBase+18, 0x03) < 0) //write Flash Control
	{
		TPD_DEBUG("RMI4_program_firmware error, erase firmware error \n");
		return -1;
	}
	RMI4_wait_attn_hw(client,300);

	//check status
	if((ret = i2c_smbus_read_byte_data(client,fd_34.dataBase+18)) != 0x80) //check Flash Control
	{
		return -1;
	}

	//write firmware
	if( RMI4_write_image(client,0x02,pgm_data) <0 )
	{
		TPD_DEBUG("write UI firmware error!\n");
		return -1;
	}

	ret = i2c_smbus_read_byte_data(client,fd_34.dataBase+18); //read Flash Control
	return ((ret & 0xF0) == 0x80 ? 0 : ret);
}

static int synaptics_download(struct i2c_client *client,const unsigned char *pgm_data)
{
	int ret;

	ret = RMI4_read_PDT(client);
	if(ret != 0)
	{
		TPD_DEBUG("RMI page func check error\n");
		return -1;
	}

	ret = RMI4_enable_program(client);
	if( ret != 0)
	{
		TPD_DEBUG("%s:%d:RMI enable program error,return...\n",__FUNCTION__,__LINE__);
		goto error;
	}

	ret = RMI4_check_firmware(client,pgm_data);
	if( ret != 0)
	{
		TPD_DEBUG("%s:%d:RMI check firmware error,return...\n",__FUNCTION__,__LINE__);
		goto error;
	}

	ret = RMI4_program_firmware(client, pgm_data + 0x100);
	if( ret != 0)
	{
		TPD_DEBUG("%s:%d:RMI program firmware error,return...",__FUNCTION__,__LINE__);
		goto error;
	}

	RMI4_program_configuration(client, pgm_data +  0x100);
	return RMI4_disable_program_hw(client);

error:
	RMI4_disable_program_hw(client);
	TPD_DEBUG("%s:%d:error,return ....",__FUNCTION__,__LINE__);
	return -1;

}

static int i2c_update_firmware(struct i2c_client *client)
{
	TPD_DEBUG("[Agold mcz] func = %s, line = %d \n", __func__,__LINE__);
	char *buf;
	struct file	*filp;
	struct inode *inode = NULL;
	mm_segment_t oldfs;
	uint16_t	length;
	int ret = 0;
	const char filename[]="/storage/sdcard0/synaptics.img";
	/* open file */
	oldfs = get_fs();
	set_fs(KERNEL_DS);
	filp = filp_open(filename, O_RDONLY, S_IRUSR);
	if (IS_ERR(filp))
	{
            TPD_DEBUG("%s: file %s filp_open error\n", __FUNCTION__,filename);
            set_fs(oldfs);
            return -1;
	}

	if (!filp->f_op)
	{
            TPD_DEBUG("%s: File Operation Method Error\n", __FUNCTION__);
            filp_close(filp, NULL);
            set_fs(oldfs);
            return -1;
	}

    inode = filp->f_path.dentry->d_inode;
    if (!inode)
    {
        TPD_DEBUG("%s: Get inode from filp failed\n", __FUNCTION__);
        filp_close(filp, NULL);
        set_fs(oldfs);
        return -1;
    }

    /* file's size */
    length = i_size_read(inode->i_mapping->host);
    if (!( length > 0 && length < 62*1024 ))
    {
        TPD_DEBUG("file size error\n");
        filp_close(filp, NULL);
        set_fs(oldfs);
        return -1;
    }

	/* allocation buff size */
	buf = vmalloc(length+(length%2));		/* buf size if even */
	if (!buf)
	{
		TPD_DEBUG("alloctation memory failed\n");
		filp_close(filp, NULL);
		set_fs(oldfs);
		return -1;
	}

    /* read data */
    if (filp->f_op->read(filp, buf, length, &filp->f_pos) != length)
    {
        TPD_DEBUG("%s: file read error\n", __FUNCTION__);
        filp_close(filp, NULL);
        set_fs(oldfs);
        vfree(buf);
        return -1;
    }
	ret = synaptics_download(client,buf);

 	filp_close(filp, NULL);
	set_fs(oldfs);
	vfree(buf);
	return ret;
}

static int ts_firmware_file(void)
{
	TPD_DEBUG("[Agold mcz] func = %s, line = %d \n", __func__,__LINE__);
	int ret=0;
	struct kobject *kobject_ts;
	kobject_ts = kobject_create_and_add("touch_screen", NULL);
	if (!kobject_ts)
	{
		TPD_DEBUG("create kobjetct error!\n");
		return -1;
	}

	ret = sysfs_create_file(kobject_ts, &update_firmware_attribute.attr);
	if (ret) {
		kobject_put(kobject_ts);
		TPD_DEBUG("create file error\n");
		return -1;
	}
	return 0;
}

/*
 * The "update_firmware" file where a static variable is read from and written to.
 */
static ssize_t update_firmware_show(struct kobject *kobj, struct kobj_attribute *attr,char *buf)
{
	return 1;
}

static ssize_t update_firmware_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	char ret = -1;
	TPD_DEBUG("#################update_firmware_store######################\n");

	if(buf[0] == '2')
	{
		TPD_DEBUG("[Agold mcz] func = %s, line = %d \n", __func__,__LINE__);
		/* driver detect its device  */
		ret = i2c_smbus_read_byte_data(g_client, fd_01.queryBase);
		TPD_DEBUG("The id of synaptics device is : %d\n",ret); //if ---id 20130601

		disable_irq(touch_irq);
		/*update firmware*/
		ret = i2c_update_firmware(g_client);
		enable_irq(touch_irq);

		if( 0 != ret )
		{
			TPD_DEBUG("Update firmware failed!\n");
			ret = -1;
		}
		else
		{
			TPD_DEBUG("Update firmware success!\n");
			//arm_pm_restart(0,&ret);//restart command?
			ret = 1;
		}
	}

	return ret;
 }
#endif


static int tpd_local_init(void)
{
	//TPD_DMESG("s2202 I2C Touchscreen Driver (Built %s @ %s)\n", __DATE__, __TIME__);
#if !defined CONFIG_MTK_LEGACY
	int ret;
	TPD_DEBUG("tpd_local_init Device Tree get regulator!");
	
	if(tpd->reg == NULL)
	{
		tpd->reg = regulator_get(tpd->tpd_dev, "vtouch");
	}
	ret = regulator_set_voltage(tpd->reg, 2800000, 2800000);	/*set 2.8v*/
	if (ret) {
		TPD_DEBUG("xfl regulator_set_voltage(%d) failed!\n", ret);
		return -1;
	}

	ret = regulator_disable(tpd->reg);	/*enable regulator*/
	if (ret)
	{
		TPD_DEBUG("xfl regulator_enable() failed!\n");
	}
	msleep(300);
#endif
	if(i2c_add_driver(&tpd_i2c_driver)!=0)
	{
		TPD_DMESG("Error unable to add i2c driver.\n");
		return -1;
	}
	TPD_DEBUG("[muchaozhen] tpd_load_status = %d,s2202 driver.\n",tpd_load_status);

	if(-1 == tpd_load_status)
	{
		i2c_del_driver(&tpd_i2c_driver);
		TPD_DEBUG("[muchaozhen] del s2202_i2c_driver successful\n");

		return -1;
	}

#ifdef TPD_HAVE_BUTTON
    tpd_button_setting(TPD_KEY_COUNT, tpd_keys_local, tpd_keys_dim_local);// initialize tpd button data
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

	boot_mode = get_boot_mode();
	if (boot_mode == 3) boot_mode = NORMAL_BOOT;

	TPD_DMESG("end %s, %d\n", __FUNCTION__, __LINE__);
	tpd_type_cap = 1;
    return 0;
 }

static void tpd_resume( struct device *h )
{
	TPD_DEBUG("TPD wake up\n");

/*
#ifdef TPD_CLOSE_POWER_IN_SLEEP
	hwPowerOn(TPD_POWER_SOURCE,VOL_3300,"TP");
#else
#ifdef MT6573
	mt_set_gpio_mode(GPIO_CTP_EN_PIN, GPIO_CTP_EN_PIN_M_GPIO);
    mt_set_gpio_dir(GPIO_CTP_EN_PIN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_CTP_EN_PIN, GPIO_OUT_ONE);
#endif
	msleep(100);

	mt_set_gpio_mode(GTP_RST_PORT, GTP_RST_PORT_M_GPIO);
    mt_set_gpio_dir(GTP_RST_PORT, GPIO_DIR_OUT);
    mt_set_gpio_out(GTP_RST_PORT, GPIO_OUT_ZERO);
    msleep(1);
    mt_set_gpio_mode(GTP_RST_PORT, GTP_RST_PORT_M_GPIO);
    mt_set_gpio_dir(GTP_RST_PORT, GPIO_DIR_OUT);
    mt_set_gpio_out(GTP_RST_PORT, GPIO_OUT_ONE);
#endif
*/
	tpd_power(ts->client, 1);
	tpd_clear_interrupt(ts->client);

	enable_irq(touch_irq);

	return;
}

static void tpd_suspend( struct device *h )
{
	TPD_DEBUG("TPD enter sleep\n");
	disable_irq(touch_irq);

	tpd_power(ts->client, 0);

/*
#ifdef TPD_CLOSE_POWER_IN_SLEEP
	hwPowerDown(TPD_POWER_SOURCE,"TP");
#else
i2c_smbus_write_i2c_block_data(i2c_client, 0xA5, 1, &data);  //TP enter sleep mode
#ifdef MT6573
mt_set_gpio_mode(GPIO_CTP_EN_PIN, GPIO_CTP_EN_PIN_M_GPIO);
mt_set_gpio_dir(GPIO_CTP_EN_PIN, GPIO_DIR_OUT);
mt_set_gpio_out(GPIO_CTP_EN_PIN, GPIO_OUT_ZERO);
#endif

#endif
*/

	 return;
}

#if defined(TPD_UPDATE_FIRMWARE)
int agold_get_S2202_fw_version(void)
{
	int fw_version = 0;
	char ret = 0;

	fw_version = i2c_smbus_read_byte_data(g_client,fd_34.controlBase+3);
	TPD_DEBUG("[mcz] fw_version = 0x%x\n",fw_version);

	return fw_version;
}

int agold_start_S2202_fw_update(char *buf, int size)
{
	int ret = -1;
	TPD_DEBUG("[mcz] JH_synaptics fw size = 0x%x\n",size);
	TPD_DEBUG("JH_new FW version = 0x%x, old FW version = 0x%x\n", buf[45315],S2202_fw_version);
	disable_irq(touch_irq);
	/*update firmware*/
	if(buf[45315] > S2202_fw_version)
		ret = synaptics_download(g_client,buf);
	enable_irq(touch_irq);
	if( 0 != ret )
	{
		TPD_DEBUG("Update firmware failed!\n");
		ret = -1;
		return FW_UPGRATE_FAILED;
	}
	else
	{
		TPD_DEBUG("Update firmware success!\n");
		//arm_pm_restart(0,&ret);
		ret = 1;
		return FW_UPGRATE_SUCESS;
	}
}
#endif

static struct tpd_driver_t tpd_device_driver = {
	.tpd_device_name = "S2202",
	.tpd_local_init = tpd_local_init,
	.suspend = tpd_suspend,
	.resume = tpd_resume,
#ifdef TPD_HAVE_BUTTON
	.tpd_have_button = 1,
#else
	.tpd_have_button = 0,
#endif
	#if defined(TPD_UPDATE_FIRMWARE)
	.tpd_get_fw_version = agold_get_S2202_fw_version,
	.tpd_start_fw_update = agold_start_S2202_fw_update,
	#endif
};

static int __init tpd_driver_init(void)
{
	printk("[agold_debug] JH_S2202 touch panel driver init\n");
	//i2c_register_board_info(TPD_I2C_NUMBER, &i2c_tpd, 1);
	tpd_get_dts_info();
	if(tpd_driver_add(&tpd_device_driver) < 0)
		TPD_DMESG("JH_Error Add S2202 driver failed\n");
	return 0;
}

static void __exit tpd_driver_exit(void)
{
	TPD_DMESG("S2202 touch panel driver exit\n");
	tpd_driver_remove(&tpd_device_driver);
}

module_init(tpd_driver_init);
module_exit(tpd_driver_exit);

MODULE_DESCRIPTION("Mediatek S2202 Driver");

