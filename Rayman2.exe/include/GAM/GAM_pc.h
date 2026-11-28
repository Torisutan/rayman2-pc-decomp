#pragma once

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

/* 0x0049f07c */
extern HINSTANCE g_hInstance_storage;
#define g_hInstance (&g_hInstance_storage)

extern HANDLE g_hEngineEventExeFrame_storage;  /* 0x004e0ec8 */
extern HANDLE g_hEngineEventExit_storage;      /* 0x004e0ecc */
extern HANDLE g_hEngineEventIsDead_storage;    /* 0x004e0ed0 */
extern HANDLE g_hEngineEventIsPaused_storage;  /* 0x004e0ed4 */
#define g_hEngineEventExeFrame (&g_hEngineEventExeFrame_storage)
#define g_hEngineEventExit     (&g_hEngineEventExit_storage)
#define g_hEngineEventIsDead   (&g_hEngineEventIsDead_storage)
#define g_hEngineEventIsPaused (&g_hEngineEventIsPaused_storage)

/* 0x004013c0 */
void GAM_pc_fn_vGetAppContext(unsigned long *p_aContext);

/* 0x004013f0 */
HINSTANCE GAM_pc_fn_hGetAppInstance(void);

/* 0x00401370 */
void __cdecl GAM_pc_fn_vSetDisplaySize(unsigned long ulWidth,
                                        unsigned long ulHeight);

/* 0x00401390 */
unsigned long GAM_pc_fn_ulGetDisplayWidth(void);

/* 0x004013a0 */
unsigned long GAM_pc_fn_ulGetDisplayHeight(void);

/* 0x004013b0 */
void __cdecl GAM_pc_fn_vSetDisplayFullScreen(unsigned long bFullScreen);

/* 0x00401820 */
unsigned long __cdecl GAM_pc_fn_vHandleActivateEnterFullScreen(int iFlag);

/* 0x00401910 */
unsigned long __cdecl GAM_pc_fn_vHandleActivateExitToWindowed(int iFlag);

/* 0x004019e0 */
unsigned long GAM_pc_fn_vDispatchWmActivate(void);

/* 0x004016e0 */
unsigned long __cdecl GAM_pc_fn_vEnterPauseOnDeactivate(int iReDispatch);

/* 0x00401a80 */
void GAM_pc_fn_vResumeAfterFocusReturn(void);

/* 0x004014a0 */
unsigned long GAM_pc_fn_vProbeDisplayBpp(void);

/* 0x004015b0 */
void GAM_pc_fn_vResumeEngineThread(void);

/* 0x004015e0 */
void GAM_pc_fn_vEngineEventControl(unsigned short uwCmd);

/* 0x00401650 */
void GAM_pc_fn_vPostWindowCmd(unsigned short uwCmd);

/* 0x00401410 */
void GAM_pc_fn_vPostResumeAfterFocus(void);

/* 0x00401550 */
void GAM_pc_fn_vSignalEngineAndPostQuit(void);

/* 0x00401790 */
int GAM_pc_fn_vRestoreEngineOnActivate(void);

/* 0x00401b50 */
int GAM_pc_fn_vDispatchWmUser(WPARAM wParam, LPARAM lParam);

/* 0x00401c50 */
int GAM_pc_fn_vHandleWmPowerBroadcast(WPARAM wParam, LPARAM lParam,
                                      LRESULT *p_lResult);

/* 0x004013e0 */
HANDLE fn_hGetDrawSemaphore(void);

/* 0x00401420 */
void GAM_pc_fn_vCreateSyncObjects(void);

/* 0x004014f0 */
int GAM_pc_fn_bInitDisplayAndSync(void);

/* 0x00401260 */
void GAM_pc_fn_vOpenEngineEvents(void);

/* 0x00401090 */
void GAM_pc_fn_vEngineThreadExit(void);

/* 0x00401100 */
int FUN_00401100(void);
int FUN_00401130(void);

/* 0x00401340 */
unsigned short __cdecl FUN_00401340(int);
unsigned short __cdecl FUN_00401350(int);
void           __cdecl GAM_pc_fn_vWaitForEitherEngineEvent(void);

/* 0x00401210 */
unsigned int fn_uiEngineMainLoop(void);

/* 0x004010B0 */
void GAM_pc_fn_vChooseTheGoodInit(void);

#ifndef USE_SDL
DWORD WINAPI GAM_pc_fn_ulEngineThreadProc(LPVOID lpParameter);
#endif

/* 0x00401510 */
void GAM_pc_fn_vCreateEngineThread(void);

/* 0x00401590 */
void GAM_pc_fn_vKillEngineThreadAfterExit(void);

/* 0x00401b20 */
unsigned long FUN_00401b20(void);

#ifndef USE_SDL
int FUN_00402580(MSG *p_msg);
#endif

/* 0x00401050 */
void FUN_00401050(void);

/* 0x004494b0 */
void __cdecl GAM_pc_fn_vFreeMmgTableAndHelperDll(void);

/* 0x00402020 */
int GAM_fn_bCreateMainWindow(HINSTANCE hInstance, int iShowCmd);

/* 0x00402150 */
int __cdecl fn_bCreateMainDisplayScreen(void);

#ifndef USE_SDL
LRESULT CALLBACK GAM_fn_WndProc(HWND hWnd, UINT uMsg, WPARAM wParam,
                                LPARAM lParam);
#endif

/* 0x00401d40 */
int __stdcall GAM_pc_fn_WinMain(HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      char     *p_szCmdLine,
                      int       iShowCmd);

/* 0x004081D0 */
long  __cdecl GAM_pc_fn_lGetSaveSlotId(long lSlotId);

/* 0x004083B0 */
char *__cdecl GAM_pc_fn_p_szGetSaveSlotNameScore(long lSlotId);

/* 0x004082E0 */
int   __cdecl GAM_pc_fn_lEnsureDefaultSaveSlot(void);

/* 0x00410DB0 */
char *__cdecl GAM_pc_fn_szFormatSaveSlotDate(long lSlotId);

/* 0x00407B80 */
unsigned char __cdecl fn_bSaveCurrentGameOptions(void);

/* 0x00410980 */
unsigned char __cdecl GAM_pc_fn_bBuildSaveSlotPath(char *pszOut, long lSlotId);

/* 0x00408200 */
long  __cdecl GAM_pc_fn_lCountSaveSlotDirs(char *pszPath);

/* 0x00408460 */
unsigned char __cdecl GAM_pc_fn_ucGrowSaveSlotList(long lCount);

/* 0x00408290 */
long  __cdecl fn_lGetNbAvailableSlots(void);

/* 0x004A706C */
extern void *GAM_gs_pSaveSlotHead;

/* 0x004106A0 */
int   __cdecl GAM_pc_fn_bDeleteDirectoryTree(char *pszDir);
