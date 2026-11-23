#ifndef RAYMAN2_GAM_HITPTS_H
#define RAYMAN2_GAM_HITPTS_H

struct tdstEngineObject_;

unsigned char __cdecl fn_ucGetHitPoints(void *p_stObject);                       /* 0x004949A0 */
void          __cdecl fn_vAddHitPoints(void *p_stObject, unsigned char ucValue); /* 0x004949E0 */
unsigned char __cdecl fn_ucSubHitPoints(void *p_stObject, unsigned char ucValue);/* 0x00494A30 */
unsigned char __cdecl fn_ucGetHitPointsMax(void *p_stObject);                    /* 0x00494A80 */
void          __cdecl fn_vAddHitPointsMax(struct tdstEngineObject_ *_p_stObject, unsigned char _ucValue);  /* 0x00494AB0 */
unsigned char __cdecl fn_ucSubHitPointsMax(void *p_stObject, unsigned char ucValue); /* 0x00494B00 */
void          __cdecl fn_vSetHitPointsInit(void *p_stObject, unsigned char ucValue);  /* 0x004949B0 */
void          __cdecl fn_vSetHitPoints(void *p_stObject, unsigned char ucValue);      /* 0x004949C0 */
void          __cdecl fn_vSetHitPointsMax(void *p_stObject, unsigned char ucValue);   /* 0x00494A90 */
void          __cdecl fn_vSetHitPointsToMaxValue(void *p_stObject);              /* 0x004949D0 */
void          __cdecl fn_vSetHitPointsMaxToMaxValue(void *p_stObject);           /* 0x00494AA0 */

#endif
