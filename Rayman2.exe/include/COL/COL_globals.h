#ifndef __COL_globals_h__
#define __COL_globals_h__

#undef EXTERN
#if !defined(D_COL_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN long COL_g_lFacesTagCounter;

/* 0x004faabc */
EXTERN long *COL_g_d_lTaggedFacesTable;

#endif
