#ifndef BLC_SECTOR_H
#define BLC_SECTOR_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stSector_
{
    U64_tdxIndex    xLstGraphicId;
    U64_tdxIndex    xLstGraphicParamId;
    U64_tdxIndex    xLstActivityId;
    U64_tdxIndex    xLstCollisionId;
    U64_tdxIndex    xLstStaticLightsId;
    U64_tdxIndex    xLstSoundId;
    U64_tdxIndex    xLstSoundParamId;
    U64_tdxIndex    xLstSoundEventId;
    U64_tdxIndex    xLstSoundEventParamId;
    U64_tdxIndex    xBorderBoxId;

    float           fAddU;
    float           fAddV;
    U64_tdxIndex    SkyVisualMaterialId;
    unsigned char   FogIntensity;
    unsigned char   bUseSky;

    unsigned short  uwLstGraphicNb;
    unsigned short  uwLstActivityNb;
    unsigned short  uwLstCollisionNb;
    unsigned short  uwLstStaticLightsNb;
    unsigned short  uwLstSoundNb;
    unsigned short  uwLstSoundEventNb;
    unsigned char   ucVirtual;
    char            cCameraType;
    short           sZFar;
    char            cPriority;
    char            cPad1;
    short           wPad2;
}   U64_tdstSector;

typedef struct U64_stSuperObject_
{   U64_tdxIndex    xMatrixId;
    U64_tdxIndex    xLinkedObjectId;
    U64_tdxIndex    xChildListId;
    U64_tdxIndex    xBVBoxId;
    unsigned short  uwLinkedObjectType;
    unsigned short  uwNbChild;
    unsigned short  uwTransparenceLevel;
    unsigned short  uwPad;
    unsigned long   ulFlags;
}   U64_tdstSuperObject;

typedef struct U64_stSurface_
{   U64_tdxIndex    xGeometricObjectId;
    U64_tdxIndex    xMatrixId;
}   U64_tdstSurface;

typedef struct U64_stFamily_
{
    U64_tdxIndex    xStateRefId;
    U64_tdxIndex    xObjectsTableId;
    U64_tdxIndex    xBoundingVolumeId;
    unsigned short  uwNumberOfChannels;
}   U64_tdstFamily;

typedef struct U64_stStateRef_
{   U64_tdxIndex    xStateRefListId;
    unsigned short  uwStateRefListNb;
}   U64_tdstStateRef;

typedef struct U64_stState_
{   U64_tdxIndex    xAnimInfoId;
    U64_tdxIndex    xMecIdCardId;
    U64_tdxIndex    xTargetStateListId;
    U64_tdxIndex    xNextStateId;
    U64_tdxIndex    xProhibitedTargetStateId;
    unsigned short  uwTargetStateNb;
    unsigned short  uwMecIdCardType;
    unsigned short  uwRepeat;
    unsigned short  uwSpeed;
    unsigned char   ucTransitionStatusFlag;
    unsigned char   ucCustomBits;
}   U64_tdstState;

typedef struct U64_stObjectsTablePO_
{
    U64_tdxIndex    xEntryId;
    U64_tdxIndex    xCustomZoomId;
    unsigned short  uwEntryType;
    unsigned short  uwFlag;
}   U64_tdstObjectsTablePO;

typedef struct U64_stObjectsTableEvent_
{
    long    lTarget;
    char    ucType;
    char    ucFirstCall;
    char    ucPeriod;
    char    ucPriority;
}   U64_tdstObjectsTableEvent;

typedef struct U64_stObjectsTableEntry_
{
    unsigned short uwTypeOfLinkedObject;
    unsigned short align;
    union uLinkedObject
    {
        U64_tdstObjectsTablePO    stPO;
        U64_tdstObjectsTableEvent stEvent;
    } u_stLinkedObject;
}   U64_tdstObjectsTableEntry;

typedef struct U64_stObjectsTable_
{
    U64_tdxIndex    xLstObjectsTableId;
    unsigned short  uwPhysicalObjectsNb;
    unsigned short  uwZDxUsed;
    unsigned short  uwAlign;
}   U64_tdstObjectsTable;

typedef struct U64_stPhysicalObject_
{
#ifndef D_THROW_VISUAL_SET
    U64_tdxIndex    xVisualSetId;
#else
    U64_tdxIndex    xGeometricObjectId;
#endif
    U64_tdxIndex    xCollisionSetId;
}   U64_tdstPhysicalObject;

typedef struct U64_stInstanciatedPhysicalObject_
{   U64_tdxIndex    xPhysicalObjectId;
    U64_tdxIndex    xReceivedLightIntensityId;
}   U64_tdstInstanciatedPhysicalObject;

typedef struct U64_stBoundingVolume_
{
    U64_tdstVector3D stSphereCenter;
    float            fSphereRadius;
}   U64_tdstBoundingVolume;

#pragma pack(pop, u64align)

#define D_BINSCR_UniversName "SPO_Univers"
#define D_BINSCR_TblHdr_Duplicate (1 << 0)

#define D_BINSCR_StructSector             E_StructSector
#define D_BINSCR_StructLstGraphic         E_StructLstGraphic
#define D_BINSCR_StructLstGraphicParam    E_StructLstGraphicParam
#define D_BINSCR_StructLstActivity        E_StructLstActivity
#define D_BINSCR_StructLstCollision       E_StructLstCollision
#define D_BINSCR_StructLstStaticLights    E_StructLstStaticLights
#define D_BINSCR_StructLstStaticLightsTmp E_StructLstStaticLightsTmp
#define D_BINSCR_StructLstEnvironment     E_StructLstEnvironment
#define D_BINSCR_StructLstSurface         E_StructLstSurface
#define D_BINSCR_StructLstSound           E_StructLstSound
#define D_BINSCR_StructLstSoundParam      E_StructLstSoundParam
#define D_BINSCR_StructLstSoundEvent      E_StructLstSoundEvent
#define D_BINSCR_StructLstSoundEventParam E_StructLstSoundEventParam
#define D_BINSCR_StructSuperObject        E_StructSuperObject
#define D_BINSCR_StructSuperObjectChildList E_StructSuperObjectChildList
#define D_BINSCR_StructSurface            E_StructSurface
#define D_BINSCR_StructFamily             E_StructFamily
#define D_BINSCR_StructFixFamily          E_StructFixFamily
#define D_BINSCR_StructStateRef           E_StructStateRef
#define D_BINSCR_StructStateRefList       E_StructStateRefList
#define D_BINSCR_StructState              E_StructState
#define D_BINSCR_StructFixState           E_StructFixState
#define D_BINSCR_StructStateList          E_StructStateList
#define D_BINSCR_StructObjectsTableLst    E_StructObjectsTableLst
#define D_BINSCR_StructObjectsTable       E_StructObjectsTable
#define D_BINSCR_StructFixObjectsTable    E_StructFixObjectsTable
#define D_BINSCR_StructPhysicalObject     E_StructPhysicalObject
#define D_BINSCR_StructInstanciatedPhysicalObject E_StructInstanciatedPhysicalObject
#define D_BINSCR_StructBoundingVolume     E_StructBoundingVolume

#endif
