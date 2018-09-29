#pragma once

class CGridViewDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_GRIDVIEW1 = 101,
		IDC_GRIDVIEW2 = 102,
		IDC_BUTTON1 = 201,
		IDC_BUTTON2 = 202,
	};

public:
	CGridViewDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedAddItem1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedAddItem2(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinGridView*	m_pGridView1;
	CSkinGridView*	m_pGridView2;
};