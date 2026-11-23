#pragma once

#include <stdint.h>

#include "MMG/MMG_alloc.h"

/* 0x0045dc60 */
void *__cdecl GLI_pc_fn_p_vAlloc(uint32_t ulSize);

/* 0x0045dce0 */
void __cdecl GLI_pc_fn_vFree(void **ppUser);

/* 0x00492d80 */
void __cdecl GLI_pc_fn_vFreeIfNotNull(void **ppUser);

/* 0x00419650 */
void __cdecl GLI_pc_v_vTmpFree(void *pUser);
