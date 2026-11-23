#if !defined(M_DEFINE_KEYWORD)
#error You should define M_DEFINE_KEYWORD accordingly before including this file !
#endif

M_DEFINE_KEYWORD(eKeyWord_If           ,"Si"               ,"If"              ,"If"              ,fn_p_stIfKeyWord,USE_BOOLEAN_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_IfNot        ,"SiPas"            ,"IfNot"           ,"IfNot"           ,fn_p_stIfKeyWord,USE_BOOLEAN_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_If2          ,"Si2"              ,"If2"             ,"If2"             ,fn_p_stIfKeyWord,USE_BOOLEAN_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_If4          ,"Si4"              ,"If4"             ,"If4"             ,fn_p_stIfKeyWord,USE_BOOLEAN_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_If8          ,"Si8"              ,"If8"             ,"If8"             ,fn_p_stIfKeyWord,USE_BOOLEAN_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_If16         ,"Si16"             ,"If16"            ,"If16"            ,fn_p_stIfKeyWord,USE_BOOLEAN_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_IfDebug	   ,"SiDebug"          ,"IfDebug"         ,"IfDebug"         ,fn_p_stIfDebug,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_IfNotU64	   ,"SiPasU64"         ,"IfNotU64"        ,"IfNotU64"        ,fn_p_stIfNotU64,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_Then         ,"Alors"            ,"Then"            ,"Then"            ,fn_p_stThenKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_Else         ,"Sinon"            ,"Else"            ,"Else"            ,fn_p_stElseKeyWord,USE_NO_PARAM,USE_NO_PARAM)

M_DEFINE_KEYWORD(eKeyWord_EngineGoto   ,"_EngineGoto"      ,"_EngineGoto"     ,"_EngineGoto"     ,fn_p_stEngineGotoKeyWord,USE_CONSTANT_PARAM,USE_NO_PARAM)

M_DEFINE_KEYWORD(eKeyWord_Me           ,"Moi"              ,"Me"              ,"Me"              ,fn_p_stMeKeyWord,USE_NO_PARAM,USE_PERSO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_MainActor    ,"ActeurPrincipal"  ,"MainActor"       ,"MainActor"       ,fn_p_stMainActorKeyWord,USE_NO_PARAM,USE_PERSO_PARAM)

M_DEFINE_KEYWORD(eKeyWord_Nobody       ,"Personne"         ,"Nobody"          ,"Nobody"          ,fn_p_stNobodyKeyWord,USE_NO_PARAM,USE_PERSO_PARAM)

#if	!defined(U64) && !defined(NITRO)
M_DEFINE_KEYWORD(eKeyWord_NoSuperObject,"SansSuperObjet"   ,"NoSuperObject"   ,"NoSuperObject"   ,fn_p_stNoSuperObjectKeyWord,USE_NO_PARAM,USE_SUPEROBJECT_PARAM)
#endif

M_DEFINE_KEYWORD(eKeyWord_Nowhere      ,"Nullepart"        ,"Nowhere"         ,"Nowhere"         ,fn_p_stNowhereKeyWord,USE_NO_PARAM,USE_WAYPOINT_PARAM)
M_DEFINE_KEYWORD(eKeyWord_EmptyText    ,"TexteVide"        ,"EmptyText"       ,"EmptyText"       ,fn_p_stEmptyTextKeyWord,USE_NO_PARAM,USE_TEXT_PARAM)

M_DEFINE_KEYWORD(eKeyWord_CapsNull     ,"CapaZero"         ,"CapaNull"       ,"CapaNull"       ,fn_p_stCapsNullKeyWord, USE_NO_PARAM, USE_CAPS_PARAM)
M_DEFINE_KEYWORD(eKeyWord_NoGraph      ,"SansGraph"        ,"NoGraph"        ,"NoGraph"        ,fn_p_stNoGraphKeyWord, USE_NO_PARAM, USE_GRAPH_PARAM)

M_DEFINE_KEYWORD(eKeyWord_NoAction     ,"SansAction"       ,"NoAction"        ,"NoAction"        ,fn_p_stNoActionKeyWord,USE_NO_PARAM,USE_ACTION_PARAM)
#if defined(ACTIVE_EDITOR)
M_DEFINE_KEYWORD(eKeyWord_NoComport    ,"SansComportement" ,"NoComport"       ,"NoComport"       ,fn_p_stMiscKeyWord,USE_NO_PARAM,"")
M_DEFINE_KEYWORD(eKeyWord_Schedule     ,"EmploiTemps"      ,"Schedule"        ,"Schedule"        ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_InterruptRule,"RegleInterruption","InterruptRule"   ,"InterruptRule"   ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_Vector       ,"Vecteur"          ,"Vector"          ,"Vector"          ,fn_p_stMiscKeyWord,USE_3_REALS_PARAM,USE_VECTOR_PARAM)
M_DEFINE_KEYWORD(eKeyWord_ConstVector  ,"VecteurConstant"  ,"ConstantVector"  ,"ConstantVector"  ,fn_p_stMiscKeyWord,USE_3_REALS_PARAM,USE_VECTOR_PARAM)
M_DEFINE_KEYWORD(eKeyWord_Endif        ,"FinSi"            ,"Endif"           ,"Endif"           ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_Macro        ,"Macro"            ,"Macro"           ,"Macro"           ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_True         ,"Vrai"			   ,"True"            ,"True"            ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_False        ,"Faux"			   ,"False"           ,"False"           ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_StopEngine   ,"BloquantMoteur"   ,"StopEngine"      ,"StopEngine"      ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_StopRule     ,"BloquantRegle"    ,"StopRule"        ,"StopRule"        ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
M_DEFINE_KEYWORD(eKeyWord_NonStop      ,"NonBloquant"      ,"NonStop"         ,"NonStop"         ,fn_p_stMiscKeyWord,USE_NO_PARAM,USE_NO_PARAM)
#endif

#if defined(M_DEFINE_KEYWORD)
#undef M_DEFINE_KEYWORD
#endif
