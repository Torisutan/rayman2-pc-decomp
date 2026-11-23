#include "GAM/GAM_types.h"
#include "GAM/cineinfo.h"
#include "HIE/HIE_types.h"
#include "POS/POS_types.h"
#include "MTH/MTH_flt.h"
#include "GAM/GAM_globals.h"
#include "ERM/CpaError.h"

#define E_uwGameMiniStructObjectNull ((unsigned short)0xE)
#define E_uwGameMiniStructAllocAlreadyAlloc ((unsigned short)0xD)
#define E_uwGameMiniStructNull       ((unsigned short)0xF)

/* 0x004078C0 */
extern void __cdecl fn_vGameFreeInHLM(void *p_vObject);

#define CAM_M_pCineinfo(_p) ((MS_tdxHandleToCineinfo)(_p)->h_Cineinfo)

CAM_tdstCameraConstants CAM_g_stCameraConstants;       /* 0x004FF660 */
CAM_tdstCameraConstants CAM_g_stCopyCameraConstants;   /* 0x004FF6E0 */

unsigned long CAM_fn_ulCineinfoSizeOf( void )
{
	return(sizeof(struct tdstCineinfo_));
}

unsigned long CAM_fn_ulCineinfoInternalSizeOf( void )
{
	return(sizeof(struct tdstInternalStructurCineinfo_));
}

MS_tdxHandleToCineinfo CAM_fn_hCineinfoRealAlloc( void )
{
	MS_tdxHandleToCineinfo hCineinfo;
	hCineinfo = (MS_tdxHandleToCineinfo) fnp_vGameMallocInHLM(CAM_fn_ulCineinfoSizeOf());
	return(hCineinfo);
}

MS_tdxHandleToInternalCineinfo CAM_fn_hCineinfoInternalRealAlloc()
{
	MS_tdxHandleToInternalCineinfo hCineinfoInternal;
	hCineinfoInternal = (MS_tdxHandleToInternalCineinfo) fnp_vGameMallocInHLM(CAM_fn_ulCineinfoInternalSizeOf());
	return(hCineinfoInternal);
}

void CAM_fn_vCineinfoFree(struct tdstEngineObject_ *_p_stObject)
{
	if (_p_stObject == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructObjectNull, -1, 0xff, 0xff, NULL);
	}

	if (_p_stObject->h_Cineinfo == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructNull, -1, 0xff, 0xff, NULL);
	}

	if (CAM_M_pCineinfo(_p_stObject)->hInit == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructNull, -1, 0xff, 0xff, NULL);
	}
	fn_vGameFreeInHLM(CAM_M_pCineinfo(_p_stObject)->hInit);
	CAM_M_pCineinfo(_p_stObject)->hInit = NULL;

	if (CAM_M_pCineinfo(_p_stObject)->hCurrent == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructNull, -1, 0xff, 0xff, NULL);
	}
	fn_vGameFreeInHLM(CAM_M_pCineinfo(_p_stObject)->hCurrent);
	CAM_M_pCineinfo(_p_stObject)->hCurrent = NULL;

	if (CAM_M_pCineinfo(_p_stObject)->hVisibility == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructNull, -1, 0xff, 0xff, NULL);
	}
	fn_vGameFreeInHLM(CAM_M_pCineinfo(_p_stObject)->hVisibility);
	CAM_M_pCineinfo(_p_stObject)->hVisibility = NULL;

	if (CAM_M_pCineinfo(_p_stObject)->hWork == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructNull, -1, 0xff, 0xff, NULL);
	}
	fn_vGameFreeInHLM(CAM_M_pCineinfo(_p_stObject)->hWork);
	CAM_M_pCineinfo(_p_stObject)->hWork = NULL;

	fn_vGameFreeInHLM(_p_stObject->h_Cineinfo);
	_p_stObject->h_Cineinfo = NULL;
}

void CAM_fn_vCineinfoDesinit(struct tdstEngineObject_ *_p_stObject, int _eObjectInit)
{
	if (_p_stObject == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructObjectNull, -1, 0xff, 0xff, NULL);
	}
	if (_p_stObject->h_Cineinfo == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructNull, -1, 0xff, 0xff, NULL);
	}
}

void CAM_fn_vCineinfoAlloc(struct tdstEngineObject_ *_p_stObject)
{
	if (_p_stObject == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructObjectNull, -1, 0xff, 0xff, NULL);
	}

	if (CAM_M_pCineinfo(_p_stObject) != NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructAllocAlreadyAlloc, -1, 0xff, 0xff, NULL);
	}

	_p_stObject->h_Cineinfo = CAM_fn_hCineinfoRealAlloc();
	CAM_M_pCineinfo(_p_stObject)->hInit = CAM_fn_hCineinfoInternalRealAlloc();
	CAM_M_pCineinfo(_p_stObject)->hCurrent = CAM_fn_hCineinfoInternalRealAlloc();
	CAM_M_pCineinfo(_p_stObject)->hVisibility = CAM_fn_hCineinfoInternalRealAlloc();
	CAM_M_pCineinfo(_p_stObject)->hWork = CAM_fn_hCineinfoInternalRealAlloc();

	MTH3D_M_vNullVector(&CAM_M_pCineinfo(_p_stObject)->hInit->stShiftTarget);
	MTH3D_M_vNullVector(&CAM_M_pCineinfo(_p_stObject)->hInit->stShiftPos);

	CAM_M_pCineinfo(_p_stObject)->hInit->xDistMin = (MTH_tdxReal)6.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xDistMax = (MTH_tdxReal)6.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xBoundDistMin = (MTH_tdxReal)2.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xBoundDistMax = (MTH_tdxReal)10.0f;

	CAM_M_pCineinfo(_p_stObject)->hInit->xAngleAlpha = MTH_C_ZERO;
	CAM_M_pCineinfo(_p_stObject)->hInit->xAngleShiftAlpha = MTH_C_ZERO;
	CAM_M_pCineinfo(_p_stObject)->hInit->xAngleTheta = MTH_C_ZERO;
	CAM_M_pCineinfo(_p_stObject)->hInit->xAngleShiftTheta = MTH_C_ZERO;

	CAM_M_pCineinfo(_p_stObject)->hInit->xLinearSpeed = (MTH_tdxReal)200.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xLinearIncreaseSpeed = (MTH_tdxReal)1.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xLinearDecreaseSpeed = MTH_C_ZERO;

	CAM_M_pCineinfo(_p_stObject)->hInit->xAngularSpeed = (MTH_tdxReal)3.14f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xAngularIncreaseSpeed = (MTH_tdxReal)1.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xAngularDecreaseSpeed = MTH_C_ZERO;

	CAM_M_pCineinfo(_p_stObject)->hInit->xTargetSpeed = (MTH_tdxReal)200.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xTargetIncreaseSpeed = (MTH_tdxReal)1.0f;
	CAM_M_pCineinfo(_p_stObject)->hInit->xTargetDecreaseSpeed = MTH_C_ZERO;

	CAM_M_pCineinfo(_p_stObject)->hInit->xFocal = (MTH_tdxReal)1.5f;

	CAM_M_pCineinfo(_p_stObject)->hInit->xZMin = MTH_C_InfinitMinus;
	CAM_M_pCineinfo(_p_stObject)->hInit->xZMax = MTH_C_InfinitPlus;

	CAM_M_pCineinfo(_p_stObject)->hInit->hSuperObjectTargeted = NULL;
	CAM_M_pCineinfo(_p_stObject)->hInit->hSecondSuperObjectTargeted = NULL;

	CAM_M_pCineinfo(_p_stObject)->hInit->uwDNMFlags = 0;
	CAM_M_pCineinfo(_p_stObject)->hInit->uwIAFlags = 0;

	CAM_M_pCineinfo(_p_stObject)->hInit->eTypeOfViewport = CAM_e_NoViewport;
	CAM_M_pCineinfo(_p_stObject)->hInit->cChannel = -1;
	CAM_M_pCineinfo(_p_stObject)->hInit->bIsActive = 0;
}

void fn_vInitAveragePositionDatasIfNecessary(MS_tdxHandleToCineinfo	_hCineinfo)
{
	unsigned long			ulIndex;
    MTH_tdxReal             xBaseTime;
    MTH3D_tdstVector        *p_stVectorPos;

	for ( ulIndex = 0; ulIndex < C_ucNbOfCheckedSpeeds; ulIndex ++ )
        if(_hCineinfo ->AveragePosition.a_CheckedTime[ulIndex])
            break;

    if(ulIndex < C_ucNbOfCheckedSpeeds)
		return;

    p_stVectorPos = POS_fn_p_stGetTranslationVector(HIE_fn_hGetSuperObjectGlobalMatrix(_hCineinfo->hWork->hSuperObjectTargeted));
    xBaseTime     = (MTH_tdxReal)0.03f;

	for ( ulIndex = 0; ulIndex < C_ucNbOfCheckedSpeeds; ulIndex ++ )
    {
		_hCineinfo->AveragePosition.a_CheckedTime[ulIndex] = xBaseTime;
        MTH3D_M_vNullVector(&(_hCineinfo ->AveragePosition.a_CheckedSpeed[ulIndex]));
        MTH3D_M_vCopyVector(&(_hCineinfo ->AveragePosition.a_CheckedPos[ulIndex]),p_stVectorPos);
    }
}

void CAM_fn_vAverageSpeed(MS_tdxHandleToCineinfo _hCineinfo,MTH_tdxReal xTimeWindow,MTH3D_tdstVector *p_result)
{
	MTH_tdxReal				xCurrentTime,tmpTime;
	unsigned long			ulIndex;
	MTH3D_tdstVector		*p_stTmp;

	fn_vInitAveragePositionDatasIfNecessary(_hCineinfo);

	xCurrentTime = 0;
	MTH3D_M_vNullVector(p_result);

	for ( ulIndex = 0; ulIndex < C_ucNbOfCheckedSpeeds; ulIndex ++ )
	{
		tmpTime = _hCineinfo ->AveragePosition.a_CheckedTime[ulIndex];

		p_stTmp = &(_hCineinfo ->AveragePosition.a_CheckedSpeed[ulIndex]);

		if(tmpTime && !MTH3D_M_bIsNullVector(p_stTmp))
		{
			xCurrentTime += tmpTime;
			MTH3D_M_vMulAddVector( p_result, tmpTime , p_stTmp , p_result );

			if(xCurrentTime >= xTimeWindow)
				break;
		}
	}
	if ( xCurrentTime )
		MTH3D_M_vDivScalarVector( p_result , p_result , xCurrentTime);
}

void CAM_fn_vAveragePosition(MS_tdxHandleToCineinfo _hCineinfo,MTH_tdxReal xTimeWindow,MTH3D_tdstVector *p_result)
{
	MTH_tdxReal				xCurrentTime,tmpTime;
	unsigned long			ulIndex;
	MTH3D_tdstVector		*p_stTmp;

	fn_vInitAveragePositionDatasIfNecessary(_hCineinfo);

	xCurrentTime = 0;
    MTH3D_M_vNullVector(p_result);

	for ( ulIndex = 0; ulIndex < C_ucNbOfCheckedSpeeds; ulIndex ++ )
	{
		tmpTime = _hCineinfo ->AveragePosition.a_CheckedTime[ulIndex];
			p_stTmp = &(_hCineinfo ->AveragePosition.a_CheckedPos[ulIndex]);

			if(tmpTime && !MTH3D_M_bIsNullVector(p_stTmp))
			{
				xCurrentTime += tmpTime;

				MTH3D_M_vMulAddVector( p_result, tmpTime , p_stTmp , p_result );

				if(xCurrentTime >= xTimeWindow)
					break;
			}
	}
	if(xCurrentTime)
        MTH3D_M_vDivScalarVector( p_result, p_result, xCurrentTime);
}

#define MTH_C_PiBy16 ((float) 1.9634954084936207E-1)

void CAM_fn_vLoadCameraConstants(void)
{
	CAM_g_stCameraConstants.xRayCameraSphereToGo1 = MTH_M_xConstFloatToReal(0.35f);
	CAM_g_stCameraConstants.xRayCameraSphereToGo2 = MTH_M_xConstFloatToReal(0.35f);
	CAM_g_stCameraConstants.xRayCameraSphereToSee1 = MTH_M_xConstFloatToReal(0.10f);
	CAM_g_stCameraConstants.xRayCameraSphereToSee2 = MTH_M_xConstFloatToReal(0.10f);

	CAM_g_stCameraConstants.xBaseAngleComputePosNormal = MTH_C_PiBy4;
	CAM_g_stCameraConstants.xBaseAngleComputePosFailure = MTH_C_PiBy4;
	CAM_g_stCameraConstants.xBaseCutAngle = MTH_C_PiBy8;

	CAM_g_stCameraConstants.xAverageForComputePos = MTH_M_xConstFloatToReal(0.40f);
	CAM_g_stCameraConstants.xAverageForComputeLinearSpeed = MTH_M_xConstFloatToReal(0.40f);

	CAM_g_stCameraConstants.xMinLinearSpeedCamera = MTH_M_xConstFloatToReal(0.005f);
	CAM_g_stCameraConstants.xMinLinearSpeedTgtPerso = MTH_M_xConstFloatToReal(0.01f);
	CAM_g_stCameraConstants.xMinAngularSpeedTgtPerso = MTH_M_xConstFloatToReal(0.01f);

	CAM_g_stCameraConstants.xEpsilonDynTgtAngle = MTH_C_PiBy4;
	CAM_g_stCameraConstants.xEpsilonDynTgtFocalAngle = MTH_C_PiBy16;
	CAM_g_stCameraConstants.xEpsilonForEqualVectors = MTH_M_xConstFloatToReal(0.5f);

	CAM_g_stCameraConstants.xOffsetMinDistPerso = MTH_M_xConstFloatToReal(0.05f);
	CAM_g_stCameraConstants.xDistanceForNoCut = MTH_C_5;

	CAM_g_stCameraConstants.xNumRayCameraCanGo = 3;
	CAM_g_stCameraConstants.xNumRayCameraCanSee = 1;

	CAM_g_stCameraConstants.xTickTestVisibility = 4;
	CAM_g_stCameraConstants.xTickFindBetterPos = 20;
	CAM_g_stCameraConstants.xTickFindBetterPosIfNoMove = 60;
	CAM_g_stCameraConstants.xTickFailureCantSee = 60;

	CAM_g_stCameraConstants.xDynSpeed_LinearFactNorm = MTH_C_3;
	CAM_g_stCameraConstants.xDynSpeed_LinearMax = MTH_M_xLongToReal(10);
	CAM_g_stCameraConstants.xDynSpeed_LinearMulPerso = MTH_M_xConstFloatToReal(1.5f);
	CAM_g_stCameraConstants.xDynSpeed_AngularFactNorm = MTH_C_3;
	CAM_g_stCameraConstants.xDynSpeed_AngularMax = MTH_C_3;
	CAM_g_stCameraConstants.xDynSpeed_AngularMulPerso = MTH_C_ZERO;
	CAM_g_stCameraConstants.xDynSpeed_TargetFactNorm = MTH_C_4;
	CAM_g_stCameraConstants.xDynSpeed_TargetMax = MTH_M_xLongToReal(10);
	CAM_g_stCameraConstants.xDynSpeed_TargetMulPerso = MTH_C_ONE;

	CAM_g_stCameraConstants.xCutAngleFactorPos = MTH_C_ONE;
	CAM_g_stCameraConstants.xCutAngleFactorTgt = MTH_C_ONE;

	CAM_g_stCameraConstants.wFlags = 0;
}

MTH3D_tdstVector *fn_p_CineinfoGetSightAxis(MS_tdxHandleToCineinfo _hCineinfo)
{
	return (&(_hCineinfo->stSightAxisSystem.SightAxis));
}

MTH3D_tdstVector *fn_p_CineinfoGetFirstComplementaryAxis(MS_tdxHandleToCineinfo _hCineinfo)
{
	return (&(_hCineinfo->stSightAxisSystem.FirstComplementaryAxis));
}

MTH3D_tdstVector *fn_p_CineinfoGetSecondComplementaryAxis(MS_tdxHandleToCineinfo _hCineinfo)
{
	return (&(_hCineinfo->stSightAxisSystem.SecondComplementaryAxis));
}

void fn_vGetPersoSightAxisSystem
(
	MS_tdxHandleToCineinfo		_hCineinfo,
	MTH3D_tdstVector			*_p_stSightAxis,
	MTH3D_tdstVector			*_p_stFirstComplementaryAxis,
	MTH3D_tdstVector			*_p_stSecondComplementaryAxis
)
{
	MTH3D_M_vCopyVector(_p_stSightAxis , fn_p_CineinfoGetSightAxis(_hCineinfo));
	MTH3D_M_vCopyVector(_p_stFirstComplementaryAxis , fn_p_CineinfoGetFirstComplementaryAxis(_hCineinfo));
	MTH3D_M_vCopyVector(_p_stSecondComplementaryAxis , fn_p_CineinfoGetSecondComplementaryAxis(_hCineinfo));
}

void CAM_fn_vSetCineinfoVisibilityFromCurrent(MS_tdxHandleToCineinfo _hCineinfo)
{
	if(!(_hCineinfo->ucPerIAFlags & C_PerIAFlags_VisibilityCopied))
	{
		*_hCineinfo->hVisibility = *_hCineinfo->hCurrent;
		_hCineinfo->ucPerIAFlags |= C_PerIAFlags_VisibilityCopied;
	}
}

void CAM_fn_vSetCameraInList(struct HIE_tdstSuperObject *_hSupObjectCamera)
{
	tdstNodeCamera *p_stTempNodeCamera;

	p_stTempNodeCamera = (tdstNodeCamera *)fnp_vGameMallocInHLM(sizeof(tdstNodeCamera));
	p_stTempNodeCamera->p_stSuperObjectCamera = _hSupObjectCamera;

	p_stTempNodeCamera->hPrev = NULL;
	p_stTempNodeCamera->hFather = NULL;

	p_stTempNodeCamera->hNext = NULL;
	p_stTempNodeCamera->hPrev = GAM_g_stEngineStructure.hCameraList_hLastElementDyn;
	p_stTempNodeCamera->hFather = &GAM_g_stEngineStructure.hCameraList_hFirstElementDyn;

	if (GAM_g_stEngineStructure.hCameraList_hFirstElementDyn == NULL)
	{
		GAM_g_stEngineStructure.hCameraList_hFirstElementDyn = p_stTempNodeCamera;
		GAM_g_stEngineStructure.hCameraList_hLastElementDyn = p_stTempNodeCamera;
		GAM_g_stEngineStructure.hCameraList_lNumberOfElementsDyn++;
		return;
	}
	((tdstNodeCamera *)GAM_g_stEngineStructure.hCameraList_hLastElementDyn)->hNext = p_stTempNodeCamera;
	GAM_g_stEngineStructure.hCameraList_hLastElementDyn = p_stTempNodeCamera;
	GAM_g_stEngineStructure.hCameraList_lNumberOfElementsDyn++;
}

#define E_uwGameCineInfoSuperObjectNull ((unsigned short)0x10)

void CAM_fn_vCineinfoInit(struct tdstEngineObject_ *_p_stObject, int _eObjectInit)
{
	MS_tdxHandleToCineinfo	hCineinfo;
	struct HIE_tdstSuperObject *hSupObjectCamera;

	if (_p_stObject == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructObjectNull, -1, 0xff, 0xff, NULL);
	}

	hCineinfo = (MS_tdxHandleToCineinfo)_p_stObject->h_Cineinfo;
	if (_p_stObject->h_Cineinfo == NULL)
	{
		ERM_fn_vClearLastError(0);
		ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameMiniStructNull, -1, 0xff, 0xff, NULL);
	}

	switch (_eObjectInit)
	{
	case 0:
		break;
	case 1:
		hSupObjectCamera = M_GetSuperObject(_p_stObject);
		if (hSupObjectCamera == NULL)
		{
			ERM_fn_vClearLastError(0);
			ERM_fn_vUpdateLastError(0x30, g_ucGameModuleId, 0, E_uwGameCineInfoSuperObjectNull, -1, 0xff, 0xff, NULL);
		}
		CAM_fn_vSetCameraInList(hSupObjectCamera);

	case 2:
	case 3:
	case 4:
	case 5:
		hCineinfo->hInit->hSuperObjectTargeted = GAM_pc_g_hMainCharacterSO;
		CAM_fn_vInitCompleteCineinfo(hCineinfo);
		break;
	default:
		break;
	}
}

/* 0x00414040 */
void __cdecl CAM_fn_vCineinfoCopyClone(struct tdstEngineObject_ *_p_stObjectDest, struct tdstEngineObject_ *_p_stObjectSrc)
{
    memcpy(((struct tdstCineinfo_ *)_p_stObjectDest->h_Cineinfo)->hInit,
           ((struct tdstCineinfo_ *)_p_stObjectSrc->h_Cineinfo)->hInit,
           sizeof(struct tdstInternalStructurCineinfo_));
}
