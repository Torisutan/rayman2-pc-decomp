#pragma once

#define GLI_C_lMaxTimeForLensFlare    8
#define GLI_C_MaxLensFlare            10

/* 0x005036C0 */
typedef struct stLensFlareTab_ tdstLensFlareTab ;
struct stLensFlareTab_ {
  void *p_vReference[GLI_C_MaxLensFlare] ;
  long lApparitionTrame[GLI_C_MaxLensFlare] ;
  long lCounter[GLI_C_MaxLensFlare] ;
  char bIntersect[GLI_C_MaxLensFlare] ;
  long lNumberOfLensFlare ;
} ;

extern tdstLensFlareTab GLI_pc_g_stLensFlareTab;   /* 0x005036C0 */

void __cdecl GLI_vSetLensFlareRef ( void *p_vRef ) ;      /* 0x00428DD0 */
char __cdecl GLI_cRegisterLensFlare (void *p_vRef) ;      /* 0x00428DE0 */
void __cdecl GLI_vUnregisterLensFlare(void *p_vRef) ;     /* 0x00428E60 */
long __cdecl GLI_lLensFlareExist(void *p_vRef) ;          /* 0x00428ED0 */
void __cdecl GLI_vInitLensFlare (void) ;                  /* 0x00428F00 */
