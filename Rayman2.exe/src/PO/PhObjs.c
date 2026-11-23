#include "PO/POStruc.h"
#include "PO/POProto.h"

void *PO_fn_hGetVisualSet(void *_hPhysicalObject)
{
    return ((PO_tdstPhysicalObject *)_hPhysicalObject)->_hVisualSet;
}

void *PO_fn_hGetBoundingVolume(void *_hPhysicalObject)
{
    return ((PO_tdstPhysicalObject *)_hPhysicalObject)->_hBoundingVolume;
}
