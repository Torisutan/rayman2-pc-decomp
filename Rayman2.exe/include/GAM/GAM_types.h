#pragma once

#include <stddef.h>
#include "HIE/HIE_types.h"
#include "MTH/MTH_types.h"

typedef unsigned char ACP_tdxBool;

typedef long tdObjectType;
#define C_InvalidObjectType (-1)
#define C_AlwaysObjectType  0x00010000

enum tdeObjectinitInit_
{
    OI_WhenPlayerGoOutOfActionZone = 0,
    OI_Always,
    OI_WhenPlayerIsDead,
    OI_WhenMapJustLoaded,
    OI_WhenSavedGameJustLoaded,
    OI_NeverBackWhenTaken,
    OI_NumberOfObjectInit,
    OI_WhenGeneratorIsDesactivated   /* 0x40c2f0 */
};

#define GAM_C_DesactivateAtAll      0x01
#define GAM_C_Activable             0x02
#define GAM_C_Active                0x04
#define GAM_C_AllSecondPassDone     0x08
#define GAM_C_Always                0x10
#define GAM_C_UselessCulling        0x20
#define GAM_C_AlwaysActive          0x40
#define GAM_C_TooFar                0x80

#define GAM_C_CustBitUnseenFrozenAnimPlayer 0x00000001UL
#define GAM_C_CustBitNeedModuleMatrices    0x00000002UL
#define GAM_C_CustBitOutOfVisibility       0x00000800UL
#define GAM_C_CustBitUnseenFrozen          0x00001000UL
#define GAM_C_CustBitNoAnimPlayer          0x00002000UL
#define GAM_C_CustBitNoAnimPlayerWhenTooFar 0x00040000UL
#define GAM_C_CustBitSoundWhenInvisible    0x00800000UL
#define GAM_C_CustBitProtection            0x01000000UL
#define GAM_C_CustBitNoAIWhenTooFar         0x00080000UL
#define GAM_C_CustBitUnfreezable            0x00100000UL
#define GAM_C_CustBitDestroyWhenAnimEnded   0x00020000UL
#define GAM_C_CustBitNoMecaWhenTooFar       0x00400000UL
#define GAM_C_CustBitNoMechanic             0x00008000UL
#define GAM_C_CustBitNoAI                   0x00010000UL
#define GAM_C_CustBitActorHasShadow         0x00000100UL

#define C_ucPlatFormType_None              0
#define C_ucPlatFormType_StandardPlatForm  1

struct tdstStandardGame_
{
      tdObjectType                  otObjectFamilyType;
      tdObjectType                  otObjectModelType;
      tdObjectType                  otObjectPersonalType;
      struct HIE_tdstSuperObject   *h_SuperObject;
      enum tdeObjectinitInit_       eInitFlagWhenOutOfZone;
      enum tdeObjectinitInit_       eInitFlagWhenDeadOrTaken;
      unsigned long                 ulLastTrame;
      unsigned long                 ubf32Capabilities;
      unsigned char                 ucTractionFactor;
      unsigned char                 ucHitPoints;
      unsigned char                 ucHitPointsMax;
      unsigned char                 ucHitPointsMaxMax;
      unsigned long                 ulCustomBits;
      unsigned char                 ucPlatFormType;
      unsigned char                 ucMiscFlags;
      unsigned char                 ucTransparencyZoneMin;
      unsigned char                 ucTransparencyZoneMax;
      unsigned long                 ulSaveCustomBits;
      unsigned char                 ucSaveHitPoints;
      unsigned char                 ucSaveHitPointsMax;
      unsigned char                 ucSaveMiscFlags;
      unsigned char                 ucTooFarLimit;
};
typedef struct tdstStandardGame_ * MS_tdxHandleToStandardGame;

struct tdstEngineObject_
{
    void                        *h_3dData;
    MS_tdxHandleToStandardGame   h_StandardGame;

    void                        *h_Dynam;
    void                        *h_Brain;        /* 0x4120D0 */
    void                        *h_Cineinfo;
    void                        *h_CollSet;
    void                        *h_MSWay;
    void                        *h_MSLight;
    void                        *h_SectInfo;
    void                        *h_Micro;
    void                        *h_MSPrtSrc;
    void                        *h_MSSound;
    void                        *h_AnimEffect;
    void                        *h_MSMagnet;
};

typedef struct tdstEngineObject_ tdstEngineObject;

struct HIE_tdstSuperObject *__cdecl fn_h_StandardGameGetSuperObject(
    MS_tdxHandleToStandardGame h_StdGame);
void __cdecl fn_vStandardGameSetSuperObject(
    MS_tdxHandleToStandardGame h_StdGame,
    struct HIE_tdstSuperObject *h_SuperObject);

/* 0x4062F0 */
void __cdecl fn_vInitAllObjectsWhenMapJustLoaded(void);

/* 0x40B8D0 */
void __cdecl CAM_fn_vInitCameras(void);

/* 0x40BAD0 */
void __cdecl CAM_fn_vCameraManagement(void);
ACP_tdxBool __cdecl CAM_fn_bSuperObjectIsACamera(HIE_tdstSuperObject *hSuperObj); /* 0x40b930 */

/* 0x40B810 */
void *__cdecl CAM_fn_p_stGetViewPortManagement(long _lViewportNumber);

/* 0x40B830 */
HIE_tdstSuperObject *__cdecl CAM_fn_hGetActiveCamera(long _lViewportNumber);

/* 0x40B950 */
void __cdecl CAM_fn_vActualizeAViewport(long _lViewport);

/* 0x40AB90 */
void __cdecl fn_vTreatCameraHierarchy(struct HIE_tdstSuperObject *hSuperObj,
                                      ACP_tdxBool bForcedActivity);

void __cdecl fn_vUpdateLight(struct HIE_tdstSuperObject *hSupObject);

void __cdecl fn_vTreatCharactersInSector(struct HIE_tdstSuperObject *hCharacter);

void __cdecl fn_vInitAllObjectTree(int eObjIniType, struct HIE_tdstSuperObject *p_stSupObject);
void __cdecl fn_vInitAlwaysModel(int eObjIniType);

static __inline unsigned char fn_bf1StandardGameGetIsDesactivateAtAll(MS_tdxHandleToStandardGame h_StdGame)
    { return (unsigned char)(h_StdGame->ucMiscFlags & GAM_C_DesactivateAtAll ? 1 : 0); }

static __inline unsigned char fn_bf1StandardGameGetIsActivable(MS_tdxHandleToStandardGame h_StdGame)
    { return (unsigned char)(h_StdGame->ucMiscFlags & GAM_C_Activable ? 1 : 0); }

static __inline unsigned char fn_bStandardGameIsAlwaysActive(MS_tdxHandleToStandardGame h_StdGame)
    { return (unsigned char)(h_StdGame->ucMiscFlags & GAM_C_AlwaysActive ? 1 : 0); }

static __inline void fn_vStandardGameSetIsActive(MS_tdxHandleToStandardGame h_StdGame, unsigned char bf1IsActive)
{
    if (bf1IsActive)
        h_StdGame->ucMiscFlags |= GAM_C_Active;
    else
        h_StdGame->ucMiscFlags &= ~GAM_C_Active;
}

static __inline void fn_vStandardGameSetIsDesactivateAtAll(MS_tdxHandleToStandardGame h_StdGame, unsigned char bf1IsDesactivateAtAll)
{
    if (bf1IsDesactivateAtAll)
        h_StdGame->ucMiscFlags |= GAM_C_DesactivateAtAll;
    else
        h_StdGame->ucMiscFlags &= ~GAM_C_DesactivateAtAll;
}

static __inline void fn_vStandardGameSetIsActivable(MS_tdxHandleToStandardGame h_StdGame, unsigned char bf1IsActivable)
{
    if (bf1IsActivable)
        h_StdGame->ucMiscFlags |= GAM_C_Activable;
    else
        h_StdGame->ucMiscFlags &= ~GAM_C_Activable;
}

static __inline enum tdeObjectinitInit_ fn_eStandardGameGetInitFlagWhenDeadOrTaken(MS_tdxHandleToStandardGame h_StdGame)
    { return h_StdGame->eInitFlagWhenDeadOrTaken; }

static __inline unsigned char fn_ucStandardGameGetPlatFormType(MS_tdxHandleToStandardGame h_StdGame)
    { return h_StdGame->ucPlatFormType; }

static __inline unsigned char fn_bf1StandardGameGetIsActive(MS_tdxHandleToStandardGame h_StdGame)
    { return (unsigned char)(h_StdGame->ucMiscFlags & GAM_C_Active ? 1 : 0); }

static __inline enum tdeObjectinitInit_ fn_eStandardGameGetInitFlagWhenOutOfZone(MS_tdxHandleToStandardGame h_StdGame)
    { return h_StdGame->eInitFlagWhenOutOfZone; }

static __inline unsigned long fn_ulStandardGameGetCustomBits(MS_tdxHandleToStandardGame h_StdGame)
    { return h_StdGame->ulCustomBits; }

static __inline void fn_vStandardGameSetCustomBits(MS_tdxHandleToStandardGame h_StdGame, unsigned long ulCustomBits)
    { h_StdGame->ulCustomBits = ulCustomBits; }

static __inline unsigned long fn_ulStandardGameGetLastTrame(MS_tdxHandleToStandardGame h_StdGame)
    { return h_StdGame->ulLastTrame; }

static __inline unsigned char fn_ucStandardGameGetTooFarLimit(MS_tdxHandleToStandardGame h_StdGame)
    { return h_StdGame->ucTooFarLimit; }

static __inline void fn_vStandardGameSetTooFar(MS_tdxHandleToStandardGame h_StdGame, ACP_tdxBool _bTooFar)
    { if (_bTooFar) h_StdGame->ucMiscFlags |= GAM_C_TooFar; else h_StdGame->ucMiscFlags &= (unsigned char)~GAM_C_TooFar; }

static __inline ACP_tdxBool fn_bStandardGameIsTooFar(MS_tdxHandleToStandardGame h_StdGame)
    { return (ACP_tdxBool)(h_StdGame->ucMiscFlags & GAM_C_TooFar ? 1 : 0); }

#define M_ObjectIsActivable(p_stObject) \
    (fn_bf1StandardGameGetIsActivable((p_stObject)->h_StandardGame)==1)

#define M_ObjectIsAlreadyTreated(p_stObject) \
    (fn_ulStandardGameGetLastTrame((p_stObject)->h_StandardGame) == GAM_g_ulEngineTrameNumber)

#define M_ObjectIsActive(p_stObject) \
    (fn_bf1StandardGameGetIsActive((p_stObject)->h_StandardGame)==1)
#define M_ActivateObject(p_stObject) \
    (fn_vStandardGameSetIsActive((p_stObject)->h_StandardGame,1))

#define M_UnactivateObject(p_stObject) \
    (fn_vStandardGameSetIsActive((p_stObject)->h_StandardGame,0))
#define M_GetSuperObject(p_stObject) \
    (fn_h_StandardGameGetSuperObject((p_stObject)->h_StandardGame))
#define M_GetMSHandle(p_stSuperObject,Name) \
    ((MS_tdxHandleTo##Name) ((struct tdstEngineObject_ *)(HIE_fn_hGetSuperObjectObject(p_stSuperObject)))->h_##Name)

#define M_GetEngineObject(p_stSuperObject) \
    ((HIE_fn_ulGetSuperObjectType(p_stSuperObject) != HIE_C_ulActor)?NULL:((struct tdstEngineObject_ *)(HIE_fn_hGetSuperObjectObject(p_stSuperObject))))

#define M_VoidMiniStructurePointer(p_stObject,i) (*(((void **)(p_stObject))+i))
#define M_ForAllMiniStructure(i) for (i=0;i<sizeof(tdstEngineObject)/sizeof(void*);i++)
#define M_ForAllMiniStructureExceptNULL(p_stObject,i) \
  M_ForAllMiniStructure(i) \
   if (M_VoidMiniStructurePointer(p_stObject,i)!=NULL)
#define M_CopyMSPointer(p_stDest,p_stSrc,ucRank) \
  { M_VoidMiniStructurePointer((p_stDest),(ucRank)) = M_VoidMiniStructurePointer((p_stSrc),(ucRank)); }

static __inline void fn_vStandardGameSetPersonalType(MS_tdxHandleToStandardGame h_StdGame, tdObjectType otPersonalType)
{ h_StdGame->otObjectPersonalType = otPersonalType; }
#define M_ObjectSetPersonalType(p_stObject,Type) \
    fn_vStandardGameSetPersonalType((p_stObject)->h_StandardGame,(Type))
#define M_SetSuperObject(p_stObject,p_stSuperObjectIn) \
    fn_vStandardGameSetSuperObject((p_stObject)->h_StandardGame,(p_stSuperObjectIn))

extern HIE_tdstSuperObject *gp_stDynamicWorld;
extern HIE_tdstSuperObject *gp_stInactiveDynamicWorld;

/* 0x0049F084 */
extern void *GAM_pc_g_hEngineThread_storage;
#define GAM_pc_g_hEngineThread_ADDR  ((void *)&GAM_pc_g_hEngineThread_storage)

typedef unsigned char GAM_tdeEngineMode;
enum GAM_tdeEngineMode_
{
    E_EM_ModeInvalid = 0,
    E_EM_ModeStartingProgram,
    E_EM_ModeStoppingProgram,
    E_EM_ModeEnterGame,
    E_EM_ModeQuitGame,
    E_EM_ModeEnterLevel,
    E_EM_ModeChangeLevel,
    E_EM_ModeDeadLoop,
    E_EM_ModePlayerDead,
    E_EM_ModePlaying,
    E_EM_NbTotalEngineMode
};

#define GAM_C_MAX_NAME_LEVEL  30
#define GAM_C_NumberOfCounter 16

typedef unsigned char GAM_tdeInputMode;
typedef unsigned char GAM_tdeDisplayFixMode;

typedef struct GAM_tdstEngineTimerStructure_
{
    unsigned long ulTrameNumber;                          /* 0x5003e4 */
    short         sTimerHandle;                           /* 0x5003e8 */

    unsigned long ulCurrentTimerCount;                    /* 0x5003ec */
    unsigned long ulDeltaTimerCount;                      /* 0x5003f0 */
    unsigned long a_ulCounter[GAM_C_NumberOfCounter];     /* 0x5003f4 */
    unsigned long ulUsefulDeltaTime;                      /* 0x500434 */
    unsigned long ulPauseTime;                            /* 0x500438 */
    MTH_tdxReal   xFrameLength;                           /* 0x50043c */
    unsigned long ulRealTimeCountLow;                     /* 0x500440 */
    unsigned long ulRealTimeCountHigh;                    /* 0x500444 */
    unsigned long ulPauseRealTimeLow;                     /* 0x500448 */
    unsigned long ulPauseRealTimeHigh;                    /* 0x50044c */
    unsigned long ulTickPerMS;                            /* 0x500450 */
} GAM_tdstEngineTimerStructure;

typedef struct GAM_tdstEngineStructure_
{
    GAM_tdeEngineMode eEngineMode;                        /* 0x00500380 */
    char              szLevelName[GAM_C_MAX_NAME_LEVEL];  /* 0x00500381 */
    char              szNextLevelName[GAM_C_MAX_NAME_LEVEL];  /* 0x0050039f */
    char              szFirstLevelName[GAM_C_MAX_NAME_LEVEL]; /* 0x005003bd */
    GAM_tdeInputMode      eInputMode;                     /* 0x005003db */
    GAM_tdeDisplayFixMode eDisplayFixMode;                /* 0x005003dc */

    unsigned long     ulDisplayMode;                      /* 0x005003e0 */
    GAM_tdstEngineTimerStructure stEngineTimer;           /* 0x005003e4 */

    short             hGLDDevice;                         /* 0x00500454 */
    short             hGLDViewport;                       /* 0x00500456 */

    unsigned char     stViewportAttr[0x70];               /* 0x00500458 */

    void              *p_stGameViewportCamera;            /* 0x005004c8 */
    void              *hDrawSem;                          /* 0x005004cc */
    short             hGLDFixViewport;                    /* 0x005004d0 */

    unsigned char     a_ucReserved_152[0x154 - 0x152];
    unsigned char     stFixViewportAttr[0x70];            /* 0x005004d4 */

    unsigned char     stFixAttributes3D[8];               /* 0x00500544 */
    void              *p_stFixCamera;                     /* 0x0050054c */

    void              *a_hViewportArray;                  /* 0x00500550 */
    void *hCameraList_hFirstElementDyn, *hCameraList_hLastElementDyn; long hCameraList_lNumberOfElementsDyn;
    void *hFamilyList_hFirstElementDyn, *hFamilyList_hLastElementDyn; long hFamilyList_lNumberOfElementsDyn;
    void *hAlwaysActiveCharactersList_hFirstElementDyn, *hAlwaysActiveCharactersList_hLastElementDyn; long hAlwaysActiveCharactersList_lNumberOfElementsDyn;
    HIE_tdstSuperObject *g_hMainActor;                    /* 0x00500578 */
    HIE_tdstSuperObject *g_hNextMainActor;                /* 0x0050057c */
    HIE_tdstSuperObject *h_StdCamCaracter;                /* 0x00500580 */
    void              *p_stLanguageTable;                 /* 0x00500584 */
    void              *hLevelNameList;                    /* 0x00500588 */
    POS_tdstCompletePosition stMainCharacterPosition;     /* 0x0050058c */
    POS_tdstCompletePosition stMainCameraPosition;        /* 0x005005e4 */

    long              lSubMapNumber;                      /* 0x0050063c */
    unsigned char     bEngineIsInPaused;                  /* 0x00500640 */
    unsigned char     bEngineHasInPaused;                 /* 0x00500641 */
    char              a_szLevelName[80][GAM_C_MAX_NAME_LEVEL]; /* 0x00500642 */
    unsigned char     ucNumberOfLevels;                   /* 0x00500fa2 */
    unsigned char     ucCurrentLevel;                     /* 0x00500fa3 */
    unsigned char     ucPreviousLevel;                    /* 0x00500fa4 */
    unsigned char     ucExitIdToQuitPrevLevel;            /* 0x00500fa5 */
    unsigned char     ucLevelGlobalCounter;               /* 0x00500fa6 */
    ACP_tdxBool       xDemoMode;                          /* 0x00500fa7 */
    unsigned char     ucCurrentLanguage;                  /* 0x00500fa8 */
    unsigned char     ucNbLanguages;                      /* 0x00500fa9 */
    ACP_tdxBool       bEngineFrozen;                      /* 0x00500faa */
    ACP_tdxBool       bResurection;                       /* 0x00500fab */
    char              cCameraMode;                        /* 0x00500fac */
} GAM_tdstEngineStructure;

#define GAM_M_AssertEngineOffset(field, off) \
    typedef char GAM_ct_assert_eng_##field[(offsetof(GAM_tdstEngineStructure, field) == (off)) ? 1 : -1]
GAM_M_AssertEngineOffset(eEngineMode,        0x000);
GAM_M_AssertEngineOffset(eInputMode,         0x05b);
GAM_M_AssertEngineOffset(eDisplayFixMode,    0x05c);
GAM_M_AssertEngineOffset(ulDisplayMode,      0x060);
GAM_M_AssertEngineOffset(stEngineTimer,      0x064);
GAM_M_AssertEngineOffset(hGLDDevice,         0x0d4);
GAM_M_AssertEngineOffset(hGLDViewport,       0x0d6);
GAM_M_AssertEngineOffset(hGLDFixViewport,    0x150);
GAM_M_AssertEngineOffset(lSubMapNumber,      0x2bc);
GAM_M_AssertEngineOffset(bEngineIsInPaused,  0x2c0);
GAM_M_AssertEngineOffset(a_szLevelName,      0x2c2);
GAM_M_AssertEngineOffset(ucNumberOfLevels,   0xc22);
GAM_M_AssertEngineOffset(ucCurrentLanguage,  0xc28);
GAM_M_AssertEngineOffset(cCameraMode,        0xc2c);
typedef char GAM_ct_assert_eng_sizeof[(sizeof(GAM_tdstEngineStructure) == 0xc30) ? 1 : -1];

typedef char GAM_ct_assert_timer_delta[(offsetof(GAM_tdstEngineTimerStructure, ulDeltaTimerCount) == 0x0c) ? 1 : -1];
typedef char GAM_ct_assert_timer_useful[(offsetof(GAM_tdstEngineTimerStructure, ulUsefulDeltaTime) == 0x50) ? 1 : -1];
typedef char GAM_ct_assert_timer_tick[(offsetof(GAM_tdstEngineTimerStructure, ulTickPerMS) == 0x6c) ? 1 : -1];
typedef char GAM_ct_assert_timer_sizeof[(sizeof(GAM_tdstEngineTimerStructure) == 0x70) ? 1 : -1];

extern GAM_tdstEngineStructure GAM_g_stEngineStructure_storage;
#define GAM_g_stEngineStructure (GAM_g_stEngineStructure_storage)
#define GAM_ENGINE_BASE         ((char *)&GAM_g_stEngineStructure_storage)

#define GAM_pc_g_hMainCharacterSO (GAM_g_stEngineStructure.g_hMainActor)

#define GAM_AA_engine_D4   OFFSET GAM_g_stEngineStructure_storage + 0xD4
#define GAM_AA_engine_D6   OFFSET GAM_g_stEngineStructure_storage + 0xD6
#define GAM_AA_engine_14C  OFFSET GAM_g_stEngineStructure_storage + 0x14C
#define GAM_AA_engine_150  OFFSET GAM_g_stEngineStructure_storage + 0x150

#define GAM_M_MakeSubMapNumber(_lSubMap, _lEntry) \
    ((((_lSubMap) & 0x0000FFFF) << 16) + ((_lEntry) & 0x0000FFFF))

extern unsigned long GAM_g_ulQuitFlag;

#define GAM_g_bEngineIsInPaused      (GAM_g_stEngineStructure.bEngineIsInPaused)
#define GAM_g_lSubMapNumber          (GAM_g_stEngineStructure.lSubMapNumber)

#define GAM_g_bEngineFrozen          (GAM_g_stEngineStructure.bEngineFrozen)        /* 0x500faa */
#define GAM_g_ucCurrentLanguage      (GAM_g_stEngineStructure.ucCurrentLanguage)    /* 0x500fa8 */
#define GAM_g_ucLevelGlobalCounter   (GAM_g_stEngineStructure.ucLevelGlobalCounter) /* 0x500fa6 */

#define GAM_g_ulDeltaTimerCount      (GAM_g_stEngineStructure.stEngineTimer.ulDeltaTimerCount) /* 0x5003f0 */
#define GAM_g_xFrameLength           (GAM_g_stEngineStructure.stEngineTimer.xFrameLength)       /* 0x50043c */
#define GAM_g_sTimerHandle           (GAM_g_stEngineStructure.stEngineTimer.sTimerHandle)       /* 0x5003e8 */
#define GAM_g_ulAccumulatedTime      (GAM_g_stEngineStructure.stEngineTimer.ulCurrentTimerCount)/* 0x5003ec */
#define GAM_g_a_ulCounter            (GAM_g_stEngineStructure.stEngineTimer.a_ulCounter)        /* 0x5003f4 */
#define GAM_g_ulUsefulDeltaTime      (GAM_g_stEngineStructure.stEngineTimer.ulUsefulDeltaTime)  /* 0x500434 */
#define GAM_g_ulCurrentTimerCountLow (GAM_g_stEngineStructure.stEngineTimer.ulRealTimeCountLow) /* 0x500440 */
#define GAM_g_ulCurrentTimerCountHigh (GAM_g_stEngineStructure.stEngineTimer.ulRealTimeCountHigh)/* 0x500444 */
#define GAM_g_ulTimerScale           (GAM_g_stEngineStructure.stEngineTimer.ulTickPerMS)        /* 0x500450 */

#define GAM_g_ulPauseTimeAccumulated (GAM_g_stEngineStructure.stEngineTimer.ulPauseTime)        /* 0x500438 */
#define GAM_g_ulPauseTimeLow         (GAM_g_stEngineStructure.stEngineTimer.ulPauseRealTimeLow) /* 0x500448 */
#define GAM_g_ulPauseTimeHigh        (GAM_g_stEngineStructure.stEngineTimer.ulPauseRealTimeHigh)/* 0x50044c */

extern long GAM_g_lCurrentFrameSave;

extern unsigned long GAM_pc_g_ulActualizeClockHookGate;

extern unsigned char g_ucGameModuleId;

#define DAT_0049f630 g_ucGameModuleId

#define GAM_g_ulEngineTrameNumber   (GAM_g_stEngineStructure.stEngineTimer.ulTrameNumber) /* 0x5003e4 */

#define GAM_g_ulMaxNumberOfAlways       (g_stAlways.ulMaxNumberOfAlways)
#define GAM_g_p_stAlwaysSuperObject     (*(HIE_tdstSuperObject **)&g_stAlways.d_stAlwaysSuperObject)
#define GAM_g_p_hAlwaysGenerator        (*(void **)&g_stAlways.d_hAlwaysGenerator)

typedef struct tdstAlwaysActiveCharacter tdstAlwaysActiveCharacter;
typedef tdstAlwaysActiveCharacter *tdxHandleToAlwaysActiveCharacterNode;

struct tdstAlwaysActiveCharacter
{

    struct HIE_tdstSuperObject *hAlwActSuperObject;

    tdxHandleToAlwaysActiveCharacterNode p_stNext;
};

#define GAM_g_hFirstAlwaysActiveCharNode (GAM_g_stEngineStructure.hAlwaysActiveCharactersList_hFirstElementDyn)

tdxHandleToAlwaysActiveCharacterNode fn_hGetFirstAlwaysActiveCharNode(void);
HIE_tdstSuperObject *fn_hGetCharacterInAlwaysActiveCharacterNode(tdxHandleToAlwaysActiveCharacterNode hCharNode);
tdxHandleToAlwaysActiveCharacterNode fn_hGetNextAlwaysActiveCharNode(tdxHandleToAlwaysActiveCharacterNode hCharNode);

static __inline void fn_vSetCharacterInAlwaysActiveCharacterNode(
    tdxHandleToAlwaysActiveCharacterNode hCharNode,
    HIE_tdstSuperObject                 *hCharacter)
{
    hCharNode->hAlwActSuperObject = hCharacter;
}

static __inline ACP_tdxBool fn_bGetIfCharacterIsInAlwaysActiveCharacterList(
    HIE_tdstSuperObject *hCharacter)
{
    return (ACP_tdxBool)fn_bStandardGameIsAlwaysActive(
        M_GetMSHandle(hCharacter, StandardGame));
}

void                fn_vChangeEngineMode(GAM_tdeEngineMode ucMode);
GAM_tdeEngineMode   GAM_fn_ucGetEngineMode(void);

unsigned char       GAM_fn_bIsStoppingProgram(void);   /* 0x004046C0 */
unsigned char       GAM_fn_bIsDesInitMode(void);       /* 0x004046D0 */

void                fn_vSetFirstLevelName(char *_szName);
char               *fn_p_szGetFirstLevelName(void);

void                fn_vSetLevelName(char *_szName);
char               *fn_p_szGetLevelName(void);

void                fn_vSetNextLevelName(char *_szName);
char               *fn_p_szGetNextLevelName(void);
void                fn_vFreeNextLevelName(void);
unsigned char       fn_bIsNextLevelNameValid(void);
unsigned char       fn_bIsEngineInPause(void);
long                fn_lGetSubMapNumber(void);

#define GAM_M_GetSubMap(_lAbsolute)                 ( ( (_lAbsolute) & 0xFFFF0000 ) >> 16 )
unsigned long       fn_ulDetermineUsefulDT(void);
void                fn_vFirstInitEngineClock(void);   /* 0x00409c50 */
void                fn_vActualizeEngineClock(void);
void                fn_vInitEngineWhenInitApplication(void);
void                fn_vStopEngineClock(void);
void                fn_vSaveEngineClock(void);
void                fn_vLoadEngineClock(void);
void                fn_vSetEngineInPaused(void);
void                fn_vResetEngineFromPaused(void);

void                GAM_fn_vChooseTheGoodInit(void);
void                fn_vChooseTheGoodDesInit(void);

void                fn_vFirstInitEngine(void);  /* 0x00403430 */
void                fn_lInitSoundForAnim(void);  /* 0x0040a3e0 */
void                fn_vInitMicrosFunction(void); /* 0x00411c20 */
void                fn_vFirstTimeInitCollisionGeometricObject(void); /* 0x0040dd40 */
void                fn_vInitGameLoop(void);      /* 0x004030c0 */
void                fn_vInitLevelLoop(void);     /* 0x00403730 */
void                fn_vInitDeadLoop(void);      /* 0x00403150 */
void                fn_vReinitTheMap(void);      /* 0x004032A0 */
void                fn_vDesInitDeadLoop(void);   /* 0x00403280 */
void                fn_vDesInitLevelLoop(void);  /* 0x004044a0 */
void                FUN_00403060(void);
unsigned char       fn_bPlayerSaveGameAll(void);              /* 0x00410360 */
unsigned char       fn_bLevelSaveGameAll(void);              /* 0x004103a0 */
unsigned char       fn_bLoadPlayerSaveGameAfterLoadLevel(void);            /* 0x00410410 */

void                GAM_fn_vActualizeAllGameViewportSize(void);
void                fn_vValidateAllOption(void);

/* 0x0044f4e0 */
unsigned char       FUN_0044f4e0(void);
void                GAM_pc_fn_vRewindEngineClock(void);
void                FUN_00403690(void);
void                FUN_00406820(void);
void                FUN_0044c310(short param_1);

ACP_tdxBool         fn_bCollSetGetCharacterNoCollisionWithMap(void *hCollSet);
ACP_tdxBool         fn_bCollSetGetCharacterNoCollisionWithProjectile(void *hCollSet);
ACP_tdxBool         fn_bCollSetGetCharacterNoCollisionWithSecondaryCharacter(void *hCollSet);
ACP_tdxBool         fn_bCollSetGetCharacterNoCollisionWithMainCharacter(void *hCollSet);
ACP_tdxBool         fn_bCollSetGetCharacterNoCollisionWithOtherSectors(void *hCollSet);
ACP_tdxBool         fn_bCollSetGetCharacterNoCollisionZdeWithProjectile(void *hCollSet);
void                fn_vCollSetSetCharacterNoCollisionWithMap(void *hCollSet, ACP_tdxBool bValue);
void                fn_vCollSetSetCharacterNoCollisionWithProjectile(void *hCollSet, ACP_tdxBool bValue);
void                fn_vCollSetSetCharacterNoCollisionWithSecondaryCharacter(void *hCollSet, ACP_tdxBool bValue);
void                fn_vCollSetSetCharacterNoCollisionWithMainCharacter(void *hCollSet, ACP_tdxBool bValue);
void                fn_vCollSetSetCharacterNoCollisionWithOtherSectors(void *hCollSet, ACP_tdxBool bValue);
void                fn_vCollSetSetCharacterNoCollisionZdeWithProjectile(void *hCollSet, ACP_tdxBool bValue);
unsigned char       fn_ucCollSetGetColliderPriority(void *hCollSet);
void                fn_vCollSetSetColliderPriority(void *hCollSet, unsigned char ucPriority);
void                fn_vCollSetSetColliderType(void *hCollSet, unsigned char ucType);
unsigned char       fn_ucCollSetGetCollComputeFrequency(void *hCollSet);
void                fn_vCollSetSetCollComputeFrequency(void *hCollSet, unsigned char ucFrequency);
unsigned char       fn_ucCollSetGetCollComputeFrequencySO(void *hSuperObject);
ACP_tdxBool         fn_bGetCharacterForceCollisionWhenNotMoving(void *hSuperObject);
unsigned char       CS_fn_ucGetCharacterPriority(void *hCollSet);
void                CS_fn_vSetCharacterPriority(void *hCollSet, unsigned char ucPriority);
float               fn_xCollSetGetColliderReal(void *hCollSet, short wIndex);
void                fn_vCollSetSetColliderReal(void *hCollSet, short wIndex, float xReal);
void               *CS_fn_hGetZdxList(unsigned char ucZoneType, void *hSuperObject);
void               *CS_fn_hGetActivationList(unsigned char ucZoneType, void *hSuperObject);
void               *CS_fn_hGetActivationListInCollSet(unsigned char ucZoneType, void *hCollSet);
MTH3D_tdstVector    fn_stCollSetGetColliderVector(void *hCollSet, short wIndex);
void                fn_vCollSetSetColliderVector(void *hCollSet, short wIndex, MTH3D_tdstVector *p_stVector);
void               *fn_hGetCurrentZoneSetOfType(unsigned char ucZoneType, void *hCollSet);
void                fn_vSetCurrentZoneSetOfType(unsigned char ucZoneType, void *hCollSet, void *hCurrentZoneSet);
unsigned long       CS_fn_ulGetPrivilegedActivationZoneInCollSet(unsigned char ucZoneType, void *hCollSet);
void                CS_fn_vSetPrivilegedActivationZoneInCollSet(unsigned char ucZoneType, void *hCollSet, unsigned long ulFB);
void                CS_fn_vSetPrivilegedActivationZone(unsigned char ucZoneType, void *hCollSet, short wIndex, unsigned char ePrivilege);
unsigned char       CS_fn_eGetPrivilegedActivationZone(unsigned char ucZoneType, void *hCollSet, short wIndex);

unsigned short      fn_uwGetIndexFromZdxIndexList(void *p_stZdxIndexList);

long                fn_lGetZdxListNumberOfElements(unsigned char ucZoneType, void *hSuperObj);

unsigned char       fn_eGetPrivilegedActivationZoneOfCharacter(unsigned char ucZoneType, void *hCharacter, short xIndex);

ACP_tdxBool         fn_bIsAllDefaultPrivilegedActivationZoneOfCharacter(unsigned char ucZoneType, void *hCharacter);

void               *fn_p_stGetCurrentZoneSetOfType2(unsigned char ucZoneType, void *hSuperObj);

ACP_tdxHandleOfObject fn_hGetGeometricZdxOfTypeAtIndex(unsigned char ucZoneType, unsigned short uwIndex, void *hSuperObj);

ACP_tdxHandleOfObject fn_hMakeOneObjectFromManyOthers(unsigned char ucZoneType, void *hCharacter, ACP_tdxHandleOfObject hTargetObject);

ACP_tdxHandleOfObject fn_hStaticMakeOneObjectFromManyZdx(unsigned char ucZoneType, void *hCharacter);
void                fn_vCollSetInitValueSAI(void *hCollSet);
void                fn_vCollSetFreeInitValueSAI(void *hCollSet);
void               *fn_h_CollSetRealAlloc(void);
void                fn_vCollSetFree(void *p_stObject);
void                fn_vCollSetDesinit(void *p_stObject, int eObjectInit);
void                fn_vCorrectAllActivationLists(void *p_stObject);
void                fn_vCollSetInit(void *p_stObject, int eObjectInit);

unsigned long       GAM_pc_fn_ulGetQuitFlag(void);

void *GAM_fn_hGetWindowHandle(void);

void fn_vInsertActorInDynamicHierarchy(HIE_tdstSuperObject *_hCharacter, ACP_tdxBool _bNewInsert);

extern HIE_tdstSuperObject *g_hSOCurrentMainSector;
extern HIE_tdstSuperObject *g_hSOPreviousMainSector;

void fn_vFillDynamicHierarchy(HIE_tdstSuperObject *_hSOCurrentSector, ACP_tdxBool _bInit);

void fn_vUpdateDynamicHierarchy(void);

void fn_vTreatDynamicHierarchy(HIE_tdstSuperObject *hSuperObj,
                                   HIE_tdstSuperObject *hMainChar,
                                   MTH3D_tdstVector *p_stMainCharTranslation);
void fn_vTreatDynamicHierarchyOfPlatForms(HIE_tdstSuperObject *hSuperObj);
void fn_vKillAllAlwaysInNonActiveSectors(void);

void GAM_fn_vEngine(void);

/* 0x0040B150 */
void fn_vDisplayAll(void);

/* 0x00419A30 */
void fn_vDisplayFix(void);

/* 0x00412230 */
void __cdecl fn_vMakeCharacterReact(HIE_tdstSuperObject *p_stSuperObj);

/* 0x00412150 */
void __cdecl fn_vMakeCharacterMechanicallyReact(HIE_tdstSuperObject *p_stSuperObj);

long PLA_fn_bTestIfEndOfAction(HIE_tdstSuperObject *hSuperObj);
void fn_vKillEngineObjectOrAlwaysByPointer(struct tdstEngineObject_ *p_stEngObj);

/* 0x00406220 */
void __cdecl fn_vKillEngineObjectNotAlways(struct tdstEngineObject_ *p_stObject);

/* 0x0040C0C0 */
void __cdecl fn_vKillAlwaysByPersonalType(tdObjectType otPersonalType);

/* 0x0040B040 */
void __cdecl fn_vReputCharacterSuperObjectAtTheWorld(struct HIE_tdstSuperObject *h_SupObject);

/* 0x00409A90 */
void __cdecl TFMT_ucClearNumberOfCurrentTextAffiche(HIE_tdstSuperObject *p_SuperObjPersoTreated);
/* 0x00412810 */
void __cdecl fn_vRemoveObjectInSectorList(HIE_tdstSuperObject *hCharacter);
/* 0x00419B90 */
void *__cdecl fn_h_SectInfoGetCurrentSector(void *h_SectInfo);
