#pragma once
enum
{
	WM_SETUP_NOTIFY = WM_USER + 20000,
};

enum
{
	NOTIFY_RANGE = 1,
	NOTIFY_PROGRESS,
};

class CMainDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_PROGRESS = 1001,
		IDC_TEXTVIEW = 1002,
		IDC_BUTTON_FINISH = 1004,
	};

	enum
	{
		WINDOW_MODE_START = 1,
		WINDOW_MODE_ING = 2,
		WINDOW_MODE_FINISH = 3,
	};

public:
	CMainDialog();

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedSetupStart(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedSetupFinish(UINT uNotifyCode, int nID, CSkinView* pView);

	LRESULT OnSetupNotify(WPARAM wParam, LPARAM lParam);

	void OnNcDestroy(BOOL& bHandle);

	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinTextView* m_pTextView;
	CSkinProgress* m_pProgress;
};