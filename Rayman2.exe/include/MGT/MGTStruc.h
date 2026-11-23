#pragma once

#include "ACP/ACP_types.h"

struct GEO_tdstGeometricObject_;
struct MTH3D_tdstVector_;
struct COL_tdstOctree_;
struct HIE_tdstSuperObject;

#define MGT_MAX_NUMBEROF_MAGNETS         5
#define MGT_MAX_NUMBEROF_MODIFIEDOBJECTS 20

typedef struct MGT_tdstMagnetModification_
{
    ACP_tdxIndex                  xIndexOfModifiedObject;
    ACP_tdxIndex                  xNbPoints;
    struct HIE_tdstSuperObject   *h_SuperObject;
    char                         *d_cFieldBitsModifiedPoints;
    char                         *d_cFieldBitsInfluencedPoints;
    unsigned long                *d_ulCurrentDuration;
    ACP_tdxIndex                  xIndexOfActivatedMagnet;
    ACP_tdxBool                   bUsed;
} MGT_tdstMagnetModification;

typedef MGT_tdstMagnetModification *MGT_tdxHandleToMagnetModification;

typedef struct MGT_tdstModifiedObject_
{
    struct GEO_tdstGeometricObject_ *p_stMorphedObject;
    MGT_tdstMagnetModification      *aDEF_hMagnet[MGT_MAX_NUMBEROF_MAGNETS];
    char                            *d_cFieldBitsAlreadyInfluencedPoints;
    struct MTH3D_tdstVector_        *d_stOriginalPosition;
    struct COL_tdstOctree_          *p_stOctree;
    struct HIE_tdstSuperObject      *h_SuperObject;
} MGT_tdstModifiedObject;

typedef MGT_tdstModifiedObject *MGT_tdxHandleToModifiedObject;

#include <stddef.h>
typedef char MGT__assert_mod_size[(sizeof(MGT_tdstMagnetModification) == 0x18) ? 1 : -1];
typedef char MGT__assert_mod_hsuper[(offsetof(MGT_tdstMagnetModification, h_SuperObject) == 0x04) ? 1 : -1];
typedef char MGT__assert_mod_bitB[(offsetof(MGT_tdstMagnetModification, d_cFieldBitsInfluencedPoints) == 0x0C) ? 1 : -1];
typedef char MGT__assert_mod_tag[(offsetof(MGT_tdstMagnetModification, xIndexOfActivatedMagnet) == 0x14) ? 1 : -1];
typedef char MGT__assert_mod_used[(offsetof(MGT_tdstMagnetModification, bUsed) == 0x16) ? 1 : -1];
typedef char MGT__assert_obj_size[(sizeof(MGT_tdstModifiedObject) == 0x28) ? 1 : -1];
typedef char MGT__assert_obj_magnets[(offsetof(MGT_tdstModifiedObject, aDEF_hMagnet) == 0x04) ? 1 : -1];
typedef char MGT__assert_obj_hsuper[(offsetof(MGT_tdstModifiedObject, h_SuperObject) == 0x24) ? 1 : -1];
