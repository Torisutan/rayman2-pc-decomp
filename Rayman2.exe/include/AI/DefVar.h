#if !defined(M_DEFINE_DSGVAR_TYPE)
#error You should define M_DEFINE_DSGVAR_TYPE accordingly before including this file !
#endif

	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Boolean		,"Booleen"				,"Boolean"			,E_vt_Boolean		,C_ADDR_BOOLEAN_PARAM	,C_NO_PARAM				,fn_ucGetDsgVarBoolean			,fn_ucSetDsgVarBoolean			,fn_p_cBinaryLoadDsgVarBoolean			,fn_p_cBinarySaveDsgVarBoolean)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType__128To127		,"Entier_128To127"		,"_128To127"		,E_vt__128To127		,C_ADDR_LONG_PARAM		,C_NO_PARAM				,fn_ucGetDsgVar_128To127		,fn_ucSetDsgVar_128To127		,fn_p_cBinaryLoadDsgVar_128To127		,fn_p_cBinarySaveDsgVar_128To127)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_0To255			,"Entier0To255"			,"0To255"			,E_vt_0To255		,C_ADDR_LONG_PARAM		,C_NO_PARAM				,fn_ucGetDsgVar0To255			,fn_ucSetDsgVar0To255			,fn_p_cBinaryLoadDsgVar0To255			,fn_p_cBinarySaveDsgVar0To255)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType__32768To32767	,"Entier_32768To32767"	,"_32768To32767"	,E_vt__32768To32767	,C_ADDR_LONG_PARAM		,C_NO_PARAM				,fn_ucGetDsgVar_32768To32767	,fn_ucSetDsgVar_32768To32767	,fn_p_cBinaryLoadDsgVar_32768To32767	,fn_p_cBinarySaveDsgVar_32768To32767)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_0To65535		,"Entier0To65535"		,"0To65535"			,E_vt_0To65535		,C_ADDR_LONG_PARAM		,C_NO_PARAM				,fn_ucGetDsgVar0To65535			,fn_ucSetDsgVar0To65535			,fn_p_cBinaryLoadDsgVar0To65535			,fn_p_cBinarySaveDsgVar0To65535)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Integer		,"Entier"				,"Integer"			,E_vt_Integer		,C_ADDR_LONG_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarInteger			,fn_ucSetDsgVarInteger			,fn_p_cBinaryLoadDsgVarInteger			,fn_p_cBinarySaveDsgVarInteger)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_PositiveInteger,"EntierPositif"		,"PositiveInteger"	,E_vt_PositiveInteger,C_ADDR_LONG_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarPositiveInteger	,fn_ucSetDsgVarPositiveInteger	,fn_p_cBinaryLoadDsgVarPositiveInteger	,fn_p_cBinarySaveDsgVarPositiveInteger)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Float			,"Reel"					,"Float"			,E_vt_Float			,C_ADDR_REAL_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarFloat			,fn_ucSetDsgVarFloat			,fn_p_cBinaryLoadDsgVarFloat			,fn_p_cBinarySaveDsgVarFloat)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_WayPoint		,"WayPoint"				,"WayPoint"			,E_vt_WayPoint		,C_ADDR_WAYPOINT_PARAM	,C_NO_PARAM				,fn_ucGetDsgVarWayPoint			,fn_ucSetDsgVarWayPoint			,fn_p_cBinaryLoadDsgVarWayPoint			,fn_p_cBinarySaveDsgVarWayPoint)

	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Perso			,"Perso"				,"Perso"			,E_vt_Perso			,C_ADDR_PERSO_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarPerso			,fn_ucSetDsgVarPerso			,fn_p_cBinaryLoadDsgVarPerso			,fn_p_cBinarySaveDsgVarPerso)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_List			,"Liste"				,"List"				,E_vt_List			,C_ADDR_LIST_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarList				,fn_ucSetDsgVarList				,fn_p_cBinaryLoadDsgVarList				,fn_p_cBinarySaveDsgVarList)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Vector			,"TypeVecteur"			,"Vector"			,E_vt_Vector		,C_ADDR_VECTOR_PARAM	,C_NO_PARAM				,fn_ucGetDsgVarVector			,fn_ucSetDsgVarVector			,fn_p_cBinaryLoadDsgVarVector			,fn_p_cBinarySaveDsgVarVector)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Comport		,"TypeComportement"		,"Comport"			,E_vt_Comport		,C_ADDR_COMPORT_PARAM	,C_NO_PARAM				,fn_ucGetDsgVarComport			,fn_ucSetDsgVarComport			,fn_p_cBinaryLoadDsgVarComport			,fn_p_cBinarySaveDsgVarComport)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Action			,"TypeAction"			,"Action"			,E_vt_Action		,C_ADDR_ACTION_PARAM	,C_NO_PARAM				,fn_ucGetDsgVarAction			,fn_ucSetDsgVarAction			,fn_p_cBinaryLoadDsgVarAction			,fn_p_cBinarySaveDsgVarAction)
  M_DEFINE_DSGVAR_TYPE(eDsgVarType_Text     ,"Texte"        ,"Text"       ,E_vt_Text      ,C_ADDR_TEXT_PARAM  ,C_NO_PARAM    ,fn_ucGetDsgVarText    ,fn_ucSetDsgVarText    ,fn_p_cBinaryLoadDsgVarText    ,fn_p_cBinarySaveDsgVarText)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_GameMaterial	,"TypeMateriauJeu"		,"GameMaterial"		,E_vt_GameMaterial	,C_ADDR_GMT_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarGameMaterial		,fn_ucSetDsgVarGameMaterial		,fn_p_cBinaryLoadDsgVarGameMaterial		,fn_p_cBinarySaveDsgVarGameMaterial)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Caps			,"TypeCapacite"			,"Capability"		,E_vt_Caps			,C_ADDR_CAPS_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarCaps			,fn_ucSetDsgVarCaps			,fn_p_cBinaryLoadDsgVarCaps			,fn_p_cBinarySaveDsgVarCaps)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_Graph			,"TypeReseau"			,"Graph"			,E_vt_Graph			,C_ADDR_GRAPH_PARAM		,C_NO_PARAM				,fn_ucGetDsgVarGraph			,fn_ucSetDsgVarGraph			,fn_p_cBinaryLoadDsgVarGraph			,fn_p_cBinarySaveDsgVarGraph)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_PersoArray		,"TypeTableauPerso"		,"PersoArray"		,E_vt_Array			,C_ADDR_ARRAY_PARAM		,C_ADDR_PERSO_PARAM		,fn_ucGetDsgVarArray			,fn_ucSetDsgVarArray			,fn_p_cBinaryLoadDsgVarArray			,fn_p_cBinarySaveDsgVarArray)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_VectorArray	,"TypeTableauVecteur"	,"VectorArray"		,E_vt_Array			,C_ADDR_ARRAY_PARAM		,C_ADDR_VECTOR_PARAM	,fn_ucGetDsgVarArray			,fn_ucSetDsgVarArray			,fn_p_cBinaryLoadDsgVarArray			,fn_p_cBinarySaveDsgVarArray)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_FloatArray		,"TypeTableauReel"		,"FloatArray"		,E_vt_Array			,C_ADDR_ARRAY_PARAM		,C_ADDR_REAL_PARAM		,fn_ucGetDsgVarArray			,fn_ucSetDsgVarArray			,fn_p_cBinaryLoadDsgVarArray			,fn_p_cBinarySaveDsgVarArray)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_IntegerArray	,"TypeTableauEntier"	,"IntegerArray"		,E_vt_Array			,C_ADDR_ARRAY_PARAM		,C_ADDR_LONG_PARAM		,fn_ucGetDsgVarArray			,fn_ucSetDsgVarArray			,fn_p_cBinaryLoadDsgVarArray			,fn_p_cBinarySaveDsgVarArray)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_WayPointArray	,"TypeTableauWayPoint"	,"WayPointArray"	,E_vt_Array			,C_ADDR_ARRAY_PARAM		,C_ADDR_WAYPOINT_PARAM	,fn_ucGetDsgVarArray			,fn_ucSetDsgVarArray			,fn_p_cBinaryLoadDsgVarArray			,fn_p_cBinarySaveDsgVarArray)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_TextArray		,"TypeTableauTexte"		,"TextArray"		,E_vt_Array			,C_ADDR_ARRAY_PARAM		,C_ADDR_TEXT_PARAM		,fn_ucGetDsgVarArray			,fn_ucSetDsgVarArray			,fn_p_cBinaryLoadDsgVarArray			,fn_p_cBinarySaveDsgVarArray)

#if !defined(U64) && !defined(NITRO)
	M_DEFINE_DSGVAR_TYPE(eDsgVarType_SuperObject	,"TypeSuperObjet"		,"SuperObject"		,E_vt_SuperObject	,C_SUPEROBJECT_PARAM	,C_NO_PARAM				,fn_ucGetDsgVarSuperObject		,fn_ucSetDsgVarSuperObject		,fn_p_cBinaryLoadDsgVarSuperObject		,fn_p_cBinarySaveDsgVarSuperObject)
#endif

#if defined(M_DEFINE_DSGVAR_TYPE)
#undef M_DEFINE_DSGVAR_TYPE
#endif
