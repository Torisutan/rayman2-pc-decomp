#ifndef RAYMAN2_GAM_CAPS_H
#define RAYMAN2_GAM_CAPS_H

void          __cdecl fn_vSetCapabilities(void *p_stObject, unsigned long ubf32Capabilities); /* 0x00494B50 */
unsigned long __cdecl fn_ulGetCapabilities(void *p_stObject);                                  /* 0x00494B60 */
void          __cdecl fn_vAddCapabilities(void *p_stObject, unsigned long ubf32Capabilities); /* 0x00494B70 */
void          __cdecl fn_vSubCapabilities(void *p_stObject, unsigned long ubf32Capabilities); /* 0x00494B80 */
void          __cdecl fn_vChangeCapabilities(void *p_stObject, unsigned long ubf32Capabilities, long lValue); /* 0x00494BA0 */

#endif
