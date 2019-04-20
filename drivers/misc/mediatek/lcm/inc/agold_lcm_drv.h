#ifndef __AGOLD_LCM_DRV_H__
#define __AGOLD_LCM_DRV_H__

#ifndef BUILD_LK
#include <linux/string.h>
#endif
#include "lcm_drv.h"

#ifdef BUILD_LK
	#include <platform/mt_gpio.h>
	#include <string.h>
#elif defined(BUILD_UBOOT)
    #include <asm/arch/mt_gpio.h>
#else
	//#include <mach/mt_gpio.h>
#endif

int agold_lcm_power_on(void);
int agold_lcm_power_down(void);


#endif
