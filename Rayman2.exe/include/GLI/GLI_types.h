#pragma once

#include "MTH/MTH_types.h"
#include "ACP/ACP_types.h"

#define GLI_C_lAllIsEnable                0xffffffffL
#define GLI_C_lIsNotChromed               0x00400000L
#define GLI_C_lIsNotGrided                0x00000008L
#define GLI_C_lNotInvertBackfaces         0x00080000L
#define GLI_C_lIsNotVisibleInRealWorld    0x00800000L
#define GLI_C_lIsNotVisibleInSymetricWorld 0x01000000L
#define GLI_C_lIsNotDrawingInMirror       0x02000000L

#define PIC_C_DepthPickingElements 3

typedef enum {
    PIC_C_ModePickingFace  = 0,
    PIC_C_ModePickingEdge  = 1,
    PIC_C_ModePickingPoint = 2
} GLI_tdeModePicking;

typedef struct GLI_tdstDataOfElement_ {
    MTH3D_tdstVector        stHit;
    MTH_tdxReal             xDistance;
    ACP_tdxHandleOfElement  xElements;
    ACP_tdxIndex            xIndexOfFace;
    ACP_tdxIndex            xIndexOfEdge;
    ACP_tdxIndex            xIndexOfPoint;
} GLI_tdstDataOfElement;

typedef struct GLI_tdstPickedObject_ {
    GLI_tdeModePicking      xModePicking;
    ACP_tdxIndex            xNbElements;
    GLI_tdstDataOfElement   aDEF_stDataOfElement[PIC_C_DepthPickingElements];
} GLI_tdstPickedObject;

typedef struct GLI_tdstTexture
{
    int            bIsAvailable;
    long           lTextureQuality;

    void          *p_vBitMap;
    void          *p_vColorTable;

    void          *p_stSpecParam;

    unsigned long  ulTextureCaps;

    unsigned short uwHeight;
    unsigned short uwWidth;

    unsigned short uwRealHeight;
    unsigned short uwRealWidth;

    MTH_tdxReal    xAddU;
    MTH_tdxReal    xAddV;
    int            lIncrementIsEnable;

    unsigned long  ulChromakeyColorRGBA;

    long           lNumberOfLod;
    unsigned long  ulCompressionCounter;
    unsigned long  ulTypeOfCompression;
    unsigned long  ulTypeOfMipMapping;
    struct GLI_tdstTexture *p_TextureOfSubstitution;

    unsigned char  ucBilinearMode;
    unsigned char  ucCyclingMode;

    char           szFileName[128];
} GLI_tdstTexture;

#define GLI_C_Tex_lTiledTexture           0x00000001ul
#define GLI_C_Tex_lNZTexture              0x00000002ul
#define GLI_C_Tex_lMipMapTexture          0x00000004ul
#define GLI_C_Tex_lAlphaTexture           0x00000008ul
#define GLI_C_Tex_lNZFilteredTexture      0x00000010ul
#define GLI_C_Tex_lAddTransparencyTexture 0x00000020ul
#define GLI_C_Tex_lNoZBufferWriteTexture  0x00000040ul
#define GLI_C_Tex_lPaletteTexture         0x00000080ul
#define GLI_C_Tex_lAlphaTest              0x00000100ul
#define GLI_C_Tex_lAAATexture             0x00000200ul
#define GLI_C_Tex_lMAATexture             0x00000400ul
#define GLI_C_Tex_lProceduralTexture      0x00000800ul
#define GLI_C_Tex_lBMPTexture             0x40000000ul
#define GLI_C_Tex_lTGATexture             0x80000000ul

#define GLI_C_lCyclingU                   1
#define GLI_C_lCyclingV                   2
#define GLI_C_lCyclingUV                  3
#define GLI_C_lMirrorU                    4
#define GLI_C_lMirrorV                    8
#define GLI_C_lMirrorUV                   12
