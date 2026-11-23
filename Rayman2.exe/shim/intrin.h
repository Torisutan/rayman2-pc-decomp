#ifndef _VC5MATCH_INTRIN_H
#define _VC5MATCH_INTRIN_H

unsigned __int64 __rdtsc(void);
void             __cpuid(int a_iCpuInfo[4], int iFunctionId);
void *           _AddressOfReturnAddress(void);

#endif
