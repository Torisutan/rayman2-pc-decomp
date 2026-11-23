#pragma once

typedef struct HIE_tdstEngineObject_ HIE_tdstEngineObject;
typedef struct ZDX_tdstCollSet_ ZDX_tdstCollSet;

void __cdecl fn_vCollSetAlloc(HIE_tdstEngineObject *engineObject);
void __cdecl fn_vCollSetCopyClone(HIE_tdstEngineObject *pDest,
                                      HIE_tdstEngineObject *pSrc);
void __cdecl COL_fn_vNewStaticCollisionForCharacter(void *pCharacter, void *pSector,
                                                    void *pStartMatrix, void *pEndMatrix);
