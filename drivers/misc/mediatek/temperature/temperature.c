
#include "inc/temperature.h"

struct temp_context *temp_context_obj = NULL;

static struct temp_init_info *temperature_init_list[MAX_CHOOSE_TEMP_NUM] = { 0 };

static void temp_work_func(struct work_struct *work)
{

	struct temp_context *cxt = NULL;
	int value = 0, status = 0;
	int64_t nt = 0;
	struct timespec time;
	int err = 0;

	cxt = temp_context_obj;

	printk("[zp],temp_work_func is on\n");
	if (NULL == cxt->temp_data.get_data)
		TEMP_LOG("temp driver not register data path\n");

	time.tv_sec = time.tv_nsec = 0;
	time = get_monotonic_coarse();
	nt = time.tv_sec * 1000000000LL + time.tv_nsec;

	err = cxt->temp_data.get_data(&value, &status);
	printk("[zp],value = %d,status = %d\n",value,status);

	if (err) {
		TEMP_ERR("get temp data fails!!\n");
		goto temp_loop;
	} else {
		{
			cxt->drv_data.temp_data.values[0] = value;
			cxt->drv_data.temp_data.status = status;
			cxt->drv_data.temp_data.time = nt;
		}
	}

	if (true == cxt->is_first_data_after_enable) {
		cxt->is_first_data_after_enable = false;
		if (TEMP_INVALID_VALUE == cxt->drv_data.temp_data.values[0]) {
			TEMP_LOG(" read invalid data\n");
			goto temp_loop;
		}
	}


	temp_data_report(cxt->idev, cxt->drv_data.temp_data.values[0], cxt->drv_data.temp_data.status);

 temp_loop:
	if (true == cxt->is_polling_run) {
		{
			mod_timer(&cxt->timer, jiffies + atomic_read(&cxt->delay) / (1000 / HZ));
		}
	}
}

static void temp_poll(unsigned long data)
{
	
	struct temp_context *obj = (struct temp_context *)data;
	printk("[zp],temp_poll ok\n");
	if (obj != NULL)
		schedule_work(&obj->report);
}

static struct temp_context *temp_context_alloc_object(void)
{

	struct temp_context *obj = kzalloc(sizeof(*obj), GFP_KERNEL);

	TEMP_LOG("temp_context_alloc_object++++\n");
	if (!obj) {
		TEMP_ERR("Alloc temp object error!\n");
		return NULL;
	}
	atomic_set(&obj->delay, 200);
	atomic_set(&obj->wake, 0);
	INIT_WORK(&obj->report, temp_work_func);
	init_timer(&obj->timer);
	obj->timer.expires = jiffies + atomic_read(&obj->delay) / (1000 / HZ);
	obj->timer.function = temp_poll;
	obj->timer.data = (unsigned long)obj;
	obj->is_first_data_after_enable = false;
	obj->is_polling_run = false;
	mutex_init(&obj->temp_op_mutex);
	obj->is_batch_enable = false;

	TEMP_LOG("temp_context_alloc_object----\n");
	return obj;
}

static int temp_real_enable(int enable)
{
	int err = 0;
	struct temp_context *cxt = NULL;

	cxt = temp_context_obj;
	if (1 == enable) {

		if (true == cxt->is_active_data || true == cxt->is_active_nodata) {
			err = cxt->temp_ctl.enable_nodata(1);
			if (err) {
				err = cxt->temp_ctl.enable_nodata(1);
				if (err) {
					err = cxt->temp_ctl.enable_nodata(1);
					if (err)
						TEMP_ERR("temp enable(%d) err 3 timers = %d\n", enable, err);
				}
			}
			TEMP_LOG("temp real enable\n");
		}

	}
	if (0 == enable) {
		if (false == cxt->is_active_data && false == cxt->is_active_nodata) {
			err = cxt->temp_ctl.enable_nodata(0);
			if (err)
				TEMP_ERR("temp enable(%d) err = %d\n", enable, err);
			TEMP_LOG("temp real disable\n");
		}

	}

	return err;
}

static int temp_enable_data(int enable)
{
	struct temp_context *cxt = NULL;

	cxt = temp_context_obj;
	if (NULL == cxt->temp_ctl.open_report_data) {
		TEMP_ERR("no temp control path\n");
		return -1;
	}

	if (1 == enable) {
		TEMP_LOG("TEMP enable data\n");
		cxt->is_active_data = true;
		cxt->is_first_data_after_enable = true;
		cxt->temp_ctl.open_report_data(1);
		temp_real_enable(enable);
		if (false == cxt->is_polling_run && cxt->is_batch_enable == false) {
			if (false == cxt->temp_ctl.is_report_input_direct) {
				mod_timer(&cxt->timer, jiffies + atomic_read(&cxt->delay) / (1000 / HZ));
				cxt->is_polling_run = true;
			}
		}
	}
	if (0 == enable) {
		TEMP_LOG("TEMP disable\n");
		cxt->is_active_data = false;
		cxt->temp_ctl.open_report_data(0);
		if (true == cxt->is_polling_run) {
			if (false == cxt->temp_ctl.is_report_input_direct) {
				cxt->is_polling_run = false;
				del_timer_sync(&cxt->timer);
				cancel_work_sync(&cxt->report);
				cxt->drv_data.temp_data.values[0] = TEMP_INVALID_VALUE;
			}
		}
		temp_real_enable(enable);
	}
	return 0;
}

int temp_enable_nodata(int enable)
{
	struct temp_context *cxt = NULL;

	cxt = temp_context_obj;
	if (NULL == cxt->temp_ctl.enable_nodata) {
		TEMP_ERR("temp_enable_nodata:temp ctl path is NULL\n");
		return -1;
	}

	if (1 == enable)
		cxt->is_active_nodata = true;

	if (0 == enable)
		cxt->is_active_nodata = false;
	temp_real_enable(enable);
	return 0;
}

static ssize_t temp_show_enable_nodata(struct device *dev, struct device_attribute *attr, char *buf)
{
	int len = 0;

	TEMP_LOG(" not support now\n");
	return len;
}

static ssize_t temp_store_enable_nodata(struct device *dev, struct device_attribute *attr,
					const char *buf, size_t count)
{
	struct temp_context *cxt = NULL;

	TEMP_LOG("temp_store_enable nodata buf=%s\n", buf);
	mutex_lock(&temp_context_obj->temp_op_mutex);

	cxt = temp_context_obj;
	if (NULL == cxt->temp_ctl.enable_nodata) {
		TEMP_LOG("temp_ctl enable nodata NULL\n");
		mutex_unlock(&temp_context_obj->temp_op_mutex);
		return count;
	}
	if (!strncmp(buf, "1", 1))
		temp_enable_nodata(1);
	else if (!strncmp(buf, "0", 1))
		temp_enable_nodata(0);
	else
		TEMP_ERR(" temp_store enable nodata cmd error !!\n");
	mutex_unlock(&temp_context_obj->temp_op_mutex);

	return count;
}

static ssize_t temp_store_active(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct temp_context *cxt = NULL;

	TEMP_LOG("temp_store_active buf=%s\n", buf);
	mutex_lock(&temp_context_obj->temp_op_mutex);

	cxt = temp_context_obj;
	if (NULL == cxt->temp_ctl.open_report_data) {
		TEMP_LOG("temp_ctl enable NULL\n");
		mutex_unlock(&temp_context_obj->temp_op_mutex);
		return count;
	}
	if (!strncmp(buf, "1", 1))
		temp_enable_data(1);
	else if (!strncmp(buf, "0", 1))
		temp_enable_data(0);
	else
		TEMP_ERR(" temp_store_active error !!\n");
	mutex_unlock(&temp_context_obj->temp_op_mutex);
	TEMP_LOG(" temp_store_active done\n");
	return count;
}

/*----------------------------------------------------------------------------*/
static ssize_t temp_show_active(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct temp_context *cxt = NULL;
	int div = 0;

	cxt = temp_context_obj;
	div = cxt->temp_data.vender_div;

	TEMP_LOG("temp vender_div value: %d\n", div);
	return snprintf(buf, PAGE_SIZE, "%d\n", div);
}

static ssize_t temp_store_delay(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	int delay = 0;
	int mdelay = 0;
	int err = 0;
	struct temp_context *cxt = NULL;

	mutex_lock(&temp_context_obj->temp_op_mutex);

	cxt = temp_context_obj;
	if (NULL == cxt->temp_ctl.set_delay) {
		TEMP_LOG("temp_ctl set_delay NULL\n");
		mutex_unlock(&temp_context_obj->temp_op_mutex);
		return count;
	}
	err = kstrtoint(buf, 10, &delay);
	if (err != 0) {
		TEMP_ERR("invalid format!!\n");
		mutex_unlock(&temp_context_obj->temp_op_mutex);
		return count;
	}

	if (false == cxt->temp_ctl.is_report_input_direct) {
		mdelay = (int)delay / 1000 / 1000;
		atomic_set(&temp_context_obj->delay, mdelay);
	}
	cxt->temp_ctl.set_delay(delay);
	TEMP_LOG(" temp_delay %d ns\n", delay);
	mutex_unlock(&temp_context_obj->temp_op_mutex);
	return count;

}

static ssize_t temp_show_delay(struct device *dev, struct device_attribute *attr, char *buf)
{
	int len = 0;

	TEMP_LOG("not support now\n");
	return len;
}

static ssize_t temp_store_batch(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct temp_context *cxt = NULL;

	TEMP_LOG("temp_store_batch buf=%s\n", buf);
	mutex_lock(&temp_context_obj->temp_op_mutex);

	cxt = temp_context_obj;

	if (!strncmp(buf, "1", 1)) {
		cxt->is_batch_enable = true;
		if (true == cxt->is_polling_run) {
			cxt->is_polling_run = false;
			del_timer_sync(&cxt->timer);
			cancel_work_sync(&cxt->report);
			cxt->drv_data.temp_data.values[0] = TEMP_INVALID_VALUE;
			cxt->drv_data.temp_data.values[1] = TEMP_INVALID_VALUE;
			cxt->drv_data.temp_data.values[2] = TEMP_INVALID_VALUE;
		}
	} else if (!strncmp(buf, "0", 1)) {
		cxt->is_batch_enable = false;
		if (false == cxt->is_polling_run) {
			if (false == cxt->temp_ctl.is_report_input_direct)
				mod_timer(&cxt->timer, jiffies + atomic_read(&cxt->delay) / (1000 / HZ));
				cxt->is_polling_run = true;
		}
	} else {
		TEMP_ERR(" temp_store_batch error !!\n");
	}
	mutex_unlock(&temp_context_obj->temp_op_mutex);
	TEMP_LOG(" temp_store_batch done: %d\n", cxt->is_batch_enable);
	return count;

}

static ssize_t temp_show_batch(struct device *dev, struct device_attribute *attr, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%d\n", 0);
}

static ssize_t temp_store_flush(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	mutex_lock(&temp_context_obj->temp_op_mutex);
	mutex_unlock(&temp_context_obj->temp_op_mutex);
	return count;
}

static ssize_t temp_show_flush(struct device *dev, struct device_attribute *attr, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%d\n", 0);
}

static ssize_t temp_show_devnum(struct device *dev, struct device_attribute *attr, char *buf)
{
	const char *devname = NULL;

	devname = dev_name(&temp_context_obj->idev->dev);
	return snprintf(buf, PAGE_SIZE, "%s\n", devname + 5);
}

static int temperature_remove(struct platform_device *pdev)
{
	TEMP_LOG("temperature_remove\n");
	return 0;
}

static int temperature_probe(struct platform_device *pdev)
{
	TEMP_LOG("temperature_probe\n");
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id temperature_of_match[] = {
	{.compatible = "mediatek,temperature",},
	{},
};
#endif

static struct platform_driver temperature_driver = {
	.probe = temperature_probe,
	.remove = temperature_remove,
	.driver = {
		   .name = "temperature",
#ifdef CONFIG_OF
		   .of_match_table = temperature_of_match,
#endif
		   }
};

static int temp_real_driver_init(void)
{
	int i = 0;
	int err = 0;

	TEMP_LOG(" temp_real_driver_init +\n");
	for (i = 0; i < MAX_CHOOSE_TEMP_NUM; i++) {
		TEMP_LOG(" i=%d\n", i);
		if (0 != temperature_init_list[i]) {
			TEMP_LOG(" temp try to init driver %s\n", temperature_init_list[i]->name);
			err = temperature_init_list[i]->init();
			if (0 == err) {
				TEMP_LOG(" temp real driver %s probe ok\n", temperature_init_list[i]->name);
				break;
			}
		}
	}

	if (i == MAX_CHOOSE_TEMP_NUM) {
		TEMP_LOG(" temp_real_driver_init fail\n");
		err = -1;
	}
	return err;
}

int temp_driver_add(struct temp_init_info *obj)
{
	int err = 0;
	int i = 0;

	//();
	printk("chenpeng line[%d] temp_driver_add\n",__LINE__);
	if (!obj) {
		TEMP_ERR("TEMP driver add fail, temp_init_info is NULL\n");
		return -1;
	}

	for (i = 0; i < MAX_CHOOSE_TEMP_NUM; i++) {
		printk("chenpeng line[%d] temp_driver_add i=%d\n",__LINE__,i);
		if (i == 0) {
			TEMP_LOG("register temperature driver for the first time\n");
			printk("chenpeng line[%d] register temperature driver for the first time i=%d\n",__LINE__,i);
			if (platform_driver_register(&temperature_driver)){
				TEMP_ERR("failed to register gensor driver already exist\n");
				printk("chenpeng line[%d] failed to register gensor driver already exist \n",__LINE__);
				}
		}

		if (NULL == temperature_init_list[i]) {
		printk("chenpeng line[%d] NULL == temperature_init_list\n",__LINE__);
			obj->platform_diver_addr = &temperature_driver;
			temperature_init_list[i] = obj;
			break;
		}
	}
	if (i >= MAX_CHOOSE_TEMP_NUM) {
	printk("chenpeng line[%d] TEMP driver add err\n",__LINE__);
		TEMP_ERR("TEMP driver add err\n");
		err = -1;
	}

	return err;
}
EXPORT_SYMBOL_GPL(temp_driver_add);

static int temp_misc_init(struct temp_context *cxt)
{

	int err = 0;

	cxt->mdev.minor = MISC_DYNAMIC_MINOR;
	cxt->mdev.name = TEMP_MISC_DEV_NAME;
	err = misc_register(&cxt->mdev);
	if (err)
		TEMP_ERR("unable to register temp misc device!!\n");
	return err;
}

static void temp_input_destroy(struct temp_context *cxt)
{
	struct input_dev *dev = cxt->idev;

	input_unregister_device(dev);
	input_free_device(dev);
}

static int temp_input_init(struct temp_context *cxt)
{
	struct input_dev *dev;
	int err = 0;

	dev = input_allocate_device();
	if (NULL == dev)
		return -ENOMEM;

	dev->name = TEMP_INPUTDEV_NAME;

	set_bit(EV_REL, dev->evbit);
	input_set_capability(dev, EV_REL, EVENT_TYPE_TEMPERATURE_VALUE);
	input_set_capability(dev, EV_ABS, EVENT_TYPE_TEMPERATURE_STATUS);

	input_set_abs_params(dev, EVENT_TYPE_TEMPERATURE_STATUS, TEMP_STATUS_MIN, TEMP_STATUS_MAX, 0, 0);
	input_set_drvdata(dev, cxt);

	err = input_register_device(dev);
	if (err < 0) {
		input_free_device(dev);
		return err;
	}
	cxt->idev = dev;

	return 0;
}

DEVICE_ATTR(tempenablenodata, S_IWUSR | S_IRUGO, temp_show_enable_nodata, temp_store_enable_nodata);
DEVICE_ATTR(tempactive, S_IWUSR | S_IRUGO, temp_show_active, temp_store_active);
DEVICE_ATTR(tempdelay, S_IWUSR | S_IRUGO, temp_show_delay, temp_store_delay);
DEVICE_ATTR(tempbatch, S_IWUSR | S_IRUGO, temp_show_batch, temp_store_batch);
DEVICE_ATTR(tempflush, S_IWUSR | S_IRUGO, temp_show_flush, temp_store_flush);
DEVICE_ATTR(tempdevnum, S_IWUSR | S_IRUGO, temp_show_devnum, NULL);

static struct attribute *temp_attributes[] = {
	&dev_attr_tempenablenodata.attr,
	&dev_attr_tempactive.attr,
	&dev_attr_tempdelay.attr,
	&dev_attr_tempbatch.attr,
	&dev_attr_tempflush.attr,
	&dev_attr_tempdevnum.attr,
	NULL
};

static struct attribute_group temp_attribute_group = {
	.attrs = temp_attributes
};

int temp_register_data_path(struct temp_data_path *data)
{
	struct temp_context *cxt = NULL;

	cxt = temp_context_obj;
	cxt->temp_data.get_data = data->get_data;
	cxt->temp_data.vender_div = data->vender_div;
	cxt->temp_data.get_raw_data = data->get_raw_data;
	TEMP_LOG("temp register data path vender_div: %d\n", cxt->temp_data.vender_div);
	if (NULL == cxt->temp_data.get_data) {
		TEMP_LOG("temp register data path fail\n");
		return -1;
	}
	return 0;
}

int temp_register_control_path(struct temp_control_path *ctl)
{
	struct temp_context *cxt = NULL;
	int err = 0;

	cxt = temp_context_obj;
	cxt->temp_ctl.set_delay = ctl->set_delay;
	cxt->temp_ctl.open_report_data = ctl->open_report_data;
	cxt->temp_ctl.enable_nodata = ctl->enable_nodata;
	cxt->temp_ctl.is_support_batch = ctl->is_support_batch;
	cxt->temp_ctl.is_report_input_direct = ctl->is_report_input_direct;
	cxt->temp_ctl.is_support_batch = ctl->is_support_batch;
	cxt->temp_ctl.is_use_common_factory = ctl->is_use_common_factory;

	if (NULL == cxt->temp_ctl.set_delay || NULL == cxt->temp_ctl.open_report_data
	    || NULL == cxt->temp_ctl.enable_nodata) {
		TEMP_LOG("temp register control path fail\n");
		return -1;
	}

	err = temp_misc_init(temp_context_obj);
	if (err) {
		TEMP_ERR("unable to register temp misc device!!\n");
		return -2;
	}
	err = sysfs_create_group(&temp_context_obj->mdev.this_device->kobj, &temp_attribute_group);
	if (err < 0) {
		TEMP_ERR("unable to create temp attribute file\n");
		return -3;
	}

	kobject_uevent(&temp_context_obj->mdev.this_device->kobj, KOBJ_ADD);

	return 0;
}

int temp_data_report(struct input_dev *dev, int value, int status)
{
	input_report_rel(dev, EVENT_TYPE_TEMPERATURE_VALUE, value);
	input_report_abs(dev, EVENT_TYPE_TEMPERATURE_STATUS, status);
	input_sync(dev);

	return 0;
}

static int temp_probe(struct platform_device *pdev)
{

	int err = 0;

	TEMP_LOG("+++++++++++++temp_probe!!\n");

	temp_context_obj = temp_context_alloc_object();
	if (!temp_context_obj) {
		err = -ENOMEM;
		TEMP_ERR("unable to allocate devobj!\n");
		goto exit_alloc_data_failed;
	}
	err = temp_real_driver_init();
	if (err) {
		TEMP_ERR("temp real driver init fail\n");
		goto real_driver_init_fail;
	}
	err = temp_factory_device_init();
	if (err)
		TEMP_ERR("temp factory device already registed\n");
	err = temp_input_init(temp_context_obj);
	if (err) {
		TEMP_ERR("unable to register temp input device!\n");
		goto exit_alloc_input_dev_failed;
	}

	TEMP_LOG("----temp_probe OK !!\n");
	return 0;

	if (err) {
		TEMP_ERR("sysfs node creation error\n");
		temp_input_destroy(temp_context_obj);
	}

real_driver_init_fail:
exit_alloc_input_dev_failed:
	kfree(temp_context_obj);
	temp_context_obj = NULL;
exit_alloc_data_failed:

	TEMP_LOG("----temp_probe fail !!!\n");
	return err;
}

static int temp_remove(struct platform_device *pdev)
{
	int err = 0;

	//(f);

	input_unregister_device(temp_context_obj->idev);
	sysfs_remove_group(&temp_context_obj->idev->dev.kobj, &temp_attribute_group);
	err = misc_deregister(&temp_context_obj->mdev);
	if (err)
		TEMP_ERR("misc_deregister fail: %d\n", err);
	kfree(temp_context_obj);

	return 0;
}

static int temp_suspend(struct platform_device *dev, pm_message_t state)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
static int temp_resume(struct platform_device *dev)
{
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id m_temp_pl_of_match[] = {
	{.compatible = "mediatek,m_temp_pl",},
	{},
};
#endif

static struct platform_driver temp_driver = {
	.probe = temp_probe,
	.remove = temp_remove,
	.suspend = temp_suspend,
	.resume = temp_resume,
	.driver = {
		   .name = TEMP_PL_DEV_NAME,
#ifdef CONFIG_OF
		   .of_match_table = m_temp_pl_of_match,
#endif
		   }
};

static int __init temp_init(void)
{
	//();

	if (platform_driver_register(&temp_driver)) {
		TEMP_ERR("failed to register temp driver\n");
		return -ENODEV;
	}

	return 0;
}

static void __exit temp_exit(void)
{
	platform_driver_unregister(&temp_driver);
	platform_driver_unregister(&temperature_driver);
}

late_initcall(temp_init);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("temperature device driver");
MODULE_AUTHOR("Mediatek");
