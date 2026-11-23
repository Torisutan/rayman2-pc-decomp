#ifndef RAYMAN2_AI_VARTYPE_H
#define RAYMAN2_AI_VARTYPE_H

typedef enum tdeVariableType_{
	E_vt_None=0,
		E_vt_Boolean,
		E_vt__128To127,
		E_vt_0To255,
		E_vt__32768To32767,
		E_vt_0To65535,
		E_vt_Integer,
		E_vt_PositiveInteger,
		E_vt_Float,
		E_vt_String,
		E_vt_WayPoint,
		E_vt_Perso,
		E_vt_List,
		E_vt_1bit,
		E_vt_2bit,
		E_vt_3bit,
		E_vt_4bit,
		E_vt_5bit,
		E_vt_6bit,
		E_vt_7bit,
		E_vt_MetaActionReturn,
		E_vt_Vector,
		E_vt_Module,
		E_vt_DsgVarId,
		E_vt_Action,
		E_vt_Button,
		E_vt_Mask,
		E_vt_Surface,
		E_vt_LipsSynchro,
		E_vt_ObjectTable,

		E_vt_SuperObject,
		E_vt_Environment,
		E_vt_Family,
		E_vt_SoundEvent,
		E_vt_Comport,
		E_vt_Font,
		E_vt_Text,
		E_vt_ParticleGenerator,
		E_vt_GameMaterial,
		E_vt_Color,
		E_vt_Model,
		E_vt_Array,
		E_vt_Light,
		E_vt_Caps,
		E_vt_Graph,

		E_Nb_vt

} tdeVariableType;

#endif
