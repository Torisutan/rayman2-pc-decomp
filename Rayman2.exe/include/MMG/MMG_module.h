#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void __cdecl Mmg_fn_v_StopMmg(unsigned char ucModuleId);

/* 0x00442650 */
void __cdecl Mmg_fn_vDeleteBlock(unsigned char ucBlockId,
                                 unsigned char ucModuleId,
                                 void         *p_stMyBlocksInfo);

void __cdecl Mmg_fn_vFreeBlock(unsigned char ucBlockId,
                               unsigned char ucModuleId,
                               void         *p_stMyBlocksInfo);

void __cdecl Mmg_fn_vReleaseChannelId(unsigned char ucChannelId);

void *__cdecl Mmg_fn_p_vGiveTheBeginingAddress(unsigned short uwModuleBlockId);

void __cdecl Mmg_fn_vTestMallocIntegrityAt(void *p_vMemBlock);

/* 0x00403290 */
void __cdecl Mmg_fn_cCheckAlignmentValidity(void);

#ifdef __cplusplus
}
#endif
