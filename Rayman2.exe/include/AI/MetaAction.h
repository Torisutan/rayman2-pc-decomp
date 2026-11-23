#pragma once

#include "AI/AI_types.h"

enum tdeMetaActionId_
{
    eMetaAction_FrozenWait,
    eMetaAction_ExecuteAction,
    eMetaAction_WaitEndOfAction,
    eMetaAction_WaitEndOfAnim,
    eMetaAction_CamCineMoveAToBTgtC,
    eMetaAction_CamCineMoveAToBTgtAC,
    eMetaAction_CamCinePosATgtB,
    eMetaAction_CamCinePosAMoveTgtBToC,
    eMetaAction_CamCinePosATgtBTurnPosH,
    eMetaAction_CamCinePosATgtBTurnTgtH,
    eMetaAction_CamCinePosATgtBTurnPosV,
    eMetaAction_CamCinePosATgtBTurnTgtV,
    eNbMetaAction
};

#include "AI/ActConst.h"

typedef AI_tdstNodeInterpret *(__cdecl *tdp_fn_p_stMetaActionInitFunctionPtr)(HIE_tdstSuperObject *, AI_tdstNodeInterpret *);
typedef unsigned char (__cdecl *tdp_fn_ucMetaActionFunctionPtr)(HIE_tdstSuperObject *);

typedef struct tdstMetaActionEntry_
{
    tdp_fn_p_stMetaActionInitFunctionPtr p_fn_p_stMetaActionInitFunction;
    tdp_fn_ucMetaActionFunctionPtr       p_fn_ucMetaActionFunction;
    char                                 szMetaActionTypeParam[9];
} tdstMetaActionEntry;

/* 0x00487D90 */
char *__cdecl szGetMetaActionTypeInParamFromId(enum tdeMetaActionId_ eMetaActionId);
tdp_fn_p_stMetaActionInitFunctionPtr __cdecl fn_p_fn_pGetMetaActionInitFunctionPtr(enum tdeMetaActionId_ eMetaActionId);
tdp_fn_ucMetaActionFunctionPtr __cdecl fn_p_fn_pGetMetaActionFunctionPtr(enum tdeMetaActionId_ eMetaActionId);

AI_tdstNodeInterpret *__cdecl fn_p_stDefaultActionInit(HIE_tdstSuperObject *p_SuperObjPerso, AI_tdstNodeInterpret *p_stTree);
AI_tdstNodeInterpret *__cdecl fn_p_stExecuteActionInit(HIE_tdstSuperObject *p_SuperObjPerso, AI_tdstNodeInterpret *p_stTree);
unsigned char __cdecl fn_ucExecuteAction(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucWaitEndOfAction(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucWaitEndOfAnim(HIE_tdstSuperObject *p_SuperObjPerso);
AI_tdstNodeInterpret *__cdecl fn_p_stFrozenWaitInit(HIE_tdstSuperObject *p_SuperObjPerso, AI_tdstNodeInterpret *p_stTree);
unsigned char __cdecl fn_ucFrozenWait(HIE_tdstSuperObject *p_SuperObjPerso);
AI_tdstNodeInterpret *__cdecl fn_p_stCamCineInit(HIE_tdstSuperObject *p_SuperObjPerso, AI_tdstNodeInterpret *p_stTree);
unsigned char __cdecl fn_ucCamCineMoveAToBTgtC(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucCamCineMoveAToBTgtAC(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucCamCinePosATgtB(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucCamCinePosAMoveTgtBToC(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucCamCinePosATgtBTurnPosH(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucCamCinePosATgtBTurnTgtH(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucCamCinePosATgtBTurnPosV(HIE_tdstSuperObject *p_SuperObjPerso);
unsigned char __cdecl fn_ucCamCinePosATgtBTurnTgtV(HIE_tdstSuperObject *p_SuperObjPerso);
