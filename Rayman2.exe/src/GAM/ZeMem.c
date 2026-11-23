#include "GAM/GAM_types.h"
#include "MMG/MMG_alloc.h"

extern void __cdecl Mmg_fn_cCheckAlignmentValidity(void);

/* 0x004077A0 */
void __cdecl fn_vFirstInitGameMemory(void)
{
    Mmg_fn_v_InitMmg(g_ucGameModuleId, 2, 0x186a0);
    Mmg_fn_cCheckAlignmentValidity();
}
