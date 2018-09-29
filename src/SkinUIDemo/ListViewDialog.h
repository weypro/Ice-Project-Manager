#pragma once

class CListViewDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_LISTVIEW1 = 101,
		IDC_LISTVIEW2 = 102,
		IDC_BUTTON1 = 201,
		IDC_BUTTON2 = 202,
	};

public:
	CListViewDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedAddItem1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedAddItem2(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinListView*	m_pListView1;
	CSkinListView*	m_pListView2;
};