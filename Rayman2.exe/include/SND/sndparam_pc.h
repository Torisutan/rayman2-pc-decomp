#ifndef SND_SNDPARAM_PC_H
#define SND_SNDPARAM_PC_H

#include "SND/snddef.h"
#include "SND/sndres.h"

#ifdef NB_MICRO_MAX
#define NB_LINK NB_MICRO_MAX
#else
#define NB_LINK 8
#endif

typedef struct SoundParam_ SoundParam;
struct SoundParam_{
	SndReal     Freq;
	unsigned char ucVol;
	unsigned char ucPan;
	unsigned char ucSpace;
	unsigned char ucReverb;
	SndVector   Pos;
	SndVector   Vit;
	int         iFlags ;
	int         iNbLinks;
	MicroLink   astMicro[NB_LINK];
	ExtraSoundParam	xExtra;
} ;

#define SND_M_GetExtraParamFromSoundParam(pstSoundParam)	(ExtraSoundParam*)((char*)pstSoundParam+sizeof(SoundParam)-sizeof(ExtraSoundParam)+(pstSoundParam->iNbLinks-NB_LINK)*sizeof(MicroLink))

#define SND_M_lGetSizeOfSoundParamFromNbLink(nb) (sizeof(SoundParam)+(nb-NB_LINK)*sizeof(MicroLink))
#define SND_M_lGetSizeOfSoundParam( _pObj) (SND_M_lGetSizeOfSoundParamFromNbLink(_pObj->iNbLinks))

#endif
