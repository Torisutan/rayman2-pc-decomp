#pragma once

struct GLD_tdstViewportAttributes_
{
    unsigned long dwInitialHeight;
    unsigned long dwInitialWidth;
    unsigned long dwHeight;
    unsigned long dwWidth;
    unsigned long dwTopInPix;
    unsigned long dwBottomInPix;
    unsigned long dwLeftInPix;
    unsigned long dwRightInPix;
    unsigned long dwTopInPixForClip;
    unsigned long dwBottomInPixForClip;
    unsigned long dwLeftInPixForClip;
    unsigned long dwRightInPixForClip;
    unsigned long dwWidthInPercent;
    unsigned long dwHeightInPercent;
    unsigned long dwClipTopInPix;
    unsigned long dwClipBottomInPix;
    unsigned long dwClipLeftInPix;
    unsigned long dwClipRightInPix;
    unsigned long dwClipTopInPerMille;
    unsigned long dwClipBottomInPerMille;
    unsigned long dwClipLeftInPerMille;
    unsigned long dwClipRightInPerMille;
    int           iOffsetPosX;
    int           iOffsetPosY;
    char         *p_cVirtualScreen;
    long          lPitch;
    void         *p_vSpecificToXD;
    short         hDevice;
    short         hViewport;
};
