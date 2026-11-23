#pragma once

#include "ACP/ACP_types.h"
#include "GAM/ObjsTbls.h"

struct tdstFamilyList_;

typedef struct tdstFamilyListAnchor_
{
    struct tdstFamilyList_ *hFirstElementDyn;
    struct tdstFamilyList_ *hLastElementDyn;
    long                    lNumberOfElementsDyn;
} tdstFamilyListAnchor;

typedef struct tdstFamilyList_
{
    struct tdstFamilyList_       *hNextBrother;
    struct tdstFamilyList_       *hPrevBrother;
    tdstFamilyListAnchor         *hFather;
    long                          lObjectFamilyType;
    void                         *hForStateArray_first;
    void                         *hForStateArray_last;
    long                          hForStateArray_count;
    tdxHandleToObjectsTablesList  h_DefaultObjectsTable;
    void                         *hForObjectsTablesList_first;
    void                         *hForObjectsTablesList_last;
    long                          hForObjectsTablesList_count;
    void                         *hBoundingSphere;
    unsigned long                 ulNumberOfChannels;
    unsigned char                 ucPriority;
    unsigned char                 ucOptimized;
} tdstFamilyList;

typedef tdstFamilyList *tdxHandleToFamilyList;

/* 0x00407AB0 */
tdxHandleToObjectsTablesList __cdecl fn_hGetObjectsTableOfFamilyByIndex(tdxHandleToFamilyList _hFamily, ACP_tdxIndex _xIndex);
