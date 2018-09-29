#pragma once

class CConversationDetailLayout : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_LAYOUT_INFO = 40000,
	};

public:
	CConversationDetailLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	static CConversationDetailLayout* GetInstance(CSkinView* pParent, ConvId convId);
	static CConversationDetailLayout* GetInstance(CSkinView* pParent, uint32 nDeptId);

public:
	void Init(ConvId convId);
	void Init(uint32 nDeptId);
};