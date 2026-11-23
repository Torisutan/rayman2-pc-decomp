#pragma once

#include <string.h>
#include "MMG/MMG_alloc.h"
#include "GEO/GEO_globals.h"

#define GEO_g_ucMmgMode           g_ucGEOMMemMallocMode  /* 0x0049fbc0 */

#define GEO_C_CanNotUseDynamic 0
#define GEO_C_CanUseDynamic    1
#define GEO_C_UseDynamic       2

#define E_ucDynamic 0xff

#define E_uwGEONotEnoughtMemory      1
#define E_uwGEODebugDynamicAllocation 8

#include "ERM/CpaError.h"
#define GEO_Erm_fn_vClearLastError(ch)  ERM_fn_vClearLastError(ch)
#define GEO_Erm_fn_vUpdateLastError(uwStart, ucModule, ulChannel, uwErr) \
    ERM_fn_vUpdateLastError((uwStart), (ucModule), (ulChannel), (uwErr), -1, 0xff, 0xff, NULL)

#define GEO_M_CPAMalloc(Var, cast, ulSize, error) \
    do { \
        if ((ulSize) != 0) { \
            if (GEO_g_bDynamicAllocation != GEO_C_UseDynamic) { \
                Mmg_fn_v_SetModeAlloc(g_ucGEOModuleId, GEO_g_ucMmgMode, 0); \
                (Var) = (cast)fn_p_vGenAlloc((unsigned long)(ulSize), 0); \
            } \
            if (GEO_g_bDynamicAllocation == GEO_C_UseDynamic || \
                (GEO_g_bDynamicAllocation == GEO_C_CanUseDynamic && (Var) == NULL)) { \
                GEO_Erm_fn_vClearLastError(0); \
                if (GEO_g_bDynamicAllocation == GEO_C_CanUseDynamic) { \
                    GEO_Erm_fn_vUpdateLastError(4, g_ucGEOModuleId, 0, E_uwGEODebugDynamicAllocation); \
                    GEO_Erm_fn_vClearLastError(0); \
                    GEO_g_bDynamicAllocation = GEO_C_UseDynamic; \
                } \
                Mmg_fn_v_SetModeAlloc(g_ucGEOModuleId, E_ucDynamic, 0); \
                (Var) = (cast)fn_p_vGenAlloc((unsigned long)(ulSize), 0); \
            } \
            if ((Var) == NULL) { \
                GEO_Erm_fn_vClearLastError(0); \
                GEO_Erm_fn_vUpdateLastError(4, g_ucGEOModuleId, 0, (error)); \
            } \
            memset((void *)(Var), 0, (ulSize)); \
        } \
    } while (0)
