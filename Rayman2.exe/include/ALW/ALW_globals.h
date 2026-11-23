#pragma once

#include "ALW/ALW.h"

#undef EXTERN
#if !defined(D_ALW_VariableDefine)
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN tdstAlways g_stAlways;

#define ALW_g_stAlways (&g_stAlways)
