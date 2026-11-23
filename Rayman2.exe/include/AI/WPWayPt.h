#ifndef RAYMAN2_AI_WPWAYPT_H
#define RAYMAN2_AI_WPWAYPT_H

#include "MTH/MTH3D.h"
#include "AI/WPgraphe.h"

#ifdef _WP_D_WAYPOINT_FRIEND_
typedef struct WP_tdstWayPoint_
{
	MTH3D_tdstVector		m_stVertex;
	MTH_tdxReal				m_xRadius;
	struct HIE_tdstSuperObject *m_hSuperObject;
}WP_tdstWayPoint;
#endif

#if defined(_WP_D_WAYPOINT_FRIEND_)

#define WP_M_vWayPointGetStructureField(_hWayPt,_pxPointer,_SlotName)\
 (*(_pxPointer) = (_hWayPt)->m_st##_SlotName)
#define WP_M_xWayPointGetScalarField(_hWayPt,_Prefix,_SlotName)\
 ((_hWayPt)->m_##_Prefix ##_SlotName)
#define WP_M_vWayPointSetStructureField(_hWayPt,_pxPointer,_SlotName)\
 ((_hWayPt)->m_st##_SlotName = *(_pxPointer))
#define WP_M_vWayPointSetScalarField(_hWayPt,_xScalar,_Prefix,_SlotName)\
 ((_hWayPt)->m_##_Prefix ##_SlotName = (_xScalar))

#define WP_M_uwWayPointSizeOf()\
 ((unsigned short)(sizeof(struct WP_tdstWayPoint_)))

#else

#define WP_M_vWayPointGetStructureField(_hWayPt,_pxPointer,_SlotName)\
 (WP_fnv_WayPoint_Get##_SlotName(_hWayPt,_pxPointer))
#define WP_M_xWayPointGetScalarField(_hWayPt,_Prefix,_SlotName)\
 (WP_fn##_Prefix_WayPoint_Get##_SlotName(_hWayPt))
#define WP_M_vWayPointSetStructureField(_hWayPt,_pxPointer,_SlotName)\
 (WP_fnv_WayPoint_Set##_SlotName(_hWayPt,_pxPointer))
#define WP_M_vWayPointSetScalarField(_hWayPt,_xScalar,_Prefix,_SlotName)\
 (WP_fnv_WayPoint_Set##_SlotName(_hWayPt,_xScalar))

#define WP_M_uwWayPointSizeOf()\
 WP_fnuw_WayPoint_SizeOf()
#endif

#define WP_M_vWayPointGetVertex(_hWayPt,_pstVertex)\
 WP_M_vWayPointGetStructureField(_hWayPt,_pstVertex,Vertex)
#define WP_M_vWayPointSetVertex(_hWayPt,_pstNuevoVertex)\
 WP_M_vWayPointSetStructureField(_hWayPt,_pstNuevoVertex,Vertex)

#define WP_M_xWayPointGetRadius(_hWayPt)\
 WP_M_xWayPointGetScalarField(_hWayPt,x,Radius)
#define WP_M_vWayPointSetRadius(_hWayPt,_xNuevoRadius)\
 WP_M_vWayPointSetScalarField(_hWayPt,_xNuevoRadius,x,Radius)

#define WP_M_hWayPointGetSuperObject(_hWayPt)\
 WP_M_xWayPointGetScalarField(_hWayPt,h,SuperObject)
#define WP_M_vWayPointSetSuperObject(_hWayPt,_hNuevoSuperObj)\
 WP_M_vWayPointSetScalarField(_hWayPt,_hNuevoSuperObj,h,SuperObject)

#define WP_M_ucWayPointGetUsedCount(_hWayPt)\
 WP_M_xWayPointGetScalarField(_hWayPt,uc,UsedCount)
#define WP_M_vWayPointSetUsedCount(_hWayPt,_ucNuevoUsedCount)\
 WP_M_vWayPointSetScalarField(_hWayPt,_ucNuevoUsedCount,uc,UsedCount)

void WP_fnv_WayPoint_GetVertex(WP_tdhWayPoint,MTH3D_tdstVector*);

MTH_tdxReal WP_fnx_WayPoint_GetRadius(WP_tdhWayPoint);

#endif
