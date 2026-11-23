#pragma once

#include "MTH/MTH_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define C_wTdO_Undefined        0xffff
#define C_wTdO_PhysicalObject   0
#define C_wTdO_Animation        1
#define C_wTdO_Light            2
#define C_wTdO_Camera           3
#define C_wTdO_Mirror           4
#define C_wTdO_Event            5

typedef struct tdstObjectsTableElement_
{
    MTH3D_tdstVector *p_stCustomZoom;
    void             *h_Target;
    unsigned long     uwChannelNumber;
    unsigned short    wTypeOfTarget;
    unsigned char     ucPhoneme;
    unsigned char     ucIntensity;
    unsigned char     ucExpression;
    unsigned char     _pad11[3];
} tdstObjectsTableElement;

typedef struct tdstObjectsTablesList_
{
    void                    *_list_element;
    tdstObjectsTableElement *d_stObjectsTable;
    tdstObjectsTableElement *d_stInitObjectsTable;
    unsigned short           wNumberOfElement;
    unsigned short           wZDxUsed;
} tdstObjectsTablesList;

typedef tdstObjectsTablesList *tdxHandleToObjectsTablesList;

/* 0x00419420 */
void __cdecl fn_vCopyObjectFromObjectTabletoAnother(tdxHandleToObjectsTablesList _hTargetTable, tdxHandleToObjectsTablesList _hSourceTable, unsigned short _uwTargetObject, unsigned short _uwSourceObject);

/* 0x00419460 */
unsigned short __cdecl fn_uwGetObjectTableNumberOfelements(tdxHandleToObjectsTablesList _hTargetTable);

#ifdef __cplusplus
}
#endif
