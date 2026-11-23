#ifndef RAYMAN2_SCT_SECTEXT_H
#define RAYMAN2_SCT_SECTEXT_H

#include "SCT/Sector.h"

struct SECT_tdstListOfSOSectorsInActivityInteraction_
{
	HIE_tdstSuperObject *hPointerOfSectorSO;
	LST2_M_StaticElementDeclaration(SECT_tdxHandleOfElementLstActivityInteraction)
};

#ifndef CODEWARRIOR
static
#endif
__inline HIE_tdstSuperObject *SECT_GetCharacterInList(SECT_tdxHandleOfElementLstCharacter hCharacterList)
    { return(hCharacterList->hPointerOfCharacter); }

#ifndef CODEWARRIOR
static
#endif
__inline HIE_tdstSuperObject *SECT_GetSectorInActivityList(SECT_tdxHandleOfElementLstActivityInteraction hActivityList)
    { return(hActivityList->hPointerOfSectorSO); }

#ifndef CODEWARRIOR
static
#endif
__inline char SECT_cGetCounterInSector(HIE_tdstSuperObject *_hSector)
	{ return ((SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSector))->cCounter; }

#ifndef CODEWARRIOR
static
#endif
__inline SECT_tdxHandleOfElementLstCharacter SECT_fn_hGetFirstCharListInSector(HIE_tdstSuperObject *_hSector)
    { return(LST2_M_DynamicGetFirstElement( &((SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSector))->stListOfCharacters)); }

#ifndef CODEWARRIOR
static
#endif
__inline SECT_tdxHandleOfElementLstCharacter SECT_fn_hGetNextCharListInSector(SECT_tdxHandleOfElementLstCharacter _hCharList)
    { return(LST2_M_DynamicGetNextElement( _hCharList)); }

#ifndef CODEWARRIOR
static
#endif
__inline SECT_tdxHandleOfElementLstActivityInteraction SECT_fn_hGetFirstActivityNodeInActivityList(HIE_tdstSuperObject *_hSector)
    { return(LST2_M_StaticGetFirstElement( &((SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(_hSector))->stListOfSectorsInActivityInteraction)); }

#ifndef CODEWARRIOR
static
#endif
__inline SECT_tdxHandleOfElementLstActivityInteraction SECT_fn_hGetNextActivityNodeInActivityList(SECT_tdxHandleOfElementLstActivityInteraction _hActNode)
    { return(LST2_M_StaticGetNextElement( _hActNode)); }

#ifndef CODEWARRIOR
static
#endif
__inline int SECT_fn_iGetNumberOfNodesInActivityInteractionList(HIE_tdstSuperObject *hSector)
{
	return LST2_M_StaticGetNumberOfElements(&((SECT_tdxHandleOfSectorObject)HIE_fn_hGetSuperObjectObject(hSector))->stListOfSectorsInActivityInteraction);
}

#define SECT_M_ForEachCharListInSector(_hSector,_hCharList,_i) \
for														\
(														\
	_i=0,(_hCharList)=SECT_fn_hGetFirstCharListInSector(_hSector);		\
	_hCharList;									\
	_i++,_hCharList=SECT_fn_hGetNextCharListInSector(_hCharList)			\
)

#define SECT_M_ForEachActivityNodeInActivityInteractionList(_hSector,_hActList,_i) \
for														\
(														\
	_i=SECT_fn_iGetNumberOfNodesInActivityInteractionList(_hSector), \
	(_hActList)=SECT_fn_hGetFirstActivityNodeInActivityList(_hSector);		\
	_i>0; 									\
	_i--,(_hActList)=SECT_fn_hGetNextActivityNodeInActivityList(_hActList)			\
)

#endif
