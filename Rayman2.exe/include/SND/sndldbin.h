#ifndef SND_SNDLDBIN_H_
#define SND_SNDLDBIN_H_

SndBool __stdcall SND_fn_bStartLoadBanks2(int level);
SndBool __stdcall SND_fn_bInitBank2(int _iBankNum,int level);
SND_tdstBlockEvent* __stdcall SND_fn_pGetBinEvent(unsigned long _ulBinId);
tdstBlockResourceMem* __stdcall SND_fn_pGetBinRes(unsigned long _ulBinId);
SndBool __stdcall SND_fn_bUnLoadBinaryBank(int _iBankNum);

void __stdcall SND_fn_vInitBankSnd(char *czPathName);

void __stdcall SND_fn_vDesInitBankSnd(void);

/* 0x00454370 */
int  __stdcall SND_fn_bCanSetOptions(void);

#endif
