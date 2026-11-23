#include "GLI/DisplayFrame.h"
#include "GLI/GlobalAlpha.h"
#include "GLI/Object.h"
#include "GLI/GLI_globals.h"
#include "GLI/mater_st.h"

void __cdecl GLI_vDisplayFrame(float *p_stTopLeft,
                                float *p_stBottomRight,
                                float  xAlpha,
                                void  *p_stViewport)
{
    float  xSavedAlpha;

    xSavedAlpha = GLI_fn_xGetGlobalAlpha();
    GLI_vSetGlobalAlpha(xAlpha);

    ((struct GLI_tdstMaterial_ *)GLI_pc_g_hDefaultMaterial)->stAmbient.xB = 0.0f;
    ((struct GLI_tdstMaterial_ *)GLI_pc_g_hDefaultMaterial)->stAmbient.xG = 0.0f;
    ((struct GLI_tdstMaterial_ *)GLI_pc_g_hDefaultMaterial)->stAmbient.xR = 0.0f;

    GLI_vDraw2DSpriteWithPercent(
        p_stViewport,
        p_stTopLeft[0],     p_stTopLeft[1],
        p_stBottomRight[0], p_stBottomRight[1],
        GLI_pc_g_hDefaultMaterial);

    GLI_vSetGlobalAlpha(xSavedAlpha);
}
