#ifndef MTH2D_H
#define MTH2D_H

#include <math.h>
#include <stdio.h>
#include "MTH/MTH_types.h"
#include "MTH/MTH_flt.h"

typedef struct MTH2D_tdstVector_ {
    MTH_tdxReal xX;
    MTH_tdxReal xY;
} MTH2D_tdstVector;

typedef struct MTH2D_tdstMatrix_ {
    MTH2D_tdstVector stCol_0;
    MTH2D_tdstVector stCol_1;
} MTH2D_tdstMatrix;

static inline MTH_tdxReal MTH2D_M_xGetXofVector(const MTH2D_tdstVector *VectA) { return VectA->xX; }
static inline MTH_tdxReal MTH2D_M_xGetYofVector(const MTH2D_tdstVector *VectA) { return VectA->xY; }
static inline void MTH2D_M_vSetXofVector(MTH2D_tdstVector *VectDest, MTH_tdxReal Vx) { VectDest->xX = Vx; }
static inline void MTH2D_M_vSetYofVector(MTH2D_tdstVector *VectDest, MTH_tdxReal Vy) { VectDest->xY = Vy; }

static inline void MTH2D_M_vNullVector(MTH2D_tdstVector *VectDest) { VectDest->xX = 0.0f; VectDest->xY = 0.0f; }
static inline void MTH2D_M_vFillVector(MTH2D_tdstVector *VectDest, MTH_tdxReal a) { VectDest->xX = a; VectDest->xY = a; }
static inline void MTH2D_M_vCopyVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA) { *VectDest = *VectA; }

static inline void MTH2D_M_vAddVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ VectDest->xX=VectA->xX+VectB->xX; VectDest->xY=VectA->xY+VectB->xY; }

static inline void MTH2D_M_vSubVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ VectDest->xX=VectA->xX-VectB->xX; VectDest->xY=VectA->xY-VectB->xY; }

static inline void MTH2D_M_vNegVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA)
{ VectDest->xX=-(VectA->xX); VectDest->xY=-(VectA->xY); }

static inline void MTH2D_M_vMulScalarVector(MTH2D_tdstVector *VectDest, MTH_tdxReal a, const MTH2D_tdstVector *VectA)
{ VectDest->xX=a*VectA->xX; VectDest->xY=a*VectA->xY; }

static inline void MTH2D_M_vDivScalarVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, MTH_tdxReal a)
{ VectDest->xX=VectA->xX/a; VectDest->xY=VectA->xY/a; }

static inline void MTH2D_M_vAddScalarVector(MTH2D_tdstVector *VectDest, MTH_tdxReal a, const MTH2D_tdstVector *VectA)
{ VectDest->xX=VectA->xX+a; VectDest->xY=VectA->xY+a; }

static inline void MTH2D_M_vSubScalarVector(MTH2D_tdstVector *VectDest, MTH_tdxReal a, const MTH2D_tdstVector *VectA)
{ VectDest->xX=VectA->xX-a; VectDest->xY=VectA->xY-a; }

static inline void MTH2D_M_vScaleVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ VectDest->xX=VectA->xX*VectB->xX; VectDest->xY=VectA->xY*VectB->xY; }

static inline void MTH2D_M_vMulAddVector(MTH2D_tdstVector *VectDest, MTH_tdxReal x, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ VectDest->xX=x*VectA->xX+VectB->xX; VectDest->xY=x*VectA->xY+VectB->xY; }

static inline MTH_tdxReal MTH2D_M_xDotProductVector(const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ return VectA->xX*VectB->xX + VectA->xY*VectB->xY; }

static inline MTH_tdxReal MTH2D_M_xSqrVector(const MTH2D_tdstVector *VectA)
{ return VectA->xX*VectA->xX + VectA->xY*VectA->xY; }

static inline MTH_tdxReal MTH2D_M_xNormVector(const MTH2D_tdstVector *VectA)
{ return MTH_M_xSqrt(MTH2D_M_xSqrVector(VectA)); }

static inline MTH_tdxReal MTH2D_M_xInvNormVector(const MTH2D_tdstVector *VectA)
{ return MTH_M_xInvSqrt(MTH2D_M_xSqrVector(VectA)); }

static inline MTH_tdxReal MTH2D_M_xVectorGapSqr(const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ MTH_tdxReal dx=VectA->xX-VectB->xX, dy=VectA->xY-VectB->xY; return dx*dx+dy*dy; }

static inline MTH_tdxReal MTH2D_M_xVectorGap(const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ return MTH_M_xSqrt(MTH2D_M_xVectorGapSqr(VectA, VectB)); }

static inline void MTH2D_M_vNormalizeVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA)
{
    MTH_tdxReal inv_norm = MTH_M_xInvSqrt(MTH2D_M_xSqrVector(VectA));
    VectDest->xX = inv_norm * VectA->xX;
    VectDest->xY = inv_norm * VectA->xY;
}

static inline void MTH2D_M_vMiddleVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ VectDest->xX=(VectA->xX+VectB->xX)*0.5f; VectDest->xY=(VectA->xY+VectB->xY)*0.5f; }

static inline void MTH2D_M_vLinearInterpolVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB, MTH_tdxReal t)
{ VectDest->xX=VectA->xX+t*(VectB->xX-VectA->xX); VectDest->xY=VectA->xY+t*(VectB->xY-VectA->xY); }

static inline void MTH2D_M_vMaxVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ VectDest->xX=VectA->xX>VectB->xX?VectA->xX:VectB->xX; VectDest->xY=VectA->xY>VectB->xY?VectA->xY:VectB->xY; }

static inline void MTH2D_M_vMinVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ VectDest->xX=VectA->xX<VectB->xX?VectA->xX:VectB->xX; VectDest->xY=VectA->xY<VectB->xY?VectA->xY:VectB->xY; }

static inline int MTH2D_M_bEqualVector(const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{ return VectA->xX==VectB->xX && VectA->xY==VectB->xY; }

static inline int MTH2D_M_bIsNullVector(const MTH2D_tdstVector *VectA)
{ return VectA->xX==0.0f && VectA->xY==0.0f; }

static inline void MTH2D_M_vSetBaseIVector(MTH2D_tdstVector *VectDest) { VectDest->xX=1.0f; VectDest->xY=0.0f; }
static inline void MTH2D_M_vSetBaseJVector(MTH2D_tdstVector *VectDest) { VectDest->xX=0.0f; VectDest->xY=1.0f; }

static inline void MTH2D_M_vGetVectorElements(MTH_tdxReal *Vx, MTH_tdxReal *Vy, const MTH2D_tdstVector *VectA)
{ *Vx=VectA->xX; *Vy=VectA->xY; }

static inline void MTH2D_M_vSetVectorElements(MTH2D_tdstVector *VectDest, MTH_tdxReal Vx, MTH_tdxReal Vy)
{ VectDest->xX=Vx; VectDest->xY=Vy; }

static inline void MTH2D_M_vPrintfVector(const char *Name, const MTH2D_tdstVector *VectA)
{ printf("%s = \n |%e", Name, VectA->xX); printf("\n |%e\n", VectA->xY); }

static inline void MTH2D_M_vCopyMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA) { *MatDest = *MatA; }

static inline void MTH2D_M_vFillMatrix(MTH2D_tdstMatrix *MatDest, MTH_tdxReal a)
{ MatDest->stCol_0.xX=a; MatDest->stCol_0.xY=a; MatDest->stCol_1.xX=a; MatDest->stCol_1.xY=a; }

static inline void MTH2D_M_vAddMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA, const MTH2D_tdstMatrix *MatB)
{
    MTH2D_M_vAddVector(&MatDest->stCol_0, &MatA->stCol_0, &MatB->stCol_0);
    MTH2D_M_vAddVector(&MatDest->stCol_1, &MatA->stCol_1, &MatB->stCol_1);
}

static inline void MTH2D_M_vSubMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA, const MTH2D_tdstMatrix *MatB)
{
    MTH2D_M_vSubVector(&MatDest->stCol_0, &MatA->stCol_0, &MatB->stCol_0);
    MTH2D_M_vSubVector(&MatDest->stCol_1, &MatA->stCol_1, &MatB->stCol_1);
}

static inline void MTH2D_M_vNegMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA)
{
    MTH2D_M_vNegVector(&MatDest->stCol_0, &MatA->stCol_0);
    MTH2D_M_vNegVector(&MatDest->stCol_1, &MatA->stCol_1);
}

static inline void MTH2D_M_vMulScalarMatrix(MTH2D_tdstMatrix *MatDest, MTH_tdxReal a, const MTH2D_tdstMatrix *MatA)
{
    MTH2D_M_vMulScalarVector(&MatDest->stCol_0, a, &MatA->stCol_0);
    MTH2D_M_vMulScalarVector(&MatDest->stCol_1, a, &MatA->stCol_1);
}

static inline void MTH2D_M_vDivScalarMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA, MTH_tdxReal a)
{
    MTH2D_M_vDivScalarVector(&MatDest->stCol_0, &MatA->stCol_0, a);
    MTH2D_M_vDivScalarVector(&MatDest->stCol_1, &MatA->stCol_1, a);
}

static inline void MTH2D_M_vMulMatrixMatrixWithoutBuffer(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA, const MTH2D_tdstMatrix *MatB)
{
    MatDest->stCol_0.xX = MatA->stCol_0.xX*MatB->stCol_0.xX + MatA->stCol_1.xX*MatB->stCol_0.xY;
    MatDest->stCol_0.xY = MatA->stCol_0.xY*MatB->stCol_0.xX + MatA->stCol_1.xY*MatB->stCol_0.xY;
    MatDest->stCol_1.xX = MatA->stCol_0.xX*MatB->stCol_1.xX + MatA->stCol_1.xX*MatB->stCol_1.xY;
    MatDest->stCol_1.xY = MatA->stCol_0.xY*MatB->stCol_1.xX + MatA->stCol_1.xY*MatB->stCol_1.xY;
}

static inline void MTH2D_M_vMulMatrixMatrix(MTH2D_tdstMatrix *Mat_Dest, const MTH2D_tdstMatrix *Mat_A, const MTH2D_tdstMatrix *Mat_B)
{
    if (Mat_Dest == Mat_A || Mat_Dest == Mat_B) {
        MTH2D_tdstMatrix Mtemp;
        MTH2D_M_vMulMatrixMatrixWithoutBuffer(&Mtemp, Mat_A, Mat_B);
        MTH2D_M_vCopyMatrix(Mat_Dest, &Mtemp);
    } else {
        MTH2D_M_vMulMatrixMatrixWithoutBuffer(Mat_Dest, Mat_A, Mat_B);
    }
}

static inline void MTH2D_M_vSqrMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA)
{ MTH2D_M_vMulMatrixMatrix(MatDest, MatA, MatA); }

static inline void MTH2D_M_vTranspMatrixWithoutBuffer(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA)
{
    MatDest->stCol_0.xX = MatA->stCol_0.xX;
    MatDest->stCol_0.xY = MatA->stCol_1.xX;
    MatDest->stCol_1.xX = MatA->stCol_0.xY;
    MatDest->stCol_1.xY = MatA->stCol_1.xY;
}

static inline void MTH2D_M_vTranspMatrix(MTH2D_tdstMatrix *Mat_Dest, const MTH2D_tdstMatrix *Mat_A)
{
    if (Mat_Dest == Mat_A) {
        MTH2D_tdstMatrix Mtemp;
        MTH2D_M_vTranspMatrixWithoutBuffer(&Mtemp, Mat_A);
        MTH2D_M_vCopyMatrix(Mat_Dest, &Mtemp);
    } else {
        MTH2D_M_vTranspMatrixWithoutBuffer(Mat_Dest, Mat_A);
    }
}

static inline MTH_tdxReal MTH2D_M_xTraceMatrix(const MTH2D_tdstMatrix *MatA)
{ return MatA->stCol_0.xX + MatA->stCol_1.xY; }

static inline void MTH2D_M_vSetIdentityMatrix(MTH2D_tdstMatrix *MatDest)
{ MatDest->stCol_0.xX=1.0f; MatDest->stCol_0.xY=0.0f; MatDest->stCol_1.xX=0.0f; MatDest->stCol_1.xY=1.0f; }

static inline int MTH2D_M_bEqualMatrix(const MTH2D_tdstMatrix *MatA, const MTH2D_tdstMatrix *MatB)
{
    return MatA->stCol_0.xX==MatB->stCol_0.xX && MatA->stCol_0.xY==MatB->stCol_0.xY &&
           MatA->stCol_1.xX==MatB->stCol_1.xX && MatA->stCol_1.xY==MatB->stCol_1.xY;
}

static inline int MTH2D_M_bMatchMatrix(const MTH2D_tdstMatrix *MatA, const MTH2D_tdstMatrix *MatB, MTH_tdxReal eps)
{
    return MTH_M_xAbs(MatA->stCol_0.xX-MatB->stCol_0.xX)<eps && MTH_M_xAbs(MatA->stCol_0.xY-MatB->stCol_0.xY)<eps &&
           MTH_M_xAbs(MatA->stCol_1.xX-MatB->stCol_1.xX)<eps && MTH_M_xAbs(MatA->stCol_1.xY-MatB->stCol_1.xY)<eps;
}

static inline MTH_tdxReal MTH2D_M_xDetMatrix(const MTH2D_tdstMatrix *MatA)
{ return MatA->stCol_0.xX*MatA->stCol_1.xY - MatA->stCol_0.xY*MatA->stCol_1.xX; }

static inline void MTH2D_M_vInverMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstMatrix *MatA)
{
    MTH2D_tdstMatrix MatTmp;
    MTH_tdxReal det;
    MatTmp.stCol_0.xX =  MatA->stCol_1.xY;
    MatTmp.stCol_0.xY = -(MatA->stCol_0.xY);
    MatTmp.stCol_1.xX = -(MatA->stCol_1.xX);
    MatTmp.stCol_1.xY =  MatA->stCol_0.xX;
    det = MTH2D_M_xDetMatrix(MatA);
    MTH2D_M_vDivScalarMatrix(MatDest, &MatTmp, det);
}

static inline void MTH2D_M_vGetMatrixColumnElements(MTH_tdxReal *Vx, MTH_tdxReal *Vy, int col, const MTH2D_tdstMatrix *MatA)
{
    if (col == 0) { *Vx=MatA->stCol_0.xX; *Vy=MatA->stCol_0.xY; }
    else          { *Vx=MatA->stCol_1.xX; *Vy=MatA->stCol_1.xY; }
}

static inline void MTH2D_M_vSetMatrixColumnElements(MTH2D_tdstMatrix *MatDest, MTH_tdxReal Vx, MTH_tdxReal Vy, int col)
{
    if (col == 0) { MatDest->stCol_0.xX=Vx; MatDest->stCol_0.xY=Vy; }
    else          { MatDest->stCol_1.xX=Vx; MatDest->stCol_1.xY=Vy; }
}

static inline MTH_tdxReal MTH2D_M_xGetMatrixElement(int lin, int col, const MTH2D_tdstMatrix *MatA)
{
    if (col == 0) return lin == 0 ? MatA->stCol_0.xX : MatA->stCol_0.xY;
    else          return lin == 0 ? MatA->stCol_1.xX : MatA->stCol_1.xY;
}

static inline void MTH2D_M_vSetMatrixElement(MTH2D_tdstMatrix *MatDest, MTH_tdxReal a, int lin, int col)
{
    if (col == 0) { if (lin == 0) MatDest->stCol_0.xX=a; else MatDest->stCol_0.xY=a; }
    else          { if (lin == 0) MatDest->stCol_1.xX=a; else MatDest->stCol_1.xY=a; }
}

static inline void MTH2D_M_vGetColumnInMatrix(MTH2D_tdstVector *VectDest, const MTH2D_tdstMatrix *MatA, int col)
{
    if (col == 0) { VectDest->xX=MatA->stCol_0.xX; VectDest->xY=MatA->stCol_0.xY; }
    else          { VectDest->xX=MatA->stCol_1.xX; VectDest->xY=MatA->stCol_1.xY; }
}

static inline void MTH2D_M_vSetColumnInMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstVector *VectA, int col)
{
    if (col == 0) { MatDest->stCol_0.xX=VectA->xX; MatDest->stCol_0.xY=VectA->xY; }
    else          { MatDest->stCol_1.xX=VectA->xX; MatDest->stCol_1.xY=VectA->xY; }
}

static inline void MTH2D_M_vGetLineInMatrix(MTH2D_tdstVector *VectDest, const MTH2D_tdstMatrix *MatA, int lin)
{
    if (lin == 0) { VectDest->xX=MatA->stCol_0.xX; VectDest->xY=MatA->stCol_1.xX; }
    else          { VectDest->xX=MatA->stCol_0.xY; VectDest->xY=MatA->stCol_1.xY; }
}

static inline void MTH2D_M_vSetLineInMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstVector *VectA, int lin)
{
    if (lin == 0) { MatDest->stCol_0.xX=VectA->xX; MatDest->stCol_1.xX=VectA->xY; }
    else          { MatDest->stCol_0.xY=VectA->xX; MatDest->stCol_1.xY=VectA->xY; }
}

static inline void MTH2D_M_vGetDiagInMatrix(MTH2D_tdstVector *VectDest, const MTH2D_tdstMatrix *MatA)
{ VectDest->xX=MatA->stCol_0.xX; VectDest->xY=MatA->stCol_1.xY; }

static inline void MTH2D_M_vSetDiagInMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstVector *VectA)
{ MatDest->stCol_0.xX=VectA->xX; MatDest->stCol_1.xY=VectA->xY; }

static inline void MTH2D_M_vGetVectorsInMatrix(MTH2D_tdstVector *VaDest, MTH2D_tdstVector *VbDest, const MTH2D_tdstMatrix *MatA)
{
    VaDest->xX=MatA->stCol_0.xX; VaDest->xY=MatA->stCol_0.xY;
    VbDest->xX=MatA->stCol_1.xX; VbDest->xY=MatA->stCol_1.xY;
}

static inline void MTH2D_M_vSetVectorsInMatrix(MTH2D_tdstMatrix *MatDest, const MTH2D_tdstVector *VectA, const MTH2D_tdstVector *VectB)
{
    MatDest->stCol_0.xX=VectA->xX; MatDest->stCol_0.xY=VectA->xY;
    MatDest->stCol_1.xX=VectB->xX; MatDest->stCol_1.xY=VectB->xY;
}

static inline void MTH2D_M_vMulMatrixVectorWithoutBuffer(MTH2D_tdstVector *VectDest, const MTH2D_tdstMatrix *MatA, const MTH2D_tdstVector *VectA)
{
    VectDest->xX = MatA->stCol_0.xX*VectA->xX + MatA->stCol_1.xX*VectA->xY;
    VectDest->xY = MatA->stCol_0.xY*VectA->xX + MatA->stCol_1.xY*VectA->xY;
}

static inline void MTH2D_M_vMulMatrixVector(MTH2D_tdstVector *VectDest, const MTH2D_tdstMatrix *MatA, const MTH2D_tdstVector *VectA)
{
    if (VectA == VectDest) {
        MTH2D_tdstVector Vtmp;
        MTH2D_M_vCopyVector(&Vtmp, VectA);
        MTH2D_M_vMulMatrixVectorWithoutBuffer(VectDest, MatA, &Vtmp);
    } else {
        MTH2D_M_vMulMatrixVectorWithoutBuffer(VectDest, MatA, VectA);
    }
}

static inline void MTH2D_M_vPrintfMatrix(const char *Name, const MTH2D_tdstMatrix *MatA)
{
    printf("%s = \n |%e %e|", Name, MatA->stCol_0.xX, MatA->stCol_1.xX);
    printf("\n |%e %e|\n", MatA->stCol_0.xY, MatA->stCol_1.xY);
}

#endif
