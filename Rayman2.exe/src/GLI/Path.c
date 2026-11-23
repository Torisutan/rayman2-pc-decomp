#include "GLI/Path.h"

/* 0x00501540 */
static char GLI_pc_gs_aszTexturePath[0x104];
#define GLI_pc_g_szTexturePath (GLI_pc_gs_aszTexturePath)

char *__cdecl GLI_fn_szGetPathOfTexture(void)
{
    return GLI_pc_g_szTexturePath;
}
