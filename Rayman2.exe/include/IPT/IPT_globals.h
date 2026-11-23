#ifndef __IPT_globals_h__
#define __IPT_globals_h__

#undef EXTERN
#if !defined(D_IPT_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

#include "IPT/IPT_Str.h"
EXTERN struct IPT_tdstInput_ IPT_g_hInputStructure;   /* 0x00509E60 */

/* 0x0050A980 */
EXTERN struct IPT_tdstKeyAndPadDefine_ *IPT_gd_hKeyAndPadDefine;

/* 0x509E60 */
EXTERN unsigned long IPT_g_ulAnyDeviceInputFlag;
EXTERN unsigned long IPT_g_ulSequenceAnalyseNumber;

#endif
