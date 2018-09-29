#include <stdafx.h>
#include "LoginLayout.h"
#include "MainDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CLoginLayout, CSkinRelativeLayout)
	ON_SKINUI_COMMAND(IDC_BUTTON_LOGIN, OnBtnClickedLogin)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONFIG_OK, OnBtnClickedConfigOK)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONFIG_CANCEL, OnBtnClickedConfigCancel)
	ON_SKINUI_COMMAND(IDC_HYPERLINK_SERVER_CONFIG, OnHyperlinkClickedServerConfig)
	ON_SKINUI_COMMAND(IDC_HYPERLINK_FORGET_PASSWORD, OnHyperlinkClickedForgetPassword)
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CLoginLayout)
CLoginLayout::CLoginLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
, m_pEditViewAccount(NULL)
, m_pEditViewPassword(NULL)
, m_pCheckBoxAutoLogin(NULL)
, m_pEditViewServerIp(NULL)
, m_pEditViewServerPort(NULL)
{

}

void CLoginLayout::HandleBuildFinish()
{
	CSkinRelativeLayout::HandleBuildFinish();

	m_pEditViewAccount = static_cast<CSkinEditView*>(GetChildById(IDC_EDITVIEW_ACCOUNT));
	m_pEditViewPassword = static_cast<CSkinEditView*>(GetChildById(IDC_EDITVIEW_PASSWORD));

	m_pEditViewServerIp = static_cast<CSkinEditView*>(GetChildById(IDC_EDITVIEW_SERVER_IP));
	m_pEditViewServerPort = static_cast<CSkinEditView*>(GetChildById(IDC_EDITVIEW_SERVER_PORT));

	m_pCheckBoxAutoLogin = static_cast<CSkinCheckBox*>(GetChildById(IDC_CHECKBOX_AUTO_LOGIN));

	GetOwner()->SetFocusView(m_pEditViewAccount);
}

void CLoginLayout::OnBtnClickedLogin(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSwitchAnimationHost* pSwitchAnimationHost = static_cast<CSwitchAnimationHost*>(GetChildById(IDC_LAYOUT_LOGIN_HOST));
	if(pSwitchAnimationHost)
	{
		pSwitchAnimationHost->ShowView(IDC_LAYOUT_LOGIN_ING);
	}

	//To Do
	//连接服务器登录
	tstring strAccount = m_pEditViewAccount->GetText();
	tstring strPassword = m_pEditViewPassword->GetText();
	CMainDialog::s_inst->DoLogin();
}

void CLoginLayout::OnBtnClickedConfigOK(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSwitchAnimationHost* pSwitchAnimationHost = static_cast<CSwitchAnimationHost*>(GetChildById(IDC_LAYOUT_MAIN_HOST));
	if(pSwitchAnimationHost)
	{
		pSwitchAnimationHost->ShowView(IDC_LAYOUT_LOGIN_HOST);
	}

	//To Do
	//保存配置信息
	tstring strIp = m_pEditViewServerIp->GetText();
	tstring strPort = m_pEditViewServerPort->GetText();
}

void CLoginLayout::OnBtnClickedConfigCancel(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSwitchAnimationHost* pSwitchAnimationHost = static_cast<CSwitchAnimationHost*>(GetChildById(IDC_LAYOUT_MAIN_HOST));
	if(pSwitchAnimationHost)
	{
		pSwitchAnimationHost->ShowView(IDC_LAYOUT_LOGIN_HOST);
	}

	//To Do
	//取消登录
}

void CLoginLayout::OnHyperlinkClickedServerConfig(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSwitchAnimationHost* pSwitchAnimationHost = static_cast<CSwitchAnimationHost*>(GetChildById(IDC_LAYOUT_MAIN_HOST));
	if(pSwitchAnimationHost)
	{
		pSwitchAnimationHost->ShowView(IDC_LAYOUT_SERVER_CONFIG);
	}
}

void CLoginLayout::OnHyperlinkClickedForgetPassword(UINT uNotifyCode, int nID, CSkinView* pView)
{
	//打开忘记密码的链接
	SkinUI::OpenURL(_T("www.baidu.com"));
}