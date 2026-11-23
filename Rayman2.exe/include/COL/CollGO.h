#ifndef _COL_COLLGO_H_
#define _COL_COLLGO_H_

#include "ACP/ACP_types.h"
#include "POS/POS_types.h"
#include "GEO/GEO_types.h"
#include "COL/CollGOCo.h"

void __cdecl COL_fn_vInitCollideStaticGeomObjWithStaticGeomObj(COL_tdstGVForCollision *p_stGV);

void __cdecl COL_fn_vComputeCollisionStaticGeomObjWithStaticGeomObj(COL_tdstGVForCollision *p_stGV);

void __cdecl COL_fn_vCollideStaticGeomObj1WithStaticGeomObj2(
    ACP_tdxHandleOfObject     _hGeometricObject1,
    POS_tdstCompletePosition *_p_stGeometricObjectStartMatrix1,
    POS_tdstCompletePosition *_p_stGeometricObjectEndMatrix1,
    ACP_tdxHandleOfObject     _hGeometricObject2,
    POS_tdstCompletePosition *_p_stGeometricObjectMatrix2,
    void                     *_p_vParameter1,
    short                     _sParameter2,
    ACP_tdxBool               _bStaticGeomObjHasNoTransformationMatrix,
    ACP_tdxBool               _bDynamicGeomObjHasZoomInsteadOfScale);

ACP_tdxBool __cdecl COL_fn_bDetectCollisionStaticGeomObjWithStaticGeomObj(
    GEO_tdxHandleToBoundingSphere  _hDynamicGeometricObject,
    POS_tdstCompletePosition      *_p_stDynamicGeometricObjectMatrix,
    void                          *_hStaticGeometricObject,
    POS_tdstCompletePosition      *_p_stStaticGeometricObjectMatrix,
    ACP_tdxBool                    _bStaticGeomObjHasNoTransformationMatrix,
    ACP_tdxBool                    _bDynamicGeomObjHasZoomInsteadOfScale,
    ACP_tdxBool                    _bHasABoxBoundingVolume);

#endif
