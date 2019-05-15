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
#include "camera_AE_PLineTable_ov5648mipiraw.h"
#include "camera_info_ov5648mipiraw.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"
#include "agold_camera_version.h"

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
      0x00000000, // MIX3_CTRL_0
      0x00000000, // MIX3_CTRL_1
      0x00000000  // MIX3_SPARE
    }},
    ISPMulitCCM:{
      Poly22:{
        60875,      // i4R_AVG
        11565,      // i4R_STD
        93675,      // i4B_AVG
        22682,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
        {  // i4P00[9]
            10150000, -3667500, -1355000, -1765000, 7187500, -295000, 107500, -4047500, 9052500
        },
        {  // i4P10[9]
            1915350, -1812492, -89182, -199063, -95843, 278466, -7213, 763167, -760527
        },
        {  // i4P01[9]
            876188, -1009742, 141928, -474149, -121658, 580932, -172605, -314185, 486376
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
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // A
        {
          461,    // i4R
          512,    // i4G
          1145    // i4B
        },
        // TL84
        {
          575,    // i4R
          512,    // i4G
          957    // i4B
        },
        // CWF
        {
          681,    // i4R
          512,    // i4G
          1028    // i4B
        },
        // D65
        {
          718,    // i4R
          512,    // i4G
          617    // i4B
        },
        // Reserved 1
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 2
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 3
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        }
      },
      Weight:{
        0, // Strobe
        0, // A
        0, // TL84
        0, // CWF
        0, // D65
        0, // Reserved 1
        0, // Reserved 2
        0  // Reserved 3
      }
    },
    MDPMulitCCM:{
      Poly22:{
        0,      // i4R_AVG
        0,      // i4R_STD
        0,      // i4B_AVG
        0,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
        {  // i4P00[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
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
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // A
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // TL84
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // CWF
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // D65
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 1
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 2
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        },
        // Reserved 3
        {
          0,    // i4R
          0,    // i4G
          0    // i4B
        }
      },
      Weight:{
        0, // Strobe
        0, // A
        0, // TL84
        0, // CWF
        0, // D65
        0, // Reserved 1
        0, // Reserved 2
        0  // Reserved 3
      }
    },
    isp_ccm_ratio: 0.000000,
    //bInvokeSmoothCCM
    bInvokeSmoothCCM: MFALSE,

    DngMetadata:{
      0, // i4RefereceIlluminant1
      0, // i4RefereceIlluminant2
      rNoiseProfile:{
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
          }
        },
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
          }
        },
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
          }
        },
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
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
            1136,    // u4MinGain, 1024 base = 1x
            10240,    // u4MaxGain, 16x
            51,    // u4MiniISOGain, ISOxx  
            64,    // u4GainStepUnit, 1x/8 
            35,    // u4PreExpUnit 
            30,    // u4PreMaxFrameRate
            35,    // u4VideoExpUnit  
            30,    // u4VideoMaxFrameRate 
            1024,    // u4Video2PreRatio, 1024 base = 1x 
            35,    // u4CapExpUnit 
            15,    // u4CapMaxFrameRate
            1024,    // u4Cap2PreRatio, 1024 base = 1x
            35,    // u4Video1ExpUnit
            30,    // u4Video1MaxFrameRate
            1024,    // u4Video12PreRatio, 1024 base = 1x
            35,    // u4Video2ExpUnit
            30,    // u4Video2MaxFrameRate
            1024,    // u4Video22PreRatio, 1024 base = 1x
            35,    // u4Custom1ExpUnit
            30,    // u4Custom1MaxFrameRate
            1024,    // u4Custom12PreRatio, 1024 base = 1x
            35,    // u4Custom2ExpUnit
            30,    // u4Custom2MaxFrameRate
            1024,    // u4Custom22PreRatio, 1024 base = 1x
            35,    // u4Custom3ExpUnit
            30,    // u4Custom3MaxFrameRate
            1024,    // u4Custom32PreRatio, 1024 base = 1x
            35,    // u4Custom4ExpUnit
            30,    // u4Custom4MaxFrameRate
            1024,    // u4Custom42PreRatio, 1024 base = 1x
            35,    // u4Custom5ExpUnit
            30,    // u4Custom5MaxFrameRate
            1024,    // u4Custom52PreRatio, 1024 base = 1x
            24,    // u4LensFno, Fno = 2.8
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
            84,    // u4AETarget
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
            -10,    // i4BVOffset delta BV = value/10 
            64,    // u4PreviewFlareOffset
            64,    // u4CaptureFlareOffset
            3,    // u4CaptureFlareThres
            64,    // u4VideoFlareOffset
            3,    // u4VideoFlareThres
            64,    // u4CustomFlareOffset
            3,    // u4CustomFlareThres
            64,    // u4StrobeFlareOffset
            3,    // u4StrobeFlareThres
            160,    // u4PrvMaxFlareThres
            0,    // u4PrvMinFlareThres
            160,    // u4VideoMaxFlareThres
            0,    // u4VideoMinFlareThres
            18,    // u4FlatnessThres    // 10 base for flatness condition.
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
                    170,  //u4Thd
                    72, //52,   //u4FlatThd

                    200,  //u4BrightTonePcent
                    92, //u4BrightToneThd

                    500,  //u4LowBndPcent
                    5,    //u4LowBndThd
                    26,    //u4LowBndThdLimit

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
                128,    // u4BVCompRatio
                {
                    {
                        47,  //u4Y_Target
                        10,  //u4AOE_OE_percent
                        160,  //u4AOE_OEBound
                        15,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        5,    //u4AOE_LowlightBound
                        100,    //u4AOESceneLV_L
                        150,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        10,  //u4AOE_OE_percent
                        180,  //u4AOE_OEBound
                20,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                10,    //u4AOE_LowlightBound
                100,    //u4AOESceneLV_L
                150,    //u4AOESceneLV_H
                        40,    //u4AOE_SWHdrLE_Bound
                    },
                    {
                        47,  //u4Y_Target
                        10,  //u4AOE_OE_percent
                        200,  //u4AOE_OEBound
                        25,    //u4AOE_DarkBound
                        950,    //u4AOE_LowlightPrecent
                        15,    //u4AOE_LowlightBound
                        100,    //u4AOESceneLV_L
                        150,    //u4AOESceneLV_H
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
                    729,    // D65Gain_R
                    512,    // D65Gain_G
                    605    // D65Gain_B
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
                    -426,    // OriX_Hor
                    -280    // OriY_Hor
                },
                // A
                {
                    -310,    // OriX_A
                    -270    // OriY_A
                },
                // TL84
                {
                    -206,    // OriX_TL84
                    -270    // OriY_TL84
                },
                // CWF
                {
                    -155,    // OriX_CWF
                    -339    // OriY_CWF
                },
                // DNP
                {
                    -94,    // OriX_DNP
                    -239    // OriY_DNP
                },
                // D65
                {
                    69,    // OriX_D65
                    -192    // OriY_D65
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
                    -474,    // RotX_Hor
                    -185    // RotY_Hor
                },
                // A
                {
                    -359,    // RotX_A
                    -199    // RotY_A
                },
                // TL84
                {
                    -257,    // RotX_TL84
                    -221    // RotY_TL84
                },
                // CWF
                {
                    -222,    // RotX_CWF
                    -299    // RotY_CWF
                },
                // DNP
                {
                    -141,    // RotX_DNP
                    -214    // RotY_DNP
                },
                // D65
                {
                    28,    // RotX_D65
                    -202    // RotY_D65
                },
                // DF
                {
                    -8,    // RotX_DF
                    -287    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    512,    // i4R
                                512,	// u4G
                    512    // i4B
                },
                // Horizon 
                {
                    512,    // AWBGAIN_HOR_R
                    624,    // AWBGAIN_HOR_G
                    1623    // AWBGAIN_HOR_B
                },
                // A 
                {
                    512,    // AWBGAIN_A_R
                    541,    // AWBGAIN_A_G
                    1185    // AWBGAIN_A_B
                },
                // TL84 
                {
                    558,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    975    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    657,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1000    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    623,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    804    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    729,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    605    // AWBGAIN_D65_B
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
                12,    // RotationAngle
                250,    // Cos
                53    // Sin
            },
            // Daylight locus parameter
            {
                -192,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    699,    // i4R
                    530,    // i4G
                    625    // i4B
                },
                // DaylightLocus_H
                {
                    535,    // i4R
                    512,    // i4G
                    975    // i4B
                },
                // Temporal General
                {
                    729,    // i4R
                    512,    // i4G
                    605    // i4B
                },
                // AWB LSC Gain
                {
                    596,        // i4R
                    512,        // i4G
                    825        // i4B
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
                    -298,    // TungRightBound
                    -874,    // TungLeftBound
                    -130,    // TungUpperBound
                    -175    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -298,    // WFluoRightBound
                    -874,    // WFluoLeftBound
                    -175,    // WFluoUpperBound
                    -389    // WFluoLowerBound
                },
                // Fluorescent
                {
                    -179,    // FluoRightBound
                    -298,    // FluoLeftBound
                    -142,    // FluoUpperBound
                    -260    // FluoLowerBound
                },
                // CWF
                {
                -128,    // CWFRightBound
                -298,    // CWFLeftBound
                -260,    // CWFUpperBound
                -354    // CWFLowerBound
                },
                // Daylight
                {
                    58,    // DayRightBound
                    -179,    // DayLeftBound
                    -142,    // DayUpperBound
                    -260    // DayLowerBound
                },
                // Shade
                {
                    388,    // ShadeRightBound
                    58,    // ShadeLeftBound
                    -142,    // ShadeUpperBound
                    -241    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    58,    // DFRightBound
                    -128,    // DFLeftBound
                    -260,    // DFUpperBound
                    -354    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    388,    // PRefRightBound
                    -874,    // PRefLeftBound
                    0,    // PRefUpperBound
                    -389    // PRefLowerBound
                },
                // Daylight
                {
                    83,    // PDayRightBound
                    -179,    // PDayLeftBound
                    -142,    // PDayUpperBound
                    -260    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    183,    // PCloudyRightBound
                    8,    // PCloudyLeftBound
                    -142,    // PCloudyUpperBound
                    -260    // PCloudyLowerBound
                },
                // Shade
                {
                    283,    // PShadeRightBound
                    8,    // PShadeLeftBound
                    -142,    // PShadeUpperBound
                    -260    // PShadeLowerBound
                },
                // Twilight
                {
                    -179,    // PTwiRightBound
                    -339,    // PTwiLeftBound
                    -142,    // PTwiUpperBound
                    -260    // PTwiLowerBound
                },
                // Fluorescent
                {
                    78,    // PFluoRightBound
                    -357,    // PFluoLeftBound
                    -152,    // PFluoUpperBound
                    -349    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -259,    // PWFluoRightBound
                    -459,    // PWFluoLeftBound
                    -152,    // PWFluoUpperBound
                    -349    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -259,    // PIncaRightBound
                    -459,    // PIncaLeftBound
                    -142,    // PIncaUpperBound
                    -260    // PIncaLowerBound
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
                    673,    // PWB_Day_R
                    512,    // PWB_Day_G
                    682    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    782,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    542    // PWB_Cloudy_B
                },
                // Shade
                {
                    824,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    500    // PWB_Shade_B
                },
                // Twilight
                {
                    540,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    958    // PWB_Twi_B
                },
                // Fluorescent
                {
                    662,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    833    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    526,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1185    // PWB_WFluo_B
                },
                // Incandescent
                {
                    486,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1125    // PWB_Inca_B
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
                    4815    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    40,    // WFluo_SLIDER
                    4732    // WFluo_OFFS
                },
                // Shade
                {
                    50,    // Shade_SLIDER
                    417    // Shade_OFFS
                },
                // Sunset Area
                {
                    -112,   // i4Sunset_BoundXr_Thr
                    -214    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -181,   // i4BoundXrThr
                    -225    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -239,   // i4BoundXrThr
                    -243    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -130,   // i4BoundXrThr
                    -303    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -213,   // i4BoundXrThr
                    -329    // i4BoundYrThr
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
                -502,    // i4RotatedXCoordinate[0]
                -387,    // i4RotatedXCoordinate[1]
                -285,    // i4RotatedXCoordinate[2]
                -169,    // i4RotatedXCoordinate[3]
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
                    {500, 530, 480}, {500, 530, 480}, {500, 530, 480}, {500, 530, 480}, {500, 530, 480}, {500, 520, 496}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, 
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}
                }, // TUNGSTEN
                {
                    {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, {500, 512, 508}, 
                    {500, 512, 508}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}
                }, // WARM F
                {
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, 
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}
                }, // F
                {
                    {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, 
                    {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}, {500, 490, 512}
                }, // CWF
                {
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, 
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}
                }, // DAYLIGHT
                {
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, 
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}
                }, // SHADE
                {
                    {500, 512, 512}, {512, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, 
                    {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}, {500, 512, 512}
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
                        // rCalGain (calibration gain: 1.0 = 512)
                        {
                                0,	// u4R
                                0,	// u4G
                                0	// u4B
                        },
                        // rDefGain (Default calibration gain: 1.0 = 512)
                        {
                                0,	// u4R
                                0,	// u4G
                                0	// u4B
                        },
					// rUnitGain TL84 (unit gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                    // rGoldenGain TL84 (golden sample gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                     // rUnitGain Alight (unit gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                    // rGoldenGain Alight (golden sample gain: 1.0 = 512)
                    {
                        0,    // i4R
                        0,    // i4G
                        0     // i4B
                    },
                        // rDefGain (Default calibration gain: 1.0 = 512)
                        {
                                0,	// u4R
                                0,	// u4G
                                0	// u4B
                        },
                        // rD65Gain (D65 WB gain: 1.0 = 512)
                        {
                                778,	// u4R
                                512,	// u4G
                                603	    // u4B
                        }
                },
                // Original XY coordinate of AWB light source
                {
                        // Strobe
                        {
                                -39,	// i4X
                                -411	// i4Y
                        },
                        // Horizon
                        {
                                -425,	// i4X
                                -286	// i4Y
                        },
                        // A
                        {
                                -321,	// i4X
                                -291	// i4Y
                        },
                        // TL84
                        {
                                -203,	// i4X
                                -315	// i4Y
                        },
                        // CWF
                        {
                                -139,	// i4X
                                -416	// i4Y
                        },
                        // DNP
                        {
                                -24,	// i4X
                                -275	// i4Y
                        },
                        // D65
                        {
                                94,	    // i4X
                                -215	// i4Y
                        },
                        // DF
                        {
                                0, 	// i4X
                                0	// i4Y
                        }
                },
                // Rotated XY coordinate of AWB light source
                {
                        // Strobe
                        {
                                -131,	// i4X
                                -391	// i4Y
                        },
                        // Horizon
                        {
                                -468,	// i4X
                                -208	// i4Y
                        },
                        // A
                        {
                                -366,	// i4X
                                -231	// i4Y
                        },
                        // TL84
                        {
                                -254,	// i4X
                                -275	// i4Y
                        },
                        // CWF
                        {
                                -208,	// i4X
                                -386	// i4Y
                        },
                        // DNP
                        {
                                -71,	// i4X
                                -267	// i4Y
                        },
                        // D65
                        {
                                56,	// i4X
                                -228	// i4Y
                        },
                        // DF
                        {
                                0,	// i4X
                                0	// i4Y
                        }
                },
                // AWB gain of AWB light source
                {
                        // Strobe
                        {
                                848,	// u4R
                                512,	// u4G
                                941	// u4B
                        },
                        // Horizon
                        {
                                512,	// u4R
                                618,	// u4G
                                1620	// u4B
                        },
                        // A
                        {
                                512,	// u4R
                                533,	// u4G
                                1221	// u4B
                        },
                        // TL84
                        {
                                569,	// u4R
                                512,	// u4G
                                1032	// u4B
                        },
                        // CWF
                        {
                                745,	// u4R
                                512,	// u4G
                                1086	// u4B
                        },
                        // DNP
                        {
                                719,	// u4R
                                512,	// u4G
                                767	    // u4B
                        },
                        // D65
                        {
                                778,	// u4R
                                512,	// u4G
                                603	    // u4B
                        },
                        // DF
                        {
                                512,	// u4R
                                512,	// u4G
                                512	    // u4B
                        }
                },
                // Rotation matrix parameter
                {
                        10,	            // i4RotationAngle
                        252,	        // i4Cos
                        44,	            // i4Sin
                },
                // Daylight locus parameter
                {
                        -184,       	// i4SlopeNumerator
                        128    // i4SlopeDenominator
                },
	            // Predictor gain
                {
                        // i4PrefRatio100
                        101,
                // DaylightLocus_L
                {
                    792,    // i4R
                    512,    // i4G
                    589    // i4B
                },
                // DaylightLocus_H
                {
                    603,    // i4R
                    512,    // i4G
                    867    // i4B
                },
                // Temporal General
                {
                    792,    // i4R
                    512,    // i4G
                    589    // i4B
                },
                // AWB LSC Gain
                        {
                            664,    // i4R
                            512,    // i4G
                            756     // i4B
                        }
                },
                // AWB light area
                {
                        // Strobe
                        {
                                120,	// i4RightBound
                                -264,	// i4LeftBound
                                -322,	// i4UpperBound
                                -491	// i4LowerBound
                        },
                        // Tungsten
                        {
                                -310,	// i4RightBound
                                -868,	// i4LeftBound
                                -168,	// i4UpperBound
                                -253	// i4LowerBound
                        },
                        // Warm fluorescent
                        {
                                -310,	// i4RightBound
                                -868,	// i4LeftBound
                                -253,	// i4UpperBound
                                -386	// i4LowerBound
                        },
                        // Fluorescent
                        {
                                -117,	// i4RightBound
                                -310,	// i4LeftBound
                                -163,	// i4UpperBound
                                -344	// i4LowerBound
                        },
                        // CWF
                        {
                                -112,	// i4RightBound
                                -310,	// i4LeftBound
                                -344,	// i4UpperBound
                                -431	// i4LowerBound
                        },
                        // Daylight
                        {
                                86,	// i4RightBound
                                -117,	// i4LeftBound
                                -158,	// i4UpperBound
                                -344	// i4LowerBound
                        },
                        // Shade
                        {
                                416,	// i4RightBound
                                86,	// i4LeftBound
                                -158,	// i4UpperBound
                                -291	// i4LowerBound
                        },
                        // Daylight Fluorescent
                        {
                                86,	// i4RightBound
                                -112,// i4LeftBound
                                -344,	// i4UpperBound
                                -431	// i4LowerBound
                        }
                },
                // PWB light area
                {
                        // Reference area
                        {
                                444,	// i4RightBound
                                -964,	// i4LeftBound
                                -122,	// i4UpperBound
                                -401	// i4LowerBound
                        },
                        // Daylight
                        {
                                109,	// i4RightBound
                                -124,	// i4LeftBound
                                -147,	// i4UpperBound
                                -322	// i4LowerBound
                        },
                        // Cloudy daylight
                        {
                                209,	// i4RightBound
                                34,	// i4LeftBound
                                -147,	// i4UpperBound
                                -322	// i4LowerBound
                        },
                        // Shade
                        {
                                309,	// i4RightBound
                                34,	// i4LeftBound
                                -147,	// i4UpperBound
                                -322	// i4LowerBound
                        },
                        // Twilight
                        {
                                -124,	// i4RightBound
                                -284,	// i4LeftBound
                                -147,	// i4UpperBound
                                -322	// i4LowerBound
                        },
                        // Fluorescent
                        {
                                109,	// i4RightBound
                                -314,	// i4LeftBound
                                -162,	// i4UpperBound
                                -401	// i4LowerBound
                        },
                        // Warm fluorescent
                        {
                                -221,	// i4RightBound
                                -421,	// i4LeftBound
                                -162,	// i4UpperBound
                                -371	// i4LowerBound
                        },
                        // Incandescent
                        {
                                -221,	// i4RightBound
                                -421,	// i4LeftBound
                                -147,	// i4UpperBound
                                -322	// i4LowerBound
                        },
                        // Gray World
                        {
                                5000,    // i4RightBound
                                -5000,    // i4LeftBound
                                5000,    // i4UpperBound
                                -5000    // i4LowerBound
                        }
                },
                // PWB default gain
                {
                        // Daylight
                        {
                                744,	// u4R
                                512,	// u4G
                                657	// u4B
                        },
                        // Cloudy daylight
                        {
                                848,	// u4R
                                512,	// u4G
                                533	// u4B
                        },
                        // Shade
                        {
                                892,	// u4R
                                512,	// u4G
                                491	// u4B
                        },
                        // Twilight
                        {
                                610,	// u4R
                                512,	// u4G
                                905	// u4B
                        },
                        // Fluorescent
                        {
                                712,	// u4R
                                512,	// u4G
                                792	// u4B
                        },
                        // Warm fluorescent
                        {
                                571,	// u4R
                                512,	// u4G
                                1131	// u4B
                        },
                        // Incandescent
                        {
                                542,	// u4R
                                512,	// u4G
                                1095	// u4B
                        },
                        // Gray World
                        {
                                512,	// u4R
                                512,	// u4G
                                512	// u4B
                        }
                },
                // AWB preference color
                {
                        // Tungsten
                        {
                                100,	// i4SliderValue
                                4071	// i4OffsetThr
                        },
                        // Warm fluorescent
                        {
                                100,	// i4SliderValue
                                4071	// i4OffsetThr
                        },
                        // Shade
                        {
                                50,	// i4SliderValue
                                916	// i4OffsetThr
                        },
                        // Sunset Area
                    {
                        -25, //64,   // i4Sunset_BoundXr_Thr
                        -267 //-463     // i4Sunset_BoundYr_Thr
                    },
                    // Shade F Area
                    {
                    -185,   // i4BoundXrThr
                    -228    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -185,   // i4BoundXrThr
                    -228    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -208,   // i4BoundXrThr
                    -386    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -208,   // i4BoundXrThr
                    -386    // i4BoundYrThr
                    }
                },
                // CCT estimation
                {
                        // CCT
                        {
			                2300,	// i4CCT[0]
			                2850,	// i4CCT[1]
			                    3700,	// i4CCT[2]
			                5100,	// i4CCT[3]
			                6500 	// i4CCT[4]
		            },
                        // Rotated X coordinate
                        {
                                -524,	// i4RotatedXCoordinate[0]
                                -422,	// i4RotatedXCoordinate[1]
                                -310,	// i4RotatedXCoordinate[2]
                                -127,	// i4RotatedXCoordinate[3]
			                0 	    // i4RotatedXCoordinate[4]
		            }
	            }
            },
            // Algorithm Tuning Paramter
            {
                // AWB Backup Enable
                0,

                // Daylight locus offset LUTs for tungsten
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 350,  800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                    //{0, 500, 1000, 1333, 1667, 2000, 2333, 2667, 3000, 3333, 3667, 4000, 4333, 4667, 5000, 5333, 5667, 6000, 6333, 6667,  7000} // i4LUTOut
                    //{0, 500, 1000, 1500, 2000, 2313, 2625, 2938, 3250, 3563, 3875, 4188, 4500, 4813, 5125, 5438, 5750, 6063, 6375, 6688,  7000} // i4LUTOut
                },

                // Daylight locus offset LUTs for WF
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 350,  700,  850, 1200, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778,  5000} // i4LUTOut
                },

                // Daylight locus offset LUTs for shade
                {
                    21, // i4Size: LUT dimension
                    {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                    {0, 500, 1000, 1500, 2500, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8000, 8000, 8500, 9000, 9500, 10000}  // i4LUTOut
                },
                // Preference gain for each light source
                {
                    //        LV0              LV1              LV2              LV3              LV4              LV5              LV6              LV7              LV8              LV9
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                    //        LV10             LV11             LV12             LV13             LV14             LV15             LV16             LV17             LV18
          	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // STROBE
        	        {
          	            {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {530, 530, 480}, {520, 520, 496}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
           	            {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // TUNGSTEN
        	        {
                        {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508}, {512, 512, 508},
           	            {512, 512, 508}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
        	        }, // WARM F
        	        {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}, {502, 512, 512}
                    }, // F
                    {
                        {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512},
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
                    115, //100,    // i4InitLVThr_L
                    155, //140,    // i4InitLVThr_H
                    100 //80      // i4EnqueueLVThr
                },
                // AWB number threshold for temporal predictor
                {
                        65,     // i4Neutral_ParentBlk_Thr
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                // AWB light neutral noise reduction for outdoor
                {
                    //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    // Non neutral
	                { 3,   3,   3,   3,   3,   3,   3,   3,    3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // Flurescent
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
	                // CWF
	                { 0,   0,   0,   0,   0,   0,   0,   0,    0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
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
                        90,        // i4LVThr
                        105,        // i4LVThr
                        96 //10         // i4DaylightProb
                    },

                    // Shade CWF Detection
                    {
                        1,          // i4Enable
                        90,        // i4LVThr
                        105,        // i4LVThr
                        208 //224 //128 //35         // i4DaylightProb
                    }

                },

                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                {
                    //LV0   1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    {  90, 90,  90,  90,  90,  90,  90,  90,  90,  90,   90,  50,  30,  20,  10,   0,   0,   0,   0}
                },

                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                {
                    //LV0  1    2    3    4    5    6    7    8    9     10    11   12   13   14   15  16   17   18
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100,  50,  25,   0,  0,   0,   0}, // Strobe
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,   75,  50,  25,  25,  25,  0,   0,   0}, // Tungsten
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,   75,  50,  25,  25,  25,  0,   0,   0}, // Warm fluorescent
                    {100, 100, 100, 100, 100, 100, 100, 100, 100,  95,   95,   70,  50,  25,  25,  25,  0,   0,   0}, // Fluorescent
                    { 90,  90,  90,  90,  90,  90,  90,  90,  90,  90,   80,   55,  30,  30,  30,  30,  0,   0,   0}, // CWF
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100, 100, 100,  75,  50, 40,  30,  20}, // Daylight
                    {100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  100,  100,  75,  50,  25,   0,  0,   0,   0}, // Shade
                    { 90,  90,  90,  90,  90,  90,  90,  90,  90,  90,   80,   55,  30,  30,  30,  30,  0,   0,   0}  // Daylight fluorescent
                },

                // AWB tuning information
                {
                    6735,       // project code
                    5588,       // model   
                    20150624,   // date
                    0,          // reserved 0 
                    1,          // reserved 1  
                    2,          // reserved 2  
                    3,          // reserved 3 
                    4,          // reserved 4
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
	"KMJ_40093A1_v1",
	(NVRAM_CAMERA_ISP_PARAM_STRUCT*)&CAMERA_ISP_DEFAULT_VALUE,
	(NVRAM_CAMERA_3A_STRUCT*)&CAMERA_3A_NVRAM_DEFAULT_VALUE,
	(NVRAM_CAMERA_SHADING_STRUCT*)&CAMERA_SHADING_DEFAULT_VALUE,
	&g_PlineTableMapping,
	(CAMERA_TSF_TBL_STRUCT*)&CAMERA_TSF_DEFAULT_VALUE,
	&CAMERA_FEATURE_DEFAULT_VALUE,
	
};

