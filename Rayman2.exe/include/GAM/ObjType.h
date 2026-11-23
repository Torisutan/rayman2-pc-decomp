#ifndef RAYMAN2_GAM_OBJTYPE_H
#define RAYMAN2_GAM_OBJTYPE_H

#include "LST/LstDef2.h"
#include "GAM/GAM_globals.h"

typedef struct tdstObjectTypeElement_ *tdhHandleToObjectTypeElement;

LST2_M_DynamicUseListOf(tdhHandleToObjectTypeElement);

typedef struct tdstObjectTypeElement_
{
 LST2_M_DynamicElementDeclaration(tdhHandleToObjectTypeElement)
 char *szName;
 unsigned char ucElementPriority;
} tdstObjectTypeElement;

typedef struct tdstObjectType_
{
 LST2_M_DynamicAnchorDeclaration(tdhHandleToObjectTypeElement) hFamilyType;
 LST2_M_DynamicAnchorDeclaration(tdhHandleToObjectTypeElement) hModelType;
 LST2_M_DynamicAnchorDeclaration(tdhHandleToObjectTypeElement) hPersonalType;
} tdstObjectType;

#define g_stObjectTypes (*(tdstObjectType *)GAM_g_aucObjectTypes)

#endif
