#pragma once
#include "Thread.h"

class CMainThread : public CThread
{
public:
	CMainThread(HWND hMainWnd);

public:
	virtual unsigned Run();

private:
	void NotifyProgress(LONG nPos, const tstring& strText);

	BOOL WriteFile(FILE* fp, const tstring& sFile, uint unFileSize);

private:
	HWND m_hMainWnd;
};