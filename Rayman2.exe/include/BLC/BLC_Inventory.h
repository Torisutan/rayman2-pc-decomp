#ifndef BLC_INVENTORY_H
#define BLC_INVENTORY_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stInvBox_
{   U64_tdxIndex    a4_xDirSuperObjectId[4];
    unsigned short  a2_uwFontOffset[2];
    unsigned short  uwFlags;
}   U64_tdstInvBox;

typedef struct U64_stInstanciatedItem_
{   U64_tdxIndex    xItemId;
    short           wNumber;
    unsigned short  uwFlags;
}   U64_tdstInstanciatedItem;

typedef struct U64_stItem_
{   U64_tdxIndex    xInfo2Id;
    U64_tdxIndex    xModelId;
    U64_tdxIndex    xNextItemToUseId;
    U64_tdxIndex    xAllowedById;
    U64_tdxIndex    xProhibitedById;
    unsigned short  uwInfoId;
    unsigned short  uwMaxCapacity;
    unsigned short  uwFlags;
}   U64_tdstItem;

typedef struct U64_stArrayOfStrings_
{   U64_tdxIndex    xStringLstId;
    unsigned short  uwNbStrings;
}   U64_tdstArrayOfStrings;

#pragma pack(pop, u64align)

#define D_BINSCR_InvBox_Left  0
#define D_BINSCR_InvBox_Right 1
#define D_BINSCR_InvBox_Up    2
#define D_BINSCR_InvBox_Down  3
#define D_BINSCR_InvBox_FontOffsetX 0
#define D_BINSCR_InvBox_FontOffsetY 1
#define D_BINSCR_InvBox_Rot (1 << 0)

#define D_BINSCR_InstanciatedItem_Selected (1 << 0)
#define D_BINSCR_InstanciatedItem_Rot      (1 << 1)

#define D_BINSCR_Item_DrawWhenZero      (1 << 0)
#define D_BINSCR_Item_RestWhenZero      (1 << 1)
#define D_BINSCR_Item_Available         (1 << 2)
#define D_BINSCR_Item_NextExtCondition  (1 << 3)
#define D_BINSCR_Item_AllowedPermission (1 << 4)
#define D_BINSCR_Item_DrawCounter       (1 << 5)

#define D_BINSCR_StructInvBox            E_StructInvBox
#define D_BINSCR_StructInstanciatedItem  E_StructInstanciatedItem
#define D_BINSCR_StructItem              E_StructItem
#define D_BINSCR_StructItemStringList    E_StructItemStringList
#define D_BINSCR_StructArrayOfStrings    E_StructArrayOfStrings
#define D_BINSCR_StructStringLst         E_StructStringLst

#endif
