#include "stdafx.h"
#include "SkinUIDemo.h"
#include "MainDialog.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return SkinUI::WinMain(hInstance, lpCmdLine, nCmdShow);
}

CSkinUIDemo theApp;
CSkinUIDemo::CSkinUIDemo()
{

}

BOOL CSkinUIDemo::InitInstance()
{
	SkinUI::LoadConfig(_T("C:\\MySkin\\SkinUIDemo\\AppConfig.xml"));
	SkinUI::LoadSkin(_T("C:\\MySkin\\SkinUIDemo\\"));
	return TRUE;
}

void CSkinUIDemo::Run(const tstring& strCmdLine, int nCmdShow)
{
	CMainDialog dlg;
	SkinUI::SetMainWnd(&dlg);
	dlg.DoModal(NULL);
}

void CSkinUIDemo::ExitInstance()
{
	CSkinApplication::ExitInstance();
}

tstring GetCurModulePath()
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