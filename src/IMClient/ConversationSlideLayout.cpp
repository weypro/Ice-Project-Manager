#include <stdafx.h>
#include "GroupView.h"
#include "ConversationSlideLayout.h"
#include "ConversationInfoLayout.h"

SKINUI_IMPLEMENT_DYNCREATE(CConversationSlideLayout)
CConversationSlideLayout::CConversationSlideLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
{

}

CConversationSlideLayout* CConversationSlideLayout::GetInstance(CSkinView* pParent, ConvId convId)
{
	CConversationSlideLayout* pConversationSlideLayout = new CConversationSlideLayout(pParent);
	if(pConversationSlideLayout)
	{
		pConversationSlideLayout->Init(convId);
		pConversationSlideLayout->SetRect(pParent->GetRect());
	}
	return pConversationSlideLayout;
}

void CConversationSlideLayout::Init(ConvId convId)
{
	SetLayoutWidth(FILL_PARENT);
	SetLayoutHeight(FILL_PARENT);
	if(convId.nType == CONV_TYPE_USER)
	{
		SetLayout(_T("UserSlideLayout.xml"));
	}
	else if(convId.nType == CONV_TYPE_GROUP)
	{
		SetLayout(_T("GroupSlideLayout.xml"));

		CGroupMemberListView* pGroupMemberListView = static_cast<CGroupMemberListView*>(GetChildById(IDC_LISTVIEW_GROUP_MEMBER));
		if(pGroupMemberListView)
		{
			pGroupMemberListView->Load(convId.nId);
		}
	}
	else
	{
		assert(false);
		return;
	}

	CConversationInfoLayout* pConversationInfoLayout = static_cast<CConversationInfoLayout*>(GetChildById(IDC_LAYOUT_INFO));
	if(pConversationInfoLayout)
	{
		pConversationInfoLayout->Init(convId);

		CSkinView* pSkinView = GetChildById(CConversationInfoLayout::IDC_LAYOUT_SEND_MSG);
		if(pSkinView)
		{
			pSkinView->SetState(VS_HIDED);
		}
	}
}