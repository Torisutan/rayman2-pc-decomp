#ifndef __INO_dinput_dx6_h__
#define __INO_dinput_dx6_h__

#define GET_DIDEVICE_TYPE(dwDevType)    LOBYTE(dwDevType)
#define GET_DIDEVICE_SUBTYPE(dwDevType) HIBYTE(dwDevType)

typedef struct DIDEVCAPS_DX3 {
    DWORD   dwSize;
    DWORD   dwFlags;
    DWORD   dwDevType;
    DWORD   dwAxes;
    DWORD   dwButtons;
    DWORD   dwPOVs;
} DIDEVCAPS_DX3, *LPDIDEVCAPS_DX3;

typedef struct DIDEVCAPS {
    DWORD   dwSize;
    DWORD   dwFlags;
    DWORD   dwDevType;
    DWORD   dwAxes;
    DWORD   dwButtons;
    DWORD   dwPOVs;
    DWORD   dwFFSamplePeriod;
    DWORD   dwFFMinTimeResolution;
    DWORD   dwFirmwareRevision;
    DWORD   dwHardwareRevision;
    DWORD   dwFFDriverVersion;
} DIDEVCAPS, *LPDIDEVCAPS;

#define DIDC_ATTACHED           0x00000001

typedef struct DIDEVICEINSTANCEA {
    DWORD   dwSize;
    GUID    guidInstance;
    GUID    guidProduct;
    DWORD   dwDevType;
    CHAR    tszInstanceName[MAX_PATH];
    CHAR    tszProductName[MAX_PATH];
    GUID    guidFFDriver;
    WORD    wUsagePage;
    WORD    wUsage;
} DIDEVICEINSTANCEA, *LPDIDEVICEINSTANCEA;

typedef struct _DIMOUSESTATE {
    LONG    lX;
    LONG    lY;
    LONG    lZ;
    BYTE    rgbButtons[4];
} DIMOUSESTATE, *LPDIMOUSESTATE;

typedef struct DIJOYSTATE {
    LONG    lX;
    LONG    lY;
    LONG    lZ;
    LONG    lRx;
    LONG    lRy;
    LONG    lRz;
    LONG    rglSlider[2];
    DWORD   rgdwPOV[4];
    BYTE    rgbButtons[32];
} DIJOYSTATE, *LPDIJOYSTATE;

typedef struct INO_pc_tdstDIDeviceVtbl_ {
    long          (__stdcall *QueryInterface)(void *This, const void *riid, void **ppvObj);
    unsigned long (__stdcall *AddRef)(void *This);
    unsigned long (__stdcall *Release)(void *This);
    long          (__stdcall *GetCapabilities)(void *This, void *lpDIDevCaps);
    long          (__stdcall *EnumObjects)(void *This, void *lpCallback, void *pvRef,
                                           unsigned long dwFlags);
    long          (__stdcall *GetProperty)(void *This, const void *rguidProp, void *pdiph);
    long          (__stdcall *SetProperty)(void *This, const void *rguidProp, const void *pdiph);
    long          (__stdcall *Acquire)(void *This);
    long          (__stdcall *Unacquire)(void *This);
    long          (__stdcall *GetDeviceState)(void *This, unsigned long cbData, void *lpvData);
    long          (__stdcall *GetDeviceData)(void *This, unsigned long cbObjectData, void *rgdod,
                                             unsigned long *pdwInOut, unsigned long dwFlags);
    long          (__stdcall *SetDataFormat)(void *This, const void *lpdf);
    long          (__stdcall *SetEventNotification)(void *This, void *hEvent);
    long          (__stdcall *SetCooperativeLevel)(void *This, void *hwnd, unsigned long dwFlags);
    long          (__stdcall *GetObjectInfo)(void *This, void *pdidoi, unsigned long dwObj,
                                             unsigned long dwHow);
    long          (__stdcall *GetDeviceInfo)(void *This, void *pdidi);
    long          (__stdcall *RunControlPanel)(void *This, void *hwndOwner, unsigned long dwFlags);
    long          (__stdcall *Initialize)(void *This, void *hinst, unsigned long dwVersion,
                                          const void *rguid);
    long          (__stdcall *CreateEffect)(void *This, const void *rguid, const void *lpeff,
                                            void **ppdeff, void *punkOuter);
    long          (__stdcall *EnumEffects)(void *This, void *lpCallback, void *pvRef,
                                           unsigned long dwEffType);
    long          (__stdcall *GetEffectInfo)(void *This, void *pdei, const void *rguid);
    long          (__stdcall *GetForceFeedbackState)(void *This, unsigned long *pdwOut);
    long          (__stdcall *SendForceFeedbackCommand)(void *This, unsigned long dwFlags);
    long          (__stdcall *EnumCreatedEffectObjects)(void *This, void *lpCallback, void *pvRef,
                                                        unsigned long fl);
    long          (__stdcall *Escape)(void *This, void *pesc);
    long          (__stdcall *Poll)(void *This);
} INO_pc_tdstDIDeviceVtbl;

#endif
