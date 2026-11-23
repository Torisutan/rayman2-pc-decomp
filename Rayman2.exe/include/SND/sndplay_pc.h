#ifndef SND_SNDPLAY_PC_H
#define SND_SNDPLAY_PC_H

typedef struct {
        long            voice_sxd;
        tduRefRes       res;
        SndBool_field_decl(bFree);
        SndBool_field_decl(bAssociation_running);
		SndBool_field_decl(bTransition);
        SndBool			bValid;
        SndBool*        pbValid;
		long			lPauseInstance;
} voice_description;

#endif
