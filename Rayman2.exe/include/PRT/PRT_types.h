#ifndef RAYMAN2_PRT_PRT_TYPES_H
#define RAYMAN2_PRT_PRT_TYPES_H

#include "ACP/ACP_types.h"
#include "MTH/MTH_types.h"
#include "MTH/MTH3D.h"
#include "MTH/MTH2D.h"
#include "GEO/GEO_types.h"
#include "GMT/GMT_types.h"
#include "POS/POS_types.h"
#include "PRT/PrtSrc.h"

#define PRT_C_xNullParticles      0
#define PRT_C_xBubbleParticles    1
#define PRT_C_xPointParticles     2
#define PRT_C_xSegmentParticles   3
#define PRT_C_xSpriteParticles    4
#define PRT_C_xTriangleParticles  5
#define PRT_C_xRectangleParticles 6

typedef struct PRT_tdstParticlesSystem_
{
  ACP_tdxIndex xNbParticles;
  ACP_tdxIndex xNbActiveParticles;
  MTH3D_tdstVector *d_stSpeed;
  ACP_tdxHandleOfObject hParticlesSystemObject;
  ACP_tdxIndex xParticlesType;
  void *d_stListOfParticles;
  void *p_stCommonData;
}
  PRT_tdstParticlesSystem;

typedef struct PRT_tdstPointParticle_
{
  MTH_tdxReal xBirthDate;
}
  PRT_tdstPointParticle;

typedef struct PRT_tdstPointCommonData_
{
  GMT_tdxHandleToGameMaterial hMaterial;
}
  PRT_tdstPointCommonData;

typedef MTH_tdxReal GEO_tdxColorValue;
struct GEO_tdstColor_
{
  GEO_tdxColorValue xR;
  GEO_tdxColorValue xG;
  GEO_tdxColorValue xB;
  GEO_tdxColorValue xA;
};

typedef struct PRT_tdstSegmentParticle_
{
  MTH_tdxReal xDeathDate;
  GEO_tdstColor stPointColor;
  GEO_tdstColor stLastPointColor;
}
  PRT_tdstSegmentParticle;

typedef struct PRT_tdstSegmentCommonData_
{
  GMT_tdxHandleToGameMaterial hMaterial;
  GEO_tdstColor stPointColor;
  GEO_tdstColor stLastPointColor;
}
  PRT_tdstSegmentCommonData;

typedef struct PRT_tdstSpriteParticle_
{
  MTH_tdxReal          xDeathDate;
  MTH_tdxReal          xChangeSpriteDate;
  char                 cNextSpriteIndex;
  MTH2D_tdstVector     stSize;
  char                 a2_cRotateSpeed[2];
  unsigned char        a2_ucRotateAngle[2];
}
  PRT_tdstSpriteParticle;

typedef struct PRT_tdstSpriteData_
{
  ACP_tdxHandleOfSprite hSprite;
  MTH_tdxReal           xTime;
  char                  cProba;
  char                  cNextSprite;
}
  PRT_tdstSpriteData;

typedef struct PRT_tdstSpriteCommonData_
{
  ACP_tdxIndex                 xNumberOfSprites;
  PRT_tdstSpriteData          *d_stSpriteData;
  ACP_tdxHandleOfSprite        hSprite;
  GMT_tdxHandleToGameMaterial  hMaterial;
}
  PRT_tdstSpriteCommonData;

#endif
