#pragma once

void __cdecl GLI_xCreateMaterial(void **p_hMaterial);

/* 0x00424A00 */
void __cdecl GLI_xSetMaterialTexture(void *hMaterial, void *p_stTexture);

/* 0x00424C00 */
void __cdecl GLI_pc_vRefreshOneCyclingTexture(void *hMaterial);

/* 0x004249e0 */
void __cdecl GLI_vSetMaterialAsChromed(void *hMaterial, long bChromed);

/* 0x00424770 */
void __cdecl GLI_xDuplicateMaterial(void **p_hDest, void *hSource);

void __cdecl GLI_xSetMaterialAmbientCoef(void *hMaterial, void *p_stColor);    /* 0x00424860 */
void __cdecl GLI_xGetMaterialAmbientCoef(void *hMaterial, void *p_stColor);    /* 0x00424890 */
void __cdecl GLI_xSetMaterialColor(void *hMaterial, void *p_stColor);          /* 0x004248c0 */
void __cdecl GLI_xGetMaterialColor(void *hMaterial, void *p_stColor);          /* 0x004248f0 */
void __cdecl GLI_xSetMaterialDiffuseCoef(void *hMaterial, void *p_stColor);    /* 0x00424920 */
void __cdecl GLI_xGetMaterialDiffuseCoef(void *hMaterial, void *p_stColor);    /* 0x00424950 */
void __cdecl GLI_xSetMaterialSpecularCoef(void *hMaterial, long lExp, void *p_stColor); /* 0x00424980 */
void __cdecl GLI_xGetMaterialSpecularCoef(void *hMaterial, long *p_lExp, void *p_stColor); /* 0x004249b0 */
void __cdecl GLI_xGetMaterialTexture(void *hMaterial, void **p_hTexture);      /* 0x00424a40 */
long __cdecl GLI_lGetMaterialNumberOfAnimatedTexture(void *hMaterial);          /* 0x00424b40 */
long __cdecl GLI_lGetCurrentAnimatedTextureNumber(void *hMaterial);             /* 0x00424b50 */
void __cdecl GLI_vSetCurrentAnimatedTextureNumber(void *hMaterial, long lTextureNumber); /* 0x00424b80 */
void __cdecl GLI_vLockAnimatedTexture(void *hMaterial);                         /* 0x00424bb0 */
void __cdecl GLI_vUnLockAnimatedTexture(void *hMaterial);                       /* 0x00424bc0 */
void __cdecl GLI_vRefreshAllCyclingTextures(float fCoefOfMultiplication);       /* 0x00424bd0 */
