#ifndef SND_SNDREAL_H
#define SND_SNDREAL_H

#define M_MulIntRealSnd(i,r) ((i)*(r))
#define M_RealToDoubleSnd(r) (((double)r)/(0x10000))
#define M_DoubleToRealSnd(d) ((SndReal)((d)*0x10000))
#define M_DivIntIntRealSnd(a,b) ((SndReal)(((a)<<16)/(b)))
#define M_RealToIntSnd(r) ((r)>>16)
#define M_IntToRealSnd(r) ((r)<<16)
#define M_Fixed1616ToRealSnd(r) (r)

#endif
