#ifndef __MGT_globals_h__
#define __MGT_globals_h__

#include "MGT/MGTStruc.h"

#undef EXTERN
#if !defined(D_MGT_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN short g_lNbActiveMagnets;
EXTERN short g_lNbPendingMagnets;

/* 0x0050AC40 */
EXTERN MGT_tdstModifiedObject *g_aModifiedObjects[20];

/* 0x0050ACA0 */
EXTERN int *g_aActiveMagnets[8];

#endif
