#include <stddef.h>

#include "AI/MetaAction.h"
#include "AI/ActParam.h"
#include "AI/CAM_Base.h"
#include "AI/CAM_Tool.h"
#include "GAM/GAM_types.h"
#include "POS/POS_types.h"
#include "HIE/HIE_types.h"
#include "MTH/MTH3D.h"

extern void CAM_fn_vComputeProjection(MTH3D_tdstVector *_p_sDestVector, MTH3D_tdstVector *_p_sSrcVector,
                                      MTH3D_tdstVector *_p_sNormVector);
extern MTH_tdxReal CAM_fn_xComputeRotation(MTH3D_tdstVector *_p_stDestVector, MTH3D_tdstVector *_p_stSrcVector,
                                           MTH3D_tdstVector *_p_stAxisVector);
extern void CAM_fn_vForceCameraPos(HIE_tdstSuperObject *_hSuperObjCamera, MTH3D_tdstVector *_p_stPosition);
extern void CAM_fn_vForceCameraTgt(HIE_tdstSuperObject *_hSuperObjCamera, MTH3D_tdstVector *_p_stPosition,
                                   MTH3D_tdstVector *_p_stRefAxisZ);
extern MTH3D_tdstVector *MTH_p_stRotationMulVector(MTH_tdstRotation *_p_stRotation,
                                                   MTH3D_tdstVector *_p_stSource,
                                                   MTH3D_tdstVector *_p_stResult);

static void fnv_MoveAToB
(
    HIE_tdstSuperObject *p_SuperObjPerso,
    MTH3D_tdstVector    *_p_stSource,
    MTH3D_tdstVector    *_p_stDest,
    MTH3D_tdstVector    *_p_stCurrent,
    int                  _iTime,
    int                  _iAccel
)
{
    MTH_tdxReal         xDist, xActDist, xSpeed, xTemp;
    long                lTime;
    MTH3D_tdstVector    stTempVector;

    MTH3D_M_vSubVector(&stTempVector, _p_stDest, _p_stSource);
    xDist = MTH3D_M_xNormVector(&stTempVector);

    MTH3D_M_vSubVector(&stTempVector, _p_stCurrent, _p_stSource);
    xActDist = MTH3D_M_xNormVector(&stTempVector);

    xSpeed = MTH_M_xDiv(xDist, MTH_M_xLongToReal(_iTime));

    lTime = GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount - fn_lGetActionParamlValue(5, p_SuperObjPerso);

    if(lTime < _iAccel)
    {
        xSpeed = MTH_M_xMul(MTH_M_xDiv(xSpeed, MTH_M_xLongToReal(_iAccel)), lTime);
    }

    if(lTime > _iTime - _iAccel)
    {
        xTemp = MTH_M_xMul(MTH_M_xLongToReal(lTime), -MTH_M_xDiv(xSpeed, MTH_M_xLongToReal(_iAccel)));
        xSpeed = MTH_M_xAdd(xTemp, MTH_M_xDiv(MTH_M_xMul(MTH_M_xLongToReal(_iTime), xSpeed), MTH_M_xLongToReal(_iAccel)));
    }

    MTH3D_M_vSubVector(&stTempVector, _p_stDest, _p_stSource);
    MTH3D_M_vNormalizeVector(&stTempVector, &stTempVector);

    xSpeed = MTH_M_xMul(xSpeed, fn_ulDetermineUsefulDT());
    MTH3D_M_vMulScalarVector(&stTempVector, xSpeed, &stTempVector);
    MTH3D_M_vAddVector(_p_stDest, &stTempVector, _p_stCurrent);
}

static void fnv_TurnAWithB
(
    HIE_tdstSuperObject *p_SuperObjPerso,
    MTH3D_tdstVector    *_p_stSource,
    MTH3D_tdstVector    *_p_stPointAxis,
    MTH3D_tdstVector    *_p_stAxis,
    MTH3D_tdstVector    *_p_stCurrent,
    MTH_tdxReal          _xAngle,
    int                  _iTime,
    int                  _iAccel
)
{
    MTH_tdxReal         xActAngle, xSpeed, xTemp;
    long                lTime;
    MTH3D_tdstVector    stTempVector, stTempVector1;
    MTH_tdstRotation    stRotation;

    MTH3D_M_vSubVector(&stTempVector, _p_stCurrent, _p_stPointAxis);
    CAM_fn_vComputeProjection(&stTempVector, &stTempVector, _p_stAxis);
    MTH3D_M_vSubVector(&stTempVector1, _p_stSource, _p_stPointAxis);
    CAM_fn_vComputeProjection(&stTempVector1, &stTempVector1, _p_stAxis);

    xActAngle = CAM_fn_xComputeRotation(&stTempVector1, &stTempVector, NULL);

    xSpeed = MTH_M_xDiv(_xAngle, MTH_M_xLongToReal(_iTime));

    lTime = GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount - fn_lGetActionParamlValue(5, p_SuperObjPerso);

    if(lTime < _iAccel)
    {
        xSpeed = MTH_M_xMul(MTH_M_xDiv(xSpeed, MTH_M_xLongToReal(_iAccel)), lTime);
    }

    if(lTime > _iTime - _iAccel)
    {
        xTemp = MTH_M_xMul(MTH_M_xLongToReal(lTime), -MTH_M_xDiv(xSpeed, MTH_M_xLongToReal(_iAccel)));
        xSpeed = MTH_M_xAdd(xTemp, MTH_M_xDiv(MTH_M_xMul(MTH_M_xLongToReal(_iTime), xSpeed), MTH_M_xLongToReal(_iAccel)));
    }

    MTH3D_M_vCopyVector(&stRotation.m_stAxis, _p_stAxis);
    xSpeed = MTH_M_xMul(xSpeed, fn_ulDetermineUsefulDT());
    stRotation.m_xAngle = xSpeed;
    MTH3D_M_vSubVector(&stTempVector, _p_stCurrent, _p_stPointAxis);
    MTH_p_stRotationMulVector(&stRotation, &stTempVector, _p_stSource);
    MTH3D_M_vAddVector(_p_stSource, _p_stSource, _p_stPointAxis);
}

/* 0x0048BEE0 */
AI_tdstNodeInterpret *__cdecl fn_p_stCamCineInit(HIE_tdstSuperObject *p_SuperObjPerso,
                                                 AI_tdstNodeInterpret *p_stTree)
{
    MS_tdxHandleToCineinfo  hCineinfo;
    MTH3D_tdstVector        stTempVector;
    enum tdeMetaActionId_   eMetaActionId = (enum tdeMetaActionId_) AI_M_eMetaActionIdInterpret(p_stTree - 1);
    AI_tdstGetSetParam      stParam;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits |= 0x8000;

    MTH3D_M_vSetVectorElements(&stTempVector, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    switch(eMetaActionId)
    {
    case eMetaAction_CamCineMoveAToBTgtC:
    case eMetaAction_CamCineMoveAToBTgtAC:
    case eMetaAction_CamCinePosAMoveTgtBToC:

        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamp_stVertex(1, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamp_stVertex(2, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamlValue(3, p_SuperObjPerso, M_ReturnParam_lValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamlValue(4, p_SuperObjPerso, M_ReturnParam_lValue(&stParam));

        fn_vSetActionParamlValue(5, p_SuperObjPerso, GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount);
        CAM_fn_vForceCameraPos(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));
        if(eMetaActionId == eMetaAction_CamCinePosAMoveTgtBToC)
        {
            CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso), &stTempVector);

            fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
        }
        else
            CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(2, p_SuperObjPerso), &stTempVector);
        break;

    case eMetaAction_CamCinePosATgtB:
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamp_stVertex(1, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamlValue(2, p_SuperObjPerso, M_ReturnParam_lValue(&stParam));

        fn_vSetActionParamlValue(3, p_SuperObjPerso, GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount);
        CAM_fn_vForceCameraPos(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));
        CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso), &stTempVector);
        break;

    case eMetaAction_CamCinePosATgtBTurnPosH:
    case eMetaAction_CamCinePosATgtBTurnTgtH:
    case eMetaAction_CamCinePosATgtBTurnPosV:
    case eMetaAction_CamCinePosATgtBTurnTgtV:

        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamp_stVertex(1, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamxValue(2, p_SuperObjPerso, stParam.uParam.xValue);
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamlValue(3, p_SuperObjPerso, M_ReturnParam_lValue(&stParam));
        p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);
        fn_vSetActionParamlValue(4, p_SuperObjPerso, M_ReturnParam_lValue(&stParam));

        fn_vSetActionParamlValue(5, p_SuperObjPerso, GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount);
        CAM_fn_vForceCameraPos(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));
        CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso), &stTempVector);
        if((eMetaActionId == eMetaAction_CamCinePosATgtBTurnTgtH) || (eMetaActionId == eMetaAction_CamCinePosATgtBTurnTgtV))
        {

            fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
        }
        break;

    default:
        break;
    }

    return p_stTree;
}

/* 0x0048C280 */
unsigned char __cdecl fn_ucCamCineMoveAToBTgtC(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo  hCineinfo;
    MTH3D_tdstVector        stTempVector, stCurrentCameraPos;
    unsigned long           ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(5, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {
        CAM_fn_vForceCameraPos(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
        MTH3D_M_vSetVectorElements(&stTempVector, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
        CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(2, p_SuperObjPerso), &stTempVector);

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    POS_fn_vGetTranslationVector
    (
        HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso),
        &stCurrentCameraPos
    );

    MTH3D_M_vCopyVector(&stTempVector, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
    fnv_MoveAToB
    (
        p_SuperObjPerso,
        fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso),
        &stTempVector,
        &stCurrentCameraPos,
        fn_lGetActionParamlValue(3, p_SuperObjPerso),
        fn_lGetActionParamlValue(4, p_SuperObjPerso)
    );
    CAM_fn_vForceCameraPos(p_SuperObjPerso, &stTempVector);
    MTH3D_M_vSetVectorElements(&stTempVector, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(2, p_SuperObjPerso), &stTempVector);

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048C3D0 */
unsigned char __cdecl fn_ucCamCineMoveAToBTgtAC(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo  hCineinfo;
    MTH3D_tdstVector        stTempVector, stTempVector1, stCurrentCameraPos;
    unsigned long           ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(5, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {
        CAM_fn_vForceCameraPos(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
        MTH3D_M_vSubVector(&stTempVector1, fn_p_stGetActionParamp_stVertex(2, p_SuperObjPerso), fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));
        MTH3D_M_vAddVector(&stTempVector1, &stTempVector1, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
        MTH3D_M_vSetVectorElements(&stTempVector, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
        CAM_fn_vForceCameraTgt(p_SuperObjPerso, &stTempVector1, &stTempVector);

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    POS_fn_vGetTranslationVector
    (
        HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso),
        &stCurrentCameraPos
    );

    MTH3D_M_vCopyVector(&stTempVector, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
    fnv_MoveAToB
    (
        p_SuperObjPerso,
        fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso),
        &stTempVector,
        &stCurrentCameraPos,
        fn_lGetActionParamlValue(3, p_SuperObjPerso),
        fn_lGetActionParamlValue(4, p_SuperObjPerso)
    );
    CAM_fn_vForceCameraPos(p_SuperObjPerso, &stTempVector);

    MTH3D_M_vSubVector(&stTempVector1, fn_p_stGetActionParamp_stVertex(2, p_SuperObjPerso), fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));
    MTH3D_M_vAddVector(&stTempVector1, &stTempVector1, &stTempVector);
    MTH3D_M_vSetVectorElements(&stTempVector, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    CAM_fn_vForceCameraTgt(p_SuperObjPerso, &stTempVector1, &stTempVector);

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048C610 */
unsigned char __cdecl fn_ucCamCinePosATgtB(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo  hCineinfo;
    unsigned long           ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(2, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048C660 */
unsigned char __cdecl fn_ucCamCinePosAMoveTgtBToC(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo  hCineinfo;
    MTH3D_tdstVector        stTempVector, stTempVector1, stCurrentTarget;
    unsigned long           ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(5, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {
        MTH3D_M_vSetVectorElements(&stTempVector1, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
        CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(2, p_SuperObjPerso), &stTempVector1);

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    MTH3D_M_vCopyVector(&stCurrentTarget, fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));

    MTH3D_M_vCopyVector(&stTempVector, fn_p_stGetActionParamp_stVertex(2, p_SuperObjPerso));
    fnv_MoveAToB
    (
        p_SuperObjPerso,
        fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso),
        &stTempVector,
        &stCurrentTarget,
        fn_lGetActionParamlValue(3, p_SuperObjPerso),
        fn_lGetActionParamlValue(4, p_SuperObjPerso)
    );
    MTH3D_M_vSetVectorElements(&stTempVector1, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    CAM_fn_vForceCameraTgt(p_SuperObjPerso, &stTempVector, &stTempVector1);

    fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, &stTempVector);

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048C7C0 */
unsigned char __cdecl fn_ucCamCinePosATgtBTurnPosH(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo      hCineinfo;
    MTH3D_tdstVector            stTempVector, stCurrentCameraPos, stAxis;
    POS_tdstCompletePosition   *p_stPersoGlobalMatrix;
    unsigned long               ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(5, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    POS_fn_vGetTranslationVector
    (
        HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso),
        &stCurrentCameraPos
    );

    p_stPersoGlobalMatrix = HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso);
    POS_fn_vGetRotationMatrix(p_stPersoGlobalMatrix, &stTempVector, &stTempVector, &stAxis);

    MTH3D_M_vCopyVector(&stTempVector, fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));
    fnv_TurnAWithB
    (
        p_SuperObjPerso,
        &stTempVector,
        fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso),
        &stAxis,
        &stCurrentCameraPos,
        fn_xGetActionParamxValue(2, p_SuperObjPerso),
        fn_lGetActionParamlValue(3, p_SuperObjPerso),
        fn_lGetActionParamlValue(4, p_SuperObjPerso)
    );
    CAM_fn_vForceCameraPos(p_SuperObjPerso, &stTempVector);
    MTH3D_M_vSetVectorElements(&stTempVector, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso), &stTempVector);

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048C900 */
unsigned char __cdecl fn_ucCamCinePosATgtBTurnPosV(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo      hCineinfo;
    MTH3D_tdstVector            stTempVector, stCurrentCameraPos, stAxis;
    POS_tdstCompletePosition   *p_stPersoGlobalMatrix;
    unsigned long               ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(5, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    POS_fn_vGetTranslationVector
    (
        HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso),
        &stCurrentCameraPos
    );

    p_stPersoGlobalMatrix = HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso);
    POS_fn_vGetRotationMatrix(p_stPersoGlobalMatrix, &stAxis, &stTempVector, &stTempVector);

    MTH3D_M_vCopyVector(&stTempVector, fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso));
    fnv_TurnAWithB
    (
        p_SuperObjPerso,
        &stTempVector,
        fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso),
        &stAxis,
        &stCurrentCameraPos,
        fn_xGetActionParamxValue(2, p_SuperObjPerso),
        fn_lGetActionParamlValue(3, p_SuperObjPerso),
        fn_lGetActionParamlValue(4, p_SuperObjPerso)
    );
    CAM_fn_vForceCameraPos(p_SuperObjPerso, &stTempVector);
    MTH3D_M_vSetVectorElements(&stTempVector, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    CAM_fn_vForceCameraTgt(p_SuperObjPerso, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso), &stTempVector);

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048CA40 */
unsigned char __cdecl fn_ucCamCinePosATgtBTurnTgtH(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo      hCineinfo;
    MTH3D_tdstVector            stCurrentCameraPos, stTempVector, stTempVector1, stAxis;
    POS_tdstCompletePosition   *p_stPersoGlobalMatrix;
    unsigned long               ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(5, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    POS_fn_vGetTranslationVector
    (
        HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso),
        &stCurrentCameraPos
    );

    p_stPersoGlobalMatrix = HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso);
    POS_fn_vGetRotationMatrix(p_stPersoGlobalMatrix, &stTempVector, &stTempVector, &stAxis);

    MTH3D_M_vCopyVector(&stTempVector, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
    fnv_TurnAWithB
    (
        p_SuperObjPerso,
        &stTempVector,
        &stCurrentCameraPos,
        &stAxis,
        fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso),
        fn_xGetActionParamxValue(2, p_SuperObjPerso),
        fn_lGetActionParamlValue(3, p_SuperObjPerso),
        fn_lGetActionParamlValue(4, p_SuperObjPerso)
    );
    MTH3D_M_vSetVectorElements(&stTempVector1, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    CAM_fn_vForceCameraTgt(p_SuperObjPerso, &stTempVector, &stTempVector1);

    fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, &stTempVector);

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048CB80 */
unsigned char __cdecl fn_ucCamCinePosATgtBTurnTgtV(HIE_tdstSuperObject *p_SuperObjPerso)
{
    MS_tdxHandleToCineinfo      hCineinfo;
    MTH3D_tdstVector            stCurrentCameraPos, stTempVector, stTempVector1, stAxis;
    POS_tdstCompletePosition   *p_stPersoGlobalMatrix;
    unsigned long               ulEndTimer;

    hCineinfo = M_GetMSHandle(p_SuperObjPerso, Cineinfo);

    ulEndTimer = (unsigned long) fn_lGetActionParamlValue(5, p_SuperObjPerso);
    ulEndTimer += (unsigned long) fn_lGetActionParamlValue(3, p_SuperObjPerso);
    if
    (
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount >= ulEndTimer
    )
    {

        M_GetMSHandle(p_SuperObjPerso, StandardGame)->ulCustomBits &= ~0x8000;
        return C_DefaultMetaActionFinished;
    }

    POS_fn_vGetTranslationVector
    (
        HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso),
        &stCurrentCameraPos
    );

    p_stPersoGlobalMatrix = HIE_fn_hGetSuperObjectGlobalMatrix(p_SuperObjPerso);
    POS_fn_vGetRotationMatrix(p_stPersoGlobalMatrix, &stAxis, &stTempVector, &stTempVector);

    MTH3D_M_vCopyVector(&stTempVector, fn_p_stGetActionParamp_stVertex(1, p_SuperObjPerso));
    fnv_TurnAWithB
    (
        p_SuperObjPerso,
        &stTempVector,
        &stCurrentCameraPos,
        &stAxis,
        fn_p_stGetActionParamp_stVertex(0, p_SuperObjPerso),
        fn_xGetActionParamxValue(2, p_SuperObjPerso),
        fn_lGetActionParamlValue(3, p_SuperObjPerso),
        fn_lGetActionParamlValue(4, p_SuperObjPerso)
    );
    MTH3D_M_vSetVectorElements(&stTempVector1, MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE);
    CAM_fn_vForceCameraTgt(p_SuperObjPerso, &stTempVector, &stTempVector1);

    fn_vSetActionParamp_stVertex(0, p_SuperObjPerso, &stTempVector);

    return C_DefaultMetaActionNotFinished;
}
