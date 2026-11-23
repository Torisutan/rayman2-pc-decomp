#pragma once

#include "ACP/ACP_types.h"

typedef struct GMT_tdstGameMaterial_    *GMT_tdxHandleToGameMaterial;
typedef struct GMT_tdstCollideMaterial_ *GMT_tdxHandleToCollideMaterial;
typedef unsigned short                   GMT_tdxMask;

typedef void *DNM_tdxHandleToMecMatCharacteristics;

typedef long  SND_tdxHandleToSoundMaterial;

#define GMT_C_InvalidSoundMaterial   ((SND_tdxHandleToSoundMaterial)(-1))
#define GMT_C_InvalidCollideMaterial ((GMT_tdxHandleToCollideMaterial)(-1))
#define GMT_C_ulInvalidHandle        ((GMT_tdxHandleToGameMaterial)(0xcdcdcdcd))

struct GMT_tdstCollideMaterial_
{
    short        wTypeOfZone;
    GMT_tdxMask  xIdentifier;
};
typedef struct GMT_tdstCollideMaterial_ GMT_tdstCollideMaterial;

struct GMT_tdstGameMaterial_
{
    ACP_tdxHandleOfMaterial               hVisualMaterial;
    DNM_tdxHandleToMecMatCharacteristics  hMechanicsMaterial;
    SND_tdxHandleToSoundMaterial          hSoundMaterial;
    GMT_tdxHandleToCollideMaterial        hCollideMaterial;
};
typedef struct GMT_tdstGameMaterial_ GMT_tdstGameMaterial;

#define GMT_M_hGetVisualMaterial(_handle) \
    ((_handle)->hVisualMaterial)

#define GMT_M_vSetVisualMaterial(_hGameMat, _hVisualMat) \
    { (_hGameMat)->hVisualMaterial = (_hVisualMat); }

#define GMT_M_hGetMechanicsMaterial(_handle) \
    ((_handle)->hMechanicsMaterial)

#define GMT_M_vSetMechanicsMaterial(_hGameMat, _hMechanicsMat) \
    { (_hGameMat)->hMechanicsMaterial = (_hMechanicsMat); }

#define GMT_M_hGetSoundMaterial(_handle) \
    ((_handle)->hSoundMaterial)

#define GMT_M_vSetSoundMaterial(_hGameMat, _hSoundMat) \
    { (_hGameMat)->hSoundMaterial = (_hSoundMat); }

#define GMT_M_hGetCollideMaterial(_handle) \
    ((_handle)->hCollideMaterial)

#define GMT_M_vSetCollideMaterial(_hGameMat, _hCollideMat) \
    { (_hGameMat)->hCollideMaterial = (_hCollideMat); }

#define GMT_M_wGetTypeOfCollideMaterial(_handle) \
    ((_handle)->wTypeOfZone)

#define GMT_M_vSetTypeOfCollideMaterial(_hCollideMat, _wType) \
    { (_hCollideMat)->wTypeOfZone = (_wType); }

#define GMT_M_wGetCollideMaterialIdentifier(_hCollideMat) \
    ((_hCollideMat)->xIdentifier)

#define GMT_M_vSetCollideMaterialIdentifier(_hCollideMat, _wIdentifier) \
    { (_hCollideMat)->xIdentifier = (_wIdentifier); }

/* 0x004B72B8 */
extern unsigned char g_ucGmtModuleId;

GMT_tdxHandleToGameMaterial    __cdecl GMT_fn_hCreateGameMaterial(void);
unsigned long                  __cdecl GMT_fn_b_ulIsValid(GMT_tdxHandleToGameMaterial _hMaterial);
void                           __cdecl GMT_fn_vSetVisualMaterial(GMT_tdxHandleToGameMaterial _hGameMat, ACP_tdxHandleOfMaterial _hVisualMat);
GMT_tdxHandleToCollideMaterial __cdecl GMT_fn_hGetCollideMaterial(GMT_tdxHandleToGameMaterial _hGameMat);
ACP_tdxBool                    __cdecl GMT_fn_xTestCollideIdentifierTypeOfGameMaterial(GMT_tdxHandleToGameMaterial _hGameMat, unsigned short _uwType);
ACP_tdxBool                    __cdecl GMT_fn_xMultipleTestCollideIdentifierFromGameMaterial(GMT_tdxHandleToGameMaterial _hGameMat, GMT_tdxMask _xType);
GMT_tdxMask                    __cdecl GMT_fn_hGetCollideMaterialIdentifier(GMT_tdxHandleToCollideMaterial _hCollideMat);
ACP_tdxBool                    __cdecl GMT_fn_xTestCollideMaterialTypeOfIdentifier(GMT_tdxHandleToCollideMaterial _hCollideMat, unsigned short _uwType);
ACP_tdxBool                    __cdecl GMT_fn_xMultipleTestCollideIdentifier(GMT_tdxHandleToCollideMaterial _hCollideMat, GMT_tdxMask _xType);

/* 0x00419B90 */
void                           __cdecl GMT_fn_vInitFor3DOS(void);
GMT_tdxHandleToGameMaterial    __cdecl GMT_fn_hCreateFor3DOS(void);
void                           __cdecl GMT_fn_vCopyFor3DOS(GMT_tdxHandleToGameMaterial _hDst,
                                                            GMT_tdxHandleToGameMaterial _hSrc);
void                           __cdecl GMT_fn_vDestroyFor3DOS(GMT_tdxHandleToGameMaterial _hOld);
void                           __cdecl GMT_fn_vResetEntireMask(GMT_tdxMask *_p_xMask);
void                           __cdecl GMT_fn_vSetMechanicsMaterial(GMT_tdxHandleToGameMaterial _hGameMat,
                                                                    DNM_tdxHandleToMecMatCharacteristics _hMechMat);
