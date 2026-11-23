#ifndef RAYMAN2_MEC_DNMMTH_H
#define RAYMAN2_MEC_DNMMTH_H

#include "MTH/MTH_types.h"
#include "MTH/MTH3D.h"

#define MTH_M_RotationSetAxis(_p_stRotation,_p_stVector) MTH3D_M_vCopyVector(&(_p_stRotation)->m_stAxis,_p_stVector)

#define MTH_M_MoveSetAngularPosition(_p_stMove,_xAngle,_p_stAxis) {\
        MTH_M_xRotationSetAngle(&(_p_stMove)->m_stAngular,_xAngle);\
        MTH_M_RotationSetAxis(&(_p_stMove)->m_stAngular,_p_stAxis);\
}

#define MTH_M_MoveSetLinear(_p_stMove,_p_stVector) MTH3D_M_vCopyVector(&(_p_stMove)->m_stLinear,_p_stVector)

#endif
