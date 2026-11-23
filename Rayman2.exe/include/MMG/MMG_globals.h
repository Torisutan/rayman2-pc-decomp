#pragma once

#include <stdint.h>

struct tdstBlockInfoPriv;

extern unsigned int *g_ulMMGTable_storage;
#define g_p_ulMMGTable (g_ulMMGTable_storage)

extern struct tdstBlockInfoPriv *g_a_p_stMmgModuleBlocksInfo[255];

extern unsigned char g_a_ucBlocksNbInModule[255];

typedef struct tdstChannelInfo_ {
    unsigned long ulThreadId;
    unsigned char ucGroupId;
    unsigned char a_ucPad[3];
} tdstChannelInfo;

typedef struct tdstGeneralChannelInfo_ {
    unsigned char    ucNbChannelUsed;
    unsigned char    ucMaxNbChannel;
    unsigned char    a_ucPad[2];
    tdstChannelInfo *d_stTabChannelInfo;
} tdstGeneralChannelInfo;

/* 0x0050B1E0 */
extern tdstGeneralChannelInfo *const g_p_stMmgGeneralChannelInfo;
extern tdstGeneralChannelInfo g_stMmgGeneralChannelInfo_storage;

#define MMG_M_p_TabChannelInfo (g_stMmgGeneralChannelInfo_storage.d_stTabChannelInfo)

#define C_ucMmgInvalidGroup 0xff

#define C_ucMmgDefaultGroup 0

#define C_p_cBlockNotValidKey ((void *)(intptr_t)-1)

/* 0x004A6AB4 */
extern unsigned char g_ucErmNbOfModule;
#define g_p_ucErmNbOfModule (&g_ucErmNbOfModule)

typedef struct tdstBlockInfo_ {
    void *p_cBeginBlock;
    void *p_cEndBlock;
    void *p_cFirstFree;
    void *p_cMaxMem;
} tdstBlockInfo;

/* 0x00501530 */
extern tdstBlockInfo MMG_g_stGmtPalBlockInfo;
#define MMG_g_p_GmtPalBlockInfo (&MMG_g_stGmtPalBlockInfo)

#undef EXTERN
#if !defined(D_MMG_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN uint8_t *g_p_d_stCurrentModeInfo;

EXTERN unsigned int g_ucMMGTableSize;
EXTERN unsigned int g_ul113f0;
EXTERN int SNA_g_bLoadListsSorted;
EXTERN unsigned long SNA_g_ulGptHeaderScratch;

/* 0x004A11C4 */
extern unsigned char MMG_g_ucErmChannelId;

#undef EXTERN
#if !defined(D_MMG_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN void * g_pfnMMG_510dc8;   /* 0x00510DC8 */
EXTERN void * g_pfnMMG_510c08;   /* 0x00510C08 */
EXTERN void * g_pfnMMG_510e08;   /* 0x00510E08 */
EXTERN void * g_pfnMMG_510c48;   /* 0x00510C48 */
EXTERN void * SNA_g_pErrorFrame1; /* 0x00510E1C */
EXTERN void * SNA_g_pErrorFrame2; /* 0x00510C5C */
EXTERN void * SNA_g_pGptErrorFrame1;
EXTERN void * SNA_g_pGptErrorFrame2;
EXTERN void * SNA_g_pOpenErrorFrame1;
EXTERN void * SNA_g_pOpenErrorFrame2;
EXTERN struct SNA_pc_tdstRelocSlot_ * SNA_g_pRelocCursor;
EXTERN struct SNA_pc_tdstRelocSlot_ * SNA_g_pRelocCursorEnd;

/* 0x00510BF0 */
EXTERN unsigned int MMG_g_ulLCGState;

/* 0x00510BF4 */
EXTERN unsigned long MMG_pc_g_ulPsapiLoaded;

EXTERN int SNA_g_lProtectionGate;

/* 0x004A13D0 */
typedef struct MMG_pc_tdstImport_
{
    unsigned long ulKey;
    unsigned char ucNameLen;
    char a_cName[0x2B];
    unsigned long ulPtrXorKey;
    unsigned long ulModule;
    unsigned long a_ulImporter[5];
} MMG_pc_tdstImport;

#define MMG_pc_C_ImpGetModuleHandleA        0
#define MMG_pc_C_ImpFlushInstructionCache   1
#define MMG_pc_C_ImpGetCurrentProcess       2
#define MMG_pc_C_ImpGetDriveTypeA           15
#define MMG_pc_C_ImpGetVolumeInformationA   16
#define MMG_pc_C_ImpCreateFileA             8
#define MMG_pc_C_ImpReadFile                10
#define MMG_pc_C_ImpCloseHandle             11
#define MMG_pc_C_ImpSetFilePointer          12
#define MMG_pc_C_ImpGetLogicalDrives        35
#define MMG_pc_C_NbImport                   36

extern MMG_pc_tdstImport MMG_pc_g_a_stImport[MMG_pc_C_NbImport + 1];   /* 0x004A13D0 */

#pragma pack(push, 1)
typedef struct MMG_pc_tdstModule_
{
    unsigned long ulKey;
    unsigned char ucNameLen;
    char a_cName[40];
} MMG_pc_tdstModule;
#pragma pack(pop)

#define MMG_pc_C_NbModule   7
extern char MMG_pc_g_a_szModule[MMG_pc_C_NbModule + 1][sizeof(MMG_pc_tdstModule)];   /* 0x004A1268 */
#define MMG_pc_M_p_stModule(i)  ((MMG_pc_tdstModule *)MMG_pc_g_a_szModule[i])

#define MMG_pc_M_ulImportAddress(i)                                       \
    (MMG_pc_g_a_stImport[i].ulKey                                         \
     ^ *(volatile unsigned long *)&MMG_pc_g_a_stImport[i].ulPtrXorKey)

/* 0x00510EA0 */
typedef union MMG_pc_tduLcgPool_
{
    unsigned int a_ulWord[0x119];
    unsigned char a_ucCode[0x464];
} MMG_pc_tduLcgPool;
extern MMG_pc_tduLcgPool MMG_pc_g_uLcgPool;   /* 0x00510EA0 */
#define MMG_pc_C_PoolSize       0x464
#define MMG_pc_C_PoolSlots      0x455
#define MMG_pc_C_StubSize       15

#define MMG_pc_M_vStepLcg()                                                                    \
    {                                                                                          \
        unsigned int ulS_ = MMG_g_ulLCGState ^ 0x75bd924u;                                     \
        MMG_g_ulLCGState = ulS_ * 0x41a7u + (unsigned int)((int)ulS_ / 0x1f31d * -0x7fffffff); \
        if ((int)MMG_g_ulLCGState < 0)                                                         \
            MMG_g_ulLCGState += 0x7fffffffu;                                                   \
    }

#define MMG_pc_M_vWriteStub(p, i, ucOp1, ucOp2)                                   \
    {                                                                             \
        (p)[0] = 0xA1;                                                            \
        *(unsigned long **)((p) + 1) = &MMG_pc_g_a_stImport[i].ulPtrXorKey;      \
        (p)[5] = 0x33;                                                            \
        (p)[6] = 0x05;                                                            \
        *(unsigned long **)((p) + 7) = &MMG_pc_g_a_stImport[i].ulKey;            \
        (p)[11] = (ucOp1);                                                        \
        (p)[12] = (ucOp2);                                                        \
    }

#define MMG_pc_M_vFlushPool(hProcess)                                                            \
    {                                                                                            \
        (hProcess) = ((void *(__stdcall *)(void))                                                \
                          MMG_pc_M_ulImportAddress(MMG_pc_C_ImpGetCurrentProcess))();            \
        ((int (__stdcall *)(void *, const void *, unsigned long))                                \
             MMG_pc_M_ulImportAddress(MMG_pc_C_ImpFlushInstructionCache))(                       \
            (hProcess), &MMG_pc_g_uLcgPool, MMG_pc_C_PoolSize);                          \
    }
