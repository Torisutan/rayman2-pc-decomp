#include "ALW/ALW.h"
#include "GAM/PlayAnim.h"
#include "GAM/Actions/3dData.h"
#include "GAM/STRUCTUR/State.h"

/* 0x0040FD30 */
void __cdecl PLA_fn_vSetCurrFrame(HIE_tdstSuperObject *p_stSuperObject, short _wFrame);

void __cdecl ANI_fn_vFreeze(HIE_tdxHandleToSuperObject hSuperObjPerso)
{
    MS_tdxHandleTo3dData h_Current3dData = M_GetMSHandle(hSuperObjPerso, 3dData);

    if (fn_uc3dDataGetFrameRate(h_Current3dData))
        fn_v3dDataSetFrameRate(h_Current3dData, 0);
}

void __cdecl ANI_fn_vUnFreeze(HIE_tdxHandleToSuperObject hSuperObjPerso)
{
    MS_tdxHandleTo3dData h_Current3dData = M_GetMSHandle(hSuperObjPerso, 3dData);

    if (!fn_uc3dDataGetFrameRate(h_Current3dData))
    {

        fn_v3dDataSetFrameRate(h_Current3dData, fn_scGetSpeedInState(fn_h3dDataGetCurrentState(h_Current3dData)));

        PLA_fn_vSetCurrFrame(hSuperObjPerso, (short)(fn_uw3dDataGetCurrentFrame(h_Current3dData) + 1));
    }
}
