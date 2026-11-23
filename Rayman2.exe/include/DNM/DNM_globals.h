#ifndef __DNM_globals_h__
#define __DNM_globals_h__

#undef EXTERN
#if !defined(D_DNM_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN long g_lCallCounter;
EXTERN unsigned char g_bHighSpeed; /* 0x004B72D0 */

#endif
