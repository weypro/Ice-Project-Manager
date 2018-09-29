#include "stdafx.h"
#include "AboutDialog.h"

CAboutDialog::CAboutDialog()
: CSkinDialog(_T("AboutDialog.xml"))
{

}

void CAboutDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();

	CSkinTextView* pTextView = static_cast<CSkinTextView*>(GetChildById(IDC_TEXTVIEW_VERSION));
	if(pTextView)
	{
		tstring strFormat = SkinUI::GetString(_T("IDS_SKINUI_VERSION_FORMAT"));
		pTextView->SetText(SkinUI::StringFormat(strFormat.c_str(), SkinUI::GetVersion().c_str()));
	}

	pTextView = static_cast<CSkinTextView*>(GetChildById(IDC_TEXTVIEW_DATE));
	if(pTextView)
	{
		tstring strFormat = SkinUI::GetString(_T("IDS_SKINUI_DATE_FORMAT"));
		pTextView->SetText(SkinUI::StringFormat(strFormat.c_str(), SkinUI::GetVersionDate().c_str()));
	}
}