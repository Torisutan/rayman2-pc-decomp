#ifndef _COL_OCTREEGO_H_
#define _COL_OCTREEGO_H_

#include "ACP/ACP_types.h"
#include "MTH/MTH3D.h"
#include "GEO/GEO_types.h"
#include "COL/COL_types.h"

void __cdecl COL_fn_vExploreRecursiveOctreeWithBox(COL_tdpstOctreeNode  p_stNodeToBeExplored,
                                                   MTH3D_tdstVector    *p_stMinSituation,
                                                   MTH3D_tdstVector    *p_stMaxSituation,
                                                   COL_tdpstOctreeNode *d_pstSelectedNode,
                                                   ACP_tdxIndex        *p_xNumberOfSelectedNodes);

void __cdecl COL_fn_vExploreOctreeWithBox(COL_tdpstOctree      p_stOctree,
                                          MTH3D_tdstVector    *p_stMinPoint,
                                          MTH3D_tdstVector    *p_stMaxPoint,
                                          COL_tdpstOctreeNode *d_pstSelectedNode,
                                          ACP_tdxIndex        *p_xNumberOfSelectedNodes);

#endif
