#pragma once

long __cdecl GLI_fnl_InitDll(void);

/* 0x00421810 */
extern long g_lGliInit;
long __cdecl GLI_xIsGliInit(void);

/* 0x00421800 */
void __cdecl GLI_vCloseGli(void);

/* 0x004011c0 */
void __cdecl GLI_FatalExitOrSleep(void);

int __cdecl GAM_pc_fn_bAreBothEventsIdle(void);

/* 0x00421670 */
void __cdecl GLI_xInitGli(void);
