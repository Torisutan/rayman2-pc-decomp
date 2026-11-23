#ifndef __LSTDEF2_H__
#define __LSTDEF2_H__

#if !defined(U64) && !defined(NITRO)

#if defined(_DEBUG)

	#undef LST2_StaticIsOptimised
	#undef LST2_StaticIsSemiOptimised
	#undef LST2_StaticIsSingleLink
#else

	#undef LST2_StaticIsOptimised
	#undef LST2_StaticIsSemiOptimised
	#define LST2_StaticIsSingleLink
#endif

#else

#ifndef LST2_StaticIsOptimised
	#undef LST2_StaticIsSemiOptimised
	#define LST2_StaticIsSingleLink
	#pragma message( "Warning ! LST2_StaticIsOptimised isn't defined" )
#else
	#undef LST2_StaticIsSemiOptimised
	#undef LST2_StaticIsSingleLink
#endif

#endif

#define LST2_C_DynamicInvalid									        LST2_C_DoubleLinkInvalid
#define LST2_M_DynamicAnchorTo(TypeElement)						LST2_M_AnchorTo(Dyn, TypeElement)
#define LST2_M_DynamicUseListOf(type)							    LST2_M_DoubleLinkUseListOf(Dyn, type)
#define LST2_M_DynamicGetMember(handle, member)				LST2_M_DoubleLinkGetMember(Dyn, handle, member)
#define LST2_M_DynamicSetMember(handle, member, value)			LST2_M_DoubleLinkSetMember(Dyn, handle, member, value)
#define LST2_M_DynamicAnchorDeclaration(TypeElement)	LST2_M_DoubleLinkAnchorDeclaration(Dyn, TypeElement)
#define LST2_M_DynamicParentDeclaration(TypeElement)	LST2_M_DoubleLinkParentDeclaration(Dyn, TypeElement)
#define LST2_M_DynamicGetFirstElement(hAnchor)				LST2_M_DoubleLinkGetFirstElement(Dyn, hAnchor)
#define LST2_M_DynamicGetLastElement(hAnchor)					LST2_M_DoubleLinkGetLastElement(Dyn, hAnchor)
#define LST2_M_DynamicGetNumberOfElements(hAnchor)		LST2_M_DoubleLinkGetNumberOfElements(Dyn, hAnchor)
#define LST2_M_DynamicSetFirstElement(hAnchor, value)	LST2_M_DoubleLinkSetFirstElement(Dyn, hAnchor, value)
#define LST2_M_DynamicSetLastElement(hAnchor, value)	LST2_M_DoubleLinkSetLastElement(Dyn, hAnchor, value)
#define LST2_M_DynamicInitAnchor(hAnchor)						  LST2_M_DoubleLinkInitAnchor(Dyn, hAnchor)
#define LST2_M_DynamicElementDeclaration(TypeElement)	LST2_M_DoubleLinkElementDeclaration(Dyn, TypeElement)
#define LST2_M_DynamicChildDeclaration(TypeElement, TypeParent)	LST2_M_DoubleLinkChildDeclaration(Dyn, TypeElement, TypeParent)
#define LST2_M_DynamicGetNextElement(hElement)				LST2_M_DoubleLinkGetNextElement(Dyn, hElement)
#define LST2_M_DynamicGetPrevElement(hElement)				LST2_M_DoubleLinkGetPrevElement(Dyn, hElement)
#define LST2_M_DynamicGetFather(hElement)						  LST2_M_DoubleLinkGetFather(Dyn, hElement)
#define LST2_M_DynamicSetNextElement(hElement, value)	LST2_M_DoubleLinkSetNextElement(Dyn, hElement, value)
#define LST2_M_DynamicSetPrevElement(hElement, value)	LST2_M_DoubleLinkSetPrevElement(Dyn, hElement, value)
#define LST2_M_DynamicSetFather(hElement, value)			LST2_M_DoubleLinkSetFather(Dyn, hElement, value)
#define LST2_M_DynamicInitElement(hElement)						LST2_M_DoubleLinkInitElement(Dyn, hElement)
#define LST2_M_DynamicAddTail(hAnchor, hElement)			LST2_M_DoubleLinkAddTail(Dyn, hAnchor, hElement)
#define LST2_M_DynamicAddHead(hAnchor, hElement)			LST2_M_DoubleLinkAddHead(Dyn, hAnchor, hElement)
#define LST2_M_DynamicIsolate(hElement)							  LST2_M_DoubleLinkIsolate(Dyn, hElement)
#define LST2_M_DynamicInsertBetween(hElement,hPrevElement,hNextElement)	LST2_M_DoubleLinkInsertBetween(Dyn, hElement,hPrevElement,hNextElement)
#define LST2_M_DynamicWhatElementNumber(hElement0,hElement, i)	    LST2_M_DoubleLinkWhatElementNumber(Dyn, hElement0,hElement, i)
#define LST3_M_DynamicWhatElementNumber(hElement0,hAnchor, hElement, i)	    LST3_M_DoubleLinkWhatElementNumber(Dyn, hElement0,hAnchor,hElement, i)
#define LST2_M_DynamicForEachElementOf(hAnchor, hElement, i)		    LST2_M_DoubleLinkForEachElementOf(Dyn, hAnchor, hElement, i)
#define LST2_M_DynamicForEachMovingElementOf(hAnchor, hElement, hNextElement, i)	LST2_M_DoubleLinkForEachMovingElementOf(Dyn, hAnchor, hElement, hNextElement, i)
#define LST2_M_DynamicGetElementNumber(hAnchor, hElement, k, i)     LST2_M_DoubleLinkGetElementNumber(Dyn, hAnchor, hElement, k, i)
#define LST2_M_DynamicGetNthBrother(hFirstElement, hElement, k, i)  LST2_M_DoubleLinkGetNthBrother(Dyn, hFirstElement, hElement, k, i)

#ifdef LST2_StaticIsOptimised

#define LST2_C_StaticInvalid				                  LST2_C_ArrayInvalid
#define LST2_M_StaticGetMember(handle, member)		    LST2_M_ArrayGetMember(Opt, handle, member)
#define LST2_M_StaticSetMember(handle, member, value)	LST2_M_ArraySetMember(Opt, handle, member, value)
#define LST2_M_StaticAnchorTo(TypeElement)						LST2_M_ArrayAnchorTo(Opt, TypeElement)
#define LST2_M_StaticUseListOf(TypeElement)				    LST2_M_ArrayUseListOf(Opt, TypeElement)
#define LST2_M_StaticParentDeclaration(TypeElement)		LST2_M_ArrayParentDeclaration(Opt, TypeElement)
#define LST2_M_StaticAnchorDeclaration(TypeElement)		LST2_M_ArrayAnchorDeclaration(Opt, TypeElement)
#define LST2_M_StaticGetFirstElement(hAnchor)		      LST2_M_ArrayGetFirstElement(Opt, hAnchor)
#define LST2_M_StaticSetFirstElement(hAnchor, value)	LST2_M_ArraySetFirstElement(Opt, hAnchor, value)
#define LST2_M_StaticGetNumberOfElements(hAnchor)	    LST2_M_ArrayGetNumberOfElements(Opt, hAnchor)
#define LST2_M_StaticSetNumberOfElements(hAnchor, value)	          LST2_M_ArraySetNumberOfElements(Opt, hAnchor, value)
#define LST2_M_StaticElementDeclaration(TypeElement)  LST2_M_ArrayElementDeclaration(Opt, TypeElement)
#define LST2_M_StaticChildDeclaration(TypeElement,TypeParent)       LST2_M_ArrayChildDeclaration(Opt, TypeElement,TypeParent)
#define LST2_M_StaticGetNextElement(_hElement)		    LST2_M_ArrayGetNextElement(Opt, _hElement)
#define LST2_M_StaticGetNthBrother(hFirstElement, hElement, k, i)		LST2_M_ArrayGetNthBrother(Opt, hFirstElement, hElement, k, i)
#define LST2_M_StaticGetPrevElement(_hElement)		    LST2_M_ArrayGetPrevElement(Opt, _hElement)
#define LST2_M_StaticForEachElementOf(_hAnchor, _hElement, _i)		  LST2_M_ArrayForEachElementOf(Opt, _hAnchor, _hElement, _i)
#define LST2_M_StaticGetElementNumber(_hAnchor, _hElement, _k, _i)	LST2_M_ArrayGetElementNumber(Opt, _hAnchor, _hElement, _k, _i)
#define LST2_M_StaticWhatElementNumber(_hElement0,_hAnchor, _i)	    LST2_M_ArrayWhatElementNumber(Opt, _hElement0,_hAnchor, _i)
#define LST3_M_StaticWhatElementNumber(_hElement0,_hAnchor, _hIterator, _i)	    LST3_M_ArrayWhatElementNumber(Opt, _hElement0,_hAnchor, _hIterator, _i)

#define LST2_M_StaticGetLastElement(hAnchor)					LST2_M_ArrayGetLastElement(Opt, hAnchor)

#define LST2_M_StaticInitAnchor(hAnchor)
#define LST2_M_StaticInitElement(hElement)

#endif

#ifdef LST2_StaticIsSemiOptimised

#define LST2_C_StaticInvalid				                  LST2_C_StaticInvalid
#define LST2_M_StaticGetMember(handle, member)		    LST2_M_ArrayGetMember(SemiOpt, handle, member)
#define LST2_M_StaticSetMember(handle, member, value)	LST2_M_ArraySetMember(SemiOpt, handle, member, value)
#define LST2_M_StaticAnchorTo(TypeElement)						LST2_M_ArrayAnchorTo(SemiOpt, TypeElement)
#define LST2_M_StaticUseListOf(TypeElement)				    LST2_M_ArrayUseListOf(SemiOpt, TypeElement)
#define LST2_M_StaticParentDeclaration(TypeElement)		LST2_M_DoubleLinkParentDeclaration(SemiOpt, TypeElement)
#define LST2_M_StaticAnchorDeclaration(TypeElement)		LST2_M_DoubleLinkAnchorDeclaration(SemiOpt, TypeElement)
#define LST2_M_StaticGetFirstElement(hAnchor)		      LST2_M_ArrayGetFirstElement(SemiOpt, hAnchor)
#define LST2_M_StaticGetNumberOfElements(hAnchor)	    LST2_M_ArrayGetNumberOfElements(SemiOpt, hAnchor)
#define LST2_M_StaticSetFirstElement(hAnchor, value)	LST2_M_ArraySetFirstElement(SemiOpt, hAnchor, value)
#define LST2_M_StaticSetNumberOfElements(hAnchor, value)	          LST2_M_ArraySetNumberOfElements(SemiOpt, hAnchor, value)
#define LST2_M_StaticElementDeclaration(TypeElement)  LST2_M_DoubleLinkElementDeclaration(SemiOpt, TypeElement)
#define LST2_M_StaticChildDeclaration(TypeElement,TypeParent)       LST2_M_DoubleLinkChildDeclaration(SemiOpt, TypeElement,TypeParent)
#define LST2_M_StaticGetNextElement(_hElement)		    LST2_M_ArrayGetNextElement(SemiOpt, _hElement)
#define LST2_M_StaticGetPrevElement(_hElement)		    LST2_M_ArrayGetPrevElement(SemiOpt, _hElement)
#define LST2_M_StaticGetNthBrother(hFirstElement, hElement, k, i)		LST2_M_ArrayGetNthBrother(SemiOpt, hFirstElement, hElement, k, i)
#define LST2_M_StaticForEachElementOf(_hAnchor, _hElement, _i)		  LST2_M_ArrayForEachElementOf(SemiOpt, _hAnchor, _hElement, _i)
#define LST2_M_StaticGetElementNumber(_hAnchor, _hElement, _k, _i)	LST2_M_ArrayGetElementNumber(SemiOpt, _hAnchor, _hElement, _k, _i)
#define LST2_M_StaticWhatElementNumber(_hElement0,_hAnchor, _i)	    LST2_M_ArrayWhatElementNumber(SemiOpt, _hElement0,_hAnchor, _i)
#define LST3_M_StaticWhatElementNumber(_hElement0,_hAnchor, _hIterator, _i)	    LST3_M_ArrayWhatElementNumber(SemiOpt, _hElement0,_hAnchor, _hIterator, _i)

#define LST2_M_StaticInitElement(hElement)						  LST2_M_DoubleLinkInitElement(SemiOpt, hElement)
#define LST2_M_StaticAddTail(hAnchor, hElement)				  LST2_M_DoubleLinkAddTail(SemiOpt, hAnchor, hElement)
#define LST2_M_StaticAddHead(hAnchor, hElement)				  LST2_M_DoubleLinkAddHead(SemiOpt, hAnchor, hElement)
#define LST2_M_StaticIsolate(hElement)							    LST2_M_DoubleLinkIsolate(SemiOpt, hElement)
#define LST2_M_StaticInsertBetween(hElement,hPrevElement,hNextElement)	LST2_M_DoubleLinkInsertBetween(SemiOpt, hElement,hPrevElement,hNextElement)
#define LST3_M_StaticInsertBetween(hAnchor,hElement,hPrevElement,hNextElement)  LST2_M_DoubleLinkInsertBetween(SemiOpt, hElement,hPrevElement,hNextElement)

#define LST2_M_StaticConvert(_hAnchor, _dTab, _ulSize, _hDest, _hSrc, _i)   \
{                                                                           \
  _hDest=_dTab;                                                             \
  LST2_M_DoubleLinkForEachElementOf(SemiOpt, _hAnchor, _hSrc, _i)           \
  {                                                                         \
    memcpy(_hDest, _hSrc, _ulSize);                                         \
    _hDest++;                                                               \
  }                                                                         \
  LST2_M_StaticSetFirstElement(_hAnchor, _dTab);                            \
}

#endif

#ifdef LST2_StaticIsSingleLink

#define LST2_C_StaticInvalid                                            LST2_C_DoubleLinkInvalid
#define LST2_M_StaticGetMember(handle, member)                          LST2_M_SingleLinkGetMember(SLk, handle, member)
#define LST2_M_StaticSetMember(handle, member, value)                   LST2_M_SingleLinkSetMember(SLk, handle, member, value)
#define LST2_M_StaticAnchorTo(TypeElement)                              LST2_M_SingleLinkAnchorTo(SLk, TypeElement)
#define LST2_M_StaticUseListOf(TypeElement)                             LST2_M_SingleLinkUseListOf(SLk, TypeElement)
#define LST2_M_StaticParentDeclaration(TypeElement)                     LST2_M_SingleLinkParentDeclaration(SLk, TypeElement)
#define LST2_M_StaticAnchorDeclaration(TypeElement)                     LST2_M_SingleLinkAnchorDeclaration(SLk, TypeElement)
#define LST2_M_StaticGetFirstElement(hAnchor)                           LST2_M_SingleLinkGetFirstElement(SLk, hAnchor)
#define LST2_M_StaticGetLastElement(hAnchor)                            LST2_M_SingleLinkGetLastElement(SLk, hAnchor)
#define LST2_M_StaticGetNumberOfElements(hAnchor)                       LST2_M_SingleLinkGetNumberOfElements(SLk, hAnchor)
#define LST2_M_StaticInitAnchor(hAnchor)                                LST2_M_SingleLinkInitAnchor(SLk, hAnchor)
#define LST2_M_StaticElementDeclaration(TypeElement)                    LST2_M_SingleLinkElementDeclaration(SLk, TypeElement)
#define LST2_M_StaticChildDeclaration(TypeElement,TypeParent)           LST2_M_SingleLinkChildDeclaration(SLk, TypeElement,TypeParent)
#define LST2_M_StaticGetNextElement(_hElement)                          LST2_M_SingleLinkGetNextElement(SLk, _hElement)
#define LST2_M_StaticGetNthBrother(hFirstElement, hElement, k, i)       LST2_M_SingleLinkGetNthBrother(SLk, hFirstElement, hElement, k, i)
#define LST2_M_StaticForEachElementOf(_hAnchor, _hElement, _i)          LST2_M_SingleLinkForEachElementOf(SLk, _hAnchor, _hElement, _i)
#define LST2_M_StaticGetElementNumber(_hAnchor, _hElement, _k, _i)      LST2_M_SingleLinkGetElementNumber(SLk, _hAnchor, _hElement, _k, _i)
#define LST3_M_StaticWhatElementNumber(_hElement0,_hAnchor, _hIterator, _i)     LST3_M_SingleLinkWhatElementNumber(SLk, _hElement0,_hAnchor, _hIterator, _i)
#define LST2_M_StaticAddHead(hAnchor, hElement)                         LST2_M_SingleLinkAddHead(SLk, hAnchor, hElement)
#define LST2_M_StaticAddTail(hAnchor, hElement)                         LST2_M_SingleLinkAddTail(SLk, hAnchor, hElement)
#define LST2_M_StaticInitElement(hElement)                              LST2_M_SingleLinkInitElement(SLk, hElement)
#define LST3_M_StaticInsertBetween(hAnchor,hElement,hPrevElement,hNextElement)  LST3_M_SingleLinkInsertBetween(SLk, hAnchor,hElement,hPrevElement,hNextElement)

#undef	LST2_M_StaticSetNumberOfElements
#undef  LST2_M_StaticGetPrevElement
#undef  LST2_M_StaticWhatElementNumber
#undef  LST2_M_StaticSetFirstElement
#undef	LST2_M_StaticSetLastElement
#undef  LST2_M_StaticSetNextElement
#undef  LST2_M_StaticIsolate
#undef  LST2_M_StaticInsertBetween

#endif

#if !defined(LST2_StaticIsOptimised)&&!defined(LST2_StaticIsSemiOptimised)&&!defined(LST2_StaticIsSingleLink)

#define LST2_C_StaticInvalid									LST2_C_DoubleLinkInvalid
#define LST2_M_StaticGetMember(handle, member)					LST2_M_DoubleLinkGetMember(Dyn, handle, member)
#define LST2_M_StaticSetMember(handle, member, value)			LST2_M_DoubleLinkSetMember(Dyn, handle, member, value)
#define LST2_M_StaticAnchorTo(TypeElement)						LST2_M_AnchorTo(Dyn, TypeElement)
#define LST2_M_StaticUseListOf(type)							LST2_M_DoubleLinkUseListOf(Dyn, type)
#define LST2_M_StaticParentDeclaration(TypeElement)				LST2_M_DoubleLinkParentDeclaration(Dyn, TypeElement)
#define LST2_M_StaticAnchorDeclaration(TypeElement)				LST2_M_DoubleLinkAnchorDeclaration(Dyn, TypeElement)
#define LST2_M_StaticGetFirstElement(hAnchor)					LST2_M_DoubleLinkGetFirstElement(Dyn, hAnchor)
#define LST2_M_StaticGetLastElement(hAnchor)					LST2_M_DoubleLinkGetLastElement(Dyn, hAnchor)
#define LST2_M_StaticGetNumberOfElements(hAnchor)				LST2_M_DoubleLinkGetNumberOfElements(Dyn, hAnchor)
#define LST2_M_StaticSetFirstElement(hAnchor, value)			LST2_M_DoubleLinkSetFirstElement(Dyn, hAnchor, value)
#define LST2_M_StaticSetLastElement(hAnchor, value)				LST2_M_DoubleLinkSetLastElement(Dyn, hAnchor, value)
#define LST2_M_StaticInitAnchor(hAnchor)						LST2_M_DoubleLinkInitAnchor(Dyn, hAnchor)
#define LST2_M_StaticElementDeclaration(TypeElement)			LST2_M_DoubleLinkElementDeclaration(Dyn, TypeElement)
#define LST2_M_StaticChildDeclaration(TypeElement, TypeParent)	LST2_M_DoubleLinkChildDeclaration(Dyn, TypeElement, TypeParent)
#define LST2_M_StaticGetNextElement(hElement)					LST2_M_DoubleLinkGetNextElement(Dyn, hElement)
#define LST2_M_StaticGetPrevElement(hElement)					LST2_M_DoubleLinkGetPrevElement(Dyn, hElement)
#define LST2_M_StaticGetFather(hElement)						LST2_M_DoubleLinkGetFather(Dyn, hElement)
#define LST2_M_StaticSetNextElement(hElement, value)			LST2_M_DoubleLinkSetNextElement(Dyn, hElement, value)
#define LST2_M_StaticSetPrevElement(hElement, value)			LST2_M_DoubleLinkSetPrevElement(Dyn, hElement, value)
#define LST2_M_StaticSetFather(hElement, value)					LST2_M_DoubleLinkSetFather(Dyn, hElement, value)
#define LST2_M_StaticInitElement(hElement)						LST2_M_DoubleLinkInitElement(Dyn, hElement)
#define LST2_M_StaticAddTail(hAnchor, hElement)					LST2_M_DoubleLinkAddTail(Dyn, hAnchor, hElement)
#define LST2_M_StaticAddHead(hAnchor, hElement)					LST2_M_DoubleLinkAddHead(Dyn, hAnchor, hElement)
#define LST2_M_StaticIsolate(hElement)							LST2_M_DoubleLinkIsolate(Dyn, hElement)
#define LST2_M_StaticInsertBetween(hElement,hPrevElement,hNextElement)	LST2_M_DoubleLinkInsertBetween(Dyn, hElement,hPrevElement,hNextElement)
#define LST2_M_StaticWhatElementNumber(hElement0,hElement, i)			LST2_M_DoubleLinkWhatElementNumber(Dyn, hElement0,hElement, i)
#define LST3_M_StaticWhatElementNumber(hElement0, hAnchor, hElement, i)	LST3_M_DoubleLinkWhatElementNumber(Dyn, hElement0, hAnchor, hElement, i)
#define LST2_M_StaticForEachElementOf(hAnchor, hElement, i)		        LST2_M_DoubleLinkForEachElementOf(Dyn, hAnchor, hElement, i)

#define LST2_M_StaticForEachMovingElementOf(hAnchor, hElement, hNextElement, i)	LST2_M_DoubleLinkForEachMovingElementOf(Dyn, hAnchor, hElement, hNextElement, i)
#define LST2_M_StaticGetElementNumber(hAnchor, hElement, k, i)	        LST2_M_DoubleLinkGetElementNumber(Dyn, hAnchor, hElement, k, i)
#define LST2_M_StaticGetNthBrother(hFirstElement, hElement, k, i)       LST2_M_DoubleLinkGetNthBrother(Dyn, hFirstElement, hElement, k, i)
#define LST3_M_StaticInsertBetween(hAnchor,hElement,hPrevElement,hNextElement)  LST2_M_DoubleLinkInsertBetween(Dyn, hElement,hPrevElement,hNextElement)

#endif

#define LST2_C_ArrayInvalid				0

#define LST2_M_ArrayGetMember(n, handle, member)		\
((handle)->member##n)

#define LST2_M_ArraySetMember(n, handle, member, value)	\
{(handle)->member##n=(value);}

#define LST2_M_ArrayAnchorTo(n, TypeElement)										\
LST2_M_AnchorTo(n, TypeElement)

#define LST2_M_ArrayUseListOf(n, TypeElement)				\
LST2_M_ArrayAnchorTo(n, TypeElement)										\
{																\
TypeElement hFirstElement##n;									\
long lNumberOfElements##n;										\
}

#define LST2_M_ArrayParentDeclaration(n, TypeElement)		\
TypeElement hFirstElement##n;								\
long lNumberOfElements##n;

#define LST2_M_ArrayAnchorDeclaration(n, TypeElement)		\
LST2_M_ArrayAnchorTo(n, TypeElement)

#define LST2_M_ArrayGetFirstElement(n, hAnchor)		\
LST2_M_ArrayGetMember(n, (hAnchor), hFirstElement)

#define LST2_M_ArraySetFirstElement(n, hAnchor, value)		\
LST2_M_ArraySetMember(n, (hAnchor), hFirstElement, (value))

#define LST2_M_ArrayGetNumberOfElements(n, hAnchor)	\
LST2_M_ArrayGetMember(n, (hAnchor), lNumberOfElements)

#define LST2_M_ArraySetNumberOfElements(n, hAnchor, value)	\
LST2_M_ArraySetMember(n, (hAnchor), lNumberOfElements, (value))

#define LST2_M_ArrayElementDeclaration(n, TypeElement)
#define LST2_M_ArrayChildDeclaration(n, TypeElement,TypeParent)

#define LST2_M_ArrayGetNextElement(n, _hElement)		\
((_hElement)+1)

#define LST2_M_ArrayGetNthBrother(n, hFirstElement, hElement, k, i)		\
{(hElement)=(hFirstElement)+(k); i=i;}

#define LST2_M_ArrayGetPrevElement(n, _hElement)		\
((_hElement)-1)

#define LST2_M_ArrayForEachElementOf(n, _hAnchor, _hElement, _i)		\
	for((_hElement)=LST2_M_ArrayGetFirstElement(n, (_hAnchor)),(_i)=0;	\
	(_i)<LST2_M_ArrayGetNumberOfElements(n, (_hAnchor));			\
	(_i)++,(_hElement)=LST2_M_ArrayGetNextElement(n, _hElement))

#define LST2_M_ArrayGetElementNumber(n, _hAnchor, _hElement, _k, _i)		\
  {(_hElement)=LST2_M_ArrayGetFirstElement(n, (_hAnchor))+(_k);(_i)=0;}

#define LST2_M_ArrayWhatElementNumber(n, _hElement0,_hAnchor, _i)	\
{_i=(_hElement0) - LST2_M_ArrayGetFirstElement(n, (_hAnchor));}

#define LST3_M_ArrayWhatElementNumber(n, _hElement0,_hAnchor, _hIterator, _i)	\
{	_i=(_hElement0) - LST2_M_ArrayGetFirstElement(n, (_hAnchor));_hIterator=0;}

#define LST2_M_ArrayGetLastElement(n, hAnchor) \
((LST2_M_ArrayGetFirstElement(n, hAnchor))+LST2_M_ArrayGetNumberOfElements(n, hAnchor)-1)

#define LST2_C_DoubleLinkInvalid 0

#define LST2_M_DoubleLinkGetMember(n, handle, member)			\
((handle)->member##n)

#define LST2_M_DoubleLinkSetMember(n, handle, member, value)	\
{(handle)->member##n=(value);}

#define LST2_M_AnchorTo(n, TypeElement) struct LST2_tdstAnchorTo##TypeElement##n

#define LST2_M_DoubleLinkUseListOf(n, TypeElement)							\
LST2_M_AnchorTo(n, TypeElement)										\
{																\
	TypeElement hFirstElement##n;								\
	TypeElement hLastElement##n;								\
	long lNumberOfElements##n;									\
}

#define LST2_M_DoubleLinkParentDeclaration(n, TypeElement)							\
	TypeElement hFirstElement##n;								\
	TypeElement hLastElement##n;								\
	long lNumberOfElements##n;

#define LST2_M_DoubleLinkAnchorDeclaration(n, TypeElement)		\
LST2_M_AnchorTo(n, TypeElement)

#define LST2_M_DoubleLinkGetFirstElement(n, hAnchor)				\
LST2_M_DoubleLinkGetMember(n, hAnchor, hFirstElement)

#define LST2_M_DoubleLinkGetLastElement(n, hAnchor)				\
LST2_M_DoubleLinkGetMember(n, hAnchor, hLastElement)

#define LST2_M_DoubleLinkSetFirstElement(n, hAnchor, value)		\
LST2_M_DoubleLinkGetMember(n, hAnchor, hFirstElement) = (value)

#define LST2_M_DoubleLinkGetNumberOfElements(n, hAnchor)		\
LST2_M_DoubleLinkGetMember(n, hAnchor, lNumberOfElements)

#define LST2_M_DoubleLinkSetLastElement(n, hAnchor, value)		\
LST2_M_DoubleLinkGetMember(n, hAnchor, hLastElement) = (value)

#define LST2_M_DoubleLinkInitAnchor(n, hAnchor)				\
{													\
	LST2_M_DoubleLinkGetFirstElement(n, (hAnchor))= LST2_C_DoubleLinkInvalid;		\
	LST2_M_DoubleLinkGetLastElement(n, (hAnchor)) = LST2_C_DoubleLinkInvalid;		\
	LST2_M_DoubleLinkGetNumberOfElements(n, (hAnchor))= 0;								\
}

#define LST2_M_DoubleLinkElementDeclaration(n, TypeElement)	\
TypeElement hNextBrother##n;								\
TypeElement hPrevBrother##n;								\
LST2_M_AnchorTo(n, TypeElement)* hFather##n;

#define LST2_M_DoubleLinkChildDeclaration(n, TypeElement, TypeFather)	\
TypeElement hNextBrother##n;								\
TypeElement hPrevBrother##n;								\
TypeFather hFather##n;

#define LST2_M_DoubleLinkGetNextElement(n, hElement)	\
LST2_M_DoubleLinkGetMember(n, (hElement), hNextBrother)

#define LST2_M_DoubleLinkGetPrevElement(n, hElement)	\
LST2_M_DoubleLinkGetMember(n, (hElement), hPrevBrother)

#define LST2_M_DoubleLinkGetFather(n, hSO) \
LST2_M_DoubleLinkGetMember(n, (hSO), hFather)

#define LST2_M_DoubleLinkSetNextElement(n, hElement, value)	\
LST2_M_DoubleLinkGetMember(n, (hElement), hNextBrother) = (value)

#define LST2_M_DoubleLinkSetPrevElement(n, hElement, value)	\
LST2_M_DoubleLinkGetMember(n, (hElement), hPrevBrother) = (value)

#define LST2_M_DoubleLinkSetFather(n, hSO, value) \
LST2_M_DoubleLinkGetMember(n, (hSO), hFather) = (value)

#define LST2_M_DoubleLinkInitElement(n, hElement)				\
{												\
	LST2_M_DoubleLinkGetNextElement(n, (hElement))= LST2_C_DoubleLinkInvalid;	\
	LST2_M_DoubleLinkGetPrevElement(n, (hElement))= LST2_C_DoubleLinkInvalid;	\
	LST2_M_DoubleLinkGetFather(n, (hElement))   = LST2_C_DoubleLinkInvalid;	\
}

#define LST2_M_DoubleLinkIsolate(n, hElement)											\
{																			\
	if(LST2_M_DoubleLinkGetNextElement(n, (hElement))!=LST2_C_DoubleLinkInvalid)							\
		LST2_M_DoubleLinkGetPrevElement(n, LST2_M_DoubleLinkGetNextElement(n, (hElement)))  = LST2_M_DoubleLinkGetPrevElement(n, (hElement));	\
	if(LST2_M_DoubleLinkGetPrevElement(n, (hElement))!=LST2_C_DoubleLinkInvalid)							\
		LST2_M_DoubleLinkGetNextElement(n, LST2_M_DoubleLinkGetPrevElement(n, (hElement))) = LST2_M_DoubleLinkGetNextElement(n, (hElement));	\
	if(LST2_M_DoubleLinkGetFather(n, (hElement))!=LST2_C_DoubleLinkInvalid)								\
	{																							\
		LST2_M_DoubleLinkGetNumberOfElements(n, LST2_M_DoubleLinkGetFather(n, (hElement)))--;		\
		if(LST2_M_DoubleLinkGetFirstElement(n, LST2_M_DoubleLinkGetFather(n, (hElement)))==(hElement))	\
			LST2_M_DoubleLinkGetFirstElement(n, LST2_M_DoubleLinkGetFather(n, (hElement))) = LST2_M_DoubleLinkGetNextElement(n, (hElement));	\
		if(LST2_M_DoubleLinkGetLastElement(n, LST2_M_DoubleLinkGetFather(n, (hElement)))==(hElement))	\
			LST2_M_DoubleLinkGetLastElement(n, LST2_M_DoubleLinkGetFather(n, (hElement))) = LST2_M_DoubleLinkGetPrevElement(n, (hElement));	\
	}																		\
	LST2_M_DoubleLinkInitElement(n, (hElement));											\
}

#define LST2_M_DoubleLinkAddTail(n, hAnchor, hElement)							\
{																			\
	LST2_M_DoubleLinkIsolate(n, (hElement));										\
	LST2_M_DoubleLinkGetNextElement(n, (hElement)) = LST2_C_DoubleLinkInvalid;			\
	LST2_M_DoubleLinkGetPrevElement(n, (hElement)) = LST2_M_DoubleLinkGetLastElement(n, (hAnchor));		\
	LST2_M_DoubleLinkGetFather(n, (hElement)) = (hAnchor);						\
	if (LST2_M_DoubleLinkGetFirstElement(n, (hAnchor))==LST2_C_DoubleLinkInvalid)		\
		LST2_M_DoubleLinkGetFirstElement(n, (hAnchor)) = (hElement);				\
	else																	\
		LST2_M_DoubleLinkGetNextElement(n, LST2_M_DoubleLinkGetLastElement(n, (hAnchor))) = (hElement);	\
	LST2_M_DoubleLinkGetLastElement(n, (hAnchor)) = (hElement);						\
	LST2_M_DoubleLinkGetNumberOfElements(n, (hAnchor))++;							\
}

#define LST2_M_DoubleLinkAddHead(n, hAnchor,hElement)									\
{																			\
	LST2_M_DoubleLinkIsolate(n, (hElement));										\
	LST2_M_DoubleLinkGetPrevElement(n, (hElement)) = LST2_C_DoubleLinkInvalid;								\
	LST2_M_DoubleLinkGetNextElement(n, (hElement)) = LST2_M_DoubleLinkGetFirstElement(n, (hAnchor));	\
	LST2_M_DoubleLinkGetFather(n, (hElement)) = (hAnchor);								\
	if (LST2_M_DoubleLinkGetLastElement(n, (hAnchor))==LST2_C_DoubleLinkInvalid)							\
		LST2_M_DoubleLinkGetLastElement(n, (hAnchor)) = (hElement);						\
	else																	\
		LST2_M_DoubleLinkGetPrevElement(n, LST2_M_DoubleLinkGetFirstElement(n, (hAnchor))) = (hElement);	\
	LST2_M_DoubleLinkGetFirstElement(n, (hAnchor)) = (hElement);							\
	LST2_M_DoubleLinkGetNumberOfElements(n, (hAnchor))++;							\
}

#define LST2_M_DoubleLinkInsertBetween(n, hElement,hPrevElement,hNextElement)							\
{																										\
	LST2_M_DoubleLinkIsolate(n, (hElement));																\
	LST2_M_DoubleLinkGetNextElement(n, (hElement)) = (hNextElement);										\
	LST2_M_DoubleLinkGetPrevElement(n, (hElement)) = (hPrevElement);										\
	if((hPrevElement)!=LST2_C_DoubleLinkInvalid)															\
	{																									\
		LST2_M_DoubleLinkGetNextElement(n, (hPrevElement)) = (hElement);									\
		LST2_M_DoubleLinkGetFather(n, (hElement)) = LST2_M_DoubleLinkGetFather(n, (hPrevElement));		\
	}																									\
	else																								\
	{																									\
		LST2_M_DoubleLinkGetFirstElement(n, LST2_M_DoubleLinkGetFather(n, (hNextElement))) = (hElement);	\
	}																									\
	if((hNextElement)!=LST2_C_DoubleLinkInvalid)															\
	{																									\
		LST2_M_DoubleLinkGetPrevElement(n, (hNextElement)) = (hElement);									\
		LST2_M_DoubleLinkGetFather(n, (hElement)) = LST2_M_DoubleLinkGetFather(n, (hNextElement));		\
	}																									\
	else																								\
	{																									\
		LST2_M_DoubleLinkGetLastElement(n, LST2_M_DoubleLinkGetFather(n, (hPrevElement))) = (hElement);	\
	}																									\
	LST2_M_DoubleLinkGetNumberOfElements(n, LST2_M_DoubleLinkGetFather(n, (hElement)))++;					\
}

#define LST2_M_DoubleLinkWhatElementNumber(n, hElement0,hElement, i)	\
{for													\
(													\
	i=-1,(hElement)=(hElement0);						\
	(hElement)!=LST2_C_DoubleLinkInvalid;						\
	i++,(hElement)=LST2_M_DoubleLinkGetPrevElement(n,(hElement))				\
);}

#define LST3_M_DoubleLinkWhatElementNumber(n, hElement0,hAnchor, hElement, i)	\
{for													\
(													\
	i=-1,(hElement)=(hElement0);						\
	(hElement)!=LST2_C_DoubleLinkInvalid;						\
	i++,(hElement)=LST2_M_DoubleLinkGetPrevElement(n,(hElement))				\
);}

#define LST2_M_DoubleLinkForEachElementOf(n, hAnchor, hElement, i)		\
for														\
(														\
	(i)=0,(hElement)=LST2_M_DoubleLinkGetFirstElement(n, (hAnchor));	\
	(hElement)!=LST2_C_DoubleLinkInvalid;							\
	(i)++,hElement=LST2_M_DoubleLinkGetNextElement(n, (hElement))		\
)

#define LST2_M_DoubleLinkForEachMovingElementOf(n, hAnchor, hElement, hNextElement, i)	\
for																		\
(																		\
	(i)=0,(hElement)=LST2_M_DoubleLinkGetFirstElement(n, (hAnchor)),(hNextElement)=(hElement)?LST2_M_DoubleLinkGetNextElement(n,(hElement)):LST2_C_DoubleLinkInvalid;	\
	(hElement)!=LST2_C_DoubleLinkInvalid;													\
	(i)++,(hElement)=(hNextElement),(hNextElement)=(hElement)?LST2_M_DoubleLinkGetNextElement(n, (hElement)):LST2_C_DoubleLinkInvalid			\
)

#define LST2_M_DoubleLinkGetElementNumber(n, hAnchor, hElement, k, i)		\
{														\
	for													\
	(													\
		(i)=0,(hElement)=LST2_M_DoubleLinkGetFirstElement(n, (hAnchor));	\
		(i)<(k);											\
		(i)++,(hElement)=LST2_M_DoubleLinkGetNextElement(n, (hElement))		\
	){}														\
}

#define LST2_M_DoubleLinkGetNthBrother(n, hFirstElement, hElement, k, i)		\
{														\
	for													\
	(													\
		(i)=0,(hElement)=hFirstElement;	\
		(i)<(k);											\
		(i)++,(hElement)=LST2_M_DoubleLinkGetNextElement(n, (hElement))		\
	){}														\
}

#define LST2_C_SingleLinkInvalid 0

#define LST2_M_SingleLinkGetMember(n, handle, member)           \
((handle)->member##n)

#define LST2_M_SingleLinkSetMember(n, handle, member, value)    \
{(handle)->member##n=(value);}

#define LST2_M_AnchorTo(n, TypeElement) struct LST2_tdstAnchorTo##TypeElement##n

#define LST2_M_SingleLinkUseListOf(n, TypeElement)                          \
LST2_M_AnchorTo(n, TypeElement)										\
{																\
	TypeElement hFirstElement##n;								\
	TypeElement hLastElement##n;								\
	long lNumberOfElements##n;									\
}

#define LST2_M_SingleLinkParentDeclaration(n, TypeElement)                          \
	TypeElement hFirstElement##n;								\
	TypeElement hLastElement##n;								\
	long lNumberOfElements##n;

#define LST2_M_SingleLinkAnchorDeclaration(n, TypeElement)      \
LST2_M_AnchorTo(n, TypeElement)

#define LST2_M_SingleLinkGetFirstElement(n, hAnchor)                \
LST2_M_SingleLinkGetMember(n, hAnchor, hFirstElement)

#define LST2_M_SingleLinkGetLastElement(n, hAnchor)             \
LST2_M_SingleLinkGetMember(n, hAnchor, hLastElement)

#define LST2_M_SingleLinkGetNumberOfElements(n, hAnchor)        \
LST2_M_SingleLinkGetMember(n, hAnchor, lNumberOfElements)

#define LST2_M_SingleLinkInitAnchor(n, hAnchor)             \
{													\
    LST2_M_SingleLinkGetFirstElement(n, (hAnchor))= LST2_C_SingleLinkInvalid;       \
    LST2_M_SingleLinkGetLastElement(n, (hAnchor)) = LST2_C_SingleLinkInvalid;       \
    LST2_M_SingleLinkGetNumberOfElements(n, (hAnchor))= 0;                              \
}

#define LST2_M_SingleLinkElementDeclaration(n, TypeElement) \
TypeElement hNextBrother##n;

#define LST2_M_SingleLinkChildDeclaration(n, TypeElement, TypeFather)   \
TypeElement hNextBrother##n;

#define LST2_M_SingleLinkGetNextElement(n, hElement)    \
LST2_M_SingleLinkGetMember(n, (hElement), hNextBrother)

#define LST2_M_SingleLinkInitElement(n, hElement)               \
LST2_M_SingleLinkGetNextElement(n, (hElement))= LST2_C_SingleLinkInvalid;

#define LST2_M_SingleLinkAddTail(n, hAnchor, hElement)                              \
{                                                                                   \
    LST2_M_SingleLinkGetNextElement(n, (hElement)) = LST2_C_SingleLinkInvalid;      \
    if (LST2_M_SingleLinkGetFirstElement(n, (hAnchor))==LST2_C_SingleLinkInvalid)   \
    {                                                                               \
        LST2_M_SingleLinkGetFirstElement(n, (hAnchor)) = (hElement);                \
    }                                                                               \
    else                                                                            \
    {                                                                               \
        LST2_M_SingleLinkGetNextElement(n, LST2_M_SingleLinkGetLastElement(n, (hAnchor))) = (hElement);                 \
    }                                                                               \
    LST2_M_SingleLinkGetLastElement(n, (hAnchor)) = (hElement);                     \
    LST2_M_SingleLinkGetNumberOfElements(n, (hAnchor))++;                           \
}

#define LST2_M_SingleLinkAddHead(n, hAnchor,hElement)                               \
{                                                                                   \
    LST2_M_SingleLinkGetNextElement(n, (hElement)) = LST2_M_SingleLinkGetFirstElement(n, (hAnchor)); \
    if (LST2_M_SingleLinkGetFirstElement(n, (hAnchor))==LST2_C_SingleLinkInvalid)   \
    {                                                                               \
        LST2_M_SingleLinkGetLastElement(n, (hAnchor)) = (hElement);                 \
    }                                                                               \
    LST2_M_SingleLinkGetFirstElement(n, (hAnchor)) = (hElement);                    \
	LST2_M_SingleLinkGetNumberOfElements(n, (hAnchor))++;							\
}

#define LST3_M_SingleLinkWhatElementNumber(n, hElement0,hAnchor, hElement, i)   \
{for                                                                            \
(                                                                               \
    (hElement)=LST2_M_SingleLinkGetFirstElement(n, (hAnchor)),(i)=0;            \
    (hElement)!=(hElement0) && hElement!=LST2_C_SingleLinkInvalid;              \
    (i)++,(hElement)=LST2_M_SingleLinkGetNextElement(n,(hElement))              \
);}

#define LST3_M_SingleLinkInsertBetween(n, hAnchor, hElement,hPrevElement,hNextElement)  \
{                                                                                       \
    LST2_M_SingleLinkGetNextElement(n, (hElement)) = (hNextElement);                    \
    if ((hNextElement)==LST2_C_SingleLinkInvalid)                                       \
        LST2_M_SingleLinkGetLastElement(n, (hAnchor)) = (hElement);                     \
    if ((hPrevElement)==LST2_C_SingleLinkInvalid)                                       \
        LST2_M_SingleLinkGetFirstElement(n, (hAnchor)) = (hElement);                    \
    else                                                                                \
        LST2_M_SingleLinkGetNextElement(n, (hPrevElement)) = (hElement);                \
    LST2_M_SingleLinkGetNumberOfElements(n, (hAnchor))++;                               \
}

#define LST2_M_SingleLinkForEachElementOf(n, hAnchor, hElement, i)      \
for                                                                     \
(                                                                       \
    (i)=0,(hElement)=LST2_M_SingleLinkGetFirstElement(n, (hAnchor));    \
    (hElement)!=LST2_C_SingleLinkInvalid;                               \
    (i)++,hElement=LST2_M_SingleLinkGetNextElement(n, (hElement))       \
)

#define LST2_M_SingleLinkGetElementNumber(n, hAnchor, hElement, k, i)       \
{														\
	for													\
	(													\
        (i)=0,(hElement)=LST2_M_SingleLinkGetFirstElement(n, (hAnchor));    \
		(i)<(k);											\
        (i)++,(hElement)=LST2_M_SingleLinkGetNextElement(n, (hElement))     \
	);														\
}

#define LST2_M_SingleLinkGetNthBrother(n, hFirstElement, hElement, k, i)        \
{														\
	for													\
	(													\
		(i)=0,(hElement)=hFirstElement;	\
		(i)<(k);											\
        (i)++,(hElement)=LST2_M_SingleLinkGetNextElement(n, (hElement))     \
	);														\
}

#endif
