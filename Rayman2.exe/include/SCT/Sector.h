#ifndef RAYMAN2_SCT_SECTOR_H
#define RAYMAN2_SCT_SECTOR_H

#include "LST/LstDef2.h"
#include "HIE/HIE_types.h"

typedef struct SECT_tdstListOfSOCharacters_ *SECT_tdxHandleOfElementLstCharacter;
LST2_M_DynamicUseListOf(SECT_tdxHandleOfElementLstCharacter);

typedef struct SECT_tdstListOfStaticLights_ *SECT_tdxHandleOfElementLstStaticLights;
LST2_M_StaticUseListOf(SECT_tdxHandleOfElementLstStaticLights);
typedef struct SECT_tdstListOfDNMLights_ *SECT_tdxHandleOfElementLstDNMLights;
LST2_M_DynamicUseListOf(SECT_tdxHandleOfElementLstDNMLights);

struct SECT_tdstListOfSOCharacters_
{
    HIE_tdstSuperObject *hPointerOfCharacter;
    LST2_M_DynamicElementDeclaration(SECT_tdxHandleOfElementLstCharacter)
};

struct SECT_tdstListOfStaticLights_
{
    void *hStaticLights;
    LST2_M_StaticElementDeclaration(SECT_tdxHandleOfElementLstStaticLights)
};

struct SECT_tdstListOfDNMLights_
{
    void *hDNMLights;
    LST2_M_DynamicElementDeclaration(SECT_tdxHandleOfElementLstDNMLights)
};

typedef struct SECT_tdstSector_* SECT_tdxHandleOfSectorObject;
typedef struct SECT_tdstListOfSOSectorsInGraphicInteraction_* SECT_tdxHandleOfElementLstGraphicInteraction;
typedef struct SECT_tdstListOfSOSectorsInCollisionInteraction_* SECT_tdxHandleOfElementLstCollisionInteraction;
typedef struct SECT_tdstListOfSOSectorsInActivityInteraction_* SECT_tdxHandleOfElementLstActivityInteraction;
typedef struct SECT_tdstListOfSOSectorsInSoundInteraction_ * SECT_tdxHandleOfElementLstSoundInteraction;
typedef struct SCT_tdstListOfSoundEvent_* SCT_tdxHandleOfLstSoundEvent;

LST2_M_StaticUseListOf(SECT_tdxHandleOfElementLstSoundInteraction);
LST2_M_StaticUseListOf(SECT_tdxHandleOfElementLstActivityInteraction);
LST2_M_StaticUseListOf(SECT_tdxHandleOfElementLstCollisionInteraction);
LST2_M_StaticUseListOf(SECT_tdxHandleOfElementLstGraphicInteraction);
LST2_M_StaticUseListOf(SCT_tdxHandleOfLstSoundEvent);

struct SCT_tdstListOfSoundEvent_
{
    HIE_tdstSuperObject *hPointerOfSectorSO;
    void *uSoundEvent;
    LST2_M_StaticElementDeclaration(SCT_tdxHandleOfLstSoundEvent)
};

#define C_SECT_ModeLookOnly	2
#define C_SECT_ModeNormal	0

typedef struct SECT_tdstListOfSOSectorsInGraphicInteraction_
{
	short	wLevelOfDetail;

	char	cDisplayMode;

	HIE_tdstSuperObject *hPointerOfSectorSO;
	LST2_M_StaticElementDeclaration(SECT_tdxHandleOfElementLstGraphicInteraction)
} SECT_tdstListOfSOSectorsInGraphicInteraction;

typedef struct SECT_tdstListOfSOSectorsInCollisionInteraction_
{
	HIE_tdstSuperObject *hPointerOfSectorSO;
	LST2_M_StaticElementDeclaration(SECT_tdxHandleOfElementLstCollisionInteraction)
} SECT_tdstListOfSOSectorsInCollisionInteraction;

typedef struct SECT_tdstSector_
{
    LST2_M_DynamicAnchorDeclaration(SECT_tdxHandleOfElementLstCharacter)   stListOfCharacters;
    LST2_M_StaticAnchorDeclaration(SECT_tdxHandleOfElementLstStaticLights) stListOfStaticLights;
    LST2_M_DynamicAnchorDeclaration(SECT_tdxHandleOfElementLstDNMLights)   stListOfDNMLights;

	LST2_M_StaticAnchorDeclaration(SECT_tdxHandleOfElementLstGraphicInteraction) stListOfSectorsInGraphicInteraction;
	LST2_M_StaticAnchorDeclaration(SECT_tdxHandleOfElementLstCollisionInteraction) stListOfSectorsInCollisionInteraction;
	LST2_M_StaticAnchorDeclaration(SECT_tdxHandleOfElementLstActivityInteraction) stListOfSectorsInActivityInteraction;
	LST2_M_StaticAnchorDeclaration(SECT_tdxHandleOfElementLstSoundInteraction) stListOfSectorsInSoundInteraction;
	LST2_M_StaticAnchorDeclaration(SCT_tdxHandleOfLstSoundEvent) stListOfSoundEvent;

	MTH3D_tdstVector stMinMaxPoints [2];
	MTH_tdxReal		xZFar;

	ACP_tdxBool		xVirtual;
	char			cCameraType;
	char			cCounter;
	char			cPriority;

	void *pSkyVisualMaterial;
	unsigned char FogIntensity;
} SECT_tdstSector;

#define SECT_GetSectorInCollisionList(hCollisionList) ((hCollisionList)->hPointerOfSectorSO)

#define SECT_fn_hGetFirstCollisionNodeInCollisionList(_hSector) \
    (LST2_M_StaticGetFirstElement( &((SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSector))->stListOfSectorsInCollisionInteraction))
#define SECT_fn_hGetNextCollisionNodeInCollisionList(_hCollNode) (LST2_M_StaticGetNextElement( _hCollNode))

#define SECT_fn_iGetNumberOfNodesInCollisionList(hSector) \
    (LST2_M_StaticGetNumberOfElements(&((SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(hSector))->stListOfSectorsInCollisionInteraction))

#define SECT_M_ForEachCollisionNodeInCollisionInteractionList(_hSector,_hCollList,_i) \
for														\
(														\
	_i=SECT_fn_iGetNumberOfNodesInCollisionList(_hSector), \
	(_hCollList)=SECT_fn_hGetFirstCollisionNodeInCollisionList(_hSector);		\
	_i>0; 									\
	_i--,(_hCollList)=SECT_fn_hGetNextCollisionNodeInCollisionList(_hCollList)			\
)

void __cdecl SECT_fn_vAddHeadCharListNode(HIE_tdstSuperObject *, SECT_tdxHandleOfElementLstCharacter);        /* 0x44c170 */
void __cdecl SECT_fn_vAddTailCharListNode(HIE_tdstSuperObject *, SECT_tdxHandleOfElementLstCharacter);        /* 0x44c0d0 */
void __cdecl SECT_fn_vIsolateCharListNode(void *_hNode);                                                     /* 0x44c070 */
void __cdecl SECT_fn_vAddTailDNMLightsListNode(HIE_tdstSuperObject *, SECT_tdxHandleOfElementLstDNMLights);   /* 0x44c210 */

char __cdecl SECT_fn_bIsThisSectorVirtual(void *_hSprObjSector);   /* 0x0044C2C0 */
char __cdecl fn_cGetSectorCameraType(void *_hSprObjSector);        /* 0x0044C2D0 */
float __cdecl fn_xGetSectorZFar(void *_hSprObjSector);             /* 0x0044C2E0 */

/* 0x0044B410 */
struct POS_tdstCompletePosition_;
struct MTH3D_tdstVector_;
void __cdecl SCT_pc_fn_vComputeMirrorMatrix(struct POS_tdstCompletePosition_ *_p_stSourceMatrix,
                                            struct POS_tdstCompletePosition_ *_p_stMirrorMatrix,
                                            struct MTH3D_tdstVector_         *_p_stReflectedPoint,
                                            struct MTH3D_tdstVector_         *_p_stPlaneNormal,
                                            struct MTH3D_tdstVector_         *_p_stPlanePoint);

#endif
