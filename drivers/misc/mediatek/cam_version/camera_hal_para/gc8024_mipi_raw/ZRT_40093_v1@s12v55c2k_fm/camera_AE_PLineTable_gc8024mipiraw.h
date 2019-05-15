/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2010. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
*/

#ifndef _CAMERA_AE_PLINETABLE_GC8024MIPI_RAW_H
#define _CAMERA_AE_PLINETABLE_GC8024MIPI_RAW_H

#include "camera_custom_AEPlinetable.h"
static strEvPline sPreviewPLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33348,1056,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.07  BV=2.81
    {33348,1152,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.17  BV=2.71
    {33348,1248,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.29  BV=2.59
    {41664,1056,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.04  BV=2.51
    {41664,1120,1032, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.14  BV=2.42
    {41664,1216,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.25  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {58338,1056,1032, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.06  BV=2.01
    {58338,1152,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.17  BV=1.90
    {66654,1056,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.07  BV=1.81
    {66654,1152,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.17  BV=1.71
    {66654,1216,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.27  BV=1.61
    {66654,1312,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.37  BV=1.51
    {66654,1408,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.47  BV=1.41
    {66654,1504,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.58  BV=1.30
    {66654,1632,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.67  BV=1.21
    {66654,1728,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.77  BV=1.11
    {66654,1856,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.87  BV=1.01
    {66654,2016,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.98  BV=0.90
    {66654,2144,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.07  BV=0.81
    {66654,2304,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.17  BV=0.71
    {75012,2176,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=6.09  BV=0.62
    {83328,2112,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.04  BV=0.51
    {91644,2048,1032, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=6.01  BV=0.41
    {91644,2208,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=6.11  BV=0.31
    {100002,2176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.09  BV=0.21
    {100002,2304,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.18  BV=0.11
    {100002,2496,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.30  BV=-0.00
    {100002,2688,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.39  BV=-0.10
    {100002,2880,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.49  BV=-0.20
    {100002,3104,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.60  BV=-0.31
    {100002,3328,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.70  BV=-0.41
    {100002,3552,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.79  BV=-0.50
    {100002,3808,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.89  BV=-0.60
    {100002,4064,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.99  BV=-0.70
    {100002,4352,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.09  BV=-0.79
    {100002,4704,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.20  BV=-0.91
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5760,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.49  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {100002,7072,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7648,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.90  BV=-1.61
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {100002,8192,1096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.10  BV=-1.81
    {108318,8192,1080, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=8.08  BV=-1.90
    {116676,8192,1080, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=8.08  BV=-2.01
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sPreviewPLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {39984,1024,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.01  BV=2.60
    {39984,1088,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.10  BV=2.52
    {39984,1184,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.21  BV=2.41
    {39984,1248,1040, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.31  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {60018,1024,1040, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.02  BV=2.01
    {60018,1120,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.13  BV=1.90
    {60018,1184,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.22  BV=1.81
    {60018,1280,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.32  BV=1.71
    {60018,1376,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.43  BV=1.60
    {60018,1472,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.52  BV=1.51
    {60018,1568,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.61  BV=1.41
    {60018,1696,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.73  BV=1.30
    {60018,1792,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.82  BV=1.21
    {60018,1920,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.92  BV=1.11
    {60018,2080,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.02  BV=1.01
    {60018,2240,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.13  BV=0.90
    {70014,2048,1032, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.01  BV=0.80
    {70014,2176,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.09  BV=0.72
    {80010,2048,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.00  BV=0.61
    {80010,2208,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.11  BV=0.51
    {90006,2080,1032, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=6.03  BV=0.41
    {90006,2240,1032, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=6.14  BV=0.30
    {100002,2176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.09  BV=0.21
    {100002,2304,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.18  BV=0.11
    {100002,2496,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.30  BV=-0.00
    {100002,2688,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.39  BV=-0.10
    {100002,2880,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.49  BV=-0.20
    {100002,3104,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.60  BV=-0.31
    {100002,3328,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.70  BV=-0.41
    {100002,3552,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.79  BV=-0.50
    {100002,3808,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.89  BV=-0.60
    {100002,4064,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.99  BV=-0.70
    {100002,4352,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.09  BV=-0.79
    {100002,4704,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.20  BV=-0.91
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5760,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.49  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {100002,7072,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7648,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.90  BV=-1.61
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {100002,8192,1096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.10  BV=-1.81
    {109998,8192,1064, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=8.06  BV=-1.90
    {119994,8192,1048, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=8.03  BV=-2.00
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_PreviewAutoTable =
{
    AETABLE_RPEVIEW_AUTO, //eAETableID
    119, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -20, //i4MinBV
    90, //i4EffectiveMaxBV
    -10, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sPreviewPLineTable_60Hz,
    sPreviewPLineTable_50Hz,
    NULL,
};
static strEvPline sCapturePLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33348,1056,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.07  BV=2.81
    {33348,1152,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.17  BV=2.71
    {33348,1248,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.29  BV=2.59
    {41664,1056,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.04  BV=2.51
    {41664,1120,1032, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.14  BV=2.42
    {41664,1216,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.25  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {58338,1056,1032, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.06  BV=2.01
    {58338,1152,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.17  BV=1.90
    {66654,1056,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.07  BV=1.81
    {75012,1024,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=5.00  BV=1.71
    {75012,1088,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=5.09  BV=1.62
    {83328,1056,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.04  BV=1.51
    {83328,1120,1032, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.14  BV=1.42
    {83328,1216,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.25  BV=1.31
    {83328,1280,1040, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.34  BV=1.21
    {83328,1376,1040, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.45  BV=1.11
    {83328,1472,1040, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.55  BV=1.01
    {83328,1600,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.64  BV=0.91
    {83328,1696,1032, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.74  BV=0.82
    {83328,1824,1032, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.84  BV=0.71
    {83328,1952,1032, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.94  BV=0.61
    {83328,2112,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.04  BV=0.51
    {91644,2048,1032, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=6.01  BV=0.41
    {91644,2208,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=6.11  BV=0.31
    {100002,2176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.09  BV=0.21
    {100002,2304,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.18  BV=0.11
    {100002,2496,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.30  BV=-0.00
    {100002,2688,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.39  BV=-0.10
    {100002,2880,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.49  BV=-0.20
    {100002,3104,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.60  BV=-0.31
    {100002,3328,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.70  BV=-0.41
    {100002,3552,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.79  BV=-0.50
    {100002,3808,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.89  BV=-0.60
    {100002,4064,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.99  BV=-0.70
    {100002,4352,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.09  BV=-0.79
    {100002,4704,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.20  BV=-0.91
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5760,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.49  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {100002,7072,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7648,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.90  BV=-1.61
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {100002,8192,1096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.10  BV=-1.81
    {108318,8192,1080, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=8.08  BV=-1.90
    {116676,8192,1080, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=8.08  BV=-2.01
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCapturePLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {39984,1024,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.01  BV=2.60
    {39984,1088,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.10  BV=2.52
    {39984,1184,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.21  BV=2.41
    {39984,1248,1040, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.31  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {60018,1024,1040, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.02  BV=2.01
    {60018,1120,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.13  BV=1.90
    {70014,1024,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=5.00  BV=1.81
    {70014,1088,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=5.09  BV=1.72
    {80010,1024,1032, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.01  BV=1.60
    {80010,1088,1032, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.10  BV=1.52
    {80010,1184,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.21  BV=1.41
    {80010,1248,1040, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.31  BV=1.31
    {80010,1344,1040, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.41  BV=1.20
    {80010,1440,1032, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.50  BV=1.11
    {80010,1536,1040, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.61  BV=1.01
    {80010,1664,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.70  BV=0.91
    {80010,1792,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.81  BV=0.81
    {80010,1920,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.91  BV=0.71
    {80010,2048,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.00  BV=0.61
    {80010,2208,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.11  BV=0.51
    {90006,2080,1032, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=6.03  BV=0.41
    {90006,2240,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=6.13  BV=0.32
    {100002,2176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.09  BV=0.21
    {100002,2304,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.18  BV=0.11
    {100002,2496,1032, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.30  BV=-0.00
    {100002,2688,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.39  BV=-0.10
    {100002,2880,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.49  BV=-0.20
    {100002,3104,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.60  BV=-0.31
    {100002,3328,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.70  BV=-0.41
    {100002,3552,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.79  BV=-0.50
    {100002,3808,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.89  BV=-0.60
    {100002,4064,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.99  BV=-0.70
    {100002,4352,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.09  BV=-0.79
    {100002,4704,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.20  BV=-0.91
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5760,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.49  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {100002,7072,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7648,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.90  BV=-1.61
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {100002,8192,1096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.10  BV=-1.81
    {109998,8192,1064, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=8.06  BV=-1.90
    {119994,8192,1048, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=8.03  BV=-2.00
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_CaptureAutoTable =
{
    AETABLE_CAPTURE_AUTO, //eAETableID
    119, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -20, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCapturePLineTable_60Hz,
    sCapturePLineTable_50Hz,
    NULL,
};
static strEvPline sVideoPLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33180,1056,1040, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=5.07  BV=2.82
    {33180,1152,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=5.17  BV=2.71
    {33180,1216,1040, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=5.27  BV=2.61
    {41664,1056,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.04  BV=2.51
    {41664,1120,1032, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.14  BV=2.42
    {41664,1216,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.25  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {49980,1248,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.29  BV=2.01
    {49980,1312,1040, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.38  BV=1.91
    {49980,1440,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.49  BV=1.80
    {49980,1536,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.58  BV=1.71
    {49980,1632,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.68  BV=1.61
    {49980,1760,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.78  BV=1.51
    {49980,1888,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.88  BV=1.41
    {49980,2016,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.99  BV=1.30
    {49980,2176,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.09  BV=1.21
    {49980,2336,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.19  BV=1.10
    {58338,2144,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=6.07  BV=1.00
    {58338,2272,1032, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=6.16  BV=0.91
    {66528,2144,1024, 0, 0, 0},  //TV = 3.91(1584 lines)  AV=2.97  SV=6.07  BV=0.81
    {75012,2048,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=6.00  BV=0.71
    {75012,2176,1032, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=6.10  BV=0.61
    {83328,2112,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.04  BV=0.51
    {91644,2048,1032, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=6.01  BV=0.41
    {91644,2208,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=6.11  BV=0.31
    {100002,2176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.09  BV=0.21
    {108318,2144,1024, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=6.07  BV=0.11
    {116676,2144,1024, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=6.07  BV=0.00
    {124992,2144,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.07  BV=-0.10
    {124992,2304,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.17  BV=-0.20
    {124992,2464,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.27  BV=-0.30
    {124992,2656,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.38  BV=-0.40
    {124992,2848,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.48  BV=-0.50
    {124992,3040,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.57  BV=-0.60
    {124992,3264,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.67  BV=-0.70
    {124992,3488,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.77  BV=-0.80
    {124992,3744,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.87  BV=-0.90
    {124992,4000,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.97  BV=-0.99
    {124992,4288,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.07  BV=-1.10
    {124992,4640,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.18  BV=-1.21
    {124992,4960,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.28  BV=-1.31
    {124992,5312,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.38  BV=-1.40
    {124992,5696,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.48  BV=-1.50
    {124992,6080,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.57  BV=-1.60
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sVideoPLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {39984,1024,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.01  BV=2.60
    {39984,1088,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.10  BV=2.52
    {39984,1184,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.21  BV=2.41
    {39984,1248,1040, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.31  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {49980,1248,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.29  BV=2.01
    {49980,1312,1040, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.38  BV=1.91
    {49980,1440,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.49  BV=1.80
    {49980,1536,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.58  BV=1.71
    {49980,1632,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.68  BV=1.61
    {49980,1760,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.78  BV=1.51
    {49980,1888,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.88  BV=1.41
    {49980,2016,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.99  BV=1.30
    {49980,2176,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.09  BV=1.21
    {49980,2336,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.19  BV=1.10
    {60018,2080,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.02  BV=1.01
    {60018,2208,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.12  BV=0.91
    {70014,2048,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.00  BV=0.81
    {70014,2176,1032, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.10  BV=0.71
    {80010,2048,1032, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.01  BV=0.60
    {80010,2208,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.11  BV=0.51
    {90006,2080,1032, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=6.03  BV=0.41
    {90006,2240,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=6.13  BV=0.32
    {100002,2176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.09  BV=0.21
    {109998,2112,1024, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=6.04  BV=0.11
    {119994,2080,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.02  BV=0.01
    {119994,2240,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.13  BV=-0.10
    {119994,2400,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.23  BV=-0.20
    {119994,2560,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.32  BV=-0.29
    {119994,2752,1032, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.44  BV=-0.41
    {119994,2944,1032, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.53  BV=-0.50
    {119994,3168,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.63  BV=-0.60
    {119994,3392,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.73  BV=-0.70
    {119994,3648,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.83  BV=-0.80
    {119994,3904,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.93  BV=-0.90
    {119994,4192,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.03  BV=-1.00
    {119994,4480,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.13  BV=-1.10
    {119994,4832,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.24  BV=-1.21
    {119994,5152,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.33  BV=-1.30
    {119994,5536,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.43  BV=-1.40
    {119994,5920,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.53  BV=-1.50
    {119994,6336,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.63  BV=-1.60
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_VideoAutoTable =
{
    AETABLE_VIDEO_AUTO, //eAETableID
    115, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -16, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideoPLineTable_60Hz,
    sVideoPLineTable_50Hz,
    NULL,
};
static strEvPline sVideo1PLineTable_60Hz =
{
{
    {252,1344,1032, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.40  BV=9.52
    {252,1344,1040, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.41  BV=9.51
    {294,1248,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.29  BV=9.42
    {294,1344,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.39  BV=9.31
    {336,1248,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.30  BV=9.21
    {378,1184,1040, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.23  BV=9.11
    {378,1280,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.32  BV=9.02
    {420,1248,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.29  BV=8.90
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {504,1280,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.32  BV=8.60
    {546,1248,1032, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.30  BV=8.51
    {588,1248,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.29  BV=8.42
    {630,1248,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=5.29  BV=8.32
    {672,1248,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.30  BV=8.21
    {714,1248,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.31  BV=8.11
    {798,1216,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.25  BV=8.01
    {840,1248,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=5.29  BV=7.90
    {924,1216,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.25  BV=7.80
    {966,1248,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=5.29  BV=7.70
    {1050,1216,1024, 0, 0, 0},  //TV = 9.90(25 lines)  AV=2.97  SV=5.25  BV=7.62
    {1134,1216,1024, 0, 0, 0},  //TV = 9.78(27 lines)  AV=2.97  SV=5.25  BV=7.51
    {1218,1216,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.25  BV=7.40
    {1302,1216,1024, 0, 0, 0},  //TV = 9.59(31 lines)  AV=2.97  SV=5.25  BV=7.31
    {1386,1216,1024, 0, 0, 0},  //TV = 9.49(33 lines)  AV=2.97  SV=5.25  BV=7.22
    {1512,1184,1040, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.23  BV=7.11
    {1596,1216,1024, 0, 0, 0},  //TV = 9.29(38 lines)  AV=2.97  SV=5.25  BV=7.01
    {1722,1216,1024, 0, 0, 0},  //TV = 9.18(41 lines)  AV=2.97  SV=5.25  BV=6.90
    {1848,1216,1024, 0, 0, 0},  //TV = 9.08(44 lines)  AV=2.97  SV=5.25  BV=6.80
    {1974,1216,1024, 0, 0, 0},  //TV = 8.98(47 lines)  AV=2.97  SV=5.25  BV=6.71
    {2100,1216,1024, 0, 0, 0},  //TV = 8.90(50 lines)  AV=2.97  SV=5.25  BV=6.62
    {2268,1216,1024, 0, 0, 0},  //TV = 8.78(54 lines)  AV=2.97  SV=5.25  BV=6.51
    {2436,1216,1024, 0, 0, 0},  //TV = 8.68(58 lines)  AV=2.97  SV=5.25  BV=6.40
    {2604,1216,1024, 0, 0, 0},  //TV = 8.59(62 lines)  AV=2.97  SV=5.25  BV=6.31
    {2814,1184,1040, 0, 0, 0},  //TV = 8.47(67 lines)  AV=2.97  SV=5.23  BV=6.21
    {3024,1184,1040, 0, 0, 0},  //TV = 8.37(72 lines)  AV=2.97  SV=5.23  BV=6.11
    {3234,1184,1040, 0, 0, 0},  //TV = 8.27(77 lines)  AV=2.97  SV=5.23  BV=6.01
    {3444,1216,1024, 0, 0, 0},  //TV = 8.18(82 lines)  AV=2.97  SV=5.25  BV=5.90
    {3738,1184,1032, 0, 0, 0},  //TV = 8.06(89 lines)  AV=2.97  SV=5.22  BV=5.81
    {3990,1184,1040, 0, 0, 0},  //TV = 7.97(95 lines)  AV=2.97  SV=5.23  BV=5.71
    {4284,1184,1032, 0, 0, 0},  //TV = 7.87(102 lines)  AV=2.97  SV=5.22  BV=5.62
    {4578,1184,1040, 0, 0, 0},  //TV = 7.77(109 lines)  AV=2.97  SV=5.23  BV=5.51
    {4956,1184,1032, 0, 0, 0},  //TV = 7.66(118 lines)  AV=2.97  SV=5.22  BV=5.41
    {5250,1184,1040, 0, 0, 0},  //TV = 7.57(125 lines)  AV=2.97  SV=5.23  BV=5.31
    {5670,1184,1032, 0, 0, 0},  //TV = 7.46(135 lines)  AV=2.97  SV=5.22  BV=5.21
    {6048,1184,1040, 0, 0, 0},  //TV = 7.37(144 lines)  AV=2.97  SV=5.23  BV=5.11
    {6510,1184,1032, 0, 0, 0},  //TV = 7.26(155 lines)  AV=2.97  SV=5.22  BV=5.01
    {6972,1184,1032, 0, 0, 0},  //TV = 7.16(166 lines)  AV=2.97  SV=5.22  BV=4.91
    {7434,1184,1040, 0, 0, 0},  //TV = 7.07(177 lines)  AV=2.97  SV=5.23  BV=4.81
    {8022,1184,1040, 0, 0, 0},  //TV = 6.96(191 lines)  AV=2.97  SV=5.23  BV=4.70
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.47  BV=4.41
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {8316,2144,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.07  BV=3.81
    {8316,2304,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {16674,1856,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.87  BV=3.01
    {16674,2016,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.98  BV=2.90
    {16674,2144,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.07  BV=2.81
    {16674,2304,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.17  BV=2.71
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2624,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.37  BV=2.51
    {16674,2816,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.47  BV=2.41
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {16674,3744,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.87  BV=2.01
    {16674,4000,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.97  BV=1.91
    {16674,4320,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.08  BV=1.80
    {16674,4608,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.17  BV=1.71
    {16674,4928,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.27  BV=1.61
    {16674,5280,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.37  BV=1.51
    {16674,5664,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.47  BV=1.41
    {16674,6080,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.57  BV=1.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sVideo1PLineTable_50Hz =
{
{
    {252,1344,1032, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.40  BV=9.52
    {252,1344,1040, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.41  BV=9.51
    {294,1248,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.29  BV=9.42
    {294,1344,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.39  BV=9.31
    {336,1248,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.30  BV=9.21
    {378,1184,1040, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.23  BV=9.11
    {378,1280,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.32  BV=9.02
    {420,1248,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.29  BV=8.90
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {504,1280,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.32  BV=8.60
    {546,1248,1032, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.30  BV=8.51
    {588,1248,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.29  BV=8.42
    {630,1248,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=5.29  BV=8.32
    {672,1248,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.30  BV=8.21
    {714,1248,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.31  BV=8.11
    {798,1216,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.25  BV=8.01
    {840,1248,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=5.29  BV=7.90
    {924,1216,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.25  BV=7.80
    {966,1248,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=5.29  BV=7.70
    {1050,1216,1024, 0, 0, 0},  //TV = 9.90(25 lines)  AV=2.97  SV=5.25  BV=7.62
    {1134,1216,1024, 0, 0, 0},  //TV = 9.78(27 lines)  AV=2.97  SV=5.25  BV=7.51
    {1218,1216,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.25  BV=7.40
    {1302,1216,1024, 0, 0, 0},  //TV = 9.59(31 lines)  AV=2.97  SV=5.25  BV=7.31
    {1386,1216,1024, 0, 0, 0},  //TV = 9.49(33 lines)  AV=2.97  SV=5.25  BV=7.22
    {1512,1184,1040, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.23  BV=7.11
    {1596,1216,1024, 0, 0, 0},  //TV = 9.29(38 lines)  AV=2.97  SV=5.25  BV=7.01
    {1722,1216,1024, 0, 0, 0},  //TV = 9.18(41 lines)  AV=2.97  SV=5.25  BV=6.90
    {1848,1216,1024, 0, 0, 0},  //TV = 9.08(44 lines)  AV=2.97  SV=5.25  BV=6.80
    {1974,1216,1024, 0, 0, 0},  //TV = 8.98(47 lines)  AV=2.97  SV=5.25  BV=6.71
    {2100,1216,1024, 0, 0, 0},  //TV = 8.90(50 lines)  AV=2.97  SV=5.25  BV=6.62
    {2268,1216,1024, 0, 0, 0},  //TV = 8.78(54 lines)  AV=2.97  SV=5.25  BV=6.51
    {2436,1216,1024, 0, 0, 0},  //TV = 8.68(58 lines)  AV=2.97  SV=5.25  BV=6.40
    {2604,1216,1024, 0, 0, 0},  //TV = 8.59(62 lines)  AV=2.97  SV=5.25  BV=6.31
    {2814,1184,1040, 0, 0, 0},  //TV = 8.47(67 lines)  AV=2.97  SV=5.23  BV=6.21
    {3024,1184,1040, 0, 0, 0},  //TV = 8.37(72 lines)  AV=2.97  SV=5.23  BV=6.11
    {3234,1184,1040, 0, 0, 0},  //TV = 8.27(77 lines)  AV=2.97  SV=5.23  BV=6.01
    {3444,1216,1024, 0, 0, 0},  //TV = 8.18(82 lines)  AV=2.97  SV=5.25  BV=5.90
    {3738,1184,1032, 0, 0, 0},  //TV = 8.06(89 lines)  AV=2.97  SV=5.22  BV=5.81
    {3990,1184,1040, 0, 0, 0},  //TV = 7.97(95 lines)  AV=2.97  SV=5.23  BV=5.71
    {4284,1184,1032, 0, 0, 0},  //TV = 7.87(102 lines)  AV=2.97  SV=5.22  BV=5.62
    {4578,1184,1040, 0, 0, 0},  //TV = 7.77(109 lines)  AV=2.97  SV=5.23  BV=5.51
    {4956,1184,1032, 0, 0, 0},  //TV = 7.66(118 lines)  AV=2.97  SV=5.22  BV=5.41
    {5250,1184,1040, 0, 0, 0},  //TV = 7.57(125 lines)  AV=2.97  SV=5.23  BV=5.31
    {5670,1184,1032, 0, 0, 0},  //TV = 7.46(135 lines)  AV=2.97  SV=5.22  BV=5.21
    {6048,1184,1040, 0, 0, 0},  //TV = 7.37(144 lines)  AV=2.97  SV=5.23  BV=5.11
    {6510,1184,1032, 0, 0, 0},  //TV = 7.26(155 lines)  AV=2.97  SV=5.22  BV=5.01
    {6972,1184,1032, 0, 0, 0},  //TV = 7.16(166 lines)  AV=2.97  SV=5.22  BV=4.91
    {7434,1184,1040, 0, 0, 0},  //TV = 7.07(177 lines)  AV=2.97  SV=5.23  BV=4.81
    {8022,1184,1040, 0, 0, 0},  //TV = 6.96(191 lines)  AV=2.97  SV=5.23  BV=4.70
    {8568,1184,1032, 0, 0, 0},  //TV = 6.87(204 lines)  AV=2.97  SV=5.22  BV=4.62
    {9156,1184,1040, 0, 0, 0},  //TV = 6.77(218 lines)  AV=2.97  SV=5.23  BV=4.51
    {9870,1184,1040, 0, 0, 0},  //TV = 6.66(235 lines)  AV=2.97  SV=5.23  BV=4.40
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.50  BV=4.11
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.00  BV=3.62
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3360,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.71  BV=2.90
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4128,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.01  BV=2.60
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4704,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.20  BV=2.42
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {9996,6240,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.61  BV=2.01
    {9996,6688,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.71  BV=1.91
    {9996,7136,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.80  BV=1.81
    {9996,7712,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.91  BV=1.70
    {9996,8192,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.01  BV=1.60
    {9996,8192,1104, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.11  BV=1.51
    {9996,8192,1184, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.21  BV=1.41
    {9996,8192,1264, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.30  BV=1.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_Video1AutoTable =
{
    AETABLE_VIDEO1_AUTO, //eAETableID
    84, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    13, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideo1PLineTable_60Hz,
    sVideo1PLineTable_50Hz,
    NULL,
};
static strEvPline sVideo2PLineTable_60Hz =
{
{
    {252,1344,1032, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.40  BV=9.52
    {252,1344,1040, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.41  BV=9.51
    {294,1248,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.29  BV=9.42
    {294,1344,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.39  BV=9.31
    {336,1248,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.30  BV=9.21
    {378,1184,1040, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.23  BV=9.11
    {378,1280,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.32  BV=9.02
    {420,1248,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.29  BV=8.90
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {504,1280,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.32  BV=8.60
    {546,1248,1032, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.30  BV=8.51
    {588,1248,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.29  BV=8.42
    {630,1248,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=5.29  BV=8.32
    {672,1248,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.30  BV=8.21
    {714,1248,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.31  BV=8.11
    {798,1216,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.25  BV=8.01
    {840,1248,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=5.29  BV=7.90
    {924,1216,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.25  BV=7.80
    {966,1248,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=5.29  BV=7.70
    {1050,1216,1024, 0, 0, 0},  //TV = 9.90(25 lines)  AV=2.97  SV=5.25  BV=7.62
    {1134,1216,1024, 0, 0, 0},  //TV = 9.78(27 lines)  AV=2.97  SV=5.25  BV=7.51
    {1218,1216,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.25  BV=7.40
    {1302,1216,1024, 0, 0, 0},  //TV = 9.59(31 lines)  AV=2.97  SV=5.25  BV=7.31
    {1386,1216,1024, 0, 0, 0},  //TV = 9.49(33 lines)  AV=2.97  SV=5.25  BV=7.22
    {1512,1184,1040, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.23  BV=7.11
    {1596,1216,1024, 0, 0, 0},  //TV = 9.29(38 lines)  AV=2.97  SV=5.25  BV=7.01
    {1722,1216,1024, 0, 0, 0},  //TV = 9.18(41 lines)  AV=2.97  SV=5.25  BV=6.90
    {1848,1216,1024, 0, 0, 0},  //TV = 9.08(44 lines)  AV=2.97  SV=5.25  BV=6.80
    {1974,1216,1024, 0, 0, 0},  //TV = 8.98(47 lines)  AV=2.97  SV=5.25  BV=6.71
    {2100,1216,1024, 0, 0, 0},  //TV = 8.90(50 lines)  AV=2.97  SV=5.25  BV=6.62
    {2268,1216,1024, 0, 0, 0},  //TV = 8.78(54 lines)  AV=2.97  SV=5.25  BV=6.51
    {2436,1216,1024, 0, 0, 0},  //TV = 8.68(58 lines)  AV=2.97  SV=5.25  BV=6.40
    {2604,1216,1024, 0, 0, 0},  //TV = 8.59(62 lines)  AV=2.97  SV=5.25  BV=6.31
    {2814,1184,1040, 0, 0, 0},  //TV = 8.47(67 lines)  AV=2.97  SV=5.23  BV=6.21
    {3024,1184,1040, 0, 0, 0},  //TV = 8.37(72 lines)  AV=2.97  SV=5.23  BV=6.11
    {3234,1184,1040, 0, 0, 0},  //TV = 8.27(77 lines)  AV=2.97  SV=5.23  BV=6.01
    {3444,1216,1024, 0, 0, 0},  //TV = 8.18(82 lines)  AV=2.97  SV=5.25  BV=5.90
    {3738,1184,1032, 0, 0, 0},  //TV = 8.06(89 lines)  AV=2.97  SV=5.22  BV=5.81
    {3990,1184,1040, 0, 0, 0},  //TV = 7.97(95 lines)  AV=2.97  SV=5.23  BV=5.71
    {4284,1184,1032, 0, 0, 0},  //TV = 7.87(102 lines)  AV=2.97  SV=5.22  BV=5.62
    {4578,1184,1040, 0, 0, 0},  //TV = 7.77(109 lines)  AV=2.97  SV=5.23  BV=5.51
    {4956,1184,1032, 0, 0, 0},  //TV = 7.66(118 lines)  AV=2.97  SV=5.22  BV=5.41
    {5250,1184,1040, 0, 0, 0},  //TV = 7.57(125 lines)  AV=2.97  SV=5.23  BV=5.31
    {5670,1184,1032, 0, 0, 0},  //TV = 7.46(135 lines)  AV=2.97  SV=5.22  BV=5.21
    {6048,1184,1040, 0, 0, 0},  //TV = 7.37(144 lines)  AV=2.97  SV=5.23  BV=5.11
    {6510,1184,1032, 0, 0, 0},  //TV = 7.26(155 lines)  AV=2.97  SV=5.22  BV=5.01
    {6972,1184,1032, 0, 0, 0},  //TV = 7.16(166 lines)  AV=2.97  SV=5.22  BV=4.91
    {7434,1184,1040, 0, 0, 0},  //TV = 7.07(177 lines)  AV=2.97  SV=5.23  BV=4.81
    {8022,1184,1040, 0, 0, 0},  //TV = 6.96(191 lines)  AV=2.97  SV=5.23  BV=4.70
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.47  BV=4.41
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {8316,2144,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.07  BV=3.81
    {8316,2304,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {16674,1856,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.87  BV=3.01
    {16674,2016,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.98  BV=2.90
    {16674,2144,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.07  BV=2.81
    {16674,2304,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.17  BV=2.71
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2624,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.37  BV=2.51
    {16674,2816,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.47  BV=2.41
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {16674,3744,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.87  BV=2.01
    {16674,4000,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.97  BV=1.91
    {16674,4288,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.07  BV=1.81
    {24990,3072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.58  BV=1.71
    {24990,3296,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.69  BV=1.61
    {24990,3520,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.78  BV=1.51
    {24990,3776,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.88  BV=1.41
    {24990,4032,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.98  BV=1.32
    {33180,3264,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=6.67  BV=1.21
    {33180,3488,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=6.77  BV=1.12
    {33180,3744,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=6.87  BV=1.01
    {33180,4000,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=6.97  BV=0.92
    {33180,4320,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=7.08  BV=0.81
    {33180,4640,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=7.18  BV=0.70
    {33180,4960,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=7.28  BV=0.61
    {33180,5312,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=7.38  BV=0.51
    {33180,5696,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=7.48  BV=0.41
    {33180,6080,1024, 0, 0, 0},  //TV = 4.91(790 lines)  AV=2.97  SV=7.57  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sVideo2PLineTable_50Hz =
{
{
    {252,1344,1032, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.40  BV=9.52
    {252,1344,1040, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.41  BV=9.51
    {294,1248,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.29  BV=9.42
    {294,1344,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.39  BV=9.31
    {336,1248,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.30  BV=9.21
    {378,1184,1040, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.23  BV=9.11
    {378,1280,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.32  BV=9.02
    {420,1248,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.29  BV=8.90
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {504,1280,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.32  BV=8.60
    {546,1248,1032, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.30  BV=8.51
    {588,1248,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.29  BV=8.42
    {630,1248,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=5.29  BV=8.32
    {672,1248,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.30  BV=8.21
    {714,1248,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.31  BV=8.11
    {798,1216,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.25  BV=8.01
    {840,1248,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=5.29  BV=7.90
    {924,1216,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.25  BV=7.80
    {966,1248,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=5.29  BV=7.70
    {1050,1216,1024, 0, 0, 0},  //TV = 9.90(25 lines)  AV=2.97  SV=5.25  BV=7.62
    {1134,1216,1024, 0, 0, 0},  //TV = 9.78(27 lines)  AV=2.97  SV=5.25  BV=7.51
    {1218,1216,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.25  BV=7.40
    {1302,1216,1024, 0, 0, 0},  //TV = 9.59(31 lines)  AV=2.97  SV=5.25  BV=7.31
    {1386,1216,1024, 0, 0, 0},  //TV = 9.49(33 lines)  AV=2.97  SV=5.25  BV=7.22
    {1512,1184,1040, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.23  BV=7.11
    {1596,1216,1024, 0, 0, 0},  //TV = 9.29(38 lines)  AV=2.97  SV=5.25  BV=7.01
    {1722,1216,1024, 0, 0, 0},  //TV = 9.18(41 lines)  AV=2.97  SV=5.25  BV=6.90
    {1848,1216,1024, 0, 0, 0},  //TV = 9.08(44 lines)  AV=2.97  SV=5.25  BV=6.80
    {1974,1216,1024, 0, 0, 0},  //TV = 8.98(47 lines)  AV=2.97  SV=5.25  BV=6.71
    {2100,1216,1024, 0, 0, 0},  //TV = 8.90(50 lines)  AV=2.97  SV=5.25  BV=6.62
    {2268,1216,1024, 0, 0, 0},  //TV = 8.78(54 lines)  AV=2.97  SV=5.25  BV=6.51
    {2436,1216,1024, 0, 0, 0},  //TV = 8.68(58 lines)  AV=2.97  SV=5.25  BV=6.40
    {2604,1216,1024, 0, 0, 0},  //TV = 8.59(62 lines)  AV=2.97  SV=5.25  BV=6.31
    {2814,1184,1040, 0, 0, 0},  //TV = 8.47(67 lines)  AV=2.97  SV=5.23  BV=6.21
    {3024,1184,1040, 0, 0, 0},  //TV = 8.37(72 lines)  AV=2.97  SV=5.23  BV=6.11
    {3234,1184,1040, 0, 0, 0},  //TV = 8.27(77 lines)  AV=2.97  SV=5.23  BV=6.01
    {3444,1216,1024, 0, 0, 0},  //TV = 8.18(82 lines)  AV=2.97  SV=5.25  BV=5.90
    {3738,1184,1032, 0, 0, 0},  //TV = 8.06(89 lines)  AV=2.97  SV=5.22  BV=5.81
    {3990,1184,1040, 0, 0, 0},  //TV = 7.97(95 lines)  AV=2.97  SV=5.23  BV=5.71
    {4284,1184,1032, 0, 0, 0},  //TV = 7.87(102 lines)  AV=2.97  SV=5.22  BV=5.62
    {4578,1184,1040, 0, 0, 0},  //TV = 7.77(109 lines)  AV=2.97  SV=5.23  BV=5.51
    {4956,1184,1032, 0, 0, 0},  //TV = 7.66(118 lines)  AV=2.97  SV=5.22  BV=5.41
    {5250,1184,1040, 0, 0, 0},  //TV = 7.57(125 lines)  AV=2.97  SV=5.23  BV=5.31
    {5670,1184,1032, 0, 0, 0},  //TV = 7.46(135 lines)  AV=2.97  SV=5.22  BV=5.21
    {6048,1184,1040, 0, 0, 0},  //TV = 7.37(144 lines)  AV=2.97  SV=5.23  BV=5.11
    {6510,1184,1032, 0, 0, 0},  //TV = 7.26(155 lines)  AV=2.97  SV=5.22  BV=5.01
    {6972,1184,1032, 0, 0, 0},  //TV = 7.16(166 lines)  AV=2.97  SV=5.22  BV=4.91
    {7434,1184,1040, 0, 0, 0},  //TV = 7.07(177 lines)  AV=2.97  SV=5.23  BV=4.81
    {8022,1184,1040, 0, 0, 0},  //TV = 6.96(191 lines)  AV=2.97  SV=5.23  BV=4.70
    {8568,1184,1032, 0, 0, 0},  //TV = 6.87(204 lines)  AV=2.97  SV=5.22  BV=4.62
    {9156,1184,1040, 0, 0, 0},  //TV = 6.77(218 lines)  AV=2.97  SV=5.23  BV=4.51
    {9870,1184,1040, 0, 0, 0},  //TV = 6.66(235 lines)  AV=2.97  SV=5.23  BV=4.40
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.50  BV=4.11
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.00  BV=3.62
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3360,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.71  BV=2.90
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4128,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.01  BV=2.60
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4704,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.20  BV=2.42
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {19992,3104,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.60  BV=2.02
    {19992,3328,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.70  BV=1.91
    {19992,3584,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.81  BV=1.81
    {19992,3840,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.91  BV=1.71
    {19992,4128,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.01  BV=1.60
    {19992,4416,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.11  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {29988,3360,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.71  BV=1.32
    {29988,3616,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.82  BV=1.21
    {29988,3872,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.92  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4480,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.13  BV=0.90
    {29988,4800,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.23  BV=0.80
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.42  BV=0.61
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_Video2AutoTable =
{
    AETABLE_VIDEO2_AUTO, //eAETableID
    94, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    3, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideo2PLineTable_60Hz,
    sVideo2PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom1PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.58  BV=3.30
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {16674,1856,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.87  BV=3.01
    {16674,2016,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.98  BV=2.90
    {16674,2144,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.07  BV=2.81
    {16674,2304,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.17  BV=2.71
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2656,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.38  BV=2.50
    {16674,2816,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.47  BV=2.41
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {16674,3744,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.87  BV=2.01
    {16674,4000,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.97  BV=1.91
    {16674,4288,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.07  BV=1.81
    {24990,3072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.58  BV=1.71
    {24990,3296,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.69  BV=1.61
    {24990,3520,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.78  BV=1.51
    {24990,3776,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.88  BV=1.41
    {24990,4032,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.98  BV=1.32
    {33348,3264,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.67  BV=1.20
    {33348,3488,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.77  BV=1.11
    {33348,3712,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.86  BV=1.02
    {33348,4032,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.98  BV=0.90
    {33348,4288,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.07  BV=0.81
    {33348,4608,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.17  BV=0.71
    {33348,4928,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.27  BV=0.61
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6048,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.56  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCustom1PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.01  BV=3.60
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3360,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.71  BV=2.90
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4096,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.00  BV=2.62
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4736,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.21  BV=2.41
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {19992,3104,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.60  BV=2.02
    {19992,3328,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.70  BV=1.91
    {19992,3584,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.81  BV=1.81
    {19992,3840,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.91  BV=1.71
    {19992,4128,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.01  BV=1.60
    {19992,4416,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.11  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {29988,3360,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.71  BV=1.32
    {29988,3616,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.82  BV=1.21
    {29988,3872,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.92  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4480,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.13  BV=0.90
    {29988,4800,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.23  BV=0.80
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.42  BV=0.61
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_Custom1AutoTable =
{
    AETABLE_CUSTOM1_AUTO, //eAETableID
    96, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    3, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom1PLineTable_60Hz,
    sCustom1PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom2PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.58  BV=3.30
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {16674,1856,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.87  BV=3.01
    {16674,2016,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.98  BV=2.90
    {16674,2144,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.07  BV=2.81
    {16674,2304,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.17  BV=2.71
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2656,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.38  BV=2.50
    {16674,2816,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.47  BV=2.41
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {16674,3744,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.87  BV=2.01
    {16674,4000,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.97  BV=1.91
    {16674,4288,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.07  BV=1.81
    {24990,3072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.58  BV=1.71
    {24990,3296,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.69  BV=1.61
    {24990,3520,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.78  BV=1.51
    {24990,3776,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.88  BV=1.41
    {24990,4032,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.98  BV=1.32
    {33348,3264,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.67  BV=1.20
    {33348,3488,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.77  BV=1.11
    {33348,3712,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.86  BV=1.02
    {33348,4032,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.98  BV=0.90
    {33348,4288,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.07  BV=0.81
    {33348,4608,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.17  BV=0.71
    {33348,4928,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.27  BV=0.61
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6048,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.56  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCustom2PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.01  BV=3.60
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3360,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.71  BV=2.90
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4096,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.00  BV=2.62
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4736,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.21  BV=2.41
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {19992,3104,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.60  BV=2.02
    {19992,3328,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.70  BV=1.91
    {19992,3584,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.81  BV=1.81
    {19992,3840,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.91  BV=1.71
    {19992,4128,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.01  BV=1.60
    {19992,4416,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.11  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {29988,3360,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.71  BV=1.32
    {29988,3616,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.82  BV=1.21
    {29988,3872,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.92  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4480,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.13  BV=0.90
    {29988,4800,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.23  BV=0.80
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.42  BV=0.61
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_Custom2AutoTable =
{
    AETABLE_CUSTOM2_AUTO, //eAETableID
    96, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    3, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom2PLineTable_60Hz,
    sCustom2PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom3PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.58  BV=3.30
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {16674,1856,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.87  BV=3.01
    {16674,2016,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.98  BV=2.90
    {16674,2144,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.07  BV=2.81
    {16674,2304,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.17  BV=2.71
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2656,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.38  BV=2.50
    {16674,2816,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.47  BV=2.41
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {16674,3744,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.87  BV=2.01
    {16674,4000,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.97  BV=1.91
    {16674,4288,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.07  BV=1.81
    {24990,3072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.58  BV=1.71
    {24990,3296,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.69  BV=1.61
    {24990,3520,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.78  BV=1.51
    {24990,3776,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.88  BV=1.41
    {24990,4032,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.98  BV=1.32
    {33348,3264,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.67  BV=1.20
    {33348,3488,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.77  BV=1.11
    {33348,3712,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.86  BV=1.02
    {33348,4032,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.98  BV=0.90
    {33348,4288,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.07  BV=0.81
    {33348,4608,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.17  BV=0.71
    {33348,4928,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.27  BV=0.61
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6048,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.56  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCustom3PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.01  BV=3.60
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3360,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.71  BV=2.90
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4096,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.00  BV=2.62
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4736,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.21  BV=2.41
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {19992,3104,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.60  BV=2.02
    {19992,3328,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.70  BV=1.91
    {19992,3584,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.81  BV=1.81
    {19992,3840,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.91  BV=1.71
    {19992,4128,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.01  BV=1.60
    {19992,4416,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.11  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {29988,3360,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.71  BV=1.32
    {29988,3616,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.82  BV=1.21
    {29988,3872,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.92  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4480,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.13  BV=0.90
    {29988,4800,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.23  BV=0.80
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.42  BV=0.61
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_Custom3AutoTable =
{
    AETABLE_CUSTOM3_AUTO, //eAETableID
    96, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    3, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom3PLineTable_60Hz,
    sCustom3PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom4PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.58  BV=3.30
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {16674,1856,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.87  BV=3.01
    {16674,2016,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.98  BV=2.90
    {16674,2144,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.07  BV=2.81
    {16674,2304,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.17  BV=2.71
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2656,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.38  BV=2.50
    {16674,2816,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.47  BV=2.41
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {16674,3744,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.87  BV=2.01
    {16674,4000,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.97  BV=1.91
    {16674,4288,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.07  BV=1.81
    {24990,3072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.58  BV=1.71
    {24990,3296,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.69  BV=1.61
    {24990,3520,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.78  BV=1.51
    {24990,3776,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.88  BV=1.41
    {24990,4032,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.98  BV=1.32
    {33348,3264,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.67  BV=1.20
    {33348,3488,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.77  BV=1.11
    {33348,3712,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.86  BV=1.02
    {33348,4032,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.98  BV=0.90
    {33348,4288,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.07  BV=0.81
    {33348,4608,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.17  BV=0.71
    {33348,4928,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.27  BV=0.61
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6048,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.56  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCustom4PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.01  BV=3.60
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3360,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.71  BV=2.90
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4096,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.00  BV=2.62
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4736,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.21  BV=2.41
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {19992,3104,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.60  BV=2.02
    {19992,3328,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.70  BV=1.91
    {19992,3584,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.81  BV=1.81
    {19992,3840,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.91  BV=1.71
    {19992,4128,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.01  BV=1.60
    {19992,4416,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.11  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {29988,3360,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.71  BV=1.32
    {29988,3616,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.82  BV=1.21
    {29988,3872,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.92  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4480,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.13  BV=0.90
    {29988,4800,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.23  BV=0.80
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.42  BV=0.61
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_Custom4AutoTable =
{
    AETABLE_CUSTOM4_AUTO, //eAETableID
    96, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    3, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom4PLineTable_60Hz,
    sCustom4PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom5PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.58  BV=3.30
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {16674,1856,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.87  BV=3.01
    {16674,2016,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.98  BV=2.90
    {16674,2144,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.07  BV=2.81
    {16674,2304,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.17  BV=2.71
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2656,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.38  BV=2.50
    {16674,2816,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.47  BV=2.41
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {16674,3744,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.87  BV=2.01
    {16674,4000,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.97  BV=1.91
    {16674,4288,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.07  BV=1.81
    {24990,3072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.58  BV=1.71
    {24990,3296,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.69  BV=1.61
    {24990,3520,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.78  BV=1.51
    {24990,3776,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.88  BV=1.41
    {24990,4032,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.98  BV=1.32
    {33348,3264,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.67  BV=1.20
    {33348,3488,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.77  BV=1.11
    {33348,3712,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.86  BV=1.02
    {33348,4032,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.98  BV=0.90
    {33348,4288,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.07  BV=0.81
    {33348,4608,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.17  BV=0.71
    {33348,4928,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.27  BV=0.61
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6048,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.56  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCustom5PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.01  BV=3.60
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3360,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.71  BV=2.90
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4096,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.00  BV=2.62
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4736,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.21  BV=2.41
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {19992,3104,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.60  BV=2.02
    {19992,3328,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.70  BV=1.91
    {19992,3584,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.81  BV=1.81
    {19992,3840,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.91  BV=1.71
    {19992,4128,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.01  BV=1.60
    {19992,4416,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.11  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {29988,3360,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.71  BV=1.32
    {29988,3616,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.82  BV=1.21
    {29988,3872,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.92  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4480,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.13  BV=0.90
    {29988,4800,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.23  BV=0.80
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.42  BV=0.61
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_Custom5AutoTable =
{
    AETABLE_CUSTOM5_AUTO, //eAETableID
    96, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    3, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom5PLineTable_60Hz,
    sCustom5PLineTable_50Hz,
    NULL,
};
static strEvPline sVideoNightPLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33348,1056,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.07  BV=2.81
    {33348,1152,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.17  BV=2.71
    {33348,1216,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.27  BV=2.61
    {33348,1312,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.37  BV=2.51
    {33348,1408,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.46  BV=2.42
    {33348,1504,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.58  BV=2.30
    {33348,1632,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.67  BV=2.20
    {33348,1728,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.77  BV=2.11
    {33348,1856,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.87  BV=2.01
    {33348,2016,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.98  BV=1.90
    {33348,2144,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.07  BV=1.81
    {33348,2304,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.17  BV=1.71
    {33348,2464,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.27  BV=1.61
    {33348,2656,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.38  BV=1.50
    {33348,2816,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.47  BV=1.41
    {33348,3040,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.57  BV=1.31
    {33348,3264,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.67  BV=1.20
    {33348,3488,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.77  BV=1.11
    {33348,3744,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.87  BV=1.01
    {33348,4000,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.97  BV=0.91
    {33348,4288,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.07  BV=0.81
    {33348,4576,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.16  BV=0.72
    {33348,4960,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.28  BV=0.60
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6080,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.57  BV=0.31
    {33348,6528,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.67  BV=0.20
    {33348,6976,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.77  BV=0.11
    {33348,7552,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.88  BV=-0.01
    {41664,6464,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=7.66  BV=-0.10
    {41664,6944,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=7.76  BV=-0.21
    {49980,6208,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.60  BV=-0.31
    {49980,6624,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.69  BV=-0.40
    {49980,7104,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.79  BV=-0.50
    {58338,6528,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=7.67  BV=-0.60
    {58338,7008,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=7.77  BV=-0.70
    {66654,6560,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=7.68  BV=-0.80
    {75012,6240,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.61  BV=-0.90
    {75012,6688,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.71  BV=-1.00
    {83328,6464,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.66  BV=-1.10
    {91644,6304,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.62  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {100002,7072,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7648,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.90  BV=-1.61
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sVideoNightPLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {29988,1376,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.43  BV=2.60
    {29988,1472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.52  BV=2.51
    {29988,1568,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.61  BV=2.42
    {29988,1696,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.73  BV=2.30
    {29988,1824,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.83  BV=2.20
    {29988,1920,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.92  BV=2.11
    {29988,2080,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.02  BV=2.01
    {29988,2240,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.13  BV=1.90
    {29988,2368,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.22  BV=1.81
    {29988,2560,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.32  BV=1.71
    {29988,2752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.43  BV=1.60
    {29988,2944,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.52  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {29988,3360,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.71  BV=1.32
    {29988,3616,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.82  BV=1.21
    {29988,3872,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.92  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4448,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.12  BV=0.91
    {29988,4768,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.22  BV=0.81
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5504,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.43  BV=0.60
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {29988,7264,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.83  BV=0.20
    {29988,7776,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.92  BV=0.11
    {39984,6304,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.62  BV=-0.01
    {39984,6752,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.72  BV=-0.11
    {39984,7232,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.82  BV=-0.20
    {49980,6208,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.60  BV=-0.31
    {49980,6624,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.69  BV=-0.40
    {49980,7104,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.79  BV=-0.50
    {60018,6336,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.63  BV=-0.60
    {60018,6816,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.73  BV=-0.71
    {70014,6240,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.61  BV=-0.80
    {70014,6688,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.71  BV=-0.90
    {80010,6272,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.61  BV=-1.00
    {80010,6720,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.71  BV=-1.10
    {90006,6400,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.64  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {100002,7072,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7648,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.90  BV=-1.61
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_VideoNightTable =
{
    AETABLE_VIDEO_NIGHT, //eAETableID
    116, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -17, //i4MinBV
    90, //i4EffectiveMaxBV
    -10, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideoNightPLineTable_60Hz,
    sVideoNightPLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO100PLineTable_60Hz =
{
{
    {252,1376,1032, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.44  BV=9.49
    {294,1248,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.29  BV=9.42
    {294,1344,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.39  BV=9.31
    {336,1248,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.30  BV=9.21
    {336,1344,1024, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.39  BV=9.12
    {378,1280,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.32  BV=9.02
    {420,1248,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.29  BV=8.90
    {420,1312,1040, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.38  BV=8.81
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {504,1280,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.32  BV=8.60
    {546,1248,1032, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.30  BV=8.51
    {588,1248,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.29  BV=8.42
    {630,1248,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=5.29  BV=8.32
    {672,1248,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.30  BV=8.21
    {714,1248,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.31  BV=8.11
    {756,1280,1024, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.32  BV=8.02
    {840,1248,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=5.29  BV=7.90
    {882,1248,1040, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.31  BV=7.81
    {966,1248,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=5.29  BV=7.70
    {1008,1280,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.32  BV=7.60
    {1092,1248,1032, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.30  BV=7.51
    {1176,1248,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.29  BV=7.42
    {1260,1248,1024, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=5.29  BV=7.32
    {1344,1248,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.30  BV=7.21
    {1470,1216,1040, 0, 0, 0},  //TV = 9.41(35 lines)  AV=2.97  SV=5.27  BV=7.11
    {1554,1248,1024, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=5.29  BV=7.02
    {1680,1248,1024, 0, 0, 0},  //TV = 9.22(40 lines)  AV=2.97  SV=5.29  BV=6.90
    {1806,1216,1040, 0, 0, 0},  //TV = 9.11(43 lines)  AV=2.97  SV=5.27  BV=6.81
    {1932,1248,1024, 0, 0, 0},  //TV = 9.02(46 lines)  AV=2.97  SV=5.29  BV=6.70
    {2058,1248,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=5.29  BV=6.61
    {2226,1216,1040, 0, 0, 0},  //TV = 8.81(53 lines)  AV=2.97  SV=5.27  BV=6.51
    {2394,1216,1040, 0, 0, 0},  //TV = 8.71(57 lines)  AV=2.97  SV=5.27  BV=6.41
    {2562,1216,1040, 0, 0, 0},  //TV = 8.61(61 lines)  AV=2.97  SV=5.27  BV=6.31
    {2730,1248,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=5.29  BV=6.20
    {2940,1216,1040, 0, 0, 0},  //TV = 8.41(70 lines)  AV=2.97  SV=5.27  BV=6.11
    {3150,1216,1040, 0, 0, 0},  //TV = 8.31(75 lines)  AV=2.97  SV=5.27  BV=6.01
    {3402,1216,1032, 0, 0, 0},  //TV = 8.20(81 lines)  AV=2.97  SV=5.26  BV=5.91
    {3612,1216,1040, 0, 0, 0},  //TV = 8.11(86 lines)  AV=2.97  SV=5.27  BV=5.81
    {3864,1248,1024, 0, 0, 0},  //TV = 8.02(92 lines)  AV=2.97  SV=5.29  BV=5.70
    {4158,1216,1040, 0, 0, 0},  //TV = 7.91(99 lines)  AV=2.97  SV=5.27  BV=5.61
    {4452,1216,1040, 0, 0, 0},  //TV = 7.81(106 lines)  AV=2.97  SV=5.27  BV=5.51
    {4788,1216,1040, 0, 0, 0},  //TV = 7.71(114 lines)  AV=2.97  SV=5.27  BV=5.41
    {5124,1216,1040, 0, 0, 0},  //TV = 7.61(122 lines)  AV=2.97  SV=5.27  BV=5.31
    {5502,1216,1040, 0, 0, 0},  //TV = 7.51(131 lines)  AV=2.97  SV=5.27  BV=5.21
    {5880,1216,1040, 0, 0, 0},  //TV = 7.41(140 lines)  AV=2.97  SV=5.27  BV=5.11
    {6300,1216,1040, 0, 0, 0},  //TV = 7.31(150 lines)  AV=2.97  SV=5.27  BV=5.01
    {6762,1216,1040, 0, 0, 0},  //TV = 7.21(161 lines)  AV=2.97  SV=5.27  BV=4.91
    {7266,1216,1032, 0, 0, 0},  //TV = 7.10(173 lines)  AV=2.97  SV=5.26  BV=4.82
    {7812,1216,1040, 0, 0, 0},  //TV = 7.00(186 lines)  AV=2.97  SV=5.27  BV=4.70
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1728,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.77  BV=4.11
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {8316,2144,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.07  BV=3.81
    {8316,2304,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.17  BV=3.71
    {16674,1248,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.29  BV=3.59
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.46  BV=3.42
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {16674,1632,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.67  BV=3.20
    {16674,1728,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.77  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1312,1040, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.38  BV=2.91
    {24990,1408,1040, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.48  BV=2.81
    {24990,1536,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.58  BV=2.71
    {33348,1216,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.27  BV=2.61
    {33348,1312,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.37  BV=2.51
    {33348,1408,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.46  BV=2.42
    {33348,1504,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.57  BV=2.31
    {41664,1280,1040, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.34  BV=2.21
    {41664,1408,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.46  BV=2.10
    {49980,1248,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.29  BV=2.01
    {49980,1312,1040, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.38  BV=1.91
    {49980,1408,1040, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.48  BV=1.81
    {58338,1312,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.36  BV=1.71
    {66654,1216,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.27  BV=1.61
    {66654,1312,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.37  BV=1.51
    {75012,1248,1032, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=5.30  BV=1.41
    {75012,1344,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=5.39  BV=1.32
    {83328,1280,1040, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=5.34  BV=1.21
    {91644,1280,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=5.32  BV=1.10
    {100002,1248,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=5.29  BV=1.01
    {100002,1312,1040, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=5.38  BV=0.91
    {116676,1216,1032, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=5.26  BV=0.81
    {124992,1216,1032, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=5.26  BV=0.71
    {133308,1216,1040, 0, 0, 0},  //TV = 2.91(3174 lines)  AV=2.97  SV=5.27  BV=0.61
    {141666,1248,1024, 0, 0, 0},  //TV = 2.82(3373 lines)  AV=2.97  SV=5.29  BV=0.50
    {149982,1248,1032, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=5.30  BV=0.41
    {158340,1280,1024, 0, 0, 0},  //TV = 2.66(3770 lines)  AV=2.97  SV=5.32  BV=0.31
    {174972,1216,1040, 0, 0, 0},  //TV = 2.51(4166 lines)  AV=2.97  SV=5.27  BV=0.22
    {183330,1248,1040, 0, 0, 0},  //TV = 2.45(4365 lines)  AV=2.97  SV=5.31  BV=0.11
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCaptureISO100PLineTable_50Hz =
{
{
    {252,1376,1032, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.44  BV=9.49
    {294,1248,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.29  BV=9.42
    {294,1344,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.39  BV=9.31
    {336,1248,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.30  BV=9.21
    {336,1344,1024, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.39  BV=9.12
    {378,1280,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.32  BV=9.02
    {420,1248,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.29  BV=8.90
    {420,1312,1040, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.38  BV=8.81
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {504,1280,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.32  BV=8.60
    {546,1248,1032, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.30  BV=8.51
    {588,1248,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.29  BV=8.42
    {630,1248,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=5.29  BV=8.32
    {672,1248,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.30  BV=8.21
    {714,1248,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.31  BV=8.11
    {756,1280,1024, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.32  BV=8.02
    {840,1248,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=5.29  BV=7.90
    {882,1248,1040, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.31  BV=7.81
    {966,1248,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=5.29  BV=7.70
    {1008,1280,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.32  BV=7.60
    {1092,1248,1032, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.30  BV=7.51
    {1176,1248,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.29  BV=7.42
    {1260,1248,1024, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=5.29  BV=7.32
    {1344,1248,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.30  BV=7.21
    {1470,1216,1040, 0, 0, 0},  //TV = 9.41(35 lines)  AV=2.97  SV=5.27  BV=7.11
    {1554,1248,1024, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=5.29  BV=7.02
    {1680,1248,1024, 0, 0, 0},  //TV = 9.22(40 lines)  AV=2.97  SV=5.29  BV=6.90
    {1806,1216,1040, 0, 0, 0},  //TV = 9.11(43 lines)  AV=2.97  SV=5.27  BV=6.81
    {1932,1248,1024, 0, 0, 0},  //TV = 9.02(46 lines)  AV=2.97  SV=5.29  BV=6.70
    {2058,1248,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=5.29  BV=6.61
    {2226,1216,1040, 0, 0, 0},  //TV = 8.81(53 lines)  AV=2.97  SV=5.27  BV=6.51
    {2394,1216,1040, 0, 0, 0},  //TV = 8.71(57 lines)  AV=2.97  SV=5.27  BV=6.41
    {2562,1216,1040, 0, 0, 0},  //TV = 8.61(61 lines)  AV=2.97  SV=5.27  BV=6.31
    {2730,1248,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=5.29  BV=6.20
    {2940,1216,1040, 0, 0, 0},  //TV = 8.41(70 lines)  AV=2.97  SV=5.27  BV=6.11
    {3150,1216,1040, 0, 0, 0},  //TV = 8.31(75 lines)  AV=2.97  SV=5.27  BV=6.01
    {3402,1216,1032, 0, 0, 0},  //TV = 8.20(81 lines)  AV=2.97  SV=5.26  BV=5.91
    {3612,1216,1040, 0, 0, 0},  //TV = 8.11(86 lines)  AV=2.97  SV=5.27  BV=5.81
    {3864,1248,1024, 0, 0, 0},  //TV = 8.02(92 lines)  AV=2.97  SV=5.29  BV=5.70
    {4158,1216,1040, 0, 0, 0},  //TV = 7.91(99 lines)  AV=2.97  SV=5.27  BV=5.61
    {4452,1216,1040, 0, 0, 0},  //TV = 7.81(106 lines)  AV=2.97  SV=5.27  BV=5.51
    {4788,1216,1040, 0, 0, 0},  //TV = 7.71(114 lines)  AV=2.97  SV=5.27  BV=5.41
    {5124,1216,1040, 0, 0, 0},  //TV = 7.61(122 lines)  AV=2.97  SV=5.27  BV=5.31
    {5502,1216,1040, 0, 0, 0},  //TV = 7.51(131 lines)  AV=2.97  SV=5.27  BV=5.21
    {5880,1216,1040, 0, 0, 0},  //TV = 7.41(140 lines)  AV=2.97  SV=5.27  BV=5.11
    {6300,1216,1040, 0, 0, 0},  //TV = 7.31(150 lines)  AV=2.97  SV=5.27  BV=5.01
    {6762,1216,1040, 0, 0, 0},  //TV = 7.21(161 lines)  AV=2.97  SV=5.27  BV=4.91
    {7266,1216,1032, 0, 0, 0},  //TV = 7.10(173 lines)  AV=2.97  SV=5.26  BV=4.82
    {7812,1216,1040, 0, 0, 0},  //TV = 7.00(186 lines)  AV=2.97  SV=5.27  BV=4.70
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8904,1216,1040, 0, 0, 0},  //TV = 6.81(212 lines)  AV=2.97  SV=5.27  BV=4.51
    {9534,1216,1040, 0, 0, 0},  //TV = 6.71(227 lines)  AV=2.97  SV=5.27  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.40  BV=4.21
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.01  BV=3.60
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {19992,1536,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.61  BV=3.01
    {19992,1664,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.70  BV=2.91
    {19992,1792,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.81  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {29988,1376,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.43  BV=2.60
    {29988,1472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.52  BV=2.51
    {29988,1568,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.61  BV=2.42
    {39984,1248,1040, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.31  BV=2.31
    {39984,1344,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.40  BV=2.21
    {39984,1440,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.50  BV=2.11
    {49980,1248,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.29  BV=2.01
    {49980,1312,1040, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.38  BV=1.91
    {49980,1408,1040, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.48  BV=1.81
    {60018,1280,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.32  BV=1.71
    {60018,1376,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.43  BV=1.60
    {70014,1248,1032, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=5.30  BV=1.51
    {70014,1344,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=5.39  BV=1.41
    {80010,1248,1040, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.31  BV=1.31
    {80010,1344,1040, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=5.41  BV=1.20
    {90006,1280,1032, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=5.33  BV=1.11
    {100002,1248,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=5.29  BV=1.01
    {100002,1312,1040, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=5.38  BV=0.91
    {109998,1280,1040, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=5.34  BV=0.81
    {119994,1280,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=5.32  BV=0.71
    {129990,1248,1040, 0, 0, 0},  //TV = 2.94(3095 lines)  AV=2.97  SV=5.31  BV=0.61
    {139986,1248,1032, 0, 0, 0},  //TV = 2.84(3333 lines)  AV=2.97  SV=5.30  BV=0.51
    {149982,1248,1032, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=5.30  BV=0.41
    {160020,1248,1040, 0, 0, 0},  //TV = 2.64(3810 lines)  AV=2.97  SV=5.31  BV=0.31
    {170016,1280,1024, 0, 0, 0},  //TV = 2.56(4048 lines)  AV=2.97  SV=5.32  BV=0.21
    {180012,1280,1032, 0, 0, 0},  //TV = 2.47(4286 lines)  AV=2.97  SV=5.33  BV=0.11
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_CaptureISO100Table =
{
    AETABLE_CAPTURE_ISO100, //eAETableID
    95, //u4TotalIndex
    20, //i4StrobeTrigerBV
    95, //i4MaxBV
    1, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_100, //ISO
    sCaptureISO100PLineTable_60Hz,
    sCaptureISO100PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO200PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {504,2560,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=6.32  BV=7.60
    {546,2528,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=6.30  BV=7.51
    {588,2496,1032, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=6.30  BV=7.41
    {630,2496,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=6.29  BV=7.32
    {672,2528,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=6.30  BV=7.21
    {714,2528,1024, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=6.30  BV=7.12
    {756,2560,1032, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=6.33  BV=7.01
    {840,2464,1032, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=6.28  BV=6.91
    {882,2528,1024, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=6.30  BV=6.81
    {966,2464,1032, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=6.28  BV=6.71
    {1008,2560,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=6.32  BV=6.60
    {1092,2528,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=6.30  BV=6.51
    {1176,2496,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=6.29  BV=6.42
    {1260,2496,1032, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=6.30  BV=6.31
    {1344,2528,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=6.30  BV=6.21
    {1470,2464,1024, 0, 0, 0},  //TV = 9.41(35 lines)  AV=2.97  SV=6.27  BV=6.11
    {1554,2496,1032, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=6.30  BV=6.00
    {1680,2464,1032, 0, 0, 0},  //TV = 9.22(40 lines)  AV=2.97  SV=6.28  BV=5.91
    {1806,2464,1024, 0, 0, 0},  //TV = 9.11(43 lines)  AV=2.97  SV=6.27  BV=5.82
    {1932,2496,1024, 0, 0, 0},  //TV = 9.02(46 lines)  AV=2.97  SV=6.29  BV=5.70
    {2058,2496,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=6.29  BV=5.61
    {2226,2464,1032, 0, 0, 0},  //TV = 8.81(53 lines)  AV=2.97  SV=6.28  BV=5.50
    {2394,2464,1024, 0, 0, 0},  //TV = 8.71(57 lines)  AV=2.97  SV=6.27  BV=5.41
    {2562,2464,1024, 0, 0, 0},  //TV = 8.61(61 lines)  AV=2.97  SV=6.27  BV=5.31
    {2730,2496,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=6.29  BV=5.20
    {2940,2464,1024, 0, 0, 0},  //TV = 8.41(70 lines)  AV=2.97  SV=6.27  BV=5.11
    {3150,2464,1024, 0, 0, 0},  //TV = 8.31(75 lines)  AV=2.97  SV=6.27  BV=5.01
    {3360,2464,1032, 0, 0, 0},  //TV = 8.22(80 lines)  AV=2.97  SV=6.28  BV=4.91
    {3612,2464,1024, 0, 0, 0},  //TV = 8.11(86 lines)  AV=2.97  SV=6.27  BV=4.82
    {3906,2464,1024, 0, 0, 0},  //TV = 8.00(93 lines)  AV=2.97  SV=6.27  BV=4.70
    {4158,2464,1024, 0, 0, 0},  //TV = 7.91(99 lines)  AV=2.97  SV=6.27  BV=4.61
    {4452,2464,1024, 0, 0, 0},  //TV = 7.81(106 lines)  AV=2.97  SV=6.27  BV=4.52
    {4788,2464,1024, 0, 0, 0},  //TV = 7.71(114 lines)  AV=2.97  SV=6.27  BV=4.41
    {5124,2464,1024, 0, 0, 0},  //TV = 7.61(122 lines)  AV=2.97  SV=6.27  BV=4.31
    {5502,2464,1024, 0, 0, 0},  //TV = 7.51(131 lines)  AV=2.97  SV=6.27  BV=4.21
    {5880,2464,1024, 0, 0, 0},  //TV = 7.41(140 lines)  AV=2.97  SV=6.27  BV=4.11
    {6300,2464,1024, 0, 0, 0},  //TV = 7.31(150 lines)  AV=2.97  SV=6.27  BV=4.01
    {6804,2464,1024, 0, 0, 0},  //TV = 7.20(162 lines)  AV=2.97  SV=6.27  BV=3.90
    {7266,2464,1024, 0, 0, 0},  //TV = 7.10(173 lines)  AV=2.97  SV=6.27  BV=3.81
    {7812,2464,1024, 0, 0, 0},  //TV = 7.00(186 lines)  AV=2.97  SV=6.27  BV=3.70
    {8316,2464,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.27  BV=3.61
    {8316,2656,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.38  BV=3.51
    {8316,2848,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.48  BV=3.41
    {8316,3040,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.57  BV=3.31
    {8316,3264,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.67  BV=3.21
    {8316,3488,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.77  BV=3.11
    {8316,3744,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.87  BV=3.01
    {8316,4000,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.97  BV=2.91
    {8316,4288,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.07  BV=2.81
    {8316,4640,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.18  BV=2.70
    {16674,2464,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.27  BV=2.61
    {16674,2656,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.38  BV=2.50
    {16674,2816,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.46  BV=2.42
    {16674,3040,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.57  BV=2.31
    {16674,3264,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.67  BV=2.20
    {16674,3488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=6.77  BV=2.11
    {24990,2496,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.29  BV=2.01
    {24990,2688,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.39  BV=1.90
    {24990,2880,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.49  BV=1.80
    {24990,3072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=6.58  BV=1.71
    {33348,2464,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.27  BV=1.61
    {33348,2656,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.38  BV=1.50
    {33348,2816,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.47  BV=1.41
    {33348,3040,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.57  BV=1.31
    {41664,2592,1032, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=6.35  BV=1.20
    {41664,2784,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=6.44  BV=1.11
    {49980,2496,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.29  BV=1.01
    {49980,2656,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.39  BV=0.91
    {49980,2848,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.49  BV=0.81
    {58338,2624,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=6.36  BV=0.71
    {66654,2464,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.27  BV=0.61
    {66654,2624,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.37  BV=0.51
    {75012,2528,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=6.30  BV=0.40
    {75012,2688,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=6.39  BV=0.32
    {83328,2592,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.34  BV=0.22
    {91644,2528,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=6.30  BV=0.11
    {100002,2496,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.29  BV=0.01
    {108318,2464,1032, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=6.28  BV=-0.10
    {116676,2464,1024, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=6.27  BV=-0.20
    {124992,2464,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=6.27  BV=-0.30
    {133308,2464,1032, 0, 0, 0},  //TV = 2.91(3174 lines)  AV=2.97  SV=6.28  BV=-0.40
    {141666,2496,1024, 0, 0, 0},  //TV = 2.82(3373 lines)  AV=2.97  SV=6.29  BV=-0.50
    {149982,2528,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=6.30  BV=-0.60
    {158340,2560,1032, 0, 0, 0},  //TV = 2.66(3770 lines)  AV=2.97  SV=6.33  BV=-0.70
    {174972,2496,1024, 0, 0, 0},  //TV = 2.51(4166 lines)  AV=2.97  SV=6.29  BV=-0.80
    {183330,2560,1024, 0, 0, 0},  //TV = 2.45(4365 lines)  AV=2.97  SV=6.32  BV=-0.90
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCaptureISO200PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {504,2560,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=6.32  BV=7.60
    {546,2528,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=6.30  BV=7.51
    {588,2496,1032, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=6.30  BV=7.41
    {630,2496,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=6.29  BV=7.32
    {672,2528,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=6.30  BV=7.21
    {714,2528,1024, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=6.30  BV=7.12
    {756,2560,1032, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=6.33  BV=7.01
    {840,2464,1032, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=6.28  BV=6.91
    {882,2528,1024, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=6.30  BV=6.81
    {966,2464,1032, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=6.28  BV=6.71
    {1008,2560,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=6.32  BV=6.60
    {1092,2528,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=6.30  BV=6.51
    {1176,2496,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=6.29  BV=6.42
    {1260,2496,1032, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=6.30  BV=6.31
    {1344,2528,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=6.30  BV=6.21
    {1470,2464,1024, 0, 0, 0},  //TV = 9.41(35 lines)  AV=2.97  SV=6.27  BV=6.11
    {1554,2496,1032, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=6.30  BV=6.00
    {1680,2464,1032, 0, 0, 0},  //TV = 9.22(40 lines)  AV=2.97  SV=6.28  BV=5.91
    {1806,2464,1024, 0, 0, 0},  //TV = 9.11(43 lines)  AV=2.97  SV=6.27  BV=5.82
    {1932,2496,1024, 0, 0, 0},  //TV = 9.02(46 lines)  AV=2.97  SV=6.29  BV=5.70
    {2058,2496,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=6.29  BV=5.61
    {2226,2464,1032, 0, 0, 0},  //TV = 8.81(53 lines)  AV=2.97  SV=6.28  BV=5.50
    {2394,2464,1024, 0, 0, 0},  //TV = 8.71(57 lines)  AV=2.97  SV=6.27  BV=5.41
    {2562,2464,1024, 0, 0, 0},  //TV = 8.61(61 lines)  AV=2.97  SV=6.27  BV=5.31
    {2730,2496,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=6.29  BV=5.20
    {2940,2464,1024, 0, 0, 0},  //TV = 8.41(70 lines)  AV=2.97  SV=6.27  BV=5.11
    {3150,2464,1024, 0, 0, 0},  //TV = 8.31(75 lines)  AV=2.97  SV=6.27  BV=5.01
    {3360,2464,1032, 0, 0, 0},  //TV = 8.22(80 lines)  AV=2.97  SV=6.28  BV=4.91
    {3612,2464,1024, 0, 0, 0},  //TV = 8.11(86 lines)  AV=2.97  SV=6.27  BV=4.82
    {3906,2464,1024, 0, 0, 0},  //TV = 8.00(93 lines)  AV=2.97  SV=6.27  BV=4.70
    {4158,2464,1024, 0, 0, 0},  //TV = 7.91(99 lines)  AV=2.97  SV=6.27  BV=4.61
    {4452,2464,1024, 0, 0, 0},  //TV = 7.81(106 lines)  AV=2.97  SV=6.27  BV=4.52
    {4788,2464,1024, 0, 0, 0},  //TV = 7.71(114 lines)  AV=2.97  SV=6.27  BV=4.41
    {5124,2464,1024, 0, 0, 0},  //TV = 7.61(122 lines)  AV=2.97  SV=6.27  BV=4.31
    {5502,2464,1024, 0, 0, 0},  //TV = 7.51(131 lines)  AV=2.97  SV=6.27  BV=4.21
    {5880,2464,1024, 0, 0, 0},  //TV = 7.41(140 lines)  AV=2.97  SV=6.27  BV=4.11
    {6300,2464,1024, 0, 0, 0},  //TV = 7.31(150 lines)  AV=2.97  SV=6.27  BV=4.01
    {6804,2464,1024, 0, 0, 0},  //TV = 7.20(162 lines)  AV=2.97  SV=6.27  BV=3.90
    {7266,2464,1024, 0, 0, 0},  //TV = 7.10(173 lines)  AV=2.97  SV=6.27  BV=3.81
    {7812,2464,1024, 0, 0, 0},  //TV = 7.00(186 lines)  AV=2.97  SV=6.27  BV=3.70
    {8358,2464,1024, 0, 0, 0},  //TV = 6.90(199 lines)  AV=2.97  SV=6.27  BV=3.61
    {8946,2464,1024, 0, 0, 0},  //TV = 6.80(213 lines)  AV=2.97  SV=6.27  BV=3.51
    {9576,2464,1024, 0, 0, 0},  //TV = 6.71(228 lines)  AV=2.97  SV=6.27  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3328,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.70  BV=2.91
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4096,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.00  BV=2.62
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4736,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.21  BV=2.41
    {19992,2528,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.30  BV=2.31
    {19992,2720,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.41  BV=2.21
    {19992,2912,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.51  BV=2.11
    {19992,3104,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.60  BV=2.02
    {19992,3328,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.70  BV=1.91
    {19992,3584,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=6.81  BV=1.81
    {29988,2560,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.32  BV=1.71
    {29988,2752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.43  BV=1.60
    {29988,2944,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.52  BV=1.51
    {29988,3136,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.61  BV=1.42
    {39984,2528,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=6.30  BV=1.31
    {39984,2720,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=6.41  BV=1.21
    {39984,2912,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=6.51  BV=1.11
    {49980,2496,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.29  BV=1.01
    {49980,2656,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.39  BV=0.91
    {49980,2848,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.49  BV=0.81
    {60018,2560,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.32  BV=0.71
    {60018,2720,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.42  BV=0.61
    {70014,2528,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.30  BV=0.50
    {70014,2688,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.39  BV=0.41
    {80010,2528,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.30  BV=0.31
    {80010,2720,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.41  BV=0.21
    {90006,2592,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=6.34  BV=0.10
    {100002,2496,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.29  BV=0.01
    {100002,2688,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=6.39  BV=-0.10
    {109998,2624,1024, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=6.36  BV=-0.20
    {119994,2560,1032, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=6.33  BV=-0.30
    {129990,2528,1032, 0, 0, 0},  //TV = 2.94(3095 lines)  AV=2.97  SV=6.32  BV=-0.40
    {139986,2528,1024, 0, 0, 0},  //TV = 2.84(3333 lines)  AV=2.97  SV=6.30  BV=-0.50
    {149982,2528,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=6.30  BV=-0.60
    {160020,2528,1032, 0, 0, 0},  //TV = 2.64(3810 lines)  AV=2.97  SV=6.32  BV=-0.70
    {170016,2560,1024, 0, 0, 0},  //TV = 2.56(4048 lines)  AV=2.97  SV=6.32  BV=-0.79
    {190008,2464,1024, 0, 0, 0},  //TV = 2.40(4524 lines)  AV=2.97  SV=6.27  BV=-0.90
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_CaptureISO200Table =
{
    AETABLE_CAPTURE_ISO200, //eAETableID
    108, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -9, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_200, //ISO
    sCaptureISO200PLineTable_60Hz,
    sCaptureISO200PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO400PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {462,2784,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.44  BV=7.61
    {462,2976,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.54  BV=7.51
    {462,3200,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.64  BV=7.41
    {462,3424,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.74  BV=7.31
    {462,3680,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.85  BV=7.21
    {462,3936,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.94  BV=7.11
    {462,4224,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.04  BV=7.01
    {462,4512,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.14  BV=6.91
    {462,4832,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.24  BV=6.81
    {462,5216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.35  BV=6.70
    {504,5088,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=7.31  BV=6.61
    {546,5024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=7.29  BV=6.52
    {588,5024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=7.29  BV=6.41
    {630,5024,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=7.29  BV=6.31
    {672,5024,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=7.29  BV=6.22
    {714,5088,1024, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=7.31  BV=6.11
    {756,5152,1024, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=7.33  BV=6.01
    {840,4992,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=7.29  BV=5.90
    {882,5056,1024, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=7.30  BV=5.81
    {966,4960,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=7.28  BV=5.71
    {1008,5088,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=7.31  BV=5.61
    {1092,5056,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=7.30  BV=5.51
    {1176,5024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=7.29  BV=5.41
    {1260,5024,1024, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=7.29  BV=5.31
    {1344,5056,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=7.30  BV=5.21
    {1470,4928,1024, 0, 0, 0},  //TV = 9.41(35 lines)  AV=2.97  SV=7.27  BV=5.11
    {1554,5024,1024, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=7.29  BV=5.01
    {1680,4960,1024, 0, 0, 0},  //TV = 9.22(40 lines)  AV=2.97  SV=7.28  BV=4.91
    {1806,4960,1024, 0, 0, 0},  //TV = 9.11(43 lines)  AV=2.97  SV=7.28  BV=4.81
    {1932,4960,1024, 0, 0, 0},  //TV = 9.02(46 lines)  AV=2.97  SV=7.28  BV=4.71
    {2058,4992,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=7.29  BV=4.61
    {2226,4960,1024, 0, 0, 0},  //TV = 8.81(53 lines)  AV=2.97  SV=7.28  BV=4.51
    {2394,4928,1024, 0, 0, 0},  //TV = 8.71(57 lines)  AV=2.97  SV=7.27  BV=4.41
    {2562,4960,1024, 0, 0, 0},  //TV = 8.61(61 lines)  AV=2.97  SV=7.28  BV=4.30
    {2730,4992,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=7.29  BV=4.20
    {2940,4960,1024, 0, 0, 0},  //TV = 8.41(70 lines)  AV=2.97  SV=7.28  BV=4.10
    {3150,4928,1024, 0, 0, 0},  //TV = 8.31(75 lines)  AV=2.97  SV=7.27  BV=4.01
    {3360,4960,1024, 0, 0, 0},  //TV = 8.22(80 lines)  AV=2.97  SV=7.28  BV=3.91
    {3654,4928,1024, 0, 0, 0},  //TV = 8.10(87 lines)  AV=2.97  SV=7.27  BV=3.80
    {3906,4928,1024, 0, 0, 0},  //TV = 8.00(93 lines)  AV=2.97  SV=7.27  BV=3.70
    {4158,4960,1024, 0, 0, 0},  //TV = 7.91(99 lines)  AV=2.97  SV=7.28  BV=3.60
    {4452,4960,1024, 0, 0, 0},  //TV = 7.81(106 lines)  AV=2.97  SV=7.28  BV=3.51
    {4788,4928,1024, 0, 0, 0},  //TV = 7.71(114 lines)  AV=2.97  SV=7.27  BV=3.41
    {5166,4928,1024, 0, 0, 0},  //TV = 7.60(123 lines)  AV=2.97  SV=7.27  BV=3.30
    {5502,4928,1024, 0, 0, 0},  //TV = 7.51(131 lines)  AV=2.97  SV=7.27  BV=3.21
    {5922,4928,1024, 0, 0, 0},  //TV = 7.40(141 lines)  AV=2.97  SV=7.27  BV=3.10
    {6342,4928,1024, 0, 0, 0},  //TV = 7.30(151 lines)  AV=2.97  SV=7.27  BV=3.00
    {6804,4928,1024, 0, 0, 0},  //TV = 7.20(162 lines)  AV=2.97  SV=7.27  BV=2.90
    {7266,4928,1024, 0, 0, 0},  //TV = 7.10(173 lines)  AV=2.97  SV=7.27  BV=2.81
    {7812,4896,1024, 0, 0, 0},  //TV = 7.00(186 lines)  AV=2.97  SV=7.26  BV=2.71
    {8316,4928,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.27  BV=2.61
    {8316,5280,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.37  BV=2.51
    {8316,5664,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.47  BV=2.41
    {8316,6080,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.57  BV=2.31
    {8316,6560,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.68  BV=2.20
    {8316,7008,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.77  BV=2.11
    {8316,7520,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.88  BV=2.00
    {8316,8064,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.98  BV=1.90
    {8316,8192,1080, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.08  BV=1.80
    {8316,8192,1152, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.17  BV=1.71
    {16674,4928,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.27  BV=1.61
    {16674,5312,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.38  BV=1.50
    {16674,5664,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.47  BV=1.41
    {16674,6080,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.57  BV=1.31
    {16674,6528,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.67  BV=1.20
    {16674,6976,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.77  BV=1.11
    {24990,4992,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.29  BV=1.01
    {24990,5344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.38  BV=0.91
    {24990,5728,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.48  BV=0.81
    {24990,6144,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.58  BV=0.71
    {33348,4928,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.27  BV=0.61
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6080,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.57  BV=0.31
    {41664,5216,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=7.35  BV=0.21
    {41664,5568,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=7.44  BV=0.11
    {49980,5024,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.29  BV=-0.00
    {49980,5376,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.39  BV=-0.10
    {58338,4928,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=7.27  BV=-0.20
    {58338,5280,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=7.37  BV=-0.30
    {66654,4960,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=7.28  BV=-0.40
    {66654,5312,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=7.38  BV=-0.50
    {75012,5056,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.30  BV=-0.60
    {75012,5440,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.41  BV=-0.70
    {83328,5248,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.36  BV=-0.80
    {91644,5088,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.31  BV=-0.89
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {108318,4960,1024, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=7.28  BV=-1.10
    {116676,4928,1024, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=7.27  BV=-1.20
    {124992,4928,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.27  BV=-1.30
    {133308,4960,1024, 0, 0, 0},  //TV = 2.91(3174 lines)  AV=2.97  SV=7.28  BV=-1.40
    {141666,4992,1024, 0, 0, 0},  //TV = 2.82(3373 lines)  AV=2.97  SV=7.29  BV=-1.50
    {149982,5056,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=7.30  BV=-1.60
    {158340,5152,1024, 0, 0, 0},  //TV = 2.66(3770 lines)  AV=2.97  SV=7.33  BV=-1.70
    {174972,4992,1024, 0, 0, 0},  //TV = 2.51(4166 lines)  AV=2.97  SV=7.29  BV=-1.80
    {183330,5088,1024, 0, 0, 0},  //TV = 2.45(4365 lines)  AV=2.97  SV=7.31  BV=-1.89
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCaptureISO400PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {462,2784,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.44  BV=7.61
    {462,2976,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.54  BV=7.51
    {462,3200,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.64  BV=7.41
    {462,3424,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.74  BV=7.31
    {462,3680,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.85  BV=7.21
    {462,3936,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.94  BV=7.11
    {462,4224,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.04  BV=7.01
    {462,4512,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.14  BV=6.91
    {462,4832,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.24  BV=6.81
    {462,5216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.35  BV=6.70
    {504,5088,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=7.31  BV=6.61
    {546,5024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=7.29  BV=6.52
    {588,5024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=7.29  BV=6.41
    {630,5024,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=7.29  BV=6.31
    {672,5024,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=7.29  BV=6.22
    {714,5088,1024, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=7.31  BV=6.11
    {756,5152,1024, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=7.33  BV=6.01
    {840,4992,1024, 0, 0, 0},  //TV = 10.22(20 lines)  AV=2.97  SV=7.29  BV=5.90
    {882,5056,1024, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=7.30  BV=5.81
    {966,4960,1024, 0, 0, 0},  //TV = 10.02(23 lines)  AV=2.97  SV=7.28  BV=5.71
    {1008,5088,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=7.31  BV=5.61
    {1092,5056,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=7.30  BV=5.51
    {1176,5024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=7.29  BV=5.41
    {1260,5024,1024, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=7.29  BV=5.31
    {1344,5056,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=7.30  BV=5.21
    {1470,4928,1024, 0, 0, 0},  //TV = 9.41(35 lines)  AV=2.97  SV=7.27  BV=5.11
    {1554,5024,1024, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=7.29  BV=5.01
    {1680,4960,1024, 0, 0, 0},  //TV = 9.22(40 lines)  AV=2.97  SV=7.28  BV=4.91
    {1806,4960,1024, 0, 0, 0},  //TV = 9.11(43 lines)  AV=2.97  SV=7.28  BV=4.81
    {1932,4960,1024, 0, 0, 0},  //TV = 9.02(46 lines)  AV=2.97  SV=7.28  BV=4.71
    {2058,4992,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=7.29  BV=4.61
    {2226,4960,1024, 0, 0, 0},  //TV = 8.81(53 lines)  AV=2.97  SV=7.28  BV=4.51
    {2394,4928,1024, 0, 0, 0},  //TV = 8.71(57 lines)  AV=2.97  SV=7.27  BV=4.41
    {2562,4960,1024, 0, 0, 0},  //TV = 8.61(61 lines)  AV=2.97  SV=7.28  BV=4.30
    {2730,4992,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=7.29  BV=4.20
    {2940,4960,1024, 0, 0, 0},  //TV = 8.41(70 lines)  AV=2.97  SV=7.28  BV=4.10
    {3150,4928,1024, 0, 0, 0},  //TV = 8.31(75 lines)  AV=2.97  SV=7.27  BV=4.01
    {3360,4960,1024, 0, 0, 0},  //TV = 8.22(80 lines)  AV=2.97  SV=7.28  BV=3.91
    {3654,4928,1024, 0, 0, 0},  //TV = 8.10(87 lines)  AV=2.97  SV=7.27  BV=3.80
    {3906,4928,1024, 0, 0, 0},  //TV = 8.00(93 lines)  AV=2.97  SV=7.27  BV=3.70
    {4158,4960,1024, 0, 0, 0},  //TV = 7.91(99 lines)  AV=2.97  SV=7.28  BV=3.60
    {4452,4960,1024, 0, 0, 0},  //TV = 7.81(106 lines)  AV=2.97  SV=7.28  BV=3.51
    {4788,4928,1024, 0, 0, 0},  //TV = 7.71(114 lines)  AV=2.97  SV=7.27  BV=3.41
    {5166,4928,1024, 0, 0, 0},  //TV = 7.60(123 lines)  AV=2.97  SV=7.27  BV=3.30
    {5502,4928,1024, 0, 0, 0},  //TV = 7.51(131 lines)  AV=2.97  SV=7.27  BV=3.21
    {5922,4928,1024, 0, 0, 0},  //TV = 7.40(141 lines)  AV=2.97  SV=7.27  BV=3.10
    {6342,4928,1024, 0, 0, 0},  //TV = 7.30(151 lines)  AV=2.97  SV=7.27  BV=3.00
    {6804,4928,1024, 0, 0, 0},  //TV = 7.20(162 lines)  AV=2.97  SV=7.27  BV=2.90
    {7266,4928,1024, 0, 0, 0},  //TV = 7.10(173 lines)  AV=2.97  SV=7.27  BV=2.81
    {7812,4896,1024, 0, 0, 0},  //TV = 7.00(186 lines)  AV=2.97  SV=7.26  BV=2.71
    {8358,4928,1024, 0, 0, 0},  //TV = 6.90(199 lines)  AV=2.97  SV=7.27  BV=2.61
    {8946,4928,1024, 0, 0, 0},  //TV = 6.80(213 lines)  AV=2.97  SV=7.27  BV=2.51
    {9576,4928,1024, 0, 0, 0},  //TV = 6.71(228 lines)  AV=2.97  SV=7.27  BV=2.41
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5440,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.41  BV=2.21
    {9996,5792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.50  BV=2.12
    {9996,6272,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.61  BV=2.00
    {9996,6720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.71  BV=1.90
    {9996,7200,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.81  BV=1.80
    {9996,7712,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.91  BV=1.70
    {9996,8192,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.01  BV=1.60
    {9996,8192,1104, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.11  BV=1.51
    {9996,8192,1184, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.21  BV=1.41
    {19992,5056,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.30  BV=1.31
    {19992,5440,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.41  BV=1.21
    {19992,5824,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.51  BV=1.11
    {19992,6240,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.61  BV=1.01
    {19992,6688,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.71  BV=0.91
    {19992,7168,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.81  BV=0.81
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.42  BV=0.61
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {39984,5056,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.30  BV=0.31
    {39984,5440,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.41  BV=0.21
    {39984,5824,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.51  BV=0.11
    {49980,5024,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.29  BV=-0.00
    {49980,5376,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.39  BV=-0.10
    {49980,5760,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.49  BV=-0.20
    {60018,5152,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.33  BV=-0.30
    {60018,5504,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.43  BV=-0.40
    {70014,5056,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.30  BV=-0.50
    {70014,5440,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.41  BV=-0.60
    {80010,5088,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.31  BV=-0.70
    {80010,5440,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.41  BV=-0.79
    {90006,5184,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.34  BV=-0.90
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {109998,5248,1024, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=7.36  BV=-1.20
    {119994,5152,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.33  BV=-1.30
    {129990,5088,1024, 0, 0, 0},  //TV = 2.94(3095 lines)  AV=2.97  SV=7.31  BV=-1.40
    {139986,5056,1024, 0, 0, 0},  //TV = 2.84(3333 lines)  AV=2.97  SV=7.30  BV=-1.50
    {149982,5056,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=7.30  BV=-1.60
    {160020,5088,1024, 0, 0, 0},  //TV = 2.64(3810 lines)  AV=2.97  SV=7.31  BV=-1.70
    {170016,5120,1024, 0, 0, 0},  //TV = 2.56(4048 lines)  AV=2.97  SV=7.32  BV=-1.79
    {190008,4928,1024, 0, 0, 0},  //TV = 2.40(4524 lines)  AV=2.97  SV=7.27  BV=-1.90
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_CaptureISO400Table =
{
    AETABLE_CAPTURE_ISO400, //eAETableID
    118, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -19, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_400, //ISO
    sCaptureISO400PLineTable_60Hz,
    sCaptureISO400PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO800PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {462,2784,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.44  BV=7.61
    {462,2976,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.54  BV=7.51
    {462,3200,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.64  BV=7.41
    {462,3424,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.74  BV=7.31
    {462,3680,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.85  BV=7.21
    {462,3936,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.94  BV=7.11
    {462,4224,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.04  BV=7.01
    {462,4512,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.14  BV=6.91
    {462,4832,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.24  BV=6.81
    {462,5216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.35  BV=6.70
    {462,5568,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.44  BV=6.61
    {462,5984,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.55  BV=6.50
    {462,6400,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.64  BV=6.41
    {504,6272,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=7.61  BV=6.31
    {546,6208,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=7.60  BV=6.21
    {588,6208,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=7.60  BV=6.10
    {630,6176,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=7.59  BV=6.01
    {672,6208,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=7.60  BV=5.91
    {714,6272,1024, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=7.61  BV=5.81
    {756,6336,1024, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=7.63  BV=5.71
    {798,6432,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=7.65  BV=5.61
    {882,6240,1024, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=7.61  BV=5.51
    {924,6400,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=7.64  BV=5.41
    {1008,6272,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=7.61  BV=5.31
    {1092,6240,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=7.61  BV=5.20
    {1176,6176,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=7.59  BV=5.11
    {1260,6176,1024, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=7.59  BV=5.01
    {1344,6240,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=7.61  BV=4.90
    {1428,6272,1024, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=7.61  BV=4.81
    {1554,6176,1024, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=7.59  BV=4.71
    {1638,6272,1024, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=7.61  BV=4.61
    {1764,6272,1024, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=7.61  BV=4.50
    {1890,6240,1024, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=7.61  BV=4.41
    {2058,6144,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=7.58  BV=4.31
    {2184,6240,1024, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=7.61  BV=4.20
    {2352,6176,1024, 0, 0, 0},  //TV = 8.73(56 lines)  AV=2.97  SV=7.59  BV=4.11
    {2520,6176,1024, 0, 0, 0},  //TV = 8.63(60 lines)  AV=2.97  SV=7.59  BV=4.01
    {2730,6144,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=7.58  BV=3.90
    {2898,6176,1024, 0, 0, 0},  //TV = 8.43(69 lines)  AV=2.97  SV=7.59  BV=3.81
    {3108,6176,1024, 0, 0, 0},  //TV = 8.33(74 lines)  AV=2.97  SV=7.59  BV=3.71
    {3318,6176,1024, 0, 0, 0},  //TV = 8.24(79 lines)  AV=2.97  SV=7.59  BV=3.61
    {3570,6208,1024, 0, 0, 0},  //TV = 8.13(85 lines)  AV=2.97  SV=7.60  BV=3.50
    {3822,6208,1024, 0, 0, 0},  //TV = 8.03(91 lines)  AV=2.97  SV=7.60  BV=3.40
    {4116,6144,1024, 0, 0, 0},  //TV = 7.92(98 lines)  AV=2.97  SV=7.58  BV=3.31
    {4410,6144,1024, 0, 0, 0},  //TV = 7.83(105 lines)  AV=2.97  SV=7.58  BV=3.21
    {4704,6176,1024, 0, 0, 0},  //TV = 7.73(112 lines)  AV=2.97  SV=7.59  BV=3.11
    {5040,6176,1024, 0, 0, 0},  //TV = 7.63(120 lines)  AV=2.97  SV=7.59  BV=3.01
    {5460,6144,1024, 0, 0, 0},  //TV = 7.52(130 lines)  AV=2.97  SV=7.58  BV=2.90
    {5838,6144,1024, 0, 0, 0},  //TV = 7.42(139 lines)  AV=2.97  SV=7.58  BV=2.81
    {6258,6144,1024, 0, 0, 0},  //TV = 7.32(149 lines)  AV=2.97  SV=7.58  BV=2.71
    {6678,6176,1024, 0, 0, 0},  //TV = 7.23(159 lines)  AV=2.97  SV=7.59  BV=2.60
    {7182,6144,1024, 0, 0, 0},  //TV = 7.12(171 lines)  AV=2.97  SV=7.58  BV=2.51
    {7686,6144,1024, 0, 0, 0},  //TV = 7.02(183 lines)  AV=2.97  SV=7.58  BV=2.41
    {8232,6144,1024, 0, 0, 0},  //TV = 6.92(196 lines)  AV=2.97  SV=7.58  BV=2.31
    {8316,6528,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.67  BV=2.21
    {8316,6976,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.77  BV=2.11
    {8316,7488,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.87  BV=2.01
    {8316,8032,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.97  BV=1.91
    {8316,8192,1072, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.07  BV=1.81
    {8316,8192,1152, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.17  BV=1.71
    {8316,8192,1240, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.28  BV=1.60
    {8316,8192,1328, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.38  BV=1.51
    {8316,8192,1424, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.48  BV=1.41
    {8316,8192,1528, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.58  BV=1.30
    {16674,6528,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.67  BV=1.20
    {16674,7008,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.77  BV=1.10
    {16674,7488,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.87  BV=1.01
    {16674,8032,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.97  BV=0.91
    {16674,8192,1072, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=8.07  BV=0.81
    {24990,6144,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.58  BV=0.71
    {24990,6592,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.69  BV=0.61
    {24990,7072,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.79  BV=0.51
    {24990,7584,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.89  BV=0.40
    {24990,8096,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.98  BV=0.31
    {33348,6496,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.67  BV=0.21
    {33348,6976,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.77  BV=0.11
    {33348,7520,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.88  BV=0.00
    {41664,6464,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=7.66  BV=-0.10
    {41664,6912,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=7.75  BV=-0.20
    {49980,6176,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.59  BV=-0.30
    {49980,6624,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.69  BV=-0.40
    {49980,7104,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.79  BV=-0.50
    {58338,6528,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=7.67  BV=-0.60
    {58338,6976,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=7.77  BV=-0.70
    {66654,6560,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=7.68  BV=-0.80
    {75012,6240,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.61  BV=-0.90
    {75012,6688,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.71  BV=-1.00
    {83328,6464,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.66  BV=-1.10
    {91644,6272,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.61  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {108318,6560,1024, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=7.68  BV=-1.50
    {116676,6528,1024, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=7.67  BV=-1.60
    {124992,6528,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.67  BV=-1.70
    {141666,6176,1024, 0, 0, 0},  //TV = 2.82(3373 lines)  AV=2.97  SV=7.59  BV=-1.80
    {149982,6240,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=7.61  BV=-1.90
    {158340,6336,1024, 0, 0, 0},  //TV = 2.66(3770 lines)  AV=2.97  SV=7.63  BV=-2.00
    {174972,6144,1024, 0, 0, 0},  //TV = 2.51(4166 lines)  AV=2.97  SV=7.58  BV=-2.10
    {183330,6272,1024, 0, 0, 0},  //TV = 2.45(4365 lines)  AV=2.97  SV=7.61  BV=-2.20
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCaptureISO800PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {462,2784,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.44  BV=7.61
    {462,2976,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.54  BV=7.51
    {462,3200,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.64  BV=7.41
    {462,3424,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.74  BV=7.31
    {462,3680,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.85  BV=7.21
    {462,3936,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.94  BV=7.11
    {462,4224,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.04  BV=7.01
    {462,4512,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.14  BV=6.91
    {462,4832,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.24  BV=6.81
    {462,5216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.35  BV=6.70
    {462,5568,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.44  BV=6.61
    {462,5984,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.55  BV=6.50
    {462,6400,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.64  BV=6.41
    {504,6272,1024, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=7.61  BV=6.31
    {546,6208,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=7.60  BV=6.21
    {588,6208,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=7.60  BV=6.10
    {630,6176,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=7.59  BV=6.01
    {672,6208,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=7.60  BV=5.91
    {714,6272,1024, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=7.61  BV=5.81
    {756,6336,1024, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=7.63  BV=5.71
    {798,6432,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=7.65  BV=5.61
    {882,6240,1024, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=7.61  BV=5.51
    {924,6400,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=7.64  BV=5.41
    {1008,6272,1024, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=7.61  BV=5.31
    {1092,6240,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=7.61  BV=5.20
    {1176,6176,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=7.59  BV=5.11
    {1260,6176,1024, 0, 0, 0},  //TV = 9.63(30 lines)  AV=2.97  SV=7.59  BV=5.01
    {1344,6240,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=7.61  BV=4.90
    {1428,6272,1024, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=7.61  BV=4.81
    {1554,6176,1024, 0, 0, 0},  //TV = 9.33(37 lines)  AV=2.97  SV=7.59  BV=4.71
    {1638,6272,1024, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=7.61  BV=4.61
    {1764,6272,1024, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=7.61  BV=4.50
    {1890,6240,1024, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=7.61  BV=4.41
    {2058,6144,1024, 0, 0, 0},  //TV = 8.92(49 lines)  AV=2.97  SV=7.58  BV=4.31
    {2184,6240,1024, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=7.61  BV=4.20
    {2352,6176,1024, 0, 0, 0},  //TV = 8.73(56 lines)  AV=2.97  SV=7.59  BV=4.11
    {2520,6176,1024, 0, 0, 0},  //TV = 8.63(60 lines)  AV=2.97  SV=7.59  BV=4.01
    {2730,6144,1024, 0, 0, 0},  //TV = 8.52(65 lines)  AV=2.97  SV=7.58  BV=3.90
    {2898,6176,1024, 0, 0, 0},  //TV = 8.43(69 lines)  AV=2.97  SV=7.59  BV=3.81
    {3108,6176,1024, 0, 0, 0},  //TV = 8.33(74 lines)  AV=2.97  SV=7.59  BV=3.71
    {3318,6176,1024, 0, 0, 0},  //TV = 8.24(79 lines)  AV=2.97  SV=7.59  BV=3.61
    {3570,6208,1024, 0, 0, 0},  //TV = 8.13(85 lines)  AV=2.97  SV=7.60  BV=3.50
    {3822,6208,1024, 0, 0, 0},  //TV = 8.03(91 lines)  AV=2.97  SV=7.60  BV=3.40
    {4116,6144,1024, 0, 0, 0},  //TV = 7.92(98 lines)  AV=2.97  SV=7.58  BV=3.31
    {4410,6144,1024, 0, 0, 0},  //TV = 7.83(105 lines)  AV=2.97  SV=7.58  BV=3.21
    {4704,6176,1024, 0, 0, 0},  //TV = 7.73(112 lines)  AV=2.97  SV=7.59  BV=3.11
    {5040,6176,1024, 0, 0, 0},  //TV = 7.63(120 lines)  AV=2.97  SV=7.59  BV=3.01
    {5460,6144,1024, 0, 0, 0},  //TV = 7.52(130 lines)  AV=2.97  SV=7.58  BV=2.90
    {5838,6144,1024, 0, 0, 0},  //TV = 7.42(139 lines)  AV=2.97  SV=7.58  BV=2.81
    {6258,6144,1024, 0, 0, 0},  //TV = 7.32(149 lines)  AV=2.97  SV=7.58  BV=2.71
    {6678,6176,1024, 0, 0, 0},  //TV = 7.23(159 lines)  AV=2.97  SV=7.59  BV=2.60
    {7182,6144,1024, 0, 0, 0},  //TV = 7.12(171 lines)  AV=2.97  SV=7.58  BV=2.51
    {7686,6144,1024, 0, 0, 0},  //TV = 7.02(183 lines)  AV=2.97  SV=7.58  BV=2.41
    {8232,6144,1024, 0, 0, 0},  //TV = 6.92(196 lines)  AV=2.97  SV=7.58  BV=2.31
    {8820,6144,1024, 0, 0, 0},  //TV = 6.83(210 lines)  AV=2.97  SV=7.58  BV=2.21
    {9450,6144,1024, 0, 0, 0},  //TV = 6.73(225 lines)  AV=2.97  SV=7.58  BV=2.11
    {9996,6240,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.61  BV=2.01
    {9996,6656,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.70  BV=1.91
    {9996,7136,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.80  BV=1.81
    {9996,7648,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.90  BV=1.71
    {9996,8192,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.01  BV=1.60
    {9996,8192,1104, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.11  BV=1.51
    {9996,8192,1184, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.21  BV=1.41
    {9996,8192,1272, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.31  BV=1.30
    {9996,8192,1360, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.41  BV=1.21
    {9996,8192,1456, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.51  BV=1.11
    {19992,6240,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.61  BV=1.01
    {19992,6688,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.71  BV=0.91
    {19992,7168,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.81  BV=0.81
    {19992,7680,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.91  BV=0.71
    {19992,8192,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.00  BV=0.62
    {19992,8192,1104, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.11  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {29988,7232,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.82  BV=0.21
    {29988,7776,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.92  BV=0.11
    {39984,6272,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.61  BV=0.00
    {39984,6720,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.71  BV=-0.10
    {39984,7200,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=7.81  BV=-0.20
    {49980,6176,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.59  BV=-0.30
    {49980,6624,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.69  BV=-0.40
    {49980,7104,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=7.79  BV=-0.50
    {60018,6336,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.63  BV=-0.60
    {60018,6784,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.73  BV=-0.70
    {70014,6240,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.61  BV=-0.80
    {70014,6688,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.71  BV=-0.90
    {80010,6272,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.61  BV=-1.00
    {80010,6720,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.71  BV=-1.10
    {90006,6400,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.64  BV=-1.20
    {100002,6176,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.59  BV=-1.30
    {100002,6624,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.69  BV=-1.40
    {109998,6464,1024, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=7.66  BV=-1.50
    {119994,6336,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.63  BV=-1.60
    {129990,6272,1024, 0, 0, 0},  //TV = 2.94(3095 lines)  AV=2.97  SV=7.61  BV=-1.70
    {139986,6240,1024, 0, 0, 0},  //TV = 2.84(3333 lines)  AV=2.97  SV=7.61  BV=-1.80
    {149982,6240,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=7.61  BV=-1.90
    {160020,6272,1024, 0, 0, 0},  //TV = 2.64(3810 lines)  AV=2.97  SV=7.61  BV=-2.00
    {170016,6336,1024, 0, 0, 0},  //TV = 2.56(4048 lines)  AV=2.97  SV=7.63  BV=-2.10
    {180012,6400,1024, 0, 0, 0},  //TV = 2.47(4286 lines)  AV=2.97  SV=7.64  BV=-2.20
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_CaptureISO800Table =
{
    AETABLE_CAPTURE_ISO800, //eAETableID
    121, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -22, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_800, //ISO
    sCaptureISO800PLineTable_60Hz,
    sCaptureISO800PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO1600PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {462,2784,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.44  BV=7.61
    {462,2976,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.54  BV=7.51
    {462,3200,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.64  BV=7.41
    {462,3424,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.74  BV=7.31
    {462,3680,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.85  BV=7.21
    {462,3936,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.94  BV=7.11
    {462,4224,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.04  BV=7.01
    {462,4512,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.14  BV=6.91
    {462,4832,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.24  BV=6.81
    {462,5216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.35  BV=6.70
    {462,5568,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.44  BV=6.61
    {462,5984,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.55  BV=6.50
    {462,6400,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.64  BV=6.41
    {462,6848,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.74  BV=6.31
    {462,7328,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.84  BV=6.21
    {462,7872,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.94  BV=6.11
    {462,8192,1048, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=8.03  BV=6.02
    {504,8192,1032, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=8.01  BV=5.91
    {546,8192,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=8.00  BV=5.81
    {546,8192,1096, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=8.10  BV=5.71
    {630,8192,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=8.00  BV=5.60
    {672,8192,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=8.00  BV=5.51
    {714,8192,1032, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=8.01  BV=5.41
    {756,8192,1040, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=8.02  BV=5.32
    {798,8192,1056, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=8.04  BV=5.22
    {882,8192,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=8.01  BV=5.11
    {924,8192,1048, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=8.03  BV=5.02
    {1008,8192,1032, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=8.01  BV=4.91
    {1092,8192,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=8.00  BV=4.81
    {1134,8192,1056, 0, 0, 0},  //TV = 9.78(27 lines)  AV=2.97  SV=8.04  BV=4.71
    {1218,8192,1056, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=8.04  BV=4.61
    {1344,8192,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=8.00  BV=4.51
    {1428,8192,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=8.02  BV=4.40
    {1512,8192,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=8.03  BV=4.31
    {1638,8192,1032, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=8.01  BV=4.21
    {1764,8192,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=8.01  BV=4.11
    {1890,8192,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=8.01  BV=4.01
    {2016,8192,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=8.02  BV=3.90
    {2184,8192,1024, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=8.00  BV=3.81
    {2310,8192,1032, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=8.01  BV=3.72
    {2520,8192,1024, 0, 0, 0},  //TV = 8.63(60 lines)  AV=2.97  SV=8.00  BV=3.60
    {2688,8192,1024, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=8.00  BV=3.51
    {2856,8192,1032, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=8.01  BV=3.41
    {3066,8192,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=8.01  BV=3.31
    {3318,8192,1024, 0, 0, 0},  //TV = 8.24(79 lines)  AV=2.97  SV=8.00  BV=3.21
    {3528,8192,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=8.01  BV=3.11
    {3780,8192,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=8.01  BV=3.01
    {4074,8192,1024, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=8.00  BV=2.91
    {4326,8192,1032, 0, 0, 0},  //TV = 7.85(103 lines)  AV=2.97  SV=8.01  BV=2.81
    {4704,8192,1024, 0, 0, 0},  //TV = 7.73(112 lines)  AV=2.97  SV=8.00  BV=2.70
    {4998,8192,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=8.01  BV=2.60
    {5376,8192,1024, 0, 0, 0},  //TV = 7.54(128 lines)  AV=2.97  SV=8.00  BV=2.51
    {5754,8192,1024, 0, 0, 0},  //TV = 7.44(137 lines)  AV=2.97  SV=8.00  BV=2.41
    {6174,8192,1024, 0, 0, 0},  //TV = 7.34(147 lines)  AV=2.97  SV=8.00  BV=2.31
    {6594,8192,1024, 0, 0, 0},  //TV = 7.24(157 lines)  AV=2.97  SV=8.00  BV=2.22
    {7098,8192,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=8.00  BV=2.11
    {7602,8192,1024, 0, 0, 0},  //TV = 7.04(181 lines)  AV=2.97  SV=8.00  BV=2.01
    {8106,8192,1024, 0, 0, 0},  //TV = 6.95(193 lines)  AV=2.97  SV=8.00  BV=1.92
    {8316,8192,1080, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.08  BV=1.80
    {8316,8192,1160, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.18  BV=1.70
    {8316,8192,1240, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.28  BV=1.60
    {8316,8192,1328, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.38  BV=1.51
    {8316,8192,1424, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.48  BV=1.41
    {8316,8192,1528, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.58  BV=1.30
    {8316,8192,1632, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.67  BV=1.21
    {8316,8192,1752, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.77  BV=1.11
    {8316,8192,1872, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.87  BV=1.01
    {8316,8192,2008, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=8.97  BV=0.91
    {16674,8192,1072, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=8.07  BV=0.81
    {16674,8192,1152, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=8.17  BV=0.71
    {16674,8192,1232, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=8.27  BV=0.61
    {16674,8192,1320, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=8.37  BV=0.51
    {16674,8192,1416, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=8.47  BV=0.41
    {16674,8192,1512, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=8.56  BV=0.31
    {24990,8192,1080, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=8.08  BV=0.22
    {24990,8192,1160, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=8.18  BV=0.11
    {24990,8192,1256, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=8.29  BV=-0.00
    {24990,8192,1344, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=8.39  BV=-0.10
    {33348,8192,1080, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=8.08  BV=-0.20
    {33348,8192,1152, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=8.17  BV=-0.29
    {33348,8192,1240, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=8.28  BV=-0.40
    {41664,8192,1064, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=8.06  BV=-0.50
    {41664,8192,1136, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=8.15  BV=-0.59
    {41664,8192,1216, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=8.25  BV=-0.69
    {49980,8192,1096, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=8.10  BV=-0.80
    {49980,8192,1168, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=8.19  BV=-0.90
    {58338,8192,1080, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=8.08  BV=-1.01
    {58338,8192,1160, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=8.18  BV=-1.11
    {66654,8192,1088, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=8.09  BV=-1.21
    {75012,8192,1032, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=8.01  BV=-1.30
    {75012,8192,1104, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=8.11  BV=-1.40
    {83328,8192,1064, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=8.06  BV=-1.50
    {91644,8192,1040, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=8.02  BV=-1.60
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {100002,8192,1096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.10  BV=-1.81
    {108318,8192,1080, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=8.08  BV=-1.90
    {116676,8192,1080, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=8.08  BV=-2.01
    {124992,8192,1080, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=8.08  BV=-2.11
    {133308,8192,1080, 0, 0, 0},  //TV = 2.91(3174 lines)  AV=2.97  SV=8.08  BV=-2.20
    {149982,8192,1032, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=8.01  BV=-2.30
    {158340,8192,1048, 0, 0, 0},  //TV = 2.66(3770 lines)  AV=2.97  SV=8.03  BV=-2.40
    {166656,8192,1064, 0, 0, 0},  //TV = 2.59(3968 lines)  AV=2.97  SV=8.06  BV=-2.50
    {183330,8192,1040, 0, 0, 0},  //TV = 2.45(4365 lines)  AV=2.97  SV=8.02  BV=-2.60
    {191646,8192,1064, 0, 0, 0},  //TV = 2.38(4563 lines)  AV=2.97  SV=8.06  BV=-2.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCaptureISO1600PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {462,1120,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.14  BV=8.91
    {462,1216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.25  BV=8.80
    {462,1280,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.34  BV=8.71
    {462,1376,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.44  BV=8.61
    {462,1472,1040, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.55  BV=8.50
    {462,1600,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.64  BV=8.41
    {462,1696,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.74  BV=8.31
    {462,1824,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.84  BV=8.21
    {462,1952,1032, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.94  BV=8.11
    {462,2112,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.04  BV=8.01
    {462,2272,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.15  BV=7.90
    {462,2432,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.25  BV=7.80
    {462,2592,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.34  BV=7.71
    {462,2784,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.44  BV=7.61
    {462,2976,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.54  BV=7.51
    {462,3200,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.64  BV=7.41
    {462,3424,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.74  BV=7.31
    {462,3680,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.85  BV=7.21
    {462,3936,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=6.94  BV=7.11
    {462,4224,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.04  BV=7.01
    {462,4512,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.14  BV=6.91
    {462,4832,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.24  BV=6.81
    {462,5216,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.35  BV=6.70
    {462,5568,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.44  BV=6.61
    {462,5984,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.55  BV=6.50
    {462,6400,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.64  BV=6.41
    {462,6848,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.74  BV=6.31
    {462,7328,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.84  BV=6.21
    {462,7872,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=7.94  BV=6.11
    {462,8192,1048, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=8.03  BV=6.02
    {504,8192,1032, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=8.01  BV=5.91
    {546,8192,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=8.00  BV=5.81
    {546,8192,1096, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=8.10  BV=5.71
    {630,8192,1024, 0, 0, 0},  //TV = 10.63(15 lines)  AV=2.97  SV=8.00  BV=5.60
    {672,8192,1024, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=8.00  BV=5.51
    {714,8192,1032, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=8.01  BV=5.41
    {756,8192,1040, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=8.02  BV=5.32
    {798,8192,1056, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=8.04  BV=5.22
    {882,8192,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=8.01  BV=5.11
    {924,8192,1048, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=8.03  BV=5.02
    {1008,8192,1032, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=8.01  BV=4.91
    {1092,8192,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=8.00  BV=4.81
    {1134,8192,1056, 0, 0, 0},  //TV = 9.78(27 lines)  AV=2.97  SV=8.04  BV=4.71
    {1218,8192,1056, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=8.04  BV=4.61
    {1344,8192,1024, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=8.00  BV=4.51
    {1428,8192,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=8.02  BV=4.40
    {1512,8192,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=8.03  BV=4.31
    {1638,8192,1032, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=8.01  BV=4.21
    {1764,8192,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=8.01  BV=4.11
    {1890,8192,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=8.01  BV=4.01
    {2016,8192,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=8.02  BV=3.90
    {2184,8192,1024, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=8.00  BV=3.81
    {2310,8192,1032, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=8.01  BV=3.72
    {2520,8192,1024, 0, 0, 0},  //TV = 8.63(60 lines)  AV=2.97  SV=8.00  BV=3.60
    {2688,8192,1024, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=8.00  BV=3.51
    {2856,8192,1032, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=8.01  BV=3.41
    {3066,8192,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=8.01  BV=3.31
    {3318,8192,1024, 0, 0, 0},  //TV = 8.24(79 lines)  AV=2.97  SV=8.00  BV=3.21
    {3528,8192,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=8.01  BV=3.11
    {3780,8192,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=8.01  BV=3.01
    {4074,8192,1024, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=8.00  BV=2.91
    {4326,8192,1032, 0, 0, 0},  //TV = 7.85(103 lines)  AV=2.97  SV=8.01  BV=2.81
    {4704,8192,1024, 0, 0, 0},  //TV = 7.73(112 lines)  AV=2.97  SV=8.00  BV=2.70
    {4998,8192,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=8.01  BV=2.60
    {5376,8192,1024, 0, 0, 0},  //TV = 7.54(128 lines)  AV=2.97  SV=8.00  BV=2.51
    {5754,8192,1024, 0, 0, 0},  //TV = 7.44(137 lines)  AV=2.97  SV=8.00  BV=2.41
    {6174,8192,1024, 0, 0, 0},  //TV = 7.34(147 lines)  AV=2.97  SV=8.00  BV=2.31
    {6594,8192,1024, 0, 0, 0},  //TV = 7.24(157 lines)  AV=2.97  SV=8.00  BV=2.22
    {7098,8192,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=8.00  BV=2.11
    {7602,8192,1024, 0, 0, 0},  //TV = 7.04(181 lines)  AV=2.97  SV=8.00  BV=2.01
    {8106,8192,1024, 0, 0, 0},  //TV = 6.95(193 lines)  AV=2.97  SV=8.00  BV=1.92
    {8778,8192,1024, 0, 0, 0},  //TV = 6.83(209 lines)  AV=2.97  SV=8.00  BV=1.80
    {9408,8192,1024, 0, 0, 0},  //TV = 6.73(224 lines)  AV=2.97  SV=8.00  BV=1.70
    {9996,8192,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.01  BV=1.60
    {9996,8192,1104, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.11  BV=1.51
    {9996,8192,1184, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.21  BV=1.41
    {9996,8192,1264, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.30  BV=1.31
    {9996,8192,1360, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.41  BV=1.21
    {9996,8192,1456, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.51  BV=1.11
    {9996,8192,1560, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.61  BV=1.01
    {9996,8192,1672, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.71  BV=0.91
    {9996,8192,1792, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.81  BV=0.81
    {9996,8192,1920, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=8.91  BV=0.71
    {19992,8192,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.00  BV=0.62
    {19992,8192,1104, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.11  BV=0.51
    {19992,8192,1176, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.20  BV=0.42
    {19992,8192,1264, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.30  BV=0.31
    {19992,8192,1352, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.40  BV=0.21
    {19992,8192,1448, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=8.50  BV=0.12
    {29988,8192,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=8.02  BV=0.01
    {29988,8192,1120, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=8.13  BV=-0.10
    {29988,8192,1200, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=8.23  BV=-0.20
    {29988,8192,1288, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=8.33  BV=-0.30
    {39984,8192,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=8.01  BV=-0.40
    {39984,8192,1112, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=8.12  BV=-0.50
    {39984,8192,1184, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=8.21  BV=-0.59
    {49980,8192,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=8.00  BV=-0.71
    {49980,8192,1096, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=8.10  BV=-0.80
    {49980,8192,1168, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=8.19  BV=-0.90
    {60018,8192,1048, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=8.03  BV=-1.00
    {60018,8192,1120, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=8.13  BV=-1.10
    {70014,8192,1032, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=8.01  BV=-1.20
    {70014,8192,1104, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=8.11  BV=-1.30
    {80010,8192,1040, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=8.02  BV=-1.41
    {80010,8192,1112, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=8.12  BV=-1.50
    {90006,8192,1056, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=8.04  BV=-1.60
    {100002,8192,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.00  BV=-1.71
    {100002,8192,1096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.10  BV=-1.81
    {109998,8192,1064, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=8.06  BV=-1.90
    {119994,8192,1048, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=8.03  BV=-2.00
    {129990,8192,1040, 0, 0, 0},  //TV = 2.94(3095 lines)  AV=2.97  SV=8.02  BV=-2.11
    {139986,8192,1032, 0, 0, 0},  //TV = 2.84(3333 lines)  AV=2.97  SV=8.01  BV=-2.20
    {149982,8192,1032, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=8.01  BV=-2.30
    {160020,8192,1040, 0, 0, 0},  //TV = 2.64(3810 lines)  AV=2.97  SV=8.02  BV=-2.41
    {170016,8192,1048, 0, 0, 0},  //TV = 2.56(4048 lines)  AV=2.97  SV=8.03  BV=-2.51
    {180012,8192,1056, 0, 0, 0},  //TV = 2.47(4286 lines)  AV=2.97  SV=8.04  BV=-2.60
    {190008,8192,1072, 0, 0, 0},  //TV = 2.40(4524 lines)  AV=2.97  SV=8.07  BV=-2.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_CaptureISO1600Table =
{
    AETABLE_CAPTURE_ISO1600, //eAETableID
    126, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -27, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_1600, //ISO
    sCaptureISO1600PLineTable_60Hz,
    sCaptureISO1600PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureStrobePLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33348,1056,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.07  BV=2.81
    {33348,1152,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.17  BV=2.71
    {33348,1248,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.29  BV=2.59
    {41664,1056,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.04  BV=2.51
    {41664,1120,1032, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.14  BV=2.42
    {41664,1216,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.25  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {58338,1056,1032, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.06  BV=2.01
    {58338,1152,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.17  BV=1.90
    {66654,1056,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.07  BV=1.81
    {66654,1152,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.17  BV=1.71
    {66654,1216,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.27  BV=1.61
    {66654,1312,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.37  BV=1.51
    {66654,1408,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.47  BV=1.41
    {66654,1504,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.58  BV=1.30
    {66654,1632,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.67  BV=1.21
    {66654,1728,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.77  BV=1.11
    {66654,1856,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.87  BV=1.01
    {66654,2016,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.98  BV=0.90
    {66654,2144,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.07  BV=0.81
    {66654,2304,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.17  BV=0.71
    {66654,2464,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.27  BV=0.61
    {66654,2656,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.38  BV=0.50
    {66654,2816,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.47  BV=0.41
    {66654,3040,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.57  BV=0.31
    {66654,3232,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.66  BV=0.22
    {66654,3488,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.77  BV=0.11
    {66654,3776,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.88  BV=-0.00
    {66654,4032,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.98  BV=-0.10
    {66654,4320,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=7.08  BV=-0.20
    {75012,4096,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.00  BV=-0.29
    {75012,4416,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.11  BV=-0.40
    {83328,4256,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.06  BV=-0.50
    {91644,4128,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.01  BV=-0.59
    {91644,4448,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.12  BV=-0.70
    {100002,4384,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.10  BV=-0.81
    {100002,4672,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.19  BV=-0.90
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5792,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.50  BV=-1.21
    {100002,6208,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.60  BV=-1.31
    {100002,6656,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.70  BV=-1.41
    {100002,7104,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7616,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.89  BV=-1.60
    {100002,8160,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.99  BV=-1.70
    {100002,8192,1088, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.09  BV=-1.79
    {100002,8192,1168, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.19  BV=-1.90
    {100002,8192,1256, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.29  BV=-2.00
    {100002,8192,1344, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.39  BV=-2.10
    {100002,8192,1440, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.49  BV=-2.20
    {100002,8192,1552, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.60  BV=-2.31
    {100002,8192,1664, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.70  BV=-2.41
    {100002,8192,1784, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.80  BV=-2.51
    {100002,8192,1904, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.89  BV=-2.60
    {100002,8192,2048, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.00  BV=-2.71
    {100002,8192,2192, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.10  BV=-2.81
    {100002,8192,2344, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.19  BV=-2.90
    {100002,8192,2512, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.29  BV=-3.00
    {100002,8192,2696, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.40  BV=-3.10
    {100002,8192,2888, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.50  BV=-3.20
    {100002,8192,3096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.60  BV=-3.30
    {100002,8192,3320, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.70  BV=-3.40
    {100002,8192,3560, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.80  BV=-3.50
    {100002,8192,3808, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.89  BV=-3.60
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sCaptureStrobePLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {39984,1024,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.01  BV=2.60
    {39984,1088,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.10  BV=2.52
    {39984,1184,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.21  BV=2.41
    {39984,1248,1040, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.31  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {60018,1024,1040, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.02  BV=2.01
    {60018,1120,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.13  BV=1.90
    {60018,1184,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.22  BV=1.81
    {60018,1280,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.32  BV=1.71
    {60018,1376,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.43  BV=1.60
    {60018,1472,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.52  BV=1.51
    {60018,1568,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.61  BV=1.41
    {60018,1696,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.73  BV=1.30
    {60018,1792,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.82  BV=1.21
    {60018,1920,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.92  BV=1.11
    {60018,2080,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.02  BV=1.01
    {60018,2240,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.13  BV=0.90
    {60018,2368,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.22  BV=0.81
    {60018,2560,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.32  BV=0.71
    {60018,2752,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.43  BV=0.60
    {60018,2944,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.52  BV=0.51
    {60018,3136,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.61  BV=0.41
    {60018,3360,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.71  BV=0.32
    {60018,3616,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.82  BV=0.21
    {60018,3872,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.92  BV=0.11
    {60018,4192,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.03  BV=-0.00
    {60018,4480,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.13  BV=-0.10
    {70014,4096,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.00  BV=-0.19
    {70014,4416,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.11  BV=-0.30
    {80010,4128,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.01  BV=-0.40
    {80010,4416,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.11  BV=-0.49
    {90006,4224,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.04  BV=-0.60
    {90006,4512,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.14  BV=-0.69
    {100002,4384,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.10  BV=-0.81
    {100002,4672,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.19  BV=-0.90
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5792,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.50  BV=-1.21
    {100002,6208,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.60  BV=-1.31
    {100002,6656,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.70  BV=-1.41
    {100002,7104,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.79  BV=-1.50
    {100002,7616,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.89  BV=-1.60
    {100002,8160,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.99  BV=-1.70
    {100002,8192,1088, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.09  BV=-1.79
    {100002,8192,1168, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.19  BV=-1.90
    {100002,8192,1256, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.29  BV=-2.00
    {100002,8192,1344, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.39  BV=-2.10
    {100002,8192,1440, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.49  BV=-2.20
    {100002,8192,1552, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.60  BV=-2.31
    {100002,8192,1664, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.70  BV=-2.41
    {100002,8192,1784, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.80  BV=-2.51
    {100002,8192,1904, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=8.89  BV=-2.60
    {100002,8192,2048, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.00  BV=-2.71
    {100002,8192,2192, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.10  BV=-2.81
    {100002,8192,2344, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.19  BV=-2.90
    {100002,8192,2512, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.29  BV=-3.00
    {100002,8192,2696, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.40  BV=-3.10
    {100002,8192,2888, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.50  BV=-3.20
    {100002,8192,3096, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.60  BV=-3.30
    {100002,8192,3320, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.70  BV=-3.40
    {100002,8192,3560, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.80  BV=-3.50
    {100002,8192,3808, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=9.89  BV=-3.60
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_StrobeTable =
{
    AETABLE_STROBE, //eAETableID
    135, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -36, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCaptureStrobePLineTable_60Hz,
    sCaptureStrobePLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene1PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33348,1056,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.07  BV=2.81
    {33348,1152,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.17  BV=2.71
    {33348,1248,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.29  BV=2.59
    {41664,1056,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.04  BV=2.51
    {41664,1120,1032, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.14  BV=2.42
    {41664,1216,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.25  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {58338,1056,1032, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.06  BV=2.01
    {58338,1152,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.17  BV=1.90
    {66654,1056,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.07  BV=1.81
    {66654,1152,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.17  BV=1.71
    {66654,1216,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.27  BV=1.61
    {66654,1312,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.37  BV=1.51
    {66654,1408,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.47  BV=1.41
    {66654,1504,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.58  BV=1.30
    {66654,1632,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.67  BV=1.21
    {66654,1728,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.77  BV=1.11
    {66654,1856,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.87  BV=1.01
    {66654,2016,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.98  BV=0.90
    {66654,2144,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.07  BV=0.81
    {66654,2304,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.17  BV=0.71
    {66654,2464,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.27  BV=0.61
    {66654,2656,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.38  BV=0.50
    {66654,2816,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.47  BV=0.41
    {66654,3040,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.57  BV=0.31
    {66654,3232,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.66  BV=0.22
    {66654,3488,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.77  BV=0.11
    {66654,3776,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.88  BV=-0.00
    {66654,4032,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.98  BV=-0.10
    {66654,4320,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=7.08  BV=-0.20
    {75012,4096,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.00  BV=-0.29
    {75012,4416,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.11  BV=-0.40
    {83328,4256,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.06  BV=-0.50
    {91644,4128,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.01  BV=-0.59
    {91644,4448,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.12  BV=-0.70
    {100002,4352,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.09  BV=-0.79
    {108318,4320,1024, 0, 0, 0},  //TV = 3.21(2579 lines)  AV=2.97  SV=7.08  BV=-0.90
    {116676,4288,1024, 0, 0, 0},  //TV = 3.10(2778 lines)  AV=2.97  SV=7.07  BV=-1.00
    {124992,4288,1024, 0, 0, 0},  //TV = 3.00(2976 lines)  AV=2.97  SV=7.07  BV=-1.10
    {133308,4320,1024, 0, 0, 0},  //TV = 2.91(3174 lines)  AV=2.97  SV=7.08  BV=-1.20
    {149982,4096,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=7.00  BV=-1.29
    {158340,4160,1024, 0, 0, 0},  //TV = 2.66(3770 lines)  AV=2.97  SV=7.02  BV=-1.39
    {166656,4256,1024, 0, 0, 0},  //TV = 2.59(3968 lines)  AV=2.97  SV=7.06  BV=-1.50
    {183330,4128,1024, 0, 0, 0},  //TV = 2.45(4365 lines)  AV=2.97  SV=7.01  BV=-1.59
    {191646,4256,1024, 0, 0, 0},  //TV = 2.38(4563 lines)  AV=2.97  SV=7.06  BV=-1.70
    {200004,4384,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.10  BV=-1.81
    {200004,4672,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.19  BV=-1.90
    {200004,5024,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.29  BV=-2.00
    {200004,5376,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.39  BV=-2.10
    {200004,5792,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.50  BV=-2.21
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sAEScene1PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {39984,1024,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.01  BV=2.60
    {39984,1088,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.10  BV=2.52
    {39984,1184,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.21  BV=2.41
    {39984,1248,1040, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.31  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {60018,1024,1040, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.02  BV=2.01
    {60018,1120,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.13  BV=1.90
    {60018,1184,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.22  BV=1.81
    {60018,1280,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.32  BV=1.71
    {60018,1376,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.43  BV=1.60
    {60018,1472,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.52  BV=1.51
    {60018,1568,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.61  BV=1.41
    {60018,1696,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.73  BV=1.30
    {60018,1792,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.82  BV=1.21
    {60018,1920,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.92  BV=1.11
    {60018,2080,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.02  BV=1.01
    {60018,2240,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.13  BV=0.90
    {60018,2368,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.22  BV=0.81
    {60018,2560,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.32  BV=0.71
    {60018,2752,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.43  BV=0.60
    {60018,2944,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.52  BV=0.51
    {60018,3136,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.61  BV=0.41
    {60018,3360,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.71  BV=0.32
    {60018,3616,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.82  BV=0.21
    {60018,3872,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.92  BV=0.11
    {60018,4192,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.03  BV=-0.00
    {60018,4480,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.13  BV=-0.10
    {70014,4096,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.00  BV=-0.19
    {70014,4416,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.11  BV=-0.30
    {80010,4128,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.01  BV=-0.40
    {80010,4416,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.11  BV=-0.49
    {90006,4224,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.04  BV=-0.60
    {90006,4512,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.14  BV=-0.69
    {100002,4352,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.09  BV=-0.79
    {109998,4256,1024, 0, 0, 0},  //TV = 3.18(2619 lines)  AV=2.97  SV=7.06  BV=-0.90
    {119994,4160,1024, 0, 0, 0},  //TV = 3.06(2857 lines)  AV=2.97  SV=7.02  BV=-0.99
    {129990,4128,1024, 0, 0, 0},  //TV = 2.94(3095 lines)  AV=2.97  SV=7.01  BV=-1.10
    {139986,4096,1024, 0, 0, 0},  //TV = 2.84(3333 lines)  AV=2.97  SV=7.00  BV=-1.19
    {149982,4096,1024, 0, 0, 0},  //TV = 2.74(3571 lines)  AV=2.97  SV=7.00  BV=-1.29
    {160020,4128,1024, 0, 0, 0},  //TV = 2.64(3810 lines)  AV=2.97  SV=7.01  BV=-1.40
    {170016,4160,1024, 0, 0, 0},  //TV = 2.56(4048 lines)  AV=2.97  SV=7.02  BV=-1.50
    {180012,4224,1024, 0, 0, 0},  //TV = 2.47(4286 lines)  AV=2.97  SV=7.04  BV=-1.60
    {190008,4288,1024, 0, 0, 0},  //TV = 2.40(4524 lines)  AV=2.97  SV=7.07  BV=-1.70
    {200004,4384,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.10  BV=-1.81
    {200004,4672,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.19  BV=-1.90
    {200004,5024,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.29  BV=-2.00
    {200004,5376,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.39  BV=-2.10
    {200004,5792,1024, 0, 0, 0},  //TV = 2.32(4762 lines)  AV=2.97  SV=7.50  BV=-2.21
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_SceneTable1 =
{
    AETABLE_SCENE_INDEX1, //eAETableID
    121, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -22, //i4MinBV
    90, //i4EffectiveMaxBV
    -10, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene1PLineTable_60Hz,
    sAEScene1PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene2PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.38  BV=4.50
    {8316,1408,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.47  BV=4.41
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1728,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.77  BV=4.11
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,1984,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.97  BV=3.92
    {8316,2144,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.07  BV=3.81
    {8316,2304,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.17  BV=3.71
    {8316,2464,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.27  BV=3.61
    {8316,2656,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.38  BV=3.51
    {8316,2848,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.48  BV=3.41
    {8316,3040,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.57  BV=3.31
    {8316,3264,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.67  BV=3.21
    {8316,3488,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.77  BV=3.11
    {8316,3744,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.87  BV=3.01
    {8316,4000,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=6.97  BV=2.91
    {8316,4288,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.07  BV=2.81
    {8316,4608,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.17  BV=2.71
    {8316,4960,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.28  BV=2.60
    {8316,5312,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.38  BV=2.51
    {8316,5696,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.48  BV=2.41
    {8316,6080,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.57  BV=2.31
    {8316,6528,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.67  BV=2.21
    {8316,6976,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.77  BV=2.11
    {8316,7488,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.87  BV=2.01
    {8316,8032,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=7.97  BV=1.91
    {16674,4288,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.07  BV=1.81
    {16674,4576,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.16  BV=1.72
    {16674,4960,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.28  BV=1.60
    {16674,5312,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.38  BV=1.50
    {16674,5696,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.48  BV=1.40
    {16674,6080,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=7.57  BV=1.31
    {24990,4352,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.09  BV=1.21
    {24990,4672,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.19  BV=1.10
    {24990,4992,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.29  BV=1.01
    {24990,5376,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=7.39  BV=0.90
    {33348,4288,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.07  BV=0.81
    {33348,4576,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.16  BV=0.72
    {33348,4928,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.27  BV=0.61
    {33348,5280,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.37  BV=0.51
    {33348,5664,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.47  BV=0.41
    {33348,6080,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=7.57  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sAEScene2PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.50  BV=4.11
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.70  BV=3.91
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {9996,2048,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.00  BV=3.62
    {9996,2208,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.11  BV=3.51
    {9996,2368,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.21  BV=3.41
    {9996,2528,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.30  BV=3.31
    {9996,2720,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.41  BV=3.21
    {9996,2912,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.51  BV=3.11
    {9996,3104,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.60  BV=3.02
    {9996,3328,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.70  BV=2.91
    {9996,3584,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.81  BV=2.81
    {9996,3840,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=6.91  BV=2.71
    {9996,4128,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.01  BV=2.60
    {9996,4416,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.11  BV=2.51
    {9996,4736,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.21  BV=2.41
    {9996,5056,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.30  BV=2.31
    {9996,5408,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.40  BV=2.21
    {9996,5824,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.51  BV=2.11
    {9996,6240,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.61  BV=2.01
    {9996,6688,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.71  BV=1.91
    {9996,7136,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.80  BV=1.81
    {9996,7648,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=7.90  BV=1.71
    {19992,4096,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.00  BV=1.62
    {19992,4384,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.10  BV=1.52
    {19992,4736,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.21  BV=1.41
    {19992,5088,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.31  BV=1.30
    {19992,5440,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.41  BV=1.21
    {19992,5824,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=7.51  BV=1.11
    {29988,4160,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.02  BV=1.01
    {29988,4480,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.13  BV=0.90
    {29988,4768,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.22  BV=0.81
    {29988,5120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.32  BV=0.71
    {29988,5504,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.43  BV=0.60
    {29988,5888,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.52  BV=0.51
    {29988,6304,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.62  BV=0.41
    {29988,6752,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=7.72  BV=0.31
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_SceneTable2 =
{
    AETABLE_SCENE_INDEX2, //eAETableID
    96, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    3, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene2PLineTable_60Hz,
    sAEScene2PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene3PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33348,1056,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.07  BV=2.81
    {33348,1152,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.17  BV=2.71
    {33348,1216,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.27  BV=2.61
    {33348,1312,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.37  BV=2.51
    {33348,1408,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.46  BV=2.42
    {33348,1504,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.58  BV=2.30
    {33348,1632,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.67  BV=2.20
    {33348,1728,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.77  BV=2.11
    {33348,1856,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.87  BV=2.01
    {33348,2016,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.98  BV=1.90
    {33348,2144,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.07  BV=1.81
    {33348,2304,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.17  BV=1.71
    {33348,2464,1032, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=6.28  BV=1.60
    {41664,2112,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=6.04  BV=1.51
    {41664,2272,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=6.15  BV=1.41
    {41664,2432,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=6.25  BV=1.31
    {49980,2176,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.09  BV=1.21
    {49980,2304,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.18  BV=1.11
    {58338,2112,1032, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=6.06  BV=1.01
    {58338,2304,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=6.17  BV=0.90
    {66654,2144,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.07  BV=0.81
    {66654,2304,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.17  BV=0.71
    {66654,2464,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.27  BV=0.61
    {66654,2624,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.37  BV=0.51
    {66654,2848,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.48  BV=0.40
    {66654,3040,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.57  BV=0.31
    {66654,3264,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.67  BV=0.21
    {66654,3488,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.77  BV=0.11
    {66654,3776,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.88  BV=-0.00
    {66654,4032,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.98  BV=-0.10
    {66654,4320,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=7.08  BV=-0.20
    {75012,4096,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.00  BV=-0.29
    {75012,4416,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=7.11  BV=-0.40
    {83328,4256,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.06  BV=-0.50
    {91644,4128,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.01  BV=-0.59
    {91644,4448,1024, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=7.12  BV=-0.70
    {100002,4384,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.10  BV=-0.81
    {100002,4672,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.19  BV=-0.90
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5792,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.50  BV=-1.21
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sAEScene3PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {29988,1376,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.43  BV=2.60
    {29988,1472,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.52  BV=2.51
    {29988,1568,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.61  BV=2.42
    {29988,1696,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.73  BV=2.30
    {29988,1824,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.83  BV=2.20
    {29988,1920,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.92  BV=2.11
    {29988,2080,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.02  BV=2.01
    {29988,2240,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.13  BV=1.90
    {29988,2368,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.22  BV=1.81
    {29988,2560,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=6.32  BV=1.71
    {39984,2048,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=6.00  BV=1.62
    {39984,2208,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=6.11  BV=1.51
    {39984,2368,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=6.21  BV=1.41
    {39984,2528,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=6.30  BV=1.31
    {49980,2176,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.09  BV=1.21
    {49980,2304,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=6.18  BV=1.11
    {60018,2080,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.02  BV=1.01
    {60018,2240,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.13  BV=0.90
    {60018,2400,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.23  BV=0.80
    {60018,2560,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.32  BV=0.71
    {60018,2720,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.42  BV=0.61
    {60018,2912,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.52  BV=0.51
    {60018,3136,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.61  BV=0.41
    {60018,3360,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.71  BV=0.32
    {60018,3616,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.82  BV=0.21
    {60018,3904,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.93  BV=0.10
    {60018,4192,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.03  BV=-0.00
    {60018,4480,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=7.13  BV=-0.10
    {70014,4096,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.00  BV=-0.19
    {70014,4416,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=7.11  BV=-0.30
    {80010,4128,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.01  BV=-0.40
    {80010,4416,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.11  BV=-0.49
    {90006,4224,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.04  BV=-0.60
    {90006,4512,1024, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=7.14  BV=-0.69
    {100002,4384,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.10  BV=-0.81
    {100002,4672,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.19  BV=-0.90
    {100002,5024,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.29  BV=-1.00
    {100002,5376,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.39  BV=-1.10
    {100002,5792,1024, 0, 0, 0},  //TV = 3.32(2381 lines)  AV=2.97  SV=7.50  BV=-1.21
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_SceneTable3 =
{
    AETABLE_SCENE_INDEX3, //eAETableID
    111, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -12, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene3PLineTable_60Hz,
    sAEScene3PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene4PLineTable_60Hz =
{
{
    {249984,1696,1032, 0, 0, 0},  //TV = 2.00(5952 lines)  AV=2.97  SV=5.74  BV=-0.77
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sAEScene4PLineTable_50Hz =
{
{
    {249984,1696,1032, 0, 0, 0},  //TV = 2.00(5952 lines)  AV=2.97  SV=5.74  BV=-0.77
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_SceneTable4 =
{
    AETABLE_SCENE_INDEX4, //eAETableID
    1, //u4TotalIndex
    20, //i4StrobeTrigerBV
    1, //i4MaxBV
    -7, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene4PLineTable_60Hz,
    sAEScene4PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene5PLineTable_60Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8316,1056,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.07  BV=4.81
    {8316,1152,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.17  BV=4.71
    {8316,1216,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.27  BV=4.61
    {8316,1312,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.37  BV=4.51
    {8316,1408,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.48  BV=4.40
    {8316,1504,1040, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.58  BV=4.30
    {8316,1632,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.67  BV=4.21
    {8316,1760,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.78  BV=4.10
    {8316,1856,1032, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.87  BV=4.01
    {8316,2016,1024, 0, 0, 0},  //TV = 6.91(198 lines)  AV=2.97  SV=5.98  BV=3.90
    {16674,1056,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.07  BV=3.81
    {16674,1152,1024, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.17  BV=3.71
    {16674,1216,1040, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.27  BV=3.61
    {16674,1312,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.37  BV=3.51
    {16674,1408,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.47  BV=3.41
    {16674,1504,1032, 0, 0, 0},  //TV = 5.91(397 lines)  AV=2.97  SV=5.57  BV=3.31
    {24990,1088,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.09  BV=3.21
    {24990,1152,1032, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.18  BV=3.11
    {24990,1248,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.29  BV=3.01
    {24990,1344,1024, 0, 0, 0},  //TV = 5.32(595 lines)  AV=2.97  SV=5.39  BV=2.90
    {33348,1056,1040, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.07  BV=2.81
    {33348,1152,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.17  BV=2.71
    {33348,1248,1024, 0, 0, 0},  //TV = 4.91(794 lines)  AV=2.97  SV=5.29  BV=2.59
    {41664,1056,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.04  BV=2.51
    {41664,1120,1032, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.14  BV=2.42
    {41664,1216,1024, 0, 0, 0},  //TV = 4.59(992 lines)  AV=2.97  SV=5.25  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {58338,1056,1032, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.06  BV=2.01
    {58338,1152,1024, 0, 0, 0},  //TV = 4.10(1389 lines)  AV=2.97  SV=5.17  BV=1.90
    {66654,1056,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.07  BV=1.81
    {66654,1152,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.17  BV=1.71
    {66654,1216,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.27  BV=1.61
    {66654,1312,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.37  BV=1.51
    {66654,1408,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.47  BV=1.41
    {66654,1504,1040, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.58  BV=1.30
    {66654,1632,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.67  BV=1.21
    {66654,1728,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.77  BV=1.11
    {66654,1856,1032, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.87  BV=1.01
    {66654,2016,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=5.98  BV=0.90
    {66654,2144,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.07  BV=0.81
    {66654,2304,1024, 0, 0, 0},  //TV = 3.91(1587 lines)  AV=2.97  SV=6.17  BV=0.71
    {75012,2176,1024, 0, 0, 0},  //TV = 3.74(1786 lines)  AV=2.97  SV=6.09  BV=0.62
    {83328,2112,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.04  BV=0.51
    {83328,2272,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.15  BV=0.41
    {83328,2432,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.25  BV=0.31
    {83328,2592,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.34  BV=0.22
    {83328,2784,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.44  BV=0.11
    {83328,3008,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.55  BV=0.00
    {83328,3232,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.66  BV=-0.10
    {83328,3456,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.75  BV=-0.20
    {83328,3712,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.86  BV=-0.30
    {83328,4000,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=6.97  BV=-0.41
    {83328,4256,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.06  BV=-0.50
    {83328,4576,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.16  BV=-0.60
    {83328,4896,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.26  BV=-0.70
    {83328,5248,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.36  BV=-0.80
    {83328,5600,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.45  BV=-0.90
    {83328,6016,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.55  BV=-1.00
    {83328,6496,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.67  BV=-1.11
    {83328,6944,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.76  BV=-1.21
    {83328,7424,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.86  BV=-1.30
    {83328,7968,1024, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=7.96  BV=-1.40
    {83328,8192,1064, 0, 0, 0},  //TV = 3.59(1984 lines)  AV=2.97  SV=8.06  BV=-1.50
    {91644,8192,1040, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=8.02  BV=-1.60
    {91644,8192,1112, 0, 0, 0},  //TV = 3.45(2182 lines)  AV=2.97  SV=8.12  BV=-1.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strEvPline sAEScene5PLineTable_50Hz =
{
{
    {252,1152,1024, 0, 0, 0},  //TV = 11.95(6 lines)  AV=2.97  SV=5.17  BV=9.76
    {294,1024,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.00  BV=9.70
    {294,1088,1024, 0, 0, 0},  //TV = 11.73(7 lines)  AV=2.97  SV=5.09  BV=9.62
    {336,1024,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.01  BV=9.50
    {336,1088,1032, 0, 0, 0},  //TV = 11.54(8 lines)  AV=2.97  SV=5.10  BV=9.41
    {378,1024,1048, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.03  BV=9.31
    {378,1120,1024, 0, 0, 0},  //TV = 11.37(9 lines)  AV=2.97  SV=5.13  BV=9.21
    {420,1088,1024, 0, 0, 0},  //TV = 11.22(10 lines)  AV=2.97  SV=5.09  BV=9.10
    {462,1056,1024, 0, 0, 0},  //TV = 11.08(11 lines)  AV=2.97  SV=5.04  BV=9.01
    {504,1024,1040, 0, 0, 0},  //TV = 10.95(12 lines)  AV=2.97  SV=5.02  BV=8.90
    {546,1024,1024, 0, 0, 0},  //TV = 10.84(13 lines)  AV=2.97  SV=5.00  BV=8.81
    {588,1024,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.00  BV=8.70
    {588,1088,1024, 0, 0, 0},  //TV = 10.73(14 lines)  AV=2.97  SV=5.09  BV=8.62
    {672,1024,1032, 0, 0, 0},  //TV = 10.54(16 lines)  AV=2.97  SV=5.01  BV=8.50
    {714,1024,1040, 0, 0, 0},  //TV = 10.45(17 lines)  AV=2.97  SV=5.02  BV=8.40
    {756,1024,1048, 0, 0, 0},  //TV = 10.37(18 lines)  AV=2.97  SV=5.03  BV=8.31
    {798,1056,1024, 0, 0, 0},  //TV = 10.29(19 lines)  AV=2.97  SV=5.04  BV=8.22
    {882,1024,1032, 0, 0, 0},  //TV = 10.15(21 lines)  AV=2.97  SV=5.01  BV=8.11
    {924,1056,1024, 0, 0, 0},  //TV = 10.08(22 lines)  AV=2.97  SV=5.04  BV=8.01
    {1008,1024,1040, 0, 0, 0},  //TV = 9.95(24 lines)  AV=2.97  SV=5.02  BV=7.90
    {1092,1024,1024, 0, 0, 0},  //TV = 9.84(26 lines)  AV=2.97  SV=5.00  BV=7.81
    {1176,1024,1024, 0, 0, 0},  //TV = 9.73(28 lines)  AV=2.97  SV=5.00  BV=7.70
    {1218,1056,1024, 0, 0, 0},  //TV = 9.68(29 lines)  AV=2.97  SV=5.04  BV=7.61
    {1344,1024,1032, 0, 0, 0},  //TV = 9.54(32 lines)  AV=2.97  SV=5.01  BV=7.50
    {1428,1024,1040, 0, 0, 0},  //TV = 9.45(34 lines)  AV=2.97  SV=5.02  BV=7.40
    {1512,1024,1048, 0, 0, 0},  //TV = 9.37(36 lines)  AV=2.97  SV=5.03  BV=7.31
    {1638,1024,1040, 0, 0, 0},  //TV = 9.25(39 lines)  AV=2.97  SV=5.02  BV=7.20
    {1764,1024,1032, 0, 0, 0},  //TV = 9.15(42 lines)  AV=2.97  SV=5.01  BV=7.11
    {1890,1024,1032, 0, 0, 0},  //TV = 9.05(45 lines)  AV=2.97  SV=5.01  BV=7.01
    {2016,1024,1040, 0, 0, 0},  //TV = 8.95(48 lines)  AV=2.97  SV=5.02  BV=6.90
    {2184,1024,1032, 0, 0, 0},  //TV = 8.84(52 lines)  AV=2.97  SV=5.01  BV=6.80
    {2310,1024,1040, 0, 0, 0},  //TV = 8.76(55 lines)  AV=2.97  SV=5.02  BV=6.71
    {2478,1024,1040, 0, 0, 0},  //TV = 8.66(59 lines)  AV=2.97  SV=5.02  BV=6.61
    {2688,1024,1032, 0, 0, 0},  //TV = 8.54(64 lines)  AV=2.97  SV=5.01  BV=6.50
    {2856,1024,1040, 0, 0, 0},  //TV = 8.45(68 lines)  AV=2.97  SV=5.02  BV=6.40
    {3066,1024,1032, 0, 0, 0},  //TV = 8.35(73 lines)  AV=2.97  SV=5.01  BV=6.31
    {3276,1024,1040, 0, 0, 0},  //TV = 8.25(78 lines)  AV=2.97  SV=5.02  BV=6.20
    {3528,1024,1032, 0, 0, 0},  //TV = 8.15(84 lines)  AV=2.97  SV=5.01  BV=6.11
    {3780,1024,1032, 0, 0, 0},  //TV = 8.05(90 lines)  AV=2.97  SV=5.01  BV=6.01
    {4074,1024,1032, 0, 0, 0},  //TV = 7.94(97 lines)  AV=2.97  SV=5.01  BV=5.90
    {4368,1024,1024, 0, 0, 0},  //TV = 7.84(104 lines)  AV=2.97  SV=5.00  BV=5.81
    {4662,1024,1032, 0, 0, 0},  //TV = 7.74(111 lines)  AV=2.97  SV=5.01  BV=5.70
    {4998,1024,1032, 0, 0, 0},  //TV = 7.64(119 lines)  AV=2.97  SV=5.01  BV=5.60
    {5418,1024,1024, 0, 0, 0},  //TV = 7.53(129 lines)  AV=2.97  SV=5.00  BV=5.50
    {5796,1024,1024, 0, 0, 0},  //TV = 7.43(138 lines)  AV=2.97  SV=5.00  BV=5.40
    {6132,1024,1032, 0, 0, 0},  //TV = 7.35(146 lines)  AV=2.97  SV=5.01  BV=5.31
    {6636,1024,1024, 0, 0, 0},  //TV = 7.24(158 lines)  AV=2.97  SV=5.00  BV=5.21
    {7098,1024,1024, 0, 0, 0},  //TV = 7.14(169 lines)  AV=2.97  SV=5.00  BV=5.11
    {7644,1024,1032, 0, 0, 0},  //TV = 7.03(182 lines)  AV=2.97  SV=5.01  BV=4.99
    {8190,1024,1032, 0, 0, 0},  //TV = 6.93(195 lines)  AV=2.97  SV=5.01  BV=4.89
    {8736,1024,1024, 0, 0, 0},  //TV = 6.84(208 lines)  AV=2.97  SV=5.00  BV=4.81
    {9366,1024,1024, 0, 0, 0},  //TV = 6.74(223 lines)  AV=2.97  SV=5.00  BV=4.71
    {9996,1024,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.01  BV=4.60
    {9996,1088,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.10  BV=4.52
    {9996,1184,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.21  BV=4.41
    {9996,1248,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.31  BV=4.31
    {9996,1344,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.41  BV=4.20
    {9996,1440,1040, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.51  BV=4.10
    {9996,1568,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.61  BV=4.00
    {9996,1664,1032, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.71  BV=3.90
    {9996,1792,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.81  BV=3.81
    {9996,1920,1024, 0, 0, 0},  //TV = 6.64(238 lines)  AV=2.97  SV=5.91  BV=3.71
    {19992,1024,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.01  BV=3.60
    {19992,1088,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.10  BV=3.52
    {19992,1184,1024, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.21  BV=3.41
    {19992,1248,1040, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.31  BV=3.31
    {19992,1344,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.40  BV=3.21
    {19992,1440,1032, 0, 0, 0},  //TV = 5.64(476 lines)  AV=2.97  SV=5.50  BV=3.11
    {29988,1024,1040, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.02  BV=3.01
    {29988,1120,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.13  BV=2.90
    {29988,1184,1032, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.22  BV=2.81
    {29988,1280,1024, 0, 0, 0},  //TV = 5.06(714 lines)  AV=2.97  SV=5.32  BV=2.71
    {39984,1024,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.01  BV=2.60
    {39984,1088,1032, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.10  BV=2.52
    {39984,1184,1024, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.21  BV=2.41
    {39984,1248,1040, 0, 0, 0},  //TV = 4.64(952 lines)  AV=2.97  SV=5.31  BV=2.31
    {49980,1088,1024, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.09  BV=2.21
    {49980,1152,1032, 0, 0, 0},  //TV = 4.32(1190 lines)  AV=2.97  SV=5.18  BV=2.11
    {60018,1024,1040, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.02  BV=2.01
    {60018,1120,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.13  BV=1.90
    {60018,1184,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.22  BV=1.81
    {60018,1280,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.32  BV=1.71
    {60018,1376,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.43  BV=1.60
    {60018,1472,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.52  BV=1.51
    {60018,1568,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.61  BV=1.41
    {60018,1696,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.73  BV=1.30
    {60018,1792,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.82  BV=1.21
    {60018,1920,1032, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=5.92  BV=1.11
    {60018,2080,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.02  BV=1.01
    {60018,2240,1024, 0, 0, 0},  //TV = 4.06(1429 lines)  AV=2.97  SV=6.13  BV=0.90
    {70014,2048,1032, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.01  BV=0.80
    {70014,2176,1024, 0, 0, 0},  //TV = 3.84(1667 lines)  AV=2.97  SV=6.09  BV=0.72
    {80010,2048,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.00  BV=0.61
    {80010,2208,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.11  BV=0.51
    {80010,2336,1032, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.20  BV=0.41
    {80010,2528,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.30  BV=0.31
    {80010,2720,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.41  BV=0.21
    {80010,2912,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.51  BV=0.11
    {80010,3136,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.61  BV=-0.00
    {80010,3360,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.71  BV=-0.10
    {80010,3584,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.81  BV=-0.19
    {80010,3840,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=6.91  BV=-0.29
    {80010,4160,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.02  BV=-0.41
    {80010,4448,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.12  BV=-0.50
    {80010,4768,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.22  BV=-0.60
    {80010,5088,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.31  BV=-0.70
    {80010,5472,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.42  BV=-0.80
    {80010,5856,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.52  BV=-0.90
    {80010,6272,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.61  BV=-1.00
    {80010,6752,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.72  BV=-1.11
    {80010,7232,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.82  BV=-1.21
    {80010,7744,1024, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=7.92  BV=-1.30
    {80010,8192,1032, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=8.01  BV=-1.40
    {80010,8192,1112, 0, 0, 0},  //TV = 3.64(1905 lines)  AV=2.97  SV=8.12  BV=-1.50
    {90006,8192,1056, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=8.04  BV=-1.60
    {90006,8192,1128, 0, 0, 0},  //TV = 3.47(2143 lines)  AV=2.97  SV=8.14  BV=-1.69
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static strAETable g_AE_SceneTable5 =
{
    AETABLE_SCENE_INDEX5, //eAETableID
    116, //u4TotalIndex
    20, //i4StrobeTrigerBV
    98, //i4MaxBV
    -17, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene5PLineTable_60Hz,
    sAEScene5PLineTable_50Hz,
    NULL,
};
static strEvPline sAESceneReservePLineTable =
{
{
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};
static strAETable g_AE_ReserveSceneTable =
{
	AETABLE_SCENE_MAX,    //eAETableID
	0,    //u4TotalIndex
	20,    //u4StrobeTrigerBV
	0,    //i4MaxBV
	0,    //i4MinBV
	90,    //i4EffectiveMaxBV
	0,      //i4EffectiveMinBV
	LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
	sAESceneReservePLineTable,
	sAESceneReservePLineTable,
	NULL,
};

static strAESceneMapping g_AEScenePLineMapping = 
{
{
    {LIB3A_AE_SCENE_AUTO, {AETABLE_SCENE_INDEX5, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_NIGHT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_ACTION, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_BEACH, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_CANDLELIGHT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_FIREWORKS, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX4, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX4}},
    {LIB3A_AE_SCENE_LANDSCAPE, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_PORTRAIT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_NIGHT_PORTRAIT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_PARTY, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_SNOW, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_SPORTS, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_STEADYPHOTO, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_SUNSET, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_THEATRE, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_ISO_ANTI_SHAKE, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_ISO100, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO100, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO100}},
    {LIB3A_AE_SCENE_ISO200, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO200, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO200}},
    {LIB3A_AE_SCENE_ISO400, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO400, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO400}},
    {LIB3A_AE_SCENE_ISO800, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO800, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO800}},
    {LIB3A_AE_SCENE_ISO1600, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO1600, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO1600}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
},
};

static strAEPLineTable g_strAEPlineTable =
{
{
// PLINE Table
    g_AE_PreviewAutoTable,
    g_AE_CaptureAutoTable,
    g_AE_VideoAutoTable,
    g_AE_Video1AutoTable,
    g_AE_Video2AutoTable,
    g_AE_Custom1AutoTable,
    g_AE_Custom2AutoTable,
    g_AE_Custom3AutoTable,
    g_AE_Custom4AutoTable,
    g_AE_Custom5AutoTable,
    g_AE_VideoNightTable,
    g_AE_CaptureISO100Table,
    g_AE_CaptureISO200Table,
    g_AE_CaptureISO400Table,
    g_AE_CaptureISO800Table,
    g_AE_CaptureISO1600Table,
    g_AE_StrobeTable,
    g_AE_SceneTable1,
    g_AE_SceneTable2,
    g_AE_SceneTable3,
    g_AE_SceneTable4,
    g_AE_SceneTable5,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
},
};

static strAEPLineNumInfo g_strAEPreviewAutoPLineInfo =
{
    AETABLE_RPEVIEW_AUTO,
    90,
    -10,
    {
        {1,3500,20,1024,1024},
        {2,20,15,1024,1024},
        {3,15,15,1024,2048},
        {4,15,10,2048,2048},
        {5,10,10,2048,8192},
        {6,10,8,8192,8192},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECaptureAutoPLineInfo =
{
    AETABLE_CAPTURE_AUTO,
    90,
    0,
    {
        {1,3500,20,1024,1024},
        {2,20,12,1024,1024},
        {3,12,12,1024,2048},
        {4,12,10,2048,2048},
        {5,10,10,2048,8192},
        {6,10,8,8192,8192},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEVideoAutoPLineInfo =
{
    AETABLE_VIDEO_AUTO,
    90,
    0,
    {
        {1,3500,20,1024,1024},
        {2,20,20,1024,2048},
        {3,20,8,2048,2048},
        {4,8,8,2048,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEVideo1AutoPLineInfo =
{
    AETABLE_VIDEO1_AUTO,
    90,
    0,
    {
        {1,3500,60,1195,1195},
        {2,60,60,1195,6144},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEVideo2AutoPLineInfo =
{
    AETABLE_VIDEO2_AUTO,
    90,
    0,
    {
        {1,3500,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECustom1AutoPLineInfo =
{
    AETABLE_CUSTOM1_AUTO,
    90,
    0,
    {
        {1,3500,60,1024,1024},
        {2,60,60,1024,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECustom2AutoPLineInfo =
{
    AETABLE_CUSTOM2_AUTO,
    90,
    0,
    {
        {1,3500,60,1024,1024},
        {2,60,60,1024,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECustom3AutoPLineInfo =
{
    AETABLE_CUSTOM3_AUTO,
    90,
    0,
    {
        {1,3500,60,1024,1024},
        {2,60,60,1024,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECustom4AutoPLineInfo =
{
    AETABLE_CUSTOM4_AUTO,
    90,
    0,
    {
        {1,3500,60,1024,1024},
        {2,60,60,1024,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECustom5AutoPLineInfo =
{
    AETABLE_CUSTOM5_AUTO,
    90,
    0,
    {
        {1,3500,60,1024,1024},
        {2,60,60,1024,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEVideoNightPLineInfo =
{
    AETABLE_VIDEO_NIGHT,
    90,
    -10,
    {
        {1,3500,30,1024,1024},
        {2,30,30,1024,6144},
        {3,30,10,6144,6144},
        {4,10,10,6144,8196},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECaptureISO100PLineInfo =
{
    AETABLE_CAPTURE_ISO100,
    90,
    0,
    {
        {1,3500,5,1230,1230},
        {2,0,0,0,0},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECaptureISO200PLineInfo =
{
    AETABLE_CAPTURE_ISO200,
    90,
    0,
    {
        {1,3500,2000,1024,1024},
        {2,2000,2000,1024,2460},
        {3,2000,5,2460,2460},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECaptureISO400PLineInfo =
{
    AETABLE_CAPTURE_ISO400,
    90,
    0,
    {
        {1,3500,2000,1024,1024},
        {2,2000,2000,1024,4920},
        {3,2000,5,4920,4920},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECaptureISO800PLineInfo =
{
    AETABLE_CAPTURE_ISO800,
    90,
    0,
    {
        {1,3500,2000,1024,1024},
        {2,2000,2000,1024,6144},
        {3,2000,5,6144,6144},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAECaptureISO1600PLineInfo =
{
    AETABLE_CAPTURE_ISO1600,
    90,
    0,
    {
        {1,3500,2000,1024,1024},
        {2,2000,2000,1024,8196},
        {3,2000,5,8196,8196},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEStrobePLineInfo =
{
    AETABLE_STROBE,
    90,
    0,
    {
        {1,3500,15,1024,1024},
        {2,15,15,1024,4096},
        {3,15,10,4096,4096},
        {4,10,10,4096,30720},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEScene1PLineInfo =
{
    AETABLE_SCENE_INDEX1,
    90,
    -10,
    {
        {1,3500,15,1024,1024},
        {2,15,15,1024,4096},
        {3,15,5,4096,4096},
        {4,5,5,4096,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEScene2PLineInfo =
{
    AETABLE_SCENE_INDEX2,
    90,
    0,
    {
        {1,3500,100,1024,1024},
        {2,100,100,1024,4096},
        {3,100,30,4096,4096},
        {4,30,30,4096,6144},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEScene3PLineInfo =
{
    AETABLE_SCENE_INDEX3,
    90,
    0,
    {
        {1,3500,30,1024,1024},
        {2,30,30,1024,2048},
        {3,30,15,2048,2048},
        {4,15,15,2048,4096},
        {5,15,10,4096,4096},
        {6,10,10,4096,6144},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEScene4PLineInfo =
{
    AETABLE_SCENE_INDEX4,
    90,
    0,
    {
        {1,4,4,1706,1706},
        {2,0,0,0,0},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAEScene5PLineInfo =
{
    AETABLE_SCENE_INDEX5,
    90,
    0,
    {
        {1,3500,20,1024,1024},
        {2,20,15,1024,1024},
        {3,15,15,1024,2048},
        {4,15,12,2048,2048},
        {5,12,12,2048,8192},
        {6,12,10,8192,8192},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static strAEPLineNumInfo g_strAENoScenePLineInfo =
{
    AETABLE_SCENE_MAX,
    90,
    0,
    {
        {1,0,0,0,0},
        {2,0,0,0,0},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};
static strAEPLineInfomation g_strAEPlineInfo =
{
    MTRUE,   // FALSE mean the sampling
    {
    // PLINE Info
        g_strAEPreviewAutoPLineInfo,
        g_strAECaptureAutoPLineInfo,
        g_strAEVideoAutoPLineInfo,
        g_strAEVideo1AutoPLineInfo,
        g_strAEVideo2AutoPLineInfo,
        g_strAECustom1AutoPLineInfo,
        g_strAECustom2AutoPLineInfo,
        g_strAECustom3AutoPLineInfo,
        g_strAECustom4AutoPLineInfo,
        g_strAECustom5AutoPLineInfo,
        g_strAEVideoNightPLineInfo,
        g_strAECaptureISO100PLineInfo,
        g_strAECaptureISO200PLineInfo,
        g_strAECaptureISO400PLineInfo,
        g_strAECaptureISO800PLineInfo,
        g_strAECaptureISO1600PLineInfo,
        g_strAEStrobePLineInfo,
        g_strAEScene1PLineInfo,
        g_strAEScene2PLineInfo,
        g_strAEScene3PLineInfo,
        g_strAEScene4PLineInfo,
        g_strAEScene5PLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
},
};

static strAEPLineGainList g_strAEGainList =
{
    0,
    {
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
    }
};

static AE_PLINETABLE_T g_PlineTableMapping =
{
    g_AEScenePLineMapping,
    g_strAEPlineTable,
    g_strAEPlineInfo,
    g_strAEGainList
};
#endif
#if 0 //Save the P-line info to file for debug
MinGain,1024
MaxGain,8192
MiniISOGain,100
GainStepUnitInTotalRange,32
PreviewExposureLineUnit,42000
PreviewMaxFrameRate,20
VideoExposureLineUnit,42000
VideoMaxFrameRate,20
VideoToPreviewSensitivityRatio,1024
CaptureExposureLineUnit,42000
CaptureMaxFrameRate,20
CaptureToPreviewSensitivityRatio,1024
Video1ExposureLineUnit,42000
Video1MaxFrameRate,20
Video1ToPreviewSensitivityRatio,1024
Video2ExposureLineUnit,42000
Video2MaxFrameRate,20
Video2ToPreviewSensitivityRatio,1024
Custom1ExposureLineUnit,42000
Custom1MaxFrameRate,20
Custom1ToPreviewSensitivityRatio,1024
Custom2ExposureLineUnit,42000
Custom2MaxFrameRate,20
Custom2ToPreviewSensitivityRatio,1024
Custom3ExposureLineUnit,42000
Custom3MaxFrameRate,20
Custom3ToPreviewSensitivityRatio,1024
Custom4ExposureLineUnit,42000
Custom4MaxFrameRate,20
Custom4ToPreviewSensitivityRatio,1024
Custom5ExposureLineUnit,42000
Custom5MaxFrameRate,20
Custom5ToPreviewSensitivityRatio,1024
FocusLength,350
Fno,28

// Preview table -- Use preview sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_RPEVIEW_AUTO
90,-10
1,3500,20,1024,1024
2,20,15,1024,1024
3,15,15,1024,2048
4,15,10,2048,2048
5,10,10,2048,8192
6,10,8,8192,8192
AETABLE_END

// Capture table -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_AUTO
90,0
1,3500,20,1024,1024
2,20,12,1024,1024
3,12,12,1024,2048
4,12,10,2048,2048
5,10,10,2048,8192
6,10,8,8192,8192
AETABLE_END

// Video table -- Use video sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO_AUTO
90,0
1,3500,20,1024,1024
2,20,20,1024,2048
3,20,8,2048,2048
4,8,8,2048,6144
AETABLE_END

// Video1 table -- Use video1 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO1_AUTO
90,0
1,3500,60,1195,1195
2,60,60,1195,6144
AETABLE_END

// Video2 table -- Use video2 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO2_AUTO
90,0
1,3500,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,6144
AETABLE_END

// Custom1 table -- Use custom1 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM1_AUTO
90,0
1,3500,60,1024,1024
2,60,60,1024,3072
3,60,30,3072,3072
4,30,30,3072,6144
AETABLE_END

// Custom2 table -- Use custom2 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM2_AUTO
90,0
1,3500,60,1024,1024
2,60,60,1024,3072
3,60,30,3072,3072
4,30,30,3072,6144
AETABLE_END

// Custom3 table -- Use custom3 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM3_AUTO
90,0
1,3500,60,1024,1024
2,60,60,1024,3072
3,60,30,3072,3072
4,30,30,3072,6144
AETABLE_END

// Custom4 table -- Use custom4 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM4_AUTO
90,0
1,3500,60,1024,1024
2,60,60,1024,3072
3,60,30,3072,3072
4,30,30,3072,6144
AETABLE_END

// Custom5 table -- Use custom5 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM5_AUTO
90,0
1,3500,60,1024,1024
2,60,60,1024,3072
3,60,30,3072,3072
4,30,30,3072,6144
AETABLE_END

// Video Night table -- Use video sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO_NIGHT
90,-10
1,3500,30,1024,1024
2,30,30,1024,6144
3,30,10,6144,6144
4,10,10,6144,8196
AETABLE_END

// Capture ISO100 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO100
90,0
1,3500,5,1230,1230
AETABLE_END

// Capture ISO200 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO200
90,0
1,3500,2000,1024,1024
2,2000,2000,1024,2460
3,2000,5,2460,2460
AETABLE_END

// Capture ISO400 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO400
90,0
1,3500,2000,1024,1024
2,2000,2000,1024,4920
3,2000,5,4920,4920
AETABLE_END

// Capture ISO800 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO800
90,0
1,3500,2000,1024,1024
2,2000,2000,1024,6144
3,2000,5,6144,6144
AETABLE_END

// Capture ISO1600 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO1600
90,0
1,3500,2000,1024,1024
2,2000,2000,1024,8196
3,2000,5,8196,8196
AETABLE_END

// Strobe -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_STROBE
90,0
1,3500,15,1024,1024
2,15,15,1024,4096
3,15,10,4096,4096
4,10,10,4096,30720
AETABLE_END

// Table1 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX1
90,-10
1,3500,15,1024,1024
2,15,15,1024,4096
3,15,5,4096,4096
4,5,5,4096,6144
AETABLE_END

// Table2 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX2
90,0
1,3500,100,1024,1024
2,100,100,1024,4096
3,100,30,4096,4096
4,30,30,4096,6144
AETABLE_END

// Table3 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX3
90,0
1,3500,30,1024,1024
2,30,30,1024,2048
3,30,15,2048,2048
4,15,15,2048,4096
5,15,10,4096,4096
6,10,10,4096,6144
AETABLE_END

// Table4 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX4
90,0
1,4,4,1706,1706
AETABLE_END

// Table5 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX5
90,0
1,3500,20,1024,1024
2,20,15,1024,1024
3,15,15,1024,2048
4,15,12,2048,2048
5,12,12,2048,8192
6,12,10,8192,8192
AETABLE_END

AE_SCENE_AUTO,AETABLE_RPEVIEW_AUTO,AETABLE_CAPTURE_AUTO,AETABLE_VIDEO_AUTO,AETABLE_VIDEO1_AUTO,AETABLE_VIDEO2_AUTO,AETABLE_CUSTOM1_AUTO,AETABLE_CUSTOM2_AUTO,AETABLE_CUSTOM3_AUTO,AETABLE_CUSTOM4_AUTO,AETABLE_CUSTOM5_AUTO,AETABLE_SCENE_INDEX5
AE_SCENE_NIGHT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
AE_SCENE_ACTION, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
AE_SCENE_BEACH, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
AE_SCENE_CANDLELIGHT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
AE_SCENE_FIREWORKS, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX4, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX4
AE_SCENE_LANDSCAPE, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
AE_SCENE_PORTRAIT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
AE_SCENE_NIGHT_PORTRAIT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
AE_SCENE_PARTY, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
AE_SCENE_SNOW, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
AE_SCENE_SPORTS, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
AE_SCENE_STEADYPHOTO, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
AE_SCENE_SUNSET, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
AE_SCENE_THEATRE, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
AE_SCENE_ISO_ANTI_SHAKE, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
AE_SCENE_ISO100, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO100, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO100
AE_SCENE_ISO200, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO200, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO200
AE_SCENE_ISO400, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO400, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO400
AE_SCENE_ISO800, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO800, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO800
AE_SCENE_ISO1600, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO1600, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO1600
#endif
