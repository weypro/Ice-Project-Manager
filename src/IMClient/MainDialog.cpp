#include "stdafx.h"
#include "MainDialog.h"
#include "LoginLayout.h"
#include "MainLayout.h"
#include "ConversationView.h"
#include "ConversationLayout.h"
#include "UserInfoDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_COMMAND(ID_MENU_OPEN_CLIENT, OnCommandOpenClient)
	ON_SKINUI_COMMAND(ID_MENU_QUIT_CLIENT, OnCommandQuitClient)
	ON_SKINUI_COMMAND(ID_MENU_PERSONAL_INFO, OnCommandPersonalInfo)
	ON_SKINUI_COMMAND(ID_MENU_SYSTEM_CONFIG, OnCommandSystemConfig)
	ON_SKINUI_COMMAND(ID_MENU_MODIFY_PASSWORD, OnCommandModifyPassword)
	ON_SKINUI_COMMAND(ID_MENU_QUIT_LOGIN, OnCommandQuitLogin)
	ON_SKINUI_WM_NCDESTROY()
	ON_SKINUI_WM_TIMER()
SKINUI_END_MESSAGE_MAP()

CMainDialog* CMainDialog::s_inst = NULL;
CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
{
	s_inst = this;
}

void CMainDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	CreateLoginLayout();
}

void CMainDialog::CreateLoginLayout()
{
	m_pLoginLayout = new CLoginLayout(this);
	if(m_pLoginLayout)
	{
		m_pLoginLayout->SetLayout(_T("LoginLayout.xml"));
		m_pLoginLayout->SetLayoutWidth(FILL_PARENT);
		m_pLoginLayout->SetLayoutHeight(FILL_PARENT);
	}
}

void CMainDialog::CreateMainLayout()
{
	m_pMainLayout = new CMainLayout(this);
	if(m_pMainLayout)
	{
		m_pMainLayout->SetLayout(_T("MainLayout.xml"));
		m_pMainLayout->SetBkgImage(_T("MainBkg.png"));
		m_pMainLayout->SetLayoutWidth(FILL_PARENT);
		m_pMainLayout->SetLayoutHeight(FILL_PARENT);
	}
}

void CMainDialog::BeginConversation(ConvId convId)
{
	SkinUI::SetForegroundWindow(this);
	CConvListStore::GetInstance()->BeginConv(convId);
	CConversationListView* pListViewConversation = static_cast<CConversationListView*>(GetChildById(CConversationLayout::IDC_LISTVIEW));
	if(pListViewConversation)
	{
		CRedrawLocker locker(this);
		if(!pListViewConversation->IsVisible())
		{
			CSkinRadioGroup* pRadioGroup = static_cast<CSkinRadioGroup*>(GetChildById(CMainLayout::IDC_TABCTRL_MAIN));
			if(pRadioGroup)
			{
				CSkinRadioButton* pRadioButton = static_cast<CSkinRadioButton*>(pRadioGroup->GetChildById(CMainLayout::IDC_BUTTON_CONVERSATION));
				if(pRadioButton)
				{
					pRadioGroup->SetChecked(pRadioButton);
				}
			}
		}

		CConversationItem* pConversationItem = pListViewConversation->FindConversationItem(convId);
		if(!pConversationItem)
		{
			pListViewConversation->AddConversationItem(convId);
			pListViewConversation->ResetScrollInfo();
		}

		pConversationItem = pListViewConversation->FindConversationItem(convId);
		if(pConversationItem)
		{
			pListViewConversation->SetChecked(pConversationItem);
		}
	}
}

void CMainDialog::DoLogin()
{
	SetTimer(TIMER_LOGIN, 1000);
}

void CMainDialog::HandleLoginSuccess()
{
	CRedrawLocker locker(this);

	if(m_pLoginLayout)
	{
		DeleteChild(m_pLoginLayout);
		m_pLoginLayout = NULL;
	}

	CreateMainLayout();
	SetRect(GetRect());
}

void CMainDialog::OnCommandOpenClient(UINT uNotifyCode, int nID, CSkinView* pView)
{
	SkinUI::SetForegroundWindow(this);
}

void CMainDialog::OnCommandQuitClient(UINT uNotifyCode, int nID, CSkinView* pView)
{
	PostMessage(WM_COMMAND, IDCANCEL);
}

void CMainDialog::OnCommandPersonalInfo(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CUserInfoDialog::Show(GetOwner()->GetHWND(), theApp.GetUserId());
}

void CMainDialog::OnCommandSystemConfig(UINT uNotifyCode, int nID, CSkinView* pView)
{

}

void CMainDialog::OnCommandModifyPassword(UINT uNotifyCode, int nID, CSkinView* pView)
{

}

void CMainDialog::OnCommandQuitLogin(UINT uNotifyCode, int nID, CSkinView* pView)
{

}

void CMainDialog::OnTimer(UINT_PTR nIDEvent, BOOL& bHandle)
{
	if(nIDEvent == TIMER_LOGIN)
	{
		KillTimer(nIDEvent);
		HandleLoginSuccess();
	}
}

void CMainDialog::OnNcDestroy(BOOL& bHandle)
{
	bHandle = FALSE;
	PostQuitMessage(0);
}