#include "stdafx.h"
#include "HyperlinkDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CHyperlinkDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_HYPERLINK1, OnHyperlinkClicked)
	ON_SKINUI_COMMAND(IDC_HYPERLINK2, OnHyperlinkClicked)
SKINUI_END_MESSAGE_MAP()

CHyperlinkDialog::CHyperlinkDialog(const tstring& strXml)
	: CSkinDialog(strXml)
{

}

void CHyperlinkDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CHyperlinkDialog::OnHyperlinkClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	MsgBox(SkinUI::StringFormat(_T("OnHyperlinkClicked£¬Id=%d£¡"), nID));
}