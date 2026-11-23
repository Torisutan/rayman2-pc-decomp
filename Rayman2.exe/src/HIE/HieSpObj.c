#include "HIE/HIE_types.h"
#include "POS/POS_types.h"
#include "GLI/GLI_types.h"
#include "MMG/MMG_alloc.h"
#include "MMG/MMG_pubaccess.h"
#include "ERM/CpaError.h"

#include "GEO/GeoMem.h"
#include <stdlib.h>
#include <string.h>

/* 0x0042dd10 */
static void GEO_fn_vDestroyMatrix(void *hMatrix)
{
    /* 0x0042DD10 */
    GMT_fn_vDestroyFor3DOS((GMT_tdxHandleToGameMaterial)hMatrix);
}

#define HIE_g_p_MmgPoolRangeLo (MMG_g_p_GmtPalBlockInfo->p_cBeginBlock)
#define HIE_g_p_MmgPoolRangeHi (MMG_g_p_GmtPalBlockInfo->p_cEndBlock)

HIE_tdstSuperObject *HIE_fn_hCreateSuperObject(void)
{
    HIE_tdstSuperObject *hNewSuperObject;

    hNewSuperObject = (HIE_tdstSuperObject *)malloc(sizeof(HIE_tdstSuperObject));
    if (hNewSuperObject == NULL)
        return NULL;

    memset(hNewSuperObject, 0, sizeof(HIE_tdstSuperObject));

    HIE_fn_vSetSuperObjectObjectAndType(hNewSuperObject, NULL, HIE_C_ulSuperObject);
    hNewSuperObject->hBoundingVolume  = NULL;
    hNewSuperObject->lDrawModeMask    = GLI_C_lAllIsEnable;
    hNewSuperObject->hGlobalMatrix    = GEO_fn_hCreateMatrix();
    POS_fn_vSetIdentityMatrix((POS_tdstCompletePosition *)hNewSuperObject->hGlobalMatrix);
    HIE_fn_vInvalidateOneGlobalMatrix(hNewSuperObject);
    hNewSuperObject->fTransparenceLevel = 255.0f;
    HIE_fn_vSetSuperObjectExcluLight(hNewSuperObject, 0);

    return hNewSuperObject;
}

void HIE_fn_vDestroySuperObject(HIE_tdstSuperObject *hOldSuperObject)
{
    GEO_fn_vDestroyMatrix(hOldSuperObject->hGlobalMatrix);

    Mmg_fn_v_SetModeAlloc(g_ucGEOModuleId, GEO_g_ucMmgMode, 0);
    if (GEO_g_bDynamicAllocation != '\0') {
        /* 0x501530 */
        Mmg_fn_vGiveInformationBlock(g_ucGEOModuleId, GEO_g_ucMmgMode, (void *)MMG_g_p_GmtPalBlockInfo);
        if ((void *)hOldSuperObject < HIE_g_p_MmgPoolRangeLo ||
            (void *)hOldSuperObject > HIE_g_p_MmgPoolRangeHi) {
            Mmg_fn_v_SetModeAlloc(g_ucGEOModuleId, 0xff, 0);
        }
    }
    fn_vGenFree(hOldSuperObject, 0);

    /* 0x45bce3 */
    if (Erm_fn_uwCheckError(MMG_g_ucErmChannelId, 0)) {
        ERM_fn_vClearLastError(0);
        ERM_fn_vUpdateLastError(4, g_ucGEOModuleId, 0, 5, -1, 0xff, 0xff, NULL);
    }
}

/* 0x0045BEF0 */
HIE_tdstSuperObject *HIE_fn_hGetChildNumber(HIE_tdstSuperObject *_hParent, long _lNumber)
{
    HIE_tdstSuperObject *hChild;
    ACP_tdxIndex i;

    for (i = 0, hChild = _hParent->p_stFirstChild; i < _lNumber; i++, hChild = hChild->p_stNextBrother)
    {
    }
    return hChild;
}
