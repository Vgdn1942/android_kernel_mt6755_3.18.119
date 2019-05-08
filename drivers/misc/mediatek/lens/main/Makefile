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

#
# Makefile for misc devices that really don't fit anywhere else.
#

MTK_PLATFORM := $(subst ",,$(CONFIG_MTK_PLATFORM))
ARCH_MTK_PROJECT := $(subst ",,$(CONFIG_ARCH_MTK_PROJECT))

MTK_CUSTOM_PATH  := $(srctree)/drivers/misc/mediatek

subdir-ccflags-y += -I$(MTK_CUSTOM_PATH)/lens/main/inc

obj-$(CONFIG_MTK_LENS)    += mainaf.o

mainaf-y  += main_lens.o

mainaf-y  += common/ad5820af/AD5820AF.o
mainaf-y  += common/bu6424af/BU6424AF.o
mainaf-y  += common/bu6429af/BU6429AF.o
mainaf-y  += common/dw9714af/DW9714AF.o
mainaf-y  += common/dw9763af/DW9763AF.o
mainaf-y  += common/dw9763xaf/DW9763XAF.o
mainaf-y  += common/dw9800af/DW9800AF.o
mainaf-y  += common/lc898212af/LC898212AF.o
mainaf-y  += common/lc898214af/LC898214AF.o

