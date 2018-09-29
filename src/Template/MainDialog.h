#pragma once

class CMainDialog : public CSkinDialog
{
public:
	CMainDialog();

public:
	virtual void OnInitDialog();

protected:
	void OnNcDestroy(BOOL& bHandle);
	SKINUI_DECLARE_MESSAGE_MAP()
};