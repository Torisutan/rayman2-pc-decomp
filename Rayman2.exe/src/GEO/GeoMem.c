#include "GEO/GeoMem.h"
#include "ERM/CpaError.h"
#include "MMG/MMG_module.h"
#include "MMG/MMG_globals.h"
#include "MMG/MMG_alloc.h"

#define E_ucGEOMaxBlocksNb          5
#define E_uwGEOUnAvailableChannel   2

/* 0x00421870 */
extern void __cdecl GLI_pc_fn_vUnloadTexturesOfKeyWrapper(unsigned long ulKey);

extern void __cdecl FUN_00424fe0(unsigned int arg);

unsigned char g_ucGEOModuleId = 0xFF;

/* 0x0041BBE0 */
void __cdecl GEO_xInitGEOError(void)
{
    if (g_ucGEOModuleId == 0xff)
        g_ucGEOModuleId = Erm_fn_ucInitErrMsg();
    Mmg_fn_v_InitMmg(g_ucGEOModuleId, 5, 0x186a0);
    FUN_00424fe0(0xff);
    GEO_g_bDynamicAllocation = GEO_C_CanNotUseDynamic;
}

/* 0x0041BC20 */
void __cdecl GEO_xCreateMemoryChannel(unsigned char ucChannel, unsigned long ulSize)
{
    Mmg_fn_vInitSpecificBlock(ucChannel, g_ucGEOModuleId, g_a_p_stMmgModuleBlocksInfo[g_ucGEOModuleId],
                              ulSize, 300000, 1, 0);
}

/* 0x0041BCB0 */
void __cdecl GEO_xDeleteMemoryChannel(unsigned long ulChannel)
{
    unsigned char ucChannel = (unsigned char)ulChannel;

    if ((E_ucGEOMaxBlocksNb < ucChannel) && (ucChannel != E_ucDynamic))
    {
        ERM_fn_vClearLastError(C_ucErmDefaultChannel);
        ERM_fn_vUpdateLastError(4, g_ucGEOModuleId, C_ucErmDefaultChannel,
                                E_uwGEOUnAvailableChannel, -1, C_ucErmOpenInfoWindow,
                                0xFF, "Malloc allocation");
    }

    GLI_pc_fn_vUnloadTexturesOfKeyWrapper(ulChannel);
    Mmg_fn_vDeleteBlock(ucChannel, g_ucGEOModuleId, g_a_p_stMmgModuleBlocksInfo[g_ucGEOModuleId]);
}
