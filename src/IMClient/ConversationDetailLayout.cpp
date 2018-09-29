#include <stdafx.h>
#include "ConversationDetailLayout.h"
#include "ConversationInfoLayout.h"
#include "UserInfoLayout.h"
#include "GroupInfoLayout.h"
#include "DeptInfoLayout.h"

SKINUI_IMPLEMENT_DYNCREATE(CConversationDetailLayout)
CConversationDetailLayout::CConversationDetailLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
{

}

CConversationDetailLayout* CConversationDetailLayout::GetInstance(CSkinView* pParent, ConvId convId)
{
	CConversationDetailLayout* pConversationDetailLayout = new CConversationDetailLayout(pParent);
	if(pConversationDetailLayout)
	{
		pConversationDetailLayout->Init(convId);
		pConversationDetailLayout->SetRect(pParent->GetRect());
	}
	return pConversationDetailLayout;
}

CConversationDetailLayout* CConversationDetailLayout::GetInstance(CSkinView* pParent, uint32 nDeptId)
{
	CConversationDetailLayout* pConversationDetailLayout = new CConversationDetailLayout(pParent);
	if(pConversationDetailLayout)
	{
		pConversationDetailLayout->Init(nDeptId);
		pConversationDetailLayout->SetRect(pParent->GetRect());
	}
	return pConversationDetailLayout;
}

void CConversationDetailLayout::Init(ConvId convId)
{
	SetLayoutWidth(FILL_PARENT);
	SetLayoutHeight(FILL_PARENT);
	if(convId.nType == CONV_TYPE_USER)
	{
		SetLayout(_T("UserDetailLayout.xml"));
	}
	else if(convId.nType == CONV_TYPE_GROUP)
	{
		SetLayout(_T("GroupDetailLayout.xml"));
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
	}
}

void CConversationDetailLayout::Init(uint32 nDeptId)
{
	SetLayoutWidth(FILL_PARENT);
	SetLayoutHeight(FILL_PARENT);
	SetLayout(_T("DeptDetailLayout.xml"));

	CDeptInfoLayout* pDeptInfoLayout = static_cast<CDeptInfoLayout*>(GetChildById(IDC_LAYOUT_INFO));
	if(pDeptInfoLayout)
	{
		pDeptInfoLayout->Init(nDeptId);
	}
}