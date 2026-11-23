#ifndef BLC_LEVEL_H
#define BLC_LEVEL_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stLevelDescription_
{
    U64_tdxIndex    xLevelDescriptionId;
}   U64_tdstLevelDescription;

#define D_BINSCR_LevelNameSize 32
typedef struct U64_stDscMiscInfo_
{
    char            acFirstLevelName[D_BINSCR_LevelNameSize];
}   U64_tdstDscMiscInfo;

typedef struct U64_stDscIpt_
{
    signed long     lHistoricSize;
    U64_tdxIndex    xInputActionLstId;
    unsigned short  uwInputActionNb;
}   U64_tdstDscIpt;

typedef struct U64_stDscLvl_
{
    unsigned short  ulBeginMapSoundEventId;
    unsigned short  uwNumberOfAlways;
}   U64_tdstDscLvl;

typedef struct U64_stLevelEntry_
{   U64_tdxIndex    xCharacterId;
    U64_tdxIndex    xMatrixId;
    unsigned short  uwFlags;
    unsigned char   ucTransparency;
    unsigned char   ucAlignment;
    unsigned long   ulCharacterFlags;
}   U64_tdstLevelEntry;

typedef struct U64_stLevel_
{
    U64_tdxIndex    xEntireLevelId;
    U64_tdxIndex    xSubLevelListId;
    U64_tdxIndex    xAlwaysEntryListId;
    U64_tdxIndex    xLevelDescriptionId;
    U64_tdxIndex    xMemoryDescriptionId;
    U64_tdxIndex    xExtendedFarClipping;
    unsigned short  uwSubLevelListNb;
    unsigned short  uwAlwaysEntryListNb;
#ifdef USE_LEVELSAVE
    unsigned short  uwLevelGameSaveLength;
#endif
    unsigned short  a6_uwTextureCacheSize[6];
    unsigned short  uwNbMorphTasks;
    unsigned short  uwNbMorphElements;
    unsigned short  uwNbMorphPoints;
    unsigned short  uwQuality;
    unsigned short  uwGfxSize;
    unsigned short  uwGfxTransSize;
    unsigned short  uwMtxSize;
    unsigned short  uwLightSize;
    unsigned short  uwFifoSizeInKB;
    U64_tdxIndex    xVector3DId;
    U64_tdxIndex    xTripledIndexId;
    unsigned short  uwVector3DNb;
    unsigned short  uwTripledIndexNb;
    unsigned short  uwCoordScale;
}   U64_tdstLevel;

#define D_BINSCR_LevelNameLength 62
typedef struct U64_stLevelsNameList_
{   U64_tdxIndex    xLevelId;
    char            a_szName[D_BINSCR_LevelNameLength];
}   U64_tdstLevelsNameList;

typedef struct U64_stSubLevel_
{
    U64_tdxIndex    xLevelEntryListId;
    U64_tdxIndex    xSuperObjectRootId;
    U64_tdxIndex    xStartMatrixListId;
    unsigned short  uwLevelEntryListNb;
    unsigned short  uwStartMatrixListNb;
    U64_tdxIndex    xSubmapSoundEvent;
}   U64_tdstSubLevel;

typedef struct U64_stFixPreloadSection_
{
    U64_tdxIndex    xSectionsId;
    unsigned short  uwSectionsNb;
}   U64_tdstFixPreloadSection;

typedef struct U64_stLevelBankList
{   U64_tdxIndex    xListId;
    unsigned short  uwBankNb;
}   U64_tdstLevelBankList;

typedef struct U64_stLevelMem_
{
    unsigned long ulAIMemory;
    unsigned long ulACPMemory;
    unsigned long ulACPU64Memory;
    unsigned long ulSAIMemorySize;
    unsigned long ulTMPMemory;
    unsigned long ulGameMemorySize;
}   U64_tdstLevelMem;

typedef struct U64_stFixMem_
{
    unsigned long ulAIMemory;
    unsigned long ulACPMemory;
    unsigned long ulACPU64Memory;
    unsigned long ulSAIMemorySize;
    unsigned long ulTMPMemory;
    unsigned long ulGameMemorySize;
    unsigned long ulFONMemorySize1;
    unsigned long ulIPTMemorySize;
}   U64_tdstFixMem;

typedef struct U64_stGenericMem
{
    U64_tdxIndex    xMemId;
    unsigned short  uwMemType;
}   U64_tdstGenericMem;

#pragma pack(pop, u64align)

#define D_BINSCR_LevelPrincipalCharacter        1
#define D_BINSCR_LevelCharacterLaunchingSounds  2
#define D_BINSCR_LevelCharacterAlwaysActive     4
#define D_BINSCR_LevelStandardCamera            32

#define D_BINSCR_StructLevelDescription E_StructLevelDescription
#define D_BINSCR_StructDscMiscInfo      E_StructDscMiscInfo
#define D_BINSCR_StructDscIpt           E_StructDscIpt
#define D_BINSCR_StructDscIptActionLst  E_StructDscIptActionLst
#define D_BINSCR_StructDscLvl           E_StructDscLvl
#define D_BINSCR_StructLevelEntry       E_StructLevelEntry
#define D_BINSCR_StructLevelEntryList   E_StructLevelEntryList
#define D_BINSCR_StructLevel            E_StructLevel
#define D_BINSCR_StructLevelsNameList   E_StructLevelsNameList
#define D_BINSCR_StructSubLevel         E_StructSubLevel
#define D_BINSCR_StructSubLevelList     E_StructSubLevelList
#define D_BINSCR_StructStartMatrixList  E_StructSubLevelList
#define D_BINSCR_StructFixPreloadSection E_StructFixPreloadSection
#define D_BINSCR_StructLevelBankList    E_StructLevelBankList
#define D_BINSCR_StructLevelBankListElement E_StructLevelBankListElement
#define D_BINSCR_StructMem              E_StructMem
#define D_BINSCR_StructLevelMem         E_StructLevelMem
#define D_BINSCR_StructFixMem           E_StructFixMem

#endif
