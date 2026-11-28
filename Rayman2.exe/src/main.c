#ifdef WIN32
#include <windows.h>
#endif
#if defined(LINUX)
#include "cpa_std.h"
#include <string.h>
#endif

extern int __stdcall GAM_pc_fn_WinMain(HINSTANCE hInstance,
                             HINSTANCE hPrevInstance,
                             char     *p_szCmdLine,
                             int       iShowCmd);

#if defined(LINUX)

int main(int argc, char *argv[])
{
    static char szCmdLine[260];
    int         i;

    szCmdLine[0] = '\0';
    for ( i = 1 ; i < argc ; i++ )
    {
        if ( strlen(szCmdLine) + strlen(argv[i]) + 2 > sizeof(szCmdLine) )
            break;
        if ( i > 1 )
            strcat(szCmdLine, " ");
        strcat(szCmdLine, argv[i]);
    }
    return GAM_pc_fn_WinMain(NULL, NULL, szCmdLine, 1);
}
#else
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nShowCmd)
{
    return GAM_pc_fn_WinMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}
#endif
