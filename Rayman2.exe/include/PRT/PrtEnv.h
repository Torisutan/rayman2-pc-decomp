#ifndef RAYMAN2_PRT_PRTENV_H
#define RAYMAN2_PRT_PRTENV_H

#include "MTH/MTH_types.h"
#include "MTH/MTH3D.h"

#define PRT_C_ulAlignedBoxEnv 0x00000000
#define PRT_C_ulSphereEnv     0x00000001

typedef struct PRT_tdstParticlesEnvironment_
{
  unsigned long ulEnvType;
  MTH3D_tdstVector stMinPoint;
  MTH3D_tdstVector stMaxPoint;
  MTH3D_tdstVector stSphereCenter;
  MTH_tdxReal xRadius;
  MTH3D_tdstVector stAcceleration;
  MTH_tdxReal xAccelerationRange;
}
  PRT_tdstParticlesEnvironment;

#define PRT_M_vCopyParticlesEnvironment( _p_stDstParticlesEnvironment, _p_stSrcParticlesEnvironment )\
  memcpy ( _p_stDstParticlesEnvironment, _p_stSrcParticlesEnvironment, sizeof ( PRT_tdstParticlesEnvironment ) )
#define PRT_M_vSetTypeParticlesEnvironment( _p_stParticlesEnvironment, _ulEnvType )\
  ( (_p_stParticlesEnvironment)->ulEnvType = ( _ulEnvType ) )
#define PRT_M_vSetMinMaxPointParticlesEnvironment( _p_stParticlesEnvironment, _p_stMinPoint, _p_stMaxPoint )\
{\
  MTH3D_M_vCopyVector ( &((_p_stParticlesEnvironment)->stMinPoint), ( _p_stMinPoint ) );\
  MTH3D_M_vCopyVector ( &((_p_stParticlesEnvironment)->stMaxPoint), ( _p_stMaxPoint ) );\
}
#define PRT_M_vSetSphereParticlesEnvironment( _p_stParticlesEnvironment, _p_stSphereCenter, _xRadius )\
{\
  MTH3D_M_vCopyVector ( &((_p_stParticlesEnvironment)->stSphereCenter), ( _p_stSphereCenter ) );\
  (_p_stParticlesEnvironment)->xRadius = ( _xRadius );\
}
#define PRT_M_vSetAccelerationParticlesEnvironment( _p_stParticlesEnvironment, _p_stAcceleration )\
{\
  MTH3D_M_vCopyVector ( &((_p_stParticlesEnvironment)->stAcceleration), ( _p_stAcceleration ) );\
}
#define PRT_M_vSetAccelerationRangeParticlesEnvironment( _p_stParticlesEnvironment, _xAccelerationRange )\
  ( (_p_stParticlesEnvironment)->xAccelerationRange = ( _xAccelerationRange ) )

#endif
