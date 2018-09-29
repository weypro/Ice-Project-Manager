#pragma once

class CChatLayout;
class CConversationListView;
class CConversationLayout : public CSkinSplitterLayout
{
public:
	enum
	{
		IDC_LISTVIEW = 21110,
		IDC_LAYOUT_PARENT = 21300,
		IDC_LAYOUT_TIPS = 21310,
	};

public:
	CConversationLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleBuildFinish();

protected:
	LRESULT OnListItemCheckedChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CConversationListView*		m_pListView;
	CSkinRelativeLayout*		m_pLayoutParent;
	CChatLayout*				m_pLayoutDetails;
	CSkinRelativeLayout*		m_pLayoutTips;
};