#pragma once

#include "ACP/ACP_types.h"
#include "MTH/MTH_types.h"

#define COL_C_ulNullMask    0x00u
#define COL_C_ulXMinMask    0x01u
#define COL_C_ulXMaxMask    0x02u
#define COL_C_ulYMinMask    0x04u
#define COL_C_ulYMaxMask    0x08u
#define COL_C_ulZMinMask    0x10u
#define COL_C_ulZMaxMask    0x20u

#define INT_C_xNoSolution   0
#define INT_C_xOneSolution  1
#define INT_C_xTwoSolutions 2

ACP_tdxIndex INT_fn_xTrinomeResolution(MTH_tdxReal xA, MTH_tdxReal xB, MTH_tdxReal xC,
                                       MTH_tdxReal *p_xT1, MTH_tdxReal *p_xT2);

unsigned long INT_fn_ulGetPositionPointWithBox(MTH3D_tdstVector *p_stPoint,
                                               MTH3D_tdstVector *p_stMinPoint,
                                               MTH3D_tdstVector *p_stMaxPoint);

ACP_tdxBool INT_fn_bIntersectBoxWithBox(MTH3D_tdstVector *p_stMinPoint1,
                                        MTH3D_tdstVector *p_stMaxPoint1,
                                        MTH3D_tdstVector *p_stMinPoint2,
                                        MTH3D_tdstVector *p_stMaxPoint2);

ACP_tdxBool INT_fn_bIntersectSphereWithBox(MTH3D_tdstVector *p_stCenter,
                                           MTH_tdxReal       xRadius,
                                           MTH3D_tdstVector *p_stMinPoint,
                                           MTH3D_tdstVector *p_stMaxPoint);

ACP_tdxBool INT_fn_bIntersectSphereWithSphere(MTH3D_tdstVector *p_stCenter1,
                                              MTH_tdxReal       xRadius1,
                                              MTH3D_tdstVector *p_stCenter2,
                                              MTH_tdxReal       xRadius2);

ACP_tdxBool INT_fn_bGetInclusionPointInBox(MTH3D_tdstVector *p_stPoint,
                                           MTH3D_tdstVector *p_stMinPoint,
                                           MTH3D_tdstVector *p_stMaxPoint);

ACP_tdxBool INT_fn_bIntersectSegmentWithTriangle2(MTH3D_tdstVector *p_stVertexA,
                                                  MTH3D_tdstVector *p_stVectAB,
                                                  MTH3D_tdstVector *p_stVertex1,
                                                  MTH3D_tdstVector *p_stVertex2,
                                                  MTH3D_tdstVector *p_stVertex3,
                                                  MTH3D_tdstVector *p_stNormal,
                                                  MTH_tdxReal       xDPlan,
                                                  MTH_tdxReal       xDotProduct,
                                                  MTH_tdxReal      *p_xT,
                                                  MTH3D_tdstVector *p_stHit);

ACP_tdxBool INT_fn_bGetPointInTriangle(MTH3D_tdstVector *p_stPoint,
                                       MTH3D_tdstVector *p_stVertex0,
                                       MTH3D_tdstVector *p_stVertex1,
                                       MTH3D_tdstVector *p_stVertex2,
                                       MTH3D_tdstVector *p_stNormal);

ACP_tdxBool INT_fn_bGetInclusionPointInSphere(MTH3D_tdstVector *p_stPoint,
                                              MTH3D_tdstVector *p_stSphereCenter,
                                              MTH_tdxReal       xSphereRadius);

ACP_tdxBool INT_fn_bFastRejectIntersectSegmentWithSphere(MTH3D_tdstVector *p_stVertex1,
                                                         MTH3D_tdstVector *p_stVect12,
                                                         MTH3D_tdstVector *p_stSphereCenter,
                                                         MTH_tdxReal       xSphereRadius);

ACP_tdxBool INT_fn_bIntersectSegmentWithSphere(MTH3D_tdstVector *p_stVertex1,
                                               MTH3D_tdstVector *p_stVect12,
                                               MTH3D_tdstVector *p_stSphereCenter,
                                               MTH_tdxReal       xSphereRadius,
                                               MTH_tdxReal      *p_xT,
                                               MTH3D_tdstVector *p_stHit,
                                               MTH3D_tdstVector *p_stNormal);

ACP_tdxBool INT_fn_bIntersectSegmentWithCylinder(MTH3D_tdstVector *p_stVertex1,
                                                 MTH3D_tdstVector *p_stVect12,
                                                 MTH3D_tdstVector *p_stVertexA,
                                                 MTH3D_tdstVector *p_stVectAB,
                                                 MTH_tdxReal       xCylinderRadius,
                                                 MTH_tdxReal      *p_xTSegment,
                                                 MTH3D_tdstVector *p_stHitSegment,
                                                 MTH3D_tdstVector *p_stHitLine);

ACP_tdxBool INT_fn_bDetectIntersectSegmentWithBox(MTH3D_tdstVector *p_stVertex1,
                                                  MTH3D_tdstVector *p_stVect12,
                                                  MTH3D_tdstVector *p_stMinPoint,
                                                  MTH3D_tdstVector *p_stMaxPoint,
                                                  MTH_tdxReal      *_p_xT);

ACP_tdxBool INT_fn_bDetectIntersectSegmentWithSphere(MTH3D_tdstVector *p_stVertexA,
                                                     MTH3D_tdstVector *p_stVectAB,
                                                     MTH3D_tdstVector *p_stSphereCenter,
                                                     MTH_tdxReal       xSphereRadius);

ACP_tdxBool INT_fn_bDetectIntersectSegmentWithTriangle(MTH3D_tdstVector *p_stVertexA,
                                                       MTH3D_tdstVector *p_stVectAB,
                                                       MTH3D_tdstVector *p_stVertex1,
                                                       MTH3D_tdstVector *p_stVertex2,
                                                       MTH3D_tdstVector *p_stVertex3,
                                                       MTH3D_tdstVector *p_stNormal,
                                                       MTH_tdxReal       xDPlan);
