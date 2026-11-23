#pragma once

#include "GEO/GEO_types.h"

void GEO_vSetHandleOfIndexedSprite(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xIndexOfSprite,
    ACP_tdxHandleOfSprite  hSprite);

void GEO_vCreateElementIndexedTriangles(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement *p_hElement,
    ACP_tdxIndex            xNbFaces,
    ACP_tdxIndex            xNbElementUV);

void GEO_vSetFaceOfIndexedTriangles(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xIndexOfFace,
    ACP_tdxIndex           xPoint1,
    ACP_tdxIndex           xPoint2,
    ACP_tdxIndex           xPoint3);

void GEO_vSetIndexedUVOfFaceOfIndexedTriangles(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xIndexOfFace,
    ACP_tdxIndex           xUV1,
    ACP_tdxIndex           xUV2,
    ACP_tdxIndex           xUV3);

void GEO_vSetUVOfIndexedTriangles(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xIndexOfUV,
    ACP_tdst2DUVValues    *p_stUV);

void GEO_vSetGameMaterialOfIndexedTriangles(
    ACP_tdxHandleOfObject       hObject,
    ACP_tdxHandleOfElement      hElement,
    GMT_tdxHandleToGameMaterial hMaterial);

void GEO_vGetGameMaterialOfIndexedTriangles(
    ACP_tdxHandleOfObject        hObject,
    ACP_tdxHandleOfElement       hElement,
    GMT_tdxHandleToGameMaterial *p_hMaterial);

void GEO_vGetMaterialOfIndexedTriangles(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement  hElement,
    ACP_tdxHandleOfMaterial *p_hMaterial);

void GEO_xCreateElementPoints(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement *p_hElement,
    ACP_tdxIndex            xNumberOfPoints);

GMT_tdxHandleToGameMaterial GEO_xGetGameMaterialOfElementPoints(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement);

void GEO_vCreateElementSpheres(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement *p_hElement,
    ACP_tdxIndex            xNbSpheres);

void GEO_vSetRadiusOfIndexedSphere(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfSphere,
    MTH_tdxReal            xRadius);

void GEO_vSetMaterialOfIndexedSphere(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement  hElement,
    ACP_tdxIndex            xNumberOfSphere,
    ACP_tdxHandleOfMaterial hMaterial);

void GEO_vSetGameMaterialOfIndexedSphere(
    ACP_tdxHandleOfObject       hObject,
    ACP_tdxHandleOfElement      hElement,
    ACP_tdxIndex                xNumberOfSphere,
    GMT_tdxHandleToGameMaterial hMaterial);

ACP_tdxIndex GEO_lGetIndexedSphereNbSpheres(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement);

GMT_tdxHandleToGameMaterial GEO_hGetGameMaterialOfIndexedSphere(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfSphere);

void GEO_vSetCenterPointOfIndexedSphere(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfSphere,
    ACP_tdxIndex           xIndexOfPoint);

ACP_tdxIndex GEO_xGetCenterPointOfIndexedSphere(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfSphere);

void GEO_vCreateElementAlignedBoxes(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement *p_hElement,
    ACP_tdxIndex            xNbAlignedBoxes);

void GEO_vGetMinMaxPointOfIndexedAlignedBox(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfAlignedBox,
    ACP_tdxIndex          *p_xMinPoint,
    ACP_tdxIndex          *p_xMaxPoint);

GMT_tdxHandleToGameMaterial GEO_vGetGameMaterialOfIndexedAlignedBox(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfAlignedBox);

MTH_tdxReal GEO_xGetRadiusOfIndexedSphere(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfSphere);

void GEO_vCreateElementCones(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement *p_hElement,
    ACP_tdxIndex            xNbCones);

void GEO_vSetPointsOfIndexedCone(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfCone,
    ACP_tdxIndex           xTopPoint,
    ACP_tdxIndex           xBasePoint);

void GEO_vGetPointsOfIndexedCone(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfCone,
    ACP_tdxIndex          *p_xTopPoint,
    ACP_tdxIndex          *p_xBasePoint);

void GEO_vSetRadiusOfIndexedCone(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfCone,
    MTH_tdxReal            xRadius);

void GEO_vSetMaterialOfIndexedCone(
    ACP_tdxHandleOfObject   hObject,
    ACP_tdxHandleOfElement  hElement,
    ACP_tdxIndex            xNumberOfCone,
    ACP_tdxHandleOfMaterial hMaterial);

void GEO_vSetGameMaterialOfIndexedCone(
    ACP_tdxHandleOfObject       hObject,
    ACP_tdxHandleOfElement      hElement,
    ACP_tdxIndex                xNumberOfCone,
    GMT_tdxHandleToGameMaterial hMaterial);

GMT_tdxHandleToGameMaterial GEO_vGetGameMaterialOfIndexedCone(
    ACP_tdxHandleOfObject  hObject,
    ACP_tdxHandleOfElement hElement,
    ACP_tdxIndex           xNumberOfCone);
