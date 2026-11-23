#pragma once

typedef unsigned char ACP_tdxBool;
typedef signed short  ACP_tdxIndex;

#define TRUE  1
#define FALSE 0

typedef ACP_tdxIndex ACP_tdxHandleOfElement;

struct GEO_tdstGeometricObject_;
struct GLI_tdstMaterial_;
struct GEO_tdstSprite_;
struct GEO_tdstFaceMapDescriptor_;

typedef struct GEO_tdstGeometricObject_   *ACP_tdxHandleOfObject;
typedef struct GLI_tdstMaterial_          *ACP_tdxHandleOfMaterial;
typedef struct GEO_tdstSprite_            *ACP_tdxHandleOfSprite;
typedef struct GEO_tdstFaceMapDescriptor_ *ACP_tdxHandleOfFMD;
