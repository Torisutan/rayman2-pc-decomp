#ifndef BLC_MATERIAL_H
#define BLC_MATERIAL_H

#include "BLC_Rom64.h"

#ifndef MTH_tdxReal
typedef float MTH_tdxReal;
#endif

#pragma pack(push, u64align, 1)

typedef struct U64_stGameMaterial_
{   U64_tdxIndex    xVisualMaterialId;
    U64_tdxIndex    xMechanicalMaterialId;
    U64_tdxIndex    xCollideMaterialId;
    U64_tdxIndex    xSoundMaterialId;
}   U64_tdstGameMaterial;

typedef struct U64_stVisualMaterial_
{
#if !defined CONST_VMT
    MTH_tdxReal     a4_fAmbient[4];
    MTH_tdxReal     a4_fDiffuse[4];
    MTH_tdxReal     a4_fSpecular[4];
    long            lSpecularCoef;
#endif
    short           wColor;
    short           wAmbient;
    float           fAddU;
    float           fAddV;
    U64_tdxIndex    xTextureListId;
    unsigned short  uwTextureNb;
    unsigned short  uwTotalTime;
    unsigned short  uwType;
}   U64_tdstVisualMaterial;

typedef struct U64_stTextureList_
{   U64_tdxIndex    xTextureId;
    unsigned short  uwTime;
}   U64_tdstTextureList;

typedef struct U64_stMechanicalMaterial_
{
    float   fBaseSlide;
    float   fBaseRebound;
}   U64_tdstMechanicalMaterial;

typedef struct U64_stCollideMaterial_
{   unsigned short  uwIdentifier;
    unsigned short  uwTypeOfZone;
}   U64_tdstCollideMaterial;

typedef struct U64_stTexture_
{   U64_tdxIndex    xBitmapInfoId;
}   U64_tdstTexture;

typedef struct U64_stBitmapInfo_
{   U64_tdxIndex    xBitMapId;
    U64_tdxIndex    xPaletteId;
    U64_tdxIndex    xAlphaId;
    unsigned char   a2_ucSizeLog[2];
    unsigned short  uwFlags;
    unsigned short  uwAlphaChannel;
    unsigned short  uwPaletteSize;
}   U64_tdstBitmapInfo;

typedef struct U64_stLight_
{
    float           fNear;
    float           fFar;
    float           a2_fIntensityMinMax[2];
    U64_tdstColor   stBackgroundColor;
    U64_tdstColor   stColor;
    unsigned short  uwObjectLighted;
    unsigned short  uwPaintOrAlphaFlag;
    U64_tdstVector3D stInter_Min_Pos;
    U64_tdstVector3D stInter_Max_Pos;
    U64_tdstVector3D stExter_Min_Pos;
    U64_tdstVector3D stExter_Max_Pos;
    U64_tdxIndex    xMatrixId;
    unsigned short  uwFlags;
}   U64_tdstLight;

#pragma pack(pop, u64align)

#define D_BINSCR_VisualMaterial_Gouraud       1
#define D_BINSCR_VisualMaterial_Flat          2
#define D_BINSCR_VisualMaterial_GouraudAlpha  3
#define D_BINSCR_VisualMaterial_BackFace      256

#define D_CollisionZDD 1
#define D_CollisionZDE 2
#define D_CollisionZDM 3
#define D_CollisionZDR 4

#define BITMAP_GET_TYPE(x)          ((x) & 0xF)
#define BITMAP_SET_TYPE(x, type)    (x) |= (type)
#define D_BINSCR_CI4                0x0001
#define D_BINSCR_CI8                0x0002
#define D_BINSCR_RGBA16             0x0004
#define D_BINSCR_RGBA32             0x0008
#define D_BINSCR_MirrorX            0x0010
#define D_BINSCR_MirrorY            0x0020
#define D_BINSCR_TileX              0x0040
#define D_BINSCR_TileY              0x0080
#define TEXTURE_GET_TYPE(x)         ((x) & 0x0F00)
#define TEXTURE_SET_TYPE(x, type)   (x) = (unsigned short)(((x) & 0xF0FF) | (type))
#define TEXTURE_GET_TYPEINDEX(x)    (((x) & 0x0F00) >> 8)
#define D_BINSCR_Alpha              0x0100
#define D_BINSCR_Add                0x0200
#define D_BINSCR_AlphaOnly          0x0300
#define D_BINSCR_AddAlpha           0x0400
#define D_BINSCR_AlphaNZ            0x0500
#define D_BINSCR_MultiAlphaOnly     0x0600
#define D_BINSCR_Multi_Opaque       0x0700
#define D_BINSCR_Multi_Opaque_Detail 0x0800
#define D_BINSCR_AlphaUZ           0x0900
#define D_BINSCR_Alpha5i3           0x0A00
#define D_BINSCR_Alpha3i5           0x0B00
#define D_BINSCR_Reflect            0x1000
#define D_BINSCR_CHROMASET          0x2000
#define D_BINSCR_TRANSPARENTOBJECT  0x4000
#define D_BINSCR_AUTOLUM            0x8000
#define D_BINSCR_IS_A_SMALL_LETTER  D_BINSCR_CHROMASET

#define D_BINSCR_LightType_Parallel   1
#define D_BINSCR_LightType_Spherical  2
#define D_BINSCR_LightType_HotSpot    3
#define D_BINSCR_LightType_Ambient    4
#define D_BINSCR_LightType_Box        5
#define D_BINSCR_LightType_Fog        6
#define D_BINSCR_LightType_Mask       0x000F
#define D_BINSCR_LightOn              0x8000
#define D_BINSCR_LightIsValid         0x8000
#define D_BINSCR_PersoLighted         2
#define D_BINSCR_MapLighted           1
#define D_BINSCR_AllLighted           3
#define D_BINSCR_AlphaOn              0x8000
#define D_BINSCR_PaintOn              1
#define D_BINSCR_NoAlphaLight         2

#define D_BINSCR_StructGameMaterial         E_StructGameMaterial
#define D_BINSCR_StructVisualMaterial       E_StructVisualMaterial
#define D_BINSCR_StructTextureList          E_StructTextureList
#define D_BINSCR_StructMechanicalMaterial   E_StructMechanicalMaterial
#define D_BINSCR_StructCollideMaterial      E_StructCollideMaterial
#define D_BINSCR_StructTexture              E_StructTexture
#define D_BINSCR_StructBitmapInfo           E_StructBitmapInfo
#define D_BINSCR_StructBitmapRGBA16         E_StructBitmapRGBA16
#define D_BINSCR_StructBitmapCI8            E_StructBitmapCI8
#define D_BINSCR_StructBitmapCI4            E_StructBitmapCI4
#define D_BINSCR_StructPaletteRGBA16        E_StructPaletteRGBA16
#define D_BINSCR_StructLight                E_StructLight

#endif
