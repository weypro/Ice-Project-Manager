#include "stdafx.h"
#include "ComboBoxDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CComboBoxDialog, CSkinDialog)
	ON_SKINUI_MESSAGE(WM_SKINUI_COMBOBOX_SEL_CHANGE, OnComboBoxSelChange)
SKINUI_END_MESSAGE_MAP()

CComboBoxDialog::CComboBoxDialog(const tstring& strXml)
	: CSkinDialog(strXml)
{

}

void CComboBoxDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

LRESULT CComboBoxDialog::OnComboBoxSelChange(WPARAM wParam, LPARAM lParam)
{
	CSkinComboBox* pComboBox = reinterpret_cast<CSkinComboBox*>(lParam);
	if(pComboBox)
	{
		MsgBox(SkinUI::StringFormat(_T("OnComboBoxSelChange£¬Id=%d£¬CurSel=%d, CurText=%s£¡"), wParam, pComboBox->GetCurSel(), pComboBox->GetText().c_str()));
	}
	return 1L;
}