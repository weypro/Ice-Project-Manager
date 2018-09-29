#include "Stdafx.h"
#include "FileHelper.h"

BOOL CFileHelper::IsFileExist(const tstring& strPath, BOOL* pDir, uint64* pFileSize)
{
	tstring sFile = strPath;
	SkinUI::StringTrim(sFile, _T('\\'));
	if(sFile.size() == 2 && IsDriverExist(sFile))
	{
		if(pDir != NULL)
		{
			*pDir = TRUE;
		}

		if(pFileSize != NULL)
		{
			*pFileSize = 0;
		}
		return TRUE;
	}

	WIN32_FIND_DATA data;
	HANDLE hFind = ::FindFirstFile(sFile.c_str(), &data);
	if(hFind == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	bool bDir = (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
	if(pDir != NULL)
	{
		*pDir = bDir;
	}

	if(pFileSize != NULL)
	{
		if(bDir)
		{
			*pFileSize = 0;
		}
		else
		{
			*pFileSize = (((uint64)data.nFileSizeHigh) << 32) + data.nFileSizeLow;
		}
	}
	::FindClose(hFind);
	return TRUE;
}

BOOL CFileHelper::IsDriverExist(const tstring& strDriver)
{
	if(strDriver.size() == 2 && tolower(strDriver[0]) >= 'a' && tolower(strDriver[0]) <= 'z' && strDriver[1] == _T(':'))
	{
		uint unDriverNum = tolower(strDriver[0]) - 'a';
		DWORD dwDriverMask = ::GetLogicalDrives();
		if((dwDriverMask >> unDriverNum) & 1)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

BOOL CFileHelper::IsDirectory(const tstring& strPath)
{
	BOOL bDirectory = FALSE;
	if(CFileHelper::IsFileExist(strPath, &bDirectory))
	{
		if(bDirectory)
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CFileHelper::IsCDDriver(const tstring& strPath)
{
	return ::GetDriveType(strPath.c_str()) == DRIVE_CDROM;
}

BOOL CFileHelper::IsFileOccupied(const tstring& strPath)
{
	HANDLE hFile = ::CreateFile(strPath.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		// 被占用或者文件不存在
		return TRUE;
	}
	else
	{
		::CloseHandle(hFile);
		return FALSE;
	}
}

BOOL CFileHelper::DeleteFile(const tstring& strPath)
{
	return ::DeleteFile(strPath.c_str()) != FALSE;
}

BOOL CFileHelper::DeleteFolder(const tstring& strPath)
{
	WIN32_FIND_DATA wfd;
	TCHAR szFile[MAX_PATH];
	TCHAR szDelDir[MAX_PATH];
	lstrcpy(szDelDir, strPath.c_str());
	wsprintf(szFile, _T("%s\\*.*"), strPath.c_str());

	HANDLE hFindFile = FindFirstFile(szFile, &wfd);
	if(hFindFile != INVALID_HANDLE_VALUE)
	{
		BOOL bFind = TRUE;
		while(bFind)
		{
			bFind = FindNextFile(hFindFile, &wfd);
			if(lstrcmpi(wfd.cFileName, _T(".")) == 0 || lstrcmpi(wfd.cFileName, _T("..")) == 0)
				continue;

			wsprintf(szFile, _T("%s\\%s"), szDelDir, wfd.cFileName);
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				DeleteFolder(szFile);
			}
			else
			{
				DeleteFile(szFile);
			}
		}
		::FindClose(hFindFile);
	}

	return ::RemoveDirectory(szDelDir);
}

BOOL CFileHelper::ForceDeleteFile(const tstring& strPath)
{
	if(CFileHelper::IsFileExist(strPath))
	{
		if(!::DeleteFile(strPath.c_str()))
		{
			tstring strTemp = strPath;
			strTemp += _T(".tmp");
			MoveFile(strPath.c_str(), strTemp.c_str());
		}
	}
	return !CFileHelper::IsFileExist(strPath);
}

BOOL CFileHelper::GetFileTime(const tstring& sFile, uint64& unCreateTime, uint64& unWriteTime)
{
	WIN32_FIND_DATA data;

	HANDLE hFind = ::FindFirstFile(sFile.c_str(), &data);
	if (hFind == INVALID_HANDLE_VALUE)
		return FALSE;

	unCreateTime = (((uint64)data.ftCreationTime.dwHighDateTime) << 32) + data.ftCreationTime.dwLowDateTime;
	unWriteTime = (((uint64)data.ftLastWriteTime.dwHighDateTime) << 32) + data.ftLastWriteTime.dwLowDateTime;

	::FindClose(hFind);
	return TRUE;
}

BOOL CFileHelper::CopyFile(const tstring& strSrcFile, const tstring& strDstFile, BOOL bForce)
{
	return ::CopyFile(strSrcFile.c_str(), strDstFile.c_str(), !bForce);
}

uint64 CFileHelper::GetFileSize(const tstring& strPath)
{
	HANDLE hFile = ::CreateFile(strPath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	LARGE_INTEGER li;
	BOOL bRet = ::GetFileSizeEx(hFile, &li);
	if(!bRet)
	{
		::CloseHandle(hFile);
		return 0;
	}

	::CloseHandle(hFile);
	return li.QuadPart;
}

tstring CFileHelper::GetFileName(const tstring& strPath, BOOL bIncludeExt)
{
	uint unPos1 = strPath.find_last_of('\\');
	uint unPos2 = strPath.find_last_of('/');

	if(unPos1 == strPath.npos && unPos2 == strPath.npos)
	{
		return strPath;
	}

	uint unPos = 0;

	if(unPos1 != strPath.npos)
	{
		unPos = unPos1;
	}

	if(unPos2 != strPath.npos && unPos2 > unPos)
	{
		unPos = unPos2;
	}

	tstring strName = strPath.substr(unPos + 1);
	if(!bIncludeExt)
	{
		uint unPos = strName.find_last_of('.');
		strName = strName.substr(0, unPos);
	}
	return strName;
}

tstring CFileHelper::GetFilePath(const tstring& strPath)
{
	uint unPos1 = strPath.find_last_of('\\');
	uint unPos2 = strPath.find_last_of('/');

	if(unPos1 == strPath.npos && unPos2 == strPath.npos)
	{
		return tstring();
	}

	uint unPos = 0;
	if(unPos1 != strPath.npos)
	{
		unPos = unPos1;
	}

	if(unPos2 != strPath.npos && unPos2 > unPos)
	{
		unPos = unPos2;
	}

	return strPath.substr(0, unPos);
}

tstring CFileHelper::GetFilePri(const tstring& strPath)
{
	tstring sFileName = GetFileName(strPath);
	uint unPos = sFileName.find_last_of('.');
	if(unPos == sFileName.npos)
	{
		return sFileName;
	}
	else
	{
		return sFileName.substr(0, unPos);
	}
}

tstring CFileHelper::GetFileExt(const tstring& strPath)
{
	uint unPos = strPath.find_last_of('.');

	if(unPos == strPath.npos)
	{
		return tstring();
	}

	return strPath.substr(unPos + 1);
}

tstring CFileHelper::GetFileNewPath(const tstring& strPath)
{
	UINT nIndex = 0;
	tstring strNewPath = strPath;
	while(IsFileExist(strNewPath))
	{
		++nIndex;
		tstring strFilePath = GetFilePath(strPath);
		tstring strFileName = GetFileName(strPath, FALSE);
		tstring strFileExt = GetFileExt(strPath);
		strNewPath = SkinUI::StringFormat(_T("%s\\%s(%d).%s"), strFilePath.c_str(), strFileName.c_str(), nIndex, strFileExt.c_str());
	}
	return strNewPath;
}

void CFileHelper::GetChildFolder(const tstring& strPath, list<tstring>& lstFolder, BOOL bFullPath)
{
	WIN32_FIND_DATA fd;
	::SetCurrentDirectory(strPath.c_str());
	HANDLE hFind = ::FindFirstFile(_T("*.*"), &fd);
	if(hFind != INVALID_HANDLE_VALUE)
	{
		while(::FindNextFile(hFind, &fd))
		{
			if(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				tstring strFolderName = fd.cFileName;
				if(strFolderName != _T(".") && strFolderName != _T(".."))
				{
					lstFolder.push_back(bFullPath ? strPath + strFolderName + _T("\\") : strFolderName);
				}
			}
		}
	}
	::FindClose(hFind);
}

void CFileHelper::GetChildFile(const tstring& strPath, list<tstring>& lstFile, BOOL bFullPath)
{
	WIN32_FIND_DATA fd;
	::SetCurrentDirectory(strPath.c_str());
	HANDLE hFind = ::FindFirstFile(_T("*.*"), &fd);
	if(hFind != INVALID_HANDLE_VALUE )
	{
		while(::FindNextFile(hFind, &fd))
		{
			if(!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				lstFile.push_back(bFullPath ? strPath + fd.cFileName : fd.cFileName);
			}
		}
	}
	::FindClose(hFind);
}

void CFileHelper::GetAllChildFile(const tstring& strPath, list<tstring>& lstFile)
{
	list<tstring> lstFolder;
	CFileHelper::GetChildFile(strPath, lstFile, TRUE);
	CFileHelper::GetChildFolder(strPath, lstFolder, TRUE);
	for(list<tstring>::iterator iter = lstFolder.begin(); iter != lstFolder.end(); ++iter)
	{
		CFileHelper::GetAllChildFile(*iter, lstFile);
	}
}

tstring CFileHelper::GetCurModulePath()
{
	TCHAR szFilePath[MAX_PATH + 1] = {0};
	int dwlen = GetModuleFileName(NULL, szFilePath, _MAX_PATH);

	if(dwlen != 0){
		while(true)
		{
			if(szFilePath[dwlen--] == _T('\\'))
				break;
		}
		szFilePath [dwlen+2] = 0;
	}

	return tstring(szFilePath);
}