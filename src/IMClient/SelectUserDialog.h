#pragma once
class CCorpTreeView;
class CSelectedListView;
class CSelectUserDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_TREEVIEW = 11000,
		IDC_TEXTVIEW = 20001,
		IDC_LISTVIEW = 21000,
	};

public:
	CSelectUserDialog(const tstring& strCaption, uint32 nMaxCount);

public:
	virtual void OnInitDialog();

public:
	void GetSelected(list<uint64>& lstMember);

protected:
	void OnUpdateCommandOK(CSkinView* pView);

	LRESULT OnCheckBoxStateChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	void UpdateSelectedCount();

private:
	uint32					m_nMaxCount;
	tstring					m_strCaption;

	set<uint64>				m_setSelected;
	CCorpTreeView*			m_pTreeViewCorp;
	CSkinTextView*			m_pTextViewSelected;
	CSelectedListView*		m_pListViewSelected;
};