#include "GAM/Caps.h"
#include "GAM/GAM_types.h"

#define CAPS_M_hStandardGame(o)   (((struct tdstEngineObject_ *)(o))->h_StandardGame)

#define CAPS_M_ulCapabilities(o)  (CAPS_M_hStandardGame(o)->ubf32Capabilities)

/* 0x00494B50 */
void __cdecl fn_vSetCapabilities(void *p_stObject, unsigned long ubf32Capabilities)
{
    CAPS_M_ulCapabilities(p_stObject) = ubf32Capabilities;
}

/* 0x00494B60 */
unsigned long __cdecl fn_ulGetCapabilities(void *p_stObject)
{
    return CAPS_M_ulCapabilities(p_stObject);
}

/* 0x00494B70 */
void __cdecl fn_vAddCapabilities(void *p_stObject, unsigned long ubf32Capabilities)
{
    CAPS_M_ulCapabilities(p_stObject) |= ubf32Capabilities;
}

/* 0x00494B80 */
void __cdecl fn_vSubCapabilities(void *p_stObject, unsigned long ubf32Capabilities)
{
    CAPS_M_hStandardGame(p_stObject)->ubf32Capabilities -= (CAPS_M_hStandardGame(p_stObject)->ubf32Capabilities & ubf32Capabilities);
}

/* 0x00494BA0 */
void __cdecl fn_vChangeCapabilities(void *p_stObject, unsigned long ubf32Capabilities, long lValue)
{
    switch (lValue)
    {
    case 0:
    case 2:
        CAPS_M_hStandardGame(p_stObject)->ubf32Capabilities |= ubf32Capabilities;
        break;
    case 1:
    case 3:
        CAPS_M_hStandardGame(p_stObject)->ubf32Capabilities = ubf32Capabilities;
        break;
    case 4:
        CAPS_M_hStandardGame(p_stObject)->ubf32Capabilities -= (CAPS_M_hStandardGame(p_stObject)->ubf32Capabilities & ubf32Capabilities);
        break;
    case 5:
        CAPS_M_hStandardGame(p_stObject)->ubf32Capabilities = 0;
        break;
    }
}
