#pragma once

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

unsigned long __cdecl fn_ulTimerEventTickPerSecond(short channel);

void          __cdecl fn_vTimerGetCounter(short channel, LARGE_INTEGER *p);
unsigned long __cdecl TMR_pc_fn_bHasCPUID(void);
unsigned long __cdecl TMR_pc_fn_ulGetCPUSignature(void);
unsigned long __cdecl TMR_pc_fn_ulReadCpuVendorString(void);  /* 0x45e9e0 */
int           __cdecl TMR_pc_fn_bIsTscUsableForVendor(void);  /* 0x45ea20 */
/* 0x45e8a0 */
unsigned long __cdecl fn_ulTimerTickPerSecond(short sChannel);

/* 0x45ddc0 */
short         __cdecl TMR_fn_wInitLibrary(void);
