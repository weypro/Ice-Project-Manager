#include <stdafx.h>
#include "UserInfoLayout.h"

SKINUI_BEGIN_MESSAGE_MAP(CUserInfoLayout, CConversationInfoLayout)
	ON_SKINUI_COMMAND(IDC_BUTTON_EDIT, OnBtnClickedEdit)
	ON_SKINUI_COMMAND(IDC_BUTTON_SAVE, OnBtnClickedSave)
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CUserInfoLayout)
CUserInfoLayout::CUserInfoLayout(CSkinView* pParent)
: CConversationInfoLayout(pParent)
, m_pEditMobile(NULL)
, m_pEditPhone(NULL)
, m_pEditEmail(NULL)
{

}

void CUserInfoLayout::HandleBuildFinish()
{
	CConversationInfoLayout::HandleBuildFinish();
	m_pEditMobile = static_cast<CSkinEditTextView*>(GetChildById(IDC_EDITVIEW_MOBILE));
	m_pEditPhone = static_cast<CSkinEditTextView*>(GetChildById(IDC_EDITVIEW_PHONE));
	m_pEditEmail = static_cast<CSkinEditTextView*>(GetChildById(IDC_EDITVIEW_EMAIL));
}

void CUserInfoLayout::Init(ConvId convId)
{
	CConversationInfoLayout::Init(convId);

	STUser* pUser = CUserStore::GetInstance()->GetUserById(convId.nId);
	if(pUser)
	{
		CSkinView* pSkinView = GetChildById(IDC_EDITVIEW_GENDER);
		if(pSkinView)
		{
			pSkinView->SetText(SkinUI::GetString(pUser->nGender == MALE ? _T("IDS_MALE") : _T("IDS_FEMALE")));
		}

		if(pUser->nDeptId != 0)
		{
			STDept* pDept = CDeptStore::GetInstance()->GetDeptById(pUser->nDeptId);
			if(pDept)
			{
				pSkinView = GetChildById(IDC_EDITVIEW_DEPTMENT);
				if(pSkinView)
				{
					pSkinView->SetText(pDept->strName);
				}
			}
		}

		pSkinView = GetChildById(IDC_EDITVIEW_POSITION);
		if(pSkinView)
		{
			pSkinView->SetText(pUser->strPosition);
		}
	}

	if(convId.nId == theApp.GetUserId() && GetOwner() != SkinUI::GetMainWnd())
	{
		CSkinView* pLayoutSendMsg = GetChildById(IDC_LAYOUT_SEND_MSG);
		CSkinView* pLayoutEditInfo = GetChildById(IDC_LAYOUT_EDIT_INFO);
		if(pLayoutSendMsg && pLayoutEditInfo)
		{
			pLayoutSendMsg->SetState(VS_HIDED);
			pLayoutEditInfo->SetState(VS_NORMAL);
		}
	}
}

void CUserInfoLayout::UpdateExtInfo(const map<tstring, JsonValue>& mapData)
{
	tstring strValue;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("mobile"));
	if(iter != mapData.end())
	{
		strValue = iter->second.GetString();
		if(m_pEditMobile)
		{
			m_pEditMobile->SetText(strValue);
		}
	}

	iter = mapData.find(_T("phone"));
	if(iter != mapData.end())
	{
		strValue = iter->second.GetString();
		if(m_pEditPhone)
		{
			m_pEditPhone->SetText(strValue);
		}
	}

	iter = mapData.find(_T("email"));
	if(iter != mapData.end())
	{
		strValue = iter->second.GetString();
		if(m_pEditEmail)
		{
			m_pEditEmail->SetText(strValue);
		}
	}
}

void CUserInfoLayout::OnBtnClickedEdit(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CRedrawLocker locker(this);
	SetEditMode(TRUE);
}

void CUserInfoLayout::OnBtnClickedSave(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(CommitPersonalInfo())
	{
		CRedrawLocker locker(this);
		SetEditMode(FALSE);
	}
}

void CUserInfoLayout::SetEditMode(BOOL bEditMode)
{
	CRedrawLocker locker(GetOwner());
	CSkinView* pButtonEdit = GetChildById(IDC_BUTTON_EDIT);
	CSkinView* pButtonSave = GetChildById(IDC_BUTTON_SAVE);
	if(pButtonEdit&& pButtonSave)
	{
		pButtonEdit->SetState(bEditMode ? VS_HIDED : VS_NORMAL);
		pButtonSave->SetState(bEditMode ? VS_NORMAL : VS_HIDED);
	}

	if(m_pEditMobile && m_pEditPhone && m_pEditEmail)
	{
		m_pEditMobile->SetEditMode(bEditMode);
		m_pEditPhone->SetEditMode(bEditMode);
		m_pEditEmail->SetEditMode(bEditMode);
	}
}

BOOL CUserInfoLayout::CommitPersonalInfo()
{
	if(m_pEditMobile && m_pEditPhone && m_pEditEmail)
	{
		//To Do
		//保存个人信息
		tstring strMobile = m_pEditMobile->GetText();
		tstring strPhone = m_pEditPhone->GetText();
		tstring strEmail = m_pEditEmail->GetText();

		return TRUE;
	}
	return FALSE;
}