#pragma once

class CDeptInfoLayout : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_TEXTVIEW_DEPT_NAME = 40011,
		IDC_TEXTVIEW_DEPT_INFO = 40012,
	};

public:
	CDeptInfoLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Init(uint32 nDeptId);
};