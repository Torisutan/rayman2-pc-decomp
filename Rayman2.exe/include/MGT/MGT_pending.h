#pragma once

#include "MGT/MGTStruc.h"

#ifdef __cplusplus
extern "C" {
#endif

void __cdecl MGT_pc_fn_vUnlinkMagnetModification(MGT_tdstMagnetModification *p_stMod);
void __cdecl MGT_pc_fn_vLinkMagnetModification(MGT_tdstMagnetModification *p_stMod);
void __cdecl MGT_pc_fn_vDestroyModifiedObject(short sModuleIdx);
void __cdecl MGT_pc_fn_vDestroyMagnetModification(MGT_tdstMagnetModification *p_stMod);
MGT_tdstMagnetModification *__cdecl MGT_pc_fn_p_stAllocMagnetModification(short sActivatedMagnet, short sModuleIdx);

void __cdecl MGT_fn_vDestroySubByTag(short sModuleIdx, short sSubTag);
void __cdecl MGT_fn_vReleasePendingIfEmpty(short sModuleIdx);
MGT_tdstMagnetModification *__cdecl MGT_pc_fn_p_stFindOrAllocMagnetModification(short sSubTag, short sModuleIdx, void *p_stGeo);
void __cdecl MGT_fn_vClearSubBitmapA(void *p_stSub);
void __cdecl MGT_fn_vClearSubBitmapB(void *p_stSub);
unsigned char __cdecl MGT_fn_bIsSubBitmapANonZero(void *p_stSub);

#ifdef __cplusplus
}
#endif
