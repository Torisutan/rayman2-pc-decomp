#ifndef SND_SNDDEF_H
#define SND_SNDDEF_H

#define NB_MICRO_MAX 2

#define SND_CALL WINAPI

typedef void (__stdcall *SND_td_pfn_vSoundCallback)(long par);

#define SndBool_field_decl(x) SndBool x

#endif
