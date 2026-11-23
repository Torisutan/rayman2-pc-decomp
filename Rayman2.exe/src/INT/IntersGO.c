#include "INT/IntersGO.h"
#include "COL/COL_types.h"
#include "GMT/GMT_types.h"
#include "MTH/MTH_flt.h"
#include "MTH/MTH_xNeg.h"
#include "MTH/MTH3D.h"
#include "INT/Inters.h"
#include "COL/Box.h"
#include "COL/CollGOCo.h"
#include "POS/POS_types.h"
#include "GLI/GLI_types.h"
#include "GEO/Element.h"
#include <string.h>

ACP_tdxBool INT_fn_bIntersectSegmentWithTriangle(MTH3D_tdstVector *p_stVertexA, MTH3D_tdstVector *p_stVectAB,
                                                 MTH3D_tdstVector *p_stVertex1, MTH3D_tdstVector *p_stVertex2,
                                                 MTH3D_tdstVector *p_stVertex3, MTH3D_tdstVector *p_stNormal,
                                                 MTH_tdxReal xDPlan, MTH_tdxReal *p_xT,
                                                 MTH3D_tdstVector *p_stHit);                  /* 0x00491250 */
ACP_tdxBool INT_fn_bGetInclusionPointInCone(MTH3D_tdstVector *p_stPoint, MTH3D_tdstVector *p_stTopPoint,
                                            MTH3D_tdstVector *p_stBasePoint, MTH_tdxReal xBaseRadius);  /* 0x00492250 */

void COL_fn_vExploreOctreeWithSegment(COL_tdpstOctree      p_stOctree,
                                      MTH3D_tdstVector    *p_stVertexA,
                                      MTH3D_tdstVector    *p_stVectAB,
                                      COL_tdpstOctreeNode *d_pstSelectedNode,
                                      MTH_tdxReal         *d_xSelectedT,
                                      ACP_tdxIndex        *p_xNumberOfSelectedNodes);

ACP_tdxBool INT_fn_bIntersectSegmentWithBox(MTH3D_tdstVector *p_stVertex1,
                                            MTH3D_tdstVector *p_stVertex2,
                                            MTH3D_tdstVector *p_stVect12,
                                            MTH3D_tdstVector *p_stMinPoint,
                                            MTH3D_tdstVector *p_stMaxPoint,
                                            MTH_tdxReal      *p_xT,
                                            MTH3D_tdstVector *p_stHit,
                                            MTH3D_tdstVector *p_stNormal);

/* 0x004B9C44 */
unsigned long g_xMask = 0;

void INT_fn_vViewAndAddFaceElementInList ( ACP_tdxIndex xNbMaxElements,
                                           ACP_tdxIndex *p_xNbElements,
                                           GLI_tdstDataOfElement *d_stDataOfElement,
                                           MTH3D_tdstVector *p_stVertexA,
                                           ACP_tdxBool bBack,
                                           MTH3D_tdstVector *p_stHit,
                                           ACP_tdxIndex xElements,
                                           ACP_tdxIndex xDataElementIndex )
{
  ACP_tdxIndex xFaceIndex;
  MTH_tdxReal xDistance;

  if ( !(bBack) )
  {
    xDistance = MTH3D_M_xVectorGap ( p_stHit, p_stVertexA );

    xFaceIndex = *p_xNbElements;
    while ( ( 0 < xFaceIndex ) && ( xDistance < d_stDataOfElement[xFaceIndex-1].xDistance ) )
    {
      if ( xFaceIndex < xNbMaxElements )
      {

        memcpy ( &(d_stDataOfElement[xFaceIndex]), &(d_stDataOfElement[xFaceIndex-1]), sizeof ( GLI_tdstDataOfElement ) );
      }
      xFaceIndex--;
    }

    if ( xFaceIndex < xNbMaxElements )
    {

      MTH3D_M_vCopyVector ( &(d_stDataOfElement[xFaceIndex].stHit), p_stHit );
      d_stDataOfElement[xFaceIndex].xDistance = xDistance;
      d_stDataOfElement[xFaceIndex].xElements = xElements;
      d_stDataOfElement[xFaceIndex].xIndexOfFace = xDataElementIndex;
      if ( (*p_xNbElements) < xNbMaxElements )
        (*p_xNbElements)++;
    }
  }
}

ACP_tdxBool INT_fn_bIntersectSegmentWithFaceOfGeometricObject ( MTH3D_tdstVector *p_stVertexA,
                                                                MTH3D_tdstVector *p_stVertexB,
                                                                MTH3D_tdstVector *p_stVectAB,
                                                                GEO_tdstGeometricObject *p_stGeomObj,
                                                                ACP_tdxIndex xNbMaxElements,
                                                                ACP_tdxIndex *p_xNbElements,
                                                                GLI_tdstDataOfElement *d_stDataOfElement )
{
	ACP_tdxIndex                      xElementIndex;
	COL_tdxFaceIndex                  * p_xListIndex;
	GEO_tdstElementIndexedTriangles   * p_stElementIndexedTriangles;
	GEO_tdstElementSpheres            * p_stElementSpheres;
	GEO_tdstElementAlignedBoxes       * p_stElementAlignedBoxes;
	ACP_tdxIndex                      xDataElementIndex;
	ACP_tdxIndex                      xNodeIndex;
	COL_tdxFaceIndex                  xIndex;
	MTH3D_tdstVector                  *p_stVertex1;
	MTH3D_tdstVector                  *p_stVertex2;
	MTH3D_tdstVector                  *p_stVertex3;
	MTH3D_tdstVector                  *p_stNormal;
	MTH_tdxReal xDPlan;
	GEO_tdstIndexedSphere             *p_stIndexedSphere;
	GEO_tdstIndexedAlignedBox         *p_stIndexedAlignedBox;
	MTH3D_tdstVector                  *p_stCenter;
	MTH3D_tdstVector                  *p_stMinPoint;
	MTH3D_tdstVector                  *p_stMaxPoint;
	MTH3D_tdstVector                  stNormal;

	ACP_tdxBool bBack = FALSE;
	MTH_tdxReal xT;
	MTH3D_tdstVector stHit;

	ACP_tdxIndex					xNumberOfSelectedNodes;
	COL_tdpstOctreeNode				aDEF_pstSelectedNode[COL_C_xMaxSelectedNodes];
	MTH_tdxReal						aDEF_xSelectedT[COL_C_xMaxSelectedNodes];
	ACP_tdxIndex					xNbElements;
	GMT_tdxHandleToGameMaterial		hMaterial = NULL;
	GMT_tdxHandleToCollideMaterial	hCM = NULL;

	*p_xNbElements = 0;

	if ( p_stGeomObj->p_stOctree == NULL )
	{

		for ( xElementIndex = 0 ; xElementIndex < p_stGeomObj->xNbElements ; xElementIndex++ )
		{
			switch ( p_stGeomObj->d_xListOfElementsTypes[xElementIndex] )
			{
			case GEO_C_xElementIndexedTriangles :
				if ( g_xMask != 0 )
				{
					GEO_vGetGameMaterialOfIndexedTriangles( p_stGeomObj, xElementIndex, &hMaterial );
					if ( hMaterial != NULL )
					{
						hCM = GMT_fn_hGetCollideMaterial( hMaterial );
						if (hCM != GMT_C_InvalidCollideMaterial)
						{

							if ((GMT_fn_hGetCollideMaterialIdentifier( hCM ) & g_xMask ) == 0x0000 )
								break;
						}
						else
							break;
					}
					else
						break;
				}

				p_stElementIndexedTriangles = (GEO_tdstElementIndexedTriangles *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

				for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementIndexedTriangles->xNbFaces ; xDataElementIndex++ )
				{

					p_stVertex1 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[0];
					p_stVertex2 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[1];
					p_stVertex3 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[2];

					p_stNormal = p_stElementIndexedTriangles->d_stListOfFacesNormals + xDataElementIndex;

					xDPlan = MTH_M_xNeg ( MTH3D_M_xDotProductVector ( p_stNormal, p_stVertex1 ) );

					if
						(
						INT_fn_bIntersectSegmentWithTriangle ( p_stVertexA, p_stVectAB,
						p_stVertex1, p_stVertex2, p_stVertex3,
						p_stNormal, xDPlan, &xT, &stHit )
						)
					{
						INT_fn_vViewAndAddFaceElementInList ( xNbMaxElements, p_xNbElements, d_stDataOfElement,
							p_stVertexA, bBack, &stHit, xElementIndex, xDataElementIndex );
					}
				}
				break;

			case GEO_C_xElementSpheres :
				p_stElementSpheres = (GEO_tdstElementSpheres *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

				for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementSpheres->xNbSpheres ; xDataElementIndex++ )
				{

					p_stIndexedSphere = p_stElementSpheres->d_stListOfSpheres + xDataElementIndex;

					p_stCenter = p_stGeomObj->d_stListOfPoints + p_stIndexedSphere->xCenterPoint;

					if
						(
						INT_fn_bIntersectSegmentWithSphere ( p_stVertexA, p_stVectAB,
						p_stCenter, p_stIndexedSphere->xRadius,
						&xT, &stHit, &stNormal )
						)
					{
						INT_fn_vViewAndAddFaceElementInList ( xNbMaxElements, p_xNbElements, d_stDataOfElement,
							p_stVertexA, bBack, &stHit, xElementIndex, xDataElementIndex );
					}
				}
				break;

			case GEO_C_xElementAlignedBoxes :
				p_stElementAlignedBoxes = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

				for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementAlignedBoxes->xNbAlignedBoxes ; xDataElementIndex++ )
				{

					p_stIndexedAlignedBox = p_stElementAlignedBoxes->d_stListOfAlignedBoxes + xDataElementIndex;

					p_stMinPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMinPoint;
					p_stMaxPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMaxPoint;

					if
						(
						INT_fn_bIntersectSegmentWithBox ( p_stVertexA, p_stVertexB, p_stVectAB,
						p_stMinPoint, p_stMaxPoint,
						&xT, &stHit, &stNormal )
						)
					{
						INT_fn_vViewAndAddFaceElementInList ( xNbMaxElements, p_xNbElements, d_stDataOfElement,
							p_stVertexA, bBack, &stHit, xElementIndex, xDataElementIndex );
					}
				}
				break;

			default :
				break;
			}
		}
	}
	else
	{
		COL_fn_vExploreOctreeWithSegment ( p_stGeomObj->p_stOctree, p_stVertexA, p_stVectAB,
			aDEF_pstSelectedNode, aDEF_xSelectedT, &xNumberOfSelectedNodes );

		COL_g_lFacesTagCounter++;

		for ( xNodeIndex = 0 ; xNodeIndex < xNumberOfSelectedNodes ; xNodeIndex++ )
		{
			xNbElements  = *((COL_tdxFaceIndexDouble*)aDEF_pstSelectedNode[xNodeIndex]->d_xFaceIndexList);
			p_xListIndex = (COL_tdxFaceIndex*)(((COL_tdxFaceIndexDouble*)aDEF_pstSelectedNode[xNodeIndex]->d_xFaceIndexList)+1);

			for ( xIndex = 0 ; xIndex < xNbElements ; xIndex++ )
			{
				if ((*p_xListIndex) < COL_C_MaxIndex)
					xElementIndex = (ACP_tdxIndex) (*(p_xListIndex ++));
				else
				{
					ACP_tdxIndex xData;

					xData = (ACP_tdxIndex)(*(p_xListIndex ++));
					xData <<= 8;
					xData += (ACP_tdxIndex)(*(p_xListIndex ++));
					xData &= ~COL_C_OverflowIndex;
					xElementIndex = xData;
				}

				if ((*p_xListIndex) < COL_C_MaxIndex)
					xDataElementIndex = (ACP_tdxIndex) (*(p_xListIndex ++));
				else
				{
					ACP_tdxIndex xData;

					xData = (ACP_tdxIndex)(*(p_xListIndex ++));
					xData <<= 8;
					xData += (ACP_tdxIndex)(*(p_xListIndex ++));
					xData &= ~COL_C_OverflowIndex;
					xDataElementIndex = xData;
				}

				if
					(
					COL_g_d_lTaggedFacesTable[(p_stGeomObj->p_stOctree)->d_xElementBasesTable[xElementIndex] + xDataElementIndex]
					!= COL_g_lFacesTagCounter
					)
				{
					switch ( p_stGeomObj->d_xListOfElementsTypes[xElementIndex] )
					{
					case GEO_C_xElementIndexedTriangles :
						if (g_xMask != 0)
						{
							GEO_vGetGameMaterialOfIndexedTriangles( p_stGeomObj, xElementIndex, &hMaterial );
							if ( hMaterial != NULL)
							{
								hCM = GMT_fn_hGetCollideMaterial( hMaterial );
								if (hCM != GMT_C_InvalidCollideMaterial)
								{

									if ((GMT_fn_hGetCollideMaterialIdentifier( hCM ) & g_xMask ) == 0x0000 )
										break;
								}
								else
									break;
							}
							else
								break;
						}
						p_stElementIndexedTriangles = (GEO_tdstElementIndexedTriangles *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

						p_stVertex1 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[0];
						p_stVertex2 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[1];
						p_stVertex3 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[2];

						p_stNormal = p_stElementIndexedTriangles->d_stListOfFacesNormals + xDataElementIndex;

						xDPlan = MTH_M_xNeg ( MTH3D_M_xDotProductVector ( p_stNormal, p_stVertex1 ) );

						if
							(
							INT_fn_bIntersectSegmentWithTriangle ( p_stVertexA, p_stVectAB,
							p_stVertex1, p_stVertex2, p_stVertex3,
							p_stNormal, xDPlan, &xT, &stHit )
							)
						{
							INT_fn_vViewAndAddFaceElementInList ( xNbMaxElements, p_xNbElements, d_stDataOfElement,
								p_stVertexA, bBack, &stHit, xElementIndex, xDataElementIndex );
						}
						break;

					case GEO_C_xElementSpheres :
						p_stElementSpheres = (GEO_tdstElementSpheres *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

						p_stIndexedSphere = p_stElementSpheres->d_stListOfSpheres + xDataElementIndex;

						p_stCenter = p_stGeomObj->d_stListOfPoints + p_stIndexedSphere->xCenterPoint;

						if
							(
							INT_fn_bIntersectSegmentWithSphere ( p_stVertexA, p_stVectAB,
							p_stCenter, p_stIndexedSphere->xRadius,
							&xT, &stHit, &stNormal )
							)
						{
							INT_fn_vViewAndAddFaceElementInList ( xNbMaxElements, p_xNbElements, d_stDataOfElement,
								p_stVertexA, bBack, &stHit, xElementIndex, xDataElementIndex );
						}
						break;

					case GEO_C_xElementAlignedBoxes :
						p_stElementAlignedBoxes = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

						p_stIndexedAlignedBox = p_stElementAlignedBoxes->d_stListOfAlignedBoxes + xDataElementIndex;

						p_stMinPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMinPoint;
						p_stMaxPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMaxPoint;

						if
							(
							INT_fn_bIntersectSegmentWithBox ( p_stVertexA, p_stVertexB, p_stVectAB,
							p_stMinPoint, p_stMaxPoint,
							&xT, &stHit, &stNormal )
							)
						{
							INT_fn_vViewAndAddFaceElementInList ( xNbMaxElements, p_xNbElements, d_stDataOfElement,
								p_stVertexA, bBack, &stHit, xElementIndex, xDataElementIndex );
						}
						break;

					default :
						break;
					}

					COL_g_d_lTaggedFacesTable[(p_stGeomObj->p_stOctree)->d_xElementBasesTable[xElementIndex] + xDataElementIndex]
						= COL_g_lFacesTagCounter;
				}
			}
		}
	}

	return (*p_xNbElements) > 0;
}

ACP_tdxBool INT_fn_bDetectIntersectSegmentWithFaceOfGeometricObject
(
    MTH3D_tdstVector        *p_stVertexA,
    MTH3D_tdstVector        *p_stVectAB,
    GEO_tdstGeometricObject *p_stGeomObj
)
{
    ACP_tdxIndex                          xElementIndex;
    ACP_tdxIndex                          xDataElementIndex;
    GEO_tdstElementIndexedTriangles      *p_stElementIndexedTriangles;
    GEO_tdstElementSpheres               *p_stElementSpheres;
    GEO_tdstElementAlignedBoxes          *p_stElementAlignedBoxes;

    MTH3D_tdstVector                     *p_stVertex1;
    MTH3D_tdstVector                     *p_stVertex2;
    MTH3D_tdstVector                     *p_stVertex3;
    MTH3D_tdstVector                     *p_stNormal;
    MTH_tdxReal                           xDPlan;
    GEO_tdstIndexedSphere                *p_stIndexedSphere;
    GEO_tdstIndexedAlignedBox            *p_stIndexedAlignedBox;
    MTH3D_tdstVector                     *p_stCenter;
    MTH3D_tdstVector                     *p_stMinPoint;
    MTH3D_tdstVector                     *p_stMaxPoint;

    COL_tdxFaceIndex                     *p_xListIndex;
    ACP_tdxIndex                          xNodeIndex;
    COL_tdxFaceIndex                      xIndex;
    ACP_tdxIndex                          xNumberOfSelectedNodes;
    COL_tdpstOctreeNode                   aDEF_pstSelectedNode[COL_C_xMaxSelectedNodes];
    MTH_tdxReal                           aDEF_xSelectedT[COL_C_xMaxSelectedNodes];
    GMT_tdxHandleToCollideMaterial        hCollidedCollideMaterial;
    ACP_tdxIndex                          xNbElements;

    if ( p_stGeomObj->p_stOctree == (COL_tdpstOctree)0 )
    {

        for ( xElementIndex = 0 ; xElementIndex < p_stGeomObj->xNbElements ; xElementIndex++ )
        {
            switch ( p_stGeomObj->d_xListOfElementsTypes[xElementIndex] )
            {
            case GEO_C_xElementIndexedTriangles :

                p_stElementIndexedTriangles = (GEO_tdstElementIndexedTriangles *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

                hCollidedCollideMaterial = GMT_fn_hGetCollideMaterial(p_stElementIndexedTriangles->hMaterial);
                if
                (
                    (hCollidedCollideMaterial != GMT_C_InvalidCollideMaterial)
                &&  (GMT_fn_hGetCollideMaterialIdentifier(hCollidedCollideMaterial) & 0xC000)
                )
                    break;

                for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementIndexedTriangles->xNbFaces ; xDataElementIndex++ )
                {

                    p_stVertex1 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[0];
                    p_stVertex2 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[1];
                    p_stVertex3 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[2];

                    p_stNormal = p_stElementIndexedTriangles->d_stListOfFacesNormals + xDataElementIndex;

                    xDPlan = MTH_M_xNeg ( MTH3D_M_xDotProductVector ( p_stNormal, p_stVertex1 ) );

                    if
                    (
                        INT_fn_bDetectIntersectSegmentWithTriangle ( p_stVertexA, p_stVectAB,
                        p_stVertex1, p_stVertex2, p_stVertex3,
                        p_stNormal, xDPlan )
                    )
                    {
                        return TRUE;
                    }
                }
                break;

            case GEO_C_xElementSpheres :

                p_stElementSpheres = (GEO_tdstElementSpheres *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

                for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementSpheres->xNbSpheres ; xDataElementIndex++ )
                {

                    p_stIndexedSphere = p_stElementSpheres->d_stListOfSpheres + xDataElementIndex;

                    hCollidedCollideMaterial = GMT_fn_hGetCollideMaterial(p_stIndexedSphere->hMaterial);
                    if
                    (
                        (hCollidedCollideMaterial != GMT_C_InvalidCollideMaterial)
                    &&  (GMT_fn_hGetCollideMaterialIdentifier(hCollidedCollideMaterial) & 0xC000)
                    )
                        continue;

                    p_stCenter = p_stGeomObj->d_stListOfPoints + p_stIndexedSphere->xCenterPoint;

                    if
                    (
                        INT_fn_bDetectIntersectSegmentWithSphere
                        (
                            p_stVertexA,
                            p_stVectAB,
                            p_stCenter,
                            p_stIndexedSphere->xRadius
                        )
                    )
                    {
                        return TRUE;
                    }
                }
                break;

            case GEO_C_xElementAlignedBoxes :
                p_stElementAlignedBoxes = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

                for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementAlignedBoxes->xNbAlignedBoxes ; xDataElementIndex++ )
                {

                    p_stIndexedAlignedBox = p_stElementAlignedBoxes->d_stListOfAlignedBoxes + xDataElementIndex;

                    hCollidedCollideMaterial = GMT_fn_hGetCollideMaterial(p_stIndexedAlignedBox->hMaterial);
                    if
                    (
                        (hCollidedCollideMaterial != GMT_C_InvalidCollideMaterial)
                    &&  (GMT_fn_hGetCollideMaterialIdentifier(hCollidedCollideMaterial) & 0xC000)
                    )
                        continue;

                    p_stMinPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMinPoint;
                    p_stMaxPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMaxPoint;

                    if
                    (
                        INT_fn_bDetectIntersectSegmentWithBox ( p_stVertexA, p_stVectAB,
                        p_stMinPoint, p_stMaxPoint, (MTH_tdxReal *)0 )
                    )
                    {
                        return TRUE;
                    }
                }
                break;

            default :
                break;
            }
        }
    }
    else
    {
        COL_fn_vExploreOctreeWithSegment ( p_stGeomObj->p_stOctree, p_stVertexA, p_stVectAB,
            aDEF_pstSelectedNode, aDEF_xSelectedT, &xNumberOfSelectedNodes );

        COL_g_lFacesTagCounter++;

        for ( xNodeIndex = 0 ; xNodeIndex < xNumberOfSelectedNodes ; xNodeIndex++ )
        {
            xNbElements  = (ACP_tdxIndex)*((COL_tdxFaceIndexDouble *)aDEF_pstSelectedNode[xNodeIndex]->d_xFaceIndexList);
            p_xListIndex = (COL_tdxFaceIndex *)(((COL_tdxFaceIndexDouble *)aDEF_pstSelectedNode[xNodeIndex]->d_xFaceIndexList) + 1);

            for ( xIndex = 0 ; xIndex < (COL_tdxFaceIndex)xNbElements ; xIndex++ )
            {
                if ((*p_xListIndex) < COL_C_MaxIndex)
                    xElementIndex = (ACP_tdxIndex)(*(p_xListIndex++));
                else
                {
                    ACP_tdxIndex xData;

                    xData = (ACP_tdxIndex)(*(p_xListIndex++));
                    xData <<= 8;
                    xData += (ACP_tdxIndex)(*(p_xListIndex++));
                    xData &= (ACP_tdxIndex)(~COL_C_OverflowIndex);
                    xElementIndex = xData;
                }

                if ((*p_xListIndex) < COL_C_MaxIndex)
                    xDataElementIndex = (ACP_tdxIndex)(*(p_xListIndex++));
                else
                {
                    ACP_tdxIndex xData;

                    xData = (ACP_tdxIndex)(*(p_xListIndex++));
                    xData <<= 8;
                    xData += (ACP_tdxIndex)(*(p_xListIndex++));
                    xData &= (ACP_tdxIndex)(~COL_C_OverflowIndex);
                    xDataElementIndex = xData;
                }

                if
                (
                    COL_g_d_lTaggedFacesTable[p_stGeomObj->p_stOctree->d_xElementBasesTable[xElementIndex] + xDataElementIndex]
                    != COL_g_lFacesTagCounter
                )
                {
                    switch ( p_stGeomObj->d_xListOfElementsTypes[xElementIndex] )
                    {
                    case GEO_C_xElementIndexedTriangles :

                        p_stElementIndexedTriangles = (GEO_tdstElementIndexedTriangles *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

                        hCollidedCollideMaterial = GMT_fn_hGetCollideMaterial(p_stElementIndexedTriangles->hMaterial);
                        if
                        (
                            (hCollidedCollideMaterial != GMT_C_InvalidCollideMaterial)
                        &&  (GMT_fn_hGetCollideMaterialIdentifier(hCollidedCollideMaterial) & 0xC000)
                        )
                            break;

                        p_stVertex1 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[0];
                        p_stVertex2 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[1];
                        p_stVertex3 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[2];

                        p_stNormal = p_stElementIndexedTriangles->d_stListOfFacesNormals + xDataElementIndex;

                        xDPlan = MTH_M_xNeg ( MTH3D_M_xDotProductVector ( p_stNormal, p_stVertex1 ) );

                        if
                        (
                            INT_fn_bDetectIntersectSegmentWithTriangle ( p_stVertexA, p_stVectAB,
                            p_stVertex1, p_stVertex2, p_stVertex3,
                            p_stNormal, xDPlan )
                        )
                        {
                            return TRUE;
                        }
                        break;

                    case GEO_C_xElementSpheres :
                        p_stElementSpheres = (GEO_tdstElementSpheres *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

                        p_stIndexedSphere = p_stElementSpheres->d_stListOfSpheres + xDataElementIndex;

                        hCollidedCollideMaterial = GMT_fn_hGetCollideMaterial(p_stIndexedSphere->hMaterial);
                        if
                        (
                            (hCollidedCollideMaterial != GMT_C_InvalidCollideMaterial)
                        &&  (GMT_fn_hGetCollideMaterialIdentifier(hCollidedCollideMaterial) & 0xC000)
                        )
                            break;

                        p_stCenter = p_stGeomObj->d_stListOfPoints + p_stIndexedSphere->xCenterPoint;

                        if
                        (
                            INT_fn_bDetectIntersectSegmentWithSphere ( p_stVertexA, p_stVectAB,
                            p_stCenter, p_stIndexedSphere->xRadius )
                        )
                        {
                            return TRUE;
                        }
                        break;

                    case GEO_C_xElementAlignedBoxes :
                        p_stElementAlignedBoxes = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

                        p_stIndexedAlignedBox = p_stElementAlignedBoxes->d_stListOfAlignedBoxes + xDataElementIndex;

                        hCollidedCollideMaterial = GMT_fn_hGetCollideMaterial(p_stIndexedAlignedBox->hMaterial);
                        if
                        (
                            (hCollidedCollideMaterial != GMT_C_InvalidCollideMaterial)
                        &&  (GMT_fn_hGetCollideMaterialIdentifier(hCollidedCollideMaterial) & 0xC000)
                        )
                            break;

                        p_stMinPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMinPoint;
                        p_stMaxPoint = p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMaxPoint;

                        if
                        (
                            INT_fn_bDetectIntersectSegmentWithBox ( p_stVertexA, p_stVectAB,
                            p_stMinPoint, p_stMaxPoint, (MTH_tdxReal *)0 )
                        )
                        {
                            return TRUE;
                        }
                        break;

                    default :
                        break;
                    }

                    COL_g_d_lTaggedFacesTable[p_stGeomObj->p_stOctree->d_xElementBasesTable[xElementIndex] + xDataElementIndex]
                        = COL_g_lFacesTagCounter;
                }
            }
        }
    }

    return FALSE;
}

ACP_tdxBool INT_fn_bGetInclusionPointInGeometricObject ( MTH3D_tdstVector *p_stPoint,
                                                         GEO_tdstGeometricObject *p_stGeomObj )
{
  ACP_tdxIndex                    xElementIndex;
  ACP_tdxIndex                    xDataElementIndex;

  GEO_tdstElementIndexedTriangles *p_stElementIndexedTriangles;
  GEO_tdstElementSpheres          *p_stElementSpheres;
  GEO_tdstElementAlignedBoxes     *p_stElementAlignedBoxes;
  GEO_tdstElementCones            *p_stElementCones;

  GEO_tdstIndexedSphere           *p_stIndexedSphere;
  GEO_tdstIndexedAlignedBox       *p_stIndexedAlignedBox;
  GEO_tdstIndexedCone             *p_stIndexedCone;

  MTH3D_tdstVector                *p_stVertex1;
  MTH3D_tdstVector                *p_stVertex2;
  MTH3D_tdstVector                *p_stVertex3;
  MTH3D_tdstVector                *p_stNormal;
  MTH_tdxReal                     xDPlan;

  MTH_tdxReal                     xT;
  MTH3D_tdstVector                stHit;

  MTH3D_tdstVector stZNormal = { MTH_C_ZERO, MTH_C_ZERO, MTH_C_ONE };

  ACP_tdxIndex xNbIntersect;

  for ( xElementIndex = 0 ; xElementIndex < p_stGeomObj->xNbElements ; xElementIndex++ )
  {
    switch ( p_stGeomObj->d_xListOfElementsTypes[xElementIndex] )
    {
      case GEO_C_xElementIndexedTriangles :
        p_stElementIndexedTriangles = (GEO_tdstElementIndexedTriangles *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

        xNbIntersect = 0;

        for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementIndexedTriangles->xNbFaces ; xDataElementIndex++ )
        {

          p_stVertex1 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[0];
          p_stVertex2 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[1];
          p_stVertex3 = p_stGeomObj->d_stListOfPoints + (p_stElementIndexedTriangles->d_stListOfFacesTripled + xDataElementIndex)->a3_xIndex[2];

          p_stNormal = p_stElementIndexedTriangles->d_stListOfFacesNormals + xDataElementIndex;

          xDPlan = MTH_M_xNeg ( MTH3D_M_xDotProductVector ( p_stNormal, p_stVertex1 ) );

          if
            (
              INT_fn_bIntersectSegmentWithTriangle ( p_stPoint, &stZNormal,
                                                     p_stVertex1, p_stVertex2, p_stVertex3,
                                                     p_stNormal, xDPlan, &xT, &stHit )
            )
          {
            xNbIntersect ++;
          }
        }

        if ( (xNbIntersect % 2) != 0 )
        {
          return TRUE;
        }
      break;

      case GEO_C_xElementSpheres :
        p_stElementSpheres = (GEO_tdstElementSpheres *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

        for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementSpheres->xNbSpheres ; xDataElementIndex++ )
        {

          p_stIndexedSphere = p_stElementSpheres->d_stListOfSpheres + xDataElementIndex;

          if ( INT_fn_bGetInclusionPointInSphere ( p_stPoint, p_stGeomObj->d_stListOfPoints + p_stIndexedSphere->xCenterPoint,
                                                   p_stIndexedSphere->xRadius ) )
          {
            return TRUE;
          }
        }
      break;

      case GEO_C_xElementAlignedBoxes :
        p_stElementAlignedBoxes = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

        for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementAlignedBoxes->xNbAlignedBoxes ; xDataElementIndex++ )
        {

          p_stIndexedAlignedBox = p_stElementAlignedBoxes->d_stListOfAlignedBoxes + xDataElementIndex;

          if ( INT_fn_bGetInclusionPointInBox ( p_stPoint, p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMinPoint,
                                                p_stGeomObj->d_stListOfPoints + p_stIndexedAlignedBox->xMaxPoint ) )
          {
            return TRUE;
          }
        }
      break;

      case GEO_C_xElementCones :
        p_stElementCones = (GEO_tdstElementCones *)(p_stGeomObj->d_stListOfElements[xElementIndex]);

        for ( xDataElementIndex = 0 ; xDataElementIndex < p_stElementCones->xNbCones ; xDataElementIndex++ )
        {

          p_stIndexedCone = p_stElementCones->d_stListOfCones + xDataElementIndex;

          if ( INT_fn_bGetInclusionPointInCone ( p_stPoint, p_stGeomObj->d_stListOfPoints + p_stIndexedCone->xTopPoint,
                                                 p_stGeomObj->d_stListOfPoints + p_stIndexedCone->xBasePoint,
                                                 p_stIndexedCone->xBaseRadius ) )
          {
            return TRUE;
          }
        }
      break;

      default :
      break;
    }
  }

  return FALSE;
}

void COL_fn_vMinMaxBox2VerticesBox ( COL_tda8st8VerticesBox a8_stBoxDest,
                                     MTH3D_tdstVector *p_stMinPoint,
                                     MTH3D_tdstVector *p_stMaxPoint );

ACP_tdxBool INT_fn_bDetectIntersectGeomObjWithGeomObj ( GEO_tdstGeometricObject *p_stGeomObj1,
                                                        POS_tdstCompletePosition *_p_stMatrix1,
                                                        GEO_tdstGeometricObject *p_stGeomObj2,
                                                        POS_tdstCompletePosition *_p_stMatrix2,
                                                        GMT_tdxHandleToGameMaterial *_p_hMat1,
                                                        GMT_tdxHandleToGameMaterial *_p_hMat2 )
{
  POS_tdstCompletePosition stInvMatrix2;
  POS_tdstCompletePosition st12TransformMatrix;
  POS_tdstCompletePosition st21TransformMatrix;
  MTH_tdxReal xScale1;
  MTH_tdxReal xScale2;

  ACP_tdxIndex xElementIndex1;
  ACP_tdxIndex xDataElementIndex1;
  GEO_tdstElementSpheres *p_stElementSpheres1;
  GEO_tdstElementAlignedBoxes *p_stElementAlignedBoxes1;
  GEO_tdstIndexedSphere *p_stIndexedSphere1;
  GEO_tdstIndexedAlignedBox *p_stIndexedAlignedBox1;
  ACP_tdxIndex xElementIndex2;
  ACP_tdxIndex xDataElementIndex2;
  GEO_tdstElementSpheres *p_stElementSpheres2;
  GEO_tdstElementAlignedBoxes *p_stElementAlignedBoxes2;
  GEO_tdstIndexedSphere *p_stIndexedSphere2;
  GEO_tdstIndexedAlignedBox *p_stIndexedAlignedBox2;

  MTH3D_tdstVector stCenter1in2;
  MTH3D_tdstVector stCenter2in1;
  MTH3D_tdstVector stCenter1 , stCenter2;

  COL_tda8st8VerticesBox a8_st8VBox2;
  COL_tda8st8VerticesBox a8_st8VBox2in1;
  COL_tda8st8VerticesBox a8_st8VBox1;
  COL_tda8st8VerticesBox a8_st8VBox1in2;
  MTH3D_tdstVector stEdgeVector;
  ACP_tdxIndex xVertexIndex;
  ACP_tdxIndex xEdgeIndex;

  xScale1 = POS_fn_xGetMaxScale ( _p_stMatrix1 );
  xScale2 = POS_fn_xGetMaxScale ( _p_stMatrix2 );

  for ( xElementIndex1 = 0 ; xElementIndex1 < p_stGeomObj1->xNbElements ; xElementIndex1++ )
  {
    switch ( p_stGeomObj1->d_xListOfElementsTypes[xElementIndex1] )
    {
      case GEO_C_xElementSpheres :
        p_stElementSpheres1 = (GEO_tdstElementSpheres *)(p_stGeomObj1->d_stListOfElements[xElementIndex1]);

        for ( xDataElementIndex1 = 0 ; xDataElementIndex1 < p_stElementSpheres1->xNbSpheres ; xDataElementIndex1++ )
        {

          p_stIndexedSphere1 = p_stElementSpheres1->d_stListOfSpheres + xDataElementIndex1;

          POS_fn_vMulMatrixVertex (& stCenter1 , _p_stMatrix1 , p_stGeomObj1 -> d_stListOfPoints + p_stIndexedSphere1 -> xCenterPoint);

          for ( xElementIndex2 = 0 ; xElementIndex2 < p_stGeomObj2->xNbElements ; xElementIndex2++ )
          {
            switch ( p_stGeomObj2->d_xListOfElementsTypes[xElementIndex2] )
            {
              case GEO_C_xElementSpheres :
                p_stElementSpheres2 = (GEO_tdstElementSpheres *)(p_stGeomObj2->d_stListOfElements[xElementIndex2]);

                for ( xDataElementIndex2 = 0 ; xDataElementIndex2 < p_stElementSpheres2->xNbSpheres ; xDataElementIndex2++ )
                {

                  p_stIndexedSphere2 = p_stElementSpheres2->d_stListOfSpheres + xDataElementIndex2;

                  POS_fn_vMulMatrixVertex (& stCenter2 , _p_stMatrix2 , p_stGeomObj2 -> d_stListOfPoints + p_stIndexedSphere2 -> xCenterPoint);

                  if (INT_fn_bIntersectSphereWithSphere (& stCenter1 , MTH_M_xMul (p_stIndexedSphere1 -> xRadius , xScale1) ,
                                                         & stCenter2 , MTH_M_xMul (p_stIndexedSphere2 -> xRadius , xScale2)))
                  {
                    *_p_hMat1 = p_stIndexedSphere1->hMaterial;
                    *_p_hMat2 = p_stIndexedSphere2->hMaterial;
                    return TRUE;
                  }
                }
              break;

              case GEO_C_xElementAlignedBoxes :
               {

                POS_fn_vInvertMatrix( &stInvMatrix2, _p_stMatrix2 );

                POS_fn_vMulMatrixMatrix( &st12TransformMatrix, &stInvMatrix2, _p_stMatrix1 );

                POS_fn_vMulMatrixVertex ( &stCenter1in2, &st12TransformMatrix, p_stGeomObj1->d_stListOfPoints + p_stIndexedSphere1->xCenterPoint );

                p_stElementAlignedBoxes2 = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj2->d_stListOfElements[xElementIndex2]);

                for ( xDataElementIndex2 = 0 ; xDataElementIndex2 < p_stElementAlignedBoxes2->xNbAlignedBoxes ; xDataElementIndex2++ )
                {

                  p_stIndexedAlignedBox2 = p_stElementAlignedBoxes2->d_stListOfAlignedBoxes + xDataElementIndex2;

                  if (INT_fn_bIntersectSphereWithBox ( &stCenter1in2, MTH_M_xDiv ( MTH_M_xMul ( p_stIndexedSphere1->xRadius, xScale1 ), xScale2 ),
                                                       p_stGeomObj2->d_stListOfPoints + p_stIndexedAlignedBox2->xMinPoint,
                                                       p_stGeomObj2->d_stListOfPoints + p_stIndexedAlignedBox2->xMaxPoint ) )
                  {
                    *_p_hMat1 = p_stIndexedSphere1->hMaterial;
                    *_p_hMat2 = p_stIndexedAlignedBox2->hMaterial;
                    return TRUE;
                  }
                }
               }
              break;

              default :
              break;
            }
          }
        }
      break;

      case GEO_C_xElementAlignedBoxes :
       {

        POS_fn_vInvertMatrix( &stInvMatrix2, _p_stMatrix2 );

        POS_fn_vMulMatrixMatrix( &st12TransformMatrix, &stInvMatrix2, _p_stMatrix1 );

        POS_fn_vInvertMatrix( &st21TransformMatrix, &st12TransformMatrix );

        p_stElementAlignedBoxes1 = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj1->d_stListOfElements[xElementIndex1]);

        for ( xDataElementIndex1 = 0 ; xDataElementIndex1 < p_stElementAlignedBoxes1->xNbAlignedBoxes ; xDataElementIndex1++ )
        {

          p_stIndexedAlignedBox1 = p_stElementAlignedBoxes1->d_stListOfAlignedBoxes + xDataElementIndex1;

          for ( xElementIndex2 = 0 ; xElementIndex2 < p_stGeomObj2->xNbElements ; xElementIndex2++ )
          {
            switch ( p_stGeomObj2->d_xListOfElementsTypes[xElementIndex2] )
            {
              case GEO_C_xElementSpheres :
                p_stElementSpheres2 = (GEO_tdstElementSpheres *)(p_stGeomObj2->d_stListOfElements[xElementIndex2]);

                for ( xDataElementIndex2 = 0 ; xDataElementIndex2 < p_stElementSpheres2->xNbSpheres ; xDataElementIndex2++ )
                {

                  p_stIndexedSphere2 = p_stElementSpheres2->d_stListOfSpheres + xDataElementIndex2;

                  POS_fn_vMulMatrixVertex ( &stCenter2in1, &st21TransformMatrix, p_stGeomObj2->d_stListOfPoints + p_stIndexedSphere2->xCenterPoint );

                  if (INT_fn_bIntersectSphereWithBox ( &stCenter2in1, MTH_M_xDiv ( MTH_M_xMul ( p_stIndexedSphere2->xRadius, xScale2 ), xScale1 ),
                                                       p_stGeomObj1->d_stListOfPoints + p_stIndexedAlignedBox1->xMinPoint,
                                                       p_stGeomObj1->d_stListOfPoints + p_stIndexedAlignedBox1->xMaxPoint ) )
                  {
                    *_p_hMat1 = p_stIndexedAlignedBox1->hMaterial;
                    *_p_hMat2 = p_stIndexedSphere2->hMaterial;
                    return TRUE;
                  }
                }
              break;

              case GEO_C_xElementAlignedBoxes :
                p_stElementAlignedBoxes2 = (GEO_tdstElementAlignedBoxes *)(p_stGeomObj2->d_stListOfElements[xElementIndex2]);

                for ( xDataElementIndex2 = 0 ; xDataElementIndex2 < p_stElementAlignedBoxes2->xNbAlignedBoxes ; xDataElementIndex2++ )
                {

                  p_stIndexedAlignedBox2 = p_stElementAlignedBoxes2->d_stListOfAlignedBoxes + xDataElementIndex2;

                  COL_fn_vMinMaxBox2VerticesBox ( a8_st8VBox2, p_stGeomObj2->d_stListOfPoints + p_stIndexedAlignedBox2->xMinPoint,
                                                               p_stGeomObj2->d_stListOfPoints + p_stIndexedAlignedBox2->xMaxPoint );

                  for ( xVertexIndex = 0 ; xVertexIndex < COL_C_xNbVerticesPerBox ; xVertexIndex++ )
                  {

                    POS_fn_vMulMatrixVertex ( &(a8_st8VBox2in1[xVertexIndex]), &st21TransformMatrix, &(a8_st8VBox2[xVertexIndex]) );
                  }

                  for ( xEdgeIndex = 0 ; xEdgeIndex < COL_C_xNbEdgesPerBox ; xEdgeIndex++ )
                  {
                    MTH3D_M_vSubVector ( &stEdgeVector, &(a8_st8VBox2in1[COL_g_a12_stBoxEdges[xEdgeIndex].a2_xIndex[1]]),
                                                        &(a8_st8VBox2in1[COL_g_a12_stBoxEdges[xEdgeIndex].a2_xIndex[0]]) );

                    if ( INT_fn_bDetectIntersectSegmentWithBox ( &(a8_st8VBox2in1[COL_g_a12_stBoxEdges[xEdgeIndex].a2_xIndex[0]]),
                                                                    &stEdgeVector,
                                                                    p_stGeomObj1->d_stListOfPoints + p_stIndexedAlignedBox1->xMinPoint,
                                                                    p_stGeomObj1->d_stListOfPoints + p_stIndexedAlignedBox1->xMaxPoint, NULL ) )
                    {
                      *_p_hMat1 = p_stIndexedAlignedBox1->hMaterial;
                      *_p_hMat2 = p_stIndexedAlignedBox2->hMaterial;
                      return TRUE;
                    }
                  }

                  COL_fn_vMinMaxBox2VerticesBox ( a8_st8VBox1, p_stGeomObj1->d_stListOfPoints + p_stIndexedAlignedBox1->xMinPoint,
                                                               p_stGeomObj1->d_stListOfPoints + p_stIndexedAlignedBox1->xMaxPoint );

                  for ( xVertexIndex = 0 ; xVertexIndex < COL_C_xNbVerticesPerBox ; xVertexIndex++ )
                  {

                    POS_fn_vMulMatrixVertex ( &(a8_st8VBox1in2[xVertexIndex]), &st12TransformMatrix, &(a8_st8VBox1[xVertexIndex]) );
                  }

                  for ( xEdgeIndex = 0 ; xEdgeIndex < COL_C_xNbEdgesPerBox ; xEdgeIndex++ )
                  {
                    MTH3D_M_vSubVector ( &stEdgeVector, &(a8_st8VBox1in2[COL_g_a12_stBoxEdges[xEdgeIndex].a2_xIndex[1]]),
                                                        &(a8_st8VBox1in2[COL_g_a12_stBoxEdges[xEdgeIndex].a2_xIndex[0]]) );

                    if ( INT_fn_bDetectIntersectSegmentWithBox ( &(a8_st8VBox1in2[COL_g_a12_stBoxEdges[xEdgeIndex].a2_xIndex[0]]),
                                                                    &stEdgeVector,
                                                                    p_stGeomObj2->d_stListOfPoints + p_stIndexedAlignedBox2->xMinPoint,
                                                                    p_stGeomObj2->d_stListOfPoints + p_stIndexedAlignedBox2->xMaxPoint, NULL ) )
                    {
                      *_p_hMat1 = p_stIndexedAlignedBox1->hMaterial;
                      *_p_hMat2 = p_stIndexedAlignedBox2->hMaterial;
                      return TRUE;
                    }
                  }
                }
              break;

              default :
              break;
            }
          }
        }
       }
      break;

      default :
      break;
    }
  }

  return FALSE;
}
