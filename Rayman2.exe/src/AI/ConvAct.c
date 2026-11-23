#include "AI/MetaAction.h"

tdstMetaActionEntry a_stMetaActionTable[eNbMetaAction] =
{

    { fn_p_stFrozenWaitInit,             fn_ucFrozenWait,                    "L"      },

    { fn_p_stExecuteActionInit,          fn_ucExecuteAction,                 "A"      },

    { fn_p_stDefaultActionInit,          fn_ucWaitEndOfAction,               ""       },

    { fn_p_stDefaultActionInit,          fn_ucWaitEndOfAnim,                 ""       },

    { fn_p_stCamCineInit,                fn_ucCamCineMoveAToBTgtC,           "VVVLLL" },

    { fn_p_stCamCineInit,                fn_ucCamCineMoveAToBTgtAC,          "VVVLLL" },

    { fn_p_stCamCineInit,                fn_ucCamCinePosATgtB,               "VVLL"   },

    { fn_p_stCamCineInit,                fn_ucCamCinePosAMoveTgtBToC,        "VVVLLL" },

    { fn_p_stCamCineInit,                fn_ucCamCinePosATgtBTurnPosH,       "VVXLLL" },

    { fn_p_stCamCineInit,                fn_ucCamCinePosATgtBTurnTgtH,       "VVXLLL" },

    { fn_p_stCamCineInit,                fn_ucCamCinePosATgtBTurnPosV,       "VVXLLL" },

    { fn_p_stCamCineInit,                fn_ucCamCinePosATgtBTurnTgtV,       "VVXLLL" }
};

/* 0x00487D90 */
char *__cdecl szGetMetaActionTypeInParamFromId(enum tdeMetaActionId_ eMetaActionId)
{
    return( a_stMetaActionTable[eMetaActionId].szMetaActionTypeParam);
}

/* 0x00487DA0 */
tdp_fn_p_stMetaActionInitFunctionPtr __cdecl fn_p_fn_pGetMetaActionInitFunctionPtr(enum tdeMetaActionId_ eMetaActionId)
{
  return(a_stMetaActionTable[eMetaActionId].p_fn_p_stMetaActionInitFunction);
}

/* 0x00487DB0 */
tdp_fn_ucMetaActionFunctionPtr __cdecl fn_p_fn_pGetMetaActionFunctionPtr(enum tdeMetaActionId_ eMetaActionId)
{
  return(a_stMetaActionTable[eMetaActionId].p_fn_ucMetaActionFunction);
}
