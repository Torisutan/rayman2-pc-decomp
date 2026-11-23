#include "DNM/DNM_types.h"
#include "GMT/GMT_types.h"
#include "TMP/TmpMem.h"

extern void *__cdecl fnp_vGameMallocInHLM(unsigned int ulSize);  /* 0x004077E0 */

/* 0x00412BD0 */
unsigned long __cdecl fn_ulDynamSizeOf(void)
{
    return sizeof(struct tdstDynam_);
}

/* 0x00419B90 */
void *__cdecl fn_p_stDynamGetDynamics(MS_tdxHandleToDynam h_Dynam)
{
    return(h_Dynam->p_stDynamics);
}

void __cdecl fn_vDynamSetDynamics(MS_tdxHandleToDynam h_Dynam, void *p_stDynam)
{
    h_Dynam->p_stDynamics = (DNM_tdstDynamics *)p_stDynam;
}

void *__cdecl fn_p_stDynamGetParsingDatas(MS_tdxHandleToDynam h_Dynam)
{
    return(h_Dynam->p_stParsingDatas);
}

void __cdecl fn_vDynamSetParsingDatas(MS_tdxHandleToDynam h_Dynam, void *p_stParsingDatas)
{
    h_Dynam->p_stParsingDatas = (DNM_tdstParsingDatas *)p_stParsingDatas;
}

/* 0x00412C70 */
void *__cdecl fn_h_DynamRealAlloc(void)
{
    void *h_Dynam;

    h_Dynam = fnp_vGameMallocInHLM((unsigned int)fn_ulDynamSizeOf());
    fn_vDynamSetParsingDatas((MS_tdxHandleToDynam)h_Dynam,
                             fnp_vGameMallocInHLM((unsigned int)sizeof(DNM_tdstParsingDatas)));
    return h_Dynam;
}

/* 0x00413100 */
void __cdecl fn_vDynamSetUsedMechanics(MS_tdxHandleToDynam h_Dynam, DNM_tdeMechanicsID eUsedMechanics)
{
    h_Dynam->eUsedMechanics = eUsedMechanics;
}

#define FN_DYN_SIZE_BASE       0x154
#define FN_DYN_SIZE_ADVANCED   0x1DC
#define FN_DYN_SIZE_COMPLEX    0x338
#define FN_DYN_SIZE_REPORT     0x16C

#define FN_DYN_SET_REPORT(p, r) (DNM_M_p_stDynamicsGetReport(p) = (r))

#define FN_DYN_SET_COLLISION_REPORT(p, b) \
    (DNM_M_ulEndFlags(p) = ((b) ? (DNM_M_ulEndFlags(p) |= DNM_C_CollisionReport) \
                                : (DNM_M_ulEndFlags(p) &= ~DNM_C_CollisionReport)))

#define FN_DYN_SET_ALWAYS(p, b) \
    (DNM_M_ulEndFlags(p) = ((b) ? (DNM_M_ulEndFlags(p) |= DNM_C_Always) \
                                : (DNM_M_ulEndFlags(p) &= ~DNM_C_Always)))

#define FN_DYN_SET_BASE_SIZE(p) \
    { DNM_M_ulEndFlags(p) &= ~(DNM_C_BaseSize|DNM_C_AdvancedSize|DNM_C_ComplexSize); \
      DNM_M_ulEndFlags(p) |= DNM_C_BaseSize; }
#define FN_DYN_SET_ADVANCED_SIZE(p) \
    { DNM_M_ulEndFlags(p) &= ~(DNM_C_BaseSize|DNM_C_AdvancedSize|DNM_C_ComplexSize); \
      DNM_M_ulEndFlags(p) |= (DNM_C_AdvancedSize|DNM_C_BaseSize); }
#define FN_DYN_SET_COMPLEX_SIZE(p) \
    { DNM_M_ulEndFlags(p) |= (DNM_C_ComplexSize|DNM_C_AdvancedSize|DNM_C_BaseSize); }

/* 0x00412CA0 */
void __cdecl fn_v_DynamicAlloc(void *h_Dynam, eDynamicSize eSize,
                               ACP_tdxBool bCollision, ACP_tdxBool bAlways)
{
    DNM_tdstDynamics *p_stDynamic = NULL;

    if (bAlways)
    {
        switch (eSize)
        {
        case eDynamicSizeBase :
            p_stDynamic = (DNM_tdstDynamics *)TMP_M_p_Malloc(FN_DYN_SIZE_BASE);
            FN_DYN_SET_BASE_SIZE(p_stDynamic);
            break;
        case eDynamicSizeAdvanced :
            p_stDynamic = (DNM_tdstDynamics *)TMP_M_p_Malloc(FN_DYN_SIZE_ADVANCED);
            FN_DYN_SET_ADVANCED_SIZE(p_stDynamic);
            break;
        case eDynamicSizeComplex :
            p_stDynamic = (DNM_tdstDynamics *)TMP_M_p_Malloc(FN_DYN_SIZE_COMPLEX);
            FN_DYN_SET_COMPLEX_SIZE(p_stDynamic);
            break;
        }
    }
    else
    {
        switch (eSize)
        {
        case eDynamicSizeBase :
            p_stDynamic = (DNM_tdstDynamics *)fnp_vGameMallocInHLM(FN_DYN_SIZE_BASE);
            FN_DYN_SET_BASE_SIZE(p_stDynamic);
            break;
        case eDynamicSizeAdvanced :
            p_stDynamic = (DNM_tdstDynamics *)fnp_vGameMallocInHLM(FN_DYN_SIZE_ADVANCED);
            FN_DYN_SET_ADVANCED_SIZE(p_stDynamic);
            break;
        case eDynamicSizeComplex :
            p_stDynamic = (DNM_tdstDynamics *)fnp_vGameMallocInHLM(FN_DYN_SIZE_COMPLEX);
            FN_DYN_SET_COMPLEX_SIZE(p_stDynamic);
            break;
        }
    }

    fn_vDynamSetDynamics((MS_tdxHandleToDynam)h_Dynam, p_stDynamic);
    FN_DYN_SET_ALWAYS(p_stDynamic, bAlways);

    if (bCollision)
    {
        if (bAlways)
            FN_DYN_SET_REPORT(p_stDynamic,
                              (DNM_tdstReport *)TMP_M_p_Malloc(FN_DYN_SIZE_REPORT));
        else
            FN_DYN_SET_REPORT(p_stDynamic,
                              (DNM_tdstReport *)fnp_vGameMallocInHLM(FN_DYN_SIZE_REPORT));
    }
    else
        FN_DYN_SET_REPORT(p_stDynamic, NULL);

    FN_DYN_SET_COLLISION_REPORT(p_stDynamic, bCollision);
}
