#ifndef _MEC_MECPFM_H_
#define _MEC_MECPFM_H_

#include "ACP/ACP_types.h"
#include "DNM/DNM_types.h"
#include "POS/POS_types.h"
#include "HIE/HIE_types.h"

void __cdecl MEC_fn_vUpdatePlatform (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, POS_tdxHandleToPosition hPreviousReferenceMatrix, POS_tdxHandleToPosition hInvPreviousReferenceMatrix);

void __cdecl MEC_fn_vDynamicComputeAbsoluteMatrix (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, POS_tdxHandleToPosition hPreviousMatrix, POS_tdxHandleToPosition hInvPreviousMatrix, POS_tdxHandleToPosition hCurrentMatrix);

void __cdecl MEC_fn_vSetPlatformLink (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, HIE_tdstSuperObject *hFatherSupObj);

void __cdecl MEC_fn_vCutPlatformLink (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj);
/* 0x0043DA30 */
void __cdecl MEC_fn_vForcePlatformLink (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, HIE_tdstSuperObject *hFatherSupObj);
void __cdecl MEC_fn_vFreePlatformLink (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj);

ACP_tdxBool __cdecl MEC_fn_vBasePlatformManagement (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj);

#endif
