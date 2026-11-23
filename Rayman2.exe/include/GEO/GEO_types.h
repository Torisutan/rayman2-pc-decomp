#pragma once

#include "ACP/ACP_types.h"
#include "GMT/GMT_types.h"
#include "MTH/MTH_types.h"
#include "MTH/MTH2D.h"
#include "POS/POS_types.h"

typedef struct COL_tdstOctree_ *COL_tdpstOctree;

#define GEO_C_lCullingOut       0x00
#define GEO_C_lCullingLeft      0x01
#define GEO_C_lCullingRight     0x02
#define GEO_C_lCullingUp        0x04
#define GEO_C_lCullingDown      0x08
#define GEO_C_lCullingNear      0x10
#define GEO_C_lCullingFar       0x20
#define GEO_C_lCullingIntersect 0x40
#define GEO_C_lCullingIn        0x7f

MTH_tdxReal GEO_xGetZFar(void);
void        GEO_vSetZFar(MTH_tdxReal _xZ);
MTH_tdxReal GEO_xGetZFarTransparencyZone(void);
void        GEO_vSetZFarTransparencyZone(MTH_tdxReal _xZ);
MTH_tdxReal GEO_xGetZFarTransparencyLevel(void);

void GEO_fn_vComputeCameraParametersForCulling(void *p_stVpt, MTH_tdxReal _xZFar);

typedef struct {
    MTH3D_tdstVector stCenterPoint;
    MTH_tdxReal      xRadius;
} GEO_tdstBoundingSphere;
typedef GEO_tdstBoundingSphere *GEO_tdxHandleToBoundingSphere;

typedef struct {
    MTH3D_tdstVector stMinPoint;
    MTH3D_tdstVector stMaxPoint;
} GEO_tdstParallelBox;
typedef GEO_tdstParallelBox *GEO_tdxHandleToParallelBox;

typedef void *GEO_tdxHandleToMatrix;

#define GEO_C_xElementNULL               0
#define GEO_C_xElementIndexedTriangles   1
#define GEO_C_xElementFaceMapDescriptors 2
#define GEO_C_xElementSprites            3
#define GEO_C_xElementTMeshes            4
#define GEO_C_xElementPoints             5
#define GEO_C_xElementLines              6
#define GEO_C_xElementSpheres            7
#define GEO_C_xElementAlignedBoxes       8
#define GEO_C_xElementCones              9

#define GEO_C_xNoParallelBox ((ACP_tdxIndex)0xFFFF)

#define GEO_C_NotALookAt 0

typedef struct {
    ACP_tdxIndex a3_xIndex[3];
} GEO_tdstTripledIndex;

typedef struct {
    MTH_tdxReal xU;
    MTH_tdxReal xV;
} ACP_tdst2DUVValues;

typedef struct {
    GMT_tdxHandleToGameMaterial  hMaterial;
    ACP_tdxIndex                 xNbFaces;
    ACP_tdxIndex                 xNbElementUV;
    GEO_tdstTripledIndex        *d_stListOfFacesTripled;
    GEO_tdstTripledIndex        *d_stListOfFacesTripledIndexUV;
    MTH3D_tdstVector            *d_stListOfFacesNormals;
    ACP_tdst2DUVValues          *d_stListOfElementUV;
    ACP_tdxIndex                *d_stListOfIndexUsedByThisElement;
    ACP_tdxIndex                 xNumberOfIndexsUsed;
    ACP_tdxIndex                 xIndexOfParallelBox;
} GEO_tdstElementIndexedTriangles;

typedef struct {
    ACP_tdxIndex a2_xIndex[2];
} GEO_tdstDoubledIndex;

typedef struct {
    GEO_tdstTripledIndex stFaceTripled;

    ACP_tdxHandleOfFMD   hFaceMapDescriptor;
} GEO_tdstFaceMapTriangle;

typedef struct {
    ACP_tdxIndex              xNbFaces;

    GEO_tdstFaceMapTriangle  *d_stListOfFacesQuadrupled;
    MTH3D_tdstVector         *d_stListOfFacesNormals;
    ACP_tdxIndex              xIndexOfParallelBox;
} GEO_tdstElementFaceMapDescriptors;

typedef struct {
    GMT_tdxHandleToGameMaterial  hMaterial;
    ACP_tdxIndex                 xNbMeshAtoms;
    ACP_tdxIndex                 xNbFaces;
    ACP_tdxIndex                 xNbUV;

    void                        *d_stListOfMeshAtoms;
    MTH3D_tdstVector            *d_stListOfFacesNormals;
    ACP_tdst2DUVValues          *d_stListOfElementUV;
    ACP_tdxIndex                 xIndexOfParallelBox;
} GEO_tdstElementTMeshes;

typedef struct GEO_tdstColor_ GEO_tdstColor;

typedef struct {
    ACP_tdxHandleOfSprite   hSprite;
    MTH2D_tdstVector        stSize;
    MTH3D_tdstVector        stAxe;
    ACP_tdst2DUVValues      stUVpos;
    ACP_tdst2DUVValues      stUVsize;
    ACP_tdxIndex            xCenterPoint;

} GEO_tdstIndexedSprite;

typedef struct {
    GEO_tdstIndexedSprite *d_stListOfSprites;
    ACP_tdxIndex           xNbSprites;
    ACP_tdxIndex           xIndexOfParallelBox;
    signed char            cFastDraw;
} GEO_tdstElementSprite;

typedef struct {
    MTH_tdxReal          xThickness;
    GEO_tdstDoubledIndex *d_stListOfLineIndex;
    GMT_tdxHandleToGameMaterial *d_hListOfLinesMaterial;
    void                *d_stListOfLinesReceivedLightIntensity;
    ACP_tdxIndex         xNbLines;
    ACP_tdxIndex         xIndexOfParallelBox;
} GEO_tdstElementLines;

typedef struct {
    MTH_tdxReal              xFatness;
    ACP_tdxIndex            *d_xListOfPointIndex;
    GMT_tdxHandleToGameMaterial hMaterial;
    ACP_tdxIndex             xNbPoints;
    ACP_tdxIndex             xIndexOfParallelBox;
} GEO_tdstElementPoints;

typedef struct {
    MTH_tdxReal                  xRadius;
    GMT_tdxHandleToGameMaterial  hMaterial;
    ACP_tdxIndex                 xCenterPoint;

} GEO_tdstIndexedSphere;

typedef struct {
    GEO_tdstIndexedSphere *d_stListOfSpheres;
    ACP_tdxIndex           xNbSpheres;
    ACP_tdxIndex           xIndexOfParallelBox;
} GEO_tdstElementSpheres;

typedef struct {
    ACP_tdxIndex                 xMinPoint;
    ACP_tdxIndex                 xMaxPoint;
    GMT_tdxHandleToGameMaterial  hMaterial;
} GEO_tdstIndexedAlignedBox;

typedef struct {
    GEO_tdstIndexedAlignedBox *d_stListOfAlignedBoxes;
    ACP_tdxIndex               xNbAlignedBoxes;
    ACP_tdxIndex               xIndexOfParallelBox;
} GEO_tdstElementAlignedBoxes;

typedef struct {
    ACP_tdxIndex                xTopPoint;
    ACP_tdxIndex                xBasePoint;
    MTH_tdxReal                 xBaseRadius;
    GMT_tdxHandleToGameMaterial hMaterial;
} GEO_tdstIndexedCone;

typedef struct {
    GEO_tdstIndexedCone *d_stListOfCones;
    ACP_tdxIndex         xNbCones;
    ACP_tdxIndex         xIndexOfParallelBox;
} GEO_tdstElementCones;

typedef struct GEO_tdstGeometricObject_ {
    MTH3D_tdstVector    *d_stListOfPoints;
    MTH3D_tdstVector    *d_stListOfPointsNormals;
    void                *d_hListOfPointsMaterial;
    void                *d_stListOfPointsReceivedLightIntensity;
    ACP_tdxIndex        *d_xListOfElementsTypes;
    void               **d_stListOfElements;
    COL_tdpstOctree      p_stOctree;
    void                *d_stListOfEdges;
    void                *d_hListOfEdgesMaterial;
    GEO_tdstParallelBox *d_stListOfParallelBoxes;
    unsigned long        ulType;
    ACP_tdxIndex         xNbPoints;
    ACP_tdxIndex         xNbElements;
    ACP_tdxIndex         xNbEdges;
    ACP_tdxIndex         xNbParallelBoxes;
    MTH_tdxReal          xBoudingSphereRadius;
    MTH3D_tdstVector     xBoudingSphereCenter;
} GEO_tdstGeometricObject;

static inline MTH3D_tdstVector *GEO_fn_pGetCenterPointOfBoundingSphere(GEO_tdxHandleToBoundingSphere _h)
    { return &_h->stCenterPoint; }
static inline MTH_tdxReal GEO_fn_xGetRadiusOfBoundingSphere(GEO_tdxHandleToBoundingSphere _h)
    { return _h->xRadius; }
static inline MTH3D_tdstVector *GEO_fn_pGetMinPointOfParallelBox(GEO_tdxHandleToParallelBox _h)
    { return &_h->stMinPoint; }
static inline MTH3D_tdstVector *GEO_fn_pGetMaxPointOfParallelBox(GEO_tdxHandleToParallelBox _h)
    { return &_h->stMaxPoint; }

long GEO_lCullingSphere(
    void                   *p_stVpt,
    MTH3D_tdstVector       *p_stSphereCenter,
    MTH_tdxReal             xRadius,
    POS_tdstCompletePosition *p_stMatrix,
    long                    _lCullingresult);

long GEO_lCullingSphereNoMMM(
    void                   *p_stVpt,
    MTH3D_tdstVector       *p_stShereCenter,
    MTH_tdxReal             xRadius,
    POS_tdstCompletePosition *p_stMatrix,
    long                    _lCullingresult);

long GEO_lCullingBox(
    void             *p_stVpt,
    MTH3D_tdstVector *p_stMin,
    MTH3D_tdstVector *p_stMax,
    long              _lCullingresult);

void GEO_vCreateObjectListOfParallelBox(
    ACP_tdxHandleOfObject hObject,
    ACP_tdxIndex          xNumberOfParallelBoxes);

void GEO_vComputeObjectListOfParallelBox(ACP_tdxHandleOfObject hObject);

void GEO_vTurnLookAt(
    GEO_tdstGeometricObject  *p_stObj,
    void                     *hVpt,
    POS_tdstCompletePosition *p_stCurrentMatrix);
