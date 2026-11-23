#include <string.h>
#include "ALW/ALW.h"
#include "GAM/ObjsTbls.h"
#include "GAM/PlayAnim.h"

/* 0x004193A0 */
void __cdecl fn_vExchangeTwoObjectsInCurrentObjectsTable(HIE_tdxHandleToSuperObject p_stSuperObject,
                                                         unsigned short w_ObjectA, unsigned short w_ObjectB)
{
    struct tdstObjectsTableElement_ stObjectsTableElement;

    if (fn_h3dDataGetCurrentObjectsTable(M_GetMSHandle(p_stSuperObject, 3dData)) == NULL) return;

    memcpy(&stObjectsTableElement,
           &(fn_h3dDataGetCurrentObjectsTable(M_GetMSHandle(p_stSuperObject, 3dData))->d_stObjectsTable[w_ObjectB]),
           sizeof(struct tdstObjectsTableElement_));

    memcpy(&(fn_h3dDataGetCurrentObjectsTable(M_GetMSHandle(p_stSuperObject, 3dData))->d_stObjectsTable[w_ObjectB]),
           &(fn_h3dDataGetCurrentObjectsTable(M_GetMSHandle(p_stSuperObject, 3dData))->d_stObjectsTable[w_ObjectA]),
           sizeof(struct tdstObjectsTableElement_));

    memcpy(&(fn_h3dDataGetCurrentObjectsTable(M_GetMSHandle(p_stSuperObject, 3dData))->d_stObjectsTable[w_ObjectA]),
           &stObjectsTableElement,
           sizeof(struct tdstObjectsTableElement_));
}

/* 0x00419420 */
void __cdecl fn_vCopyObjectFromObjectTabletoAnother(tdxHandleToObjectsTablesList _hTargetTable,
                                                    tdxHandleToObjectsTablesList _hSourceTable,
                                                    unsigned short _uwTargetObject,
                                                    unsigned short _uwSourceObject)
{
    if (_hTargetTable == NULL || _hSourceTable == NULL) return;

    _hTargetTable->d_stObjectsTable[_uwTargetObject] = _hSourceTable->d_stObjectsTable[_uwSourceObject];
}

/* 0x00419460 */
unsigned short __cdecl fn_uwGetObjectTableNumberOfelements(tdxHandleToObjectsTablesList _hTargetTable)
{
    if (_hTargetTable)
        return _hTargetTable->wNumberOfElement;
    else
        return 0;
}

#define C_wObjectTableHasZde 0x0002
ACP_tdxBool __cdecl fn_bObjectTableHasZde(tdxHandleToObjectsTablesList _hObjectTableList)
{
    return (ACP_tdxBool) ((_hObjectTableList -> wZDxUsed & C_wObjectTableHasZde) != 0);
}
