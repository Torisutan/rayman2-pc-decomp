#include "GLI/GlobalAlpha.h"
#include "GLI/GLI_globals.h"

#include "GLI/GLI_BigGlobals.h"
#define GLI_g_xInternalAlpha (GLI_BIG_GLOBALS->xGlobalAlpha)

#define GLI_K_xZero          (0.0f)
#define GLI_K_x255           (255.0f)

void __cdecl GLI_vSetGlobalAlpha(float xAlpha)
{
    GLI_g_xInternalAlpha = xAlpha * GLI_K_xOneOver255;
    if (GLI_g_xInternalAlpha > 1.0f) {
        GLI_g_xInternalAlpha = 1.0f;
    }
    if (GLI_g_xInternalAlpha < GLI_K_xZero) {
        GLI_g_xInternalAlpha = GLI_K_xZero;
    }
}

float __cdecl GLI_fn_xGetGlobalAlpha(void)
{
    return GLI_g_xInternalAlpha * GLI_K_x255;
}
