#pragma once

#include "GAM/STRUCTUR/State.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SEB_Invalid              0xFFFF
#define SEB_xMaskQuatOri         0x0001
#define SEB_xMaskQuatSca         0x0002
#define SEB_xMaskScaleValues     0x0004
#define SEB_xMaskPosition        0x0008
#define SEB_xMaskIdQuatOri       0x0010
#define SEB_xMaskIdQuatSca       0x0020
#define SEB_xMaskIdScaleValues   0x0040
#define SEB_xMaskLastKey         0x0080
#define SEB_xMaskZeroAngCentre   0x0100
#define SEB_xTypeWrapLastKey     0x0200

typedef struct tdstA3dGENERAL_
{
    unsigned char  _r00[0x0c];
    unsigned short uwNumberOfChannels;
    unsigned short uwNumberOfFrames;
    unsigned char  _r10[0x18 - 0x10];
    unsigned short uwStartFrame;
    unsigned char  _r1a[0x24 - 0x1a];
    unsigned short uwNumberOfMorphData;
    unsigned char  _r26[0x2e - 0x26];
    unsigned short uwNumOfFirstOnlyFrame;
    unsigned short uwNumOfFirstChannel;
    unsigned char  _r32[0x34 - 0x32];
    unsigned short uwNumOfFirstMorphData;
    unsigned char  _r36[0x38 - 0x36];
} tdstA3dGENERAL;

typedef struct tdstOnlyFrame_
{
    unsigned short uwNumOfAngularSpeedQuat;
    unsigned short uwNumOfSpeedVector;
    unsigned short uwHierarchyNbCouples;
    unsigned short uwNumOfFirstHierarchyCouple;
    unsigned short uwNumOfSavedFrame;
} tdstOnlyFrame;

typedef struct tdstA3dChannel_
{
    unsigned short uwNumberOfKeys;
    unsigned short uwChannelNumber;
    unsigned short uwNumOfLocalPivotPos;
    unsigned short uwNumOfFirstFrame;
    unsigned long  ulNumOfFirstFrameKF;
    unsigned short uwNumOfFirstKeyFrame;
    unsigned char  _r0e[0x10 - 0x0e];
} tdstA3dChannel;

/* 0x00419BD0 */
typedef struct tdstKeyFrame_
{
    float          a3_xWorldPivotPosition[3];
    float          xDistMaster;
    unsigned short uwFrameNumber;
    unsigned short uwMask;
    unsigned short uwNumOfQuatOri;
    unsigned short uwNumOfQuatSca;
    unsigned short uwNumOfScaleValues;
    unsigned short uwNumOfPosition;
    unsigned short uwAngQuatOri;
    unsigned short uwAngQuatSca;
    unsigned short uwAngObjCentre;
    short          swInterpolationParameter;
} tdstKeyFrame;

typedef struct tdstA3dFrame_
{
    unsigned short uwNumOfNTTO;
} tdstA3dFrame;

typedef struct tdstNTTO_
{
    unsigned short uwTypeOfObject;
    unsigned short ucNumberInTable;
    unsigned char  ucTransparency;
    unsigned char  _r05;
} tdstNTTO;

extern tdstA3dGENERAL  *p_stA3dGeneral;
extern tdstA3dChannel  *p_stChannels;
extern tdstA3dFrame    *p_stFrames;
extern tdstCouple      *p_stHierarchies;
extern tdstOnlyFrame   *p_stOnlyFrames;
extern MTH3D_tdstVector *p_stSpeedVectors;
extern tdstNTTO        *p_stNTTO;

extern short *p_stAngularSpeedQuats;

extern int *p_stFramesKF;
extern tdstKeyFrame *p_stKeyFrames;

extern void *GAM_g_pAnimStack500288;
extern void *GAM_g_pAnimStack500298;

/* 0x004A6B38 */
struct HIE_tdstSuperObject;
struct tdstFrame3d_;
struct tdstAnim3d_;

/* 0x0041A400 */
void __cdecl fn_vUpdateFrame(struct HIE_tdstSuperObject *_p_stSuperObject, struct tdstFrame3d_ *_p_stFrame,
                             struct tdstAnim3d_ *_p_stAnim3d, unsigned short _uwFrame);

struct tdstAChannel_;
/* 0x0041A610 */
void __cdecl fn_vUpdateFrameMatrix(struct HIE_tdstSuperObject *_p_stSuperObject, struct tdstFrame3d_ *_p_stFrame,
                                   struct tdstAnim3d_ *_p_stAnim3d, unsigned short _uwFrame,
                                   unsigned char ucForceUpdate, struct tdstAChannel_ *d_stChannelArray);

#ifdef __cplusplus
}
#endif
