#ifndef MTH_TYPES_H
#define MTH_TYPES_H

typedef float MTH_tdxReal;

typedef struct MTH3D_tdstVector_ {
    MTH_tdxReal xX;
    MTH_tdxReal xY;
    MTH_tdxReal xZ;
} MTH3D_tdstVector;

typedef struct MTH3D_tdstMatrix_ {
    MTH3D_tdstVector stCol_0;
    MTH3D_tdstVector stCol_1;
    MTH3D_tdstVector stCol_2;
} MTH3D_tdstMatrix;

typedef struct MTH_stRotation
{
    MTH_tdxReal      m_xAngle;
    MTH3D_tdstVector m_stAxis;
} MTH_tdstRotation;

typedef struct MTH_stMove
{
    MTH3D_tdstVector m_stLinear;
    MTH_tdstRotation m_stAngular;
} MTH_tdstMove;

#define MTH_M_xRotationGetAngle(_p_stRotation)         ((_p_stRotation)->m_xAngle)
#define MTH_M_p_stRotationGetAxis(_p_stRotation)       (&(_p_stRotation)->m_stAxis)
#define MTH_M_xRotationSetAngle(_p_stRotation,_xValue) ((_p_stRotation)->m_xAngle = (_xValue))

#define MTH_M_p_stMoveGetLinear(_p_stMove)             (&(_p_stMove)->m_stLinear)
#define MTH_M_p_stMoveGetAngular(_p_stMove)            (&(_p_stMove)->m_stAngular)

#endif
