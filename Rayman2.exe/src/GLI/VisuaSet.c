#include "GLI/VisuSet.h"
#include "TMP/TmpMem.h"

#include "ACP/ACP_types.h"
#include "GLI/VisuS_st.h"

/* 0x0042AE70 */
struct GEO_tdstVisualSet_ *GLI_p_stCreateTMPVisualSet(long lNbLOD)
{
    GEO_tdstVisualSet *p_stLocalVS;
    ACP_tdxIndex xLodCounter;

    p_stLocalVS = (GEO_tdstVisualSet *)TMP_M_p_Malloc(sizeof(GEO_tdstVisualSet));
    if (p_stLocalVS == NULL) return(NULL);

    p_stLocalVS->d_xThresholdsTable = (MTH_tdxReal *)TMP_M_p_Malloc(sizeof(MTH_tdxReal) * lNbLOD);
    if (p_stLocalVS->d_xThresholdsTable == NULL) return(NULL);

    p_stLocalVS->d_p_stLodDefinitions = (struct GEO_tdstGeometricObject_ **)TMP_M_p_Malloc(sizeof(struct GEO_tdstGeometricObject_ *) * lNbLOD);
    if (p_stLocalVS->d_p_stLodDefinitions == NULL) return(NULL);

    p_stLocalVS->xNbLodDefinitions = lNbLOD;

    for (xLodCounter = 0;
    xLodCounter < lNbLOD;
    xLodCounter ++)
    {
      p_stLocalVS->d_xThresholdsTable[xLodCounter] = 0.0;
      p_stLocalVS->d_p_stLodDefinitions[xLodCounter] = NULL;
    }

    return (p_stLocalVS);
}

void GLI_vGetVisualSetLOD(void *hVisualSet, long lNumberOfLodToGet,
                          MTH_tdxReal *p_xThreshold, void **h_stObject)
{
    GEO_tdstVisualSet *p_stVisualSet = (GEO_tdstVisualSet *)hVisualSet;

    if (lNumberOfLodToGet < (long)p_stVisualSet->xNbLodDefinitions)
    {
        *p_xThreshold = p_stVisualSet->d_xThresholdsTable[lNumberOfLodToGet];
        *h_stObject = p_stVisualSet->d_p_stLodDefinitions[lNumberOfLodToGet];
    }
}

/* 0x004315F0 */
short *ISI_hComputeBlendRLI(short *psSrcA, short *psSrcB, void *p_vIndex, float xBlend);

/* 0x0042B2D0 */
short *GLI_hComputeBlendRLI(void *hVS, long lShadowIdx, long lMirrorIdx,
                                           void *p_vIndex, float xBlend)
{
    void **ppTables;

    if ((int)(lShadowIdx & 0xff) < ((GEO_tdstVisualSet *)hVS)->lNumberOfRLI &&
        (int)(lMirrorIdx & 0xff) < ((GEO_tdstVisualSet *)hVS)->lNumberOfRLI) {
        ppTables = ((GEO_tdstVisualSet *)hVS)->d_hRLI;
        return ISI_hComputeBlendRLI((short *)ppTables[lShadowIdx & 0xff],
                                             (short *)ppTables[lMirrorIdx & 0xff],
                                             p_vIndex, xBlend);
    }
    return NULL;
}
