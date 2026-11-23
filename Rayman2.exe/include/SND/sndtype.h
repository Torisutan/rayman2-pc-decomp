#ifndef SND_SNDTYPE_H
#define SND_SNDTYPE_H

typedef int SndBool;

typedef long SndReal;
#define C_SNDREAL_1 0x10000
#define C_SNDREAL_0 0x00000

typedef long SndRealTwin;

typedef struct _SndVector SndVector;
typedef struct _MicroLink MicroLink;
typedef struct _ExtraSoundParam ExtraSoundParam;
typedef struct _RollOffParam RollOffParam;
typedef struct _SwitchParam SwitchParam;

typedef struct _MicroParam MicroParam;

struct _SndVector {
	SndReal x ;
	SndReal y ;
	SndReal z ;
};

struct _MicroLink{
    long    lId;
    SndBool bLinked;
};

#define C_SOUNDPARAM_NO_POSITION 1
#define C_SOUNDPARAM_NO_DOPPLER 2
#define C_SOUNDPARAM_COEF_VOL 4
#define C_SOUNDPARAM_COEF_FREQ 8
#define C_SOUNDPARAM_ROLLOFF 16
#define C_SOUNDPARAM_SWITCH 32

struct _RollOffParam {
	SndReal		rDistSatur;
	SndReal		rDistBackGround;
};

struct _SwitchParam {
	long	lObjectType;
	long	lObjectId;
};

struct _ExtraSoundParam {
	RollOffParam	stRollOff;
	SwitchParam		stSwitch;
};

#define C_ROLLOFFPARAM_INFINITE 0x7FFFFFFF
#define C_ROLLOFFPARAM_DEFAULT 0x7FFFFFFE

struct _MicroParam{
	SndVector	pos;
	SndVector	vit;
	SndVector	dirnor;
	SndVector	dirtan;
} ;

#define C_SOUNDPAN_MEDIAN 64
#define C_SOUNDPAN_LEFT 0
#define C_SOUNDPAN_RIGHT 127

#define C_SOUNDVOL_MINI 0
#define C_SOUNDVOL_MAXI 127

#define C_SOUNDSPACE_FRONT 0
#define C_SOUNDSPACE_BACK 127

#define NO_REVERB 0

#define C_CREATEMICRO_FAILED -1
#define C_PLAY_FAILED -1
#define C_GETVOLUME_FAILED 255
#define C_INIT_FAILED 2
#define C_INIT_OK 3
#define C_INIT_RUNNING 4
#define C_INIT_UNCOMPLETED 5

#endif
