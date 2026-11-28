#pragma once

#include <stdint.h>
#include <stdio.h>

#define FIL_pc_tdhFind                              HANDLE
#define FIL_pc_tdstFindData                         WIN32_FIND_DATAA
#define FIL_pc_C_hInvalidFind                       INVALID_HANDLE_VALUE
#define FIL_pc_M_hFindFirstFile(szPattern, p_stData) FindFirstFileA((szPattern), (p_stData))
#define FIL_pc_M_bFindNextFile(hFind, p_stData)     FindNextFileA((hFind), (p_stData))
#define FIL_pc_M_bFindClose(hFind)                  FindClose(hFind)
#define FIL_pc_M_bFindIsDirectory(p_stData)         (((p_stData)->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
#define FIL_pc_M_szFindName(p_stData)               ((p_stData)->cFileName)
#define FIL_pc_M_bCopyFile(szSrc, szDst, bFailIfExists) CopyFileA((szSrc), (szDst), (bFailIfExists))
#define FIL_pc_M_bDeleteFile(szPath)                DeleteFileA(szPath)
#define FIL_pc_M_bRemoveDirectory(szPath)           RemoveDirectoryA(szPath)
#define FIL_pc_M_ulGetCurrentDirectory(ulSize, szOut) GetCurrentDirectoryA((ulSize), (szOut))
#define FIL_pc_M_bSetCurrentDirectory(szPath)       SetCurrentDirectoryA(szPath)

typedef struct FIL_tdstFileHeader_ {
    unsigned long  ulWidth;
    unsigned long  ulHeight;
    unsigned long  ulImageSize;
    long           lChromakeyIndex;
    unsigned short uwNbColorInPalette;
    unsigned char  ucBpcInPalette;
    unsigned char  ucBpp;
    unsigned char  ucRLECode;
    unsigned char  ucRed;
    unsigned char  ucGreen;
    unsigned char  ucBlue;
    unsigned char  ucFormat;
    unsigned char  ucVersion;

} FIL_tdstFileHeader;

typedef struct FIL_tdstGF_ {
    FIL_tdstFileHeader  stFileHeader;
    unsigned char      *p_ucBitMap;
    unsigned char      *p_ucPalette;
} FIL_tdstGF;

#pragma pack(push, 1)
typedef struct FIL_tdstRealGFFileHeader_ {
    unsigned long  ulFormat;
    unsigned long  ulWidth;
    unsigned long  ulHeight;
    unsigned char  ucBpp;
    unsigned char  ucRLECode;
} FIL_tdstRealGFFileHeader;
#pragma pack(pop)

/* 0x00492bf0 */
unsigned long __cdecl FIL_fn_ulGetFileSize(char *szFileName);

/* 0x00492da0 */
void *__cdecl FIL_fn_hCreateConcatFileHandle(unsigned long ulNumberOfPath,
                                             unsigned long ulNumberOfFiles);

/* 0x00492df0 */
void __cdecl fn_vDestroyConcatFileHandle(void *hConcatFile);

/* 0x00492fc0 */
long __cdecl FIL_FUN_00492fc0(FILE *pFile,
                              const char *szSectionName,
                              const char *szExtension);

/* 0x004929c0 */
unsigned char __cdecl FIL_fn_bIsFileExist(char *_szFileName);

/* 0x00492f60 */
void __cdecl FIL_fn_vBuildConcatCompleteFileName(char *szCompleteFilename,
                                                  void *hConcatFile,
                                                  unsigned long ulIndex);

/* 0x004938d0 */
struct FIL_tdstFileInConcatFile_;
void __cdecl FIL_fn_vCloseFileInConcatFile(struct FIL_tdstFileInConcatFile_ **hHandleToFile);

/* 0x00493c20 */
void __cdecl FIL_fn_vInitGlobalHandleToFileInConcatFile(void);

/* 0x00493c80 */
void __cdecl FIL_fn_vFreeGlobalHandleToFileInConcatFile(void);

/* 0x004929f0 */
unsigned char __cdecl FIL_fn_bIsValidPath(char *_szFileName);

/* 0x00493820 */
void __cdecl FIL_vFillCacheFromFile(struct FIL_tdstFileInConcatFile_ *hHandleToFile);

/* 0x00492930 */
struct FIL_tdstFileNameListElement_;
void __cdecl FIL_fn_vDestroyOnElementInFileNameList(struct FIL_tdstFileNameListElement_ *hFileNameListElement);

/* 0x00493960 */
long __cdecl FIL_fn_lReadFileInConcatFile(void *p_vBuffer, long lSize, long lNumber,
                                          struct FIL_tdstFileInConcatFile_ *hHandleToFile);

/* 0x00492a10 */
unsigned char __cdecl FIL_fn_bValidatePath(char *_p_szStartPath, char *_p_szFileName);

/* 0x00492e80 */
unsigned char __cdecl FIL_fn_bSetConcatPathElement(void *hConcatFile,
                                                    unsigned long ulPathNumber,
                                                    char *p_szPathName);

/* 0x00492ef0 */
unsigned char __cdecl FIL_fn_bSetConcatFileElement(void *hConcatFile,
                                                    unsigned long ulFileNumber,
                                                    char *p_szFileName);

/* 0x00493590 */
void __cdecl FIL_fn_vCloseConcatFile(void **hConcatFile);

/* 0x004935c0 */
void *__cdecl FIL_fn_hOpenFileInConcatFile(
    void *hConcatFile, char *p_szPath, char *p_szFilename);

/* 0x00493300 */
void *__cdecl FIL_fn_vOpenConcatFile(char *p_szFilename);

/* 0x004928f0 */
unsigned char __cdecl FIL_fn_bDestroyFileOrDirectory(char *_szFileName);

/* 0x00492900 */
void *__cdecl FIL_fn_hSearchFile(char *_szFileName, unsigned long ulAttrib);

#define FIL_PATH_BUFFER_SIZE  0x104
#define FIL_PATH_BUFFER_COUNT 11
extern char FIL_g_aaszPathRegistry[FIL_PATH_BUFFER_COUNT][FIL_PATH_BUFFER_SIZE];
#define FIL_PATH_BUFFER(i) (FIL_g_aaszPathRegistry[i])

/* 0x004A68EC */
extern unsigned char FIL_g_ucFILModuleId;

void  __cdecl FIL_pc_fn_vSetSoundDir(char *param_1);   /* 0x00492650 */
char *__cdecl FIL_pc_fn_szGetSoundDir(void);           /* 0x00492680 */
void  __cdecl FIL_pc_fn_vSetDataDir(char *param_1);    /* 0x00492690 */
char *__cdecl FIL_pc_fn_szGetDataDir(void);            /* 0x004926c0 */

void  __cdecl FUN_004926d0(char *param_1);  char *__cdecl FUN_00492700(void);  /* 0x4face8 */
void  __cdecl FUN_00492710(char *param_1);                                     /* 0x4fadec */
void  __cdecl FUN_00492740(char *param_1);  char *__cdecl FUN_00492770(void);  /* 0x4faef0 */
void  __cdecl FUN_00492780(char *param_1);                                     /* 0x4faff4 */
void  __cdecl FUN_004927b0(char *param_1);                                     /* 0x4fb0f8 */
void  __cdecl FUN_004927e0(char *param_1);  char *__cdecl FUN_00492810(void);  /* 0x4fb300 */
void  __cdecl FUN_00492820(char *param_1);  char *__cdecl FUN_00492850(void);  /* 0x4fb404 */
char *__cdecl FUN_004928c0(void);                                              /* 0x4fb508 */
