#pragma once

#define SAI_C_UserFlags     ((unsigned short)0x03FF)
#define SAI_C_PrivateFlags  ((unsigned short)0xFC00)
#define SAI_C_TypesFlags    ((unsigned short)0xFC00)

typedef unsigned short SAI_tdeFlags;

#define SAI_eInitWhenNewGameStart           ((unsigned short)0x0001)
#define SAI_eInitWhenMapLoaded              ((unsigned short)0x0002)
#define SAI_eInitWhenPlayerGameSavedLoaded  ((unsigned short)0x0004)
#define SAI_eInitWhenLevelGameSavedLoaded   ((unsigned short)0x0008)
#define SAI_eInitWhenReinitTheMap           ((unsigned short)0x0010)
#define SAI_eInitWhenPlayerDead             ((unsigned short)0x0020)

#define SAI_ePlayerSaveTableValue    ((unsigned short)0x0040)
#define SAI_ePlayerSaveCurrentValue  ((unsigned short)0x0080)
#define SAI_ePlayerSaveMask          (SAI_ePlayerSaveTableValue | SAI_ePlayerSaveCurrentValue)
#define SAI_eLevelSaveTableValue     ((unsigned short)0x0100)
#define SAI_eLevelSaveCurrentValue   ((unsigned short)0x0200)
#define SAI_eLevelSaveMask           (SAI_eLevelSaveTableValue | SAI_eLevelSaveCurrentValue)
#define SAI_eAllSaveMask             (SAI_eLevelSaveMask | SAI_ePlayerSaveMask)

#define SAI_eType8        ((unsigned short)0x1000)
#define SAI_eType16       ((unsigned short)0x2000)
#define SAI_eType32       ((unsigned short)0x3000)
#define SAI_eType64       ((unsigned short)0x4000)
#define SAI_eTypeXX       ((unsigned short)0x5000)
#define SAI_eTypePointer  ((unsigned short)0x7000)

#define SAI_eType1        ((unsigned short)0x8000)

#define SAI_TRUE   1
#define SAI_FALSE  0

typedef __int64 SAI_tdLong64;

#pragma pack(push, 4)

typedef struct SAI_tdstPointerData_
{
    void          *p_vPointer;
    unsigned short uwBlocAndModuleID;
} SAI_tdstPointerData;

typedef struct SAI_tdstArrayData_
{
    unsigned char *p_ucPointer;
    unsigned long  ulArraySize;
} SAI_tdstArrayData;

typedef struct SAI_tdstBooleanData_
{
    unsigned char ucBitPosition;
    unsigned char ucCharData;
} SAI_tdstBooleanData;

union SAI_tduData_
{
    unsigned char            ucCharData;
    unsigned short           uwShortData;
    unsigned long            ulLongData;
    SAI_tdLong64             i64Long64Data;
    struct SAI_tdstPointerData_ stPointerData;
    struct SAI_tdstArrayData_   stArrayData;
    struct SAI_tdstBooleanData_ stBooleanData;
};

typedef struct SAI_tdstListEntry_
{
    struct SAI_tdstListEntry_ *p_stNextEntry;
    void                      *p_vDataPointer;
    union SAI_tduData_         uData;
    SAI_tdeFlags               eFlags;
    unsigned char              ucMemoryLevel;
    unsigned char              ucDummy;
} SAI_tdstListEntry;
#pragma pack(pop)

typedef SAI_tdstListEntry *SAI_tdxHandleToListEntry;

typedef struct SAI_tdstInternalStructure_
{
    SAI_tdstListEntry *p_stFirstEntry;  /* 0x005115c0 */
    SAI_tdstListEntry *p_stLastEntry;   /* 0x005115c4 */
} SAI_tdstInternalStructure;

/* 0x005115c0 */
extern SAI_tdstInternalStructure SAI_g_stInternalStructure;

#define SAI_g_p_stInternalStructure (&SAI_g_stInternalStructure)

/* 0x004a1f6c */
extern unsigned char g_ucSAIModuleId;

extern unsigned char SAI_g_ucMemoryBlockUsed;

#define E_ucSAIFixMemory    0
#define E_ucSAILevelMemory  1
