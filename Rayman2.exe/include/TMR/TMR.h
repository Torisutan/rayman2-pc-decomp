#pragma once

#include "TMR/TMR_globals.h"

short __stdcall TMR_fn_wStartTimer(short wTimerHandle);
short __stdcall TMR_fn_wReadTimer(short wTimerHandle, stTimerCount *p_stTimerCount);
short __stdcall TMR_fn_wSetTimerValue(short wTimerHandle, stTimerCount *p_stValue);

short __stdcall TMR_fn_wCreateTimer(short wTimerType);
short __stdcall TMR_fn_wResetTimer(short wTimerHandle);
short __stdcall TMR_fn_wGetTimerFrequency(short wTimerHandle, unsigned long *p_ulFrequency);
