#pragma once

void __cdecl GLD_vSetDefinedPixelFormat(unsigned long *p_uDst, short iIdx);
void __cdecl GLD_vCopyPixelFormat(unsigned long *p_uDst, const unsigned long *p_uSrc);
int  __cdecl FUN_0042c6e0(void);
void __cdecl FUN_0042c780(void);

/* 0x0042b6f0 */
void *__cdecl GLD_fn_p_stGetDefinedPixelFormat(unsigned long ulIndex);
long  __cdecl GLD_fn_lAddDefinedPixelFormat(void *p_stFormat);

/* 0x0042c250 */
struct GLI_tdstTexture;
unsigned long __cdecl GLI_pc_ulVerifyTextureIsReallyAlpha(struct GLI_tdstTexture *p_stTexture);
