#include "PRT/PrtSrc.h"
#include "RND/RND.h"
#include "MTH/MTH_flt.h"

/* 0x00446840 */
ACP_tdxBool PRT_fn_bComputeParticlesGeneration ( PRT_tdstParticlesSource *_p_stParticlesSource )
{

	if ( _p_stParticlesSource->ucGenerationMode == PRT_C_ucContinousGeneration )
		return TRUE;

	if ( _p_stParticlesSource->ucGenerationMode == PRT_C_ucProbabilistGeneration )
    {
		if ( _p_stParticlesSource->xGenerationProbability > RND_fn_xGetRealRandomValue ( 0, MTH_C_ZERO, MTH_C_ONE ) )
			return TRUE;
		return FALSE;
    }

	if ( _p_stParticlesSource->ucGenerationMode == PRT_C_ucCrenelGeneration )
    {
		if ( _p_stParticlesSource->xFramesCounter < _p_stParticlesSource->xNbFramesNoGeneration )
        {
			_p_stParticlesSource->xFramesCounter ++;
            return FALSE;
        }
        _p_stParticlesSource->xFramesCounter = (_p_stParticlesSource->xFramesCounter+1)%_p_stParticlesSource->xNbFramesTotal;
        return TRUE;
	}

	return FALSE;
}

/* 0x004468A0 */
ACP_tdxIndex PRT_fn_xComputeNbParticlesToInject ( PRT_tdstParticlesSource *_p_stParticlesSource )
{
	if ( _p_stParticlesSource->ucNbParticlesToGenerateMode == PRT_C_ucConstantNb )
		return _p_stParticlesSource->xNbParticlesToGenerate;
	if ( _p_stParticlesSource->ucNbParticlesToGenerateMode == PRT_C_ucProbabilistNb )
		return (ACP_tdxIndex) RND_fn_lGetLongRandomValue ( 0, _p_stParticlesSource->xNbMin, _p_stParticlesSource->xNbMax );
	return 0;
}
