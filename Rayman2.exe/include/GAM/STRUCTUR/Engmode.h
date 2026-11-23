#ifndef GAM_STRUCTUR_ENGMODE_H
#define GAM_STRUCTUR_ENGMODE_H

enum
{
 IM_Normal,
 IM_Commands,
 IM_NumberOfMode
};

typedef struct tdstLanguageStructure_
{
	char	szLanguageCode[20];
	char	szLanguageText[20];
}tdstLanguageStructure;

#define M_ulGetUsefulDeltaTimeInMilliSeconds(stTimer) ((stTimer).ulUsefulDeltaTime)

#define M_xGetUsefulDeltaTimeInSeconds(stTimer)\
	(MTH_M_xDiv(MTH_M_xLongToReal(stTimer.ulUsefulDeltaTime),\
				MTH_M_xLongToReal(1000)))

#define M_xGetFrameLength(stTimer) ((stTimer).xFrameLength)

#define C_CamModeNormal 0
#define C_CamModeLook	1

#endif
