#
# Copyright (C) 2015 MediaTek Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
ifeq ($(CONFIG_MTK_CAMERA_VERSION),y)
ccflags-y += -I$(srctree)/drivers/misc/mediatek/cam_version
endif

#obj-y += imx214otp.o
obj-y += imx214mipiraw_Sensor.o
ifeq ($(AGOLD_IMX214_OTP_NULL),)
obj-y += imx214_otp_code.o
endif

