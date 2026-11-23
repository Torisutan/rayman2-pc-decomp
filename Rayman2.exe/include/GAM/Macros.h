#pragma once

#include "ERM/CpaError.h"
#include "GAM/ErrGame.h"

#define M_GameFatalError(ErrorNum) \
{ \
 if (ErrorNum>E_uwGameFatalErr&&ErrorNum<E_uwGameStartOfWarning) \
 { \
  Erm_M_ClearLastError(C_ucErmDefaultChannel);\
  Erm_M_UpdateLastError(Game,C_ucErmDefaultChannel,(unsigned short)ErrorNum,C_lErmNoDebugData,C_ucErmOpenInfoWindow,C_ucAllowStopForDebug, NULL);\
 } \
 else \
 { \
  Erm_M_ClearLastError((unsigned short)C_ucErmDefaultChannel);\
  Erm_M_UpdateLastError(Game,C_ucErmDefaultChannel,(unsigned short)E_uwGameFatalErrorNotAFatalError,C_lErmNoDebugData,C_ucErmOpenInfoWindow,C_ucAllowStopForDebug, NULL);\
 } \
}
