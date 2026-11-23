#pragma once

#include "ACP/ACP_types.h"
#include "HIE/HIE_types.h"
#include "LST/LstDef2.h"

#ifdef __cplusplus
extern "C" {
#endif

#define C_ucUnknownChannel  ((unsigned char)0xFF)

typedef struct tdstAChannel_
{
    HIE_tdstSuperObject  *hSupObject;
    HIE_tdstSuperObject  *hZoomSupObject;
    struct tdstAChannel_ *p_stNextActiveChannel;
    struct tdstAChannel_ *p_stFatherChannel;
    ACP_tdxBool           bControlledChannel;
    ACP_tdxBool           bActiveChannel;
} tdstAChannel;

typedef tdstAChannel *CHN_tdxHandleToChannel;
typedef tdstAChannel *CHN_tdxHandleToChannelArray;

static __inline CHN_tdxHandleToChannel fn_hGetCSOForChannel(
    CHN_tdxHandleToChannelArray hChannelArray, unsigned short uwChannel)
{
    return &hChannelArray[uwChannel];
}

/* 0x004194D0 */
void __cdecl fn_vInitCSOList(CHN_tdxHandleToChannelArray *p_hChannelArray, unsigned long ulNumberOfChannels);

/* 0x00419510 */
void __cdecl fn_vFreeCSOList(CHN_tdxHandleToChannelArray *p_hChannelArray);

/* 0x00419580 */
void __cdecl fn_vUpdateSPOFlagsOfChannelForActivation(HIE_tdstSuperObject *_hSOChannel, ACP_tdxBool _bActivate);

/* 0x00419530 */
struct tdstEngineObject_;
void __cdecl fn_vTakeControlOfChannel(struct tdstEngineObject_ *_hActor, unsigned short _uwChannel, ACP_tdxBool _bControlled);

/* 0x004195A0 */
void __cdecl fn_vActivateChannel(HIE_tdstSuperObject *_hPerso, unsigned short _uwChannel, ACP_tdxBool _bActivate);

typedef struct tdstMorphChannelList_ *CHN_tdxHandleToMorphElement;
LST2_M_DynamicUseListOf(CHN_tdxHandleToMorphElement);
typedef LST2_M_DynamicAnchorDeclaration(CHN_tdxHandleToMorphElement) *CHN_tdxHandleToMorphList;

typedef struct tdstMorphChannelList_
{
    LST2_M_DynamicElementDeclaration(CHN_tdxHandleToMorphElement)
    unsigned short uwChannelNumber;
    ACP_tdxIndex   MorphListIndex;
} tdstMorphChannelList;

/* 0x00419900 */
ACP_tdxIndex __cdecl fn_hMorphListIndex(CHN_tdxHandleToMorphList hMorphList, unsigned short uwChannel);
/* 0x00419710 */
void __cdecl fn_vPutMorphElementInChannel(CHN_tdxHandleToMorphList hMorphList, unsigned short uwChannel, ACP_tdxIndex IndexOfMorphList);
/* 0x00419860 */
void __cdecl fn_vRemoveChannelFromMorphList(CHN_tdxHandleToMorphList hMorphList, unsigned short uwChannel);
/* 0x00419690 */
void __cdecl fn_vFreeMorphList(CHN_tdxHandleToMorphList *p_hMorphList);

#ifdef __cplusplus
}
#endif
