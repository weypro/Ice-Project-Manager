#pragma once

class CLoginLayout : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_LAYOUT_MAIN_HOST = 10000,

		IDC_LAYOUT_LOGIN_HOST = 11000,
		IDC_LAYOUT_SERVER_CONFIG = 12000,

		IDC_LAYOUT_LOGIN_BEGIN = 11100,
		IDC_LAYOUT_LOGIN_ING = 11200,

		IDC_EDITVIEW_ACCOUNT = 11103,
		IDC_EDITVIEW_PASSWORD = 11104,

		IDC_BUTTON_LOGIN = 11105,
		IDC_CHECKBOX_AUTO_LOGIN = 11106,

		IDC_HYPERLINK_SERVER_CONFIG = 11107,
		IDC_HYPERLINK_FORGET_PASSWORD = 11108,

		IDC_EDITVIEW_SERVER_IP = 12001,
		IDC_EDITVIEW_SERVER_PORT = 12002,

		IDC_BUTTON_CONFIG_OK = 12003,
		IDC_BUTTON_CONFIG_CANCEL = 12004,
	};

public:
	CLoginLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleBuildFinish();

protected:
	void OnBtnClickedLogin(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedConfigOK(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedConfigCancel(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnHyperlinkClickedServerConfig(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnHyperlinkClickedForgetPassword(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinEditView*		m_pEditViewAccount;
	CSkinEditView*		m_pEditViewPassword;
	CSkinCheckBox*		m_pCheckBoxAutoLogin;

	CSkinEditView*		m_pEditViewServerIp;
	CSkinEditView*		m_pEditViewServerPort;
};