/*
 * Copyright (C) 2012 Senodia Corporation.
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

#include "cust_mag.h"
#include "st480.h"
#include "mag.h"
/*----------------------------------------------------------------------------*/
#define MSE_TAG                  "MSENSOR"
#define MSE_FUN(f)               pr_debug(MSE_TAG" %s\r\n", __func__)
#define MSE_ERR(fmt, args...)    pr_err(MSE_TAG" %s %d : \r\n"fmt, __func__, __LINE__, ##args)
#define MSE_LOG(fmt, args...)    pr_debug(MSE_TAG fmt, ##args)

#define MSE_VER(fmt, args...)   ((void)0)

#define POWER_NONE_MACRO MT65XX_POWER_NONE

/*----------------------------------------------------------------------------*/

static int st480_i2c_probe(struct i2c_client *client,
			  const struct i2c_device_id *id);
static int st480_i2c_remove(struct i2c_client *client);
static int st480_suspend(struct i2c_client *client, pm_message_t msg);
static int st480_resume(struct i2c_client *client);
static int st480_i2c_detect(struct i2c_client *client,
			   struct i2c_board_info *info);
static int st480_local_init(void);
static int st480_remove(void);
static int st480_flush(void);

static int factory_mode;
static int st480_init_flag;	/* 0<==>OK -1 <==> fail */

#define ST480_AXIS_X            0
#define ST480_AXIS_Y            1
#define ST480_AXIS_Z            2
#define ST480_AXES_NUM          3

#define ST480_BUFSIZE          256

#define CONVERT_DIV		1000

/*----------------------------------------------------------------------------*/
/*static struct i2c_board_info i2c_st480 __initdata = { I2C_BOARD_INFO("st480", (0X0c)) }; */
/*static struct platform_driver st480_sensor_driver;*/


static DECLARE_WAIT_QUEUE_HEAD(open_wq);

struct st480_i2c_data {
	struct i2c_client *client;
	struct mag_hw hw;
	struct hwmsen_convert cvt;
	atomic_t layout;
	atomic_t trace;
	bool flush;
	bool enable;
};

struct SensorData st480sensordata;

static struct st480_i2c_data *st480;

static atomic_t flag;
static atomic_t open_flag;

static atomic_t dev_open_count;

static volatile  short st480d_delay = ST480_DEFAULT_DELAY;

struct mag_3 {
	s16 mag_x, mag_y, mag_z;
};
static volatile struct mag_3 mag;

static const struct i2c_device_id st480_i2c_id[] = { {ST480_I2C_NAME, 0}, {} };

static const struct of_device_id msensor_of_match[] = {
	{.compatible = "mediatek,msensor"},
	{},
};
static struct i2c_driver st480_i2c_driver = {
	.driver = {
		.name = ST480_I2C_NAME,
		.of_match_table = msensor_of_match,
	},
	.probe = st480_i2c_probe,
	.remove = st480_i2c_remove,
	.suspend = st480_suspend,
	.resume = st480_resume,
	.detect = st480_i2c_detect,
	.id_table = st480_i2c_id,
};

/*----------------------------------------------------------------------------*/
static struct platform_driver st_sensor_driver = {
	.driver = {
		.name = "msensor",
		.of_match_table = msensor_of_match,
	}
};

static struct mag_init_info st480_init_info = {
	.name = ST480_I2C_NAME,
	.init = st480_local_init,
	.uninit = st480_remove,
	.platform_diver_addr = &st_sensor_driver,
};

/*----------------------------------------------------------------------------*/

/*
 * st480 i2c transfer
 * read/write
 */
static int st480_i2c_transfer_data(struct i2c_client *client, int len, char *buf, int length)
{
	struct i2c_msg msgs[] = {
		{
		 .addr = client->addr,
		 .flags = 0,
		 .len = len,
		 .buf = buf,
		 },
		{
		 .addr = client->addr,
		 .flags = I2C_M_RD,
		 .len = length,
		 .buf = buf,
		 },
	};

	if (i2c_transfer(client->adapter, msgs, 2) < 0) {
		pr_err("megnetic_i2c_read_data: transfer error\n");
		return EIO;
	} else
		return 0;
}

/*
 * Device detect and init
 *
 */
static int client_init(struct i2c_client *client)
{
	int ret;
	unsigned char buf[5];
	unsigned char data[1];

	MSE_FUN();
	memset(buf, 0, 5);
	memset(data, 0, 1);

	buf[0] = READ_REGISTER_CMD;
	buf[1] = 0x00;
	ret = 0;

	while (st480_i2c_transfer_data(client, 2, buf, 3) != 0) {
		ret++;
		msleep(1);
		if (st480_i2c_transfer_data(client, 2, buf, 3) == 0) {
			break;
		}
		if (ret > MAX_FAILURE_COUNT) {
			return -EIO;
		}
	}

/***
	if(buf[2] != ST480_DEVICE_ID)
	{
		MSE_ERR("st480 ic not exist!");
		return -ENODEV;
	}
**/

	MSE_LOG("st480 device id is %x\n", buf[2]);

/* init register step 1 */
	buf[0] = WRITE_REGISTER_CMD;
	buf[1] = ONE_INIT_DATA_HIGH;
	buf[2] = ONE_INIT_DATA_LOW;
	buf[3] = ONE_INIT_REG;
	ret = 0;
	while (st480_i2c_transfer_data(client, 4, buf, 1) != 0) {
		ret++;
		msleep(1);
		if (st480_i2c_transfer_data(client, 4, buf, 1) == 0) {
			break;
		}
		if (ret > MAX_FAILURE_COUNT) {
			return -EIO;
		}
	}

/* init register step 2 */
	buf[0] = WRITE_REGISTER_CMD;
	buf[1] = TWO_INIT_DATA_HIGH;
	buf[2] = TWO_INIT_DATA_LOW;
	buf[3] = TWO_INIT_REG;
	ret = 0;
	while (st480_i2c_transfer_data(client, 4, buf, 1) != 0) {
		ret++;
		msleep(1);
		if (st480_i2c_transfer_data(client, 4, buf, 1) == 0) {
			break;
		}
		if (ret > MAX_FAILURE_COUNT) {
			return -EIO;
		}
	}

/* set calibration register */
	buf[0] = WRITE_REGISTER_CMD;
	buf[1] = CALIBRATION_DATA_HIGH;
	buf[2] = CALIBRATION_DATA_LOW;
	buf[3] = CALIBRATION_REG;
	ret = 0;
	while (st480_i2c_transfer_data(client, 4, buf, 1) != 0) {
		ret++;
		msleep(1);
		if (st480_i2c_transfer_data(client, 4, buf, 1) == 0) {
			break;
		}
		if (ret > MAX_FAILURE_COUNT) {
			return -EIO;
		}
	}

/* set mode config */
	buf[0] = SINGLE_MEASUREMENT_MODE_CMD;
	ret = 0;
	while (st480_i2c_transfer_data(client, 1, buf, 1) != 0) {
		ret++;
		msleep(1);
		if (st480_i2c_transfer_data(client, 1, buf, 1) == 0) {
			break;
		}
		if (ret > MAX_FAILURE_COUNT) {
			return -EIO;
		}
	}

	return 0;
}

static void st480_work_func(void)
{
	char buffer[7];
	int ret;
	int mag_tmp[ST480_AXES_NUM];

	memset(buffer, 0, 7);

	buffer[0] = READ_MEASUREMENT_CMD;
	ret = 0;
	while (st480_i2c_transfer_data(st480->client, 1, buffer, 7) != 0) {
		ret++;

		if (st480_i2c_transfer_data(st480->client, 1, buffer, 7) == 0) {
			break;
		}
		if (ret > MAX_FAILURE_COUNT) {
			break;
		}
	}

	if (!((buffer[0] >> 4) & 0X01)) {
		mag.mag_x = ((buffer[1] << 8) | buffer[2]);
		mag.mag_y = ((buffer[3] << 8) | buffer[4]);
		mag.mag_z = ((buffer[5] << 8) | buffer[6]);

		/* MSE_LOG("st480 raw data: x = %d, y = %d, z = %d\n",mag.mag_x,mag.mag_y,mag.mag_z); */
	}
	mag_tmp[st480->cvt.map[ST480_AXIS_X]] = st480->cvt.sign[ST480_AXIS_X] * mag.mag_x;
	mag_tmp[st480->cvt.map[ST480_AXIS_Y]] = st480->cvt.sign[ST480_AXIS_Y] * mag.mag_y;
	mag_tmp[st480->cvt.map[ST480_AXIS_Z]] = st480->cvt.sign[ST480_AXIS_Z] * mag.mag_z;

	mag.mag_x = mag_tmp[0];
	mag.mag_y = mag_tmp[1];
	mag.mag_z = mag_tmp[2];
	buffer[0] = SINGLE_MEASUREMENT_MODE_CMD;
	ret = 0;
	while (st480_i2c_transfer_data(st480->client, 1, buffer, 1) != 0) {
		ret++;
		msleep(1);
		if (st480_i2c_transfer_data(st480->client, 1, buffer, 1) == 0) {
			break;
		}
		if (ret > MAX_FAILURE_COUNT) {
			break;
		}
	}
}

/*----------------------------------------------------------------------------*/
static int st480_ReadChipInfo(char *buf, int bufsize)
{
	if ((!buf) || (bufsize <= 30)) {
		return -1;
	}
	if (!(st480->client)) {
		*buf = 0;
		return -2;
	}

	sprintf(buf, "st480 Chip");
	return 0;
}

/*----------------------------------------------------------------------------*/
static int st480_ReadCaliData(char *buf, int bufsize)
{
	if ((!buf) || (bufsize <= 80)) {
		return -1;
	}

	read_lock(&st480sensordata.datalock);
	sprintf(buf, "%d %d %d %d ", st480sensordata.nmx, st480sensordata.nmy,
		st480sensordata.nmz, st480sensordata.mag_status);
	read_unlock(&st480sensordata.datalock);
	return 0;
}


/*----------------------------------------------------------------------------*/
static ssize_t show_daemon_name(struct device_driver *ddri, char *buf)
{
	char strbuf[256];

	sprintf(strbuf, "st480");
	return sprintf(buf, "%s", strbuf);
}


static ssize_t show_chipinfo_value(struct device_driver *ddri, char *buf)
{
	char strbuf[256];

	st480_ReadChipInfo(strbuf, 256);
	return sprintf(buf, "%s\n", strbuf);
}

/*----------------------------------------------------------------------------*/
static ssize_t show_sensordata_value(struct device_driver *ddri, char *buf)
{
	char strbuf[ST480_BUFSIZE];

	st480_work_func();
	sprintf(strbuf, "%04x %04x %04x", mag.mag_x, mag.mag_y, mag.mag_z);
	/* st480_ReadSensorData(strbuf, ST480_BUFSIZE); */
	return sprintf(buf, "%s\n", strbuf);
}

/*----------------------------------------------------------------------------*/
static ssize_t show_calidata_value(struct device_driver *ddri, char *buf)
{
	char strbuf[ST480_BUFSIZE];

	st480_ReadCaliData(strbuf, ST480_BUFSIZE);
	return sprintf(buf, "%s\n", strbuf);
}

static ssize_t show_sensordata_calidata(struct device_driver *ddri, char *buf)
{
	char strbuf[ST480_BUFSIZE];

	read_lock(&st480sensordata.datalock);
	sprintf(strbuf, "%d %d %d\n", st480sensordata.nmx, st480sensordata.nmy,
		st480sensordata.nmz);
	read_unlock(&st480sensordata.datalock);
	return sprintf(buf, "%s\n", strbuf);
}


/*----------------------------------------------------------------------------*/
static ssize_t show_layout_value(struct device_driver *ddri, char *buf)
{
	struct st480_i2c_data *data = st480;

	return sprintf(buf, "(%d, %d)\n[%+2d %+2d %+2d]\n[%+2d %+2d %+2d]\n",
		       data->hw.direction, atomic_read(&data->layout), data->cvt.sign[0],
		       data->cvt.sign[1], data->cvt.sign[2], data->cvt.map[0], data->cvt.map[1],
		       data->cvt.map[2]);
}

/*----------------------------------------------------------------------------*/
static ssize_t store_layout_value(struct device_driver *ddri, const char *buf, size_t count)
{
	struct st480_i2c_data *data = st480;
	int layout = 0;

	if (1 == sscanf(buf, "%d", &layout)) {
		atomic_set(&data->layout, layout);
		if (!hwmsen_get_convert(layout, &data->cvt)) {
			MSE_ERR("HWMSEN_GET_CONVERT function OK!\r\n");
		} else if (!hwmsen_get_convert(data->hw.direction, &data->cvt)) {
			MSE_ERR("invalid layout: %d, restore to %d\n", layout, data->hw.direction);
		} else {
			MSE_ERR("invalid layout: (%d, %d)\n", layout, data->hw.direction);
			hwmsen_get_convert(0, &data->cvt);
		}
	} else {
		MSE_ERR("invalid format = '%s'\n", buf);
	}

	return count;
}

/*----------------------------------------------------------------------------*/
static ssize_t show_status_value(struct device_driver *ddri, char *buf)
{
	struct st480_i2c_data *data = st480;
	ssize_t len = 0;

	len += snprintf(buf + len, PAGE_SIZE - len, "CUST: %d %d (%d %d)\n",
				data->hw.i2c_num, data->hw.direction, data->hw.power_id,
				data->hw.power_vol);

	len += snprintf(buf + len, PAGE_SIZE - len, "OPEN: %d\n", atomic_read(&dev_open_count));
	return len;
}

/*----------------------------------------------------------------------------*/
static ssize_t show_trace_value(struct device_driver *ddri, char *buf)
{
	ssize_t res;
	struct st480_i2c_data *obj = st480;

	if (NULL == obj) {
		MSE_ERR("ST480_i2c_data is null!!\n");
		return 0;
	}

	res = snprintf(buf, PAGE_SIZE, "0x%04X\n", atomic_read(&obj->trace));
	return res;
}

/*----------------------------------------------------------------------------*/
static ssize_t store_trace_value(struct device_driver *ddri, const char *buf, size_t count)
{
	struct st480_i2c_data *obj = st480;
	int trace;

	if (NULL == obj) {
		MSE_ERR("st480_i2c_data is null!!\n");
		return 0;
	}

	if (1 == sscanf(buf, "0x%x", &trace)) {
		atomic_set(&obj->trace, trace);
	} else {
		MSE_ERR("invalid content: '%s', length = %d\n", buf, (int)count);
	}

	return count;
}

static ssize_t show_direction_value(struct device_driver *ddri, char *buf)
{
	ssize_t res;
	struct st480_i2c_data *obj = st480;

	if (NULL == obj) {
		MSE_ERR("ST480_i2c_data is null!!\n");
		return 0;
	}

	res = snprintf(buf, PAGE_SIZE, "%d\n", obj->hw.direction);
	return res;
}

static ssize_t store_direction_value(struct device_driver *ddri, const char *buf, size_t count)
{
	struct st480_i2c_data *obj = st480;
	int direction;

	if (NULL == obj) {
		MSE_ERR("st480_i2c_data is null!!\n");
		return 0;
	}

	if (1 == sscanf(buf, "%d", &direction)) {
		if (!hwmsen_get_convert(direction, &obj->cvt)) {
			obj->hw.direction = direction;
		}
	} else {
		MSE_ERR("invalid content: '%s', length = %d\n", buf, (int)count);
	}

	return count;
}

/*----------------------------------------------------------------------------*/
static DRIVER_ATTR(daemon, S_IRUGO, show_daemon_name, NULL);
static DRIVER_ATTR(chipinfo, S_IRUGO, show_chipinfo_value, NULL);
static DRIVER_ATTR(sensordata, S_IRUGO, show_sensordata_value, NULL);
static DRIVER_ATTR(calidata, S_IRUGO, show_calidata_value, NULL);
static DRIVER_ATTR(layout, S_IRUGO | S_IWUSR, show_layout_value, store_layout_value);
static DRIVER_ATTR(status, S_IRUGO, show_status_value, NULL);
static DRIVER_ATTR(trace, S_IRUGO | S_IWUSR, show_trace_value, store_trace_value);
static DRIVER_ATTR(calidata1, S_IRUGO, show_sensordata_calidata, NULL);
static DRIVER_ATTR(direction, S_IRUGO | S_IWUSR, show_direction_value, store_direction_value);
/*----------------------------------------------------------------------------*/
static struct driver_attribute *st480_attr_list[] = {
	&driver_attr_daemon,
	&driver_attr_chipinfo,
	&driver_attr_sensordata,
	&driver_attr_calidata,
	&driver_attr_layout,
	&driver_attr_status,
	&driver_attr_trace,
	&driver_attr_direction,
	&driver_attr_calidata1
};

/*----------------------------------------------------------------------------*/
static int st480_create_attr(struct device_driver *driver)
{
	int idx, err = 0;
	int num = (int)(sizeof(st480_attr_list) / sizeof(st480_attr_list[0]));

	if (driver == NULL) {
		return -EINVAL;
	}

	for (idx = 0; idx < num; idx++) {
		if ((err = driver_create_file(driver, st480_attr_list[idx]))) {
			MSE_ERR("driver_create_file (%s) = %d\n", st480_attr_list[idx]->attr.name,
				err);
			break;
		}
	}
	return err;
}

/*----------------------------------------------------------------------------*/
static int st480_delete_attr(struct device_driver *driver)
{
	int idx, err = 0;
	int num = (int)(sizeof(st480_attr_list) / sizeof(st480_attr_list[0]));

	if (driver == NULL) {
		return -EINVAL;
	}


	for (idx = 0; idx < num; idx++) {
		driver_remove_file(driver, st480_attr_list[idx]);
	}


	return err;
}

/*----------------------------------------------------------------------------*/
static int st480_suspend(struct i2c_client *client, pm_message_t msg)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
static int st480_resume(struct i2c_client *client)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
static int st480_i2c_detect(struct i2c_client *client,
			   struct i2c_board_info *info)
{
	strlcpy(info->type, ST480_I2C_NAME, sizeof(info->type));
	return 0;
}

#if SENSOR_AUTO_TEST
static int sensor_test_read(void)
{
	st480_work_func();
	return 0;
}

static int auto_test_read(void *unused)
{
	while (1) {
		sensor_test_read();
		msleep(200);
	}
	return 0;
}
#endif

#define CKT_G_AND_M_SENSOR_DIRECTION_DEBUG
#if defined(CKT_G_AND_M_SENSOR_DIRECTION_DEBUG)
static int st480_set_mag_direction(struct i2c_client *client, int direction)
{
	int err = -1;
	struct st480_i2c_data *mag = i2c_get_clientdata(client);

	mag->hw.direction = direction;
	atomic_set(&mag->layout, mag->hw.direction);
	err = hwmsen_get_convert(mag->hw.direction, &mag->cvt);
	if (err)
		MSE_ERR("luosen invalid direction: %d\n", mag->hw.direction);
	i2c_set_clientdata(st480->client, mag);

	return err;
}

static ssize_t msensor_test(struct file *file,struct kobject *kobj,
			    struct bin_attribute *attr, char *buf, loff_t off, size_t count)
{
	struct st480_i2c_data *msensor_i2c_data = i2c_get_clientdata(st480->client);

	MSE_ERR("luosen read msensor_direction=%d\n", msensor_i2c_data->hw.direction);
	if (msensor_i2c_data->hw.direction >= -1 && msensor_i2c_data->hw.direction < 7)
		msensor_i2c_data->hw.direction = msensor_i2c_data->hw.direction + 1;
	else
		msensor_i2c_data->hw.direction = 0;
	st480_set_mag_direction(st480->client, msensor_i2c_data->hw.direction);
	MSE_ERR(" luosen write msensor direction = %d\n", msensor_i2c_data->hw.direction);
	return count;
}

static ssize_t msensor_read(struct file *file,struct kobject *kobj,
			    struct bin_attribute *attr, char *buf, loff_t off, size_t count)
{
	struct st480_i2c_data *msensor_i2c_data = i2c_get_clientdata(st480->client);
	int i = 1;

	MSE_LOG("msensor_direction=%d\n", msensor_i2c_data->hw.direction);
	while (i > 0) {
		mdelay(100);
		i--;
	}
	return count;
}

static struct bin_attribute msensor_mode_attr = {
	.attr = {
		 .name = "st480_sensor_test",
		 .mode = S_IRUGO | S_IWUSR,
		 },
	.size = 4,
	.read = msensor_read,
	.write = msensor_test,
};
#endif

static int st480_enable(int en)
{
	int value = 0;
	struct st480_i2c_data *f_obj = st480;

	if (NULL == f_obj)
		return -1;

	value = en;
	factory_mode = 1;
	read_lock(&st480sensordata.ctrllock);
	if (value == 1) {
		f_obj->enable = true;
	} else {
		f_obj->enable = false;
	}
	if (f_obj->flush) {
		if (value == 1) {
			st480_flush();
		} else
			f_obj->flush = false;
	}
	wake_up(&open_wq);
	read_unlock(&st480sensordata.ctrllock);

	return 0;
}

static int st480_set_delay(u64 ns)
{
	int value = 0;

	value = (int)ns/1000/1000;
	if (value < 10)
		value = 10;
	st480d_delay = value;
	return 0;
}
static int st480_open_report_data(int open)
{
	return 0;
}

static int st480_get_data(int *x , int *y, int *z, int *status)
{
#if 0
	*x = st480sensordata.nmx;
	*y = st480sensordata.nmy;
	*z = st480sensordata.nmz;
#else
	*x = st480sensordata.yaw;
	*y = st480sensordata.pitch;
	*z = st480sensordata.roll;
#endif
	*status = st480sensordata.mag_status;
	return 0;
}

static int st480_batch(int flag, int64_t samplingPeriodNs, int64_t maxBatchReportLatencyNs)
{
	int value = 0;

	value = (int)samplingPeriodNs / 1000 / 1000;

	if (value <= 10)
		st480d_delay = 10;
	else
		st480d_delay = value;

	return 0;
}

static int st480_flush(void)
{
	/*Only flush after sensor was enabled*/
	int err = 0;
	struct st480_i2c_data *f_obj = st480;

	if (NULL == f_obj)
		return -1;

	if (!f_obj->enable) {
		f_obj->flush = true;
		return 0;
	}
	err = mag_flush_report();
	if (err >= 0)
		f_obj->flush = false;
	return err;
}

static int st480_factory_enable_sensor(bool enabledisable, int64_t sample_periods_ms)
{
	int err;

	err = st480_enable(enabledisable == true ? 1 : 0);
	if (err) {
		return -1;
	}
	err = st480_batch(0, sample_periods_ms * 1000000, 0);
	if (err) {
		return -1;
	}
	return 0;
}
static int st480_factory_get_data(int32_t data[3], int *status)
{
	/* get raw data */
	return  st480_get_data(&data[0], &data[1], &data[2], status);
}
static int st480_factory_get_raw_data(int32_t data[3])
{
	return 0;
}
static int st480_factory_enable_calibration(void)
{
	return 0;
}
static int st480_factory_clear_cali(void)
{
	return 0;
}
static int st480_factory_set_cali(int32_t data[3])
{
	return 0;
}
static int st480_factory_get_cali(int32_t data[3])
{
	return 0;
}
static int st480_factory_do_self_test(void)
{
	return 0;
}

static struct mag_factory_fops st480_factory_fops = {
	.enable_sensor = st480_factory_enable_sensor,
	.get_data = st480_factory_get_data,
	.get_raw_data = st480_factory_get_raw_data,
	.enable_calibration = st480_factory_enable_calibration,
	.clear_cali = st480_factory_clear_cali,
	.set_cali = st480_factory_set_cali,
	.get_cali = st480_factory_get_cali,
	.do_self_test = st480_factory_do_self_test,
};

static struct mag_factory_public st480_factory_device = {
	.gain = 1,
	.sensitivity = 1,
	.fops = &st480_factory_fops,
};

static int st480_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int err = 0;
	/*struct hwmsen_object sobj_m, sobj_o;*/
	struct mag_control_path ctl = {0};
	struct mag_data_path mag_data = {0};
#if SENSOR_AUTO_TEST
	struct task_struct *thread;
#endif
#if defined(CKT_G_AND_M_SENSOR_DIRECTION_DEBUG)
	int ret;
#endif

	MSE_FUN();

	st480 = kzalloc(sizeof(struct st480_i2c_data), GFP_KERNEL);
	if (!st480) {
		MSE_ERR("SENODIA st480_i2c_probe: memory allocation failed.\n");
		err = -ENOMEM;
		goto exit;
	}

	err = hwmsen_get_convert(st480->hw.direction, &st480->cvt);
	if (err) {
		MSE_ERR("invalid direction: %d\n", st480->hw.direction);
		goto exit;
	}
	rwlock_init(&st480sensordata.ctrllock);
	rwlock_init(&st480sensordata.datalock);

	err = get_mag_dts_func(client->dev.of_node, &st480->hw);
	if (err < 0) {
		MSE_ERR("get customization info from dts failed\n");
		goto exit_kfree;
	}

	atomic_set(&st480->layout, st480->hw.direction);
	atomic_set(&st480->trace, 0);
	init_waitqueue_head(&open_wq);

	client->addr = 0x30; //I2C addr
	st480->client = client;
	i2c_set_clientdata(client, st480);

	if (client_init(st480->client) != 0) {
		MSE_ERR("st480 setup error!\n");
		goto exit_kfree;
	}

	err = mag_factory_device_register(&st480_factory_device);
	if (err) {
		MSE_ERR("misc device register failed, err = %d\n", err);
		goto exit_misc_device_register_failed;
	}

	err = st480_create_attr(&(st480_init_info.platform_diver_addr->driver));
	if (err) {
		MSE_ERR("create attribute err = %d\n", err);
		goto exit_sysfs_create_group_failed;
	}

	ctl.is_use_common_factory = false;
	ctl.enable = st480_enable;
	ctl.set_delay  = st480_set_delay;
	ctl.open_report_data = st480_open_report_data;
	ctl.batch = st480_batch;
	ctl.flush = st480_flush;
	ctl.is_report_input_direct = false;
	ctl.is_support_batch = st480->hw.is_batch_supported;

	err = mag_register_control_path(&ctl);
	if (err) {
		MSE_ERR("register mag control path err\n");
		goto exit_misc_device_register_failed;
	}

	mag_data.div = CONVERT_DIV;
	mag_data.get_data = st480_get_data;

	err = mag_register_data_path(&mag_data);
	if (err) {
		MSE_ERR("register data control path err\n");
		goto exit_misc_device_register_failed;
	}

	/* As default, report all information */
	atomic_set(&flag, 0);
	atomic_set(&open_flag, 0);

#if SENSOR_AUTO_TEST
	thread = kthread_run(auto_test_read, NULL, "st480_read_test");
#endif

	MSE_LOG("st480 compass i2c probe successfully.");
	st480_init_flag = 0;
#if defined(CKT_G_AND_M_SENSOR_DIRECTION_DEBUG)
	ret = sysfs_create_bin_file(&(module_kset->kobj), &msensor_mode_attr);
	if (ret) {
		MSE_ERR("%s <msensor> Failed to create sys file\n", __func__);
		return -ENOMEM;
	}
#endif
	return 0;

exit_sysfs_create_group_failed:
exit_misc_device_register_failed:
exit_kfree:
	kfree(st480);
exit:
	st480_init_flag = -1;
	return err;
}

static int st480_i2c_remove(struct i2c_client *client)
{
	int err;

	MSE_FUN();
	err = st480_delete_attr(&(st480_init_info.platform_diver_addr->driver));
	if (err)
		MSE_ERR("st480_delete_attr fail: %d\n", err);

	i2c_unregister_device(st480->client);
	kfree(i2c_get_clientdata(st480->client));

	st480 = NULL;

	MSE_LOG("st480 i2c successfully removed.");
	return 0;
}

static int st480_local_init(void)
{
	MSE_FUN();

	atomic_set(&dev_open_count, 0);
	/* mmc328x_force[0] = hw->i2c_num; */

	if (i2c_add_driver(&st480_i2c_driver)) {
		MSE_ERR("add driver error\n");
		return -1;
	}
	if (st480_init_flag == -1) {
		return -1;
	}
	return 0;
}

/*----------------------------------------------------------------------------*/
static int st480_remove(void)
{
	atomic_set(&dev_open_count, 0);
	i2c_del_driver(&st480_i2c_driver);
	return 0;
}

static int __init st480_init(void)
{
	mag_driver_add(&st480_init_info);
	return 0;
}

static void __exit st480_exit(void)
{
}
module_init(st480_init);
module_exit(st480_exit);

MODULE_AUTHOR("MTK");
MODULE_DESCRIPTION("Senodia ST480 linux driver for MTK");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0.0");
