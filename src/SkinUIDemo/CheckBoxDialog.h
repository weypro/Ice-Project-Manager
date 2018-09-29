#pragma once

class CCheckBoxDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_CHECKBOX1 = 101,
		IDC_CHECKBOX2 = 102,
	};

public:
	CCheckBoxDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnCheckBoxClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	LRESULT OnCheckBoxStateChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()
};