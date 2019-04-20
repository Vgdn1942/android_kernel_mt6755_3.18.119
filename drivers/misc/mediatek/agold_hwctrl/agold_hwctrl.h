
#ifndef HWCTRL_H
#define HWCTRL_H

#include <linux/ioctl.h>

#ifdef AGOLD_HWCTRL_ENABLE
//agold wlg start 20130911
typedef struct
{
  int total;
  int free;
  int cached;
}AGOLD_CHANGE_RAM; 
//end

#define HWCTRL			0X86
#define HWCTRL_MODIFIED_VALUE		_IOW(HWCTRL, 0x01, int)
#define SIMLOAD_MODIFIED_VALUE		_IOW(HWCTRL, 0x02, int)      //agold liulou add
//agold wlg start 20130911
#define RAMCTRL_MODIFIED_VALUE		_IOW(HWCTRL, 5, AGOLD_CHANGE_RAM)
//end



#endif

#endif
