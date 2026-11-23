#include <stddef.h>
#include "COL/CsEltEdg.h"
#include "COL/CsSphElt.h"
#include "INT/Inters.h"
#include "POS/POS_types.h"
#include "GEO/GEO_types.h"
#include "MTH/MTH_flt.h"
#include "MTH/MTH3D.h"

#define C_xTwoEpsilon         (MTH_M_xConstFloatToReal (0.002f))
#define C_xOneMinusTwoEpsilon (MTH_M_xConstFloatToReal (0.998f))

#define COL_CT_ASSERT(tag, cond) typedef char tag[(cond) ? 1 : -1]
COL_CT_ASSERT(ee_off_vertex1, offsetof(COL_tdstGVForCollision, p_stVertex1)  == 0x298);
COL_CT_ASSERT(ee_off_vertex2, offsetof(COL_tdstGVForCollision, p_stVertex2)  == 0x29C);
COL_CT_ASSERT(ee_off_edgevec, offsetof(COL_tdstGVForCollision, stEdgeVector) == 0x2A0);
COL_CT_ASSERT(ee_off_staticscale, offsetof(COL_tdstGVForCollision, xStaticScale) == 0x1DC);

/* 0x0049AA20 */
void __cdecl
COL_fn_vCollideStaticSphereWithStaticEdge(COL_tdstGVForCollision *p_stGV,
                                          MTH3D_tdstVector       *p_stNormal)
{
    COL_fn_vUseEnlargeSphere(p_stGV);

    if (INT_fn_bDetectIntersectSegmentWithSphere(p_stGV->p_stVertex1, &p_stGV->stEdgeVector,
                                                 &p_stGV->stDinST0Point, p_stGV->xDynamicRadius))
    {
        MTH3D_tdstVector stMovementVector;

        MTH3D_M_vNegVector(&stMovementVector, &p_stGV->stDinST01Vector);

        COL_fn_vUseInitialSphere(p_stGV);

        if (INT_fn_bDetectIntersectSegmentWithSphere(p_stGV->p_stVertex1, &p_stGV->stEdgeVector,
                                                     &p_stGV->stDinST1Point, p_stGV->xDynamicRadius))
        {

            MTH3D_tdstVector stVertex1ToCenter;
            MTH_tdxReal      xDotProduct;
            MTH3D_tdstVector stTempHit;
            MTH3D_tdstVector stTempNormal;
            MTH3D_tdstVector stTempDistance;
            MTH3D_tdstVector stEndPosition;
            ACP_tdxIndex     xEdgeEntity;

            MTH3D_M_vSubVector(&stVertex1ToCenter, &p_stGV->stDinST0Point, p_stGV->p_stVertex1);
            xDotProduct = MTH3D_M_xDotProductVector(&stVertex1ToCenter, &p_stGV->stEdgeVector);
            xDotProduct = MTH_M_xDiv(xDotProduct, MTH3D_M_xSqrVector(&p_stGV->stEdgeVector));

            if (MTH_M_bLess(xDotProduct, C_xTwoEpsilon))
                xDotProduct = C_xTwoEpsilon;
            else if (MTH_M_bGreater(xDotProduct, C_xOneMinusTwoEpsilon))
                xDotProduct = C_xOneMinusTwoEpsilon;

            MTH3D_M_vMulAddVector(&stTempHit, xDotProduct, &p_stGV->stEdgeVector, p_stGV->p_stVertex1);

            MTH3D_M_vSubVector(&stTempDistance, &p_stGV->stDinST0Point, &stTempHit);
            POS_fn_vMulMatrixVector(&stTempDistance, p_stGV->p_stStaticGeomObjMatrix, &stTempDistance);

            MTH3D_M_vMulMatrixVector(&stTempNormal, &p_stGV->p_stStaticGeomObjMatrix->stRotationMatrix, p_stNormal);

            xDotProduct = MTH_M_xSub(MTH_M_xMul(p_stGV->xDynamicRadius, p_stGV->xStaticScale),
                                     MTH3D_M_xDotProductVector(&stTempDistance, &stTempNormal));
            MTH3D_M_vMulScalarVector(&stTempDistance, xDotProduct, &stTempNormal);

            if (MTH_M_bGreaterEqual(MTH3D_M_xGetZofVector(p_stGV->p_stVertex2),
                                    MTH3D_M_xGetZofVector(&stTempHit)))
                xEdgeEntity = COL_C_xHighEdgeEntity;
            else
                xEdgeEntity = COL_C_xLowEdgeEntity;

            POS_fn_vMulMatrixVertex(&stTempHit, p_stGV->p_stStaticGeomObjMatrix, &stTempHit);
            POS_fn_vMulMatrixVector(&stMovementVector, p_stGV->p_stStaticGeomObjMatrix, &stMovementVector);
            POS_fn_vMulMatrixVertex(&stEndPosition, p_stGV->p_stStaticGeomObjMatrix, &p_stGV->stDinST0Point);

            COL_fn_vAddInStaticCollisionTable(MTH_C_MinusONE, &stTempDistance, &stTempHit, &stTempNormal,
                                              p_stGV->hDynamicMaterial, p_stGV->hStaticMaterial,
                                              COL_C_xSphereEntity, xEdgeEntity,
                                              p_stGV->p_vParameter1, p_stGV->sParameter2,
                                              &stMovementVector, p_stGV->p_stDynamicIndexedSphere->xRadius, &stEndPosition);
        }
        else
        {

            MTH_tdxReal      xT;
            MTH3D_tdstVector stTempVector;
            MTH3D_tdstVector stHit;
            MTH3D_tdstVector stNormal;
            MTH3D_tdstVector stTempHit;
            MTH3D_tdstVector stTempDistance;
            MTH3D_tdstVector stTempNormal;
            MTH3D_tdstVector stEndPosition;
            ACP_tdxIndex     xEdgeEntity;

            if (INT_fn_bIntersectSegmentWithCylinder(&p_stGV->stDinST1Point, &stMovementVector,
                                                     p_stGV->p_stVertex1, &p_stGV->stEdgeVector,
                                                     p_stGV->xDynamicRadius, &xT, &stHit, &stNormal))
            {

                if (MTH_M_bGreaterEqual(MTH3D_M_xGetZofVector(p_stGV->p_stVertex2),
                                        MTH3D_M_xGetZofVector(&stNormal)))
                    xEdgeEntity = COL_C_xHighEdgeEntity;
                else
                    xEdgeEntity = COL_C_xLowEdgeEntity;

                POS_fn_vMulMatrixVertex(&stTempHit, p_stGV->p_stStaticGeomObjMatrix, &stNormal);

                MTH3D_M_vSubVector(&stTempVector, &stHit, &stNormal);
                MTH3D_M_vDivScalarVector(&stTempVector, &stTempVector, p_stGV->xDynamicRadius);

                MTH3D_M_vMulMatrixVector(&stTempNormal, &p_stGV->p_stStaticGeomObjMatrix->stRotationMatrix, p_stNormal);

                MTH3D_M_vNullVector(&stTempDistance);

                POS_fn_vMulMatrixVector(&stMovementVector, p_stGV->p_stStaticGeomObjMatrix, &stMovementVector);
                POS_fn_vMulMatrixVertex(&stEndPosition, p_stGV->p_stStaticGeomObjMatrix, &p_stGV->stDinST0Point);

                COL_fn_vAddInStaticCollisionTable(xT, &stTempDistance, &stTempHit, &stTempNormal,
                                                  p_stGV->hDynamicMaterial, p_stGV->hStaticMaterial,
                                                  COL_C_xSphereEntity, xEdgeEntity,
                                                  p_stGV->p_vParameter1, p_stGV->sParameter2,
                                                  &stMovementVector, p_stGV->p_stDynamicIndexedSphere->xRadius, &stEndPosition);
            }
            else
            {

                if (INT_fn_bDetectIntersectSegmentWithSphere(p_stGV->p_stVertex1, &p_stGV->stEdgeVector,
                                                             &p_stGV->stDinST0Point, p_stGV->xDynamicRadius))
                {
                    MTH3D_tdstVector stVertex1ToCenter;
                    MTH_tdxReal      xDotProduct;

                    MTH3D_M_vSubVector(&stVertex1ToCenter, &p_stGV->stDinST0Point, p_stGV->p_stVertex1);
                    xDotProduct = MTH3D_M_xDotProductVector(&stVertex1ToCenter, &p_stGV->stEdgeVector);
                    xDotProduct = MTH_M_xDiv(xDotProduct, MTH3D_M_xSqrVector(&p_stGV->stEdgeVector));
                    MTH3D_M_vMulAddVector(&stTempHit, xDotProduct, &p_stGV->stEdgeVector, p_stGV->p_stVertex1);

                    MTH3D_M_vSubVector(&stTempDistance, &p_stGV->stDinST0Point, &stTempHit);
                    POS_fn_vMulMatrixVector(&stTempDistance, p_stGV->p_stStaticGeomObjMatrix, &stTempDistance);
                    MTH3D_M_vNormalizeVector(&stTempNormal, &stTempDistance);

                    MTH3D_M_vNegVector(&stTempDistance, &stTempDistance);
                    MTH3D_M_vMulAddVector(&stTempDistance, p_stGV->xDynamicRadius, &stTempNormal, &stTempDistance);

                    POS_fn_vMulMatrixVertex(&stTempHit, p_stGV->p_stStaticGeomObjMatrix, &stTempHit);

                    MTH3D_M_vMulMatrixVector(&stTempNormal, &p_stGV->p_stStaticGeomObjMatrix->stRotationMatrix, p_stNormal);
                    POS_fn_vMulMatrixVector(&stMovementVector, p_stGV->p_stStaticGeomObjMatrix, &stMovementVector);
                    POS_fn_vMulMatrixVertex(&stEndPosition, p_stGV->p_stStaticGeomObjMatrix, &p_stGV->stDinST0Point);

                    COL_fn_vAddInStaticCollisionTable(MTH_M_xConstFloatToReal(1.5f), &stTempDistance, &stTempHit, &stTempNormal,
                                                      p_stGV->hDynamicMaterial, p_stGV->hStaticMaterial,
                                                      COL_C_xSphereEntity, COL_C_xLowEdgeEntity,
                                                      p_stGV->p_vParameter1, p_stGV->sParameter2,
                                                      &stMovementVector, p_stGV->p_stDynamicIndexedSphere->xRadius, &stEndPosition);
                }
            }
        }
    }
}
