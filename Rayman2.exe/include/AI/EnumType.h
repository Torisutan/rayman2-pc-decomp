#if !defined(__ENUM_TYPE_H__)
#define  __ENUM_TYPE_H__

#define M_DEFINE_TYPE_INTERPRET(a,b,c,d) a,

typedef enum tdeTypeInterpret_
{
  #include "DefType.h"

  E_ti_NbTypes

} tdeTypeInterpret;

#undef M_DEFINE_TYPE_INTERPRET

#endif
