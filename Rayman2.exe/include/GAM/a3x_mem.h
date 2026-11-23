#ifndef RAYMAN2_GAM_A3X_MEM_H
#define RAYMAN2_GAM_A3X_MEM_H

typedef struct	tdstStackInfos_ {
	unsigned long	ulPosAlloc;
	unsigned long	ulStackPos;
	unsigned long	ulMaxPos;
	unsigned long	ulResetPos;
}	tdstStackInfos;

enum
{	eStackA3dGENERAL,
	eStackVertexes,
	eStackQuaternions,
	eStackHierarchies,
	eStackNTTO,
	eStackOnlyFrames,
	eStackChannels,
	eStackFrames,
	eStackFramesKF,
	eStackKeyFrames,
	eStackEvents,
	eStackMorphData,

	eStackNbMax
};

#define	M_v_ResetOneStack( uwNumStack )												\
	tdstStacks[ (uwNumStack) ].ulPosAlloc=											\
		tdstStacks[ (uwNumStack) ].ulStackPos=										\
		tdstStacks[ (uwNumStack) ].ulResetPos

extern	tdstStackInfos				tdstStacks[];	/* 0x004A6B38 */

extern void fn_v_UnclearPreviousLoadedAnims( void );

extern void fn_v_ClearLoadedAnims(unsigned char ucClearAll);

#endif
