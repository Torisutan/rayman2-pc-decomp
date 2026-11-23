#ifndef __HIE_globals_h__
#define __HIE_globals_h__

#undef EXTERN
#if !defined(D_HIE_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN long HIE_g_lNbMatrixInStack;
EXTERN unsigned char HIE_g_ucRenderMode;
EXTERN unsigned char HIE_g_ucShadowIdx;
EXTERN unsigned char HIE_g_ucMirrorIdx;
EXTERN float HIE_g_xMirrorBlend;
EXTERN int g_lActiveLightCount;
EXTERN char DAT_005115c9;
EXTERN long HIE_g_lNbMatrixInCameraStack;
EXTERN unsigned char HIE_g_ucContext;
EXTERN short HIE_g_xFixIndex;
EXTERN short HIE_g_xFixIndexSave;

#endif

#undef EXTERN
#if !defined(D_HIE_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN void * HIE_g_hCurrentMatrix;
EXTERN void * HiePick_GeoHandle;
