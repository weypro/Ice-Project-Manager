#pragma once

class CIceProject : public CSkinApplication
{
public:
	CIceProject();

public:
	virtual BOOL InitInstance();
	//virtual ResType GetResType() { return RT_RC_PACKAGE; }
	virtual void Run(const tstring& strCmdLine, int nCmdShow);
	virtual void ExitInstance();
};

extern CIceProject theApp;