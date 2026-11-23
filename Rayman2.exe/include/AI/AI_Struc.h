#ifndef AI_STRUC_H
#define AI_STRUC_H

typedef struct AI_tdstAIModel_
{
    AI_tdstScriptAI *p_stScriptAIIntell;
    AI_tdstScriptAI *p_stScriptAIReflex;
    AI_tdstDsgVar   *p_stDsgVar;
} AI_tdstAIModel;

#endif
