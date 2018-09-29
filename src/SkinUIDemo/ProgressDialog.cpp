#include "stdafx.h"
#include "ProgressDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CProgressDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON1, OnBtnClickedAddPosByStep4)
	ON_SKINUI_COMMAND(IDC_BUTTON2, OnBtnClickedAddPosByStep10)
SKINUI_END_MESSAGE_MAP()

CProgressDialog::CProgressDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pProgress1(NULL)
, m_pProgress2(NULL)
{

}

void CProgressDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	m_pProgress1 = static_cast<CSkinProgress*>(GetChildById(IDC_PROGRESS1));
	m_pProgress2 = static_cast<CSkinProgress*>(GetChildById(IDC_PROGRESS2));
}

void CProgressDialog::OnBtnClickedAddPosByStep4(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pProgress1)
	{
		m_pProgress1->SetPos(min(m_pProgress1->GetPos() + 4, m_pProgress1->GetRange()));
		m_pProgress1->RedrawView();
	}
}

void CProgressDialog::OnBtnClickedAddPosByStep10(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pProgress2)
	{
		m_pProgress2->SetPos(min(m_pProgress2->GetPos() + 10, m_pProgress2->GetRange()));
		m_pProgress2->RedrawView();
	}
}