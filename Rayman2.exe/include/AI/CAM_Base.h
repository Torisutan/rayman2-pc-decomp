#ifndef RAYMAN2_AI_CAM_BASE_H
#define RAYMAN2_AI_CAM_BASE_H

#include "MTH/MTH_types.h"
#include "MTH/MTH3D.h"
#include "HIE/HIE_types.h"
#include "DNM/DNM_types.h"
#include "GAM/cineinfo.h"

typedef struct CAM_tdstComputedPosition_
{
    MTH3D_tdstVector    stTarget;
    MTH3D_tdstVector    stMovePos;
    MTH3D_tdstVector    stRefAxisZ;
    MTH_tdxReal         xLinearSpeed;
    MTH_tdxReal         xAngularSpeed;
    MTH_tdxReal         xTargetSpeed;
} CAM_tdstComputedPosition;

typedef struct CAM_tdstUpdateCamera_
{
    DNM_tdstReport                  *p_stReport;
    DNM_tdstDynamics                *p_stDynamics;

    MS_tdxHandleToCineinfo           hCineinfo;
    MS_tdxHandleToInternalCineinfo   hCineinfoWork;
    MS_tdxHandleToInternalCineinfo   hCineinfoCurrent;
    MS_tdxHandleToInternalCineinfo   hCineinfoInit;
    MS_tdxHandleToInternalCineinfo   hCineinfoVisibility;

    HIE_tdstSuperObject             *hSuperObjCamera;

    MTH3D_tdstVector                 stCurrentCameraPos;
    MTH3D_tdstVector                 stWantedCameraPos;
    MTH3D_tdstVector                 stRealWantedCameraPos;

    MTH3D_tdstVector                 stTargetedPersoRealPos;
    MTH3D_tdstVector                 stTargetedPersoPos;
    MTH3D_tdstVector                 stSecondTargetedPersoRealPos;
    MTH3D_tdstVector                 stSecondTargetedPersoPos;

    char                             cHasCutAlpha;
    MTH_tdxReal                      xAngleAlphaCut;
    MTH_tdxReal                      xAngleDeltaAlphaCut;

    char                             cTgtPersoIsMovingAbsolute;
    MTH3D_tdstVector                 stTgtPersoMoveAbsolute;
    char                             cTgtPersoIsMovingRelative;
    MTH3D_tdstVector                 stTgtPersoMoveRelative;

    CAM_tdstComputedPosition         stCptPos;
} CAM_tdstUpdateCamera;

void CAM_fn_vComputeTarget(CAM_tdstUpdateCamera *_p_stStruct);   /* 0x004840A0 */
void CAM_fn_vComputeReferencePoint(CAM_tdstUpdateCamera *_p_stStruct);   /* 0x00483F90 */

#define	DNM_CAM_C_NoLinearParsing				0x0001
#define DNM_CAM_C_NoLinearInertia				0x0002
#define DNM_CAM_C_NoAngularParsing				0x0004
#define DNM_CAM_C_NoAngularInertia				0x0008
#define DNM_CAM_C_NoTargetParsing				0x0010
#define DNM_CAM_C_NoTargetInertia				0x0020
#define	DNM_CAM_C_NoObstacle					0x0040
#define DNM_CAM_C_FixedOrientation				0x0080
#define DNM_CAM_C_NoCollisionWhenNotMoving		0x0100

#endif
