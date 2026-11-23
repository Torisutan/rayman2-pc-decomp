#ifndef RAYMAN2_AI_LIST_H
#define RAYMAN2_AI_LIST_H

#define C_ucSizeOfMinimalList 2
#define C_ucSizeOfMaximalList 30
#define C_ucEndOfList 255

#define C_TypeOfPersoInList		struct HIE_tdstSuperObject *
#define C_SizeOfPersoInList		(sizeof (C_TypeOfPersoInList))

#define C_TypeOfList1			struct tdstList1_
#define C_SizeOfList1			(sizeof (C_TypeOfList1))

#define M_Min(a,b) (((a)>(b)) ? (b) : (a))

#define M_bListEmptyTest(p_List) (((p_List)->ucNbElt) == 0)
#define M_ucNbEltInList(p_List) ((p_List)->ucNbElt)
#define M_ucGetMaxSizeOfList(p_List) ((p_List)->ucMaxSize)
#define M_ClearList(p_List) (p_List)->ucNbElt = 0;
#define M_InitList(p_List, ucNbEltMax) \
{\
	M_ClearList(p_List);\
	(p_List)->ucMaxSize = ucNbEltMax;\
}

typedef struct tdstList1_ {
	unsigned char ucNbElt;
	unsigned char ucMaxSize;
	struct HIE_tdstSuperObject *d_TabElt[1];
} tdstList1;

typedef struct tdstList_ {
	unsigned char ucNbElt;
	unsigned char ucMaxSize;
	struct HIE_tdstSuperObject *d_TabElt[C_ucSizeOfMaximalList];
} tdstList;

void *__cdecl fn_p_stGetPersoInList(void *p_List, unsigned char ucPosition);   /* 0x004838F0 */

/* 0x004831D0 */
unsigned char __cdecl fn_bFindPersoInList(void *p_List, void *p_Perso);

/* 0x00483210 */
unsigned char __cdecl fn_bFindModelInList(void *p_List, void *_p_stModel);

/* 0x00483260 */
unsigned char __cdecl fn_bFindFamilyInList(void *p_List, void *hFamily);

void __cdecl fn_vPutInList(void *p_List, void *p_Perso);                       /* 0x00483120 */
void __cdecl fn_vInsertPersoAtPositionInList(void *p_List, void *p_Perso, unsigned char ucPosition); /* 0x00483150 */
void __cdecl fn_vDeletePersoAtPositionInList(void *p_List, unsigned char ucPosition);  /* 0x00483340 */
char __cdecl fn_bFindPersoAndDeleteInList(void *p_List, void *p_Perso);        /* 0x004832B0 */
void __cdecl fn_vUnionList(void *p_ListA, void *p_ListB, void *p_ListC);       /* 0x00483510 */
void __cdecl fn_vInterList(void *p_ListA, void *p_ListB, void *p_ListC);       /* 0x004835D0 */
void __cdecl fn_vDiffList(void *p_ListA, void *p_ListB, void *p_ListC);        /* 0x00483640 */
void __cdecl fn_vAddList(void *p_ListA, void *p_ListB);                        /* 0x004836C0 */
void __cdecl fn_vSortListByFamily(void *p_List, void *hFamily);                /* 0x004833D0 */
void __cdecl fn_vSortListByModel(void *p_stList, void *_p_stModel);            /* 0x00483460 */

#endif
