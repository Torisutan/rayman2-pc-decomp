#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char (__cdecl *SNA_pc_tdpfnRawRead)(void *_p_vBuffer, size_t _ulBytes,
                                                     void *_p_stFile);
typedef struct SNA_pc_tdstStream_
{
    void                *hFile;
    unsigned long        ulValid;
    union
    {
        unsigned long    ulWord;
        unsigned char    a_ucByte[4];
    }                    uCarry;
    unsigned char        ucCarryUsed;
    unsigned long        ulChecksum;
    union
    {
        unsigned long    ulState;
        unsigned char    a_ucByte[4];
    }                    uKey;
    unsigned char        ucFlags;
    unsigned long        ul_pc_1C;
    unsigned long        ul_pc_20;
    SNA_pc_tdpfnRawRead  pfn_bRawRead;
    SNA_pc_tdpfnRawRead  pfn_bRawReadPlain;
} SNA_pc_tdstStream;

#define SNA_pc_C_ulStreamSeed   0x6AB5CC79UL   /* 0x00450A1F */

size_t __cdecl SNA_fn_ulFRead(void   *_p_vBuffer,
                              size_t  _ulSize,
                              size_t  _ulCount,
                              void   *_p_stFile);

unsigned char __cdecl SNA_pc_bGetFlagBit0(void *_p_stFile);  /* 0x00450EB0 */
unsigned char __cdecl SNA_pc_bGetFlagBit1(void *_p_stFile);          /* 0x00450EC0 */
unsigned char __cdecl SNA_pc_bGetFlagBit2(void *_p_stFile);        /* 0x00450ED0 */
void          __cdecl SNA_pc_vInitStream(unsigned char _ucFlags,
                                         void *_p_stFile);         /* 0x00450A00 */
unsigned char __cdecl SNA_pc_bOpenFile(const char *_szPath, char _cMode,
                                       unsigned char _ucFlags,
                                       void *_p_stFile);           /* 0x00450A80 */
unsigned char __cdecl SNA_pc_bCloseFile(void *_p_stFile);         /* 0x00450C40 */

unsigned char __cdecl SNA_pc_bRawReadPlain(void *_p_vBuffer, size_t _ulBytes,
                                           void *_p_stFile);       /* 0x004512C0 */
unsigned char __cdecl SNA_pc_bRawReadDecode(void *_p_vBuffer, size_t _ulBytes,
                                            void *_p_stFile);      /* 0x00451090 */

unsigned long __cdecl SNA_pc_ulSeek(void *_p_stFile, long _lDistance,
                                    int _iOrigin);                /* 0x00450EE0 */

#ifdef __cplusplus
}
#endif
