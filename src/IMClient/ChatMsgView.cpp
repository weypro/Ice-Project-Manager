#include <stdafx.h>
#include "ChatMsgView.h"

CChatLoadingItem::CChatLoadingItem(CSkinView* pParent)
: CSkinListItem(pParent)
{

}

void CChatLoadingItem::Init()
{
	SetLayout(_T("ChatLoadingItem.xml"));
}

LONG CChatLoadingItem::GetLayoutHeight()
{
	CSize szImage = SkinUI::GetImageSize(_T("Loading.gif"));
	CSize szText = SkinUI::MesureSize(CRect(0, 0, 1000, 1000), SkinUI::GetString(_T("IDS_NO_MORE_MSG")), _T("IDS_FONT_NORMAL"));
	LONG nLayoutHeight = max(szImage.cy, szText.cy) + MSG_MARGIN_10 + MSG_MARGIN_10;
	return nLayoutHeight;
}

CChatTimeItem::CChatTimeItem(CSkinView* pParent)
: CSkinListItem(pParent)
, m_pEditView(NULL)
, m_unTime(0)
{

}

void CChatTimeItem::Init(uint64 unTime)
{
	SetLayout(_T("ChatTimeItem.xml"));
	m_pEditView = static_cast<CSkinEditView*>(GetChildById(IDC_TIME));
	m_unTime = unTime;
	if(m_pEditView)
	{
		m_pEditView->SetText(CAppHelper::GetMsgTimeText(m_unTime, FALSE));
	}
}

LONG CChatTimeItem::GetLayoutHeight()
{
	CSize szEditView;
	if(m_pEditView)
	{
		m_pEditView->GetWrapContentSize(szEditView);
		m_pEditView->SetLayoutWidth(szEditView.cx);
		m_pEditView->SetLayoutHeight(szEditView.cy);
	}
	LONG nLayoutHeight = szEditView.cy + MSG_MARGIN_10 + MSG_MARGIN_10;
	return nLayoutHeight;
}

CChatMsgItem::CChatMsgItem(CSkinView* pParent)
: CSkinListItem(pParent)
, m_pAvatar(NULL)
, m_pUserName(NULL)
, m_pSendStatus(NULL)
, m_pLayoutContent(NULL)
{

}

void CChatMsgItem::Init(const STMsg& msg)
{
	m_msg = msg;
	SetLayout(GetLayoutXml());
	LoadMsgContent();
}

ConvId CChatMsgItem::GetConvId()
{
	CChatMsgListView* pChatMsgListView = static_cast<CChatMsgListView*>(GetParent());
	if(pChatMsgListView)
	{
		return pChatMsgListView->GetConvId();
	}
	assert(false);
	return ConvId();
}

void CChatMsgItem::LoadMsgContent()
{
	m_pUserName = static_cast<CConversationNameView*>(GetChildById(IDC_NAME));
	if(m_pUserName)
	{
		m_pUserName->Init(ConvId(CONV_TYPE_USER, m_msg.nMsgSender));
	}

	m_pAvatar = static_cast<CAvatarView*>(GetChildById(IDC_AVATAR));
	if(m_pAvatar)
	{
		m_pAvatar->Init(ConvId(CONV_TYPE_USER, m_msg.nMsgSender));
	}

	m_pSendStatus = static_cast<CSkinImageView*>(GetChildById(IDC_SEND_STATUS));
	if(m_pSendStatus)
	{
		m_pSendStatus->Play();
		SetTimer(0, 1000);
	}

	m_pLayoutContent = static_cast<CSkinRelativeLayout*>(GetChildById(IDC_LAYOUT_CONTENT));
}

void CChatMsgItem::HandleTimer(UINT_PTR nIDEvent)
{
	KillTimer(0);

	if(m_pSendStatus)
	{
		DeleteChild(m_pSendStatus);
		m_pSendStatus = NULL;
	}
}

LONG CChatMsgItem::GetLayoutHeight()
{
	LONG nLayoutHeight = GetMsgContentHeight() + MSG_MARGIN_10 + MSG_MARGIN_10;
	if(m_pUserName)
	{
		CSize szText = SkinUI::MesureSize(CRect(0, 0, 1000, 1000), m_pUserName->GetText(), _T("IDS_FONT_NORMAL"));
		nLayoutHeight += szText.cx + MSG_MARGIN_10;
	}
	return nLayoutHeight;
}

CTextMsgItem::CTextMsgItem(CSkinView* pParent)
: CChatMsgItem(pParent)
, m_pEditView(NULL)
{

}

tstring CTextMsgItem::GetLayoutXml()
{
	return IsSendMsg() ? _T("ChatTextMsgSendItem.xml") : _T("ChatTextMsgRecvItem.xml");
}

LONG CTextMsgItem::GetMsgContentHeight()
{
	CSize szEditView;
	szEditView.cx = GetParent()->GetRect().Width() - 150;
	if(m_pEditView && m_pLayoutContent)
	{
		m_pEditView->GetWrapContentSize(szEditView);
		m_pLayoutContent->SetLayoutWidth(szEditView.cx + MSG_MARGIN_10 * 2 + MSG_MARGIN_5);
		m_pLayoutContent->SetLayoutHeight(szEditView.cy + MSG_MARGIN_10 * 2);
	}
	LONG nLayoutHeight = szEditView.cy + MSG_MARGIN_10 + MSG_MARGIN_10;
	return nLayoutHeight;
}

void CTextMsgItem::LoadMsgContent()
{
	CChatMsgItem::LoadMsgContent();

	m_pEditView = static_cast<CSkinEditView*>(GetChildById(IDC_EDITVIEW_CONTENT));
	if(m_pEditView)
	{
		m_pEditView->AppendText(m_msg.strMsgContent);

		tstring strImage = SkinUI::GetCurModulePath() + _T("\\res\\IMClient\\image\\");
		m_pEditView->AppendImage(strImage + _T("1.gif"));
		m_pEditView->AppendImage(strImage + _T("2.gif"));
		m_pEditView->AppendImage(strImage + _T("3.gif"));
		m_pEditView->AppendImage(strImage + _T("4.gif"));
	}
}

SKINUI_IMPLEMENT_DYNCREATE(CChatMsgListView)
CChatMsgListView::CChatMsgListView(CSkinView* pParent)
: CSkinEditListView(pParent)
{

}

void CChatMsgListView::SetConvId(ConvId convId)
{
	m_convId = convId;
}

static BOOL IsOverFiveMinute(const map<uint64, CChatTimeItem*>& mapChatTimeItem, uint64 unTime)
{
	if(mapChatTimeItem.empty())
	{
		return TRUE;
	}

	uint64 unTimeMin = mapChatTimeItem.begin()->first;
	uint64 unTimeMax = mapChatTimeItem.rbegin()->first;
	if(unTime < unTimeMin && (unTimeMin - unTime) >= (PRE_MINUTE * 5))
	{
		return TRUE;
	}

	if(unTime > unTimeMax && (unTime - unTimeMax) >= (PRE_MINUTE * 5))
	{
		return TRUE;
	}

	return FALSE;
}

CChatMsgItem* CChatMsgListView::PrintMessage(const STMsg& msg)
{
	map<MsgId, CChatMsgItem*>::iterator iterFind = m_mapChatMsgItem.find(msg.msgId);
	if(iterFind != m_mapChatMsgItem.end())
	{
		return NULL;
	}

	if(IsOverFiveMinute(m_mapChatTimeItem, msg.nMsgTime))
	{
		CChatTimeItem* pChatTimeItem = new CChatTimeItem(this);
		if(pChatTimeItem)
		{
			pChatTimeItem->Init(msg.nMsgTime);
			m_mapChatTimeItem[msg.nMsgTime] = pChatTimeItem;
		}
	}

	CChatMsgItem* pChatMsgItem = CreateChatMsgItem(msg);
	if(pChatMsgItem)
	{
		m_mapChatMsgItem[msg.msgId] = pChatMsgItem;
	}
	return pChatMsgItem;
}

CChatMsgItem* CChatMsgListView::CreateChatMsgItem(const STMsg& msg)
{
	CChatMsgItem* pChatMsgItem = NULL;
	if(msg.nMsgType == MSG_TYPE_TEXT)
	{
		pChatMsgItem = new CTextMsgItem(this);
	}
	else
	{
		assert(false);
		return NULL;
	}

	if(pChatMsgItem)
	{
		pChatMsgItem->Init(msg);
	}
	return pChatMsgItem;
}

void CChatMsgListView::ResetSortedItem()
{
	CSkinView* pLoadingItem = NULL;
	map<MsgId, CChatMsgItem*> mapChatMsgItem;
	map<uint64, CChatTimeItem*> mapChatTimeItem;

	const list<CSkinView*>& lstChild = CSkinListView::GetAllChild();
	for(list<CSkinView*>::const_iterator iter = lstChild.begin(); iter != lstChild.end(); ++iter)
	{
		if((*iter)->GetClassName() == _T("CChatLoadingItem"))
		{
			pLoadingItem = static_cast<CChatLoadingItem*>(*iter);
		}
		else if((*iter)->GetClassName() == _T("CChatTimeItem"))
		{
			CChatTimeItem* pChatTimeItem = static_cast<CChatTimeItem*>(*iter);
			if(pChatTimeItem)
			{
				mapChatTimeItem[pChatTimeItem->GetTime()] = pChatTimeItem;
			}
		}
		else if((*iter)->GetClassName() == _T("CChatMsgItem"))
		{
			CChatMsgItem* pChatMsgItem = static_cast<CChatMsgItem*>(*iter);
			if(pChatMsgItem)
			{
				mapChatMsgItem[pChatMsgItem->GetMsg().msgId] = pChatMsgItem;
			}
		}
		else
		{
			assert(false);
		}
	}

	m_child.clear();
	if(pLoadingItem)
	{
		m_child.push_back(pLoadingItem);
	}

	set<uint64> setTime;
	for(map<MsgId, CChatMsgItem*>::iterator iter = mapChatMsgItem.begin(); iter != mapChatMsgItem.end(); ++iter)
	{
		CChatMsgItem* pChatMsgItem = static_cast<CChatMsgItem*>(iter->second);
		if(pChatMsgItem)
		{
			uint64 unTime = pChatMsgItem->GetMsg().nMsgTime;
			map<uint64, CChatTimeItem*>::iterator iterTimeItem = mapChatTimeItem.find(unTime);
			if(iterTimeItem != mapChatTimeItem.end())
			{
				set<uint64>::iterator iterTime = setTime.find(unTime);
				if(iterTime == setTime.end())
				{
					setTime.insert(unTime);
					m_child.push_back(iterTimeItem->second);
				}
			}
		}
		m_child.push_back(iter->second);
	}
}
