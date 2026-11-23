#ifndef _AI_DSGVARTABLE_H
#define _AI_DSGVARTABLE_H

#include "AI/AI_types.h"
#include "AI/EnumVar.h"

typedef unsigned char (*tdp_fn_ucGetDsgVarFunctionPtr)(void *,unsigned char,struct AI_tdstGetSetParam_ *);
typedef unsigned char (*tdp_fn_ucSetDsgVarFunctionPtr)(void *,unsigned char,struct AI_tdstGetSetParam_ *);

typedef struct tdstDsgVarTypeTableEntry_
{

  enum tdeVariableType_ eVariableType;
  tdp_fn_ucGetDsgVarFunctionPtr p_fn_ucGetDsgVarFunction;
  tdp_fn_ucSetDsgVarFunctionPtr p_fn_ucSetDsgVarFunction;
} tdstDsgVarTypeTableEntry;

extern tdstDsgVarTypeTableEntry a_stDsgVarTypeTable[eNbDsgVarType];

tdp_fn_ucGetDsgVarFunctionPtr fn_p_fn_pGetDsgVarGetFunctionPtr(enum tdeDsgVarTypeId_ eDsgVarTypeId);
tdp_fn_ucSetDsgVarFunctionPtr fn_p_fn_pGetDsgVarSetFunctionPtr(enum tdeDsgVarTypeId_ eDsgVarTypeId);
enum tdeVariableType_ fn_GetDsgVarType(enum tdeDsgVarTypeId_ eDsgVarTypeId);

/* 0x00481260 */
unsigned long fn_ulSizeOfDsgVar(tdeDsgVarTypeId eDsgVarTypeId, unsigned char ucNbElt);

#endif
