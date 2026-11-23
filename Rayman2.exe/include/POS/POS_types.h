#ifndef POS_TYPES_H
#define POS_TYPES_H

#include "MTH/MTH3D.h"

#define POS_C_ulIdentityMatrixFlag    1
#define POS_C_ulTranslationMatrixFlag 2
#define POS_C_ulRotationMatrixFlag    3
#define POS_C_ulCompleteMatrixFlag    4

typedef struct POS_tdstCompletePosition_ {
    unsigned long ulType;
    MTH3D_tdstVector stTranslationVector;
    MTH3D_tdstMatrix stRotationMatrix;
    MTH3D_tdstMatrix stTransformMatrix;
} POS_tdstCompletePosition;

typedef POS_tdstCompletePosition *POS_tdxHandleToPosition;

void POS_fn_vSetIdentityMatrix(POS_tdstCompletePosition *p_stPos);
void POS_fn_vMulMatrixVertex(MTH3D_tdstVector *_p_stDest, POS_tdstCompletePosition *_hMatrix, MTH3D_tdstVector *_p_stSource);
void POS_fn_vMulMatrixVector(MTH3D_tdstVector *_p_stDest, POS_tdstCompletePosition *_hMatrix, MTH3D_tdstVector *_p_stSource);
void POS_fn_vRotateVector(MTH3D_tdstVector *_p_stDest, POS_tdstCompletePosition *_hMatrix, MTH3D_tdstVector *_p_stSource);
void POS_fn_vNormalizeMatrix(POS_tdstCompletePosition *_hMatrix);
void POS_fn_vGetRotationVector(POS_tdstCompletePosition *_hMatrix,
                               MTH3D_tdstVector **_p_p_stI,
                               MTH3D_tdstVector **_p_p_stJ,
                               MTH3D_tdstVector **_p_p_stK);
void POS_fn_vSetRotationMatrix(POS_tdstCompletePosition *_hMatrix,
                               MTH3D_tdstVector *_p_stI,
                               MTH3D_tdstVector *_p_stJ,
                               MTH3D_tdstVector *_p_stK);
void POS_fn_vGetRotationMatrix(POS_tdstCompletePosition *_hMatrix,
                               MTH3D_tdstVector *_p_stI,
                               MTH3D_tdstVector *_p_stJ,
                               MTH3D_tdstVector *_p_stK);
void POS_fn_vSetScaleMatrix(POS_tdstCompletePosition *_hMatrix,
                            MTH3D_tdstVector *_p_stI,
                            MTH3D_tdstVector *_p_stJ,
                            MTH3D_tdstVector *_p_stK);
void POS_fn_vGetScaleMatrix(POS_tdstCompletePosition *_hMatrix,
                            MTH3D_tdstVector *_p_stI,
                            MTH3D_tdstVector *_p_stJ,
                            MTH3D_tdstVector *_p_stK);
void POS_fn_vGetTransformMatrix(POS_tdstCompletePosition *_hMatrix,
                                MTH3D_tdstVector *_p_stI,
                                MTH3D_tdstVector *_p_stJ,
                                MTH3D_tdstVector *_p_stK);
void POS_fn_vInvertIsoMatrix(POS_tdstCompletePosition *_hDest, POS_tdstCompletePosition *_hSrc);
void POS_fn_vInvertMatrix(POS_tdstCompletePosition *_hDest, POS_tdstCompletePosition *_hSrc);
void POS_fn_vMulMatrixMatrix(POS_tdstCompletePosition *_hDest, POS_tdstCompletePosition *_hA, POS_tdstCompletePosition *_hB);
void POS_fn_vGetTranslationVector(POS_tdstCompletePosition *_hMatrix, MTH3D_tdstVector *_p_stTrs);
void POS_fn_vSetTranslationVector(POS_tdstCompletePosition *_hMatrix, MTH3D_tdstVector *_p_stTrs);
void POS_fn_vSetTransformMatrix(POS_tdstCompletePosition *_hMatrix, MTH3D_tdstVector *_p_stI, MTH3D_tdstVector *_p_stJ, MTH3D_tdstVector *_p_stK);
void POS_fn_vSetZoomMatrix(POS_tdstCompletePosition *_hMatrix, MTH_tdxReal _xZoom);
MTH_tdxReal POS_fn_xGetXScale(POS_tdstCompletePosition *_hMatrix);
MTH_tdxReal POS_fn_xGetYScale(POS_tdstCompletePosition *_hMatrix);
MTH_tdxReal POS_fn_xGetMaxScale(POS_tdstCompletePosition *_hMatrix);
void POS_fn_vQuatToMat(MTH3D_tdstMatrix *_p_stMatrix, MTH_tdxReal _xX, MTH_tdxReal _xY, MTH_tdxReal _xZ, MTH_tdxReal _xW);
void fn_vTurnMatrixX(POS_tdstCompletePosition *_p_stMatrix, MTH_tdxReal _xAngle);
void fn_vTurnMatrixY(POS_tdstCompletePosition *_p_stMatrix, MTH_tdxReal _xAngle);
void fn_vTurnMatrixZ(POS_tdstCompletePosition *_p_stMatrix, MTH_tdxReal _xAngle);
void POS_fn_vRotateX(POS_tdstCompletePosition *hMatrix, MTH_tdxReal xXAngle);   /* 0x00445BE0 */
void POS_fn_vRotateZ(POS_tdstCompletePosition *hMatrix, MTH_tdxReal xZAngle);   /* 0x00445C70 */
void POS_fn_vRotatePositionAroundAxis(POS_tdxHandleToPosition _hPos, MTH3D_tdstVector *_p_stAxisVector, MTH_tdxReal _xAngle);
void POS_fn_vRotatePositionAroundAxisNoTranslation(POS_tdxHandleToPosition _hPos, MTH3D_tdstVector *_p_stAxisVector, MTH_tdxReal _xAngle);

static inline MTH3D_tdstVector *POS_fn_p_stGetTranslationVector(POS_tdxHandleToPosition _hMatrix)
{
    return &_hMatrix->stTranslationVector;
}

static inline MTH3D_tdstVector *POS_fn_vGetTranslationVectorReadOnly(POS_tdxHandleToPosition _hMatrix)
{
    return &_hMatrix->stTranslationVector;
}

static inline MTH3D_tdstMatrix *POS_fn_vGetRotationMatrixReadOnly(POS_tdxHandleToPosition _hMatrix)
{
    return &_hMatrix->stRotationMatrix;
}

static inline MTH3D_tdstMatrix *POS_fn_vGetTransformMatrixReadOnly(POS_tdxHandleToPosition _hMatrix)
{
    return &_hMatrix->stTransformMatrix;
}

static inline void POS_fn_vGetTransformMatrixCol0(POS_tdxHandleToPosition _hMatrix, MTH3D_tdstVector *_p_Vec)
{
    MTH3D_M_vGetColumn0InMatrix(_p_Vec, &_hMatrix->stTransformMatrix);
}

static inline void POS_fn_vGetTransformMatrixCol1(POS_tdxHandleToPosition _hMatrix, MTH3D_tdstVector *_p_Vec)
{
    MTH3D_M_vGetColumn1InMatrix(_p_Vec, &_hMatrix->stTransformMatrix);
}

static inline void POS_fn_vGetTransformMatrixCol2(POS_tdxHandleToPosition _hMatrix, MTH3D_tdstVector *_p_Vec)
{
    MTH3D_M_vGetColumn2InMatrix(_p_Vec, &_hMatrix->stTransformMatrix);
}

#define POS_fn_ulIsIdentityMatrix(_hMatrix) ((_hMatrix)->ulType == POS_C_ulIdentityMatrixFlag)

static inline void POS_fn_vCopyMatrix(POS_tdxHandleToPosition _hDst, POS_tdxHandleToPosition _hSrc)
{
    *_hDst = *_hSrc;
}

#endif
