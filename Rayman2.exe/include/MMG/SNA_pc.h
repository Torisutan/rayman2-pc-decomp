#ifndef __MMG_SNA_pc_h__
#define __MMG_SNA_pc_h__

typedef HANDLE SNA_pc_tdhFile;

#define SNA_pc_C_hInvalidFile           INVALID_HANDLE_VALUE
#define SNA_pc_C_ulAccessRead           GENERIC_READ
#define SNA_pc_C_ulAccessWrite          GENERIC_WRITE
#define SNA_pc_C_ulOpenExisting         OPEN_EXISTING
#define SNA_pc_C_ulCreateAlways         CREATE_ALWAYS
#define SNA_pc_C_ulAttributeNormal      FILE_ATTRIBUTE_NORMAL
#define SNA_pc_C_ulAttributeReadOnly    FILE_ATTRIBUTE_READONLY
#define SNA_pc_C_ulSeekBegin            FILE_BEGIN
#define SNA_pc_C_ulSeekCurrent          FILE_CURRENT
#define SNA_pc_C_ulSeekEnd              FILE_END

#define SNA_pc_M_hOpenFile(szPath, ulAccess, ulCreation, ulFlags) \
    CreateFileA((szPath), (ulAccess), 0, NULL, (ulCreation), (ulFlags), NULL)
#define SNA_pc_M_bReadFile(hFile, p_vBuffer, ulBytes, p_ulRead) \
    ReadFile((hFile), (p_vBuffer), (ulBytes), (p_ulRead), NULL)
#define SNA_pc_M_ulSeekFile(hFile, lDistance, ulOrigin) \
    SetFilePointer((hFile), (lDistance), NULL, (ulOrigin))
#define SNA_pc_M_bCloseFile(hFile) CloseHandle(hFile)
#define SNA_pc_M_ulGetFileAttributes(szPath) GetFileAttributesA(szPath)
#define SNA_pc_M_bSetFileAttributes(szPath, ulAttributes) SetFileAttributesA((szPath), (ulAttributes))

#endif
