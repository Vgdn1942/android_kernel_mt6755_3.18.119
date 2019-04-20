
#ifndef __TEMPERATURE_H__
#define __TEMPERATURE_H__

#include <linux/i2c.h>
#include <linux/irq.h>
#include <linux/uaccess.h>
#include <linux/kobject.h>
#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/io.h>
#include <linux/sched.h>
#include <linux/wakelock.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/module.h>

#include <batch.h>
#include <sensors_io.h>
#include <hwmsensor.h>
#include <hwmsen_dev.h>
#include "temperature_factory.h"

#define TEMP_TAG					"<TEMPERATURE> "
/*
#define TEMP_FUN(f)				pr_err(TEMP_TAG"%s\n", __func__)
#define TEMP_ERR(fmt, args...)	pr_err(TEMP_TAG"%s %d : "fmt, __func__, __LINE__, ##args)
#define TEMP_LOG(fmt, args...)	pr_err(TEMP_TAG fmt, ##args)
#define TEMP_VER(fmt, args...)	pr_err(TEMP_TAG"%s: "fmt, __func__, ##args)
*/
#define TEMP_FUN	pr_err(TEMP_TAG"%s\n", __func__)
#define TEMP_ERR	printk
#define TEMP_LOG	printk
#define TEMP_VER	printk


#define OP_TEMP_DELAY		0X01
#define	OP_TEMP_ENABLE		0X02
#define	OP_TEMP_GET_DATA	0X04

#define TEMP_INVALID_VALUE -1

#define EVENT_TYPE_TEMPERATURE_VALUE	ABS_THROTTLE
#define EVENT_TYPE_TEMPERATURE_STATUS	ABS_X

#define TEMP_VALUE_MAX (32767)
#define TEMP_VALUE_MIN (-32768)
#define TEMP_STATUS_MIN (0)
#define TEMP_STATUS_MAX (64)
#define TEMP_DIV_MAX (32767)
#define TEMP_DIV_MIN (1)

#define MAX_CHOOSE_TEMP_NUM 5

struct temp_control_path {
	int (*open_report_data)(int open);
	int (*enable_nodata)(int en);
	int (*set_delay)(u64 delay);
	int (*tempess_data_fifo)(void);
	bool is_report_input_direct;
	bool is_support_batch;
	bool is_use_common_factory;
};

struct temp_data_path {
	int (*get_data)(int *value, int *status);
	int (*get_raw_data)(int type, int *value);
	int vender_div;
};

struct temp_init_info {
	char *name;
	int (*init)(void);
	int (*uninit)(void);
	struct platform_driver *platform_diver_addr;
};

struct temp_data {
	struct hwm_sensor_data temp_data;
	int data_updata;
};

struct temp_drv_obj {
	void *self;
	int polling;
	int (*temp_operate)(void *self, uint32_t command, void *buff_in, int size_in, void *buff_out, int size_out,
			     int *actualout);
};

struct temp_context {
	struct input_dev *idev;
	struct miscdevice mdev;
	struct work_struct report;
	struct mutex temp_op_mutex;
	atomic_t delay;
	atomic_t wake;
	struct timer_list timer;
	atomic_t trace;

	struct temp_data drv_data;
	struct temp_control_path temp_ctl;
	struct temp_data_path temp_data;
	bool is_active_nodata;
	bool is_active_data;
	bool is_first_data_after_enable;
	bool is_polling_run;
	bool is_batch_enable;
};

extern int temp_driver_add(struct temp_init_info *obj);
extern int temp_data_report(struct input_dev *dev, int value, int status);
extern int temp_register_control_path(struct temp_control_path *ctl);
extern int temp_register_data_path(struct temp_data_path *data);

#endif
