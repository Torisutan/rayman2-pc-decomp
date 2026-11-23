#ifndef RAYMAN2_PRT_PRTSRC_H
#define RAYMAN2_PRT_PRTSRC_H

#include "ACP/ACP_types.h"
#include "MTH/MTH_types.h"
#include "MTH/MTH3D.h"

#define PRT_C_ucNoGeneration           0
#define PRT_C_ucContinousGeneration    1
#define PRT_C_ucProbabilistGeneration  2
#define PRT_C_ucCrenelGeneration       3

#define PRT_C_ucConstantNb             0
#define PRT_C_ucProbabilistNb          1

#define PRT_C_ucPoint                  0
#define PRT_C_ucQuad                   1
#define PRT_C_ucParallelepipede        2

#define PRT_C_ucRotationLink           0
#define PRT_C_ucTranslationLink        1
#define PRT_C_ucRotAndTransLink        2

#define PRT_C_ucNoLifeTime             0
#define PRT_C_ucConstantLifeTime       1
#define PRT_C_ucProbabilistLifeTime    2

typedef struct PRT_tdstParticlesSource_
{

  unsigned char ucGenerationMode;
  MTH_tdxReal xGenerationProbability;
  ACP_tdxIndex xNbFramesNoGeneration;
  ACP_tdxIndex xNbFramesTotal;
  ACP_tdxIndex xFramesCounter;
  unsigned char ucNbParticlesToGenerateMode;
  ACP_tdxIndex xNbParticlesToGenerate;
  ACP_tdxIndex xNbMin;
  ACP_tdxIndex xNbMax;

  unsigned char ucGeometryMode;
  unsigned char ucLinkMode;
  MTH3D_tdstVector stVertex1;
  MTH3D_tdstVector stVertex2;
  MTH3D_tdstVector stVertex3;
  MTH3D_tdstVector stNormal;
  MTH3D_tdstVector stVertex4;

  MTH_tdxReal xSpeed;
  MTH_tdxReal xSpeedRange;
  unsigned char ucLifeMode;
  MTH_tdxReal xMinTime;
  MTH_tdxReal xMaxTime;
}
  PRT_tdstParticlesSource;

extern ACP_tdxBool PRT_fn_bComputeParticlesGeneration ( PRT_tdstParticlesSource *_p_stParticlesSource );

extern ACP_tdxIndex PRT_fn_xComputeNbParticlesToInject ( PRT_tdstParticlesSource *_p_stParticlesSource );

#endif
