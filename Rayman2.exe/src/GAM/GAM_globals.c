#define D_GAM_VariableDefine
#include "MMG/SNA.h"
#include "GAM/GAM_globals.h"
#include "GAM/GAM_pc_session.h"

unsigned char GAM_pc_g_ucGameEndCondition;    /* 0x005116EC */

/* 0x0049f080 */
HANDLE g_hWnd_storage = (HANDLE)-1;

/* 0x004A1234 */
float GAM_pc_g_xParticuleRate = 1.0f;

/* 0x0049F630 */
unsigned char g_ucGameModuleId = 0xFF;

/* 0x004A6A90 */
unsigned long GAM_g_ulQuitFlag;

long          GAM_g_lCurrentFrameSave;           /* 0x004A6AE8 */
unsigned long GAM_pc_g_ulActualizeClockHookGate; /* 0x004A7084 */

#include "GAM/GAM_types.h"
GAM_tdstEngineStructure GAM_g_stEngineStructure_storage;

HIE_tdstSuperObject *g_hSOCurrentMainSector;    /* 0x500FB0 */
HIE_tdstSuperObject *g_hSOPreviousMainSector;   /* 0x500FC8 */
HIE_tdstSuperObject *gp_stInactiveDynamicWorld; /* 0x500FC4 */
HIE_tdstSuperObject *gp_stDynamicWorld;         /* 0x500FD0 */
HIE_tdstSuperObject *SECT_hFatherSector;        /* 0x500FC0 */

#include "ALW/ALW.h"
void fn_v3dDataCopyClone(); void fn_ul3dDataSizeOf(); void fn_v3dDataAlloc(); void fn_v3dDataFree(); void fn_v3dDataInit(); void fn_v3dDataDesinit();
void fn_vStdGameCopyClone(); void fn_ulStdGameSizeOf(); void fn_vStdGameAlloc(); void fn_vStdGameFree(); void fn_vStdGameInit(); void fn_vStdGameDesinit();
void fn_vDynamCopyClone(); void fn_ulBrainSizeOf(); void fn_vDynamAlloc(); void fn_vDynamFree(); void fn_vDynamInit(); void fn_vDynamDesinit();
void fn_vBrainCopyClone(); void fn_vBrainAlloc(); void fn_vBrainFree(); void fn_vBrainInit(); void fn_vBrainDesinit();
void CAM_fn_vCineinfoCopyClone(); void CAM_fn_ulCineinfoSizeOf(); void CAM_fn_vCineinfoAlloc(); void CAM_fn_vCineinfoFree(); void CAM_fn_vCineinfoInit(); void CAM_fn_vCineinfoDesinit();
void fn_vCollSetCopyClone(); void fn_ulCollSetSizeOf(); void fn_vCollSetAlloc(); void fn_vCollSetFree(); void fn_vCollSetInit(); void fn_vCollSetDesinit();
void fn_vMSWayCopyClone(); void fn_vMSWayAlloc(); void fn_vMSWayFree(); void fn_vMSWayInit(); void fn_vMSWayDesinit();
void fn_vLightCopyClone(); void fn_ulLightSizeOf(); void fn_vLightAlloc(); void fn_vLightFree(); void fn_vLightInit(); void fn_vLightDesinit();
void fn_vSectInfoCopyClone(); void fn_ulSectInfoSizeOf(); void fn_vSectInfoAlloc(); void fn_vSectInfoFree(); void fn_vSectInfoInit(); void fn_vSectInfoDesinit();
void fn_vMicroCopyClone(); void GAM_pc_fn_ulGetHolderSize8(); void fn_vMicroAlloc(); void fn_vMicroFree(); void fn_vActivateMicroForObject(); void fn_vMicroDesinit();
void fn_vMSPrtSrcCopyClone(); void fn_ulMSPrtSrcSizeOf(); void fn_vMSPrtSrcAlloc(); void fn_vMSPrtSrcFree(); void fn_vMSPrtSrcInit(); void fn_vMSPrtSrcDesinit();
void fn_vMSSoundCopyClone(); void fn_vMSSoundAlloc(); void fn_vMSSoundFree(); void fn_vMSSoundInit(); void fn_vMSSoundDesinit();
void fn_vAnimEffectCopyClone(); void fn_ulAnimEffectSizeOf(); void fn_vAnimEffectAlloc(); void fn_vAnimEffectFree(); void fn_vAnimEffectDesinit();
void fn_vMSMagnetCopyClone(); void fn_ulMSMagnetSizeOf(); void fn_vMSMagnetAlloc(); void fn_vMSMagnetFree(); void fn_vMSMagnetInit(); void fn_vMSMagnetDesinit();

#define GAM_M_SHF(a, b, c, d, e, f) { \
    (void (__cdecl *)(struct tdstEngineObject_ *, struct tdstEngineObject_ *))(a), \
    (unsigned long (__cdecl *)(void))(b), \
    (void (__cdecl *)(struct tdstEngineObject_ *))(c), \
    (void (__cdecl *)(struct tdstEngineObject_ *))(d), \
    (void (__cdecl *)(struct tdstEngineObject_ *, int))(e), \
    (void (__cdecl *)(struct tdstEngineObject_ *, int))(f) }

tdstStructureHandleFunction g_a_stStructureHandleFunction[15] =   /* 0x0049F4C8 */
{
           GAM_M_SHF(fn_v3dDataCopyClone, fn_ul3dDataSizeOf, fn_v3dDataAlloc, fn_v3dDataFree, fn_v3dDataInit, fn_v3dDataDesinit),
     GAM_M_SHF(fn_vStdGameCopyClone, fn_ulStdGameSizeOf, fn_vStdGameAlloc, fn_vStdGameFree, fn_vStdGameInit, fn_vStdGameDesinit),

                        GAM_M_SHF(fn_vDynamCopyClone, fn_ulBrainSizeOf, fn_vDynamAlloc, fn_vDynamFree, fn_vDynamInit, fn_vDynamDesinit),
            GAM_M_SHF(fn_vBrainCopyClone, fn_ulBrainSizeOf, fn_vBrainAlloc, fn_vBrainFree, fn_vBrainInit, fn_vBrainDesinit),
         GAM_M_SHF(CAM_fn_vCineinfoCopyClone, CAM_fn_ulCineinfoSizeOf, CAM_fn_vCineinfoAlloc, CAM_fn_vCineinfoFree, CAM_fn_vCineinfoInit, CAM_fn_vCineinfoDesinit),
          GAM_M_SHF(fn_vCollSetCopyClone, fn_ulCollSetSizeOf, fn_vCollSetAlloc, fn_vCollSetFree, fn_vCollSetInit, fn_vCollSetDesinit),

                        GAM_M_SHF(fn_vMSWayCopyClone, fn_ulBrainSizeOf, fn_vMSWayAlloc, fn_vMSWayFree, fn_vMSWayInit, fn_vMSWayDesinit),
            GAM_M_SHF(fn_vLightCopyClone, fn_ulLightSizeOf, fn_vLightAlloc, fn_vLightFree, fn_vLightInit, fn_vLightDesinit),
    /* 0x00403290 */
                        GAM_M_SHF(fn_vSectInfoCopyClone, fn_ulSectInfoSizeOf, fn_vSectInfoAlloc, fn_vSectInfoFree, fn_vSectInfoInit, fn_vSectInfoDesinit),

                        GAM_M_SHF(fn_vMicroCopyClone, GAM_pc_fn_ulGetHolderSize8, fn_vMicroAlloc, fn_vMicroFree, fn_vActivateMicroForObject, fn_vMicroDesinit),
         GAM_M_SHF(fn_vMSPrtSrcCopyClone, fn_ulMSPrtSrcSizeOf, fn_vMSPrtSrcAlloc, fn_vMSPrtSrcFree, fn_vMSPrtSrcInit, fn_vMSPrtSrcDesinit),

                        GAM_M_SHF(fn_vMSSoundCopyClone, GAM_pc_fn_ulGetHolderSize8, fn_vMSSoundAlloc, fn_vMSSoundFree, fn_vMSSoundInit, fn_vMSSoundDesinit),

                        GAM_M_SHF(fn_vAnimEffectCopyClone, fn_ulAnimEffectSizeOf, fn_vAnimEffectAlloc, fn_vAnimEffectFree, fn_vAnimEffectDesinit, fn_vAnimEffectDesinit),
         GAM_M_SHF(fn_vMSMagnetCopyClone, fn_ulMSMagnetSizeOf, fn_vMSMagnetAlloc, fn_vMSMagnetFree, fn_vMSMagnetInit, fn_vMSMagnetDesinit),
      GAM_M_SHF(1, 2, 3, 4, 5, 6)
};
