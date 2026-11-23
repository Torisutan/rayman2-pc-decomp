#include "PRT/PRT_types.h"
#include "RND/RND.h"
#include "MTH/MTH_flt.h"
#include "MTH/MTH_xNeg.h"
#include "GEO/Element.h"
#include "GAM/GAM_globals.h"

/* 0x00447040 */
void PRT_fn_vGenerateSpriteParticle
		(
			MTH3D_tdstVector			*_p_stParticlePosition,
            MTH3D_tdstVector			*_p_stParticleSpeed,
            PRT_tdstSpriteParticle		*_p_stSpriteParticle,
            PRT_tdstSpriteCommonData	*_p_stSpriteCommonData,
            PRT_tdstParticlesSource		*_p_stParticlesSource,
            POS_tdstCompletePosition	*_p_stSourceMatrix,
            MTH_tdxReal					_xTimeT
		)
{

	MTH3D_tdstVector	stSpeedVariation;
	MTH_tdxReal			xC1, xC2, xC3, xC4;
	MTH3D_tdstVector	stTrans;

	MTH3D_M_vSetVectorElements
		(
			&stSpeedVariation,
			RND_fn_xGetRealRandomValue ( 0, MTH_M_xNeg ( _p_stParticlesSource->xSpeedRange ), _p_stParticlesSource->xSpeedRange ),
			RND_fn_xGetRealRandomValue ( 0, MTH_M_xNeg ( _p_stParticlesSource->xSpeedRange ), _p_stParticlesSource->xSpeedRange ),
			RND_fn_xGetRealRandomValue ( 0, MTH_M_xNeg ( _p_stParticlesSource->xSpeedRange ), _p_stParticlesSource->xSpeedRange )
		);

	MTH3D_M_vMulAddVector ( _p_stParticleSpeed, _p_stParticlesSource->xSpeed, &(_p_stParticlesSource->stNormal), &stSpeedVariation );
	if ( (_p_stParticlesSource->ucLinkMode == PRT_C_ucRotationLink) || (_p_stParticlesSource->ucLinkMode == PRT_C_ucRotAndTransLink) )
	{
		POS_fn_vMulMatrixVector ( _p_stParticleSpeed, _p_stSourceMatrix, _p_stParticleSpeed );
	}

	if ( _p_stParticlesSource->ucGeometryMode == PRT_C_ucPoint )
	{
		MTH3D_M_vCopyVector ( _p_stParticlePosition, &(_p_stParticlesSource->stVertex1) );
	}
	else
	if ( _p_stParticlesSource->ucGeometryMode == PRT_C_ucQuad )
	{

		xC2 = RND_fn_xGetRealRandomValue ( 0, MTH_C_ZERO, MTH_C_ONE );
		xC3 = RND_fn_xGetRealRandomValue ( 0, MTH_C_ZERO, MTH_C_ONE );
		xC1 = MTH_M_xSub ( MTH_M_xSub ( MTH_C_ONE, xC2 ), xC3 );
		_p_stParticlePosition->xX = xC1*_p_stParticlesSource->stVertex1.xX + xC2*_p_stParticlesSource->stVertex2.xX + xC3*_p_stParticlesSource->stVertex3.xX;
		_p_stParticlePosition->xY = xC1*_p_stParticlesSource->stVertex1.xY + xC2*_p_stParticlesSource->stVertex2.xY + xC3*_p_stParticlesSource->stVertex3.xY;
		_p_stParticlePosition->xZ = xC1*_p_stParticlesSource->stVertex1.xZ + xC2*_p_stParticlesSource->stVertex2.xZ + xC3*_p_stParticlesSource->stVertex3.xZ;
	}
	else if ( _p_stParticlesSource->ucGeometryMode == PRT_C_ucParallelepipede )
	{

		xC2 = RND_fn_xGetRealRandomValue ( 0, MTH_C_ZERO, MTH_C_ONE );
		xC3 = RND_fn_xGetRealRandomValue ( 0, MTH_C_ZERO, MTH_C_ONE );
		xC4 = RND_fn_xGetRealRandomValue ( 0, MTH_C_ZERO, MTH_C_ONE );
		xC1 = MTH_M_xSub ( MTH_M_xSub ( MTH_M_xSub ( MTH_C_ONE, xC2 ), xC3 ), xC4 );
		_p_stParticlePosition->xX = xC1*_p_stParticlesSource->stVertex1.xX + xC2*_p_stParticlesSource->stVertex2.xX + xC3*_p_stParticlesSource->stVertex3.xX + xC4*_p_stParticlesSource->stVertex4.xX;
		_p_stParticlePosition->xY = xC1*_p_stParticlesSource->stVertex1.xY + xC2*_p_stParticlesSource->stVertex2.xY + xC3*_p_stParticlesSource->stVertex3.xY + xC4*_p_stParticlesSource->stVertex4.xY;
		_p_stParticlePosition->xZ = xC1*_p_stParticlesSource->stVertex1.xZ + xC2*_p_stParticlesSource->stVertex2.xZ + xC3*_p_stParticlesSource->stVertex3.xZ + xC4*_p_stParticlesSource->stVertex4.xZ;
	}
	if ( _p_stParticlesSource->ucLinkMode == PRT_C_ucRotAndTransLink )
	{
		POS_fn_vMulMatrixVertex( _p_stParticlePosition, _p_stSourceMatrix, _p_stParticlePosition );
	}
	else if ( _p_stParticlesSource->ucLinkMode == PRT_C_ucTranslationLink )
	{
		POS_fn_vGetTranslationVector( _p_stSourceMatrix, &stTrans );
		MTH3D_M_vAddVector ( _p_stParticlePosition, &stTrans, _p_stParticlePosition );
	}
	else if ( _p_stParticlesSource->ucLinkMode == PRT_C_ucRotationLink )
	{
		POS_fn_vMulMatrixVector ( _p_stParticlePosition, _p_stSourceMatrix, _p_stParticlePosition );
	}

	if ( _p_stParticlesSource->ucLifeMode == PRT_C_ucNoLifeTime )
	{
		_p_stSpriteParticle->xDeathDate = MTH_C_InfinitPlus;
	}
	else if ( _p_stParticlesSource->ucLifeMode == PRT_C_ucConstantLifeTime )
	{
		_p_stSpriteParticle->xDeathDate = MTH_M_xAdd ( _xTimeT, _p_stParticlesSource->xMinTime );
	}
	else if ( _p_stParticlesSource->ucLifeMode == PRT_C_ucProbabilistLifeTime )
	{
		_p_stSpriteParticle->xDeathDate = MTH_M_xAdd ( _xTimeT, RND_fn_xGetRealRandomValue ( 0, _p_stParticlesSource->xMinTime, _p_stParticlesSource->xMaxTime ) );
	}

	{
		static int iRotation = 0;   /* 0x004B72DC */
		if (iRotation)
		{
			_p_stSpriteParticle->a2_cRotateSpeed[0] = (char) (RND_fn_lGetLongRandomValue( 0, 0, 9) - 4 );
			_p_stSpriteParticle->a2_cRotateSpeed[1] = (char) (RND_fn_lGetLongRandomValue( 0, 0, 9) - 4 );
		}
	}
}

/* 0x00447350 */
void PRT_fn_vSourceGenerateSpriteParticle
		(
			PRT_tdstParticlesSystem *_p_stParticlesSystem,
            PRT_tdstParticlesSource *_p_stParticlesSource,
            POS_tdstCompletePosition *_p_stSourceMatrix,
            MTH_tdxReal _xTimeT
		)
{

	PRT_tdstSpriteParticle		*p_stSpriteParticle;
	MTH3D_tdstVector			*p_stParticlePosition;
	MTH3D_tdstVector			*p_stParticleSpeed;
	ACP_tdxIndex				xNbParticlesToInject;
	ACP_tdxIndex				xIndex;
	ACP_tdxIndex				xSpriteIndex;
	PRT_tdstSpriteCommonData	*p_stSpriteCommonData;
	PRT_tdstSpriteData			*p_stSprData;
	char						cProba;

	if ( PRT_fn_bComputeParticlesGeneration ( _p_stParticlesSource ) )
	{
		xNbParticlesToInject = (ACP_tdxIndex) MTH_M_xRealToLong ( MTH_M_xMul ( MTH_M_xLongToReal ( PRT_fn_xComputeNbParticlesToInject ( _p_stParticlesSource ) ), GAM_pc_g_xParticuleRate ) );

		if ( xNbParticlesToInject > 0 )
		{
			if ( _p_stParticlesSystem->xNbActiveParticles + xNbParticlesToInject > _p_stParticlesSystem->xNbParticles )
			{
				xNbParticlesToInject = _p_stParticlesSystem->xNbParticles - _p_stParticlesSystem->xNbActiveParticles;
			}

			p_stSpriteCommonData = (PRT_tdstSpriteCommonData *)(_p_stParticlesSystem->p_stCommonData);
			p_stSpriteParticle = (PRT_tdstSpriteParticle *)(_p_stParticlesSystem->d_stListOfParticles) + _p_stParticlesSystem->xNbActiveParticles;
			p_stParticlePosition = _p_stParticlesSystem->hParticlesSystemObject->d_stListOfPoints + _p_stParticlesSystem->xNbActiveParticles;
			p_stParticleSpeed = _p_stParticlesSystem->d_stSpeed + _p_stParticlesSystem->xNbActiveParticles;
			xSpriteIndex = _p_stParticlesSystem->xNbActiveParticles;
			_p_stParticlesSystem->xNbActiveParticles += xNbParticlesToInject;

			for ( xIndex = 0 ; xIndex < xNbParticlesToInject ; xIndex ++ )
			{

				PRT_fn_vGenerateSpriteParticle
					(
						p_stParticlePosition,
						p_stParticleSpeed,
                        p_stSpriteParticle,
						p_stSpriteCommonData,
						_p_stParticlesSource,
						_p_stSourceMatrix,
						_xTimeT
					);

				if ( (p_stSprData = p_stSpriteCommonData->d_stSpriteData) != NULL )
				{
					cProba = (char) RND_fn_lGetLongRandomValue( 0, 0, 100);
					while (p_stSprData->cProba <= cProba )
						p_stSprData++;

					GEO_vSetHandleOfIndexedSprite( _p_stParticlesSystem->hParticlesSystemObject, 0, xSpriteIndex, p_stSprData->hSprite );

					if (p_stSprData->xTime < 0)
						p_stSpriteParticle->xChangeSpriteDate = MTH_C_InfinitPlus;
					else
					{
						p_stSpriteParticle->xChangeSpriteDate = _xTimeT + p_stSprData->xTime;
						p_stSpriteParticle->cNextSpriteIndex  = p_stSprData->cNextSprite;
					}

					xSpriteIndex++;
				}

				p_stSpriteParticle ++;
				p_stParticlePosition ++;
				p_stParticleSpeed ++;
			}
		}
	}
}
