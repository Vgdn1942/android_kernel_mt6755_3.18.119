/*
FILENAME.
	fps_trigger.h - FPS trigger routine

	$PATH:

FUNCTIONAL DESCRIPTION.
    1. FPS trigger control 

MODIFICATION HISTORY.

NOTICE.
     Copyright (C) 2000-2014 EgisTec All Rights Reserved.
*/

#ifndef _FPS_TRIGGER_CONTROL_H
#define _FPS_TRIGGER_CONTROL_H

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/sched.h>
#include <linux/irq.h>
#include <asm/irq.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/miscdevice.h>
#include <linux/gpio.h>

#include <linux/spi/spi.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/kthread.h>
#include <linux/poll.h>
#include <linux/types.h>

#include <mt_spi.h>
#include <mt-plat/mt_gpio.h>
#include <linux/of.h>
#include <linux/of_irq.h>

/*interrupt free*/
int Interrupt_Free(void);

int Interrupt_Exit(void);
void fingerprint_eint_work_func(struct work_struct *work);

irqreturn_t fingerprint_interrupt(unsigned irq, struct irq_desc *desc);

/*interrupt read status*/
int fps_interrupt_read(struct file *filp, char __user *buff, size_t count, loff_t *offp);

/*interrupt polling*/
unsigned int fps_interrupt_poll(struct file *file, struct poll_table_struct *wait);

#endif
