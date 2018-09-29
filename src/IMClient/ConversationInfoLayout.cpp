#include <stdafx.h>
#include "ConversationInfoLayout.h"
#include "MainDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CConversationInfoLayout, CSkinRelativeLayout)
	ON_SKINUI_COMMAND(IDC_BUTTON_SEND_MSG, OnBtnClickedSendMsg)
SKINUI_END_MESSAGE_MAP()

CConversationInfoLayout::CConversationInfoLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
, m_nSeq(0)
{

}

void CConversationInfoLayout::Init(ConvId convId)
{
	m_convId = convId;
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

	Load();
}

void CConversationInfoLayout::Load()
{
	STExtInfo* pExtInfo = CExtInfoStore::GetInstance()->GetExtInfoById(m_convId);
	if(pExtInfo)
	{
		Update(*pExtInfo);
	}
}

void CConversationInfoLayout::Update(const STExtInfo& extInfo)
{
	JsonObject object;
	SkinUI::StringToObject(object, extInfo.strExtInfo);
	UpdateExtInfo(object.GetKeyValue());
}

void CConversationInfoLayout::OnBtnClickedSendMsg(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(CMainDialog::s_inst)
	{
		CMainDialog::s_inst->BeginConversation(m_convId);
	}
}