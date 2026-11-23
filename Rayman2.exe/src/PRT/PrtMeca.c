#include "PRT/PRT_types.h"

void PRT_fn_vSourceGeneratePointParticle ( PRT_tdstParticlesSystem *_p_stParticlesSystem,
                                           PRT_tdstParticlesSource *_p_stParticlesSource,
                                           POS_tdstCompletePosition *_p_stSourceMatrix,
                                           MTH_tdxReal _xTimeT );
void PRT_fn_vSourceGenerateSegmentParticle ( PRT_tdstParticlesSystem *_p_stParticlesSystem,
                                             PRT_tdstParticlesSource *_p_stParticlesSource,
                                             POS_tdstCompletePosition *_p_stSourceMatrix,
                                             MTH_tdxReal _xTimeT );
void PRT_fn_vSourceGenerateSpriteParticle ( PRT_tdstParticlesSystem *_p_stParticlesSystem,
                                            PRT_tdstParticlesSource *_p_stParticlesSource,
                                            POS_tdstCompletePosition *_p_stSourceMatrix,
                                            MTH_tdxReal _xTimeT );

void PRT_fn_vSourceGenerateParticle
	(
		PRT_tdstParticlesSystem *_p_stParticlesSystem,
        PRT_tdstParticlesSource *_p_stParticlesSource,
        POS_tdstCompletePosition *_p_stSourceMatrix,
        MTH_tdxReal _xTimeT
	)
{
	switch ( _p_stParticlesSystem->xParticlesType )
	{
		case PRT_C_xSpriteParticles :
			PRT_fn_vSourceGenerateSpriteParticle ( _p_stParticlesSystem, _p_stParticlesSource, _p_stSourceMatrix, _xTimeT );
			break;
		case PRT_C_xPointParticles :
			PRT_fn_vSourceGeneratePointParticle ( _p_stParticlesSystem, _p_stParticlesSource, _p_stSourceMatrix, _xTimeT );
			break;
		case PRT_C_xSegmentParticles :
			PRT_fn_vSourceGenerateSegmentParticle ( _p_stParticlesSystem, _p_stParticlesSource, _p_stSourceMatrix, _xTimeT );
			break;
		default :
			break;
  }
}
