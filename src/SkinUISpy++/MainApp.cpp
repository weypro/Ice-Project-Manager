#include "stdafx.h"
#include "MainApp.h"
#include "MainDialog.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return SkinUI::WinMain(hInstance, lpCmdLine, nCmdShow);
}

CApp theApp;
CApp::CApp()
{

}

BOOL CApp::InitInstance()
{
	return TRUE;
}

void CApp::Run(const tstring& strCmdLine, int nCmdShow)
{
	SkinUI::ChangeSkin(_T("255,128,187,11"));

	CMainDialog dlg;
	SkinUI::SetMainWnd(&dlg);
	dlg.DoModal(NULL);
}

void CApp::ExitInstance()
{
	CSkinApplication::ExitInstance();
}