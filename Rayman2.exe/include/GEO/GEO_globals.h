#ifndef __GEO_globals_h__
#define __GEO_globals_h__

#undef EXTERN
#if !defined(D_GEO_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN float GEO_g_xZFarTransparencyLevel;

/* 0x00501524 */
EXTERN unsigned char GEO_g_bDynamicAllocation;

/* 0x0049FBBC */
extern unsigned char g_ucGEOModuleId;

/* 0x0049FBC0 */
extern unsigned char g_ucGEOMMemMallocMode;

#endif
