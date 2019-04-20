#include "mt_fps_trigger.h"


/*FPS interrupt table*/
#define GPIO_FPS_EINT_PIN         GPIO_FINGER_IRQ_PIN  
#define GPIO_FPS_EINT_PIN_M_EINT  CUST_EINT_FINGERPRINT_NUM

static volatile char interrupt_values[] = 
{
	'0', '0', '0', '0', '0', '0', '0', '0'
};

static DECLARE_WAIT_QUEUE_HEAD(interrupt_waitq);
static volatile int ev_press = 0;

extern unsigned int et310_irq;
extern void et310_device_change(void);
extern struct delayed_work fingerprint_delay_work;

void fingerprint_eint_work_func(struct work_struct *work)
{
	et310_device_change();
	printk("jay fingerprint_eint_work_func");
	enable_irq(et310_irq);
}
/*
FUNCTION NAME.
    fingerprint_interrupt

FUNCTIONAL DESCRIPTION.
	finger print interrupt callback routine 


ENTRY PARAMETERS.
     irq           
     dev_id 

EXIT PARAMETERS.
    Function Return  – int, 
*/

irqreturn_t fingerprint_interrupt(unsigned irq, struct irq_desc *desc)
{
    
	//printk("[IRQ_et310_irq_registration]jay_FPS interrupt trigger");
	disable_irq_nosync(et310_irq);

	schedule_delayed_work(&fingerprint_delay_work, msecs_to_jiffies(10));
	return IRQ_HANDLED;
}

int Interrupt_Free(void)
{
  return 0;
}

/*
FUNCTION NAME.
	fps_interrupt_read

FUNCTIONAL DESCRIPTION.
	FPS interrupt read status

ENTRY PARAMETERS.

EXIT PARAMETERS.
	Function Return  – int 
*/
int fps_interrupt_read(struct file *filp, char __user *buff, size_t count, loff_t *offp)
{
  unsigned long err;

  if (filp->f_flags & O_NONBLOCK)
  {
    return -EAGAIN;
  }
  else
  {
    wait_event_interruptible(interrupt_waitq, ev_press);
  }

  printk(KERN_ERR "interrupt read condition %d\n",ev_press); 
  printk(KERN_ERR "interrupt value  %d\n",interrupt_values[0]); 

  err = copy_to_user((void *)buff, (const void *)(&interrupt_values),min(sizeof(interrupt_values), count));
    return err ? -EFAULT : min(sizeof(interrupt_values), count);
}

int Interrupt_Exit(void)
{
  return 0;
}

/*
FUNCTION NAME.
	fps_interrupt_read

FUNCTIONAL DESCRIPTION.
	FPS interrupt read status


ENTRY PARAMETERS.
	wait  poll table structure  

EXIT PARAMETERS.
	Function Return  – int, 
*/

unsigned int fps_interrupt_poll(struct file *file, struct poll_table_struct *wait)
{
  unsigned int mask = 0;

  poll_wait(file, &interrupt_waitq, wait);
  if (ev_press)
  {
    mask |= POLLIN | POLLRDNORM;
  }

  return mask;
}


