#pragma once

#include "MTH/MTH_types.h"

#define RND_C_MaxIndex 50

typedef unsigned long RND_tdxHandleToRandomIndex;

typedef struct RND_tdstRandom_ {
    unsigned long              ulSizeOfTable;
    unsigned long              a_ulIndex[RND_C_MaxIndex];
    RND_tdxHandleToRandomIndex hLastUsedIndex;
    unsigned long              ulMaxValueInTable;

    MTH_tdxReal                xInverseMaxValueInTable;
    unsigned long             *p_ulTable;
} RND_tdstRandom;
