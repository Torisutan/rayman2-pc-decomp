#ifndef __INO_globals_h__
#define __INO_globals_h__

#undef EXTERN
#if !defined(D_INO_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN short INO_pc_g_bInited;
EXTERN int INO_pc_g_bInputProduced;
EXTERN short INO_pc_g_wDeviceCount;
EXTERN int INO_pc_g_lEnumDeviceCount;
EXTERN int INO_pc_g_lDInputVersion;
EXTERN unsigned short INO_pc_g_uwActiveKeyCount;

#endif

#undef EXTERN
#if !defined(D_INO_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN void * INO_pc_g_pDirectInput;
