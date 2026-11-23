#pragma once

#include "ERM/CpaError.h"

#define __FATAL_ERR_Tmr__
#define __WARNING1_ERR_Tmr__
#define __WARNING2_ERR_Tmr__
#define __WARNING3_ERR_Tmr__

typedef enum e_uwTmrErrNumber_{
	E_uwTmrFatalErr,
#ifdef __FATAL_ERR_Tmr__

#endif
	E_uwTmrStartOfWarning,
#ifdef __WARNING1_ERR_Tmr__

    E_uwTmrLibraryNotInitialized,
    E_uwTmrInvalidType,
    E_uwTmrTypeNotAvailable,
    E_uwTmrInvalidHandle,
    E_uwTmrInvalidForEventTimer,
    E_uwTmrMaxTimerCountReached,
    E_uwTmrTimerNotReady,

    E_uwTmrCreateEventFailed,
#endif
#ifdef __WARNING2_ERR_Tmr__

#endif
#ifdef __WARNING3_ERR_Tmr__

#endif
	E_uwTmrErrNumber
} e_uwTmrErrNumber;
