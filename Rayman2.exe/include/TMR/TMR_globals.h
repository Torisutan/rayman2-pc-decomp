#pragma once

#include "TMR/TMR_types.h"

extern TMR_tdstTimer  TMR_a_stTimerTab_storage[16];
extern unsigned short TMR_g_p_wTimerCount_storage;
extern unsigned long  TMR_a3_ulTimerFrequency_storage[3];
extern unsigned long  a3_ulEventFrequency[3];   /* 0x00516180 */
#define TMR_a_stTimerTab        (TMR_a_stTimerTab_storage)
#define TMR_g_p_wTimerCount     (&TMR_g_p_wTimerCount_storage)      /* 0x004B9A9C */
#define TMR_a3_ulTimerFrequency (TMR_a3_ulTimerFrequency_storage)   /* 0x00516170 */

#define a_stTimerTab            TMR_a_stTimerTab_storage
#define wTimerCount             TMR_g_p_wTimerCount_storage
#define a3_ulTimerFrequency     TMR_a3_ulTimerFrequency_storage

#undef EXTERN
#if !defined(D_TMR_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN int g_bTMRInited;

#define TimerLibOk (*(short *)&g_bTMRInited)

EXTERN unsigned short TMR_pc_g_bCpuFeaturesInited;
EXTERN unsigned long  TMR_pc_g_ulTimerPeriod;
EXTERN unsigned short TMR_pc_g_bTimerPeriodSet;

/* 0x004A3FE4 */
extern unsigned char g_ucTmrModuleId;
#define TMR_pc_g_aucExternalSvcId g_ucTmrModuleId
#define TMR_pc_g_ucExternalSvcId  g_ucTmrModuleId

EXTERN unsigned char TMR_pc_g_aucCpuVendor[16];
EXTERN unsigned long TMR_pc_g_ulCpuSignature;
