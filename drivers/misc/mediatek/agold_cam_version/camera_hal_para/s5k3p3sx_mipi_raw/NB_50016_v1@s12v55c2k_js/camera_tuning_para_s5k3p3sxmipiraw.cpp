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

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "camera_custom_nvram.h"
#include "camera_custom_sensor.h"
#include "image_sensor.h"
#include "kd_imgsensor_define.h"
#include "camera_AE_PLineTable_s5k3p3sxmipiraw.h"
#include "camera_info_s5k3p3sxmipiraw.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"
#include "agold_camera_version.h"
#define NVRAM_TUNING_PARAM_NUM	5341001

const NVRAM_CAMERA_ISP_PARAM_STRUCT CAMERA_ISP_DEFAULT_VALUE =
{{
    //Version
    Version: NVRAM_CAMERA_PARA_FILE_VERSION,

    //SensorId
    SensorId: SENSOR_ID,
    ISPComm:{
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1819238756, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        }
    },
    ISPPca: {
#include INCLUDE_FILENAME_ISP_PCA_PARAM
    },
    ISPRegs:{
#include INCLUDE_FILENAME_ISP_REGS_PARAM
    },
    ISPMfbMixer:{{
      0x01FF0001, // MIX3_CTRL_0
      0x00FF0000, // MIX3_CTRL_1
      0xFFFF0000  // MIX3_SPARE
    }},
    ISPMulitCCM:{
      Poly22:{
        96550,      // i4R_AVG
        23684,      // i4R_STD
        109675,      // i4B_AVG
        26815,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
        {  // i4P00[9]
            9487500, -4082500, -290000, -1865000, 7667500, -677500, 15000, -5630000, 10737500
        },
        {  // i4P10[9]
            2467941, -3060822, 588028, -205679, -265, 209490, 301284, 1026976, -1324770
        },
        {  // i4P01[9]
            1991354, -2573754, 577060, -594218, -327975, 930036, -101178, -468473, 581932
        },
        {  // i4P20[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P11[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P02[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        }
      },

      AWBGain:{
        // Strobe
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // A
        {
          670,    // i4R
          512,    // i4G
          1353    // i4B
        },
        // TL84
        {
          911,    // i4R
          512,    // i4G
          1064    // i4B
        },
        // CWF
        {
          1049,    // i4R
          512,    // i4G
          1234    // i4B
        },
        // D65
        {
          1232,    // i4R
          512,    // i4G
          736    // i4B
        },
        // Reserved 1
        {
            512,    // i4R
            512,    // i4G
            512    // i4B
        },
        // Reserved 2
        {
            512,    // i4R
            512,    // i4G
            512    // i4B
        },
        // Reserved 3
        {
            512,    // i4R
            512,    // i4G
            512    // i4B
        }
      },
      Weight:{
        1, // Strobe
        1, // A
        1, // TL84
        1, // CWF
        1, // D65
        1, // Reserved 1
        1, // Reserved 2
        1  // Reserved 3
      }
    },
    MDPMulitCCM:{
      Poly22:{
        125225,      // i4R_AVG
        32141,      // i4R_STD
        165675,      // i4B_AVG
        30249,      // i4B_STD
        646,      // i4R_MAX
        527,      // i4R_MIN
        789,      // i4G_MAX
        670,      // i4G_MIN
        856,      // i4B_MAX
        721,      // i4B_MIN
        {  // i4P00[9]
            5995000, -505000, -370000, -1387500, 7165000, -657500, -532500, -2045000, 7697500
        },
        {  // i4P10[9]
            725905, -1081879, 355974, 627096, -389018, -238079, 626246, -86040, -540207
        },
        {  // i4P01[9]
            257857, -576218, 318361, -96902, -138571, 235473, 24959, 193148, -218107
        },
        {  // i4P20[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P11[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P02[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        }
      },

      AWBGain:{
        // Strobe
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // A
        {
          618,    // i4R
          512,    // i4G
          1487    // i4B
        },
        // TL84
        {
          844,    // i4R
          512,    // i4G
          1119    // i4B
        },
        // CWF
        {
          945,    // i4R
          512,    // i4G
          1219    // i4B
        },
        // D65
        {
          1144,    // i4R
          512,    // i4G
          762    // i4B
        },
        // Reserved 1
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // Reserved 2
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // Reserved 3
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        }
      },
      Weight:{
        1, // Strobe
        1, // A
        1, // TL84
        1, // CWF
        1, // D65
        1, // Reserved 1
        1, // Reserved 2
        1  // Reserved 3
      }
    },
    isp_ccm_ratio: 1.000000,
    //bInvokeSmoothCCM
    bInvokeSmoothCCM: MFALSE,

    DngMetadata:{
      0, // i4RefereceIlluminant1
      3, // i4RefereceIlluminant2
      rNoiseProfile:{
        {
          S:{
            0.000004,      // a
            0.000336       // b
          },
          O:{
            0.000000,      // a
            -0.000234       // b
          }
        },
        {
          S:{
            0.000004,      // a
            0.000336       // b
          },
          O:{
            0.000000,      // a
            -0.000234       // b
          }
        },
        {
          S:{
            0.000004,      // a
            0.000336       // b
          },
          O:{
            0.000000,      // a
            -0.000234       // b
          }
        },
        {
          S:{
            0.000004,      // a
            0.000336       // b
          },
          O:{
            0.000000,      // a
            -0.000234       // b
          }
        }
      }
  },
  ANR_TBL:
  {0}
}};

const NVRAM_CAMERA_3A_STRUCT CAMERA_3A_NVRAM_DEFAULT_VALUE =
{
    NVRAM_CAMERA_3A_FILE_VERSION, // u4Version
    SENSOR_ID, // SensorId

    // AE NVRAM
    {
        // rDevicesInfo
        {
            1152,    // u4MinGain, 1024 base = 1x
            16364,    // u4MaxGain, 16x
            100,    // u4MiniISOGain, ISOxx  
            128,    // u4GainStepUnit, 1x/8 
            16463,    // u4PreExpUnit 
            30,    // u4PreMaxFrameRate
            16463,    // u4VideoExpUnit  
            30,    // u4VideoMaxFrameRate 
            1024,    // u4Video2PreRatio, 1024 base = 1x 
            16463,    // u4CapExpUnit 
            29,    // u4CapMaxFrameRate
            1024,    // u4Cap2PreRatio, 1024 base = 1x
            16463,    // u4Video1ExpUnit
            120,    // u4Video1MaxFrameRate
            1024,    // u4Video12PreRatio, 1024 base = 1x
            16463,    // u4Video2ExpUnit
            30,    // u4Video2MaxFrameRate
            1024,    // u4Video22PreRatio, 1024 base = 1x
            16463,    // u4Custom1ExpUnit
            30,    // u4Custom1MaxFrameRate
            1024,    // u4Custom12PreRatio, 1024 base = 1x
            16463,    // u4Custom2ExpUnit
            30,    // u4Custom2MaxFrameRate
            1024,    // u4Custom22PreRatio, 1024 base = 1x
            16463,    // u4Custom3ExpUnit
            30,    // u4Custom3MaxFrameRate
            1024,    // u4Custom32PreRatio, 1024 base = 1x
            16463,    // u4Custom4ExpUnit
            30,    // u4Custom4MaxFrameRate
            1024,    // u4Custom42PreRatio, 1024 base = 1x
            16463,    // u4Custom5ExpUnit
            30,    // u4Custom5MaxFrameRate
            1024,    // u4Custom52PreRatio, 1024 base = 1x
            20,    // u4LensFno, Fno = 2.8
            350    // u4FocusLength_100x
        },
        // rHistConfig
        {
            4, // 2,   // u4HistHighThres
            40,  // u4HistLowThres
            2,   // u4MostBrightRatio
            1,   // u4MostDarkRatio
            160, // u4CentralHighBound
            20,  // u4CentralLowBound
            {240, 230, 220, 210, 200}, // u4OverExpThres[AE_CCT_STRENGTH_NUM]
            {62, 70, 82, 108, 141},  // u4HistStretchThres[AE_CCT_STRENGTH_NUM]
            {18, 22, 26, 30, 34}       // u4BlackLightThres[AE_CCT_STRENGTH_NUM]
        },
        // rCCTConfig
        {
            TRUE,    // bEnableBlackLight
            TRUE,    // bEnableHistStretch
            TRUE,    // bEnableAntiOverExposure
            TRUE,    // bEnableTimeLPF
            TRUE,    // bEnableCaptureThres
            TRUE,    // bEnableVideoThres
            TRUE,    // bEnableVideo1Thres
            TRUE,    // bEnableVideo2Thres
            TRUE,    // bEnableCustom1Thres
            TRUE,    // bEnableCustom2Thres
            TRUE,    // bEnableCustom3Thres
            TRUE,    // bEnableCustom4Thres
            TRUE,    // bEnableCustom5Thres
            TRUE,    // bEnableStrobeThres
            47,    // u4AETarget
            47,    // u4StrobeAETarget
            50,    // u4InitIndex
            4,    // u4BackLightWeight
            32,    // u4HistStretchWeight
            4,    // u4AntiOverExpWeight
            2,    // u4BlackLightStrengthIndex
            2,    // u4HistStretchStrengthIndex
            2,    // u4AntiOverExpStrengthIndex
            2,    // u4TimeLPFStrengthIndex
            {1, 3, 5, 7, 8},    // u4LPFConvergeTable[AE_CCT_STRENGTH_NUM] 
            90,    // u4InDoorEV = 9.0, 10 base 
            -14,    // i4BVOffset delta BV = value/10 
            64,                 // u4PreviewFlareOffset
            64,                 // u4CaptureFlareOffset
            3,                 // u4CaptureFlareThres
            64,                 // u4VideoFlareOffset
            3,                 // u4VideoFlareThres
            64,               // u4CustomFlareOffset
            3,                 //  u4CustomFlareThres
            64,                 // u4StrobeFlareOffset //12 bits
            3,                 // u4StrobeFlareThres // 0.5%
            160,                 // u4PrvMaxFlareThres //12 bit
            0,                 // u4PrvMinFlareThres
            160,                 // u4VideoMaxFlareThres // 12 bit
            0,                 // u4VideoMinFlareThres
            18,                // u4FlatnessThres              // 10 base for flatness condition.
            75,    // u4FlatnessStrength
            //rMeteringSpec
            {
                //rHS_Spec
                {
                    TRUE,//bEnableHistStretch           // enable histogram stretch
                    1024,//u4HistStretchWeight          // Histogram weighting value
                    50,//u4Pcent                      // 
                    140,//u4Thd                        // 0~255
                    75, //74,//u4FlatThd                    // 0~255
                    120,//u4FlatBrightPcent
                    120,//u4FlatDarkPcent
                    //sFlatRatio
                    {
                        1000,  //i4X1
                        1024,  //i4Y1
                        2400, //i4X2
                        0     //i4Y2
                    },
                    TRUE, //bEnableGreyTextEnhance
                    1800, //u4GreyTextFlatStart, > sFlatRatio.i4X1, < sFlatRatio.i4X2
                    {
                        10,     //i4X1
                        1024,   //i4Y1
                        80,     //i4X2
                        0       //i4Y2
                    }
                },
                //rAOE_Spec
                {
                    TRUE, //bEnableAntiOverExposure
                    1024, //u4AntiOverExpWeight
                    10, //u4Pcent
                    200, //u4Thd
                    TRUE, //bEnableCOEP
                    1,    //u4COEPcent
                    106,  //u4COEThd
                    0,  // u4BVCompRatio
                    //sCOEYRatio;     // the outer y ratio
                    {
                        23,   //i4X1
                        1024,  //i4Y1
                        47,   //i4X2
                        0     //i4Y2
                    },
                    //sCOEDiffRatio;  // inner/outer y difference ratio
                    {
                        1500, //i4X1
                        0,    //i4Y1
                        2100, //i4X2
                        1024   //i4Y2
                    }
                },
                //rABL_Spec
                {
                    TRUE,//bEnableBlackLigh
                    1024,//u4BackLightWeigh
                    400,//u4Pcent
                    40,//u4Thd
                    255, // center luminance
                    246, //256, // final target limitation, 256/128 = 2x
                    //sFgBgEVRatio
                    {
                        2100,//2200, //i4X1
                        0,    //i4Y1
                        4000, //i4X2
                        1024   //i4Y2
                    },
                    //sBVRatio
                    {
                        3800,//i4X1
                        0,   //i4Y1
                        5000,//i4X2
                        1024  //i4Y2
                    }
                },
                //rNS_Spec
                {
                    TRUE, // bEnableNightScene
                    10,//u4Pcent
                    175,//u4Thd
                    72,//u4FlatThd
                    180,//u4BrightTonePcent
                    80,//u4BrightToneThd
                    500,//u4LowBndPcent
                    5,//u4LowBndThd
                    26,//u4LowBndThdLimit
                    50,//u4FlatBrightPcent
                    300,//u4FlatDarkPcent
                    //sFlatRatio
                    {
                        1200, //i4X1
                        1024, //i4Y1
                      2800,//  2400, //i4X2
                        0    //i4Y2
                    },
                    //sBVRatio
                    {
                        -500, //i4X1
                        1024,  //i4Y1
                        3000, //i4X2
                        0     //i4Y2
                    },
                    TRUE, // bEnableNightSkySuppresion
                    //sSkyBVRatio
                    {
                        -4000, //i4X1
                        1024, //i4X2
                        -2000,  //i4Y1
                        0     //i4Y2
                    }
                },
                // rTOUCHFD_Spec
                {
                    40, //uMeteringYLowBound;
                    50, //uMeteringYHighBound;
                    40, //uFaceYLowBound;
                    50, //uFaceYHighBound;
                    3,  //uFaceCentralWeight;
                    120,//u4MeteringStableMax;
                    80, //u4MeteringStableMin;
                }
            }, //End rMeteringSpec
            // rFlareSpec
            {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uPrvFlareWeightArr[16];
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uVideoFlareWeightArr[16];
                96,                                               //u4FlareStdThrHigh;
                48,                                               //u4FlareStdThrLow;
                0,                                                //u4PrvCapFlareDiff;
                2,                                                //u4FlareMaxStepGap_Fast;
                0,//0,                                                //u4FlareMaxStepGap_Slow;
                1800,                                             //u4FlarMaxStepGapLimitBV;
                2,//0,                                                //u4FlareAEStableCount;
            },
            //rAEMoveRatio =
            {
                100,//100, //u4SpeedUpRatio 500
                100, //100, //u4GlobalRatio
                190, //u4Bright2TargetEnd  190 150
                10,//20,   //u4Dark2TargetStart
                90, //u4B2TEnd
                85,//70,  //u4B2TStart 70
                70,//60,  //u4D2TEnd 60
                85,  //u4D2TStart
            },

            //rAEVideoMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom3MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom4MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom5MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                40,  //u4B2TStart
                30,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEFaceMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190,  //u4Bright2TargetEnd
                10,    //u4Dark2TargetStart
                80, //u4B2TEnd
                30,  //u4B2TStart
                20,  //u4D2TEnd
                60,  //u4D2TStart
            },

            //rAETrackingMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190,  //u4Bright2TargetEnd
                10,    //u4Dark2TargetStart
                80, //u4B2TEnd
                30,  //u4B2TStart
                20,  //u4D2TEnd
                60,  //u4D2TStart
            },
            //rAEAOENVRAMParam =
            {
                1,      // i4AOEStrengthIdx: 0 / 1 / 2
                130,    // u4BVCompRatio
                {
                    {
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        10,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        1,    //u4AOE_LowlightBound
                        145,    //u4AOESceneLV_L
                        180,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        15, //20,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        3, //10,    //u4AOE_LowlightBound
                        145,    //u4AOESceneLV_L
                        180,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        25,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        8,    //u4AOE_LowlightBound
                        145,    //u4AOESceneLV_L
                        180,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    }
                }
            }
        }
    },

        // AWB NVRAM
    AWB_NVRAM_START
    {
        {
          {
            // AWB calibration data
            {
                // rUnitGain (unit gain: 1.0 = 512)
                {
                    1180,    // i4R
                    512,    // i4G
                    839    // i4B
                },
                // rGoldenGain (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rUnitGain TL84 (unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rGoldenGain TL84 (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rUnitGain Alight (unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rGoldenGain Alight (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rD65Gain (D65 WB gain: 1.0 = 512)
                {
                    1270,    // D65Gain_R
                    512,    // D65Gain_G
                    710    // D65Gain_B
                }
            },
            // Original XY coordinate of AWB light source
            {
                // Strobe
                {
                    89,    // i4X
                    -519    // i4Y
                },
                // Horizon
                {
                    -371,    // OriX_Hor
                    -444    // OriY_Hor
                },
                // A
                {
                    -215,    // OriX_A
                    -439    // OriY_A
                },
                // TL84
                {
                    -34,    // OriX_TL84
                    -490    // OriY_TL84
                },
                // CWF
                {
                    -12,    // OriX_CWF
                    -572    // OriY_CWF
                },
                // DNP
                {
                    72,    // OriX_DNP
                    -467    // OriY_DNP
                },
                // D65
                {
                    215,    // OriX_D65
                    -456    // OriY_D65
                },
                // DF
                {
                    0,    // OriX_DF
                    0    // OriY_DF
                }
            },
            // Rotated XY coordinate of AWB light source
            {
                // Strobe
                {
                    97,    // i4X
                    -518    // i4Y
                },
                // Horizon
                {
                    -364,    // RotX_Hor
                    -450    // RotY_Hor
                },
                // A
                {
                    -208,    // RotX_A
                    -442    // RotY_A
                },
                // TL84
                {
                    -26,    // RotX_TL84
                    -491    // RotY_TL84
                },
                // CWF
                {
                    -3,    // RotX_CWF
                    -572    // RotY_CWF
                },
                // DNP
                {
                    79,    // RotX_DNP
                    -466    // RotY_DNP
                },
                // D65
                {
                    222,    // RotX_D65
                    -453    // RotY_D65
                },
                // DF
                {
                    211,    // RotX_DF
                    -558    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    1166,    // i4R
                    512,    // i4G
                    916    // i4B
                },
                // Horizon 
                {
                    566,    // AWBGAIN_HOR_R
                    512,    // AWBGAIN_HOR_G
                    1542    // AWBGAIN_HOR_B
                },
                // A 
                {
                    693,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1241    // AWBGAIN_A_B
                },
                // TL84 
                {
                    949,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1041    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    1093,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1129    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    1063,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    874    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    1270,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    710    // AWBGAIN_D65_B
                },
                // DF 
                {
                    512,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    512    // AWBGAIN_DF_B
                }
            },
            // Rotation matrix parameter
            {
                -1,    // RotationAngle
                256,    // Cos
                -4    // Sin
            },
            // Daylight locus parameter
            {
                -125,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    1240,    // i4R
                    530,    // i4G
                    730    // i4B
                },
                // DaylightLocus_H
                {
                    1035,    // i4R
                    512,    // i4G
                    866    // i4B
                },
                // Temporal General
                {
                    1270,    // i4R
                    512,    // i4G
                    710    // i4B
                },
                // AWB LSC Gain
                {
                    1015,        // i4R
                    512,        // i4G
                    883        // i4B
                }
            },
            // AWB light area
            {
                // Strobe:FIXME
                {
                    147,    // i4RightBound
                    47,    // i4LeftBound
                    -468,    // i4UpperBound
                    -568    // i4LowerBound
                },
                // Tungsten
                {
                    -99,    // TungRightBound
                    -764,    // TungLeftBound
                    -395,    // TungUpperBound
                    -490    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -99,    // WFluoRightBound
                    -764,    // WFluoLeftBound
                    -490,    // WFluoUpperBound
                    -662    // WFluoLowerBound
                },
                // Fluorescent
                {
                    45,    // FluoRightBound
                    -99,    // FluoLeftBound
                    -393,    // FluoUpperBound
                    -532    // FluoLowerBound
                },
                // CWF
                {
                91,    // CWFRightBound
                -99,    // CWFLeftBound
                -532,    // CWFUpperBound
                -627    // CWFLowerBound
                },
                // Daylight
                {
                    252,    // DayRightBound
                    45,    // DayLeftBound
                    -350,    // DayUpperBound
                    -532    // DayLowerBound
                },
                // Shade
                {
                    582,    // ShadeRightBound
                    252,    // ShadeLeftBound
                    -393,    // ShadeUpperBound
                    -501    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    252,    // DFRightBound
                    91,    // DFLeftBound
                    -532,    // DFUpperBound
                    -627    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    582,    // PRefRightBound
                    -764,    // PRefLeftBound
                    -350,    // PRefUpperBound
                    -662    // PRefLowerBound
                },
                // Daylight
                {
                    277,    // PDayRightBound
                    45,    // PDayLeftBound
                    -350,    // PDayUpperBound
                    -532    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    377,    // PCloudyRightBound
                    202,    // PCloudyLeftBound
                    -350,    // PCloudyUpperBound
                    -532    // PCloudyLowerBound
                },
                // Shade
                {
                    477,    // PShadeRightBound
                    202,    // PShadeLeftBound
                    -350,    // PShadeUpperBound
                    -532    // PShadeLowerBound
                },
                // Twilight
                {
                    45,    // PTwiRightBound
                    -115,    // PTwiLeftBound
                    -350,    // PTwiUpperBound
                    -532    // PTwiLowerBound
                },
                // Fluorescent
                {
                    272,    // PFluoRightBound
                    -126,    // PFluoLeftBound
                    -403,    // PFluoUpperBound
                    -622    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -108,    // PWFluoRightBound
                    -308,    // PWFluoLeftBound
                    -403,    // PWFluoUpperBound
                    -622    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -108,    // PIncaRightBound
                    -308,    // PIncaLeftBound
                    -350,    // PIncaUpperBound
                    -532    // PIncaLowerBound
                },
                // Gray World
                {
                    5000,    // PGWRightBound
                    -5000,    // PGWLeftBound
                    5000,    // PGWUpperBound
                    -5000    // PGWLowerBound
                }
            },
            // PWB default gain	
            {
                // Daylight
                {
                    1150,    // PWB_Day_R
                    512,    // PWB_Day_G
                    758    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    1372,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    638    // PWB_Cloudy_B
                },
                // Shade
                {
                    1469,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    597    // PWB_Shade_B
                },
                // Twilight
                {
                    878,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    984    // PWB_Twi_B
                },
                // Fluorescent
                {
                    1120,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    940    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    761,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1366    // PWB_WFluo_B
                },
                // Incandescent
                {
                    692,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1238    // PWB_Inca_B
                },
                // Gray World
                {
                    512,    // PWB_GW_R
                    512,    // PWB_GW_G
                    512    // PWB_GW_B
                }
            },
            // AWB preference color	
            {
                // Tungsten
                {
                    40,    // TUNG_SLIDER
                    4868    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    40,    // WFluo_SLIDER
                    4573    // WFluo_OFFS
                },
                // Shade
                {
                    50,    // Shade_SLIDER
                    409    // Shade_OFFS
                },
                // Sunset Area
                {
                    105,   // i4Sunset_BoundXr_Thr
                    -466    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -99,   // i4BoundXrThr
                    -495    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -27,   // i4BoundXrThr
                    -514    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -99,   // i4BoundXrThr
                    -576    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -4,   // i4BoundXrThr
                    -602    // i4BoundYrThr
                },
            },
            // CCT estimation
            {
                // CCT
                {
                    2300,    // i4CCT[0]
                    2850,    // i4CCT[1]
                    3750,    // i4CCT[2]
                    5100,    // i4CCT[3]
                    6500     // i4CCT[4]
                },
                // Rotated X coordinate
                {
                -586,    // i4RotatedXCoordinate[0]
                -430,    // i4RotatedXCoordinate[1]
                -248,    // i4RotatedXCoordinate[2]
                -143,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
                }
            }
        },
        // Algorithm Tuning Parameter
        {
            // AWB Backup Enable
            0,

            // Daylight locus offset LUTs for tungsten
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for WF
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for Shade
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
            },
            // Preference gain for each light source
            {
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, 
                    {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}
                }, // TUNGSTEN
                {
                    {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, 
                    {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}
                }, // WARM F
                {
                    {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, 
                    {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}
                }, // F
                {
                    {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, 
                    {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}
                }, // CWF
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                }, // DAYLIGHT
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // SHADE
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                } // DAYLIGHT F
            },
            // Parent block weight parameter
            {
                1,      // bEnable
                6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
            },
            // AWB LV threshold for predictor
            {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
            },
            // AWB number threshold for temporal predictor
            {
                65,     // i4Neutral_ParentBlk_Thr
                //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                // AWB light neutral noise reduction for outdoor
                {
                    //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    // Non neutral
	                { 3,   3,   3,   3,   3,   3,   3,   3,    3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // Flurescent
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // CWF
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // Daylight
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
	                // DF
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                },
                // AWB feature detection
                {
                    // Sunset Prop
                    {
                        1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                        10,         // i4SunsetCountThr
                        0,          // i4SunsetCountRatio_L
                        171         // i4SunsetCountRatio_H
                    },

                    // Shade F Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        128         // i4DaylightProb
                    },
                    // Shade CWF Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        192         // i4DaylightProb
                    }

                },

                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                {
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },

                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                {
                    //LV0  1    2    3    4    5    6    7    8    9     10    11   12   13   14   15  16   17   18
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100,  50,  25,   0,  0,   0,   0}, // Strobe
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0}, // Tungsten
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,   75,  50,  25,  25,  25,  0,   0,   0}, // Warm fluorescent
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  95,  75,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    { 90,  90,  90,  90,  90,  90,  90,  90,  90,  90,   80,   55,  30,  30,  30,  30,  0,   0,   0}, // CWF
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100, 100,  75,  50, 40,  30,  20}, // Daylight
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100,  75,  50,  25,   0,  0,   0,   0}, // Shade
                    { 90,  90,  90,  90,  90,  90,  90,  90,  90,  90,   80,   55,  30,  30,  30,  30,  0,   0,   0}  // Daylight fluorescent
                },

                // AWB tuning information
                {
                    0,		// project code
                    0,		// model
                    0,		// date
                    0,		// reserved 0
                    0,		// reserved 1
                    0,		// reserved 2
                    0,		// reserved 3
                    0,		// reserved 4
                }
            }
        },
        {
          {
            // AWB calibration data
            {
                // rUnitGain (unit gain: 1.0 = 512)
                {
                    1024,    // i4R
                    512,    // i4G
                    879    // i4B
                },
                // rGoldenGain (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rUnitGain TL84 (unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rGoldenGain TL84 (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rUnitGain Alight (unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rGoldenGain Alight (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rD65Gain (D65 WB gain: 1.0 = 512)
                {
                    1270,    // D65Gain_R
                    512,    // D65Gain_G
                    710    // D65Gain_B
                }
            },
            // Original XY coordinate of AWB light source
            {
                // Strobe
                {
                    89,    // i4X
                    -519    // i4Y
                },
                // Horizon
                {
                    -371,    // OriX_Hor
                    -444    // OriY_Hor
                },
                // A
                {
                    -215,    // OriX_A
                    -439    // OriY_A
                },
                // TL84
                {
                    -34,    // OriX_TL84
                    -490    // OriY_TL84
                },
                // CWF
                {
                    -12,    // OriX_CWF
                    -572    // OriY_CWF
                },
                // DNP
                {
                    72,    // OriX_DNP
                    -467    // OriY_DNP
                },
                // D65
                {
                    215,    // OriX_D65
                    -456    // OriY_D65
                },
                // DF
                {
                    0,    // OriX_DF
                    0    // OriY_DF
                }
            },
            // Rotated XY coordinate of AWB light source
            {
                // Strobe
                {
                    97,    // i4X
                    -518    // i4Y
                },
                // Horizon
                {
                    -364,    // RotX_Hor
                    -450    // RotY_Hor
                },
                // A
                {
                    -208,    // RotX_A
                    -442    // RotY_A
                },
                // TL84
                {
                    -26,    // RotX_TL84
                    -491    // RotY_TL84
                },
                // CWF
                {
                    -3,    // RotX_CWF
                    -572    // RotY_CWF
                },
                // DNP
                {
                    79,    // RotX_DNP
                    -466    // RotY_DNP
                },
                // D65
                {
                    222,    // RotX_D65
                    -453    // RotY_D65
                },
                // DF
                {
                    211,    // RotX_DF
                    -558    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    1166,    // i4R
                    512,    // i4G
                    916    // i4B
                },
                // Horizon 
                {
                    566,    // AWBGAIN_HOR_R
                    512,    // AWBGAIN_HOR_G
                    1542    // AWBGAIN_HOR_B
                },
                // A 
                {
                    693,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1241    // AWBGAIN_A_B
                },
                // TL84 
                {
                    949,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1041    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    1093,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1129    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    1063,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    874    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    1270,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    710    // AWBGAIN_D65_B
                },
                // DF 
                {
                    512,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    512    // AWBGAIN_DF_B
                }
            },
            // Rotation matrix parameter
            {
                -1,    // RotationAngle
                256,    // Cos
                -4    // Sin
            },
            // Daylight locus parameter
            {
                -125,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    1240,    // i4R
                    530,    // i4G
                    730    // i4B
                },
                // DaylightLocus_H
                {
                    1035,    // i4R
                    512,    // i4G
                    866    // i4B
                },
                // Temporal General
                {
                    1270,    // i4R
                    512,    // i4G
                    710    // i4B
                },
                // AWB LSC Gain
                {
                    1015,        // i4R
                    512,        // i4G
                    883        // i4B
                }
            },
            // AWB light area
            {
                // Strobe:FIXME
                {
                    147,    // i4RightBound
                    47,    // i4LeftBound
                    -468,    // i4UpperBound
                    -568    // i4LowerBound
                },
                // Tungsten
                {
                    -99,    // TungRightBound
                    -764,    // TungLeftBound
                    -395,    // TungUpperBound
                    -490    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -99,    // WFluoRightBound
                    -764,    // WFluoLeftBound
                    -490,    // WFluoUpperBound
                    -662    // WFluoLowerBound
                },
                // Fluorescent
                {
                    45,    // FluoRightBound
                    -99,    // FluoLeftBound
                    -393,    // FluoUpperBound
                    -532    // FluoLowerBound
                },
                // CWF
                {
                91,    // CWFRightBound
                -99,    // CWFLeftBound
                -532,    // CWFUpperBound
                -627    // CWFLowerBound
                },
                // Daylight
                {
                    252,    // DayRightBound
                    45,    // DayLeftBound
                    -350,    // DayUpperBound
                    -532    // DayLowerBound
                },
                // Shade
                {
                    582,    // ShadeRightBound
                    252,    // ShadeLeftBound
                    -393,    // ShadeUpperBound
                    -501    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    252,    // DFRightBound
                    91,    // DFLeftBound
                    -532,    // DFUpperBound
                    -627    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    582,    // PRefRightBound
                    -764,    // PRefLeftBound
                    -350,    // PRefUpperBound
                    -662    // PRefLowerBound
                },
                // Daylight
                {
                    277,    // PDayRightBound
                    45,    // PDayLeftBound
                    -350,    // PDayUpperBound
                    -532    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    377,    // PCloudyRightBound
                    202,    // PCloudyLeftBound
                    -350,    // PCloudyUpperBound
                    -532    // PCloudyLowerBound
                },
                // Shade
                {
                    477,    // PShadeRightBound
                    202,    // PShadeLeftBound
                    -350,    // PShadeUpperBound
                    -532    // PShadeLowerBound
                },
                // Twilight
                {
                    45,    // PTwiRightBound
                    -115,    // PTwiLeftBound
                    -350,    // PTwiUpperBound
                    -532    // PTwiLowerBound
                },
                // Fluorescent
                {
                    272,    // PFluoRightBound
                    -126,    // PFluoLeftBound
                    -403,    // PFluoUpperBound
                    -622    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -108,    // PWFluoRightBound
                    -308,    // PWFluoLeftBound
                    -403,    // PWFluoUpperBound
                    -622    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -108,    // PIncaRightBound
                    -308,    // PIncaLeftBound
                    -350,    // PIncaUpperBound
                    -532    // PIncaLowerBound
                },
                // Gray World
                {
                    5000,    // PGWRightBound
                    -5000,    // PGWLeftBound
                    5000,    // PGWUpperBound
                    -5000    // PGWLowerBound
                }
            },
            // PWB default gain	
            {
                // Daylight
                {
                    1150,    // PWB_Day_R
                    512,    // PWB_Day_G
                    758    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    1372,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    638    // PWB_Cloudy_B
                },
                // Shade
                {
                    1469,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    597    // PWB_Shade_B
                },
                // Twilight
                {
                    878,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    984    // PWB_Twi_B
                },
                // Fluorescent
                {
                    1120,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    940    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    761,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1366    // PWB_WFluo_B
                },
                // Incandescent
                {
                    692,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1238    // PWB_Inca_B
                },
                // Gray World
                {
                    512,    // PWB_GW_R
                    512,    // PWB_GW_G
                    512    // PWB_GW_B
                }
            },
            // AWB preference color	
            {
                // Tungsten
                {
                    40,    // TUNG_SLIDER
                    4868    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    40,    // WFluo_SLIDER
                    4573    // WFluo_OFFS
                },
                // Shade
                {
                    50,    // Shade_SLIDER
                    409    // Shade_OFFS
                },
                // Sunset Area
                {
                    105,   // i4Sunset_BoundXr_Thr
                    -466    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -99,   // i4BoundXrThr
                    -495    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -27,   // i4BoundXrThr
                    -514    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -99,   // i4BoundXrThr
                    -576    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -4,   // i4BoundXrThr
                    -602    // i4BoundYrThr
                },
            },
            // CCT estimation
            {
                // CCT
                {
                    2300,    // i4CCT[0]
                    2850,    // i4CCT[1]
                    3750,    // i4CCT[2]
                    5100,    // i4CCT[3]
                    6500     // i4CCT[4]
                },
                // Rotated X coordinate
                {
                -586,    // i4RotatedXCoordinate[0]
                -430,    // i4RotatedXCoordinate[1]
                -248,    // i4RotatedXCoordinate[2]
                -143,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
                }
            }
        },
        // Algorithm Tuning Parameter
        {
            // AWB Backup Enable
            0,

            // Daylight locus offset LUTs for tungsten
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for WF
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for Shade
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
            },
            // Preference gain for each light source
            {
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, 
                    {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}, {430, 512, 555}
                }, // TUNGSTEN
                {
                    {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, 
                    {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}, {430, 512, 560}
                }, // WARM F
                {
                    {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, 
                    {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}, {470, 512, 560}
                }, // F
                {
                    {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, 
                    {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}, {480, 512, 630}
                }, // CWF
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                }, // DAYLIGHT
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // SHADE
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                } // DAYLIGHT F
            },
            // Parent block weight parameter
            {
                1,      // bEnable
                6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
            },
            // AWB LV threshold for predictor
            {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
            },
            // AWB number threshold for temporal predictor
            {
                65,     // i4Neutral_ParentBlk_Thr
                //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                // AWB light neutral noise reduction for outdoor
                {
                    //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    // Non neutral
                    {   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Flurescent
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // CWF
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Daylight
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
                    // DF
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                },
                // AWB feature detection
                {
                    // Sunset Prop
                    {
                        1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                        10,         // i4SunsetCountThr
                        0,          // i4SunsetCountRatio_L
                        171         // i4SunsetCountRatio_H
                    },

                    // Shade F Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        128         // i4DaylightProb
                    },

                    // Shade CWF Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        192         // i4DaylightProb
                    },
                },

                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                {
                    //LV0   1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },

                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                {   //LV0    1     2     3      4     5     6     7     8      9      10     11    12   13     14    15   16    17    18
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   0,   0,   0,   0}, // Strobe
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0}, // Tungsten
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,  25,  25,   0,   0,   0}, // Warm fluorescent
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  95,  75,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0}, // CWF
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  40,  30,  20}, // Daylight
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0,   0}, // Shade
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0} // Daylight fluorescent
                },

                // AWB tuning information
                {
                    0,		// project code
                    0,		// model
                    0,		// date
                    0,		// reserved 0
                    0,		// reserved 1
                    0,		// reserved 2
                    0,		// reserved 3
                    0,		// reserved 4
                }
            }
        }
    },

    // Flash AWB NVRAM
    {
#include INCLUDE_FILENAME_FLASH_AWB_PARA
    },

    {0}
};

#include INCLUDE_FILENAME_ISP_LSC_PARAM
//};  //  namespace

const CAMERA_TSF_TBL_STRUCT CAMERA_TSF_DEFAULT_VALUE =
{
        {
                1,  // isTsfEn
                2,  // tsfCtIdx
                {20, 2000, -110, -110, 512, 512, 512, 0}    // rAWBInput[8]
        },
    #include INCLUDE_FILENAME_TSF_PARA                                                                         
    #include INCLUDE_FILENAME_TSF_DATA                                                                         
}; 
const NVRAM_CAMERA_FEATURE_STRUCT CAMERA_FEATURE_DEFAULT_VALUE =
{
#include INCLUDE_FILENAME_FEATURE_PARA
};

agold_camera_version agold_camera_para = {
	"NB_50016_v1",
	(NVRAM_CAMERA_ISP_PARAM_STRUCT*)&CAMERA_ISP_DEFAULT_VALUE,
	(NVRAM_CAMERA_3A_STRUCT*)&CAMERA_3A_NVRAM_DEFAULT_VALUE,
	(NVRAM_CAMERA_SHADING_STRUCT*)&CAMERA_SHADING_DEFAULT_VALUE,
	&g_PlineTableMapping,
	(CAMERA_TSF_TBL_STRUCT*)&CAMERA_TSF_DEFAULT_VALUE,
	&CAMERA_FEATURE_DEFAULT_VALUE,
	
};
