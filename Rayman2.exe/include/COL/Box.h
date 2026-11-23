#pragma once

#include "GEO/GEO_types.h"

#define COL_C_xXMinYMinZMin 0
#define COL_C_xXMinYMinZMax 1
#define COL_C_xXMinYMaxZMin 2
#define COL_C_xXMinYMaxZMax 3
#define COL_C_xXMaxYMinZMin 4
#define COL_C_xXMaxYMinZMax 5
#define COL_C_xXMaxYMaxZMin 6
#define COL_C_xXMaxYMaxZMax 7

#define COL_C_xNbVerticesPerBox 8

#define COL_C_xNbEdgesPerBox 12

extern GEO_tdstDoubledIndex COL_g_a12_stBoxEdges[COL_C_xNbEdgesPerBox]; /* 0x004A6880 */
