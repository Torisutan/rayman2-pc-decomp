#include <math.h>
#include "GLI/light_fog.h"
#include "GLD/GLD_Pub.h"
#include "GLI/GLI_BigGlobals.h"
#include "GLI/mater_st.h"

extern struct GLI_tdstInternalGlobalValuesFor3dEngine_ *GLI_BIG_GLOBALS;
extern void *GLI_pc_g_hDefaultMaterial;
extern void *GLI_DRV_g_vSetClipWindow;              /* 0x00504534 */
extern void *GLI_DRV_g_xSendElementTIToClip_TRIANGLES; /* 0x00504854 */
extern void __cdecl GLI_vDoMaterialSelection(struct GLI_tdstInternalGlobalValuesFor3dEngine_ *p_stGlobals);
extern unsigned int GAM_g_u4a724c_storage;
extern int          GAM_g_l4a7250_storage;

/* 0x004A0730 */
static float GLI_pc_g_afColourGridParams[11];
static float GLI_pc_g_afColourGridAngle[5];
/* 0x0049C52C */
static const float GLI_pc_g_afColourGridConst[15] =
{
    8.0f, -14.0f, -6.0f, -1.0471976f, -1.5707964f, -2.0943952f, 10.0f, -12.0f,
    -0.9424778f, -0.012271847f, -0.03681554f, -0.024543693f, -0.03365992f, -0.01682996f, -0.01923077f
};

void __cdecl GLI_pc_fn_vInitColourGrid(void)
{
    signed char   acStack_8[6];
    signed char   acStack_10[5];
    double        xA, xB, xC, xD, xE, xS;
    long          lSum, lCol2, lR1, lR2, lR3;
    unsigned long ulEdi, ulEbx;
    GLI_tdstAligned2DVector *pstCell;
    struct GLI_tdstInternalGlobalValuesFor3dEngine_ *pstBig;
    int           i, j;

    xA = GLI_pc_g_afColourGridAngle[0];
    xB = GLI_pc_g_afColourGridAngle[1];
    xC = GLI_pc_g_afColourGridAngle[2];
    for (i = 0; i < 6; i++)
    {
        acStack_8[i] = (signed char)(long)(sin(xB) * GLI_pc_g_afColourGridConst[0]
                                           - sin(xA) * GLI_pc_g_afColourGridConst[1]
                                           - sin(xC) * GLI_pc_g_afColourGridConst[2]);
        xA = xA - GLI_pc_g_afColourGridConst[3];
        xB = xB - GLI_pc_g_afColourGridConst[4];
        xC = xC - GLI_pc_g_afColourGridConst[5];
    }

    xD = GLI_pc_g_afColourGridAngle[3];
    xE = GLI_pc_g_afColourGridAngle[4];
    for (i = 0; i < 5; i++)
    {
        acStack_10[i] = (signed char)(long)(sin(xE) * GLI_pc_g_afColourGridConst[6]
                                            - sin(xD) * GLI_pc_g_afColourGridConst[7]);
        xD = xD - GLI_pc_g_afColourGridConst[4];
        xE = xE - GLI_pc_g_afColourGridConst[8];
    }

    GLI_pc_g_afColourGridAngle[0] = GLI_pc_g_afColourGridAngle[0] - GLI_pc_g_afColourGridConst[9];
    GLI_pc_g_afColourGridAngle[1] = GLI_pc_g_afColourGridAngle[1] - GLI_pc_g_afColourGridConst[10];
    GLI_pc_g_afColourGridAngle[2] = GLI_pc_g_afColourGridAngle[2] - GLI_pc_g_afColourGridConst[11];
    GLI_pc_g_afColourGridAngle[3] = GLI_pc_g_afColourGridAngle[3] - GLI_pc_g_afColourGridConst[12];
    GLI_pc_g_afColourGridAngle[4] = GLI_pc_g_afColourGridAngle[4] - GLI_pc_g_afColourGridConst[13];

    pstCell = GLI_BIG_GLOBALS->GLI_ScreenPoint;
    for (i = 0; i < 5; i++)
    {
        lCol2 = (long)acStack_10[i];
        for (j = 0; j < 6; j++)
        {
            lSum = (long)acStack_8[j] + lCol2;
            pstCell->ulPackedColor = 0xff000000UL;
            xS = (double)lSum;
            if (lSum >= 0)
            {
                lR1 = (long)(GLI_pc_g_afColourGridParams[4]
                             - ((GLI_pc_g_afColourGridParams[8] - GLI_pc_g_afColourGridParams[4]) * xS) * GLI_pc_g_afColourGridConst[14]);
                ulEdi = ((unsigned long)lR1 | 0xffffff00UL) << 16;
                pstCell->ulPackedColor =ulEdi;
                lR2 = (long)(GLI_pc_g_afColourGridParams[5]
                             - ((GLI_pc_g_afColourGridParams[9] - GLI_pc_g_afColourGridParams[5]) * xS) * GLI_pc_g_afColourGridConst[14]);
                ulEbx = ((unsigned long)lR2 << 8) | ulEdi;
                pstCell->ulPackedColor =ulEbx;
                lR3 = (long)(GLI_pc_g_afColourGridParams[6]
                             - ((GLI_pc_g_afColourGridParams[10] - GLI_pc_g_afColourGridParams[6]) * xS) * GLI_pc_g_afColourGridConst[14]);
            }
            else
            {
                lR1 = (long)(GLI_pc_g_afColourGridParams[4]
                             - ((GLI_pc_g_afColourGridParams[4] - GLI_pc_g_afColourGridParams[0]) * xS) * GLI_pc_g_afColourGridConst[14]);
                ulEdi = ((unsigned long)lR1 | 0xffffff00UL) << 16;
                pstCell->ulPackedColor =ulEdi;
                lR2 = (long)(GLI_pc_g_afColourGridParams[5]
                             - ((GLI_pc_g_afColourGridParams[5] - GLI_pc_g_afColourGridParams[1]) * xS) * GLI_pc_g_afColourGridConst[14]);
                ulEbx = ((unsigned long)lR2 << 8) | ulEdi;
                pstCell->ulPackedColor =ulEbx;
                lR3 = (long)(GLI_pc_g_afColourGridParams[6]
                             - ((GLI_pc_g_afColourGridParams[6] - GLI_pc_g_afColourGridParams[2]) * xS) * GLI_pc_g_afColourGridConst[14]);
            }
            pstCell->ulPackedColor =(unsigned long)lR3 | ulEbx;
            pstCell++;
        }
    }

    pstBig = GLI_BIG_GLOBALS;
    pstBig->GLI_ScreenPoint[14].ulPackedColor = 0xff050505UL;
    pstBig->GLI_ScreenPoint[15].ulPackedColor = 0xff050505UL;
    pstBig->GLI_ScreenPoint[20].ulPackedColor = 0xff050505UL;
    pstBig->GLI_ScreenPoint[21].ulPackedColor = 0xff050505UL;
}

static float GLI_pc_g_afColourGridParams[11] =
{
    8.0f, 23.0f, 34.0f, 0.0f, 5.0f, 5.0f, 5.0f, 0.0f, 94.0f, 17.0f, 9.0f
};

void __cdecl GLI_pc_fn_vDisplayMagicMirror(void *pvParam)
{
    struct GLD_tdstViewportAttributes_ *pstFixVpt;
    unsigned long  ulCell;
    unsigned long  ulColStep;
    unsigned long  ulRowStep;
    unsigned long  ulX;
    unsigned long  ulY;
    int            iRow, iCol;

    GLI_vFogOff();
    GLI_BIG_GLOBALS->p_stVpt = 0;
    GLI_BIG_GLOBALS->lHierachDrawMask = (long)0xf7fffbffUL;
    GLI_BIG_GLOBALS->lClippingModeMask = 0;
    GLI_BIG_GLOBALS->p_stObj = (struct GEO_tdstGeometricObject_ *)GAM_g_u4a724c_storage;
    GLI_BIG_GLOBALS->gs_st_CurrentMatrix = 0;
    GLI_BIG_GLOBALS->gs_st_CameraMatrix = 0;
    GLI_BIG_GLOBALS->p_stCurrentCamera = 0;
    GLI_BIG_GLOBALS->hCurrentMaterial = 0;
    ((struct GLI_tdstMaterial_ *)GLI_pc_g_hDefaultMaterial)->p_stTexture = 0;

    pstFixVpt = (struct GLD_tdstViewportAttributes_ *)pvParam;

    (*(void (__cdecl **)(float, float, float, float, void *))&GLI_DRV_g_vSetClipWindow)(
        (float)pstFixVpt->dwClipLeftInPix,
        (float)pstFixVpt->dwClipRightInPix,
        (float)pstFixVpt->dwClipTopInPix,
        (float)pstFixVpt->dwClipBottomInPix,
        (void *)GLI_BIG_GLOBALS);

    GLI_vDoMaterialSelection(GLI_BIG_GLOBALS);

    ulColStep = pstFixVpt->dwWidth / 5;
    ulRowStep = pstFixVpt->dwHeight >> 2;
    ulY = pstFixVpt->dwClipTopInPix;

    ulCell = 0;
    iRow = 5;
    do
    {
        ulX = pstFixVpt->dwClipLeftInPix;
        iCol = 6;
        do
        {
            GLI_BIG_GLOBALS->GLI_ScreenPoint[ulCell].xX = (float)ulX;
            GLI_BIG_GLOBALS->GLI_ScreenPoint[ulCell].xY = (float)ulY;
            *(unsigned long *)&GLI_BIG_GLOBALS->GLI_ScreenPoint[ulCell].xOoZ = 0x38d1b717UL;
            ulCell++;
            ulX = ulX + ulColStep;
        } while (--iCol != 0);
        ulY = ulY + ulRowStep;
    } while (--iRow != 0);

    GLI_pc_fn_vInitColourGrid();

    (*(void (__cdecl **)(int, void *))&GLI_DRV_g_xSendElementTIToClip_TRIANGLES)(
        GAM_g_l4a7250_storage, (void *)GLI_BIG_GLOBALS);
}
