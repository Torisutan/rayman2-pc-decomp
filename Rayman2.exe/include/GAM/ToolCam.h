#ifndef RAYMAN2_GAM_TOOLCAM_H
#define RAYMAN2_GAM_TOOLCAM_H

#define CAM_Nb_Viewport	2

typedef struct tdstViewportManagement_
{
	struct HIE_tdstSuperObject	*hCamera;
	struct HIE_tdstSuperObject	*hTempCamera;
	struct GLI_tdstCamera_		*p_stCamera;
	ACP_tdxBool					bValid;
}tdstViewportManagement;

typedef struct tdstViewportManagement_	*tdxHandleToViewportManagement;

#endif
