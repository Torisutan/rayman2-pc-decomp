#include "AI/MetaAction.h"
#include "AI/ActParam.h"
#include "GAM/GAM_types.h"
#include "GAM/PlayAnim.h"

extern long __cdecl PLA_fn_bTestCurrentAction(HIE_tdstSuperObject *p_stSuperObject,
                                              struct tdstState_ *h_FirstStateOfAction);
extern long __cdecl PLA_fn_bTestIfEndOfAnim(HIE_tdstSuperObject *p_stSuperObject);

/* 0x0048CCC0 */
AI_tdstNodeInterpret *__cdecl fn_p_stExecuteActionInit(HIE_tdstSuperObject *p_SuperObjPerso,
                                                       AI_tdstNodeInterpret *p_stTree)
{
    struct tdstState_ *h_WantedState;

    p_stTree = fn_p_stDefaultActionInit(p_SuperObjPerso, p_stTree);
    h_WantedState = fn_xGetActionParamStateValue(0, p_SuperObjPerso);

    fn_v3dDataSetFirstStateOfAction(M_GetMSHandle(p_SuperObjPerso, 3dData), NULL);

    fn_vSetActionParamlValue(0, p_SuperObjPerso,
        (long)(PLA_fn_bSetNewState(p_SuperObjPerso, h_WantedState, 0, 0, 0)));

    fn_vSetActionParamStateValue(1, p_SuperObjPerso, h_WantedState);

    return(p_stTree);
}

/* 0x0048CD30 */
unsigned char __cdecl fn_ucExecuteAction(HIE_tdstSuperObject *p_SuperObjPerso)
{
    struct tdstState_ *h_WantedState = fn_xGetActionParamStateValue(1, p_SuperObjPerso);

    if (fn_lGetActionParamlValue(0, p_SuperObjPerso) == 0)
        return C_DefaultMetaActionFinished;

    if (!PLA_fn_bTestCurrentAction(p_SuperObjPerso, h_WantedState))
        return C_DefaultMetaActionFinished;

    if (PLA_fn_bTestIfEndOfAction(p_SuperObjPerso))
        return C_DefaultMetaActionFinished;

    return C_DefaultMetaActionNotFinished;
}

/* 0x0048CD80 */
unsigned char __cdecl fn_ucWaitEndOfAction(HIE_tdstSuperObject *p_SuperObjPerso)
{
    if (PLA_fn_bTestIfEndOfAction(p_SuperObjPerso))
        return C_DefaultMetaActionFinished;
    return C_DefaultMetaActionNotFinished;
}

/* 0x0048CDA0 */
unsigned char __cdecl fn_ucWaitEndOfAnim(HIE_tdstSuperObject *p_SuperObjPerso)
{
    if (PLA_fn_bTestIfEndOfAnim(p_SuperObjPerso))
        return C_DefaultMetaActionFinished;
    return C_DefaultMetaActionNotFinished;
}

/* 0x0048CDC0 */
AI_tdstNodeInterpret *__cdecl fn_p_stFrozenWaitInit(HIE_tdstSuperObject *p_SuperObjPerso,
                                                    AI_tdstNodeInterpret *p_stTree)
{
    long lTimer;

    p_stTree = fn_p_stDefaultActionInit(p_SuperObjPerso, p_stTree);

    lTimer = fn_lGetActionParamlValue(0, p_SuperObjPerso);

    fn_vSetActionParamlValue(0, p_SuperObjPerso,
        GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount + lTimer);

    return p_stTree;
}

/* 0x0048CE00 */
unsigned char __cdecl fn_ucFrozenWait(HIE_tdstSuperObject *p_SuperObjPerso)
{
    unsigned char ucReturn;

    ucReturn = (GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount
                < (unsigned long) fn_lGetActionParamlValue(0, p_SuperObjPerso))
        ? C_DefaultMetaActionNotFinished
        : C_DefaultMetaActionFinished;

    return ucReturn;
}
