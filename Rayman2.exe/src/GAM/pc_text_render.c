#include "GAM/GAM_types.h"
#include "GLI/Material.h"
#include "GLI/light_fog.h"
#include "GMT/GMT_types.h"
#include "GEO/GeoObj.h"
#include "GEO/Element.h"

#include "GAM/pc_text_render.h"

static unsigned char g_a_ucTextDeviceInfo[96];
#define g_p_stTextDeviceInfo    ((void *)g_a_ucTextDeviceInfo)
/* 0x005115cc */
void *g_hTextVisualMaterial;
void *g_hTextTexture;

GMT_tdxHandleToGameMaterial g_hTextGameMaterial;
GMT_tdxHandleToGameMaterial g_hTextGameMaterialPub;
ACP_tdxHandleOfObject  g_a_hTextGeoObject[10];
ACP_tdxHandleOfElement g_a_xTextElement[10];

#define GAM_C_lNbTextGeoObjects   10
#define GAM_C_lTextObjectNbPoints 100
#define GAM_C_lTextElementNbFaces 0x30

/* 0x00420890 */
long __cdecl GLD_bGetDeviceAttributes(short hDev, void *pstDevAttrib);

void __cdecl FUN_0044c310(short param_1)
{
    float a4_xColor[4];
    ACP_tdxHandleOfObject  *p_hObj;
    ACP_tdxHandleOfElement *p_xElem;
    int iCount;

    if (FUN_0044f4e0() != 1)
    {
        GLI_xCreateMaterial(&g_hTextVisualMaterial);
        a4_xColor[0] = 0.0f;
        a4_xColor[1] = 0.0f;
        a4_xColor[2] = 0.0f;
        a4_xColor[3] = 0.0f;
        GLI_xSetMaterialAmbientCoef(g_hTextVisualMaterial, a4_xColor);
        GLI_xSetMaterialDiffuseCoef(g_hTextVisualMaterial, a4_xColor);
        GLI_xSetMaterialSpecularCoef(g_hTextVisualMaterial, 2, a4_xColor);
        /* 0x00426F40 */
        GLI_xSetLightState(g_hTextVisualMaterial, -1);
    }

    GLD_bGetDeviceAttributes((unsigned long)param_1, g_p_stTextDeviceInfo);

    if (FUN_0044f4e0() != 1)
    {
        GLI_xSetMaterialTexture(g_hTextVisualMaterial, g_hTextTexture);
        g_hTextGameMaterial = GMT_fn_hCreateGameMaterial();
        GMT_fn_vSetVisualMaterial(g_hTextGameMaterial,
                                  (ACP_tdxHandleOfMaterial)g_hTextVisualMaterial);

        p_hObj  = g_a_hTextGeoObject;
        p_xElem = g_a_xTextElement;
        iCount  = GAM_C_lNbTextGeoObjects;
        do {
            GEO_vCreateGeometricObject(p_hObj, GAM_C_lTextObjectNbPoints, 1);
            GEO_vCreateElementIndexedTriangles(*p_hObj, p_xElem,
                GAM_C_lTextElementNbFaces, GAM_C_lTextObjectNbPoints);
            GEO_vSetGameMaterialOfIndexedTriangles(*p_hObj, *p_xElem, g_hTextGameMaterial);
            p_hObj++;
            p_xElem++;
            iCount--;
        } while (iCount != 0);
    }

    g_hTextGameMaterialPub = g_hTextGameMaterial;
}
