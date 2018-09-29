#include "stdafx.h"
#include "HideAnimationDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CHideAnimationDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON_TEST, OnBtnClickedTest)
SKINUI_END_MESSAGE_MAP()

CHideAnimationDialog::CHideAnimationDialog(const tstring& strXml)
: CSkinDialog(strXml)
{

}

void CHideAnimationDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CHideAnimationDialog::OnBtnClickedTest(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CHideAnimationHost* pAnimationHost = static_cast<CHideAnimationHost*>(GetChildById(IDC_HOST));
	CSkinView* pSkinView = GetChildById(IDC_HIDE_VIEW);
	if(pAnimationHost && pSkinView)
	{
		if(pSkinView->IsVisible())
		{
			pAnimationHost->HideView(pSkinView);
		}
		else
		{
			pAnimationHost->ShowView(pSkinView);
		}
	}
}