#ifndef AI_DSGMEM_H
#define AI_DSGMEM_H

#include "GAM/InitEnum.h"

#define C_TypeOfComport			struct AI_tdstComport_ *
#define C_SizeOfComport			(sizeof(C_TypeOfComport))

#define C_TypeOfAction			struct tdstState_ *
#define C_SizeOfAction			(sizeof(C_TypeOfAction))

#define C_TypeOfText			long
#define C_SizeOfText			(sizeof(C_TypeOfText))

#define C_TypeOfBoolean			char
#define C_SizeOfBoolean			(sizeof (C_TypeOfBoolean))

#define C_TypeOf_128To127		char
#define C_SizeOf_128To127		(sizeof (C_TypeOf_128To127))

#define C_TypeOf0To255			unsigned char
#define C_SizeOf0To255			(sizeof (C_TypeOf0To255))

#define C_TypeOf_32768To32767	short
#define C_SizeOf_32768To32767	(sizeof (C_TypeOf_32768To32767))

#define C_TypeOf0To65535		unsigned short
#define C_SizeOf0To65535		(sizeof (C_TypeOf0To65535))

#define C_TypeOfInteger			long
#define C_SizeOfInteger			(sizeof (C_TypeOfInteger))

#define C_TypeOfPositiveInteger	unsigned long
#define C_SizeOfPositiveInteger	(sizeof (C_TypeOfInteger))

#define C_TypeOfFloat			MTH_tdxReal
#define C_SizeOfFloat			(sizeof (C_TypeOfFloat))

#define C_TypeOfWayPoint		struct WP_tdstWayPoint_ *
#define C_SizeOfWayPoint		(sizeof (C_TypeOfWayPoint))

#define C_TypeOfPerso			struct HIE_tdstSuperObject *
#define C_SizeOfPerso			(sizeof (C_TypeOfPerso))

#if !defined(U64) && !defined(NITRO)
#define C_TypeOfSuperObject		struct HIE_tdstSuperObject *
#define C_SizeOfSuperObject		(sizeof (C_TypeOfPerso))
#endif

#define C_TypeOfPersoInList		struct HIE_tdstSuperObject *
#define C_SizeOfPersoInList		(sizeof (C_TypeOfPersoInList))

#define C_TypeOfList1			struct tdstList1_
#define C_SizeOfList1			(sizeof (C_TypeOfList1))

#define C_TypeOfVector			struct MTH3D_tdstVector_
#define C_SizeOfVector			(sizeof (C_TypeOfVector))

#define C_TypeOfGameMaterial	struct GMT_tdstGameMaterial_ *
#define C_SizeOfGameMaterial	(sizeof(C_TypeOfGameMaterial))

#define C_TypeOfCaps		unsigned long
#define C_SizeOfCaps		(sizeof (C_TypeOfCaps))

#define C_TypeOfGraph		struct WP_tdstGraph_ *
#define C_SizeOfGraph		(sizeof (C_TypeOfGraph))

#include "AI/EnumVar.h"

typedef struct AI_tdstDsgVarInfo_
{
    unsigned long ulOffsetInDsgMem;
    tdeDsgVarTypeId eDsgVarTypeId;
    unsigned long eSaveType;
    tdeObjectTreeInit eInitType;
} AI_tdstDsgVarInfo;

struct AI_tdstDsgVar_
{
    char              *p_cDsgMemDefaultInit;
    AI_tdstDsgVarInfo *p_stDsgVarInfo;
    unsigned long      ulSize;
    unsigned char      ucNbDsgVar;
};

#define AI_M_GetDsgVarModel(p_stMind)           ((p_stMind)->p_stAIModel->p_stDsgVar)

#define AI_M_p_stGetDsgMem(p_stMind)            ((p_stMind)->p_stDsgMem)

#define M_GetDsgMem(p_stMind)              (AI_M_p_stGetDsgMem(p_stMind))
#define M_GetDsgMemBuffer(p_stMind)        (AI_M_p_stGetDsgMem(p_stMind)->p_cDsgMemBuffer)

#define M_GetDsgVar(p_stMind)              (*(AI_M_p_stGetDsgMem(p_stMind)->p_p_stDsgVar))
#define M_GetDsgVarInfo(p_stMind,ucId)     (&(M_GetDsgVar(p_stMind)->p_stDsgVarInfo[ucId]))
#define M_GetDsgVarOffset(p_stMind,ucId)   (M_GetDsgVarInfo(p_stMind,ucId)->ulOffsetInDsgMem)
#define M_GetDsgVarAddr(p_stMind,ucId)     (M_GetDsgMemBuffer(p_stMind)+M_GetDsgVarOffset(p_stMind,ucId))

#define M_GetDsgVarType(p_stMind,ucId)     (M_GetDsgVarInfo(p_stMind,ucId)->eDsgVarTypeId)
#define M_GetDsgVarSaveType(p_stMind,ucId) (M_GetDsgVarInfo(p_stMind,ucId)->eSaveType)
#define M_GetDsgVarInitType(p_stMind,ucId) (M_GetDsgVarInfo(p_stMind,ucId)->eInitType)

#define M_GetDsgVarSize(p_stMind)              (AI_M_GetDsgVarModel(p_stMind)->ulSize)
#define M_GetNbDsgVar(p_stMind)                (AI_M_GetDsgVarModel(p_stMind)->ucNbDsgVar)

#define M_GetDsgMemDefaultInit(p_stMind)       (AI_M_GetDsgVarModel(p_stMind)->p_cDsgMemDefaultInit)
#define M_GetDsgMemBufferInit(p_stMind)        (AI_M_p_stGetDsgMem(p_stMind)->p_cDsgMemBufferInit)

#define M_GetDsgVarAddrInit(p_stMind,ucId)     (M_GetDsgMemBufferInit(p_stMind)+M_GetDsgVarOffset(p_stMind,ucId))
#define M_GetDsgVarAddrDefault(p_stMind,ucId)  (M_GetDsgMemDefaultInit(p_stMind)+M_GetDsgVarOffset(p_stMind,ucId))

#define C_ucSizeOfMinimalArray 2
#define C_ucSizeOfMaximalArray 255

#define C_TypeOfArray1			struct tdstArray1_
#define C_SizeOfArray1			(sizeof (C_TypeOfArray1))

#define M_ARRAY_TYPE(array)			((array)->eType)
#define M_ARRAY_SIZE(array)			((array)->ucMaxSize)

  #define ARRAY_FACTOR 3
  #define C_TypeOfArrayElement	    AI_tduGetSetParamForNode
  #define C_SizeOfArrayElement	    (sizeof(C_TypeOfArrayElement))
  #define M_ARRAY_ELEMENT(array,n)	(&((array)->d_ArrayElement[(M_ARRAY_TYPE(array)==eDsgVarType_Vector)?ARRAY_FACTOR*n:n]))

typedef struct tdstArray1_
{

  enum tdeDsgVarTypeId_ eType;

  unsigned char ucMaxSize;

  C_TypeOfArrayElement d_ArrayElement[1];
} tdstArray1;

typedef struct tdstArray_
{

  enum tdeDsgVarTypeId_ eType;

  unsigned char ucMaxSize;

  C_TypeOfArrayElement d_ArrayElement[C_ucSizeOfMaximalArray];
} tdstArray;

#endif
