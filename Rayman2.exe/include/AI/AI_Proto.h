#ifndef AI_PROTO_H
#define AI_PROTO_H

void __cdecl fn_vReinitAIComport(AI_tdstMind *p_stMind);
void __cdecl ReinitDesignerVariables(AI_tdstMind *p_stMind);

/* 0x00466730 */
AI_tdstMind *__cdecl fn_pstAllocMind(void);

/* 0x00466ED0 */
void __cdecl fn_vSimulateMindAllocationFromAnotherMind(AI_tdstMind *p_stMindSrc,
                                                       AI_tdstMind *p_stMindDst);

/* 0x00403290 */
void __cdecl AI_fn_vMemoryLogFile(void *, unsigned char, char *, unsigned long);

/* 0x00403290 */
void __cdecl fn_vSecondPassOfMindLoading(AI_tdstMind *p_stMind, unsigned char _bPersoInFix,
                                         unsigned long _eObjectInit);

#endif
