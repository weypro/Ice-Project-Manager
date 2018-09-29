#include "stdafx.h"
#include "TimeViewDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CTimeViewDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON, OnBtnClickedGetTime)
SKINUI_END_MESSAGE_MAP()

CTimeViewDialog::CTimeViewDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pTimeView(NULL)
{

}

void CTimeViewDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	m_pTimeView = static_cast<CSkinTimeView*>(GetChildById(IDC_TIMEVIEW));
	if(m_pTimeView)
	{
		m_pTimeView->SetTime(12, 34, 56);
	}
}

void CTimeViewDialog::OnBtnClickedGetTime(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pTimeView)
	{
		LONG nHour = 0, nMinute = 0, nSecond = 0;
		m_pTimeView->GetTime(nHour, nMinute, nSecond);
		MsgBox(SkinUI::StringFormat(_T("当前时间为：%d时%d分%d秒"), nHour, nMinute, nSecond));
	}
}