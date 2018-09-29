#include <stdafx.h>
#include "ConversationView.h"

SKINUI_IMPLEMENT_DYNCREATE(CConversationItem)
CConversationItem::CConversationItem(CSkinView* pParent)
: CSkinListItem(pParent)
{
	SetLazyLoad(TRUE);
}

void CConversationItem::Init(ConvId convId)
{
	m_convId = convId;
	SetLayoutHeight(ITEM_HEIGHT_60);
	SetLayout(_T("ConversationItem.xml"));
	SetMenu(_T("ConversationItemMenu.xml"));
	SetImage(_T("ListItem.png"));
}

void CConversationItem::HandleBuildFinish()
{
	CConversationNameView* pConversationNameView = static_cast<CConversationNameView*>(GetChildById(IDC_NAME));
	if(pConversationNameView)
	{
		pConversationNameView->Init(m_convId);
	}

	CAvatarView* pAvatarView = static_cast<CAvatarView*>(GetChildById(IDC_AVATAR));
	if(pAvatarView)
	{
		pAvatarView->Init(m_convId);
	}

	Update();
}

void CConversationItem::Update()
{
	STConv* pConv = CConvListStore::GetInstance()->GetConvById(m_convId);
	if(!pConv)
	{
		assert(false);
		return;
	}

	CSkinView* pView = GetChildById(IDC_INFO);
	if(pView)
	{
		pView->SetText(pConv->strMsgContent);
	}

	CSkinView* pViewMsgTime = GetChildById(IDC_TIME);
	if(pViewMsgTime)
	{
		pViewMsgTime->SetText(CAppHelper::GetMsgTimeText(pConv->nMsgTime, TRUE));
	}
}

static uint64 GetLastMsgTime(ConvId convId)
{
	STConv* pConv = CConvListStore::GetInstance()->GetConvById(convId);
	if(pConv)
	{
		return pConv->nMsgTime;
	}
	return 0;
}

static bool ConversationItemSortCompare(CSkinView* pView1, CSkinView* pView2)
{
	CConversationItem* pItem1 = static_cast<CConversationItem*>(pView1);
	CConversationItem* pItem2 = static_cast<CConversationItem*>(pView2);
	if(pItem1 && pItem2)
	{
		return GetLastMsgTime(pItem1->GetConvId()) > GetLastMsgTime(pItem2->GetConvId());
	}
	return false;
}

SKINUI_IMPLEMENT_DYNCREATE(CConversationListView)
CConversationListView::CConversationListView(CSkinView* pParent)
: CSkinListView(pParent)
{
	SetAnimationScroll(TRUE);
	SetItemSortFunc(ConversationItemSortCompare);
}

void CConversationListView::Load()
{
	const map<ConvId, STConv>& mapConv = CConvListStore::GetInstance()->GetAllConv();
	for(map<ConvId, STConv>::const_iterator iter = mapConv.begin(); iter != mapConv.end(); ++iter)
	{
		AddConversationItem(iter->first);
	}
}

void CConversationListView::AddConversationItem(ConvId convId)
{
	CConversationItem* pConversationItem = new CConversationItem(this);
	if(pConversationItem)
	{
		pConversationItem->Init(convId);
	}
}

CConversationItem* CConversationListView::FindConversationItem(ConvId convId)
{
	const list<CSkinView*>& lstChild = CSkinListView::GetAllChild();
	for(list<CSkinView*>::const_iterator iter = lstChild.begin(); iter != lstChild.end(); ++iter)
	{
		CConversationItem* pConversationItem = static_cast<CConversationItem*>(*iter);
		if(pConversationItem)
		{
			if(pConversationItem->GetConvId() == convId)
			{
				return pConversationItem;
			}
		}
	}
	return NULL;
}