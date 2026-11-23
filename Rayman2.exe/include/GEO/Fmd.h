#pragma once

#include "GEO/GEO_types.h"
#include "GMT/GMT_types.h"

typedef struct GEO_tdstFaceMapDescriptor_
{
    ACP_tdst2DUVValues stUVValues[3];
	GMT_tdxHandleToGameMaterial hMaterial;
} GEO_tdstFaceMapDescriptor ;

extern void
GEO_xGetFaceMapDescriptorGameMaterial ( ACP_tdxHandleOfFMD  hFmd ,
							        GMT_tdxHandleToGameMaterial  *p_hMaterial);
