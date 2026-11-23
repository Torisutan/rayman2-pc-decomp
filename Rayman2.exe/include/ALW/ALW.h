#pragma once

#include <stddef.h>
#include "GAM/GAM_types.h"
#include "HIE/HIE_types.h"
#include "LST/LstDef2.h"
#include "POS/POS_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef HIE_tdxHandleToSuperObject_DEFINED
#define HIE_tdxHandleToSuperObject_DEFINED
typedef HIE_tdstSuperObject *HIE_tdxHandleToSuperObject;
#endif

typedef struct tdstAlwaysModelList_ *ALW_tdxHandleToModelList;

LST2_M_DynamicUseListOf(ALW_tdxHandleToModelList);

struct tdstAlwaysModelList_
{
    LST2_M_DynamicElementDeclaration(ALW_tdxHandleToModelList)
    tdObjectType              otObjectModelType;
    struct tdstEngineObject_ *p_stAlwaysObject;
};

typedef struct tdstAlways_
{
    unsigned long ulMaxNumberOfAlways;
    LST2_M_DynamicAnchorDeclaration(ALW_tdxHandleToModelList) ALW_h_LstAlwaysModel;
    HIE_tdxHandleToSuperObject   d_stAlwaysSuperObject;
    struct tdstEngineObject_    *d_stAlwaysEngineObjectInit;
    HIE_tdxHandleToSuperObject  *d_hAlwaysGenerator;
} tdstAlways;

typedef tdstAlways ALW_tdstAlways;

typedef struct tdstStructureHandleFunction_
{
    void          (__cdecl *p_fn_vCopyCloneMSFunction)(struct tdstEngineObject_ *, struct tdstEngineObject_ *);
    unsigned long (__cdecl *p_fn_ulSizeOfFunction)(void);
    void          (__cdecl *p_fn_vAllocFunction)(struct tdstEngineObject_ *);
    void          (__cdecl *p_fn_vFreeFunction)(struct tdstEngineObject_ *);
    void          (__cdecl *p_fn_vInitFunction)(struct tdstEngineObject_ *, int);
    void          (__cdecl *p_fn_vDesinitFunction)(struct tdstEngineObject_ *, int);
} tdstStructureHandleFunction;

#define OTI_AlwaysCreated  5

HIE_tdxHandleToSuperObject __cdecl fn_p_stAllocateAlways(
    tdObjectType                otObjectModelType,
    HIE_tdxHandleToSuperObject  p_stFatherSuperObject,
    HIE_tdxHandleToSuperObject  _hGenerator,
    unsigned short              uwAction,
    POS_tdstCompletePosition   *p_stMatrix);

#ifdef __cplusplus
}
#endif
