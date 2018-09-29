#pragma once

class CConversationInfoLayout : public CSkinRelativeLayout
{
public:
	enum
	{
		IDC_AVATAR = 40002,
		IDC_NAME = 40003,
		IDC_LAYOUT_SEND_MSG = 40200,
		IDC_BUTTON_SEND_MSG = 40201,
		IDC_LAYOUT_EDIT_INFO = 40300,
	};

public:
	CConversationInfoLayout(CSkinView* pParent);

public:
	virtual void Init(ConvId convId);

private:
	virtual void UpdateExtInfo(const map<tstring, JsonValue>& mapData) = 0;

public:
	void Load();
	void Update(const STExtInfo& extInfo);

public:
	void OnBtnClickedSendMsg(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

protected:
	uint32	m_nSeq;
	ConvId	m_convId;
};