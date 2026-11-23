#pragma once

#include "AI/AI_types.h"
#include "MTH/MTH3D.h"

/* 0x00487E60 */
long __cdecl fn_lGetActionParamlValue(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso);

/* 0x00487F80 */
MTH3D_tdstVector *__cdecl fn_p_stGetActionParamp_stVertex(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso);

/* 0x00487EA0 */
void __cdecl fn_vSetActionParamlValue(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso, long lValue);

/* 0x00487DC0 */
void __cdecl fn_vSetActionParamxValue(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso, float xValue);

/* 0x00487EF0 */
void __cdecl fn_vSetActionParamp_stVertex(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso,
                                          MTH3D_tdstVector *p_stVertex);

/* 0x00487E10 */
MTH_tdxReal __cdecl fn_xGetActionParamxValue(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso);

void __cdecl fn_vSetActionParamStateValue(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso,
                                          struct tdstState_ *hState);

struct tdstState_ *__cdecl fn_xGetActionParamStateValue(unsigned char ucN, HIE_tdstSuperObject *p_SuperObjPerso);
