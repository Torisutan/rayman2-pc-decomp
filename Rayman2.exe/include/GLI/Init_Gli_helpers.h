#pragma once

void          __cdecl GLI_vInitLensFlare(void);   /* 0x00428F00 */
unsigned long __cdecl GLI_fn_lIsFullScreenMode(void);
unsigned long __cdecl GLI_fn_lDisplayModeWidth(void);
unsigned long __cdecl GLI_fn_lDisplayModeHeight(void);
unsigned long __cdecl FUN_00422090(void);

void __cdecl GLI_pc_fn_vAddDisplayMode(long lModeId, long lWidth, long lHeight, long lBpp);

long __cdecl GLI_pc_lFindDisplayMode(unsigned long ulWidth, unsigned long ulHeight, unsigned long ulBpp);

/* 0x00405930 */
void __cdecl GLI_pc_fn_vReadIniString(const char *szSection, const char *szKey,
                                      unsigned long ulSize, char *szReturnBuf);
void __cdecl GLI_pc_fn_vWriteIniString(const char *szSection, const char *szKey,
                                       const char *szValue);

/* 0x004228d0 */
struct GLI_tdstCamera_;
void GLI_xAdjustCameraToViewport ( short hDevice,
                              short hViewport,
                              struct GLI_tdstCamera_ *p_stCam ) ;

void          __cdecl FUN_00409c80(void);

char *        __cdecl GLI_pc_fn_szStristr(char *szHaystack, char *szNeedle);

void          __cdecl GLI_fnv_SetDllFileName(const char *szBaseName);

long          __cdecl GLI_pc_fn_bApplyDeferredMode(void);

/* 0x004222C0 */
long          __cdecl GLI_fn_lRequestNewDisplayMode(long lSlot);

long          __cdecl GLI_fn_lChooseDisplayMode(void);

long          __cdecl GLI_pc_bInitDisplayModes(void);
