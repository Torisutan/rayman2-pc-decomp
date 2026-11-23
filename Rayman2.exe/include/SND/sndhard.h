#ifndef SND_SNDHARD_H
#define SND_SNDHARD_H

typedef union _tduBlockResource tduBlockResource;
typedef struct _tdstSndBankHeader tdstSndBankHeader;
typedef struct _tdstSndBankHead tdstSndBankHead;
typedef struct _tdstSampleMemory        tdstSampleMemory;
typedef struct _tdstSampleStreaming     tdstSampleStreaming;
typedef union _tduDataSample tduDataSample;
typedef struct _tdstTypeSampleDisk tdstTypeSampleDisk;
typedef struct _tdstTypeSampleMem tdstTypeSampleMem;

typedef enum {
	SAMPLE_INVALID,
	SAMPLE_PCM,
	SAMPLE_MPEG,
	SAMPLE_AIFF,
	SAMPLE_ADPCM,
	SAMPLE_ADPCM_TOCONVERT,
	SAMPLE_FOR_ALIGNEMENT=0x13245678
} tdeTypeZip;

struct _tdstTypeSampleDisk {
	SndBool			bPitchable;
	SndBool			bVolable;
	SndBool			bPanable;
	SndBool			bSpacable;
	SndBool			bReverbable;
	SndBool			bStream;
	SndBool			bLoop;
	unsigned long	ulStartLoop;
	unsigned long	pc_ulLoopLength;
	unsigned long	ulFreq;
	unsigned short	uwResolution;
	unsigned short	uwNbChannels;
	tdeTypeZip		eZip;
	char			szFileName[13];
};

struct _tdstSampleMemory {
	void			*pvPtrFirst;
	unsigned long	ulNbEchLoop;
	unsigned long	ulNbEch;
};

struct _tdstSampleStreaming {
	char			szFileName[13];
	unsigned long	ulOffsetFirst;
	unsigned long	ulOffsetLoop;
	unsigned long	ulOffsetLast;
};

union _tduDataSample {
	tdstSampleMemory	stMem;
	tdstSampleStreaming	stStream;
};

struct _tdstTypeSampleMem {
	SndBool			bPitchable;
	SndBool			bVolable;
	SndBool			bPanable;
	SndBool			bSpacable;
	SndBool			bReverbable;
	SndBool			bStream;
	SndBool			bLoop;
	tduDataSample	uData;
	unsigned long	ulInc0;
	unsigned long	ulFreq;
	unsigned short	uwResolution;
	unsigned short	uwNbChannels;
	tdeTypeZip		eZip;
};

struct _tdstSndBankHeader
{
	long lVersion;
};

typedef struct _tdstSndBankPolyRes tdstSndBankPolyRes;

typedef struct _tdstSndBankPolyEvent tdstSndBankPolyEvent;

struct _tdstSndBankPolyRes
{
      tduBlockResource *hFirstElementOpt;
      long lNumberOfElementsOpt;
};

struct _tdstSndBankPolyEvent
{
	struct _SND_tdstBlockEvent *hFirstElementOpt;
	long lNumberOfElementsOpt;
};

#define SND_INVALID_BINID 0xFFFFFFFF

struct _tdstSndBankHead
{
	tdstSndBankHeader stHeader;
	tdstSndBankPolyEvent stEventList;
	tdstSndBankPolyRes stResList;
	unsigned long ulOffsetMPEG;
	unsigned long ulOffsetMidi;
	unsigned long ulOffsetSample;
	unsigned long ulOffsetADPCM;
	unsigned long ulOffsetStreaming;
	unsigned long ulTotalSize;
};

#endif
