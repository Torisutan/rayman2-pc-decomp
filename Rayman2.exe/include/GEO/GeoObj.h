#pragma once

#include "GEO/GEO_types.h"

GEO_tdxHandleToParallelBox GEO_hGetParallelBox(
    ACP_tdxHandleOfObject hObject,
    ACP_tdxIndex          xParallelBox);

ACP_tdxIndex GEO_xGetParallelBoxIndexOfElement(
    ACP_tdxHandleOfObject hObject,
    ACP_tdxIndex          xIndexOfElement);

void GEO_vComputeObjectParallelBox(
    ACP_tdxHandleOfObject hObject,
    ACP_tdxIndex          xParallelBox);

/* 0x41cd60 */
void GEO_vCreateTMPGeometricObject(
    ACP_tdxHandleOfObject *p_hObject,
    ACP_tdxIndex           xNbPoints,
    ACP_tdxIndex           xNbElements);

/* 0x41cd30 */
void GEO_vCreateGeometricObject(
    ACP_tdxHandleOfObject *p_hObject,
    ACP_tdxIndex           xNbPoints,
    ACP_tdxIndex           xNbElements);

/* 0x41d1f0 */
void GEO_vEndModifyObject2(ACP_tdxHandleOfObject hObject);

/* 0x41d1a0 */
void GEO_vEndModifyObject(ACP_tdxHandleOfObject hObject);

void GEO_vSetPointOfObject(ACP_tdxHandleOfObject hObject,           /* 0x41cda0 */
    MTH3D_tdstVector *p_stPoint, ACP_tdxIndex xIndexOfPoint);
void GEO_vGetPointOfObject(ACP_tdxHandleOfObject hObject,           /* 0x41cdd0 */
    MTH3D_tdstVector *p_stPoint, ACP_tdxIndex xIndexOfPoint);

/* 0x41cd90 */
ACP_tdxIndex GEO_xGetGeometricObjectNumberOfPoints(ACP_tdxHandleOfObject hObject);

/* 0x41d2d0 */
ACP_tdxHandleOfObject GEO_fn_hTransformTableOfObjectInOneObjectForGAM(
    ACP_tdxHandleOfObject  _hGeoObj,
    ACP_tdxHandleOfObject *a_hTableOfGeoObj,
    ACP_tdxIndex           xNbOfgEOoBJ);

void GEO_vCreateObjectListOfPointsMaterial(ACP_tdxHandleOfObject hObject);   /* 0x41ce30 */
void GEO_vComputeObjectListOfPointsMaterial(ACP_tdxHandleOfObject hObject);  /* 0x41cf60 */

void GEO_xComputeNormalWeightedBySurf(
    MTH3D_tdstVector *p_stPResult,
    MTH3D_tdstVector *p_stPA,
    MTH3D_tdstVector *p_stPB,
    MTH3D_tdstVector *p_stPC);

void GEO_xComputeObjectNormals(GEO_tdstGeometricObject *p_stObj);   /* 0x41bdd0 */
void GEO_xComputeObjectNormals2(GEO_tdstGeometricObject *p_stObj);  /* 0x41c3f0 */

void GEO_xGrowSphereWithPoint(                                      /* 0x41b8f0 */
    MTH3D_tdstVector *p_stOutCenter, MTH_tdxReal *p_xOutRadius,
    MTH3D_tdstVector *p_stInCenter,  MTH_tdxReal  xInRadius,
    MTH3D_tdstVector *p_stPoint);

void GEO_xMergeSpheres(                                             /* 0x41b7c0 */
    MTH3D_tdstVector *p_stOutCenter, MTH_tdxReal *p_xOutRadius,
    MTH3D_tdstVector *p_stCenterA,   MTH_tdxReal  xRadiusA,
    MTH3D_tdstVector *p_stCenterB,   MTH_tdxReal  xRadiusB);

void GEO_xComputeSpriteRadius(GEO_tdstIndexedSprite *p_stSprite,    /* 0x41b9e0 */
    MTH_tdxReal *p_xOutRadius);

void GEO_xComputeObjectSphereBox(                                  /* 0x41ba30 */
    GEO_tdstGeometricObject *p_stObj,
    MTH3D_tdstVector        *p_stCenter,
    MTH_tdxReal             *p_xRadius);

ACP_tdxBool GEO_bIsLookAt (GEO_tdstGeometricObject *p_stObj) ;             /* 0x41dac0 */
