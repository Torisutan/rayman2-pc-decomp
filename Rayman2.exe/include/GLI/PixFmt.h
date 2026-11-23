#pragma once

#include "ACP/ACP_types.h"

typedef struct GLD_stPixelFormat
{
    ACP_tdxIndex  xFormatNumber;
    ACP_tdxBool   bAlpha;
    long          lPixelNbBits;
    unsigned long ulPixelMask;
    long          lPixelNbBytes;
    long          lRedNbBits;
    long          lRedShift;
    unsigned long ulRedMask;
    long          lGreenNbBits;
    long          lGreenShift;
    unsigned long ulGreenMask;
    long          lBlueNbBits;
    long          lBlueShift;
    unsigned long ulBlueMask;
    long          lAlphaNbBits;
    long          lAlphaShift;
    unsigned long ulAlphaMask;
} GLD_tdstPixelFormat, *GLD_tdpstPixelFormat;

ACP_tdxBool __cdecl GLD_bGetPixelFormatOfDevice(GLD_tdpstPixelFormat p_stDstPixelFormat,
                                                short hDev, short hVP);
void __cdecl GLD_vBitmapConvert16bPixelFormat(GLD_tdpstPixelFormat p_stDstPixelFormat,
                                              GLD_tdpstPixelFormat p_stSrcPixelFormat,
                                              unsigned short *p_usBuffer, long lBufferSize);
void __cdecl GLD_vYInvertBitmap24b(unsigned char *p_ucBuffer, long lWidth, long lHeight);
void __cdecl GLD_vBitmapConvert24bTo16bPixelFormat(unsigned short *p_usDstBuffer,
                                                   unsigned char *p_ucSrcBuffer,
                                                   long lWidth, long lHeight);
void __cdecl GLD_vBitmapConvert24bTo16bPixelFormatAndFiltre(unsigned short *p_usDstBuffer,
                                                            long lWDst, long lHDst,
                                                            unsigned char *p_ucSrcBuffer,
                                                            long lWSrc, long lHSrc);
