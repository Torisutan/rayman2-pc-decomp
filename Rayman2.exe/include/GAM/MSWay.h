#ifndef RAYMAN2_GAM_MSWAY_H
#define RAYMAN2_GAM_MSWAY_H

typedef struct tdstMSWay_ * MS_tdxHandleToMSWay;

#ifdef D_MSWay_StructureDefine
typedef struct tdstMSWay_
{
 WP_tdHandleOfGraph m_hPath ;
 long m_lIndex ;
 char m_bIsCircular;
} tdstMSWay;
#endif

long __cdecl MSWay_fn_lGetNumberWayPointInPath(MS_tdxHandleToMSWay hWay);            /* 0x004170B0 */
long __cdecl MSWay_fn_lGetCurrentIndexInPath(MS_tdxHandleToMSWay hWay);             /* 0x004170D0 */
long __cdecl MSWay_fn_lGetLastIndexInPath(MS_tdxHandleToMSWay hWay);               /* 0x004170F0 */
long __cdecl MSWay_fn_lGetFirstIndexInPath(MS_tdxHandleToMSWay hWay);              /* 0x00417110 */
long __cdecl MSWay_fn_lSetCurrentIndexInPath(MS_tdxHandleToMSWay hWay, long _lIndex);        /* 0x00417130 */
long __cdecl MSWay_fn_lIncrementCurrentIndexInPath(MS_tdxHandleToMSWay hWay, int iStep);   /* 0x004171B0 */
void *__cdecl MSWay_fn_hGetWayPointOfPath(MS_tdxHandleToMSWay hWay, int iIndex);            /* 0x00417210 */
long  __cdecl MSWay_fn_lLookForWPInMSWay(MS_tdxHandleToMSWay _hWay, void *_hWayPoint);        /* 0x00417170 */
unsigned long __cdecl MSWay_fn_ulGetCapsForNextWayPointOfPath(MS_tdxHandleToMSWay hWay, int iIndex); /* 0x00417260 */
long __cdecl MSWay_fn_lGetWeightForNextWayPointOfPath(MS_tdxHandleToMSWay hWay, int iIndex);  /* 0x00417360 */
long __cdecl MSWay_fn_lChangeWeightForNextWayPointOfPath(MS_tdxHandleToMSWay hWay, int iIndex, long lWeight); /* 0x004173E0 */
long __cdecl MSWay_fn_lChangeCapsForNextWayPointOfPath(MS_tdxHandleToMSWay hWay, int iIndex, unsigned long ulNewCaps, long lValue); /* 0x004172E0 */

#endif
