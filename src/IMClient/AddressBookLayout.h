#pragma once

class CGroupListView;
class CCorpTreeView;
class CAddressBookLayout : public CSkinSplitterLayout
{
public:
	enum
	{
		IDC_TREEVIEW = 22120,
		IDC_LISTVIEW = 22130,
		IDC_LAYOUT_PARENT = 22300,
		IDC_LAYOUT_TIPS = 22310,
	};

public:
	CAddressBookLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleBuildFinish();

protected:
	LRESULT OnListItemCheckedChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CCorpTreeView*				m_pTreeView;
	CGroupListView*				m_pListView;

	CSkinRelativeLayout*		m_pLayoutParent;
	CSkinRelativeLayout*		m_pLayoutDetails;
	CSkinRelativeLayout*		m_pLayoutTips;
};