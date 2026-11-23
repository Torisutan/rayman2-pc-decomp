#pragma once

typedef void *(__cdecl *TMP_pfn_vMalloc_t)(unsigned long);
typedef void  (__cdecl *TMP_pfn_vFree_t)(void *);

#include "GLI/Memory.h"
#define TMP_fnp_vMalloc  ((TMP_pfn_vMalloc_t)&GLI_pc_fn_p_vAlloc)
#define TMP_fn_vFree     ((TMP_pfn_vFree_t)&GLI_pc_fn_vFree)

#define TMP_M_p_Malloc(ulSize)    (TMP_fnp_vMalloc((unsigned long)(ulSize)))
#define TMP_M_Free(p_vPointer)    (TMP_fn_vFree((void *)&(p_vPointer)))
