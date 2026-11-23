#if !defined(__IPT_Str_H__)
#define __IPT_Str_H__

#include <stddef.h>
#include "IPT/IPT_KDef.h"

#define IPT_E_MouseDeviceEvent     18
#define IPT_E_NumberOfDeviceEvent  19

struct INO_tdstDevice_;
struct IPT_tdstEntryElement_;
struct IPT_tdstHistoricElement_;

typedef struct IPT_tdstInput_
{
 unsigned char ucOnePadActivate;
 unsigned char p_ucValideAndActiveDevice[IPT_E_NumberOfDeviceEvent];
 struct INO_tdstDevice_ *a_hINODevice[IPT_E_NumberOfDeviceEvent];
 unsigned char p_ucKeyboardCounter[256];
 unsigned char p_ucPadAndJoyCounter[IPT_E_NumberOfDeviceEvent][IPT_E_NumberOfPadAndJoyAction];
 unsigned char ucKeyboardType;
 unsigned char a_ucMouseButtonsCounter[9];
 unsigned char a_ucGap06E8[24];
 unsigned long ulNumberOfEntryElement;
 struct IPT_tdstEntryElement_ *d_stEntryElementArray;
 struct IPT_tdstEntryElement_ *hEntryElement_hFirstElementDyn;
 struct IPT_tdstEntryElement_ *hEntryElement_hLastElementDyn;
 long hEntryElement_lNumberOfElementsDyn;
 short sEventHistoricSize;
 struct IPT_tdstHistoricElement_ *hEventHistoric;
 unsigned char aucPcTail[0xB20 - 0x71C];
} IPT_tdstInput;

typedef char IPT_ct_assert_Input_KeyboardType[(offsetof(IPT_tdstInput, ucKeyboardType) == 0x6DE) ? 1 : -1];
typedef char IPT_ct_assert_Input_EventHistoric[(offsetof(IPT_tdstInput, hEventHistoric) == 0x718) ? 1 : -1];
typedef char IPT_ct_assert_Input_size[(sizeof(IPT_tdstInput) == 0xB20) ? 1 : -1];

#endif
