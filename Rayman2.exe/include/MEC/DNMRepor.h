#ifndef MEC_DNMREPOR_H
#define MEC_DNMREPOR_H

#define DNM_C_ReportCollision					0x00000001
#define DNM_C_ReportWall						0x00000002
#define DNM_C_ReportChar						0x00000004

#define DNM_M_bReportIsWall(_p_stReport)					( _p_stReport->m_cBitField & DNM_C_ReportWall ? TRUE : FALSE )
#define DNM_M_bReportSetWallFlagToFalse(_p_stReport)		( _p_stReport->m_cBitField &= ~DNM_C_ReportWall )
#define DNM_M_bReportSetWallFlagToTrue(_p_stReport)			( _p_stReport->m_cBitField |= DNM_C_ReportWall )

#define DNM_M_vReportSetLastMove(__p_stReport, __p_stMove)		MTH_M_MoveSetLinear(&__p_stReport->m_stAbsolutePrevSpeed, __p_stMove)
#define DNM_M_p_stReportGetLastMove(__p_stReport)				(MTH_M_p_stMoveGetLinear(&__p_stReport->m_stAbsolutePrevSpeed))

#define DNM_M_vReportSetLastTgtMove(__p_stReport, __p_stMove)	MTH_M_MoveSetLinear(&__p_stReport->m_stAbsolutePrevPosition, __p_stMove)
#define DNM_M_p_stReportGetLastTgtMove(__p_stReport)			(MTH_M_p_stMoveGetLinear(&__p_stReport->m_stAbsolutePrevPosition))

#define DNM_M_bReportCollision(_p_stReport)					( _p_stReport->m_cBitField & DNM_C_ReportCollision ? TRUE : FALSE )
#define DNM_M_bReportSetCollisionFlagToFalse(_p_stReport)	( _p_stReport->m_cBitField &= ~DNM_C_ReportCollision )
#define DNM_M_bReportSetCollisionFlagToTrue(_p_stReport)	( _p_stReport->m_cBitField |= DNM_C_ReportCollision )

#define DNM_M_ReportStateTranslate(_p_stReport)		(DNM_M_ulReportSetPrevSurfaceState(_p_stReport,DNM_M_ulReportGetSurfaceState(_p_stReport)))

#endif
