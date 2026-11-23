#ifndef RAYMAN2_GAM_EFFECT_H
#define RAYMAN2_GAM_EFFECT_H

#include "ACP/ACP_types.h"
#include "MTH/MTH3D.h"

typedef struct tdstFootPath_
{
    ACP_tdxIndex      xNumberOfAlphaLevels;
    float             a8_xAlphaColor[8];
    ACP_tdxIndex      a8_xNumberOfPoints[8];
    ACP_tdxIndex      a8_xMaxNumberOfFaces[8];
    ACP_tdxIndex      a8_xNumberOfFaces[8];
    ACP_tdxIndex      a8_xNextFaces[8];
    MTH3D_tdstVector  a2_stOffset[2];
    float             a2_xScale[2];
    void             *a8_hGeomObj[8];
    void             *hFootPrintMaterial;
    unsigned long     xConsiderMaterial;
} tdstFootPath;

typedef struct tdstWaterFoam_
{
    MTH3D_tdstVector  stPosition;
    unsigned char     bFoamIsActive;
    long              lLifeTime;
} tdstWaterFoam;

typedef struct tdstWaterStreakEffect_
{
    long              lNbFoams;
    long              lNbGraphicFoams;
    tdstWaterFoam    *a_stFoams;
    unsigned long     ulLastTimeOfShift;
    float             xFoamXZoom;
    float             xFoamYZoom;
    long              lFoamFrameCounter;
    void            **a_hFoamObjectTable;
    float             xAttenuationCoeff;
    float             xLifeTimeFrequency;
    long              lLifeTime;
    long              lTimeBetweenTwoShifts;
    float             xTimeWindow;
    float             xGap;
} tdstWaterStreakEffect;

/* 0x0040C450 */
void __cdecl fn_vWaterStreakEffect(void *_p_stViewportAttr, void *_hCharacter, long _lDrawMask);

/* 0x0040C3B0 */
void __cdecl fn_vTreatWaterStreak(tdstWaterStreakEffect *_hWaterStreak, long _lElapsedTime);

/* 0x0040C4B0 */
void __cdecl fn_v_FootPath_ReInit(tdstFootPath *_hFootPath);
/* 0x0040C4F0 */
void __cdecl fn_v_FootPath_Add(void *_hCharacter, ACP_tdxIndex _xFootPrintType);

#endif
