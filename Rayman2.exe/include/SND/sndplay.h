#ifndef SND_SNDPLAY_H
#define SND_SNDPLAY_H

void SND_fn_vSetDopplerFactorSnd(SndReal factor);

int SND_fn_iInitSnd(void *pInitStruct);

void SND_fn_vDesInitSnd(void);

long SND_fn_lCreateMicroSnd(MicroParam* par);

SndBool SND_fn_bLoadResBinarySnd(tdstBlockResourceDisk *disk,tdstBlockResourceMem *mem,char *pDataBloc);

void SND_fn_vUnLoadResSnd(tdstBlockResourceMem* mem);
void SND_fn_vStopBeforeUnLoadResSnd(tdstBlockResourceMem* mem);

void SND_fn_vSynchroSnd();

#endif
