#ifndef PCS_PCSSTRUC_H
#define PCS_PCSSTRUC_H

typedef struct tdstPhysicalCollSet_
{
    void *hZdm;
    void *hZdd;
    void *hZde;
    void *hZdr;
} tdstPhysicalCollSet;

void *PCS_fn_hGetZdrGeoObjOfPhysicalCollSet(void *_hPhyCollSet);

#endif
