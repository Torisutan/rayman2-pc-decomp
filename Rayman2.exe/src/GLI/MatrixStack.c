#include "GLI/MatrixStack.h"
#include "GLI/GLI_globals.h"
#include "POS/POS_types.h"

#include <stddef.h>

/* 0x005048A0 */
static POS_tdstCompletePosition GLI_pc_gs_astMatrixStack[100];
static long                     GLI_pc_gs_lMatrixStackDepth;
#define GLI_pc_g_pstMatrixStack    (GLI_pc_gs_astMatrixStack)
#define GLI_pc_g_lMatrixStackDepth (GLI_pc_gs_lMatrixStackDepth)

void __cdecl GLI_xInitMatrixStack(void)
{
    POS_tdstCompletePosition *p;
    int                       i;

    p = GLI_pc_g_pstMatrixStack;
    for (i = 0; i < 100; i++) {
        p->stTranslationVector.xX = 0.0f;
        p->stTranslationVector.xY = 0.0f;
        p->stTranslationVector.xZ = 0.0f;
        p->stRotationMatrix.stCol_0.xX = 1.0f;
        p->stRotationMatrix.stCol_0.xY = 0.0f;
        p->stRotationMatrix.stCol_0.xZ = 0.0f;
        p->stRotationMatrix.stCol_1.xX = 0.0f;
        p->stRotationMatrix.stCol_1.xY = 1.0f;
        p->stRotationMatrix.stCol_1.xZ = 0.0f;
        p->stRotationMatrix.stCol_2.xX = 0.0f;
        p->stRotationMatrix.stCol_2.xY = 0.0f;
        p->stRotationMatrix.stCol_2.xZ = 1.0f;
        p->stTransformMatrix.stCol_0.xX = 1.0f;
        p->stTransformMatrix.stCol_0.xY = 0.0f;
        p->stTransformMatrix.stCol_0.xZ = 0.0f;
        p->stTransformMatrix.stCol_1.xX = 0.0f;
        p->stTransformMatrix.stCol_1.xY = 1.0f;
        p->stTransformMatrix.stCol_1.xZ = 0.0f;
        p->stTransformMatrix.stCol_2.xX = 0.0f;
        p->stTransformMatrix.stCol_2.xY = 0.0f;
        p->stTransformMatrix.stCol_2.xZ = 1.0f;
        p->ulType = 1;                                    /* 0x42c226 */
        p++;
    }
    /* 0x00506b00 */
    GLI_pc_g_lMatrixStackDepth = 1;
    GLI_g_p_stCurrentMatrix = GLI_pc_g_pstMatrixStack;
}
