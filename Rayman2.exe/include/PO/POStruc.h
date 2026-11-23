#ifndef PO_POSTRUC_H
#define PO_POSTRUC_H

typedef struct PO_tdstPhysicalObject_
{
    struct GEO_tdstVisualSet_ *_hVisualSet;
    void *_hCollideSet;
    void *_hBoundingVolume;
} PO_tdstPhysicalObject;

#endif
