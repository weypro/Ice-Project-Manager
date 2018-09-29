#pragma once

class CButtonDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_BUTTON1 = 101,
		IDC_BUTTON2 = 102,
		IDC_BUTTON3 = 103,
		IDC_BUTTON4 = 104,
	};

public:
	CButtonDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnButtonClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};