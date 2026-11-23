#ifndef BLC_MISC_H
#define BLC_MISC_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_tdstInputAction_
{   U64_tdxIndex    xLstIptId;
    unsigned short  uwEltNb;
    unsigned short  uwKeyWordEltNb;
}   U64_tdstInputAction;

typedef signed short tdElementOfIptList;

typedef struct U64_tdstIptLink_
{   U64_tdxIndex    xLstIptLinkId;
    unsigned short  uwEltNb;
}   U64_tdstIptLink;

typedef unsigned short tdElementOfIptLinkList;

typedef unsigned short td_uwNbOfLanguages;

typedef struct U64_tdstFontStringLength_
{   unsigned short uwLength;
}   U64_tdstFonStringLength;

typedef struct U64_stString_
{
    unsigned short  uwLength;
    U64_tdxIndex    xId;
}   U64_tdstString;

typedef struct U64_stStringChunk_
{   char acChar[2];
}   U64_tdstStringChunk;

typedef struct U64_tdstTextString_
{   U64_tdstString szU64String;
}   U64_tdstTextString;

typedef struct U64_tdstLanguageString_
{
    U64_tdxIndex    xStringLstIndexId;
    unsigned short  uwStringLstIndexNb;
    U64_tdxIndex    xStringLengthLstIndexId;
    unsigned short  uwStringLengthLstIndexNb;
    unsigned short  uwLanguage;
    char            szLanguageName[18];
}   U64_tdstLanguageString;

typedef struct U64_stFixDisplay_
{
    U64_tdxIndex    xFixFontId;
    U64_tdxIndex    xFixFont3DId;
    U64_tdxIndex    xFontText3DId;
    U64_tdxIndex    xHitPointsFirstLineId;
    U64_tdxIndex    xHitPointsSecondLineId;
    U64_tdxIndex    xSilverSpadeId;
    U64_tdxIndex    xSilverSpadeNumberId;
    U64_tdxIndex    xGameSaveId;
    unsigned short  uwFixFontType;
    unsigned short  uwFixFont3DType;
    unsigned short  uwFontText3DType;
    unsigned short  uwHitPointsFirstLineType;
    unsigned short  uwHitPointsSecondLineType;
    unsigned short  uwSilverSpadeType;
    unsigned short  uwSilverSpadeNumberType;
    unsigned short  uwGameSaveType;
}   U64_tdstFixDisplay;

typedef struct U64_stArrayOfZoneSet
{   U64_tdxIndex    xLstZoneSetId;
    unsigned short  uwZoneSetNb;
}   U64_tdstArrayOfZoneSet;

typedef struct U64_stActivationZone_
{   U64_tdxIndex    xLstZdxIndexId;
    unsigned short  uwZdxIndexNb;
}   U64_tdstActivationZone;

typedef struct U64_stZoneSet_
{   U64_tdxIndex    xActivationZoneId;
    U64_tdxIndex    xStateId;
}   U64_tdstZoneSet;

typedef struct U64_stChannelName_
{   U64_tdxIndex    xStringListId;
    unsigned short  uwStringListNb;
}   U64_tdstChannelName;

typedef struct U64_stChannelNameString_
{   char    szString[64];
}   U64_tdstChannelNameString;

typedef struct U64_stBkGrdInfo_
{
    unsigned long   ulCompressSize;
    U64_tdxIndex    xBkGrdId;
    unsigned short  uwNbPalettes;
    U64_tdxIndex    xLstPaletteIdId;
    char            szName[14];
}   U64_tdstBkGrdInfo;

typedef unsigned short tdElementOfBkGrdPaletteList;

#pragma pack(pop, u64align)

#define Cuw_FirstElt                       0xFFFF
#define D_BINSCR_AIDefinesNameStringLength_CHL 64
#define D_BINSCR_StringSize                256

#define D_BINSCR_StructLanguageFrench   0x00
#define D_BINSCR_StructLanguageEnglish  0x01
#define D_BINSCR_StructLanguageGerman   0x02
#define D_BINSCR_StructLanguageItalian  0x04
#define D_BINSCR_StructLanguageSpanish  0x08
#define D_BINSCR_StructLanguageCommon   0x10

#define D_BINSCR_StructInputAction       E_StructInputAction
#define D_BINSCR_StructFixInputAction    E_StructFixInputAction
#define D_BINSCR_StructIptList           E_StructIptList
#define D_BINSCR_StructIptLink           E_StructIptLink
#define D_BINSCR_StructIptLinkList       E_StructIptLinkList
#define D_BINSCR_StructStringChunk       E_StructStringChunk
#define D_BINSCR_StructNbOfLanguages     E_StructNbOfLanguages
#define D_BINSCR_StructLanguageString    E_StructLanguageString
#define D_BINSCR_StructTextString        E_StructTextString
#define D_BINSCR_StructStringLength      E_StructStringLength
#define D_BINSCR_StructStringLengthLst   E_StructStringLengthLst
#define D_BINSCR_StructTextStringLst     E_StructTextStringLst
#define D_BINSCR_StructLanguageStringLst E_StructLaguageStringLst
#define D_BINSCR_StructFixDisplay        E_StructFixDisplay
#define D_BINSCR_StructArrayOfZoneSet    E_StructArrayOfZoneSet
#define D_BINSCR_StructActivationZone    E_StructActivationZone
#define D_BINSCR_StructLstZdxIndex       E_StructLstZdxIndex
#define D_BINSCR_StructLstZoneSet        E_StructLstZoneSet
#define D_BINSCR_StructChannelName       E_StructChannelName
#define D_BINSCR_StructChannelNameString E_StructChannelNameString
#define D_BINSCR_StructBkGrdInfo         E_StructBkGrdInfo
#define D_BINSCR_StructBkGrdCI8          E_StructBkGrdCI8
#define D_BINSCR_StructBkGrdPaletteList  E_StructBkGrdPalletteList
#define D_BINSCR_StructVigNb             E_StructVigNb
#define D_BINSCR_StructCPakFont          E_StructCPakFont
#define D_BINSCR_StructSndEventIdList    E_StructSndEventIdList

#endif
