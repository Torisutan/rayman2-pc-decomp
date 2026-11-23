#ifndef RAYMAN2_GAM_ACTIONS_MSPRTSRC_H
#define RAYMAN2_GAM_ACTIONS_MSPRTSRC_H

#include "MTH/MTH3D.h"
#include "PRT/PrtSrc.h"
#include "PRT/PRT_types.h"
#include "PRT/PrtEnv.h"

typedef struct tdstParticleGenerator_
{
   PRT_tdstParticlesSource *        p_stPrtSrc;
   PRT_tdstParticlesSystem *        p_stPrtSys;
   PRT_tdstParticlesEnvironment *   p_stPrtEnv;
   long                             lEnvironmentMask;
   MTH3D_tdstVector                 stMinPoint;
   MTH3D_tdstVector                 stMaxPoint;
   unsigned char                    ucLinkedToEnvironment;

	unsigned long					ulLinkedPrtGenMask;
	struct tdstParticleGenerator_	*p_stLinkedPrtGen;

} tdstParticleGenerator;

struct tdstMSPrtSrc_
{
   tdstParticleGenerator *          p_stParticleGenerator;

   void *                           hWaterStreakGenerator;
   unsigned char                    ucGeneratorActivation;
   unsigned char                    ucCanGenerate;

   void *                           hFootPath;

};

#endif
