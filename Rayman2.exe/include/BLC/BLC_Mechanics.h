#ifndef BLC_MECHANICS_H
#define BLC_MECHANICS_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stIdCardBase_
{
    float           fGravity;
    float           fSlide;
    float           fRebound;
    float           fSlopeLimit;
    float           fTiltIntensity;
    float           fTiltInertia;
    float           fTiltOrigin;
    U64_tdxIndex    xInertiaId;
    U64_tdxIndex    xMaxSpeedId;
    unsigned short  uwMiscFlags;
    unsigned short  uwSwim;
}   U64_tdstIdCardBase;

typedef struct U64_stIdCardCamera_
{   float   fAngularSpeed;
    float   fLinearSpeed;
    float   fSpeedingUp;
}   U64_tdstIdCardCamera;

typedef struct U64_stEnvironment_
{   U64_tdxIndex    xMechanicalEnvironmentId;
    U64_tdxIndex    xVisualEnvironmentId;
    float           fSoundEnvironment;
}   U64_tdstEnvironment;

typedef struct U64_stMechanicalEnvironment_
{   float           fGravity;
    float           a3_fVertical[3];
    float           fViscosity;
    float           fLiquidLevel;
    float           fLiquidDensity;
    float           a3_fMoveLiquid[3];
    float           fFluidToxicity;
    unsigned short  uwVolumicEnvironment;
}   U64_tdstMechanicalEnvironment;

typedef struct U64_stVisualEnvironment_
{   float   fFogNear;
    float   fFogFar;
    float   fFogInfinite;
    float   a3_fFogColor[3];
    float   fBlendNear;
    float   fBlendFar;
}   U64_tdstVisualEnvironment;

#pragma pack(pop, u64align)

#define D_BINSCR_IdCardBase_Animation         0x0001
#define D_BINSCR_IdCardBase_Collide           0x0002
#define D_BINSCR_IdCardBase_Gravity           0x0004
#define D_BINSCR_IdCardBase_Tilt              0x0008
#define D_BINSCR_IdCardBase_Gi                0x0010
#define D_BINSCR_IdCardBase_Climb             0x0020
#define D_BINSCR_IdCardBase_OnGround          0x0040
#define D_BINSCR_IdCardBase_CollisionControl  0x0080
#define D_BINSCR_IdCardBase_KeepSpeedZ        0x0100
#define D_BINSCR_IdCardBase_SpeedLimit        0x0200
#define D_BINSCR_IdCardBase_Inertia           0x0400
#define D_BINSCR_IdCardBase_Stream            0x0800
#define D_BINSCR_IdCardBase_StickOnPlatform   0x1000
#define D_BINSCR_IdCardBase_Spider            0x2000
#define D_BINSCR_IdCardBase_Shoot             0x4000
#define D_BINSCR_IdCardBase_Scale             0x8000

#define D_BINSCR_MevAir   0
#define D_BINSCR_MevWater 1
#define D_BINSCR_MevLava  2

#define D_BINSCR_StructIdCardBase             E_StructIdCardBase
#define D_BINSCR_StructIdCardCamera           E_StructIdCardCamera
#define D_BINSCR_StructEnvironment            E_StructEnvironment
#define D_BINSCR_StructMechanicalEnvironment  E_StructMechanicalEnvironment
#define D_BINSCR_StructVisualEnvironment      E_StructVisualEnvironment

#endif
