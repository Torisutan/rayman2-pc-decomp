#pragma once

struct GLD_tdstViewportAttributes_;

/* 0x0042CA40 */
void GLI_pc_vTransformPointsByObject(long lCount, float *p_xSrc, float *p_xDst, void *p_stObj);

struct MTH3D_tdstVector_;

void GLI_vDraw2DSprite(struct GLD_tdstViewportAttributes_ *p_stVpt,
                                float fParam2,
                                float fParam3,
                                float fParam4,
                                float fParam5,
                                void *p_vMaterial);

int GLI_vDrawWorldPlanarSprite(struct MTH3D_tdstVector_ *pPosition,
                               void *pVisualMaterial,
                               float fscaleX,
                               float fscaleY,
                               struct GLD_tdstViewportAttributes_ *_p_stViewport,
                               unsigned long AnimTime);
int GLI_vDrawWorldOrthoPlanarSprite(struct MTH3D_tdstVector_ *pPosition,
                                    void *pVisualMaterial,
                                    float fscaleX,
                                    float fscaleY,
                                    struct GLD_tdstViewportAttributes_ *_p_stViewport,
                                    unsigned long AnimTime,
                                    struct MTH3D_tdstVector_ *p_stV1,
                                    struct MTH3D_tdstVector_ *p_stV2,
                                    int FollowZ);

/* 0x0042A1E0 */
void GLI_vDisplayWorldTriangle(struct GLD_tdstViewportAttributes_ *p_stViewport,
                               float c[3][3],
                               float uvs[3][2],
                               void *pVisualMaterial);
