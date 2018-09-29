#pragma once

class CConversationItem : public CSkinListItem
{
public:
	enum
	{
		IDC_AVATAR = 100011,
		IDC_NAME = 100012,
		IDC_INFO = 100013,
		IDC_TIME = 100014,

		IDC_BUTTON_CLOSE = 100041,
	};

public:
	CConversationItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Init(ConvId convId);
	void Update();

public:
	const ConvId& GetConvId() { return m_convId; }

public:
	virtual void HandleBuildFinish();

private:
	ConvId	m_convId;
};

class CConversationListView : public CSkinListView
{
public:
	CConversationListView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Load();
	void AddConversationItem(ConvId convId);
	CConversationItem* FindConversationItem(ConvId convId);
};