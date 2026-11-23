#ifndef GLI_BIGGLOBALS_H
#define GLI_BIGGLOBALS_H

#include "MTH/MTH3D.h"
#include "POS/POS_types.h"
#include "PRT/PRT_types.h"

#define GLI_C_lMaxVertexPerObject 2500

typedef struct GLI_tdstAligned3DVector_
{
    MTH_tdxReal xX;
    MTH_tdxReal xY;
    MTH_tdxReal xZ;
    MTH_tdxReal ALIGN;
}
GLI_tdstAligned3DVector;

typedef struct GLI_tdstAligned2DVector_
{
    MTH_tdxReal   xX;
    MTH_tdxReal   xY;
    MTH_tdxReal   xOoZ;
    unsigned long ulPackedColor;
}
GLI_tdstAligned2DVector;

typedef struct GLI_tdst2DUVValues_
{
    MTH_tdxReal xU;
    MTH_tdxReal xV;
}
GLI_tdst2DUVValues;

struct GLD_tdstViewportAttributes_;
struct GEO_tdstGeometricObject_;
struct GLI_tdstTexture;
struct GLI_tdstMaterial_;
struct GLI_tdstCamera_;
struct tdstFogParams_;

typedef struct GLI_tdstInternalGlobalValuesFor3dEngine_
{
    struct GLD_tdstViewportAttributes_ *p_stVpt;
    struct GEO_tdstGeometricObject_ *p_stObj;
    long lDrawModeMask;
    long lHierachDrawMask;
    long lCurrentDrawMask;
    long GLD_RenderingCounter;
    long lClippingModeMask;

    MTH3D_tdstVector stCenterOfCurrentBoundingSphere;
    MTH_tdxReal stRadiusOfCurrentBoundingSphere;

    GLI_tdstAligned3DVector GLI_TurnedScaledDisplecedPoint[GLI_C_lMaxVertexPerObject];
    GLI_tdstAligned2DVector GLI_ScreenPoint[GLI_C_lMaxVertexPerObject];
    MTH_tdxReal GLI_aDEF_xWaterPlaneDepth[(GLI_C_lMaxVertexPerObject >> 1) - 8];
    struct GEO_tdstColor_ GLI_aDEF_stColorsRLID[GLI_C_lMaxVertexPerObject];
    struct GEO_tdstColor_ GLI_aDEF_stColorsRLIS[GLI_C_lMaxVertexPerObject];
    struct GEO_tdstColor_ GLI_aDEF_stColorsRLIA;
    GLI_tdst2DUVValues GLI_aDEF_stEnvUV[GLI_C_lMaxVertexPerObject];

    struct GEO_tdstColor_ GLI_stColorsAdd;
    struct GEO_tdstColor_ GLI_stColorsMul;

    POS_tdstCompletePosition *gs_st_CameraMatrix;
    POS_tdstCompletePosition *gs_st_CurrentMatrix;
    POS_tdstCompletePosition gs_st_CurrentMatrixInverted;
    POS_tdstCompletePosition gs_st_CurrentMatrixMultiplyedWithCameraMatrix;

    float fZClipping;
    float fWClipping;
    float fXMinClipping;
    float fXMaxClipping;
    float fYMinClipping;
    float fYMaxClipping;
    struct GLI_tdstTexture *p_stCurrentTexture;
    struct GLI_tdstMaterial_ *hCurrentMaterial;

    struct GLI_tdstCamera_ *p_stCurrentCamera;

    long xWaterPlaneDistance;
    GLI_tdstAligned3DVector stWaterPlanNormale;
    unsigned long ulColorInitForSprite;
    unsigned long ulSpecularColorForSprite;
    float fMulU;
    float fMulV;

    void *p_TheZListe;
    unsigned long ulCurrentZTable;

    struct tdstFogParams_ *p_stActiveFog;
    struct tdstFogParams_ *p_stLastComputedFog;
    long xFogIsOn;
    long xTextureDontAcceptFog;

    long lAMirrorIsDetected;
    long bDrawMirrorSymetric;
    long lDisplayMenuIsDetected;

    float xGlobalAlpha;
}
GLI_tdstInternalGlobalValuesFor3dEngine;

#ifdef GLI_D_CheckBigGlobalsLayout
#include <stddef.h>
#define GLI_M_BigGlobalsAt(f, o) \
    typedef char GLI_a_cBigGlobalsCheck_##f[(offsetof(GLI_tdstInternalGlobalValuesFor3dEngine, f) == (o)) ? 1 : -1];
GLI_M_BigGlobalsAt(GLI_TurnedScaledDisplecedPoint, 0x2C)
GLI_M_BigGlobalsAt(GLI_aDEF_xWaterPlaneDepth, 0x138AC)
GLI_M_BigGlobalsAt(GLI_aDEF_stColorsRLID, 0x14C14)
GLI_M_BigGlobalsAt(GLI_aDEF_stColorsRLIA, 0x28494)
GLI_M_BigGlobalsAt(GLI_stColorsAdd, 0x2D2C4)
GLI_M_BigGlobalsAt(GLI_stColorsMul, 0x2D2D4)
GLI_M_BigGlobalsAt(gs_st_CameraMatrix, 0x2D2E4)
GLI_M_BigGlobalsAt(gs_st_CurrentMatrixMultiplyedWithCameraMatrix, 0x2D344)
GLI_M_BigGlobalsAt(p_stCurrentTexture, 0x2D3B4)
GLI_M_BigGlobalsAt(hCurrentMaterial, 0x2D3B8)
GLI_M_BigGlobalsAt(p_stCurrentCamera, 0x2D3BC)
GLI_M_BigGlobalsAt(xWaterPlaneDistance, 0x2D3C0)
GLI_M_BigGlobalsAt(ulColorInitForSprite, 0x2D3D4)
GLI_M_BigGlobalsAt(p_TheZListe, 0x2D3E4)
GLI_M_BigGlobalsAt(p_stActiveFog, 0x2D3EC)
GLI_M_BigGlobalsAt(xFogIsOn, 0x2D3F4)
GLI_M_BigGlobalsAt(xTextureDontAcceptFog, 0x2D3F8)
GLI_M_BigGlobalsAt(lAMirrorIsDetected, 0x2D3FC)
GLI_M_BigGlobalsAt(lDisplayMenuIsDetected, 0x2D404)
GLI_M_BigGlobalsAt(xGlobalAlpha, 0x2D408)
typedef char GLI_a_cBigGlobalsCheck_size[(sizeof(GLI_tdstInternalGlobalValuesFor3dEngine) == 0x2D40C) ? 1 : -1];
#undef GLI_M_BigGlobalsAt
#endif

#endif
