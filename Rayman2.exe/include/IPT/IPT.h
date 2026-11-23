#pragma once

#include <stddef.h>
#include "IPT/IPT_globals.h"

#define IPT_C_TRUE   1
#define IPT_C_FALSE  0

typedef struct IPT_tdstEntryElement_ {
    unsigned long  ulNumberOfKeyWordElement;
    struct IPT_tdstKeyWordElement_ *d_stKeyWordElementArray;
    char          *p_szEntryName;
    long           lState;
    float          xAnalogicValue;
    unsigned char  bIsActivate;

    unsigned char  pc_bSaveInOptions;
} IPT_tdstEntryElement;

typedef struct IPT_tdstKeyAndPadDefine_ {
    unsigned short uwBasedKey;
    char          *p_szFrenchKey;
    char          *p_szAmericanKey;
} IPT_tdstKeyAndPadDefine;

typedef char IPT_ct_assert_EntryElement_size[(sizeof(IPT_tdstEntryElement) == 0x18) ? 1 : -1];
typedef char IPT_ct_assert_lState_off[(offsetof(IPT_tdstEntryElement, lState) == 0x0C) ? 1 : -1];
typedef char IPT_ct_assert_xAnalog_off[(offsetof(IPT_tdstEntryElement, xAnalogicValue) == 0x10) ? 1 : -1];

extern const float IPT_g_xDefaultAnalogicValue;

#define IPT_C_InvalideDevice         0
#define IPT_C_ValideDevice           1
#define IPT_C_ActivateDevice         2
#define IPT_C_ActivatePadDevice      3
#define IPT_C_ActivateJoystickDevice 4
#define IPT_C_ActivateMouseDevice    5

/* 0x004B9C68 */
extern int IPT_pc_g_bMouseEnabled;

typedef struct IPT_tdstKeyWordElement_ {
    union {
        void          *hEntryElement;
        short          swValue;
        unsigned long  ulNumberOfSequence;
    } u_ElementUnion;
    unsigned char ucResult;
    unsigned char ucMinCounterInput;
    unsigned char ucMaxCounterInput;
} IPT_tdstKeyWordElement;
typedef char IPT_ct_assert_KeyWordElement_size[(sizeof(IPT_tdstKeyWordElement) == 8) ? 1 : -1];

/* 0x0042EAC0 */
extern IPT_tdstEntryElement   *IPT_g_h_ActualEntryInput;
extern IPT_tdstKeyWordElement *IPT_g_hNextParameter;

/* 0x0042EAF0 */
typedef unsigned char (IPT_tdfn_bIsKeyWordValid)(IPT_tdstKeyWordElement *);
extern IPT_tdfn_bIsKeyWordValid *IPT_p_fn_bIsKeyWordValid[38]; /* 0x004A0F18 */

/* 0x004A0CFC */
extern unsigned char g_ucIPTModuleId;

/* 0x00430880 */
typedef struct IPT_tdstHistoricElement_ {
    unsigned char  bf2State;
    unsigned char  bf6DeviceType;
    unsigned char  ucCounter;
    unsigned char  ucPad;
    short          swDeviceValue;
} IPT_tdstHistoricElement;
typedef char IPT_ct_assert_HistoricElement_size[(sizeof(IPT_tdstHistoricElement) == 6) ? 1 : -1];

#define IPT_E_Stopped                 0
#define IPT_E_Stopping                1
#define IPT_E_InProgress              2
#define IPT_E_KeyboardDeviceEvent     1
#define IPT_E_Pad00DeviceEvent        2
#define IPT_E_Pad15DeviceEvent        17

/* 0x004A0D20 */
void __cdecl IPT_fn_vActualizeHistoric(void);

#ifndef IPT_ANAL_DEFINES_PREDICATES
unsigned char __cdecl IPT_fn_bIsJustValidated(IPT_tdstEntryElement *_hEntryElement);
unsigned char __cdecl IPT_fn_bIsValidated(IPT_tdstEntryElement *_hEntryElement);
unsigned char __cdecl IPT_fn_bIsJustInvalidated(IPT_tdstEntryElement *_hEntryElement);
unsigned char __cdecl IPT_fn_bIsInvalidated(IPT_tdstEntryElement *_hEntryElement);
#endif

/* 0x0042E110 */
char *__cdecl IPT_fn_szGetEntryActionName(IPT_tdstEntryElement *_hEntryElement);

/* 0x0042E5A0 */
char *__cdecl IPT_fn_p_szGetNameOfKeyName(unsigned short uwKeyCode, unsigned char ucFrenchOrAmerican);

/* 0x0042E540 */
char *__cdecl FUN_0042E540(long lHandle);

void          __cdecl IPT_fn_vActivateEntryElement(IPT_tdstEntryElement *_hEntryElement);    /* 0x0042E180 */
void          __cdecl IPT_fn_vDesactivateEntryElement(IPT_tdstEntryElement *_hEntryElement); /* 0x0042E1A0 */
unsigned char __cdecl IPT_fn_bModifyIPTAction(IPT_tdstEntryElement *_hElementToChange,
                                              IPT_tdstEntryElement *_hReplacingElement);     /* 0x0042E2D0 */

float __cdecl IPT_fn_lGetAnalogicValue(IPT_tdstEntryElement *_hEntryElement);

void __cdecl IPT_fn_vResetInputEntry(void);
unsigned char __cdecl IPT_fn_bAJoypadConnected(void);   /* 0x0042E1C0 */
unsigned char __cdecl IPT_fn_bAKeyJustPressed(void);    /* 0x0042E600 */
unsigned char __cdecl IPT_fn_bAButtonPadJustPressed(void); /* 0x0042E690 */

void __cdecl IPT_fn_vReadInput(void);
unsigned char __cdecl IPT_fn_bIsEntryActionValid(IPT_tdstEntryElement *_hEntryElement);

/* 0x00413890 */
extern IPT_tdstEntryElement *IPT_g_hEngineMonitoredEntry;
void __cdecl fn_vEngineReadInput(void);
unsigned char __cdecl IPT_fn_bIsKeyWordValid(void *hKeyWordElement);

unsigned char __cdecl IPT_fn_bIsKeyWordValid_And(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_Or(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_Not(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionJustValidated(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionJustInvalidated(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionValidated(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_ActionInvalidated(IPT_tdstKeyWordElement *_hKeyWordElement);

unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_KeyReleased(IPT_tdstKeyWordElement *_hKeyWordElement);

unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_PadReleased(IPT_tdstKeyWordElement *_hKeyWordElement);

#define IPT_C_JoyKeywordDeviceActive   4
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickAxeValue(IPT_tdstKeyWordElement *_hKeyWordElement);

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickReleased(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickOrPadReleased(IPT_tdstKeyWordElement *_hKeyWordElement);

unsigned char __cdecl IPT_fn_bIsKeyWordValid_Sequence(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequenceKey(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequenceKeyEnd(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequencePad(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_SequencePadEnd(IPT_tdstKeyWordElement *_hKeyWordElement);

unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickAngularValue(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickTrueNormValue(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_JoystickCorrectedNormValue(IPT_tdstKeyWordElement *_hKeyWordElement);

unsigned char __cdecl IPT_fn_bIsKeyWordValid_MouseAxeValue(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_MouseAxePosition(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_MouseJustPressed(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_MouseJustReleased(IPT_tdstKeyWordElement *_hKeyWordElement);
unsigned char __cdecl IPT_fn_bIsKeyWordValid_MousePressed(IPT_tdstKeyWordElement *_hKeyWordElement);
