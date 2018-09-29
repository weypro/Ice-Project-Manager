#include <stdafx.h>
#include "AddressBookView.h"

SKINUI_IMPLEMENT_DYNCREATE(CDeptItem)
CDeptItem::CDeptItem(CSkinView* pParent)
: CSkinTreeItem(pParent)
, m_nDeptId(0)
{
	SetLazyLoad(TRUE);
}

void CDeptItem::Init(uint32 nDeptId, const tstring& strLayout)
{
	m_nDeptId = nDeptId;

	SetLayout(strLayout);
	SetLayoutHeight(ITEM_HEIGHT_40);
	SetImage(_T("ListItem.png"));
}

void CDeptItem::HandleBuildFinish()
{
	CSkinView* pExpandButton = GetChildById(IDC_TREEITEM_EXPAND);
	if(pExpandButton)
	{
		pExpandButton->SetLayoutAlignParentLeft(5 + 25 * GetLevel());
	}

	STDept* pDept = CDeptStore::GetInstance()->GetDeptById(m_nDeptId);
	if(pDept)
	{
		CSkinView* pView = GetChildById(IDC_NAME);
		if(pView)
		{
			pView->SetText(pDept->strName);
		}
	}
}

SKINUI_IMPLEMENT_DYNCREATE(CUserItem)
CUserItem::CUserItem(CSkinView* pParent)
: CSkinListItem(pParent)
, m_nUserId(0)
{
	SetLazyLoad(TRUE);
}

void CUserItem::Init(uint64 nUserId, const tstring& strLayout)
{
	m_nUserId = nUserId;

	SetLayout(strLayout);
	SetLayoutHeight(ITEM_HEIGHT_40);
	SetImage(_T("ListItem.png"));
}

void CUserItem::HandleBuildFinish()
{
	LONG nLevel = GetLevel();
	if(nLevel != -1)
	{
		CSkinView* pView = GetChildById(IDC_AVATAR);
		if(pView)
		{
			pView->SetLayoutAlignParentLeft(26 + 25 * (nLevel - 1));
		}
	}

	CConversationNameView* pConversationNameView = static_cast<CConversationNameView*>(GetChildById(IDC_NAME));
	if(pConversationNameView)
	{
		pConversationNameView->Init(ConvId(CONV_TYPE_USER, m_nUserId));
	}

	CAvatarView* pAvatarView = static_cast<CAvatarView*>(GetChildById(IDC_AVATAR));
	if(pAvatarView)
	{
		pAvatarView->Init(ConvId(CONV_TYPE_USER, m_nUserId));
	}
}

SKINUI_IMPLEMENT_DYNCREATE(CCorpTreeView)
CCorpTreeView::CCorpTreeView(CSkinView* pParent)
: CSkinCheckTreeView(pParent)
{

}

void CCorpTreeView::Load(const tstring& strLayoutUserItem, const tstring& strLayoutDeptItem)
{
	m_strLayoutUserItem = strLayoutUserItem;
	m_strLayoutDeptItem = strLayoutDeptItem;

	CDeptItem* pDeptItem = AddDeptItem(NULL, 0);
	if(pDeptItem)
	{
		ExpandItem(pDeptItem, TRUE);
	}
}

CDeptItem* CCorpTreeView::AddDeptItem(CDeptItem* pParentDeptItem, uint32 nDeptId)
{
	CDeptItem* pDeptItem = new CDeptItem(this);
	if(pDeptItem)
	{
		InsertItem(pParentDeptItem, pDeptItem);
		pDeptItem->Init(nDeptId, m_strLayoutDeptItem);

		list<uint32> lstChildDept;
		CDeptStore::GetInstance()->GetChildDept(nDeptId, lstChildDept);
		for(list<uint32>::const_iterator iter = lstChildDept.begin(); iter != lstChildDept.end(); ++iter)
		{
			AddDeptItem(pDeptItem, *iter);
		}

		list<uint64> lstChildUser;
		CUserStore::GetInstance()->GetChildUser(nDeptId, lstChildUser);
		for(list<uint64>::const_iterator iter = lstChildUser.begin(); iter != lstChildUser.end(); ++iter)
		{
			AddUserItem(pDeptItem, *iter);
		}
	}
	return pDeptItem;
}

CUserItem* CCorpTreeView::AddUserItem(CDeptItem* pDeptItem, uint64 nUserId)
{
	CUserItem* pUserItem = new CUserItem(this);
	if(pUserItem)
	{
		InsertItem(pDeptItem, pUserItem);
		pUserItem->Init(nUserId, m_strLayoutUserItem);
	}
	return pUserItem;
}


SKINUI_IMPLEMENT_DYNCREATE(CSelectedListView)
CSelectedListView::CSelectedListView(CSkinView* pParent)
: CSkinListView(pParent)
{
	SetAnimationScroll(TRUE);
}

void CSelectedListView::AddUserItem(uint64 nUserId)
{
	CUserItem* pUserItem = new CUserItem(this);
	if(pUserItem)
	{
		pUserItem->Init(nUserId, _T("UserItem.xml"));
		ResetScrollInfo();
		RedrawView();
	}
}

void CSelectedListView::DeleteUserItem(uint64 nUserId)
{
	const list<CSkinView*>& lstChild = GetAllChild();
	for(list<CSkinView*>::const_iterator iter = lstChild.begin(); iter != lstChild.end(); ++iter)
	{
		CUserItem* pUserItem = static_cast<CUserItem*>(*iter);
		if(pUserItem && pUserItem->GetUserId() == nUserId)
		{
			DeleteChild(pUserItem);
			ResetScrollInfo();
			RedrawView();
			return;
		}
	}
}