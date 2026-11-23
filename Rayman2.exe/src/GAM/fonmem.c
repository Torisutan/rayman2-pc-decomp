#include "ERM/CpaError.h"
#include "MMG/MMG_alloc.h"
#include "MMG/MMG_module.h"
#include "MMG/MMG_globals.h"

extern void __cdecl Mmg_fn_cCheckAlignmentValidity(void);

/* 0x0049F6AC */
extern unsigned char g_ucFONModuleId;
static unsigned long gs_ulFontTextMemorySize;  /* 0x004A7108 */

/* 0x00419300 */
void FON_fn_vFirstInitFONMemory(unsigned long _ulFontTextMemorySize)
{
    if (g_ucFONModuleId == 0xFF)
        g_ucFONModuleId = Erm_fn_ucInitErrMsg();
    Mmg_fn_v_InitMmg(g_ucFONModuleId, 1, 100000);
    Mmg_fn_cCheckAlignmentValidity();

    Mmg_fn_vInitSpecificBlock(0, g_ucFONModuleId, g_a_p_stMmgModuleBlocksInfo[g_ucFONModuleId],
                              _ulFontTextMemorySize, 100000, 1, 0);

    gs_ulFontTextMemorySize = _ulFontTextMemorySize;
}

/* 0x00419360 */
void FON_fn_vDesinitFONMemory(void)
{
    Mmg_fn_vFreeBlock(0, g_ucFONModuleId, g_a_p_stMmgModuleBlocksInfo[g_ucFONModuleId]);
    Mmg_fn_vDeleteBlock(0, g_ucFONModuleId, g_a_p_stMmgModuleBlocksInfo[g_ucFONModuleId]);
}
