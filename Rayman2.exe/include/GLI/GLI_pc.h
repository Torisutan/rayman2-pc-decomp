#pragma once

#define GLI_tdhDriver				HMODULE
#define GLI_tdpfnDriverProc			FARPROC

#define GLI_pc_M_hLoadDriver(szDllPath)            LoadLibraryA(szDllPath)
#define GLI_pc_M_pfnGetDriverProc(hDriver, szName) GetProcAddress((hDriver), (szName))
