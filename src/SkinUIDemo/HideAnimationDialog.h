#pragma once

class CHideAnimationDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_BUTTON_TEST = 1000,
		IDC_HOST = 2000,
		IDC_HIDE_VIEW = 2020,
	};

public:
	CHideAnimationDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedTest(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};