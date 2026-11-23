#pragma once

#include "GLI/Camera.h"

#define C_MAX_MATRIX_IN_VPT 100

typedef struct GLI_tdstSpecificAttributesFor3D_
{
	GLI_tdstCamera *p_stCam;
	MTH_tdxReal xNear, xFar;
} GLI_tdstSpecificAttributesFor3D, *GLI_pstSpecificAttributesFor3D;
