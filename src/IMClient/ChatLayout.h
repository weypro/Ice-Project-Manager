#pragma once

class CChatMsgListView;
class CChatInputEditView;
class CChatLayout : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_BUTTON_DETAIL = 31101,
		IDC_CONVERSATION_NAME = 31201,
		IDC_LISTVIEW_MESSAGE = 32110,
		IDC_BUTTON_EMOTION = 32311,
		IDC_BUTTON_SEND_MESSAGE = 323201,
		IDC_BUTTON_SEND_MESSAGE_MENU = 323202,
		IDC_EDITVIEW_INPUT = 32330,
	};

private:
	CChatLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	static map<ConvId, CChatLayout*> s_mapInst;
	static CChatLayout* GetExist(ConvId convId);
	static CChatLayout* GetInstance(CSkinView* pParent, ConvId convId);

public:
	void Init(ConvId convId);
	const ConvId& GetConvId() { return m_convId; }

public:
	void PrintMessage(const STMsg& msg);

public:
	virtual void HandleBuildFinish();
	virtual void PreHandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle);

protected:
	void OnBtnClickedDetail(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedEmotion(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedSendMessage(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedSendMessageMenu(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnCommandChangeSendMsgType(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnUpdateCommandSendEnter(CSkinView* pView);
	void OnUpdateCommandSendCtrlEnter(CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	void CreateSlideHost(CSlideHost** ppSlideHost, CSkinSlideLayout** ppSlideLayout);

private:
	ConvId					m_convId;
	CChatMsgListView*		m_pListView;
	CChatInputEditView*		m_pEditView;
};