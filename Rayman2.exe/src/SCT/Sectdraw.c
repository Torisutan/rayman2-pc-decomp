#include <malloc.h>
#include "GLI/light_fog.h"
#include "MTH/MTH3D.h"
#include "GAM/GAM_types.h"
#include "GMT/GMT_types.h"
#include "SCT/Sector.h"
#include "GAM/STRUCTUR/Engmode.h"
#include "HIE/HieSpObj.h"

unsigned long __cdecl fn_ulStandardGameGetCustomBitsSO(void *hSupObj);

#define GEO_C_lCullingOut_PC 0x00

extern void __cdecl GLI_vAddLightToViewport(void *p_stVpt, void *p_stLight);     /* 0x00426B80 */
extern unsigned char __cdecl GLI_ucGetObjectLighted(void *p_stLight);            /* 0x004270C0 */
extern void __cdecl GLI_vSetFog2(float xBlendStart, float xDepthStart, float xBlendEnd,
                                 float xDepthEnd, float xInfinite, unsigned long *p_ulColor);   /* 0x00424010 */
extern void *__cdecl SECT_fn_p_stGetMinPointInBorder(void *_hSector);            /* 0x0044C2F0 */
extern void *__cdecl SECT_fn_p_stGetMaxPointInBorder(void *_hSector);            /* 0x0044C300 */

/* 0x0044ADC0 */
static void SECT_fn_vSendDynamicLightsOfASector(
	void	*_p_stVpt,
	SECT_tdxHandleOfSectorObject _hSectorObject,
	long _lCullingResult)
{
	SECT_tdxHandleOfElementLstDNMLights hDNMLightsElement, hPrevDNMLightsElement = NULL;
	ACP_tdxIndex						xI;

	LST2_M_DynamicForEachElementOf(
		&(_hSectorObject->stListOfDNMLights),
		hDNMLightsElement,
		xI)
	{
		if (hDNMLightsElement == hPrevDNMLightsElement)
			break;

		GLI_vAddLightToViewport(_p_stVpt, hDNMLightsElement->hDNMLights);
		hPrevDNMLightsElement = hDNMLightsElement;
	}
}

/* 0x0044ADF0 */
void __cdecl SECT_fn_vSendDynamicLightsFromWhereIAmToViewport(
	void	*_p_stVpt,
	HIE_tdstSuperObject *_hSprObjSector)
{
	SECT_tdxHandleOfSectorObject					hSectorObject;
	SECT_tdxHandleOfElementLstGraphicInteraction	hGraphicInteractionChild;
	ACP_tdxIndex									xI;

	hSectorObject = (SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSprObjSector);

	SECT_fn_vSendDynamicLightsOfASector(_p_stVpt, hSectorObject, GEO_C_lCullingOut);

	LST2_M_StaticForEachElementOf(&hSectorObject->stListOfSectorsInGraphicInteraction, hGraphicInteractionChild, xI)
	{
		SECT_fn_vSendDynamicLightsOfASector(_p_stVpt,
			(SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(hGraphicInteractionChild->hPointerOfSectorSO),
			GEO_C_lCullingOut);
	}
}

#define GLI_C_LightPerso	0x02

/* 0x0044AE30 */
short __cdecl SECT_fn_xSendStaticLightsToViewportForChar(
	void	*_p_stVpt, HIE_tdstSuperObject *_hSprObjSector,
	long _lCullingResult)
{
	ACP_tdxIndex							xI, xNotAdd = 0;
	SECT_tdxHandleOfSectorObject			hSectorObject;
	SECT_tdxHandleOfElementLstStaticLights	hStaticLightsElement;
	void									*hStaticLight;

	hSectorObject = (SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSprObjSector);

	LST2_M_StaticForEachElementOf(&hSectorObject->stListOfStaticLights, hStaticLightsElement, xI)
	{
		hStaticLight = hStaticLightsElement->hStaticLights;
		if (GLI_ucGetObjectLighted(hStaticLight) & GLI_C_LightPerso)
		{
			GLI_vAddLightToViewport(_p_stVpt, hStaticLight);
			xNotAdd++;
		}
	}

	return xNotAdd;
}

/* 0x0044AE80 */
void __cdecl SECT_fn_vSendFogToViewport(
		void *_p_stVpt,
		HIE_tdstSuperObject *_hSprObjSector)
{
	if (GLI_g_cGlobalFogIsOn)
	{
        GLI_vFogOn();
        return;
	}
	else
	{
		ACP_tdxIndex							xI;
		SECT_tdxHandleOfSectorObject			hSectorObject = (SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSprObjSector);
		SECT_tdxHandleOfElementLstStaticLights	hStaticLightsElement;
		unsigned long stColor[4];
		void *hStaticLight;

		LST2_M_StaticForEachElementOf(&hSectorObject->stListOfStaticLights, hStaticLightsElement, xI)
		{
			hStaticLight = hStaticLightsElement->hStaticLights;
			if ( GLI_lGetLightType(hStaticLight) == GLI_C_lFogLight )
			{
				GLI_vFogGetColor(hStaticLight, stColor);

				GLI_vSetFog2(
					GLI_fn_xFogGetBlendNear(hStaticLight),
					GLI_fn_xFogGetNear(hStaticLight),
					GLI_fn_xFogGetBlendFar(hStaticLight),
					GLI_fn_xFogGetFar(hStaticLight),
					GLI_fn_xFogGetInfinite(hStaticLight),
					stColor);

		        GLI_vFogOn();
		        return;
			}
		}
	}
	GLI_vFogOff();
}

#define SCT_pc_C_xBorderEpsilon 0.01f

/* 0x0044AF30 */
long SCT_fn_lSendSectorToViewportStatic(void *_p_stAbsolutePositionOfCamera, void *_p_stVpt,
                                        HIE_tdstSuperObject *_hSprObjSector, long _lDrawMask)
{
	SECT_tdxHandleOfSectorObject			hSectorObject;
	MTH3D_tdstVector						*p_stBdvMinPoint;
	MTH3D_tdstVector						*p_stBdvMaxPoint;
	MTH3D_tdstVector						*p_stBorderMinPoint;
	MTH3D_tdstVector						*p_stBorderMaxPoint;
	long									lCullingResult = GEO_C_lCullingOut;
	MTH3D_tdstVector						stDeltaMin, stDeltaMax;
	MTH_tdxReal								xNorm1;

	hSectorObject = (SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSprObjSector);

	SECT_fn_vSendFogToViewport(_p_stVpt, _hSprObjSector);

	{
		GEO_tdxHandleToParallelBox hParallelBox = (GEO_tdxHandleToParallelBox) HIE_fn_hGetSuperObjectBoundingVolume(_hSprObjSector);

		p_stBorderMinPoint = SECT_fn_p_stGetMinPointInBorder(hSectorObject);
		p_stBorderMaxPoint = SECT_fn_p_stGetMaxPointInBorder(hSectorObject);

		if ( hParallelBox )
		{

			p_stBdvMinPoint = GEO_fn_pGetMinPointOfParallelBox(hParallelBox);
			p_stBdvMaxPoint = GEO_fn_pGetMaxPointOfParallelBox(hParallelBox);

			lCullingResult = GEO_lCullingBox(_p_stVpt, p_stBdvMinPoint, p_stBdvMaxPoint, GEO_C_lCullingOut);
			if ( (lCullingResult != GEO_C_lCullingOut) || HIE_fn_SO_bCheckChildren(_hSprObjSector) )
			{

				HIE_fn_vSendStaticWorldToViewport(_p_stVpt, _hSprObjSector, _lDrawMask, lCullingResult);
			}

			MTH3D_M_vSubVector(&stDeltaMin, p_stBorderMinPoint, p_stBdvMinPoint);
			MTH3D_M_vSubVector(&stDeltaMax, p_stBorderMaxPoint, p_stBdvMaxPoint);

			if (!(MTH_M_bIsNullWithEpsilon((xNorm1 = (MTH_M_xAbs(stDeltaMin.xX) + MTH_M_xAbs(stDeltaMin.xY)) + MTH_M_xAbs(stDeltaMin.xZ)), SCT_pc_C_xBorderEpsilon) &&
				  MTH_M_bIsNullWithEpsilon(MTH3D_M_xNorm1Vector(&stDeltaMax), SCT_pc_C_xBorderEpsilon)))
			{
				long lMinInOut, lMaxInOut;

				lMinInOut = (MTH_M_bLessZero(stDeltaMin.xX) ? 1 : -1) + (MTH_M_bLessZero(stDeltaMin.xY) ? 1 : -1) + (MTH_M_bLessZero(stDeltaMin.xZ) ? 1 : -1);
				if ( (lMinInOut == -3) || (lMinInOut == 3) )
				{

					lMaxInOut = (MTH_M_bLessZero(stDeltaMax.xX) ? -1 : 1) + (MTH_M_bLessZero(stDeltaMax.xY) ? -1 : 1) + (MTH_M_bLessZero(stDeltaMax.xZ) ? -1 : 1);
				}
				else
				{
					lMaxInOut = 0;
				}

				if ( lMinInOut != lMaxInOut )
				{
					lCullingResult = GEO_lCullingBox(_p_stVpt, p_stBorderMinPoint, p_stBorderMaxPoint, GEO_C_lCullingOut);
				}
				else
				{
					if ( lMinInOut > 0 )
					{
							lCullingResult = GEO_lCullingBox(_p_stVpt, p_stBorderMinPoint, p_stBorderMaxPoint, GEO_C_lCullingOut);
					}
					else
					{
						if (!(lCullingResult != GEO_C_lCullingIn) && (lCullingResult != GEO_C_lCullingOut) )
						{
							lCullingResult = GEO_lCullingBox(_p_stVpt, p_stBorderMinPoint, p_stBorderMaxPoint, GEO_C_lCullingOut);
						}
					}
				}
			}
		}
		else
		{

			lCullingResult = GEO_lCullingBox(_p_stVpt, p_stBorderMinPoint, p_stBorderMaxPoint, GEO_C_lCullingOut);
		}
	}
	return lCullingResult;
}

/* 0x0044B1B0 */
extern unsigned char GAM_g_bInGameMenu;
extern void __cdecl GLI_vResetTableOfActiveLightsForChar(char _cValue);
extern void __cdecl GLI_vPopLightsInViewport(void *p_stVpt, long lNbLights);
extern void __cdecl GLI_vClearListOfLightInViewport(void *p_stVpt);
extern void __cdecl GEO_vSetZFar(float xZ);
extern void __cdecl GEO_vSetZFarTransparencyZone(float xZ);
extern float __cdecl fn_xGetSectorZFar(void *_hSprObjSector);
extern void __cdecl SHW_fn_vDrawShadow(void *p_stVpt, void *p_stSuperObject,
                                                       void *p_stSectorSuperObject,
                                                       unsigned long ulDrawMask);

#define GLI_C_lIsUseStaticLights					32768
#define GLI_C_lDrawNothing							0x200000

void __cdecl SCT_fn_vSendSectorToViewportDynamic(void *_p_stAbsolutePositionOfCamera, void *_p_stVpt,
                                                 HIE_tdstSuperObject *_hSprObjSector, long _lDrawMask,
                                                 long _lCullingResult)
{
	ACP_tdxIndex xI, xNbLights;
	SECT_tdxHandleOfSectorObject hSectorObject = (SECT_tdxHandleOfSectorObject) HIE_fn_hGetSuperObjectObject(_hSprObjSector);
	SECT_tdxHandleOfElementLstCharacter		hCharacter;
	HIE_tdstSuperObject *hCharacterSO;
	long lDrawmaskOfCharacter;
	unsigned long ulCustomBits ;

	if (_lCullingResult == GEO_C_lCullingOut && !GAM_g_bInGameMenu) {

		LST2_M_DynamicForEachElementOf(&(hSectorObject->stListOfCharacters), hCharacter, xI)
		{
		}
		return;
	}

	GLI_vResetTableOfActiveLightsForChar(1);
	xNbLights = 0;
	SECT_fn_vSendFogToViewport(_p_stVpt, _hSprObjSector);
	if ((_lDrawMask & GLI_C_lIsUseStaticLights) && (HIE_fn_lGetSuperObjectDrawMask(_hSprObjSector) & GLI_C_lIsUseStaticLights))
	{
		xNbLights=SECT_fn_xSendStaticLightsToViewportForChar(_p_stVpt, _hSprObjSector, _lCullingResult);
	}
	GEO_vSetZFar( fn_xGetSectorZFar( _hSprObjSector ) );
	GEO_vSetZFarTransparencyZone( MTH_C_ZERO );

	LST2_M_DynamicForEachElementOf(&(hSectorObject->stListOfCharacters), hCharacter, xI)
	{
		hCharacterSO = hCharacter->hPointerOfCharacter;
		lDrawmaskOfCharacter = HIE_fn_lGetSuperObjectDrawMask(hCharacterSO);
		ulCustomBits = fn_ulStandardGameGetCustomBitsSO(hCharacterSO) ;

		if ((!GAM_g_bInGameMenu) || (ulCustomBits & GAM_C_CustBitUnfreezable))

		if ( lDrawmaskOfCharacter & GLI_C_lDrawNothing )
		{
			HIE_fn_vSendCharacterToViewport(
				_p_stVpt,
				hCharacterSO,
				lDrawmaskOfCharacter & _lDrawMask,
				_lCullingResult
				);

			if ( ulCustomBits & GAM_C_CustBitActorHasShadow )
			{
				SHW_fn_vDrawShadow(_p_stVpt,hCharacterSO,_hSprObjSector,_lDrawMask);
			}
		}
	}

	if(xNbLights)
		GLI_vPopLightsInViewport(_p_stVpt,(unsigned long) xNbLights);
}

/* 0x0044B2E0 */
void SCT_fn_vSendSectorWhereIAmToViewport(void *_p_stAbsolutePositionOfCamera, void *_p_stVpt,
                                          void *_hSprObjSector, long _lDrawMask)
{
	ACP_tdxIndex									xI;
	SECT_tdxHandleOfSectorObject					hSectorObject;
	SECT_tdxHandleOfElementLstGraphicInteraction	hGraphicInteractionChild;
	long											*a_lCullingResultArray;

	hSectorObject = (SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSprObjSector);

	a_lCullingResultArray = alloca(sizeof(long) * (LST2_M_StaticGetNumberOfElements(&(hSectorObject->stListOfSectorsInGraphicInteraction)) +1 ));

	SECT_fn_vSendDynamicLightsFromWhereIAmToViewport(_p_stVpt, _hSprObjSector);
	HIE_fn_bInitCameraMatrixStack(_p_stVpt);

	if (!GAM_g_bInGameMenu)
	{

		a_lCullingResultArray[0] = SCT_fn_lSendSectorToViewportStatic(_p_stAbsolutePositionOfCamera,_p_stVpt,_hSprObjSector,_lDrawMask);

	}

	if (!GAM_g_bInGameMenu)
	{

	LST2_M_StaticForEachElementOf(&(hSectorObject->stListOfSectorsInGraphicInteraction),hGraphicInteractionChild,xI)
	{

		if ( !( (GAM_g_stEngineStructure_storage.cCameraMode != C_CamModeLook) && (hGraphicInteractionChild->cDisplayMode == C_SECT_ModeLookOnly) ) )
		{

				a_lCullingResultArray[xI+1] = SCT_fn_lSendSectorToViewportStatic(_p_stAbsolutePositionOfCamera,_p_stVpt,hGraphicInteractionChild->hPointerOfSectorSO,_lDrawMask);
		}
	}
	}

	SCT_fn_vSendSectorToViewportDynamic(_p_stAbsolutePositionOfCamera,_p_stVpt,_hSprObjSector,_lDrawMask,a_lCullingResultArray[0]);

	LST2_M_StaticForEachElementOf(&(hSectorObject->stListOfSectorsInGraphicInteraction),hGraphicInteractionChild,xI)
	{

		if ((GAM_g_bInGameMenu) || ( !( (GAM_g_stEngineStructure_storage.cCameraMode != C_CamModeLook) && (hGraphicInteractionChild->cDisplayMode == C_SECT_ModeLookOnly) ) ))
		{
				SCT_fn_vSendSectorToViewportDynamic(_p_stAbsolutePositionOfCamera,
													_p_stVpt,
													hGraphicInteractionChild->hPointerOfSectorSO,
													_lDrawMask,
													a_lCullingResultArray[xI+1]);
		}
	}

	GLI_vClearListOfLightInViewport (_p_stVpt);
}

/* 0x0044C450 */
extern unsigned short GAM_g_uw5115d0_storage;
extern short          g_a_xTextElement[10];       /* 0x00511620 */
extern GMT_tdxHandleToGameMaterial g_hTextGameMaterial; /* 0x005115D4 */

#include "GAM/PlayAnim.h"

void __cdecl GEO_vSetGameMaterialOfIndexedTriangles(void *hObject, short hElement, void *hMaterial);
float __cdecl GEO_xGetZFarTransparencyLevel(void);
unsigned long __cdecl fn_ulStandardGameGetCustomBitsSO(void *hSupObj);
float __cdecl GLI_fn_xGetGlobalAlpha(void);
void  __cdecl GLI_vSetGlobalAlpha(float xAlpha);
void  __cdecl GLI_xSendObjectToViewportWithLights(void *p_stVpt, void *p_stObj, long lDrawModeMask);
void  HIE_fn_vPopMatrix(void);                    /* 0x0045BFF0 */

void __cdecl SHW_fn_vSentToViewPort(void *p_stVpt,
                                                    void *p_stSuperObject,
                                                    long  _lUnused,
                                                    unsigned long ulDrawModeMask,
                                                    void *hObject)
{
    HIE_tdstSuperObject  *p_stSO;
    HIE_tdstEngineObject *p_stEngObj;
    unsigned long  ulCustomBits;
    unsigned long  ulExtraBits;
    unsigned long  ulMask;
    float          xSavedAlpha;
    float          xObjAlpha;
    int            bRestoreAlpha;

    p_stSO        = (HIE_tdstSuperObject *)p_stSuperObject;
    ulExtraBits   = 0;
    ulMask        = ulDrawModeMask;
    bRestoreAlpha = 0;
    xSavedAlpha   = 0.0f;

    p_stEngObj  = (HIE_tdstEngineObject *)p_stSO->hLinkedObject.p_Void;
    g_hTextGameMaterial = (GMT_tdxHandleToGameMaterial)((MS_tdxHandleTo3dData)p_stEngObj->h3dData)->p_stShadowMaterial;

    GEO_vSetGameMaterialOfIndexedTriangles(hObject,
                                           g_a_xTextElement[(short)GAM_g_uw5115d0_storage],
                                           (void *)g_hTextGameMaterial);
    HIE_fn_bLoadIdentity();

    ulCustomBits = fn_ulStandardGameGetCustomBitsSO(p_stSuperObject);
    if ((ulCustomBits & 0x200000UL) == 0) {
        if ((p_stSO->lDrawModeMask & 8) == 0) {
            ulMask &= 0xFFFBFFF7UL;
            xSavedAlpha = GLI_fn_xGetGlobalAlpha();
            xObjAlpha   = p_stSO->fTransparenceLevel;
            GLI_vSetGlobalAlpha(xObjAlpha);
            bRestoreAlpha = 1;
        } else {
            ulExtraBits = 0xF7FC0000UL;
        }
    } else {
        xSavedAlpha = GLI_fn_xGetGlobalAlpha();
        xObjAlpha   = p_stSO->fTransparenceLevel;
        GLI_vSetGlobalAlpha(GEO_xGetZFarTransparencyLevel() * xObjAlpha);
        ulMask &= 0xFFFBFFF7UL;
        bRestoreAlpha = 1;
    }

    GLI_xSendObjectToViewportWithLights(p_stVpt, hObject, (long)(ulExtraBits | ulMask));

    if (bRestoreAlpha) {
        GLI_vSetGlobalAlpha(xSavedAlpha);
    }
    HIE_fn_vPopMatrix();
}
