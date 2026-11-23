#pragma once

#include "POS/POS_types.h"
#include "GLI/vertex.h"

typedef struct GLI_tdstCamera_
{
    long                     lSizeOfThis;
    long                     lTypeOfThis;
    long                     lCameraMode;
    POS_tdstCompletePosition stMatrix;
    MTH_tdxReal              xAlphaX;
    MTH_tdxReal              xAlphaY;
    MTH_tdxReal              xNear;
    MTH_tdxReal              xFar;
    MTH_tdxReal              xScreen;
    GLI_tdst2DVertex         stScale;
    GLI_tdst2DVertex         stTrans;
    MTH_tdxReal              xXProjectionRatio;
    MTH_tdxReal              xYProjectionRatio;
    MTH3D_tdstVector         stNormPlaneLeft;
    MTH_tdxReal              xDistPlaneLeft;
    MTH3D_tdstVector         stNormPlaneRight;
    MTH_tdxReal              xDistPlaneRight;
    MTH3D_tdstVector         stNormPlaneUp;
    MTH_tdxReal              xDistPlaneUp;
    MTH3D_tdstVector         stNormPlaneDown;
    MTH_tdxReal              xDistPlaneDown;
    MTH_tdxReal              xRatio;
}
GLI_tdstCamera;

#define GLI_C_lIsoCamWithDistorsion     100
#define GLI_C_lIsoCamWithoutDistorsion  101
#define GLI_C_lPersCamWithDistorsion    102
#define GLI_C_lPersCamWithoutDistorsion 103

void __cdecl GLI_xGetCameraMatrix(void *p_stCam, long *p_stMatrix);
void __cdecl GLI_xSetCameraMatrix(void *p_stCam, long *p_stMatrix);
void __cdecl GLI_xSetCameraAspectAndRatio(void *p_stCam, float xAlphaX, float xRatio);
void __cdecl GLI_xGetCameraAspectAndRatio(void *p_stCam, float *p_xAlphaX, float *p_xRatio);
void __cdecl GLI_xSetCameraRatio(void *p_stCam, float xRatio);
void __cdecl GLI_xSetCameraNearFar(void *p_stCam, float xNear_unused, float xFar);

/* 0x00422750 */
void __cdecl GLI_xCreateCamera(GLI_tdstCamera **h_stCam, long lCameraMode);

/* 0x004226d0 */
void __cdecl GLI_xSetViewportCamera(short hDevice, short hViewport, long lCam);

/* 0x00422720 */
void __cdecl GLI_xGetViewportCamera(unsigned long hDevice, unsigned short hViewport, void **p_stCam);
