#include "GLI/int64_arithmetic.h"

void __cdecl fn_vAddTimerValues(unsigned int *p_uDst, unsigned int *p_uSrc)
{
    unsigned int uNewLo = p_uDst[0] + p_uSrc[0];
    if (uNewLo < p_uDst[0]) {
        p_uDst[1] += 1;
    }
    p_uDst[0] = uNewLo;
    p_uDst[1] += p_uSrc[1];
}

void __cdecl fn_vSubTimerValues(unsigned int *p_uDst, unsigned int *p_uSrc)
{
    if (p_uDst[1] == p_uSrc[1]) {

        p_uDst[1] = 0;
        p_uDst[0] -= p_uSrc[0];
    } else if (p_uDst[0] >= p_uSrc[0]) {

        p_uDst[0] -= p_uSrc[0];
        p_uDst[1] -= p_uSrc[1];
    } else {

        unsigned int uNewLo = p_uDst[0] - p_uSrc[0];
        unsigned int uHmDec = p_uDst[1] - 1;
        p_uDst[0]  = uNewLo;
        p_uDst[1]  = uHmDec;
        p_uDst[1]  = uHmDec - p_uSrc[1];
    }
}
