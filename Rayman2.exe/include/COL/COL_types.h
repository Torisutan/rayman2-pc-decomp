#pragma once

#include "MTH/MTH_types.h"
#include "COL/COL_globals.h"

typedef unsigned char  COL_tdxFaceIndex;
typedef unsigned short COL_tdxFaceIndexDouble;

#define COL_C_xMaxSelectedNodes 100
#define COL_C_MaxIndex          0x0080
#define COL_C_OverflowIndex     0x8000

typedef struct COL_tdstOctreeNode_ {
    MTH3D_tdstVector               stMinPart;
    MTH3D_tdstVector               stMaxPart;
    struct COL_tdstOctreeNode_   **p_pstChildList;
    COL_tdxFaceIndex              *d_xFaceIndexList;
} COL_tdstOctreeNode, *COL_tdpstOctreeNode;

struct COL_tdstOctree_ {
    COL_tdpstOctreeNode      p_stOctreeRoot;
    short                    xNbFaces;

    COL_tdxFaceIndexDouble  *d_xElementBasesTable;
    MTH3D_tdstVector         stMinBoundingBox;
    MTH3D_tdstVector         stMaxBoundingBox;
};
