#include "COL/OctreeGO.h"
#include "COL/Box.h"
#include "INT/Inters.h"
#include "MTH/MTH3D.h"

/* 0x4FAAB8 */
static ACP_tdxIndex COL_g_xDepth_storage;
static ACP_tdxIndex COL_g_xSelectedDepth_storage;
#define COL_g_xDepth         (COL_g_xDepth_storage)
#define COL_g_xSelectedDepth (COL_g_xSelectedDepth_storage)

void __cdecl
COL_fn_vExploreRecursiveOctreeWithBox(COL_tdpstOctreeNode  p_stNodeToBeExplored,
                                      MTH3D_tdstVector    *p_stMinSituation,
                                      MTH3D_tdstVector    *p_stMaxSituation,
                                      COL_tdpstOctreeNode *d_pstSelectedNode,
                                      ACP_tdxIndex        *p_xNumberOfSelectedNodes)
{
    COL_g_xDepth++;

    if (INT_fn_bIntersectBoxWithBox(p_stMinSituation, p_stMaxSituation,
                                    &p_stNodeToBeExplored->stMinPart,
                                    &p_stNodeToBeExplored->stMaxPart))
    {
        if (p_stNodeToBeExplored->p_pstChildList != NULL)
        {
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[0], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[1], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[2], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[3], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[4], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[5], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[6], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithBox(p_stNodeToBeExplored->p_pstChildList[7], p_stMinSituation, p_stMaxSituation, d_pstSelectedNode, p_xNumberOfSelectedNodes);
        }
        else
        {
            if (p_stNodeToBeExplored->d_xFaceIndexList != NULL)
            {
                if (*p_xNumberOfSelectedNodes < COL_C_xMaxSelectedNodes)
                {
                    d_pstSelectedNode[*p_xNumberOfSelectedNodes] = p_stNodeToBeExplored;
                    (*p_xNumberOfSelectedNodes)++;
                    COL_g_xSelectedDepth = COL_g_xDepth;
                }
            }
        }
    }

    COL_g_xDepth--;
}

void __cdecl
COL_fn_vExploreOctreeWithBox(COL_tdpstOctree      p_stOctree,
                             MTH3D_tdstVector    *p_stMinPoint,
                             MTH3D_tdstVector    *p_stMaxPoint,
                             COL_tdpstOctreeNode *d_pstSelectedNode,
                             ACP_tdxIndex        *p_xNumberOfSelectedNodes)
{
    *p_xNumberOfSelectedNodes = 0;
    COL_g_xSelectedDepth = 0;
    COL_g_xDepth = 0;

    if (p_stOctree != NULL)
    {
        COL_fn_vExploreRecursiveOctreeWithBox(p_stOctree->p_stOctreeRoot, p_stMinPoint, p_stMaxPoint,
                                              d_pstSelectedNode, p_xNumberOfSelectedNodes);
    }
}

void COL_fn_vViewAndAddSelectedNode(COL_tdpstOctreeNode p_stNodeToBeExplored,
                                    MTH_tdxReal         xT,
                                    COL_tdpstOctreeNode *d_pstSelectedNode,
                                    MTH_tdxReal         *d_xSelectedT,
                                    ACP_tdxIndex        *p_xNumberOfSelectedNodes)
{
    ACP_tdxIndex xNodeIndex;

    xNodeIndex = *p_xNumberOfSelectedNodes;
    while ((0 < xNodeIndex) && (xT < d_xSelectedT[xNodeIndex-1]))
    {
        if (xNodeIndex < COL_C_xMaxSelectedNodes)
        {

            d_pstSelectedNode[xNodeIndex] = d_pstSelectedNode[xNodeIndex-1];
            d_xSelectedT[xNodeIndex] = d_xSelectedT[xNodeIndex-1];
        }
        xNodeIndex--;
    }

    if (xNodeIndex < COL_C_xMaxSelectedNodes)
    {

        d_pstSelectedNode[xNodeIndex] = p_stNodeToBeExplored;
        d_xSelectedT[xNodeIndex] = xT;
        if (*p_xNumberOfSelectedNodes < COL_C_xMaxSelectedNodes)
        {
            (*p_xNumberOfSelectedNodes)++;
        }
    }
}

void COL_fn_vExploreRecursiveOctreeWithSegment(COL_tdpstOctreeNode p_stNodeToBeExplored,
                                               MTH3D_tdstVector   *p_stVertexA,
                                               MTH3D_tdstVector   *p_stVectAB,
                                               COL_tdpstOctreeNode *d_pstSelectedNode,
                                               MTH_tdxReal        *d_xSelectedT,
                                               ACP_tdxIndex       *p_xNumberOfSelectedNodes)
{
    MTH_tdxReal xT;

    COL_g_xDepth++;

    if (INT_fn_bDetectIntersectSegmentWithBox(p_stVertexA, p_stVectAB,
                                              &(p_stNodeToBeExplored->stMinPart),
                                              &(p_stNodeToBeExplored->stMaxPart), &xT))
    {

        if (p_stNodeToBeExplored->p_pstChildList != NULL)
        {

            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMinYMinZMin], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMinYMinZMax], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMinYMaxZMin], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMinYMaxZMax], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMaxYMinZMin], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMaxYMinZMax], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMaxYMaxZMin], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
            COL_fn_vExploreRecursiveOctreeWithSegment(p_stNodeToBeExplored->p_pstChildList[COL_C_xXMaxYMaxZMax], p_stVertexA, p_stVectAB, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
        }
        else
        {
            if (p_stNodeToBeExplored->d_xFaceIndexList != NULL)
            {

                COL_fn_vViewAndAddSelectedNode(p_stNodeToBeExplored, xT, d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
                COL_g_xSelectedDepth = COL_g_xDepth;
            }
        }
    }
    COL_g_xDepth--;
}

void COL_fn_vExploreOctreeWithSegment(COL_tdpstOctree    p_stOctree,
                                      MTH3D_tdstVector   *p_stVertexA,
                                      MTH3D_tdstVector   *p_stVectAB,
                                      COL_tdpstOctreeNode *d_pstSelectedNode,
                                      MTH_tdxReal        *d_xSelectedT,
                                      ACP_tdxIndex       *p_xNumberOfSelectedNodes)
{

    *p_xNumberOfSelectedNodes = 0;
    COL_g_xSelectedDepth = 0;
    COL_g_xDepth = 0;

    if (p_stOctree != NULL)
    {

        COL_fn_vExploreRecursiveOctreeWithSegment(p_stOctree->p_stOctreeRoot, p_stVertexA, p_stVectAB,
                                                  d_pstSelectedNode, d_xSelectedT, p_xNumberOfSelectedNodes);
    }
}
