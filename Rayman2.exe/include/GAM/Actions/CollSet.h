#ifndef GAM_ACTIONS_COLLSET_H
#define GAM_ACTIONS_COLLSET_H

#define C_wCollsetNbCollisionVectors 2
#define C_wCollsetNbCollisionReals	2

typedef struct tdstCollSet_
{
   void *hZddList;
   void *hZdeList;
   void *hZdmList;
   void *hZdrList;
   void *hZddActivationList;
   void *hZdeActivationList;
   void *hZdmActivationList;
   void *hZdrActivationList;

   void *hZddCurrentActivation;
   void *hZdeCurrentActivation;
   void *hZdrCurrentActivation;
   void *hZdmCurrentActivation;

	unsigned long ulFBZddPriviligedZones;
	unsigned long ulFBZdePriviligedZones;
	unsigned long ulFBZdmPriviligedZones;
	unsigned long ulFBZdrPriviligedZones;
    unsigned char ucCollComputeFrequency;

    unsigned char ucCharacterPriority;
    unsigned char ucCollisionFlag;

	struct stColliderInfo_
	{
		MTH3D_tdstVector	a_stColliderVectors[C_wCollsetNbCollisionVectors];
		MTH_tdxReal			a_xColliderReals[C_wCollsetNbCollisionReals];
		unsigned char		ucColliderType;

		unsigned char		ucColliderPriority;
		unsigned char		a2_ucUnused[2];
	} stColliderInfo;

} tdstCollSet;

typedef struct tdstCollSet_ * MS_tdxHandleToCollSet;

#define CS_M_GetZdxList(ZoneType,p_stCollSet)								((p_stCollSet)->h##ZoneType##List)
#define CS_M_GetActivationList(ZoneType,p_stCollSet)						((p_stCollSet)->h##ZoneType##ActivationList)
#define CS_M_GetPrivilegedZone(ZoneType,p_stCollSet)						((p_stCollSet)->ulFB##ZoneType##PriviligedZones)
#define CS_M_SetPrivilegedZone(ZoneType,p_stCollSet,ulValue)				((p_stCollSet)->ulFB##ZoneType##PriviligedZones=ulValue)

#endif
