#include "stdafx.h"
#include "CheckBoxDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CCheckBoxDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_CHECKBOX1, OnCheckBoxClicked)
	ON_SKINUI_COMMAND(IDC_CHECKBOX2, OnCheckBoxClicked)
	ON_SKINUI_MESSAGE(WM_SKINUI_CHECKBOX_STATE_CHANGE, OnCheckBoxStateChange)
SKINUI_END_MESSAGE_MAP()

CCheckBoxDialog::CCheckBoxDialog(const tstring& strXml)
	: CSkinDialog(strXml)
{

}

void CCheckBoxDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CCheckBoxDialog::OnCheckBoxClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinCheckBox* pCheckBox = static_cast<CSkinCheckBox*>(pView);
	if(pCheckBox)
	{
		MsgBox(SkinUI::StringFormat(_T("OnCheckBoxClicked£¬Id=%d, IsChecked()=%s£¡"), nID, pCheckBox->IsChecked() ? _T("true") : _T("false")));
	}
}

LRESULT CCheckBoxDialog::OnCheckBoxStateChange(WPARAM wParam, LPARAM lParam)
{
	CSkinCheckBox* pCheckBox = reinterpret_cast<CSkinCheckBox*>(lParam);
	if(pCheckBox)
	{
		MsgBox(SkinUI::StringFormat(_T("OnCheckBoxStateChange£¬Id=%d£¬State=%d, IsChecked()=%s£¡"), pCheckBox->GetId(), wParam, pCheckBox->IsChecked() ? _T("true") : _T("false")));
	}
	return 1L;
}