
include $(srctree)/drivers/misc/mediatek/imgsensor/src/Makefile.custom

subdir-ccflags-y += -I$(srctree)/drivers/misc/mediatek/imgsensor/src/$(MTK_PLATFORM)

ifeq ($(strip $(AGOLD_CAMERA_VERSION)),yes)
obj-y	+=  agold_cam_version.o
obj-y	+=  agold_camera_info.o
endif

