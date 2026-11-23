#pragma once

void __cdecl TMR_pc_fn_vReadTSC(unsigned __int64 *p_uOut);
void __cdecl TMR_pc_fn_vSetupTimerPeriod(void);
unsigned long __cdecl TMR_pc_fn_ulCalibrateTscFreq(void);    /* 0x0045e640 */
