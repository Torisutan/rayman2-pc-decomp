#pragma once

#define __FATAL_ERR_GAME__
#define __INFORMATION_ERR_GAME__
#define __WARNING_ERR_GAME__

enum e_uwGameErrNumber
{
 E_uwGameFatalErr,

 #if defined(__FATAL_ERR_GAME__)

 E_uwGameFatalErrorNotAFatalError,
 E_uwGameInformationErrorIsNotAInformationError,
 E_uwGameWarningErrorIsNotAWarningError,

 E_uwGameInitMemoryCheckAlign,
 E_uwGameGameMallocBadBlock,
 E_uwGameGameMallocBadSize,
 E_uwGameGameMallocAlloc,
 E_uwGameIncreaseNumberOfSource,

 E_uwGameScriptCallBackStateActionsAlreadyRead,
 E_uwGameInitAllObjectTreeNullPointer,
 E_uwGameInitAllObjectTreeBadInitType,
 E_uwGameInitDesinitOneObjectNullPointer,
 E_uwGameMiniStructAllocAlreadyAlloc,
 E_uwGameMiniStructObjectNull,
 E_uwGameMiniStructNull,
 E_uwGameCineInfoSuperObjectNull,

 E_uwGameChooseTheGoodInitInvalidMode,
 E_uwGameChooseTheGoodDesinitInvalidMode,
 E_uwGameChangeEngineModeNewMode,
 E_uwGameExploreWorldTreeInvalidSuperObject,
 E_uwGameVerifySomeProgramVariableHandleFunction,
 E_uwGameLanguage,
 E_uwGameLanguageDefinition,

 E_uwGameAToIBadEntry,
 E_uwGameAToFBadEntry,

 E_uwGameScriptBadNumberOfArg,
 E_uwGameScriptBadIPTLinkNumber,

 E_uwGameErrorWhileLoadingAnimation,
 E_uwGameBadAnimationGeneralInfo,
 E_uwGameBadFrameNumber,
 E_uwGameBadChannelNumber,
 E_uwGameTooManyAnimations,
 E_uwGameCurrentActorNotSet,
 E_uwGameNoMorePLAObj,
 E_uwGamePLA_NoWantedState,
 E_uwGameStateNotInLinkTable,
 E_uwGameScriptCallBackCreateNewStateBadNextState,
 E_uwGameScriptCallBackCreateNewStateBadTargetState,
 E_uwGameScriptCallBackCreateNewStateBadStateToGo,

 E_uwGameCantCreateFixViewPort,
 E_uwGameCantClearViewPort,
 E_uwGameCantWriteToViewPort,
 E_uwGameCantWriteToViewPortFinished,
 E_uwGameCantFlipDevice,

 E_uwGameKillAlwaysByPersonalType,

 E_uwGameDynamScriptCallBackBadParameter,

 E_uwGameUnCoherentSubMap,
#endif

 E_uwGameStartOfWarning,

 #if defined(__WARNING_ERR_GAME__)

 E_uwGameChangeEngineModeOldMode,

 E_uwGameMallocUserDataAlreadyAllocated,

 E_uwGameReadInputKeyboard,
 E_uwGameReadInputJoystick,

 E_uwGameAddAnAlwaysModelAlreadyExist,
 E_uwGameAllocateAlwaysUnknownModel,
 E_uwGameAllocateAlwaysNoMorePlace,
 E_uwGameKillOneEngineObjectInvalid,
 E_uwGameFreeEngineSuperObjectNoCharacter,
 E_uwGameFirstInitFamilyStructureNoNull,
 E_uwGameFreeUnknownSuperObjectType,
 E_uwGameSaveOneEngineCharacters,
 E_uwGameSaveAllEngineCharacters,
 E_uwGameCreateSOFromEngineObjectAndParentBadSO,
 E_uwGameChangeOfMechanicsDuringOneFrame,
 E_uwGameBadNumberOfStatesInActivationList,
 E_uwGamePLA_BadInitialState,

 E_uwGameDebugDynamicAllocation,
#endif

 E_uwGameStartOfInformationWarning,

 #if defined(__INFORMATION_ERR_GAME__)

 E_uwGameInitInputKeyboard,
 E_uwGameInitInputJoystick,

 E_uwGameGameFreeNullPointer,

 E_uwGameInitOneObjectInvalidObject,
 E_uwGameKillAlwaysByRankInvalidObject,

 E_uwGameScriptCallBackDescriptionUnknownAction,
 E_uwGameScriptCallBackDescriptionScriptError,

 E_uwGameCurrentSectorInOwnSoundList,
 E_uwGameSectorTwiceInSoundList,
 E_uwGameCurrentSectorInOwnActivityList,
 E_uwGameSectorTwiceInActivityList,
 E_uwGameCurrentSectorInOwnCollisionList,
 E_uwGameSectorTwiceInCollisionList,
 E_uwGameCurrentSectorInOwnGraphicList,
 E_uwGameSectorTwiceInGraphicList,

  #endif

	E_uwGameErrNumber
};

typedef int _ErrGame_check[(E_uwGameMiniStructObjectNull == 0x0E && E_uwGameStartOfWarning == 0x30) ? 1 : -1];
