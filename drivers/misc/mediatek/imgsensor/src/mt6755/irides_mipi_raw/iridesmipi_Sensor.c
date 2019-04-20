/*****************************************************************************
 *
 * Filename:
 * ---------
 *     GC5024mipi_Sensor.c
 *
 * Project:
 * --------
 *     ALPS
 *
 * Description:
 * ------------
 *     Source code of Sensor driver
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>

#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"

typedef enum CamIndex
{
	SUBCAMERAMODE = 0,
	IRIDESCAMERAMODE,
	ENDOFMODE
} CAMINDEX;

SENSOR_FUNCTION_STRUCT *pfSensorFunc[ENDOFMODE] = {NULL, NULL};

static int SensorFlag = 1;

extern UINT32 GC5024_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
extern UINT32 IMX132_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc);
extern void iridesPowerOn(int on);

void setSensorFlag(int flag)
{
	SensorFlag = flag;
}

int getSensorFlag(void)
{
	int flag = SensorFlag;
	
	return flag;
}

EXPORT_SYMBOL(getSensorFlag);

static kal_uint32 open(void)
{
	printk("[irides] %s SensorFlag = %d\n", __func__, SensorFlag);
	//iridesPowerOn(SensorFlag);
	//mdelay(10);
	pfSensorFunc[SensorFlag]->SensorOpen();
	
    return ERROR_NONE;
}    /*    open  */


static kal_uint32 close(void)
{
	printk("[irides] %s\n", __func__);
  	pfSensorFunc[SensorFlag]->SensorClose();

    return ERROR_NONE;
}    /*    close  */



static kal_uint32 get_resolution(MSDK_SENSOR_RESOLUTION_INFO_STRUCT *sensor_resolution)
{
	printk("[irides] %s\n", __func__);
    pfSensorFunc[SensorFlag]->SensorGetResolution(sensor_resolution);
    
    return ERROR_NONE;
}    /*    get_resolution    */

static kal_uint32 get_info(MSDK_SCENARIO_ID_ENUM scenario_id,
                      MSDK_SENSOR_INFO_STRUCT *sensor_info,
                      MSDK_SENSOR_CONFIG_STRUCT *sensor_config_data)
{
	printk("[irides] %s\n", __func__);
  	pfSensorFunc[SensorFlag]->SensorGetInfo(scenario_id, sensor_info, sensor_config_data);

    return ERROR_NONE;
}    /*    get_info  */


static kal_uint32 control(MSDK_SCENARIO_ID_ENUM scenario_id, MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *image_window,
                      MSDK_SENSOR_CONFIG_STRUCT *sensor_config_data)
{
	printk("[irides] %s\n", __func__);
    pfSensorFunc[SensorFlag]->SensorControl(scenario_id, image_window, sensor_config_data);
   
    return ERROR_NONE;
}    /* control() */

static void irides_power_update(CAMINDEX Index)
{
	if (SUBCAMERAMODE == Index)
	{
		iridesPowerOn(0);
	}
	else
	{
		iridesPowerOn(1);
	}
}

static kal_uint32 feature_control(MSDK_SENSOR_FEATURE_ENUM feature_id,
                             UINT8 *feature_para, UINT32 *feature_para_len)
{

	UINT32 SensorID[ENDOFMODE] = {0, 0};
	UINT32 *feature_return_para_32=(UINT32 *) feature_para;
	
	if (SENSOR_FEATURE_CHECK_SENSOR_ID == feature_id)
	{
	    irides_power_update(SUBCAMERAMODE);
	    mdelay(10);
		pfSensorFunc[SUBCAMERAMODE]->SensorFeatureControl(feature_id, feature_para, feature_para_len);
		SensorID[SUBCAMERAMODE] = *feature_return_para_32;
		
		irides_power_update(IRIDESCAMERAMODE);
	    mdelay(10);
		pfSensorFunc[IRIDESCAMERAMODE]->SensorFeatureControl(feature_id, feature_para, feature_para_len);
		SensorID[IRIDESCAMERAMODE] = *feature_return_para_32;
		
		printk("read sensor id 0---0x%x, 1----0x%x", SensorID[SUBCAMERAMODE], SensorID[IRIDESCAMERAMODE]);
		
		if ((SensorID[SUBCAMERAMODE] == GC5024_SENSOR_ID) && (SensorID[IRIDESCAMERAMODE] == IMX132_SENSOR_ID))
		{
			*feature_return_para_32 = IRIDES_SENSOR_ID;
			return ERROR_NONE;
		}
		else
		{
			*feature_return_para_32 = 0xFFFFFFFF;
			return ERROR_SENSOR_CONNECT_FAIL;
		}
    }
    else
    {
    	pfSensorFunc[SensorFlag]->SensorFeatureControl(feature_id, feature_para, feature_para_len);
    }
 
    return ERROR_NONE;
}    /*    feature_control()  */

static SENSOR_FUNCTION_STRUCT sensor_func = {
    open,
    get_info,
    get_resolution,
    feature_control,
    control,
    close
};

UINT32 IRIDES_MIPI_RAW_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc)
{
    GC5024_MIPI_RAW_SensorInit(&pfSensorFunc[SUBCAMERAMODE]);
    IMX132_MIPI_RAW_SensorInit(&pfSensorFunc[IRIDESCAMERAMODE]);
    
    if (pfFunc!=NULL)
        *pfFunc=&sensor_func;
    return ERROR_NONE;
}    /*    GC5024MIPI_RAW_SensorInit    */
