#pragma once

class CChatLoadingItem : public CSkinListItem
{
public:
	CChatLoadingItem(CSkinView* pParent);

public:
	void Init();

public:
	virtual tstring GetClassName(){ return _T("CChatLoadingItem"); }
	virtual LONG GetLayoutHeight();
};

class CChatTimeItem : public CSkinListItem
{
public:
	enum
	{
		IDC_TIME = 100001,
	};

public:
	CChatTimeItem(CSkinView* pParent);

public:
	void Init(uint64 unTime);
	uint64 GetTime() { return m_unTime; }

public:
	virtual tstring GetClassName(){ return _T("CChatTimeItem"); }
	virtual LONG GetLayoutHeight();

private:
	CSkinEditView*	m_pEditView;
	uint64			m_unTime;
};

class CChatMsgItem : public CSkinListItem
{
public:
	enum
	{
		IDC_AVATAR = 100001,
		IDC_NAME = 100002,
		IDC_SEND_STATUS = 100003,
		IDC_LAYOUT_CONTENT = 100100,
	};

public:
	CChatMsgItem(CSkinView* pParent);

public:
	void Init(const STMsg& msg);
	const STMsg& GetMsg() { return m_msg; }
	ConvId GetConvId();

public:
	virtual void LoadMsgContent();

public:
	virtual tstring GetClassName(){ return _T("CChatMsgItem"); }
	virtual tstring GetLayoutXml() = 0;
	virtual LONG GetMsgContentHeight() = 0;

	virtual void HandleTimer(UINT_PTR nIDEvent);
	virtual LONG GetLayoutHeight();

public:
	BOOL IsSendMsg()
	{
		return m_msg.nMsgSender == theApp.GetUserId();
	}

protected:
	STMsg						m_msg;

	CAvatarView*				m_pAvatar;
	CConversationNameView*		m_pUserName;
	CSkinImageView*				m_pSendStatus;
	CSkinRelativeLayout*		m_pLayoutContent;
};

class CTextMsgItem : public CChatMsgItem
{
public:
	enum
	{
		IDC_EDITVIEW_CONTENT = 100101,
	};

public:
	CTextMsgItem(CSkinView* pParent);

public:
	virtual tstring GetLayoutXml();
	virtual LONG GetMsgContentHeight();
	virtual void LoadMsgContent();

private:
	CSkinEditView*	m_pEditView;
};

class CChatMsgListView : public CSkinEditListView
{
public:
	CChatMsgListView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void SetConvId(ConvId convId);
	ConvId GetConvId() { return m_convId; }

public:
	CChatMsgItem* PrintMessage(const STMsg& msg);

private:
	CChatMsgItem* CreateChatMsgItem(const STMsg& msg);

private:
	virtual void ResetSortedItem();

private:
	ConvId								m_convId;
	map<MsgId, CChatMsgItem*>			m_mapChatMsgItem;
	map<uint64, CChatTimeItem*>			m_mapChatTimeItem;
};