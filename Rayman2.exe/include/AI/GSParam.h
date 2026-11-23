#ifndef RAYMAN2_AI_GSPARAM_H
#define RAYMAN2_AI_GSPARAM_H

#include "MTH/MTH_types.h"

#define C_INVALID_GET 0
#define C_VALID_GET   1
#define C_INVALID_SET 0
#define C_VALID_SET   1

#include "AI/VarType.h"

typedef struct RGBAComponent_
{
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;
	unsigned char Alpha;
} RGBAComponent;

typedef union RGBAStruct_
{
	long Color;
	RGBAComponent Component;
} RGBAStruct;

#define RGBA_Color(n) ((n).Color)
#define RGBA_Component(n) ((n).Component)
#define RGBA_Red(n)   (RGBA_Component(n).Red)
#define RGBA_Green(n) (RGBA_Component(n).Green)
#define RGBA_Blue(n)  (RGBA_Component(n).Blue)
#define RGBA_Alpha(n) (RGBA_Component(n).Alpha)

typedef union AI_tduGetSetParam_
{
  float          xValue;
  long           lValue;
  unsigned long  ulValue;
  short          wValue;
  unsigned short uwValue;
  char           cValue;
  unsigned char  ucValue;
  unsigned char  bf7Value:7;
  unsigned char  bf6Value:6;
  unsigned char  bf5Value:5;
  unsigned char  bf4Value:4;
  unsigned char  bf3Value:3;
  unsigned char  bf2Value:2;
  unsigned char  bf1Value:1;
  RGBAStruct	   ColorValue;
  char           *szString;
  struct tdstEngineObject_    *p_stEngObjValue;
  struct tdstState_           *tdxstHandleToState;
  struct HIE_tdstSuperObject  *hSuperObject;
  struct WP_tdstWayPoint_     *m_hWayPoint;
  unsigned short               xMask;
  struct tdstLipsSynchroTable_ *hLipsSynchro;
  struct tdstObjectsTablesList_ *hObjectTable;
  struct tdstFamilyList_      *hFamily;
  struct _SND_tdstBlockEvent  *pSoundEvent;
  struct AI_tdstComport_      *pComport;
  long                         hText;
  struct tdstParticleGenerator_ *hParticleGenerator;
  struct GMT_tdstGameMaterial_ *hGameMaterial;
  struct AI_tdstAIModel_      *p_stModel;
  MTH3D_tdstVector             stVectorValue;
  struct GLI_tdstLight_       *p_stLight;
  struct WP_tdstGraph_        *hGraph;
  struct AI_tdstMacro_        *p_stMacro;
  float                        a_xVectorValue[3];
} AI_tduGetSetParam;

typedef union AI_tduGetSetParamForNode_
{
  float          xValue;
  long           lValue;
  unsigned long  ulValue;
  short          wValue;
  unsigned short uwValue;
  char           cValue;
  unsigned char  ucValue;
  RGBAStruct	   ColorValue;
  char           *szString;
  struct tdstEngineObject_    *p_stEngObjValue;
  struct tdstState_           *tdxstHandleToState;
  struct HIE_tdstSuperObject  *hSuperObject;
  struct WP_tdstWayPoint_     *m_hWayPoint;
  unsigned short               xMask;
  struct tdstLipsSynchroTable_ *hLipsSynchro;
  struct tdstObjectsTablesList_ *hObjectTable;
  struct tdstFamilyList_      *hFamily;
  struct _SND_tdstBlockEvent  *pSoundEvent;
  struct AI_tdstComport_      *pComport;
  long                         hText;
  struct tdstParticleGenerator_ *hParticleGenerator;
  struct GMT_tdstGameMaterial_ *hGameMaterial;
  struct AI_tdstAIModel_      *p_stModel;
  MTH3D_tdstVector            *p_stVectorValue;
  struct GLI_tdstLight_       *p_stLight;
  struct WP_tdstGraph_        *hGraph;
  struct AI_tdstMacro_        *p_stMacro;
} AI_tduGetSetParamForNode;

typedef struct AI_tdstGetSetParam_
{
    AI_tduGetSetParam uParam;
    enum tdeVariableType_ eType;
} AI_tdstGetSetParam;

#define M_tduGetSetParam_szString(n)			     ((n)->szString)
#define M_tduGetSetParam_xValue(n)				     ((n)->xValue)
#define M_tduGetSetParam_lValue(n)				     ((n)->lValue)
#define M_tduGetSetParam_ulValue(n)				     ((n)->ulValue)

#define M_tduGetSetParam_p_stEngObjValue(n)		 ((n)->p_stEngObjValue)
#define M_tduGetSetParam_boolValue(n)			     M_tduGetSetParam_lValue(n)
#define M_tduGetSetParam_HandleToState(n)      ((n)->tdxstHandleToState)
#define M_tduGetSetParam_stVertexValue(n)	     M_tduGetSetParam_stVectorValue(n)
#define M_tduGetSetParam_p_stVectorValue(n)		 ((n)->p_stVectorValue)
#define M_tduGetSetParam_stVectorValue(n)		   ((n)->stVectorValue)
#define M_tduGetSetParam_hWayPoint(n)			     ((n)->m_hWayPoint)
#define M_GetSetParam_lZDMIdValue(n)			     M_GetSetParam_lValue(n)
#define M_tduGetSetParam_hLipsSynchro(n)		   ((n)->hLipsSynchro)
#define M_tduGetSetParam_hFamily(n)				     ((n)->hFamily)
#define M_tduGetSetParam_hObjectTable(n)		   ((n)->hObjectTable)
#define M_tduGetSetParam_hSuperObject(n)		   ((n)->hSuperObject)
#define M_tduGetSetParam_pSoundEvent(n)			   ((n)->pSoundEvent)
#define M_tduGetSetParam_pComport(n)           ((n)->pComport)
#define M_tduGetSetParam_hText(n)              ((n)->hText)
#define M_tduGetSetParam_hParticleGenerator(n) ((n)->hParticleGenerator)
#define M_tduGetSetParam_hGameMaterial(n)      ((n)->hGameMaterial)
#define M_tduGetSetParam_p_stModel(n)			     ((n)->p_stModel)

#define M_tduGetSetParam_ColorValue(n)    RGBA_Color(M_tduGetSetParam_Color(n))
#define M_tduGetSetParam_Color(n)         ((n)->ColorValue)
#define M_tduGetSetParam_RedValue(n)			RGBA_Red(M_tduGetSetParam_Color(n))
#define M_tduGetSetParam_GreenValue(n)    RGBA_Green(M_tduGetSetParam_Color(n))
#define M_tduGetSetParam_BlueValue(n)			RGBA_Blue(M_tduGetSetParam_Color(n))
#define M_tduGetSetParam_AlphaValue(n)    RGBA_Alpha(M_tduGetSetParam_Color(n))

#define M_tduGetSetParam_p_stLight(n)			((n)->p_stLight)
#define M_tduGetSetParam_ubf32Caps(n)			((n)->ulValue)
#define M_tduGetSetParam_hGraph(n)				((n)->hGraph)
#define M_tduGetSetParam_p_stMacro(n)			((n)->p_stMacro)

#define M_tduGetSetParam_wValue(n)				((n)->wValue)
#define M_tduGetSetParam_uwValue(n)				((n)->uwValue)
#define M_tduGetSetParam_cValue(n)				((n)->cValue)
#define M_tduGetSetParam_ucValue(n)				((n)->ucValue)
#define M_tduGetSetParam_bf7Value(n)			((n)->bf7Value)
#define M_tduGetSetParam_bf6Value(n)			((n)->bf6Value)
#define M_tduGetSetParam_bf5Value(n)			((n)->bf5Value)
#define M_tduGetSetParam_bf4Value(n)			((n)->bf4Value)
#define M_tduGetSetParam_bf3Value(n)			((n)->bf3Value)
#define M_tduGetSetParam_bf2Value(n)			((n)->bf2Value)
#define M_tduGetSetParam_bf1Value(n)			((n)->bf1Value)
#define M_tduGetSetParam_xMaskValue(n)    ((n)->xMask)

#define M_GetSetParam_Param(n)    (&((n)->uParam))

#define M_GetSetParam_Type(n)     ((n)->eType)

#define M_GetSetParam_szString(n)           M_tduGetSetParam_szString(M_GetSetParam_Param(n))
#define M_GetSetParam_xValue(n)             M_tduGetSetParam_xValue(M_GetSetParam_Param(n))
#define M_GetSetParam_lValue(n)             M_tduGetSetParam_lValue(M_GetSetParam_Param(n))
#define M_GetSetParam_ulValue(n)            M_tduGetSetParam_ulValue(M_GetSetParam_Param(n))
#define M_GetSetParam_wValue(n)             M_tduGetSetParam_wValue(M_GetSetParam_Param(n))
#define M_GetSetParam_uwValue(n)            M_tduGetSetParam_uwValue(M_GetSetParam_Param(n))
#define M_GetSetParam_cValue(n)             M_tduGetSetParam_cValue(M_GetSetParam_Param(n))
#define M_GetSetParam_ucValue(n)            M_tduGetSetParam_ucValue(M_GetSetParam_Param(n))
#define M_GetSetParam_bf7Value(n)           M_tduGetSetParam_bf7Value(M_GetSetParam_Param(n))
#define M_GetSetParam_bf6Value(n)           M_tduGetSetParam_bf6Value(M_GetSetParam_Param(n))
#define M_GetSetParam_bf5Value(n)           M_tduGetSetParam_bf5Value(M_GetSetParam_Param(n))
#define M_GetSetParam_bf4Value(n)           M_tduGetSetParam_bf4Value(M_GetSetParam_Param(n))
#define M_GetSetParam_bf3Value(n)           M_tduGetSetParam_bf3Value(M_GetSetParam_Param(n))
#define M_GetSetParam_bf2Value(n)           M_tduGetSetParam_bf2Value(M_GetSetParam_Param(n))
#define M_GetSetParam_bf1Value(n)           M_tduGetSetParam_bf1Value(M_GetSetParam_Param(n))

#define M_GetSetParam_p_stSupObjValue(n)    M_GetSuperObject(M_tduGetSetParam_p_stEngObjValue(M_GetSetParam_Param(n)))
#define M_GetSetParam_p_stEngineObjValue(n)	M_tduGetSetParam_p_stEngObjValue(M_GetSetParam_Param(n))
#define M_GetSetParam_lPersoId(n)           M_GetSetParam_lValue(n)
#define M_GetSetParam_ActionReturnValue(n)  M_GetSetParam_lValue(n)
#define M_GetSetParam_ActionValue(n)        M_tduGetSetParam_HandleToState(M_GetSetParam_Param(n))
#define M_GetSetParam_lZdxId(n)             M_GetSetParam_lValue(n)
#define M_GetSetParam_stVertexValue(n)      M_GetSetParam_stVectorValue(n)
#define M_GetSetParam_p_stVectorValue(n)    M_tduGetSetParam_p_stVectorValue(M_GetSetParam_Param(n))
#define M_GetSetParam_stVectorValue(n)      M_tduGetSetParam_stVectorValue(M_GetSetParam_Param(n))
#define M_GetSetParam_WayPointValue(n)      M_tduGetSetParam_hWayPoint(M_GetSetParam_Param(n))
#define M_GetSetParam_lModuleValue(n)       M_GetSetParam_lValue(n)
#define M_GetSetParam_lDsgVarIdValue(n)     M_GetSetParam_lValue(n)
#define M_GetSetParam_xMaskValue(n)         M_tduGetSetParam_xMaskValue(M_GetSetParam_Param(n))
#define M_GetSetParam_ulTimeValue(n)        M_GetSetParam_ulValue(n)
#define M_GetSetParam_hLipsSynchro(n)       M_tduGetSetParam_hLipsSynchro(M_GetSetParam_Param(n))
#define M_GetSetParam_hFamily(n)            M_tduGetSetParam_hFamily(M_GetSetParam_Param(n))
#define M_GetSetParam_hObjectTable(n)       M_tduGetSetParam_hObjectTable(M_GetSetParam_Param(n))
#define M_GetSetParam_SuperObjectValue(n)   M_tduGetSetParam_hSuperObject(M_GetSetParam_Param(n))
#define M_GetSetParam_SectorValue(n)        M_GetSetParam_SuperObjectValue(n)
#define M_GetSetParam_DNMLimbTypeValue(n)   M_GetSetParam_lValue(n)
#define M_GetSetParam_SoundEvent(n)         M_tduGetSetParam_pSoundEvent(M_GetSetParam_Param(n))
#define M_GetSetParam_pComport(n)           M_tduGetSetParam_pComport(M_GetSetParam_Param(n))
#define M_GetSetParam_hText(n)	            M_tduGetSetParam_hText(M_GetSetParam_Param(n))
#define M_GetSetParam_hParticleGenerator(n)	M_tduGetSetParam_hParticleGenerator(M_GetSetParam_Param(n))
#define M_GetSetParam_hGameMaterial(n)      M_tduGetSetParam_hGameMaterial(M_GetSetParam_Param(n))
#define M_GetSetParam_p_stModel(n)          M_tduGetSetParam_p_stModel(M_GetSetParam_Param(n))
#define M_GetSetParam_Color(n)              M_tduGetSetParam_Color(M_GetSetParam_Param(n))
#define M_GetSetParam_ColorValue(n)         M_tduGetSetParam_ColorValue(M_GetSetParam_Param(n))
#define M_GetSetParam_RedValue(n)           M_tduGetSetParam_RedValue(M_GetSetParam_Param(n))
#define M_GetSetParam_GreenValue(n)         M_tduGetSetParam_GreenValue(M_GetSetParam_Param(n))
#define M_GetSetParam_BlueValue(n)          M_tduGetSetParam_BlueValue(M_GetSetParam_Param(n))
#define M_GetSetParam_AlphaValue(n)         M_tduGetSetParam_AlphaValue(M_GetSetParam_Param(n))
#define M_GetSetParam_LightValue(n)         M_tduGetSetParam_p_stLight(M_GetSetParam_Param(n))
#define M_GetSetParam_CapsValue(n)          M_tduGetSetParam_ubf32Caps(M_GetSetParam_Param(n))
#define M_GetSetParam_GraphValue(n)         M_tduGetSetParam_hGraph(M_GetSetParam_Param(n))
#define M_GetSetParam_p_stMacroValue(n)     M_tduGetSetParam_p_stMacro(M_GetSetParam_Param(n))

#define M_GetSetParam_Dsg_Boolean(n)           M_GetSetParam_cValue(n)
#define M_GetSetParam_Dsg__128To127(n)         M_GetSetParam_cValue(n)
#define M_GetSetParam_Dsg_0To255(n)            M_GetSetParam_ucValue(n)
#define M_GetSetParam_Dsg__32768To32767(n)     M_GetSetParam_wValue(n)
#define M_GetSetParam_Dsg_0To65535(n)          M_GetSetParam_uwValue(n)
#define M_GetSetParam_Dsg_Integer(n)           M_GetSetParam_lValue(n)
#define M_GetSetParam_Dsg_PositiveInteger(n)   M_GetSetParam_ulValue(n)
#define M_GetSetParam_Dsg_Float(n)             M_GetSetParam_xValue(n)
#define M_GetSetParam_Dsg_Perso(n)             M_GetSetParam_lPersoId(n)
#define M_GetSetParam_Dsg_PersoInList(n)       M_GetSetParam_cValue(n)
#define M_GetSetParam_Dsg_List(n)              M_GetSetParam_lValue(n)
#define M_GetSetParam_Dsg_WayPoint(n)          M_GetSetParam_WayPointValue(n)
#define M_GetSetParam_Dsg_Vector(n)            (&M_GetSetParam_stVectorValue(n))
#define M_GetSetParam_Dsg_Comport(n)           M_GetSetParam_pComport(n)
#define M_GetSetParam_Dsg_Action(n)            M_GetSetParam_ActionValue(n)
#define M_GetSetParam_Dsg_Text(n)              M_GetSetParam_hText(n)
#define M_GetSetParam_Dsg_GameMaterial(n)      M_GetSetParam_hGameMaterial(n)
#define M_GetSetParam_Dsg_Caps(n)              M_GetSetParam_CapsValue(n)
#define M_GetSetParam_Dsg_Graph(n)             M_GetSetParam_GraphValue(n)

#define M_ReturnParam_lValue(n) \
  (  \
    (M_GetSetParam_Type(n)==E_vt_Float) \
    ? ( MTH_M_xRealToLong(M_GetSetParam_xValue(n)) ) \
	: ( M_GetSetParam_lValue(n) ) \
  )
#define M_ReturnParam_xValue(n) \
  (  \
    (M_GetSetParam_Type(n)==E_vt_Float) \
    ? ( M_GetSetParam_xValue(n) ) \
	: ( MTH_M_xLongToReal(M_GetSetParam_lValue(n)) ) \
  )

#define M_Full_GetSetParam_Integer(p_stValue,lValue) \
   M_GetSetParam_lValue(p_stValue)=(long) (lValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Integer;

#define M_Full_GetSetParam_Float(p_stValue,xValue) \
   M_GetSetParam_xValue(p_stValue)=(xValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Float;

#define M_Full_GetSetParam_ActionReturn(p_stValue,ucActionReturn) \
   M_GetSetParam_ActionReturnValue(p_stValue)=(ucActionReturn); \
   M_GetSetParam_Type(p_stValue)=E_vt_MetaActionReturn;

#define M_Full_GetSetParam_Perso(p_stValue,pPerso) \
   M_GetSetParam_p_stEngineObjValue(p_stValue) = ((pPerso==NULL)?NULL:M_GetEngineObject(pPerso)); \
   M_GetSetParam_Type(p_stValue)=E_vt_Perso;

#define M_Full_GetSetParam_SuperObject(p_stValue,pSuperObject) \
   M_GetSetParam_SuperObjectValue(p_stValue) = (pSuperObject); \
   M_GetSetParam_Type(p_stValue)=E_vt_SuperObject;

#define M_Full_GetSetParam_hLipsSynchro(p_stValue,hLipsSynchro) \
   M_GetSetParam_hLipsSynchro(p_stValue) = hLipsSynchro; \
   M_GetSetParam_Type(p_stValue)=E_vt_LipsSynchro;

#define M_Full_GetSetParam_hObjectTable(p_stValue,hObjectTable) \
   M_GetSetParam_hObjectTable(p_stValue) = hObjectTable; \
   M_GetSetParam_Type(p_stValue)=E_vt_ObjectTable;

#define M_Full_GetSetParam_hFamily(p_stValue,hFamily) \
   M_GetSetParam_hFamily(p_stValue) = hFamily; \
   M_GetSetParam_Type(p_stValue)=E_vt_Family;

#define M_Full_GetSetParam_p_stVertex(p_stValue,p_stVertex) \
	MTH3D_M_vCopyVector(&M_GetSetParam_stVertexValue(p_stValue),p_stVertex);	\
    M_GetSetParam_Type(p_stValue)=E_vt_Vector;

#define M_Full_GetSetParam_Button(p_stValue,lValue) \
   M_GetSetParam_lValue(p_stValue)=(long)(lValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Button;

#define M_Full_GetSetParam_List(p_stValue,lValue) \
   M_GetSetParam_Dsg_List(p_stValue)=(long) ((tdstList*) (lValue) ); \
   M_GetSetParam_Type(p_stValue)=E_vt_List;

#define M_Full_GetSetParam_WayPoint(p_stValue,lWP)\
  M_GetSetParam_WayPointValue(p_stValue) = (lWP);\
  M_GetSetParam_Type(p_stValue) = E_vt_WayPoint;

#define M_Full_GetSetParam_Module(p_stValue,lModule) \
	M_GetSetParam_lModuleValue(p_stValue)=(long) (lModule);	\
	M_GetSetParam_Type(p_stValue)=E_vt_Module;

#define M_Full_GetSetParam_DsgVarId(p_stValue,lDsgVarId) \
	M_GetSetParam_lDsgVarIdValue(p_stValue)=(long) (lDsgVarId);	\
	M_GetSetParam_Type(p_stValue)=E_vt_DsgVarId;

#define M_Full_GetSetParam_String(p_stValue, szString) \
	M_GetSetParam_szString(p_stValue) = (szString);	\
	M_GetSetParam_Type(p_stValue) = E_vt_String;

#define M_Full_GetSetParam_Mask(p_stValue,xMask) \
   M_GetSetParam_lValue(p_stValue) = (long) (xMask); \
   M_GetSetParam_Type(p_stValue)=E_vt_Mask;

#define M_Full_GetSetParam_Time(p_stValue,ulValue) \
   M_GetSetParam_ulTimeValue(p_stValue)=(unsigned long) (ulValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_PositiveInteger;

#define M_Full_GetSetParam_SoundEvent(p_stValue,pSndEvent) \
   M_GetSetParam_SoundEvent(p_stValue)=(pSndEvent); \
   M_GetSetParam_Type(p_stValue)=E_vt_SoundEvent;

#define M_Full_GetSetParam_pComport(p_stValue,pComport) \
   M_GetSetParam_pComport(p_stValue)=(pComport); \
   M_GetSetParam_Type(p_stValue)=E_vt_Comport;

#define M_Full_GetSetParam_Action(p_stValue,hAction) \
   M_GetSetParam_ActionValue(p_stValue)=(hAction); \
   M_GetSetParam_Type(p_stValue)=E_vt_Action;

#define M_Full_GetSetParam_hText(p_stValue,hText) \
   M_GetSetParam_hText(p_stValue)=(hText); \
   M_GetSetParam_Type(p_stValue)=E_vt_Text;

#define M_Full_GetSetParam_hParticleGenerator(p_stValue,hParticleGenerator) \
   M_GetSetParam_hParticleGenerator(p_stValue)=(hParticleGenerator); \
   M_GetSetParam_Type(p_stValue)=E_vt_ParticleGenerator;

#define M_Full_GetSetParam_hGameMaterial(p_stValue, hGameMaterial) \
   M_GetSetParam_hGameMaterial(p_stValue)=(hGameMaterial); \
   M_GetSetParam_Type(p_stValue)=E_vt_GameMaterial;

#define M_Full_GetSetParam_ColorValue(p_stValue,ColorValue) \
   M_GetSetParam_ColorValue(p_stValue)=(long) (ColorValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Color;

#define M_Full_GetSetParam_p_stModel(p_stValue,ModelValue) \
   M_GetSetParam_p_stModel(p_stValue)=(AI_tdstAIModel*) (ModelValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Model;

#define M_Full_GetSetParam_Light(p_stValue,LightValue) \
   M_GetSetParam_LightValue(p_stValue)=(LightValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Light;

#define M_Full_GetSetParam_Caps(p_stValue, CapsValue) \
   M_GetSetParam_CapsValue(p_stValue)=(CapsValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Caps;

#define M_Full_GetSetParam_Graph(p_stValue, GraphValue) \
   M_GetSetParam_GraphValue(p_stValue)=(GraphValue); \
   M_GetSetParam_Type(p_stValue)=E_vt_Graph;

#define M_IsFloatType(p_stParam)                   (M_GetSetParam_Type((p_stParam))==E_vt_Float)
#define M_IsVectorType(p_stParam)                   (M_GetSetParam_Type((p_stParam))==E_vt_Vector)

#endif
