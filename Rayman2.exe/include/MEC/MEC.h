#pragma once

#include "DNM/DNM_types.h"
#include "HIE/HIE_types.h"
#include "MTH/MTH3D.h"

void __cdecl MEC_vInitTranslation(DNM_tdstDynamics *p_stDynamic,
                                  HIE_tdstSuperObject *hSupObj,
                                  MTH3D_tdstVector *p_stVector);

void __cdecl MEC_vImposeTranslation(DNM_tdstDynamics *p_stDynamic,
                                    MTH3D_tdstVector *p_stVector);

void __cdecl MEC_vImposeRotationVector(DNM_tdstDynamics *p_stDynamic,
                                       MTH3D_tdstVector *p_stX,
                                       MTH3D_tdstVector *p_stY,
                                       MTH3D_tdstVector *p_stZ);

void __cdecl MEC_vImposeRelativeRotation(DNM_tdstDynamics *p_stDynamic,
                                         MTH3D_tdstMatrix *p_stRotationMatrix);

void __cdecl MEC_fn_vImposeActorMatrix(HIE_tdstSuperObject *hSupObj);

void __cdecl MEC_fn_vUpdateMatrix(DNM_tdstDynamics *p_stDynamic,
                                  POS_tdxHandleToPosition _hMatrix);
void __cdecl MEC_fn_vCancelTilt(DNM_tdstDynamics *p_stDynamic);

void __cdecl MEC_vImposeRotationMatrix(DNM_tdstDynamics *p_stDynamic,
                                       POS_tdxHandleToPosition hRotationMatrix);

void __cdecl MEC_vTurnAbsolute(DNM_tdstDynamics *p_stDynamic,
                               MTH3D_tdstVector *p_stVector);

void __cdecl DNM_fn_vSetHangingLimit(DNM_tdstDynamics *p_stDynamic,
                                     MTH_tdxReal xValue);

void __cdecl MEC_vTurnAroundZAxis(DNM_tdstDynamics *p_stDynamic,
                                  MTH_tdxReal xAngle);

void __cdecl MEC_fn_vUpdateSpeed(HIE_tdstSuperObject *hSupObj);

DNM_tdstDynamics * __cdecl DNM_p_stDynamicsCameraMechanics(
    DNM_tdstDynamics *_p_stDynamics,
    HIE_tdstSuperObject *_hSupObj,
    DNM_tdstParsingDatas *_p_stParsingDatas,
    void *_h_MecIdCard,
    MTH_tdxReal _xDT);

/* 0x00431AD0 */
DNM_tdstDynamics * __cdecl MEC_p_stDynamicsBaseMechanics(
    DNM_tdstDynamics    *p_stDynamic,
    HIE_tdstSuperObject *hSupObj,
    DNM_tdstParsingDatas *p_stParsingDatas,
    void                *h_MecIdCard,
    MTH_tdxReal          xDT);

static __inline unsigned char MEC_fn_bIsPlatform(DNM_tdstDynamics *p_stDynamic)
{
    return (unsigned char)(DNM_M_hDynamicsGetPlatformSO(p_stDynamic) != NULL);
}
