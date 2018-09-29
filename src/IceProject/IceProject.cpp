#include "stdafx.h"
#include "IceProject.h"
#include "MainDialog.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return SkinUI::WinMain(hInstance, lpCmdLine, nCmdShow);
}

CIceProject theApp;
CIceProject::CIceProject()
{

}

BOOL CIceProject::InitInstance()
{
	//SkinUI::LoadConfig(_T("C:\\MySkin\\IceProject\\AppConfig.xml"));
	//SkinUI::LoadSkin(_T("C:\\MySkin\\IceProject\\"));

	return TRUE;
}

void CIceProject::Run(const tstring& strCmdLine, int nCmdShow)
{
	SkinUI::ChangeSkin(_T("255,0,145,255"));
	CMainDialog dlg;
	SkinUI::SetMainWnd(&dlg);
	dlg.DoModal(NULL);
}

void CIceProject::ExitInstance()
{
	CSkinApplication::ExitInstance();
}