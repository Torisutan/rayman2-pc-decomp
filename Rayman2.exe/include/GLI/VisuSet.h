#ifndef GLI_VISUSET_H
#define GLI_VISUSET_H

#include "MTH/MTH_types.h"

void GLI_vGetVisualSetLOD(void *hVisualSet, long lNumberOfLodToGet,
                          MTH_tdxReal *p_xThreshold, void **h_stObject);

#endif
