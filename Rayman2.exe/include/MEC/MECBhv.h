#ifndef _MEC_MECBHV_H_
#define _MEC_MECBHV_H_

#include "ACP/ACP_types.h"
#include "DNM/DNM_types.h"
#include "MTH/MTH3D.h"
#include "HIE/HIE_types.h"

void __cdecl MEC_fn_vBaseObstacleManagement (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, MTH_tdxReal xDT); /* 0x00439660 */
void __cdecl MEC_fn_vGiObstacleManagement (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, MTH_tdxReal xDT);   /* 0x00439730 */
void __cdecl MEC_fn_vGroundObstacleManagement (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, MTH_tdxReal xDT); /* 0x0043B360 */
void __cdecl MEC_fn_vSpiderObstacleManagement (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, MTH_tdxReal xDT); /* 0x0043D440 */
void __cdecl MEC_fn_vOrient (DNM_tdstDynamics *p_stDynamic, MTH3D_tdstVector *p_stNormal); /* 0x004394A0 */
void __cdecl MEC_fn_vClimbObstacleManagement (DNM_tdstDynamics *p_stDynamic, HIE_tdstSuperObject *hSupObj, MTH_tdxReal xDT); /* 0x0043A260 */
void __cdecl MEC_fn_vGroundGuess (DNM_tdstDynamics *p_stDynamic, MTH_tdxReal xDT);                   /* 0x0043D2A0 */
void __cdecl MEC_fn_vFillCollisionReport (DNM_tdstDynamics *p_stDynamic);                            /* 0x0043F940 */
void __cdecl MEC_fn_vWallObstacleManagement (MTH3D_tdstVector *pstResultMove, DNM_tdstDynamics *p_stDynamic,
                                             MTH3D_tdstVector *pstMove, MTH3D_tdstVector *pstGroundNormal,
                                             MTH3D_tdstVector *pstWallNormal, MTH_tdxReal xDT, ACP_tdxBool bAngleLimit); /* 0x004390D0 */

#endif
