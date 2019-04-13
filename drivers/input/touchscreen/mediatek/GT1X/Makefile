ifeq ($(CONFIG_MTK_LCM_PHYSICAL_ROTATION), "90")
ccflags-y += -DMTK_LCM_PHYSICAL_ROTATION=\"90\"
endif

ifeq ($(CONFIG_MTK_LCM_PHYSICAL_ROTATION), "270")
ccflags-y += -DMTK_LCM_PHYSICAL_ROTATION=\"270\"
endif

ifeq ($(CONFIG_MTK_LCM_PHYSICAL_ROTATION), "180")
ccflags-y += -DMTK_LCM_PHYSICAL_ROTATION=\"180\"
endif

ifeq ($(CONFIG_MTK_LCM_PHYSICAL_ROTATION), "0")
ccflags-y += -DMTK_LCM_PHYSICAL_ROTATION=\"0\"
endif

ifeq ($(CONFIG_LCM_WIDTH), "240")
ccflags-y += -DAGOLD_TPD_RES_X=240
else ifeq ($(CONFIG_LCM_WIDTH), "480")
ccflags-y += -DAGOLD_TPD_RES_X=480
else ifeq ($(CONFIG_LCM_WIDTH), "540")
ccflags-y += -DAGOLD_TPD_RES_X=540
else ifeq ($(CONFIG_LCM_WIDTH), "600")
ccflags-y += -DAGOLD_TPD_RES_X=600
else ifeq ($(CONFIG_LCM_WIDTH), "720")
ccflags-y += -DAGOLD_TPD_RES_X=720
else ifeq ($(CONFIG_LCM_WIDTH), "1080")
ccflags-y += -DAGOLD_TPD_RES_X=1080
else ifeq ($(CONFIG_LCM_WIDTH), "1200")
ccflags-y += -DAGOLD_TPD_RES_X=1200
else ifeq ($(CONFIG_LCM_WIDTH), "1536")
ccflags-y += -DAGOLD_TPD_RES_X=1536
endif

ifeq ($(CONFIG_LCM_HEIGHT), "240")
ccflags-y += -DAGOLD_TPD_RES_Y=240
else ifeq ($(CONFIG_LCM_HEIGHT), "432")
ccflags-y += -DAGOLD_TPD_RES_Y=432
else ifeq ($(CONFIG_LCM_HEIGHT), "800")
ccflags-y += -DAGOLD_TPD_RES_Y=800
else ifeq ($(CONFIG_LCM_HEIGHT), "854")
ccflags-y += -DAGOLD_TPD_RES_Y=854
else ifeq ($(CONFIG_LCM_HEIGHT), "960")
ccflags-y += -DAGOLD_TPD_RES_Y=960
else ifeq ($(CONFIG_LCM_HEIGHT), "1280")
ccflags-y += -DAGOLD_TPD_RES_Y=1280
else ifeq ($(CONFIG_LCM_HEIGHT), "1920")
ccflags-y += -DAGOLD_TPD_RES_Y=1920
else ifeq ($(CONFIG_LCM_HEIGHT), "2048")
ccflags-y += -DAGOLD_TPD_RES_Y=2048
endif

# Linux driver folder
ccflags-y += -I$(srctree)/drivers/input/touchscreen/mediatek/GT1X/include/
ccflags-y += -I$(srctree)/drivers/input/touchscreen/mediatek/GT1X/include/config/
ccflags-y += -I$(srctree)/drivers/input/touchscreen/mediatek/
ccflags-y += -I$(srctree)/drivers/misc/mediatek/include/mt-plat/
ccflags-y += -I$(srctree)/drivers/misc/mediatek/include/mt-plat/$(MTK_PLATFORM)/include/

obj-y	+=  gt1x_tpd.o
obj-y	+=  gt1x_generic.o
obj-y	+=  gt1x_extents.o
obj-y	+=  gt1x_tools.o
obj-y	+=  gt1x_update.o

