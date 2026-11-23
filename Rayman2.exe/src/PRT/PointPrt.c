#include "PRT/PRT_types.h"
#include "RND/RND.h"
#include "MTH/MTH_flt.h"
#include "MTH/MTH_xNeg.h"
#include "GAM/GAM_globals.h"

/* 0x004468E0 */
void PRT_fn_vGeneratePointParticle ( MTH3D_tdstVector *_p_stParticlePosition,
                                     MTH3D_tdstVector *_p_stParticleSpeed,
                                     PRT_tdstPointParticle *_p_stPointParticle,
                                     PRT_tdstPointCommonData *_p_stPointCommonData,
                                     PRT_tdstParticlesSource *_p_stParticlesSource,
                                     POS_tdstCompletePosition *_p_stSourceMatrix,
                                     MTH_tdxReal _xTimeT )
{
  MTH3D_tdstVector stSpeedVariation;
  MTH_tdxReal xC1;
  MTH_tdxReal xC2;
  MTH_tdxReal xC3;
  MTH_tdxReal xC4;
  MTH3D_tdstVector stTrans;

  MTH3D_M_vSetVectorElements ( &stSpeedVariation,
    RND_fn_xGetRealRandomValue ( 0, MTH_M_xNeg ( _p_stParticlesSource->xSpeedRange ), _p_stParticlesSource->xSpeedRange ),
    RND_fn_xGetRealRandomValue ( 0, MTH_M_xNeg ( _p_stParticlesSource->xSpeedRange ), _p_stParticlesSource->xSpeedRange ),
    RND_fn_xGetRealRandomValue ( 0, MTH_M_xNeg ( _p_stParticlesSource->xSpeedRange ), _p_stParticlesSource->xSpeedRange ) );

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
  else
  if ( _p_stParticlesSource->ucGeometryMode == PRT_C_ucParallelepipede )
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
  else
  if ( _p_stParticlesSource->ucLinkMode == PRT_C_ucTranslationLink )
  {
    POS_fn_vGetTranslationVector( _p_stSourceMatrix, &stTrans );
    MTH3D_M_vAddVector ( _p_stParticlePosition, &stTrans, _p_stParticlePosition );
  }
  else
  if ( _p_stParticlesSource->ucLinkMode == PRT_C_ucRotationLink )
  {
    POS_fn_vMulMatrixVector ( _p_stParticlePosition, _p_stSourceMatrix, _p_stParticlePosition );
  }

}

/* 0x00446B80 */
void PRT_fn_vSourceGeneratePointParticle ( PRT_tdstParticlesSystem *_p_stParticlesSystem,
                                           PRT_tdstParticlesSource *_p_stParticlesSource,
                                           POS_tdstCompletePosition *_p_stSourceMatrix,
                                           MTH_tdxReal _xTimeT )
{
  PRT_tdstPointParticle *p_stPointParticle;
  MTH3D_tdstVector *p_stParticlePosition;
  MTH3D_tdstVector *p_stParticleSpeed;
  ACP_tdxIndex xNbParticlesToInject;
  ACP_tdxIndex xIndex;

  if ( PRT_fn_bComputeParticlesGeneration ( _p_stParticlesSource ) )
  {

	xNbParticlesToInject = (ACP_tdxIndex) MTH_M_xRealToLong ( MTH_M_xMul ( MTH_M_xLongToReal ( PRT_fn_xComputeNbParticlesToInject ( _p_stParticlesSource ) ), GAM_pc_g_xParticuleRate ) );

    if ( xNbParticlesToInject > 0 )
    {
      if ( _p_stParticlesSystem->xNbActiveParticles + xNbParticlesToInject > _p_stParticlesSystem->xNbParticles )
      {
        xNbParticlesToInject = _p_stParticlesSystem->xNbParticles - _p_stParticlesSystem->xNbActiveParticles;
      }

      p_stPointParticle = (PRT_tdstPointParticle *)(_p_stParticlesSystem->d_stListOfParticles) + _p_stParticlesSystem->xNbActiveParticles;
      p_stParticlePosition = _p_stParticlesSystem->hParticlesSystemObject->d_stListOfPoints + _p_stParticlesSystem->xNbActiveParticles;
      p_stParticleSpeed = _p_stParticlesSystem->d_stSpeed + _p_stParticlesSystem->xNbActiveParticles;
      _p_stParticlesSystem->xNbActiveParticles += xNbParticlesToInject;

      for ( xIndex = 0 ; xIndex < xNbParticlesToInject ; xIndex ++ )
      {

        PRT_fn_vGeneratePointParticle ( p_stParticlePosition, p_stParticleSpeed,
                                        p_stPointParticle, (PRT_tdstPointCommonData *)(_p_stParticlesSystem->p_stCommonData),
                                        _p_stParticlesSource, _p_stSourceMatrix, _xTimeT );

        p_stPointParticle ++;
        p_stParticlePosition ++;
        p_stParticleSpeed ++;
      }
    }
  }
}
