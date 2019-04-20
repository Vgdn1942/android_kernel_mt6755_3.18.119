#ifndef __TEMPERATURE_FACTORY_H__
#define __TEMPERATURE_FACTORY_H__

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
#include <linux/types.h>
#include <linux/atomic.h>

#include <hwmsensor.h>
#include <hwmsen_dev.h>
#include <sensors_io.h>
#include <hwmsen_helper.h>
#include <batch.h>

/*#include <mach/mt_typedefs.h>*/
/*#include <mach/mt_gpio.h>*/
/*#include <mach/mt_pm_ldo.h>*/

#include "temperature.h"
#include "cust_temp.h"


extern struct temp_context *temp_context_obj;

#define TYPE_PRESS 1
#define TYPE_TEMP 2


int temp_factory_device_init(void);

#endif

