#ifndef BLC_WAYPOINT_H
#define BLC_WAYPOINT_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stWay_
{   U64_tdxIndex    xLstWaypointIndexId;
    U64_tdxIndex    xLstWayLinkIndexId;
    unsigned short  uwLstWaypointIndexNb;
    unsigned short  uwLstWayLinkIndexNb;
}   U64_tdstWay;

typedef struct U64_stWayLink_
{   float           a3_fValues[3];
    U64_tdxIndex    a4_xVectorId[4];
    unsigned char   ucType;
    unsigned char   ucDynType;
    unsigned char   ucSamplingRate;
    unsigned char   ucPad;
}   U64_tdstWayLink;

typedef struct U64_stWayLst_
{   U64_tdxIndex    xLstWayLstIndexId;
    unsigned short  uwLstWayLstIndexNb;
}   U64_tdstWayLst;

typedef struct U64_stWaypoint_
{
    short                 sRadius;
    U64_tdstShortVector3D stVertex;
    U64_tdxIndex          xFatherId;
}   U64_tdstWaypoint;

typedef struct U64_stWayGraph_
{   U64_tdxIndex    xLstOfNodeIndexId;
    unsigned short  uwLstOfNodeIndexNb;
}   U64_tdstWayGraph;

typedef struct U64_stWayGraphNode_
{
    U64_tdxIndex    xDstWaypointIndexId;
    U64_tdxIndex    xLstOfNodeId;
    U64_tdxIndex    xLstCapacityId;
    U64_tdxIndex    xLstValuationId;
    unsigned short  uwLstOfNodeNb;
    U64_tdxIndex    xTypeOfWPId;
}   U64_tdstWayGraphNode;

#pragma pack(pop, u64align)

#define D_BINSCR_RefSectionNameLength 64

#define D_BINSCR_WayLink_StaticLine  1
#define D_BINSCR_WayLink_DynamicLine 2
#define D_BINSCR_WayLink_Bezier      3
#define D_BINSCR_WayLink_Circle      4
#define D_BINSCR_WayLink_None        1
#define D_BINSCR_WayLink_Constant    2
#define D_BINSCR_WayLink_Linear      3
#define D_BINSCR_WayLink_Sinus       4

#define D_BINSCR_StructWay                E_StructWay
#define D_BINSCR_StructWayLink            E_StructWayLink
#define D_BINSCR_StructWayLinkVector      E_StructWayLinkVector
#define D_BINSCR_StructLstWaypointIndex   E_StructLstWaypointIndex
#define D_BINSCR_StructLstWayLinkIndex    E_StructLstWayLinkIndex
#define D_BINSCR_StructWayLst             E_StructWayLst
#define D_BINSCR_StructLstWayLstIndex     E_StructLstWayLstIndex
#define D_BINSCR_StructWaypoint           E_StructWaypoint
#define D_BINSCR_StructWayGraph           E_StructWayGraph
#define D_BINSCR_StructWayGraphNode       E_StructWayGraphNode
#define D_BINSCR_StructLstOfNodeIndex     E_StructLstNodeIndex
#define D_BINSCR_StructLstOfCapacity      E_StructLstCapacity
#define D_BINSCR_StructLstOfValuation     E_StructLstValuation
#define D_BINSCR_StructTypeOfWP           D_BINSCR_StructLstOfCapacity
#define D_BINSCR_StructNoCtrlList         E_StructLstNodeIndex

#endif
