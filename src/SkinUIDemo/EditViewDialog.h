#pragma once

class CEditViewDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_EDITVIEW = 100,
		IDC_BUTTON1 = 101,
		IDC_BUTTON2 = 102,
		IDC_BUTTON3 = 103,
		IDC_BUTTON4 = 104,
		IDC_BUTTON5 = 105,
		IDC_BUTTON6 = 106,
		ID_COMMAND_BEGIN = 1001,
		ID_COMMAND_END = 10000,
	};

public:
	CEditViewDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedAppendText(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedAppendHyperlink(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedAppendImage(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedInsertText(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedInsertHyperlink(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedInsertImage(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnHyperlinkClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinEditView*	m_pRichEditView;
	LONG			m_nCommandId;
};