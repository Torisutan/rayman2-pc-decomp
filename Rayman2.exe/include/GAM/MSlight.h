#ifndef RAYMAN2_GAM_MSLIGHT_H
#define RAYMAN2_GAM_MSLIGHT_H

typedef struct tdstMSLight_ * MS_tdxHandleToMSLight;

void __cdecl fn_vMSLightSetRLIParameter(void *hMSLight, long lNbRLI, long lIndex1, long lIndex2, long lPercent);   /* 0x00416D70 */
void __cdecl fn_vMSLightSetLocalLight(void *h, unsigned char bLocalLight);   /* 0x00416210 */

#endif
