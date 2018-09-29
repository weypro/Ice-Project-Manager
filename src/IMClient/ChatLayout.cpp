#include <stdafx.h>
#include "ChatLayout.h"
#include "ChatMsgView.h"
#include "ConversationDetailLayout.h"
#include "ConversationSlideLayout.h"

SKINUI_BEGIN_MESSAGE_MAP(CChatLayout, CSkinRelativeLayout)
	ON_SKINUI_COMMAND(IDC_BUTTON_DETAIL, OnBtnClickedDetail)
	ON_SKINUI_COMMAND(IDC_BUTTON_EMOTION, OnBtnClickedEmotion)
	ON_SKINUI_COMMAND(IDC_BUTTON_SEND_MESSAGE, OnBtnClickedSendMessage)
	ON_SKINUI_COMMAND(IDC_BUTTON_SEND_MESSAGE_MENU, OnBtnClickedSendMessageMenu)
	ON_SKINUI_COMMAND(ID_MENU_SEND_ENTER, OnCommandChangeSendMsgType)
	ON_SKINUI_COMMAND(ID_MENU_SEND_CTRL_ENTER, OnCommandChangeSendMsgType)
	ON_SKINUI_UPDATE_COMMAND_UI(ID_MENU_SEND_ENTER, OnUpdateCommandSendEnter)
	ON_SKINUI_UPDATE_COMMAND_UI(ID_MENU_SEND_CTRL_ENTER, OnUpdateCommandSendCtrlEnter)
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CChatLayout)
CChatLayout::CChatLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
, m_pListView(NULL)
, m_pEditView(NULL)
{

}

map<ConvId, CChatLayout*> CChatLayout::s_mapInst;
CChatLayout* CChatLayout::GetExist(ConvId convId)
{
	map<ConvId, CChatLayout*>::iterator iter = s_mapInst.find(convId);
	if(iter != s_mapInst.end())
	{
		return iter->second;
	}
	return NULL;
}

CChatLayout* CChatLayout::GetInstance(CSkinView* pParent, ConvId convId)
{
	CChatLayout* pChatLayout = GetExist(convId);
	if(!pChatLayout)
	{
		pChatLayout = new CChatLayout(pParent);
		if(pChatLayout)
		{
			pChatLayout->Init(convId);
			pChatLayout->SetRect(pParent->GetRect());
		}
	}
	return pChatLayout;
}

void CChatLayout::Init(ConvId convId)
{
	m_convId = convId;
	s_mapInst[convId] = this;
	SetLayoutWidth(FILL_PARENT);
	SetLayoutHeight(FILL_PARENT);
	SetLayout(_T("ChatLayout.xml"));
}

void CChatLayout::HandleBuildFinish()
{
	CSkinRelativeLayout::HandleBuildFinish();

	CConversationNameView* pConversationNameView = static_cast<CConversationNameView*>(GetChildById(IDC_CONVERSATION_NAME));
	if(pConversationNameView)
	{
		pConversationNameView->Init(m_convId);
	}

	m_pEditView = static_cast<CChatInputEditView*>(GetChildById(IDC_EDITVIEW_INPUT));
	m_pListView = static_cast<CChatMsgListView*>(GetChildById(IDC_LISTVIEW_MESSAGE));
	if(m_pListView)
	{
		m_pListView->SetConvId(m_convId);
	}
}

void CChatLayout::PreHandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle)
{
	if(vkey == VK_RETURN)
	{
		BOOL bCtrlEnter = FALSE;
		if((bCtrlEnter && SkinUI::IsCtrlKeyDown()) || (!bCtrlEnter && !SkinUI::IsCtrlKeyDown()))
		{
			OnBtnClickedSendMessage(NULL, NULL, NULL);
			bHandle = TRUE;
		}
	}
	else
	{
		if(SkinUI::IsAltKeyDown())
		{
			if(vkey == 's' || vkey == 'S')
			{
				OnBtnClickedSendMessage(NULL, NULL, NULL);
				bHandle = TRUE;
			}
		}
	}
}

void CChatLayout::PrintMessage(const STMsg& msg)
{
	if(m_pListView)
	{
		m_pListView->PrintMessage(msg);
		m_pListView->ResetScrollInfo();
		m_pListView->ScrollBottom();
	}
}

void CChatLayout::CreateSlideHost(CSlideHost** ppSlideHost, CSkinSlideLayout** ppSlideLayout)
{
	CSlideHost* pSlideHost = new CSlideHost(this);
	if(pSlideHost)
	{
		pSlideHost->SetLayoutWidth(360);
		pSlideHost->SetLayoutHeight(FILL_PARENT);
		pSlideHost->SetLayoutAlignParentRight(0);
		pSlideHost->SetBkgImage(_T("SlideShadow.png"));

		CSkinSlideLayout* pSlideLayout = new CSkinSlideLayout(pSlideHost);
		if(pSlideLayout)
		{
			pSlideLayout->SetLayoutAlignParentLeft(12);
			pSlideLayout->SetLayoutAlignParentRight(0);
			pSlideLayout->SetLayoutHeight(FILL_PARENT);
			*ppSlideLayout = pSlideLayout;
		}
		*ppSlideHost = pSlideHost;
	}
}

void CChatLayout::OnBtnClickedDetail(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSlideHost* pSlideHost = NULL;
	CSkinSlideLayout* pSlideLayout = NULL;
	CreateSlideHost(&pSlideHost, &pSlideLayout);
	if(pSlideHost && pSlideLayout)
	{
		CConversationSlideLayout::GetInstance(pSlideLayout, m_convId);
		pSlideHost->GetParent()->SetRect(pSlideHost->GetParent()->GetRect());
		pSlideHost->Show(pSlideLayout);
	}
}

void CChatLayout::OnBtnClickedEmotion(UINT uNotifyCode, int nID, CSkinView* pView)
{

}

void CChatLayout::OnBtnClickedSendMessage(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strText(m_pEditView->GetText());
	if(strText.empty())
	{
		return;
	}

	CRedrawLocker locker(this);
	m_pEditView->SetText(tstring());

	STMsg msg;
	msg.nMsgType = MSG_TYPE_TEXT;
	msg.strMsgContent = strText;
	msg.nMsgTime = CAppHelper::GetCurTime();
	msg.nMsgSender = theApp.GetUserId();
	PrintMessage(msg);

	//To Do
	//转发消息
}

void CChatLayout::OnBtnClickedSendMessageMenu(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(pView)
	{
		CRect rc = pView->GetRect();
		CPoint pt(rc.left, rc.bottom);
		GetOwner()->ClientToScreen(pt);
		GetOwner()->PopupMenu(_T("SendMsgMenu.xml"), pt, rc.Size(), this);
	}
}

void CChatLayout::OnCommandChangeSendMsgType(UINT uNotifyCode, int nID, CSkinView* pView)
{
	BOOL bCtrlEnter = (nID == ID_MENU_SEND_CTRL_ENTER);
	//To Do
	//保存配置信息
}

void CChatLayout::OnUpdateCommandSendEnter(CSkinView* pView)
{
	BOOL bCtrlEnter = FALSE;
	CSkinListItem* pMenuItem = static_cast<CSkinListItem*>(pView);
	if(pMenuItem)
	{
		pMenuItem->SetCheckedState((!bCtrlEnter) ? CS_CHECKED : CS_UNCHECKED);
	}
}

void CChatLayout::OnUpdateCommandSendCtrlEnter(CSkinView* pView)
{
	BOOL bCtrlEnter = FALSE;
	CSkinListItem* pMenuItem = static_cast<CSkinListItem*>(pView);
	if(pMenuItem)
	{
		pMenuItem->SetCheckedState(bCtrlEnter ? CS_CHECKED : CS_UNCHECKED);
	}
}