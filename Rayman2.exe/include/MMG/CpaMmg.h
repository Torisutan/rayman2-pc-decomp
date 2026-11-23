#ifndef __MMG_CpaMmg_h__
#define __MMG_CpaMmg_h__

#define C_ucMmgDefaultChannel (0)

#define C_ucTrue (0xFF)
#define C_ucFalse (0)

#define C_uwAllocSize (4)
#define C_uwShiftAllocSize (2)

#define unitAlloc unsigned long

#define Mmg_M_BigBoundSize(ulSize, ucAlignment) \
 \
        \
				 \
                if ( (ulSize) & (unsigned long)(ucAlignment-1)) {\
				 \
                  \
                  \
                (ulSize) = ((ulSize) & (~((unsigned long)(ucAlignment-1)))) + ucAlignment;\
                }

#define C_FillTheBlockWithCleanKeyFlag 2
#define C_Check_AlignementFlag 4
#define C_Check_OverflowFlag 8

#define Mmg_M_SetModeAlloc4Ch(ModuleAbreviation, ucNewMode, C_ucMmgDefaultChannel) Mmg_fn_v_SetModeAlloc(g_uc##ModuleAbreviation##ModuleId, ucNewMode, C_ucMmgDefaultChannel)

#define Mmg_fn_p_vAlloc4Ch(ulSize, ucChannel) fn_p_vGenAlloc((ulSize), (ucChannel))

#define Mmg_MEnterCriticalSection() EnterCriticalSection (&g_csMmg)
#define Mmg_MLeaveCriticalSection() LeaveCriticalSection (&g_csMmg)

#endif
