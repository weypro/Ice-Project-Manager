#include <stdafx.h>
#include "ChatLayout.h"
#include "ConversationLayout.h"
#include "ConversationView.h"

SKINUI_BEGIN_MESSAGE_MAP(CConversationLayout, CSkinSplitterLayout)
	ON_SKINUI_MESSAGE(WM_SKINUI_LIST_ITEM_CHECKED_CHANGE, OnListItemCheckedChange)
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CConversationLayout)
CConversationLayout::CConversationLayout(CSkinView* pParent)
: CSkinSplitterLayout(pParent)
, m_pListView(NULL)
, m_pLayoutTips(NULL)
, m_pLayoutDetails(NULL)
, m_pLayoutParent(NULL)
{

}

void CConversationLayout::HandleBuildFinish()
{
	CSkinSplitterLayout::HandleBuildFinish();

	m_pListView = static_cast<CConversationListView*>(GetChildById(IDC_LISTVIEW));
	if(m_pListView)
	{
		m_pListView->Load();
	}

	m_pLayoutParent = static_cast<CSkinRelativeLayout*>(GetChildById(IDC_LAYOUT_PARENT));
	m_pLayoutTips = static_cast<CSkinRelativeLayout*>(GetChildById(IDC_LAYOUT_TIPS));
}

LRESULT CConversationLayout::OnListItemCheckedChange(WPARAM wParam, LPARAM lParam)
{
	CRedrawLocker locker(this);
	CSkinListItem* pCheckedListItem = NULL;
	CSkinListView* pListView = reinterpret_cast<CSkinListView*>(lParam);
	if(pListView)
	{
		pCheckedListItem = pListView->GetChecked();
	}

	m_pLayoutDetails = NULL;
	if(pCheckedListItem && m_pLayoutParent)
	{
		tstring strClassName = pCheckedListItem->GetClassName();
		if(strClassName == _T("CConversationItem"))
		{
			CConversationItem* pItem = static_cast<CConversationItem*>(pCheckedListItem);
			if(pItem)
			{
				m_pLayoutDetails = CChatLayout::GetInstance(m_pLayoutParent, pItem->GetConvId());
			}
		}
		else
		{
			assert(false);
		}
	}

	CSkinRelativeLayout* pLayoutNeedShow = m_pLayoutDetails ? m_pLayoutDetails : m_pLayoutTips;
	const list<CSkinView*>& lstChild = m_pLayoutParent->GetAllChild();
	for(list<CSkinView*>::const_iterator iter = lstChild.begin(); iter != lstChild.end(); ++iter)
	{
		(*iter)->SetState((*iter == pLayoutNeedShow) ? VS_NORMAL : VS_HIDED);
	}
	return 1L;
}