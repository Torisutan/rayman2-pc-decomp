#ifndef __DNMREPOR_H__
#define __DNMREPOR_H__

#define DNM_M_ReportSetObstacle(_p_stReport,_p_stObstacle) DNM_M_ObstacleCopyClone(&(_p_stReport)->m_stObstacle,_p_stObstacle)

#define DNM_M_ReportSetGround(_p_stReport,_p_stObstacle) DNM_M_ObstacleCopyClone(&(_p_stReport)->m_stGround,_p_stObstacle)

#define DNM_M_ReportSetWall(_p_stReport,_p_stObstacle) DNM_M_ObstacleCopyClone(DNM_M_p_stReportGetWall(_p_stReport),_p_stObstacle)

#define DNM_M_ReportSetCharacter(_p_stReport,_p_stObstacle) DNM_M_ObstacleCopyClone(DNM_M_p_stReportGetCharacter(_p_stReport),_p_stObstacle)

#define DNM_M_ReportSetWater(_p_stReport,_p_stObstacle) DNM_M_ObstacleCopyClone(DNM_M_p_stReportGetWater(_p_stReport),_p_stObstacle)

#define DNM_M_ReportSetCeil(_p_stReport,_p_stObstacle) DNM_M_ObstacleCopyClone(DNM_M_p_stReportGetCeil(_p_stReport),_p_stObstacle)

#endif
