#ifndef BLC_GEOMETRY_H
#define BLC_GEOMETRY_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stGeometricObject_
{
    float           fScale;
    float           fRadius;
    U64_tdxIndex    xListOfPointsId;
    U64_tdxIndex    xListOfColElementsId;
    U64_tdxIndex    xListOfU64ElementsId;
    unsigned short  uwNbPoints;
    unsigned short  uwNbColElements;
    unsigned short  uwNbU64Elements;
    unsigned short  uwNbEdges;
    unsigned short  uwSymType;
    unsigned short  uwRliFlag;
    unsigned short  uwLookAtFlag;
}   U64_tdstGeometricObject;

typedef struct U64_stElementList_
{   U64_tdxIndex    xIndexId;
    unsigned short  uwType;
    unsigned short  uwBoundingVolume;
    unsigned short  uwAlign;
}   U64_tdstElementList;

typedef struct _DS_Normal
{
    signed short n[3];
    signed short sRLI;
} DS_Normal;
#define DS_NORMAL_LENGTH 4095

typedef struct _DS_Vertex
{
    signed short v[3];
    signed short uv[2];
    DS_Normal n;
} DS_Vertex;

typedef struct _DS_Vtx
{
    signed short v[3];
} DS_Vtx;

typedef struct U64_stElementIndexedTriangles_
{   U64_tdxIndex    xMaterialId;
    U64_tdxIndex    xListOfFacesTripledId;
    U64_tdxIndex    xPointedSectorId;
    unsigned short  uwNbFaces;
    unsigned short  uwNbElementUV;
    unsigned short  uwMaterialType;
}   U64_tdstElementIndexedTriangles;

typedef struct U64_stElementU64IndexedTriangles_
{   U64_tdxIndex    xVisualMaterialId;
    U64_tdxIndex    xGfxListId;
    unsigned short  uwGfxListSize;
#if defined(_U64_GLI_BENCH_)
    unsigned short  uwNbFacesForBench;
#endif
#if defined(COMPRESS_GFXLIST)
    U64_tdxIndex    xCmpGfxListId;
    unsigned short  uwCmpGfxListSize;
#endif
}   U64_tdstElementU64IndexedTriangles;

typedef struct U64_stElementPoints_
{   float           fFatness;
    U64_tdxIndex    xLstPointsId;
    U64_tdxIndex    xGameMaterialId;
    unsigned short  uwPointsNb;
    unsigned short  uwPad;
}   U64_tdstElementPoints;

typedef struct U64_stPoint_
{   unsigned short  uwCenterId;
}   U64_tdstPoint;

typedef struct U64_stElementSpheres_
{   U64_tdxIndex    xLstSpheresId;
    unsigned short  uwSpheresNb;
}   U64_tdstElementSpheres;

typedef struct U64_stSphere_
{   float           fRadius;
    U64_tdxIndex    xGameMaterialId;
    unsigned short  uwCenterId;
}   U64_tdstSphere;

typedef struct U64_stElementAlignedBoxes_
{   U64_tdxIndex    xLstAlignedBoxesId;
    unsigned short  uwAlignedBoxesNb;
}   U64_tdstElementAlignedBoxes;

typedef struct U64_stAlignedBox_
{   U64_tdxIndex    xGameMaterialId;
    unsigned short  uwMinPointId;
    unsigned short  uwMaxPointId;
}   U64_tdstAlignedBox;

typedef struct U64_stElementCones_
{   U64_tdxIndex    xLstConesId;
    unsigned short  uwConesNb;
}   U64_tdstElementCones;

typedef struct U64_stCone_
{   float           fBaseRadius;
    unsigned short  uwBasePointId;
    unsigned short  uwTopPointId;
    U64_tdxIndex    xGameMaterialId;
    unsigned short  uwPad;
}   U64_tdstCone;

typedef struct U64_stElementSpritesList_
{   float           a2_fSize[2];
    U64_tdxIndex    xSpriteId;
    unsigned short  uwCenterId;
}   U64_tdstElementSpritesList;

#ifndef D_THROW_COMPLEX_SPRITE
typedef struct U64_stElementSprites_
{   U64_tdxIndex    xElementSpritesListId;
    unsigned short  uwElementSpritesListNb;
}   U64_tdstElementSprites;
#else
typedef struct U64_stElementSprites_
{
    U64_tdstVector2D    stSizeOfSprite;
    U64_tdxIndex        xVisualMaterialId;
    unsigned short      uwCenterId;
    unsigned short      uwTypeOfSprite;
}   U64_tdstElementSprites;
#endif

typedef struct U64_stSpriteInstance_
{   float               fThreshold;
    U64_tdstVector2D    stSizeOfSprite;
    U64_tdstVector2D    stDisplacementOfSprite;
    U64_tdxIndex        xMaterialId;
    unsigned short      uwTypeOfSprite;
    unsigned short      uwMaterialType;
    unsigned short      uwPad;
}   U64_tdstSpriteInstance;

typedef struct U64_stSprite_
{   U64_tdxIndex    xSpriteInstanceId;
    unsigned short  uwSpriteInstanceNb;
}   U64_tdstSprite;

typedef struct U64_stAltimapSquare_
{   U64_tdxIndex    xFaceIndex;
    unsigned char   ucType;
    unsigned char   ucAlign;
}   U64_tdstAltimapSquare;

typedef struct U64_stAltimapFace_
{   U64_tdstVector3D stNormal;
    unsigned short   uwMaterialType;
    U64_tdxIndex     xMaterialId;
    U64_tdxIndex     xUVIndex[3];
    U64_tdxIndex     xAlign;
}   U64_tdstAltimapFace;

typedef struct U64_stAltimapVertex_
{   U64_tdstVector3D stVector;
}   U64_tdstAltimapVertex;

typedef struct U64_stAltimapUV_
{   float xU;
    float xV;
}   U64_tdstAltimapUV;

typedef struct U64_stAltimap_
{
    unsigned short   uwNbVertices;
    unsigned short   uwNbSquares;
    unsigned short   uwNbVisibles;
    unsigned short   uwNbUVValues;
    U64_tdxIndex     xAltimapSquareId;
    U64_tdxIndex     xAltimapFaceId;
    U64_tdxIndex     xAltimapVertexId;
    U64_tdxIndex     xAltimapUVId;
    U64_tdstVector3D stOrigin;
    unsigned short   xWidth;
    unsigned short   xDepth;
    float            xDeltaX;
    float            xDeltaY;
    float*           d_xHeight;
}   U64_tdstAltimap;

typedef struct U64_stVisualSet_
{   U64_tdxIndex    xLodLstId;
    unsigned short  uwLodLstNb;
    U64_tdxIndex    xRLIId;
}   U64_tdstVisualSet;

typedef struct U64_stLevelOfDetail_
{   float           fThreshold;
    U64_tdxIndex    xGeometricObjectId;
    unsigned short  uwPad;
}   U64_tdstLevelOfDetail;

typedef struct U64_stRliLst_
{   U64_tdxIndex    xLstIsiLstIndexId;
    unsigned short  uwIsiNb;
}   U64_tdstRliLst;

typedef struct U64_stArrayOfZdx_
{   U64_tdxIndex    xLstGeometricObjectId;
    unsigned short  uwGeometricObjectNb;
}   U64_tdstArrayOfZdx;

typedef struct U64_stZoo_
{   U64_tdxIndex    xGeometricObjectId;
    unsigned short  uwZoneType;
}   U64_tdstZoo;

#pragma pack(pop, u64align)

#define D_BINSCR_GeometricSymX        0
#define D_BINSCR_GeometricSymY        1
#define D_BINSCR_GeometricSymZ        2
#define D_BINSCR_GeometricSymNone     0xFFFF
#define D_BINSCR_GeometricSemiLookAt  0x0100

#define D_BINSCR_Sprite_2DScaled  1
#define D_BINSCR_Sprite_SemiLookAt 2
#define D_BINSCR_Sprite_UseMatrix 8

#define D_BINSCR_ZooZdr 1
#define D_BINSCR_ZooZde 2
#define D_BINSCR_ZooZdd 3
#define D_BINSCR_ZooZdm 4

#define D_BINSCR_StructGeometricObject       E_StructGeometricObject
#define D_BINSCR_StructGeometricObjectTemp   E_StructGeometricObjectTemp
#define D_BINSCR_StructIndirectGeoObjLst     E_StructIndirectGeoObjLst
#define D_BINSCR_StructVertex                E_StructVertex
#define D_BINSCR_StructNormal                E_StructNormal
#define D_BINSCR_StructEdge                  E_StructEdge
#define D_BINSCR_StructElementList           E_StructElementList
#define D_BINSCR_StructElementColList        E_StructElementColList
#define D_BINSCR_StructElementU64List        E_StructElementU64List
#define D_BINSCR_StructElementIndexedTriangles    E_StructElementIndexedTriangles
#define D_BINSCR_StructElementU64IndexedTriangles E_StructElementU64IndexedTriangles
#define D_BINSCR_StructElementTmpIndexedTriangles E_StructElementTmpIndexedTriangles
#define D_BINSCR_StructElementColIndexedTriangles E_StructElementColIndexedTriangles
#define D_BINSCR_StructElementPoints         E_StructElementPoints
#define D_BINSCR_StructLstPoints             E_StructLstPoints
#define D_BINSCR_StructElementSpheres        E_StructElementSpheres
#define D_BINSCR_StructLstSpheres            E_StructLstSpheres
#define D_BINSCR_StructElementAlignedBoxes   E_StructElementAlignedBoxes
#define D_BINSCR_StructLstAlignedBoxes       E_StructLstAlignedBoxes
#define D_BINSCR_StructElementCones          E_StructElementCones
#define D_BINSCR_StructLstCones              E_StructLstCones
#define D_BINSCR_StructElementSprites        E_StructElementSprites
#define D_BINSCR_StructElementSpritesList    E_StructElementSpritesList
#define D_BINSCR_StructSprite                E_StructSprite
#define D_BINSCR_StructSpriteInstance        E_StructSpriteInstance
#define D_BINSCR_StructElementAltimap        E_StructAltimap
#define D_BINSCR_StructAltimapSquare         E_StructAltimapSquare
#define D_BINSCR_StructAltimapFace           E_StructAltimapFace
#define D_BINSCR_StructAltimapVertex         E_StructAltimapVertex
#define D_BINSCR_StructAltimapUV             E_StructAltimapUV
#define D_BINSCR_StructVisualSet             E_StructVisualSet
#define D_BINSCR_StructLodLst                E_StructLodLst
#define D_BINSCR_StructRliLst                E_StructRliLst
#define D_BINSCR_StructLstIsiIndex           E_StructLstIsiIndex
#define D_BINSCR_StructISI                   E_StructISI
#define D_BINSCR_StructArrayOfZdx            E_StructArrayOfZdx
#define D_BINSCR_StructLstGeometricObject    E_StructLstGeometricObject
#define D_BINSCR_StructZoo                   E_StructZoo

#endif
