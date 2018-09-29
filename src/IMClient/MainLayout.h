#pragma once
class CConversationLayout;
class CAddressBookLayout;
class CGroupLayout;
class CMainLayout : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_AVATAR = 20101,
		IDC_TABCTRL_MAIN = 20110,
		IDC_BUTTON_CONVERSATION = 20111,
		IDC_BUTTON_ADDRESS_BOOK = 20112,
		IDC_BUTTON_CREATE_GROUP = 20122,
		IDC_LAYOUT_CONVERSATION = 21000,
		IDC_LAYOUT_ADDRESS_BOOK = 22000,
		IDC_LAYOUT_CHAT = 30000,
		IDC_LAYOUT_DETAIL = 40000,
	};

public:
	CMainLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleBuildFinish();

protected:
	void OnBtnClickedUserInfo(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedCreateGroup(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CConversationLayout*		m_pLayoutConversation;
	CAddressBookLayout*			m_pLayoutAddressBook;
};