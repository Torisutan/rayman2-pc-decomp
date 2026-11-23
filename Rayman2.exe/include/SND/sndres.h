#ifndef SND_SNDRES_H
#define SND_SNDRES_H

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#include "SND/sndtype.h"

#include "SND/sndlst2.h"

typedef unsigned long tdxId;

#define SND_C_RES_FANTOME_PTR ((void *)0)

typedef enum _tdeTypeResource {
    TYPE_INVALID,
    TYPE_SAMPLE,
    TYPE_MIDI,
    TYPE_CDAUDIO,
    TYPE_SEQUENCE,
    TYPE_SWITCH_OLD,
    TYPE_SPLIT,
    TYPE_THEME_OLD,
    TYPE_SWITCH,
    TYPE_THEME_OLD2,
    TYPE_RANDOM,
    TYPE_THEME,
    TYPE_FOR_ALIGNEMENT = 32767
} tdeTypeResource;
#define NB_TYPES_RESOURCES 12

typedef enum {
    TYPE_EXTERNAL,
    TYPE_MEGAFILE,
    TYPE_BIGFILE,
    STORAGE_FOR_ALIGNEMENT = 32767
} tdeTypeStorage;

#include "SND/sndhard.h"

typedef struct _tdstTypeSplitDisk      tdstTypeSplitDisk;
typedef struct _tdstTypeSplitMem       tdstTypeSplitMem;
typedef struct _tdstRangeSplitMem  tdstRangeSplitMem;
typedef struct _tdstRangeSplitListMem tdstRangeSplitListMem;
typedef union _tduRefRes tduRefRes;
typedef struct _tdstBlockResourceMem tdstBlockResourceMem;
typedef struct _tdstBlockResourceDisk tdstBlockResourceDisk;
typedef union _tduResDisk tduResDisk;
typedef union _tduResMem tduResMem;
typedef struct _tdstRandomElement tdstRandomElement;
typedef struct _tdstTypeRandomMem tdstTypeRandomMem;
typedef struct _tdstTypeRandomDisk tdstTypeRandomDisk;
typedef struct _tdstThemePart tdstThemePart;
typedef struct _tdstThemePartOutro tdstThemePartOutro;
typedef struct _tdstTypeThemeDisk tdstTypeThemeDisk;
typedef struct _tdstTypeThemeMem tdstTypeThemeMem;
typedef struct _tdstSwitchElement tdstSwitchElement;
typedef struct _tdstTypeSwitchMem tdstTypeSwitchMem;
typedef struct _tdstTypeSwitchDisk tdstTypeSwitchDisk;
typedef struct _tdstInfoTrackMem tdstInfoTrackMem;
typedef struct _tdstInfoTrackList tdstInfoTrackList;
typedef struct _tdstTypeSequenceDisk tdstTypeSequenceDisk;
typedef struct _tdstTypeSequenceMem tdstTypeSequenceMem;

typedef long SND_tdxHandleToSoundInfo;

union _tduRefRes {
    tdxId Id;
    tdstBlockResourceMem *pstPtr;
};

extern tduRefRes SND_RES_FANTOME;

struct _tdstRandomElement {
    tduRefRes uRes;
    SndReal rProb;
    SndBool bCanBeChosenTwice;
};

struct _tdstTypeRandomMem {
    unsigned long ulNbElements;
    SndReal rProbNothing;
    SndBool bNothingCanBeChosenTwice;
    long lLastElementChoosen;
    long lLastResChoosen;
    tdstRandomElement *hFirstElementOpt;
    long lNumberOfElementsOpt;
};

/* 0x0045A3F0 */
struct _tdstTypeRandomDisk {
    unsigned long ulNbElements;
    SndReal rProbNothing;
    SndBool bNothingCanBeChosenTwice;
    long lLastResChoosen;
    tdstRandomElement *hFirstElementOpt;
    long lNumberOfElementsOpt;
};

typedef enum _tdeTypeTransition{
		TRANSITION_CROSSFADE,
		TRANSITION_ATENDOFPART,
		TRANSITION_OUTRO,
        TRANSITION_FOR_ALIGNEMENT=32767
} tdeTypeTransition;

typedef  tdstThemePart* hThemePart;

struct _tdstThemePart {
    tduRefRes   uRes;
	SndBool		bLoopStart;
	SndBool		bLoopEnd;
	long		lNbLoops;
	tdeTypeTransition	eTransition;
	SndReal				rFadeDuration;
};

struct _tdstThemePartOutro {
    tduRefRes   uRes;
	tdeTypeTransition	eTransition;
	SndReal		rFadeDuration;
};

struct _tdstTypeThemeDisk {
    unsigned long   ulStartLoop;
    unsigned long   ulEndLoop;
	unsigned long	ulNbLoops;
    unsigned long	ulNbParts;
    long			lOffsetPartOutro;
	SndReal			rFadeDuration;
    tdstThemePart *hFirstElementOpt;
    long lNumberOfElementsOpt;
};

struct _tdstTypeThemeMem {
    unsigned long	ulStartLoop;
    unsigned long	ulEndLoop;
    unsigned long	ulNbParts;
    tdstThemePartOutro*	pstPartOutro;
	SndReal			rFadeDuration;
	unsigned long	ulNbLoops;
    tdstThemePart *hFirstElementOpt;
    long lNumberOfElementsOpt;
};

struct _tdstSwitchElement {
        tduRefRes                   uRes;
        SND_tdxHandleToSoundInfo    hIndice;
} ;

#define C_SWITCH_NODEFAULT ((SND_tdxHandleToSoundInfo)-1)

struct _tdstTypeSwitchMem
{
		tdstSwitchElement *hFirstElementOpt;
		long lNumberOfElementsOpt;
        unsigned long				ulNbElements;
        long						lTypeSwitch;
        SND_tdxHandleToSoundInfo	hDefault;
		SndBool						bDynamic;
		SndBool						bMaintainIfSwitched;
};

/* 0x0045A900 */
struct _tdstTypeSwitchDisk
{
		tdstSwitchElement *hFirstElementOpt;
		long lNumberOfElementsOpt;
        unsigned long				ulNbElements;
        long						lTypeSwitch;
        SND_tdxHandleToSoundInfo	hDefault;
		SndBool						bDynamic;
		SndBool						bMaintainIfSwitched;
};

/* 0x0045A9A0 */
typedef struct _tdstTypeSwitchOld       tdstTypeSwitchOld;

struct _tdstTypeSwitchOld
{
		tdstSwitchElement *hFirstElementOpt;
		long lNumberOfElementsOpt;
        unsigned long               ulNbElements;
        long                        lTypeSwitch;
        SND_tdxHandleToSoundInfo    hDefault;
		SndBool						bDynamic;
};

/* 0x00457D10 */
struct _tdstTypeSplitDisk
{
        unsigned long   ulNbRanges ;
        SndBool			bStayActive;

}  ;

struct _tdstRangeSplitMem {
	tduRefRes   uRes ;
	SndReal	    rPitchA ;
	SndReal	    rPitchB ;
	SndReal	    rPitchC ;
	SndReal	    rPitchD ;
	SndReal	    rCoefPitch ;
	unsigned char ucVolume ;
    SndReal     rCoefMagAB;
    SndReal     rCoefMagCD;
}  ;

struct _tdstRangeSplitListMem{
	tdstRangeSplitMem *hFirstElementOpt;
	long lNumberOfElementsOpt;
}  ;

struct _tdstTypeSplitMem
{
	unsigned long           ulNbRanges;
    SndBool					bStayActive;
	tdstRangeSplitListMem   stRangeList;
} ;

struct _tdstInfoTrackMem {
        unsigned long ulFadeIn;
        unsigned long ulFadeOut;
        unsigned long ulCrossFade;
        tduRefRes       uRes;
} ;

struct _tdstInfoTrackList
{
        tdstInfoTrackMem *hFirstElementOpt;
        long lNumberOfElementsOpt;
};

/* 0x0045AB20 */
struct _tdstTypeSequenceDisk {
        SndBool			bLoop;
        unsigned long	ulStartLoop;
        unsigned long	ulEndLoop;
        unsigned long	ulNbLoops;
        unsigned long	ulNbElements;
} ;

struct _tdstTypeSequenceMem {
        SndBool			bLoop;
        unsigned long	ulStartLoop;
        unsigned long	ulEndLoop;
        unsigned long	ulNbLoops;
        unsigned long	ulNbElements;
        tdstInfoTrackList stResList;
} ;

union _tduResDisk {
        tdstTypeSampleDisk      stSample ;
        tdstTypeSequenceDisk    stSequence ;
        tdstTypeSwitchDisk      stSwitch ;
        tdstTypeSwitchOld       stSwitchOld ;
        tdstTypeSplitDisk       stSplit;
        tdstTypeThemeDisk       stTheme;
        tdstTypeRandomDisk		stRandom;
} ;

struct _tdstBlockResourceDisk {
        tdxId			Id;
        tdeTypeResource	eType;
        tdeTypeStorage	eStorage;
        unsigned long	ulDataSize;
        unsigned long	ulDataOffset;
        unsigned char	ucVolume;
        tduResDisk		uRes;
};

union _tduResMem {
        tdstTypeSampleMem   stSample ;
        tdstTypeSequenceMem stSequence ;
        tdstTypeSwitchMem   stSwitch ;
        tdstTypeSplitMem    stSplit;
        tdstTypeThemeMem    stTheme;
        tdstTypeRandomMem	stRandom;
} ;

struct _tdstBlockResourceMem {
    tdxId Id;
    tdeTypeResource eType;
    tdeTypeStorage eStorage;
    unsigned char ucVolume;
    SndBool bIsLoaded;
    tduResMem uRes;
};

union _tduBlockResource {
    tdstBlockResourceMem stMem;
    tdstBlockResourceDisk stDisk;
};

#endif
