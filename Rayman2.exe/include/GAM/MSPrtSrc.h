#ifndef RAYMAN2_GAM_MSPRTSRC_H
#define RAYMAN2_GAM_MSPRTSRC_H

typedef struct tdstMSPrtSrc_ * MS_tdxHandleToMSPrtSrc;

void __cdecl fn_vMSPrtSrcSetGeneratorActivation(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, unsigned char ucActivation);  /* 0x00414990 */
void __cdecl fn_p_stMSPrtSrcSetGenerator(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, void *p_stPrtGenerator);             /* 0x0042DB20 */
void __cdecl fn_vMSPrtSrcSetGenerationModeNone(MS_tdxHandleToMSPrtSrc h_MSPrtSrc);                               /* 0x00414D00 */
void __cdecl fn_vMSPrtSrcSetGenerationModeContinuous(MS_tdxHandleToMSPrtSrc h_MSPrtSrc);                         /* 0x00414D20 */
void __cdecl fn_vMSPrtSrcSetGenerationModeCrenel(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, short xNb1, short xNb2);     /* 0x00414D40 */
void __cdecl fn_vMSPrtSrcSetGenerationModeProbability(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, float xProbability);    /* 0x00414D80 */
void __cdecl fn_vMSPrtSrcSetGenerationNumberConstant(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, short xNumber); /* 0x00414DA0 */
void __cdecl fn_vMSPrtSrcSetGenerationNumberProbabilist(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, short xMin, short xMax); /* 0x00414DD0 */
void __cdecl fn_vMSPrtSrcSetParticlesInfiniteLifeTime(MS_tdxHandleToMSPrtSrc h_MSPrtSrc);                        /* 0x00414E00 */
void __cdecl fn_vMSPrtSrcSetParticlesConstantLifeTime(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, float xLifeTime);       /* 0x00414E20 */
void __cdecl fn_vMSPrtSrcSetParticlesProbabilistLifeTime(MS_tdxHandleToMSPrtSrc h_MSPrtSrc, float xMin, float xMax); /* 0x00414E40 */

#endif
