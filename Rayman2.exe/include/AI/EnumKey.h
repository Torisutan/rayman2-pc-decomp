#if !defined(__ENUM_KEY_H__)
#define __ENUM_KEY_H__

#define M_DEFINE_KEYWORD(a,b,english,c,d,e,f) a,

typedef enum tdeKeyWordId_
{
  #include "AI/DefKey.h"

  eNbKeyWord

} tdeKeyWordId;

#undef M_DEFINE_KEYWORD

#endif
