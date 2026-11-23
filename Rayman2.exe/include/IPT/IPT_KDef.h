#if !defined(__IPT_KDef_H__)
#define __IPT_KDef_H__

enum IPT_E_PadEvent_
{
 IPT_E_FirstPadAction = 0x00,
 IPT_E_PadUp          = IPT_E_FirstPadAction,
 IPT_E_PadDown,
 IPT_E_PadLeft,
 IPT_E_PadRight,
 IPT_E_JoyXValue,
 IPT_E_JoyYValue,
 IPT_E_JoyZValue,
 IPT_E_JoyRValue,
 IPT_E_JoyUValue,
 IPT_E_JoyVValue,
 IPT_E_PadFirstButton,
 IPT_E_PadButton0     = IPT_E_PadFirstButton,
 IPT_E_PadButton1,
 IPT_E_PadButton2,
 IPT_E_PadButton3,
 IPT_E_PadButton4,
 IPT_E_PadButton5,
 IPT_E_PadButton6,
 IPT_E_PadButton7,
 IPT_E_PadButton8,
 IPT_E_PadButton9,
 IPT_E_PadButton10,
 IPT_E_PadButton11,
 IPT_E_PadButton12,
 IPT_E_PadButton13,
 IPT_E_PadButton14,
 IPT_E_PadButton15,
 IPT_E_PadButton16,
 IPT_E_PadButton17,
 IPT_E_PadButton18,
 IPT_E_PadButton19,
 IPT_E_PadButton20,
 IPT_E_PadButton21,
 IPT_E_PadButton22,
 IPT_E_PadButton23,
 IPT_E_PadButton24,
 IPT_E_PadButton25,
 IPT_E_PadButton26,
 IPT_E_PadButton27,
 IPT_E_PadButton28,
 IPT_E_PadButton29,
 IPT_E_PadButton30,
 IPT_E_PadButton31,
 IPT_E_PadLastButton    = IPT_E_PadButton31,
 IPT_E_JoyFirstButton,
 IPT_E_JoyButton0     = IPT_E_JoyFirstButton,
 IPT_E_JoyButton1,
 IPT_E_JoyButton2,
 IPT_E_JoyButton3,
 IPT_E_JoyButton4,
 IPT_E_JoyButton5,
 IPT_E_JoyButton6,
 IPT_E_JoyButton7,
 IPT_E_JoyButton8,
 IPT_E_JoyButton9,
 IPT_E_JoyButton10,
 IPT_E_JoyButton11,
 IPT_E_JoyButton12,
 IPT_E_JoyButton13,
 IPT_E_JoyButton14,
 IPT_E_JoyButton15,
 IPT_E_JoyButton16,
 IPT_E_JoyButton17,
 IPT_E_JoyButton18,
 IPT_E_JoyButton19,
 IPT_E_JoyButton20,
 IPT_E_JoyButton21,
 IPT_E_JoyButton22,
 IPT_E_JoyButton23,
 IPT_E_JoyButton24,
 IPT_E_JoyButton25,
 IPT_E_JoyButton26,
 IPT_E_JoyButton27,
 IPT_E_JoyButton28,
 IPT_E_JoyButton29,
 IPT_E_JoyButton30,
 IPT_E_JoyButton31,
 IPT_E_JoyLastButton    = IPT_E_JoyButton31,
 IPT_E_NumberOfPadAndJoyAction
};

typedef struct IPT_tdstScriptValue_ * IPT_tdxHandleToScriptValue;

struct IPT_tdstScriptValue_
{
 signed short swKeyValue;
};

struct IPT_tdstConvertValue_
{
 signed short swAZERTYKeyValue;
 signed short swQWERTYKeyValue;
};

extern struct IPT_tdstConvertValue_ IPT_g_ConvertAZERTYtoQWERTY[];
extern struct IPT_tdstScriptValue_ IPT_g_hScriptKeyValue[];
extern struct IPT_tdstScriptValue_ IPT_g_hScriptPadValue[];
extern unsigned long IPT_g_ulPadAndJoyButtonFlag[];

#endif
