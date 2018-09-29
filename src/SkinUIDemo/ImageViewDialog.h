#pragma once

class CImageViewDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_IMAGEVIEW = 101,
	};

public:
	CImageViewDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnImageViewClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};