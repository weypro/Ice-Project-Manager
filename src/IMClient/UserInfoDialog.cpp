#include "stdafx.h"
#include "UserInfoDialog.h"
#include "UserInfoLayout.h"

map<uint64, CUserInfoDialog*> CUserInfoDialog::s_mapInst;
CUserInfoDialog::CUserInfoDialog(uint64 nUserId)
: CSkinDialog(_T("UserInfoDialog.xml"))
, m_nUserId(nUserId)
{
	s_mapInst[nUserId] = this;
}

CUserInfoDialog::~CUserInfoDialog()
{
	map<uint64, CUserInfoDialog*>::iterator iter = s_mapInst.find(m_nUserId);
	if(iter != s_mapInst.end())
	{
		s_mapInst.erase(iter);
	}
}

void CUserInfoDialog::Show(HWND hParentWnd, uint64 nUserId)
{
	CUserInfoDialog* pDialog = NULL;
	map<uint64, CUserInfoDialog*>::iterator iter = s_mapInst.find(nUserId);
	if(iter != s_mapInst.end())
	{
		pDialog = iter->second;
	}
	if(!pDialog)
	{
		pDialog = new CUserInfoDialog(nUserId);
		if(pDialog)
		{
			if(!pDialog->Create(hParentWnd))
			{
				delete pDialog;
				pDialog = NULL;
			}
			else
			{
				pDialog->ShowWindow(SW_SHOW);
			}
		}
	}
	else
	{
		SkinUI::SetForegroundWindow(pDialog);
	}
}

void CUserInfoDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	CUserInfoLayout* pInfoLayout = static_cast<CUserInfoLayout*>(GetChildById(IDC_LAYOUT_INFO));
	if(pInfoLayout)
	{
		pInfoLayout->Init(ConvId(CONV_TYPE_USER, m_nUserId));
		pInfoLayout->Load();
	}
}