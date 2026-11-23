#pragma once

#include <stddef.h>
#include "MTH/MTH_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define C_ucAllowedState      0
#define C_ucProhibitedState   1
#define C_ucStandardLink      0
#define C_ucProportionalLink  1

#define C_ucSOUND_EVENT       0

typedef struct tdstEventInTable_
{
    void          *p_xEvent;
    unsigned char  ucTypeOfEvent;
    unsigned char  ucPriority;
    unsigned char  ucFirstCall;
    unsigned char  ucPeriod;
} tdstEventInTable;

typedef struct tdstEvent_
{
    tdstEventInTable *p_stfEventInTBL;
    unsigned short usEventNumberInTBL;
    unsigned short uwFrameNumber;
    unsigned short uwChannelNumber;
} tdstEvent;

typedef struct LST2_tdstStaticAnchor_
{
    void *hFirst;
    void *hLast;
    long  lCount;
} LST2_tdstStaticAnchor;

typedef struct tdstAnim3d_
{
    unsigned short      uwNumberOfFrames;
    unsigned char       ucFrameRate;
    unsigned char       ucMaxNumberOfElements;
    struct tdstEvent_  *d_stAnimEvent;
    MTH3D_tdstVector    stOffsetMatrix;
    void               *d_stMorphDataArray;
    unsigned short      uwNumOfA3dGENERAL;
    unsigned char       ucNumberOfEvents;
    unsigned char       ucUnused;
} tdstAnim3d;

typedef struct tdstElement3d_
{
    unsigned short wElement       : 15;
    unsigned short bf1ActiveStatus : 1;
    unsigned char  ucChannelNumber;
    unsigned char  eTypeOfElement;        /* 0x40e0d0 */
    unsigned char  ucTransparency;
    unsigned char  ucAlign;
} tdstElement3d;

#define TE_GraphicObject  0
#define TE_SubAnimation   1
#define TE_EmptyObject    2
#define TE_Event          3
#define TE_Light          4
#define TE_Fake           5
#define TE_Undefined      6

typedef struct tdstMorphData_
{
    unsigned char  ucTarget;
    unsigned char  ucMorphingAmount;
    unsigned short uwChannelNumber;
    unsigned short uwFrameNumber;
    unsigned short uwAlign;
} tdstMorphData;

typedef struct tdstCouple_
{
    unsigned short wChild;
    unsigned short wFather;
} tdstCouple;

typedef struct tdstPLA_Hierarchy_
{
    unsigned long  ulNbOfCouples;
    tdstCouple    *d_stCouples;
} tdstPLA_Hierarchy;

typedef struct tdstFrame3d_
{
    struct tdstElement3d_ *p_stArrayOfElts3d;
    void                  *p_stAngularSpeedMatrix;
    void                  *p_stLinearSpeedVector;
    tdstPLA_Hierarchy      stHierarchy;
    struct tdstAnim3d_    *p_stAnim;
    unsigned short         uwFrameNumber;
    unsigned char          ucMatrixUpdated;
    unsigned char          ucCacheEntry;
} tdstFrame3d;

typedef struct tdstState_      *tdxHandleToState;
typedef struct tdstState_
{
    unsigned char         _list_element[0x04];
    struct tdstAnim3d_   *p_stAnim;
    LST2_tdstStaticAnchor hForTransitionArray;
    LST2_tdstStaticAnchor hForProhibitArray;
    struct tdstState_    *h_NextState;            /* 0x00419970 */
    void                 *h_LinkedMechanicsIdCard; /* 0x00419990 */
    unsigned char         ucRepeatAnimation;
    signed char           scSpeedAnim;
    unsigned char         ucTransitionStatusFlag;
    unsigned char         ucCustomBits;
} tdstState;

typedef struct tdstTransition_
{
    struct tdstTransition_ *pNextElement;
    tdxHandleToState        h_TargetState;
    tdxHandleToState        h_StateToGo;
    unsigned char           ucLinkingType;
} tdstTransition;
typedef struct tdstTransition_ *tdxHandleToTransition;

typedef struct tdstProhibit_
{
    struct tdstProhibit_ *pNextElement;
    tdxHandleToState      h_ProhibitedState;
} tdstProhibit;

void            *__cdecl fn_hGetStateMechanicsIdCard(tdxHandleToState h_State);      /* 0x00419990 */
unsigned char    __cdecl fn_ucGetStateCustomBits(tdxHandleToState h_State);          /* 0x004199A0 */
signed char      __cdecl fn_scGetSpeedInState(tdxHandleToState h_State);            /* 0x00419980 */
tdxHandleToState __cdecl fn_hGetStateToGoInTransition(tdxHandleToTransition h_Transition); /* 0x004194B0 */
unsigned char    __cdecl fn_ucGetLinkingTypeInTransition(tdxHandleToTransition h_Transition); /* 0x00415210 */
void             __cdecl fn_vSetLinkingTypeInTransition(tdxHandleToTransition h_Transition, unsigned char ucLinkingType); /* 0x00415220 */
tdxHandleToState __cdecl fn_hGetNextStateInState(tdxHandleToState h_State);                  /* 0x00419970 */
tdxHandleToTransition __cdecl fn_hIfExistTransitionalWithTargetState(
    tdxHandleToState h_State, tdxHandleToState h_TargetState);                       /* 0x004199B0 */
long             __cdecl fn_hIfExistProhibitedState(
    tdxHandleToState h_State, tdxHandleToState h_TargetState);                       /* 0x004199F0 */

#ifdef __cplusplus
}
#endif
