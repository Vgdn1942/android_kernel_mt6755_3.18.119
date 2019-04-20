#include $(srctree)/drivers/misc/mediatek/Makefile.custom
ifeq ($(AGOLD_CAMERA_VERSION),yes)
ccflags-y += -I$(srctree)/drivers/misc/mediatek/agold_cam_version
endif

obj-y += ov13853mipiraw_Sensor.o
obj-y += ov13853_otp_pdaf.o
#obj-y += ov13853_otp_cal.o

