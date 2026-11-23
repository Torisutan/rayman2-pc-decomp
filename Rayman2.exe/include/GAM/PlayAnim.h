#pragma once

#include <stddef.h>
#include "ACP/ACP_types.h"
#include "GAM/GAM_types.h"
#include "GAM/STRUCTUR/State.h"
#include "GAM/ChanList.h"
#include "GAM/ObjsTbls.h"

#ifdef __cplusplus
extern "C" {
#endif

#define LME_INVALID           65535

typedef struct tdst3dData_
{
    tdxHandleToState h_InitialState;
    tdxHandleToState h_CurrentState;
    tdxHandleToState h_FirstStateOfAction;
    tdxHandleToObjectsTablesList h_InitialObjectsTable;
    tdxHandleToObjectsTablesList h_CurrentObjectsTable;
    void            *h_Family;
    POS_tdstCompletePosition stGLIObjectMatrix;
    POS_tdstCompletePosition *p_stGLIObjectAbsoluteMatrix;
    unsigned short   uwCurrentFrame;
    unsigned char    ucRepeatAnimation;
    unsigned char    ucNextEvent;
    unsigned char   *d_ucEventActivation;
    tdstCouple      *p_stCurrentHieCouples;
    unsigned short   wCurrentHieNbCouples;
    unsigned short   wSizeOfArrayOfElts3d;
    tdxHandleToState h_StateInLastFrame;
    tdxHandleToState h_WantedState;
    unsigned short   uwForcedFrame;
    unsigned char    ucFlagEndState;
    unsigned char    ucFlagEndOfAnim;
    CHN_tdxHandleToChannelArray hArrayOfChannels;
    unsigned long               ulNumberOfChannels;
    CHN_tdxHandleToChannel      hFirstActiveChannel;
    tdstFrame3d      stFrame3d;
    void            *hMorphChannelList;
    unsigned long    ulStartTime;
    unsigned long    ulTimeDelay;
    unsigned long    ulTimePreviousFrame;
    short            sLastFrame;
    unsigned char    bStateJustModified;
    unsigned char    bSkipCurrentFrame;
    void            *p_stShadowMaterial;
    void            *p_stShadowTexture;
    MTH_tdxReal      xShadowScaleX;
    MTH_tdxReal      xShadowScaleY;
    short            xShadowQuality;
    unsigned short   uwNbEngineFrameSinceLastMechEvent;
    unsigned char    ucFrameRate;
    unsigned char    ucFlagModifState;
    unsigned char    _reserved_e2[2];
    long             lDrawMaskInit;
    long             lDrawMask;
    long             lLastComputeFrame;
    MTH3D_tdstVector stLastEventGlobalPosition;
    unsigned char    ucAnimMatrixHasChanged;
    unsigned char    ucUserEventFlags;
    unsigned char    ucBrainComputationFrequency;/* 0x00418880 */
    char             cBrainCounter;             /* 0x004188C0 */
    unsigned short   uwBrainMainCounter;        /* 0x004120D0 */
    unsigned char    ucTransparency;
    unsigned char    ucLightComputationFrequency;/* 0x004188F0 */
    char             cLightCounter;             /* 0x004188F0 */
    unsigned char    _reserved_105[0x108 - 0x105];
    MTH3D_tdstVector stSHWDeformationVector;
    MTH_tdxReal      xSHWHeight;
} tdst3dData;

typedef struct tdst3dData_ *MS_tdxHandleTo3dData;

static __inline tdxHandleToState fn_h3dDataGetCurrentState(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->h_CurrentState; }
static __inline tdxHandleToState fn_h3dDataGetFirstStateOfAction(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->h_FirstStateOfAction; }
static __inline tdxHandleToState fn_h3dDataGetWantedState(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->h_WantedState; }
static __inline void fn_v3dDataSetWantedState(MS_tdxHandleTo3dData h_3dData, tdxHandleToState h_WantedState)
    { h_3dData->h_WantedState = h_WantedState; }
static __inline void fn_v3dDataSetStateInLastFrame(MS_tdxHandleTo3dData h_3dData, tdxHandleToState h_StateInLastFrame)
    { h_3dData->h_StateInLastFrame = h_StateInLastFrame; }
static __inline void fn_v3dDataSetFirstStateOfAction(MS_tdxHandleTo3dData h_3dData, tdxHandleToState h_FirstStateOfAction)
    { h_3dData->h_FirstStateOfAction = h_FirstStateOfAction; }
static __inline unsigned short fn_uw3dDataGetCurrentFrame(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->uwCurrentFrame; }
static __inline void fn_v3dDataSetCurrentFrame(MS_tdxHandleTo3dData h_3dData, unsigned short uwCurrentFrame)
    { h_3dData->uwCurrentFrame = uwCurrentFrame; }
static __inline unsigned short fn_uw3dDataGetForcedFrame(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->uwForcedFrame; }
static __inline void fn_v3dDataSetForcedFrame(MS_tdxHandleTo3dData h_3dData, unsigned short uwForcedFrame)
    { h_3dData->uwForcedFrame = uwForcedFrame; }
static __inline void fn_v3dDataSetSizeOfArrayOfElts3d(MS_tdxHandleTo3dData h_3dData, unsigned short uwSize)
    { h_3dData->wSizeOfArrayOfElts3d = uwSize; }
static __inline void fn_v3dDataSetLastFrame(MS_tdxHandleTo3dData h_3dData, short sValue)
    { h_3dData->sLastFrame = sValue; }
static __inline void fn_v3dDataSetFlagModifState(MS_tdxHandleTo3dData h_3dData, unsigned char ucFlagModifState)
    { h_3dData->ucFlagModifState = ucFlagModifState; }
static __inline void fn_v3dDataSetFlagEndOfAnim(MS_tdxHandleTo3dData h_3dData, unsigned char ucFlagEndOfAnim)
    { h_3dData->ucFlagEndOfAnim = ucFlagEndOfAnim; }
static __inline unsigned long fn_ul3dDataGetStartTime(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ulStartTime; }
static __inline void fn_v3dDataSetStartTime(MS_tdxHandleTo3dData h_3dData, unsigned long ulValue)
    { h_3dData->ulStartTime = ulValue; }
static __inline void fn_v3dDataSetSkipCurrentFrame(MS_tdxHandleTo3dData h_3dData, int bValue)
    { h_3dData->bSkipCurrentFrame = (unsigned char)bValue; }
static __inline void fn_v3dDataSetTimeDelay(MS_tdxHandleTo3dData h_3dData, unsigned long ulValue)
    { h_3dData->ulTimeDelay = ulValue; }
static __inline void fn_v3dDataSetTimePreviousFrame(MS_tdxHandleTo3dData h_3dData, unsigned long ulValue)
    { h_3dData->ulTimePreviousFrame = ulValue; }
static __inline void fn_v3dDataSetNbEngineFrameSinceLastMechEvent(MS_tdxHandleTo3dData h_3dData, unsigned short uwValue)
    { h_3dData->uwNbEngineFrameSinceLastMechEvent = uwValue; }

static __inline void fn_v3dDataSetCurrentState(MS_tdxHandleTo3dData h_3dData, tdxHandleToState h_CurrentState)
    { h_3dData->h_CurrentState = h_CurrentState; }
static __inline unsigned char fn_uc3dDataGetFlagModifState(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ucFlagModifState; }
static __inline unsigned char fn_uc3dDataGetRepeatAnimation(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ucRepeatAnimation; }
static __inline void fn_v3dDataSetRepeatAnimation(MS_tdxHandleTo3dData h_3dData, unsigned char ucRepeatAnimation)
    { h_3dData->ucRepeatAnimation = ucRepeatAnimation; }
static __inline void fn_v3dDataDecRepeatAnimation(MS_tdxHandleTo3dData h_3dData)
    { (h_3dData->ucRepeatAnimation)--; }
static __inline unsigned char fn_uc3dDataGetFrameRate(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ucFrameRate; }
static __inline unsigned long fn_ul3dDataGetTimeDelay(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ulTimeDelay; }
static __inline unsigned long fn_ul3dDataGetTimePreviousFrame(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ulTimePreviousFrame; }
static __inline short fn_s3dDataGetLastFrame(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->sLastFrame; }
static __inline tdstFrame3d *fn_p_st3dDataGetCurrentFrame(MS_tdxHandleTo3dData h_3dData)
    { return &h_3dData->stFrame3d; }

static __inline void fn_v3dDataSetMatrix(MS_tdxHandleTo3dData h_3dData, POS_tdstCompletePosition *p_stMatrix)
    { *(POS_tdstCompletePosition *)((char *)h_3dData + 0x18) = *p_stMatrix; }
static __inline void fn_v3dDataSetEventActivationByIndex(MS_tdxHandleTo3dData h_3dData, unsigned long ulIndex, unsigned char ucValue)
    { h_3dData->d_ucEventActivation[ulIndex] = ucValue; }
static __inline void fn_v3dDataSetFlagEndState(MS_tdxHandleTo3dData h_3dData, unsigned char ucFlagEndState)
    { h_3dData->ucFlagEndState = ucFlagEndState; }
static __inline unsigned char fn_uc3dDataGetFlagEndState(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ucFlagEndState; }
static __inline void fn_v3dDataSetStateJustModified(MS_tdxHandleTo3dData h_3dData, int bValue)
    { h_3dData->bStateJustModified = (unsigned char)bValue; }
static __inline unsigned char fn_uc3dDataGetFlagEndOfAnim(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ucFlagEndOfAnim; }
static __inline int fn_b3dDataGetStateJustModified(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->bStateJustModified; }

static __inline CHN_tdxHandleToChannelArray fn_h3dDataGetChannelSOList(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->hArrayOfChannels; }
static __inline void fn_v3dDataSetChannelSOList(MS_tdxHandleTo3dData h_3dData, CHN_tdxHandleToChannelArray hArray)
    { h_3dData->hArrayOfChannels = hArray; }
static __inline unsigned long fn_ul3dDataGetNumberOfChannels(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ulNumberOfChannels; }
static __inline CHN_tdxHandleToChannel fn_h3dDataGetFirstActiveChannel(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->hFirstActiveChannel; }
static __inline void fn_v3dDataSetFirstActiveChannel(MS_tdxHandleTo3dData h_3dData, CHN_tdxHandleToChannel hChannel)
    { h_3dData->hFirstActiveChannel = hChannel; }
static __inline tdstCouple *fn_p_st3dDataGetCurrentHieCouples(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->p_stCurrentHieCouples; }
static __inline void fn_v3dDataSetCurrentHieCouples(MS_tdxHandleTo3dData h_3dData, tdstCouple *p_stCpl)
    { h_3dData->p_stCurrentHieCouples = p_stCpl; }
static __inline unsigned long fn_ul3dDataGetCurrentHieNbCouples(MS_tdxHandleTo3dData h_3dData)
    { return (unsigned long)h_3dData->wCurrentHieNbCouples; }
static __inline void fn_v3dDataSetCurrentHieNbCouples(MS_tdxHandleTo3dData h_3dData, unsigned long ulNbCpl)
    { h_3dData->wCurrentHieNbCouples = (unsigned short)ulNbCpl; }

static __inline tdxHandleToObjectsTablesList fn_h3dDataGetCurrentObjectsTable(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->h_CurrentObjectsTable; }
static __inline void *fn_h3dDataGetMorphList(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->hMorphChannelList; }
static __inline unsigned char fn_b3dDataHasAnimMatrixChanged(MS_tdxHandleTo3dData h_3dData)
    { return h_3dData->ucAnimMatrixHasChanged; }
static __inline void fn_v3dDataResetAnimMatrixHasChanged(MS_tdxHandleTo3dData h_3dData)
    { h_3dData->ucAnimMatrixHasChanged = 0; }

static __inline void fn_v3dDataUpdateMainBrainCounter(MS_tdxHandleTo3dData h_3dData)
    { if (h_3dData) h_3dData->uwBrainMainCounter++; }
static __inline unsigned short fn_uw3dDataGetMainBrainCounter(MS_tdxHandleTo3dData h_3dData)
    { return (unsigned short)(h_3dData ? h_3dData->uwBrainMainCounter : 0); }

/* 0x004188C0 */
ACP_tdxBool __cdecl fn_b3dDataCanComputeBrain(HIE_tdstSuperObject *_hCharacter);

/* 0x00418880 */
void __cdecl fn_v3dDataUpdateBrainCounter(HIE_tdstSuperObject *_hCharacter);

/* 0x00418850 */
void __cdecl fn_v3dDataSetBrainComputationFrequency(MS_tdxHandleTo3dData h_3dData, unsigned char _ucFrequency);
void __cdecl fn_v3dDataSetLightComputationFrequency(MS_tdxHandleTo3dData h_3dData, unsigned char _ucFrequency);

/* 0x004120D0 */
void __cdecl fn_vMakeCharacterThink(HIE_tdstSuperObject *p_stSuperObj);

/* 0x0040FAA0 */
ACP_tdxBool __cdecl PLA_fn_bSetNewState(HIE_tdstSuperObject *p_stSuperObject,
                                        tdxHandleToState h_WantedState,
                                        ACP_tdxBool _bForce,
                                        ACP_tdxBool _bHandleSkippedEventsIfRelevant,
                                        ACP_tdxBool _bPcSkipTransition);

/* 0x0040E9E0 */
ACP_tdxBool __cdecl PLA_fn_bDoAnimPlayerForCharacter(HIE_tdstSuperObject *p_stSuperObject,
                                                     ACP_tdxBool bNoDisplay,
                                                     ACP_tdxBool _bHandleSkippedEventsIfRelevant);

/* 0x0040EDF0 */
void __cdecl PLA_fn_vComputeNextFrame(HIE_tdstSuperObject *p_stSuperObject);

/* 0x0040F2C0 */
void __cdecl PLA_fn_vInitAllChildInHeapNewAnim(HIE_tdstSuperObject *p_stSuperObject,
                                               tdstAnim3d *p_stCurrentAnim,
                                               unsigned short _uwFrameNumber);

/* 0x0040FA60 */
void __cdecl PLA_fn_vRefreshGlobalMatrixOfAnimsHierarchy(HIE_tdstSuperObject *_hSprObj);

/* 0x0040FA30 */
void __cdecl PLA_fn_vRefreshGlobalMatrixUnderCharacter(HIE_tdstSuperObject *_hSprObj);

/* 0x0040E0D0 */
void __cdecl PLA_fn_vDoFrame(tdstAnim3d *p_stCurrentAnim, unsigned short uwCurrentFrame,
                             HIE_tdstSuperObject *p_stSuperObject);

/* 0x0040F140 */
HIE_tdstSuperObject *__cdecl PLA_fn_hFindNextFreeSupObj(void);
void __cdecl PLA_fn_vReleaseSuperObjectInHeap(HIE_tdstSuperObject *_hSupObj);

void __cdecl PLA_fn_vInitMatrixHeap(void);      /* 0x0040EF60 */
void __cdecl PLA_fn_vCreateMatrixHeap(void);    /* 0x0040EF80 */
void __cdecl PLA_fn_vInitSupObjHeap(void);      /* 0x0040F090 */
void __cdecl PLA_fn_vCreateSupObjHeap(void);    /* 0x0040F0E0 */
void __cdecl PLA_fn_vInitHeaps(void);           /* 0x0040F100 */
void __cdecl PLA_fn_vCreateAndInitHeaps(void);  /* 0x0040F110 */
/* 0x0040FE50 */
unsigned short __cdecl PLA_fn_uwGetNbFrameInCurrAnim(HIE_tdstSuperObject *p_stSuperObject);

/* 0x00418A70 */
void __cdecl fn_vFreeArrayOfElts3d(MS_tdxHandleTo3dData h_3dData);

/* 0x0040F840 */
void __cdecl PLA_fn_vDesInitAllChildOfCharacter(HIE_tdstSuperObject *p_stSuperObject,
                                                struct tdstEngineObject_ *p_stObject);

#ifdef __cplusplus
}
#endif
