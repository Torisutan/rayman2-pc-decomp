#include "SPO/SPO_types.h"
#include "HIE/HIE_types.h"

void SPO_ReinitSuperimposedArray(void)
{
    short xIndex;

    for (xIndex = 0; xIndex < HIE_g_xFixIndex; xIndex++)
    {
        HIE_gd_hFixSPO[xIndex]->ulFlags &= ~(HIE_C_Flag_Superimposed | HIE_C_Flag_NotPickable);
    }

    HIE_g_xFixIndex = 0;
    HIE_g_ucContext = 0;
    HIE_g_xFixIndexSave = 0;
}
