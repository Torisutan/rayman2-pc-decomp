#ifndef BLC_ACTOR_H
#define BLC_ACTOR_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stCharacter_
{
    U64_tdxIndex    x3dDataId;
    U64_tdxIndex    xBrainId;
    U64_tdxIndex    xCineInfoId;
    U64_tdxIndex    xCollSetId;
    U64_tdxIndex    xLightId;
    U64_tdxIndex    xMicroId;
#ifndef D_THROW_PRT
    U64_tdxIndex    xParticleSrcId;
#endif
    U64_tdxIndex    xStandardGameId;
    U64_tdxIndex    xDynId;
    U64_tdxIndex    xSndId;
    unsigned char   ucAllocWay;
    unsigned char   ucPad;
}   U64_tdstCharacter;

typedef struct U64_stCharacter3dData_
{
    unsigned long       ulDrawMask;
    U64_tdstVector2D    stShadowScale;
    U64_tdxIndex        xInitialStateId;
    U64_tdxIndex        xInitialObjectsTableId;
    unsigned char       ucBrainComputationFrequency;
    unsigned char       ucbIsAlphabet;
    unsigned char       a3_ucPad[2];
}   U64_tdstCharacter3dData;

typedef struct U64_stCharacterCineInfo_
{
    float           a3_fShiftTarget[3];
    float           a3_fShiftPos[3];
    float           a3_fLinearSpeed[3];
    float           a3_fAngularSpeed[3];
    float           a3_fTargetSpeed[3];
    float           a4_fDistance[4];
    float           a2_fZMinMax[2];
    float           a2_fAlpha[2];
    float           a2_fTheta[2];
    float           fFocal;
    unsigned short  uwDNMFlags;
    unsigned short  uwIAFlags;
    unsigned short  uwViewport;
    unsigned short  uwActivation;
    short           wChannel;
    unsigned short  uwPad;
}   U64_tdstCharacterCineInfo;

typedef struct U64_stCharacterCollSet_
{   U64_tdxIndex    xZddTableId;
    U64_tdxIndex    xZdmTableId;
    U64_tdxIndex    xZdeTableId;
    U64_tdxIndex    xZdrTableId;
    U64_tdxIndex    xZddActivationTableId;
    U64_tdxIndex    xZdmActivationTableId;
    U64_tdxIndex    xZdeActivationTableId;
    U64_tdxIndex    xZdrActivationTableId;
    short           wCharacterPriority;
    unsigned char   ucCollisionFlag;
    unsigned char   ucCollComputeFrequency;
}   U64_tdstCharacterCollSet;

typedef struct U64_stCharacterDyn_
{
    float           fSlideFactorX;
    float           fSlideFactorY;
    float           fSlideFactorZ;
    unsigned short  uwDynamFlags;
    unsigned char   ucSize;
    unsigned char   ucCollision;
}   U64_tdstCharacterDyn;

typedef struct U64_stCharacterLight_
{   float           a2_fFarNear[2];
    float           a2_fLittleBigAlpha[2];
    float           a2_fLittleBigTangent[2];
    float           a4_fColor[4];
    float           fGyrophare;
    float           a2_fPulse[2];
    float           a3_fOffset[3];
    float           a3_fDirection[3];
    float           a3_fInterMinPos[3];
    float           a3_fInterMaxPos[3];
    float           a3_fExterMinPos[3];
    float           a3_fExterMaxPos[3];
    float           a2_fIntensityMinMax[2];
    unsigned short  uwFlags;
    unsigned char   ucGyrophare;
    unsigned char   ucPulse;
    unsigned char   ucLocal;
    unsigned char   ucOnlyLocal;
    unsigned short  uwAlign;
}   U64_tdstCharacterLight;

typedef struct U64_stCharacterMicro_
{   U64_tdxIndex    xRotationId;
    U64_tdxIndex    xTranslationId;
    unsigned short  uwFlags;
}   U64_tdstCharacterMicro;

#ifndef D_THROW_PRT
typedef struct U64_stCharacterParticleSrc_
{
    U64_tdxIndex    xGeneratorId;
    unsigned short  uwActivation;
}   U64_tdstCharacterParticleSrc;
#endif

typedef struct U64_stCharacterSnd_
{
    unsigned long   ulSaturationDistance;
    unsigned long   ulBackGroundDistance;
}   U64_tdstCharacterSnd;

typedef struct U64_stCharacterStandardGame_
{
    unsigned long   ulCustomBitsInit;
    unsigned long   ulCapabilities;
    U64_tdxIndex    xFamilyId;
    short           wHitPointsInit;
    short           wHitPointsMaxInit;
    short           wHitPointsMaxMax;
    unsigned short  uwFlags;
    unsigned short  uwSpecialPositionFlags;
    unsigned char   ucPlatformType;
    unsigned char   ucTransparencyZoneMin;
    unsigned char   ucTransparencyZoneMax;
    unsigned char   ucTooFarLimit;
}   U64_tdstCharacterStandardGame;

typedef struct U64_stCharacterStream_
{   float           a3_fDirection[3];
    float           fLimitSpeed;
    float           fNullSpeedDistance;
    float           fSpeedAtL0;
    float           fL0;
    float           fSpeedAtSecondZero;
    float           fSecondZero;
    unsigned short  uwFlags;
    unsigned short  uwPad;
}   U64_tdstCharacterStream;

typedef struct U64_stCharacterStockLst_
{   U64_tdxIndex    xBoxSetId;
    U64_tdxIndex    xInstanciatedItemId;
    short           wNumber;
    unsigned short  uwFlags;
}   U64_tdstCharacterStockLst;

typedef struct U64_stCharacterWay_
{   U64_tdxIndex    xWayLstId;
}   U64_tdstCharacterWay;

typedef struct U64_stCharacterWorld_
{   float   fSnowForce;
    float   fRainForce;
    float   a3_fWindVector[3];
    float   a3_fWaterFogColor[3];
    float   a3_fWaterFogAttributes[3];
    float   a3_fAirFogColor[3];
    float   a3_fAirFogAttributes[3];
}   U64_tdstCharacterWorld;

#pragma pack(pop, u64align)

#define D_BINSCR_DynamUnknown                  0
#define D_BINSCR_DynamSolid                    (1 << 0)
#define D_BINSCR_DynamLiquid                   (1 << 1)
#define D_BINSCR_DynamGas                      (1 << 2)
#define D_BINSCR_DynamPlasma                   (1 << 3)
#define D_BINSCR_DynamIsMobile                 (1 << 4)
#define D_BINSCR_DynamIsNotMobile              (0 << 4)
#define D_BINSCR_DynamCanHangSmthgOn           (1 << 5)
#define D_BINSCR_DynamCanNotHangSmthgOn        (0 << 5)
#define D_BINSCR_DynamTakeCareOfTheEnvironment (1 << 6)

#define C_DynamicSizeBase     0
#define C_DynamicSizeAdvanced 1
#define C_DynamicSizeComplex  2

#define D_BINSCR_MicroIsActive (1 << 0)

#define D_BINSCR_CharacterLightAmbient  0
#define D_BINSCR_CharacterLightParallel 1
#define D_BINSCR_CharacterLightSpherical 2
#define D_BINSCR_CharacterLightHotSpot  3
#define D_BINSCR_CharacterLightOn       4

#define D_BINSCR_StdInitFlagWhenOutOfZoneNeverBack       (1 << 0)
#define D_BINSCR_StdInitFlagWhenOutOfZoneGoOutOfZone     (1 << 1)
#define D_BINSCR_StdInitFlagWhenDeadOrTakenNeverBack     (1 << 2)
#define D_BINSCR_StdInitFlagWhenDeadOrTakenGoOutOfZone   (1 << 3)
#define D_BINSCR_StdInitFlagWhenDeadOrTakenAlways        (1 << 4)
#define D_BINSCR_StdInitFlagWhenDeadOrTakenPlayerDead    (1 << 5)
#define D_BINSCR_StdInitFlagWhenDeadOrTakenMapLoaded     (1 << 6)
#define D_BINSCR_StdInitFlagWhenDeadOrTakenSavedGameLoaded (1 << 7)
#define D_BINSCR_StdSpecialPositionFlag                  (1 << 15)

#define D_BINSCR_CharacterStream_On             (1 << 0)
#define D_BINSCR_CharacterStream_Way            (1 << 1)
#define D_BINSCR_CharacterStream_CylinderLinear (1 << 2)
#define D_BINSCR_CharacterStream_CylinderRadial (1 << 3)
#define D_BINSCR_CharacterStream_CylinderSteer  (1 << 4)
#define D_BINSCR_CharacterStream_Cone           (1 << 5)
#define D_BINSCR_CharacterStream_ConeRadial     (1 << 6)
#define D_BINSCR_CharacterStream_Air            (1 << 7)
#define D_BINSCR_CharacterStream_Water          (1 << 8)
#define D_BINSCR_CharacterStream_Lava           (1 << 9)

#define D_BINSCR_CharacterStockLst_Blocking (1 << 0)

#define D_BINSCR_StructCharacter              E_StructCharacter
#define D_BINSCR_StructFixCharacter           E_StructFixCharacter
#define D_BINSCR_StructCharacter3dData        E_StructCharacter3dData
#define D_BINSCR_StructCharacterCineInfo      E_StructCharacterCineInfo
#define D_BINSCR_StructCharacterCollSet       E_StructCharacterCollSet
#define D_BINSCR_StructCharacterDyn           E_StructCharacterDyn
#define D_BINSCR_StructCharacterLight         E_StructCharacterLight
#define D_BINSCR_StructCharacterMicro         E_StructCharacterMicro
#define D_BINSCR_StructCharacterParticleSrc   E_StructCharacterParticleSrc
#define D_BINSCR_StructCharacterSnd           E_StructCharacterSnd
#define D_BINSCR_StructCharacterStandardGame  E_StructCharacterStandardGame
#define D_BINSCR_StructCharacterStream        E_StructCharacterStream
#define D_BINSCR_StructCharacterStockLst      E_StructCharacterStockLst
#define D_BINSCR_StructCharacterWay           E_StructCharacterWay
#define D_BINSCR_StructCharacterWorld         E_StructCharacterWorld

#endif
