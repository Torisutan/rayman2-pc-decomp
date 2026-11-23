#ifndef SND_SNDEVENT_H
#define SND_SNDEVENT_H

#ifndef SND_SNDRES_H

typedef unsigned long tdxId;

typedef union _tduRefRes tduRefRes;
union _tduRefRes {
	tdxId Id;
	void   *pstPtr;
};
#endif

typedef enum {
        EVT_INVALID,
		EVT_SON_PLAY ,
		EVT_SON_STOP ,
		EVT_SON_STOP_ALL ,
		EVT_SON_STOP_N_GO,
		EVT_SON_STOP_N_GO_CROSSFADE ,
		EVT_SON_PITCH ,
		EVT_SON_VOLUME ,
		EVT_SON_PAN ,
		EVT_SON_EFFET,
		EVT_SON_EXTRA,
		EVT_SON_CHANGE_VOLUME,
        FOR_ALIGNEMENT=32767
} tdeTypeEvent ;

typedef struct {
	SndReal		rDelta;
} tdstDeTune;
#define NO_DETUNING 0

typedef struct {
	tduRefRes	uResource;
	tdstDeTune	stDeTune;
} tdstEvtPlay;

typedef struct {
	SND_tduRefEvt  uEvt;
} tdstEvtStop;

typedef struct {
	SND_tduRefEvt	uEvtStop;
	SND_tduRefEvt	uEvtGo;
} tdstEvtStopNGo;

typedef struct {
	SND_tduRefEvt	uEvtStop;
	SND_tduRefEvt	uEvtGo;
	int			iTime;
} tdstEvtStopNGoFade;

typedef struct {
	tduRefRes	uResource;
	SndReal		CoefA;
	SndReal		CoefB;
	tdstDeTune	stDeTune;
} tdstEvtExtraParam;

typedef struct {
	tduRefRes	uResource;
	SndRealTwin	rtCoefPitch;
	SndRealTwin	rtCoefVol;
	SndRealTwin	rtCoefPan;
} tdstEvtExtraAll;

typedef struct {
	int	iIdEffect;
} tdstEvtEffect;

typedef struct {
	SndBool	bConcernWithObjectType;
	long	lNewVolume;
} tdstEvtchangeVolume;

typedef union {
		tdstEvtPlay			stPlay;
		tdstEvtStop			stStop;
		tdstEvtStopNGo		stStopNGo;
		tdstEvtStopNGoFade	stStopNGoFade;
		tdstEvtExtraParam	stExtraParam;
		tdstEvtExtraAll		stExtraAll;
		tdstEvtEffect		stEffect;
		tdstEvtchangeVolume stChangeVolume;
} tduEvtParams;

typedef struct _SND_tdstBlockEvent SND_tdstBlockEvent;
struct _SND_tdstBlockEvent {
	tdxId			Id;
	tdeTypeEvent	eType;
	tduEvtParams	uParams;
	SndBool			bStopable;
	SndBool			bDynamic;
};

struct _tdstSndPolyEvent {
	SND_tdstBlockEvent *hFirstElementOpt;
	long lNumberOfElementsOpt;
};

#endif
