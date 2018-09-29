#pragma once

class CHyperlinkDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_HYPERLINK1 = 101,
		IDC_HYPERLINK2 = 102,
	};

public:
	CHyperlinkDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnHyperlinkClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};