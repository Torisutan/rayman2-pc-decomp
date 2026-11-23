#include "PCS/PCSStruc.h"

void *PCS_fn_hGetZdrGeoObjOfPhysicalCollSet(void *_hPhyCollSet)
{
    return ((tdstPhysicalCollSet *)_hPhyCollSet)->hZdr;
}

void *PCS_fn_hGetZddGeoObjOfPhysicalCollSet(void *_hPhyCollSet)
{
    return ((tdstPhysicalCollSet *)_hPhyCollSet)->hZdd;
}

void *PCS_fn_hGetZdeGeoObjOfPhysicalCollSet(void *_hPhyCollSet)
{
    return ((tdstPhysicalCollSet *)_hPhyCollSet)->hZde;
}

void *PCS_fn_hGetZdmGeoObjOfPhysicalCollSet(void *_hPhyCollSet)
{
    return ((tdstPhysicalCollSet *)_hPhyCollSet)->hZdm;
}
