#include "PO/IPOProto.h"

void *IPO_fn_hGetPhysicalObject(void *_hInstanciatedPhysicalObject)
{
    return *(void **)_hInstanciatedPhysicalObject;
}
