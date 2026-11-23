#if !defined(__ENUM_VAR_H__)
#define __ENUM_VAR_H__

#define M_DEFINE_DSGVAR_TYPE(a,b,c,d,e,f,g,h,i,j) a,

typedef enum tdeDsgVarTypeId_
{
  #include "AI/DefVar.h"

  eNbDsgVarType

} tdeDsgVarTypeId;

#undef M_DEFINE_DSGVAR_TYPE

#endif
