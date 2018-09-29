#pragma once

class CMainLayout;
class CLoginLayout;
class CMainDialog : public CSkinDialog
{
public:
	CMainDialog();
	static CMainDialog* s_inst;

public:
	virtual void OnInitDialog();

public:
	void DoLogin();
	void HandleLoginSuccess();
	void BeginConversation(ConvId convId);

private:
	void CreateLoginLayout();
	void CreateMainLayout();

protected:
	void OnCommandOpenClient(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandQuitClient(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnCommandPersonalInfo(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandSystemConfig(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandModifyPassword(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandQuitLogin(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnTimer(UINT nIDEvent, BOOL& bHandle);
	void OnNcDestroy(BOOL& bHandle);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CLoginLayout*		m_pLoginLayout;
	CMainLayout*		m_pMainLayout;
};