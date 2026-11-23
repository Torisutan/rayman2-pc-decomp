#ifndef RAYMAN2_GAM_ACTIONS_STDGAME_H
#define RAYMAN2_GAM_ACTIONS_STDGAME_H

#include "GAM/GAM_types.h"

#ifndef INLINE
#define INLINE static __inline
#endif

INLINE
unsigned char fn_ucStandardGameGetHitPointsMax(MS_tdxHandleToStandardGame h_StdGame)
    { return(h_StdGame->ucHitPointsMax); }

INLINE
void fn_vStandardGameSetHitPointsMax(MS_tdxHandleToStandardGame h_StdGame,unsigned char ucHitPoints)
    { h_StdGame->ucHitPointsMax=ucHitPoints; }

INLINE
unsigned char fn_ucStandardGameGetHitPointsMaxMax(MS_tdxHandleToStandardGame h_StdGame)
    { return(h_StdGame->ucHitPointsMaxMax); }

#endif
