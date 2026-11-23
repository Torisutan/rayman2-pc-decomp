#include "GLI/Brightness.h"

float GLI_g_xBrightness_storage = 0.5f;            /* 0x4A0488 */
static const unsigned long GLI_K_xOneOver100_bits = 0x3C23D70Au;
#define GLI_g_xBrightness  (GLI_g_xBrightness_storage)
#define GLI_K_xOneOver100  (*(const float *)&GLI_K_xOneOver100_bits)
#define GLI_K_x100         (100.0f)

void __cdecl GLI_fn_vSetBrightness(long lValue)
{
    if (lValue < 0) {
        lValue = 0;
    } else if (lValue >= 100) {
        lValue = 100;
    }
    GLI_g_xBrightness = (float)lValue * GLI_K_xOneOver100;
}

long __cdecl GLI_fn_lGetBrightness(void)
{
    return (long)(GLI_g_xBrightness * GLI_K_x100);
}
