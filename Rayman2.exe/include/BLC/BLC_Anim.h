#ifndef BLC_ANIM_H
#define BLC_ANIM_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stAnimInfo_
{
    U64_tdxIndex    xAnimListTableId;
    unsigned short  uwChannelNb;
    unsigned short  uwFrameNb;
    unsigned short  uwNumOfIntAnim;
}   U64_tdstAnimInfo;

typedef struct U64_stAnimListTable_
{   U64_tdxIndex    xEntryId;
    unsigned short  uwEntryType;
}   U64_tdstAnimListTable;

typedef struct U64_stAnimList_
{
    float           fSphereBoxRadius;
    U64_tdxIndex    xMatrixId;
    U64_tdxIndex    xPivotPositionId;
    U64_tdxIndex    xPivotOrientationId;
    U64_tdxIndex    xSphereBoxCenterId;
    unsigned short  uwChannelId;
    unsigned short  uwPhysicalObjectInTableId;
    unsigned short  uwKeyAttribute;
    unsigned short  uwPad;
}   U64_tdstAnimList;

typedef struct U64_stAnimationEvent_
{   unsigned long   ulReference;
    unsigned long   ulSndEventId;
    unsigned char   ucEventType;
    unsigned char   ucAnimReferenceChannel;
    unsigned char   ucFrameNumber;
    unsigned char   ucPriority;
    unsigned char   ucFirstCall;
    unsigned char   ucPeriod;
    unsigned char   ucType;
    unsigned char   ucData;
}   U64_tdstAnimationEvent;

typedef struct U64_stAnimSpeedMatrix_
{   U64_tdxIndex    xRotationSpeedId;
    U64_tdxIndex    xTranslationSpeedId;
    unsigned short  uwStartFrame;
}   U64_tdstAnimSpeedMatrix;

typedef struct U64_stGliMatrix_
{   U64_tdxIndex    xRotationId;
    U64_tdxIndex    xTransformId;
    U64_tdxIndex    xTransId;
}   U64_tdstGliMatrix;

typedef struct U64_stLipsSynchro_
{   unsigned short  uwChannelNb;
    unsigned char   ucPhoneme;
    unsigned char   ucIntensity;
    unsigned char   ucNeutral;
    unsigned char   ucPad;
}   U64_tdstLipsSynchro;

typedef struct U64_stSndEventM_
{   U64_tdxIndex    xParamId;
    unsigned char   ucSetStopable;
    unsigned char   ucSetDynamic;
}   U64_tdstSndEventM;

#pragma pack(pop, u64align)

#define D_BINSCR_AnimEvent_TypeMechanic 1
#define D_BINSCR_AnimEvent_TypeSound    2
#define D_BINSCR_AnimEvent_TypeGeneric  3
#define D_BINSCR_AnimEvent_TypeGenerate 4

#define D_BINSCR_AnimEvent_TurnUp                 1
#define D_BINSCR_AnimEvent_TurnDown               2
#define D_BINSCR_AnimEvent_TurnLeft               3
#define D_BINSCR_AnimEvent_TurnRight              4
#define D_BINSCR_AnimEvent_TurnAbsolute           5
#define D_BINSCR_AnimEvent_JumpAbsolute           6
#define D_BINSCR_AnimEvent_JumpWithoutAddingSpeed 7
#define D_BINSCR_AnimEvent_Jump                   8
#define D_BINSCR_AnimEvent_Accelerate             9
#define D_BINSCR_AnimEvent_Pulse                  10
#define D_BINSCR_AnimEvent_Brake                  11
#define D_BINSCR_AnimEvent_GoRelative             12
#define D_BINSCR_AnimEvent_GoAbsolute             13

#define D_BINSCR_AnimEvent_TakeObjectEvent    1
#define D_BINSCR_AnimEvent_TakeInObjectEvent  2
#define D_BINSCR_AnimEvent_TakeOutObjectEvent 3
#define D_BINSCR_AnimEvent_DropObjectEvent    4
#define D_BINSCR_AnimEvent_ThrowObjectEvent   5
#define D_BINSCR_AnimEvent_User0              6
#define D_BINSCR_AnimEvent_User1              7
#define D_BINSCR_AnimEvent_User2              8
#define D_BINSCR_AnimEvent_User3              9
#define D_BINSCR_AnimEvent_User4              10
#define D_BINSCR_AnimEvent_User5              11
#define D_BINSCR_AnimEvent_User6              12
#define D_BINSCR_AnimEvent_User7              13

#define D_BINSCR_InvalidObject  0xFFFF
#define D_BINSCR_InvalidChannel 0xFFFF

#define D_BINSCR_StructAnimInfo         E_StructAnimInfo
#define D_BINSCR_StructAnimListTable    E_StructAnimListTable
#define D_BINSCR_StructAnimList         E_StructAnimList
#define D_BINSCR_StructAnimationEvent   E_StructAnimationEvent
#define D_BINSCR_StructAnimSpeedList    E_StructAnimSpeedList
#define D_BINSCR_StructAnimSpeedMatrix  E_StructAnimSpeedMatrix
#define D_BINSCR_StructLipsSynchro      E_StructLipsSynchro
#define D_BINSCR_StructSndEventM        E_StructSndEventM
#define D_BINSCR_StructSndEventLst      E_StructSndEventLst
#define D_BINSCR_StructSndEventIdList   E_StructSndEventIdList

#endif
