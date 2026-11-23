#ifndef __MmgSai_h__
#define __MmgSai_h__










void SAI_fn_vMemoryLogFile(void *p_vPointer,unsigned char ucAction,char *szFile,unsigned long ulLine);


#define SAI_C_ActionMalloc  0
#define SAI_C_ActionRealloc 1
#define SAI_C_ActionFree    2


#define M_SAIChooseMemoryBlock() Mmg_M_SetModeAlloc4Ch(SAI,(unsigned char)SAI_g_ucMemoryBlockUsed,C_ucMmgDefaultChannel)


#if !defined(U64) && !defined(NITRO)
#define M_SAIAlloc(Var, cast, ucSize)\
{\
	M_SAIChooseMemoryBlock();\
	Var = (cast) Mmg_fn_p_vAlloc4Ch(ucSize,C_ucMmgDefaultChannel);\
 SAI_fn_vMemoryLogFile(Var,SAI_C_ActionMalloc,__FILE__,__LINE__); \
}
#endif

#endif
