#pragma once

typedef struct FON_tdstLanguage_ {
    char          **d_pTextsArray;
    unsigned short  uwMaxNumberOfTexts;
    unsigned short  uwNumberOfTexts;
} FON_tdstLanguage;

typedef struct FON_tdstGeneral_ {
    unsigned long      ulElapsedTime;
    unsigned long      hRandomHandle;
    unsigned short     uwNumberOfLanguages;

    FON_tdstLanguage  *d_sLanguageArray;
    FON_tdstLanguage  *p_stCommonLanguage;
} FON_tdstGeneral;

typedef long FON_tdxHandleOfText;

#define FON_C_xInvalidTextHandle            ((FON_tdxHandleOfText)-1)
#define FON_C_HandleOffsetForCommonLanguage 20000
