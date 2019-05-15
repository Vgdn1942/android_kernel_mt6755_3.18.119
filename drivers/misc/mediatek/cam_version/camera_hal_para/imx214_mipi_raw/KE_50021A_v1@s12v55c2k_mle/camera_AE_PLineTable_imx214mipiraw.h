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

#ifndef _CAMERA_AE_PLINETABLE_IMX214MIPIRAW_H
#define _CAMERA_AE_PLINETABLE_IMX214MIPIRAW_H

#include "camera_custom_AEPlinetable.h"
static strEvPline sPreviewPLineTable_60Hz =
{
{
    {188,1270,1032, 0, 0, 0},  //TV = 12.38(12 lines)  AV=1.70  SV=3.72  BV=10.35
    {204,1198,1032, 0, 0, 0},  //TV = 12.26(13 lines)  AV=1.70  SV=3.64  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(14 lines)  AV=1.70  SV=3.64  BV=10.21
    {235,1198,1032, 0, 0, 0},  //TV = 12.06(15 lines)  AV=1.70  SV=3.64  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(16 lines)  AV=1.70  SV=3.64  BV=10.02
    {267,1219,1024, 0, 0, 0},  //TV = 11.87(17 lines)  AV=1.70  SV=3.65  BV=9.91
    {282,1239,1024, 0, 0, 0},  //TV = 11.79(18 lines)  AV=1.70  SV=3.68  BV=9.81
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(20 lines)  AV=1.70  SV=3.63  BV=9.71
    {329,1219,1024, 0, 0, 0},  //TV = 11.57(21 lines)  AV=1.70  SV=3.65  BV=9.61
    {360,1198,1024, 0, 0, 0},  //TV = 11.44(23 lines)  AV=1.70  SV=3.63  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(24 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(26 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(28 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(30 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(32 lines)  AV=1.70  SV=3.65  BV=9.01
    {533,1219,1032, 0, 0, 0},  //TV = 10.87(34 lines)  AV=1.70  SV=3.66  BV=8.91
    {580,1198,1032, 0, 0, 0},  //TV = 10.75(37 lines)  AV=1.70  SV=3.64  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(40 lines)  AV=1.70  SV=3.63  BV=8.71
    {658,1219,1024, 0, 0, 0},  //TV = 10.57(42 lines)  AV=1.70  SV=3.65  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(46 lines)  AV=1.70  SV=3.63  BV=8.51
    {767,1198,1032, 0, 0, 0},  //TV = 10.35(49 lines)  AV=1.70  SV=3.64  BV=8.41
    {830,1198,1024, 0, 0, 0},  //TV = 10.23(53 lines)  AV=1.70  SV=3.63  BV=8.30
    {877,1198,1032, 0, 0, 0},  //TV = 10.16(56 lines)  AV=1.70  SV=3.64  BV=8.21
    {955,1198,1024, 0, 0, 0},  //TV = 10.03(61 lines)  AV=1.70  SV=3.63  BV=8.10
    {1018,1198,1032, 0, 0, 0},  //TV = 9.94(65 lines)  AV=1.70  SV=3.64  BV=8.00
    {1080,1198,1032, 0, 0, 0},  //TV = 9.85(69 lines)  AV=1.70  SV=3.64  BV=7.91
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(74 lines)  AV=1.70  SV=3.64  BV=7.81
    {1237,1198,1032, 0, 0, 0},  //TV = 9.66(79 lines)  AV=1.70  SV=3.64  BV=7.72
    {1331,1198,1032, 0, 0, 0},  //TV = 9.55(85 lines)  AV=1.70  SV=3.64  BV=7.61
    {1440,1198,1024, 0, 0, 0},  //TV = 9.44(92 lines)  AV=1.70  SV=3.63  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(98 lines)  AV=1.70  SV=3.64  BV=7.41
    {1644,1198,1032, 0, 0, 0},  //TV = 9.25(105 lines)  AV=1.70  SV=3.64  BV=7.31
    {1769,1198,1032, 0, 0, 0},  //TV = 9.14(113 lines)  AV=1.70  SV=3.64  BV=7.20
    {1910,1198,1024, 0, 0, 0},  //TV = 9.03(122 lines)  AV=1.70  SV=3.63  BV=7.10
    {2019,1198,1032, 0, 0, 0},  //TV = 8.95(129 lines)  AV=1.70  SV=3.64  BV=7.01
    {2192,1198,1024, 0, 0, 0},  //TV = 8.83(140 lines)  AV=1.70  SV=3.63  BV=6.90
    {2348,1198,1024, 0, 0, 0},  //TV = 8.73(150 lines)  AV=1.70  SV=3.63  BV=6.80
    {2489,1198,1032, 0, 0, 0},  //TV = 8.65(159 lines)  AV=1.70  SV=3.64  BV=6.71
    {2677,1198,1032, 0, 0, 0},  //TV = 8.55(171 lines)  AV=1.70  SV=3.64  BV=6.60
    {2865,1198,1032, 0, 0, 0},  //TV = 8.45(183 lines)  AV=1.70  SV=3.64  BV=6.51
    {3068,1198,1032, 0, 0, 0},  //TV = 8.35(196 lines)  AV=1.70  SV=3.64  BV=6.41
    {3303,1198,1032, 0, 0, 0},  //TV = 8.24(211 lines)  AV=1.70  SV=3.64  BV=6.30
    {3538,1198,1032, 0, 0, 0},  //TV = 8.14(226 lines)  AV=1.70  SV=3.64  BV=6.20
    {3788,1198,1032, 0, 0, 0},  //TV = 8.04(242 lines)  AV=1.70  SV=3.64  BV=6.10
    {4054,1198,1032, 0, 0, 0},  //TV = 7.95(259 lines)  AV=1.70  SV=3.64  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(280 lines)  AV=1.70  SV=3.63  BV=5.90
    {4680,1198,1024, 0, 0, 0},  //TV = 7.74(299 lines)  AV=1.70  SV=3.63  BV=5.81
    {5024,1198,1024, 0, 0, 0},  //TV = 7.64(321 lines)  AV=1.70  SV=3.63  BV=5.71
    {5369,1198,1024, 0, 0, 0},  //TV = 7.54(343 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(368 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(394 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(422 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(452 lines)  AV=1.70  SV=3.63  BV=5.21
    {7623,1198,1024, 0, 0, 0},  //TV = 7.04(487 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(522 lines)  AV=1.70  SV=3.63  BV=5.00
    {8327,1249,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=3.69  BV=4.92
    {8327,1341,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=3.80  BV=4.80
    {8327,1444,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=3.90  BV=4.71
    {8327,1536,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.00  BV=4.61
    {8327,1649,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.10  BV=4.50
    {8327,1761,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.19  BV=4.41
    {8327,1884,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.29  BV=4.31
    {8327,2028,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.39  BV=4.22
    {8327,2181,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.49  BV=4.11
    {8327,2324,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.59  BV=4.01
    {16669,1249,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.69  BV=3.92
    {16669,1341,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.79  BV=3.81
    {16669,1444,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.90  BV=3.71
    {16669,1536,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.99  BV=3.62
    {16669,1649,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.09  BV=3.51
    {16669,1761,1032, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.19  BV=3.41
    {24995,1270,1024, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=3.71  BV=3.31
    {24995,1341,1032, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=3.80  BV=3.22
    {24995,1454,1024, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=3.91  BV=3.11
    {24995,1567,1024, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=4.01  BV=3.00
    {33337,1249,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=3.69  BV=2.92
    {33337,1341,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=3.79  BV=2.81
    {33337,1454,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=3.91  BV=2.70
    {33337,1536,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=3.99  BV=2.62
    {33337,1649,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=4.09  BV=2.51
    {33337,1761,1032, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=4.19  BV=2.41
    {33337,1905,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=4.30  BV=2.31
    {33337,2028,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=4.39  BV=2.22
    {33337,2181,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=4.49  BV=2.11
    {33337,2345,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=4.60  BV=2.01
    {33337,2519,1024, 0, 0, 0},  //TV = 4.91(2130 lines)  AV=1.70  SV=4.70  BV=1.90
    {41663,2150,1024, 0, 0, 0},  //TV = 4.59(2662 lines)  AV=1.70  SV=4.47  BV=1.81
    {41663,2304,1024, 0, 0, 0},  //TV = 4.59(2662 lines)  AV=1.70  SV=4.57  BV=1.71
    {49990,2048,1032, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=4.41  BV=1.61
    {49990,2202,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=4.51  BV=1.51
    {49990,2365,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=4.61  BV=1.41
    {49990,2519,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=4.70  BV=1.32
    {49990,2703,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=4.80  BV=1.22
    {49990,2908,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=4.91  BV=1.11
    {49990,3123,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=5.01  BV=1.01
    {49990,3318,1032, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=5.11  BV=0.91
    {49990,3594,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=5.21  BV=0.81
    {49990,3850,1024, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=5.31  BV=0.71
    {49990,4096,1032, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=5.41  BV=0.61
    {49990,4372,1032, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=5.51  BV=0.51
    {49990,4680,1032, 0, 0, 0},  //TV = 4.32(3194 lines)  AV=1.70  SV=5.60  BV=0.41
    {58332,4301,1032, 0, 0, 0},  //TV = 4.10(3727 lines)  AV=1.70  SV=5.48  BV=0.31
    {58332,4598,1032, 0, 0, 0},  //TV = 4.10(3727 lines)  AV=1.70  SV=5.58  BV=0.22
    {66658,4372,1024, 0, 0, 0},  //TV = 3.91(4259 lines)  AV=1.70  SV=5.49  BV=0.11
    {66658,4680,1032, 0, 0, 0},  //TV = 3.91(4259 lines)  AV=1.70  SV=5.60  BV=-0.00
    {66658,5038,1024, 0, 0, 0},  //TV = 3.91(4259 lines)  AV=1.70  SV=5.70  BV=-0.10
    {66658,5345,1032, 0, 0, 0},  //TV = 3.91(4259 lines)  AV=1.70  SV=5.80  BV=-0.19
    {66658,5827,1024, 0, 0, 0},  //TV = 3.91(4259 lines)  AV=1.70  SV=5.91  BV=-0.31
    {66658,6093,1040, 0, 0, 0},  //TV = 3.91(4259 lines)  AV=1.70  SV=6.00  BV=-0.39
    {66658,6554,1040, 0, 0, 0},  //TV = 3.91(4259 lines)  AV=1.70  SV=6.10  BV=-0.50
    {75000,6246,1040, 0, 0, 0},  //TV = 3.74(4792 lines)  AV=1.70  SV=6.03  BV=-0.60
    {75000,6717,1032, 0, 0, 0},  //TV = 3.74(4792 lines)  AV=1.70  SV=6.13  BV=-0.69
    {83326,6554,1024, 0, 0, 0},  //TV = 3.59(5324 lines)  AV=1.70  SV=6.08  BV=-0.80
    {91669,6390,1024, 0, 0, 0},  //TV = 3.45(5857 lines)  AV=1.70  SV=6.04  BV=-0.90
    {99995,6246,1032, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.02  BV=-1.00
    {99995,6717,1024, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.11  BV=-1.10
    {99995,7086,1040, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.21  BV=-1.20
    {99995,7711,1024, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.31  BV=-1.30
    {99995,8192,1032, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.41  BV=-1.39
    {108321,8192,1024, 0, 0, 0},  //TV = 3.21(6921 lines)  AV=1.70  SV=6.40  BV=-1.50
    {108321,8192,1096, 0, 0, 0},  //TV = 3.21(6921 lines)  AV=1.70  SV=6.50  BV=-1.60
    {116663,8192,1096, 0, 0, 0},  //TV = 3.10(7454 lines)  AV=1.70  SV=6.50  BV=-1.70
    {133332,8192,1024, 0, 0, 0},  //TV = 2.91(8519 lines)  AV=1.70  SV=6.40  BV=-1.80
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {188,1270,1032, 0, 0, 0},  //TV = 12.38(12 lines)  AV=1.70  SV=3.72  BV=10.35
    {204,1198,1032, 0, 0, 0},  //TV = 12.26(13 lines)  AV=1.70  SV=3.64  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(14 lines)  AV=1.70  SV=3.64  BV=10.21
    {235,1198,1032, 0, 0, 0},  //TV = 12.06(15 lines)  AV=1.70  SV=3.64  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(16 lines)  AV=1.70  SV=3.64  BV=10.02
    {267,1219,1024, 0, 0, 0},  //TV = 11.87(17 lines)  AV=1.70  SV=3.65  BV=9.91
    {282,1239,1024, 0, 0, 0},  //TV = 11.79(18 lines)  AV=1.70  SV=3.68  BV=9.81
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(20 lines)  AV=1.70  SV=3.63  BV=9.71
    {329,1219,1024, 0, 0, 0},  //TV = 11.57(21 lines)  AV=1.70  SV=3.65  BV=9.61
    {360,1198,1024, 0, 0, 0},  //TV = 11.44(23 lines)  AV=1.70  SV=3.63  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(24 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(26 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(28 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(30 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(32 lines)  AV=1.70  SV=3.65  BV=9.01
    {533,1219,1032, 0, 0, 0},  //TV = 10.87(34 lines)  AV=1.70  SV=3.66  BV=8.91
    {580,1198,1032, 0, 0, 0},  //TV = 10.75(37 lines)  AV=1.70  SV=3.64  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(40 lines)  AV=1.70  SV=3.63  BV=8.71
    {658,1219,1024, 0, 0, 0},  //TV = 10.57(42 lines)  AV=1.70  SV=3.65  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(46 lines)  AV=1.70  SV=3.63  BV=8.51
    {767,1198,1032, 0, 0, 0},  //TV = 10.35(49 lines)  AV=1.70  SV=3.64  BV=8.41
    {830,1198,1024, 0, 0, 0},  //TV = 10.23(53 lines)  AV=1.70  SV=3.63  BV=8.30
    {877,1198,1032, 0, 0, 0},  //TV = 10.16(56 lines)  AV=1.70  SV=3.64  BV=8.21
    {955,1198,1024, 0, 0, 0},  //TV = 10.03(61 lines)  AV=1.70  SV=3.63  BV=8.10
    {1018,1198,1032, 0, 0, 0},  //TV = 9.94(65 lines)  AV=1.70  SV=3.64  BV=8.00
    {1080,1198,1032, 0, 0, 0},  //TV = 9.85(69 lines)  AV=1.70  SV=3.64  BV=7.91
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(74 lines)  AV=1.70  SV=3.64  BV=7.81
    {1237,1198,1032, 0, 0, 0},  //TV = 9.66(79 lines)  AV=1.70  SV=3.64  BV=7.72
    {1331,1198,1032, 0, 0, 0},  //TV = 9.55(85 lines)  AV=1.70  SV=3.64  BV=7.61
    {1440,1198,1024, 0, 0, 0},  //TV = 9.44(92 lines)  AV=1.70  SV=3.63  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(98 lines)  AV=1.70  SV=3.64  BV=7.41
    {1644,1198,1032, 0, 0, 0},  //TV = 9.25(105 lines)  AV=1.70  SV=3.64  BV=7.31
    {1769,1198,1032, 0, 0, 0},  //TV = 9.14(113 lines)  AV=1.70  SV=3.64  BV=7.20
    {1910,1198,1024, 0, 0, 0},  //TV = 9.03(122 lines)  AV=1.70  SV=3.63  BV=7.10
    {2019,1198,1032, 0, 0, 0},  //TV = 8.95(129 lines)  AV=1.70  SV=3.64  BV=7.01
    {2192,1198,1024, 0, 0, 0},  //TV = 8.83(140 lines)  AV=1.70  SV=3.63  BV=6.90
    {2348,1198,1024, 0, 0, 0},  //TV = 8.73(150 lines)  AV=1.70  SV=3.63  BV=6.80
    {2489,1198,1032, 0, 0, 0},  //TV = 8.65(159 lines)  AV=1.70  SV=3.64  BV=6.71
    {2677,1198,1032, 0, 0, 0},  //TV = 8.55(171 lines)  AV=1.70  SV=3.64  BV=6.60
    {2865,1198,1032, 0, 0, 0},  //TV = 8.45(183 lines)  AV=1.70  SV=3.64  BV=6.51
    {3068,1198,1032, 0, 0, 0},  //TV = 8.35(196 lines)  AV=1.70  SV=3.64  BV=6.41
    {3303,1198,1032, 0, 0, 0},  //TV = 8.24(211 lines)  AV=1.70  SV=3.64  BV=6.30
    {3538,1198,1032, 0, 0, 0},  //TV = 8.14(226 lines)  AV=1.70  SV=3.64  BV=6.20
    {3788,1198,1032, 0, 0, 0},  //TV = 8.04(242 lines)  AV=1.70  SV=3.64  BV=6.10
    {4054,1198,1032, 0, 0, 0},  //TV = 7.95(259 lines)  AV=1.70  SV=3.64  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(280 lines)  AV=1.70  SV=3.63  BV=5.90
    {4680,1198,1024, 0, 0, 0},  //TV = 7.74(299 lines)  AV=1.70  SV=3.63  BV=5.81
    {5024,1198,1024, 0, 0, 0},  //TV = 7.64(321 lines)  AV=1.70  SV=3.63  BV=5.71
    {5369,1198,1024, 0, 0, 0},  //TV = 7.54(343 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(368 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(394 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(422 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(452 lines)  AV=1.70  SV=3.63  BV=5.21
    {7623,1198,1024, 0, 0, 0},  //TV = 7.04(487 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(522 lines)  AV=1.70  SV=3.63  BV=5.00
    {8749,1198,1024, 0, 0, 0},  //TV = 6.84(559 lines)  AV=1.70  SV=3.63  BV=4.91
    {9375,1198,1024, 0, 0, 0},  //TV = 6.74(599 lines)  AV=1.70  SV=3.63  BV=4.81
    {10002,1198,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.64  BV=4.70
    {10002,1280,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.72  BV=4.62
    {10002,1382,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.83  BV=4.51
    {10002,1475,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.93  BV=4.41
    {10002,1567,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.03  BV=4.31
    {10002,1700,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.13  BV=4.21
    {10002,1823,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.23  BV=4.11
    {10002,1925,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.32  BV=4.02
    {10002,2099,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.44  BV=3.90
    {10002,2222,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=4.14  BV=3.20
    {30004,1198,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=3.64  BV=3.12
    {30004,1300,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=3.74  BV=3.01
    {30004,1393,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=3.84  BV=2.91
    {30004,1495,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=3.95  BV=2.81
    {30004,1608,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.05  BV=2.70
    {30004,1720,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.15  BV=2.61
    {30004,1843,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.25  BV=2.51
    {30004,1966,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.35  BV=2.40
    {30004,2109,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.44  BV=2.31
    {30004,2263,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.54  BV=2.21
    {30004,2427,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.65  BV=2.11
    {30004,2591,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=4.75  BV=2.00
    {40005,2099,1024, 0, 0, 0},  //TV = 4.64(2556 lines)  AV=1.70  SV=4.44  BV=1.90
    {40005,2243,1024, 0, 0, 0},  //TV = 4.64(2556 lines)  AV=1.70  SV=4.53  BV=1.81
    {40005,2406,1024, 0, 0, 0},  //TV = 4.64(2556 lines)  AV=1.70  SV=4.63  BV=1.71
    {50006,2048,1032, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=4.41  BV=1.61
    {50006,2202,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=4.51  BV=1.51
    {50006,2365,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=4.61  BV=1.41
    {50006,2519,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=4.70  BV=1.32
    {50006,2734,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=4.82  BV=1.20
    {50006,2908,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=4.91  BV=1.11
    {50006,3123,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=5.01  BV=1.01
    {50006,3318,1032, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=5.11  BV=0.91
    {50006,3543,1032, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=5.20  BV=0.82
    {50006,3850,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=5.31  BV=0.71
    {50006,4096,1024, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=5.40  BV=0.62
    {50006,4372,1032, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=5.51  BV=0.51
    {50006,4680,1032, 0, 0, 0},  //TV = 4.32(3195 lines)  AV=1.70  SV=5.60  BV=0.41
    {60007,4229,1024, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=5.45  BV=0.31
    {60007,4516,1024, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=5.54  BV=0.21
    {60007,4854,1024, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=5.65  BV=0.11
    {60007,5243,1024, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=5.76  BV=-0.00
    {60007,5581,1024, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=5.85  BV=-0.09
    {60007,5960,1032, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=5.95  BV=-0.20
    {60007,6390,1032, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=6.05  BV=-0.30
    {60007,6902,1024, 0, 0, 0},  //TV = 4.06(3834 lines)  AV=1.70  SV=6.15  BV=-0.40
    {69992,6246,1040, 0, 0, 0},  //TV = 3.84(4472 lines)  AV=1.70  SV=6.03  BV=-0.50
    {69992,6717,1032, 0, 0, 0},  //TV = 3.84(4472 lines)  AV=1.70  SV=6.13  BV=-0.59
    {79993,6390,1024, 0, 0, 0},  //TV = 3.64(5111 lines)  AV=1.70  SV=6.04  BV=-0.70
    {79993,6717,1040, 0, 0, 0},  //TV = 3.64(5111 lines)  AV=1.70  SV=6.14  BV=-0.80
    {89994,6390,1040, 0, 0, 0},  //TV = 3.47(5750 lines)  AV=1.70  SV=6.06  BV=-0.89
    {99995,6246,1032, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.02  BV=-1.00
    {99995,6717,1024, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.11  BV=-1.10
    {99995,7086,1040, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.21  BV=-1.20
    {99995,7711,1024, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.31  BV=-1.30
    {99995,8192,1032, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.41  BV=-1.39
    {99995,8192,1112, 0, 0, 0},  //TV = 3.32(6389 lines)  AV=1.70  SV=6.52  BV=-1.50
    {109996,8192,1080, 0, 0, 0},  //TV = 3.18(7028 lines)  AV=1.70  SV=6.48  BV=-1.60
    {119997,8192,1064, 0, 0, 0},  //TV = 3.06(7667 lines)  AV=1.70  SV=6.46  BV=-1.70
    {129998,8192,1048, 0, 0, 0},  //TV = 2.94(8306 lines)  AV=1.70  SV=6.43  BV=-1.79
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_RPEVIEW_AUTO,    //eAETableID
    123,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    104,    //i4MaxBV
    -18,    //i4MinBV
    90,    //i4EffectiveMaxBV
    -10,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sPreviewPLineTable_60Hz,
    sPreviewPLineTable_50Hz,
    NULL,
};
static strEvPline sCapturePLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33327,1249,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.69  BV=2.92
    {33327,1341,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.80  BV=2.80
    {33327,1444,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.90  BV=2.71
    {41663,1239,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.68  BV=2.61
    {41663,1311,1032, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.77  BV=2.51
    {41663,1423,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.88  BV=2.41
    {50001,1270,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.71  BV=2.31
    {50001,1362,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.81  BV=2.21
    {58327,1239,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=3.68  BV=2.12
    {58327,1341,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=3.79  BV=2.01
    {66663,1249,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=3.70  BV=1.90
    {75001,1198,1024, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=3.63  BV=1.81
    {75001,1280,1024, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=3.72  BV=1.71
    {83326,1239,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=3.68  BV=1.61
    {91663,1198,1032, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=3.64  BV=1.51
    {91663,1280,1032, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=3.73  BV=1.41
    {100001,1270,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.71  BV=1.31
    {100001,1341,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.80  BV=1.22
    {100001,1454,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.91  BV=1.11
    {100001,1567,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.01  BV=1.00
    {100001,1679,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.11  BV=0.90
    {100001,1792,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.21  BV=0.81
    {100001,1925,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.31  BV=0.71
    {100001,2068,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.41  BV=0.60
    {100001,2202,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.51  BV=0.51
    {100001,2365,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.61  BV=0.41
    {100001,2519,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.71  BV=0.31
    {100001,2703,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.81  BV=0.21
    {100001,2908,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.91  BV=0.11
    {100001,3123,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.01  BV=0.01
    {100001,3359,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.11  BV=-0.10
    {100001,3594,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.22  BV=-0.21
    {100001,3850,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.31  BV=-0.29
    {100001,4096,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.41  BV=-0.39
    {108326,4096,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=5.40  BV=-0.50
    {108326,4372,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=5.49  BV=-0.59
    {116664,4372,1024, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=5.49  BV=-0.70
    {133326,4096,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=5.40  BV=-0.80
    {141663,4096,1032, 0, 0, 0},  //TV = 2.82(13577 lines)  AV=1.70  SV=5.41  BV=-0.90
    {149989,4157,1032, 0, 0, 0},  //TV = 2.74(14375 lines)  AV=1.70  SV=5.43  BV=-1.00
    {158326,4229,1032, 0, 0, 0},  //TV = 2.66(15174 lines)  AV=1.70  SV=5.46  BV=-1.10
    {166663,4301,1032, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=5.48  BV=-1.20
    {166663,4598,1032, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=5.58  BV=-1.30
    {166663,4946,1032, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=5.68  BV=-1.40
    {166663,5243,1040, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=5.78  BV=-1.50
    {166663,5704,1024, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=5.88  BV=-1.60
    {166663,6093,1024, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=5.97  BV=-1.69
    {166663,6554,1032, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=6.09  BV=-1.81
    {166663,6902,1048, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=6.19  BV=-1.91
    {166663,7485,1032, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=6.28  BV=-2.00
    {166663,7946,1040, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=6.38  BV=-2.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {40005,1198,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.64  BV=2.70
    {40005,1280,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.72  BV=2.62
    {40005,1382,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.83  BV=2.51
    {40005,1475,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.94  BV=2.40
    {50000,1270,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.71  BV=2.31
    {50000,1362,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.81  BV=2.21
    {59996,1198,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.64  BV=2.12
    {59996,1300,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.74  BV=2.01
    {70003,1198,1024, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=3.63  BV=1.91
    {70003,1270,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=3.72  BV=1.81
    {79998,1198,1032, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=3.64  BV=1.70
    {79998,1280,1032, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=3.73  BV=1.61
    {90005,1219,1032, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=3.66  BV=1.51
    {90005,1311,1024, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=3.76  BV=1.41
    {100000,1270,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.71  BV=1.31
    {100000,1341,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.80  BV=1.22
    {100000,1454,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.91  BV=1.11
    {100000,1567,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.01  BV=1.00
    {100000,1679,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.11  BV=0.90
    {100000,1792,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.21  BV=0.81
    {100000,1925,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.31  BV=0.71
    {100000,2068,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.41  BV=0.60
    {100000,2202,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.51  BV=0.51
    {100000,2365,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.61  BV=0.41
    {100000,2550,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.72  BV=0.30
    {100000,2703,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.81  BV=0.21
    {100000,2908,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.91  BV=0.11
    {100000,3123,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.01  BV=0.01
    {100000,3359,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.11  BV=-0.10
    {100000,3594,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.22  BV=-0.21
    {100000,3850,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.31  BV=-0.29
    {100000,4096,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.41  BV=-0.39
    {100000,4444,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.52  BV=-0.50
    {109996,4301,1032, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=5.48  BV=-0.60
    {120002,4229,1032, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=5.46  BV=-0.70
    {129998,4157,1032, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=5.43  BV=-0.79
    {140004,4157,1032, 0, 0, 0},  //TV = 2.84(13418 lines)  AV=1.70  SV=5.43  BV=-0.90
    {150000,4157,1032, 0, 0, 0},  //TV = 2.74(14376 lines)  AV=1.70  SV=5.43  BV=-1.00
    {159995,4157,1032, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=5.43  BV=-1.09
    {159995,4516,1024, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=5.54  BV=-1.20
    {159995,4854,1024, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=5.65  BV=-1.31
    {159995,5140,1032, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=5.74  BV=-1.40
    {159995,5458,1040, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=5.84  BV=-1.50
    {159995,5827,1040, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=5.93  BV=-1.59
    {159995,6246,1040, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=6.03  BV=-1.69
    {159995,6717,1040, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=6.14  BV=-1.80
    {159995,7281,1032, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=6.24  BV=-1.90
    {159995,7711,1048, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=6.35  BV=-2.01
    {159995,8192,1056, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=6.44  BV=-2.11
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CAPTURE_AUTO,    //eAETableID
    136,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -21,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sCapturePLineTable_60Hz,
    sCapturePLineTable_50Hz,
    NULL,
};
static strEvPline sVideoPLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1454,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.91  BV=3.70
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.10  BV=3.50
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {16664,1905,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.30  BV=3.31
    {16664,2028,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.39  BV=3.22
    {16664,2181,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.49  BV=3.11
    {16664,2345,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.60  BV=3.01
    {16664,2519,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.70  BV=2.90
    {16664,2673,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.80  BV=2.81
    {16664,2877,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.89  BV=2.71
    {25001,2048,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.41  BV=2.61
    {25001,2202,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.51  BV=2.51
    {25001,2365,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.61  BV=2.41
    {25001,2519,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.71  BV=2.31
    {25001,2703,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.80  BV=2.22
    {33296,2181,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.49  BV=2.11
    {33296,2324,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.59  BV=2.01
    {33296,2519,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.70  BV=1.91
    {33296,2703,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.80  BV=1.80
    {33296,2877,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.89  BV=1.71
    {33296,3082,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.99  BV=1.61
    {33296,3318,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.10  BV=1.51
    {33296,3543,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.19  BV=1.41
    {33296,3799,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.29  BV=1.31
    {33296,4035,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.39  BV=1.21
    {33296,4372,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.49  BV=1.11
    {33296,4680,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.59  BV=1.01
    {33296,5038,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.70  BV=0.91
    {41663,4301,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=5.47  BV=0.81
    {41663,4598,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=5.57  BV=0.71
    {50001,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50001,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50001,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {58327,4301,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.48  BV=0.31
    {58327,4598,1040, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.59  BV=0.21
    {66632,4372,1024, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=5.49  BV=0.11
    {66632,4680,1032, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=5.60  BV=-0.00
    {66632,5038,1024, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=5.70  BV=-0.10
    {66632,5345,1032, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=5.80  BV=-0.19
    {66632,5827,1024, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=5.91  BV=-0.31
    {66632,6093,1040, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=6.00  BV=-0.39
    {66632,6554,1040, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=6.10  BV=-0.50
    {75001,6246,1040, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.03  BV=-0.60
    {75001,6717,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.13  BV=-0.69
    {83326,6554,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=6.08  BV=-0.80
    {91663,6390,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=6.04  BV=-0.90
    {100001,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100001,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100001,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100001,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100001,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {108326,8192,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.40  BV=-1.50
    {108326,8192,1096, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.50  BV=-1.60
    {116664,8192,1096, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=6.50  BV=-1.70
    {133326,8192,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=6.40  BV=-1.80
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {9996,2406,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.63  BV=3.71
    {9996,2570,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.73  BV=3.61
    {9996,2755,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.83  BV=3.51
    {9996,2949,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.93  BV=3.41
    {9996,3154,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.03  BV=3.31
    {9996,3359,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.13  BV=3.21
    {9996,3645,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.23  BV=3.11
    {9996,3912,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.33  BV=3.01
    {20003,2079,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.43  BV=2.91
    {20003,2243,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.53  BV=2.81
    {20003,2406,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.63  BV=2.71
    {20003,2570,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.73  BV=2.61
    {20003,2755,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.83  BV=2.51
    {20003,2949,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.93  BV=2.41
    {29998,2109,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.44  BV=2.31
    {29998,2263,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.54  BV=2.21
    {29998,2427,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.65  BV=2.11
    {29998,2621,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.76  BV=2.00
    {29998,2785,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.84  BV=1.91
    {29998,2980,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.94  BV=1.81
    {29998,3195,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.04  BV=1.71
    {29998,3400,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.14  BV=1.61
    {29998,3645,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.24  BV=1.51
    {29998,3912,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.35  BV=1.41
    {29998,4229,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.45  BV=1.31
    {29998,4516,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.54  BV=1.21
    {29998,4854,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.65  BV=1.11
    {29998,5140,1040, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.75  BV=1.00
    {40005,4157,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=5.43  BV=0.91
    {40005,4444,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=5.53  BV=0.81
    {40005,4762,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=5.63  BV=0.71
    {50000,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50000,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50000,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {59996,4229,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.45  BV=0.31
    {59996,4516,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.54  BV=0.21
    {59996,4854,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.65  BV=0.11
    {59996,5243,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.76  BV=-0.00
    {59996,5581,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.85  BV=-0.09
    {59996,5960,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.95  BV=-0.20
    {59996,6390,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.05  BV=-0.30
    {59996,6902,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.15  BV=-0.40
    {70003,6246,1040, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.03  BV=-0.50
    {70003,6717,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.13  BV=-0.59
    {79998,6390,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.04  BV=-0.70
    {79998,6717,1040, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.14  BV=-0.80
    {90005,6390,1040, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=6.06  BV=-0.89
    {100000,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100000,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100000,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100000,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100000,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {100000,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {109996,8192,1080, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=6.48  BV=-1.60
    {120002,8192,1064, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=6.46  BV=-1.70
    {129998,8192,1048, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=6.43  BV=-1.79
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_VIDEO_AUTO,    //eAETableID
    133,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -18,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sVideoPLineTable_60Hz,
    sVideoPLineTable_50Hz,
    NULL,
};

static strEvPline sVideo1PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1454,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.91  BV=3.70
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.10  BV=3.50
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {16664,1905,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.30  BV=3.31
    {16664,2028,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.39  BV=3.22
    {16664,2181,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.49  BV=3.11
    {16664,2345,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.60  BV=3.01
    {16664,2499,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.69  BV=2.92
    {16664,2703,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.80  BV=2.80
    {16664,2877,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.89  BV=2.71
    {16664,3082,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.99  BV=2.61
    {16664,3277,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.09  BV=2.51
    {16664,3543,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.19  BV=2.41
    {16664,3799,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.29  BV=2.31
    {16664,4035,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.39  BV=2.21
    {16664,4372,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.49  BV=2.11
    {16664,4680,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.59  BV=2.01
    {16664,4946,1040, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.69  BV=1.91
    {16664,5345,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.80  BV=1.81
    {16664,5704,1040, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.90  BV=1.70
    {16664,6093,1040, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.00  BV=1.61
    {16664,6554,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.09  BV=1.51
    {16664,7086,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.19  BV=1.41
    {16664,7485,1040, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.29  BV=1.31
    {16664,7946,1048, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.39  BV=1.21
    {16664,8192,1088, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.49  BV=1.12
    {16664,8192,1168, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.59  BV=1.01
    {16664,8192,1256, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.70  BV=0.91
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {9996,2406,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.63  BV=3.71
    {9996,2570,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.73  BV=3.61
    {9996,2755,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.83  BV=3.51
    {9996,2949,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.93  BV=3.41
    {9996,3154,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.03  BV=3.31
    {9996,3359,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.13  BV=3.21
    {9996,3645,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.23  BV=3.11
    {9996,3912,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.33  BV=3.01
    {9996,4157,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.43  BV=2.91
    {9996,4444,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.53  BV=2.81
    {9996,4762,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.63  BV=2.71
    {9996,5140,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.73  BV=2.61
    {9996,5458,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.83  BV=2.51
    {9996,5827,1040, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.93  BV=2.41
    {9996,6246,1040, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.03  BV=2.31
    {9996,6717,1040, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.14  BV=2.20
    {9996,7281,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.23  BV=2.11
    {9996,7711,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.32  BV=2.02
    {9996,8192,1040, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.42  BV=1.92
    {9996,8192,1120, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.53  BV=1.81
    {9996,8192,1208, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.64  BV=1.70
    {9996,8192,1288, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.73  BV=1.61
    {9996,8192,1384, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.84  BV=1.51
    {9996,8192,1480, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.93  BV=1.41
    {9996,8192,1584, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.03  BV=1.31
    {9996,8192,1696, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.13  BV=1.21
    {9996,8192,1824, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.23  BV=1.11
    {9996,8192,1952, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.33  BV=1.01
    {9996,8192,2088, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.43  BV=0.91
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_VIDEO1_AUTO,    //eAETableID
    106,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    9,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sVideo1PLineTable_60Hz,
    sVideo1PLineTable_50Hz,
    NULL,
};
static strEvPline sVideo2PLineTable_60Hz =
{
{
    {188,1270,1032, 0, 0, 0},  //TV = 12.38(12 lines)  AV=1.70  SV=3.72  BV=10.35
    {204,1198,1032, 0, 0, 0},  //TV = 12.26(13 lines)  AV=1.70  SV=3.64  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(14 lines)  AV=1.70  SV=3.64  BV=10.21
    {235,1198,1032, 0, 0, 0},  //TV = 12.06(15 lines)  AV=1.70  SV=3.64  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(16 lines)  AV=1.70  SV=3.64  BV=10.02
    {267,1219,1024, 0, 0, 0},  //TV = 11.87(17 lines)  AV=1.70  SV=3.65  BV=9.91
    {282,1239,1024, 0, 0, 0},  //TV = 11.79(18 lines)  AV=1.70  SV=3.68  BV=9.81
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(20 lines)  AV=1.70  SV=3.63  BV=9.71
    {329,1219,1024, 0, 0, 0},  //TV = 11.57(21 lines)  AV=1.70  SV=3.65  BV=9.61
    {360,1198,1024, 0, 0, 0},  //TV = 11.44(23 lines)  AV=1.70  SV=3.63  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(24 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(26 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(28 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(30 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(32 lines)  AV=1.70  SV=3.65  BV=9.01
    {533,1219,1032, 0, 0, 0},  //TV = 10.87(34 lines)  AV=1.70  SV=3.66  BV=8.91
    {580,1198,1032, 0, 0, 0},  //TV = 10.75(37 lines)  AV=1.70  SV=3.64  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(40 lines)  AV=1.70  SV=3.63  BV=8.71
    {658,1219,1024, 0, 0, 0},  //TV = 10.57(42 lines)  AV=1.70  SV=3.65  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(46 lines)  AV=1.70  SV=3.63  BV=8.51
    {767,1198,1032, 0, 0, 0},  //TV = 10.35(49 lines)  AV=1.70  SV=3.64  BV=8.41
    {830,1198,1024, 0, 0, 0},  //TV = 10.23(53 lines)  AV=1.70  SV=3.63  BV=8.30
    {877,1198,1032, 0, 0, 0},  //TV = 10.16(56 lines)  AV=1.70  SV=3.64  BV=8.21
    {955,1198,1024, 0, 0, 0},  //TV = 10.03(61 lines)  AV=1.70  SV=3.63  BV=8.10
    {1018,1198,1032, 0, 0, 0},  //TV = 9.94(65 lines)  AV=1.70  SV=3.64  BV=8.00
    {1080,1198,1032, 0, 0, 0},  //TV = 9.85(69 lines)  AV=1.70  SV=3.64  BV=7.91
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(74 lines)  AV=1.70  SV=3.64  BV=7.81
    {1237,1198,1032, 0, 0, 0},  //TV = 9.66(79 lines)  AV=1.70  SV=3.64  BV=7.72
    {1331,1198,1032, 0, 0, 0},  //TV = 9.55(85 lines)  AV=1.70  SV=3.64  BV=7.61
    {1440,1198,1024, 0, 0, 0},  //TV = 9.44(92 lines)  AV=1.70  SV=3.63  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(98 lines)  AV=1.70  SV=3.64  BV=7.41
    {1644,1198,1032, 0, 0, 0},  //TV = 9.25(105 lines)  AV=1.70  SV=3.64  BV=7.31
    {1769,1198,1032, 0, 0, 0},  //TV = 9.14(113 lines)  AV=1.70  SV=3.64  BV=7.20
    {1910,1198,1024, 0, 0, 0},  //TV = 9.03(122 lines)  AV=1.70  SV=3.63  BV=7.10
    {2019,1198,1032, 0, 0, 0},  //TV = 8.95(129 lines)  AV=1.70  SV=3.64  BV=7.01
    {2192,1198,1024, 0, 0, 0},  //TV = 8.83(140 lines)  AV=1.70  SV=3.63  BV=6.90
    {2348,1198,1024, 0, 0, 0},  //TV = 8.73(150 lines)  AV=1.70  SV=3.63  BV=6.80
    {2489,1198,1032, 0, 0, 0},  //TV = 8.65(159 lines)  AV=1.70  SV=3.64  BV=6.71
    {2677,1198,1032, 0, 0, 0},  //TV = 8.55(171 lines)  AV=1.70  SV=3.64  BV=6.60
    {2865,1198,1032, 0, 0, 0},  //TV = 8.45(183 lines)  AV=1.70  SV=3.64  BV=6.51
    {3068,1198,1032, 0, 0, 0},  //TV = 8.35(196 lines)  AV=1.70  SV=3.64  BV=6.41
    {3303,1198,1032, 0, 0, 0},  //TV = 8.24(211 lines)  AV=1.70  SV=3.64  BV=6.30
    {3538,1198,1032, 0, 0, 0},  //TV = 8.14(226 lines)  AV=1.70  SV=3.64  BV=6.20
    {3788,1198,1032, 0, 0, 0},  //TV = 8.04(242 lines)  AV=1.70  SV=3.64  BV=6.10
    {4054,1198,1032, 0, 0, 0},  //TV = 7.95(259 lines)  AV=1.70  SV=3.64  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(280 lines)  AV=1.70  SV=3.63  BV=5.90
    {4680,1198,1024, 0, 0, 0},  //TV = 7.74(299 lines)  AV=1.70  SV=3.63  BV=5.81
    {5024,1198,1024, 0, 0, 0},  //TV = 7.64(321 lines)  AV=1.70  SV=3.63  BV=5.71
    {5369,1198,1024, 0, 0, 0},  //TV = 7.54(343 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(368 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(394 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(422 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(452 lines)  AV=1.70  SV=3.63  BV=5.21
    {7623,1198,1024, 0, 0, 0},  //TV = 7.04(487 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(522 lines)  AV=1.70  SV=3.63  BV=5.00
    {8327,1249,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=3.69  BV=4.92
    {8327,1341,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=3.80  BV=4.80
    {8327,1444,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=3.90  BV=4.71
    {8327,1536,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.00  BV=4.61
    {8327,1649,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.10  BV=4.50
    {8327,1761,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.19  BV=4.41
    {8327,1884,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.29  BV=4.31
    {8327,2028,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.39  BV=4.22
    {8327,2181,1024, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.49  BV=4.11
    {8327,2324,1032, 0, 0, 0},  //TV = 6.91(532 lines)  AV=1.70  SV=4.59  BV=4.01
    {16669,1249,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.69  BV=3.92
    {16669,1341,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.79  BV=3.81
    {16669,1454,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.91  BV=3.70
    {16669,1536,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=3.99  BV=3.62
    {16669,1649,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.09  BV=3.51
    {16669,1761,1032, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.19  BV=3.41
    {16669,1905,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.30  BV=3.31
    {16669,2028,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.39  BV=3.22
    {16669,2181,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.49  BV=3.11
    {16669,2345,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.60  BV=3.01
    {16669,2499,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.69  BV=2.92
    {16669,2673,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.78  BV=2.82
    {16669,2877,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.89  BV=2.71
    {16669,3082,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=4.99  BV=2.61
    {16669,3277,1032, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=5.09  BV=2.51
    {16669,3543,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=5.19  BV=2.41
    {16669,3799,1024, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=5.29  BV=2.31
    {16669,4035,1032, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=5.39  BV=2.21
    {16669,4301,1032, 0, 0, 0},  //TV = 5.91(1065 lines)  AV=1.70  SV=5.48  BV=2.12
    {24995,3123,1024, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=5.01  BV=2.01
    {24995,3359,1024, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=5.11  BV=1.90
    {24995,3594,1024, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=5.21  BV=1.81
    {24995,3850,1024, 0, 0, 0},  //TV = 5.32(1597 lines)  AV=1.70  SV=5.31  BV=1.71
    {33275,3082,1024, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=4.99  BV=1.62
    {33275,3318,1024, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.10  BV=1.51
    {33275,3543,1032, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.20  BV=1.40
    {33275,3799,1024, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.29  BV=1.31
    {33275,4035,1032, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.39  BV=1.22
    {33275,4372,1024, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.49  BV=1.11
    {33275,4680,1024, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.59  BV=1.01
    {33275,5038,1024, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.70  BV=0.91
    {33275,5345,1032, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.80  BV=0.81
    {33275,5704,1040, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=5.90  BV=0.70
    {33275,6093,1040, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.00  BV=0.61
    {33275,6554,1032, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.09  BV=0.52
    {33275,7086,1024, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.19  BV=0.41
    {33275,7485,1040, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.29  BV=0.31
    {33275,7946,1048, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.39  BV=0.22
    {33275,8192,1088, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.49  BV=0.12
    {33275,8192,1184, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.61  BV=-0.00
    {33275,8192,1272, 0, 0, 0},  //TV = 4.91(2126 lines)  AV=1.70  SV=6.71  BV=-0.11
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {188,1270,1032, 0, 0, 0},  //TV = 12.38(12 lines)  AV=1.70  SV=3.72  BV=10.35
    {204,1198,1032, 0, 0, 0},  //TV = 12.26(13 lines)  AV=1.70  SV=3.64  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(14 lines)  AV=1.70  SV=3.64  BV=10.21
    {235,1198,1032, 0, 0, 0},  //TV = 12.06(15 lines)  AV=1.70  SV=3.64  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(16 lines)  AV=1.70  SV=3.64  BV=10.02
    {267,1219,1024, 0, 0, 0},  //TV = 11.87(17 lines)  AV=1.70  SV=3.65  BV=9.91
    {282,1239,1024, 0, 0, 0},  //TV = 11.79(18 lines)  AV=1.70  SV=3.68  BV=9.81
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(20 lines)  AV=1.70  SV=3.63  BV=9.71
    {329,1219,1024, 0, 0, 0},  //TV = 11.57(21 lines)  AV=1.70  SV=3.65  BV=9.61
    {360,1198,1024, 0, 0, 0},  //TV = 11.44(23 lines)  AV=1.70  SV=3.63  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(24 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(26 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(28 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(30 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(32 lines)  AV=1.70  SV=3.65  BV=9.01
    {533,1219,1032, 0, 0, 0},  //TV = 10.87(34 lines)  AV=1.70  SV=3.66  BV=8.91
    {580,1198,1032, 0, 0, 0},  //TV = 10.75(37 lines)  AV=1.70  SV=3.64  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(40 lines)  AV=1.70  SV=3.63  BV=8.71
    {658,1219,1024, 0, 0, 0},  //TV = 10.57(42 lines)  AV=1.70  SV=3.65  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(46 lines)  AV=1.70  SV=3.63  BV=8.51
    {767,1198,1032, 0, 0, 0},  //TV = 10.35(49 lines)  AV=1.70  SV=3.64  BV=8.41
    {830,1198,1024, 0, 0, 0},  //TV = 10.23(53 lines)  AV=1.70  SV=3.63  BV=8.30
    {877,1198,1032, 0, 0, 0},  //TV = 10.16(56 lines)  AV=1.70  SV=3.64  BV=8.21
    {955,1198,1024, 0, 0, 0},  //TV = 10.03(61 lines)  AV=1.70  SV=3.63  BV=8.10
    {1018,1198,1032, 0, 0, 0},  //TV = 9.94(65 lines)  AV=1.70  SV=3.64  BV=8.00
    {1080,1198,1032, 0, 0, 0},  //TV = 9.85(69 lines)  AV=1.70  SV=3.64  BV=7.91
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(74 lines)  AV=1.70  SV=3.64  BV=7.81
    {1237,1198,1032, 0, 0, 0},  //TV = 9.66(79 lines)  AV=1.70  SV=3.64  BV=7.72
    {1331,1198,1032, 0, 0, 0},  //TV = 9.55(85 lines)  AV=1.70  SV=3.64  BV=7.61
    {1440,1198,1024, 0, 0, 0},  //TV = 9.44(92 lines)  AV=1.70  SV=3.63  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(98 lines)  AV=1.70  SV=3.64  BV=7.41
    {1644,1198,1032, 0, 0, 0},  //TV = 9.25(105 lines)  AV=1.70  SV=3.64  BV=7.31
    {1769,1198,1032, 0, 0, 0},  //TV = 9.14(113 lines)  AV=1.70  SV=3.64  BV=7.20
    {1910,1198,1024, 0, 0, 0},  //TV = 9.03(122 lines)  AV=1.70  SV=3.63  BV=7.10
    {2019,1198,1032, 0, 0, 0},  //TV = 8.95(129 lines)  AV=1.70  SV=3.64  BV=7.01
    {2192,1198,1024, 0, 0, 0},  //TV = 8.83(140 lines)  AV=1.70  SV=3.63  BV=6.90
    {2348,1198,1024, 0, 0, 0},  //TV = 8.73(150 lines)  AV=1.70  SV=3.63  BV=6.80
    {2489,1198,1032, 0, 0, 0},  //TV = 8.65(159 lines)  AV=1.70  SV=3.64  BV=6.71
    {2677,1198,1032, 0, 0, 0},  //TV = 8.55(171 lines)  AV=1.70  SV=3.64  BV=6.60
    {2865,1198,1032, 0, 0, 0},  //TV = 8.45(183 lines)  AV=1.70  SV=3.64  BV=6.51
    {3068,1198,1032, 0, 0, 0},  //TV = 8.35(196 lines)  AV=1.70  SV=3.64  BV=6.41
    {3303,1198,1032, 0, 0, 0},  //TV = 8.24(211 lines)  AV=1.70  SV=3.64  BV=6.30
    {3538,1198,1032, 0, 0, 0},  //TV = 8.14(226 lines)  AV=1.70  SV=3.64  BV=6.20
    {3788,1198,1032, 0, 0, 0},  //TV = 8.04(242 lines)  AV=1.70  SV=3.64  BV=6.10
    {4054,1198,1032, 0, 0, 0},  //TV = 7.95(259 lines)  AV=1.70  SV=3.64  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(280 lines)  AV=1.70  SV=3.63  BV=5.90
    {4680,1198,1024, 0, 0, 0},  //TV = 7.74(299 lines)  AV=1.70  SV=3.63  BV=5.81
    {5024,1198,1024, 0, 0, 0},  //TV = 7.64(321 lines)  AV=1.70  SV=3.63  BV=5.71
    {5369,1198,1024, 0, 0, 0},  //TV = 7.54(343 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(368 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(394 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(422 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(452 lines)  AV=1.70  SV=3.63  BV=5.21
    {7623,1198,1024, 0, 0, 0},  //TV = 7.04(487 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(522 lines)  AV=1.70  SV=3.63  BV=5.00
    {8749,1198,1024, 0, 0, 0},  //TV = 6.84(559 lines)  AV=1.70  SV=3.63  BV=4.91
    {9375,1198,1024, 0, 0, 0},  //TV = 6.74(599 lines)  AV=1.70  SV=3.63  BV=4.81
    {10002,1198,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.64  BV=4.70
    {10002,1280,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.72  BV=4.62
    {10002,1382,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.83  BV=4.51
    {10002,1475,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=3.93  BV=4.41
    {10002,1567,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.03  BV=4.31
    {10002,1700,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.13  BV=4.21
    {10002,1823,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.23  BV=4.11
    {10002,1925,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.32  BV=4.02
    {10002,2079,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.43  BV=3.91
    {10002,2222,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.53  BV=3.81
    {10002,2406,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.63  BV=3.71
    {10002,2570,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.73  BV=3.61
    {10002,2755,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.83  BV=3.51
    {10002,2949,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=4.94  BV=3.40
    {10002,3154,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.03  BV=3.30
    {10002,3359,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.13  BV=3.21
    {10002,3645,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.23  BV=3.11
    {10002,3850,1040, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.33  BV=3.01
    {10002,4157,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.43  BV=2.91
    {10002,4444,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.53  BV=2.81
    {10002,4762,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.63  BV=2.71
    {10002,5140,1024, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.73  BV=2.61
    {10002,5458,1032, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.83  BV=2.51
    {10002,5827,1040, 0, 0, 0},  //TV = 6.64(639 lines)  AV=1.70  SV=5.93  BV=2.41
    {20003,3154,1024, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=5.02  BV=2.32
    {20003,3359,1032, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=5.13  BV=2.21
    {20003,3594,1032, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=5.22  BV=2.12
    {20003,3850,1032, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=5.32  BV=2.02
    {20003,4157,1032, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=5.43  BV=1.91
    {20003,4444,1032, 0, 0, 0},  //TV = 5.64(1278 lines)  AV=1.70  SV=5.53  BV=1.81
    {30004,3195,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.05  BV=1.70
    {30004,3400,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.14  BV=1.61
    {30004,3645,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.24  BV=1.51
    {30004,3912,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.35  BV=1.41
    {30004,4229,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.45  BV=1.31
    {30004,4516,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.54  BV=1.21
    {30004,4854,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.65  BV=1.11
    {30004,5140,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.74  BV=1.02
    {30004,5581,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.85  BV=0.91
    {30004,5960,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=5.95  BV=0.80
    {30004,6390,1024, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.04  BV=0.71
    {30004,6717,1048, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.15  BV=0.61
    {30004,7281,1032, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.24  BV=0.51
    {30004,7711,1048, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.35  BV=0.41
    {30004,8192,1056, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.44  BV=0.31
    {30004,8192,1128, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.54  BV=0.21
    {30004,8192,1208, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.64  BV=0.12
    {30004,8192,1304, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.75  BV=0.01
    {30004,8192,1408, 0, 0, 0},  //TV = 5.06(1917 lines)  AV=1.70  SV=6.86  BV=-0.11
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_VIDEO2_AUTO,    //eAETableID
    106,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    104,    //i4MaxBV
    -1,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sVideo2PLineTable_60Hz,
    sVideo2PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom1PLineTable_60Hz =
{
{
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8324,1249,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.69  BV=4.92
    {8324,1341,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.80  BV=4.80
    {8324,1444,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.90  BV=4.71
    {8324,1536,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.00  BV=4.61
    {8324,1649,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.10  BV=4.51
    {8324,1782,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.20  BV=4.40
    {8324,1884,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.29  BV=4.31
    {8324,2028,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.39  BV=4.22
    {8324,2181,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.49  BV=4.11
    {8324,2324,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.59  BV=4.01
    {16667,1249,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.69  BV=3.92
    {16667,1341,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.80  BV=3.80
    {16667,1454,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.91  BV=3.70
    {16667,1536,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.99  BV=3.62
    {16667,1649,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.09  BV=3.51
    {16667,1761,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.19  BV=3.41
    {16667,1905,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.30  BV=3.31
    {16667,2028,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.39  BV=3.22
    {16667,2181,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.49  BV=3.11
    {16667,2345,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.60  BV=3.01
    {16667,2499,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.69  BV=2.92
    {16667,2703,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.80  BV=2.80
    {16667,2877,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.89  BV=2.71
    {16667,3082,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.99  BV=2.61
    {16667,3277,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.09  BV=2.51
    {16667,3543,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.19  BV=2.41
    {16667,3799,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.29  BV=2.31
    {16667,4035,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.39  BV=2.21
    {16667,4301,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.48  BV=2.12
    {24990,3123,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.01  BV=2.01
    {24990,3359,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.11  BV=1.90
    {24990,3594,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.21  BV=1.81
    {24990,3850,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.31  BV=1.71
    {33333,3082,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=4.99  BV=1.61
    {33333,3277,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.09  BV=1.51
    {33333,3543,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.19  BV=1.41
    {33333,3799,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.29  BV=1.31
    {33333,4035,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.39  BV=1.21
    {33333,4372,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.49  BV=1.11
    {33333,4680,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.59  BV=1.01
    {33333,5038,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.70  BV=0.90
    {33333,5345,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.80  BV=0.81
    {33333,5704,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.89  BV=0.71
    {33333,6093,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.00  BV=0.61
    {33333,6554,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.09  BV=0.51
    {33333,7086,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.19  BV=0.41
    {33333,7485,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.29  BV=0.31
    {33333,7946,1048, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.39  BV=0.21
    {33333,8192,1088, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.49  BV=0.11
    {33333,8192,1184, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.61  BV=-0.01
    {33333,8192,1264, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.70  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8739,1198,1024, 0, 0, 0},  //TV = 6.84(442 lines)  AV=1.70  SV=3.63  BV=4.91
    {9371,1198,1024, 0, 0, 0},  //TV = 6.74(474 lines)  AV=1.70  SV=3.63  BV=4.81
    {10004,1198,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.64  BV=4.70
    {10004,1280,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.72  BV=4.62
    {10004,1382,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.83  BV=4.51
    {10004,1475,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.93  BV=4.41
    {10004,1567,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.03  BV=4.31
    {10004,1700,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.13  BV=4.21
    {10004,1823,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.23  BV=4.11
    {10004,1925,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.32  BV=4.02
    {10004,2079,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.43  BV=3.91
    {10004,2222,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.53  BV=3.81
    {10004,2386,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.62  BV=3.72
    {10004,2570,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.73  BV=3.61
    {10004,2755,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.83  BV=3.51
    {10004,2949,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.94  BV=3.40
    {10004,3154,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.03  BV=3.30
    {10004,3359,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.13  BV=3.21
    {10004,3645,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.23  BV=3.11
    {10004,3850,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.33  BV=3.01
    {10004,4157,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.43  BV=2.91
    {10004,4444,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.53  BV=2.81
    {10004,4762,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.63  BV=2.71
    {10004,5140,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.73  BV=2.61
    {10004,5458,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.83  BV=2.51
    {10004,5827,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.93  BV=2.41
    {20008,3154,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.02  BV=2.32
    {20008,3400,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.13  BV=2.21
    {20008,3594,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.22  BV=2.12
    {20008,3912,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.33  BV=2.01
    {20008,4157,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.43  BV=1.91
    {20008,4444,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.53  BV=1.81
    {29992,3195,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.05  BV=1.70
    {29992,3400,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.14  BV=1.61
    {29992,3645,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.24  BV=1.51
    {29992,3912,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.35  BV=1.41
    {29992,4229,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.45  BV=1.31
    {29992,4516,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.54  BV=1.21
    {29992,4854,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.65  BV=1.11
    {29992,5140,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.74  BV=1.02
    {29992,5458,1040, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.84  BV=0.92
    {29992,5960,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.95  BV=0.80
    {29992,6390,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.04  BV=0.71
    {29992,6717,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.15  BV=0.61
    {29992,7281,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.24  BV=0.51
    {29992,7711,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.35  BV=0.41
    {29992,8192,1056, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.44  BV=0.31
    {29992,8192,1128, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.54  BV=0.22
    {29992,8192,1208, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.64  BV=0.12
    {29992,8192,1312, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.76  BV=-0.00
    {29992,8192,1408, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.86  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CUSTOM1_AUTO,    //eAETableID
    106,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    104,    //i4MaxBV
    -1,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sCustom1PLineTable_60Hz,
    sCustom1PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom2PLineTable_60Hz =
{
{
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8324,1249,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.69  BV=4.92
    {8324,1341,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.80  BV=4.80
    {8324,1444,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.90  BV=4.71
    {8324,1536,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.00  BV=4.61
    {8324,1649,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.10  BV=4.51
    {8324,1782,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.20  BV=4.40
    {8324,1884,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.29  BV=4.31
    {8324,2028,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.39  BV=4.22
    {8324,2181,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.49  BV=4.11
    {8324,2324,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.59  BV=4.01
    {16667,1249,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.69  BV=3.92
    {16667,1341,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.80  BV=3.80
    {16667,1454,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.91  BV=3.70
    {16667,1536,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.99  BV=3.62
    {16667,1649,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.09  BV=3.51
    {16667,1761,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.19  BV=3.41
    {16667,1905,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.30  BV=3.31
    {16667,2028,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.39  BV=3.22
    {16667,2181,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.49  BV=3.11
    {16667,2345,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.60  BV=3.01
    {16667,2499,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.69  BV=2.92
    {16667,2703,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.80  BV=2.80
    {16667,2877,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.89  BV=2.71
    {16667,3082,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.99  BV=2.61
    {16667,3277,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.09  BV=2.51
    {16667,3543,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.19  BV=2.41
    {16667,3799,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.29  BV=2.31
    {16667,4035,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.39  BV=2.21
    {16667,4301,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.48  BV=2.12
    {24990,3123,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.01  BV=2.01
    {24990,3359,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.11  BV=1.90
    {24990,3594,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.21  BV=1.81
    {24990,3850,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.31  BV=1.71
    {33333,3082,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=4.99  BV=1.61
    {33333,3277,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.09  BV=1.51
    {33333,3543,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.19  BV=1.41
    {33333,3799,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.29  BV=1.31
    {33333,4035,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.39  BV=1.21
    {33333,4372,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.49  BV=1.11
    {33333,4680,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.59  BV=1.01
    {33333,5038,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.70  BV=0.90
    {33333,5345,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.80  BV=0.81
    {33333,5704,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.89  BV=0.71
    {33333,6093,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.00  BV=0.61
    {33333,6554,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.09  BV=0.51
    {33333,7086,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.19  BV=0.41
    {33333,7485,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.29  BV=0.31
    {33333,7946,1048, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.39  BV=0.21
    {33333,8192,1088, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.49  BV=0.11
    {33333,8192,1184, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.61  BV=-0.01
    {33333,8192,1264, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.70  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8739,1198,1024, 0, 0, 0},  //TV = 6.84(442 lines)  AV=1.70  SV=3.63  BV=4.91
    {9371,1198,1024, 0, 0, 0},  //TV = 6.74(474 lines)  AV=1.70  SV=3.63  BV=4.81
    {10004,1198,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.64  BV=4.70
    {10004,1280,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.72  BV=4.62
    {10004,1382,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.83  BV=4.51
    {10004,1475,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.93  BV=4.41
    {10004,1567,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.03  BV=4.31
    {10004,1700,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.13  BV=4.21
    {10004,1823,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.23  BV=4.11
    {10004,1925,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.32  BV=4.02
    {10004,2079,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.43  BV=3.91
    {10004,2222,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.53  BV=3.81
    {10004,2386,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.62  BV=3.72
    {10004,2570,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.73  BV=3.61
    {10004,2755,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.83  BV=3.51
    {10004,2949,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.94  BV=3.40
    {10004,3154,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.03  BV=3.30
    {10004,3359,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.13  BV=3.21
    {10004,3645,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.23  BV=3.11
    {10004,3850,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.33  BV=3.01
    {10004,4157,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.43  BV=2.91
    {10004,4444,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.53  BV=2.81
    {10004,4762,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.63  BV=2.71
    {10004,5140,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.73  BV=2.61
    {10004,5458,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.83  BV=2.51
    {10004,5827,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.93  BV=2.41
    {20008,3154,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.02  BV=2.32
    {20008,3400,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.13  BV=2.21
    {20008,3594,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.22  BV=2.12
    {20008,3912,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.33  BV=2.01
    {20008,4157,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.43  BV=1.91
    {20008,4444,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.53  BV=1.81
    {29992,3195,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.05  BV=1.70
    {29992,3400,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.14  BV=1.61
    {29992,3645,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.24  BV=1.51
    {29992,3912,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.35  BV=1.41
    {29992,4229,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.45  BV=1.31
    {29992,4516,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.54  BV=1.21
    {29992,4854,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.65  BV=1.11
    {29992,5140,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.74  BV=1.02
    {29992,5458,1040, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.84  BV=0.92
    {29992,5960,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.95  BV=0.80
    {29992,6390,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.04  BV=0.71
    {29992,6717,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.15  BV=0.61
    {29992,7281,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.24  BV=0.51
    {29992,7711,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.35  BV=0.41
    {29992,8192,1056, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.44  BV=0.31
    {29992,8192,1128, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.54  BV=0.22
    {29992,8192,1208, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.64  BV=0.12
    {29992,8192,1312, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.76  BV=-0.00
    {29992,8192,1408, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.86  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CUSTOM2_AUTO,    //eAETableID
    106,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    104,    //i4MaxBV
    -1,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sCustom2PLineTable_60Hz,
    sCustom2PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom3PLineTable_60Hz =
{
{
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8324,1249,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.69  BV=4.92
    {8324,1341,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.80  BV=4.80
    {8324,1444,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.90  BV=4.71
    {8324,1536,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.00  BV=4.61
    {8324,1649,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.10  BV=4.51
    {8324,1782,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.20  BV=4.40
    {8324,1884,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.29  BV=4.31
    {8324,2028,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.39  BV=4.22
    {8324,2181,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.49  BV=4.11
    {8324,2324,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.59  BV=4.01
    {16667,1249,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.69  BV=3.92
    {16667,1341,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.80  BV=3.80
    {16667,1454,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.91  BV=3.70
    {16667,1536,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.99  BV=3.62
    {16667,1649,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.09  BV=3.51
    {16667,1761,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.19  BV=3.41
    {16667,1905,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.30  BV=3.31
    {16667,2028,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.39  BV=3.22
    {16667,2181,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.49  BV=3.11
    {16667,2345,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.60  BV=3.01
    {16667,2499,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.69  BV=2.92
    {16667,2703,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.80  BV=2.80
    {16667,2877,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.89  BV=2.71
    {16667,3082,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.99  BV=2.61
    {16667,3277,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.09  BV=2.51
    {16667,3543,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.19  BV=2.41
    {16667,3799,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.29  BV=2.31
    {16667,4035,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.39  BV=2.21
    {16667,4301,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.48  BV=2.12
    {24990,3123,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.01  BV=2.01
    {24990,3359,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.11  BV=1.90
    {24990,3594,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.21  BV=1.81
    {24990,3850,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.31  BV=1.71
    {33333,3082,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=4.99  BV=1.61
    {33333,3277,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.09  BV=1.51
    {33333,3543,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.19  BV=1.41
    {33333,3799,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.29  BV=1.31
    {33333,4035,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.39  BV=1.21
    {33333,4372,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.49  BV=1.11
    {33333,4680,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.59  BV=1.01
    {33333,5038,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.70  BV=0.90
    {33333,5345,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.80  BV=0.81
    {33333,5704,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.89  BV=0.71
    {33333,6093,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.00  BV=0.61
    {33333,6554,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.09  BV=0.51
    {33333,7086,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.19  BV=0.41
    {33333,7485,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.29  BV=0.31
    {33333,7946,1048, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.39  BV=0.21
    {33333,8192,1088, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.49  BV=0.11
    {33333,8192,1184, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.61  BV=-0.01
    {33333,8192,1264, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.70  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8739,1198,1024, 0, 0, 0},  //TV = 6.84(442 lines)  AV=1.70  SV=3.63  BV=4.91
    {9371,1198,1024, 0, 0, 0},  //TV = 6.74(474 lines)  AV=1.70  SV=3.63  BV=4.81
    {10004,1198,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.64  BV=4.70
    {10004,1280,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.72  BV=4.62
    {10004,1382,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.83  BV=4.51
    {10004,1475,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.93  BV=4.41
    {10004,1567,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.03  BV=4.31
    {10004,1700,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.13  BV=4.21
    {10004,1823,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.23  BV=4.11
    {10004,1925,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.32  BV=4.02
    {10004,2079,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.43  BV=3.91
    {10004,2222,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.53  BV=3.81
    {10004,2386,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.62  BV=3.72
    {10004,2570,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.73  BV=3.61
    {10004,2755,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.83  BV=3.51
    {10004,2949,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.94  BV=3.40
    {10004,3154,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.03  BV=3.30
    {10004,3359,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.13  BV=3.21
    {10004,3645,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.23  BV=3.11
    {10004,3850,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.33  BV=3.01
    {10004,4157,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.43  BV=2.91
    {10004,4444,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.53  BV=2.81
    {10004,4762,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.63  BV=2.71
    {10004,5140,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.73  BV=2.61
    {10004,5458,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.83  BV=2.51
    {10004,5827,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.93  BV=2.41
    {20008,3154,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.02  BV=2.32
    {20008,3400,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.13  BV=2.21
    {20008,3594,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.22  BV=2.12
    {20008,3912,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.33  BV=2.01
    {20008,4157,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.43  BV=1.91
    {20008,4444,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.53  BV=1.81
    {29992,3195,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.05  BV=1.70
    {29992,3400,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.14  BV=1.61
    {29992,3645,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.24  BV=1.51
    {29992,3912,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.35  BV=1.41
    {29992,4229,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.45  BV=1.31
    {29992,4516,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.54  BV=1.21
    {29992,4854,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.65  BV=1.11
    {29992,5140,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.74  BV=1.02
    {29992,5458,1040, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.84  BV=0.92
    {29992,5960,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.95  BV=0.80
    {29992,6390,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.04  BV=0.71
    {29992,6717,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.15  BV=0.61
    {29992,7281,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.24  BV=0.51
    {29992,7711,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.35  BV=0.41
    {29992,8192,1056, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.44  BV=0.31
    {29992,8192,1128, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.54  BV=0.22
    {29992,8192,1208, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.64  BV=0.12
    {29992,8192,1312, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.76  BV=-0.00
    {29992,8192,1408, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.86  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CUSTOM3_AUTO,    //eAETableID
    106,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    104,    //i4MaxBV
    -1,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sCustom3PLineTable_60Hz,
    sCustom3PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom4PLineTable_60Hz =
{
{
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8324,1249,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.69  BV=4.92
    {8324,1341,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.80  BV=4.80
    {8324,1444,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.90  BV=4.71
    {8324,1536,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.00  BV=4.61
    {8324,1649,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.10  BV=4.51
    {8324,1782,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.20  BV=4.40
    {8324,1884,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.29  BV=4.31
    {8324,2028,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.39  BV=4.22
    {8324,2181,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.49  BV=4.11
    {8324,2324,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.59  BV=4.01
    {16667,1249,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.69  BV=3.92
    {16667,1341,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.80  BV=3.80
    {16667,1454,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.91  BV=3.70
    {16667,1536,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.99  BV=3.62
    {16667,1649,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.09  BV=3.51
    {16667,1761,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.19  BV=3.41
    {16667,1905,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.30  BV=3.31
    {16667,2028,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.39  BV=3.22
    {16667,2181,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.49  BV=3.11
    {16667,2345,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.60  BV=3.01
    {16667,2499,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.69  BV=2.92
    {16667,2703,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.80  BV=2.80
    {16667,2877,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.89  BV=2.71
    {16667,3082,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.99  BV=2.61
    {16667,3277,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.09  BV=2.51
    {16667,3543,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.19  BV=2.41
    {16667,3799,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.29  BV=2.31
    {16667,4035,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.39  BV=2.21
    {16667,4301,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.48  BV=2.12
    {24990,3123,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.01  BV=2.01
    {24990,3359,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.11  BV=1.90
    {24990,3594,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.21  BV=1.81
    {24990,3850,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.31  BV=1.71
    {33333,3082,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=4.99  BV=1.61
    {33333,3277,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.09  BV=1.51
    {33333,3543,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.19  BV=1.41
    {33333,3799,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.29  BV=1.31
    {33333,4035,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.39  BV=1.21
    {33333,4372,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.49  BV=1.11
    {33333,4680,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.59  BV=1.01
    {33333,5038,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.70  BV=0.90
    {33333,5345,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.80  BV=0.81
    {33333,5704,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.89  BV=0.71
    {33333,6093,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.00  BV=0.61
    {33333,6554,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.09  BV=0.51
    {33333,7086,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.19  BV=0.41
    {33333,7485,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.29  BV=0.31
    {33333,7946,1048, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.39  BV=0.21
    {33333,8192,1088, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.49  BV=0.11
    {33333,8192,1184, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.61  BV=-0.01
    {33333,8192,1264, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.70  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8739,1198,1024, 0, 0, 0},  //TV = 6.84(442 lines)  AV=1.70  SV=3.63  BV=4.91
    {9371,1198,1024, 0, 0, 0},  //TV = 6.74(474 lines)  AV=1.70  SV=3.63  BV=4.81
    {10004,1198,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.64  BV=4.70
    {10004,1280,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.72  BV=4.62
    {10004,1382,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.83  BV=4.51
    {10004,1475,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.93  BV=4.41
    {10004,1567,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.03  BV=4.31
    {10004,1700,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.13  BV=4.21
    {10004,1823,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.23  BV=4.11
    {10004,1925,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.32  BV=4.02
    {10004,2079,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.43  BV=3.91
    {10004,2222,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.53  BV=3.81
    {10004,2386,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.62  BV=3.72
    {10004,2570,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.73  BV=3.61
    {10004,2755,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.83  BV=3.51
    {10004,2949,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.94  BV=3.40
    {10004,3154,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.03  BV=3.30
    {10004,3359,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.13  BV=3.21
    {10004,3645,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.23  BV=3.11
    {10004,3850,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.33  BV=3.01
    {10004,4157,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.43  BV=2.91
    {10004,4444,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.53  BV=2.81
    {10004,4762,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.63  BV=2.71
    {10004,5140,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.73  BV=2.61
    {10004,5458,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.83  BV=2.51
    {10004,5827,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.93  BV=2.41
    {20008,3154,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.02  BV=2.32
    {20008,3400,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.13  BV=2.21
    {20008,3594,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.22  BV=2.12
    {20008,3912,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.33  BV=2.01
    {20008,4157,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.43  BV=1.91
    {20008,4444,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.53  BV=1.81
    {29992,3195,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.05  BV=1.70
    {29992,3400,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.14  BV=1.61
    {29992,3645,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.24  BV=1.51
    {29992,3912,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.35  BV=1.41
    {29992,4229,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.45  BV=1.31
    {29992,4516,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.54  BV=1.21
    {29992,4854,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.65  BV=1.11
    {29992,5140,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.74  BV=1.02
    {29992,5458,1040, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.84  BV=0.92
    {29992,5960,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.95  BV=0.80
    {29992,6390,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.04  BV=0.71
    {29992,6717,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.15  BV=0.61
    {29992,7281,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.24  BV=0.51
    {29992,7711,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.35  BV=0.41
    {29992,8192,1056, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.44  BV=0.31
    {29992,8192,1128, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.54  BV=0.22
    {29992,8192,1208, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.64  BV=0.12
    {29992,8192,1312, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.76  BV=-0.00
    {29992,8192,1408, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.86  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CUSTOM4_AUTO,    //eAETableID
    106,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    104,    //i4MaxBV
    -1,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sCustom4PLineTable_60Hz,
    sCustom4PLineTable_50Hz,
    NULL,
};
static strEvPline sCustom5PLineTable_60Hz =
{
{
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8324,1249,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.69  BV=4.92
    {8324,1341,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.80  BV=4.80
    {8324,1444,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=3.90  BV=4.71
    {8324,1536,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.00  BV=4.61
    {8324,1649,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.10  BV=4.51
    {8324,1782,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.20  BV=4.40
    {8324,1884,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.29  BV=4.31
    {8324,2028,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.39  BV=4.22
    {8324,2181,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.49  BV=4.11
    {8324,2324,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=1.70  SV=4.59  BV=4.01
    {16667,1249,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.69  BV=3.92
    {16667,1341,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.80  BV=3.80
    {16667,1454,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.91  BV=3.70
    {16667,1536,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=3.99  BV=3.62
    {16667,1649,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.09  BV=3.51
    {16667,1761,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.19  BV=3.41
    {16667,1905,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.30  BV=3.31
    {16667,2028,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.39  BV=3.22
    {16667,2181,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.49  BV=3.11
    {16667,2345,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.60  BV=3.01
    {16667,2499,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.69  BV=2.92
    {16667,2703,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.80  BV=2.80
    {16667,2877,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.89  BV=2.71
    {16667,3082,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=4.99  BV=2.61
    {16667,3277,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.09  BV=2.51
    {16667,3543,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.19  BV=2.41
    {16667,3799,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.29  BV=2.31
    {16667,4035,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.39  BV=2.21
    {16667,4301,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=1.70  SV=5.48  BV=2.12
    {24990,3123,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.01  BV=2.01
    {24990,3359,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.11  BV=1.90
    {24990,3594,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.21  BV=1.81
    {24990,3850,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=1.70  SV=5.31  BV=1.71
    {33333,3082,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=4.99  BV=1.61
    {33333,3277,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.09  BV=1.51
    {33333,3543,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.19  BV=1.41
    {33333,3799,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.29  BV=1.31
    {33333,4035,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.39  BV=1.21
    {33333,4372,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.49  BV=1.11
    {33333,4680,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.59  BV=1.01
    {33333,5038,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.70  BV=0.90
    {33333,5345,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.80  BV=0.81
    {33333,5704,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=5.89  BV=0.71
    {33333,6093,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.00  BV=0.61
    {33333,6554,1032, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.09  BV=0.51
    {33333,7086,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.19  BV=0.41
    {33333,7485,1040, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.29  BV=0.31
    {33333,7946,1048, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.39  BV=0.21
    {33333,8192,1088, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.49  BV=0.11
    {33333,8192,1184, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.61  BV=-0.01
    {33333,8192,1264, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=1.70  SV=6.70  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {198,1198,1032, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.64  BV=10.36
    {198,1249,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=1.70  SV=3.69  BV=10.31
    {218,1219,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=1.70  SV=3.65  BV=10.21
    {238,1198,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.63  BV=10.11
    {238,1280,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=1.70  SV=3.72  BV=10.01
    {258,1270,1024, 0, 0, 0},  //TV = 11.92(13 lines)  AV=1.70  SV=3.71  BV=9.91
    {277,1249,1032, 0, 0, 0},  //TV = 11.82(14 lines)  AV=1.70  SV=3.70  BV=9.82
    {297,1249,1032, 0, 0, 0},  //TV = 11.72(15 lines)  AV=1.70  SV=3.70  BV=9.71
    {317,1270,1024, 0, 0, 0},  //TV = 11.62(16 lines)  AV=1.70  SV=3.71  BV=9.61
    {356,1198,1032, 0, 0, 0},  //TV = 11.46(18 lines)  AV=1.70  SV=3.64  BV=9.51
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=1.70  SV=3.66  BV=9.41
    {396,1249,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=1.70  SV=3.69  BV=9.31
    {435,1219,1024, 0, 0, 0},  //TV = 11.17(22 lines)  AV=1.70  SV=3.65  BV=9.21
    {475,1198,1032, 0, 0, 0},  //TV = 11.04(24 lines)  AV=1.70  SV=3.64  BV=9.10
    {495,1219,1032, 0, 0, 0},  //TV = 10.98(25 lines)  AV=1.70  SV=3.66  BV=9.01
    {534,1219,1024, 0, 0, 0},  //TV = 10.87(27 lines)  AV=1.70  SV=3.65  BV=8.91
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(29 lines)  AV=1.70  SV=3.65  BV=8.81
    {613,1219,1024, 0, 0, 0},  //TV = 10.67(31 lines)  AV=1.70  SV=3.65  BV=8.72
    {653,1219,1032, 0, 0, 0},  //TV = 10.58(33 lines)  AV=1.70  SV=3.66  BV=8.61
    {712,1198,1032, 0, 0, 0},  //TV = 10.46(36 lines)  AV=1.70  SV=3.64  BV=8.51
    {752,1219,1032, 0, 0, 0},  //TV = 10.38(38 lines)  AV=1.70  SV=3.66  BV=8.41
    {811,1219,1024, 0, 0, 0},  //TV = 10.27(41 lines)  AV=1.70  SV=3.65  BV=8.31
    {870,1219,1024, 0, 0, 0},  //TV = 10.17(44 lines)  AV=1.70  SV=3.65  BV=8.21
    {949,1198,1024, 0, 0, 0},  //TV = 10.04(48 lines)  AV=1.70  SV=3.63  BV=8.11
    {1009,1198,1032, 0, 0, 0},  //TV = 9.95(51 lines)  AV=1.70  SV=3.64  BV=8.01
    {1068,1219,1024, 0, 0, 0},  //TV = 9.87(54 lines)  AV=1.70  SV=3.65  BV=7.91
    {1167,1198,1032, 0, 0, 0},  //TV = 9.74(59 lines)  AV=1.70  SV=3.64  BV=7.80
    {1246,1198,1032, 0, 0, 0},  //TV = 9.65(63 lines)  AV=1.70  SV=3.64  BV=7.71
    {1345,1198,1024, 0, 0, 0},  //TV = 9.54(68 lines)  AV=1.70  SV=3.63  BV=7.61
    {1444,1198,1024, 0, 0, 0},  //TV = 9.44(73 lines)  AV=1.70  SV=3.63  BV=7.50
    {1543,1198,1024, 0, 0, 0},  //TV = 9.34(78 lines)  AV=1.70  SV=3.63  BV=7.41
    {1641,1198,1032, 0, 0, 0},  //TV = 9.25(83 lines)  AV=1.70  SV=3.64  BV=7.31
    {1760,1198,1032, 0, 0, 0},  //TV = 9.15(89 lines)  AV=1.70  SV=3.64  BV=7.21
    {1898,1198,1032, 0, 0, 0},  //TV = 9.04(96 lines)  AV=1.70  SV=3.64  BV=7.10
    {2037,1198,1024, 0, 0, 0},  //TV = 8.94(103 lines)  AV=1.70  SV=3.63  BV=7.01
    {2175,1198,1032, 0, 0, 0},  //TV = 8.84(110 lines)  AV=1.70  SV=3.64  BV=6.90
    {2333,1198,1032, 0, 0, 0},  //TV = 8.74(118 lines)  AV=1.70  SV=3.64  BV=6.80
    {2511,1198,1024, 0, 0, 0},  //TV = 8.64(127 lines)  AV=1.70  SV=3.63  BV=6.71
    {2689,1198,1024, 0, 0, 0},  //TV = 8.54(136 lines)  AV=1.70  SV=3.63  BV=6.61
    {2867,1198,1032, 0, 0, 0},  //TV = 8.45(145 lines)  AV=1.70  SV=3.64  BV=6.50
    {3065,1198,1032, 0, 0, 0},  //TV = 8.35(155 lines)  AV=1.70  SV=3.64  BV=6.41
    {3282,1198,1032, 0, 0, 0},  //TV = 8.25(166 lines)  AV=1.70  SV=3.64  BV=6.31
    {3539,1198,1032, 0, 0, 0},  //TV = 8.14(179 lines)  AV=1.70  SV=3.64  BV=6.20
    {3796,1198,1024, 0, 0, 0},  //TV = 8.04(192 lines)  AV=1.70  SV=3.63  BV=6.11
    {4053,1198,1032, 0, 0, 0},  //TV = 7.95(205 lines)  AV=1.70  SV=3.64  BV=6.00
    {4370,1198,1032, 0, 0, 0},  //TV = 7.84(221 lines)  AV=1.70  SV=3.64  BV=5.90
    {4646,1198,1032, 0, 0, 0},  //TV = 7.75(235 lines)  AV=1.70  SV=3.64  BV=5.81
    {5022,1198,1024, 0, 0, 0},  //TV = 7.64(254 lines)  AV=1.70  SV=3.63  BV=5.71
    {5378,1198,1024, 0, 0, 0},  //TV = 7.54(272 lines)  AV=1.70  SV=3.63  BV=5.61
    {5754,1198,1024, 0, 0, 0},  //TV = 7.44(291 lines)  AV=1.70  SV=3.63  BV=5.51
    {6169,1198,1024, 0, 0, 0},  //TV = 7.34(312 lines)  AV=1.70  SV=3.63  BV=5.41
    {6604,1198,1024, 0, 0, 0},  //TV = 7.24(334 lines)  AV=1.70  SV=3.63  BV=5.31
    {7118,1198,1024, 0, 0, 0},  //TV = 7.13(360 lines)  AV=1.70  SV=3.63  BV=5.20
    {7612,1198,1024, 0, 0, 0},  //TV = 7.04(385 lines)  AV=1.70  SV=3.63  BV=5.11
    {8166,1198,1024, 0, 0, 0},  //TV = 6.94(413 lines)  AV=1.70  SV=3.63  BV=5.01
    {8739,1198,1024, 0, 0, 0},  //TV = 6.84(442 lines)  AV=1.70  SV=3.63  BV=4.91
    {9371,1198,1024, 0, 0, 0},  //TV = 6.74(474 lines)  AV=1.70  SV=3.63  BV=4.81
    {10004,1198,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.64  BV=4.70
    {10004,1280,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.72  BV=4.62
    {10004,1382,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.83  BV=4.51
    {10004,1475,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=3.93  BV=4.41
    {10004,1567,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.03  BV=4.31
    {10004,1700,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.13  BV=4.21
    {10004,1823,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.23  BV=4.11
    {10004,1925,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.32  BV=4.02
    {10004,2079,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.43  BV=3.91
    {10004,2222,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.53  BV=3.81
    {10004,2386,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.62  BV=3.72
    {10004,2570,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.73  BV=3.61
    {10004,2755,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.83  BV=3.51
    {10004,2949,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=4.94  BV=3.40
    {10004,3154,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.03  BV=3.30
    {10004,3359,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.13  BV=3.21
    {10004,3645,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.23  BV=3.11
    {10004,3850,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.33  BV=3.01
    {10004,4157,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.43  BV=2.91
    {10004,4444,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.53  BV=2.81
    {10004,4762,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.63  BV=2.71
    {10004,5140,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.73  BV=2.61
    {10004,5458,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.83  BV=2.51
    {10004,5827,1040, 0, 0, 0},  //TV = 6.64(506 lines)  AV=1.70  SV=5.93  BV=2.41
    {20008,3154,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.02  BV=2.32
    {20008,3400,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.13  BV=2.21
    {20008,3594,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.22  BV=2.12
    {20008,3912,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.33  BV=2.01
    {20008,4157,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.43  BV=1.91
    {20008,4444,1032, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=1.70  SV=5.53  BV=1.81
    {29992,3195,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.05  BV=1.70
    {29992,3400,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.14  BV=1.61
    {29992,3645,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.24  BV=1.51
    {29992,3912,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.35  BV=1.41
    {29992,4229,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.45  BV=1.31
    {29992,4516,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.54  BV=1.21
    {29992,4854,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.65  BV=1.11
    {29992,5140,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.74  BV=1.02
    {29992,5458,1040, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.84  BV=0.92
    {29992,5960,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=5.95  BV=0.80
    {29992,6390,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.04  BV=0.71
    {29992,6717,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.15  BV=0.61
    {29992,7281,1032, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.24  BV=0.51
    {29992,7711,1048, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.35  BV=0.41
    {29992,8192,1056, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.44  BV=0.31
    {29992,8192,1128, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.54  BV=0.22
    {29992,8192,1208, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.64  BV=0.12
    {29992,8192,1312, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.76  BV=-0.00
    {29992,8192,1408, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=1.70  SV=6.86  BV=-0.10
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CUSTOM5_AUTO,    //eAETableID
    106,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    104,    //i4MaxBV
    -1,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sCustom5PLineTable_60Hz,
    sCustom5PLineTable_50Hz,
    NULL,
};
static strEvPline sVideoNightPLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33296,1249,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=3.69  BV=2.92
    {33296,1341,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=3.80  BV=2.80
    {33296,1444,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=3.90  BV=2.71
    {33296,1536,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.00  BV=2.61
    {33296,1649,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.10  BV=2.51
    {33296,1761,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.19  BV=2.41
    {33296,1905,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.30  BV=2.31
    {33296,2028,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.39  BV=2.22
    {33296,2181,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.50  BV=2.10
    {33296,2345,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.60  BV=2.01
    {33296,2519,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.70  BV=1.91
    {33296,2703,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.80  BV=1.80
    {33296,2877,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.89  BV=1.71
    {33296,3082,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=4.99  BV=1.61
    {33296,3318,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.10  BV=1.51
    {33296,3543,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.19  BV=1.41
    {33296,3799,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.30  BV=1.30
    {33296,4035,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.39  BV=1.21
    {33296,4372,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.49  BV=1.11
    {33296,4680,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.59  BV=1.01
    {33296,4946,1040, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.69  BV=0.91
    {33296,5345,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.78  BV=0.82
    {33296,5704,1040, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=5.90  BV=0.70
    {33296,6093,1040, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=6.00  BV=0.61
    {33296,6554,1032, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=6.09  BV=0.51
    {33296,7086,1024, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=6.19  BV=0.41
    {33296,7485,1040, 0, 0, 0},  //TV = 4.91(3191 lines)  AV=1.70  SV=6.29  BV=0.31
    {41663,6390,1040, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=6.06  BV=0.22
    {41663,6902,1032, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=6.16  BV=0.12
    {50001,6246,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.01  BV=0.01
    {50001,6717,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.11  BV=-0.10
    {58327,6093,1040, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=6.00  BV=-0.20
    {58327,6554,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=6.09  BV=-0.29
    {66632,6093,1040, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=6.00  BV=-0.39
    {66632,6554,1040, 0, 0, 0},  //TV = 3.91(6386 lines)  AV=1.70  SV=6.10  BV=-0.50
    {75001,6246,1040, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.03  BV=-0.60
    {75001,6717,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.13  BV=-0.69
    {83326,6554,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=6.08  BV=-0.80
    {91663,6390,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=6.04  BV=-0.90
    {100001,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100001,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100001,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100001,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {29998,1608,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.05  BV=2.70
    {29998,1720,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.15  BV=2.61
    {29998,1843,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.25  BV=2.51
    {29998,1966,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.35  BV=2.40
    {29998,2109,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.44  BV=2.31
    {29998,2263,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.54  BV=2.21
    {29998,2427,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.65  BV=2.11
    {29998,2591,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.74  BV=2.02
    {29998,2785,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.84  BV=1.91
    {29998,2980,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.95  BV=1.80
    {29998,3195,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.04  BV=1.71
    {29998,3400,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.14  BV=1.61
    {29998,3645,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.24  BV=1.51
    {29998,3912,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.35  BV=1.41
    {29998,4229,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.45  BV=1.31
    {29998,4516,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.55  BV=1.20
    {29998,4854,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.65  BV=1.11
    {29998,5140,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.74  BV=1.02
    {29998,5581,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.85  BV=0.91
    {29998,5960,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.94  BV=0.81
    {29998,6390,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.05  BV=0.70
    {29998,6717,1040, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.14  BV=0.62
    {29998,7281,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.24  BV=0.51
    {29998,7711,1048, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.35  BV=0.41
    {40005,6246,1040, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.03  BV=0.31
    {40005,6717,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.13  BV=0.21
    {40005,7281,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.23  BV=0.11
    {50000,6246,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.01  BV=0.01
    {50000,6717,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.11  BV=-0.10
    {50000,7086,1040, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.21  BV=-0.20
    {59996,6390,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.05  BV=-0.30
    {59996,6902,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.15  BV=-0.40
    {70003,6246,1040, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.03  BV=-0.50
    {70003,6717,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.13  BV=-0.59
    {79998,6246,1040, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.03  BV=-0.69
    {79998,6717,1040, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.14  BV=-0.80
    {90005,6390,1040, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=6.06  BV=-0.89
    {100000,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100000,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100000,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100000,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_VIDEO_NIGHT,    //eAETableID
    128,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -13,    //i4MinBV
    90,    //i4EffectiveMaxBV
    -10,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sVideoNightPLineTable_60Hz,
    sVideoNightPLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO100PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33327,1249,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.69  BV=2.92
    {33327,1341,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.80  BV=2.80
    {33327,1444,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.90  BV=2.71
    {41663,1239,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.68  BV=2.61
    {41663,1311,1032, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.77  BV=2.51
    {41663,1423,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.88  BV=2.41
    {50001,1270,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.71  BV=2.31
    {50001,1362,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.81  BV=2.21
    {58327,1239,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=3.68  BV=2.12
    {58327,1341,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=3.79  BV=2.01
    {66663,1249,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=3.70  BV=1.90
    {75001,1198,1024, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=3.63  BV=1.81
    {75001,1280,1024, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=3.72  BV=1.71
    {83326,1239,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=3.68  BV=1.61
    {91663,1198,1032, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=3.64  BV=1.51
    {91663,1280,1032, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=3.73  BV=1.41
    {100001,1270,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.71  BV=1.31
    {108326,1249,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=3.69  BV=1.22
    {116664,1239,1024, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=3.68  BV=1.12
    {125000,1249,1024, 0, 0, 0},  //TV = 3.00(11980 lines)  AV=1.70  SV=3.69  BV=1.01
    {133326,1249,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=3.69  BV=0.92
    {149989,1198,1024, 0, 0, 0},  //TV = 2.74(14375 lines)  AV=1.70  SV=3.63  BV=0.81
    {158326,1198,1032, 0, 0, 0},  //TV = 2.66(15174 lines)  AV=1.70  SV=3.64  BV=0.72
    {166663,1239,1024, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=3.68  BV=0.61
    {183326,1198,1032, 0, 0, 0},  //TV = 2.45(17570 lines)  AV=1.70  SV=3.64  BV=0.51
    {191663,1239,1024, 0, 0, 0},  //TV = 2.38(18369 lines)  AV=1.70  SV=3.68  BV=0.40
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {40005,1198,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.64  BV=2.70
    {40005,1280,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.72  BV=2.62
    {40005,1382,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.83  BV=2.51
    {40005,1475,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.94  BV=2.40
    {50000,1270,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.71  BV=2.31
    {50000,1362,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.81  BV=2.21
    {59996,1198,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.64  BV=2.12
    {59996,1300,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.74  BV=2.01
    {70003,1198,1024, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=3.63  BV=1.91
    {70003,1270,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=3.72  BV=1.81
    {79998,1198,1032, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=3.64  BV=1.70
    {79998,1280,1032, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=3.73  BV=1.61
    {90005,1219,1032, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=3.66  BV=1.51
    {90005,1311,1024, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=3.76  BV=1.41
    {100000,1270,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=3.71  BV=1.31
    {109996,1239,1024, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=3.68  BV=1.20
    {120002,1198,1032, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=3.64  BV=1.12
    {129998,1198,1032, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=3.64  BV=1.00
    {129998,1280,1024, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=3.72  BV=0.92
    {140004,1270,1032, 0, 0, 0},  //TV = 2.84(13418 lines)  AV=1.70  SV=3.72  BV=0.81
    {159995,1198,1032, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=3.64  BV=0.70
    {170002,1198,1032, 0, 0, 0},  //TV = 2.56(16293 lines)  AV=1.70  SV=3.64  BV=0.61
    {179997,1219,1032, 0, 0, 0},  //TV = 2.47(17251 lines)  AV=1.70  SV=3.66  BV=0.51
    {190004,1239,1024, 0, 0, 0},  //TV = 2.40(18210 lines)  AV=1.70  SV=3.68  BV=0.42
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CAPTURE_ISO100,    //eAETableID
    111,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    4,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_100, //ISO SPEED
    sCaptureISO100PLineTable_60Hz,
    sCaptureISO100PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO200PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {522,2499,1024, 0, 0, 0},  //TV = 10.90(50 lines)  AV=1.70  SV=4.69  BV=7.91
    {564,2478,1024, 0, 0, 0},  //TV = 10.79(54 lines)  AV=1.70  SV=4.68  BV=7.81
    {606,2478,1024, 0, 0, 0},  //TV = 10.69(58 lines)  AV=1.70  SV=4.68  BV=7.71
    {647,2478,1024, 0, 0, 0},  //TV = 10.59(62 lines)  AV=1.70  SV=4.68  BV=7.61
    {700,2447,1032, 0, 0, 0},  //TV = 10.48(67 lines)  AV=1.70  SV=4.67  BV=7.51
    {752,2447,1024, 0, 0, 0},  //TV = 10.38(72 lines)  AV=1.70  SV=4.66  BV=7.42
    {804,2447,1032, 0, 0, 0},  //TV = 10.28(77 lines)  AV=1.70  SV=4.67  BV=7.31
    {856,2478,1024, 0, 0, 0},  //TV = 10.19(82 lines)  AV=1.70  SV=4.68  BV=7.21
    {919,2478,1024, 0, 0, 0},  //TV = 10.09(88 lines)  AV=1.70  SV=4.68  BV=7.11
    {992,2447,1024, 0, 0, 0},  //TV = 9.98(95 lines)  AV=1.70  SV=4.66  BV=7.02
    {1054,2478,1024, 0, 0, 0},  //TV = 9.89(101 lines)  AV=1.70  SV=4.68  BV=6.91
    {1127,2478,1024, 0, 0, 0},  //TV = 9.79(108 lines)  AV=1.70  SV=4.68  BV=6.81
    {1221,2447,1032, 0, 0, 0},  //TV = 9.68(117 lines)  AV=1.70  SV=4.67  BV=6.71
    {1305,2478,1024, 0, 0, 0},  //TV = 9.58(125 lines)  AV=1.70  SV=4.68  BV=6.60
    {1399,2447,1032, 0, 0, 0},  //TV = 9.48(134 lines)  AV=1.70  SV=4.67  BV=6.51
    {1503,2447,1032, 0, 0, 0},  //TV = 9.38(144 lines)  AV=1.70  SV=4.67  BV=6.41
    {1607,2447,1032, 0, 0, 0},  //TV = 9.28(154 lines)  AV=1.70  SV=4.67  BV=6.31
    {1712,2478,1024, 0, 0, 0},  //TV = 9.19(164 lines)  AV=1.70  SV=4.68  BV=6.21
    {1847,2447,1032, 0, 0, 0},  //TV = 9.08(177 lines)  AV=1.70  SV=4.67  BV=6.11
    {1973,2447,1032, 0, 0, 0},  //TV = 8.99(189 lines)  AV=1.70  SV=4.67  BV=6.01
    {2129,2447,1024, 0, 0, 0},  //TV = 8.88(204 lines)  AV=1.70  SV=4.66  BV=5.91
    {2275,2447,1032, 0, 0, 0},  //TV = 8.78(218 lines)  AV=1.70  SV=4.67  BV=5.81
    {2432,2447,1032, 0, 0, 0},  //TV = 8.68(233 lines)  AV=1.70  SV=4.67  BV=5.71
    {2619,2447,1032, 0, 0, 0},  //TV = 8.58(251 lines)  AV=1.70  SV=4.67  BV=5.60
    {2807,2447,1024, 0, 0, 0},  //TV = 8.48(269 lines)  AV=1.70  SV=4.66  BV=5.52
    {3005,2447,1024, 0, 0, 0},  //TV = 8.38(288 lines)  AV=1.70  SV=4.66  BV=5.42
    {3235,2447,1024, 0, 0, 0},  //TV = 8.27(310 lines)  AV=1.70  SV=4.66  BV=5.31
    {3454,2447,1032, 0, 0, 0},  //TV = 8.18(331 lines)  AV=1.70  SV=4.67  BV=5.20
    {3705,2447,1024, 0, 0, 0},  //TV = 8.08(355 lines)  AV=1.70  SV=4.66  BV=5.11
    {3965,2447,1024, 0, 0, 0},  //TV = 7.98(380 lines)  AV=1.70  SV=4.66  BV=5.02
    {4247,2447,1024, 0, 0, 0},  //TV = 7.88(407 lines)  AV=1.70  SV=4.66  BV=4.92
    {4539,2447,1032, 0, 0, 0},  //TV = 7.78(435 lines)  AV=1.70  SV=4.67  BV=4.81
    {4894,2447,1024, 0, 0, 0},  //TV = 7.67(469 lines)  AV=1.70  SV=4.66  BV=4.71
    {5249,2447,1024, 0, 0, 0},  //TV = 7.57(503 lines)  AV=1.70  SV=4.66  BV=4.61
    {5614,2447,1024, 0, 0, 0},  //TV = 7.48(538 lines)  AV=1.70  SV=4.66  BV=4.52
    {6010,2447,1032, 0, 0, 0},  //TV = 7.38(576 lines)  AV=1.70  SV=4.67  BV=4.41
    {6438,2447,1024, 0, 0, 0},  //TV = 7.28(617 lines)  AV=1.70  SV=4.66  BV=4.32
    {6897,2447,1024, 0, 0, 0},  //TV = 7.18(661 lines)  AV=1.70  SV=4.66  BV=4.22
    {7388,2447,1024, 0, 0, 0},  //TV = 7.08(708 lines)  AV=1.70  SV=4.66  BV=4.12
    {7920,2447,1024, 0, 0, 0},  //TV = 6.98(759 lines)  AV=1.70  SV=4.66  BV=4.02
    {8338,2519,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.70  BV=3.90
    {8338,2673,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.78  BV=3.82
    {8338,2877,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.89  BV=3.71
    {8338,3082,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.99  BV=3.61
    {8338,3318,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.10  BV=3.51
    {8338,3543,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.19  BV=3.41
    {8338,3799,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.29  BV=3.31
    {8338,4035,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.39  BV=3.21
    {8338,4372,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.49  BV=3.11
    {8338,4680,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.59  BV=3.01
    {16664,2519,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.70  BV=2.90
    {16664,2673,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.80  BV=2.81
    {16664,2877,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.89  BV=2.71
    {16664,3082,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.99  BV=2.61
    {16664,3318,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.10  BV=2.51
    {16664,3543,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.19  BV=2.41
    {25001,2519,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.70  BV=2.32
    {25001,2703,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.80  BV=2.22
    {25001,2908,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.91  BV=2.11
    {25001,3123,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=5.01  BV=2.01
    {33327,2499,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.69  BV=1.92
    {33327,2703,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.80  BV=1.80
    {33327,2877,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.89  BV=1.71
    {41663,2447,1032, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.67  BV=1.61
    {41663,2621,1032, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.77  BV=1.51
    {41663,2816,1032, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.87  BV=1.41
    {50001,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50001,2703,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.80  BV=1.22
    {58327,2478,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=4.68  BV=1.12
    {58327,2673,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=4.80  BV=1.00
    {66663,2499,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.69  BV=0.92
    {66663,2703,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.80  BV=0.80
    {75001,2570,1024, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=4.73  BV=0.70
    {83326,2447,1032, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=4.67  BV=0.61
    {83326,2621,1032, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=4.77  BV=0.51
    {91663,2591,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=4.74  BV=0.40
    {100001,2519,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.70  BV=0.32
    {108326,2519,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=4.70  BV=0.20
    {116664,2478,1024, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=4.68  BV=0.12
    {125000,2519,1024, 0, 0, 0},  //TV = 3.00(11980 lines)  AV=1.70  SV=4.70  BV=-0.00
    {133326,2519,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=4.70  BV=-0.10
    {141663,2550,1024, 0, 0, 0},  //TV = 2.82(13577 lines)  AV=1.70  SV=4.72  BV=-0.20
    {149989,2591,1024, 0, 0, 0},  //TV = 2.74(14375 lines)  AV=1.70  SV=4.74  BV=-0.31
    {166663,2478,1024, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=4.68  BV=-0.39
    {174989,2550,1024, 0, 0, 0},  //TV = 2.51(16771 lines)  AV=1.70  SV=4.72  BV=-0.51
    {191663,2499,1024, 0, 0, 0},  //TV = 2.38(18369 lines)  AV=1.70  SV=4.69  BV=-0.61
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {522,2499,1024, 0, 0, 0},  //TV = 10.90(50 lines)  AV=1.70  SV=4.69  BV=7.91
    {564,2478,1024, 0, 0, 0},  //TV = 10.79(54 lines)  AV=1.70  SV=4.68  BV=7.81
    {606,2478,1024, 0, 0, 0},  //TV = 10.69(58 lines)  AV=1.70  SV=4.68  BV=7.71
    {647,2478,1024, 0, 0, 0},  //TV = 10.59(62 lines)  AV=1.70  SV=4.68  BV=7.61
    {700,2447,1032, 0, 0, 0},  //TV = 10.48(67 lines)  AV=1.70  SV=4.67  BV=7.51
    {752,2447,1024, 0, 0, 0},  //TV = 10.38(72 lines)  AV=1.70  SV=4.66  BV=7.42
    {804,2447,1032, 0, 0, 0},  //TV = 10.28(77 lines)  AV=1.70  SV=4.67  BV=7.31
    {856,2478,1024, 0, 0, 0},  //TV = 10.19(82 lines)  AV=1.70  SV=4.68  BV=7.21
    {919,2478,1024, 0, 0, 0},  //TV = 10.09(88 lines)  AV=1.70  SV=4.68  BV=7.11
    {992,2447,1024, 0, 0, 0},  //TV = 9.98(95 lines)  AV=1.70  SV=4.66  BV=7.02
    {1054,2478,1024, 0, 0, 0},  //TV = 9.89(101 lines)  AV=1.70  SV=4.68  BV=6.91
    {1127,2478,1024, 0, 0, 0},  //TV = 9.79(108 lines)  AV=1.70  SV=4.68  BV=6.81
    {1221,2447,1032, 0, 0, 0},  //TV = 9.68(117 lines)  AV=1.70  SV=4.67  BV=6.71
    {1305,2478,1024, 0, 0, 0},  //TV = 9.58(125 lines)  AV=1.70  SV=4.68  BV=6.60
    {1399,2447,1032, 0, 0, 0},  //TV = 9.48(134 lines)  AV=1.70  SV=4.67  BV=6.51
    {1503,2447,1032, 0, 0, 0},  //TV = 9.38(144 lines)  AV=1.70  SV=4.67  BV=6.41
    {1607,2447,1032, 0, 0, 0},  //TV = 9.28(154 lines)  AV=1.70  SV=4.67  BV=6.31
    {1712,2478,1024, 0, 0, 0},  //TV = 9.19(164 lines)  AV=1.70  SV=4.68  BV=6.21
    {1847,2447,1032, 0, 0, 0},  //TV = 9.08(177 lines)  AV=1.70  SV=4.67  BV=6.11
    {1973,2447,1032, 0, 0, 0},  //TV = 8.99(189 lines)  AV=1.70  SV=4.67  BV=6.01
    {2129,2447,1024, 0, 0, 0},  //TV = 8.88(204 lines)  AV=1.70  SV=4.66  BV=5.91
    {2275,2447,1032, 0, 0, 0},  //TV = 8.78(218 lines)  AV=1.70  SV=4.67  BV=5.81
    {2432,2447,1032, 0, 0, 0},  //TV = 8.68(233 lines)  AV=1.70  SV=4.67  BV=5.71
    {2619,2447,1032, 0, 0, 0},  //TV = 8.58(251 lines)  AV=1.70  SV=4.67  BV=5.60
    {2807,2447,1024, 0, 0, 0},  //TV = 8.48(269 lines)  AV=1.70  SV=4.66  BV=5.52
    {3005,2447,1024, 0, 0, 0},  //TV = 8.38(288 lines)  AV=1.70  SV=4.66  BV=5.42
    {3235,2447,1024, 0, 0, 0},  //TV = 8.27(310 lines)  AV=1.70  SV=4.66  BV=5.31
    {3454,2447,1032, 0, 0, 0},  //TV = 8.18(331 lines)  AV=1.70  SV=4.67  BV=5.20
    {3705,2447,1024, 0, 0, 0},  //TV = 8.08(355 lines)  AV=1.70  SV=4.66  BV=5.11
    {3965,2447,1024, 0, 0, 0},  //TV = 7.98(380 lines)  AV=1.70  SV=4.66  BV=5.02
    {4247,2447,1024, 0, 0, 0},  //TV = 7.88(407 lines)  AV=1.70  SV=4.66  BV=4.92
    {4539,2447,1032, 0, 0, 0},  //TV = 7.78(435 lines)  AV=1.70  SV=4.67  BV=4.81
    {4894,2447,1024, 0, 0, 0},  //TV = 7.67(469 lines)  AV=1.70  SV=4.66  BV=4.71
    {5249,2447,1024, 0, 0, 0},  //TV = 7.57(503 lines)  AV=1.70  SV=4.66  BV=4.61
    {5614,2447,1024, 0, 0, 0},  //TV = 7.48(538 lines)  AV=1.70  SV=4.66  BV=4.52
    {6010,2447,1032, 0, 0, 0},  //TV = 7.38(576 lines)  AV=1.70  SV=4.67  BV=4.41
    {6438,2447,1024, 0, 0, 0},  //TV = 7.28(617 lines)  AV=1.70  SV=4.66  BV=4.32
    {6897,2447,1024, 0, 0, 0},  //TV = 7.18(661 lines)  AV=1.70  SV=4.66  BV=4.22
    {7388,2447,1024, 0, 0, 0},  //TV = 7.08(708 lines)  AV=1.70  SV=4.66  BV=4.12
    {7920,2447,1024, 0, 0, 0},  //TV = 6.98(759 lines)  AV=1.70  SV=4.66  BV=4.02
    {8483,2447,1024, 0, 0, 0},  //TV = 6.88(813 lines)  AV=1.70  SV=4.66  BV=3.92
    {9151,2447,1024, 0, 0, 0},  //TV = 6.77(877 lines)  AV=1.70  SV=4.66  BV=3.81
    {9798,2447,1024, 0, 0, 0},  //TV = 6.67(939 lines)  AV=1.70  SV=4.66  BV=3.71
    {9996,2591,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.74  BV=3.60
    {9996,2755,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.83  BV=3.51
    {9996,2949,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.94  BV=3.40
    {9996,3154,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.03  BV=3.31
    {9996,3400,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.13  BV=3.21
    {9996,3645,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.23  BV=3.11
    {9996,3912,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.33  BV=3.01
    {9996,4157,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.43  BV=2.91
    {9996,4444,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.53  BV=2.81
    {9996,4762,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.63  BV=2.71
    {20003,2570,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.73  BV=2.61
    {20003,2755,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.83  BV=2.51
    {20003,2949,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.93  BV=2.41
    {20003,3154,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=5.02  BV=2.32
    {20003,3359,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=5.13  BV=2.21
    {20003,3594,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=5.22  BV=2.12
    {29998,2621,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.76  BV=2.00
    {29998,2785,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.84  BV=1.91
    {29998,2980,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.94  BV=1.81
    {29998,3195,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.04  BV=1.71
    {40005,2570,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.73  BV=1.61
    {40005,2755,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.83  BV=1.51
    {40005,2949,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.93  BV=1.41
    {50000,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50000,2703,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.80  BV=1.22
    {50000,2908,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.91  BV=1.11
    {59996,2591,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.75  BV=1.00
    {59996,2785,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.86  BV=0.90
    {70003,2550,1024, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=4.72  BV=0.82
    {70003,2734,1024, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=4.82  BV=0.72
    {79998,2570,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=4.73  BV=0.61
    {79998,2755,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=4.83  BV=0.51
    {90005,2621,1032, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=4.77  BV=0.40
    {100000,2519,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=4.70  BV=0.32
    {109996,2447,1032, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=4.67  BV=0.21
    {109996,2621,1032, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=4.77  BV=0.11
    {120002,2621,1024, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=4.76  BV=-0.00
    {129998,2591,1024, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=4.74  BV=-0.10
    {140004,2591,1024, 0, 0, 0},  //TV = 2.84(13418 lines)  AV=1.70  SV=4.74  BV=-0.21
    {150000,2591,1024, 0, 0, 0},  //TV = 2.74(14376 lines)  AV=1.70  SV=4.74  BV=-0.31
    {159995,2591,1024, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=4.74  BV=-0.40
    {179997,2478,1024, 0, 0, 0},  //TV = 2.47(17251 lines)  AV=1.70  SV=4.68  BV=-0.51
    {190004,2519,1024, 0, 0, 0},  //TV = 2.40(18210 lines)  AV=1.70  SV=4.70  BV=-0.61
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CAPTURE_ISO200,    //eAETableID
    121,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -6,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_200, //ISO SPEED
    sCaptureISO200PLineTable_60Hz,
    sCaptureISO200PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO400PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {490,2652,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.77  BV=7.92
    {490,2877,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.89  BV=7.80
    {490,3052,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.99  BV=7.70
    {490,3277,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.08  BV=7.61
    {490,3492,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.18  BV=7.51
    {490,3748,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.27  BV=7.42
    {490,4035,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.38  BV=7.31
    {490,4301,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.48  BV=7.21
    {490,4598,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.58  BV=7.11
    {490,4946,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.67  BV=7.02
    {533,4854,1032, 0, 0, 0},  //TV = 10.87(51 lines)  AV=1.70  SV=5.66  BV=6.91
    {564,4946,1032, 0, 0, 0},  //TV = 10.79(54 lines)  AV=1.70  SV=5.68  BV=6.80
    {606,4946,1024, 0, 0, 0},  //TV = 10.69(58 lines)  AV=1.70  SV=5.67  BV=6.71
    {647,4946,1024, 0, 0, 0},  //TV = 10.59(62 lines)  AV=1.70  SV=5.67  BV=6.62
    {700,4854,1040, 0, 0, 0},  //TV = 10.48(67 lines)  AV=1.70  SV=5.67  BV=6.51
    {752,4854,1032, 0, 0, 0},  //TV = 10.38(72 lines)  AV=1.70  SV=5.66  BV=6.42
    {804,4854,1040, 0, 0, 0},  //TV = 10.28(77 lines)  AV=1.70  SV=5.67  BV=6.31
    {867,4854,1032, 0, 0, 0},  //TV = 10.17(83 lines)  AV=1.70  SV=5.66  BV=6.21
    {919,4946,1024, 0, 0, 0},  //TV = 10.09(88 lines)  AV=1.70  SV=5.67  BV=6.11
    {992,4854,1032, 0, 0, 0},  //TV = 9.98(95 lines)  AV=1.70  SV=5.66  BV=6.02
    {1065,4854,1032, 0, 0, 0},  //TV = 9.87(102 lines)  AV=1.70  SV=5.66  BV=5.91
    {1138,4854,1040, 0, 0, 0},  //TV = 9.78(109 lines)  AV=1.70  SV=5.67  BV=5.81
    {1221,4854,1032, 0, 0, 0},  //TV = 9.68(117 lines)  AV=1.70  SV=5.66  BV=5.72
    {1305,4946,1024, 0, 0, 0},  //TV = 9.58(125 lines)  AV=1.70  SV=5.67  BV=5.61
    {1399,4854,1040, 0, 0, 0},  //TV = 9.48(134 lines)  AV=1.70  SV=5.67  BV=5.51
    {1503,4854,1040, 0, 0, 0},  //TV = 9.38(144 lines)  AV=1.70  SV=5.67  BV=5.41
    {1607,4854,1040, 0, 0, 0},  //TV = 9.28(154 lines)  AV=1.70  SV=5.67  BV=5.31
    {1722,4946,1024, 0, 0, 0},  //TV = 9.18(165 lines)  AV=1.70  SV=5.67  BV=5.21
    {1847,4854,1040, 0, 0, 0},  //TV = 9.08(177 lines)  AV=1.70  SV=5.67  BV=5.11
    {1993,4854,1032, 0, 0, 0},  //TV = 8.97(191 lines)  AV=1.70  SV=5.66  BV=5.01
    {2129,4854,1032, 0, 0, 0},  //TV = 8.88(204 lines)  AV=1.70  SV=5.66  BV=4.91
    {2275,4854,1032, 0, 0, 0},  //TV = 8.78(218 lines)  AV=1.70  SV=5.66  BV=4.82
    {2452,4854,1032, 0, 0, 0},  //TV = 8.67(235 lines)  AV=1.70  SV=5.66  BV=4.71
    {2619,4854,1032, 0, 0, 0},  //TV = 8.58(251 lines)  AV=1.70  SV=5.66  BV=4.62
    {2807,4854,1032, 0, 0, 0},  //TV = 8.48(269 lines)  AV=1.70  SV=5.66  BV=4.52
    {3005,4854,1032, 0, 0, 0},  //TV = 8.38(288 lines)  AV=1.70  SV=5.66  BV=4.42
    {3235,4854,1032, 0, 0, 0},  //TV = 8.27(310 lines)  AV=1.70  SV=5.66  BV=4.31
    {3454,4854,1040, 0, 0, 0},  //TV = 8.18(331 lines)  AV=1.70  SV=5.67  BV=4.21
    {3705,4854,1032, 0, 0, 0},  //TV = 8.08(355 lines)  AV=1.70  SV=5.66  BV=4.12
    {3965,4854,1032, 0, 0, 0},  //TV = 7.98(380 lines)  AV=1.70  SV=5.66  BV=4.02
    {4268,4854,1032, 0, 0, 0},  //TV = 7.87(409 lines)  AV=1.70  SV=5.66  BV=3.91
    {4571,4854,1032, 0, 0, 0},  //TV = 7.77(438 lines)  AV=1.70  SV=5.66  BV=3.81
    {4894,4854,1032, 0, 0, 0},  //TV = 7.67(469 lines)  AV=1.70  SV=5.66  BV=3.71
    {5249,4854,1032, 0, 0, 0},  //TV = 7.57(503 lines)  AV=1.70  SV=5.66  BV=3.61
    {5614,4854,1032, 0, 0, 0},  //TV = 7.48(538 lines)  AV=1.70  SV=5.66  BV=3.52
    {6010,4854,1032, 0, 0, 0},  //TV = 7.38(576 lines)  AV=1.70  SV=5.66  BV=3.42
    {6438,4854,1032, 0, 0, 0},  //TV = 7.28(617 lines)  AV=1.70  SV=5.66  BV=3.32
    {6897,4854,1032, 0, 0, 0},  //TV = 7.18(661 lines)  AV=1.70  SV=5.66  BV=3.22
    {7388,4854,1032, 0, 0, 0},  //TV = 7.08(708 lines)  AV=1.70  SV=5.66  BV=3.12
    {7972,4854,1032, 0, 0, 0},  //TV = 6.97(764 lines)  AV=1.70  SV=5.66  BV=3.01
    {8338,5038,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.70  BV=2.90
    {8338,5345,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.80  BV=2.81
    {8338,5704,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=5.89  BV=2.71
    {8338,6093,1040, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.00  BV=2.61
    {8338,6554,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.09  BV=2.51
    {8338,7086,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.19  BV=2.41
    {8338,7485,1040, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.29  BV=2.31
    {8338,7946,1048, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.39  BV=2.21
    {8338,8192,1088, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.49  BV=2.11
    {8338,8192,1168, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.59  BV=2.01
    {16664,4946,1040, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.69  BV=1.91
    {16664,5345,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.78  BV=1.82
    {16664,5704,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.89  BV=1.71
    {16664,6093,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=5.98  BV=1.62
    {16664,6554,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.09  BV=1.51
    {16664,7086,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.19  BV=1.41
    {25001,5038,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=5.70  BV=1.32
    {25001,5458,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=5.81  BV=1.20
    {25001,5704,1040, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=5.90  BV=1.12
    {25001,6093,1048, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=6.01  BV=1.01
    {33327,5038,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=5.70  BV=0.90
    {33327,5345,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=5.80  BV=0.81
    {33327,5704,1040, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=5.90  BV=0.70
    {41663,4946,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=5.67  BV=0.61
    {41663,5243,1040, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=5.78  BV=0.50
    {41663,5704,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=5.88  BV=0.40
    {50001,5038,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.71  BV=0.31
    {50001,5458,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.81  BV=0.20
    {58327,4946,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.68  BV=0.11
    {58327,5345,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.80  BV=-0.00
    {66663,5038,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.71  BV=-0.11
    {66663,5345,1040, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.81  BV=-0.20
    {75001,5140,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=5.74  BV=-0.31
    {83326,4946,1032, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=5.68  BV=-0.40
    {83326,5345,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=5.78  BV=-0.50
    {91663,5140,1040, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=5.75  BV=-0.61
    {100001,5038,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.72  BV=-0.70
    {108326,5038,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=5.70  BV=-0.80
    {116664,5038,1024, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=5.70  BV=-0.90
    {125000,5038,1024, 0, 0, 0},  //TV = 3.00(11980 lines)  AV=1.70  SV=5.70  BV=-1.00
    {133326,5038,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=5.70  BV=-1.10
    {141663,5038,1040, 0, 0, 0},  //TV = 2.82(13577 lines)  AV=1.70  SV=5.72  BV=-1.21
    {149989,5140,1032, 0, 0, 0},  //TV = 2.74(14375 lines)  AV=1.70  SV=5.74  BV=-1.31
    {166663,4946,1032, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=5.68  BV=-1.40
    {174989,5038,1032, 0, 0, 0},  //TV = 2.51(16771 lines)  AV=1.70  SV=5.71  BV=-1.50
    {191663,4946,1032, 0, 0, 0},  //TV = 2.38(18369 lines)  AV=1.70  SV=5.68  BV=-1.60
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {490,2652,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.77  BV=7.92
    {490,2877,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.89  BV=7.80
    {490,3052,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.99  BV=7.70
    {490,3277,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.08  BV=7.61
    {490,3492,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.18  BV=7.51
    {490,3748,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.27  BV=7.42
    {490,4035,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.38  BV=7.31
    {490,4301,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.48  BV=7.21
    {490,4598,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.58  BV=7.11
    {490,4946,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.67  BV=7.02
    {533,4854,1032, 0, 0, 0},  //TV = 10.87(51 lines)  AV=1.70  SV=5.66  BV=6.91
    {564,4946,1032, 0, 0, 0},  //TV = 10.79(54 lines)  AV=1.70  SV=5.68  BV=6.80
    {606,4946,1024, 0, 0, 0},  //TV = 10.69(58 lines)  AV=1.70  SV=5.67  BV=6.71
    {647,4946,1024, 0, 0, 0},  //TV = 10.59(62 lines)  AV=1.70  SV=5.67  BV=6.62
    {700,4854,1040, 0, 0, 0},  //TV = 10.48(67 lines)  AV=1.70  SV=5.67  BV=6.51
    {752,4854,1032, 0, 0, 0},  //TV = 10.38(72 lines)  AV=1.70  SV=5.66  BV=6.42
    {804,4854,1040, 0, 0, 0},  //TV = 10.28(77 lines)  AV=1.70  SV=5.67  BV=6.31
    {867,4854,1032, 0, 0, 0},  //TV = 10.17(83 lines)  AV=1.70  SV=5.66  BV=6.21
    {919,4946,1024, 0, 0, 0},  //TV = 10.09(88 lines)  AV=1.70  SV=5.67  BV=6.11
    {992,4854,1032, 0, 0, 0},  //TV = 9.98(95 lines)  AV=1.70  SV=5.66  BV=6.02
    {1065,4854,1032, 0, 0, 0},  //TV = 9.87(102 lines)  AV=1.70  SV=5.66  BV=5.91
    {1138,4854,1040, 0, 0, 0},  //TV = 9.78(109 lines)  AV=1.70  SV=5.67  BV=5.81
    {1221,4854,1032, 0, 0, 0},  //TV = 9.68(117 lines)  AV=1.70  SV=5.66  BV=5.72
    {1305,4946,1024, 0, 0, 0},  //TV = 9.58(125 lines)  AV=1.70  SV=5.67  BV=5.61
    {1399,4854,1040, 0, 0, 0},  //TV = 9.48(134 lines)  AV=1.70  SV=5.67  BV=5.51
    {1503,4854,1040, 0, 0, 0},  //TV = 9.38(144 lines)  AV=1.70  SV=5.67  BV=5.41
    {1607,4854,1040, 0, 0, 0},  //TV = 9.28(154 lines)  AV=1.70  SV=5.67  BV=5.31
    {1722,4946,1024, 0, 0, 0},  //TV = 9.18(165 lines)  AV=1.70  SV=5.67  BV=5.21
    {1847,4854,1040, 0, 0, 0},  //TV = 9.08(177 lines)  AV=1.70  SV=5.67  BV=5.11
    {1993,4854,1032, 0, 0, 0},  //TV = 8.97(191 lines)  AV=1.70  SV=5.66  BV=5.01
    {2129,4854,1032, 0, 0, 0},  //TV = 8.88(204 lines)  AV=1.70  SV=5.66  BV=4.91
    {2275,4854,1032, 0, 0, 0},  //TV = 8.78(218 lines)  AV=1.70  SV=5.66  BV=4.82
    {2452,4854,1032, 0, 0, 0},  //TV = 8.67(235 lines)  AV=1.70  SV=5.66  BV=4.71
    {2619,4854,1032, 0, 0, 0},  //TV = 8.58(251 lines)  AV=1.70  SV=5.66  BV=4.62
    {2807,4854,1032, 0, 0, 0},  //TV = 8.48(269 lines)  AV=1.70  SV=5.66  BV=4.52
    {3005,4854,1032, 0, 0, 0},  //TV = 8.38(288 lines)  AV=1.70  SV=5.66  BV=4.42
    {3235,4854,1032, 0, 0, 0},  //TV = 8.27(310 lines)  AV=1.70  SV=5.66  BV=4.31
    {3454,4854,1040, 0, 0, 0},  //TV = 8.18(331 lines)  AV=1.70  SV=5.67  BV=4.21
    {3705,4854,1032, 0, 0, 0},  //TV = 8.08(355 lines)  AV=1.70  SV=5.66  BV=4.12
    {3965,4854,1032, 0, 0, 0},  //TV = 7.98(380 lines)  AV=1.70  SV=5.66  BV=4.02
    {4268,4854,1032, 0, 0, 0},  //TV = 7.87(409 lines)  AV=1.70  SV=5.66  BV=3.91
    {4571,4854,1032, 0, 0, 0},  //TV = 7.77(438 lines)  AV=1.70  SV=5.66  BV=3.81
    {4894,4854,1032, 0, 0, 0},  //TV = 7.67(469 lines)  AV=1.70  SV=5.66  BV=3.71
    {5249,4854,1032, 0, 0, 0},  //TV = 7.57(503 lines)  AV=1.70  SV=5.66  BV=3.61
    {5614,4854,1032, 0, 0, 0},  //TV = 7.48(538 lines)  AV=1.70  SV=5.66  BV=3.52
    {6010,4854,1032, 0, 0, 0},  //TV = 7.38(576 lines)  AV=1.70  SV=5.66  BV=3.42
    {6438,4854,1032, 0, 0, 0},  //TV = 7.28(617 lines)  AV=1.70  SV=5.66  BV=3.32
    {6897,4854,1032, 0, 0, 0},  //TV = 7.18(661 lines)  AV=1.70  SV=5.66  BV=3.22
    {7388,4854,1032, 0, 0, 0},  //TV = 7.08(708 lines)  AV=1.70  SV=5.66  BV=3.12
    {7972,4854,1032, 0, 0, 0},  //TV = 6.97(764 lines)  AV=1.70  SV=5.66  BV=3.01
    {8536,4854,1032, 0, 0, 0},  //TV = 6.87(818 lines)  AV=1.70  SV=5.66  BV=2.91
    {9151,4854,1032, 0, 0, 0},  //TV = 6.77(877 lines)  AV=1.70  SV=5.66  BV=2.81
    {9798,4854,1032, 0, 0, 0},  //TV = 6.67(939 lines)  AV=1.70  SV=5.66  BV=2.71
    {9996,5140,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.73  BV=2.61
    {9996,5458,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.83  BV=2.51
    {9996,5827,1040, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=5.93  BV=2.41
    {9996,6246,1040, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.03  BV=2.31
    {9996,6717,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.13  BV=2.22
    {9996,7281,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.23  BV=2.11
    {9996,7711,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.32  BV=2.02
    {9996,8192,1040, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.42  BV=1.92
    {9996,8192,1120, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.53  BV=1.81
    {9996,8192,1200, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.63  BV=1.71
    {20003,5140,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=5.73  BV=1.61
    {20003,5458,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=5.83  BV=1.51
    {20003,5827,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=5.92  BV=1.42
    {20003,6246,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.02  BV=1.32
    {20003,6717,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.13  BV=1.21
    {20003,7281,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.23  BV=1.11
    {29998,5140,1040, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.75  BV=1.00
    {29998,5581,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.85  BV=0.91
    {29998,5960,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=5.95  BV=0.80
    {29998,6390,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.05  BV=0.70
    {40005,5140,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=5.73  BV=0.61
    {40005,5458,1040, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=5.84  BV=0.50
    {40005,5827,1040, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=5.93  BV=0.41
    {50000,5038,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.71  BV=0.31
    {50000,5458,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.81  BV=0.20
    {50000,5827,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.91  BV=0.11
    {59996,5243,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.76  BV=-0.00
    {59996,5581,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.86  BV=-0.10
    {70003,5140,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=5.74  BV=-0.21
    {70003,5458,1040, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=5.84  BV=-0.30
    {79998,5140,1032, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=5.74  BV=-0.40
    {90005,4946,1024, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=5.67  BV=-0.50
    {90005,5243,1032, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=5.77  BV=-0.60
    {100000,5038,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.72  BV=-0.70
    {109996,4946,1032, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=5.68  BV=-0.80
    {109996,5345,1024, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=5.78  BV=-0.90
    {120002,5243,1024, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=5.76  BV=-1.00
    {129998,5140,1032, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=5.74  BV=-1.10
    {140004,5140,1032, 0, 0, 0},  //TV = 2.84(13418 lines)  AV=1.70  SV=5.74  BV=-1.21
    {150000,5140,1032, 0, 0, 0},  //TV = 2.74(14376 lines)  AV=1.70  SV=5.74  BV=-1.31
    {159995,5140,1032, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=5.74  BV=-1.40
    {179997,4946,1024, 0, 0, 0},  //TV = 2.47(17251 lines)  AV=1.70  SV=5.67  BV=-1.50
    {190004,5038,1024, 0, 0, 0},  //TV = 2.40(18210 lines)  AV=1.70  SV=5.70  BV=-1.61
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CAPTURE_ISO400,    //eAETableID
    131,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -16,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_400, //ISO SPEED
    sCaptureISO400PLineTable_60Hz,
    sCaptureISO400PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO800PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {490,2652,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.77  BV=7.92
    {490,2877,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.89  BV=7.80
    {490,3052,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.99  BV=7.70
    {490,3277,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.08  BV=7.61
    {490,3492,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.18  BV=7.51
    {490,3748,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.27  BV=7.42
    {490,4035,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.38  BV=7.31
    {490,4301,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.48  BV=7.21
    {490,4598,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.58  BV=7.11
    {490,4946,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.67  BV=7.02
    {490,5243,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.78  BV=6.91
    {490,5704,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.88  BV=6.81
    {490,6093,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.98  BV=6.71
    {490,6554,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.08  BV=6.61
    {490,6902,1048, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.19  BV=6.50
    {490,7485,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.28  BV=6.41
    {490,7946,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.38  BV=6.31
    {490,8192,1080, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.48  BV=6.21
    {490,8192,1160, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.58  BV=6.11
    {490,8192,1240, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.68  BV=6.01
    {512,8192,1280, 0, 0, 0},  //TV = 10.93(49 lines)  AV=1.70  SV=6.72  BV=5.91
    {543,8192,1288, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=6.73  BV=5.81
    {585,8192,1288, 0, 0, 0},  //TV = 10.74(56 lines)  AV=1.70  SV=6.73  BV=5.70
    {627,8192,1280, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=6.72  BV=5.61
    {668,8192,1288, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=6.73  BV=5.51
    {720,8192,1280, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=6.72  BV=5.41
    {773,8192,1280, 0, 0, 0},  //TV = 10.34(74 lines)  AV=1.70  SV=6.72  BV=5.31
    {825,8192,1288, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=6.73  BV=5.21
    {887,8192,1280, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=6.72  BV=5.11
    {950,8192,1288, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=6.73  BV=5.00
    {1023,8192,1280, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=6.72  BV=4.91
    {1086,8192,1288, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=6.73  BV=4.81
    {1169,8192,1280, 0, 0, 0},  //TV = 9.74(112 lines)  AV=1.70  SV=6.72  BV=4.71
    {1263,8192,1280, 0, 0, 0},  //TV = 9.63(121 lines)  AV=1.70  SV=6.72  BV=4.60
    {1346,8192,1280, 0, 0, 0},  //TV = 9.54(129 lines)  AV=1.70  SV=6.72  BV=4.51
    {1440,8192,1288, 0, 0, 0},  //TV = 9.44(138 lines)  AV=1.70  SV=6.73  BV=4.40
    {1545,8192,1280, 0, 0, 0},  //TV = 9.34(148 lines)  AV=1.70  SV=6.72  BV=4.31
    {1660,8192,1280, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=6.72  BV=4.21
    {1774,8192,1280, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=6.72  BV=4.11
    {1910,8192,1280, 0, 0, 0},  //TV = 9.03(183 lines)  AV=1.70  SV=6.72  BV=4.01
    {2046,8192,1280, 0, 0, 0},  //TV = 8.93(196 lines)  AV=1.70  SV=6.72  BV=3.91
    {2181,8192,1280, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=6.72  BV=3.81
    {2348,8192,1280, 0, 0, 0},  //TV = 8.73(225 lines)  AV=1.70  SV=6.72  BV=3.71
    {2515,8192,1280, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=6.72  BV=3.61
    {2692,8192,1280, 0, 0, 0},  //TV = 8.54(258 lines)  AV=1.70  SV=6.72  BV=3.51
    {2901,8192,1280, 0, 0, 0},  //TV = 8.43(278 lines)  AV=1.70  SV=6.72  BV=3.40
    {3099,8192,1280, 0, 0, 0},  //TV = 8.33(297 lines)  AV=1.70  SV=6.72  BV=3.31
    {3319,8192,1280, 0, 0, 0},  //TV = 8.24(318 lines)  AV=1.70  SV=6.72  BV=3.21
    {3558,8192,1280, 0, 0, 0},  //TV = 8.13(341 lines)  AV=1.70  SV=6.72  BV=3.11
    {3809,8192,1280, 0, 0, 0},  //TV = 8.04(365 lines)  AV=1.70  SV=6.72  BV=3.01
    {4101,8192,1280, 0, 0, 0},  //TV = 7.93(393 lines)  AV=1.70  SV=6.72  BV=2.90
    {4393,8192,1280, 0, 0, 0},  //TV = 7.83(421 lines)  AV=1.70  SV=6.72  BV=2.80
    {4696,8192,1280, 0, 0, 0},  //TV = 7.73(450 lines)  AV=1.70  SV=6.72  BV=2.71
    {5030,8192,1280, 0, 0, 0},  //TV = 7.64(482 lines)  AV=1.70  SV=6.72  BV=2.61
    {5395,8192,1280, 0, 0, 0},  //TV = 7.53(517 lines)  AV=1.70  SV=6.72  BV=2.51
    {5771,8192,1280, 0, 0, 0},  //TV = 7.44(553 lines)  AV=1.70  SV=6.72  BV=2.41
    {6230,8192,1280, 0, 0, 0},  //TV = 7.33(597 lines)  AV=1.70  SV=6.72  BV=2.30
    {6668,8192,1280, 0, 0, 0},  //TV = 7.23(639 lines)  AV=1.70  SV=6.72  BV=2.20
    {7137,8192,1280, 0, 0, 0},  //TV = 7.13(684 lines)  AV=1.70  SV=6.72  BV=2.10
    {7649,8192,1280, 0, 0, 0},  //TV = 7.03(733 lines)  AV=1.70  SV=6.72  BV=2.00
    {8191,8192,1280, 0, 0, 0},  //TV = 6.93(785 lines)  AV=1.70  SV=6.72  BV=1.91
    {8338,8192,1344, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.79  BV=1.81
    {8338,8192,1440, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.89  BV=1.71
    {8338,8192,1544, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.99  BV=1.61
    {8338,8192,1656, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.09  BV=1.51
    {8338,8192,1776, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.19  BV=1.41
    {8338,8192,1896, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.29  BV=1.31
    {8338,8192,2032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.39  BV=1.21
    {8338,8192,2184, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.49  BV=1.11
    {8338,8192,2336, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.59  BV=1.01
    {8338,8192,2504, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.69  BV=0.91
    {16664,8192,1352, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.80  BV=0.80
    {16664,8192,1448, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.90  BV=0.70
    {16664,8192,1552, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.00  BV=0.60
    {16664,8192,1664, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.10  BV=0.50
    {16664,8192,1784, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.20  BV=0.40
    {16664,8192,1904, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.30  BV=0.31
    {25001,8192,1360, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=6.81  BV=0.21
    {25001,8192,1456, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=6.91  BV=0.11
    {25001,8192,1576, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=7.02  BV=-0.00
    {25001,8192,1688, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=7.12  BV=-0.10
    {33327,8192,1360, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=6.81  BV=-0.21
    {33327,8192,1456, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=6.91  BV=-0.31
    {33327,8192,1560, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=7.01  BV=-0.40
    {41663,8192,1336, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=6.78  BV=-0.50
    {41663,8192,1432, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=6.88  BV=-0.60
    {50001,8192,1280, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.72  BV=-0.70
    {50001,8192,1368, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.82  BV=-0.80
    {50001,8192,1464, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.92  BV=-0.90
    {58327,8192,1352, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=6.80  BV=-1.01
    {58327,8192,1448, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=6.90  BV=-1.10
    {66663,8192,1352, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.80  BV=-1.20
    {75001,8192,1288, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.73  BV=-1.30
    {75001,8192,1384, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.84  BV=-1.40
    {83326,8192,1336, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=6.78  BV=-1.50
    {91663,8192,1296, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=6.74  BV=-1.60
    {100001,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {100001,8192,1368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.82  BV=-1.80
    {108326,8192,1352, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.80  BV=-1.90
    {116664,8192,1344, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=6.79  BV=-2.00
    {125000,8192,1344, 0, 0, 0},  //TV = 3.00(11980 lines)  AV=1.70  SV=6.79  BV=-2.10
    {133326,8192,1352, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=6.80  BV=-2.20
    {149989,8192,1288, 0, 0, 0},  //TV = 2.74(14375 lines)  AV=1.70  SV=6.73  BV=-2.30
    {158326,8192,1312, 0, 0, 0},  //TV = 2.66(15174 lines)  AV=1.70  SV=6.76  BV=-2.40
    {166663,8192,1336, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=6.78  BV=-2.50
    {183326,8192,1296, 0, 0, 0},  //TV = 2.45(17570 lines)  AV=1.70  SV=6.74  BV=-2.60
    {191663,8192,1328, 0, 0, 0},  //TV = 2.38(18369 lines)  AV=1.70  SV=6.78  BV=-2.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {490,2652,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.77  BV=7.92
    {490,2877,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.89  BV=7.80
    {490,3052,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.99  BV=7.70
    {490,3277,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.08  BV=7.61
    {490,3492,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.18  BV=7.51
    {490,3748,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.27  BV=7.42
    {490,4035,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.38  BV=7.31
    {490,4301,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.48  BV=7.21
    {490,4598,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.58  BV=7.11
    {490,4946,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.67  BV=7.02
    {490,5243,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.78  BV=6.91
    {490,5704,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.88  BV=6.81
    {490,6093,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.98  BV=6.71
    {490,6554,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.08  BV=6.61
    {490,6902,1048, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.19  BV=6.50
    {490,7485,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.28  BV=6.41
    {490,7946,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.38  BV=6.31
    {490,8192,1080, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.48  BV=6.21
    {490,8192,1160, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.58  BV=6.11
    {490,8192,1240, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.68  BV=6.01
    {512,8192,1280, 0, 0, 0},  //TV = 10.93(49 lines)  AV=1.70  SV=6.72  BV=5.91
    {543,8192,1288, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=6.73  BV=5.81
    {585,8192,1288, 0, 0, 0},  //TV = 10.74(56 lines)  AV=1.70  SV=6.73  BV=5.70
    {627,8192,1280, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=6.72  BV=5.61
    {668,8192,1288, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=6.73  BV=5.51
    {720,8192,1280, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=6.72  BV=5.41
    {773,8192,1280, 0, 0, 0},  //TV = 10.34(74 lines)  AV=1.70  SV=6.72  BV=5.31
    {825,8192,1288, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=6.73  BV=5.21
    {887,8192,1280, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=6.72  BV=5.11
    {950,8192,1288, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=6.73  BV=5.00
    {1023,8192,1280, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=6.72  BV=4.91
    {1086,8192,1288, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=6.73  BV=4.81
    {1169,8192,1280, 0, 0, 0},  //TV = 9.74(112 lines)  AV=1.70  SV=6.72  BV=4.71
    {1263,8192,1280, 0, 0, 0},  //TV = 9.63(121 lines)  AV=1.70  SV=6.72  BV=4.60
    {1346,8192,1280, 0, 0, 0},  //TV = 9.54(129 lines)  AV=1.70  SV=6.72  BV=4.51
    {1440,8192,1288, 0, 0, 0},  //TV = 9.44(138 lines)  AV=1.70  SV=6.73  BV=4.40
    {1545,8192,1280, 0, 0, 0},  //TV = 9.34(148 lines)  AV=1.70  SV=6.72  BV=4.31
    {1660,8192,1280, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=6.72  BV=4.21
    {1774,8192,1280, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=6.72  BV=4.11
    {1910,8192,1280, 0, 0, 0},  //TV = 9.03(183 lines)  AV=1.70  SV=6.72  BV=4.01
    {2046,8192,1280, 0, 0, 0},  //TV = 8.93(196 lines)  AV=1.70  SV=6.72  BV=3.91
    {2181,8192,1280, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=6.72  BV=3.81
    {2348,8192,1280, 0, 0, 0},  //TV = 8.73(225 lines)  AV=1.70  SV=6.72  BV=3.71
    {2515,8192,1280, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=6.72  BV=3.61
    {2692,8192,1280, 0, 0, 0},  //TV = 8.54(258 lines)  AV=1.70  SV=6.72  BV=3.51
    {2901,8192,1280, 0, 0, 0},  //TV = 8.43(278 lines)  AV=1.70  SV=6.72  BV=3.40
    {3099,8192,1280, 0, 0, 0},  //TV = 8.33(297 lines)  AV=1.70  SV=6.72  BV=3.31
    {3319,8192,1280, 0, 0, 0},  //TV = 8.24(318 lines)  AV=1.70  SV=6.72  BV=3.21
    {3558,8192,1280, 0, 0, 0},  //TV = 8.13(341 lines)  AV=1.70  SV=6.72  BV=3.11
    {3809,8192,1280, 0, 0, 0},  //TV = 8.04(365 lines)  AV=1.70  SV=6.72  BV=3.01
    {4101,8192,1280, 0, 0, 0},  //TV = 7.93(393 lines)  AV=1.70  SV=6.72  BV=2.90
    {4393,8192,1280, 0, 0, 0},  //TV = 7.83(421 lines)  AV=1.70  SV=6.72  BV=2.80
    {4696,8192,1280, 0, 0, 0},  //TV = 7.73(450 lines)  AV=1.70  SV=6.72  BV=2.71
    {5030,8192,1280, 0, 0, 0},  //TV = 7.64(482 lines)  AV=1.70  SV=6.72  BV=2.61
    {5395,8192,1280, 0, 0, 0},  //TV = 7.53(517 lines)  AV=1.70  SV=6.72  BV=2.51
    {5771,8192,1280, 0, 0, 0},  //TV = 7.44(553 lines)  AV=1.70  SV=6.72  BV=2.41
    {6230,8192,1280, 0, 0, 0},  //TV = 7.33(597 lines)  AV=1.70  SV=6.72  BV=2.30
    {6668,8192,1280, 0, 0, 0},  //TV = 7.23(639 lines)  AV=1.70  SV=6.72  BV=2.20
    {7137,8192,1280, 0, 0, 0},  //TV = 7.13(684 lines)  AV=1.70  SV=6.72  BV=2.10
    {7649,8192,1280, 0, 0, 0},  //TV = 7.03(733 lines)  AV=1.70  SV=6.72  BV=2.00
    {8191,8192,1280, 0, 0, 0},  //TV = 6.93(785 lines)  AV=1.70  SV=6.72  BV=1.91
    {8775,8192,1280, 0, 0, 0},  //TV = 6.83(841 lines)  AV=1.70  SV=6.72  BV=1.81
    {9402,8192,1280, 0, 0, 0},  //TV = 6.73(901 lines)  AV=1.70  SV=6.72  BV=1.71
    {9996,8192,1288, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.73  BV=1.61
    {9996,8192,1376, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.83  BV=1.51
    {9996,8192,1480, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.93  BV=1.41
    {9996,8192,1584, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.03  BV=1.31
    {9996,8192,1696, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.13  BV=1.21
    {9996,8192,1816, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.23  BV=1.11
    {9996,8192,1952, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.33  BV=1.01
    {9996,8192,2088, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.43  BV=0.91
    {9996,8192,2240, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.53  BV=0.81
    {9996,8192,2416, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.64  BV=0.70
    {20003,8192,1288, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.73  BV=0.61
    {20003,8192,1384, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.84  BV=0.50
    {20003,8192,1480, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.93  BV=0.41
    {20003,8192,1592, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=7.04  BV=0.30
    {20003,8192,1704, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=7.14  BV=0.20
    {20003,8192,1824, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=7.23  BV=0.11
    {29998,8192,1312, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.76  BV=-0.00
    {29998,8192,1408, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.86  BV=-0.10
    {29998,8192,1504, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.96  BV=-0.20
    {29998,8192,1616, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=7.06  BV=-0.30
    {40005,8192,1296, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.74  BV=-0.40
    {40005,8192,1392, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.84  BV=-0.50
    {40005,8192,1488, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.94  BV=-0.60
    {50000,8192,1280, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.72  BV=-0.70
    {50000,8192,1368, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.82  BV=-0.80
    {50000,8192,1464, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.92  BV=-0.90
    {59996,8192,1312, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.76  BV=-1.00
    {59996,8192,1408, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.86  BV=-1.10
    {70003,8192,1288, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.73  BV=-1.20
    {70003,8192,1384, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.84  BV=-1.30
    {79998,8192,1296, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.74  BV=-1.40
    {79998,8192,1392, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.84  BV=-1.50
    {90005,8192,1320, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=6.77  BV=-1.60
    {100000,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {100000,8192,1368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.82  BV=-1.80
    {109996,8192,1336, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=6.78  BV=-1.90
    {120002,8192,1312, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=6.76  BV=-2.00
    {129998,8192,1296, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=6.74  BV=-2.10
    {140004,8192,1288, 0, 0, 0},  //TV = 2.84(13418 lines)  AV=1.70  SV=6.73  BV=-2.20
    {150000,8192,1288, 0, 0, 0},  //TV = 2.74(14376 lines)  AV=1.70  SV=6.73  BV=-2.30
    {159995,8192,1296, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=6.74  BV=-2.40
    {170002,8192,1304, 0, 0, 0},  //TV = 2.56(16293 lines)  AV=1.70  SV=6.75  BV=-2.50
    {179997,8192,1320, 0, 0, 0},  //TV = 2.47(17251 lines)  AV=1.70  SV=6.77  BV=-2.60
    {190004,8192,1344, 0, 0, 0},  //TV = 2.40(18210 lines)  AV=1.70  SV=6.79  BV=-2.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CAPTURE_ISO800,    //eAETableID
    142,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -27,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_800, //ISO SPEED
    sCaptureISO800PLineTable_60Hz,
    sCaptureISO800PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureISO1600PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {490,2652,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.77  BV=7.92
    {490,2877,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.89  BV=7.80
    {490,3052,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.99  BV=7.70
    {490,3277,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.08  BV=7.61
    {490,3492,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.18  BV=7.51
    {490,3748,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.27  BV=7.42
    {490,4035,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.38  BV=7.31
    {490,4301,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.48  BV=7.21
    {490,4598,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.58  BV=7.11
    {490,4946,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.67  BV=7.02
    {490,5243,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.78  BV=6.91
    {490,5704,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.88  BV=6.81
    {490,6093,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.98  BV=6.71
    {490,6554,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.08  BV=6.61
    {490,6902,1048, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.19  BV=6.50
    {490,7485,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.28  BV=6.41
    {490,7946,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.38  BV=6.31
    {490,8192,1080, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.48  BV=6.21
    {490,8192,1160, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.58  BV=6.11
    {490,8192,1240, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.68  BV=6.01
    {512,8192,1280, 0, 0, 0},  //TV = 10.93(49 lines)  AV=1.70  SV=6.72  BV=5.91
    {543,8192,1288, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=6.73  BV=5.81
    {585,8192,1288, 0, 0, 0},  //TV = 10.74(56 lines)  AV=1.70  SV=6.73  BV=5.70
    {627,8192,1280, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=6.72  BV=5.61
    {668,8192,1288, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=6.73  BV=5.51
    {720,8192,1280, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=6.72  BV=5.41
    {773,8192,1280, 0, 0, 0},  //TV = 10.34(74 lines)  AV=1.70  SV=6.72  BV=5.31
    {825,8192,1288, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=6.73  BV=5.21
    {887,8192,1280, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=6.72  BV=5.11
    {950,8192,1288, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=6.73  BV=5.00
    {1023,8192,1280, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=6.72  BV=4.91
    {1086,8192,1288, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=6.73  BV=4.81
    {1169,8192,1280, 0, 0, 0},  //TV = 9.74(112 lines)  AV=1.70  SV=6.72  BV=4.71
    {1263,8192,1280, 0, 0, 0},  //TV = 9.63(121 lines)  AV=1.70  SV=6.72  BV=4.60
    {1346,8192,1280, 0, 0, 0},  //TV = 9.54(129 lines)  AV=1.70  SV=6.72  BV=4.51
    {1440,8192,1288, 0, 0, 0},  //TV = 9.44(138 lines)  AV=1.70  SV=6.73  BV=4.40
    {1545,8192,1280, 0, 0, 0},  //TV = 9.34(148 lines)  AV=1.70  SV=6.72  BV=4.31
    {1660,8192,1280, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=6.72  BV=4.21
    {1774,8192,1280, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=6.72  BV=4.11
    {1910,8192,1280, 0, 0, 0},  //TV = 9.03(183 lines)  AV=1.70  SV=6.72  BV=4.01
    {2046,8192,1280, 0, 0, 0},  //TV = 8.93(196 lines)  AV=1.70  SV=6.72  BV=3.91
    {2181,8192,1280, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=6.72  BV=3.81
    {2348,8192,1280, 0, 0, 0},  //TV = 8.73(225 lines)  AV=1.70  SV=6.72  BV=3.71
    {2515,8192,1280, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=6.72  BV=3.61
    {2692,8192,1280, 0, 0, 0},  //TV = 8.54(258 lines)  AV=1.70  SV=6.72  BV=3.51
    {2901,8192,1280, 0, 0, 0},  //TV = 8.43(278 lines)  AV=1.70  SV=6.72  BV=3.40
    {3099,8192,1280, 0, 0, 0},  //TV = 8.33(297 lines)  AV=1.70  SV=6.72  BV=3.31
    {3319,8192,1280, 0, 0, 0},  //TV = 8.24(318 lines)  AV=1.70  SV=6.72  BV=3.21
    {3558,8192,1280, 0, 0, 0},  //TV = 8.13(341 lines)  AV=1.70  SV=6.72  BV=3.11
    {3809,8192,1280, 0, 0, 0},  //TV = 8.04(365 lines)  AV=1.70  SV=6.72  BV=3.01
    {4101,8192,1280, 0, 0, 0},  //TV = 7.93(393 lines)  AV=1.70  SV=6.72  BV=2.90
    {4393,8192,1280, 0, 0, 0},  //TV = 7.83(421 lines)  AV=1.70  SV=6.72  BV=2.80
    {4696,8192,1280, 0, 0, 0},  //TV = 7.73(450 lines)  AV=1.70  SV=6.72  BV=2.71
    {5030,8192,1280, 0, 0, 0},  //TV = 7.64(482 lines)  AV=1.70  SV=6.72  BV=2.61
    {5395,8192,1280, 0, 0, 0},  //TV = 7.53(517 lines)  AV=1.70  SV=6.72  BV=2.51
    {5771,8192,1280, 0, 0, 0},  //TV = 7.44(553 lines)  AV=1.70  SV=6.72  BV=2.41
    {6230,8192,1280, 0, 0, 0},  //TV = 7.33(597 lines)  AV=1.70  SV=6.72  BV=2.30
    {6668,8192,1280, 0, 0, 0},  //TV = 7.23(639 lines)  AV=1.70  SV=6.72  BV=2.20
    {7137,8192,1280, 0, 0, 0},  //TV = 7.13(684 lines)  AV=1.70  SV=6.72  BV=2.10
    {7649,8192,1280, 0, 0, 0},  //TV = 7.03(733 lines)  AV=1.70  SV=6.72  BV=2.00
    {8191,8192,1280, 0, 0, 0},  //TV = 6.93(785 lines)  AV=1.70  SV=6.72  BV=1.91
    {8338,8192,1344, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.79  BV=1.81
    {8338,8192,1440, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.89  BV=1.71
    {8338,8192,1544, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=6.99  BV=1.61
    {8338,8192,1656, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.09  BV=1.51
    {8338,8192,1776, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.19  BV=1.41
    {8338,8192,1896, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.29  BV=1.31
    {8338,8192,2032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.39  BV=1.21
    {8338,8192,2184, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.49  BV=1.11
    {8338,8192,2336, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.59  BV=1.01
    {8338,8192,2504, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=7.69  BV=0.91
    {16664,8192,1352, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.80  BV=0.80
    {16664,8192,1448, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=6.90  BV=0.70
    {16664,8192,1552, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.00  BV=0.60
    {16664,8192,1664, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.10  BV=0.50
    {16664,8192,1784, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.20  BV=0.40
    {16664,8192,1904, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=7.30  BV=0.31
    {25001,8192,1360, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=6.81  BV=0.21
    {25001,8192,1456, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=6.91  BV=0.11
    {25001,8192,1576, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=7.02  BV=-0.00
    {25001,8192,1688, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=7.12  BV=-0.10
    {33327,8192,1360, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=6.81  BV=-0.21
    {33327,8192,1456, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=6.91  BV=-0.31
    {33327,8192,1560, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=7.01  BV=-0.40
    {41663,8192,1336, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=6.78  BV=-0.50
    {41663,8192,1432, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=6.88  BV=-0.60
    {50001,8192,1280, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.72  BV=-0.70
    {50001,8192,1368, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.82  BV=-0.80
    {50001,8192,1464, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.92  BV=-0.90
    {58327,8192,1352, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=6.80  BV=-1.01
    {58327,8192,1448, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=6.90  BV=-1.10
    {66663,8192,1352, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.80  BV=-1.20
    {75001,8192,1288, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.73  BV=-1.30
    {75001,8192,1384, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.84  BV=-1.40
    {83326,8192,1336, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=6.78  BV=-1.50
    {91663,8192,1296, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=6.74  BV=-1.60
    {100001,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {100001,8192,1368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.82  BV=-1.80
    {108326,8192,1352, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.80  BV=-1.90
    {116664,8192,1344, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=6.79  BV=-2.00
    {125000,8192,1344, 0, 0, 0},  //TV = 3.00(11980 lines)  AV=1.70  SV=6.79  BV=-2.10
    {133326,8192,1352, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=6.80  BV=-2.20
    {149989,8192,1288, 0, 0, 0},  //TV = 2.74(14375 lines)  AV=1.70  SV=6.73  BV=-2.30
    {158326,8192,1312, 0, 0, 0},  //TV = 2.66(15174 lines)  AV=1.70  SV=6.76  BV=-2.40
    {166663,8192,1336, 0, 0, 0},  //TV = 2.58(15973 lines)  AV=1.70  SV=6.78  BV=-2.50
    {183326,8192,1296, 0, 0, 0},  //TV = 2.45(17570 lines)  AV=1.70  SV=6.74  BV=-2.60
    {191663,8192,1328, 0, 0, 0},  //TV = 2.38(18369 lines)  AV=1.70  SV=6.78  BV=-2.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {490,1249,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.69  BV=9.00
    {490,1331,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.78  BV=8.91
    {490,1423,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.88  BV=8.82
    {490,1526,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=3.98  BV=8.71
    {490,1638,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.08  BV=8.61
    {490,1751,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.17  BV=8.52
    {490,1884,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.28  BV=8.41
    {490,2017,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.38  BV=8.31
    {490,2150,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.48  BV=8.21
    {490,2324,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.58  BV=8.11
    {490,2478,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.68  BV=8.02
    {490,2652,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.77  BV=7.92
    {490,2877,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.89  BV=7.80
    {490,3052,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=4.99  BV=7.70
    {490,3277,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.08  BV=7.61
    {490,3492,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.18  BV=7.51
    {490,3748,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.27  BV=7.42
    {490,4035,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.38  BV=7.31
    {490,4301,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.48  BV=7.21
    {490,4598,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.58  BV=7.11
    {490,4946,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.67  BV=7.02
    {490,5243,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.78  BV=6.91
    {490,5704,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.88  BV=6.81
    {490,6093,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=5.98  BV=6.71
    {490,6554,1024, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.08  BV=6.61
    {490,6902,1048, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.19  BV=6.50
    {490,7485,1032, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.28  BV=6.41
    {490,7946,1040, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.38  BV=6.31
    {490,8192,1080, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.48  BV=6.21
    {490,8192,1160, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.58  BV=6.11
    {490,8192,1240, 0, 0, 0},  //TV = 10.99(46 lines)  AV=1.70  SV=6.68  BV=6.01
    {512,8192,1280, 0, 0, 0},  //TV = 10.93(49 lines)  AV=1.70  SV=6.72  BV=5.91
    {543,8192,1288, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=6.73  BV=5.81
    {585,8192,1288, 0, 0, 0},  //TV = 10.74(56 lines)  AV=1.70  SV=6.73  BV=5.70
    {627,8192,1280, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=6.72  BV=5.61
    {668,8192,1288, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=6.73  BV=5.51
    {720,8192,1280, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=6.72  BV=5.41
    {773,8192,1280, 0, 0, 0},  //TV = 10.34(74 lines)  AV=1.70  SV=6.72  BV=5.31
    {825,8192,1288, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=6.73  BV=5.21
    {887,8192,1280, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=6.72  BV=5.11
    {950,8192,1288, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=6.73  BV=5.00
    {1023,8192,1280, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=6.72  BV=4.91
    {1086,8192,1288, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=6.73  BV=4.81
    {1169,8192,1280, 0, 0, 0},  //TV = 9.74(112 lines)  AV=1.70  SV=6.72  BV=4.71
    {1263,8192,1280, 0, 0, 0},  //TV = 9.63(121 lines)  AV=1.70  SV=6.72  BV=4.60
    {1346,8192,1280, 0, 0, 0},  //TV = 9.54(129 lines)  AV=1.70  SV=6.72  BV=4.51
    {1440,8192,1288, 0, 0, 0},  //TV = 9.44(138 lines)  AV=1.70  SV=6.73  BV=4.40
    {1545,8192,1280, 0, 0, 0},  //TV = 9.34(148 lines)  AV=1.70  SV=6.72  BV=4.31
    {1660,8192,1280, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=6.72  BV=4.21
    {1774,8192,1280, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=6.72  BV=4.11
    {1910,8192,1280, 0, 0, 0},  //TV = 9.03(183 lines)  AV=1.70  SV=6.72  BV=4.01
    {2046,8192,1280, 0, 0, 0},  //TV = 8.93(196 lines)  AV=1.70  SV=6.72  BV=3.91
    {2181,8192,1280, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=6.72  BV=3.81
    {2348,8192,1280, 0, 0, 0},  //TV = 8.73(225 lines)  AV=1.70  SV=6.72  BV=3.71
    {2515,8192,1280, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=6.72  BV=3.61
    {2692,8192,1280, 0, 0, 0},  //TV = 8.54(258 lines)  AV=1.70  SV=6.72  BV=3.51
    {2901,8192,1280, 0, 0, 0},  //TV = 8.43(278 lines)  AV=1.70  SV=6.72  BV=3.40
    {3099,8192,1280, 0, 0, 0},  //TV = 8.33(297 lines)  AV=1.70  SV=6.72  BV=3.31
    {3319,8192,1280, 0, 0, 0},  //TV = 8.24(318 lines)  AV=1.70  SV=6.72  BV=3.21
    {3558,8192,1280, 0, 0, 0},  //TV = 8.13(341 lines)  AV=1.70  SV=6.72  BV=3.11
    {3809,8192,1280, 0, 0, 0},  //TV = 8.04(365 lines)  AV=1.70  SV=6.72  BV=3.01
    {4101,8192,1280, 0, 0, 0},  //TV = 7.93(393 lines)  AV=1.70  SV=6.72  BV=2.90
    {4393,8192,1280, 0, 0, 0},  //TV = 7.83(421 lines)  AV=1.70  SV=6.72  BV=2.80
    {4696,8192,1280, 0, 0, 0},  //TV = 7.73(450 lines)  AV=1.70  SV=6.72  BV=2.71
    {5030,8192,1280, 0, 0, 0},  //TV = 7.64(482 lines)  AV=1.70  SV=6.72  BV=2.61
    {5395,8192,1280, 0, 0, 0},  //TV = 7.53(517 lines)  AV=1.70  SV=6.72  BV=2.51
    {5771,8192,1280, 0, 0, 0},  //TV = 7.44(553 lines)  AV=1.70  SV=6.72  BV=2.41
    {6230,8192,1280, 0, 0, 0},  //TV = 7.33(597 lines)  AV=1.70  SV=6.72  BV=2.30
    {6668,8192,1280, 0, 0, 0},  //TV = 7.23(639 lines)  AV=1.70  SV=6.72  BV=2.20
    {7137,8192,1280, 0, 0, 0},  //TV = 7.13(684 lines)  AV=1.70  SV=6.72  BV=2.10
    {7649,8192,1280, 0, 0, 0},  //TV = 7.03(733 lines)  AV=1.70  SV=6.72  BV=2.00
    {8191,8192,1280, 0, 0, 0},  //TV = 6.93(785 lines)  AV=1.70  SV=6.72  BV=1.91
    {8775,8192,1280, 0, 0, 0},  //TV = 6.83(841 lines)  AV=1.70  SV=6.72  BV=1.81
    {9402,8192,1280, 0, 0, 0},  //TV = 6.73(901 lines)  AV=1.70  SV=6.72  BV=1.71
    {9996,8192,1288, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.73  BV=1.61
    {9996,8192,1376, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.83  BV=1.51
    {9996,8192,1480, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=6.93  BV=1.41
    {9996,8192,1584, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.03  BV=1.31
    {9996,8192,1696, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.13  BV=1.21
    {9996,8192,1816, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.23  BV=1.11
    {9996,8192,1952, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.33  BV=1.01
    {9996,8192,2088, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.43  BV=0.91
    {9996,8192,2240, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.53  BV=0.81
    {9996,8192,2416, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=7.64  BV=0.70
    {20003,8192,1288, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.73  BV=0.61
    {20003,8192,1384, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.84  BV=0.50
    {20003,8192,1480, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=6.93  BV=0.41
    {20003,8192,1592, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=7.04  BV=0.30
    {20003,8192,1704, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=7.14  BV=0.20
    {20003,8192,1824, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=7.23  BV=0.11
    {29998,8192,1312, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.76  BV=-0.00
    {29998,8192,1408, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.86  BV=-0.10
    {29998,8192,1504, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=6.96  BV=-0.20
    {29998,8192,1616, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=7.06  BV=-0.30
    {40005,8192,1296, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.74  BV=-0.40
    {40005,8192,1392, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.84  BV=-0.50
    {40005,8192,1488, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=6.94  BV=-0.60
    {50000,8192,1280, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.72  BV=-0.70
    {50000,8192,1368, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.82  BV=-0.80
    {50000,8192,1464, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=6.92  BV=-0.90
    {59996,8192,1312, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.76  BV=-1.00
    {59996,8192,1408, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.86  BV=-1.10
    {70003,8192,1288, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.73  BV=-1.20
    {70003,8192,1384, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.84  BV=-1.30
    {79998,8192,1296, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.74  BV=-1.40
    {79998,8192,1392, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.84  BV=-1.50
    {90005,8192,1320, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=6.77  BV=-1.60
    {100000,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {100000,8192,1368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.82  BV=-1.80
    {109996,8192,1336, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=6.78  BV=-1.90
    {120002,8192,1312, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=6.76  BV=-2.00
    {129998,8192,1296, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=6.74  BV=-2.10
    {140004,8192,1288, 0, 0, 0},  //TV = 2.84(13418 lines)  AV=1.70  SV=6.73  BV=-2.20
    {150000,8192,1288, 0, 0, 0},  //TV = 2.74(14376 lines)  AV=1.70  SV=6.73  BV=-2.30
    {159995,8192,1296, 0, 0, 0},  //TV = 2.64(15334 lines)  AV=1.70  SV=6.74  BV=-2.40
    {170002,8192,1304, 0, 0, 0},  //TV = 2.56(16293 lines)  AV=1.70  SV=6.75  BV=-2.50
    {179997,8192,1320, 0, 0, 0},  //TV = 2.47(17251 lines)  AV=1.70  SV=6.77  BV=-2.60
    {190004,8192,1344, 0, 0, 0},  //TV = 2.40(18210 lines)  AV=1.70  SV=6.79  BV=-2.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_CAPTURE_ISO1600,    //eAETableID
    142,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -27,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_1600, //ISO SPEED
    sCaptureISO1600PLineTable_60Hz,
    sCaptureISO1600PLineTable_50Hz,
    NULL,
};
static strEvPline sCaptureStrobePLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33327,1249,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.69  BV=2.92
    {33327,1341,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.80  BV=2.80
    {33327,1444,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.90  BV=2.71
    {41663,1239,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.68  BV=2.61
    {41663,1311,1032, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.77  BV=2.51
    {41663,1423,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=3.88  BV=2.41
    {50001,1270,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.71  BV=2.31
    {50001,1362,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.81  BV=2.21
    {58327,1239,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=3.68  BV=2.12
    {58327,1341,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=3.79  BV=2.01
    {66663,1249,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=3.69  BV=1.92
    {66663,1341,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=3.80  BV=1.80
    {66663,1454,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=3.91  BV=1.70
    {66663,1536,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=3.99  BV=1.62
    {66663,1649,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.10  BV=1.50
    {66663,1761,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.19  BV=1.41
    {66663,1905,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.30  BV=1.31
    {66663,2028,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.39  BV=1.22
    {66663,2181,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.49  BV=1.11
    {66663,2345,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.60  BV=1.01
    {66663,2499,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.69  BV=0.92
    {66663,2703,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.80  BV=0.80
    {66663,2877,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.89  BV=0.71
    {66663,3082,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.99  BV=0.61
    {66663,3277,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.09  BV=0.51
    {66663,3543,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.19  BV=0.41
    {66663,3799,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.29  BV=0.31
    {66663,4035,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.39  BV=0.21
    {66663,4372,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.49  BV=0.11
    {75001,4157,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=5.43  BV=-0.00
    {75001,4444,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=5.53  BV=-0.10
    {83326,4301,1032, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=5.48  BV=-0.20
    {91663,4229,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=5.45  BV=-0.30
    {100001,4096,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.41  BV=-0.39
    {100001,4444,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.52  BV=-0.50
    {100001,4762,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.62  BV=-0.60
    {100001,5038,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.72  BV=-0.70
    {100001,5458,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.81  BV=-0.80
    {100001,5827,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.92  BV=-0.90
    {100001,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100001,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100001,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100001,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100001,8192,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.42  BV=-1.40
    {100001,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {100001,8192,1192, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.62  BV=-1.60
    {100001,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {100001,8192,1368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.82  BV=-1.80
    {100001,8192,1464, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.92  BV=-1.90
    {100001,8192,1576, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.02  BV=-2.00
    {100001,8192,1688, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.12  BV=-2.10
    {100001,8192,1808, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.22  BV=-2.20
    {100001,8192,1936, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.32  BV=-2.30
    {100001,8192,2072, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.42  BV=-2.40
    {100001,8192,2224, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.52  BV=-2.50
    {100001,8192,2384, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.62  BV=-2.60
    {100001,8192,2552, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.72  BV=-2.70
    {100001,8192,2736, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.82  BV=-2.80
    {100001,8192,2928, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.92  BV=-2.90
    {100001,8192,3136, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=8.02  BV=-3.00
    {100001,8192,3368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=8.12  BV=-3.10
    {100001,8192,3608, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=8.22  BV=-3.20
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {40005,1198,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.64  BV=2.70
    {40005,1280,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.72  BV=2.62
    {40005,1382,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.83  BV=2.51
    {40005,1475,1032, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=3.94  BV=2.40
    {50000,1270,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.71  BV=2.31
    {50000,1362,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=3.81  BV=2.21
    {59996,1198,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.64  BV=2.12
    {59996,1300,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.74  BV=2.01
    {59996,1393,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.84  BV=1.91
    {59996,1495,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=3.95  BV=1.81
    {59996,1608,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.05  BV=1.70
    {59996,1720,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.15  BV=1.61
    {59996,1843,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.25  BV=1.51
    {59996,1966,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.35  BV=1.40
    {59996,2109,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.44  BV=1.31
    {59996,2263,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.54  BV=1.21
    {59996,2427,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.65  BV=1.11
    {59996,2591,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.74  BV=1.02
    {59996,2785,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.84  BV=0.91
    {59996,2980,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.95  BV=0.80
    {59996,3195,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.04  BV=0.71
    {59996,3400,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.14  BV=0.61
    {59996,3645,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.24  BV=0.51
    {59996,3912,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.35  BV=0.41
    {59996,4229,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.45  BV=0.31
    {59996,4516,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.55  BV=0.20
    {70003,4157,1024, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=5.42  BV=0.11
    {70003,4444,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=5.53  BV=0.00
    {79998,4229,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=5.45  BV=-0.11
    {79998,4516,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=5.54  BV=-0.20
    {90005,4301,1024, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=5.47  BV=-0.30
    {100000,4096,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.41  BV=-0.39
    {100000,4444,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.52  BV=-0.50
    {100000,4762,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.62  BV=-0.60
    {100000,5038,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.72  BV=-0.70
    {100000,5458,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.81  BV=-0.80
    {100000,5827,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.92  BV=-0.90
    {100000,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100000,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100000,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100000,7711,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.32  BV=-1.31
    {100000,8192,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.42  BV=-1.40
    {100000,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {100000,8192,1192, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.62  BV=-1.60
    {100000,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {100000,8192,1368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.82  BV=-1.80
    {100000,8192,1464, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.92  BV=-1.90
    {100000,8192,1576, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.02  BV=-2.00
    {100000,8192,1688, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.12  BV=-2.10
    {100000,8192,1808, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.22  BV=-2.20
    {100000,8192,1936, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.32  BV=-2.30
    {100000,8192,2072, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.42  BV=-2.40
    {100000,8192,2224, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.52  BV=-2.50
    {100000,8192,2384, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.62  BV=-2.60
    {100000,8192,2552, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.72  BV=-2.70
    {100000,8192,2736, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.82  BV=-2.80
    {100000,8192,2928, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=7.92  BV=-2.90
    {100000,8192,3136, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=8.02  BV=-3.00
    {100000,8192,3368, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=8.12  BV=-3.10
    {100000,8192,3632, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=8.23  BV=-3.21
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_STROBE,    //eAETableID
    147,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -32,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sCaptureStrobePLineTable_60Hz,
    sCaptureStrobePLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene1PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33327,1249,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.69  BV=2.92
    {33327,1341,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.80  BV=2.80
    {33327,1454,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.91  BV=2.70
    {33327,1536,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.00  BV=2.61
    {33327,1649,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.10  BV=2.50
    {33327,1761,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.19  BV=2.41
    {33327,1905,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.30  BV=2.31
    {33327,2028,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.39  BV=2.22
    {33327,2181,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.49  BV=2.11
    {33327,2345,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.60  BV=2.01
    {33327,2519,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.70  BV=1.90
    {41663,2150,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.47  BV=1.81
    {41663,2304,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.57  BV=1.71
    {50001,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50001,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50001,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {50001,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50001,2734,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.82  BV=1.20
    {50001,2908,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.91  BV=1.11
    {50001,3123,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.01  BV=1.01
    {50001,3318,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.11  BV=0.91
    {50001,3594,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.21  BV=0.81
    {50001,3850,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.31  BV=0.71
    {50001,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50001,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50001,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {58327,4301,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.48  BV=0.31
    {58327,4598,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.58  BV=0.22
    {66663,4372,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.49  BV=0.11
    {66663,4680,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.60  BV=-0.00
    {66663,5038,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.70  BV=-0.10
    {66663,5345,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.80  BV=-0.19
    {66663,5827,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.91  BV=-0.31
    {66663,6093,1040, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.00  BV=-0.39
    {66663,6554,1040, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.10  BV=-0.50
    {75001,6246,1040, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.03  BV=-0.60
    {75001,6717,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.13  BV=-0.69
    {83326,6554,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=6.08  BV=-0.80
    {91663,6390,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=6.04  BV=-0.90
    {100001,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100001,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100001,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100001,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100001,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {108326,8192,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.40  BV=-1.50
    {108326,8192,1096, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.50  BV=-1.60
    {116664,8192,1096, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=6.50  BV=-1.70
    {133326,8192,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=6.40  BV=-1.80
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {29998,1608,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.05  BV=2.70
    {29998,1720,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.15  BV=2.61
    {29998,1843,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.25  BV=2.51
    {29998,1966,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.35  BV=2.40
    {29998,2109,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.44  BV=2.31
    {29998,2263,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.54  BV=2.21
    {29998,2427,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.65  BV=2.11
    {29998,2591,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.75  BV=2.00
    {40005,2099,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.44  BV=1.90
    {40005,2243,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.53  BV=1.81
    {40005,2406,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.63  BV=1.71
    {50000,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50000,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50000,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {50000,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50000,2703,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.80  BV=1.22
    {50000,2908,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.91  BV=1.11
    {50000,3123,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.01  BV=1.01
    {50000,3318,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.11  BV=0.91
    {50000,3594,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.21  BV=0.81
    {50000,3850,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.31  BV=0.71
    {50000,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50000,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50000,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {59996,4229,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.45  BV=0.31
    {59996,4516,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.54  BV=0.21
    {59996,4854,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.65  BV=0.11
    {59996,5243,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.76  BV=-0.00
    {59996,5581,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.85  BV=-0.09
    {59996,5960,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.95  BV=-0.20
    {59996,6390,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.05  BV=-0.30
    {59996,6902,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.15  BV=-0.40
    {70003,6246,1040, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.03  BV=-0.50
    {70003,6717,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.13  BV=-0.59
    {79998,6390,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.04  BV=-0.70
    {79998,6717,1040, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.14  BV=-0.80
    {90005,6390,1040, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=6.06  BV=-0.89
    {100000,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100000,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100000,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100000,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100000,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {100000,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {109996,8192,1080, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=6.48  BV=-1.60
    {120002,8192,1064, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=6.46  BV=-1.70
    {129998,8192,1048, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=6.43  BV=-1.79
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_SCENE_INDEX1,    //eAETableID
    133,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -18,    //i4MinBV
    90,    //i4EffectiveMaxBV
    -10,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sAEScene1PLineTable_60Hz,
    sAEScene1PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene2PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33327,1249,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.69  BV=2.92
    {33327,1341,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.80  BV=2.80
    {33327,1454,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.91  BV=2.70
    {33327,1536,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.00  BV=2.61
    {33327,1649,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.10  BV=2.50
    {33327,1761,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.19  BV=2.41
    {33327,1905,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.30  BV=2.31
    {33327,2028,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.39  BV=2.22
    {33327,2181,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.49  BV=2.11
    {33327,2345,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.60  BV=2.01
    {33327,2519,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.70  BV=1.90
    {41663,2150,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.47  BV=1.81
    {41663,2304,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.57  BV=1.71
    {50001,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50001,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50001,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {50001,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50001,2734,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.82  BV=1.20
    {50001,2908,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.91  BV=1.11
    {50001,3123,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.01  BV=1.01
    {50001,3318,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.11  BV=0.91
    {50001,3594,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.21  BV=0.81
    {50001,3850,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.31  BV=0.71
    {50001,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50001,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50001,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {58327,4301,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.48  BV=0.31
    {58327,4598,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.58  BV=0.22
    {66663,4372,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.49  BV=0.11
    {66663,4680,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.60  BV=-0.00
    {66663,5038,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.70  BV=-0.10
    {66663,5345,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.80  BV=-0.19
    {66663,5827,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.91  BV=-0.31
    {66663,6093,1040, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.00  BV=-0.39
    {66663,6554,1040, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.10  BV=-0.50
    {75001,6246,1040, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.03  BV=-0.60
    {75001,6717,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.13  BV=-0.69
    {83326,6554,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=6.08  BV=-0.80
    {91663,6390,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=6.04  BV=-0.90
    {100001,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100001,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100001,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100001,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100001,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {108326,8192,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.40  BV=-1.50
    {108326,8192,1096, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.50  BV=-1.60
    {116664,8192,1096, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=6.50  BV=-1.70
    {133326,8192,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=6.40  BV=-1.80
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {29998,1608,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.05  BV=2.70
    {29998,1720,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.15  BV=2.61
    {29998,1843,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.25  BV=2.51
    {29998,1966,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.35  BV=2.40
    {29998,2109,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.44  BV=2.31
    {29998,2263,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.54  BV=2.21
    {29998,2427,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.65  BV=2.11
    {29998,2591,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.75  BV=2.00
    {40005,2099,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.44  BV=1.90
    {40005,2243,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.53  BV=1.81
    {40005,2406,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.63  BV=1.71
    {50000,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50000,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50000,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {50000,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50000,2703,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.80  BV=1.22
    {50000,2908,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.91  BV=1.11
    {50000,3123,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.01  BV=1.01
    {50000,3318,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.11  BV=0.91
    {50000,3594,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.21  BV=0.81
    {50000,3850,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.31  BV=0.71
    {50000,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50000,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50000,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {59996,4229,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.45  BV=0.31
    {59996,4516,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.54  BV=0.21
    {59996,4854,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.65  BV=0.11
    {59996,5243,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.76  BV=-0.00
    {59996,5581,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.85  BV=-0.09
    {59996,5960,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.95  BV=-0.20
    {59996,6390,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.05  BV=-0.30
    {59996,6902,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.15  BV=-0.40
    {70003,6246,1040, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.03  BV=-0.50
    {70003,6717,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.13  BV=-0.59
    {79998,6390,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.04  BV=-0.70
    {79998,6717,1040, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.14  BV=-0.80
    {90005,6390,1040, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=6.06  BV=-0.89
    {100000,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100000,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100000,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100000,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100000,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {100000,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {109996,8192,1080, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=6.48  BV=-1.60
    {120002,8192,1064, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=6.46  BV=-1.70
    {129998,8192,1048, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=6.43  BV=-1.79
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_SCENE_INDEX2,    //eAETableID
    133,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -18,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sAEScene2PLineTable_60Hz,
    sAEScene2PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene3PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33327,1249,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.69  BV=2.92
    {33327,1341,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.80  BV=2.80
    {33327,1454,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.91  BV=2.70
    {33327,1536,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.00  BV=2.61
    {33327,1649,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.10  BV=2.50
    {33327,1761,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.19  BV=2.41
    {33327,1905,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.30  BV=2.31
    {33327,2028,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.39  BV=2.22
    {33327,2181,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.49  BV=2.11
    {33327,2345,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.60  BV=2.01
    {33327,2519,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.70  BV=1.90
    {41663,2150,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.47  BV=1.81
    {41663,2304,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.57  BV=1.71
    {50001,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50001,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50001,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {58327,2181,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=4.49  BV=1.30
    {58327,2324,1024, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=4.58  BV=1.21
    {66663,2181,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.49  BV=1.11
    {66663,2324,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.59  BV=1.01
    {66663,2519,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.70  BV=0.90
    {66663,2673,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.80  BV=0.81
    {66663,2877,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.89  BV=0.71
    {66663,3082,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=4.99  BV=0.61
    {66663,3318,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.10  BV=0.51
    {66663,3543,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.19  BV=0.41
    {66663,3799,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.29  BV=0.31
    {66663,4035,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.39  BV=0.21
    {66663,4372,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.49  BV=0.11
    {75001,4157,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=5.43  BV=-0.00
    {75001,4444,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=5.53  BV=-0.10
    {83326,4301,1032, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=5.48  BV=-0.20
    {91663,4229,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=5.45  BV=-0.30
    {100001,4096,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.41  BV=-0.39
    {100001,4444,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.52  BV=-0.50
    {100001,4762,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.62  BV=-0.60
    {100001,5038,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.72  BV=-0.70
    {100001,5458,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.81  BV=-0.80
    {100001,5827,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.92  BV=-0.90
    {100001,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100001,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100001,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100001,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100001,8192,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.42  BV=-1.40
    {100001,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {100001,8192,1192, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.62  BV=-1.60
    {100001,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {29998,1608,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.05  BV=2.70
    {29998,1720,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.15  BV=2.61
    {29998,1843,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.25  BV=2.51
    {29998,1966,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.35  BV=2.40
    {29998,2109,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.44  BV=2.31
    {29998,2263,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.54  BV=2.21
    {29998,2427,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.65  BV=2.11
    {29998,2591,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.75  BV=2.00
    {40005,2099,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.44  BV=1.90
    {40005,2243,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.53  BV=1.81
    {40005,2406,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.63  BV=1.71
    {50000,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50000,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50000,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {59996,2109,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.44  BV=1.31
    {59996,2263,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.54  BV=1.21
    {59996,2427,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.65  BV=1.11
    {59996,2621,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.76  BV=1.00
    {59996,2785,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.84  BV=0.91
    {59996,2980,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=4.94  BV=0.81
    {59996,3195,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.04  BV=0.71
    {59996,3400,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.14  BV=0.61
    {59996,3645,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.24  BV=0.51
    {59996,3912,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.35  BV=0.41
    {59996,4229,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.45  BV=0.31
    {59996,4516,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.54  BV=0.21
    {70003,4157,1024, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=5.42  BV=0.11
    {70003,4444,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=5.53  BV=0.00
    {79998,4229,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=5.45  BV=-0.11
    {79998,4516,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=5.54  BV=-0.20
    {90005,4301,1024, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=5.47  BV=-0.30
    {100000,4096,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.41  BV=-0.39
    {100000,4444,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.52  BV=-0.50
    {100000,4762,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.62  BV=-0.60
    {100000,5038,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.72  BV=-0.70
    {100000,5458,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.81  BV=-0.80
    {100000,5827,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=5.92  BV=-0.90
    {100000,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100000,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100000,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100000,7711,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.32  BV=-1.31
    {100000,8192,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.42  BV=-1.40
    {100000,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {100000,8192,1192, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.62  BV=-1.60
    {100000,8192,1280, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.72  BV=-1.70
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_SCENE_INDEX3,    //eAETableID
    132,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -17,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sAEScene3PLineTable_60Hz,
    sAEScene3PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene4PLineTable_60Hz =
{
{
    {249989,1710,1024, 0, 0, 0},  //TV = 2.00(23959 lines)  AV=1.70  SV=4.14  BV=-0.44
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {249999,1710,1024, 0, 0, 0},  //TV = 2.00(23960 lines)  AV=1.70  SV=4.14  BV=-0.44
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_SCENE_INDEX4,    //eAETableID
    1,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    -4,    //i4MaxBV
    -4,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
    sAEScene4PLineTable_60Hz,
    sAEScene4PLineTable_50Hz,
    NULL,
};
static strEvPline sAEScene5PLineTable_60Hz =
{
{
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8338,1249,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.70  BV=4.90
    {8338,1341,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.79  BV=4.81
    {8338,1444,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=3.90  BV=4.71
    {8338,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.00  BV=4.61
    {8338,1649,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.09  BV=4.51
    {8338,1761,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.19  BV=4.41
    {8338,1884,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.29  BV=4.31
    {8338,2028,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.39  BV=4.22
    {8338,2181,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.49  BV=4.11
    {8338,2324,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.70  SV=4.59  BV=4.01
    {16664,1249,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.69  BV=3.92
    {16664,1341,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.80  BV=3.80
    {16664,1444,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=3.90  BV=3.71
    {16664,1536,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.00  BV=3.61
    {16664,1649,1024, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.09  BV=3.52
    {16664,1761,1032, 0, 0, 0},  //TV = 5.91(1597 lines)  AV=1.70  SV=4.19  BV=3.41
    {25001,1270,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.71  BV=3.31
    {25001,1341,1032, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.80  BV=3.22
    {25001,1454,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=3.91  BV=3.11
    {25001,1556,1024, 0, 0, 0},  //TV = 5.32(2396 lines)  AV=1.70  SV=4.00  BV=3.01
    {33327,1249,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.69  BV=2.92
    {33327,1341,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.80  BV=2.80
    {33327,1454,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=3.91  BV=2.70
    {33327,1536,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.00  BV=2.61
    {33327,1649,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.10  BV=2.50
    {33327,1761,1032, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.19  BV=2.41
    {33327,1905,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.30  BV=2.31
    {33327,2028,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.39  BV=2.22
    {33327,2181,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.49  BV=2.11
    {33327,2345,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.60  BV=2.01
    {33327,2519,1024, 0, 0, 0},  //TV = 4.91(3194 lines)  AV=1.70  SV=4.70  BV=1.90
    {41663,2150,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.47  BV=1.81
    {41663,2304,1024, 0, 0, 0},  //TV = 4.59(3993 lines)  AV=1.70  SV=4.57  BV=1.71
    {50001,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50001,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50001,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {50001,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50001,2734,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.82  BV=1.20
    {50001,2908,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.91  BV=1.11
    {50001,3123,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.01  BV=1.01
    {50001,3318,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.11  BV=0.91
    {50001,3594,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.21  BV=0.81
    {50001,3850,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.31  BV=0.71
    {50001,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50001,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50001,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {58327,4301,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.48  BV=0.31
    {58327,4598,1032, 0, 0, 0},  //TV = 4.10(5590 lines)  AV=1.70  SV=5.58  BV=0.22
    {66663,4372,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.49  BV=0.11
    {66663,4680,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.60  BV=-0.00
    {66663,5038,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.70  BV=-0.10
    {66663,5345,1032, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.80  BV=-0.19
    {66663,5827,1024, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=5.91  BV=-0.31
    {66663,6093,1040, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.00  BV=-0.39
    {66663,6554,1040, 0, 0, 0},  //TV = 3.91(6389 lines)  AV=1.70  SV=6.10  BV=-0.50
    {75001,6246,1040, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.03  BV=-0.60
    {75001,6717,1032, 0, 0, 0},  //TV = 3.74(7188 lines)  AV=1.70  SV=6.13  BV=-0.69
    {83326,6554,1024, 0, 0, 0},  //TV = 3.59(7986 lines)  AV=1.70  SV=6.08  BV=-0.80
    {91663,6390,1024, 0, 0, 0},  //TV = 3.45(8785 lines)  AV=1.70  SV=6.04  BV=-0.90
    {100001,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100001,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100001,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100001,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100001,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {108326,8192,1024, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.40  BV=-1.50
    {108326,8192,1096, 0, 0, 0},  //TV = 3.21(10382 lines)  AV=1.70  SV=6.50  BV=-1.60
    {116664,8192,1096, 0, 0, 0},  //TV = 3.10(11181 lines)  AV=1.70  SV=6.50  BV=-1.70
    {133326,8192,1024, 0, 0, 0},  //TV = 2.91(12778 lines)  AV=1.70  SV=6.40  BV=-1.80
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1270,1032, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.70  SV=3.72  BV=11.35
    {105,1198,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.64  BV=11.28
    {105,1270,1032, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.70  SV=3.72  BV=11.19
    {115,1239,1024, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.70  SV=3.68  BV=11.11
    {126,1239,1024, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.70  SV=3.68  BV=10.97
    {136,1219,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.70  SV=3.65  BV=10.89
    {147,1198,1032, 0, 0, 0},  //TV = 12.73(14 lines)  AV=1.70  SV=3.64  BV=10.79
    {157,1219,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.70  SV=3.65  BV=10.68
    {167,1219,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.70  SV=3.66  BV=10.58
    {178,1249,1024, 0, 0, 0},  //TV = 12.46(17 lines)  AV=1.70  SV=3.69  BV=10.46
    {188,1219,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.70  SV=3.66  BV=10.41
    {199,1239,1024, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.70  SV=3.68  BV=10.32
    {220,1198,1032, 0, 0, 0},  //TV = 12.15(21 lines)  AV=1.70  SV=3.64  BV=10.21
    {230,1239,1024, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.70  SV=3.68  BV=10.11
    {251,1198,1032, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.70  SV=3.64  BV=10.02
    {272,1198,1032, 0, 0, 0},  //TV = 11.84(26 lines)  AV=1.70  SV=3.64  BV=9.90
    {293,1198,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.70  SV=3.64  BV=9.79
    {314,1198,1024, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.70  SV=3.63  BV=9.71
    {334,1198,1032, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.70  SV=3.64  BV=9.61
    {355,1198,1032, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.70  SV=3.64  BV=9.52
    {376,1219,1032, 0, 0, 0},  //TV = 11.38(36 lines)  AV=1.70  SV=3.66  BV=9.41
    {407,1219,1024, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.70  SV=3.65  BV=9.31
    {439,1198,1032, 0, 0, 0},  //TV = 11.15(42 lines)  AV=1.70  SV=3.64  BV=9.21
    {470,1198,1032, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.70  SV=3.64  BV=9.11
    {501,1219,1024, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.70  SV=3.65  BV=9.01
    {543,1198,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.70  SV=3.64  BV=8.90
    {574,1219,1024, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.70  SV=3.65  BV=8.81
    {627,1198,1024, 0, 0, 0},  //TV = 10.64(60 lines)  AV=1.70  SV=3.63  BV=8.71
    {668,1198,1032, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.70  SV=3.64  BV=8.61
    {720,1198,1024, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.70  SV=3.63  BV=8.51
    {762,1198,1032, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.70  SV=3.64  BV=8.42
    {825,1198,1024, 0, 0, 0},  //TV = 10.24(79 lines)  AV=1.70  SV=3.63  BV=8.31
    {887,1198,1024, 0, 0, 0},  //TV = 10.14(85 lines)  AV=1.70  SV=3.63  BV=8.21
    {950,1198,1032, 0, 0, 0},  //TV = 10.04(91 lines)  AV=1.70  SV=3.64  BV=8.10
    {1023,1198,1024, 0, 0, 0},  //TV = 9.93(98 lines)  AV=1.70  SV=3.63  BV=8.00
    {1086,1198,1032, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.70  SV=3.64  BV=7.90
    {1159,1198,1032, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.70  SV=3.64  BV=7.81
    {1253,1198,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.70  SV=3.64  BV=7.70
    {1336,1198,1032, 0, 0, 0},  //TV = 9.55(128 lines)  AV=1.70  SV=3.64  BV=7.61
    {1430,1198,1032, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.70  SV=3.64  BV=7.51
    {1534,1198,1032, 0, 0, 0},  //TV = 9.35(147 lines)  AV=1.70  SV=3.64  BV=7.41
    {1660,1198,1024, 0, 0, 0},  //TV = 9.23(159 lines)  AV=1.70  SV=3.63  BV=7.30
    {1774,1198,1024, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.70  SV=3.63  BV=7.21
    {1889,1198,1032, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.70  SV=3.64  BV=7.11
    {2035,1198,1032, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.70  SV=3.64  BV=7.00
    {2181,1198,1024, 0, 0, 0},  //TV = 8.84(209 lines)  AV=1.70  SV=3.63  BV=6.91
    {2327,1198,1032, 0, 0, 0},  //TV = 8.75(223 lines)  AV=1.70  SV=3.64  BV=6.81
    {2515,1198,1024, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.70  SV=3.63  BV=6.70
    {2682,1198,1024, 0, 0, 0},  //TV = 8.54(257 lines)  AV=1.70  SV=3.63  BV=6.61
    {2891,1198,1024, 0, 0, 0},  //TV = 8.43(277 lines)  AV=1.70  SV=3.63  BV=6.50
    {3079,1198,1024, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.70  SV=3.63  BV=6.41
    {3308,1198,1024, 0, 0, 0},  //TV = 8.24(317 lines)  AV=1.70  SV=3.63  BV=6.31
    {3548,1198,1024, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.70  SV=3.63  BV=6.21
    {3798,1198,1024, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.70  SV=3.63  BV=6.11
    {4091,1198,1024, 0, 0, 0},  //TV = 7.93(392 lines)  AV=1.70  SV=3.63  BV=6.00
    {4383,1198,1024, 0, 0, 0},  //TV = 7.83(420 lines)  AV=1.70  SV=3.63  BV=5.90
    {4685,1198,1024, 0, 0, 0},  //TV = 7.74(449 lines)  AV=1.70  SV=3.63  BV=5.81
    {5019,1198,1024, 0, 0, 0},  //TV = 7.64(481 lines)  AV=1.70  SV=3.63  BV=5.71
    {5374,1198,1024, 0, 0, 0},  //TV = 7.54(515 lines)  AV=1.70  SV=3.63  BV=5.61
    {5760,1198,1024, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.70  SV=3.63  BV=5.51
    {6167,1198,1024, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.70  SV=3.63  BV=5.41
    {6605,1198,1024, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.70  SV=3.63  BV=5.31
    {7075,1198,1024, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.70  SV=3.63  BV=5.21
    {7628,1198,1024, 0, 0, 0},  //TV = 7.03(731 lines)  AV=1.70  SV=3.63  BV=5.10
    {8170,1198,1024, 0, 0, 0},  //TV = 6.94(783 lines)  AV=1.70  SV=3.63  BV=5.00
    {8755,1198,1024, 0, 0, 0},  //TV = 6.84(839 lines)  AV=1.70  SV=3.63  BV=4.90
    {9370,1198,1024, 0, 0, 0},  //TV = 6.74(898 lines)  AV=1.70  SV=3.63  BV=4.81
    {9996,1198,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.64  BV=4.70
    {9996,1280,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.72  BV=4.62
    {9996,1382,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.83  BV=4.51
    {9996,1475,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=3.93  BV=4.41
    {9996,1587,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.03  BV=4.31
    {9996,1700,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.13  BV=4.21
    {9996,1823,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.23  BV=4.11
    {9996,1925,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.32  BV=4.02
    {9996,2079,1032, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.43  BV=3.91
    {9996,2243,1024, 0, 0, 0},  //TV = 6.64(958 lines)  AV=1.70  SV=4.53  BV=3.81
    {20003,1198,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.64  BV=3.70
    {20003,1280,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.72  BV=3.62
    {20003,1382,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.83  BV=3.51
    {20003,1475,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=3.93  BV=3.41
    {20003,1567,1032, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.03  BV=3.31
    {20003,1710,1024, 0, 0, 0},  //TV = 5.64(1917 lines)  AV=1.70  SV=4.14  BV=3.20
    {29998,1198,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.64  BV=3.12
    {29998,1311,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.76  BV=3.00
    {29998,1393,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.84  BV=2.91
    {29998,1495,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=3.95  BV=2.81
    {29998,1608,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.05  BV=2.70
    {29998,1720,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.15  BV=2.61
    {29998,1843,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.25  BV=2.51
    {29998,1966,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.35  BV=2.40
    {29998,2109,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.44  BV=2.31
    {29998,2263,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.54  BV=2.21
    {29998,2427,1024, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.65  BV=2.11
    {29998,2591,1032, 0, 0, 0},  //TV = 5.06(2875 lines)  AV=1.70  SV=4.75  BV=2.00
    {40005,2099,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.44  BV=1.90
    {40005,2243,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.53  BV=1.81
    {40005,2406,1024, 0, 0, 0},  //TV = 4.64(3834 lines)  AV=1.70  SV=4.63  BV=1.71
    {50000,2048,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.41  BV=1.61
    {50000,2202,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.51  BV=1.51
    {50000,2365,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.61  BV=1.41
    {50000,2519,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.70  BV=1.32
    {50000,2703,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.80  BV=1.22
    {50000,2908,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=4.91  BV=1.11
    {50000,3123,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.01  BV=1.01
    {50000,3318,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.11  BV=0.91
    {50000,3594,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.21  BV=0.81
    {50000,3850,1024, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.31  BV=0.71
    {50000,4096,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.41  BV=0.61
    {50000,4372,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.51  BV=0.51
    {50000,4680,1032, 0, 0, 0},  //TV = 4.32(4792 lines)  AV=1.70  SV=5.60  BV=0.41
    {59996,4229,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.45  BV=0.31
    {59996,4516,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.54  BV=0.21
    {59996,4854,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.65  BV=0.11
    {59996,5243,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.76  BV=-0.00
    {59996,5581,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.85  BV=-0.09
    {59996,5960,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=5.95  BV=-0.20
    {59996,6390,1032, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.05  BV=-0.30
    {59996,6902,1024, 0, 0, 0},  //TV = 4.06(5750 lines)  AV=1.70  SV=6.15  BV=-0.40
    {70003,6246,1040, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.03  BV=-0.50
    {70003,6717,1032, 0, 0, 0},  //TV = 3.84(6709 lines)  AV=1.70  SV=6.13  BV=-0.59
    {79998,6390,1024, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.04  BV=-0.70
    {79998,6717,1040, 0, 0, 0},  //TV = 3.64(7667 lines)  AV=1.70  SV=6.14  BV=-0.80
    {90005,6390,1040, 0, 0, 0},  //TV = 3.47(8626 lines)  AV=1.70  SV=6.06  BV=-0.89
    {100000,6246,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.02  BV=-1.00
    {100000,6717,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.11  BV=-1.10
    {100000,7086,1040, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.21  BV=-1.20
    {100000,7711,1024, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.31  BV=-1.30
    {100000,8192,1032, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.41  BV=-1.39
    {100000,8192,1112, 0, 0, 0},  //TV = 3.32(9584 lines)  AV=1.70  SV=6.52  BV=-1.50
    {109996,8192,1080, 0, 0, 0},  //TV = 3.18(10542 lines)  AV=1.70  SV=6.48  BV=-1.60
    {120002,8192,1064, 0, 0, 0},  //TV = 3.06(11501 lines)  AV=1.70  SV=6.46  BV=-1.70
    {129998,8192,1048, 0, 0, 0},  //TV = 2.94(12459 lines)  AV=1.70  SV=6.43  BV=-1.79
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    AETABLE_SCENE_INDEX5,    //eAETableID
    133,    //u4TotalIndex
    20,    //u4StrobeTrigerBV
    114,    //i4MaxBV
    -18,    //i4MinBV
    90,    //i4EffectiveMaxBV
    0,      //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
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
    {LIB3A_AE_SCENE_AUTO, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX5}},
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
        {1,5000,30,1195,1195},
        {2,30,30,1195,2048},
        {3,30,20,2048,2048},
        {4,20,20,2048,4096},
        {5,20,15,4096,4096},
        {6,15,15,4096,6144},
        {7,15,10,6144,6144},
        {8,10,10,6144,8192},
        {9,10,7,8192,8192},
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
        {1,10000,10,1195,1195},
        {2,10,10,1195,4096},
        {3,10,6,4096,4096},
        {4,6,6,4096,8192},
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

static strAEPLineNumInfo g_strAEVideoAutoPLineInfo =
{
    AETABLE_VIDEO_AUTO,
    90,
    0,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,2048},
        {3,60,30,2048,2048},
        {4,30,30,2048,4096},
        {5,30,15,4096,4096},
        {6,15,15,4096,6144},
        {7,15,10,6144,6144},
        {8,10,10,6144,8192},
        {9,10,7,8192,8192},
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
        {1,10000,60,1195,1195},
        {2,60,60,1195,10240},
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
        {1,5000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
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
        {1,5000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
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
        {1,5000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
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
        {1,5000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
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
        {1,5000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
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
        {1,5000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
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
        {1,10000,30,1195,1195},
        {2,30,30,1195,6144},
        {3,30,10,6144,6144},
        {4,10,10,6144,8192},
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
        {1,10000,5,1195,1195},
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
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,2460},
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
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,4920},
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
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,10240},
        {3,2000,5,10240,10240},
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
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,10240},
        {3,2000,5,10240,10240},
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
        {1,10000,15,1195,1195},
        {2,15,15,1195,4096},
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
        {1,10000,30,1195,1195},
        {2,30,30,1195,2048},
        {3,30,20,2048,2048},
        {4,20,20,2048,4096},
        {5,20,15,4096,4096},
        {6,15,15,4096,6144},
        {7,15,10,6144,6144},
        {8,10,10,6144,8192},
        {9,10,7,8192,8192},
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
        {1,10000,30,1195,1195},
        {2,30,30,1195,2048},
        {3,30,20,2048,2048},
        {4,20,20,2048,4096},
        {5,20,15,4096,4096},
        {6,15,15,4096,6144},
        {7,15,10,6144,6144},
        {8,10,10,6144,8192},
        {9,10,7,8192,8192},
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
        {1,10000,30,1195,1195},
        {2,30,30,1195,2048},
        {3,30,15,2048,2048},
        {4,15,15,2048,4096},
        {5,15,10,4096,4096},
        {6,10,10,4096,10240},
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
        {1,10000,30,1195,1195},
        {2,30,30,1195,2048},
        {3,30,20,2048,2048},
        {4,20,20,2048,4096},
        {5,20,15,4096,4096},
        {6,15,15,4096,6144},
        {7,15,10,6144,6144},
        {8,10,10,6144,8192},
        {9,10,7,8192,8192},
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
159,
{
{1024,100},
{1044,100},
{1055,100},
{1075,100},
{1085,100},
{1106,100},
{1116,100},
{1137,100},
{1147,100},
{1167,100},
{1188,100},
{1198,100},
{1219,100},
{1239,100},
{1249,100},
{1270,100},
{1280,100},
{1300,100},
{1311,100},
{1331,100},
{1341,100},
{1362,100},
{1382,100},
{1393,100},
{1413,100},
{1423,100},
{1444,100},
{1454,100},
{1475,100},
{1495,100},
{1505,100},
{1526,100},
{1536,100},
{1556,100},
{1567,100},
{1587,100},
{1608,100},
{1618,100},
{1638,100},
{1649,100},
{1669,100},
{1679,100},
{1700,100},
{1710,100},
{1720,100},
{1751,100},
{1761,100},
{1782,100},
{1792,100},
{1812,100},
{1823,100},
{1843,100},
{1864,100},
{1874,100},
{1884,100},
{1905,100},
{1925,100},
{1956,100},
{1966,100},
{1987,100},
{1997,100},
{2017,100},
{2028,100},
{2048,100},
{2068,100},
{2079,100},
{2099,100},
{2109,100},
{2130,100},
{2150,100},
{2181,100},
{2202,100},
{2222,100},
{2243,100},
{2263,100},
{2284,100},
{2304,100},
{2324,100},
{2345,100},
{2365,100},
{2386,100},
{2406,100},
{2427,100},
{2447,100},
{2478,100},
{2499,100},
{2519,100},
{2550,100},
{2570,100},
{2591,100},
{2621,100},
{2652,100},
{2673,100},
{2703,100},
{2734,100},
{2755,100},
{2785,100},
{2816,100},
{2847,100},
{2877,100},
{2908,100},
{2949,100},
{2980,100},
{3011,100},
{3052,100},
{3082,100},
{3123,100},
{3154,100},
{3195,100},
{3236,100},
{3277,100},
{3318,100},
{3359,100},
{3400,100},
{3451,100},
{3492,100},
{3543,100},
{3594,100},
{3645,100},
{3697,100},
{3748,100},
{3799,100},
{3850,100},
{3912,100},
{3973,100},
{4035,100},
{4096,100},
{4157,100},
{4229,100},
{4301,100},
{4372,100},
{4444,100},
{4516,100},
{4598,100},
{4680,100},
{4762,100},
{4854,100},
{4946,100},
{5038,100},
{5140,100},
{5243,100},
{5345,100},
{5458,100},
{5581,100},
{5704,100},
{5827,100},
{5960,100},
{6093,100},
{6246,100},
{6390,100},
{6554,100},
{6717,100},
{6902,100},
{7086,100},
{7281,100},
{7485,100},
{7711,100},
{7946,100},
{8192,100},
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
MinGain,1144
MaxGain,16384
MiniISOGain,50
GainStepUnitInTotalRange,32
PreviewExposureLineUnit,25059
PreviewMaxFrameRate,29
VideoExposureLineUnit,12983
VideoMaxFrameRate,30
VideoToPreviewSensitivityRatio,1024
CaptureExposureLineUnit,12983
CaptureMaxFrameRate,30
CaptureToPreviewSensitivityRatio,1024
Video1ExposureLineUnit,12386
Video1MaxFrameRate,120
Video1ToPreviewSensitivityRatio,1024
Video2ExposureLineUnit,25059
Video2MaxFrameRate,30
Video2ToPreviewSensitivityRatio,1024
Custom1ExposureLineUnit,25059
Custom1MaxFrameRate,29
Custom1ToPreviewSensitivityRatio,1024
Custom2ExposureLineUnit,25059
Custom2MaxFrameRate,29
Custom2ToPreviewSensitivityRatio,1024
Custom3ExposureLineUnit,25059
Custom3MaxFrameRate,29
Custom3ToPreviewSensitivityRatio,1024
Custom4ExposureLineUnit,25059
Custom4MaxFrameRate,29
Custom4ToPreviewSensitivityRatio,1024
Custom5ExposureLineUnit,25059
Custom5MaxFrameRate,29
Custom5ToPreviewSensitivityRatio,1024
FocusLength,350
Fno,22

// Preview table -- Use preview sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_RPEVIEW_AUTO
90,-50
1,10000,60,1144,1144
2,60,60,1144,2048
3,60,30,2048,2048
4,30,30,2048,4096
5,30,15,4096,4096
6,15,15,4096,8192
7,15,7,8192,8192
8,7,7,8192,16384
AETABLE_END

// Capture table -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_AUTO
90,-30
1,10000,60,1144,1144
2,60,60,1144,2048
3,60,30,2048,2048
4,30,30,2048,4096
5,30,15,4096,4096
6,15,15,4096,8192
7,15,7,8192,8192
8,7,7,8192,16384
AETABLE_END

// Video table -- Use video sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,32768
5,30,15,32768,32768
AETABLE_END

// Video1 table -- Use video1 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO1_AUTO
90,-30
1,10000,121,1195,1195
2,121,121,1195,21845
AETABLE_END

// Video2 table -- Use video2 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO2_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom1 table -- Use custom1 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM1_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom2 table -- Use custom2 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM2_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom3 table -- Use custom3 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM3_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom4 table -- Use custom4 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM4_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom5 table -- Use custom5 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM5_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Video Night table -- Use video sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO_NIGHT
90,-30
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,15,12288,12288
4,15,15,12288,35200
5,15,10,35200,35200
AETABLE_END

// Capture ISO100 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO100
90,-30
1,10000,5,1230,1230
AETABLE_END

// Capture ISO200 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO200
90,-30
1,10000,2000,1195,1195
2,2000,2000,1195,2460
3,2000,5,2460,2460
AETABLE_END

// Capture ISO400 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO400
90,-30
1,10000,2000,1195,1195
2,2000,2000,1195,4920
3,2000,5,4920,4920
AETABLE_END

// Capture ISO800 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO800
90,-30
1,10000,2000,1195,1195
2,2000,2000,1195,9840
3,2000,5,9840,9840
AETABLE_END

// Capture ISO1600 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO1600
90,-30
1,10000,2000,1195,1195
2,2000,2000,1195,19680
3,2000,5,19680,19680
AETABLE_END

// Strobe -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_STROBE
90,-30
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,15,12288,12288
4,15,15,12288,46080
AETABLE_END

// Table1 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX1
90,-50
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,15,12288,12288
4,15,15,12288,46080
5,15,5,46080,46080
AETABLE_END

// Table2 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX2
90,-30
1,10000,100,1195,1195
2,100,100,1195,4096
3,100,30,4096,4096
4,30,30,4096,16384
AETABLE_END

// Table3 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX3
90,-30
1,10000,30,1195,1195
2,30,30,1195,2048
3,30,15,2048,2048
4,15,15,2048,4096
5,15,10,4096,4096
6,10,10,4096,12288
AETABLE_END

// Table4 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX4
90,-30
1,5,5,1706,1706
AETABLE_END

// Table5 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX5
90,-30
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,15,12288,12288
4,15,15,12288,46080
AETABLE_END

AE_SCENE_AUTO, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX5
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
