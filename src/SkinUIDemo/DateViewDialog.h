#pragma once

class CDateViewDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_DATEVIEW = 101,
		IDC_BUTTON = 102,
	};

public:
	CDateViewDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedGetDate(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinDateView*	m_pDateView;
};