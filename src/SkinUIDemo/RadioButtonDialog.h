#pragma once

class CRadioButtonDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_RADIOBUTTON1 = 101,
		IDC_RADIOBUTTON2 = 102,
	};

public:
	CRadioButtonDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnRadioButtonClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	LRESULT OnRadioGroupCheckedChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()
};