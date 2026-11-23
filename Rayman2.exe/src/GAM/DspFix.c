#include "GAM/GAM_globals.h"
#include "GLI/ui_reset_redraw.h"

/* 0x005010E8 */
extern char GAM_pc_gs_aszUiSurfaceName[0x2E0];

/* 0x00419B50 */
void fn_vAskToDisplayVignette(char *szName)
{
    if (szName)
    {
        GAM_g_ucRefreshUi = 1;
        FUN_0045fc20((void *)GAM_pc_gs_aszUiSurfaceName, szName, 2);
    }
    else
    {
        GAM_g_ucRefreshUi = 0;
        FUN_0045fc70((void *)GAM_pc_gs_aszUiSurfaceName);
    }
}
