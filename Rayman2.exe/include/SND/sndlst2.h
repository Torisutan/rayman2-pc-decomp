#ifndef SND_SNDLST2_H
#define SND_SNDLST2_H

#define SNDLST2_M_StaticGetFirstElement(hAnchor)            ((hAnchor)->hFirstElementOpt)
#define SNDLST2_M_StaticGetNumberOfElements(hAnchor)        ((hAnchor)->lNumberOfElementsOpt)

#define SNDLST2_M_StaticSetMember(handle, member, value)    {(handle)->member##Opt=(value);}
#define SNDLST2_M_StaticSetFirstElement(hAnchor, value)     SNDLST2_M_StaticSetMember((hAnchor), hFirstElement, (value))
#define SNDLST2_M_StaticSetNumberOfElements(hAnchor, value) SNDLST2_M_StaticSetMember((hAnchor), lNumberOfElements, (value))
#define SNDLST2_M_StaticGetNextElement(_hElement)           ((_hElement)+1)
#define SNDLST2_M_StaticGetElementNumber(_hAnchor, _hElement, _k, _i) \
{(_hElement)=SNDLST2_M_StaticGetFirstElement(_hAnchor)+(_k);(_i)=0;}
#define SNDLST2_M_StaticForEachElementOf(_hAnchor, _hElement, _i) \
for((_hElement)=SNDLST2_M_StaticGetFirstElement(_hAnchor),(_i)=0;   \
    (_i)<SNDLST2_M_StaticGetNumberOfElements(_hAnchor);             \
    (_i)++,(_hElement)=SNDLST2_M_StaticGetNextElement(_hElement))

#define SNDLST2_C_DynamicInvalid									        SNDLST2_C_DoubleLinkInvalid
#define SNDLST2_M_DynamicAnchorTo(TypeElement)						SNDLST2_M_AnchorTo(Dyn, TypeElement)
#define SNDLST2_M_DynamicUseListOf(type)							    SNDLST2_M_DoubleLinkUseListOf(Dyn, type)
#define SNDLST2_M_DynamicGetMember(handle, member)				SNDLST2_M_DoubleLinkGetMember(Dyn, handle, member)
#define SNDLST2_M_DynamicSetMember(handle, member, value)			SNDLST2_M_DoubleLinkSetMember(Dyn, handle, member, value)
#define SNDLST2_M_DynamicAnchorDeclaration(TypeElement)	SNDLST2_M_DoubleLinkAnchorDeclaration(Dyn, TypeElement)
#define SNDLST2_M_DynamicParentDeclaration(TypeElement)	SNDLST2_M_DoubleLinkParentDeclaration(Dyn, TypeElement)
#define SNDLST2_M_DynamicGetFirstElement(hAnchor)				SNDLST2_M_DoubleLinkGetFirstElement(Dyn, hAnchor)
#define SNDLST2_M_DynamicGetLastElement(hAnchor)					SNDLST2_M_DoubleLinkGetLastElement(Dyn, hAnchor)
#define SNDLST2_M_DynamicGetNumberOfElements(hAnchor)		SNDLST2_M_DoubleLinkGetNumberOfElements(Dyn, hAnchor)
#define SNDLST2_M_DynamicSetFirstElement(hAnchor, value)	SNDLST2_M_DoubleLinkSetFirstElement(Dyn, hAnchor, value)
#define SNDLST2_M_DynamicSetLastElement(hAnchor, value)	SNDLST2_M_DoubleLinkSetLastElement(Dyn, hAnchor, value)
#define SNDLST2_M_DynamicInitAnchor(hAnchor)						  SNDLST2_M_DoubleLinkInitAnchor(Dyn, hAnchor)
#define SNDLST2_M_DynamicElementDeclaration(TypeElement)	SNDLST2_M_DoubleLinkElementDeclaration(Dyn, TypeElement)
#define SNDLST2_M_DynamicChildDeclaration(TypeElement, TypeParent)	SNDLST2_M_DoubleLinkChildDeclaration(Dyn, TypeElement, TypeParent)
#define SNDLST2_M_DynamicGetNextElement(hElement)				SNDLST2_M_DoubleLinkGetNextElement(Dyn, hElement)
#define SNDLST2_M_DynamicGetPrevElement(hElement)				SNDLST2_M_DoubleLinkGetPrevElement(Dyn, hElement)
#define SNDLST2_M_DynamicGetFather(hElement)						  SNDLST2_M_DoubleLinkGetFather(Dyn, hElement)
#define SNDLST2_M_DynamicSetNextElement(hElement, value)	SNDLST2_M_DoubleLinkSetNextElement(Dyn, hElement, value)
#define SNDLST2_M_DynamicSetPrevElement(hElement, value)	SNDLST2_M_DoubleLinkSetPrevElement(Dyn, hElement, value)
#define SNDLST2_M_DynamicSetFather(hElement, value)			SNDLST2_M_DoubleLinkSetFather(Dyn, hElement, value)
#define SNDLST2_M_DynamicInitElement(hElement)						SNDLST2_M_DoubleLinkInitElement(Dyn, hElement)
#define SNDLST2_M_DynamicAddTail(hAnchor, hElement)			SNDLST2_M_DoubleLinkAddTail(Dyn, hAnchor, hElement)
#define SNDLST2_M_DynamicAddHead(hAnchor, hElement)			SNDLST2_M_DoubleLinkAddHead(Dyn, hAnchor, hElement)
#define SNDLST2_M_DynamicInsertBetween(hElement,hPrevElement,hNextElement)	SNDLST2_M_DoubleLinkInsertBetween(Dyn, hElement,hPrevElement,hNextElement)
#define SNDLST2_M_DynamicIsolate(hElement)							  SNDLST2_M_DoubleLinkIsolate(Dyn, hElement)
#define SNDLST2_M_DynamicForEachElementOf(hAnchor, hElement, i)		    SNDLST2_M_DoubleLinkForEachElementOf(Dyn, hAnchor, hElement, i)
#define SNDLST2_M_DynamicForEachMovingElementOf(hAnchor, hElement, hNextElement, i)	SNDLST2_M_DoubleLinkForEachMovingElementOf(Dyn, hAnchor, hElement, hNextElement, i)

#define SNDLST2_C_DoubleLinkInvalid 0

#define SNDLST2_M_DoubleLinkGetMember(n, handle, member)			\
((handle)->member##n)

#define SNDLST2_M_DoubleLinkSetMember(n, handle, member, value)	\
{(handle)->member##n=(value);}

#define SNDLST2_M_AnchorTo(n, TypeElement) struct LST2_tdstAnchorTo##TypeElement##n

#define SNDLST2_M_DoubleLinkUseListOf(n, TypeElement)							\
SNDLST2_M_AnchorTo(n, TypeElement)										\
{																\
	TypeElement hFirstElement##n;								\
	TypeElement hLastElement##n;								\
	long lNumberOfElements##n;									\
}

#define SNDLST2_M_DoubleLinkParentDeclaration(n, TypeElement)							\
	TypeElement hFirstElement##n;								\
	TypeElement hLastElement##n;								\
	long lNumberOfElements##n;

#define SNDLST2_M_DoubleLinkAnchorDeclaration(n, TypeElement)		\
SNDLST2_M_AnchorTo(n, TypeElement)

#define SNDLST2_M_DoubleLinkGetFirstElement(n, hAnchor)				\
SNDLST2_M_DoubleLinkGetMember(n, hAnchor, hFirstElement)

#define SNDLST2_M_DoubleLinkGetLastElement(n, hAnchor)				\
SNDLST2_M_DoubleLinkGetMember(n, hAnchor, hLastElement)

#define SNDLST2_M_DoubleLinkSetFirstElement(n, hAnchor, value)		\
SNDLST2_M_DoubleLinkGetMember(n, hAnchor, hFirstElement) = (value)

#define SNDLST2_M_DoubleLinkGetNumberOfElements(n, hAnchor)		\
SNDLST2_M_DoubleLinkGetMember(n, hAnchor, lNumberOfElements)

#define SNDLST2_M_DoubleLinkSetLastElement(n, hAnchor, value)		\
SNDLST2_M_DoubleLinkGetMember(n, hAnchor, hLastElement) = (value)

#define SNDLST2_M_DoubleLinkInitAnchor(n, hAnchor)				\
{													\
	SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor))= SNDLST2_C_DoubleLinkInvalid;		\
	SNDLST2_M_DoubleLinkGetLastElement(n, (hAnchor)) = SNDLST2_C_DoubleLinkInvalid;		\
	SNDLST2_M_DoubleLinkGetNumberOfElements(n, (hAnchor))= 0;								\
}

#define SNDLST2_M_DoubleLinkElementDeclaration(n, TypeElement)	\
TypeElement hNextBrother##n;								\
TypeElement hPrevBrother##n;								\
SNDLST2_M_AnchorTo(n, TypeElement)* hFather##n;

#define SNDLST2_M_DoubleLinkChildDeclaration(n, TypeElement, TypeFather)	\
TypeElement hNextBrother##n;								\
TypeElement hPrevBrother##n;								\
TypeFather hFather##n;

#define SNDLST2_M_DoubleLinkGetNextElement(n, hElement)	\
SNDLST2_M_DoubleLinkGetMember(n, (hElement), hNextBrother)

#define SNDLST2_M_DoubleLinkGetPrevElement(n, hElement)	\
SNDLST2_M_DoubleLinkGetMember(n, (hElement), hPrevBrother)

#define SNDLST2_M_DoubleLinkGetFather(n, hSO) \
SNDLST2_M_DoubleLinkGetMember(n, (hSO), hFather)

#define SNDLST2_M_DoubleLinkSetNextElement(n, hElement, value)	\
SNDLST2_M_DoubleLinkGetMember(n, (hElement), hNextBrother) = (value)

#define SNDLST2_M_DoubleLinkSetPrevElement(n, hElement, value)	\
SNDLST2_M_DoubleLinkGetMember(n, (hElement), hPrevBrother) = (value)

#define SNDLST2_M_DoubleLinkSetFather(n, hSO, value) \
SNDLST2_M_DoubleLinkGetMember(n, (hSO), hFather) = (value)

#define SNDLST2_M_DoubleLinkInitElement(n, hElement)				\
{												\
	SNDLST2_M_DoubleLinkGetNextElement(n, (hElement))= SNDLST2_C_DoubleLinkInvalid;	\
	SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement))= SNDLST2_C_DoubleLinkInvalid;	\
	SNDLST2_M_DoubleLinkGetFather(n, (hElement))   = SNDLST2_C_DoubleLinkInvalid;	\
}

#define SNDLST2_M_DoubleLinkIsolate(n, hElement)											\
{																			\
	if(SNDLST2_M_DoubleLinkGetNextElement(n, (hElement))!=SNDLST2_C_DoubleLinkInvalid)							\
		SNDLST2_M_DoubleLinkGetPrevElement(n, SNDLST2_M_DoubleLinkGetNextElement(n, (hElement)))  = SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement));	\
	if(SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement))!=SNDLST2_C_DoubleLinkInvalid)							\
		SNDLST2_M_DoubleLinkGetNextElement(n, SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement))) = SNDLST2_M_DoubleLinkGetNextElement(n, (hElement));	\
	if(SNDLST2_M_DoubleLinkGetFather(n, (hElement))!=SNDLST2_C_DoubleLinkInvalid)								\
	{																							\
		SNDLST2_M_DoubleLinkGetNumberOfElements(n, SNDLST2_M_DoubleLinkGetFather(n, (hElement)))--;		\
		if(SNDLST2_M_DoubleLinkGetFirstElement(n, SNDLST2_M_DoubleLinkGetFather(n, (hElement)))==(hElement))	\
			SNDLST2_M_DoubleLinkGetFirstElement(n, SNDLST2_M_DoubleLinkGetFather(n, (hElement))) = SNDLST2_M_DoubleLinkGetNextElement(n, (hElement));	\
		if(SNDLST2_M_DoubleLinkGetLastElement(n, SNDLST2_M_DoubleLinkGetFather(n, (hElement)))==(hElement))	\
			SNDLST2_M_DoubleLinkGetLastElement(n, SNDLST2_M_DoubleLinkGetFather(n, (hElement))) = SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement));	\
	}																		\
	SNDLST2_M_DoubleLinkInitElement(n, (hElement));											\
}

#define SNDLST2_M_DoubleLinkAddTail(n, hAnchor, hElement)							\
{																			\
	SNDLST2_M_DoubleLinkIsolate(n, (hElement));										\
	SNDLST2_M_DoubleLinkGetNextElement(n, (hElement)) = SNDLST2_C_DoubleLinkInvalid;			\
	SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement)) = SNDLST2_M_DoubleLinkGetLastElement(n, (hAnchor));		\
	SNDLST2_M_DoubleLinkGetFather(n, (hElement)) = (hAnchor);						\
	if (SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor))==SNDLST2_C_DoubleLinkInvalid)		\
		SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor)) = (hElement);				\
	else																	\
		SNDLST2_M_DoubleLinkGetNextElement(n, SNDLST2_M_DoubleLinkGetLastElement(n, (hAnchor))) = (hElement);	\
	SNDLST2_M_DoubleLinkGetLastElement(n, (hAnchor)) = (hElement);						\
	SNDLST2_M_DoubleLinkGetNumberOfElements(n, (hAnchor))++;							\
}

#define SNDLST2_M_DoubleLinkAddHead(n, hAnchor,hElement)									\
{																			\
	SNDLST2_M_DoubleLinkIsolate(n, (hElement));										\
	SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement)) = SNDLST2_C_DoubleLinkInvalid;								\
	SNDLST2_M_DoubleLinkGetNextElement(n, (hElement)) = SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor));	\
	SNDLST2_M_DoubleLinkGetFather(n, (hElement)) = (hAnchor);								\
	if (SNDLST2_M_DoubleLinkGetLastElement(n, (hAnchor))==SNDLST2_C_DoubleLinkInvalid)							\
		SNDLST2_M_DoubleLinkGetLastElement(n, (hAnchor)) = (hElement);						\
	else																	\
		SNDLST2_M_DoubleLinkGetPrevElement(n, SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor))) = (hElement);	\
	SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor)) = (hElement);							\
	SNDLST2_M_DoubleLinkGetNumberOfElements(n, (hAnchor))++;							\
}

#define SNDLST2_M_DoubleLinkInsertBetween(n, hElement,hPrevElement,hNextElement)							\
{																										\
	SNDLST2_M_DoubleLinkIsolate(n, (hElement));																\
	SNDLST2_M_DoubleLinkGetNextElement(n, (hElement)) = (hNextElement);										\
	SNDLST2_M_DoubleLinkGetPrevElement(n, (hElement)) = (hPrevElement);										\
	if((hPrevElement)!=SNDLST2_C_DoubleLinkInvalid)															\
	{																									\
		SNDLST2_M_DoubleLinkGetNextElement(n, (hPrevElement)) = (hElement);									\
		SNDLST2_M_DoubleLinkGetFather(n, (hElement)) = SNDLST2_M_DoubleLinkGetFather(n, (hPrevElement));		\
	}																									\
	else																								\
	{																									\
		SNDLST2_M_DoubleLinkGetFirstElement(n, SNDLST2_M_DoubleLinkGetFather(n, (hNextElement))) = (hElement);	\
	}																									\
	if((hNextElement)!=SNDLST2_C_DoubleLinkInvalid)															\
	{																									\
		SNDLST2_M_DoubleLinkGetPrevElement(n, (hNextElement)) = (hElement);									\
		SNDLST2_M_DoubleLinkGetFather(n, (hElement)) = SNDLST2_M_DoubleLinkGetFather(n, (hNextElement));		\
	}																									\
	else																								\
	{																									\
		SNDLST2_M_DoubleLinkGetLastElement(n, SNDLST2_M_DoubleLinkGetFather(n, (hPrevElement))) = (hElement);	\
	}																									\
	SNDLST2_M_DoubleLinkGetNumberOfElements(n, SNDLST2_M_DoubleLinkGetFather(n, (hElement)))++;					\
}

#define SNDLST2_M_DoubleLinkForEachElementOf(n, hAnchor, hElement, i)		\
for														\
(														\
	(i)=0,(hElement)=SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor));	\
	(hElement)!=SNDLST2_C_DoubleLinkInvalid;							\
	(i)++,hElement=SNDLST2_M_DoubleLinkGetNextElement(n, (hElement))		\
)

#define SNDLST2_M_DoubleLinkForEachMovingElementOf(n, hAnchor, hElement, hNextElement, i)	\
for																		\
(																		\
	(i)=0,(hElement)=SNDLST2_M_DoubleLinkGetFirstElement(n, (hAnchor)),(hNextElement)=(hElement)?SNDLST2_M_DoubleLinkGetNextElement(n,(hElement)):SNDLST2_C_DoubleLinkInvalid;	\
	(hElement)!=SNDLST2_C_DoubleLinkInvalid;													\
	(i)++,(hElement)=(hNextElement),(hNextElement)=(hElement)?SNDLST2_M_DoubleLinkGetNextElement(n, (hElement)):SNDLST2_C_DoubleLinkInvalid			\
)

#endif
