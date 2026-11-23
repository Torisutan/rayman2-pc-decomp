#ifndef GLI_LIGHT_ST_H
#define GLI_LIGHT_ST_H

#include "PRT/PRT_types.h"
#include "GEO/GEO_types.h"

typedef struct GLI_tdstZBufferForLight_
{
	long lSizeX;
	long lSizeY;

	MTH_tdxReal xCoefX;
	MTH_tdxReal xCoefY;
	MTH_tdxReal *p_xZBufferMap;
	MTH_tdxReal *p_xMiddleZBufferMap;
}
GLI_tdstZBufferForLight;

struct GLI_tdstLight_
{
    long b_lOnOff;
    long bThisLightIsZBuffered;
    long lTypeOfLight;
    MTH_tdxReal xFar;
    MTH_tdxReal xNear;
    MTH_tdxReal xLittleAlpha;
    MTH_tdxReal xBigAlpha;
    MTH_tdxReal xLittleTangent;
    MTH_tdxReal xBigTangent;
    POS_tdstCompletePosition stMatrix;
    GLI_tdstZBufferForLight stZBuffer;
    GEO_tdstColor stColor;
    unsigned char bValid;
    unsigned char ucObjectLighted;
    unsigned char bIsPainting;
    unsigned char ucIsAlpha;
    MTH3D_tdstVector xInter_Min_Pos;
    MTH3D_tdstVector xExter_Min_Pos;
    MTH3D_tdstVector xInter_Max_Pos;
    MTH3D_tdstVector xExter_Max_Pos;
    MTH3D_tdstVector xCenterBox;
    MTH_tdxReal xRadius;
    MTH_tdxReal xIntensity_Min;
    MTH_tdxReal xIntensity_Max;
    GEO_tdstColor stBackgroundColor;
};

#endif
