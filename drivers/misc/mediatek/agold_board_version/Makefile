#include $(srctree)/drivers/misc/mediatek/Makefile.custom
ccflags-y += -I$(srctree)/drivers/misc/mediatek/auxadc
ifeq ($(strip $(AGOLD_BOARD_VERSION)),yes)
obj-y	+=  board_version.o
else
obj-n += dummy.o
endif


