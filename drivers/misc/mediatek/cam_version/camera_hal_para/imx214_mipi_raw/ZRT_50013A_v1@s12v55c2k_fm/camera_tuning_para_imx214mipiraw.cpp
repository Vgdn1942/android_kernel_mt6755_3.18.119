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
#include "camera_AE_PLineTable_imx214mipiraw.h"
#include "camera_info_imx214mipiraw.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"


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
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
        74125,      // i4R_AVG
        13342,      // i4R_STD
        90800,      // i4B_AVG
        14466,      // i4B_STD
        4095,      // i4R_MAX
        512,      // i4R_MIN
        4095,      // i4G_MAX
        512,      // i4G_MIN
        4095,      // i4B_MAX
        512,      // i4B_MIN
        {  // i4P00[9]
            7220000, -2120000, -10000, -2030000, 8040000, -910000, -950000, -2110000, 8180000
        },
        {  // i4P10[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P01[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
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
          1016,    // i4R
          512,    // i4G
          1101    // i4B
        },
        // A
        {
          572,    // i4R
          512,    // i4G
          1047    // i4B
        },
        // TL84
        {
          720,    // i4R
          512,    // i4G
          930    // i4B
        },
        // CWF
        {
          781,    // i4R
          512,    // i4G
          950    // i4B
        },
        // D65
        {
          892,    // i4R
          512,    // i4G
          705    // i4B
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
          1016,    // i4R
          512,    // i4G
          1101    // i4B
        },
        // A
        {
          572,    // i4R
          512,    // i4G
          1047    // i4B
        },
        // TL84
        {
          720,    // i4R
          512,    // i4G
          930    // i4B
        },
        // CWF
        {
          781,    // i4R
          512,    // i4G
          950    // i4B
        },
        // D65
        {
          892,    // i4R
          512,    // i4G
          705    // i4B
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
    isp_ccm_ratio: 0.500000,
    //bInvokeSmoothCCM
    bInvokeSmoothCCM: MTRUE,

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
            1144,    // u4MinGain, 1024 base = 1x
            8192,    // u4MaxGain, 16x
            33,    // u4MiniISOGain, ISOxx  
            128,    // u4GainStepUnit, 1x/8 
            20593,    // u4PreExpUnit 
            30,    // u4PreMaxFrameRate
            10434,    // u4VideoExpUnit  
            30,    // u4VideoMaxFrameRate 
            1024,    // u4Video2PreRatio, 1024 base = 1x 
            10434,    // u4CapExpUnit 
            29,    // u4CapMaxFrameRate
            1024,    // u4Cap2PreRatio, 1024 base = 1x
            10434,    // u4Video1ExpUnit
            120,    // u4Video1MaxFrameRate
            1024,    // u4Video12PreRatio, 1024 base = 1x
            20593,    // u4Video2ExpUnit
            30,    // u4Video2MaxFrameRate
            1024,    // u4Video22PreRatio, 1024 base = 1x
            19770,    // u4Custom1ExpUnit
            30,    // u4Custom1MaxFrameRate
            1024,    // u4Custom12PreRatio, 1024 base = 1x
            19770,    // u4Custom2ExpUnit
            30,    // u4Custom2MaxFrameRate
            1024,    // u4Custom22PreRatio, 1024 base = 1x
            19770,    // u4Custom3ExpUnit
            30,    // u4Custom3MaxFrameRate
            1024,    // u4Custom32PreRatio, 1024 base = 1x
            19770,    // u4Custom4ExpUnit
            30,    // u4Custom4MaxFrameRate
            1024,    // u4Custom42PreRatio, 1024 base = 1x
            19770,    // u4Custom5ExpUnit
            30,    // u4Custom5MaxFrameRate
            1024,    // u4Custom52PreRatio, 1024 base = 1x
            18,    // u4LensFno, Fno = 2.8
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
            85,    // u4AETarget
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
            -18,    // i4BVOffset delta BV = value/10 
            0,    // u4PreviewFlareOffset
            0,    // u4CaptureFlareOffset
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
                    40, //50, //20,//u4Pcent                      // 1%=10, 0~1000
                    160, //166,//176,//u4Thd                        // 0~255
                    75, //54, //74,//u4FlatThd                    // 0~255

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
                    10,    //u4Pcent
                    200,  //u4Thd

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
                    22,//u4Thd,
                    255, // center luminance
                    256, // final target limitation, 256/128 = 2x
                    //sFgBgEVRatio
                    {
                        2200, //i4X1
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
                    5,    //u4Pcent
                    174,  //u4Thd
                    72, //52,   //u4FlatThd

                    200,  //u4BrightTonePcent
                    90, //u4BrightToneThd

                    500,  //u4LowBndPcent
                    5,    //u4LowBndThd
                    20,    //u4LowBndThdLimit

                    50,  //u4FlatBrightPcent;
                    300,   //u4FlatDarkPcent;
                    //sFlatRatio
                    {
                        1200, //i4X1
                        1024, //i4Y1
                        2400, //i4X2
                        0    //i4Y2
                    },
                    //sBVRatio
                    {
                        -500, //i4X1
                        1024,  //i4Y1
                        2000, //i4X2
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
                4,                                                //u4FlareMaxStepGap_Fast;
                0,                                                //u4FlareMaxStepGap_Slow;
                1800,                                             //u4FlarMaxStepGapLimitBV;
                0,                                                //u4FlareAEStableCount;
            },
            //rAEMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190, //u4Bright2TargetEnd
                20,   //u4Dark2TargetStart
                90, //u4B2TEnd
                70,  //u4B2TStart
                60,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideoMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAEVideo2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom3MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom4MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
                90,  //u4D2TStart
            },

            //rAECustom5MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150,  //u4Bright2TargetEnd
                20,    //u4Dark2TargetStart
                90, //u4B2TEnd
                10,  //u4B2TStart
                10,  //u4D2TEnd
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
                128,      // u4BVCompRatio
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
                        32,  //u4Y_Target
                        20,  //u4AOE_OE_percent
                        190,  //u4AOE_OEBound
                        15, //20,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        10,  //u4AOE_LowlightBound
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
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
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
                    1013,    // D65Gain_R
                    512,    // D65Gain_G
                    739    // D65Gain_B
                }
            },
            // Original XY coordinate of AWB light source
            {
                // Strobe
                {
                    0,    // i4X
                    0    // i4Y
                },
                // Horizon
                {
                    -428,    // OriX_Hor
                    -367    // OriY_Hor
                },
                // A
                {
                    -335,    // OriX_A
                    -390    // OriY_A
                },
                // TL84
                {
                    -171,    // OriX_TL84
                    -414    // OriY_TL84
                },
                // CWF
                {
                    -131,    // OriX_CWF
                    -494    // OriY_CWF
                },
                // DNP
                {
                    -11,    // OriX_DNP
                    -419    // OriY_DNP
                },
                // D65
                {
                    117,    // OriX_D65
                    -387    // OriY_D65
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
                    0,    // i4X
                    0    // i4Y
                },
                // Horizon
                {
                    -428,    // RotX_Hor
                    -367    // RotY_Hor
                },
                // A
                {
                    -335,    // RotX_A
                    -390    // RotY_A
                },
                // TL84
                {
                    -171,    // RotX_TL84
                    -414    // RotY_TL84
                },
                // CWF
                {
                    -131,    // RotX_CWF
                    -494    // RotY_CWF
                },
                // DNP
                {
                    -11,    // RotX_DNP
                    -419    // RotY_DNP
                },
                // D65
                {
                    117,    // RotX_D65
                    -387    // RotY_D65
                },
                // DF
                {
                    99,    // RotX_DF
                    -481    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    512,    // i4R
                    512,    // i4G
                    512    // i4B
                },
                // Horizon 
                {
                    512,    // AWBGAIN_HOR_R
                    556,    // AWBGAIN_HOR_G
                    1630    // AWBGAIN_HOR_B
                },
                // A 
                {
                    552,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1367    // AWBGAIN_A_B
                },
                // TL84 
                {
                    712,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1131    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    837,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1192    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    889,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    916    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    1013,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    739    // AWBGAIN_D65_B
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
                0,    // RotationAngle
                256,    // Cos
                0    // Sin
            },
            // Daylight locus parameter
            {
                -127,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    983,    // i4R
                    530,    // i4G
                    759    // i4B
                },
                // DaylightLocus_H
                {
                    831,    // i4R
                    512,    // i4G
                    899    // i4B
                },
                // Temporal General
                {
                    1013,    // i4R
                    512,    // i4G
                    739    // i4B
                },
                // AWB LSC Gain
                {
                    831,        // i4R
                    512,        // i4G
                    899        // i4B
                }
            },
            // AWB light area
            {
                // Strobe:FIXME
                {
                    0,    // i4RightBound
                    0,    // i4LeftBound
                    0,    // i4UpperBound
                    0    // i4LowerBound
                },
                // Tungsten
                {
                    -237,    // TungRightBound
                    -828,    // TungLeftBound
                    -312,    // TungUpperBound
                    -402    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -237,    // WFluoRightBound
                    -828,    // WFluoLeftBound
                    -402,    // WFluoUpperBound
                    -584    // WFluoLowerBound
                },
                // Fluorescent
                {
                    -63,    // FluoRightBound
                    -237,    // FluoLeftBound
                    -327,    // FluoUpperBound
                    -454    // FluoLowerBound
                },
                // CWF
                {
                -63,    // CWFRightBound
                -237,    // CWFLeftBound
                -454,    // CWFUpperBound
                -549    // CWFLowerBound
                },
                // Daylight
                {
                    147,    // DayRightBound
                    -63,    // DayLeftBound
                    -357,    // DayUpperBound
                    -484    // DayLowerBound
                },
                // Shade
                {
                    477,    // ShadeRightBound
                    147,    // ShadeLeftBound
                    -357,    // ShadeUpperBound
                    -460    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    147,    // DFRightBound
                    -63,    // DFLeftBound
                    -484,    // DFUpperBound
                    -579    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    477,    // PRefRightBound
                    -828,    // PRefLeftBound
                    0,    // PRefUpperBound
                    -584    // PRefLowerBound
                },
                // Daylight
                {
                    172,    // PDayRightBound
                    -63,    // PDayLeftBound
                    -357,    // PDayUpperBound
                    -484    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    272,    // PCloudyRightBound
                    97,    // PCloudyLeftBound
                    -357,    // PCloudyUpperBound
                    -484    // PCloudyLowerBound
                },
                // Shade
                {
                    372,    // PShadeRightBound
                    97,    // PShadeLeftBound
                    -357,    // PShadeUpperBound
                    -484    // PShadeLowerBound
                },
                // Twilight
                {
                    -63,    // PTwiRightBound
                    -223,    // PTwiLeftBound
                    -357,    // PTwiUpperBound
                    -484    // PTwiLowerBound
                },
                // Fluorescent
                {
                    167,    // PFluoRightBound
                    -271,    // PFluoLeftBound
                    -337,    // PFluoUpperBound
                    -544    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -235,    // PWFluoRightBound
                    -435,    // PWFluoLeftBound
                    -337,    // PWFluoUpperBound
                    -544    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -235,    // PIncaRightBound
                    -435,    // PIncaLeftBound
                    -357,    // PIncaUpperBound
                    -484    // PIncaLowerBound
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
                    974,    // PWB_Day_R
                    512,    // PWB_Day_G
                    840    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    1161,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    705    // PWB_Cloudy_B
                },
                // Shade
                {
                    1243,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    659    // PWB_Shade_B
                },
                // Twilight
                {
                    745,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    1098    // PWB_Twi_B
                },
                // Fluorescent
                {
                    866,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    997    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    591,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1463    // PWB_WFluo_B
                },
                // Incandescent
                {
                    575,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1424    // PWB_Inca_B
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
                    5268    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    40,    // WFluo_SLIDER
                    5023    // WFluo_OFFS
                },
                // Shade
                {
                    50,    // Shade_SLIDER
                    409    // Shade_OFFS
                },
                // Sunset Area
                {
                    29,   // i4Sunset_BoundXr_Thr
                    -419    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -237,   // i4BoundXrThr
                    -418    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -150,   // i4BoundXrThr
                    -436    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -237,   // i4BoundXrThr
                    -498    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -134,   // i4BoundXrThr
                    -524    // i4BoundYrThr
                },
            },
            {
                {
                    2300,    // i4CCT[0]
                    2850,    // i4CCT[1]
                    3750,    // i4CCT[2]
                    5100,    // i4CCT[3]
                    6500     // i4CCT[4]
                },
                {
                -545,    // i4RotatedXCoordinate[0]
                -452,    // i4RotatedXCoordinate[1]
                -288,    // i4RotatedXCoordinate[2]
                -128,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
                }
            }
        },
        {
            0,
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 850, 1200, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2500, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8000, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
            },
            {
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, 
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}
                }, // TUNGSTEN
                {
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, 
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}
                }, // WARM F
                {
                    {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, 
                    {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}, {512, 504, 490}
                }, // F
                {
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, 
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}
                }, // CWF
                {
                    {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, 
                    {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {512, 502, 490}, {502, 502, 490}, {502, 502, 490}, {502, 502, 490}, {502, 502, 490}, {502, 502, 490}
                }, // DAYLIGHT
                {
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, 
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}
                }, // SHADE
                {
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, 
                    {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}, {512, 512, 490}
                } // DAYLIGHT F
            },
            {
                1,      // bEnable
                6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
            },
            {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
            },
            {
                65,     // i4Neutral_ParentBlk_Thr
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                {
                    {   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                },
                {
                    {
                        1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                        10,         // i4SunsetCountThr
                        0,          // i4SunsetCountRatio_L
                        171         // i4SunsetCountRatio_H
                    },
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        128         // i4DaylightProb
                    },
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        90,        // i4LVThr_H
                        192         // i4DaylightProb
                    },
                },
                {
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },
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
            {
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
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
                    1029,    // D65Gain_R
                    512,    // D65Gain_G
                    771    // D65Gain_B
                }
            },
            // Original XY coordinate of AWB light source
            {
                // Strobe
                {
                    107,    // i4X
                    -409    // i4Y
                },
                // Horizon
                {
                    -480,    // OriX_Hor
                    -404    // OriY_Hor
                },
                // A
                {
                    -329,    // OriX_A
                    -414    // OriY_A
                },
                // TL84
                {
                    -129,    // OriX_TL84
                    -434    // OriY_TL84
                },
                // CWF
                {
                    -103,    // OriX_CWF
                    -496    // OriY_CWF
                },
                // DNP
                {
                    5,    // OriX_DNP
                    -433    // OriY_DNP
                },
                // D65
                {
                    107,    // OriX_D65
                    -409    // OriY_D65
                },
                // DF
                {
                    13,    // OriX_DF
                    -423    // OriY_DF
                }
            },
            // Rotated XY coordinate of AWB light source
            {
                // Strobe
                {
                    107,    // i4X
                    -409    // i4Y
                },
                // Horizon
                {
                    -480,    // RotX_Hor
                    -404    // RotY_Hor
                },
                // A
                {
                    -329,    // RotX_A
                    -414    // RotY_A
                },
                // TL84
                {
                    -129,    // RotX_TL84
                    -434    // RotY_TL84
                },
                // CWF
                {
                    -103,    // RotX_CWF
                    -496    // RotY_CWF
                },
                // DNP
                {
                    5,    // RotX_DNP
                    -433    // RotY_DNP
                },
                // D65
                {
                    107,    // RotX_D65
                    -409    // RotY_D65
                },
                // DF
                {
                    13,    // RotX_DF
                    -423    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    1029,    // i4R
                    512,    // i4G
                    771    // i4B
                },
                // Horizon 
                {
                    512,    // AWBGAIN_HOR_R
                    568,    // AWBGAIN_HOR_G
                    1877    // AWBGAIN_HOR_B
                },
                // A 
                {
                    575,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1399    // AWBGAIN_A_B
                },
                // TL84 
                {
                    773,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1097    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    872,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1153    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    926,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    914    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    1029,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    771    // AWBGAIN_D65_B
                },
                // DF 
                {
                    923,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    892    // AWBGAIN_DF_B
                }
            },
            // Rotation matrix parameter
            {
                0,    // RotationAngle
                256,    // Cos
                0    // Sin
            },
            // Daylight locus parameter
            {
                -130,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    999,    // i4R
                    530,    // i4G
                    791    // i4B
                },
                // DaylightLocus_H
                {
                    880,    // i4R
                    512,    // i4G
                    902    // i4B
                },
                // Temporal General
                {
                    1029,    // i4R
                    512,    // i4G
                    771    // i4B
                },
                // AWB LSC Gain
                {
                    879,        // i4R
                    512,        // i4G
                    902        // i4B
                }
            },
            // AWB light area
            {
                // Strobe:FIXME
                {
                    157,    // i4RightBound
                    57,    // i4LeftBound
                    -359,    // i4UpperBound
                    -459    // i4LowerBound
                },
                // Tungsten
                {
                    -209,    // TungRightBound
                    -880,    // TungLeftBound
                    -379,    // TungUpperBound
                    -454    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -209,    // WFluoRightBound
                    -880,    // WFluoLeftBound
                    -454,    // WFluoUpperBound
                    -616    // WFluoLowerBound
                },
                // Fluorescent
                {
                    -39,    // FluoRightBound
                    -209,    // FluoLeftBound
                    -379,    // FluoUpperBound
                    -495    // FluoLowerBound
                },
                // CWF
                {
                -39,    // CWFRightBound
                -209,    // CWFLeftBound
                -495,    // CWFUpperBound
                -581    // CWFLowerBound
                },
                // Daylight
                {
                    137,    // DayRightBound
                    -39,    // DayLeftBound
                    -349,    // DayUpperBound
                    -465    // DayLowerBound
                },
                // Shade
                {
                    467,    // ShadeRightBound
                    137,    // ShadeLeftBound
                    -349,    // ShadeUpperBound
                    -444    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    137,    // DFRightBound
                    -39,    // DFLeftBound
                    -465,    // DFUpperBound
                    -551    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    467,    // PRefRightBound
                    -880,    // PRefLeftBound
                    -349,    // PRefUpperBound
                    -616    // PRefLowerBound
                },
                // Daylight
                {
                    162,    // PDayRightBound
                    -39,    // PDayLeftBound
                    -349,    // PDayUpperBound
                    -465    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    262,    // PCloudyRightBound
                    87,    // PCloudyLeftBound
                    -349,    // PCloudyUpperBound
                    -465    // PCloudyLowerBound
                },
                // Shade
                {
                    362,    // PShadeRightBound
                    87,    // PShadeLeftBound
                    -349,    // PShadeUpperBound
                    -465    // PShadeLowerBound
                },
                // Twilight
                {
                    -39,    // PTwiRightBound
                    -199,    // PTwiLeftBound
                    -349,    // PTwiUpperBound
                    -465    // PTwiLowerBound
                },
                // Fluorescent
                {
                    157,    // PFluoRightBound
                    -229,    // PFluoLeftBound
                    -359,    // PFluoUpperBound
                    -546    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -229,    // PWFluoRightBound
                    -429,    // PWFluoLeftBound
                    -359,    // PWFluoUpperBound
                    -546    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -229,    // PIncaRightBound
                    -429,    // PIncaLeftBound
                    -349,    // PIncaUpperBound
                    -465    // PIncaLowerBound
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
                    965,    // PWB_Day_R
                    512,    // PWB_Day_G
                    817    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    1125,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    701    // PWB_Cloudy_B
                },
                // Shade
                {
                    1204,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    655    // PWB_Shade_B
                },
                // Twilight
                {
                    756,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    1044    // PWB_Twi_B
                },
                // Fluorescent
                {
                    900,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    992    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    605,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1475    // PWB_WFluo_B
                },
                // Incandescent
                {
                    569,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1387    // PWB_Inca_B
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
                    4850    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    40,    // WFluo_SLIDER
                    4505    // WFluo_OFFS
                },
                // Shade
                {
                    50,    // Shade_SLIDER
                    409    // Shade_OFFS
                },
                // Sunset Area
                {
                    39,   // i4Sunset_BoundXr_Thr
                    -433    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -209,   // i4BoundXrThr
                    -468    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -124,   // i4BoundXrThr
                    -452    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -209,   // i4BoundXrThr
                    -530    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -131,   // i4BoundXrThr
                    -526    // i4BoundYrThr
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
                -587,    // i4RotatedXCoordinate[0]
                -436,    // i4RotatedXCoordinate[1]
                -236,    // i4RotatedXCoordinate[2]
                -102,    // i4RotatedXCoordinate[3]
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
                {0, 350, 700, 850, 1200, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for Shade
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2500, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8000, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
            },
            // Preference gain for each light source
            {
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {520, 520, 496}, {512, 512, 512}, {512, 512, 512}, {512, 512, 507}, {512, 512, 507}, 
                    {512, 512, 507}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // TUNGSTEN
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {490, 512, 518}, {490, 512, 518}, 
                    {490, 512, 518}, {490, 512, 518}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // WARM F
                {
                    {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {523, 504, 512}, {523, 504, 512}, {523, 504, 512}, 
                    {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}, {512, 504, 512}
                }, // F
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {515, 512, 518}, {515, 512, 518}, {515, 512, 518}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
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
        1, // tsfCtIdx
        2, // tsfCtIdx
        {20, 2000, -110, -110, 512, 512, 512, 0}    // rAWBInput[8]
    },

#include INCLUDE_FILENAME_TSF_PARA
#include INCLUDE_FILENAME_TSF_DATA
};

const NVRAM_CAMERA_FEATURE_STRUCT CAMERA_FEATURE_DEFAULT_VALUE =
{
#include INCLUDE_FILENAME_FEATURE_PARA
};



#if defined(AGOLD_CAMERA_VERSION)
#include "agold_camera_version.h"
#endif 

agold_camera_version agold_camera_para = {
	"ZRT_50013A_v1",
	(NVRAM_CAMERA_ISP_PARAM_STRUCT*)&CAMERA_ISP_DEFAULT_VALUE,
	(NVRAM_CAMERA_3A_STRUCT*)&CAMERA_3A_NVRAM_DEFAULT_VALUE,
	(NVRAM_CAMERA_SHADING_STRUCT*)&CAMERA_SHADING_DEFAULT_VALUE,
	&g_PlineTableMapping,
	(CAMERA_TSF_TBL_STRUCT*)&CAMERA_TSF_DEFAULT_VALUE,
	&CAMERA_FEATURE_DEFAULT_VALUE,	
};





