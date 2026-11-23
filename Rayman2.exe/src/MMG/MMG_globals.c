#define D_MMG_VariableDefine
#include "MMG/MMG_globals.h"

/* 0x0050acc0 */
struct tdstBlockInfoPriv *g_a_p_stMmgModuleBlocksInfo[255];

/* 0x0050b0e0 */
unsigned char g_a_ucBlocksNbInModule[255];

/* 0x0050b1e0 */
tdstGeneralChannelInfo g_stMmgGeneralChannelInfo_storage;
tdstGeneralChannelInfo *const g_p_stMmgGeneralChannelInfo = &g_stMmgGeneralChannelInfo_storage;

/* 0x00501530 */
tdstBlockInfo MMG_g_stGmtPalBlockInfo;

/* 0x004A11C4 */
unsigned char MMG_g_ucErmChannelId = 0xFF;

unsigned int *g_ulMMGTable_storage = 0;
