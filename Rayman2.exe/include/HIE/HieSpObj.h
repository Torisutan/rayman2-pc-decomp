#ifndef RAYMAN2_HIE_HIESPOBJ_H
#define RAYMAN2_HIE_HIESPOBJ_H

#include "HIE/HIE_types.h"

static __inline unsigned long HIE_fn_ulGetSuperObjectType(struct HIE_tdstSuperObject *_hSprObj)
{
    return HIE_M_xGetSuperObjectMember(_hSprObj,ulTypeOfLinkedObject);
}

static __inline ACP_tdxBool HIE_fn_SO_bIsSuperimposed(struct HIE_tdstSuperObject *_hSO)
{
    return (ACP_tdxBool)(_hSO->ulFlags & HIE_C_Flag_Superimposed);
}

static __inline ACP_tdxBool HIE_fn_SO_bIsNotPickable(struct HIE_tdstSuperObject *_hSO)
{
    return (ACP_tdxBool)(_hSO->ulFlags & HIE_C_Flag_NotPickable);
}

static __inline ACP_tdxBool HIE_fn_SO_bIsHidden(struct HIE_tdstSuperObject *_hSO)
{
    return (ACP_tdxBool)(_hSO->ulFlags & HIE_C_Flag_ulHidden);
}

static __inline ACP_tdxBool HIE_fn_SO_bCheckChildren (struct HIE_tdstSuperObject *_hSO)
{
	return (ACP_tdxBool)((_hSO->ulFlags & HIE_C_Flag_ulCheckChildren) >> 8);
}

static __inline void * HIE_fn_hGetSuperObjectBoundingVolume(struct HIE_tdstSuperObject *_hSprObj)
{
		return (HIE_M_xGetSuperObjectMember(_hSprObj, hBoundingVolume));
}

#define HIE_M_hNextChild(_hBrother)  ((_hBrother)->p_stNextBrother)
#define HIE_M_hFirstChild(_hParent)  ((_hParent)->p_stFirstChild)

#define HIE_fn_SO_bHasZoomInsteadOfScale(_hSO) (HIE_M_xGetSuperObjectMember(_hSO, ulFlags) & HIE_C_Flag_ulZoomInsteadOfScale)

#endif
