#include "GAM/ObjType.h"

/* 0x00407B00 */
char *__cdecl fn_szFindPersonalTypeNameOfPersonalType(long otType)
{
 tdhHandleToObjectTypeElement hHandleToObjectTypeElement;
 unsigned long i;

 LST2_M_DynamicGetElementNumber(&g_stObjectTypes.hPersonalType,hHandleToObjectTypeElement,(unsigned long)otType,i);

 if (hHandleToObjectTypeElement)
  return(hHandleToObjectTypeElement->szName);
 else
  return(NULL);
}
