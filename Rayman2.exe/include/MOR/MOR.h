#pragma once

#include "ACP/ACP_types.h"
#include "GAM/PlayAnim.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MOR_C_SUSPENDED     2
#define MOR_C_LOCKED        3

#define MOR_C_MORPH_WAITATEND_ANIM 2

#define MOR_C_NbMorphTasks 0x32

typedef struct MOR_tdstMorphStruct_
{
    unsigned char        bInUse;
    unsigned char        _pad01[3];
    HIE_tdstSuperObject *hActorSuperObject;
    short                xStartIndexInObjectTable;
    short                xEndIndexInObjectTable;
    unsigned char        ucMorphType;
    unsigned char        _pad0d[3];
    long                 iNbMillisecond;
    long                 iStart;
    long                 iEnd;
    long                 iStep;
    long                 iCurrent;
    unsigned short       xChannelIndex;
    unsigned char        _pad26[2];
    void                *hOriginalPhysicalObject;
    void                *p_stMorphPO;
} MOR_tdstMorphStruct;

/* 0x00443890 */
ACP_tdxIndex __cdecl MOR_fn_xStopMorph(HIE_tdstSuperObject *_hActorSuperObject,
                                       unsigned short _xChannelIndex);

/* 0x00443F30 */
ACP_tdxBool __cdecl MOR_fn_bIsChannelMorphed(HIE_tdstSuperObject *_hActorSuperObject,
                                             unsigned short _xChannelIndex);

/* 0x00443990 */
ACP_tdxIndex __cdecl MOR_fn_xMorphing(HIE_tdstSuperObject *_hActorSuperObject,
                                      short _xStartIndexInObjectTable,
                                      short _xEndIndexInObjectTable,
                                      int _iRatio,
                                      unsigned short _xChannelIndex);

/* 0x004440B0 */
void __cdecl MOR_fn_vDoMorph(short _xIndex);

/* 0x00444090 */
void *__cdecl MOR_fn_hGetMorphedObject(short _xIndex);

/* 0x00443D80 */
void __cdecl GEO_fn_vMorphAddInMainLoop(void);

/* 0x00443c00 */
void __cdecl MOR_fn_vMorphTo(MOR_tdstMorphStruct *mp);

/* 0x00444030 */
unsigned char __cdecl MOR_fn_bRemoveMorphedObjectFromHierarchy(
    HIE_tdstSuperObject *hSuperObject, void *p_stPhysicalObjectToRemove,
    void *p_stPhysicalObjectToPut);

/* 0x00443d60 */
void __cdecl MOR_fn_vCleanMorphTask(MOR_tdstMorphStruct *mp);

/* 0x004440d0 */
void *__cdecl MOR_fn_xCopyGeometricObjectForMorph(struct GEO_tdstGeometricObject_ *_pGeometricObjectToCopy);
/* 0x004444a0 */
void __cdecl MOR_fn_vDeleteGeometricObject(void *_ppGeometricObject);
/* 0x00444570 */
void __cdecl MOR_fn_vDeletePhysicalObject(void *_pPhysicalObject);

#ifdef __cplusplus
}
#endif
