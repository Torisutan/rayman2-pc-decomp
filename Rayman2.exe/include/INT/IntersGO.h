#pragma once

#include "ACP/ACP_types.h"
#include "MTH/MTH_types.h"
#include "GEO/GEO_types.h"
#include "POS/POS_types.h"
#include "GMT/GMT_types.h"

ACP_tdxBool INT_fn_bDetectIntersectSegmentWithFaceOfGeometricObject(
    MTH3D_tdstVector        *p_stVertexA,
    MTH3D_tdstVector        *p_stVectAB,
    GEO_tdstGeometricObject *p_stGeomObj);

/* 0x0048F3B0 */
ACP_tdxBool INT_fn_bGetInclusionPointInGeometricObject(
    MTH3D_tdstVector        *p_stPoint,
    GEO_tdstGeometricObject *p_stGeomObj);

/* 0x0048F610 */
ACP_tdxBool INT_fn_bDetectIntersectGeomObjWithGeomObj(
    GEO_tdstGeometricObject *p_stGeomObj1,
    POS_tdstCompletePosition *_p_stMatrix1,
    GEO_tdstGeometricObject *p_stGeomObj2,
    POS_tdstCompletePosition *_p_stMatrix2,
    GMT_tdxHandleToGameMaterial *_p_hMat1,
    GMT_tdxHandleToGameMaterial *_p_hMat2);
