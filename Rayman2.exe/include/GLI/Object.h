#pragma once

#include "GLI/GLI_globals.h"
#include "MTH/MTH3D.h"

/* 0x0042A990 */
void __cdecl GLI_xSendObjectElement(
    struct GLI_tdstInternalGlobalValuesFor3dEngine_ *p_stGlobals);

/* 0x00429890 */
unsigned char __cdecl GLI_vDrawWorldSprite(
    MTH3D_tdstVector                  *pPosition,
    void                              *hMaterial,
    MTH_tdxReal                        xScaleX,
    MTH_tdxReal                        xScaleY,
    struct GLD_tdstViewportAttributes *p_stViewport,
    unsigned long                      ulAnimTime);

/* 0x0042AAE0 */
void __cdecl GLI_xSendObjectToViewportWithLights(
    struct GLD_tdstViewportAttributes *p_stVpt,
    void                              *p_stObj,
    long                               lDrawModeMask);

/* 0x0042A410 */
void __cdecl GLI_vDoMaterialSelection(
    struct GLI_tdstInternalGlobalValuesFor3dEngine_ *p_stGlobals);

/* 0x00429670 */
void __cdecl GLI_vDraw2DSpriteWithPercent(
    struct GLD_tdstViewportAttributes *p_stViewport,
    MTH_tdxReal                        XMin,
    MTH_tdxReal                        YMin,
    MTH_tdxReal                        XMax,
    MTH_tdxReal                        YMax,
    void                              *hMaterial);
