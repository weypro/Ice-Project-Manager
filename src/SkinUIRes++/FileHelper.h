#pragma once
class CFileHelper
{
public:
	static BOOL IsFileExist(const tstring& strPath, BOOL* pDir = NULL, uint64* pFileSize = NULL);

	static BOOL IsDriverExist(const tstring& strPath);

	static BOOL IsDirectory(const tstring& strPath);

	static BOOL IsCDDriver(const tstring& strPath);

	static BOOL IsFileOccupied(const tstring& strPath);

	static BOOL DeleteFile(const tstring& strPath);

	static BOOL DeleteFolder(const tstring& strPath);

	static BOOL ForceDeleteFile(const tstring& strPath);

	static BOOL GetFileTime(const tstring& sFile, uint64& unCreateTime, uint64& unWriteTime);

	static BOOL CopyFile(const tstring& strSrcFile, const tstring& strDstFile, BOOL bForce = FALSE);

public:
	static uint64 GetFileSize(const tstring& strPath);

	static tstring GetFilePri(const tstring& strPath);

	static tstring GetFileExt(const tstring& strPath);

	static tstring GetFileName(const tstring& strPath, BOOL bIncludeExt = TRUE);

	static tstring GetFilePath(const tstring& strPath);

	static tstring GetFileNewPath(const tstring& strPath);

	static tstring GetCurModulePath();

public:
	static void GetChildFolder(const tstring& strPath, list<tstring>& lstFolder, BOOL bFullPath);

	static void GetChildFile(const tstring& strPath, list<tstring>& lstFile, BOOL bFullPath);

	static void GetAllChildFile(const tstring& strPath, list<tstring>& lstFile);
};