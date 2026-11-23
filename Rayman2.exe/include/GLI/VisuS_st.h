#pragma once

typedef struct GEO_tdstVisualSet_
{
  MTH_tdxReal xLastDistance ;
  ACP_tdxIndex xNbLodDefinitions;
  MTH_tdxReal *d_xThresholdsTable;
  struct GEO_tdstGeometricObject_ **d_p_stLodDefinitions;
	void **d_hRLI ;
	long lNumberOfRLI ;
}
GEO_tdstVisualSet ;
