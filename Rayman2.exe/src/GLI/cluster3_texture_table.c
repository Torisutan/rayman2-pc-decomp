#include "GLI/cluster3_texture_table.h"
#include "GLI/GLI_globals.h"
#include "GLI/GLD.h"
#include "GLI/PixFmt.h"
#include <string.h>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

/* 0x4A0808 */
static unsigned long GLI_pc_aulDefinedPixelFormatTable[16 * 16] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000001, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x00000000, 0x0000001f, 0x00000005, 0x00000005, 0x000003e0, 0x00000005, 0x0000000a, 0x00007c00, 0x00000000, 0x00000000, 0x00000000,
    0x00010002, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x00000000, 0x0000001f, 0x00000005, 0x00000005, 0x000003e0, 0x00000005, 0x0000000a, 0x00007c00, 0x00000001, 0x0000000f, 0x00008000,
    0x00000003, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x0000000a, 0x00007c00, 0x00000005, 0x00000005, 0x000003e0, 0x00000005, 0x00000000, 0x0000001f, 0x00000000, 0x00000000, 0x00000000,
    0x00010004, 0x00000010, 0x0000ffff, 0x00000002, 0x00000004, 0x00000000, 0x0000000f, 0x00000004, 0x00000004, 0x000000f0, 0x00000004, 0x00000008, 0x00000f00, 0x00000004, 0x0000000c, 0x0000f000,
    0x00000005, 0x00000018, 0x00ffffff, 0x00000003, 0x00000008, 0x00000000, 0x000000ff, 0x00000008, 0x00000008, 0x0000ff00, 0x00000008, 0x00000010, 0x0000ff00, 0x00000000, 0x00000000, 0x00000000,
    0x00010006, 0x00000020, 0xffffffff, 0x00000004, 0x00000008, 0x00000000, 0x000000ff, 0x00000008, 0x00000008, 0x0000ff00, 0x00000008, 0x00000010, 0x0000ff00, 0x00000008, 0x00000018, 0xff000000,
    0x00000007, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x00000000, 0x0000001f, 0x00000006, 0x00000005, 0x000007e0, 0x00000005, 0x0000000b, 0x0000f800, 0x00000000, 0x00000000, 0x00000000,
    0x00000008, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x00000000, 0x0000001f, 0x00000005, 0x00000005, 0x000003e0, 0x00000006, 0x0000000a, 0x0000fc00, 0x00000000, 0x00000000, 0x00000000,
    0x00000009, 0x00000010, 0x0000ffff, 0x00000002, 0x00000006, 0x00000000, 0x0000002f, 0x00000005, 0x00000006, 0x000007c0, 0x00000005, 0x0000000b, 0x0000f800, 0x00000000, 0x00000000, 0x00000000,
    0x0001000a, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x00000001, 0x0000003e, 0x00000005, 0x00000006, 0x000007c0, 0x00000005, 0x0000000b, 0x0000f800, 0x00000001, 0x00000000, 0x00000001,
    0x0000000b, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x0000000b, 0x0000f800, 0x00000006, 0x00000005, 0x000007e0, 0x00000005, 0x00000000, 0x0000001f, 0x00000000, 0x00000000, 0x00000000,
    0x0000000c, 0x00000010, 0x0000ffff, 0x00000002, 0x00000006, 0x0000000a, 0x0000fc00, 0x00000005, 0x00000005, 0x000003e0, 0x00000005, 0x00000000, 0x0000001f, 0x00000000, 0x00000000, 0x00000000,
    0x0000000d, 0x00000010, 0x0000ffff, 0x00000002, 0x00000005, 0x0000000b, 0x0000f800, 0x00000005, 0x00000006, 0x000007c0, 0x00000006, 0x00000000, 0x0000002f, 0x00000000, 0x00000000, 0x00000000,
};
static short         GLI_pc_wNbDefinedPixelFormat = 14;
typedef struct { unsigned long aul[16]; } GLI_pc_stPixFmtRec;
#define GLI_PC_PIXFMT_TABLE  ((char *)GLI_pc_aulDefinedPixelFormatTable)
#define GLI_PC_PIXFMT_COUNT  GLI_pc_wNbDefinedPixelFormat

void __cdecl GLD_vSetDefinedPixelFormat(unsigned long *p_uDst, short iIdx)
{
    GLI_pc_stPixFmtRec *p_stSrc = (GLI_pc_stPixFmtRec *)(GLI_PC_PIXFMT_TABLE + (int)iIdx * 0x40);
    GLI_pc_stPixFmtRec *p_stDst = (GLI_pc_stPixFmtRec *)p_uDst;
    *p_stDst = *p_stSrc;
}

void __cdecl GLD_vCopyPixelFormat(unsigned long *p_uDst, const unsigned long *p_uSrc)
{
    memcpy(p_uDst, p_uSrc, 16 * 4);
}

void * __cdecl GLD_fn_p_stGetDefinedPixelFormat(unsigned long ulIndex)
{

    if (ulIndex >= (unsigned long)(long)GLI_PC_PIXFMT_COUNT)
        return NULL;
    return (void *)(GLI_PC_PIXFMT_TABLE + ulIndex * 0x40);
}

long __cdecl GLD_fn_lAddDefinedPixelFormat(void *p_stFormat)
{
    short wCount = GLI_PC_PIXFMT_COUNT;

    if (wCount == 0x10) {
        return -1;
    }
    *(short *)p_stFormat = wCount;
    GLD_vCopyPixelFormat((unsigned long *)(GLI_PC_PIXFMT_TABLE + (int)GLI_PC_PIXFMT_COUNT * 0x40),
                 (const unsigned long *)p_stFormat);
    GLI_PC_PIXFMT_COUNT++;   /* 0x004A0C08 */
    return *(short *)p_stFormat;
}

#include "GLI/GLI_types.h"
unsigned long __cdecl GLI_pc_ulVerifyTextureIsReallyAlpha(GLI_tdstTexture *p_stTexture)
{
    unsigned long  ulAlpha = 0xFF000000u;
    unsigned int   uiCount  = (unsigned int)p_stTexture->uwHeight * (unsigned int)p_stTexture->uwWidth;

    if (uiCount > 0) {
        unsigned long *pulTexel = (unsigned long *)p_stTexture->p_vBitMap;
        do {
            ulAlpha &= *pulTexel++;
        } while (--uiCount != 0);
    }
    return ulAlpha;
}

int __cdecl FUN_0042c6e0(void)
{
    typedef int (__cdecl *pfn_GetSize)(void *);
    int   lTotal = 0;
    int   i;

    for (i = 0; i < 0x400; i++) {
        unsigned long ulKey = GLI_gs_aDEFTableOfTextureMemoryChannels[i];
        GLI_tdstTexture *p_stTex = GLI_gs_aDEFTableOfTextureAlreadyRead[i];

        if (ulKey != 0xC0DE0005ul && p_stTex != NULL) {
            /* 0x00504824 */
            lTotal += ((pfn_GetSize)*(pfn_GetSize *)GLI_DRV_lGetSizeOfTexture)(p_stTex);
        }
    }
    return lTotal;
}

unsigned long __cdecl GLI_pc_fn_vTrackMaxTextureBytes(void)
{
    int i;
    int lMax = 0;

    for (i = 0; i < 0x400; i++) {
        if (GLI_gs_aDEFTableOfTextureMemoryChannels[i] != 0xC0DE0005ul) {
            GLI_tdstTexture *p_stTex = GLI_gs_aDEFTableOfTextureAlreadyRead[i];

            if (p_stTex != NULL) {
                int lPixels = (int)p_stTex->uwRealHeight * (int)p_stTex->uwRealWidth;
                int lBytes = lPixels * 6;

                if ((p_stTex->ulTextureCaps & GLI_C_Tex_lMAATexture) != 0) {
                    lBytes += lBytes;
                }
                if (lMax < lBytes) {
                    lMax = lBytes;
                }
            }
        }
    }
    return (unsigned long)lMax;
}

void __cdecl FUN_0042c780(void)
{
    int i;
    for (i = 0; i < 0x400; i++) {
        unsigned long ulKey = GLI_gs_aDEFTableOfTextureMemoryChannels[i];
        GLI_tdstTexture *p_stTex;

        if (ulKey == 0xC0DE0005ul) continue;

        p_stTex = GLI_gs_aDEFTableOfTextureAlreadyRead[i];
        if (p_stTex == NULL) continue;

        p_stTex->uwHeight = p_stTex->uwRealHeight;

        p_stTex = GLI_gs_aDEFTableOfTextureAlreadyRead[i];
        p_stTex->uwWidth = p_stTex->uwRealWidth;

        p_stTex = GLI_gs_aDEFTableOfTextureAlreadyRead[i];
        p_stTex->ulCompressionCounter = 0;
    }
}

#include "GLI/devinfo.h"

ACP_tdxBool __cdecl GLD_bGetPixelFormatOfDevice(GLD_tdpstPixelFormat p_stDstPixelFormat,
                                                short hDev, short hVP)
{
    (void)hVP;
    if (GLD_pc_pGetDevice(hDev) == NULL) {
        return 0;
    }
    GLD_vSetDefinedPixelFormat((unsigned long *)p_stDstPixelFormat, (short)GLI_pc_g_stGliCaps.ucPrimarySurfacePixelFormat);
    return 1;
}

void __cdecl GLD_vBitmapConvert16bPixelFormat(GLD_tdpstPixelFormat p_stDstPixelFormat,
                                              GLD_tdpstPixelFormat p_stSrcPixelFormat,
                                              unsigned short *p_usBuffer, long lBufferSize)
{
    if (p_stDstPixelFormat->xFormatNumber != p_stSrcPixelFormat->xFormatNumber) {
        long lSrcRedBits   = 8 - p_stSrcPixelFormat->lRedNbBits;
        long lSrcBlueBits  = 8 - p_stSrcPixelFormat->lBlueNbBits;
        long lDstRedBits   = 8 - p_stDstPixelFormat->lRedNbBits;
        long lSrcGreenBits = 8 - p_stSrcPixelFormat->lGreenNbBits;
        long lDstGreenBits = 8 - p_stDstPixelFormat->lGreenNbBits;
        long lDstBlueBits  = 8 - p_stDstPixelFormat->lBlueNbBits;
        unsigned short *p_usEnd = p_usBuffer + lBufferSize / 2;

        for (; p_usBuffer < p_usEnd; p_usBuffer++) {
            unsigned short usPix = *p_usBuffer;
            *p_usBuffer = (unsigned short)(
                ((unsigned short)(((usPix & (unsigned short)p_stSrcPixelFormat->ulGreenMask)
                    >> p_stSrcPixelFormat->lGreenShift) << lSrcGreenBits)
                    >> lDstGreenBits) << p_stDstPixelFormat->lGreenShift
              | ((unsigned short)(((usPix & (unsigned short)p_stSrcPixelFormat->ulBlueMask)
                    >> p_stSrcPixelFormat->lBlueShift) << lSrcBlueBits)
                    >> lDstBlueBits) << p_stDstPixelFormat->lBlueShift
              | ((unsigned short)(((usPix & (unsigned short)p_stSrcPixelFormat->ulRedMask)
                    >> p_stSrcPixelFormat->lRedShift) << lSrcRedBits)
                    >> lDstRedBits) << p_stDstPixelFormat->lRedShift);
        }
    }
}

void __cdecl GLD_vYInvertBitmap24b(unsigned char *p_ucBuffer, long lWidth, long lHeight)
{
    unsigned char aucLine[0x1800];
    long lPitch = lWidth * 3;
    unsigned char *p_ucTop = p_ucBuffer;
    unsigned char *p_ucBottom = p_ucBuffer + (lHeight - 1) * lPitch;
    long lHalf = lHeight / 2;

    for (; lHalf > 0; lHalf--) {
        memcpy(aucLine, p_ucBottom, lPitch);
        memcpy(p_ucBottom, p_ucTop, lPitch);
        memcpy(p_ucTop, aucLine, lPitch);
        p_ucTop += lPitch;
        p_ucBottom -= lPitch;
    }
}

void __cdecl GLD_vBitmapConvert24bTo16bPixelFormat(unsigned short *p_usDstBuffer,
                                                   unsigned char *p_ucSrcBuffer,
                                                   long lWidth, long lHeight)
{
    long lRowBytes = lWidth * 2;

    if (lHeight > 0) {
        do {
            long lCount = lWidth;
            unsigned short *p_usDst = p_usDstBuffer;

            if (lCount > 0) {
                do {
                    unsigned int ulB0 = (unsigned int)*p_ucSrcBuffer;
                    unsigned int ulB1 = (unsigned int)p_ucSrcBuffer[1];
                    unsigned int ulB2;
                    p_ucSrcBuffer += 2;
                    ulB2 = (unsigned int)p_ucSrcBuffer[0];
                    p_ucSrcBuffer += 1;
                    lCount--;
                    *p_usDst = (unsigned short)((((ulB1 & 0xfffc) | ((ulB0 & 0xfff8) << 5)) << 3)
                                                | (ulB2 >> 3));
                    p_usDst++;
                } while (lCount != 0);
            }
            p_usDstBuffer = (unsigned short *)((unsigned char *)p_usDstBuffer + lRowBytes);
            lHeight--;
        } while (lHeight != 0);
    }
}

void __cdecl GLD_vBitmapConvert24bTo16bPixelFormatAndFiltre(unsigned short *p_usDstBuffer,
                                                            long lWDst, long lHDst,
                                                            unsigned char *p_ucSrcBuffer,
                                                            long lWSrc, long lHSrc)
{
    float fXStep, fYStep, fYAcc, fXAcc, fFracX, fFracY;
    long lYAcc, lXAcc, lRowY, lX, lY;
    unsigned char *p;
    unsigned short usR, usG, usB;

    lWSrc--;
    lHSrc--;
    fXStep = (float)lWSrc / (float)lWDst;
    fYStep = (float)lHSrc / (float)lHDst;
    fYAcc = 0.0f;
    lYAcc = 0;
    for (lY = lHDst; lY > 0; lY--) {
        lRowY = lYAcc / lHDst;
        fFracY = fYAcc - (float)lRowY;
        fXAcc = 0.0f;
        lXAcc = 0;
        for (lX = lWDst; lX > 0; lX--) {
            long lColX = lXAcc / lWDst;
            fFracX = fXAcc - (float)lColX;
            p = p_ucSrcBuffer + (lColX + (lWSrc + 1) * lRowY) * 3;
#define PF_LERP(a, b) (((float)(b) - (float)(a)) * fFracX + (float)(a))
#define PF_CH(k) ((((PF_LERP(p[(lWSrc + 1) * 3 + (k)], p[(lWSrc + 1) * 3 + (k) + 3])) \
                    - PF_LERP(p[(k)], p[(k) + 3])) * fFracY) + PF_LERP(p[(k)], p[(k) + 3]))
            usR = (unsigned short)(long)PF_CH(0);
            usG = (unsigned short)(long)PF_CH(1);
            usB = (unsigned short)(long)PF_CH(2);
#undef PF_CH
#undef PF_LERP
            *p_usDstBuffer = (unsigned short)((((usR & 0xfff8) << 5 | (usG & 0xfffc)) << 3)
                                              | (usB >> 3));
            p_usDstBuffer++;
            lXAcc += lWSrc;
            fXAcc += fXStep;
        }
        lYAcc += lHSrc;
        fYAcc += fYStep;
    }
}
