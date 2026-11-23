#include "HIE/HIE_types.h"
#include "POS/POS_types.h"
#include <string.h>

#include "MMG/MMG_alloc.h"

#include "GEO/GeoMem.h"
#include "HIE/HIE_globals.h"

#define HIE_g_a_hMatrixStack (HIE_g_a_hMatrixStack_backing + 1)

void *GEO_fn_hCreateMatrix(void)
{
    void *hMatrix;

    GEO_M_CPAMalloc(hMatrix, void *, sizeof(POS_tdstCompletePosition), E_uwGEONotEnoughtMemory);
    POS_fn_vSetIdentityMatrix((POS_tdstCompletePosition *)hMatrix);
    return hMatrix;
}

void HIE_fn_vCreateMatrixStack(void)
{
    HIE_g_a_hMatrixStack[0] = GEO_fn_hCreateMatrix();
    HIE_g_lNbMatrixInStack  = 1;
}
