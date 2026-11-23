#pragma once

#include "GMT/GMT_types.h"

ACP_tdxHandleOfMaterial              __cdecl GMT_fn_hGetVisualMaterial(GMT_tdxHandleToGameMaterial _hGameMat);
DNM_tdxHandleToMecMatCharacteristics __cdecl GMT_fn_hGetMechanicsMaterial(GMT_tdxHandleToGameMaterial _hGameMat);

/* 0x0042DAD0 */
void                           __cdecl GMT_fn_vInitGameMaterialErrorAndMemory(void);
