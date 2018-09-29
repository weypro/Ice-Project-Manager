#include <stdafx.h>
#include "ConversationDetailLayout.h"
#include "AddressBookLayout.h"
#include "GroupView.h"
#include "AddressBookView.h"

SKINUI_BEGIN_MESSAGE_MAP(CAddressBookLayout, CSkinSplitterLayout)
	ON_SKINUI_MESSAGE(WM_SKINUI_LIST_ITEM_CHECKED_CHANGE, OnListItemCheckedChange)
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CAddressBookLayout)
CAddressBookLayout::CAddressBookLayout(CSkinView* pParent)
: CSkinSplitterLayout(pParent)
, m_pTreeView(NULL)
, m_pListView(NULL)
, m_pLayoutTips(NULL)
, m_pLayoutDetails(NULL)
, m_pLayoutParent(NULL)
{

}

void CAddressBookLayout::HandleBuildFinish()
{
	CSkinSplitterLayout::HandleBuildFinish();

	m_pTreeView = static_cast<CCorpTreeView*>(GetChildById(IDC_TREEVIEW));
	m_pListView = static_cast<CGroupListView*>(GetChildById(IDC_LISTVIEW));

	m_pLayoutParent = static_cast<CSkinRelativeLayout*>(GetChildById(IDC_LAYOUT_PARENT));
	m_pLayoutTips = static_cast<CSkinRelativeLayout*>(GetChildById(IDC_LAYOUT_TIPS));

	if(m_pTreeView)
	{
		m_pTreeView->Load(_T("UserItem.xml"), _T("DeptItem.xml"));
	}

	if(m_pListView)
	{
		m_pListView->Load();
	}
}

LRESULT CAddressBookLayout::OnListItemCheckedChange(WPARAM wParam, LPARAM lParam)
{
	CRedrawLocker locker(this);
	CSkinListItem* pCheckedListItem = NULL;
	CSkinListView* pListView = reinterpret_cast<CSkinListView*>(lParam);
	if(pListView)
	{
		pCheckedListItem = pListView->GetChecked();
	}

	if(m_pLayoutDetails)
	{
		m_pLayoutParent->DeleteChild(m_pLayoutDetails);
		m_pLayoutDetails = NULL;
	}

	if(pCheckedListItem && m_pLayoutParent)
	{
		tstring strClassName = pCheckedListItem->GetClassName();
		if(strClassName == _T("CUserItem"))
		{
			CUserItem* pItem = static_cast<CUserItem*>(pCheckedListItem);
			if(pItem)
			{
				m_pLayoutDetails = CConversationDetailLayout::GetInstance(m_pLayoutParent, ConvId(CONV_TYPE_USER, pItem->GetUserId()));
			}
		}
		else if(strClassName == _T("CDeptItem"))
		{
			CDeptItem* pItem = static_cast<CDeptItem*>(pCheckedListItem);
			if(pItem)
			{
				m_pLayoutDetails = CConversationDetailLayout::GetInstance(m_pLayoutParent, pItem->GetDeptId());
			}
		}
		else if(strClassName == _T("CGroupItem"))
		{
			CGroupItem* pItem = static_cast<CGroupItem*>(pCheckedListItem);
			if(pItem)
			{
				m_pLayoutDetails = CConversationDetailLayout::GetInstance(m_pLayoutParent, ConvId(CONV_TYPE_GROUP, pItem->GetGroupId()));
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