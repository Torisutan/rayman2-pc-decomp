#ifndef GAM_PC_SESSION_H
#define GAM_PC_SESSION_H

/* 0x005116EC */
extern unsigned char GAM_pc_g_ucGameEndCondition;
/* 0x005116F2 */
extern unsigned char SNA_pc_g_a_ucLoadKey[4];
#define GAM_pc_g_ucAlwaysSpawnCounter (SNA_pc_g_a_ucLoadKey[2])

#endif
