#ifndef _COL_CSSPHELT_H_
#define _COL_CSSPHELT_H_

#include "COL/CollGOCo.h"

void __cdecl COL_fn_vEnlargeSphereIfNecessary(COL_tdstGVForCollision *p_stGV);

void __cdecl COL_fn_vUseInitialSphere(COL_tdstGVForCollision *p_stGV);

void __cdecl COL_fn_vUseEnlargeSphere(COL_tdstGVForCollision *p_stGV);

void __cdecl COL_fn_vCollideStaticSphereWithStaticSphere(COL_tdstGVForCollision *p_stGV);

ACP_tdxBool __cdecl COL_fn_bCollideStaticSphereWithStaticIndexedTriangle(COL_tdstGVForCollision *p_stGV,
                                                                          ACP_tdxBool bFaceMapInsteadOfIndexedTriangle);

void __cdecl COL_fn_vCollideStaticElementSpheresWithStaticElementSpheres(COL_tdstGVForCollision *p_stGV);

void __cdecl COL_fn_vCollideStaticElementSpheresWithStaticElementIndexedTriangles(COL_tdstGVForCollision *p_stGV);

ACP_tdxBool __cdecl COL_fn_bCollideStaticElementSpheresWithStaticBoundingVolumes(
    COL_tdstGVForCollision *p_stGV, long *_aDEF_lBitsFieldInCollision, ACP_tdxBool _bPartialResult);

void __cdecl COL_fn_vCollideStaticElementSpheresWithStaticOctree(COL_tdstGVForCollision *p_stGV);
void __cdecl COL_fn_vCollideStaticElementSpheresWithStaticElements(COL_tdstGVForCollision *p_stGV);

#endif
