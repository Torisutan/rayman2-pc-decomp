#ifndef _AI_FIELDTABLE_H
#define _AI_FIELDTABLE_H

#include "AI/AI_types.h"

typedef unsigned char (__cdecl *tdp_fn_ucGetSetField)(void *p_stContext,
                                                      AI_tdstGetSetParam *p_stValue);
typedef void          (__cdecl *tdp_fn_vFieldPostProc)(AI_tdstGetSetParam *p_stValue);

typedef struct tdstFieldTableEntryA_
{
    unsigned long        eTypeIndex;
    tdp_fn_ucGetSetField p_fn_ucGetField;
    tdp_fn_ucGetSetField p_fn_ucSetField;
} tdstFieldTableEntryA;

typedef struct tdstFieldTableEntryB_
{
    unsigned long         eVariableType;
    tdp_fn_vFieldPostProc p_fn_vGetPostProc;
    tdp_fn_vFieldPostProc p_fn_vSetPostProc;
} tdstFieldTableEntryB;

extern tdstFieldTableEntryA a_stFieldTableA[18];
extern tdstFieldTableEntryB a_stFieldTypeTable[5];

extern unsigned long         __cdecl fn_eGetFieldTypeIndex(unsigned long ulFieldId);            /* 0x00488FC0 */
extern tdp_fn_ucGetSetField  __cdecl fn_p_fn_ucGetFieldGetFunctionPtr(unsigned long ulFieldId); /* 0x00488FD0 */
extern tdp_fn_vFieldPostProc __cdecl fn_p_fn_vGetFieldPostProcFunctionPtr(unsigned long ulTypeIndex); /* 0x00488FA0 */
extern tdp_fn_ucGetSetField  __cdecl fn_p_fn_ucGetFieldSetFunctionPtr(unsigned long ulFieldId); /* 0x00488FE0 */
extern tdp_fn_vFieldPostProc __cdecl fn_p_fn_vSetFieldPostProcFunctionPtr(unsigned long ulTypeIndex); /* 0x00488FB0 */

#endif
