#ifndef __MACDPID_H__
#define __MACDPID_H__

#include "ACP/ACP_types.h"
#include "MTH/MTH3D.h"

typedef struct stMACDPID
{
	MTH_tdxReal			m_xData0;
	MTH3D_tdstVector	m_stData1;
	MTH3D_tdstVector	m_stData2;
	MTH3D_tdstVector	m_stData3;
	MTH_tdxReal			m_xData3;
	MTH_tdxReal			m_xData4;
	MTH_tdxReal			m_xData5;
	struct
	{
		MTH_tdxReal			m_xAngle;
		MTH3D_tdstVector	m_stAxis;
	} m_stData6;
	struct
	{
		MTH_tdxReal			m_xAngle;
		MTH3D_tdstVector	m_stAxis;
	} m_stData7;
	char				m_cData8;
	unsigned short		m_uwData9;
	MTH3D_tdstVector	m_stData10;
	MTH_tdxReal			m_xData11;
	MTH3D_tdstVector	m_stData12;
	MTH_tdxReal			m_xData13;
	ACP_tdxBool			m_bData14;
} tdstMACDPID;

#define M_xMACDPIDGetTheta(_p_stMACDPID)								((_p_stMACDPID)->m_xData0)
#define M_xMACDPIDSetTheta(_p_stMACDPID,_xValue)						(M_xMACDPIDGetImpetus(_p_stMACDPID) = (_xValue))
#define M_p_stMACDPIDGetTarget(_p_stMACDPID)							(&(_p_stMACDPID)->m_stData1)
#define M_vMACDPIDSetTarget(_p_stMACDPID,_p_stVector)					{MTH3D_M_vCopyVector(M_p_stMACDPIDGetTarget(_p_stMACDPID),_p_stVector)}
#define M_xMACDPIDGetTargetSpeed(_p_stMACDPID)							((_p_stMACDPID)->m_stData3.xX)
#define M_xMACDPIDGetTargetIncreaseSpeed(_p_stMACDPID)					((_p_stMACDPID)->m_stData3.xY)
#define M_xMACDPIDGetTargetDecreaseSpeed(_p_stMACDPID)					((_p_stMACDPID)->m_stData3.xZ)
#define M_p_stMACDPIDGetMovePos(_p_stMACDPID)							(&(_p_stMACDPID)->m_stData2)
#define M_xMACDPIDGetLinearSpeed(_p_stMACDPID)							((_p_stMACDPID)->m_stData6.m_stAxis.xX)
#define M_xMACDPIDGetLinearIncreaseSpeed(_p_stMACDPID)					((_p_stMACDPID)->m_stData6.m_stAxis.xY)
#define M_xMACDPIDGetLinearDecreaseSpeed(_p_stMACDPID)					((_p_stMACDPID)->m_stData6.m_stAxis.xZ)
#define M_xMACDPIDGetAngularSpeed(_p_stMACDPID)							((_p_stMACDPID)->m_stData7.m_stAxis.xX)
#define M_xMACDPIDGetAngularIncreaseSpeed(_p_stMACDPID)					((_p_stMACDPID)->m_stData7.m_stAxis.xY)
#define M_xMACDPIDGetAngularDecreaseSpeed(_p_stMACDPID)					((_p_stMACDPID)->m_stData7.m_stAxis.xZ)
#define M_uwMACDPIDGetFlags(_p_stMACDPID)								((_p_stMACDPID)->m_uwData9)
#define M_p_stMACDPIDGetPosReferencePoint(_p_stMACDPID)					(&(_p_stMACDPID)->m_stData10)
#define M_xMACDPIDGetCutAngleFactorPos(_p_stMACDPID)					((_p_stMACDPID)->m_xData11)
#define M_p_stMACDPIDGetRefAxisZ(_p_stMACDPID)							(&(_p_stMACDPID)->m_stData12)
#define M_xMACDPIDGetCutAngleFactorTgt(_p_stMACDPID)					((_p_stMACDPID)->m_xData13)

#define M_xMACDPIDGetImpetus(_p_stMACDPID) ((_p_stMACDPID)->m_xData0)

#endif
