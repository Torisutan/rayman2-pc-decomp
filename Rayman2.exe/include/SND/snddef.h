#ifndef SND_SNDDEF_H
#define SND_SNDDEF_H

#if (!defined(GAMECONSOLE))  || defined(WIN32) || defined(WIN95)
#include <windows.h>
#endif

#define NB_MICRO_MAX 2

#if !defined(GAMECONSOLE)  || defined(GENERIC)
#define FILE_MODE_C_WIN95
#endif

#if !defined(GAMECONSOLE) || defined(WIN95) || defined(WIN32)

#define SND_CALL WINAPI
#else
#define SND_CALL
#endif

typedef void (SND_CALL *SND_td_pfn_vSoundCallback)(long par);

#define SndBool_field_decl(x) SndBool x

#define SND_pc_tdhLock					HANDLE
#define SND_pc_tdhEvent					HANDLE
#define SND_pc_tdhWaitable				HANDLE
#define SND_pc_tdstCriticalSection		CRITICAL_SECTION
#define SND_pc_tdhWindow				HWND
#define SND_pc_tdhInstance				HINSTANCE
#define SND_pc_tdstThreadSecurity		SECURITY_ATTRIBUTES
#define SND_pc_tdpfnThreadProc			LPTHREAD_START_ROUTINE
#define SND_pc_tdstOsVersion			OSVERSIONINFOA
#define SND_pc_tdstWaveFormat			WAVEFORMATEX
#define SND_pc_tdstDeviceCaps			WAVEOUTCAPSA

#define SND_pc_C_ulFormat1M08			WAVE_FORMAT_1M08
#define SND_pc_C_ulFormat1S08			WAVE_FORMAT_1S08
#define SND_pc_C_ulFormat1M16			WAVE_FORMAT_1M16
#define SND_pc_C_ulFormat1S16			WAVE_FORMAT_1S16
#define SND_pc_C_ulFormat2M08			WAVE_FORMAT_2M08
#define SND_pc_C_ulFormat2S08			WAVE_FORMAT_2S08
#define SND_pc_C_ulFormat2M16			WAVE_FORMAT_2M16
#define SND_pc_C_ulFormat2S16			WAVE_FORMAT_2S16
#define SND_pc_C_ulFormat4M08			WAVE_FORMAT_4M08
#define SND_pc_C_ulFormat4S08			WAVE_FORMAT_4S08
#define SND_pc_C_ulFormat4M16			WAVE_FORMAT_4M16
#define SND_pc_C_ulFormat4S16			WAVE_FORMAT_4S16

#define SND_pc_C_ulWaitForever			INFINITE

#define SND_pc_M_hCreateLock(bOwned)			CreateMutexA(NULL,(bOwned),NULL)
#define SND_pc_M_ulWaitLock(hLock,ulMs)			WaitForSingleObject((hLock),(ulMs))
#define SND_pc_M_bReleaseLock(hLock)			ReleaseMutex(hLock)
#define SND_pc_M_bDeleteLock(hLock)				CloseHandle(hLock)

#define SND_pc_M_vInitCriticalSection(p_stCs)	InitializeCriticalSection(p_stCs)
#define SND_pc_M_vDeleteCriticalSection(p_stCs)	DeleteCriticalSection(p_stCs)
#define SND_pc_M_vEnterCriticalSection(p_stCs)	EnterCriticalSection(p_stCs)
#define SND_pc_M_vLeaveCriticalSection(p_stCs)	LeaveCriticalSection(p_stCs)

#define SND_pc_M_hCreateManualEvent()			CreateEventA(NULL,1,0,NULL)
#define SND_pc_M_bSetEvent(hEvent)				SetEvent(hEvent)
#define SND_pc_M_bResetEvent(hEvent)			ResetEvent(hEvent)
#define SND_pc_M_ulWaitEvent(hEvent,ulMs)		WaitForSingleObject((hEvent),(ulMs))
#define SND_pc_M_bDeleteEvent(hEvent)			CloseHandle(hEvent)

#define SND_pc_M_ulWaitAny(ulNb,a_hObjects,ulMs)	WaitForMultipleObjects((ulNb),(a_hObjects),0,(ulMs))

#define SND_pc_M_vSleep(ulMs)					Sleep(ulMs)
#define SND_pc_M_ulGetCurrentThreadId()			GetCurrentThreadId()
#define SND_pc_M_ulGetLastError()				GetLastError()

#define SND_pc_M_vInitThreadSecurity(stSecurity)	((stSecurity).nLength = sizeof(SECURITY_ATTRIBUTES), \
	(stSecurity).bInheritHandle = TRUE, (stSecurity).lpSecurityDescriptor = NULL)
#define SND_pc_M_hCreateThread(p_stSecurity,pfnProc,pvParam,p_ulId)	CreateThread((p_stSecurity),0,(pfnProc),(pvParam),0,(p_ulId))

#define SND_pc_M_vAssertBox(hWnd,szText,szCaption)	MessageBoxA((hWnd),(szText),(szCaption),0x40000)
#define SND_pc_M_vBreak()						DebugBreak()

#define SND_pc_M_bGetOsVersion(p_stVersion)		GetVersionExA(p_stVersion)
#define SND_pc_M_ulGetDeviceCaps(p_stCaps)		waveOutGetDevCapsA(WAVE_MAPPER,(p_stCaps),sizeof(*(p_stCaps)))

#endif
