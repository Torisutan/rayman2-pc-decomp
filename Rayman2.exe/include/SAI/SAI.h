#pragma once

#include "SAI/SAI_types.h"

SAI_tdxHandleToListEntry __cdecl SAI_fn_hCreateAListEntry(void);
SAI_tdxHandleToListEntry __cdecl fn_hSearchAnElementInList(
    SAI_tdstInternalStructure *p_stInternalStructure,
    void *p_vData, SAI_tdeFlags eUserFlags);
unsigned char __cdecl SAI_fn_ucComputeBitPosition(unsigned char ucMask);
SAI_tdeFlags __cdecl SAI_fn_eVerifyFlags(SAI_tdeFlags eFlags);
unsigned char __cdecl SAI_fn_bInsertAnElementInList(
    SAI_tdstInternalStructure *p_stInternalStructure,
    void *p_stData, unsigned long ulSizeOfData,
    SAI_tdeFlags eTypeOfData, SAI_tdeFlags eUserFlags);

unsigned char __cdecl SAI_fn_bRestoreAnElementFromList(SAI_tdxHandleToListEntry hListEntry);
unsigned char __cdecl SAI_fn_bInitAllTableWhen(
    SAI_tdstInternalStructure *p_stInternalStructure, SAI_tdeFlags eUserFlags);

unsigned char __cdecl SAI_fn_bFreeAnElementFromList(
    SAI_tdstInternalStructure *p_stInternalStructure, void *p_stData, SAI_tdeFlags eUserFlags);

void __cdecl SAI_fn_vIsolateAllListEntryByMemoryLevel(
    SAI_tdstInternalStructure *p_stInternalStructure, unsigned char ucMemoryLevel);

void __cdecl SAI_fn_vFirstInit(void);
void __cdecl SAI_fn_vInitFixMemory(unsigned long _ulMemSize);
void __cdecl SAI_fn_vInitLevelMemory(unsigned long _ulMemSize);
void __cdecl SAI_fn_vDeleteLevelMemory(void);
void __cdecl SAI_fn_vFreeLevelMemory(void);
void __cdecl SAI_fn_vSAIUseFixMemory(void);
void __cdecl SAI_fn_vSAIUseLevelMemory(void);

#include <stdio.h>
unsigned char __cdecl SAI_fn_ucSaveAllGameTableValues(
    SAI_tdstInternalStructure *p_stInternalStructure, char *_p_cFileName, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_ucLoadAllGameTableValues(
    SAI_tdstInternalStructure *p_stInternalStructure, char *_p_cFileName, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_ucPlayerSaveValues(char *_szFileName);
unsigned char __cdecl SAI_fn_ucLevelSaveValues(char *_szFileName);
unsigned char __cdecl SAI_fn_ucLoadPlayerValues(char *_szFileName);

unsigned char __cdecl SAI_fn_bInsertCharInTable(void *_p_vValue, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_bInsertLongInTable(void *_p_vValue, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_bInsertFloatInTable(void *_p_vValue, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_bInsertPointerInTable(void *_p_vValue, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_bInsertArrayInTable(void *_p_vValue, unsigned long _ulSize, SAI_tdeFlags _eFlags);

unsigned char __cdecl SAI_fn_bInsertBoolInTable(void *_p_vValue, unsigned char ucMask, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_bInsertMTHVectorInTable(void *_p_vValue, SAI_tdeFlags _eFlags);
void *__cdecl SAI_fn_p_vGetTableValuePointerOf(void *_p_vValue, SAI_tdeFlags _eFlags);
unsigned char __cdecl SAI_fn_bInitAllWhen(SAI_tdeFlags _eUserFlags);
unsigned char __cdecl SAI_fn_bRemoveValueFromTable(void *_p_vValue, SAI_tdeFlags _eFlags);
