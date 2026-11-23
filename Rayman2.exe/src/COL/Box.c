#include "MTH/MTH_flt.h"
#include "MTH/MTH3D.h"
#include "COL/Box.h"

#define COL_C_xNbSidesPerBox 6

MTH3D_tdstVector COL_g_a6_stBoxSidesNormal[COL_C_xNbSidesPerBox] =
{
  { MTH_C_MinusONE,     MTH_C_ZERO,     MTH_C_ZERO },
  {      MTH_C_ONE,     MTH_C_ZERO,     MTH_C_ZERO },
  {     MTH_C_ZERO, MTH_C_MinusONE,     MTH_C_ZERO },
  {     MTH_C_ZERO,      MTH_C_ONE,     MTH_C_ZERO },
  {     MTH_C_ZERO,     MTH_C_ZERO, MTH_C_MinusONE },
  {     MTH_C_ZERO,     MTH_C_ZERO,      MTH_C_ONE }
};

/* 0x004A6880 */
GEO_tdstDoubledIndex COL_g_a12_stBoxEdges[COL_C_xNbEdgesPerBox] =
{
  { { COL_C_xXMinYMinZMin, COL_C_xXMaxYMinZMin } },
  { { COL_C_xXMinYMinZMax, COL_C_xXMaxYMinZMax } },
  { { COL_C_xXMinYMaxZMin, COL_C_xXMaxYMaxZMin } },
  { { COL_C_xXMinYMaxZMax, COL_C_xXMaxYMaxZMax } },
  { { COL_C_xXMinYMinZMin, COL_C_xXMinYMaxZMin } },
  { { COL_C_xXMinYMinZMax, COL_C_xXMinYMaxZMax } },
  { { COL_C_xXMaxYMinZMin, COL_C_xXMaxYMaxZMin } },
  { { COL_C_xXMaxYMinZMax, COL_C_xXMaxYMaxZMax } },
  { { COL_C_xXMinYMinZMin, COL_C_xXMinYMinZMax } },
  { { COL_C_xXMinYMaxZMin, COL_C_xXMinYMaxZMax } },
  { { COL_C_xXMaxYMinZMin, COL_C_xXMaxYMinZMax } },
  { { COL_C_xXMaxYMaxZMin, COL_C_xXMaxYMaxZMax } }
};
