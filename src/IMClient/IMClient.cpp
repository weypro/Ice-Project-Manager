#include "stdafx.h"
#include "IMClient.h"
#include "MainDialog.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	return SkinUI::WinMain(hInstance, lpCmdLine, nCmdShow);
}

CIMClient theApp;
CIMClient::CIMClient()
{

}

BOOL CIMClient::InitInstance()
{
	SkinUI::LoadConfig(_T("C:\\MySkin\\IMClient\\AppConfig.xml"));
	SkinUI::LoadSkin(_T("C:\\MySkin\\IMClient\\"));
	return TRUE;
}

void CIMClient::Run(const tstring& strCmdLine, int nCmdShow)
{
	CMainDialog dlg;
	SkinUI::SetMainWnd(&dlg);
	dlg.DoModal(NULL);
}

void CIMClient::ExitInstance()
{
	CSkinApplication::ExitInstance();
}

tstring CIMClient::GetConversationName(ConvId convId)
{
	if(convId.nType == CONV_TYPE_USER)
	{
		STUser* pUser = CUserStore::GetInstance()->GetUserById(convId.nId);
		if(pUser)
		{
			return pUser->strName;
		}
	}
	else if(convId.nType == CONV_TYPE_GROUP)
	{
		STGroup* pGroup = CGroupStore::GetInstance()->GetGroupById(convId.nId);
		if(pGroup)
		{
			return pGroup->strName;
		}
	}

	assert(false);
	return SkinUI::IntToString(convId.nId);
}
