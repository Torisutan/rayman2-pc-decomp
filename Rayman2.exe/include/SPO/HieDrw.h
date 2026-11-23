#ifndef __HIEDRW_MIRROR_H__
#define __HIEDRW_MIRROR_H__

#define HIE_C_InheritableFlags  \
	(GLI_C_lIsNotVisibleInRealWorld|\
	 GLI_C_lIsNotVisibleInSymetricWorld|\
	 GLI_C_lCameraIsUnderWater|\
	 GLI_C_lIsNotDrawingSuperObjectBoundingVolume|\
	 GLI_C_lIsNotDrawingInMirror|\
	 GLI_C_lNotInvertBackfaces|\
	 GLI_C_lNotHideWhatIsUnderWater|\
	 GLI_C_lIsNotWired)

#endif
