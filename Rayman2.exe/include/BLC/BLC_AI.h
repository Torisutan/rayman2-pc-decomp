#ifndef BLC_AI_H
#define BLC_AI_H

#include "BLC_Rom64.h"

#pragma pack(push, u64align, 1)

typedef struct U64_stAIModel_
{   U64_tdxIndex    xVariableDeclarationId;
    U64_tdxIndex    xIntelligenceId;
    U64_tdxIndex    xReflexId;

    U64_tdxIndex    xRefId;
    U64_tdxIndex    xRefTreeId;
    U64_tdxIndex    xRefTreeSize;
    U64_tdxIndex    CFast_lFunction;
    U64_tdxIndex    CFast_bIsC;
}   U64_tdstAIModel;

typedef struct U64_stIntelligence_
{   U64_tdxIndex    xComportListId;
    U64_tdxIndex    xComportInitId;
    unsigned short  uwComportNb;
    unsigned short  uwActionTableEntriesNb;
}   U64_tdstIntelligence;

typedef struct U64_stComport_
{   U64_tdxIndex    xScheduleId;
    U64_tdxIndex    xLstRulesId;
    unsigned short  uwRulesNb;
}   U64_tdstComport;

typedef struct U64_stRule_
{   U64_tdxIndex    xLstNodesId;
    unsigned short  uwNodesNb;
}   U64_tdstRule;

#ifndef U64_tdstNode
typedef struct U64_tdstNode_
{   unsigned char  ucType;
    unsigned char  ucDepth;
    unsigned short uwIdOrValue;
}   U64_tdstNode;
#endif

#define D_BINSCR_AIDefinesNameStringLength 64

typedef struct U64_stAIDefines_
{
    char    szString[D_BINSCR_AIDefinesNameStringLength];
    union
    {
        float   fValue;
        long    lValue;
    };
}   U64_stAIDefines;

typedef struct U64_stCharacterBrain_
{   U64_tdxIndex    xAIModelId;
    U64_tdxIndex    xInitComportIntelligenceId;
    U64_tdxIndex    xInitComportReflexId;
    U64_tdxIndex    xInitVariablesId;
}   U64_tdstCharacterBrain;

typedef struct U64_stInitialization_
{   U64_tdxIndex    xLstVarIdId;
    unsigned short  uwVarNb;
}   U64_tdstInitialization;

typedef struct U64_stInitVariable_
{   unsigned short  uwVarId;
    unsigned short  uwType;
    unsigned short  uwValue;
}   U64_tdstInitVariable;

typedef struct U64_stDeclaration_
{
    unsigned short  uwBlockSize;
    U64_tdxIndex    xLstVarId;
    U64_tdxIndex    xLstTypeSaveVarIdId;
    U64_tdxIndex    xLstTypeInitVarIdId;
    unsigned short  uwVarNb;
    unsigned short  uwLstVarNb;
    unsigned short  uwTypeSaveVarNb;
    unsigned short  uwTypeInitVarNb;
}   U64_tdstDeclaration;

typedef struct U64_stDeclarationVariable_
{   unsigned short  uwType;
    unsigned short  uwValue;
    unsigned short  uwOffset;
}   U64_tdstDeclarationVariable;

typedef union
{   float           fVar;
    unsigned long   ulVar;
}   tduFloatOrLong;

typedef struct U64_stArrayEntry_
{   tduFloatOrLong  u;
    unsigned short  uwArrayId;
    unsigned short  uwEntryId;
}   U64_tdstArrayEntry;

typedef struct U64_stTypeVariable_
{   unsigned short  uwVarId;
    unsigned short  uwType;
}   U64_tdstTypeVariable;

typedef struct U64_tdstDsgVarRefBidouille_
{
    unsigned short uwVarIndex;
}   U64_tdstDsgVarRefBidouille;

#pragma pack(pop, u64align)

#define D_BINSCR_StructAIModel              E_StructAIModel
#define D_BINSCR_StructFixAIModel           E_StructFixAIModel
#define D_BINSCR_StructNODFile              E_StructNODFile
#define D_BINSCR_StructIntelligence         E_StructIntelligence
#define D_BINSCR_StructListOfComport        E_StructListOfComport
#define D_BINSCR_StructComport              E_StructComport
#define D_BINSCR_StructFixComport           E_StructFixComport
#define D_BINSCR_StructListOfRules          E_StructListOfRules
#define D_BINSCR_StructRule                 E_StructRule
#define D_BINSCR_StructReflex               E_StructReflex
#define D_BINSCR_StructNode                 E_StructNode
#define D_BINSCR_StructNodeLongList         E_StructNodeLongList
#define D_BINSCR_StructNodeFloatList        E_StructNodeFloatList
#define D_BINSCR_StructNodeVector3DList     E_StructNodeVector3DList
#define D_BINSCR_StructNodeStringList       E_StructNodeStringList
#define D_BINSCR_StructAIDefines            E_StructAIDefines
#define D_BINSCR_StructCharacterBrain       E_StructCharacterBrain
#define D_BINSCR_StructInitialization       E_StructInitialization
#define D_BINSCR_StructInitVariable         E_StructInitVariable
#define D_BINSCR_StructInitVariableIdList   E_StructInitVariableIdList
#define D_BINSCR_StructDeclaration          E_StructDeclaration
#define D_BINSCR_StructDeclarationVariable  E_StructDeclarationVariable
#define D_BINSCR_StructTypeVariable         E_StructTypeVariable
#define D_BINSCR_StructTypeVariableIdList   E_StructTypeVariableIdList
#define D_BINSCR_StructDsgVarRefBidouille   E_StructDsgVarRefBidouille

#endif
