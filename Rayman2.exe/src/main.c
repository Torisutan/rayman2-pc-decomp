#ifdef WIN32
#include <windows.h>
#endif

extern int __stdcall GAM_pc_fn_WinMain(HINSTANCE hInstance,
                             HINSTANCE hPrevInstance,
                             char     *p_szCmdLine,
                             int       iShowCmd);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nShowCmd)
{
    return GAM_pc_fn_WinMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}
