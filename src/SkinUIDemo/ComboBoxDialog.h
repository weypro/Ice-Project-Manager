#pragma once

class CComboBoxDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_CHECKBOX1 = 101,
		IDC_CHECKBOX2 = 102,
	};

public:
	CComboBoxDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	LRESULT OnComboBoxSelChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()
};