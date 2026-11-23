#ifndef _MEC_MECTOOLS_H_
#define _MEC_MECTOOLS_H_

#include "ACP/ACP_types.h"
#include "DNM/DNM_types.h"
#include "POS/POS_types.h"
#include "MTH/MTH_flt.h"
#include "MTH/MTH_xNeg.h"
#include "MTH/MTH3D.h"
#include "GMT/GMT_types.h"
#include "HIE/HIE_types.h"

void __cdecl MEC_fn_vComputeSpeed (DNM_tdstDynamics *p_stDynamic, MTH_tdxReal xDT);                  /* 0x00436A30 */

void __cdecl MEC_fn_vInitMatrix (DNM_tdstDynamics *p_stDynamic);                                     /* 0x00436AB0 */
void __cdecl MEC_fn_vCorrectMatrix (DNM_tdstDynamics *p_stDynamic, POS_tdxHandleToPosition hMatrix); /* 0x00436B00 */
void __cdecl MEC_fn_vTranslateMatrixOn (DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stMatrixTranslation); /* 0x00436DA0 */
ACP_tdxBool __cdecl MEC_fn_bIsEqualMatrix (POS_tdxHandleToPosition hMatrix1, POS_tdxHandleToPosition hMatrix2);          /* 0x00436B80 */
ACP_tdxBool __cdecl MEC_fn_bIsEqualTransformMatrix (POS_tdxHandleToPosition hMatrix1, POS_tdxHandleToPosition hMatrix2); /* 0x00436CC0 */

void __cdecl MEC_fn_vComputeStream (MTH3D_tdstVector *p_stStream, DNM_tdstDynamics *p_stDynamic, MTH_tdxReal xDT, ACP_tdxBool bSlide); /* 0x00437A80 */
void __cdecl MEC_fn_vComputeInertiaTranslation (DNM_tdstDynamics *p_stDynamic, MTH_tdxReal xDT);     /* 0x00437AF0 */

void __cdecl MEC_fn_vAdjustScaleVector (DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stVector);/* 0x00436EB0 */

MTH_tdxReal __cdecl MEC_fn_vRoundReal (MTH_tdxReal xReal, MTH_tdxReal xEpsilon);                     /* 0x00437040 */
void        __cdecl MEC_fn_vRoundVector (MTH3D_tdstVector *p_stVector, MTH_tdxReal xEpsilon);        /* 0x00437060 */

static __inline ACP_tdxBool MEC_fn_bTypeOfGameMaterial(GMT_tdxHandleToGameMaterial hGameMat, GMT_tdxMask xTestMask)
{
    GMT_tdxHandleToCollideMaterial hCollMat;
    hCollMat = hGameMat->hCollideMaterial;
    return (ACP_tdxBool)( (hCollMat != GMT_C_InvalidCollideMaterial)
                          && ((hCollMat->xIdentifier & xTestMask) == xTestMask) );
}

static __inline ACP_tdxBool MEC_fn_bIsNullVector (MTH3D_tdstVector *p_stVector)
{
    return (ACP_tdxBool)(
           MTH_M_bEqualWithEpsilon(MTH3D_M_xGetXofVector(p_stVector), MTH_C_ZERO, (MTH_tdxReal)1.0e-3)
        && MTH_M_bEqualWithEpsilon(MTH3D_M_xGetYofVector(p_stVector), MTH_C_ZERO, (MTH_tdxReal)1.0e-3)
        && MTH_M_bEqualWithEpsilon(MTH3D_M_xGetZofVector(p_stVector), MTH_C_ZERO, (MTH_tdxReal)1.0e-3));
}

void __cdecl MEC_fn_vTranslateMatrixOff (DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stMatrixTranslation); /* 0x00437A40 */
void __cdecl MEC_fn_vAdjustSpeed (DNM_tdstDynamics *p_stDynamic, MTH_tdxReal xDT);                   /* 0x00436EE0 */

#define C_xDNM_WATER_TYPE_GAME_MATERIAL         (1 << 14)
#define C_xDNM_NO_COLLISION_TYPE_GAME_MATERIAL  (1 << 15)
#define C_xDNM_COLLISION_REPORT_MASK            8072

static __inline ACP_tdxBool MEC_fn_bTestMaskGameMaterial(GMT_tdxHandleToGameMaterial hGameMat, GMT_tdxMask xTestMask)
{
    GMT_tdxHandleToCollideMaterial hCollMat;
    return (ACP_tdxBool)( ((hCollMat=hGameMat->hCollideMaterial)!=(GMT_tdxHandleToCollideMaterial)GMT_C_InvalidCollideMaterial) && (hCollMat->xIdentifier&xTestMask)!=MTH_C_ZERO );
}

static __inline ACP_tdxBool MEC_fn_bIsWater (DNM_tdstMecObstacle *o)
{
    return (ACP_tdxBool)(
           MEC_fn_bTypeOfGameMaterial((GMT_tdxHandleToGameMaterial)DNM_M_hObstacleGetCollidedMaterial(o), C_xDNM_WATER_TYPE_GAME_MATERIAL)
        && MEC_fn_bTypeOfGameMaterial((GMT_tdxHandleToGameMaterial)DNM_M_hObstacleGetMyMaterial(o),       C_xDNM_WATER_TYPE_GAME_MATERIAL));
}

#define COL_C_xHighEdgeEntity   7
#define COL_C_xLowEdgeEntity    8
#define COL_C_xNoEntity         99

/* 0x435EA0 */
static __inline MTH_tdxReal MEC_fn_xGroundLimit (DNM_tdstDynamics *p_stDynamic)
{ return DNM_M_xDynamicsGetCosSlope(p_stDynamic); }
static __inline MTH_tdxReal MEC_fn_xWallLimit (DNM_tdstDynamics *p_stDynamic)
{ return MTH_M_xNeg(DNM_M_xDynamicsGetCosSlope(p_stDynamic)); }

static __inline MTH_tdxReal MEC_fn_xMaxSlope (DNM_tdstDynamics *p_stDynamic)
{ return DNM_M_xDynamicsGetSlopeLimit(p_stDynamic); }

static __inline MTH_tdxReal MEC_fn_xMinSlope (DNM_tdstDynamics *p_stDynamic)
{ return MTH_M_xNeg(DNM_M_xDynamicsGetSlopeLimit(p_stDynamic)); }

static __inline ACP_tdxBool MEC_fn_bIsBaseMechanic (DNM_tdstDynamics *p_stDynamic)
{
	void *hIdCard = DNM_M_pDynamicsGetCurrentIdCard (p_stDynamic);
	return (ACP_tdxBool)((hIdCard != 0) && (DNM_fn_eIdentityCardGetType(hIdCard) == DNM_eBase));
}

ACP_tdxBool __cdecl MEC_fn_bWallNormal (DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stNormal);   /* 0x00435EA0 */
ACP_tdxBool __cdecl MEC_fn_bGroundNormal (DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stNormal); /* 0x00435EF0 */
ACP_tdxBool __cdecl MEC_fn_bCeilObstacle (DNM_tdstDynamics *p_stDynamic, DNM_tdstMecObstacle *p_stObstacle); /* 0x00435F10 */
ACP_tdxBool __cdecl DNM_fn_bIsMatCharacteristicsValid (DNM_tdxHandleToMecMatCharacteristics _hMatCharacteristics); /* 0x00435E90 */
DNM_tdstMecMatCharacteristics * __cdecl DNM_fn_p_stMecMatCharacteristicsGiveBackSemantic (DNM_tdxHandleToMecMatCharacteristics _hMatCharacteristics); /* 0x00497150 */
void __cdecl MEC_fn_vDeleteNoCollidedGroundFace (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic); /* 0x00437780 */
void __cdecl MEC_fn_vComputeCollisionTranslation (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, MTH3D_tdstVector *p_stMove); /* 0x004361B0 */
void __cdecl MEC_fn_vDeleteHangingObstacle (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic); /* 0x004377F0 */
void __cdecl MEC_fn_vDeleteClimbBackFace (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stVector); /* 0x004373F0 */
void __cdecl MEC_fn_vDeleteNullTranslationObstacle (long lObstacle, DNM_tdstMecObstacle *a_stObstacle); /* 0x00437970 */
void __cdecl MEC_fn_vDeleteUnderGroundWall (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic, DNM_tdstMecObstacle *p_stGroundObstacle); /* 0x004364A0 */
void __cdecl MEC_fn_vDeleteOnGroundBackFace (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stVector, DNM_tdstMecObstacle *p_stGroundObstacle); /* 0x00437140 */
void __cdecl MEC_fn_vDeleteWallEdge (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic); /* 0x004362E0 */
ACP_tdxBool __cdecl MEC_fn_bDetectStep (DNM_tdstDynamics *p_stDynamic, long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstMecObstacle *p_stGroundObstacle, MTH3D_tdstVector *p_stMoveDirection); /* 0x00436820 */

struct DNM_stMecBaseIdCard;
void __cdecl DNM_fn_vChangeIdCard (DNM_tdstDynamics *p_stDynamics, struct DNM_stMecBaseIdCard *hNewIdCard); /* 0x00435DF0 */

DNM_tdstMecObstacle * __cdecl MEC_fn_pSelectGround (DNM_tdstDynamics *p_stDynamic, long lObstacle, DNM_tdstMecObstacle *p_stObstacle, MTH3D_tdstVector *p_stMove, ACP_tdxBool *bFirstGround); /* 0x00436610 */
ACP_tdxBool __cdecl MEC_fn_bIsEqualRotationMatrix (POS_tdxHandleToPosition hMatrix1, POS_tdxHandleToPosition hMatrix2); /* 0x00436BD0 */

static __inline ACP_tdxBool MEC_fn_bIsEdge (DNM_tdstMecObstacle *o)
{ return (ACP_tdxBool)((DNM_M_xObstacleGetCollidedEntity(o)==COL_C_xHighEdgeEntity) || (DNM_M_xObstacleGetCollidedEntity(o)==COL_C_xLowEdgeEntity)); }
static __inline ACP_tdxBool MEC_fn_bIsHighEdge (DNM_tdstMecObstacle *o)
{ return (ACP_tdxBool)(DNM_M_xObstacleGetCollidedEntity(o)==COL_C_xHighEdgeEntity); }
static __inline ACP_tdxBool MEC_fn_bIsLowEdge (DNM_tdstMecObstacle *o)
{ return (ACP_tdxBool)(DNM_M_xObstacleGetCollidedEntity(o)==COL_C_xLowEdgeEntity); }
static __inline ACP_tdxBool MEC_fn_bIsCollide (DNM_tdstMecObstacle *o)
{ return (ACP_tdxBool)MTH_M_bLess(DNM_M_xObstacleGetRate(o), MTH_C_ZERO); }
static __inline ACP_tdxBool MEC_fn_bIsDoubleEdge (DNM_tdstMecObstacle *o)
{ return (ACP_tdxBool)((DNM_M_eObstacleGetType(o) & DNM_ObsType_DoubleEdge) == DNM_ObsType_DoubleEdge); }
static __inline void MEC_fn_vInvalidateObstacle (DNM_tdstMecObstacle *o)
{ DNM_M_xObstacleSetCollidedEntity(o, COL_C_xNoEntity); }
static __inline ACP_tdxBool MEC_fn_bIsObstacleValid (DNM_tdstMecObstacle *o)
{ return (ACP_tdxBool)(DNM_M_xObstacleGetCollidedEntity(o) != COL_C_xNoEntity); }
static __inline ACP_tdxBool MEC_fn_bWallObstacle (DNM_tdstDynamics *p_stDynamic, DNM_tdstMecObstacle *o)
{ return MEC_fn_bWallNormal(p_stDynamic, DNM_M_p_stObstacleGetNorm(o)); }
static __inline ACP_tdxBool MEC_fn_bGroundObstacle (DNM_tdstDynamics *p_stDynamic, DNM_tdstMecObstacle *o)
{ return MEC_fn_bGroundNormal(p_stDynamic, DNM_M_p_stObstacleGetNorm(o)); }

static __inline void MEC_fn_vGetCollisionTranslation (DNM_tdstDynamics *p_stDynamic, POS_tdxHandleToPosition hMatrix)
{ POS_fn_vSetTranslationVector (hMatrix, DNM_M_pDynamicsGetCollisionTranslation(p_stDynamic)); }

HIE_tdstSuperObject *__cdecl MEC_fn_hGetFatherActor (HIE_tdstSuperObject *hSupObj);                  /* 0x00437A20 */
ACP_tdxBool __cdecl MEC_fn_bMainActor (HIE_tdstSuperObject *hSupObj);                                /* 0x00437B90 */
ACP_tdxBool __cdecl MEC_fn_bCanCrashActor (DNM_tdstMecObstacle *p_stCollideObstacle);                /* 0x00435F50 */

void __cdecl MEC_fn_vDeleteBaseBackFace (long lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic); /* 0x00437520 */

ACP_tdxBool __cdecl MEC_fn_bDynamicsNeedCollide (DNM_tdstDynamics *p_stDynamic);                     /* 0x00435F80 */
MTH_tdxReal __cdecl MEC_fn_xGetSlide (DNM_tdstDynamics *p_stDynamic, DNM_tdstMecObstacle *p_stObstacle); /* 0x004360B0 */
MTH_tdxReal __cdecl MEC_fn_xGetRebound (DNM_tdstDynamics *p_stDynamic, DNM_tdstMecObstacle *p_stObstacle); /* 0x00436130 */

ACP_tdxBool __cdecl MEC_fn_bNoMove (DNM_tdstDynamics *p_stDynamic);                                  /* 0x00437BB0 */

void __cdecl MEC_fn_vRepeatMove (DNM_tdstDynamics *p_stDynamic);                                     /* 0x00437DD0 */

void __cdecl MEC_fn_vSetInitialFrameTranslation (DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stVector); /* 0x00437A40 */

void __cdecl MEC_fn_vSlowMode (DNM_tdstDynamics *p_stDynamic, long lMode);                           /* 0x00437C60 */
void __cdecl MEC_fn_vNormalMode (DNM_tdstDynamics *p_stDynamic, long lMode);                         /* 0x00437D20 */

static __inline void MEC_fn_vInvertMatrix (DNM_tdstDynamics *p_stDynamic,
                                           POS_tdxHandleToPosition hInvMatrix,
                                           POS_tdxHandleToPosition hMatrix)
{
    if (DNM_M_bDynamicsIsComputeInvertMatrix(p_stDynamic))
    {
        POS_fn_vInvertMatrix ( hInvMatrix, hMatrix );
        DNM_M_vDynamicsSetComputeInvertMatrix ( p_stDynamic, FALSE );
    }
}

#endif
