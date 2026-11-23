#ifndef RAYMAN2_GAM_ALWACT_H
#define RAYMAN2_GAM_ALWACT_H

#include "GAM/GAM_types.h"

#define M_ForEachAlwaysActiveCharacterNode(_hCharNode,_i) \
for														\
(														\
	_i=0,(_hCharNode)=fn_hGetFirstAlwaysActiveCharNode();		\
	_hCharNode;									\
	_i++,(_hCharNode)=fn_hGetNextAlwaysActiveCharNode(_hCharNode)			\
)

#endif
