#include "GLI/GLD.h"
#include "GLI/Camera.h"
#include "GLI/Memory.h"
#include "GLI/GLI_globals.h"
#include "GAM/GAM_types.h"
#include "MMG/MMG_pubaccess.h"
#include "MMG/MMG_alloc.h"
#include "ERM/CpaError.h"
#include "TMR/TMR.h"
#include "GLI/cpu_timer.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "GLD/GLD_Pub.h"
#include "GLD/Specif/DevVpt.h"

static void *GLD_pc_gs_a_pDeviceTable[16];
#define GLD_pc_g_a_pDeviceTable (GLD_pc_gs_a_pDeviceTable)

/* 0x0049FC30 */
static unsigned char g_ucGLDModuleId_storage = 0xFF;
#define g_ucGLDModuleId  g_ucGLDModuleId_storage

static unsigned long GLD_pc_g_ulFirstTimeInit_storage = 1;   /* 0x0049FC44 */
#define GLD_pc_g_ulFirstTimeInit  GLD_pc_g_ulFirstTimeInit_storage

static unsigned short GLD_pc_g_wTimerHandle_storage = 0xBEEFu;
static float         GLD_pc_g_xTickToMsScale_storage;
static unsigned long GLD_pc_g_ulFrameTimeAcc722c_storage;
static unsigned long GLD_pc_g_ulFrameTimeAcc7230_storage;
#define GLD_pc_g_wTimerHandle        GLD_pc_g_wTimerHandle_storage
#define GLD_pc_g_xTickToMsScale      GLD_pc_g_xTickToMsScale_storage
#define GLD_pc_g_ulFrameTimeAcc722c  GLD_pc_g_ulFrameTimeAcc722c_storage
#define GLD_pc_g_ulFrameTimeAcc7230  GLD_pc_g_ulFrameTimeAcc7230_storage

/* 0x0049FC54 */
static const char GLD_g_szDriverVersion_storage[] = "V5.9.0 - August 11th 1997";
#define GLD_g_szDriverVersion  GLD_g_szDriverVersion_storage

static unsigned long GLD_g_ulDrawSync720C_storage;   /* 0x4A720C */
static unsigned long GLD_g_ulDrawSync7210_storage;   /* 0x4A7210 */
unsigned long        GLD_g_ulRenderCounter7208_storage; /* 0x4A7208 */
#define GLD_ADDR_720C  (&GLD_g_ulDrawSync720C_storage)
#define GLD_ADDR_7210  (&GLD_g_ulDrawSync7210_storage)
#define GLD_ADDR_7208  (&GLD_g_ulRenderCounter7208_storage)

#include "GLI/devinfo.h"

/* 0x004A7220 */
static unsigned char GLD_pc_g_ucOptionIndex_storage;
static unsigned char GLD_pc_g_ucOptionPercent_storage = 70;
#define GLD_pc_g_ucOptionIndex    GLD_pc_g_ucOptionIndex_storage
#define GLD_pc_g_ucOptionPercent  GLD_pc_g_ucOptionPercent_storage

int __cdecl _stricmp(const char *szA, const char *szB);
int __cdecl atoi(const char *szText);

void __cdecl GLD_vSetFrameSynchro(const char *szKey, const char *szValue, const char *szPercent)
{
    int iValue;

    if (_stricmp(szKey, "OFF") == 0) {
        GLD_pc_g_ucOptionIndex = 0xFF;
    }
    else {
        if (_stricmp(szKey, "ON") == 0) {
            iValue = atoi(szValue);
            if (iValue >= 0 && iValue <= 7) {
                GLD_pc_g_ucOptionIndex = (unsigned char)iValue;
            }
        }
    }
    iValue = atoi(szPercent);
    if (iValue >= 0 && iValue <= 0x64) {
        GLD_pc_g_ucOptionPercent = (unsigned char)iValue;
    }
}

BOOL __cdecl GLD_bIsDeviceHandleValid(short hDev)
{
    if (hDev >= 0 && hDev < 0x10) {
        return GLD_pc_g_a_pDeviceTable[hDev] != 0;
    }
    return FALSE;
}

void * __cdecl GLD_pGetViewport(short hDev, short hOldVP)
{
    struct GLD_stDevice *p_stDevice = ((struct GLD_stDevice **)GLD_pc_g_a_pDeviceTable)[hDev];
    return p_stDevice->pstViewports[hOldVP];
}

void * __cdecl GLD_pc_pGetDevice(short hDev)
{
    return ((void **)GLD_pc_g_a_pDeviceTable)[hDev];
}

long __cdecl GLD_bWriteToViewportFinished(short hDev_unused, short hVpPacked)
{
    int iPacked = (int)hVpPacked;
    short hDev = (short)(iPacked / 16);
    void *p_stDevice = GLD_pc_pGetDevice(hDev);
    ((struct GLD_stDevice *)p_stDevice)->lWriteInProgress = 0;
    (void)hDev_unused;
    return 1;
}

long __cdecl GLD_bClearDeviceWithChoice(short hDev_unused, short choice)
{

    {
        unsigned long ulBusy = *(volatile unsigned long *)GLD_ADDR_720C;
        *(volatile unsigned long *)GLD_ADDR_7210 = 1;
        if (ulBusy != 0) {
            for (;;) {   }
        }
    }
    {
        (*(void (__cdecl **)(int, int, int))GLI_DRV_vClearDevice)(
            (int)(choice & 2), (int)(choice & 1), 0);
    }
    *(volatile unsigned long *)GLD_ADDR_7210 = 0;
    (void)hDev_unused;
    return 1;
}

/* 0x004A721C */
static unsigned long GLD_pc_g_ulViewportClearValue;
#define GLD_PC_VIEWPORT_CLEAR_VALUE  GLD_pc_g_ulViewportClearValue

/* 0x00421620 */
long __cdecl GLD_bSetBackgroundColorForDevice(GLD_tdhDevice hDev,
                                              unsigned long crRGBA)
{
    (void)hDev;
    GLD_PC_VIEWPORT_CLEAR_VALUE = crRGBA;
    return 1;
}

long __cdecl GLD_bClearViewportWithChoice(GLD_tdhDevice hDev_unused,
                                          GLD_tdhViewport hViewport_unused,
                                          short choice)
{
    (*(void (__cdecl **)(int, int, int))GLI_DRV_vClearDevice)(
        (int)(choice & 2), (int)(choice & 1), (int)GLD_PC_VIEWPORT_CLEAR_VALUE);
    (void)hDev_unused;
    (void)hViewport_unused;
    return 1;
}

long __cdecl GLD_bClearDevice(short hDev)
{
    return GLD_bClearDeviceWithChoice(*(unsigned long *)&hDev, 3);
}

long __cdecl GLD_bSetFullScreenModeForDevice(GLD_tdhDevice hDev,
                                          unsigned long ulWidth,
                                          unsigned long ulHeight,
                                          unsigned long ulBpp,
                                          unsigned long ulHWnd)
{
    struct GLD_stDevice *p_stDevice = (struct GLD_stDevice *)GLD_pc_pGetDevice((short)hDev);
    if (!p_stDevice) {
        return 0;
    }
    p_stDevice->stDevAttrib.dwFullScreenModeX = ulWidth;
    p_stDevice->stDevAttrib.dwFullScreenModeY = ulHeight;
    p_stDevice->stDevAttrib.dwFullScreenModeBpp = ulBpp;
    p_stDevice->stDevAttrib.hFullScreenModeWnd = (HANDLE)ulHWnd;
    return 1;
}

long __cdecl GLD_bSwapToWindowedMode(short hDev, int bRebuildMode)
{

    if (*(volatile unsigned long *)GLD_ADDR_7210 != 0) {
        for (;;) {   }
    }
    *(volatile unsigned long *)GLD_ADDR_720C = 1;

    {
        unsigned long *p_ulDevice =
            (unsigned long *)GLD_pc_pGetDevice((short)hDev);
        if (!p_ulDevice) {
            *(volatile unsigned long *)GLD_ADDR_720C = 0;
            return 0;
        }
        p_ulDevice[0xc] = 1;

        if (bRebuildMode == 0) {
            (*(void (__cdecl **)(unsigned long, int))&GLI_DRV_g_vActivateGli)(p_ulDevice[0xb], 1);
            *(volatile unsigned long *)GLD_ADDR_720C = 0;
            return 1;
        }

        {
            long lResult;
            (*(void (__cdecl **)(unsigned long))&GLI_DRV_g_vPrepareForGliFullScreen)(p_ulDevice[10]);
            lResult = GLD_pc_bRecreateDevice(hDev, p_ulDevice);
            *(volatile unsigned long *)GLD_ADDR_720C = 0;
            return lResult;
        }
    }
}

long __cdecl GLD_bSwapDeviceMode(short hDev, int bRebuildMode)
{
    if (*(volatile unsigned long *)GLD_ADDR_7210 != 0) {
        for (;;) {   }
    }
    *(volatile unsigned long *)GLD_ADDR_720C = 1;

    {
        unsigned long *p_ulDevice =
            (unsigned long *)GLD_pc_pGetDevice((short)hDev);
        if (!p_ulDevice) {
            *(volatile unsigned long *)GLD_ADDR_720C = 0;
            return 0;
        }
        p_ulDevice[0xc] = 0;

        if (bRebuildMode == 0) {
            (*(void (__cdecl **)(unsigned long, int))&GLI_DRV_g_vActivateGli)(p_ulDevice[0xb], 0);
            *(volatile unsigned long *)GLD_ADDR_720C = 0;
            return 1;
        }

        {
            long lPrepOk = (*(long (__cdecl **)(unsigned long))&GLI_DRV_g_bPrepareForGliWindowed)(p_ulDevice[0xb]);
            if (lPrepOk == 0) {
                *(volatile unsigned long *)GLD_ADDR_720C = 0;
                return 0;
            }
            {
                long lResult = GLD_pc_bRecreateDevice(hDev, p_ulDevice);
                *(volatile unsigned long *)GLD_ADDR_720C = 0;
                return lResult;
            }
        }
    }
}

typedef struct { unsigned long a[0x18]; } GLD_pc_tdstDevAttrCopy;

long __cdecl GLD_bGetDeviceAttributes(short hDev, void *pstDevAttrib)
{
    GLD_pc_tdstDevAttrCopy *p_stDev;

    *(volatile unsigned long *)GLD_ADDR_7210 = 1;
    if (*(volatile unsigned long *)GLD_ADDR_720C != 0) {
        for (;;) {   }
    }
    p_stDev = (GLD_pc_tdstDevAttrCopy *)GLD_pc_pGetDevice(hDev);
    if (p_stDev == NULL) {
        return 0;
    }
    *(GLD_pc_tdstDevAttrCopy *)pstDevAttrib = *p_stDev;
    *(volatile unsigned long *)GLD_ADDR_7210 = 0;
    return 1;
}

typedef struct { unsigned long a[0x1c]; } GLD_pc_tdstVptAttrCopy;

long __cdecl GLD_bGetViewportAttributes(GLD_tdhDevice hNotUsed, GLD_tdhViewport hVP, void *pstViewAttrib)
{
    short hDev;
    short hOldVP;
    GLD_pc_tdstVptAttrCopy *pstView;

    *(volatile unsigned long *)GLD_ADDR_7210 = 1;
    if (*(volatile unsigned long *)GLD_ADDR_720C != 0) {
        for (;;) {   }
    }
    hDev = (short)(hVP / 16);
    GLD_pc_pGetDevice(hDev);
    hOldVP = (short)(hVP % 16);
    pstView = (GLD_pc_tdstVptAttrCopy *)GLD_pGetViewport(hDev, hOldVP);
    pstView->a[0x19] = (unsigned long)-1;
    pstView->a[0x18] = 0;
    *(GLD_pc_tdstVptAttrCopy *)pstViewAttrib = *pstView;
    *(volatile unsigned long *)GLD_ADDR_7210 = 0;
    return 1;
}

long __cdecl GLD_bReleaseViewportAndDevice(short hDev, short hVP)
{

    GLD_bDeleteViewport(*(unsigned long *)&hDev, *(unsigned long *)&hVP);

    {
        unsigned long ulBusy = *(volatile unsigned long *)GLD_ADDR_720C;
        *(volatile unsigned long *)GLD_ADDR_7210 = 1;
        if (ulBusy != 0) {
            for (;;) {   }
        }
    }

    GLD_bDeleteDevice((short)hDev);
    return 1;
}

long __cdecl GLD_bDeleteViewport(short hDev_unused, short hVpPacked)
{
    int           iSignedPacked;
    short         sDev;
    short         sVp;
    int          *pDevice;
    int          *pViewport;
    int          *p_iScribble;
    int           iScribbleCount;

    *(volatile unsigned long *)GLD_ADDR_7210 = 1;
    if (*(volatile unsigned long *)GLD_ADDR_720C != 0) {
        for (;;) {   }
    }

    iSignedPacked = (int)(short)hVpPacked;
    sDev          = (short)(iSignedPacked / 16);
    pDevice       = (int *)GLD_pc_pGetDevice(sDev);

    sVp           = (short)(iSignedPacked % 16);
    pViewport = (int *)GLD_pGetViewport(sDev, sVp);

    p_iScribble = pViewport;
    for (iScribbleCount = 0x1d; iScribbleCount != 0; iScribbleCount--) {
        *p_iScribble = (int)0xCCCCCCCCu;
        p_iScribble++;
    }

    {
        DWORD (__cdecl *pfnChannelForTid)(DWORD, char) =
            (DWORD (__cdecl *)(DWORD, char))Mmg_fn_ucGiveChannelId;

        Mmg_fn_v_SetModeAlloc(g_ucGLDModuleId, 0xff, pfnChannelForTid(GetCurrentThreadId(), 0));
        fn_vGenFree(pViewport, pfnChannelForTid(GetCurrentThreadId(), 0));
    }

    ((struct GLD_stDevice *)pDevice)->pstViewports[sVp] = 0;

    *(volatile unsigned long *)GLD_ADDR_7210 = 0;
    (void)hDev_unused;
    return 1;
}

long __cdecl GLD_bDeleteDevice(short hDev)
{
    int          *pDevice;
    int          *pSlot;
    int           iSlotCount;
    int          *p_iScribble;
    int           iScribbleCount;

    pDevice = (int *)GLD_pc_pGetDevice(hDev);

    if (*(volatile unsigned long *)GLD_ADDR_720C == 0) {
        pSlot = pDevice + 0x18;
        iSlotCount = 0x10;
        do {
            if (*pSlot != 0) {
                int *pVp = (int *)*pSlot;
                p_iScribble = pVp;
                for (iScribbleCount = 0x1d; iScribbleCount != 0; iScribbleCount--) {
                    *p_iScribble = (int)0xCCCCCCCCu;
                    p_iScribble++;
                }
                *pSlot = 0;
            }
            pSlot++;
            iSlotCount--;
        } while (iSlotCount != 0);
    }

    p_iScribble = pDevice;
    for (iScribbleCount = 0x30; iScribbleCount != 0; iScribbleCount--) {
        *p_iScribble = (int)0xCCCCCCCCu;
        p_iScribble++;
    }

    {
        DWORD (__cdecl *pfnChannelForTid)(DWORD, char) =
            (DWORD (__cdecl *)(DWORD, char))Mmg_fn_ucGiveChannelId;

        Mmg_fn_v_SetModeAlloc(g_ucGLDModuleId, 0xff, pfnChannelForTid(GetCurrentThreadId(), 0));
        fn_vGenFree(pDevice, pfnChannelForTid(GetCurrentThreadId(), 0));
    }

    ((int *)GLD_pc_g_a_pDeviceTable)[hDev] = 0;
    return 1;
}

typedef struct GLD_tdstViewportAttributes_ GLD_tdstViewportAttributes;

static void fn_vUpdateViewportSizesInPixels( GLD_tdstDevice *p_stDev, GLD_tdstViewport *p_stVP )
{

    int    iLeft, iTop, iRight, iBottom, iClipLeft, iClipRight, iClipTop, iClipBottom, iWidth, iHeight;
    unsigned long ulWidthQ, ulHeightQ;

    ulWidthQ = (p_stVP->stViewAttrib.dwWidthInPercent * (p_stDev->stDevAttrib.dwWidth-1)) / 100;
    ulHeightQ = (p_stVP->stViewAttrib.dwHeightInPercent * (p_stDev->stDevAttrib.dwHeight-1)) / 100;
    iWidth = 1 + ulWidthQ;
    iHeight = 1 + ulHeightQ;

    p_stVP->stViewAttrib.dwWidth  = iWidth;
    p_stVP->stViewAttrib.dwHeight = iHeight;

    p_stVP->stViewAttrib.dwTopInPixForClip = 0;
    p_stVP->stViewAttrib.dwLeftInPixForClip = 0;
    p_stVP->stViewAttrib.dwBottomInPixForClip = iHeight - 1;
    p_stVP->stViewAttrib.dwRightInPixForClip = iWidth - 1;

    iLeft = p_stVP->stViewAttrib.dwLeftInPixForClip + p_stVP->stViewAttrib.iOffsetPosX;
    iRight = p_stVP->stViewAttrib.dwRightInPixForClip + p_stVP->stViewAttrib.iOffsetPosX;
    iTop = p_stVP->stViewAttrib.dwTopInPixForClip + p_stVP->stViewAttrib.iOffsetPosY;
    iBottom = p_stVP->stViewAttrib.dwBottomInPixForClip + p_stVP->stViewAttrib.iOffsetPosY;

    if((iRight < 0) || (iLeft > (int) (p_stDev->stDevAttrib.dwWidth - 1)))
        p_stVP->stViewAttrib.dwLeftInPixForClip = p_stVP->stViewAttrib.dwRightInPixForClip = 0;
    else if((iBottom < 0) || (iTop > (int) (p_stDev->stDevAttrib.dwHeight-1)))
        p_stVP->stViewAttrib.dwTopInPixForClip = p_stVP->stViewAttrib.dwBottomInPixForClip = 0;
    else
    {
        if(iLeft < 0)
        {
            p_stVP->stViewAttrib.dwLeftInPixForClip = 0;
            p_stVP->stViewAttrib.dwRightInPixForClip = iRight;
        }
        else if(iRight > (int) (p_stDev->stDevAttrib.dwWidth - 1))
        {
            p_stVP->stViewAttrib.dwLeftInPixForClip = iLeft;
            p_stVP->stViewAttrib.dwRightInPixForClip = p_stDev->stDevAttrib.dwWidth - 1;
        }
        else
        {
            p_stVP->stViewAttrib.dwLeftInPixForClip = iLeft;
            p_stVP->stViewAttrib.dwRightInPixForClip = iRight;
        }
        if(iTop < 0)
        {
            p_stVP->stViewAttrib.dwTopInPixForClip = 0;
            p_stVP->stViewAttrib.dwBottomInPixForClip = iBottom;
        }
        else if(iBottom > (int) (p_stDev->stDevAttrib.dwHeight - 1))
        {
            p_stVP->stViewAttrib.dwTopInPixForClip = iTop;
            p_stVP->stViewAttrib.dwBottomInPixForClip = p_stDev->stDevAttrib.dwHeight - 1;
        }
        else
        {
            p_stVP->stViewAttrib.dwTopInPixForClip = iTop;
            p_stVP->stViewAttrib.dwBottomInPixForClip = iBottom;
        }
    }

    iClipTop = (iHeight * p_stVP->stViewAttrib.dwClipTopInPerMille) / 1000;
    iClipBottom = (iHeight * p_stVP->stViewAttrib.dwClipBottomInPerMille) / 1000;
    iClipLeft = (iWidth * p_stVP->stViewAttrib.dwClipLeftInPerMille) / 1000;
    iClipRight = (iWidth * p_stVP->stViewAttrib.dwClipRightInPerMille) / 1000;
    iClipTop += iTop;
    iClipBottom += iTop;
    iClipLeft += iLeft;
    iClipRight += iLeft;

    if(iClipLeft < 0)
        iClipLeft = 0;
    if(iClipTop < 0)
        iClipTop = 0;

    if(iClipRight > (int) (p_stDev->stDevAttrib.dwWidth))
        iClipRight = (p_stDev->stDevAttrib.dwWidth);
    if(iClipBottom > (int) (p_stDev->stDevAttrib.dwHeight))
        iClipBottom = (p_stDev->stDevAttrib.dwHeight);

    p_stVP->stViewAttrib.dwClipTopInPix = iClipTop;
    p_stVP->stViewAttrib.dwClipBottomInPix = iClipBottom;
    p_stVP->stViewAttrib.dwClipLeftInPix = iClipLeft;
    p_stVP->stViewAttrib.dwClipRightInPix = iClipRight;

    p_stVP->bIsLocked = 0;

    p_stVP->stViewAttrib.dwLeftInPix   = p_stVP->stViewAttrib.dwTopInPix = 0;
    p_stVP->stViewAttrib.dwRightInPix  = p_stVP->stViewAttrib.dwWidth;
    p_stVP->stViewAttrib.dwBottomInPix = p_stVP->stViewAttrib.dwHeight;

    (*(void (__cdecl **)(void))GLI_DRV_vNoBlackPolygon)();
    if (p_stVP->stViewAttrib.dwClipTopInPix > 0) {
        (*(void (__cdecl **)(int, int, int, int))GLI_DRV_vAddBlackPolygon)(
            0, 0, (int)p_stVP->stViewAttrib.dwWidth, (int)p_stVP->stViewAttrib.dwClipTopInPix);
    }
    if (p_stVP->stViewAttrib.dwClipBottomInPix < p_stVP->stViewAttrib.dwHeight) {
        (*(void (__cdecl **)(int, int, int, int))GLI_DRV_vAddBlackPolygon)(
            0, (int)p_stVP->stViewAttrib.dwClipBottomInPix,
            (int)p_stVP->stViewAttrib.dwWidth, (int)p_stVP->stViewAttrib.dwHeight);
    }
    if (p_stVP->stViewAttrib.dwClipLeftInPix > 0) {
        (*(void (__cdecl **)(int, int, int, int))GLI_DRV_vAddBlackPolygon)(
            0, 0, (int)p_stVP->stViewAttrib.dwClipLeftInPix, (int)p_stVP->stViewAttrib.dwHeight);
    }
    if (p_stVP->stViewAttrib.dwClipRightInPix < p_stVP->stViewAttrib.dwWidth) {
        (*(void (__cdecl **)(int, int, int, int))GLI_DRV_vAddBlackPolygon)(
            (int)p_stVP->stViewAttrib.dwClipRightInPix, 0,
            (int)p_stVP->stViewAttrib.dwWidth, (int)p_stVP->stViewAttrib.dwHeight);
    }
}

typedef struct { unsigned long a[0x10]; } GLD_pc_tdstVpSlotCopy;
extern void __cdecl SND_PrintUsedStaticMemory(void);
#define GLD_pc_fn_vDebugReport                                                     \
    ((void (__cdecl *)(const char *, const char *, const char *))SND_PrintUsedStaticMemory)

long __cdecl GLD_pc_bRecreateDevice(short hDev, unsigned long *p_ulDevice)
{
    GLD_pc_tdstDevAttrCopy stAttrib;
    GLD_pc_tdstVpSlotCopy  stVpSlots;
    unsigned long          ulSavedBc;
    unsigned long         *p_ulNew;
    unsigned long         *p_ulSlot;
    int                    iSlot;

    stAttrib  = *(GLD_pc_tdstDevAttrCopy *)p_ulDevice;
    stVpSlots = *(GLD_pc_tdstVpSlotCopy *)((GLD_tdstDevice *)p_ulDevice)->pstViewports;
    ulSavedBc = p_ulDevice[0x2f];

    if (GLD_bDeleteDevice(hDev) == 0) {
        *(volatile unsigned long *)GLD_ADDR_720C = 0;
        ERM_fn_vUpdateLastError(0x34, g_ucGLDModuleId, 0, 0x19, -1, 0xFF, 0xFF,
                                (char *)GLD_g_szDriverVersion);
        GLD_pc_fn_vDebugReport("GLD - DevVpt", " GLD_bSwapDeviceMode",
                               "GLD_bDeleteDevice failed");
        return 0;
    }
    if (GLD_bCreateDevice(stAttrib.a, &hDev) == 0) {
        *(volatile unsigned long *)GLD_ADDR_720C = 0;
        GLD_pc_fn_vDebugReport("GLD - DevVpt", " GLD_bSwapDeviceMode",
                               "GLD_bCreateDevice failed");
        return 0;
    }

    p_ulNew = (unsigned long *)GLD_pc_pGetDevice(hDev);
    *(GLD_pc_tdstVpSlotCopy *)((GLD_tdstDevice *)p_ulNew)->pstViewports = stVpSlots;
    p_ulSlot = (unsigned long *)(((GLD_tdstDevice *)p_ulNew)->pstViewports + 15);
    for (iSlot = 0x10; iSlot != 0; iSlot--) {
        if (*p_ulSlot != 0) {
            fn_vUpdateViewportSizesInPixels((GLD_tdstDevice *)p_ulNew,
                                            (GLD_tdstViewport *)(*p_ulSlot));
        }
        p_ulSlot--;
    }
    p_ulNew[0x2f] = ulSavedBc;
    ((void (__cdecl *)(unsigned long, unsigned long, unsigned long, unsigned long))
        GLI_DRV_g_hChangeMode)(0, 0, 0, 0);
    return 1;
}

/* 0x00421420 */
long __cdecl GLD_fn_bChangeDeviceDisplayMode(GLD_tdhDevice hDev)
{
    GLD_pc_tdstDevAttrCopy stAttrib;
    GLD_pc_tdstVpSlotCopy  stVpSlots;
    unsigned long          ulSavedBc;
    unsigned long         *p_ulDevice;
    unsigned long         *p_ulSlot;
    int                    iSlot;

    p_ulDevice = (unsigned long *)GLD_pc_pGetDevice(hDev);
    if (GLI_fn_lIsFullScreenMode() == 0 && ((GLD_tdstDevice *)p_ulDevice)->stDevAttrib.bFullScreen == 0)
        return 1;
    if (GLI_fn_lIsFullScreenMode() != 0 && ((GLD_tdstDevice *)p_ulDevice)->stDevAttrib.bFullScreen != 0 &&
        GLI_fn_lDisplayModeWidth() == ((GLD_tdstDevice *)p_ulDevice)->stDevAttrib.dwFullScreenModeX &&
        GLI_fn_lDisplayModeHeight() == ((GLD_tdstDevice *)p_ulDevice)->stDevAttrib.dwFullScreenModeY)
        return 1;

    stAttrib  = *(GLD_pc_tdstDevAttrCopy *)p_ulDevice;
    stVpSlots = *(GLD_pc_tdstVpSlotCopy *)((GLD_tdstDevice *)p_ulDevice)->pstViewports;
    ulSavedBc = p_ulDevice[0x2f];
    if (*(volatile unsigned long *)GLD_ADDR_7210 != 0) {
        for (;;) {   }
    }
    *(volatile unsigned long *)GLD_ADDR_720C = 1;
    ((GLD_tdstDeviceAttributes *)stAttrib.a)->dwFullScreenModeX = GLI_fn_lDisplayModeWidth();
    ((GLD_tdstDeviceAttributes *)stAttrib.a)->dwFullScreenModeY = GLI_fn_lDisplayModeHeight();

    if (GLD_bDeleteDevice(hDev) == 0) {
        *(volatile unsigned long *)GLD_ADDR_720C = 0;
        ERM_fn_vUpdateLastError(0x34, g_ucGLDModuleId, 0, 0x19, -1, 0xFF, 0xFF,
                                (char *)GLD_g_szDriverVersion);
        GLD_pc_fn_vDebugReport("GLD - DevVpt", " GLD_fn_bChangeDeviceDisplayMode",
                               "GLD_bDeleteDevice failed");
        return 0;
    }
    if (GLD_bCreateDevice(stAttrib.a, &hDev) == 0) {
        *(volatile unsigned long *)GLD_ADDR_720C = 0;
        GLD_pc_fn_vDebugReport("GLD - DevVpt", " GLD_fn_bChangeDeviceDisplayMode",
                               "GLD_bCreateDevice failed");
        return 0;
    }

    p_ulDevice = (unsigned long *)GLD_pc_pGetDevice(hDev);
    *(GLD_pc_tdstVpSlotCopy *)((GLD_tdstDevice *)p_ulDevice)->pstViewports = stVpSlots;
    p_ulSlot = (unsigned long *)(((GLD_tdstDevice *)p_ulDevice)->pstViewports + 15);
    for (iSlot = 0x10; iSlot != 0; iSlot--) {
        if (*p_ulSlot != 0) {
            fn_vUpdateViewportSizesInPixels((GLD_tdstDevice *)p_ulDevice,
                                            (GLD_tdstViewport *)(*p_ulSlot));
        }
        p_ulSlot--;
    }
    p_ulDevice[0x2f] = ulSavedBc;
    *(volatile unsigned long *)GLD_ADDR_720C = 0;
    return 1;
}

long __cdecl GLD_bSetViewportPosition(short hNotUsed, short hVP, void *pstViewAttrib)
{
    short hDev;
    short hOldVP;
    void *p_stDev;
    GLD_tdstViewport *pstView;

    *(volatile unsigned long *)GLD_ADDR_7210 = 1;
    if (*(volatile unsigned long *)GLD_ADDR_720C != 0) {
        for (;;) {   }
    }
    hDev = (short)(hVP / 16);
    p_stDev = GLD_pc_pGetDevice(hDev);
    hOldVP = (short)(hVP % 16);
    pstView = (GLD_tdstViewport *)GLD_pGetViewport(hDev, hOldVP);
    memset(pstView, 0, sizeof(GLD_tdstViewport));
    memcpy(&pstView->stViewAttrib, pstViewAttrib, sizeof(GLD_tdstViewportAttributes));
    fn_vUpdateViewportSizesInPixels((GLD_tdstDevice *)p_stDev, pstView);
    pstView->stViewAttrib.p_cVirtualScreen = NULL;
    pstView->stViewAttrib.lPitch = -1;
    memcpy(pstViewAttrib, &pstView->stViewAttrib, sizeof(GLD_tdstViewportAttributes));
    *(volatile unsigned long *)GLD_ADDR_7210 = 0;
    return 1;
}

/* 0x00420a40 */
long __cdecl fn_bGetVPHandle(GLD_tdhDevice hDev, GLD_tdhViewport *phVP)
{
    GLD_tdhViewport hVP;
    void          **pstDevice;

    pstDevice = (void **)GLD_pc_pGetDevice(hDev);

    for (hVP = 0; hVP < 16; hVP++)
    {
        if (!(pstDevice + 0x60 / 4)[hVP])
        {
            *phVP = hVP;
            return 1;
        }
    }

    *phVP = -1;
    return 0;
}

long __cdecl GLD_bCreateViewport(GLD_tdhDevice  hDev,
                                  unsigned long *p_ulViewAttribs,
                                  GLD_tdhViewport *p_hVP)
{

    void            *p_stDev;
    unsigned long   *pstView;
    GLD_tdhViewport  hOldVP;

    p_stDev = GLD_pc_pGetDevice((short)hDev);
    if (!fn_bGetVPHandle((short)hDev, &hOldVP)) {
        *p_hVP = -1;
        memset(p_ulViewAttribs, 0xCC, 0x70);
        ERM_fn_vUpdateLastError(0x34, g_ucGLDModuleId, 0, 0x20, -1, 0xFF, 0xFF,
                                (char *)GLD_g_szDriverVersion);   /* 0x49FC54 */
        return 0;
    }

    Mmg_fn_v_SetModeAlloc(g_ucGLDModuleId, 0xff, Mmg_fn_ucGiveChannelId(GetCurrentThreadId(), 0));

    pstView = (unsigned long *)((void *(__cdecl *)(unsigned long, unsigned char))fn_p_vGenAlloc)(
                  0x74, Mmg_fn_ucGiveChannelId(GetCurrentThreadId(), 0));
    if (!pstView) {
        *p_hVP = -1;
        memset(p_ulViewAttribs, 0xCC, 0x70);
        return 0;
    }

    memset(pstView, 0, 0x74);
    memcpy(pstView, p_ulViewAttribs, 0x70);
    fn_vUpdateViewportSizesInPixels((GLD_tdstDevice *)p_stDev, (GLD_tdstViewport *)pstView);

    pstView[0]    = pstView[2];
    pstView[1]    = pstView[3];
    pstView[0x1a] = 0;
    pstView[0x18] = 0;
    pstView[0x1c] = 0;
    pstView[0x19] = 0xFFFFFFFFu;
    memcpy(p_ulViewAttribs, pstView, 0x70);

    *(unsigned long **)(((unsigned char **)GLD_pc_g_a_pDeviceTable)[(short)hDev] + 0x60
                        + hOldVP * 4) = pstView;
    *p_hVP = (GLD_tdhViewport)((hDev << 4) + hOldVP);
    return 1;
}

void __cdecl GLD_pc_fn_vExitCallback(void)
{
    GLD_bReleaseViewportAndDevice(0, 0);
    exit(-4);
}

void __cdecl GLD_pc_fn_vRestartFrameTimer(void)
{
    if (GLD_pc_g_wTimerHandle == 0xBEEFu) {
        unsigned long ulFrequency;

        GLD_pc_g_wTimerHandle = TMR_fn_wCreateTimer(1);
        TMR_fn_wGetTimerFrequency(GLD_pc_g_wTimerHandle, &ulFrequency);

        GLD_pc_g_xTickToMsScale = 1000.0f / (float)ulFrequency;
    }

    GLD_pc_g_ulFrameTimeAcc7230 = 0;
    GLD_pc_g_ulFrameTimeAcc722c = 0;
    TMR_fn_wResetTimer((short)GLD_pc_g_wTimerHandle);
    TMR_fn_wStartTimer((short)GLD_pc_g_wTimerHandle);
}

long __cdecl GLD_pc_lComputeWaitFrameForSmoothSynchro(long lMode)
{
    stTimerCount  stCount;
    unsigned long ulBudget;
    unsigned long ulVal;
    unsigned long ulQuotient;

    TMR_fn_wReadTimer(GLD_pc_g_wTimerHandle, &stCount);

    if (stCount.m_ulHighPart == 0) {
        ulBudget = (unsigned long)GLI_pc_g_lTickBudget;
        if ((unsigned char)lMode != 0) {
            ulVal = stCount.m_ulLowPart + ulBudget;
        } else {
            ulVal = (ulBudget >> 1) + stCount.m_ulLowPart;
        }
        ulQuotient = ulVal / ulBudget;

        if (ulQuotient > 1 && ulQuotient < 6) {
            float xParam = GLI_pc_g_stGliCaps.xRefreshRate;

            GLD_pc_g_ulFrameTimeAcc722c = 1;
            GLD_pc_g_ulFrameTimeAcc7230 = (unsigned long)((long)xParam * 15);
        }

        if (GLD_pc_g_ulFrameTimeAcc722c != 0 && ulQuotient == 1) {
            if (--GLD_pc_g_ulFrameTimeAcc7230 == 0) {
                GLD_pc_g_ulFrameTimeAcc722c = 0;
                return 2;   /* 0x420EA1 */
            }
        }
        return 1;
    }
    return 1;
}

void __cdecl GLD_pc_vSimulateFlipSynchroWithoutVSync(long lFrameCount)
{
    stTimerCount  stCount;
    unsigned long ulBudget;
    unsigned long ulTarget;

    TMR_fn_wReadTimer((short)GLD_pc_g_wTimerHandle, &stCount);
    ulBudget = (unsigned long)GLI_pc_g_lTickBudget;

    ulTarget = (unsigned long)(lFrameCount * (long)ulBudget)
             - stCount.m_ulLowPart % ulBudget;

    if (stCount.m_ulHighPart != 0) {
        return;
    }
    if (stCount.m_ulLowPart <= 0) {
        return;
    }

    if ((float)ulTarget * GLD_pc_g_xTickToMsScale >= 500.0f) {
        return;
    }

    ulTarget += stCount.m_ulLowPart;

    do {
        TMR_fn_wReadTimer((short)GLD_pc_g_wTimerHandle, &stCount);
    } while (stCount.m_ulLowPart < ulTarget && stCount.m_ulHighPart == 0);
}

long __cdecl GLD_pc_bFirstTimeInit(void)
{
    int           iSlot;
    void        **ppDeviceTable;

    Erm_fn_vSetCallBackForExit(GLD_pc_fn_vExitCallback);

    if (g_ucGLDModuleId == 0xFF) {
        g_ucGLDModuleId = Erm_fn_ucInitErrMsg();
    }

    Mmg_fn_v_InitMmg(g_ucGLDModuleId, 4, 0x186A0u);
    Mmg_fn_v_SetModeAlloc(g_ucGLDModuleId, 0xFF, 0);

    ppDeviceTable = (void **)GLD_pc_g_a_pDeviceTable;
    for (iSlot = 0; iSlot < 0x10; iSlot++) {
        ppDeviceTable[iSlot] = NULL;
    }

    if ((short)TMR_fn_wInitLibrary() == 0x7FFF) {
        ERM_fn_vUpdateLastError(0x34, g_ucGLDModuleId, 0, 0x36, -1, 0xFF, 0xFF,
                                (char *)GLD_g_szDriverVersion);
        return 0;
    }

    GLD_pc_fn_vRestartFrameTimer();
    return 1;
}

long __cdecl GLD_pc_lFindFreeDeviceHandle(short *p_hDev)
{
    short sSlot;

    for (sSlot = 0; sSlot < 0x10; sSlot++) {
        if (((void **)GLD_pc_g_a_pDeviceTable)[sSlot] == NULL) {
            *p_hDev = sSlot;
            return 1;
        }
    }
    *p_hDev = -1;
    return 0;
}

long __cdecl GLD_bCreateDevice(unsigned long *p_ulDevAttribs, short *p_hDev)
{
    int            iInitOk;
    short          sScan;
    int           *pDevice;
    DWORD          ulTid;
    unsigned char  ucChannel;

    if (p_ulDevAttribs[0xb] == 0) { p_ulDevAttribs[0xb] = p_ulDevAttribs[10]; }
    if (p_ulDevAttribs[10] == 0) { p_ulDevAttribs[10] = p_ulDevAttribs[0xb]; }

    if (GLD_pc_g_ulFirstTimeInit != 0) {
        iInitOk = GLD_pc_bFirstTimeInit();
        if (iInitOk == 0) {
            return 0;
        }
        GLD_pc_g_ulFirstTimeInit = 0;
    }

    if (p_ulDevAttribs[0xc] != 0) {
        for (sScan = 0; sScan < 0x10; sScan++) {
            GLD_tdstDevice *p_stExistingDev = ((GLD_tdstDevice **)GLD_pc_g_a_pDeviceTable)[sScan];
            if (p_stExistingDev != NULL &&
                p_stExistingDev->stDevAttrib.bFullScreen != 0) {
                p_ulDevAttribs[0xc] = 0;
                break;
            }
        }
    }

    {
        DWORD (__cdecl *pfnChannelForTid)(DWORD, char) =
            (DWORD (__cdecl *)(DWORD, char))Mmg_fn_ucGiveChannelId;
        Mmg_fn_v_SetModeAlloc(g_ucGLDModuleId, 0xff, pfnChannelForTid(GetCurrentThreadId(), 0));
        pDevice = (int *)fn_p_vGenAlloc(0xc0, pfnChannelForTid(GetCurrentThreadId(), 0));
    }

    memset(pDevice, 0, 0xc0);

    p_ulDevAttribs[1] = p_ulDevAttribs[7];
    *p_ulDevAttribs   = p_ulDevAttribs[8];

    {
        GLD_pc_lFindFreeDeviceHandle(p_hDev);
    }

    ((int **)GLD_pc_g_a_pDeviceTable)[*p_hDev] = pDevice;

    p_ulDevAttribs[2] = 0x39a3d70au;
    p_ulDevAttribs[3] = 0x39a3d70au;
    p_ulDevAttribs[4] = 0;
    p_ulDevAttribs[5] = 0xffffffffu;

    memcpy(pDevice, p_ulDevAttribs, 0x60);

    pDevice[0x28] = 0;

    pDevice[0x2f] = 0;

    return 1;
}

long __cdecl GLD_bGiveSpecificAttributesToViewport(short hDev_unused,
                                                    short hVpPacked,
                                                    void          *p_vAttribs)
{
    int             iSignedPacked;
    short           sDev;
    short           sVp;
    int            *pViewport;

    iSignedPacked = (int)(short)hVpPacked;
    sDev          = (short)(iSignedPacked / 16);

    (void)GLD_pc_pGetDevice(sDev);

    sVp = (short)(iSignedPacked % 16);

    pViewport = (int *)GLD_pGetViewport(sDev, sVp);
    ((struct GLD_stViewport *)pViewport)->stViewAttrib.p_vSpecificToXD = p_vAttribs;

    (void)hDev_unused;
    return 1;
}

long __cdecl GLD_bRequestWriteToViewport(short hDev_unused,
                                          short hVpPacked,
                                          unsigned long *p_ulOutAttribs,
                                          unsigned long *p_ulOutCanWrite)
{
    int             iSignedPacked;
    short           sDev;
    short           sVp;
    int            *pDevice;
    unsigned long  *pVp;

    *(volatile unsigned long *)GLD_ADDR_7210 = 1;
    if (*(volatile unsigned long *)GLD_ADDR_720C != 0) {
        for (;;) {   }
    }

    iSignedPacked = (int)(short)hVpPacked;
    sDev          = (short)(iSignedPacked / 16);
    pDevice       = (int *)GLD_pc_pGetDevice(sDev);

    sVp           = (short)(iSignedPacked % 16);
    pVp           = (unsigned long *)GLD_pGetViewport(sDev, sVp);

    *p_ulOutCanWrite = 1;
    *(GLD_pc_tdstVptAttrCopy *)p_ulOutAttribs = *(GLD_pc_tdstVptAttrCopy *)pVp;

    ((struct GLD_stDevice *)pDevice)->lWriteInProgress = 1;
    *(volatile unsigned long *)GLD_ADDR_7210 = 0;

    (void)hDev_unused;
    return 1;
}

long __cdecl GLD_bWriteToViewportFinished2D(short hDev_unused,
                                             short hVpPacked)
{
    int             iSignedPacked;
    short           sDev;
    short           sVp;
    int            *pDevice;
    int            *pVp;

    iSignedPacked = (int)(short)hVpPacked;
    sDev          = (short)(iSignedPacked / 16);
    pDevice       = (int *)GLD_pc_pGetDevice(sDev);

    sVp           = (short)(iSignedPacked % 16);
    pVp           = (int *)GLD_pGetViewport(sDev, sVp);

    ((void (__cdecl *)(void))GLI_DRV_g_bUnlockDevice)();

    ((struct GLD_stViewport *)pVp)->bIsLocked = 0;
    ((struct GLD_stDevice *)pDevice)->lWriteInProgress = 0;

    (void)hDev_unused;
    return 1;
}

long __cdecl GLD_bFlipDeviceWithSynchro(GLD_tdhDevice hDev_unused, int eSynchro_unused)
{

    GLD_g_ulRenderCounter7208_storage++;

    GLD_g_ulDrawSync7210_storage = 1;
    while (GLD_g_ulDrawSync720C_storage)
        ;

    {
        void (__cdecl *pfnDrvFlip)(void) =
            (void (__cdecl *)(void))*GLI_DRV_vFlipDeviceWithSyncro_;
        pfnDrvFlip();
    }

    GLD_g_ulDrawSync7210_storage = 0;

    TMR_fn_wResetTimer((short)GLD_pc_g_wTimerHandle);
    TMR_fn_wStartTimer((short)GLD_pc_g_wTimerHandle);

    return 1;
}

long __cdecl GLD_bRequestWriteToViewport2D(short hDev_unused,
                                            short hVpPacked,
                                            unsigned long *p_ulOutAttribs,
                                            long          *p_lOutCanWrite)
{
    int             iSignedPacked;
    short           sDev;
    short           sVp;
    int            *pDevice;
    struct GLD_stViewport *pVp;
    unsigned long  *pCursor;
    int             iLoop;
    long            lDriverOk;

    *(volatile unsigned long *)GLD_ADDR_7210 = 1;
    if (*(volatile unsigned long *)GLD_ADDR_720C != 0) {
        for (;;) {   }
    }

    iSignedPacked = (int)(short)hVpPacked;
    sDev          = (short)(iSignedPacked / 16);
    pDevice       = (int *)GLD_pc_pGetDevice(sDev);

    *p_lOutCanWrite = 0;
    pCursor = p_ulOutAttribs;
    for (iLoop = 0x1c; iLoop != 0; iLoop--) {
        *pCursor = 0xCCCCCCCCu;
        pCursor++;
    }

    sVp      = (short)(iSignedPacked % 16);
    pVp      = (struct GLD_stViewport *)GLD_pGetViewport(sDev, sVp);

    *(GLD_pc_tdstVptAttrCopy *)p_ulOutAttribs = *(GLD_pc_tdstVptAttrCopy *)pVp;

    lDriverOk = ((long (__cdecl *)(unsigned long *, unsigned long *))GLI_DRV_g_bLockDevice)((unsigned long *)&pVp->stViewAttrib.p_cVirtualScreen,
                                                                                         (unsigned long *)&pVp->stViewAttrib.lPitch);
    *p_lOutCanWrite = lDriverOk;

    if (lDriverOk == 1) {

        *(GLD_pc_tdstVptAttrCopy *)p_ulOutAttribs = *(GLD_pc_tdstVptAttrCopy *)pVp;

        pVp->bIsLocked = 1;

        ((struct GLD_stDevice *)pDevice)->lWriteInProgress = 1;
        *(volatile unsigned long *)GLD_ADDR_7210 = 0;
        (void)hDev_unused;
        return 1;
    }

    *(volatile unsigned long *)GLD_ADDR_7210 = 0;
    (void)hDev_unused;
    return 0;
}

void __cdecl GLD_pc_fn_vWriteScanlineRgb24(float *p_xSrc, unsigned char *p_ucDst, unsigned long ulCount)
{
    float *p_xEnd;

    p_xEnd = p_xSrc + ulCount * 4;
    for (; p_xSrc < p_xEnd; p_xSrc += 4) {
        /* 0x0042B430 */
        p_ucDst[0] = (unsigned char)(long)p_xSrc[3];
        p_ucDst++;
        p_ucDst[0] = (unsigned char)(long)p_xSrc[2];
        p_ucDst++;
        p_ucDst[0] = (unsigned char)(long)p_xSrc[1];
        p_ucDst++;
    }
}

void __cdecl GLD_pc_fn_vUnpackScanline16ToFloat(GLD_tdpstPixelFormat p_stFmt, unsigned short *p_usSrc,
                                                float *p_xDst, long lCount, float xScale)
{
    unsigned short *p_usEnd;
    unsigned long ulBitsR;
    unsigned long ulBitsG;
    unsigned long ulBitsB;

    ulBitsR = p_stFmt->lRedNbBits;
    ulBitsG = p_stFmt->lGreenNbBits;
    ulBitsB = p_stFmt->lBlueNbBits;

    p_usEnd = p_usSrc + lCount;
    ulBitsR = 8 - ulBitsR;
    ulBitsG = 8 - ulBitsG;
    ulBitsB = 8 - ulBitsB;
    for (; p_usSrc < p_usEnd; p_usSrc++) {
        p_xDst[1] = (float)((((unsigned long)*p_usSrc >> *(unsigned char *)&p_stFmt->lRedShift)
                             << ulBitsR) & 0xff) * xScale;
        p_xDst[2] = (float)((((unsigned long)*p_usSrc >> *(unsigned char *)&p_stFmt->lGreenShift)
                             << ulBitsG) & 0xff) * xScale;
        p_xDst[3] = (float)((((unsigned long)*p_usSrc >> *(unsigned char *)&p_stFmt->lBlueShift)
                             << ulBitsB) & 0xff) * xScale;
        p_xDst += 4;
    }
    *p_xDst = p_xDst[-4];
    p_xDst++;
    *p_xDst = p_xDst[-4];
    p_xDst++;
    *p_xDst = p_xDst[-4];
    p_xDst++;
    *p_xDst = p_xDst[-4];
}

/* 0x0042B480 */
void __cdecl GLI_pc_fn_vBlendScanlineRGB(float *p_xTable, float *p_xOut,
                                         unsigned long ulCountA, unsigned long ulCountB, float xWeight);

unsigned char GLD_pc_g_a_ucRgbScanline[0x8000];        /* 0x004A72B8 */
unsigned char GLD_pc_g_a_ucFloatRgbScanline[0x8000];   /* 0x004AF2B8 */
static const float GLI_pc_g_xBlendOne;                  /* 0x0049C674 */
extern long __cdecl _ftol(void);

__declspec(naked) void __cdecl GLD_vGetFrontBufferIn24BitsAA(
    short hGLDDevice, short hGLDViewport,
    unsigned long lWidth, unsigned long lHeight,
    unsigned char *p_lBufferDst)
{
    __asm {
        /* 0x0042BD20 */
        sub  esp, 0xe8
        push ebx
        push ebp
        push esi
        mov  esi, dword ptr [esp + 0xfc]
        push edi
        mov  edi, dword ptr [esp + 0xfc]

        push esi
        lea  eax, [esp + 0x4c]
        push edi
        push eax
        call GLD_bGetPixelFormatOfDevice
        add  esp, 0xc

        lea  ecx, [esp + 0x3c]
        push ecx
        lea  edx, [esp + 0x8c]
        push edx
        push esi
        push edi
        call GLD_bRequestWriteToViewport2D
        add  esp, 0x10
        test eax, eax
        jz   epilogue_pop                      /* 0x0042c1b8 */
        mov  eax, dword ptr [esp + 0x3c]
        test eax, eax
        jz   epilogue_pop

        mov  edi, dword ptr [esp + 0xec]
        mov  eax, dword ptr [esp + 0x4c]
        mov  ebp, dword ptr [esp + 0x94]
        sar  edi, 1
        cmp  eax, 0x20
        mov  dword ptr [esp + 0x10], edi
        jnz  not_32bpp

        mov  ecx, dword ptr [esp + 0x108]
        cmp  dword ptr [esp + 0x90], ecx
        jnz  epilogue_pop                      /* 0x0042c1b8 */
        test ecx, ecx
        mov  eax, dword ptr [esp + 0xe8]
        jbe  release_and_return
        mov  edi, dword ptr [esp + 0x104]
        mov  ebp, ecx
        mov  ecx, dword ptr [esp + 0x10c]
    rows_32bpp:
        test edi, edi
        jbe  next_row_32bpp
        mov  esi, edi
    cols_32bpp:
        mov  dl, byte ptr [eax]
        mov  byte ptr [ecx], dl
        mov  dl, byte ptr [eax + 1]
        inc  ecx
        inc  eax
        mov  byte ptr [ecx], dl
        mov  dl, byte ptr [eax + 1]
        inc  ecx
        inc  eax
        mov  byte ptr [ecx], dl
        inc  ecx
        add  eax, 2
        dec  esi
        jnz  cols_32bpp
    next_row_32bpp:
        dec  ebp
        jnz  rows_32bpp
        jmp  release_and_return

    not_32bpp:
        cmp  eax, 0x10
        jnz  release_and_return
        mov  esi, dword ptr [esp + 0x104]
        cmp  ebp, esi
        jbe  width_max_from_src
        mov  ecx, ebp

        mov  dword ptr [esp + 0x30], ecx
        jmp  after_width_max
    width_max_from_src:
        mov  dword ptr [esp + 0x30], esi
        mov  ecx, esi
    after_width_max:
        mov  edx, dword ptr [esp + 0x90]
        mov  eax, dword ptr [esp + 0x108]
        cmp  eax, edx
        mov  ebx, dword ptr [esp + 0xe8]
        jnz  not_equal_h

        test eax, eax
        jbe  release_and_return
        shl  ecx, 2
        lea  edx, [edi + edi*1]
        mov  dword ptr [esp + 0x34], ecx
        mov  dword ptr [esp + 0x24], edx
        mov  dword ptr [esp + 0x18], eax
        jmp  enter_equal_loop
    equal_loop_top:
        mov  ecx, dword ptr [esp + 0x34]
    enter_equal_loop:
        test ecx, ecx
        jbe  skip_zero_equal
        lea  edx, [ecx*4]
        mov  ecx, edx
        shr  ecx, 2
        xor  eax, eax
        mov  edi, OFFSET GLD_pc_g_a_ucRgbScanline
        rep  stosd
        mov  ecx, edx
        shr  ecx, 2
        mov  edi, OFFSET GLD_pc_g_a_ucFloatRgbScanline
        rep  stosd
    skip_zero_equal:
        mov  eax, dword ptr [esp + 0x30]
        push 0x3f800000
        push eax
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        lea  ecx, [esp + 0x54]
        push ebx
        push ecx
        call GLD_pc_fn_vUnpackScanline16ToFloat
        add  esp, 0x14

        push 0x3f800000
        push esi
        push ebp
        push OFFSET GLD_pc_g_a_ucRgbScanline
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        call GLI_pc_fn_vBlendScanlineRGB
        mov  edi, dword ptr [esp + 0x120]
        add  esp, 0x14

        push esi
        push edi
        push OFFSET GLD_pc_g_a_ucRgbScanline
        call GLD_pc_fn_vWriteScanlineRgb24                                /* 0x4A72B8 */
        mov  ecx, dword ptr [esp + 0x30]
        lea  eax, [esi + esi*2]
        add  edi, eax
        mov  eax, dword ptr [esp + 0x24]
        add  esp, 0xc
        add  ebx, ecx
        dec  eax
        mov  dword ptr [esp + 0x10c], edi
        mov  dword ptr [esp + 0x18], eax
        jnz  equal_loop_top
        jmp  release_and_return

    not_equal_h:
        jbe  downscale_branch
        mov  dword ptr [esp + 0x1c], edx
        xor  edx, edx
        cmp  eax, edx
        mov  dword ptr [esp + 0x20], edx
        fild qword ptr [esp + 0x1c]
        mov  dword ptr [esp + 0x1c], eax
        mov  dword ptr [esp + 0x20], edx
        mov  dword ptr [esp + 0x14], edx
        fidiv dword ptr [esp + 0x1c]
        mov  dword ptr [esp + 0x38], edx
        fstp float ptr [esp + 0x18]
        jbe  release_and_return
        mov  edx, dword ptr [esp + 0x10]
        lea  edi, [ecx*4]
        lea  ecx, [edx + edx*1]
        mov  dword ptr [esp + 0x34], edi
        mov  dword ptr [esp + 0x24], ecx
        mov  dword ptr [esp + 0x10], eax
        jmp  enter_upscale_loop
    upscale_loop_top:
        mov  edi, dword ptr [esp + 0x34]
    enter_upscale_loop:
        fld  float ptr [esp + 0x14]
        call _ftol
        cmp  eax, dword ptr [esp + 0x38]
        mov  dword ptr [esp + 0x28], eax
        jz   skip_advance_src
        add  ebx, dword ptr [esp + 0x24]
    skip_advance_src:
        test edi, edi
        mov  dword ptr [esp + 0x38], eax
        jbe  skip_zero_upscale
        mov  ecx, edi
        xor  eax, eax
        mov  edi, OFFSET GLD_pc_g_a_ucRgbScanline
        rep  stosd
    skip_zero_upscale:
        mov  edi, dword ptr [esp + 0x30]
        push 0x3f800000
        push edi
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        lea  edx, [esp + 0x54]
        push ebx
        push edx
        call GLD_pc_fn_vUnpackScanline16ToFloat
        fild dword ptr [esp + 0x3c]
        add  esp, 0x14
        push ecx
        fsubr float ptr [esp + 0x18]

        fstp float ptr [esp + 0x30]
        fld  dword ptr GLI_pc_g_xBlendOne
        fsub float ptr [esp + 0x30]
        fstp float ptr [esp]

        push esi
        push ebp
        push OFFSET GLD_pc_g_a_ucRgbScanline
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        call GLI_pc_fn_vBlendScanlineRGB
        mov  eax, dword ptr [esp + 0x38]
        add  esp, 0x14

        push 0x3f800000
        push edi
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        lea  ecx, [ebx + eax]
        push ecx
        lea  edx, [esp + 0x58]
        push edx
        call GLD_pc_fn_vUnpackScanline16ToFloat
        mov  eax, dword ptr [esp + 0x40]
        add  esp, 0x14

        push eax
        push esi
        push ebp
        push OFFSET GLD_pc_g_a_ucRgbScanline
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        call GLI_pc_fn_vBlendScanlineRGB
        mov  edi, dword ptr [esp + 0x120]
        add  esp, 0x14

        push esi
        push edi
        push OFFSET GLD_pc_g_a_ucRgbScanline
        call GLD_pc_fn_vWriteScanlineRgb24
        fld  float ptr [esp + 0x20]
        fadd float ptr [esp + 0x24]
        lea  eax, [esi + esi*2]
        add  edi, eax
        mov  eax, dword ptr [esp + 0x1c]
        add  esp, 0xc
        fstp float ptr [esp + 0x14]
        dec  eax
        mov  dword ptr [esp + 0x10c], edi
        mov  dword ptr [esp + 0x10], eax
        jnz  upscale_loop_top
        jmp  release_and_return

    downscale_branch:
        cmp  eax, edx
        jnc  release_and_return
        mov  dword ptr [esp + 0x1c], eax
        xor  eax, eax
        mov  dword ptr [esp + 0x20], eax
        fild qword ptr [esp + 0x1c]
        mov  dword ptr [esp + 0x20], eax
        mov  dword ptr [esp + 0x1c], edx
        mov  dword ptr [esp + 0x14], eax
        fidiv dword ptr [esp + 0x1c]
        mov  dword ptr [esp + 0x38], eax
        lea  eax, [ecx*4]
        test eax, eax
        mov  dword ptr [esp + 0x2c], 0
        mov  dword ptr [esp + 0x34], eax
        fstp float ptr [esp + 0x18]
        jbe  skip_zero_downscale
        shl  eax, 2
        mov  ecx, eax
        shr  ecx, 2
        mov  dword ptr [esp + 0x28], eax
        xor  eax, eax
        mov  edi, OFFSET GLD_pc_g_a_ucRgbScanline
        rep  stosd
        mov  ecx, dword ptr [esp + 0x28]
        shr  ecx, 2
        mov  edi, OFFSET GLD_pc_g_a_ucFloatRgbScanline
        rep  stosd
        mov  edi, dword ptr [esp + 0x10]
    skip_zero_downscale:
        test edx, edx
        jbe  release_and_return
        lea  ecx, [edi + edi*1]
        mov  dword ptr [esp + 0x24], ecx
        mov  dword ptr [esp + 0x28], edx
    downscale_loop_top:
        fld  float ptr [esp + 0x14]
        call _ftol
        mov  edi, eax
        cmp  edi, dword ptr [esp + 0x2c]
        mov  dword ptr [esp + 0x1c], edi
        jz   downscale_no_write
        mov  dword ptr [esp + 0x40], edi
        mov  dword ptr [esp + 0x44], 0
        fild qword ptr [esp + 0x40]
        push ecx
        fst  float ptr [esp + 0x14]
        fsub float ptr [esp + 0x3c]
        fstp float ptr [esp]
        push esi
        push ebp
        push OFFSET GLD_pc_g_a_ucRgbScanline
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        call GLI_pc_fn_vBlendScanlineRGB
        mov  edx, dword ptr [esp + 0x120]
        add  esp, 0x14

        push esi
        push edx
        push OFFSET GLD_pc_g_a_ucRgbScanline
        call GLD_pc_fn_vWriteScanlineRgb24
        mov  ecx, dword ptr [esp + 0x40]
        add  esp, 0xc
        test ecx, ecx
        jbe  no_clear_after_write
        xor  eax, eax
        mov  edi, OFFSET GLD_pc_g_a_ucRgbScanline
        rep  stosd
        mov  edi, dword ptr [esp + 0x1c]
    no_clear_after_write:
        mov  ecx, dword ptr [esp + 0x10c]
        fld  float ptr [esp + 0x14]
        fsub float ptr [esp + 0x10]
        mov  eax, esi
        add  eax, ecx
        lea  ecx, [eax + esi*2]
        fstp float ptr [esp + 0x10]
        mov  dword ptr [esp + 0x10c], ecx
        jmp  downscale_after_write
    downscale_no_write:
        mov  edx, dword ptr [esp + 0x18]
        mov  dword ptr [esp + 0x10], edx
    downscale_after_write:
        mov  ecx, dword ptr [esp + 0x30]
        mov  eax, dword ptr [esp + 0x14]
        push 0x3f800000
        push ecx
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        lea  edx, [esp + 0x54]
        push ebx
        push edx
        mov  dword ptr [esp + 0x40], edi
        mov  dword ptr [esp + 0x4c], eax
        call GLD_pc_fn_vUnpackScanline16ToFloat
        mov  eax, dword ptr [esp + 0x24]
        add  esp, 0x14

        push eax
        push esi
        push ebp
        push OFFSET GLD_pc_g_a_ucRgbScanline
        push OFFSET GLD_pc_g_a_ucFloatRgbScanline
        call GLI_pc_fn_vBlendScanlineRGB
        fld  float ptr [esp + 0x28]
        mov  ecx, dword ptr [esp + 0x38]
        fadd float ptr [esp + 0x2c]
        mov  eax, dword ptr [esp + 0x3c]
        add  esp, 0x14
        add  ebx, ecx
        fstp float ptr [esp + 0x14]
        dec  eax
        mov  dword ptr [esp + 0x28], eax
        jnz  downscale_loop_top

    release_and_return:
        mov  ecx, dword ptr [esp + 0x100]
        mov  edx, dword ptr [esp + 0xfc]
        push ecx
        push edx
        call GLD_bWriteToViewportFinished2D
        add  esp, 8
    epilogue_pop:
        pop  edi
        pop  esi
        pop  ebp
        pop  ebx
        add  esp, 0xe8
        ret
    }
}

extern void GLI_xAdjustCameraToViewport(short hDevice, short hViewport, struct GLI_tdstCamera_ *p_stCam);
__declspec(naked) void __cdecl fn_vChangeViewPortPercent(
    unsigned long _ulMode,
    unsigned long _ulWhat,
    unsigned long _ulWidth,
    unsigned long _ulHeight,
    unsigned long _ulClipTop,
    unsigned long _ulClipLeft,
    unsigned long _ulClipBottom,
    unsigned long _ulClipRight,
    int           _iPosX,
    int           _iPosY)
{
    __asm {

        mov  eax, dword ptr [GAM_AA_engine_14C]
        sub  esp, 0x74
        push esi

        push -1
        push eax
        call dword ptr [WaitForSingleObject]    /* 0x49C0F8 */

        mov  esi, dword ptr [esp + 0x7c]
        mov  dx,  word ptr [GAM_AA_engine_D6]
        lea  ecx, [esp + 0x4]
        cmp  esi, 1
        push ecx
        jz   ge1_use_primary
        mov  dx,  word ptr [GAM_AA_engine_150]
    ge1_use_primary:
        mov  ax,  word ptr [GAM_AA_engine_D4]
        push edx
        push eax
        call GLI_xGetViewportCamera             /* 0x00422720 */
        mov  eax, dword ptr [esp + 0x10]
        add  esp, 0xc
        test eax, eax
        jz   ge_release

        mov  dx,  word ptr [GAM_AA_engine_D6]
        mov  ax,  word ptr [GAM_AA_engine_D4]
        lea  ecx, [esp + 0x8]
        push ecx
        push edx
        push eax
        call GLD_bGetViewportAttributes
        mov  eax, dword ptr [esp + 0x8c]
        add  esp, 0xc

        cmp  eax, 1
        jnz  ge_check2
        mov  ecx, dword ptr [esp + 0x84]
        mov  edx, dword ptr [esp + 0x88]
        mov  dword ptr [esp + 0x38], ecx
        mov  dword ptr [esp + 0x3c], edx
        jmp  ge_after_dispatch
    ge_check2:
        cmp  eax, 2
        jnz  ge_check3
        mov  eax, dword ptr [esp + 0x8c]
        mov  ecx, dword ptr [esp + 0x90]
        mov  edx, dword ptr [esp + 0x94]
        mov  dword ptr [esp + 0x50], eax
        mov  eax, dword ptr [esp + 0x98]
        mov  dword ptr [esp + 0x58], ecx
        mov  dword ptr [esp + 0x54], edx
        mov  dword ptr [esp + 0x5c], eax
        jmp  ge_after_dispatch
    ge_check3:
        cmp  eax, 3
        jnz  ge_check4
        mov  ecx, dword ptr [esp + 0x9c]
        mov  edx, dword ptr [esp + 0xa0]
        mov  dword ptr [esp + 0x60], ecx
        jmp  ge_store_posy
    ge_check4:
        cmp  eax, 4
        jnz  ge_after_dispatch

        mov  ecx, dword ptr [esp + 0x14]
        mov  eax, 0x10624dd3
        imul ecx, dword ptr [esp + 0x9c]
        imul ecx
        mov  ecx, dword ptr [esp + 0x10]
        imul ecx, dword ptr [esp + 0xa0]
        sar  edx, 0x6
        mov  eax, edx
        shr  eax, 0x1f
        add  edx, eax
        mov  eax, 0x10624dd3
        mov  dword ptr [esp + 0x60], edx
        imul ecx
        sar  edx, 0x6
        mov  ecx, edx
        shr  ecx, 0x1f
        add  edx, ecx
    ge_store_posy:
        mov  dword ptr [esp + 0x64], edx

    ge_after_dispatch:

        lea  edx, [esp + 0x8]
        cmp  esi, 1
        push edx
        jnz  ge_alt_mode
        mov  ax,  word ptr [GAM_AA_engine_D6]
        mov  cx,  word ptr [GAM_AA_engine_D4]
        push eax
        push ecx
        call GLD_bSetViewportPosition
        mov  edx, dword ptr [esp + 0x10]
        mov  ax,  word ptr [GAM_AA_engine_D6]
        add  esp, 0xc
        push edx
        jmp  ge_publish
    ge_alt_mode:
        mov  ax,  word ptr [GAM_AA_engine_150]
        mov  cx,  word ptr [GAM_AA_engine_D4]
        push eax
        push ecx
        call GLD_bSetViewportPosition
        mov  edx, dword ptr [esp + 0x10]
        mov  ax,  word ptr [GAM_AA_engine_150]
        add  esp, 0xc
        push edx
    ge_publish:
        mov  cx,  word ptr [GAM_AA_engine_D4]
        push eax
        push ecx
        call GLI_xAdjustCameraToViewport        /* 0x004228D0 */
        add  esp, 0xc

    ge_release:
        mov  edx, dword ptr [GAM_AA_engine_14C]
        push 0
        push 1
        push edx
        call dword ptr [ReleaseSemaphore]        /* 0x49C0D8 */
        pop  esi
        add  esp, 0x74
        ret
    }
}

long __cdecl _ftol(void);

static const float GLI_pc_g_xBlendZero = 0.0f;   /* 0x0049C670 */
static const float GLI_pc_g_xBlendOne  = 1.0f;   /* 0x0049C674 */

__declspec(naked) void __cdecl GLI_pc_fn_vBlendScanlineRGB(float *p_xTable,
                                                             float *p_xOut,
                                                             unsigned long ulCountA,
                                                             unsigned long ulCountB,
                                                             float xWeight)
{
    __asm {
        /* 0x0042B480 */
        mov   ecx, dword ptr [esp + 0x0c]
        sub   esp, 8
        push  ebx
        push  ebp
        push  esi
        push  edi
        mov   edi, dword ptr [esp + 0x28]
        cmp   ecx, edi
        jnz   blend_not_equal

        test  ecx, ecx
        jbe   blend_ep_final
        mov   eax, dword ptr [esp + 0x20]
        mov   edx, ecx
        mov   ecx, dword ptr [esp + 0x1c]
        add   eax, 8
blend_eq_loop:
        fld   dword ptr [ecx + 4]
        mov   esi, dword ptr [esp + 0x2c]
        fmul  dword ptr [esp + 0x2c]
        mov   dword ptr [ecx], esi
        add   ecx, 0x10
        add   eax, 0x10
        dec   edx
        fadd  dword ptr [eax - 0x14]
        fstp  dword ptr [eax - 0x14]
        fld   dword ptr [ecx - 8]
        fmul  dword ptr [esp + 0x2c]
        fadd  dword ptr [eax - 0x10]
        fstp  dword ptr [eax - 0x10]
        fld   dword ptr [ecx - 4]
        fmul  dword ptr [esp + 0x2c]
        fadd  dword ptr [eax - 0x0c]
        fstp  dword ptr [eax - 0x0c]
        jnz   blend_eq_loop
        pop   edi
        pop   esi
        pop   ebp
        pop   ebx
        add   esp, 8
        ret

blend_not_equal:
        jbe   blend_case_c

        mov   dword ptr [esp + 0x10], edi
        xor   edi, edi
        cmp   ecx, edi
        mov   dword ptr [esp + 0x14], edi
        fild  qword ptr [esp + 0x10]
        mov   dword ptr [esp + 0x10], ecx
        mov   dword ptr [esp + 0x14], edi
        fidiv dword ptr [esp + 0x10]
        fstp  dword ptr [esp + 0x24]
        fld   dword ptr [GLI_pc_g_xBlendZero]
        jbe   blend_end_pop
        mov   edx, dword ptr [esp + 0x1c]
        mov   ebp, dword ptr [esp + 0x20]
        lea   esi, [edx + 8]
        mov   ebx, ecx
blend_b_loop:
        fld   st(0)
        call  _ftol
        fld   dword ptr [esi - 4]
        mov   edx, dword ptr [esi]
        fld   dword ptr [esi + 4]
        mov   ecx, eax
        shl   ecx, 4
        add   ecx, ebp
        cmp   edi, eax
        mov   dword ptr [esp + 0x1c], edx
        jz    blend_b_same_idx
        mov   dword ptr [esp + 0x10], eax
        mov   dword ptr [esp + 0x14], 0
        fild  qword ptr [esp + 0x10]
        fld   st(0)
        fsub  dword ptr [esp + 0x20]
        fmul  dword ptr [esp + 0x2c]
        fld   st(0)
        fadd  dword ptr [ecx - 0x10]
        fstp  dword ptr [ecx - 0x10]
        fld   st(3)
        fmul  st(0), st(1)
        fadd  dword ptr [ecx - 0x0c]
        fstp  dword ptr [ecx - 0x0c]
        fld   dword ptr [esp + 0x1c]
        fmul  st(0), st(1)
        fadd  dword ptr [ecx - 8]
        fstp  dword ptr [ecx - 8]
        fld   st(2)
        fmul  st(0), st(1)
        fadd  dword ptr [ecx - 4]
        fstp  dword ptr [ecx - 4]
        fstp  st(0)
        fld   st(3)
        _emit 0xDE
        _emit 0xE1
        jmp   blend_b_join
blend_b_same_idx:
        fld   dword ptr [esp + 0x24]
blend_b_join:
        fmul  dword ptr [esp + 0x2c]
        add   esi, 0x10
        dec   ebx
        fld   st(3)
        fstp  dword ptr [esp + 0x20]
        mov   edi, eax
        fld   st(0)
        fadd  dword ptr [ecx]
        fstp  dword ptr [ecx]
        fxch  st(2)
        fmul  st(0), st(2)
        fadd  dword ptr [ecx + 4]
        fstp  dword ptr [ecx + 4]
        fld   dword ptr [esp + 0x1c]
        fmul  st(0), st(2)
        fadd  dword ptr [ecx + 8]
        fstp  dword ptr [ecx + 8]
        fmul  st(0), st(1)
        fadd  dword ptr [ecx + 0x0c]
        fstp  dword ptr [ecx + 0x0c]
        fstp  st(0)
        fadd  dword ptr [esp + 0x24]
        jnz   blend_b_loop
        fstp  st(0)
        pop   edi
        pop   esi
        pop   ebp
        pop   ebx
        add   esp, 8
        ret

blend_case_c:
        xor   ebp, ebp
        cmp   edi, ebp
        mov   dword ptr [esp + 0x10], ecx
        mov   dword ptr [esp + 0x14], ebp
        fild  qword ptr [esp + 0x10]
        mov   dword ptr [esp + 0x10], edi
        mov   dword ptr [esp + 0x14], ebp
        fidiv dword ptr [esp + 0x10]
        fstp  dword ptr [esp + 0x24]
        fld   dword ptr [GLI_pc_g_xBlendZero]
        jbe   blend_end_pop
        mov   ebx, dword ptr [esp + 0x1c]
        mov   esi, dword ptr [esp + 0x20]
blend_c_loop:
        fld   st(0)
        call  _ftol
        mov   dword ptr [esp + 0x10], eax
        mov   dword ptr [esp + 0x14], ebp
        fild  qword ptr [esp + 0x10]
        shl   eax, 4
        add   eax, ebx
        add   esi, 0x10
        dec   edi
        fsubr st(0), st(1)
        fld   dword ptr [GLI_pc_g_xBlendOne]
        fsub  st(0), st(1)
        fld   dword ptr [eax + 4]
        fmul  st(0), st(1)
        fld   dword ptr [eax + 0x14]
        fmul  st(0), st(3)
        faddp st(1), st(0)
        fstp  dword ptr [esp + 0x20]
        fld   dword ptr [eax + 8]
        fmul  st(0), st(1)
        fld   dword ptr [eax + 0x18]
        fmul  st(0), st(3)
        faddp st(1), st(0)
        fstp  dword ptr [esp + 0x1c]
        fld   dword ptr [eax + 0x0c]
        fmul  st(0), st(1)
        fld   dword ptr [eax + 0x1c]
        fmul  st(0), st(3)
        faddp st(1), st(0)
        fstp  st(2)
        fstp  st(0)
        fld   dword ptr [esp + 0x2c]
        fadd  dword ptr [esi - 0x10]
        fstp  dword ptr [esi - 0x10]
        fld   dword ptr [esp + 0x20]
        fmul  dword ptr [esp + 0x2c]
        fadd  dword ptr [esi - 0x0c]
        fstp  dword ptr [esi - 0x0c]
        fld   dword ptr [esp + 0x1c]
        fmul  dword ptr [esp + 0x2c]
        fadd  dword ptr [esi - 8]
        fstp  dword ptr [esi - 8]
        fmul  dword ptr [esp + 0x2c]
        fadd  dword ptr [esi - 4]
        fstp  dword ptr [esi - 4]
        fadd  dword ptr [esp + 0x24]
        jnz   blend_c_loop
blend_end_pop:
        fstp  st(0)
blend_ep_final:
        pop   edi
        pop   esi
        pop   ebp
        pop   ebx
        add   esp, 8
        ret
    }
}
