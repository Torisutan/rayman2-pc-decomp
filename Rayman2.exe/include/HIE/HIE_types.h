#pragma once

#include <stddef.h>
#include "GLI/GLI_types.h"
#include "GEO/GEO_types.h"
#include "SPO/SPO_types.h"
#include "POS/POS_types.h"
#include "HIE/HIE_globals.h"

typedef struct HIE_tdstSuperObject HIE_tdstSuperObject;
typedef union HIE_tduLinkedObject HIE_tduLinkedObject;
typedef struct HIE_tdstVector HIE_tdstVector;

union HIE_tduLinkedObject
{
    HIE_tdstSuperObject *p_stSuperObject;
    void *p_Void;
};

struct HIE_tdstVector
{
    float x;
    float y;
    float z;
};

struct HIE_tdstSuperObject
{
    unsigned long ulTypeOfLinkedObject;
    HIE_tduLinkedObject hLinkedObject;

    HIE_tdstSuperObject *p_stFirstChild;
    HIE_tdstSuperObject *p_stLastChild;
    long lNumberOfChildren;

    HIE_tdstSuperObject *p_stNextBrother;
    HIE_tdstSuperObject *p_stPrevBrother;
    HIE_tdstSuperObject *p_stFather;

    void *hLocalMatrix;
    void *hGlobalMatrix;
    long lLastComputeFrame;
    long lDrawModeMask;
    unsigned long ulFlags;
    void *hBoundingVolume;
    float fTransparenceLevel;
    HIE_tdstVector stSemiLookAtVector;
};

typedef struct HIE_tdstEngineObject_ HIE_tdstEngineObject;
struct HIE_tdstEngineObject_
{
    void *h3dData;
    void *hStandardGame;
    void *hDynam;
    void *h_Brain;

    void *hCineInfo;
    void *hCollSet;
    void *hMSWay;
    void *hMSLight;
    void *hSectInfo;
    void *hMicro;
    void *hMSPrtSrc;
    void *hMSSound;
    void *hAnimEffect;
    void *hMSMagnet;
};

/* 0x00514ea0 */
extern long HIE_gs_lCurrentFrame;

#define HIE_g_p_stCurrentInCamCoordsMatrix g_p_stCurrentInCamCoordsMatrix

#define HIE_C_lCounterNotValid (-1)
#define HIE_C_lMaxMatrixInStack 0x32

extern POS_tdstCompletePosition HIE_g_a_stCameraMatrixStack[HIE_C_lMaxMatrixInStack + 1];

extern void *HIE_g_a_hMatrixStack_backing[1 + HIE_C_lMaxMatrixInStack];
#define HIE_C_MaxNumberOfSPOInTheFix 0x20

extern HIE_tdstSuperObject *HIE_gd_hFixSPO[HIE_C_MaxNumberOfSPOInTheFix];
extern HIE_tdstSuperObject *HIE_gd_hFixSPOSave[HIE_C_MaxNumberOfSPOInTheFix];
extern unsigned char HIE_gd_ucContextOfSPOSave[HIE_C_MaxNumberOfSPOInTheFix];

#define HIE_C_Flag_NotPickable              0x00000001UL
#define HIE_C_Flag_ulHidden                 0x00000002UL
#define HIE_C_Flag_ulNoTransformationMatrix 0x00000004UL
#define HIE_C_Flag_ulZoomInsteadOfScale     0x00000008UL
#define HIE_C_Flag_ulTypeOfBoundingVolume   0x00000010UL
#define HIE_C_Flag_Superimposed             0x00000020UL
#define HIE_C_Flag_ulNotHitByRayTrace       0x00000040UL
#define HIE_C_Flag_ulNoShadowOnMe           0x00000080UL
#define HIE_C_Flag_ulSemiLookAt             0x00000100UL
#define HIE_C_Flag_ulCheckChildren          0x00000200UL
#define HIE_C_Flag_ulRenderOnNearPlane      0x00000400UL
#define HIE_C_Flag_MagnetModification       0x00008000UL
#define HIE_C_Flag_ModuleTransparency       0x00010000UL
#define HIE_C_Flag_ExcluLight               0x00020000UL

#define HIE_C_ulSuperObject    0x00000001UL
#define HIE_C_ulActor          0x00000002UL
#define HIE_C_ulSector         0x00000004UL
#define HIE_C_ulPO             0x00000008UL
#define HIE_C_ulPO_Mirror      0x00000010UL
#define HIE_C_ulIPO            0x00000020UL
#define HIE_C_ulIPO_Mirror     0x00000040UL
#define HIE_C_ulSpecialEffect  0x00000080UL
#define HIE_C_ulNoAction       0x00000100UL
#define HIE_C_ulMirror         0x00000200UL
#define HIE_C_ulEDT_Geometric  0x00000400UL

static __inline void *HIE_fn_hGetSuperObjectObject(HIE_tdstSuperObject *_hSprObj)
{
    return _hSprObj->hLinkedObject.p_Void;
}

#define HIE_M_xGetSuperObjectMember(_hSprObj,_member) ((_hSprObj)->_member)

#define HIE_M_ForEachChildOf(_hSprObj,_hChild,_i) \
    for ((_i)=0,(_hChild)=(_hSprObj)->p_stFirstChild; (_hChild)!=NULL; (_i)++,(_hChild)=(_hChild)->p_stNextBrother)
#define HIE_M_hGetSuperObjectFather(_hSprObj) ((_hSprObj)->p_stFather)
static __inline HIE_tdstSuperObject *HIE_fn_hGetSuperObjectFather(HIE_tdstSuperObject *_hSprObj)
{
    return _hSprObj->p_stFather;
}
static __inline POS_tdstCompletePosition *HIE_fn_hGetSuperObjectMatrix(HIE_tdstSuperObject *_hSprObj)
{
    return (POS_tdstCompletePosition *)_hSprObj->hLocalMatrix;
}
static __inline POS_tdstCompletePosition *HIE_fn_hGetSuperObjectGlobalMatrix(HIE_tdstSuperObject *_hSprObj)
{
    return (POS_tdstCompletePosition *)_hSprObj->hGlobalMatrix;
}

static __inline void HIE_fn_vSuperObjectIsolate(HIE_tdstSuperObject *_hSprObj)
{
    if (_hSprObj->p_stNextBrother != NULL)
        _hSprObj->p_stNextBrother->p_stPrevBrother = _hSprObj->p_stPrevBrother;
    if (_hSprObj->p_stPrevBrother != NULL)
        _hSprObj->p_stPrevBrother->p_stNextBrother = _hSprObj->p_stNextBrother;
    if (_hSprObj->p_stFather != NULL)
    {
        _hSprObj->p_stFather->lNumberOfChildren--;
        if (_hSprObj->p_stFather->p_stFirstChild == _hSprObj)
            _hSprObj->p_stFather->p_stFirstChild = _hSprObj->p_stNextBrother;
        if (_hSprObj->p_stFather->p_stLastChild == _hSprObj)
            _hSprObj->p_stFather->p_stLastChild = _hSprObj->p_stPrevBrother;
    }
    _hSprObj->p_stNextBrother = NULL;
    _hSprObj->p_stPrevBrother = NULL;
    _hSprObj->p_stFather      = NULL;
}

static __inline void HIE_fn_vSuperObjectAddTail(HIE_tdstSuperObject *_hParent, HIE_tdstSuperObject *_hSprObj)
{
    HIE_fn_vSuperObjectIsolate(_hSprObj);
    _hSprObj->p_stNextBrother = NULL;
    _hSprObj->p_stPrevBrother = _hParent->p_stLastChild;
    _hSprObj->p_stFather      = _hParent;
    if (_hParent->p_stFirstChild == NULL)
        _hParent->p_stFirstChild = _hSprObj;
    else
        _hParent->p_stLastChild->p_stNextBrother = _hSprObj;
    _hParent->p_stLastChild = _hSprObj;
    _hParent->lNumberOfChildren++;
}

static __inline void HIE_fn_vSuperObjectAddHead(HIE_tdstSuperObject *_hParent, HIE_tdstSuperObject *_hSprObj)
{
    HIE_fn_vSuperObjectIsolate(_hSprObj);
    _hSprObj->p_stPrevBrother = NULL;
    _hSprObj->p_stNextBrother = _hParent->p_stFirstChild;
    _hSprObj->p_stFather      = _hParent;
    if (_hParent->p_stLastChild == NULL)
        _hParent->p_stLastChild = _hSprObj;
    else
        _hParent->p_stFirstChild->p_stPrevBrother = _hSprObj;
    _hParent->p_stFirstChild = _hSprObj;
    _hParent->lNumberOfChildren++;
}

static __inline void HIE_fn_vValidateGlobalMatrix(HIE_tdstSuperObject *_hSprObj)
{
    _hSprObj->lLastComputeFrame = HIE_gs_lCurrentFrame;
}

static __inline MTH_tdxReal HIE_fn_fGetSuperObjectTransparenceLevel(HIE_tdstSuperObject *_hSprObj)
{
    return _hSprObj->fTransparenceLevel;
}
static __inline void HIE_fn_vSetSuperObjectTransparenceLevel(HIE_tdstSuperObject *_hSprObj, MTH_tdxReal _fLevel)
{
    _hSprObj->fTransparenceLevel = _fLevel;
}
static __inline long HIE_fn_lGetSuperObjectDrawMask(HIE_tdstSuperObject *_hSprObj)
{
    return _hSprObj->lDrawModeMask;
}
static __inline void HIE_fn_vSetSuperObjectDrawMask(HIE_tdstSuperObject *_hSprObj, long _lDrawMask)
{
    _hSprObj->lDrawModeMask = _lDrawMask;
}
static __inline unsigned long HIE_fn_SO_ulGetFlags(HIE_tdstSuperObject *_hSprObj)
{
    return _hSprObj->ulFlags;
}
static __inline void HIE_fn_vSetSuperObjectBoundingVolume(HIE_tdstSuperObject *_hSprObj, void *_hBoundingVolume)
{
    _hSprObj->hBoundingVolume = _hBoundingVolume;
}
static __inline void HIE_fn_SO_vSetFlags(HIE_tdstSuperObject *_hSprObj, unsigned long _ulFlags)
{
    _hSprObj->ulFlags = _ulFlags;
}

static __inline HIE_tdstSuperObject *HIE_fn_hGetElementFromSuperObjectTab(HIE_tdstSuperObject *_p_stTab, long _lIndex)
{
    return &_p_stTab[_lIndex];
}
static __inline long HIE_fn_hGetIndexFromSuperObjectTabAndElement(HIE_tdstSuperObject *_p_stTab, HIE_tdstSuperObject *_hSprObj)
{
    return (long)(_hSprObj - _p_stTab);
}

void HIE_fn_vSetSuperObjectExcluLight(HIE_tdstSuperObject *_hSprObj, unsigned char _bExcluLight);

void HIE_fn_vIsolate(HIE_tdstSuperObject *_hSprObj);
void HIE_fn_vPseudoIsolate(HIE_tdstSuperObject *_hSprObj);
void HIE_fn_vSetSuperObjectObjectAndType(HIE_tdstSuperObject *_hSprObj, void *_hObj, unsigned long _ulType);
void HIE_fn_vInitMatrixStack(void);
ACP_tdxBool HIE_fn_bStoreMatrix(void *hMatrix);
ACP_tdxBool HIE_fn_bPopMatrix(void);
void HIE_fn_vPushMatrix(HIE_tdstSuperObject *hSprObj);
void HIE_fn_vRefreshHierarchy(HIE_tdstSuperObject *_hSprObj);
int HIE_fn_bInitCameraMatrixStack(void *_hVpt);
ACP_tdxBool HIE_fn_bPushOnCameraMatrixStack(void *_hMatrix);
ACP_tdxBool HIE_fn_bPopOnCameraMatrixStack(void);
void HIE_fn_vPushOnCameraMatrixStack(HIE_tdstSuperObject *_hSprObj);
HIE_tdstSuperObject *HIE_fn_hForceGetSuperObjectNextBrother(HIE_tdstSuperObject *_hSprObj);
HIE_tdstSuperObject *HIE_fn_hForceGetSuperObjectPrevBrother(HIE_tdstSuperObject *_hSprObj);
HIE_tdstSuperObject *HIE_fn_p_stCreateSuperObjectTab(long _lSize);
HIE_tdstSuperObject *HIE_fn_hGetElementFormFixViewport(short xIndex);

void HIE_fn_vComputeNewRelativeMatrix(HIE_tdstSuperObject *_hSprObj);
void HIE_fn_vComputeNewRelativeScaleMatrix(HIE_tdstSuperObject *_hSprObj);
void HIE_fn_vChangeFather(HIE_tdstSuperObject *_hSprObj, HIE_tdstSuperObject *_hNewFather, unsigned char _bFirstChild);

void HIE_fn_vInitGlobalMatrixFrameCounter(long lValue);
void HIE_fn_vInvalidateAllGlobalMatrices(void);
void HIE_fn_vInvalidateOneGlobalMatrix(HIE_tdstSuperObject *_hSprObj);
void HIE_fn_vInvalidateHierarchy(HIE_tdstSuperObject *_hSprObj);
void HIE_fn_SO_vSetSuperimposedFlag(HIE_tdstSuperObject *_hSO);
void HIE_fn_SO_vClearSuperimposedFlag(HIE_tdstSuperObject *_hSO);
void HIE_fn_SO_SwitchSuperImposedTab(long lParam);

void HIE_fn_vSetMagnetModification(HIE_tdstSuperObject *_hSprObj, unsigned char _xModified);
unsigned char HIE_fn_bGetMagnetModification(HIE_tdstSuperObject *_hSprObj);

ACP_tdxBool HIE_fn_bSendSPOToFixViewport(void *_hVpt, long _lDrawMask);
void HIE_fn_vSendStaticWorldToViewport(void *hVpt, HIE_tdstSuperObject *hSprObj, long DrawMask, long lCullingResult);
void HIE_fn_vSendCharacterModulesToViewPort(void *hVpt, HIE_tdstSuperObject *hSprObj, long DrawMask);
void HIE_fn_vSendCharacterToViewport(void *hVpt, HIE_tdstSuperObject *hSprObj, long DrawMask, long lCullingResult);

POS_tdstCompletePosition *HIE_hRetrieveCurrentMatrix(void);

ACP_tdxBool HIE_fn_bLoadIdentity(void);

void HIE_fn_hFindAllMirrorsInHierarchy(void *hVpt, HIE_tdstSuperObject *hSprObj,
    HIE_tdstSuperObject **p_hHandleOfMirror, void **p_hHandleOfGeometricMirror,
    short *p_shNbOfMirrors, short shNbMaxOfMirrors);

void *HIE_fn_p_stGetGeometricObjectFromSuperObject(HIE_tdstSuperObject *h_SuperObject);

void SPO_ReinitSuperimposedArray(void);
HIE_tdstSuperObject *HIE_fn_hCreateSuperObject(void);
void HIE_fn_vDestroySuperObject(HIE_tdstSuperObject *hOldSuperObject);
void *GEO_fn_hCreateMatrix(void);
void HIE_fn_vCreateMatrixStack(void);

#define HIE_C_DepthPickingObjects 3

typedef struct {
    HIE_tdstSuperObject  *hSprObject;
    void                 *hGeoObject;
    GLI_tdstPickedObject  stPickedObject;
} HIE_tdstPickInfo;

typedef HIE_tdstPickInfo HIE_aDEF_stTabOfPickInfo[HIE_C_DepthPickingObjects];

short HIE_bIntersectSegmentWithSuperObject(MTH3D_tdstVector *p_stVertexA, MTH3D_tdstVector *p_stVectAB, HIE_tdstSuperObject *hSprObj, HIE_tdstPickInfo *p_stPickInfo);
ACP_tdxBool HIE_bIntersectSegmentWithFirstSuperObject(MTH3D_tdstVector *_p_stVertexA, MTH3D_tdstVector *_p_stVectAB, HIE_tdstSuperObject *hSprObj, MTH3D_tdstVector *_p_stHit, MTH3D_tdstVector *_p_stNormal, HIE_tdstSuperObject **_p_hSprObjHit);
ACP_tdxBool HIE_bDetectIntersectSegmentWithSuperObject(MTH3D_tdstVector *p_stVertexA, MTH3D_tdstVector *p_stVectAB, HIE_tdstSuperObject *_hSprObj);
ACP_tdxBool fn_bDetectIntersectSegmentWithBoundingSphere(POS_tdstCompletePosition *_p_stCurrentMatrix, MTH3D_tdstVector *_p_stVertexA, MTH3D_tdstVector *_p_stVectAB, GEO_tdxHandleToBoundingSphere _hBoundingSphere);
