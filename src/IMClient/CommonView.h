#pragma once

class CAvatarView : public CSkinButton
{
public:
	CAvatarView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Init(ConvId convId);

protected:
	virtual void DrawForeground(HDC hdc);

protected:
	ConvId		m_convId;
};

class CConversationNameView : public CSkinTextView
{
public:
	CConversationNameView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Init(ConvId convId);

private:
	ConvId m_convId;
};

class CChatLayout;
class CChatInputEditView : public CSkinEditView
{
public:
	CChatInputEditView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	CChatLayout* GetChatLayout();

public:
	virtual void HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);
};

class CSlideHost : public CSlideAnimationHost
{
public:
	enum
	{
		IDC_BUTTON_CLOSE = 39001,
	};

public:
	CSlideHost(CSkinView* pParent);

protected:
	void OnBtnClickedClose(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};

class CTabTextView : public CSkinTextView
{
public:
	CTabTextView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

private:
	virtual void DrawForeground(HDC hdc);
};

class CTabCtrl : public CSkinRadioGroup
{
public:
	CTabCtrl(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void SetRect(const CRect& rect);
};