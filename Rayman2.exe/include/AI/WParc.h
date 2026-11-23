#ifndef RAYMAN2_AI_WPARC_H
#define RAYMAN2_AI_WPARC_H

#include "LST/LstDef2.h"

typedef struct WP_tdstGraphNode_ *WP_tdhGraphNode;
typedef struct WP_tdstWayArc_ *WP_tdHandleOfArc;
typedef struct WP_tdstListOfArc_ *WP_tdHandleOfListOfArc;

LST2_M_DynamicUseListOf(WP_tdHandleOfArc);

typedef struct WP_tdstListOfArc_ {
    LST2_M_DynamicAnchorDeclaration(WP_tdHandleOfArc) m_hArc;
} WP_tdstListOfArc;

typedef struct WP_tdstWayArc_ {
    LST2_M_DynamicElementDeclaration(WP_tdHandleOfArc)
    WP_tdhGraphNode m_hNode;
    unsigned long m_ulCapability;
    unsigned long m_ulCapabilityInit;
    long m_lWeight;
    long m_lWeightInit;
} WP_tdstWayArc;

WP_tdHandleOfListOfArc __cdecl WPARCLST_fn_hInit(void);
void __cdecl WPARCLST_fn_vAdd(WP_tdHandleOfListOfArc hListOfArc, WP_tdhGraphNode hNode,
                              long lWeight, unsigned long ulCapability);
long __cdecl WPARCLST_fn_lChangeCapabilities(WP_tdHandleOfListOfArc hListOfArc,
                                             WP_tdhGraphNode hNode,
                                             unsigned long ulCapability, long lValue);
WP_tdHandleOfArc __cdecl WPARC_CreateArc(WP_tdhGraphNode hNode, long lWeight,
                                         unsigned long ulCapability);
void __cdecl WPARCLST_fn_vDestroy(WP_tdHandleOfListOfArc hList);
void __cdecl WPARC_fn_vDestroyArc(WP_tdHandleOfArc hArc);

#endif
