#pragma once

class CMainDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_TEXTVIEW = 1001,
	};

public:
	CMainDialog();

public:
	virtual void OnInitDialog();

	virtual void OnIdle();

protected:
	LRESULT OnCopyData(HWND hWnd, PCOPYDATASTRUCT pCopyDataStruct, BOOL& bHandle);

	void OnNcDestroy(BOOL& bHandle);

	SKINUI_DECLARE_MESSAGE_MAP()

private:
	void UpdateSpyResult(const tstring& strResult);

private:
	CSkinTextView* m_pTextView;
};