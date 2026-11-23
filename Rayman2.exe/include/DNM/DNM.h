#pragma once

#include "DNM/DNM_types.h"
#include "HIE/HIE_types.h"

typedef struct HIE_tdstEngineObject_ HIE_tdstEngineObject;

void __cdecl fn_vDynamAlloc(HIE_tdstEngineObject *p_stObject);
void __cdecl fn_vDynamCopyClone(HIE_tdstEngineObject *_p_stObjectDest,
                                    HIE_tdstEngineObject *_p_stObjectSrc);
MTH_tdxReal __cdecl fn_xComputeAngleOfPerso(HIE_tdstSuperObject *pSuperObjPerso);

DNM_tdstDynamics * __cdecl fn_p_stDynamGetDynamicsSO(HIE_tdstSuperObject *hSupObj);
/* 0x00419B90 */
void * __cdecl fn_p_stDynamGetDynamics(MS_tdxHandleToDynam h_Dynam);
