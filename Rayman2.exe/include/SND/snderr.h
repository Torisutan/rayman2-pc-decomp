#ifndef SND_SNDERR_H
#define SND_SNDERR_H

#define SNDERR_DISPLAY_ALLWAYS 1
#define SNDERR_DISPLAY_ONLY_ONCE 2
#define SNDERR_DISPLAY_IF_WANTED 3

#define __FATAL_ERR_SND__
#define __WARNING1_ERR_SND__
#define __WARNING2_ERR_SND__
#define __WARNING3_ERR_SND__

typedef enum e_uwSndErrNumber_{
	E_uwSndFatalErr,
#ifdef __FATAL_ERR_SND__

	E_uwSndMemoryBlockError,
	E_uwSndThreadDeadLockError,
	E_uwSndThreadReentranceDetectedError,
    E_uwSndInitNotDoneError,
    E_uwSndBadHostConfiguration,
	E_uwSndFatalError4,
#endif
	E_uwSndStartOfWarning,
#ifdef __WARNING1_ERR_SND__

	E_uwSndMemoryAllocError,
	E_uwSndMemoryReAllocError,
	E_uwSndCannotOpenFile,
	E_uwSndErrorReadingFile,
	E_uwSndINIFileNotFound,
#endif
#ifdef __WARNING2_ERR_SND__

	E_uwSndScriptLoadError,

	E_uwSndDLLCannotFindFunction,
	E_uwSndDLLCannotLoadDLL,
	E_uwSndEndOfWarningLevel2,
#endif
#ifdef __WARNING3_ERR_SND__

	E_uwSndResourceMissing,
	E_uwSndTooManyEvents,
	E_uwSndInvalidTypeOfEvent,
	E_uwSndTooManyVoices,
	E_uwSndInvalidTypeOfResource,
	E_uwSndTooManySequences,
	E_uwSndTooManySamples,
	E_uwSndTooManySwitchs,
	E_uwSndTooManySplits,
	E_uwSndInvalidDynParamForResource,
	E_uwSndInvalidStaticParamForResource,
	E_uwSndThreadMultiThreadDetectedError,
	E_uwSndSystemError,
    E_uwSndWaveCreateThread,

  E_uwSndCDLoadTrack,
  E_uwSndCDStatus,
  E_uwSndCDSet,
  E_uwSndCDPlay,
  E_uwSndCDStop,
  E_uwSndCDNotifyFailure,
  E_uwSndCDNotifyAborted,
  E_uwSndCDNotifySuperseded,
  E_uwSndCDCreateThread,
  E_uwSndCDClose,
  E_uwSndCDFade,
  E_uwSndCDSeek,
  E_uwSndCDNbTracks,
  E_uwSndCDRegisterWndClass,

  E_uwSndMIDILoadTrack,
  E_uwSndMIDIUnloadTrack,
  E_uwSndMIDIStatus,
  E_uwSndMIDISet,
  E_uwSndMIDIPlay,
  E_uwSndMIDIStop,
  E_uwSndMIDINotifyFailure,
  E_uwSndMIDINotifyAborted,
  E_uwSndMIDINotifySuperseded,
  E_uwSndMIDICreateThread,
  E_uwSndMIDIOpen,
  E_uwSndMIDIClose,
  E_uwSndMIDIFade,
  E_uwSndMIDISeek,
  E_uwSndMIDINbTracks,
  E_uwSndMIDIAllTracksUsed,

  E_uwSndMixerNoMixer,
  E_uwSndMixerNoId,
  E_uwSndMixerOpen,
  E_uwSndMixerCapacities,
  E_uwSndMixerDesinit,
  E_uwSndEventNotInABank,
  E_uwSndEventUsesUnloadedBank,

	E_uwSndEndOfWarningLevel3,
#endif
	E_uwSndErrNumber
} e_uwSndErrNumber;

#endif
