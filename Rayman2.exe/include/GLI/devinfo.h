#ifndef RAYMAN2_GLI_DEVINFO_H
#define RAYMAN2_GLI_DEVINFO_H

typedef enum tdeDriverCaps
{
	E_DRV_IsHardware = 1 << 0,
	E_DRV_CanUseAGP = 1 << 1,
	E_DRV_CanUseSystemMemory = 1 << 2,
	E_DRV_CanBeWindowed = 1 << 3,
	E_DRV_SupportAlphaTest = 1 << 4,
	E_DRV_ReadjustViewport = 1 << 5

}
tdeDriverCaps;

typedef enum tdeTextureCaps
{
	E_TEX_Support8P = 1 << 0,
	E_TEX_SupportNonSquare = 1 << 1,
	E_TEX_SupportMipMap = 1 << 2,
	E_TEX_SupportMirror = 1 << 3

}
tdeTextureCaps;

typedef struct tdstGliCaps
{
	unsigned long ulSize;
	tdeDriverCaps ulDriverCaps;
	tdeTextureCaps ulTextureCaps;
	unsigned long ulSurfaceCaps;
	unsigned long ulMemoryCaps;
	unsigned long ulTextureMaxSize;
	unsigned long ulTotalTextureMemory;
	unsigned long ulTotalVideoMemory;
	unsigned long ulTotalAGPMemory;
	unsigned char ucPrimarySurfacePixelFormat;
	float xRefreshRate;
}
tdstGliCaps;

#define GLI_pc_C_ulDrvCapsRefreshRateDefaulted  0x40
#define GLI_pc_C_ulDrvCapsReserveTextureMemory  0x80

extern tdstGliCaps GLI_pc_g_stGliCaps;   /* 0x00503680 */

#endif
