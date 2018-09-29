#pragma once
#include "Thread.h"

class CMainThread : public CThread
{
public:
	CMainThread(HWND hMainWnd, const tstring& strProject);

public:
	virtual unsigned Run();

private:
	void CopyFolder(const list<tstring>& lstFile);

	void CopyFile(const tstring& strOldFile, const tstring& strNewFile);

	void ReplaceFolder(const list<tstring>& lstFile);

	void ReplaceString(const tstring& strFilePath, const string& strOldString, const string& strNewString);

	void NotifyProgress(LONG nPos, const tstring& strText);

private:
	HWND		m_hMainWnd;
	tstring		m_strProject;
	LONG		m_nPos;
};