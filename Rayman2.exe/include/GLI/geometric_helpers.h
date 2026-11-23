#pragma once

#include "MTH/MTH_types.h"

void __cdecl COL_fn_vComputeBoundingBoxOfSphere(MTH3D_tdstVector *p_stMinBounding, MTH3D_tdstVector *p_stMaxBounding,
                                                MTH3D_tdstVector *p_stSphereCenter, MTH_tdxReal xSphereRadius);

void __cdecl COL_fn_vMinMaxBox2VerticesBox(MTH3D_tdstVector *a8_stBoxDest,
                              MTH3D_tdstVector *p_stMinPoint, MTH3D_tdstVector *p_stMaxPoint);

unsigned char __cdecl COL_fn_bDetectCollisionBetweenTwoParallelBoxes(MTH3D_tdstVector *p_stMaxA, MTH3D_tdstVector *p_stMinA,
                                                                      MTH3D_tdstVector *p_stMaxB, MTH3D_tdstVector *p_stMinB);

void __cdecl COL_fn_vComputeBoundingBoxOfSphereAndBox(MTH3D_tdstVector *p_stMinBounding, MTH3D_tdstVector *p_stMaxBounding,
                                                      MTH3D_tdstVector *p_stSphereCenter, MTH_tdxReal xSphereRadius,
                                                      MTH3D_tdstVector *p_stMinPoint, MTH3D_tdstVector *p_stMaxPoint);
