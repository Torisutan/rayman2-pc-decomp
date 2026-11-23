#ifndef _COL_COLLGOCO_H_
#define _COL_COLLGOCO_H_

#include "ACP/ACP_types.h"
#include "MTH/MTH3D.h"
#include "POS/POS_types.h"
#include "GEO/GEO_types.h"
#include "COL/COL_types.h"

#define COL_C_xMaxStaticPoints  500
#define COL_C_xMaxStaticEdges   500
#define COL_C_xNbVerticesPerBox 8

#define COL_C_ulDynamicEltWithStaticPts 0x000000F0
#define COL_C_ulDynamicEdgWithStaticEdg 0x00000100
#define COL_C_ulDynamicEdgWithStaticElt 0x00000600
#define COL_C_ulDynamicEltWithStaticEdg 0x00001800
#define COL_C_ulDynamicEltWithStaticElt 0x01FFE000
#define COL_C_ulDynamicSphWithStaticEdg 0x00000800
#define COL_C_ulDynamicSphWithStaticITr 0x00020000
#define COL_C_ulDynamicSphWithStaticSph 0x00080000
#define COL_C_ulDynamicSphWithStaticElt 0x001E0000
#define COL_C_ulDynamicAllWithStaticAll 0x01FFFFFF
#define COL_C_xMaxStaticBoundingBoxes   50

#define COL_C_xMaxNumberOfCollisions 75

#ifndef COL_C_xHighEdgeEntity
#define COL_C_xTriangleEntity   1
#define COL_C_xSphereEntity     3
#define COL_C_xAlignedBoxEntity 4
#define COL_C_xHighEdgeEntity   7
#define COL_C_xLowEdgeEntity    8
#define COL_C_xNoEntity         99
#endif

typedef MTH3D_tdstVector COL_tda8st8VerticesBox[COL_C_xNbVerticesPerBox];

typedef struct COL_tdstCollisionCase_
{
    MTH_tdxReal      xCollisionTime;
    MTH3D_tdstVector stCollisionNormal;
    MTH3D_tdstVector stCollisionPoint;
    void            *hDynamicMaterial;
    void            *hStaticMaterial;
    void            *p_vParameter1;
    long             sParameter2;
    ACP_tdxIndex     xDynamicGeomEntity;
    ACP_tdxIndex     xStaticGeomEntity;
    MTH3D_tdstVector stTranslation;
    MTH3D_tdstVector stMovement;
    MTH3D_tdstVector stEndPosition;
    MTH_tdxReal      xSphereRadius;
    MTH_tdxReal      m_xSlide1;
    MTH_tdxReal      m_xRebound1;
    MTH_tdxReal      m_xSlide2;
    MTH_tdxReal      m_xRebound2;
} COL_tdstCollisionCase;

struct GEO_tdstDoubledIndex_;

typedef struct COL_tdstGVForCollision_
{

    ACP_tdxBool               bStaticGeomObjHasNoTransformationMatrix;
    ACP_tdxBool               bDynamicGeomObjHasZoomInsteadOfScale;
    GEO_tdstGeometricObject  *p_stDynamicGeomObj;
    POS_tdstCompletePosition *p_stT0DynamicGeomObjMatrix;
    POS_tdstCompletePosition *p_stT1DynamicGeomObjMatrix;
    GEO_tdstGeometricObject  *p_stStaticGeomObj;
    POS_tdstCompletePosition *p_stStaticGeomObjMatrix;
    unsigned long             ulSelectedCollisionCases;
    void                     *p_vParameter1;
    short                     sParameter2;

    POS_tdstCompletePosition  stInvMatrix;
    POS_tdstCompletePosition  stD2ST0TransformMatrix;
    POS_tdstCompletePosition  stD2ST1TransformMatrix;
    POS_tdstCompletePosition  stS2DT0TransformMatrix;
    POS_tdstCompletePosition  stS2DT1TransformMatrix;
    MTH_tdxReal               xStaticScale;

    ACP_tdxIndex xDynamicPointIndex;
    ACP_tdxIndex xStaticPointIndex;
    ACP_tdxIndex xDynamicEdgeIndex;
    ACP_tdxIndex xStaticEdgeIndex;
    ACP_tdxIndex xDynamicElementIndex;
    ACP_tdxIndex xStaticElementIndex;

    MTH3D_tdstVector                *p_stDynamicPoint;
    MTH3D_tdstVector                *p_stStaticPoint;
    struct GEO_tdstDoubledIndex_    *p_stDynamicEdge;
    struct GEO_tdstDoubledIndex_    *p_stStaticEdge;
    GEO_tdstElementIndexedTriangles *p_stDynamicElementIndexedTriangles;
    GEO_tdstElementIndexedTriangles *p_stStaticElementIndexedTriangles;
    void                            *p_stDynamicElementFaceMapDescriptors;
    void                            *p_stStaticElementFaceMapDescriptors;
    GEO_tdstElementSpheres          *p_stDynamicElementSpheres;
    GEO_tdstElementSpheres          *p_stStaticElementSpheres;
    GEO_tdstElementAlignedBoxes     *p_stDynamicElementAlignedBoxes;
    GEO_tdstElementAlignedBoxes     *p_stStaticElementAlignedBoxes;

    ACP_tdxIndex xDynamicIndexedTriangleIndex;
    ACP_tdxIndex xStaticIndexedTriangleIndex;
    ACP_tdxIndex xDynamicFaceMapTriangleIndex;
    ACP_tdxIndex xStaticFaceMapTriangleIndex;
    ACP_tdxIndex xDynamicIndexedSphereIndex;
    ACP_tdxIndex xStaticIndexedSphereIndex;
    ACP_tdxIndex xDynamicIndexedAlignedBoxIndex;
    ACP_tdxIndex xStaticIndexedAlignedBoxIndex;

    long lBitsFieldOfIndexedSpheresInCollision;

    GEO_tdstIndexedSphere *p_stDynamicIndexedSphere;
    GEO_tdstIndexedSphere *p_stStaticIndexedSphere;
    void *p_stDynamicIndexedAlignedBox;
    void *p_stStaticIndexedAlignedBox;

    MTH3D_tdstVector stDinST0Point;
    MTH3D_tdstVector stDinST1Point;
    MTH3D_tdstVector stDinST01Vector;
    MTH3D_tdstVector stSwapDinST0Point;
    MTH3D_tdstVector stSinDT0Point;
    MTH3D_tdstVector stSinDT1Point;
    MTH3D_tdstVector stSinDT01Vector;

    ACP_tdxIndex      xVertex1Index;
    ACP_tdxIndex      xVertex2Index;
    MTH3D_tdstVector *p_stVertex1;
    MTH3D_tdstVector *p_stVertex2;
    MTH3D_tdstVector  stEdgeVector;

    MTH3D_tdstVector *p_stDynamicCenter;
    MTH3D_tdstVector *p_stStaticCenter;
    MTH_tdxReal       xDynamicRadius;
    MTH_tdxReal       xSwapRadius;
    ACP_tdxBool       bUseEnlargeSphere;

    MTH3D_tdstVector *p_stDynamicMinPoint;
    MTH3D_tdstVector *p_stDynamicMaxPoint;
    MTH3D_tdstVector *p_stStaticMinPoint;
    MTH3D_tdstVector *p_stStaticMaxPoint;

    MTH3D_tdstVector stDinST0MaxPoint;
    MTH3D_tdstVector stDinST1MaxPoint;
    MTH3D_tdstVector stDinST0MinPoint;
    MTH3D_tdstVector stDinST1MinPoint;

    COL_tda8st8VerticesBox a8_stDynamic8VBox;
    COL_tda8st8VerticesBox a8_stStatic8VBox;
    COL_tda8st8VerticesBox a8_stDinST08VBox;
    COL_tda8st8VerticesBox a8_stDinST18VBox;
    COL_tda8st8VerticesBox a8_stDinST01Vect;
    COL_tda8st8VerticesBox a8_stSinDT08VBox;
    COL_tda8st8VerticesBox a8_stSinDT18VBox;
    COL_tda8st8VerticesBox a8_stSinDT01Vect;

    void *hDynamicMaterial;
    void *hStaticMaterial;

    COL_tdpstOctree     p_stOctree;
    ACP_tdxIndex        xNumberOfSelectedNodes;
    COL_tdpstOctreeNode aDEF_pstSelectedNode[COL_C_xMaxSelectedNodes];
    MTH_tdxReal         aDEF_xSelectedT[COL_C_xMaxSelectedNodes];

    ACP_tdxBool bSurfacicDynamicElement;
    ACP_tdxBool bDynamicSphereAndPointOnly;

    ACP_tdxIndex xNbStaticPoints;
    ACP_tdxIndex aDEF_xListOfStaticPoints[COL_C_xMaxStaticPoints];

    ACP_tdxIndex xNbStaticEdges;
    ACP_tdxIndex aDEF_xListOfStaticPt1Edges[COL_C_xMaxStaticEdges];
    ACP_tdxIndex aDEF_xListOfStaticPt2Edges[COL_C_xMaxStaticEdges];
    void        *aDEF_hListOfStaticMaterialEdges[COL_C_xMaxStaticEdges];
} COL_tdstGVForCollision;

void __cdecl COL_fn_vAddInStaticCollisionTable(MTH_tdxReal       _xT,
                                               MTH3D_tdstVector *_p_stTranslation,
                                               MTH3D_tdstVector *_p_stHit,
                                               MTH3D_tdstVector *_p_stNormal,
                                               void             *_hDynMat,
                                               void             *_hStatMat,
                                               ACP_tdxIndex      _xDynamicGeomEntity,
                                               ACP_tdxIndex      _xStaticGeomEntity,
                                               void             *_p_vParameter1,
                                               short             _sParameter2,
                                               MTH3D_tdstVector *_p_stMovement,
                                               MTH_tdxReal       _xSphereRadius,
                                               MTH3D_tdstVector *_p_stEndPosition);

#endif
