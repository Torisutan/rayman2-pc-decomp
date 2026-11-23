#if !defined(MTH_ASM_H)
#define MTH_ASM_H

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
	#if !defined(OPTIMIZED_FOR_PC_FLOATS)
		#define OPTIMIZED_FOR_PC_FLOATS
	#endif
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
INLINE void MTH3D_M_vAddVectorASM(struct MTH3D_tdstVector_ *VectDest,struct MTH3D_tdstVector_ *VectA, struct MTH3D_tdstVector_ *VectB)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		mov ecx,VectDest
		fld  dword ptr [eax]
		fadd dword ptr [ebx]
		fld  dword ptr [eax+4]
		fadd dword ptr [ebx+4]
		fld  dword ptr [eax+8]
		fadd dword ptr [ebx+8]
		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vAddVectorC MTH3D_M_vAddVectorORG
#endif

#define MTH3D_M_vAddVectorORG( VectDest, VectA, VectB)                          \
        {       (VectDest)->xX = MTH_M_xAdd((VectA)->xX, (VectB)->xX);          \
                (VectDest)->xY = MTH_M_xAdd((VectA)->xY, (VectB)->xY);          \
                (VectDest)->xZ = MTH_M_xAdd((VectA)->xZ, (VectB)->xZ); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
INLINE void MTH3D_M_vSubVectorASM(struct MTH3D_tdstVector_ *VectDest,struct MTH3D_tdstVector_ *VectA, struct MTH3D_tdstVector_ *VectB)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		mov ecx,VectDest
		fld  dword ptr [eax]
		fsub dword ptr [ebx]
		fld  dword ptr [eax+4]
		fsub dword ptr [ebx+4]
		fld  dword ptr [eax+8]
		fsub dword ptr [ebx+8]
		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vSubVectorC		MTH3D_M_vSubVectorORG
#endif

#define MTH3D_M_vSubVectorORG( VectDest, VectA, VectB)                          \
        {       (VectDest)->xX = MTH_M_xSub((VectA)->xX, (VectB)->xX);          \
                (VectDest)->xY = MTH_M_xSub((VectA)->xY, (VectB)->xY);          \
                (VectDest)->xZ = MTH_M_xSub((VectA)->xZ, (VectB)->xZ); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
#define MTH3D_M_vNegVectorASM    MTH3D_M_vNegVectorC
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)

#define MTH3D_M_vNegVectorC( VectDest, VectA)                                        \
		{		long register NegMask=0x80000000;								     \
				*((long*) &((VectDest)->xX)) = *((long*) &((VectA)->xX )) ^ NegMask; \
				*((long*) &((VectDest)->xY)) = *((long*) &((VectA)->xY )) ^ NegMask; \
				*((long*) &((VectDest)->xZ)) = *((long*) &((VectA)->xZ )) ^ NegMask; \
		}
#endif

#define MTH3D_M_vNegVectorORG( VectDest, VectA)                                 \
        {       (VectDest)->xX = MTH_M_xNeg( (VectA)->xX );                     \
                (VectDest)->xY = MTH_M_xNeg( (VectA)->xY );                     \
                (VectDest)->xZ = MTH_M_xNeg( (VectA)->xZ ); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vAdd3ScalarVectorASM(MTH3D_tdstVector *VectDest,MTH3D_tdstVector *VectA,MTH_tdxReal x,MTH_tdxReal y,MTH_tdxReal z)
{
	__asm
	{
		mov eax,VectA
		mov ecx,VectDest
		fld  dword ptr [eax]
		fadd dword ptr [x]
		fld  dword ptr [eax+4]
		fadd dword ptr [y]
		fld  dword ptr [eax+8]
		fadd dword ptr [z]
		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]

	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vAdd3ScalarVectorC			MTH3D_M_vAdd3ScalarVectorORG
#endif

#define MTH3D_M_vAdd3ScalarVectorORG( VectDest, VectA, x, y, z)                 \
        {       (VectDest)->xX = MTH_M_xAdd( (VectA)->xX, (x) );                \
                (VectDest)->xY = MTH_M_xAdd( (VectA)->xY, (y) );                \
                (VectDest)->xZ = MTH_M_xAdd( (VectA)->xZ, (z) ); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vMulScalarVectorASM(MTH3D_tdstVector *VectDest,MTH_tdxReal a,MTH3D_tdstVector *VectA)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectDest
		fld  dword ptr [eax]
		fmul dword ptr [a]
		fld  dword ptr [eax+4]
		fmul dword ptr [a]
		fld  dword ptr [eax+8]
		fmul dword ptr [a]
		fxch st(2)
		fstp dword ptr [ebx]
		fstp dword ptr [ebx+4]
		fstp dword ptr [ebx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMulScalarVectorC( VectDest, a, VectA)                          \
				{ register MTH_tdxReal xTempMTH3D_M_vMulScalarVectorC=(a);		\
		        (VectDest)->xX = MTH_M_xMul(xTempMTH3D_M_vMulScalarVectorC, (VectA)->xX);                \
                (VectDest)->xY = MTH_M_xMul(xTempMTH3D_M_vMulScalarVectorC, (VectA)->xY);                \
                (VectDest)->xZ = MTH_M_xMul(xTempMTH3D_M_vMulScalarVectorC, (VectA)->xZ); }
#endif

#define MTH3D_M_vMulScalarVectorORG( VectDest, a, VectA)                        \
        {       (VectDest)->xX = MTH_M_xMul((a), (VectA)->xX);                  \
                (VectDest)->xY = MTH_M_xMul((a), (VectA)->xY);                  \
                (VectDest)->xZ = MTH_M_xMul((a), (VectA)->xZ); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
#define MTH3D_M_vDivScalarVectorASM		MTH3D_M_vDivScalarVectorC
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)

#define MTH3D_M_vDivScalarVectorC( VectDest, VectA, a)                          \
        {  register MTH_tdxReal xTempMTH3D_M_vDivScalarVectorC=MTH_M_xDiv(MTH_C_ONE, (a));				\
		   MTH3D_M_vMulScalarVector( VectDest ,xTempMTH3D_M_vDivScalarVectorC, VectA);	}
#endif

#define MTH3D_M_vDivScalarVectorORG( VectDest, VectA, a)                        \
        {       (VectDest)->xX = MTH_M_xDiv((VectA)->xX, (a));                  \
                (VectDest)->xY = MTH_M_xDiv((VectA)->xY, (a));                  \
                (VectDest)->xZ = MTH_M_xDiv((VectA)->xZ, (a)); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vScaleVectorASM(MTH3D_tdstVector *VectDest,MTH3D_tdstVector *VectA,MTH3D_tdstVector *VectB)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		mov ecx,VectDest

		fld  dword ptr [eax]
		fmul dword ptr [ebx]
		fld  dword ptr [eax+4]
		fmul dword ptr [ebx+4]
		fld  dword ptr [eax+8]
		fmul dword ptr [ebx+8]
		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vScaleVectorC			MTH3D_M_vScaleVectorORG
#endif

#if defined(NITRO)
extern void MTH3D_M_vScaleVectorORG(MTH3D_tdstVector *VectDest, MTH3D_tdstVector *VectA, MTH3D_tdstVector *VectB);
#else

#define MTH3D_M_vScaleVectorORG( VectDest, VectA, VectB )               \
        {       (VectDest)->xX = MTH_M_xMul( (VectA)->xX, (VectB)->xX); \
                (VectDest)->xY = MTH_M_xMul( (VectA)->xY, (VectB)->xY); \
                (VectDest)->xZ = MTH_M_xMul( (VectA)->xZ, (VectB)->xZ); }
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vMulAddVectorASM(MTH3D_tdstVector *VectDest,MTH_tdxReal x,MTH3D_tdstVector *VectA,MTH3D_tdstVector *VectB)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		mov ecx,VectDest

		fld  dword ptr [eax]
		fmul dword ptr [x]
		fld  dword ptr [eax+4]
		fmul dword ptr [x]
		fxch st(1)
		fld  dword ptr [eax+8]
		fmul dword ptr [x]
		fxch st(1)
		fadd dword ptr [ebx]
		fxch st(2)
		fadd dword ptr [ebx+4]
		fxch st(1)
		fadd dword ptr [ebx+8]
		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMulAddVectorC			MTH3D_M_vMulAddVectorORG
#endif

#define MTH3D_M_vMulAddVectorORG( VectDest, x,  VectA, VectB)                           \
      { (VectDest)->xX = MTH_M_xAdd(MTH_M_xMul((x),(VectA)->xX), (VectB)->xX);          \
        (VectDest)->xY = MTH_M_xAdd(MTH_M_xMul((x),(VectA)->xY), (VectB)->xY);          \
        (VectDest)->xZ = MTH_M_xAdd(MTH_M_xMul((x),(VectA)->xZ), (VectB)->xZ); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vMul3AddVectorASM(MTH3D_tdstVector *VectDest,MTH_tdxReal x,MTH3D_tdstVector *VectA,MTH_tdxReal y,MTH3D_tdstVector *VectB,MTH_tdxReal z,MTH3D_tdstVector *VectC)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		mov ecx,VectC
		mov edx,VectDest

		fld  dword ptr [eax]
		fmul dword ptr [x]
		fld  dword ptr [eax+4]
		fmul dword ptr [x]
		fld  dword ptr [eax+8]
		fmul dword ptr [x]
		fxch st(2)

		fld  dword ptr [ebx]
		fmul dword ptr [y]
		fld  dword ptr [ebx+4]
		fmul dword ptr [y]
		fld  dword ptr [ebx+8]
		fmul dword ptr [y]
		fxch st(2)

		faddp st(3),st
		faddp st(3),st
		fld  dword ptr [ecx]
		fmul dword ptr [z]
		fxch st(1)
		faddp st(4),st
		fld  dword ptr [ecx+4]
		fmul dword ptr [z]
		fld  dword ptr [ecx+8]
		fmul dword ptr [z]
		fxch st(2)

		faddp st(3),st
		faddp st(3),st
		faddp st(3),st

		fstp dword ptr [edx]
		fstp dword ptr [edx+4]
		fstp dword ptr [edx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMul3AddVectorC			MTH3D_M_vMul3AddVectorORG
#endif

#define MTH3D_M_vMul3AddVectorORG( VectDest, x,  VectA, y, VectB, z, VectC)									\
      { (VectDest)->xX = MTH_M_xMulAddMulAddMul((x),(VectA)->xX), (y),(VectB)->xX), (z),(VectC)->xX));      \
        (VectDest)->xY = MTH_M_xMulAddMulAddMul((x),(VectA)->xY), (y),(VectB)->xY), (z),(VectC)->xY));      \
        (VectDest)->xZ = MTH_M_xMulAddMulAddMul((x),(VectA)->xZ), (y),(VectB)->xZ), (z),(VectC)->xZ)); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vMul4AddVectorASM(MTH3D_tdstVector *VectDest,MTH_tdxReal x,MTH3D_tdstVector *VectA,MTH_tdxReal y,MTH3D_tdstVector *VectB,MTH_tdxReal z,MTH3D_tdstVector *VectC,MTH_tdxReal w,MTH3D_tdstVector *VectD)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		mov ecx,VectC
		mov edx,VectD

		fld  dword ptr [eax]
		fmul dword ptr [x]
		fld  dword ptr [eax+4]
		fmul dword ptr [x]
		fld  dword ptr [eax+8]
		fmul dword ptr [x]
		fxch st(2)

		fld  dword ptr [ebx]
		fmul dword ptr [y]
		fld  dword ptr [ebx+4]
		fmul dword ptr [y]
		fld  dword ptr [ebx+8]
		fmul dword ptr [y]
		fxch st(2)

		faddp st(3),st
		faddp st(3),st
		fld  dword ptr [ecx]
		fmul dword ptr [z]
		fxch st(1)
		faddp st(4),st
		fld  dword ptr [ecx+4]
		fmul dword ptr [z]
		fld  dword ptr [ecx+8]
		fmul dword ptr [z]
		fxch st(2)

		faddp st(3),st
		faddp st(3),st
		fld  dword ptr [edx]
		fmul dword ptr [w]
		fxch st(1)
		faddp st(4),st
		fld  dword ptr [edx+4]
		fmul dword ptr [w]
		fld  dword ptr [edx+8]
		fmul dword ptr [w]
		fxch st(2)

		faddp st(3),st
		faddp st(3),st
		mov edx,VectDest
		faddp st(3),st

		fstp dword ptr [edx]
		fstp dword ptr [edx+4]
		fstp dword ptr [edx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMul4AddVectorC			MTH3D_M_vMul4AddVectorORG
#endif

#define MTH3D_M_vMul4AddVectorORG( VectDest, x,  VectA, y, VectB, z, VectC, w, VectD)																\
      { (VectDest)->xX = MTH_M_xAdd(MTH_M_xMulAddMulAddMul((x),(VectA)->xX), (y),(VectB)->xX), (z),(VectC)->xX)),MTH_M_xMul((w),(VectD)->xX));      \
        (VectDest)->xY = MTH_M_xAdd(MTH_M_xMulAddMulAddMul((x),(VectA)->xY), (y),(VectB)->xY), (z),(VectC)->xY)),MTH_M_xMul((w),(VectD)->xY));      \
        (VectDest)->xZ = MTH_M_xAdd(MTH_M_xMulAddMulAddMul((x),(VectA)->xZ), (y),(VectB)->xZ), (z),(VectC)->xZ)),MTH_M_xMul((w),(VectD)->xZ)); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vLinearInterpolVectorASM(MTH3D_tdstVector *VectDest,MTH3D_tdstVector *VectA, MTH3D_tdstVector *VectB, MTH_tdxReal t)
{

	__asm
	{
		mov ebx,VectB
		mov eax,VectA
		mov ecx,VectDest

		fld  dword ptr [ebx]
		fsub dword ptr [eax]
		fld  dword ptr [ebx+4]
		fsub dword ptr [eax+4]
		fld  dword ptr [ebx+8]
		fsub dword ptr [eax+8]
		fxch st(2)
		fmul dword ptr [t]
		fld  dword ptr [eax+4]
		fxch st(2)
		fmul dword ptr [t]
		fld  dword ptr [eax]
		fxch st(4)
		fmul dword ptr [t]
		fxch st(2)
		faddp st(4),st
		faddp st(2),st
		fld  dword ptr [eax+8]
		faddp st(1),st
		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vLinearInterpolVectorC			MTH3D_M_vLinearInterpolVectorORG
#endif

#define MTH3D_M_vLinearInterpolVectorORG( VectDest, VectA, VectB, t )				    \
	{	(VectDest)->xX =	MTH_M_xLinearInterpol( (VectA)->xX, (VectB)->xX, (t) );		\
		(VectDest)->xY =	MTH_M_xLinearInterpol( (VectA)->xY, (VectB)->xY, (t) );		\
		(VectDest)->xZ =	MTH_M_xLinearInterpol( (VectA)->xZ, (VectB)->xZ, (t) );		\
	}

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vLinearScaleVectorASM(MTH3D_tdstVector *VectDest,MTH3D_tdstVector *VectA, MTH3D_tdstVector *VectB, MTH3D_tdstVector *VectC)
{

	__asm
	{
		mov ebx,VectB
		mov eax,VectA
		mov ecx,VectDest
		mov edx,VectC

		fld  dword ptr [ebx]
		fsub dword ptr [eax]
		fld  dword ptr [ebx+4]
		fsub dword ptr [eax+4]
		fld  dword ptr [ebx+8]
		fsub dword ptr [eax+8]
		fxch st(2)
		fmul dword ptr [edx]
		fld  dword ptr [eax+4]
		fxch st(2)
		fmul dword ptr [edx+4]
		fld  dword ptr [eax]
		fxch st(4)
		fmul dword ptr [edx+8]
		fxch st(2)
		faddp st(4),st
		faddp st(2),st
		fld  dword ptr [eax+8]
		faddp st(1),st
		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vLinearScaleVectorC			MTH3D_M_vLinearScaleVectorORG
#endif

#define MTH3D_M_vLinearScaleVectorORG( VectDest, VectA, VectB, VectC )				    \
	{	(VectDest)->xX =	MTH_M_xLinearInterpol( (VectA)->xX, (VectB)->xX, (VectC)->xX );		\
		(VectDest)->xY =	MTH_M_xLinearInterpol( (VectA)->xY, (VectB)->xY, (VectC)->xY );		\
		(VectDest)->xZ =	MTH_M_xLinearInterpol( (VectA)->xZ, (VectB)->xZ, (VectC)->xZ );		\
	}

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

#pragma warning(disable:4035)
INLINE
MTH_tdxReal MTH3D_M_xDotProductVectorASM(struct MTH3D_tdstVector_ *VectA,struct MTH3D_tdstVector_ *VectB)
{
	register MTH_tdxReal xDot;
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		fld  dword ptr [eax]
		fmul dword ptr [ebx]
		fld  dword ptr [eax+4]
		fmul dword ptr [ebx+4]
		fld  dword ptr [eax+8]
		fmul dword ptr [ebx+8]
		fxch st(1)
		faddp st(2),st
		faddp st(1),st
		fstp [xDot]
	}
	return(xDot);
}
#pragma warning(default:4035)
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_xDotProductVectorC	MTH3D_M_xDotProductVectorORG
#endif

#if defined(NITRO)
inline asm MTH_tdxReal MTH3D_M_xDotProductVectorInl(MTH3D_tdstVector *VectA, MTH3D_tdstVector *VectB)
{
	stmfd sp!,{r4-r7}
	ldmia r0,{r2,r3,r4}
	ldmia r1,{r5,r6,r7}
	smull r0,r1,r2,r5
	smlal r0,r1,r3,r6
	smlal r0,r1,r4,r7
	adds r0,r0,#0x0800
	adc r1,r1,#0
	mov r0,r0,lsr #12
	add r0,r0,r1,lsl #20
	ldmfd sp!,{r4-r7}
	mov pc,lr
}

#else

#define MTH3D_M_xDotProductVectorORG( VectA, VectB)                             \
	      MTH_M_xAdd(                                                     \
                 MTH_M_xAdd(                                                    \
                MTH_M_xMul((VectA)->xX, (VectB)->xX),                           \
            MTH_M_xMul((VectA)->xY, (VectB)->xY)                                \
                           ),                                                   \
			MTH_M_xMul((VectA)->xZ, (VectB)->xZ) )
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vCrossProductVectorWithoutBufferASM(struct MTH3D_tdstVector_ *VectDest,struct MTH3D_tdstVector_ *VectA,struct MTH3D_tdstVector_ *VectB)
{
	__asm
	{
		mov eax,VectA
		mov ebx,VectB
		mov edx,VectDest

		fld  dword ptr [eax+4]
		fmul dword ptr [ebx+8]
		fld  dword ptr [eax+8]
		fmul dword ptr [ebx]
		fld  dword ptr [eax]
		fmul dword ptr [ebx+4]
		fld  dword ptr [eax+8]
		fmul dword ptr [ebx+4]
		fld  dword ptr [eax]
		fmul dword ptr [ebx+8]
		fld  dword ptr [eax+4]
		fmul dword ptr [ebx]
		fxch st(2)
		fsubp st(5),st
		fsubp st(3),st
		fsubp st(1),st
		fxch st(2)
		fstp  dword ptr [edx]
		fstp  dword ptr [edx+4]
		fstp  dword ptr [edx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vCrossProductVectorWithoutBufferC MTH3D_M_vCrossProductVectorWithoutBufferORG
#endif

#define MTH3D_M_vCrossProductVectorWithoutBufferORG(VectDest, VectA, VectB)               \
    { (VectDest)->xX=MTH_M_xMulSubMul((VectA)->xY,(VectB)->xZ,(VectA)->xZ,(VectB)->xY);   \
      (VectDest)->xY=MTH_M_xMulSubMul((VectA)->xZ,(VectB)->xX,(VectA)->xX,(VectB)->xZ);   \
      (VectDest)->xZ=MTH_M_xMulSubMul((VectA)->xX,(VectB)->xY,(VectA)->xY,(VectB)->xX); }

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
#define MTH3D_M_vCrossProductVectorASM	  MTH3D_M_vCrossProductVectorWithoutBufferASM
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vCrossProductVectorC	  MTH3D_M_vCrossProductVectorWithoutBufferC
#endif

#define MTH3D_M_vCrossProductVectorORG(VectDest, VectA, VectB)                      \
	{	if( (VectDest==VectA) || (VectDest==VectB) )                                \
            {                                                                       \
             MTH3D_tdstVector VectTmp;                                              \
             MTH3D_M_vCrossProductVectorWithoutBuffer(&VectTmp, VectA, VectB);      \
             MTH3D_M_vCopyVector(VectDest, &VectTmp);                               \
            }                                                                       \
        else                                                                        \
            {                                                                       \
              MTH3D_M_vCrossProductVectorWithoutBuffer(VectDest, VectA, VectB);     \
            }																		\
	}

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vMulMatrixMatrixWithoutBufferASM(struct MTH3D_tdstMatrix_ *MatDest,struct MTH3D_tdstMatrix_ *MatA,struct MTH3D_tdstMatrix_ *MatB)
{
	__asm
	{
		mov ebx,MatB
		mov eax,MatA
		mov ecx,MatDest

		fld  dword ptr [ebx]
		fmul dword ptr [eax]
		fld	 dword ptr [ebx]
		fmul dword ptr [eax+4]
		fld	 dword ptr [ebx]
		fmul dword ptr [eax+8]

		fld  dword ptr [ebx+4]
		fmul dword ptr [eax+12]
		fld	 dword ptr [ebx+4]
		fmul dword ptr [eax+16]
		fld	 dword ptr [ebx+4]
		fmul dword ptr [eax+20]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fld  dword ptr [ebx+8]
		fmul dword ptr [eax+24]
		fld	 dword ptr [ebx+8]
		fmul dword ptr [eax+28]
		fld	 dword ptr [ebx+8]
		fmul dword ptr [eax+32]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fxch st(1)
		fld  dword ptr [ebx+12]
		fxch st(3)

		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]

		fmul dword ptr [eax]
		fld	 dword ptr [ebx+12]
		fmul dword ptr [eax+4]
		fld	 dword ptr [ebx+12]
		fmul dword ptr [eax+8]

		fld  dword ptr [ebx+16]
		fmul dword ptr [eax+12]
		fld	 dword ptr [ebx+16]
		fmul dword ptr [eax+16]
		fld	 dword ptr [ebx+16]
		fmul dword ptr [eax+20]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fld  dword ptr [ebx+20]
		fmul dword ptr [eax+24]
		fld	 dword ptr [ebx+20]
		fmul dword ptr [eax+28]
		fld	 dword ptr [ebx+20]
		fmul dword ptr [eax+32]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fxch st(2)

		fld  dword ptr [ebx+24]
		fmul dword ptr [eax]
		fxch st(2)

		fstp dword ptr [ecx+16]
		fstp dword ptr [ecx+12]

		fld	 dword ptr [ebx+24]
		fmul dword ptr [eax+4]
		fld	 dword ptr [ebx+24]
		fmul dword ptr [eax+8]

		fld  dword ptr [ebx+28]
		fmul dword ptr [eax+12]
		fld	 dword ptr [ebx+28]
		fmul dword ptr [eax+16]
		fld	 dword ptr [ebx+28]
		fmul dword ptr [eax+20]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fxch st(3)
		fld  dword ptr [ebx+32]
		fmul dword ptr [eax+24]
		fld	 dword ptr [ebx+32]
		fmul dword ptr [eax+28]
		fld	 dword ptr [ebx+32]
		fmul dword ptr [eax+32]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(4),st

		fstp dword ptr [ecx+20]

		fstp dword ptr [ecx+28]
		fstp dword ptr [ecx+24]
		fstp dword ptr [ecx+32]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMulMatrixMatrixWithoutBufferC      MTH3D_M_vMulMatrixMatrixWithoutBufferORG
#endif

extern void MTH3D_M_fn_vMulMatrixMatrixWithoutBufferORG(MTH3D_tdstMatrix *MatDest, MTH3D_tdstMatrix *MatA, MTH3D_tdstMatrix *MatB);

#define MTH3D_M_vMulMatrixMatrixWithoutBufferORG(MatDest, MatA, MatB)                   \
	MTH3D_M_fn_vMulMatrixMatrixWithoutBufferORG(MatDest, MatA, MatB);
#if 0
    {                                                                                   \
                        (MatDest)->stCol_0.xX =  MTH_M_xMulAddMulAddMul(                \
                (MatA)->stCol_0.xX, (MatB)->stCol_0.xX,                                 \
                (MatA)->stCol_1.xX, (MatB)->stCol_0.xY,                                 \
                (MatA)->stCol_2.xX, (MatB)->stCol_0.xZ );                               \
            (MatDest)->stCol_0.xY =  MTH_M_xMulAddMulAddMul(                            \
                (MatA)->stCol_0.xY, (MatB)->stCol_0.xX,                                 \
                (MatA)->stCol_1.xY, (MatB)->stCol_0.xY,                                 \
                (MatA)->stCol_2.xY, (MatB)->stCol_0.xZ );                               \
            (MatDest)->stCol_0.xZ =  MTH_M_xMulAddMulAddMul(                            \
                (MatA)->stCol_0.xZ, (MatB)->stCol_0.xX,                                 \
                (MatA)->stCol_1.xZ, (MatB)->stCol_0.xY,                                 \
                (MatA)->stCol_2.xZ, (MatB)->stCol_0.xZ );                               \
                                                                                        \
                        (MatDest)->stCol_1.xX =  MTH_M_xMulAddMulAddMul(                \
                (MatA)->stCol_0.xX, (MatB)->stCol_1.xX,                                 \
                (MatA)->stCol_1.xX, (MatB)->stCol_1.xY,                                 \
                (MatA)->stCol_2.xX, (MatB)->stCol_1.xZ );                               \
            (MatDest)->stCol_1.xY =  MTH_M_xMulAddMulAddMul(                            \
                (MatA)->stCol_0.xY, (MatB)->stCol_1.xX,                                 \
                (MatA)->stCol_1.xY, (MatB)->stCol_1.xY,                                 \
                (MatA)->stCol_2.xY, (MatB)->stCol_1.xZ );                               \
            (MatDest)->stCol_1.xZ =  MTH_M_xMulAddMulAddMul(                            \
                (MatA)->stCol_0.xZ, (MatB)->stCol_1.xX,                                 \
                (MatA)->stCol_1.xZ, (MatB)->stCol_1.xY,                                 \
                (MatA)->stCol_2.xZ, (MatB)->stCol_1.xZ );                               \
                                                                                        \
                        (MatDest)->stCol_2.xX =  MTH_M_xMulAddMulAddMul(                \
                (MatA)->stCol_0.xX, (MatB)->stCol_2.xX,                                 \
                (MatA)->stCol_1.xX, (MatB)->stCol_2.xY,                                 \
                (MatA)->stCol_2.xX, (MatB)->stCol_2.xZ );                               \
            (MatDest)->stCol_2.xY =  MTH_M_xMulAddMulAddMul(                            \
                (MatA)->stCol_0.xY, (MatB)->stCol_2.xX,                                 \
                (MatA)->stCol_1.xY, (MatB)->stCol_2.xY,                                 \
                (MatA)->stCol_2.xY, (MatB)->stCol_2.xZ );                               \
            (MatDest)->stCol_2.xZ =  MTH_M_xMulAddMulAddMul(                            \
                (MatA)->stCol_0.xZ, (MatB)->stCol_2.xX,                                 \
                (MatA)->stCol_1.xZ, (MatB)->stCol_2.xY,                                 \
                (MatA)->stCol_2.xZ, (MatB)->stCol_2.xZ );                               \
      }
#endif

#if defined(OPTIMIZED_FOR_U64_ASM)
static inline void MTH3D_M_vMulMatrixMatrixWithoutBufferU64ASM(struct MTH3D_tdstMatrix_ *MatDest,struct MTH3D_tdstMatrix_ *MatA,struct MTH3D_tdstMatrix_ *MatB)
{

	asm(" .set noreorder ");
	asm(" # Begin MulMatrixMatrixWithoutBufferU64ASM ");
	asm(
	" # Premier MulMatrixVertex \n"
	" lwc1 $f6,0(%2) \n"
	" lwc1 $f8,4(%2) \n"
	" lwc1 $f10,8(%2) \n"
	" lwc1 $f0,0(%1)				# f0  <- Mat[0,0] \n"
	" lwc1 $f2,12(%1)				# f2  <- Mat[0,1] \n"
	" mul.s $f0,$f0,$f6			# f0  <- Mat[0,0] x Vect[0] \n"
	" lwc1 $f4,24(%1)				# f4  <- Mat[0,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[0,1] x Vect[1] \n"
	" lwc1 $f12,4(%1)				# f12 <- Mat[1,0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[0,2] x Vect[2] \n"
	" lwc1 $f14,16(%1)			# f14 <- Mat[1,1] \n"
	" mul.s $f12,$f12,$f6		# f12 <- Mat[1,0] x Vect[0] \n"
	" add.s $f0,$f0,$f2			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] \n"
	" lwc1 $f16,28(%1)			# f16 <- Mat[1,2] \n"
	" mul.s $f14,$f14,$f8		# f14 <- Mat[1,1] x Vect[1] \n"
	" add.s $f0,$f0,$f4			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] + Mat[0,2] x Vect[2] \n"
	" lwc1 $f18,8(%1)				# f18 <- Mat[2,0] \n"
	" mul.s $f16,$f16,$f10	# f16 <- Mat[1,2] x Vect[2] \n"
	" add.s $f12,$f12,$f14	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] \n"
	" lwc1 $f2,20(%1)				# f2  <- Mat[2,1] \n"
	" mul.s $f18,$f18,$f6		# f18 <- Mat[2,0] x Vect[0] \n"
	" add.s $f12,$f12,$f16	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] + Mat[1,2] x Vect[2] \n"
	" lwc1 $f4,32(%1)				# f4  <- Mat[2,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[2,1] x Vect[1] \n"
	" swc1 $f0,0(%0)				# f0  -> Dest[0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[2,2] x Vect[2] \n"
	" add.s $f18,$f18,$f2		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] \n"
	" swc1 $f12,4(%0)				# f12 -> Dest[1] \n"
	" add.s $f18,$f18,$f4		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] + Mat[2,2] x Vect[2] \n"
	" swc1 $f18,8(%0)				# f18 -> Dest[2] \n"
	" # Deuxième MulMatrixVertex \n"
	" lwc1 $f6,12(%2) \n"
	" lwc1 $f8,16(%2) \n"
	" lwc1 $f10,20(%2) \n"
	" lwc1 $f0,0(%1)				# f0  <- Mat[0,0] \n"
	" lwc1 $f2,12(%1)				# f2  <- Mat[0,1] \n"
	" mul.s $f0,$f0,$f6			# f0  <- Mat[0,0] x Vect[0] \n"
	" lwc1 $f4,24(%1)				# f4  <- Mat[0,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[0,1] x Vect[1] \n"
	" lwc1 $f12,4(%1)				# f12 <- Mat[1,0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[0,2] x Vect[2] \n"
	" lwc1 $f14,16(%1)			# f14 <- Mat[1,1] \n"
	" mul.s $f12,$f12,$f6		# f12 <- Mat[1,0] x Vect[0] \n"
	" add.s $f0,$f0,$f2			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] \n"
	" lwc1 $f16,28(%1)			# f16 <- Mat[1,2] \n"
	" mul.s $f14,$f14,$f8		# f14 <- Mat[1,1] x Vect[1] \n"
	" add.s $f0,$f0,$f4			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] + Mat[0,2] x Vect[2] \n"
	" lwc1 $f18,8(%1)				# f18 <- Mat[2,0] \n"
	" mul.s $f16,$f16,$f10	# f16 <- Mat[1,2] x Vect[2] \n"
	" add.s $f12,$f12,$f14	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] \n"
	" lwc1 $f2,20(%1)				# f2  <- Mat[2,1] \n"
	" mul.s $f18,$f18,$f6		# f18 <- Mat[2,0] x Vect[0] \n"
	" add.s $f12,$f12,$f16	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] + Mat[1,2] x Vect[2] \n"
	" lwc1 $f4,32(%1)				# f4  <- Mat[2,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[2,1] x Vect[1] \n"
	" swc1 $f0,12(%0)				# f0  -> Dest[0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[2,2] x Vect[2] \n"
	" add.s $f18,$f18,$f2		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] \n"
	" swc1 $f12,16(%0)			# f12 -> Dest[1] \n"
	" add.s $f18,$f18,$f4		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] + Mat[2,2] x Vect[2] \n"
	" swc1 $f18,20(%0)			# f18 -> Dest[2] \n"
	" # Troisième MulMatrixVertex \n"
	" lwc1 $f6,24(%2) \n"
	" lwc1 $f8,28(%2) \n"
	" lwc1 $f10,32(%2) \n"
	" lwc1 $f0,0(%1)				# f0  <- Mat[0,0] \n"
	" lwc1 $f2,12(%1)				# f2  <- Mat[0,1] \n"
	" mul.s $f0,$f0,$f6			# f0  <- Mat[0,0] x Vect[0] \n"
	" lwc1 $f4,24(%1)				# f4  <- Mat[0,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[0,1] x Vect[1] \n"
	" lwc1 $f12,4(%1)				# f12 <- Mat[1,0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[0,2] x Vect[2] \n"
	" lwc1 $f14,16(%1)			# f14 <- Mat[1,1] \n"
	" mul.s $f12,$f12,$f6		# f12 <- Mat[1,0] x Vect[0] \n"
	" add.s $f0,$f0,$f2			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] \n"
	" lwc1 $f16,28(%1)			# f16 <- Mat[1,2] \n"
	" mul.s $f14,$f14,$f8		# f14 <- Mat[1,1] x Vect[1] \n"
	" add.s $f0,$f0,$f4			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] + Mat[0,2] x Vect[2] \n"
	" lwc1 $f18,8(%1)				# f18 <- Mat[2,0] \n"
	" mul.s $f16,$f16,$f10	# f16 <- Mat[1,2] x Vect[2] \n"
	" add.s $f12,$f12,$f14	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] \n"
	" lwc1 $f2,20(%1)				# f2  <- Mat[2,1] \n"
	" mul.s $f18,$f18,$f6		# f18 <- Mat[2,0] x Vect[0] \n"
	" add.s $f12,$f12,$f16	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] + Mat[1,2] x Vect[2] \n"
	" lwc1 $f4,32(%1)				# f4  <- Mat[2,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[2,1] x Vect[1] \n"
	" swc1 $f0,24(%0)				# f0  -> Dest[0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[2,2] x Vect[2] \n"
	" add.s $f18,$f18,$f2		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] \n"
	" swc1 $f12,28(%0)			# f12 -> Dest[1] \n"
	" add.s $f18,$f18,$f4		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] + Mat[2,2] x Vect[2] \n"
	" swc1 $f18,32(%0)			# f18 -> Dest[2] \n"
	: : "r" (MatDest), "r" (MatA), "r" (MatB) : "$f0","$f2","$f4","$f6","$f8","$f10","$f12","$f14","$f16","$f18" );
	asm(" # EndOf MulMatrixMatrixWithoutBufferU64ASM ");\
	asm(" .set reorder ");
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
#define MTH3D_M_vMulMatrixMatrixASM(Mat_Dest, Mat_A, Mat_B)             \
	{       if (Mat_Dest==Mat_A)										\
            {                                                           \
              MTH3D_tdstMatrix Mtemp;                                   \
                                                                        \
              MTH3D_M_vMulMatrixMatrixWithoutBuffer(                    \
                                        &Mtemp, Mat_A, Mat_B);          \
              MTH3D_M_vCopyMatrix( Mat_Dest, &Mtemp);                   \
            }                                                           \
            else                                                        \
            {                                                           \
             MTH3D_M_vMulMatrixMatrixWithoutBuffer(Mat_Dest,            \
                                              Mat_A,  Mat_B);           \
             }															\
	}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMulMatrixMatrixC MTH3D_M_vMulMatrixMatrixORG
#endif

#define MTH3D_M_vMulMatrixMatrixORG(Mat_Dest, Mat_A, Mat_B)             \
    {       if( (Mat_Dest==Mat_A) || (Mat_Dest==Mat_B) )                \
            {                                                           \
              MTH3D_tdstMatrix Mtemp;                                   \
                                                                        \
              MTH3D_M_vMulMatrixMatrixWithoutBuffer(                    \
                                        &Mtemp, Mat_A, Mat_B);          \
              MTH3D_M_vCopyMatrix( Mat_Dest, &Mtemp);                   \
            }                                                           \
            else                                                        \
            {                                                           \
             MTH3D_M_vMulMatrixMatrixWithoutBuffer(Mat_Dest,            \
                                              Mat_A,  Mat_B);           \
             }															\
	}

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

#pragma warning(disable:4035)
INLINE MTH_tdxReal MTH3D_M_xDetMatrixASM(struct MTH3D_tdstMatrix_ *MatA)
{
	register MTH_tdxReal xTempMatrix;
	__asm
	{

		mov	ecx,MatA
		fld  dword ptr [ecx+16]
		fmul dword ptr [ecx+32]
		fld  dword ptr [ecx+20]
		fmul dword ptr [ecx+28]
		fld  dword ptr [ecx+20]
		fmul dword ptr [ecx+24]
		fld  dword ptr [ecx+12]
		fmul dword ptr [ecx+32]
		fxch st(2)
		fsubp st(3),st
		fld  dword ptr [ecx+12]
		fmul dword ptr [ecx+28]
		fxch st(2)
		fsubp st(1),st
		fxch st(2)
		fmul dword ptr [ecx]
		fld  dword ptr [ecx+16]
		fmul dword ptr [ecx+24]
		fxch st(3)
		fmul dword ptr [ecx+4]
		fxch st(3)
		fsubp st(2),st
		faddp st(2),st
		fmul dword ptr [ecx+8]
		faddp st(1),st
		fstp dword ptr [xTempMatrix]
	}
	return(xTempMatrix);
}
#pragma warning(default:4035)
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)

#define MTH3D_M_xDetMatrixC( MatA )																					    \
		MTH_M_xAdd3(																									\
			MTH_M_xMul(	(MatA)->stCol_0.xX,																				\
				MTH_M_xMulSubMul(   (MatA)->stCol_1.xY, (MatA)->stCol_2.xZ,	(MatA)->stCol_1.xZ, (MatA)->stCol_2.xY )	\
					  ),																								\
			MTH_M_xMul(	(MatA)->stCol_0.xY,																				\
				MTH_M_xMulSubMul(	(MatA)->stCol_1.xZ, (MatA)->stCol_2.xX,	(MatA)->stCol_1.xX, (MatA)->stCol_2.xZ )	\
					  ),																								\
			MTH_M_xMul(	(MatA)->stCol_0.xZ,																				\
				MTH_M_xMulSubMul(	(MatA)->stCol_1.xX, (MatA)->stCol_2.xY,	(MatA)->stCol_1.xY, (MatA)->stCol_2.xX )	\
					  )																									\
				   )
#endif

#define MTH3D_M_xDetMatrixORG(MatA)                                                                            \
                    MTH_M_xSub(                                                                             \
                            MTH_M_xAdd3(                                                                    \
                             MTH_M_xMul3( (MatA)->stCol_0.xX, (MatA)->stCol_1.xY, (MatA)->stCol_2.xZ ),     \
                             MTH_M_xMul3( (MatA)->stCol_0.xY, (MatA)->stCol_1.xZ, (MatA)->stCol_2.xX ),     \
                             MTH_M_xMul3( (MatA)->stCol_0.xZ, (MatA)->stCol_1.xX, (MatA)->stCol_2.xY )),    \
                            MTH_M_xAdd3(                                                                    \
                             MTH_M_xMul3( (MatA)->stCol_0.xZ, (MatA)->stCol_1.xY, (MatA)->stCol_2.xX ),     \
                             MTH_M_xMul3( (MatA)->stCol_1.xZ, (MatA)->stCol_2.xY, (MatA)->stCol_0.xX ),     \
                             MTH_M_xMul3( (MatA)->stCol_2.xZ, (MatA)->stCol_0.xY, (MatA)->stCol_1.xX )))

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

INLINE void MTH3D_M_vMulMatrixVectorWithoutBufferASM( struct MTH3D_tdstVector_ *VectDest, struct MTH3D_tdstMatrix_ *MatA, struct MTH3D_tdstVector_ *VectA)
{
	__asm
	{
		mov ebx,VectA
		mov eax,MatA
		mov ecx,VectDest

		fld  dword ptr [ebx]
		fmul dword ptr [eax]
		fld	 dword ptr [ebx]
		fmul dword ptr [eax+4]
		fld	 dword ptr [ebx]
		fmul dword ptr [eax+8]

		fld  dword ptr [ebx+4]
		fmul dword ptr [eax+12]
		fld	 dword ptr [ebx+4]
		fmul dword ptr [eax+16]
		fld	 dword ptr [ebx+4]
		fmul dword ptr [eax+20]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fld  dword ptr [ebx+8]
		fmul dword ptr [eax+24]
		fld	 dword ptr [ebx+8]
		fmul dword ptr [eax+28]
		fld	 dword ptr [ebx+8]
		fmul dword ptr [eax+32]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fxch st(2)
		fstp dword ptr [ecx]
		fstp dword ptr [ecx+4]
		fstp dword ptr [ecx+8]
	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMulMatrixVectorWithoutBufferC        MTH3D_M_vMulMatrixVectorWithoutBufferORG
#endif

#define MTH3D_M_vMulMatrixVectorWithoutBufferORG( VectDest, MatA, VectA)        \
    {         (VectDest)->xX = MTH_M_xAdd3(                                     \
                                MTH_M_xMul( (MatA)->stCol_0.xX, (VectA)->xX),   \
                        MTH_M_xMul( (MatA)->stCol_1.xX, (VectA)->xY),           \
                        MTH_M_xMul( (MatA)->stCol_2.xX, (VectA)->xZ));          \
             (VectDest)->xY = MTH_M_xAdd3(                                      \
                                MTH_M_xMul( (MatA)->stCol_0.xY, (VectA)->xX),   \
                        MTH_M_xMul( (MatA)->stCol_1.xY, (VectA)->xY),           \
                        MTH_M_xMul( (MatA)->stCol_2.xY, (VectA)->xZ));          \
             (VectDest)->xZ = MTH_M_xAdd3(                                      \
                                MTH_M_xMul( (MatA)->stCol_0.xZ, (VectA)->xX),   \
                        MTH_M_xMul( (MatA)->stCol_1.xZ, (VectA)->xY),           \
                        MTH_M_xMul( (MatA)->stCol_2.xZ, (VectA)->xZ)); }

#if defined(OPTIMIZED_FOR_U64_ASM)

static inline void MTH3D_M_vMulMatrixVectorWithoutBufferU64ASM( struct MTH3D_tdstVector_ *VectDest, struct MTH3D_tdstMatrix_ *MatA, struct MTH3D_tdstVector_ *VectA)
{

	asm(" .set noreorder ");
	asm(" # Begin MulMatrixVectorWithoutBufferU64ASM " );
	asm(
	" lwc1 $f6,0(%2) \n"
	" lwc1 $f8,4(%2) \n"
	" lwc1 $f10,8(%2) \n"
	" lwc1 $f0,0(%1)				# f0  <- Mat[0,0] \n"
	" lwc1 $f2,12(%1)				# f2  <- Mat[0,1] \n"
	" mul.s $f0,$f0,$f6			# f0  <- Mat[0,0] x Vect[0] \n"
	" lwc1 $f4,24(%1)				# f4  <- Mat[0,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[0,1] x Vect[1] \n"
	" lwc1 $f12,4(%1)				# f12 <- Mat[1,0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[0,2] x Vect[2] \n"
	" lwc1 $f14,16(%1)			# f14 <- Mat[1,1] \n"
	" mul.s $f12,$f12,$f6		# f12 <- Mat[1,0] x Vect[0] \n"
	" add.s $f0,$f0,$f2			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] \n"
	" lwc1 $f16,28(%1)			# f16 <- Mat[1,2] \n"
	" mul.s $f14,$f14,$f8		# f14 <- Mat[1,1] x Vect[1] \n"
	" add.s $f0,$f0,$f4			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] + Mat[0,2] x Vect[2] \n"
	" lwc1 $f18,8(%1)				# f18 <- Mat[2,0] \n"
	" mul.s $f16,$f16,$f10	# f16 <- Mat[1,2] x Vect[2] \n"
	" add.s $f12,$f12,$f14	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] \n"
	" lwc1 $f2,20(%1)				# f2  <- Mat[2,1] \n"
	" mul.s $f18,$f18,$f6		# f18 <- Mat[2,0] x Vect[0] \n"
	" add.s $f12,$f12,$f16	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] + Mat[1,2] x Vect[2] \n"
	" lwc1 $f4,32(%1)				# f4  <- Mat[2,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[2,1] x Vect[1] \n"
	" swc1 $f0,0(%0)				# f0  -> Dest[0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[2,2] x Vect[2] \n"
	" add.s $f18,$f18,$f2		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] \n"
	" swc1 $f12,4(%0)				# f12 -> Dest[1] \n"
	" add.s $f18,$f18,$f4		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] + Mat[2,2] x Vect[2] \n"
	" swc1 $f18,8(%0)				# f18 -> Dest[2] \n"
	: : "r" (VectDest), "r" (MatA), "r" (VectA) : "$f0","$f2","$f4","$f6","$f8","$f10","$f12","$f14","$f16","$f18" );
	asm(" # EndOf MulMatrixVectorWithoutBufferU64ASM ");
	asm(" .set reorder ");
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
#define MTH3D_M_vMulMatrixVectorASM                        MTH3D_M_vMulMatrixVectorWithoutBufferASM
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
#define MTH3D_M_vMulMatrixVectorC                          MTH3D_M_vMulMatrixVectorORG
#endif

#if defined(OPTIMIZED_FOR_U64_ASM)
#define MTH3D_M_vMulMatrixVectorU64ASM                     MTH3D_M_vMulMatrixVectorWithoutBufferU64ASM
#endif

#define MTH3D_M_vMulMatrixVectorORG( VectDest, MatA, VectA)                     \
	{   if( VectA==VectDest )                                                   \
        {                                                                       \
          MTH3D_tdstVector Vtmp;                                                \
                                                                                \
          MTH3D_M_vCopyVector( &Vtmp, VectA);                                   \
          MTH3D_M_vMulMatrixVectorWithoutBuffer( VectDest, MatA, &Vtmp);        \
        }                                                                       \
        else                                                                    \
        {                                                                       \
          MTH3D_M_vMulMatrixVectorWithoutBuffer( VectDest, MatA, VectA);        \
        }																		\
	}

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)

#pragma warning(disable:4725)
INLINE void MTH3D_M_vInverMatrixASM(struct MTH3D_tdstMatrix_ *MatDest, struct MTH3D_tdstMatrix_ *MatA)
{
	static MTH_tdxReal ONE=MTH_C_ONE;
		__asm
	{
		mov eax,MatA
		mov ebx,MatDest

		fld  dword ptr [eax+16]
		fmul dword ptr [eax+32]
		fld  dword ptr [eax+20]
		fmul dword ptr [eax+24]
		fld  dword ptr [eax+12]
		fmul dword ptr [eax+28]
		fld  dword ptr [eax+20]
		fmul dword ptr [eax+28]
		fld  dword ptr [eax+12]
		fmul dword ptr [eax+32]
		fld  dword ptr [eax+16]
		fmul dword ptr [eax+24]

		fxch st(2)
		fsubp st(5),st
		fsubp st(3),st
		fsubp st(1),st

		fld  dword ptr [eax+8]
		fmul dword ptr [eax+28]

		fld  st(3)
		fmul dword ptr [eax]
		fld  st(3)
		fmul dword ptr [eax+4]
		fld  st(3)
		fmul dword ptr [eax+8]

		fld  dword ptr [eax+4]
		fmul dword ptr [eax+32]

		fxch st(2)
		faddp st(3),st

		fld  dword ptr [eax]
		fmul dword ptr [eax+32]

		fxch st(2)
		fsubp st(4),st
		faddp st(2),st

		fld  dword ptr [eax+8]
		fmul dword ptr [eax+24]

		fld dword ptr [ONE]
		fdivrp st(3),st

		fsubp st(1),st
		fxch st(1)

		fld st(0)
		fmulp st(6),st
		fld st(0)
		fmulp st(5),st
		fld st(0)
		fmulp st(4),st
		fld st(0)
		fmulp st(3),st
		fld st(0)
		fmulp st(2),st

		fld  dword ptr [eax+4]
		fmul dword ptr [eax+24]

		fld  dword ptr [eax]
		fmul dword ptr [eax+28]

		fxch st(7)
		fstp dword ptr [ebx]

		fld  dword ptr [eax+4]
		fmul dword ptr [eax+20]

		fxch st(1)
		fsubrp st(7),st

		fld  dword ptr [eax+8]
		fmul dword ptr [eax+16]

		fxch st(6)
		fstp dword ptr [ebx+12]

		fld  dword ptr [eax+8]
		fmul dword ptr [eax+12]

		fxch st(1)
		fsubrp st(6),st

		fld  dword ptr [eax]
		fmul dword ptr [eax+20]

		fxch st(5)
		fstp dword ptr [ebx+24]

		fld  dword ptr [eax]
		fmul dword ptr [eax+16]

		fxch st(1)
		fsubrp st(5),st

		fld  dword ptr [eax+4]
		fmul dword ptr [eax+12]

		fxch st(4)
		fstp dword ptr [ebx+4]

		fxch st(1)
		fld st(0)
		fmulp st(7),st
		fxch st(1)
		fsubrp st(3),st

		fld st(0)
		fmulp st(5),st
		fld st(0)
		fmulp st(4),st

		fxch st(1)
		fstp dword ptr [ebx+16]
		fmulp st(1),st
		fxch st(3)

		fstp dword ptr [ebx+28]
		fstp dword ptr [ebx+20]
		fstp dword ptr [ebx+8]
		fstp dword ptr [ebx+32]
	}
}
#pragma warning(default:4725)
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)

INLINE void MTH3D_M_vInverMatrixC(MTH3D_tdstMatrix *MatDest, MTH3D_tdstMatrix *MatA)
{
      register MTH_tdxReal det;
      (MatDest)->stCol_0.xX= MTH_M_xMulSubMul((MatA)->stCol_1.xY,(MatA)->stCol_2.xZ,(MatA)->stCol_1.xZ,(MatA)->stCol_2.xY);
	  det = MTH_M_xMul( (MatA)->stCol_0.xX ,(MatDest)->stCol_0.xX );
      (MatDest)->stCol_1.xX= MTH_M_xMulSubMul((MatA)->stCol_1.xZ,(MatA)->stCol_2.xX,(MatA)->stCol_1.xX,(MatA)->stCol_2.xZ);
	  det = MTH_M_xAdd(MTH_M_xMul( (MatA)->stCol_0.xY ,(MatDest)->stCol_1.xX ), det);
      (MatDest)->stCol_2.xX= MTH_M_xMulSubMul((MatA)->stCol_1.xX,(MatA)->stCol_2.xY,(MatA)->stCol_1.xY,(MatA)->stCol_2.xX);
  	  det = MTH_M_xAdd(MTH_M_xMul( (MatA)->stCol_0.xZ ,(MatDest)->stCol_2.xX ), det);
	  (MatDest)->stCol_0.xY= MTH_M_xMulSubMul((MatA)->stCol_0.xZ,(MatA)->stCol_2.xY,(MatA)->stCol_0.xY,(MatA)->stCol_2.xZ);
	  det =	MTH_M_xDiv(	MTH_C_ONE, det );
	  (MatDest)->stCol_0.xZ= MTH_M_xMulSubMul((MatA)->stCol_0.xY,(MatA)->stCol_1.xZ,(MatA)->stCol_0.xZ,(MatA)->stCol_1.xY);
      (MatDest)->stCol_1.xY= MTH_M_xMulSubMul((MatA)->stCol_0.xX,(MatA)->stCol_2.xZ,(MatA)->stCol_0.xZ,(MatA)->stCol_2.xX);
      (MatDest)->stCol_1.xZ= MTH_M_xMulSubMul((MatA)->stCol_0.xZ,(MatA)->stCol_1.xX,(MatA)->stCol_0.xX,(MatA)->stCol_1.xZ);
	  (MatDest)->stCol_2.xY= MTH_M_xMulSubMul((MatA)->stCol_0.xY,(MatA)->stCol_2.xX,(MatA)->stCol_0.xX,(MatA)->stCol_2.xY);
      (MatDest)->stCol_2.xZ= MTH_M_xMulSubMul((MatA)->stCol_0.xX,(MatA)->stCol_1.xY,(MatA)->stCol_0.xY,(MatA)->stCol_1.xX);
	  MTH3D_M_vMulScalarMatrix( MatDest, det, MatDest );
}
#endif

#define MTH3D_M_vInverMatrixORG(MatDest, MatA)                       \
{																	 \
	  MTH3D_tdstMatrix Mat_Tmp={0};                                   \
      MTH3D_tdstMatrix Mat_Com;                                      \
      MTH_tdxReal det;                                               \
                                                                     \
      MTH3D_M_vComMatrixWithoutBuffer(&Mat_Com, MatA);               \
      MTH3D_M_vTranspMatrix(&Mat_Tmp, &Mat_Com );                    \
      det=MTH3D_M_xDetMatrix( MatA );                                \
      MTH3D_M_vDivScalarMatrix(MatDest, &Mat_Tmp, det );             \
}

#if defined(OPTIMIZED_FOR_PC_FLOATS_WITH_ASM)
INLINE void MTH3D_M_vTransformVectorWithoutBufferASM(MTH3D_tdstVector *VectDest,MTH3D_tdstMatrix *MatA,MTH3D_tdstVector *VectA,MTH3D_tdstVector *VectB)
{
	__asm
	{
		mov ecx,VectB
		mov edx,VectDest
		mov ebx,VectA
		mov eax,MatA

		fld  dword ptr [ecx]
		fld  dword ptr [ecx+4]
		fld  dword ptr [ecx+8]

		fld  dword ptr [ebx]
		fmul dword ptr [eax]
		fld	 dword ptr [ebx]
		fmul dword ptr [eax+4]
		fld	 dword ptr [ebx]
		fmul dword ptr [eax+8]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fld  dword ptr [ebx+4]
		fmul dword ptr [eax+12]
		fld	 dword ptr [ebx+4]
		fmul dword ptr [eax+16]
		fld	 dword ptr [ebx+4]
		fmul dword ptr [eax+20]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fld  dword ptr [ebx+8]
		fmul dword ptr [eax+24]
		fld	 dword ptr [ebx+8]
		fmul dword ptr [eax+28]
		fld	 dword ptr [ebx+8]
		fmul dword ptr [eax+32]

		fxch st(2)
		faddp st(5),st
		faddp st(3),st
		faddp st(1),st

		fxch st(2)

		fstp dword ptr [edx]
		fstp dword ptr [edx+4]
		fstp dword ptr [edx+8]

	}
}
#endif

#if defined(OPTIMIZED_FOR_PC_FLOATS)
	#define MTH3D_M_vTransformVectorWithoutBufferC	MTH3D_M_vTransformVectorWithoutBufferORG
#endif

#define MTH3D_M_vTransformVectorWithoutBufferORG( VectDest, MatA, VectA, VectB)	\
	{	MTH3D_M_vMulMatrixVectorWithoutBuffer(VectDest, MatA, VectA);			\
		MTH3D_M_vAddVector(VectDest,VectDest,VectB);							\
	}

#ifdef NITRO

inline asm MTH_tdxReal MTH3D_M_xMaxAbsCoordinate(MTH3D_tdstVector *pVec)
{
	mov		r1,#0
	ldr		r2,[r0]
	cmp		r2,r1
	sublt	r2,r1,r2
	ldr		r3,[r0,#4]
	cmp		r3,r1
	sublt	r3,r1,r3
	cmp		r2,r3
	movlt	r2,r3
	ldr		r3,[r0,#8]
	cmp		r3,r1
	sublt	r3,r1,r3
	cmp		r2,r3
	movlt	r2,r3
	mov		r0,r2
	mov		pc,lr
}

extern void CrossProduct20(MTH3D_tdstVector *VectDest, MTH3D_tdstVector *VectA, MTH3D_tdstVector *VectB);
extern void MulScalarVector20(MTH3D_tdstVector *VectDest, MTH_tdxReal xScale, MTH3D_tdstVector *VectA);
extern MTH_tdxReal DotProduct20(MTH3D_tdstVector *VectA, MTH3D_tdstVector *VectB);

#endif

#if defined(OPTIMIZED_FOR_U64_ASM)

static inline void MTH3D_M_vTransformVectorWithoutBufferU64ASM( struct MTH3D_tdstVector_ *VectDest, struct MTH3D_tdstMatrix_ *MatA, struct MTH3D_tdstVector_ *VectA, struct MTH3D_tdstVector_ *VectB)
{

	asm(" .set noreorder ");
	asm(" # Begin TransformVectorWithoutBufferU64ASM ");
	asm(
	" lwc1 $f6,0(%2) \n"
	" lwc1 $f8,4(%2) \n"
	" lwc1 $f10,8(%2) \n"
	" lwc1 $f0,0(%1)				# f0  <- Mat[0,0] \n"
	" lwc1 $f2,12(%1)				# f2  <- Mat[0,1] \n"
	" mul.s $f0,$f0,$f6			# f0  <- Mat[0,0] x Vect[0] \n"
	" lwc1 $f4,24(%1)				# f4  <- Mat[0,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[0,1] x Vect[1] \n"
	" lwc1 $f12,4(%1)				# f12 <- Mat[1,0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[0,2] x Vect[2] \n"
	" lwc1 $f14,16(%1)			# f14 <- Mat[1,1] \n"
	" mul.s $f12,$f12,$f6		# f12 <- Mat[1,0] x Vect[0] \n"
	" add.s $f0,$f0,$f2			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] \n"
	" lwc1 $f16,28(%1)			# f16 <- Mat[1,2] \n"
	" mul.s $f14,$f14,$f8		# f14 <- Mat[1,1] x Vect[1] \n"
	" add.s $f0,$f0,$f4			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] + Mat[0,2] x Vect[2] \n"
	" lwc1 $f18,8(%1)				# f18 <- Mat[2,0] \n"
	" mul.s $f16,$f16,$f10	# f16 <- Mat[1,2] x Vect[2] \n"
	" add.s $f12,$f12,$f14	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] \n"
	" lwc1 $f2,20(%1)				# f2  <- Mat[2,1] \n"
	" mul.s $f18,$f18,$f6		# f18 <- Mat[2,0] x Vect[0] \n"
	" add.s $f12,$f12,$f16	# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] + Mat[1,2] x Vect[2] \n"
	" lwc1 $f4,32(%1)				# f4  <- Mat[2,2] \n"
	" mul.s $f2,$f2,$f8			# f2  <- Mat[2,1] x Vect[1] \n"
	" lwc1 $f6,0(%3)				# f6  <- VctB[0] \n"
	" mul.s $f4,$f4,$f10		# f4  <- Mat[2,2] x Vect[2] \n"
	" add.s $f18,$f18,$f2		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] \n"
	" lwc1 $f8,4(%3)				# f8  <- VctB[1] \n"
	" add.s $f18,$f18,$f4		# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] + Mat[2,2] x Vect[2] \n"
	" lwc1 $f10,8(%3)				# f10 <- VctB[2] \n"
	" add.s $f0,$f0,$f6			# f0  <- Mat[0,0] x Vect[0] + Mat[0,1] x Vect[1] + Mat[0,2] x Vect[2] + VctB[0] \n"
	" add.s $f12,$f12,$f8		# f12 <- Mat[1,0] x Vect[0] + Mat[1,1] x Vect[1] + Mat[1,2] x Vect[2] + VctB[1] \n"
	" swc1 $f0,0(%0)				# f0  -> Dest[0] \n"
	" add.s $f18,$f18,$f10	# f18 <- Mat[2,0] x Vect[0] + Mat[2,1] x Vect[1] + Mat[2,2] x Vect[2] + VctB[1] \n"
	" swc1 $f12,4(%0)				# f12 -> Dest[1] \n"
	" swc1 $f18,8(%0)				# f18 -> Dest[2] \n"
	: : "r" (VectDest), "r" (MatA), "r" (VectA) , "r" (VectB) : "$f0","$f2","$f4","$f6","$f8","$f10","$f12","$f14","$f16","$f18" );
	asm(" # EndOf TransformVectorWithoutBufferU64ASM ");
	asm(" .set reorder ");
}
#endif

#endif
