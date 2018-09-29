#include "stdafx.h"
#include "RadioButtonDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CRadioButtonDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_RADIOBUTTON1, OnRadioButtonClicked)
	ON_SKINUI_COMMAND(IDC_RADIOBUTTON2, OnRadioButtonClicked)
	ON_SKINUI_MESSAGE(WM_SKINUI_RADIO_GROUP_CHECKED_CHANGE, OnRadioGroupCheckedChange)
SKINUI_END_MESSAGE_MAP()

CRadioButtonDialog::CRadioButtonDialog(const tstring& strXml)
	: CSkinDialog(strXml)
{

}

void CRadioButtonDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CRadioButtonDialog::OnRadioButtonClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinRadioButton* pRadioButton = static_cast<CSkinRadioButton*>(pView);
	if(pRadioButton)
	{
		MsgBox(SkinUI::StringFormat(_T("OnRadioButtonClicked£¬Id=%d, IsChecked()=%s£¡"), nID, pRadioButton->IsChecked() ? _T("true") : _T("false")));
	}
}

LRESULT CRadioButtonDialog::OnRadioGroupCheckedChange(WPARAM wParam, LPARAM lParam)
{
	CSkinRadioButton* pRadioButton = reinterpret_cast<CSkinRadioButton*>(lParam);
	if(pRadioButton)
	{
		MsgBox(SkinUI::StringFormat(_T("OnRadioGroupCheckedChange£¬RadioGroup Id=%d£¬IsChecked()=%s£¡"), wParam, pRadioButton->IsChecked() ? _T("true") : _T("false")));
	}
	return 1L;
}