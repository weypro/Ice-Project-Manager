#pragma once
#include "ConversationInfoLayout.h"
class CGroupInfoLayout : public CConversationInfoLayout
{
public:
	enum
	{
		IDC_EDITVIEW_GROUP_HOST = 40111,
		IDC_EDITVIEW_GROUP_NOTICE = 40112,
	};

public:
	CGroupInfoLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void Init(ConvId convId);

private:
	virtual void UpdateExtInfo(const map<tstring, JsonValue>& mapData);
};