#ifndef AI_STRINTEL_H
#define AI_STRINTEL_H

#include "AI/EnumType.h"

#define M_DepthInterpret(p_Tree)           ((p_Tree)->ucDepth)

#define M_NodeToSkip(p_Tree)               ((p_Tree)->uwNodeToSkip)

#define M_TypeUnionInterpret(p_Tree)       (&((p_Tree)->uId))
#define M_eCondIdInterpret(p_Tree)				(*M_TypeUnionInterpret(p_Tree))
#define M_eKeyWordIdInterpret(p_Tree)			(*M_TypeUnionInterpret(p_Tree))
#define M_eOperatorIdInterpret(p_Tree)			(*M_TypeUnionInterpret(p_Tree))
#define M_eFuncIdInterpret(p_Tree)				(*M_TypeUnionInterpret(p_Tree))
#define M_eFieldIdInterpret(p_Tree)				(*M_TypeUnionInterpret(p_Tree))
#define M_eMetaActionIdInterpret(p_Tree)		(*M_TypeUnionInterpret(p_Tree))
#define M_hInputHandleIdInterpret(p_Tree)		(*M_TypeUnionInterpret(p_Tree))
#define M_szStringInterpret(p_Tree)				(M_GetSetParam_szString(p_Tree))
#define M_lValueInterpret(p_Tree)				(M_GetSetParam_lValue(p_Tree))
#define M_xValueInterpret(p_Tree)				(M_GetSetParam_xValue(p_Tree))
#define M_lPersoIdInterpret(p_Tree)				(M_GetSetParam_lPersoId(p_Tree))
#define M_lKeyLinkInterpret(p_Tree)				(M_GetSetParam_lValue(p_Tree))
#define M_p_stPersoRefInterpret(p_Tree)			(M_GetSetParam_p_stEngineObjValue(p_Tree))
#define M_lZdxIdInterpret(p_Tree)				(M_GetSetParam_lZdxId(p_Tree))
#define M_p_stVectorInterpret(p_Tree)			(M_GetSetParam_p_stVectorValue(p_Tree))
#define M_lWayPointInterpret(p_Tree)			(M_GetSetParam_WayPointValue(p_Tree))
#define M_lModuleInterpret(p_Tree)				(M_GetSetParam_lModuleValue(p_Tree))
#define M_lDsgVarIdInterpret(p_Tree)			(M_GetSetParam_lDsgVarIdValue(p_Tree))
#define M_ActionInterpret(p_Tree)				(M_GetSetParam_ActionValue(p_Tree))
#define M_xMaskInterpret(p_Tree)				(M_GetSetParam_xMaskValue(p_Tree))
#define M_hLipSynchroHandleIdInterpret(p_Tree)	(M_GetSetParam_hLipsSynchro(p_Tree))
#define M_hFamilyHandleIdInterpret(p_Tree)		(M_GetSetParam_hFamily(p_Tree))
#define M_SuperObjectInterpret(p_Tree)			(M_GetSetParam_SuperObjectValue(p_Tree))
#define M_lChannelInterpret(p_Tree)				(M_GetSetParam_lChannelValue(p_Tree))
#define M_SoundEventInterpret(p_Tree)			(M_GetSetParam_SoundEvent(p_Tree))
#define M_ComportInterpret(p_Tree)				(M_GetSetParam_pComport(p_Tree))
#define M_TextInterpret(p_Tree)         (M_GetSetParam_hText(p_Tree))
#define M_ParticleGeneratorInterpret(p_Tree)	(M_GetSetParam_hParticleGenerator(p_Tree))
#define M_GameMaterialInterpret(p_Tree)			(M_GetSetParam_hGameMaterial(p_Tree))
#define M_ObjectTableInterpret(p_Tree)			(M_GetSetParam_hObjectTable(p_Tree))
#define M_ColorValueInterpret(p_Tree)			(M_GetSetParam_ColorValue(p_Tree))
#define M_p_stModelInterpret(p_Tree)			(M_GetSetParam_p_stModel(p_Tree))

#define M_IsTheEndOfTree(p_Tree)           (M_GetTypeInterpret(p_Tree) == E_ti_EndTree)
#define M_p_stLightInterpret(p_Tree)				(M_GetSetParam_LightValue(p_Tree))
#define M_ulCapsInterpret(p_Tree)				(M_GetSetParam_CapsValue(p_Tree))
#define M_p_stGraphInterpret(p_Tree)			(M_GetSetParam_GraphValue(p_Tree))
#define M_p_stMacroInterpret(p_Tree)			(M_GetSetParam_p_stMacroValue(p_Tree))

/* 0x00481060 */
void __cdecl fn_vReinitComport(AI_tdstIntelligence *p_stIntelligence);

/* 0x00480FE0 */
void __cdecl fn_vErrorOnAIAlloc(void);

/* 0x00481010 */
void __cdecl fn_vErrorOnAIFree(void);

#endif
