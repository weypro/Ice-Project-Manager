#pragma once

class CConversationSlideLayout : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_LAYOUT_INFO = 40000,
		IDC_LISTVIEW_GROUP_MEMBER = 40300,
	};

public:
	CConversationSlideLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	static CConversationSlideLayout* GetInstance(CSkinView* pParent, ConvId convId);

public:
	void Init(ConvId convId);
};