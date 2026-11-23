#if !defined(__INITENUM_H__)
#define __INITENUM_H__

typedef enum tdeObjectTreeInit_
{
 OTI_WhenGameStart = 0,
 OTI_MapLoaded,
 OTI_ReinitTheMap,
 OTI_LoadSavedGame,
 OTI_PlayerDead,
 OTI_WhenGoOutOfZone = OTI_PlayerDead,
 OTI_Always = OTI_WhenGoOutOfZone,
 OTI_AlwaysCreated
} tdeObjectTreeInit;

#endif
