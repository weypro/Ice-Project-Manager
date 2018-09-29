#pragma once

class CTemplate : public CSkinApplication
{
public:
	CTemplate();

public:
	virtual BOOL InitInstance();
	virtual void Run(const tstring& strCmdLine, int nCmdShow);
	virtual void ExitInstance();
};

extern CTemplate theApp;