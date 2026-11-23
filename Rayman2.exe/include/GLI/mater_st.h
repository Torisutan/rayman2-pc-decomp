#ifndef GLI_MATERIAL_ST_H
#define GLI_MATERIAL_ST_H

#include "MTH/MTH_types.h"
#include "GEO/GEO_types.h"
#include "PRT/PRT_types.h"
#include "GLI/GLI_types.h"

typedef struct GLI_tdstAnimatedTextureNode
{
    struct GLI_tdstTexture *p_stTexture;
    MTH_tdxReal xDisplayTime;
    struct GLI_tdstAnimatedTextureNode *p_stNextDisplayNode;
} GLI_tdstAnimatedTextureNode;

struct GLI_tdstMaterial_
{
    unsigned long ulMaterialType;
    GEO_tdstColor stAmbient;
    GEO_tdstColor stDiffuse;
    GEO_tdstColor stSpecular;
    GEO_tdstColor stColor;
    long lSpecularExponent;
    struct GLI_tdstTexture *p_stTexture;
    MTH_tdxReal fAddU;
    MTH_tdxReal fAddV;
    MTH_tdxReal fConstantAddU;
    MTH_tdxReal fConstantAddV;
    long lIncrementIsEnable;
    unsigned long dwActualRefreshNumber;
    GLI_tdstAnimatedTextureNode *p_stFistAnimatedTExtureNode;
    GLI_tdstAnimatedTextureNode *p_stActualAnimatedTExtureNode;
    long lNumberOfDisplayNode;
    MTH_tdxReal xActualDisplayTimeSinceStartOfLastTexture;
    ACP_tdxBool xIsLocked;
};

#endif
