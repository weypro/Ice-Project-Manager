#pragma once

class CAboutDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_TEXTVIEW_VERSION = 101,
		IDC_TEXTVIEW_DATE = 102,
	};

public:
	CAboutDialog();

public:
	virtual void OnInitDialog();
};