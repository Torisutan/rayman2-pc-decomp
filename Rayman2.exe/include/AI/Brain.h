#ifndef RAYMAN2_AI_BRAIN_H
#define RAYMAN2_AI_BRAIN_H

static __inline struct AI_tdstMind_ *fn_p_stBrainGetMind(MS_tdxHandleToBrain h_Brain)
{
	return(h_Brain->p_stMind);
}

#define M_vSetLastCollidedGoThroughMaterialOfBrain(h_Brain, hGameMaterial) fn_vBrainSetLastCollidedGoThroughMaterial((h_Brain),(hGameMaterial))
#define M_vSetWarnMechanicsFlagOfBrain(h_Brain, bFlag) fn_vBrainSetWarnMechanicsFlag((h_Brain),(bFlag))

static __inline void fn_vBrainSetLastCollidedGoThroughMaterial(MS_tdxHandleToBrain h_Brain, void *_hGameMaterial)
{
	h_Brain->hLastCollidedGoThroughMaterial = _hGameMaterial;
}

static __inline void fn_vBrainSetWarnMechanicsFlag(MS_tdxHandleToBrain h_Brain, ACP_tdxBool _bFlag)
{
	h_Brain->bWarnMechanicsFlag = _bFlag;
}

#endif
