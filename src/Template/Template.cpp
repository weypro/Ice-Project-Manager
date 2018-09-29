#include "stdafx.h"
#include "Template.h"
#include "MainDialog.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return SkinUI::WinMain(hInstance, lpCmdLine, nCmdShow);
}

CTemplate theApp;
CTemplate::CTemplate()
{

}

BOOL CTemplate::InitInstance()
{
	SkinUI::LoadConfig(_T("C:\\MySkin\\Template\\AppConfig.xml"));
	SkinUI::LoadSkin(_T("C:\\MySkin\\Template\\"));
	return TRUE;
}

void CTemplate::Run(const tstring& strCmdLine, int nCmdShow)
{
	CMainDialog dlg;
	SkinUI::SetMainWnd(&dlg);
	dlg.DoModal(NULL);
}

void CTemplate::ExitInstance()
{
	CSkinApplication::ExitInstance();
}