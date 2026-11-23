#pragma once

#include "POS/POS_types.h"

static __inline ACP_tdxBool POS_fn_ulIsNotScaledMatrix(POS_tdstCompletePosition *_hPosition)
{
    return (ACP_tdxBool)((_hPosition->ulType <= POS_C_ulRotationMatrixFlag ) ? TRUE : FALSE);
}
