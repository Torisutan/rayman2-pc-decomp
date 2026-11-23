#include "IPT/IPT.h"
#include "IPT/IPT_KDef.h"
#include "INO/INO.h"

/* 0x0042EAF0 */
unsigned char __cdecl IPT_fn_bIsKeyWordValid_And(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ucReturn = ((IPT_fn_bIsKeyWordValid(IPT_g_hNextParameter) == IPT_C_TRUE)
              & (IPT_fn_bIsKeyWordValid(IPT_g_hNextParameter) == IPT_C_TRUE))
             ? IPT_C_TRUE : IPT_C_FALSE;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_Or(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ucReturn = ((IPT_fn_bIsKeyWordValid(IPT_g_hNextParameter) == IPT_C_TRUE)
              | (IPT_fn_bIsKeyWordValid(IPT_g_hNextParameter) == IPT_C_TRUE))
             ? IPT_C_TRUE : IPT_C_FALSE;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_Not(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ucReturn = (IPT_fn_bIsKeyWordValid(IPT_g_hNextParameter) == IPT_C_FALSE) ? IPT_C_TRUE : IPT_C_FALSE;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionJustValidated(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ucReturn = (IPT_fn_bIsJustValidated(
                    (IPT_tdstEntryElement *)IPT_g_hNextParameter->u_ElementUnion.hEntryElement)
                == IPT_C_TRUE) ? IPT_C_TRUE : IPT_C_FALSE;
    IPT_g_hNextParameter++;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionJustInvalidated(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ucReturn = (IPT_fn_bIsJustInvalidated(
                    (IPT_tdstEntryElement *)IPT_g_hNextParameter->u_ElementUnion.hEntryElement)
                == IPT_C_TRUE) ? IPT_C_TRUE : IPT_C_FALSE;
    IPT_g_hNextParameter++;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionValidated(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ucReturn = (IPT_fn_bIsValidated(
                    (IPT_tdstEntryElement *)IPT_g_hNextParameter->u_ElementUnion.hEntryElement)
                == IPT_C_TRUE) ? IPT_C_TRUE : IPT_C_FALSE;
    IPT_g_hNextParameter++;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionInvalidated(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ucReturn = (IPT_fn_bIsInvalidated(
                    (IPT_tdstEntryElement *)IPT_g_hNextParameter->u_ElementUnion.hEntryElement)
                == IPT_C_TRUE) ? IPT_C_TRUE : IPT_C_FALSE;
    IPT_g_hNextParameter++;

    return (ucReturn);
}

#define IPT_pc_M_pKbState(hDev)       ((INO_tdstKeyboardState *)(hDev)->p_stState)
#define IPT_pc_M_wKbTab(hDev)         ((short)IPT_pc_M_pKbState(hDev)->wCurrentTab)
#define IPT_pc_M_ucKbKey(hDev, wTab)  \
    (IPT_pc_M_pKbState(hDev)->a_ucTabKey[wTab][IPT_g_hNextParameter->u_ElementUnion.swValue])
#define IPT_pc_M_ucKbKeyNow(hDev)     IPT_pc_M_ucKbKey(hDev, IPT_pc_M_wKbTab(hDev))
#define IPT_pc_M_ucKbKeyBefore(hDev)  IPT_pc_M_ucKbKey(hDev, 1 - IPT_pc_M_wKbTab(hDev))

unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    INO_tdstDevice *hDev = (INO_tdstDevice *)IPT_g_hInputStructure.a_hINODevice[IPT_E_KeyboardDeviceEvent];
    unsigned char   ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    if (IPT_pc_M_ucKbKeyNow(hDev) && !IPT_pc_M_ucKbKeyBefore(hDev))
        ucReturn = IPT_C_TRUE;
    else
        ucReturn = IPT_C_FALSE;

    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    INO_tdstDevice *hDev = (INO_tdstDevice *)IPT_g_hInputStructure.a_hINODevice[IPT_E_KeyboardDeviceEvent];
    unsigned char   ucReturn;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    if (!IPT_pc_M_ucKbKeyNow(hDev) && IPT_pc_M_ucKbKeyBefore(hDev))
        ucReturn = IPT_C_TRUE;
    else
        ucReturn = IPT_C_FALSE;

    IPT_g_hNextParameter++;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    INO_tdstDevice *hDev = (INO_tdstDevice *)IPT_g_hInputStructure.a_hINODevice[IPT_E_KeyboardDeviceEvent];
    unsigned char   ucReturn;
    unsigned char   ucCounter;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    if (IPT_pc_M_ucKbKeyNow(hDev)
        && (ucCounter = IPT_g_hInputStructure.p_ucKeyboardCounter[IPT_g_hNextParameter->u_ElementUnion.swValue])
           >= IPT_g_hNextParameter->ucMinCounterInput
        && ucCounter <= IPT_g_hNextParameter->ucMaxCounterInput)
        ucReturn = IPT_C_TRUE;
    else
        ucReturn = IPT_C_FALSE;

    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    INO_tdstDevice *hDev = (INO_tdstDevice *)IPT_g_hInputStructure.a_hINODevice[IPT_E_KeyboardDeviceEvent];
    unsigned char   ucReturn;
    unsigned char   ucCounter;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    if (!IPT_pc_M_ucKbKeyNow(hDev)
        && (ucCounter = IPT_g_hInputStructure.p_ucKeyboardCounter[IPT_g_hNextParameter->u_ElementUnion.swValue])
           >= IPT_g_hNextParameter->ucMinCounterInput
        && ucCounter <= IPT_g_hNextParameter->ucMaxCounterInput)
        ucReturn = IPT_C_TRUE;
    else
        ucReturn = IPT_C_FALSE;

    IPT_g_hNextParameter++;
    return (ucReturn);
}

#define IPT_pc_pfnPadReadDirs(pDev, n) \
    INO_pc_uwGetHistoricRecordSecondWord((pDev), (short)(n))

#define IPT_pc_pfnPadReadButtons(pDev, n) \
    INO_pc_ulGetHistoricRecordFirstDword((pDev), (short)(n))

#define IPT_pc_M_swAction()             (IPT_g_hNextParameter->u_ElementUnion.swValue)
#define IPT_pc_M_ulButtonFlag()         (IPT_g_ulPadAndJoyButtonFlag[IPT_pc_M_swAction() - IPT_E_PadFirstButton])
#define IPT_pc_M_bButtonOn(ulButtons)   (((ulButtons) & IPT_pc_M_ulButtonFlag()) == IPT_pc_M_ulButtonFlag())
#define IPT_pc_M_bButtonOff(ulButtons)  (((ulButtons) & IPT_pc_M_ulButtonFlag()) != IPT_pc_M_ulButtonFlag())
#define IPT_pc_M_bIsButtonAction()      \
    (IPT_pc_M_swAction() >= IPT_E_PadFirstButton && IPT_pc_M_swAction() <= IPT_E_PadLastButton)
#define IPT_pc_M_ucPadCounter(ulPad)    \
    (IPT_g_hInputStructure.p_ucPadAndJoyCounter[ulPad][IPT_pc_M_swAction()])
#define IPT_pc_M_bPadCounterInRange(ulPad)                                   \
    (IPT_pc_M_ucPadCounter(ulPad) >= IPT_g_hNextParameter->ucMinCounterInput  \
     && IPT_pc_M_ucPadCounter(ulPad) <= IPT_g_hNextParameter->ucMaxCounterInput)

#define IPT_pc_M_uwPadDirs(pState)      ((pState)->uwDirection)
#define IPT_pc_M_ulPadButtons(pState)   ((pState)->ulButtons)

unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;
    INO_pc_tdstJoyState *pState;
    unsigned short uwDirs;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulPadNumber] == IPT_C_ActivatePadDevice)
    {
        pState = (INO_pc_tdstJoyState *)hDev->p_stState;
        uwDirs = ~IPT_pc_pfnPadReadDirs(hDev, 1) & IPT_pc_M_uwPadDirs(pState);
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:    ucReturn = (uwDirs >> 2) & 1; break;
            case IPT_E_PadDown:  ucReturn = (uwDirs >> 3) & 1; break;
            case IPT_E_PadLeft:  ucReturn = uwDirs & 1; break;
            case IPT_E_PadRight: ucReturn = (uwDirs >> 1) & 1; break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOn(IPT_pc_M_ulPadButtons(pState))
                                && IPT_pc_M_bButtonOff(IPT_pc_pfnPadReadButtons(hDev, 1)))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;
    INO_pc_tdstJoyState *pState;
    unsigned short uwDirs;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulPadNumber] == IPT_C_ActivatePadDevice)
    {
        pState = (INO_pc_tdstJoyState *)hDev->p_stState;
        uwDirs = IPT_pc_pfnPadReadDirs(hDev, 1) & ~IPT_pc_M_uwPadDirs(pState);
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:    ucReturn = (uwDirs >> 2) & 1; break;
            case IPT_E_PadDown:  ucReturn = (uwDirs >> 3) & 1; break;
            case IPT_E_PadLeft:  ucReturn = uwDirs & 1; break;
            case IPT_E_PadRight: ucReturn = (uwDirs >> 1) & 1; break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOff(IPT_pc_M_ulPadButtons(pState))
                                && IPT_pc_M_bButtonOn(IPT_pc_pfnPadReadButtons(hDev, 1)))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;
    INO_pc_tdstJoyState *pState;
    unsigned short uwDirs;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulPadNumber] == IPT_C_ActivatePadDevice)
    {
        pState = (INO_pc_tdstJoyState *)hDev->p_stState;
        uwDirs = IPT_pc_M_uwPadDirs(pState);
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:
                ucReturn = ((uwDirs & 4) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadDown:
                ucReturn = ((uwDirs & 8) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadLeft:
                ucReturn = ((uwDirs & 1) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadRight:
                ucReturn = ((uwDirs & 2) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOn(IPT_pc_M_ulPadButtons(pState))
                                && IPT_pc_M_bPadCounterInRange(ulPadNumber))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;
    INO_pc_tdstJoyState *pState;
    unsigned short uwDirs;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulPadNumber] == IPT_C_ActivatePadDevice)
    {
        pState = (INO_pc_tdstJoyState *)hDev->p_stState;
        uwDirs = ~IPT_pc_M_uwPadDirs(pState);
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:
                ucReturn = ((uwDirs & 4) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadDown:
                ucReturn = ((uwDirs & 8) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadLeft:
                ucReturn = ((uwDirs & 1) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadRight:
                ucReturn = ((uwDirs & 2) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOff(IPT_pc_M_ulPadButtons(pState))
                                && IPT_pc_M_bPadCounterInRange(ulPadNumber))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    return (ucReturn);
}

#define IPT_KW_xJoyAxisScale  (100.0f)

#define IPT_pc_M_lJoyPos(hDev, n)    (((INO_pc_tdstJoyState *)(hDev)->p_stState)->a_lAxis[n])
#define IPT_pc_M_lJoyRange(hDev, n)  (((INO_pc_tdstAxisDeviceCaps *)(hDev)->p_stCaps)->a_stAxis[n].m_lRange)

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickAxeValue(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulJoyNumber;
    unsigned long  ulActionNumber;
    long           lMinValue, lMaxValue;
    float          dfPosition, dfTest;
    INO_tdstDevice *hDev;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulJoyNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    IPT_g_hNextParameter++;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulJoyNumber];
    ulActionNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    IPT_g_hNextParameter++;
    lMinValue = IPT_g_hNextParameter->u_ElementUnion.swValue;
    IPT_g_hNextParameter++;
    lMaxValue = IPT_g_hNextParameter->u_ElementUnion.swValue;

    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulJoyNumber] == IPT_C_ActivateJoystickDevice)
    {
        switch (ulActionNumber)
        {
            case IPT_E_JoyXValue: dfPosition = (float)IPT_pc_M_lJoyPos(hDev, 0) / IPT_pc_M_lJoyRange(hDev, 0); break;
            case IPT_E_JoyYValue: dfPosition = (float)IPT_pc_M_lJoyPos(hDev, 1) / IPT_pc_M_lJoyRange(hDev, 1); break;
            case IPT_E_JoyZValue: dfPosition = (float)IPT_pc_M_lJoyPos(hDev, 2) / IPT_pc_M_lJoyRange(hDev, 2); break;
            case IPT_E_JoyRValue: dfPosition = (float)IPT_pc_M_lJoyPos(hDev, 3) / IPT_pc_M_lJoyRange(hDev, 3); break;
            case IPT_E_JoyUValue: dfPosition = (float)IPT_pc_M_lJoyPos(hDev, 4) / IPT_pc_M_lJoyRange(hDev, 4); break;
            case IPT_E_JoyVValue: dfPosition = (float)IPT_pc_M_lJoyPos(hDev, 5) / IPT_pc_M_lJoyRange(hDev, 5); break;
        }

        dfTest = dfPosition * IPT_KW_xJoyAxisScale;
        ucReturn = ((long)dfTest >= lMinValue && (long)dfTest <= lMaxValue) ? IPT_C_TRUE : IPT_C_FALSE;
        if (ucReturn == IPT_C_TRUE)
            IPT_g_h_ActualEntryInput->xAnalogicValue = dfTest;
    }

    IPT_g_hNextParameter++;
    return (ucReturn);
}

#define IPT_M_JoyOrPadActive(n) \
    (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+(n)] == IPT_C_JoyKeywordDeviceActive || \
     IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+(n)] == IPT_C_ActivatePadDevice)

#define IPT_pc_M_ulJoyButtonFlag()        (IPT_g_ulPadAndJoyButtonFlag[IPT_pc_M_swAction() - IPT_E_JoyFirstButton])
#define IPT_pc_M_bJoyButtonOn(ulButtons)  (((ulButtons) & IPT_pc_M_ulJoyButtonFlag()) == IPT_pc_M_ulJoyButtonFlag())
#define IPT_pc_M_bJoyButtonOff(ulButtons) (((ulButtons) & IPT_pc_M_ulJoyButtonFlag()) != IPT_pc_M_ulJoyButtonFlag())
#define IPT_pc_M_bIsJoyButtonAction()     \
    (IPT_pc_M_swAction() >= IPT_E_JoyFirstButton && IPT_pc_M_swAction() <= IPT_E_JoyLastButton)

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulJoyNumber;
    INO_tdstDevice *hDev;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulJoyNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulJoyNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulJoyNumber] == IPT_C_ActivateJoystickDevice)
    {
        if (IPT_pc_M_bIsJoyButtonAction())
            ucReturn = (IPT_pc_M_bJoyButtonOn(IPT_pc_M_ulPadButtons((INO_pc_tdstJoyState *)hDev->p_stState))
                        && IPT_pc_M_bJoyButtonOff(IPT_pc_pfnPadReadButtons(hDev, 1)))
                       ? IPT_C_TRUE : IPT_C_FALSE;
    }
    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulJoyNumber;
    INO_tdstDevice *hDev;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulJoyNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulJoyNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulJoyNumber] == IPT_C_ActivateJoystickDevice)
    {
        if (IPT_pc_M_bIsJoyButtonAction())
            ucReturn = (IPT_pc_M_bJoyButtonOff(IPT_pc_M_ulPadButtons((INO_pc_tdstJoyState *)hDev->p_stState))
                        && IPT_pc_M_bJoyButtonOn(IPT_pc_pfnPadReadButtons(hDev, 1)))
                       ? IPT_C_TRUE : IPT_C_FALSE;
    }
    IPT_g_hNextParameter++;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulJoyNumber;
    INO_tdstDevice *hDev;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulJoyNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulJoyNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulJoyNumber] == IPT_C_ActivateJoystickDevice)
    {
        if (IPT_pc_M_bIsJoyButtonAction())
            ucReturn = (IPT_pc_M_bJoyButtonOn(IPT_pc_M_ulPadButtons((INO_pc_tdstJoyState *)hDev->p_stState))
                        && IPT_pc_M_bPadCounterInRange(ulJoyNumber))
                       ? IPT_C_TRUE : IPT_C_FALSE;
    }
    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulJoyNumber;
    INO_tdstDevice *hDev;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulJoyNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulJoyNumber];
    IPT_g_hNextParameter++;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_Pad00DeviceEvent+ulJoyNumber] == IPT_C_ActivateJoystickDevice)
    {
        if (IPT_pc_M_bIsJoyButtonAction())
            ucReturn = (IPT_pc_M_bJoyButtonOff(IPT_pc_M_ulPadButtons((INO_pc_tdstJoyState *)hDev->p_stState))
                        && IPT_pc_M_bPadCounterInRange(ulJoyNumber))
                       ? IPT_C_TRUE : IPT_C_FALSE;
    }
    IPT_g_hNextParameter++;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;
    INO_pc_tdstJoyState *pState;
    unsigned short uwDirs;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_M_JoyOrPadActive(ulPadNumber))
    {
        pState = (INO_pc_tdstJoyState *)hDev->p_stState;
        uwDirs = ~IPT_pc_pfnPadReadDirs(hDev, 1) & IPT_pc_M_uwPadDirs(pState);
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:    ucReturn = (uwDirs >> 2) & 1; break;
            case IPT_E_PadDown:  ucReturn = (uwDirs >> 3) & 1; break;
            case IPT_E_PadLeft:  ucReturn = uwDirs & 1; break;
            case IPT_E_PadRight: ucReturn = (uwDirs >> 1) & 1; break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOn(IPT_pc_M_ulPadButtons(pState))
                                && IPT_pc_M_bButtonOff(IPT_pc_pfnPadReadButtons(hDev, 1)))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;
    INO_pc_tdstJoyState *pState;
    unsigned short uwDirs;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_M_JoyOrPadActive(ulPadNumber))
    {
        pState = (INO_pc_tdstJoyState *)hDev->p_stState;
        uwDirs = IPT_pc_pfnPadReadDirs(hDev, 1) & ~IPT_pc_M_uwPadDirs(pState);
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:    ucReturn = (uwDirs >> 2) & 1; break;
            case IPT_E_PadDown:  ucReturn = (uwDirs >> 3) & 1; break;
            case IPT_E_PadLeft:  ucReturn = uwDirs & 1; break;
            case IPT_E_PadRight: ucReturn = (uwDirs >> 1) & 1; break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOff(IPT_pc_M_ulPadButtons(pState))
                                && IPT_pc_M_bButtonOn(IPT_pc_pfnPadReadButtons(hDev, 1)))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    return (ucReturn);
}

#define IPT_pc_M_uwDevDirs(hDev)     IPT_pc_M_uwPadDirs((INO_pc_tdstJoyState *)(hDev)->p_stState)
#define IPT_pc_M_ulDevButtons(hDev)  IPT_pc_M_ulPadButtons((INO_pc_tdstJoyState *)(hDev)->p_stState)

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_M_JoyOrPadActive(ulPadNumber))
    {
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:
                ucReturn = ((IPT_pc_M_uwDevDirs(hDev) & 4) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadDown:
                ucReturn = ((IPT_pc_M_uwDevDirs(hDev) & 8) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadLeft:
                ucReturn = ((IPT_pc_M_uwDevDirs(hDev) & 1) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadRight:
                ucReturn = ((IPT_pc_M_uwDevDirs(hDev) & 2) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOn(IPT_pc_M_ulDevButtons(hDev))
                                && IPT_pc_M_bPadCounterInRange(ulPadNumber))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    IPT_g_ulAnyDeviceInputFlag |= ucReturn;
    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char  ucReturn = IPT_C_FALSE;
    unsigned long  ulPadNumber;
    INO_tdstDevice *hDev;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_Pad00DeviceEvent+ulPadNumber];
    IPT_g_hNextParameter++;
    if (IPT_M_JoyOrPadActive(ulPadNumber))
    {
        switch (IPT_pc_M_swAction())
        {
            case IPT_E_PadUp:
                ucReturn = (!(IPT_pc_M_uwDevDirs(hDev) & 4) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadDown:
                ucReturn = (!(IPT_pc_M_uwDevDirs(hDev) & 8) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadLeft:
                ucReturn = (!(IPT_pc_M_uwDevDirs(hDev) & 1) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            case IPT_E_PadRight:
                ucReturn = (!(IPT_pc_M_uwDevDirs(hDev) & 2) && IPT_pc_M_bPadCounterInRange(ulPadNumber)) ? IPT_C_TRUE : IPT_C_FALSE;
                break;
            default:
                if (IPT_pc_M_bIsButtonAction())
                    ucReturn = (IPT_pc_M_bButtonOff(IPT_pc_M_ulDevButtons(hDev))
                                && IPT_pc_M_bPadCounterInRange(ulPadNumber))
                               ? IPT_C_TRUE : IPT_C_FALSE;
        }
    }
    IPT_g_hNextParameter++;
    return (ucReturn);
}

/* 0x4301F0 */
unsigned char __cdecl IPT_fn_bIsKeyWordValid_Sequence(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn = IPT_C_TRUE;
    unsigned long i;

    IPT_g_ulSequenceAnalyseNumber = 0;
    IPT_g_hNextParameter = _hKeyWordElement + 2;
    for (i = 0; ucReturn && i < _hKeyWordElement[1].u_ElementUnion.ulNumberOfSequence; i++)
        ucReturn = (unsigned char)(ucReturn &
                   ((IPT_fn_bIsKeyWordValid(IPT_g_hNextParameter) == IPT_C_TRUE) ? IPT_C_TRUE : IPT_C_FALSE));

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequenceKey(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn = IPT_C_FALSE;

    IPT_g_hNextParameter = _hKeyWordElement + 1;

    ucReturn = (
                  (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf6DeviceType == IPT_E_KeyboardDeviceEvent)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf2State == IPT_E_Stopped)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].swDeviceValue == IPT_g_hNextParameter->u_ElementUnion.swValue)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter >= IPT_g_hNextParameter->ucMinCounterInput)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter <= IPT_g_hNextParameter->ucMaxCounterInput)
               ) ? IPT_C_TRUE : IPT_C_FALSE;

    IPT_g_hNextParameter++;
    IPT_g_ulSequenceAnalyseNumber++;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequenceKeyEnd(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn = IPT_C_FALSE;

    IPT_g_hNextParameter = _hKeyWordElement + 1;

    ucReturn = (
                  (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf6DeviceType == IPT_E_KeyboardDeviceEvent)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf2State == IPT_E_Stopping)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].swDeviceValue == IPT_g_hNextParameter->u_ElementUnion.swValue)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter >= IPT_g_hNextParameter->ucMinCounterInput)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter <= IPT_g_hNextParameter->ucMaxCounterInput)
               ) ? IPT_C_TRUE : IPT_C_FALSE;

    IPT_g_hNextParameter++;
    IPT_g_ulSequenceAnalyseNumber++;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequencePad(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn = IPT_C_FALSE;
    unsigned long ulPadNumber;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    IPT_g_hNextParameter++;

    ucReturn = (
                  (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf6DeviceType == ulPadNumber + IPT_E_Pad00DeviceEvent)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf2State == IPT_E_Stopped)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].swDeviceValue == IPT_g_hNextParameter->u_ElementUnion.swValue)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter >= IPT_g_hNextParameter->ucMinCounterInput)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter <= IPT_g_hNextParameter->ucMaxCounterInput)
               ) ? IPT_C_TRUE : IPT_C_FALSE;

    IPT_g_hNextParameter++;
    IPT_g_ulSequenceAnalyseNumber++;

    return (ucReturn);
}

unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequencePadEnd(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    unsigned char ucReturn = IPT_C_FALSE;
    unsigned long ulPadNumber;

    IPT_g_hNextParameter = _hKeyWordElement + 1;
    ulPadNumber = IPT_g_hNextParameter->u_ElementUnion.swValue;
    IPT_g_hNextParameter++;

    ucReturn = (
                  (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf6DeviceType == ulPadNumber + IPT_E_Pad00DeviceEvent)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].bf2State == IPT_E_Stopping)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].swDeviceValue == IPT_g_hNextParameter->u_ElementUnion.swValue)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter >= IPT_g_hNextParameter->ucMinCounterInput)
                && (IPT_g_hInputStructure.hEventHistoric[IPT_g_ulSequenceAnalyseNumber].ucCounter <= IPT_g_hNextParameter->ucMaxCounterInput)
               ) ? IPT_C_TRUE : IPT_C_FALSE;

    IPT_g_hNextParameter++;
    IPT_g_ulSequenceAnalyseNumber++;

    return (ucReturn);
}

/* 0x0045FEB0 */
extern long __cdecl _ftol(void);

const unsigned long IPT_KW_ulHundredF       = 0x42C80000UL;             /* 0x0049C698 */
const unsigned long IPT_KW_aulDeadzoneNeg[2] = {0xD2F1A9FCUL, 0xBF50624DUL}; /* 0x0049C6A0 */
const unsigned long IPT_KW_aulDeadzonePos[2] = {0xD2F1A9FCUL, 0x3F50624DUL}; /* 0x0049C6A8 */
const unsigned long IPT_KW_ulZeroF          = 0x00000000UL;             /* 0x0049C6B0 */
const unsigned long IPT_KW_ulRadToDegF      = 0x42652EE1UL;             /* 0x0049C6B4 */
const unsigned long IPT_KW_aulHundredD[2]   = {0x00000000UL, 0x40590000UL}; /* 0x0049C6B8 */
const unsigned long IPT_KW_aulHalfPiD[2]    = {0x54442D17UL, 0x3FE921FBUL}; /* 0x0049C6C0 */
const unsigned long IPT_KW_ulNegRadToDegF   = 0xC2652EE1UL;             /* 0x0049C6C8 */
const unsigned long IPT_KW_ulInv255F        = 0x3B808081UL;             /* 0x0049C6CC */

/* 0x004A0FE0 */
const unsigned long IPT_KW_aulCorrectionTable[46] = {
    0x3F800000, 0x3F800818, 0x3F802058, 0x3F8048BF, 0x3F808134, 0x3F80C9A7,
    0x3F8121FF, 0x3F818A11, 0x3F8201CD, 0x3F8288F0, 0x3F831F58, 0x3F83C4CA,
    0x3F847914, 0x3F853BF3, 0x3F860D2C, 0x3F86EC85, 0x3F87D9A1, 0x3F88D44E,
    0x3F89DC38, 0x3F8AF113, 0x3F8C129D, 0x3F8D4079, 0x3F8E7A5B, 0x3F8FC001,
    0x3F91110E, 0x3F926D40, 0x3F93D439, 0x3F9545B7, 0x3F96C16E, 0x3F984702,
    0x3F99D639, 0x3F9B6EC6, 0x3F9D1056, 0x3F9EBAAE, 0x3FA06D7A, 0x3FA22889,
    0x3FA3EB85, 0x3FA5B635, 0x3FA7885D, 0x3FA961C3, 0x3FAB421C, 0x3FAD293D,
    0x3FAF16E3, 0x3FB10ADD, 0x3FB304EE, 0x3FB504F7
};

#define IPT_C_KeyWordElementSize 8

enum { IPT_C_lAxisCapsRangeOffset = (int)&((INO_pc_tdstAxisDeviceCaps *)0)->a_stAxis
                                  + (int)&((INO_tdstAxisCaps *)0)->m_lRange };

/* 0x0042F390 */
__declspec(naked) unsigned char __cdecl
IPT_fn_bIsKeyWordValid_JoystickAngularValue(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    __asm {
        mov     ecx, dword ptr [esp + 0x4]
        push    ebx
        push    ebp
        push    esi
        lea     esi, [ecx + IPT_C_KeyWordElementSize]
        push    edi
        mov     dword ptr [IPT_g_hNextParameter], esi
        xor     al, al
        movsx   ecx, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        mov     edx, dword ptr IPT_g_hInputStructure.a_hINODevice[ecx*4 + IPT_E_Pad00DeviceEvent*4]
        movsx   edi, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebx, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebp, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        cmp     byte ptr IPT_g_hInputStructure.p_ucValideAndActiveDevice[ecx + IPT_E_Pad00DeviceEvent], IPT_C_ActivateJoystickDevice
        mov     dword ptr [esp + 0x14], ebp
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebp, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        jnz     Lfi

        lea     eax, [edi - 0x4]
        cmp     eax, 0x5
        ja      LdefA
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stState
        lea     edi, [eax*4]INO_pc_tdstJoyState.a_lAxis
        fild    dword ptr [ecx + edi]
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stCaps
        lea     edi, [eax + eax*2]
        lea     edi, [edi*4 + IPT_C_lAxisCapsRangeOffset]
        fidiv   dword ptr [ecx + edi]
        jmp     LaftA
    LdefA:
        fld     dword ptr [esp + 0x14]
    LaftA:

        lea     eax, [ebx - 0x4]
        cmp     eax, 0x5
        ja      LdefB
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stState
        lea     edi, [eax*4]INO_pc_tdstJoyState.a_lAxis
        fild    dword ptr [ecx + edi]
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stCaps
        lea     edi, [eax + eax*2]
        lea     edi, [edi*4 + IPT_C_lAxisCapsRangeOffset]
        fidiv   dword ptr [ecx + edi]
        jmp     LaftB
    LdefB:
        fld     dword ptr [esp + 0x14]
    LaftB:

        fcom    qword ptr [IPT_KW_aulDeadzoneNeg]
        fnstsw  ax
        test    ah, 0x41
        jnz     Lpatan
        fcom    qword ptr [IPT_KW_aulDeadzonePos]
        fnstsw  ax
        test    ah, 0x1
        jz      Lpatan
        fld     st(1)
        fcomp   qword ptr [IPT_KW_aulDeadzoneNeg]
        fnstsw  ax
        test    ah, 0x41
        jnz     Lpatan
        fld     st(1)
        fcomp   qword ptr [IPT_KW_aulDeadzonePos]
        fnstsw  ax
        test    ah, 0x1
        jz      Lpatan
        fstp    st(0)
        fstp    st(0)
        fld     dword ptr [IPT_KW_ulZeroF]
        jmp     Lhaveangle
    Lpatan:
        fxch    st(1)
        fpatan
        fmul    dword ptr [IPT_KW_ulRadToDegF]
    Lhaveangle:
        fld     st(0)
        call    _ftol
        cmp     eax, dword ptr [esp + 0x14]
        jl      Lnv
        cmp     eax, ebp
        jg      Lnv
        mov     al, 0x1
        jmp     Lcv
    Lnv:
        xor     al, al
    Lcv:
        cmp     al, 0x1
        jnz     Ldisc
        mov     edx, dword ptr [IPT_g_h_ActualEntryInput]
        fstp    dword ptr [edx]IPT_tdstEntryElement.xAnalogicValue
        mov     esi, dword ptr [IPT_g_hNextParameter]
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    Ldisc:
        fstp    st(0)
    Lfi:
        add     esi, IPT_C_KeyWordElementSize
        pop     edi
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}

/* 0x0042F590 */
__declspec(naked) unsigned char __cdecl
IPT_fn_bIsKeyWordValid_JoystickTrueNormValue(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    __asm {
        mov     ecx, dword ptr [esp + 0x4]
        push    ebx
        push    ebp
        push    esi
        lea     esi, [ecx + IPT_C_KeyWordElementSize]
        push    edi
        mov     dword ptr [IPT_g_hNextParameter], esi
        xor     al, al
        movsx   ecx, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        mov     edx, dword ptr IPT_g_hInputStructure.a_hINODevice[ecx*4 + IPT_E_Pad00DeviceEvent*4]
        movsx   edi, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebx, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebp, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        cmp     byte ptr IPT_g_hInputStructure.p_ucValideAndActiveDevice[ecx + IPT_E_Pad00DeviceEvent], IPT_C_ActivateJoystickDevice
        mov     dword ptr [esp + 0x14], ebp
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebp, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        jnz     Lfi
        lea     eax, [edi - 0x4]
        cmp     eax, 0x5
        ja      LdefA
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stState
        lea     edi, [eax*4]INO_pc_tdstJoyState.a_lAxis
        fild    dword ptr [ecx + edi]
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stCaps
        lea     edi, [eax + eax*2]
        lea     edi, [edi*4 + IPT_C_lAxisCapsRangeOffset]
        fidiv   dword ptr [ecx + edi]
        jmp     LaftA
    LdefA:
        fld     dword ptr [esp + 0x14]
    LaftA:
        lea     eax, [ebx - 0x4]
        cmp     eax, 0x5
        ja      LdefB
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stState
        lea     edi, [eax*4]INO_pc_tdstJoyState.a_lAxis
        fild    dword ptr [ecx + edi]
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stCaps
        lea     edi, [eax + eax*2]
        lea     edi, [edi*4 + IPT_C_lAxisCapsRangeOffset]
        fidiv   dword ptr [ecx + edi]
        jmp     LaftB
    LdefB:
        fld     dword ptr [esp + 0x14]
    LaftB:

        fld     st(1)
        fld     st(1)
        fxch    st(1)
        fmulp   st(3), st(0)
        fmul    st(0), st(1)
        faddp   st(2), st(0)
        fxch    st(1)
        fsqrt
        fmul    qword ptr [IPT_KW_aulHundredD]
        fxch    st(1)
        fstp    st(0)
        fld     st(0)
        call    _ftol
        cmp     eax, dword ptr [esp + 0x14]
        jl      Lnv
        cmp     eax, ebp
        jg      Lnv
        mov     al, 0x1
        jmp     Lcv
    Lnv:
        xor     al, al
    Lcv:
        cmp     al, 0x1
        jnz     Ldisc
        mov     edx, dword ptr [IPT_g_h_ActualEntryInput]
        fstp    dword ptr [edx]IPT_tdstEntryElement.xAnalogicValue
        mov     esi, dword ptr [IPT_g_hNextParameter]
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    Ldisc:
        fstp    st(0)
    Lfi:
        add     esi, IPT_C_KeyWordElementSize
        pop     edi
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}

/* 0x0042F750 */
__declspec(naked) unsigned char __cdecl
IPT_fn_bIsKeyWordValid_JoystickCorrectedNormValue(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    __asm {
        push    ecx
        mov     ecx, dword ptr [esp + 0x8]
        push    ebx
        push    ebp
        push    esi
        lea     esi, [ecx + IPT_C_KeyWordElementSize]
        push    edi
        mov     dword ptr [IPT_g_hNextParameter], esi
        xor     al, al
        movsx   ecx, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        mov     edx, dword ptr IPT_g_hInputStructure.a_hINODevice[ecx*4 + IPT_E_Pad00DeviceEvent*4]
        movsx   edi, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebx, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebp, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        cmp     byte ptr IPT_g_hInputStructure.p_ucValideAndActiveDevice[ecx + IPT_E_Pad00DeviceEvent], IPT_C_ActivateJoystickDevice
        mov     dword ptr [esp + 0x10], ebp
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebp, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        jnz     Lcexit
        lea     eax, [edi - 0x4]
        cmp     eax, 0x5
        ja      LdefA
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stState
        lea     edi, [eax*4]INO_pc_tdstJoyState.a_lAxis
        fild    dword ptr [ecx + edi]
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stCaps
        lea     edi, [eax + eax*2]
        lea     edi, [edi*4 + IPT_C_lAxisCapsRangeOffset]
        fidiv   dword ptr [ecx + edi]
        jmp     LaftA
    LdefA:
        fld     dword ptr [esp + 0x18]
    LaftA:
        lea     eax, [ebx - 0x4]
        cmp     eax, 0x5
        ja      LdefB
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stState
        lea     edi, [eax*4]INO_pc_tdstJoyState.a_lAxis
        fild    dword ptr [ecx + edi]
        mov     ecx, dword ptr [edx]INO_tdstDevice.p_stCaps
        lea     edi, [eax + eax*2]
        lea     edi, [edi*4 + IPT_C_lAxisCapsRangeOffset]
        fidiv   dword ptr [ecx + edi]
        jmp     LaftB
    LdefB:
        fld     dword ptr [esp + 0x18]
    LaftB:

        fld     st(0)
        fld     st(2)
        fxch    st(1)
        fabs
        fxch    st(1)
        fabs
        fpatan
        fld     st(2)
        fld     st(2)
        fxch    st(1)
        fmul    st(0), st(4)
        fxch    st(2)
        fsub    qword ptr [IPT_KW_aulHalfPiD]
        fxch    st(1)
        fmul    st(0), st(3)
        fxch    st(1)
        fabs
        fxch    st(1)
        faddp   st(2), st(0)
        fsubr   qword ptr [IPT_KW_aulHalfPiD]
        fxch    st(1)
        fsqrt
        fmul    qword ptr [IPT_KW_aulHundredD]
        fxch    st(1)
        fstp    st(3)
        fst     dword ptr [esp + 0x18]
        fxch    st(2)
        fmul    dword ptr [IPT_KW_ulNegRadToDegF]
        call    _ftol
        fld     dword ptr [IPT_KW_ulZeroF]
        fxch    st(2)
        mov     edx, offset IPT_KW_aulCorrectionTable
        shl     eax, 0x2
        sub     edx, eax
        fdiv    dword ptr [edx]
        fxch    st(2)
        fcomp   st(2)
        fnstsw  ax
        test    ah, 0x41
        fstp    st(0)
        jnz     Lge0
        fld     dword ptr [IPT_KW_ulZeroF]
        jmp     Lhavelow
    Lge0:
        fld     st(0)
    Lhavelow:
        fld     dword ptr [IPT_KW_ulHundredF]
        fcomp   st(1)
        fnstsw  ax
        test    ah, 0x1
        fstp    st(0)
        jz      Lnoupper
        fstp    st(0)
        fld     dword ptr [IPT_KW_ulHundredF]
        jmp     Lcresult
    Lnoupper:
        fld     dword ptr [IPT_KW_ulZeroF]
        fcomp   st(1)
        fnstsw  ax
        test    ah, 0x41
        jnz     Lcresult
        fstp    st(0)
        fld     dword ptr [IPT_KW_ulZeroF]
    Lcresult:
        fld     st(0)
        call    _ftol
        cmp     eax, dword ptr [esp + 0x10]
        jl      Lcfail
        cmp     eax, ebp
        jg      Lcfail
        mov     ecx, dword ptr [IPT_g_h_ActualEntryInput]
        mov     al, 0x1
        fstp    dword ptr [ecx]IPT_tdstEntryElement.xAnalogicValue
        mov     esi, dword ptr [IPT_g_hNextParameter]
    Lcexit:
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        pop     ecx
        ret
    Lcfail:
        xor     al, al
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     edi
        pop     esi
        pop     ebp
        fstp    st(0)
        pop     ebx
        pop     ecx
        ret
    }
}

extern INO_tdhDevice __cdecl INO_pc_hCreateMouseDevice(unsigned short uwHistoricSize);
extern short __cdecl INO_pc_wInitMouseState(INO_tdstDevice *pDevice, short hDev);

/* 0x0042E040 */
void __cdecl IPT_pc_fn_vCreateMouseDevice(long _lParam)
{
    INO_tdhDevice hDevice;

    if (IPT_pc_g_bMouseEnabled != 0 && IPT_g_hInputStructure.a_hINODevice[IPT_E_MouseDeviceEvent] == (void *)0)
    {
        hDevice = INO_pc_hCreateMouseDevice(2);
        if (hDevice != (INO_tdhDevice)0 && (hDevice->p_stState->ucStatus & INO_C_ucConnected) != 0)
        {
            IPT_g_hInputStructure.a_hINODevice[IPT_E_MouseDeviceEvent] = hDevice;
            IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_MouseDeviceEvent] = IPT_C_ValideDevice;
            ((INO_pc_tdstMouseState *)hDevice->p_stState)->p_fnInitMouseState = INO_pc_wInitMouseState;
            ((INO_pc_tdstMouseState *)hDevice->p_stState)->p_fnInitMouseState(hDevice, (short)_lParam);
        }
    }
}

/* 0x00430460 */
__declspec(naked) unsigned char __cdecl
IPT_fn_bIsKeyWordValid_MouseAxeValue(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    __asm {
        mov     eax, dword ptr [IPT_pc_g_bMouseEnabled]
        test    eax, eax
        jnz     Lactive
        mov     eax, dword ptr [esp + 0x4]
        add     eax, 4*IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], eax
        xor     al, al
        ret
    Lactive:
        mov     edx, dword ptr [esp + 0x4]
        push    edi
        push    esi
        mov     ecx, dword ptr IPT_g_hInputStructure.a_hINODevice[IPT_E_MouseDeviceEvent*4]
        lea     esi, [edx + IPT_C_KeyWordElementSize]
        mov     dl, byte ptr IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_MouseDeviceEvent]
        mov     dword ptr [IPT_g_hNextParameter], esi
        push    ebx
        movsx   eax, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   edi, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     esi, IPT_C_KeyWordElementSize
        cmp     dl, IPT_C_ActivateMouseDevice
        mov     dword ptr [IPT_g_hNextParameter], esi
        movsx   ebx, word ptr [esi]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        jnz     Ldef
        sub     eax, 0x0
        jz      Lsel0
        dec     eax
        jz      Lsel1
        dec     eax
        jnz     Ldef
        mov     eax, dword ptr [ecx]INO_tdstDevice.p_stState
        fild    dword ptr [eax]INO_pc_tdstMouseState.lRawZ
        fmul    dword ptr [IPT_KW_ulInv255F]
        jmp     Lscale
    Lsel1:
        mov     ecx, dword ptr [ecx]INO_tdstDevice.p_stState
        fild    dword ptr [ecx]INO_pc_tdstMouseState.lRawY
        fmul    dword ptr [IPT_KW_ulInv255F]
        jmp     Lscale
    Lsel0:
        mov     edx, dword ptr [ecx]INO_tdstDevice.p_stState
        fild    dword ptr [edx]INO_pc_tdstMouseState.lRawX
        fmul    dword ptr [IPT_KW_ulInv255F]
        jmp     Lscale
    Ldef:
        fld     dword ptr [esp + 0x10]
    Lscale:
        fmul    dword ptr [IPT_KW_ulHundredF]
        fld     st(0)
        call    _ftol
        cmp     eax, edi
        jl      Lfail
        cmp     eax, ebx
        jg      Lfail
        mov     al, 0x1
        jmp     Lchk
    Lfail:
        xor     al, al
    Lchk:
        cmp     al, 0x1
        jnz     Lng
        mov     ecx, dword ptr [IPT_g_h_ActualEntryInput]
        pop     ebx
        fstp    dword ptr [ecx]IPT_tdstEntryElement.xAnalogicValue
        mov     esi, dword ptr [IPT_g_hNextParameter]
        add     esi, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     esi
        pop     edi
        ret
    Lng:
        add     esi, IPT_C_KeyWordElementSize
        pop     ebx
        mov     dword ptr [IPT_g_hNextParameter], esi
        pop     esi
        fstp    st(0)
        pop     edi
        ret
    }
}

/* 0x00430540 */
__declspec(naked) unsigned char __cdecl
IPT_fn_bIsKeyWordValid_MouseAxePosition(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    __asm {
        mov     eax, dword ptr [IPT_pc_g_bMouseEnabled]
        push    ebx
        xor     bl, bl
        test    eax, eax
        jnz     Lactive
        mov     eax, dword ptr [esp + 0x8]
        add     eax, 4*IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], eax
        xor     al, al
        pop     ebx
        ret
    Lactive:
        mov     ecx, dword ptr [esp + 0x8]
        mov     edx, dword ptr IPT_g_hInputStructure.a_hINODevice[IPT_E_MouseDeviceEvent*4]
        lea     eax, [ecx + IPT_C_KeyWordElementSize]
        mov     dword ptr [IPT_g_hNextParameter], eax
        movsx   ecx, word ptr [eax]IPT_tdstKeyWordElement.u_ElementUnion.swValue
        add     eax, 2*IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], eax
        mov     al, byte ptr IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_MouseDeviceEvent]
        cmp     al, IPT_C_ActivateMouseDevice
        jnz     Ldef
        mov     eax, ecx
        sub     eax, 0x0
        jz      Lsel0
        dec     eax
        jnz     Ldef
        mov     eax, dword ptr [edx]INO_tdstDevice.p_stState
        fld     dword ptr [eax]INO_pc_tdstMouseState.fPosY
        fild    dword ptr [eax]INO_pc_tdstMouseState.lRawY
        jmp     Lcmp
    Lsel0:
        mov     eax, dword ptr [edx]INO_tdstDevice.p_stState
        fld     dword ptr [eax]INO_pc_tdstMouseState.fPosX
        fild    dword ptr [eax]INO_pc_tdstMouseState.lRawX
    Lcmp:
        fmul    dword ptr [IPT_KW_ulInv255F]
        fcomp   dword ptr [IPT_KW_ulZeroF]
        fnstsw  ax
        test    ah, 0x40
        jnz     Lstore
        mov     bl, 0x1
        jmp     Lstore
    Ldef:
        fld     dword ptr [esp + 0x8]
    Lstore:
        fmul    dword ptr [IPT_KW_ulHundredF]
        mov     edx, dword ptr [IPT_g_h_ActualEntryInput]
        fstp    dword ptr [edx]IPT_tdstEntryElement.xAnalogicValue
        mov     eax, dword ptr [IPT_g_hNextParameter]
        add     eax, IPT_C_KeyWordElementSize
        mov     dword ptr [IPT_g_hNextParameter], eax
        mov     al, bl
        pop     ebx
        ret
    }
}

/* 0x004305E0 */
unsigned char __cdecl IPT_fn_bIsKeyWordValid_MouseJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    if (IPT_pc_g_bMouseEnabled == 0)
        IPT_g_hNextParameter = _hKeyWordElement + 2;
    return IPT_C_FALSE;
}

#define IPT_pc_M_ulMouseButtons(hDev)  (((INO_pc_tdstMouseState *)(hDev)->p_stState)->ulButtons)
#define IPT_pc_M_ulMousePrevButtons(hDev)                                              \
    (((INO_pc_tdstMouseRecord *)(hDev)->pvHistoric)                                    \
        [((hDev)->wHistoricHead + (hDev)->wHistoricSize - 1) % (hDev)->wHistoricSize].ulButtons)
#define IPT_pc_M_bMouseJustReleased(hDev, ulBit) \
    (!(IPT_pc_M_ulMouseButtons(hDev) & (ulBit)) && (IPT_pc_M_ulMousePrevButtons(hDev) & (ulBit)))
#define IPT_pc_M_bMouseCounterInRange(uwAction)                                      \
    (IPT_g_hInputStructure.p_ucPadAndJoyCounter[IPT_E_MouseDeviceEvent][uwAction] >= IPT_g_hNextParameter->ucMinCounterInput \
     && IPT_g_hInputStructure.p_ucPadAndJoyCounter[IPT_E_MouseDeviceEvent][uwAction] <= IPT_g_hNextParameter->ucMaxCounterInput)

/* 0x00430600 */
unsigned char __cdecl IPT_fn_bIsKeyWordValid_MouseJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    long            bReturn = IPT_C_FALSE;
    INO_tdstDevice *hDev;
    unsigned short  uwAction;

    if (IPT_pc_g_bMouseEnabled == 0)
    {
        IPT_g_hNextParameter = _hKeyWordElement + 2;
        return IPT_C_FALSE;
    }
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_MouseDeviceEvent];
    IPT_g_hNextParameter = _hKeyWordElement + 1;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_MouseDeviceEvent] == IPT_C_ActivateMouseDevice)
    {
        uwAction = IPT_g_hNextParameter->u_ElementUnion.swValue;
        switch (uwAction)
        {
            case 3: bReturn = IPT_pc_M_bMouseJustReleased(hDev, 1); break;
            case 4: bReturn = IPT_pc_M_bMouseJustReleased(hDev, 2); break;
            case 5: case 6: bReturn = IPT_C_FALSE; break;
            case 7: bReturn = IPT_pc_M_bMouseJustReleased(hDev, 1) || IPT_pc_M_bMouseJustReleased(hDev, 2); break;
            case 8: bReturn = IPT_pc_M_bMouseJustReleased(hDev, 1) && IPT_pc_M_bMouseJustReleased(hDev, 2); break;
        }
        bReturn = bReturn && IPT_pc_M_bMouseCounterInRange(uwAction);
    }
    IPT_g_hNextParameter++;
    return (unsigned char)(bReturn != 0);
}

/* 0x00430790 */
unsigned char __cdecl IPT_fn_bIsKeyWordValid_MousePressed(IPT_tdstKeyWordElement *_hKeyWordElement)
{
    long            bReturn = IPT_C_FALSE;
    INO_tdstDevice *hDev;
    unsigned short  uwAction;

    if (IPT_pc_g_bMouseEnabled == 0)
    {
        IPT_g_hNextParameter = _hKeyWordElement + 2;
        return IPT_C_FALSE;
    }
    hDev = IPT_g_hInputStructure.a_hINODevice[IPT_E_MouseDeviceEvent];
    IPT_g_hNextParameter = _hKeyWordElement + 1;
    if (IPT_g_hInputStructure.p_ucValideAndActiveDevice[IPT_E_MouseDeviceEvent] == IPT_C_ActivateMouseDevice)
    {
        uwAction = IPT_g_hNextParameter->u_ElementUnion.swValue;
        switch (uwAction)
        {
            case 3: bReturn = IPT_pc_M_ulMouseButtons(hDev) & 1; break;
            case 4: bReturn = IPT_pc_M_ulMouseButtons(hDev) & 2; break;
            case 5: bReturn = IPT_C_FALSE; break;
            case 6: bReturn = IPT_pc_M_ulMouseButtons(hDev) & 4; break;
            case 7: bReturn = (IPT_pc_M_ulMouseButtons(hDev) & 1) || (IPT_pc_M_ulMouseButtons(hDev) & 2); break;
            case 8: bReturn = (IPT_pc_M_ulMouseButtons(hDev) & 1) && (IPT_pc_M_ulMouseButtons(hDev) & 2); break;
        }
        bReturn = bReturn && IPT_pc_M_bMouseCounterInRange(uwAction);
    }
    IPT_g_hNextParameter++;
    return (unsigned char)(bReturn == IPT_C_TRUE);
}
