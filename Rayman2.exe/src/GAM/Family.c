#include "GAM/Family.h"

tdxHandleToObjectsTablesList __cdecl fn_hGetObjectsTableOfFamilyByIndex(tdxHandleToFamilyList _hFamily, ACP_tdxIndex _xIndex)
{
    ACP_tdxIndex xForMacro = 0;
    tdxHandleToObjectsTablesList hTable;

    for (xForMacro = 0,
         hTable = (tdxHandleToObjectsTablesList)_hFamily->hForObjectsTablesList_first;
         xForMacro < _xIndex;
         xForMacro++,
         hTable = (tdxHandleToObjectsTablesList)hTable->_list_element)
    {
    }

    return hTable;
}
