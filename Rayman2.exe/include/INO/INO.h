#pragma once

#ifdef WIN32
#include <windows.h>
#endif

#define INO_C_wNbMaxDevice      20
#define INO_C_wNbMaxAxis         6
#define INO_C_wMaxKeyDown        8
#define INO_C_wStringMaxLength  32

#define INO_C_uwUnknown         0x00
#define INO_C_uwMouse           0x04
#define INO_C_uwKeyboard        0x08
#define INO_C_uwJoystick        0x10
#define INO_C_uwAnyType         0xFF

#define INO_C_ucConnected       0x01
#define INO_C_ucAcquired        0x02
#define INO_C_ucAccessError     0x04
#define INO_C_ucGLDLink         0x08
#define INO_C_ucActivated       0x10

#define INO_C_wAllDevices       1
#define INO_C_wConnectedDevices 2

#define INO_C_ucButtonDown      0x80
#define INO_C_ucKeyDown         INO_C_ucButtonDown
#define INO_C_ucKeyToggled      0x01

typedef struct INO_tdstDevCaps_ {
    unsigned char  ucNbButtons;
    unsigned long  ulCapsFlags;
} INO_tdstDevCaps;

typedef struct INO_tdstDevState_ {
    unsigned char  ucStatus;
} INO_tdstDevState;

typedef struct INO_tdstAxisCaps_ {
    long m_lCenter;
    long m_lRange;
    long m_lThreshold;
} INO_tdstAxisCaps;

struct INO_tdstDevice_;
typedef short (*INO_tdfn_wMethod)(struct INO_tdstDevice_ *tdstDevice);

typedef struct INO_tdstDevice_ {
    unsigned short    uwType;
    INO_tdstDevCaps  *p_stCaps;
    INO_tdstDevState *p_stState;
    unsigned int      ulLastTimeCount;
    short             wHistoricSize;
    short             wHistoricHead;
    short             wRecordNumber;
    void             *pvHistoric;
    INO_tdfn_wMethod  pfnRead;
} INO_tdstDevice;

typedef INO_tdstDevice *INO_tdhDevice;

typedef struct INO_tdstKeyboardCaps_ {
    unsigned char  ucNbButtons;
    unsigned long  ulCapsFlags;
    unsigned short wIsAzerty;
} INO_tdstKeyboardCaps;

typedef struct INO_tdstKeyboardState_ {
    unsigned char  ucStatus;
    unsigned char  a_ucTabKey[2][256];
    unsigned short wCurrentTab;
    unsigned short wLastKey;
    unsigned short wLastASCII;
    unsigned short wStateHasChanged;
    char           szCurrentString[INO_C_wStringMaxLength];
    unsigned short wCurrentStringLength;
} INO_tdstKeyboardState;

typedef struct INO_tdstKeyboardRecord_ {
    unsigned short wNbKeyDown;
    unsigned short a_wKeyDown[INO_C_wMaxKeyDown];
    unsigned int   ulDate;
} INO_tdstKeyboardRecord;

typedef struct INO_pc_tdstAxisDeviceCaps_ {
    INO_tdstDevCaps  stDev;
    unsigned char    ucNbAxes;
    unsigned char    ucNbPOVs;
    unsigned char    aucPadA[2];
    INO_tdstAxisCaps a_stAxis[INO_C_wNbMaxAxis];
} INO_pc_tdstAxisDeviceCaps;

typedef struct INO_pc_tdstJoyState_ {
    unsigned char   ucStatus;
    unsigned char   aucPad1[3];
    unsigned long   ulButtons;
    unsigned short  uwDirection;
    unsigned char   aucPadA[2];
    long            a_lAxis[INO_C_wNbMaxAxis];
} INO_pc_tdstJoyState;

typedef struct INO_pc_tdstJoyRecord_ {
    unsigned long   ulButtons;
    unsigned short  uwDirection;
    unsigned char   aucPad6[2];
    unsigned long   ulTimeCount;
} INO_pc_tdstJoyRecord;

typedef struct INO_pc_tdstMouseRecord_ {
    unsigned long   ulButtons;
    unsigned long   ulTimeCount;
} INO_pc_tdstMouseRecord;

/* 0x495890 */
struct INO_tdstDevice_;
typedef struct INO_pc_tdstMouseState_
{
    unsigned char   ucStatus;
    unsigned char   aucPad1[3];
    unsigned long   ulButtons;
    long            lRawX;
    long            lRawY;
    long            lRawZ;
    unsigned char   aucPad2[0x0C];
    short           hGLDDevice;
    unsigned char   aucPad3[2];
    float           fScale;
    float           fPosX;
    float           fPosY;
    short (__cdecl *p_fnInitMouseState)(struct INO_tdstDevice_ *pDevice, short hDev);
    float           fAxis;
} INO_pc_tdstMouseState;

#define INO_M_uwType(hDev)       ((hDev)->uwType & 0xFF)
#define INO_M_uwSubType(hDev)    ((hDev)->uwType)
#define INO_M_ucNbButtons(hDev)  ((hDev)->p_stCaps->ucNbButtons)
#define INO_M_wReadDevice(hDev)  ((hDev)->pfnRead(hDev))
#define INO_M_bIsConnected(hDev) (((hDev)->p_stState->ucStatus & INO_C_ucConnected) != 0)
#define INO_M_bIsFocused(hDev)   (((hDev)->p_stState->ucStatus & INO_C_ucAcquired) != 0)
#define INO_M_bDeviceReady(hDev) (((hDev)->p_stState->ucStatus & (INO_C_ucConnected | INO_C_ucAcquired)) \
                                  == (INO_C_ucConnected | INO_C_ucAcquired))

extern unsigned short *INO_g_uwActiveKeyNumber;
extern unsigned short *INO_g_a_wActiveKey;

short __cdecl INO_fn_wInit(HINSTANCE hInstance, HWND hWindow);            /* 0x00494CF0 */
INO_tdhDevice __cdecl INO_fn_hCreateDevice(unsigned short uwType, short wHistoricSize); /* 0x00494D90 */
short __cdecl INO_fn_wReleaseDevice(INO_tdhDevice hDevice);              /* 0x00494F90 */
short __cdecl INO_fn_wIsHandleValid(INO_tdhDevice hDev);                 /* 0x00495030 */
short __cdecl INO_fn_wReadAllDevices(unsigned short uwType, short wMode);/* 0x00495080 */
short __cdecl INO_fn_wActivateDevice(INO_tdhDevice hDev);               /* 0x004950F0 */
short __cdecl INO_fn_wGetNbDevices(unsigned short uwType);              /* 0x004955B0 */
short __cdecl INO_fn_wReadKeyboard(INO_tdstDevice *hDevice);            /* 0x00496590 */

short __cdecl INO_pc_bInitDirectInput(HINSTANCE hInstance, HWND hWindow);

/* 0x004953A0 */
short __cdecl INO_pc_wAssignDeviceSlot(INO_tdstDevice *pDevice);

/* 0x00496270 */
short __cdecl INO_fn_wAddActiveKey(short wKey);

/* 0x00495C60 */
short __cdecl INO_pc_wReadMouseDI(INO_tdstDevice *hDevice);

/* 0x004960E0 */
unsigned long __cdecl INO_pc_ulGetHistoricRecordFirstDword(INO_tdstDevice *pDevice, short wHistoryNum);

/* 0x004960B0 */
unsigned short __cdecl INO_pc_uwGetHistoricRecordSecondWord(INO_tdstDevice *pDevice, short wHistoryNum);
