#include "stdafx.h"
#include "DateViewDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CDateViewDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON, OnBtnClickedGetDate)
SKINUI_END_MESSAGE_MAP()

CDateViewDialog::CDateViewDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pDateView(NULL)
{

}

void CDateViewDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	m_pDateView = static_cast<CSkinDateView*>(GetChildById(IDC_DATEVIEW));
	if(m_pDateView)
	{
		m_pDateView->SetDate(2003, 7, 21);
	}
}

void CDateViewDialog::OnBtnClickedGetDate(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pDateView)
	{
		LONG nYear = 0, nMonth = 0, nDay = 0;
		m_pDateView->GetDate(nYear, nMonth, nDay);
		MsgBox(SkinUI::StringFormat(_T("当前日期为：%d年%d月%d日"), nYear, nMonth, nDay));
	}
}