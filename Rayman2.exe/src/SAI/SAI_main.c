#include "SAI/SAI.h"
#include "ERM/CpaError.h"
#include "MMG/MMG_alloc.h"
#include "MMG/MMG_module.h"
#include "MMG/MMG_globals.h"

#define SAI_C_ulDefaultMaxNbMalloc  0x186a0

#define SAI_C_BlockFlags            0x0d
#define SAI_C_BlockAlignment        4

/* 0x00449f00 */
void __cdecl SAI_fn_vFirstInit(void)
{

    if (g_ucSAIModuleId == C_ucModuleNotInitialized)
        g_ucSAIModuleId = Erm_fn_ucInitErrMsg();

    Mmg_fn_v_InitMmg(g_ucSAIModuleId, 2, SAI_C_ulDefaultMaxNbMalloc);

    /* 0x403290 */
    Mmg_fn_cCheckAlignmentValidity();

    SAI_g_p_stInternalStructure->p_stFirstEntry = NULL;
    SAI_g_p_stInternalStructure->p_stLastEntry  = NULL;
}

/* 0x00449f40 */
void __cdecl SAI_fn_vInitFixMemory(unsigned long _ulMemSize)
{

    Mmg_fn_vInitSpecificBlock(E_ucSAIFixMemory,
                              *(unsigned int *)&g_ucSAIModuleId,
                              g_a_p_stMmgModuleBlocksInfo[*(unsigned int *)&g_ucSAIModuleId & 0xffu],
                              _ulMemSize, SAI_C_ulDefaultMaxNbMalloc,
                              SAI_C_BlockAlignment, SAI_C_BlockFlags);
}

/* 0x00449f70 */
void __cdecl SAI_fn_vInitLevelMemory(unsigned long _ulMemSize)
{

    Mmg_fn_vInitSpecificBlock(E_ucSAILevelMemory,
                              *(unsigned int *)&g_ucSAIModuleId,
                              g_a_p_stMmgModuleBlocksInfo[*(unsigned int *)&g_ucSAIModuleId & 0xffu],
                              _ulMemSize, SAI_C_ulDefaultMaxNbMalloc,
                              SAI_C_BlockAlignment, SAI_C_BlockFlags);
}

/* 0x00449fa0 */
void __cdecl SAI_fn_vDeleteLevelMemory(void)
{
    unsigned int uiModuleId;

    SAI_fn_vIsolateAllListEntryByMemoryLevel(SAI_g_p_stInternalStructure,
                                             E_ucSAILevelMemory);
    /* 0x4A1F6C */
    uiModuleId = *(unsigned int *)&g_ucSAIModuleId;

    Mmg_fn_vDeleteBlock(E_ucSAILevelMemory, uiModuleId,
                        g_a_p_stMmgModuleBlocksInfo[uiModuleId & 0xffu]);
}

/* 0x00449fd0 */
void __cdecl SAI_fn_vFreeLevelMemory(void)
{
    SAI_fn_vIsolateAllListEntryByMemoryLevel(SAI_g_p_stInternalStructure,
                                             E_ucSAILevelMemory);
}

/* 0x00449ff0 */
void __cdecl SAI_fn_vSAIUseFixMemory(void)
{
    SAI_g_ucMemoryBlockUsed = E_ucSAIFixMemory;
}

void __cdecl SAI_fn_vSAIUseLevelMemory(void)
{
    SAI_g_ucMemoryBlockUsed = E_ucSAILevelMemory;
}
