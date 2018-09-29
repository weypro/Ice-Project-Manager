#include "stdafx.h"
#include "MainDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_WM_NCDESTROY()
SKINUI_END_MESSAGE_MAP()

CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
{

}

void CMainDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CMainDialog::OnNcDestroy(BOOL& bHandle)
{
	bHandle = FALSE;
	PostQuitMessage(0);
}