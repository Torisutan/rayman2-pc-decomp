#define D_TMR_VariableDefine
#include "TMR/TMR_globals.h"

TMR_tdstTimer  TMR_a_stTimerTab_storage[16];
unsigned short TMR_g_p_wTimerCount_storage;
unsigned long  TMR_a3_ulTimerFrequency_storage[3];
unsigned long  a3_ulEventFrequency[3];                /* 0x00516180 */
/* 0x004A3FE4 */
unsigned char g_ucTmrModuleId = 0xff;
