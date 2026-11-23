#pragma once

#include <stdint.h>
#include "FIL/File.h"

void __cdecl GLI_DivideBitmapSurfaceBy2(uint32_t *pSrc,
                                        uint32_t *pDst,
                                        int lWidth,
                                        int lHeight);

void __cdecl GLI_DivideBitmapSurfaceBy2NonZero(uint32_t *pSrc,
                                               uint32_t *pDst,
                                               int lWidth,
                                               int lHeight,
                                               uint32_t ulChroma);

/* 0x00425b50 */
void __cdecl GLI_pc_fn_vDownscalePairs32_ChromaH(uint32_t *pSrc,
                              uint32_t *pDst,
                              int lWidth,
                              int lHeight,
                              uint32_t ulChroma);

/* 0x00425be0 */
void __cdecl GLI_pc_fn_vDownscaleRows32_ChromaV(uint32_t *pSrc,
                              uint32_t *pDst,
                              int lWidth,
                              int lHeight,
                              uint32_t ulChroma);

/* 0x00425f40 */
void __cdecl GLI_pc_fn_vExpandPixelsBy2_32(uint32_t *pBuffer, int lHeight, int lWidth);

/* 0x00425fa0 */
void __cdecl GLI_pc_fn_vExpandRows32A(uint32_t *pBuffer, int lHeight, int lWidth);

/* 0x00426000 */
void __cdecl GLI_pc_fn_vExpandRows32B(uint32_t *pBuffer, int lHeight, int lWidth);

/* 0x004251c0 */
void __cdecl GLI_pc_fn_vReplaceLowAlphaPixels(uint32_t *pPixels,
                              int lHeight,
                              int lWidth,
                              uint32_t ulReplacement);

/* 0x00425200 */
void __cdecl GLI_pc_fn_vApplyColorKeyAlpha(uint32_t *pPixels,
                              int lHeight,
                              int lWidth,
                              uint32_t ulKey);

/* 0x004254b0 */
void __cdecl GLI_pc_fn_vColorKeyNeighborhoodPassA(uint32_t *pPixels,
                              uint32_t  ulWidth,
                              int       lHeight,
                              uint32_t  ulKey);

/* 0x00425240 */
void __cdecl GLI_pc_fn_vColorKeyNeighborhoodPassB(int hTexture, uint32_t ulBuffer);

/* 0x00426050 */
void __cdecl GLI_pc_fn_vLoadTextureSourceA(void *p_stTexture, char *p_szFileName, uint32_t *pBuffer);

/* 0x00426320 */
void __cdecl GLI_pc_fn_vLoadTextureSourceB(void *p_stTexture, char *p_szFileName, uint32_t *pBuffer);

/* 0x00425d10 */
void __cdecl GLI_DivideBitmapSurfaceBy2Palette(unsigned char *pIndexBuffer,
                                               unsigned char *pPalette,
                                               int            lStride,
                                               int            lHeight);

/* 0x00493a40 */
void __cdecl FIL_LoadGFLikeImageToRecord(void     *hConcatFile,
                                         char     *p_szPath,
                                         char     *p_szFilename,
                                         FIL_tdstGF *pGF);

/* 0x0045f030 */
void __cdecl GLI_BlendPixelIntoUiSurface(int p_stUiObject,
                                         int x,
                                         int y,
                                         float *p_xBlendDesc);

/* 0x0045f530 */
void __cdecl GLI_FillProgressBarSpan(int ui_object,
                                     unsigned int old_progress,
                                     unsigned int new_progress);

/* 0x0045f420 */
void __cdecl GLI_DrawProgressBarFrameAndFill(int ui_object);

/* 0x0045f7e0 */
unsigned int __cdecl GLI_AddToProgressBar(int lIncrement);

/* 0x0045eed0 */
void __cdecl GLI_RefreshUiSurfaceIfVisible(char *ui_object);

/* 0x0045efb0 */
void __cdecl GLI_RefreshUiSurfaceUnsynchronized(char *ui_object);

/* 0x00426550 */
void __cdecl GLI_xLoadTextureInTexelField(void *p_stTexture,
                                          uint32_t *pBuffer,
                                          int bHideProgress);
