#include "stdafx.h"
#include "ButtonDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CButtonDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON1, OnButtonClicked)
	ON_SKINUI_COMMAND(IDC_BUTTON2, OnButtonClicked)
	ON_SKINUI_COMMAND(IDC_BUTTON3, OnButtonClicked)
	ON_SKINUI_COMMAND(IDC_BUTTON4, OnButtonClicked)
SKINUI_END_MESSAGE_MAP()

CButtonDialog::CButtonDialog(const tstring& strXml)
	: CSkinDialog(strXml)
{

}

void CButtonDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CButtonDialog::OnButtonClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	MsgBox(SkinUI::StringFormat(_T("OnButtonClicked£¬Id=%d£¡"), nID));
}