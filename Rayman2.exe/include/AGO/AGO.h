#ifndef AGO_H
#define AGO_H

#include "MTH/MTH3D.h"

typedef struct GLD_tdstViewportAttributes_ GLD_tdstViewportAttributes;

/* 0x004E0F20 */
typedef struct AGO_Gauge_
{
    MTH_tdxReal Coords[4];
    void       *EmptyMaterial;
    void       *FullMaterial;
    MTH_tdxReal Position;
    long        Transparency;
} AGO_Gauge;

/* 0x004E54A0 */
typedef struct AGO_Icone_
{
    MTH_tdxReal Coords[4];
    void       *Material;
    long        Transparency;
} AGO_Icone;

#define MAX_GAUGES 8
#define MAX_ICONES 35

/* 0x004E5800 */
typedef struct AGO_Part_
{
    unsigned long    ulType;
    long             AnimTime;
    MTH_tdxReal      fCreationTime;
    MTH3D_tdstVector vInitialPosition;
    MTH3D_tdstVector vPosition;
    MTH3D_tdstVector vDirection;
    MTH_tdxReal      fScale[2];
    MTH_tdxReal      fAnimTimeScale;
    MTH_tdxReal      fTimeLimit;
    void            *VisualMaterial;
    MTH_tdxReal      Transparency;
} AGO_Part;

typedef struct AGO_Triangles_
{
    float         c[3][3];
    float         uv[3][2];
    void         *VisualMaterial;
    unsigned long DelayTime;
    unsigned long type;
    float         fTransparency;
    unsigned long CreationTime;
} AGO_Triangles;

#define AGO_MAX_TRIANGLES 200
#define AGO_TRI_FADE      0x00000002

#define AGO_MAX_NUMBER_OF_AGOS   150
#define MAX_NUMBER_OF_ZELDA_AGOS 35
#define AGO_STILL                0x00000000
#define AGO_REMANANCE3           0x60000000
#define AGO_TYPEMASK             0x000000FF
#define AGO_ROTATING_SLOW        0x00000006
#define AGO_MOVINGSINXY          0x00000007
#define AGO_SPIRALE              0x00000008
#define AGO_MOVINGSINXYUP        0x0000000B
#define AGO_2DSPIRALE            0x0000000C
#define AGO_GOTO                 0x00000012
#define AGO_TIMELIMITED          0x00010000
#define AGO_ENDASPLOUF           0x00020000
#define AGO_ZLIMITED             0x00040000
#define AGO_SHADEMASK            0x0000F000
#define AGO_APPEAR               0x00007000
#define AGO_ZELDA                0x00080000
#define AGO_MUSTDIE              0x01000000
#define AGO_RAYMAN_PLOUF         0x10003300

void        AGO_vDisplayGAUGES(GLD_tdstViewportAttributes *p_stVpt);
void        AGO_vDisplayIcones(GLD_tdstViewportAttributes *p_stVpt);
MTH_tdxReal AGO_fGetTimeInSeconds(void);
AGO_Part   *AGO_vCreatePart(unsigned long parm_ulType, MTH3D_tdstVector *pPosition,
                            MTH3D_tdstVector *pDirection, MTH_tdxReal TimeLimit,
                            MTH_tdxReal fScaleX, MTH_tdxReal fScaleY,
                            void *pVisualMaterial);
void        AGO_Define_OrthogonalVectors(MTH3D_tdstVector *p_stDirection,
                            MTH3D_tdstVector *p_stV1, MTH3D_tdstVector *p_stV2);
void        AGO_pc_vRemoveMustDieParts(void);
void        AGO_vProcessAllParts(GLD_tdstViewportAttributes *p_stVpt);
void        AGO_vVectorMulAddInternal(MTH_tdxReal *pfdest, MTH_tdxReal *pfsrc, MTH_tdxReal mul);
void        AGO_vProcessPart(unsigned long ulPartNumber, GLD_tdstViewportAttributes *p_stVpt);
void        AGO_vDisplayPart(unsigned long ulPartNumber, GLD_tdstViewportAttributes *p_stVpt);
void        AGO_vAddParticle(unsigned long PartType, MTH3D_tdstVector *pPos,
                            MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        AGO_vAddParticleContd(unsigned long PartType, MTH3D_tdstVector *pPos,
                            MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType5AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir,
                            void *hVisualMaterial, float parameter);
void        CreateType8AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir,
                            void *hVisualMaterial, float parameter);
void        CreateType16AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType52AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType60AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType62AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType35AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType15AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType21AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType65AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType28AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        CreateType67AGO(MTH3D_tdstVector *pPos, MTH3D_tdstVector *pDir, void *hVisualMaterial, float parameter);
void        AGO_vTransformHandVector(MTH3D_tdstVector *Position, MTH3D_tdstVector *Direction);
void        AGO_vTrianglesInit(void);
void        AGO_vCreateTriangle(float c1[3], float c2[3], float c3[3], void *VisualMat,
                            float U1, float V1, float U2, float V2, float U3, float V3,
                            float DelayTime, unsigned long Parameter);
void        AGO_vDisplayTriangles(GLD_tdstViewportAttributes *p_stVpt);
void        AGO_vDisplayLogo(GLD_tdstViewportAttributes *p_stVpt);

#endif
