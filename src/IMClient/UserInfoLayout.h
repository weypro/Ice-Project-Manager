#pragma once
#include "ConversationInfoLayout.h"
class CUserInfoLayout : public CConversationInfoLayout
{
public:
	enum
	{
		IDC_BUTTON_EDIT = 40004,
		IDC_BUTTON_SAVE = 40005,
		IDC_EDITVIEW_GENDER = 40111,
		IDC_EDITVIEW_DEPTMENT = 40112,
		IDC_EDITVIEW_POSITION = 40113,
		IDC_EDITVIEW_MOBILE = 40114,
		IDC_EDITVIEW_PHONE = 40115,
		IDC_EDITVIEW_EMAIL = 40116,
	};

public:
	CUserInfoLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleBuildFinish();
	virtual void Init(ConvId convId);
	virtual void UpdateExtInfo(const map<tstring, JsonValue>& mapData);

protected:
	void OnBtnClickedEdit(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedSave(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	void SetEditMode(BOOL bEditMode);
	BOOL CommitPersonalInfo();

private:
	CSkinEditTextView*			m_pEditMobile;
	CSkinEditTextView*			m_pEditPhone;
	CSkinEditTextView*			m_pEditEmail;
};