#include "stdafx.h"
#include "MainThread.h"
#include "MainDialog.h"
#include "FileHelper.h"

CMainThread::CMainThread(HWND hMainWnd, const tstring& strProject)
: m_hMainWnd(hMainWnd)
, m_strProject(strProject)
, m_nPos(0)
{

}

unsigned CMainThread::Run()
{
	LONG nRange = 0;

	//×ÊÔ´
	list<tstring> lstResFile;
	CFileHelper::GetAllChildFile(CFileHelper::GetCurModulePath() + _T("res\\Template\\"), lstResFile);
	nRange += lstResFile.size();

	//Æ¤·ô
	list<tstring> lstSkinFile;
	CFileHelper::GetAllChildFile(CFileHelper::GetCurModulePath() + _T("skin\\Template\\"), lstSkinFile);
	nRange += lstSkinFile.size();

	//´úÂë
	list<tstring> lstCodeFile;
	tstring strPath = CFileHelper::GetCurModulePath();
	SkinUI::StringTrimRight(strPath, '\\');
	strPath = CFileHelper::GetFilePath(strPath);
	strPath = CFileHelper::GetFilePath(strPath);
	strPath += _T("\\src\\Template\\");
	CFileHelper::GetAllChildFile(strPath, lstCodeFile);
	nRange += lstCodeFile.size();
	nRange += lstCodeFile.size();
	PostMessage(m_hMainWnd, WM_SETUP_NOTIFY, NOTIFY_RANGE, nRange);

	//¿½±´×ÊÔ´
	CopyFolder(lstResFile);

	//¿½±´Æ¤·ô
	CopyFolder(lstSkinFile);

	//¿½±´´úÂë
	CopyFolder(lstCodeFile);

	//Ìæ»»´úÂë
	tstring strCodePath = strPath;
	SkinUI::StringTrimRight(strCodePath, '\\');
	strCodePath = CFileHelper::GetFilePath(strCodePath);
	strCodePath += _T("\\");
	strCodePath += m_strProject;
	strCodePath += _T("\\");
	lstCodeFile.clear();
	CFileHelper::GetAllChildFile(strCodePath, lstCodeFile);
	ReplaceFolder(lstCodeFile);

	delete this;
	return 1L;
}

void CMainThread::NotifyProgress(LONG nPos, const tstring& strText)
{
	CXMLNode root;
	root.SetName(_T("NotifyProgress"));
	root.AddChildNode(_T("Pos"), SkinUI::IntToString(nPos));
	root.AddChildNode(_T("Text"), strText);

	tstring* pStrXML = new tstring();
	SkinUI::NodeToString(root, *pStrXML);
	PostMessage(m_hMainWnd, WM_SETUP_NOTIFY, NOTIFY_PROGRESS, (LPARAM)pStrXML);
}

void CMainThread::CopyFolder(const list<tstring>& lstFile)
{
	for(list<tstring>::const_iterator iter = lstFile.begin(); iter != lstFile.end(); ++iter)
	{
		tstring strNewFile;
		tstring strFilePath = *iter;
		list<tstring> lstFileName;
		while(TRUE)
		{
			tstring strFileName = CFileHelper::GetFileName(strFilePath);
			strFilePath = CFileHelper::GetFilePath(strFilePath);
			if(strFileName != _T("Template"))
			{
				lstFileName.push_back(strFileName);
			}
			else
			{
				strNewFile += strFilePath;
				strNewFile += _T("\\");
				strNewFile += m_strProject;
				for(list<tstring>::reverse_iterator iter = lstFileName.rbegin(); iter != lstFileName.rend(); ++iter)
				{
					strNewFile += _T("\\");
					strNewFile += *iter;
				}
				break;
			}
		}
		CopyFile(*iter, strNewFile);
	}
}

void CMainThread::CopyFile(const tstring& strOldFile, const tstring& strNewFile)
{
	tstring strFolderPath = CFileHelper::GetFilePath(strNewFile);
	CFileHelper::MakeSureFolderExist(strFolderPath);

	tstring strNewFilePath;
	tstring strFileName = CFileHelper::GetFileName(strNewFile);
	if(strFileName == _T("Template.h") || strFileName == _T("Template.cpp") || strFileName == _T("Template.rc") || 
		strFileName == _T("Template.ico") || strFileName == _T("Template.vcxproj"))
	{
		strNewFilePath = CFileHelper::GetFilePath(strNewFile) + _T("\\") + m_strProject + _T(".") + CFileHelper::GetFileExt(strNewFile);
	}
	else if(strFileName == _T("Template.vcxproj.filters"))
	{
		strNewFilePath = CFileHelper::GetFilePath(strNewFile) + _T("\\") + m_strProject + _T(".") + _T("vcxproj.filters");
	}
	else
	{
		strNewFilePath = strNewFile;
	}
	CFileHelper::CopyFile(strOldFile, strNewFilePath, TRUE);

	strFileName = CFileHelper::GetFileName(strNewFilePath);
	tstring strFormat = SkinUI::GetString(_T("IDS_COPY_FILE_FORMAT"));
	tstring strText = SkinUI::StringFormat(strFormat.c_str(), strFileName.c_str());
	NotifyProgress(++m_nPos, strText);
}

void CMainThread::ReplaceFolder(const list<tstring>& lstFile)
{
	string sProject = SkinUI::UnicodeToUTF8(m_strProject);
	for(list<tstring>::const_iterator iter = lstFile.begin(); iter != lstFile.end(); ++iter)
	{
		ReplaceString(*iter, "Template", sProject);
	}
}

static string LoadStringFormFile(FILE* fp, uint32 unSize, uint32 unOffset)
{
	if(fp == NULL)
	{
		assert(false);
		return string();
	}

	char* pBuf = new char[unSize + 1];
	if(pBuf == NULL)
	{
		assert(false);
		return string();
	}

	auto_ptr<char> spBuf(pBuf);
	fseek(fp, unOffset, SEEK_SET);
	uint32 n = fread(pBuf, 1, unSize, fp);
	if(n != unSize)
	{
		assert(false);
		return string();
	}

	pBuf[unSize] = '\0';
	string str(pBuf);
	return str;
}

void CMainThread::ReplaceString(const tstring& strFilePath, const string& strOldString, const string& strNewString)
{
	if(CFileHelper::GetFileExt(strFilePath) != _T("ico"))
	{
		FILE* rfp = NULL;
		_tfopen_s(&rfp, strFilePath.c_str(), _T("rb"));
		string str = LoadStringFormFile(rfp, (uint32)CFileHelper::GetFileSize(strFilePath), 0);
		fclose(rfp);

		FILE* wfp = NULL;
		_tfopen_s(&wfp, strFilePath.c_str(), _T("wb+"));
		while(TRUE)
		{
			size_t pos = str.find(strOldString);
			if(pos == tstring::npos)
				break;

			str.replace(pos, strOldString.size(), strNewString);
		}
		fwrite(str.c_str(), 1, str.size(), wfp);
		fclose(wfp);
	}

	tstring strFileName = CFileHelper::GetFileName(strFilePath);
	tstring strFormat = SkinUI::GetString(_T("IDS_REPLACE_FILE_FORMAT"));
	tstring strText = SkinUI::StringFormat(strFormat.c_str(), strFileName.c_str());
	NotifyProgress(++m_nPos, strText);
}