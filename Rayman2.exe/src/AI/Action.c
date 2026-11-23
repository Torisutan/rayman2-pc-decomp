#include <ctype.h>
#include <string.h>

#include "AI/MetaAction.h"
#include "AI/ActParam.h"
#include "GAM/GAM_types.h"

#define STRING1_TO_CHAR(str1) ((char) (*((char *)str1)))
#define C_ACTION_PARAM        "A"
#define C_VECTOR_PARAM        "V"
#define C_REAL_PARAM          "X"
#define C_LONG_PARAM          "L"

/* 0x00481120 */
AI_tdstNodeInterpret *__cdecl fn_p_stDefaultActionInit(HIE_tdstSuperObject *p_SuperObjPerso,
                                                       AI_tdstNodeInterpret *p_stTree)
{
    char          *szTypeParam = NULL;
    unsigned char  ucNbParam = 0;
    enum tdeMetaActionId_ eMetaActionId = (enum tdeMetaActionId_) AI_M_eMetaActionIdInterpret(p_stTree - 1);

    szTypeParam = szGetMetaActionTypeInParamFromId(eMetaActionId);
    ucNbParam = (unsigned char) strlen(szTypeParam);

    if (ucNbParam != 0)
    {
        AI_tdstGetSetParam stParam;
        char               cType;
        unsigned char      ucParam = 0;

        for (ucParam = 0; ucParam < ucNbParam; ucParam++)
        {

            p_stTree = fn_p_stEvalTree(p_SuperObjPerso, p_stTree, &stParam);

            cType = (char) toupper(szTypeParam[ucParam]);

            if (cType == STRING1_TO_CHAR(C_LONG_PARAM))
            {
                fn_vSetActionParamlValue(ucParam, p_SuperObjPerso, M_ReturnParam_lValue(&stParam));
            }

            else if (cType == STRING1_TO_CHAR(C_REAL_PARAM))
            {
                fn_vSetActionParamxValue(ucParam, p_SuperObjPerso, M_ReturnParam_xValue(&stParam));
            }

            else if (cType == STRING1_TO_CHAR(C_VECTOR_PARAM))
            {
                fn_vSetActionParamp_stVertex(ucParam, p_SuperObjPerso, &M_GetSetParam_stVertexValue(&stParam));
            }

            else if (cType == STRING1_TO_CHAR(C_ACTION_PARAM))
            {
                fn_vSetActionParamStateValue(ucParam, p_SuperObjPerso, M_GetSetParam_ActionValue(&stParam));
            }
        }
    }
    return p_stTree;
}
