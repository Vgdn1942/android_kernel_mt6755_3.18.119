subdir-ccflags-y += -Werror
ccflags-y += -I$(srctree)/drivers/misc/mediatek/include/mt-plat/
ccflags-y += -I$(srctree)/drivers/input/touchscreen/mediatek
# In case the platform does NOT support this type of sensors

ifneq ($(CONFIG_TOUCHSCREEN_MTK),)
obj-y   +=  mtk_tpd.o tpd_button.o tpd_calibrate.o tpd_debug.o \
		tpd_default.o tpd_init.o tpd_misc.o tpd_setting.o
endif

obj-$(CONFIG_TOUCHSCREEN_MTK_GT9XX_GESTURE)	+=  GT9XX_GESTURE/
obj-$(CONFIG_TOUCHSCREEN_MTK_FT5406_MT)	+=  FT5406_MT/
obj-$(CONFIG_TOUCHSCREEN_MTK_GT1X)	+=  GT1X/
obj-$(CONFIG_TOUCHSCREEN_MTK_S2202)	+=  S2202/
