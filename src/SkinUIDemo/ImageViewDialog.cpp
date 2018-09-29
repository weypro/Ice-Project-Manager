#include "stdafx.h"
#include "ImageViewDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CImageViewDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_IMAGEVIEW, OnImageViewClicked)
SKINUI_END_MESSAGE_MAP()

CImageViewDialog::CImageViewDialog(const tstring& strXml)
: CSkinDialog(strXml)
{

}

void CImageViewDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CImageViewDialog::OnImageViewClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	MsgBox(SkinUI::StringFormat(_T("OnImageViewClicked£¬Id=%d£¡"), nID));
}