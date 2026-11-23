#ifndef __AGO_globals_h__
#define __AGO_globals_h__

#include "MTH/MTH_types.h"

#undef EXTERN
#if !defined(D_AGO_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN float AGO_g_xLogoTransparency;
EXTERN unsigned long AGO_g_ulNumberOfAgos;
EXTERN unsigned long AGO_g_NumberOfZeldaAgos;
EXTERN float AGO_g_ffFrameTime;   /* 0x004B9AFC */
EXTERN float AGO_g_ffLastFrameTime;
EXTERN float AGO_g_fTimeDifference;   /* 0x004B9B04 */
EXTERN int AGO_g_LastFrozen;   /* 0x004B9B14 */
EXTERN char AGO_g_bUsingMapMondeAGOs;
EXTERN char AGO_g_bForceWhiteFog;   /* 0x004B9AF4 */
EXTERN int AGO_g_OddFrame;   /* 0x004B9AD4 */
EXTERN int AGO_g_PloufMaterial;

EXTERN MTH3D_tdstVector AGO_g_ExtraParameterVec1;   /* 0x004E0F00 */
EXTERN MTH3D_tdstVector AGO_g_ExtraParameterVec2;   /* 0x004E0EF0 */
#define AGO_bb_PosX (AGO_g_ExtraParameterVec1.xX)
#define AGO_bb_PosY (AGO_g_ExtraParameterVec1.xY)
#define AGO_bb_PosZ (AGO_g_ExtraParameterVec1.xZ)
#define AGO_bb_DirX (AGO_g_ExtraParameterVec2.xX)
#define AGO_bb_DirY (AGO_g_ExtraParameterVec2.xY)
#define AGO_bb_DirZ (AGO_g_ExtraParameterVec2.xZ)
#define AGO_gExtraParameter1 ((const float *)&AGO_g_ExtraParameterVec1)
#define AGO_gExtraParameter2 ((const float *)&AGO_g_ExtraParameterVec2)
/* 0x4E57E8 */
EXTERN float AGO_g_ExtraFloatParameter;
#define AGO_bb_Param AGO_g_ExtraFloatParameter

/* 0x4E1068 */
EXTERN float AGO_g_CurrentAnimTime;
#define AGO_g_AGO_AnimTimeScale AGO_g_CurrentAnimTime
EXTERN unsigned long AGO_bb_Mat;   /* 0x004B9ADC */
EXTERN char AGO_g_SplashFlag;
EXTERN float AGO_g_Timer7;
EXTERN float AGO_g_Timer10;
EXTERN float AGO_g_Timer1A;
EXTERN float AGO_g_Timer1B;
EXTERN float AGO_g_Timer1F;
EXTERN float AGO_g_Type16PrevX;   /* 0x004B9AE8 */
EXTERN float AGO_g_Type16PrevY;   /* 0x004B9AEC */
EXTERN float AGO_g_Type21Offset;   /* 0x004B9B18 */
EXTERN float AGO_g_Timer28;   /* 0x004B9B1C */
EXTERN float AGO_g_Timer67;   /* 0x004B9B20 */
EXTERN float AGO_g_Angle132X;
EXTERN float AGO_g_Angle132Y;
EXTERN float AGO_g_Angle132Z;
EXTERN unsigned long AGO_g_NbAGO_Triangles;
EXTERN unsigned long AGO_g_NbEngineFramesSinceStart;

#endif
