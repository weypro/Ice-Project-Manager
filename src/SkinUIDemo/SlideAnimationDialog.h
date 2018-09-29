#pragma once

class CSlideAnimationDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_BUTTON_TEST = 1000,
		IDC_LAYOUT_SLIDE_HOST = 2000,
		IDC_LAYOUT_SLIDE = 2001,
	};

public:
	CSlideAnimationDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);

protected:
	void OnBtnClickedTest(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};