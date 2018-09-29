#include <stdafx.h>
#include "GroupView.h"

SKINUI_IMPLEMENT_DYNCREATE(CGroupItem)
CGroupItem::CGroupItem(CSkinView* pParent)
: CSkinListItem(pParent)
, m_nGroupId(0)
{

}

void CGroupItem::Init(uint64 nGroupId)
{
	m_nGroupId = nGroupId;
	SetLayout(_T("GroupItem.xml"));
	SetLayoutHeight(ITEM_HEIGHT_60);
	SetImage(_T("ListItem.png"));
}

void CGroupItem::HandleBuildFinish()
{
	CConversationNameView* pConversationNameView = static_cast<CConversationNameView*>(GetChildById(IDC_NAME));
	if(pConversationNameView)
	{
		pConversationNameView->Init(ConvId(CONV_TYPE_GROUP, m_nGroupId));
	}

	CAvatarView* pAvatarView = static_cast<CAvatarView*>(GetChildById(IDC_AVATAR));
	if(pAvatarView)
	{
		pAvatarView->Init(ConvId(CONV_TYPE_GROUP, m_nGroupId));
	}
}

SKINUI_IMPLEMENT_DYNCREATE(CGroupListView)
CGroupListView::CGroupListView(CSkinView* pParent)
: CSkinListView(pParent)
{
	SetAnimationScroll(TRUE);
}

void CGroupListView::Load()
{
	const map<uint64, STGroup>& mapGroup = CGroupStore::GetInstance()->GetAllGroup();
	for(map<uint64, STGroup>::const_iterator iter = mapGroup.begin(); iter != mapGroup.end(); ++iter)
	{
		AddGroupItem(iter->first);
	}
}

void CGroupListView::AddGroupItem(uint64 nGroupId)
{
	CGroupItem* pGroupItem = new CGroupItem(this);
	if(pGroupItem)
	{
		pGroupItem->Init(nGroupId);
	}
}

SKINUI_IMPLEMENT_DYNCREATE(CGroupMemberItem)
CGroupMemberItem::CGroupMemberItem(CSkinView* pParent)
: CUserItem(pParent)
{

}

SKINUI_IMPLEMENT_DYNCREATE(CGroupMemberListView)
CGroupMemberListView::CGroupMemberListView(CSkinView* pParent)
: CSkinListView(pParent)
, m_nGroupId(0)
{
	SetAnimationScroll(TRUE);
}

void CGroupMemberListView::Load(uint64 nGroupId)
{
	m_nGroupId = nGroupId;
	const set<uint64> setGroupMember = CGroupMemberStore::GetInstance()->GetGroupMember();
	for(set<uint64>::const_iterator iter = setGroupMember.begin(); iter != setGroupMember.end(); ++iter)
	{
		AddGroupMemberItem(*iter);
	}
}

void CGroupMemberListView::AddGroupMemberItem(uint64 nUserId)
{
	CGroupMemberItem* pGroupMemberItem = new CGroupMemberItem(this);
	if(pGroupMemberItem)
	{
		pGroupMemberItem->Init(nUserId, _T("GroupMemberItem.xml"));
	}
}