#pragma once

typedef struct stTimerCount_ {
    unsigned long m_ulLowPart;
    unsigned long m_ulHighPart;
} stTimerCount;

typedef void (*td_p_fn_vTimerEventCallback)(void);

#define     C_uwTimerMaxCount       16

#define     C_wTimerUnused          0
#define     C_wTimerReady           1
#define     C_wTimerRunning         2
#define     C_wTimerStop            3
#define     C_wTimerPaused          4

#define     C_wTimerEvent           5

typedef struct _tdstTimer
{

    short           m_wTimerType;

    short           m_wTimerState;

    stTimerCount    m_stTimerCount_InitValue;

    stTimerCount    m_stTimerCount_LastValue;

    stTimerCount    m_stTimerCount_TotalValue;

    unsigned long   m_ulEventId;

    td_p_fn_vTimerEventCallback  m_p_fn_vEventCallback;

} tdstTimer;

typedef tdstTimer TMR_tdstTimer;

#define		C_wTimerError			      32767

#define		C_wTimerFrequencyLow	  0
#define		C_wTimerFrequencyMedium	1
#define		C_wTimerFrequencyHigh	  2
