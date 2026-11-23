#ifndef __DNMDYNAM_H__
#define __DNMDYNAM_H__

#include "MTH/MTH3D.h"
#include "POS/POS_types.h"
#include "DNM/DNM_types.h"
#include "MEC/macdpid.h"

typedef struct DNM_stDynamicsBaseBlock
{
	long m_lObjectType;
	void *m_pCurrentIdCard;
	unsigned long	ulFlags;
	unsigned long	ulEndFlags;
	MTH_tdxReal m_xGravity;
	MTH_tdxReal m_xSlopeLimit;
	MTH_tdxReal m_xCosSlope;
	MTH_tdxReal m_xSlide;
	MTH_tdxReal m_xRebound;
	MTH3D_tdstVector m_stImposeSpeed;
	MTH3D_tdstVector m_stProposeSpeed;
	MTH3D_tdstVector m_stPreviousSpeed;
	MTH3D_tdstVector m_stScale;
	MTH3D_tdstVector m_stSpeedAnim;
	MTH3D_tdstVector m_stSafeTranslation;
	MTH3D_tdstVector m_stAddTranslation;
	POS_tdstCompletePosition m_stPreviousMatrix;
	POS_tdstCompletePosition m_stCurrentMatrix;
	MTH3D_tdstMatrix m_stImposeRotationMatrix;
	unsigned char m_ucNbFrame;
	DNM_tdstReport* m_pstReport;
} DNM_tdstDynamicsBaseBlock;

typedef struct DNM_stDynamicsAdvancedBlock
{
	MTH_tdxReal m_xInertiaX;
	MTH_tdxReal m_xInertiaY;
	MTH_tdxReal m_xInertiaZ;
	MTH_tdxReal m_xStreamPrority;
	MTH_tdxReal m_xStreamFactor;
	MTH_tdxReal m_xSlideFactorX;
	MTH_tdxReal m_xSlideFactorY;
	MTH_tdxReal m_xSlideFactorZ;
	MTH_tdxReal m_xPreviousSlide;
	MTH3D_tdstVector m_stMaxSpeed;
	MTH3D_tdstVector m_stStreamSpeed;
	MTH3D_tdstVector m_stAddSpeed;
	MTH3D_tdstVector m_stLimit;
	MTH3D_tdstVector m_stCollisionTranslation;
	MTH3D_tdstVector m_stInertiaTranslation;
	MTH3D_tdstVector m_stGroundNormal;
	MTH3D_tdstVector m_stWallNormal;
	char m_cCollideCounter;
} DNM_tdstDynamicsAdvancedBlock;

typedef struct DNM_stDynamicsComplexBlock
{
	MTH_tdxReal	m_xTiltIntensity;
	MTH_tdxReal m_xTiltInertia;
	MTH_tdxReal m_xTiltOrigin;
	MTH_tdxReal m_xTiltAngle;
	MTH_tdxReal m_xHangingLimit;
	MTH3D_tdstVector m_stContact;
	MTH3D_tdstVector m_stFallTranslation;
	tdstMACDPID m_stExternalDatas;
	struct HIE_tdstSuperObject *m_hPlatform;
	POS_tdstCompletePosition m_stAbsolutePreviousMatrix;
	POS_tdstCompletePosition m_stPrevPreviousMatrix;
} DNM_tdstDynamicsComplexBlock;

typedef struct DNM_stBaseDynamics
{
	DNM_tdstDynamicsBaseBlock m_tdstDynamicsBaseBlock;
} DNM_tdstBaseDynamics;

typedef struct DNM_stAdvancedDynamics
{
	DNM_tdstDynamicsBaseBlock m_tdstDynamicsBaseBlock;
	DNM_tdstDynamicsAdvancedBlock m_tdstDynamicsAdvancedBlock;
} DNM_tdstAdvancedDynamics;

typedef struct DNM_stComplexDynamics
{
	DNM_tdstDynamicsBaseBlock m_tdstDynamicsBaseBlock;
	DNM_tdstDynamicsAdvancedBlock m_tdstDynamicsAdvancedBlock;
	DNM_tdstDynamicsComplexBlock m_tdstDynamicsComplexBlock;
} DNM_tdstComplexDynamics;

struct DNM_tdstDynamics_
{
	DNM_tdstDynamicsBaseBlock m_tdstDynamicsBaseBlock;
	DNM_tdstDynamicsAdvancedBlock m_tdstDynamicsAdvancedBlock;
	DNM_tdstDynamicsComplexBlock m_tdstDynamicsComplexBlock;
};

#define DNM_M_pstGetBaseBlock(_p_stDynamics) (&((_p_stDynamics)->m_tdstDynamicsBaseBlock))

#define DNM_M_pstGetBaseBlockForAdvancedAccess(_p_stDynamics) DNM_M_pstGetBaseBlock(_p_stDynamics)
#define DNM_M_pstGetBaseBlockForComplexAccess(_p_stDynamics) DNM_M_pstGetBaseBlock(_p_stDynamics)
#define DNM_M_pstGetAdvancedBlock(_p_stDynamics) (&((_p_stDynamics)->m_tdstDynamicsAdvancedBlock))
#define DNM_M_pstGetComplexBlock(_p_stDynamics) (&((_p_stDynamics)->m_tdstDynamicsComplexBlock))

#define DNM_M_p_stDynamicsGetExternalDatas(_p_stDynamics) (&DNM_M_pstGetComplexBlock(_p_stDynamics)->m_stExternalDatas)

#endif
