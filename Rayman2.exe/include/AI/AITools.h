#ifndef RAYMAN2_AI_AITOOLS_H
#define RAYMAN2_AI_AITOOLS_H

struct AI_tdstGetSetParam_;
struct GEO_tdstColor_;

unsigned char fn_ucIsThereFloatIfYesConvertItToInteger(struct AI_tdstGetSetParam_ *p_stParam);

void fn_vConvertParamToColor(struct AI_tdstGetSetParam_ *p_stParam,struct GEO_tdstColor_ *p_stColor);
void fn_vConvertColorToParam(struct GEO_tdstColor_ *p_stColor,struct AI_tdstGetSetParam_ *p_stParam);

#endif
