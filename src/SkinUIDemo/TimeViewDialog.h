#pragma once

class CTimeViewDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_TIMEVIEW = 101,
		IDC_BUTTON = 102,
	};

public:
	CTimeViewDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedGetTime(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinTimeView*	m_pTimeView;
};