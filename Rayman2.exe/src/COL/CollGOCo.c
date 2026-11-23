#include <math.h>
#include <string.h>
#include <stddef.h>
#include "COL/CollGOCo.h"
#include "GMT/GMT_types.h"
#include "MTH/MTH3D.h"
#include "MTH/MTH_flt.h"
#include "DNM/DNM_types.h"
#include "GAM/GAM_types.h"
#include "GAM/GAM_globals.h"
#include "MEC/MECTools.h"
#include "GMT/GmtFunct.h"

#define COL_M_hGetMechanicsMaterial(_hGameMat) \
    GMT_fn_hGetMechanicsMaterial((GMT_tdxHandleToGameMaterial)(_hGameMat))

extern ACP_tdxBool __cdecl CAM_fn_bSuperObjectIsACamera(HIE_tdstSuperObject *_h_SprObj);

extern void __cdecl COL_fn_vNewStaticCollisionForCharacter(void *_hCharacter, void *_hSector,
                                                           POS_tdstCompletePosition *_p_stStartMatrix,
                                                           POS_tdstCompletePosition *_p_stEndMatrix);

#define COL_PC_C_ucTypeZdm        1u
#define COL_PC_C_wMobileObject    1

COL_tdstCollisionCase COL_g_stCollisionCase_storage[COL_C_xMaxNumberOfCollisions + 1];
static COL_tdstCollisionCase *COL_g_stCollisionCaseReal_storage = COL_g_stCollisionCase_storage;
static long COL_g_lNbElementsInTable_storage = 75;

long COL_g_lMaxNumberOfCollisions_storage = 75;
#define COL_g_stCollisionCase        (COL_g_stCollisionCase_storage)
#define COL_g_stCollisionCaseReal    (COL_g_stCollisionCaseReal_storage)
#define COL_g_lNbElementsInTable     (COL_g_lNbElementsInTable_storage)
#define COL_g_lMaxNumberOfCollisions (COL_g_lMaxNumberOfCollisions_storage)

#define C_wDoubleEdge 2

#define COL_C_xEdgeTimeEpsilon  0.001   /* 0x49CE00 */
#define COL_C_xEdgePosEpsilon   0.005   /* 0x49CE08 */
#define COL_C_xSortTimeEpsilon  0.0001f

#define M_bEqEps(a, b, eps)  MTH_M_bEqualWithEpsilon((a), (b), (eps))

#define M_bVecEqEps(pV, x, y, z, eps) \
    ( M_bEqEps((pV)->xX, (x), (eps)) && \
      M_bEqEps((pV)->xY, (y), (eps)) && \
      M_bEqEps((pV)->xZ, (z), (eps)) )

/* 0x0048FCA0 */
void __cdecl
COL_fn_vAddInStaticCollisionTable(MTH_tdxReal       _xT,
                                  MTH3D_tdstVector *_p_stTranslation,
                                  MTH3D_tdstVector *_p_stHit,
                                  MTH3D_tdstVector *_p_stNormal,
                                  void             *_hDynMat,
                                  void             *_hStatMat,
                                  ACP_tdxIndex      _xDynamicGeomEntity,
                                  ACP_tdxIndex      _xStaticGeomEntity,
                                  void             *_p_vParameter1,
                                  short             _sParameter2,
                                  MTH3D_tdstVector *_p_stMovement,
                                  MTH_tdxReal       _xSphereRadius,
                                  MTH3D_tdstVector *_p_stEndPosition)
{
    long                   i;
    COL_tdstCollisionCase *p_stCollisionCase;
    GMT_tdxHandleToCollideMaterial hCollideMaterial;

    hCollideMaterial = GMT_fn_hGetCollideMaterial((GMT_tdxHandleToGameMaterial)_hDynMat);
    if ((hCollideMaterial != GMT_C_InvalidCollideMaterial) &&
        (GMT_fn_hGetCollideMaterialIdentifier(hCollideMaterial) & (1 << 3)))
    {
        hCollideMaterial = GMT_fn_hGetCollideMaterial((GMT_tdxHandleToGameMaterial)_hStatMat);
        if ((hCollideMaterial == GMT_C_InvalidCollideMaterial) ||
            ((GMT_fn_hGetCollideMaterialIdentifier(hCollideMaterial) & 4) != 4))
            return;
    }

    if (_xStaticGeomEntity == COL_C_xHighEdgeEntity ||
        _xStaticGeomEntity == COL_C_xLowEdgeEntity)
    {
        p_stCollisionCase = COL_g_stCollisionCaseReal;
        for (i = 0; i < COL_g_lNbElementsInTable; i++)
        {
            if (p_stCollisionCase->xStaticGeomEntity == _xStaticGeomEntity &&
                p_stCollisionCase->p_vParameter1 == _p_vParameter1 &&
                M_bEqEps(p_stCollisionCase->xCollisionTime, _xT, COL_C_xEdgeTimeEpsilon) &&
                M_bVecEqEps(&p_stCollisionCase->stCollisionPoint,
                            _p_stHit->xX, _p_stHit->xY, _p_stHit->xZ, COL_C_xEdgePosEpsilon) &&
                M_bVecEqEps(&p_stCollisionCase->stCollisionNormal,
                            _p_stNormal->xX, _p_stNormal->xY, _p_stNormal->xZ, COL_C_xEdgePosEpsilon))
            {
                p_stCollisionCase->sParameter2 |= C_wDoubleEdge;
                return;
            }
            p_stCollisionCase++;
        }
    }

    p_stCollisionCase = COL_g_stCollisionCaseReal;
    for (i = 0; i < COL_g_lNbElementsInTable; i++)
    {
        if (M_bEqEps(_xT, p_stCollisionCase->xCollisionTime, COL_C_xSortTimeEpsilon))
        {
            if (_p_stNormal->xX < p_stCollisionCase->stCollisionNormal.xX)
            {
                int                    iNumberOfElementToCopy = 0;
                COL_tdstCollisionCase *p   = p_stCollisionCase;
                COL_tdstCollisionCase *end = COL_g_stCollisionCaseReal + COL_g_lNbElementsInTable;

                while (p++ < end) iNumberOfElementToCopy++;
                if (p == (COL_g_stCollisionCase + (COL_C_xMaxNumberOfCollisions + 1)))
                    iNumberOfElementToCopy--;
                if (iNumberOfElementToCopy)
                    memmove(p_stCollisionCase + 1, p_stCollisionCase,
                            iNumberOfElementToCopy * sizeof(COL_g_stCollisionCase[0]));
                break;
            }
        }
        else if (_xT < p_stCollisionCase->xCollisionTime)
        {
            int                    iNumberOfElementToCopy = 0;
            COL_tdstCollisionCase *p   = p_stCollisionCase;
            COL_tdstCollisionCase *end = COL_g_stCollisionCaseReal + COL_g_lNbElementsInTable;

            while (p++ < end) iNumberOfElementToCopy++;
            if (p == (COL_g_stCollisionCase + (COL_C_xMaxNumberOfCollisions + 1)))
                iNumberOfElementToCopy--;
            if (iNumberOfElementToCopy)
                memmove(p_stCollisionCase + 1, p_stCollisionCase,
                        iNumberOfElementToCopy * sizeof(COL_g_stCollisionCase[0]));
            break;
        }
        p_stCollisionCase++;
    }

    if (i == COL_g_lMaxNumberOfCollisions)
        return;

    p_stCollisionCase->xCollisionTime = _xT;
    MTH3D_M_vCopyVector(&p_stCollisionCase->stTranslation,     _p_stTranslation);
    MTH3D_M_vCopyVector(&p_stCollisionCase->stCollisionPoint,  _p_stHit);
    MTH3D_M_vCopyVector(&p_stCollisionCase->stCollisionNormal, _p_stNormal);
    MTH3D_M_vCopyVector(&p_stCollisionCase->stMovement,        _p_stMovement);
    MTH3D_M_vCopyVector(&p_stCollisionCase->stEndPosition,     _p_stEndPosition);
    p_stCollisionCase->hDynamicMaterial   = _hDynMat;
    p_stCollisionCase->hStaticMaterial    = _hStatMat;
    p_stCollisionCase->xDynamicGeomEntity = _xDynamicGeomEntity;
    p_stCollisionCase->xStaticGeomEntity  = _xStaticGeomEntity;
    p_stCollisionCase->xSphereRadius      = _xSphereRadius;
    p_stCollisionCase->p_vParameter1      = _p_vParameter1;
    p_stCollisionCase->sParameter2        = _sParameter2;

    if (COL_g_lNbElementsInTable == COL_g_lMaxNumberOfCollisions)
        return;
    COL_g_lNbElementsInTable++;
}

/* 0x00494290 */
typedef void *MS_tdxHandleToCollSet;
typedef void *MS_tdxHandleToSectInfo;
long __cdecl COL_lHaveITakeSThgIntoTheMug(DNM_tdstMecObstacle *_a_stResultObstacle,
                                          HIE_tdstSuperObject *_p_stSupObj,
                                          POS_tdstCompletePosition *_p_stStartPosition,
                                          POS_tdstCompletePosition *_p_stEndPosition)
{
    static MTH_tdxReal xSlideCoef   = MTH_C_ZERO;
    static MTH_tdxReal xReboundCoef = MTH_C_ZERO;

    ACP_tdxIndex i;
    long lResult = 0;
    long lParameter2 = 0;

    if (GAM_g_ucIsEdInGhostMode && CAM_fn_bSuperObjectIsACamera(_p_stSupObj))
    {
        DNM_M_eObstacleSetType(&_a_stResultObstacle[0], 0);
        return 0;
    }

    if (M_GetMSHandle (_p_stSupObj , CollSet) && CS_fn_hGetZdxList (COL_PC_C_ucTypeZdm , _p_stSupObj))
    {
        DNM_tdstMecObstacle *p_stCurrentResultObstacle;

        COL_g_stCollisionCaseReal = (COL_tdstCollisionCase *)_a_stResultObstacle;
        COL_g_lNbElementsInTable  = 0;

        COL_fn_vNewStaticCollisionForCharacter (_p_stSupObj, fn_h_SectInfoGetCurrentSector(M_GetMSHandle(_p_stSupObj,SectInfo)), _p_stStartPosition, _p_stEndPosition);

        for (i = 0, p_stCurrentResultObstacle = _a_stResultObstacle;
             i < COL_g_lNbElementsInTable;
             i++, p_stCurrentResultObstacle++)
        {
            lParameter2 = ((COL_tdstCollisionCase *)p_stCurrentResultObstacle)->sParameter2;

            if ((lParameter2 & 0x1) == COL_PC_C_wMobileObject)
                DNM_M_eObstacleSetType(p_stCurrentResultObstacle, DNM_ObsType_Mobile);
            else
                DNM_M_eObstacleSetType(p_stCurrentResultObstacle, DNM_ObsType_Scenery);

            if (lParameter2 & 0x2)
                DNM_M_eObstacleSetType(p_stCurrentResultObstacle,
                    DNM_M_eObstacleGetType(p_stCurrentResultObstacle) | DNM_ObsType_DoubleEdge);

            if (((COL_tdstCollisionCase *)p_stCurrentResultObstacle)->hStaticMaterial != NULL)
            {
                DNM_tdxHandleToMecMatCharacteristics hCollidedMechanicMaterial =
                    COL_M_hGetMechanicsMaterial(
                        (GMT_tdxHandleToGameMaterial)((COL_tdstCollisionCase *)p_stCurrentResultObstacle)->hStaticMaterial);

                if (DNM_fn_bIsMatCharacteristicsValid(hCollidedMechanicMaterial))
                {
                    DNM_tdstMecMatCharacteristics *p_stMechanicMaterial =
                        DNM_fn_p_stMecMatCharacteristicsGiveBackSemantic(hCollidedMechanicMaterial);

                    DNM_M_xObstacleSetSlide(p_stCurrentResultObstacle, DNM_M_xMatCharacteristicsGetSlide(p_stMechanicMaterial));
                    DNM_M_xObstacleSetRebound(p_stCurrentResultObstacle, DNM_M_xMatCharacteristicsGetRebound(p_stMechanicMaterial));
                }
                else
                {
                    DNM_M_xObstacleSetSlide(p_stCurrentResultObstacle, xSlideCoef);
                    DNM_M_xObstacleSetRebound(p_stCurrentResultObstacle, xReboundCoef);
                }
            }
            else
            {
                DNM_M_xObstacleSetSlide(p_stCurrentResultObstacle, xSlideCoef);
                DNM_M_xObstacleSetRebound(p_stCurrentResultObstacle, xReboundCoef);
            }

            lResult = i + 1;
        }
    }

    return lResult;
}
