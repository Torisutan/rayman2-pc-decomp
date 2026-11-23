#ifndef _MEC_MECCOL_H_
#define _MEC_MECCOL_H_

#include "ACP/ACP_types.h"
#include "DNM/DNM_types.h"
#include "MTH/MTH3D.h"

#include "HIE/HIE_types.h"
#include "POS/POS_types.h"

ACP_tdxBool __cdecl MEC_fn_bCollision (long *p_lObstacle, DNM_tdstMecObstacle *p_stObstacle, DNM_tdstDynamics *p_stDynamic,
                                       HIE_tdstSuperObject *p_stSupObj, POS_tdstCompletePosition *p_stStartPosition,
                                       POS_tdstCompletePosition *p_stEndPosition, ACP_tdxBool bBackFace); /* 0x0043EEC0 */
ACP_tdxBool __cdecl MEC_fn_vComputeAdjustVector (MTH3D_tdstVector *p_stAdjustVector, DNM_tdstDynamics *p_stDynamic,
                                                 long lObstacle, DNM_tdstMecObstacle *p_stObstacle, long lObstacleMin); /* 0x0043FA40 */
void __cdecl MEC_fn_vReportCollideActor (HIE_tdstSuperObject *hCollideSupObj, DNM_tdstMecObstacle *p_stCollideObstacle); /* 0x0043F470 */
void __cdecl MEC_fn_vReportCollision (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj,
                                      long lNbObstacle, DNM_tdstMecObstacle *a_stObstacle, long lObstacle); /* 0x0043F510 */
void __cdecl MEC_fn_vDeleteGiBackFace (long lObstacle, DNM_tdstMecObstacle *p_stObstacle,
                                       DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stVector); /* 0x004372F0 */
void __cdecl MEC_fn_vEdgeAnalysis (DNM_tdstDynamics *p_stDynamic, long lObstacle,
                                   DNM_tdstMecObstacle *p_stObstacle, DNM_tdstMecObstacle *p_stGround); /* 0x0043FF20 */
void __cdecl MEC_fn_vCrashAnalysis (DNM_tdstDynamics *p_stDynamic, long lObstacle, DNM_tdstMecObstacle *p_stObstacle); /* 0x004405D0 */

#endif
