#pragma once

#include "RND/RND_globals.h"

void __cdecl RND_fn_vComputeRandomTable(void);
void __cdecl RND_fn_vRemapRandomTable(void);

/* 0x00449A90 */
RND_tdxHandleToRandomIndex __cdecl RND_fn_hReserveANewHandleIndex(void);

/* 0x00449C10 */
long        __cdecl RND_fn_lGetLongRandomValue(RND_tdxHandleToRandomIndex _lIndexNumber, long _lMin, long _lMax);
MTH_tdxReal __cdecl RND_fn_xGetRealRandomValue(RND_tdxHandleToRandomIndex _lIndexNumber, MTH_tdxReal _xMin, MTH_tdxReal _xMax);
