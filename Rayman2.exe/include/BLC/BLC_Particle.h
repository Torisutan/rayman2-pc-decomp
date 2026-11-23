#ifndef BLC_PARTICLE_H
#define BLC_PARTICLE_H

#include "BLC_Rom64.h"

#ifndef D_THROW_PRT

#pragma pack(push, u64align, 1)

typedef struct U64_stPrtEnv_
{
    float            fAccelerationRange;
    U64_tdstVector3D stAcceleration;
    float            a6_fEnvParam[6];
    unsigned short   uwEnvType;
    unsigned short   uwPad;
}   U64_tdstPrtEnv;

typedef struct U64_stPrtGen_
{
    U64_tdxIndex    xSourceId;
    U64_tdxIndex    xSystemId;
    U64_tdxIndex    xEnvironmentId;
    short           wEnvironmentMask;
    unsigned char   ucLinkedToEnvironment;
    unsigned char   ucPad;
}   U64_tdstPrtGen;

typedef struct U64_stPrtSrc_
{
    U64_tdstVector3D a3_stPoint[3];
    float            fSpeed;
    float            fSpeedRange;
    float            fGenerationProbability;
    long             a2_lCrenelParam[2];
    short            NbMinMax[2];
    unsigned char    ucGenerationMode;
    unsigned char    ucNbGenerationMode;
    unsigned char    ucNbParticles;
    unsigned char    ucMode;
    unsigned char    ucLinkMode;
    char             cPad;
}   U64_tdstPrtSrc;

typedef struct U64_stPrtSys_
{
    U64_tdxIndex    xSystemId;
    unsigned short  uwSystemType;
    unsigned short  uwNumber;
    unsigned short  uwRefType;
}   U64_tdstPrtSys;

#pragma pack(pop, u64align)

#define D_BINSCR_AlignedBoxEnv 1
#define D_BINSCR_SphereEnv     2

#define D_BINSCR_NoGeneration          1
#define D_BINSCR_ContinuousGeneration  2
#define D_BINSCR_ProbabilistGeneration 3
#define D_BINSCR_CrenelGeneration      4
#define D_BINSCR_ConstantNb            1
#define D_BINSCR_ProbabilistNb         2
#define D_BINSCR_ModePoint             1
#define D_BINSCR_ModeQuad              2
#define D_BINSCR_RotationLink          1
#define D_BINSCR_TranslationLink       2
#define D_BINSCR_RotationAndTranlsationLink 3

#define D_BINSCR_PointSystem   1
#define D_BINSCR_SegmentSystem 2
#define D_BINSCR_SpriteSystem  3

#define D_BINSCR_StructPrtEnv  E_StructPrtEnv
#define D_BINSCR_StructPrtGen  E_StructPrtGen
#define D_BINSCR_StructPrtSrc  E_StructPrtSrc
#define D_BINSCR_StructPrtSys  E_StructPrtSys

#endif

#endif
