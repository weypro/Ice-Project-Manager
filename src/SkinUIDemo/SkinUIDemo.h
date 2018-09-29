#pragma once

class CSkinUIDemo : public CSkinApplication
{
public:
	CSkinUIDemo();

public:
	virtual BOOL InitInstance();
	virtual void Run(const tstring& strCmdLine, int nCmdShow);
	virtual void ExitInstance();
};

extern CSkinUIDemo theApp;
