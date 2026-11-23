#include "ACP/ACP_types.h"
#include "MTH/MTH3D.h"
#include "POS/POS_types.h"
#include "GEO/GEO_types.h"
#include "GLI/GLI_types.h"
#include "GLI/GLI_globals.h"

/* 0x0048E820 */
ACP_tdxBool INT_fn_bIntersectSegmentWithFaceOfGeometricObject(MTH3D_tdstVector *p_stVertexA,
                                                              MTH3D_tdstVector *p_stVertexB,
                                                              MTH3D_tdstVector *p_stVectAB,
                                                              GEO_tdstGeometricObject *p_stGeomObj,
                                                              ACP_tdxIndex xNbMaxElements,
                                                              ACP_tdxIndex *p_xNbElements,
                                                              GLI_tdstDataOfElement *d_stDataOfElement);

typedef int BOOL;

BOOL PIC_bIntersectSegmentWithGeometricObject(MTH3D_tdstVector *p_stCameraPos,
                                              MTH3D_tdstVector *p_stVertex12,
                                              GEO_tdstGeometricObject *p_stObject ,
                                              GLI_tdstPickedObject *p_stPickedObject)
{

	ACP_tdxIndex xNbElements;
	BOOL bTest,bReturn = FALSE;
	MTH3D_tdstVector stSouris3D;

	MTH3D_M_vAddVector(&stSouris3D, p_stCameraPos, p_stVertex12);

    bTest = INT_fn_bIntersectSegmentWithFaceOfGeometricObject(p_stCameraPos,
		&stSouris3D,
		p_stVertex12,
		p_stObject,
		PIC_C_DepthPickingElements,
		&xNbElements,
		p_stPickedObject->aDEF_stDataOfElement);

    if( bTest )
    {
		MTH3D_tdstVector stTemp;
		ACP_tdxIndex i;

		POS_fn_vMulMatrixVertex(&stTemp, GLI_g_p_stCurrentMatrix, p_stCameraPos);

		for(i=0; i<xNbElements; i++)
		{
			POS_fn_vMulMatrixVertex(&(p_stPickedObject->aDEF_stDataOfElement[i].stHit),
				GLI_g_p_stCurrentMatrix,
				&(p_stPickedObject->aDEF_stDataOfElement[i].stHit));

			p_stPickedObject->aDEF_stDataOfElement[i].xDistance =
				MTH3D_M_xVectorGap(&stTemp, &(p_stPickedObject->aDEF_stDataOfElement[i].stHit));
		}
		p_stPickedObject->xNbElements = xNbElements;
		p_stPickedObject->xModePicking = PIC_C_ModePickingFace;

		bReturn = TRUE;
    }

	return bReturn;
}
