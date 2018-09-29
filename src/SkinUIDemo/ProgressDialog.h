#pragma once

class CProgressDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_PROGRESS1 = 101,
		IDC_BUTTON1 = 201,
		IDC_PROGRESS2 = 102,
		IDC_BUTTON2 = 202,
	};

public:
	CProgressDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedAddPosByStep4(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedAddPosByStep10(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinProgress*	m_pProgress1;
	CSkinProgress*	m_pProgress2;
};