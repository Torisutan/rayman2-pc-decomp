#ifndef SND_SNDMEM_H
#define SND_SNDMEM_H

void* __stdcall SND_fn_pvMallocSnd(unsigned long nb_octets);

void  __stdcall SND_fn_vFreeSnd(void* ptr);

#endif
