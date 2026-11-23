#ifndef __GEO_GEOSPRIT_H
#define __GEO_GEOSPRIT_H

#include "ACP/ACP_types.h"
#include "GMT/GMT_types.h"

#define GEO_C_lSpriteDrawMode2DScaled  1
#define GEO_C_lSpriteDrawMode2DRotativ 2
#define GEO_C_lSpriteDrawDisable       4

#define GEO_C_lSpriteDrawModeSemiLookAt 8
#define GEO_C_lSpriteDrawModeLensFlare 16

typedef struct GEO_tdstSprite_
{
  ACP_tdxIndex xNbSprites;
  short *d_xSpriteDrawMode;
  MTH_tdxReal *d_xThresholds;
  MTH2D_tdstVector *d_xSizeOfSprite;
  MTH2D_tdstVector *d_xDisplacementOfSprite;
  GMT_tdxHandleToGameMaterial *d_hMaterial;

} GEO_tdstSprite ;

#endif
