#ifndef BLC_ROM64_H
#define BLC_ROM64_H

#ifndef D_BINSCR_Packing
#define D_BINSCR_Packing
#endif

#pragma pack(push, u64align, 1)

typedef unsigned short U64_tdxIndex;
typedef float          U64_tdxUVValue;
typedef float          U64_tdxColorValue;

typedef struct U64_tdstColor_
{   U64_tdxColorValue   xColor[4];
}   U64_tdstColor;

typedef struct U64_stVector2D_
{   float   a2_fCoord[2];
}   U64_tdstVector2D;

typedef struct U64_stVector3D_
{   float   a3_fCoord[3];
}   U64_tdstVector3D;

typedef struct U64_stShortVector3D_
{   short   a3_wCoord[3];
}   U64_tdstShortVector3D;

typedef struct U64_stShortVector2D_
{   short   a2_wCoord[2];
}   U64_tdstShortVector2D;

typedef struct U64_stDoubledIndex_
{   U64_tdxIndex    a2_xIndex[2];
}   U64_tdstDoubledIndex;

typedef struct U64_stTripledIndex_
{   U64_tdxIndex    a3_xIndex[3];
}   U64_tdstTripledIndex;

typedef struct U64_stDoubledRef_
{   unsigned short  a2_uwRef[2];
}   U64_tdstDoubledRef;

typedef struct U64_stTripledRef_
{   unsigned short  a3_uwRef[3];
}   U64_tdstTripledRef;

typedef struct stStructMainTable_
{   unsigned long ulDataOffset;
    unsigned long ulDataLength;
}   tdstStructMainTable;

typedef struct stStructTable_
{   unsigned long ulDataOffset;
}   tdstStructTable;

typedef struct U64_stBinInfo_
{   float           fCoordScale;
    unsigned short  uwStructNb;
    unsigned short  uwVersion;
    unsigned short  uwNbLevels;
    unsigned short  uwVertexSegment;
}   U64_tdstBinInfo;

typedef struct U64_stFix_
{
    U64_tdxIndex    xLevelsNameListId;
    U64_tdxIndex    xDscIptId;
    U64_tdxIndex    xIptLinkId;
    U64_tdxIndex    xVector3DId;
    U64_tdxIndex    xTripledIndexId;
    U64_tdxIndex    xMemoryId;
    U64_tdxIndex    xShadowTextureId;

    U64_tdxIndex    xLightTextureId;

    U64_tdxIndex    xVisualMatControllerId;
    U64_tdxIndex    xNoCtrlListId;

    unsigned short  uwVector3DNb;
    unsigned short  uwTripledIndexNb;
    unsigned short  uwLevelsNb;

    U64_tdxIndex    xGlobalVector3DId;
    U64_tdxIndex    xGlobalTripledIndexId;
    unsigned short  uwGlobalVector3DNb;
    unsigned short  uwGlobalTripledIndexNb;

    U64_tdxIndex    xCpakFontID;

#ifdef USE_LEVELSAVE
    unsigned short  uwPlayerGameSaveLength;
#endif
}   U64_tdstFix;

typedef struct U64_stSmallEntryRef_
{
    unsigned short  xId;
    unsigned short  uwAdrHigh;
    unsigned short  uwAdrLowAndType;
}   U64_tdstCompEntryRef;

typedef struct U64_stEntryRef_
{
    unsigned long   ulAddress;
    unsigned short  uwType;
    U64_tdxIndex    xId;
}   U64_tdstEntryRef;

typedef struct U64_stSemiEntryRefAddress_
{
    unsigned long   ulAddress;
}   U64_stSemiEntryRefAddress;

typedef struct U64_stSemiEntryRefTypeAndId_
{
    unsigned short  uwType;
    U64_tdxIndex    xId;
}   U64_stSemiEntryRefTypeAndId;

#pragma pack(pop, u64align)

#define D_BINSCR_InvalidId       0xFFFF
#define D_BINSCR_InvalidType     0xFFFF
#define D_BINSCR_InvalidRef      0xFFFFFFFF
#define D_BINSCR_IsInFixRef      0xFFFFFFFE
#define D_BINSCR_VertexSegment   6
#define D_BINSCR_IsInFixFixFat   ((unsigned short)(1 << 15))
#define D_BINSCR_Compression     (1 << 30)
#define D_BINSCR_VersionBase     0x3A00

enum
{
    E_StructFixData,
    E_StructCharacter,
    E_StructComport,
    E_StructAIModel,
    E_StructFamily,
    E_StructState,
    E_StructObjectsTable,
    E_StructInputAction,

    E_StructAnimInfo,
    E_StructCharacter3dData,
    E_StructArrayOfZoneSet,
    E_StructActivationZone,
    E_StructWaypoint,
    E_StructWayGraph,
    E_StructWayGraphNode,
#ifndef D_THROW_PRT
    E_StructCharacterParticleSrc,
    E_StructPrtSrc,
    E_StructPrtSys,
    E_StructPrtEnv,
    E_StructPrtGen,
#endif
    E_StructArrayOfZdx,
    E_StructLight,
    E_StructTexture,
    E_StructBitmapCI4,
    E_StructBitmapCI8,
    E_StructBitmapRGBA16,
    E_StructPaletteRGBA16,
    E_StructU64VtxList,

#ifdef COMPRESS_GFXLIST
    E_StructCmpDsGfxList,
#else
    E_StructU64GfxList,
#endif

    E_StructElementU64IndexedTriangles,
#ifndef D_THROW_COMPLEX_SPRITE
    E_StructSprite,
#endif
    E_StructElementSprites,
    E_StructElementSpheres,
    E_StructElementAlignedBoxes,
    E_StructElementPoints,
    E_StructElementCones,
    E_StructAltimap,
    E_StructGeometricObject,
    E_StructGameMaterial,
    E_StructCollideMaterial,
    E_StructVisualMaterial,
#ifndef D_THROW_IPO
    E_StructInstanciatedPhysicalObject,
#endif
    E_StructIdCardBase,
    E_StructIdCardCamera,
    E_StructMechanicalMaterial,
    E_StructZoo,
    E_StructPhysicalObject,
    E_StructSector,
    E_StructSuperObject,
    E_StructColFacesPnt,
#ifndef D_THROW_VISUAL_SET
    E_StructVisualSet,
#endif

    E_StructLevelsNameList,
    E_StructLevel,
    E_StructSubLevel,
    E_StructSubLevelList,
    E_StructLevelEntry,
    E_StructLevelEntryList,
    E_StructSuperObjectChildList,
    E_StructVertex,
    E_StructEdge,
    E_StructAnimListTable,
    E_StructLstGraphic,
    E_StructLstActivity,
    E_StructLstCollision,
    E_StructLstStaticLights,
    E_StructLstSound,
    E_StructLstSoundParam,
    E_StructLstSoundEvent,
    E_StructLstSoundEventParam,
#ifndef D_THROW_COMPLEX_SPRITE
    E_StructElementSpritesList,
    E_StructSpriteInstance,
#endif
    E_StructMechanicalEnvironment,
    E_StructVisualEnvironment,
    E_StructBitmapInfo,
    E_StructDeclaration,
    E_StructStateList,
    E_StructCharacterBrain,
    E_StructCharacterCineInfo,
    E_StructCharacterCollSet,
    E_StructCharacterLight,
    E_StructCharacterMicro,
    E_StructCharacterStandardGame,
    E_StructCharacterStream,
    E_StructCharacterWorld,
    E_StructCharacterSnd,
    E_StructObjectsTableLst,
    E_StructDeclarationVariable,
    E_StructIntelligence,
    E_StructListOfComport,
    E_StructListOfRules,
    E_StructRule,
    E_StructReflex,
    E_StructNode,
    E_StructLstGeometricObject,
    E_StructLstAlignedBoxes,
    E_StructLstSpheres,
    E_StructLstCones,
    E_StructLstPoints,
    E_StructLstZoneSet,
    E_StructLstZdxIndex,
    E_StructWay,
    E_StructLstNodeIndex,
    E_StructLstCapacity,
    E_StructLstValuation,
    E_StructLstWaypointIndex,
    E_StructWayLst,
    E_StructLstWayLstIndex,
    E_StructLstGraphicParam,
    E_StructSndEventLst,
    E_StructNodeLongList,
    E_StructNodeFloatList,
    E_StructNodeVector3DList,
    E_StructNodeStringList,
    E_StructDecLongList,
    E_StructDecUnsignedLongList,
    E_StructDecFloatList,
    E_StructDecVector3DList,
    E_StructStateRef,
    E_StructStateRefList,
    E_StructBoundingVolume,
    E_StructLipsSynchro,
    E_StructInitialization,
    E_StructInitVariable,
    E_StructInitVariableIdList,
    E_StructTypeVariable,
    E_StructTypeVariableIdList,
    E_StructDscIpt,
    E_StructDscIptActionLst,
    E_StructIptLink,
    E_StructIptLinkList,
    E_StructIptList,
    E_StructItemStringList,
    E_StructWayLink,
    E_StructWayLinkVector,
    E_StructLstWayLinkIndex,
    E_StructAnimVector3D,
    E_StructAnimTripledIndex,
    E_StructAllVector3D,
    E_StructAllTripledIndex,
    E_StructArrayOfStrings,
    E_StructStringLst,
    E_StructSndEventIdList,
    E_StructNbOfLanguages,
    E_StructTextString,
    E_StructLanguageString,
    E_StructTextStringLst,
    E_StructStringLength,
    E_StructStringLengthLst,
    E_StructLanguageStringLst,
    E_StructOldVtxIndex,
    E_StructAnimSpeedList,
    E_StructDscMiscInfo,
    E_StructDscLvl,
    E_StructMem,
    E_StructLevelDescription,
    E_StructFixPreloadSection,
    E_StructFixMem,
    E_StructLevelMem,
    E_StructElementU64List,
    E_StructElementColIndexedTriangles,
    E_StructElementColList,
    E_StructAltimapSquare,
    E_StructAltimapFace,
    E_StructAltimapUV,
    E_StructAltimapVertex,
    E_StructCharacterDyn,
    E_StructTextureList,
    E_StructStringChunk,
    E_StructArrayEntry,
    E_StructBkGrdCI8,
    E_StructBkGrdPalletteList,
    E_StructBkGrdInfo,
    E_StructNODFile,
    E_StructVigNb,
#ifndef D_THROW_IPO
    E_StructISI,
#endif
#ifndef D_THROW_VISUAL_SET
    E_StructLodLst,
#endif

    E_StructCPakFont,

    E_DontSaveStructStart,

    E_StructLstIsiIndex = E_DontSaveStructStart,
#ifdef D_THROW_IPO
    E_StructISI,
#endif
    E_StructElementList,
    E_StructElementIndexedTriangles,
    E_StructNormal,
    E_StructFacesPnt,
    E_StructFacesUV,
    E_StructUV,
    E_StructFacesNormals,
    E_StructGfxList,
    E_StructVtxList,
    E_StructChannelName,
    E_StructChannelNameString,
    E_StructRliLst,
    E_StructElementTmpIndexedTriangles,
    E_StructDsgVarRefBidouille,
    E_StructAIDefines,
    E_StructGeometricObjectTemp,
#ifdef D_THROW_VISUAL_SET
    E_StructVisualSet,
    E_StructLodLst,
#endif
#ifdef D_THROW_COMPLEX_SPRITE
    E_StructSprite,
    E_StructElementSpritesList,
    E_StructSpriteInstance,
#endif
#ifdef D_THROW_IPO
    E_StructInstanciatedPhysicalObject,
#endif
    E_StructLstStaticLightsTmp,
    E_StructAnimList,
    E_StructCharacterWay,
    E_StructLevelBankList,
    E_StructLevelBankListElement,
    E_StructIndirectGeoObjLst,

#ifdef COMPRESS_GFXLIST
    E_StructU64GfxList,
#endif

    E_StructNb
};

#define D_BINSCR_StructFixData          E_StructFixData
#define D_BINSCR_DontSaveStructStart    E_DontSaveStructStart
#define D_BINSCR_StructNb               E_StructNb

#endif
