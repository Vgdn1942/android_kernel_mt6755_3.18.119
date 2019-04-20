#ifndef __CUST_TEMP_H__
#define __CUST_TEMP_H__

#include <linux/types.h>

#define B_CUST_I2C_ADDR_NUM 2

struct temp_hw {
	int i2c_num;		/*!< the i2c bus used by the chip */
	int direction;		/*!< the direction of the chip */
	int power_id;		/*!< the LDO ID of the chip, MT6516_POWER_NONE means the power is always on */
	int power_vol;		/*!< the Power Voltage used by the chip */
	int firlen;		/*!< the length of low pass filter */
	int (*power)(struct temp_hw *hw, unsigned int on, char *devname);
	/*!< i2c address list,for chips which has different addresses with different HW layout */
	unsigned char i2c_addr[B_CUST_I2C_ADDR_NUM];
	bool is_batch_supported;
};

struct temp_hw *get_temp_dts_func(const char *name, struct temp_hw *hw);

#endif
