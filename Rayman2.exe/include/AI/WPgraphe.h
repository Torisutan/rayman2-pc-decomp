#ifndef RAYMAN2_AI_WPGRAPHE_H
#define RAYMAN2_AI_WPGRAPHE_H

#include "LST/LstDef2.h"
#include "AI/WParc.h"

#include "AI/WP_Handl.h"

LST2_M_DynamicUseListOf(WP_tdhGraphNode);

typedef struct WP_tdstGraph_ {
    LST2_M_DynamicAnchorDeclaration(WP_tdhGraphNode) m_hListOfNode;
} WP_tdstGraph;

typedef struct WP_tdstGraphNode_ {
    LST2_M_DynamicElementDeclaration(WP_tdhGraphNode)
    WP_tdhWayPoint m_hWayPoint;
    long m_lTypeOfWP;
    long m_lTypeOfWPInit;
    WP_tdHandleOfListOfArc m_hListOfArc;
} WP_tdstGraphNode;

void __cdecl WPG_fn_vReinitGraph(WP_tdHandleOfGraph hGraph);   /* 0x0047F920 */
void __cdecl WPG_fn_vDestroy(WP_tdHandleOfGraph hGraph);                     /* 0x0047F5E0 */
WP_tdhGraphNode __cdecl WPG_fn_hCreateNode(WP_tdhWayPoint hWayPoint, long lTypeOfWP); /* 0x00480070 */
void __cdecl WPG_fn_vDestroyNode(WP_tdhGraphNode hNode);                     /* 0x004800E0 */
void __cdecl WPG_fn_vAddArc(WP_tdhGraphNode hSrcNode, WP_tdhGraphNode hDstNode,
                            unsigned long ulCapability, long lWeight);       /* 0x00480120 */
long __cdecl WPG_fn_lAddWayPoint(WP_tdHandleOfGraph hGraph, WP_tdhWayPoint hWayPoint,
                                 long lTypeOfWP);                            /* 0x0047F680 */
long __cdecl WPG_fn_lAddArcToWayPoint(WP_tdHandleOfGraph hGraph, WP_tdhWayPoint hSrcWayPoint,
                                      WP_tdhWayPoint hDstWayPoint, long lWeight,
                                      unsigned long ulCapability);            /* 0x0047F730 */

#endif
