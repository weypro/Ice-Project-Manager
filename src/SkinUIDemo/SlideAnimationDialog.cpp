#include "stdafx.h"
#include "SlideAnimationDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CSlideAnimationDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON_TEST, OnBtnClickedTest)
SKINUI_END_MESSAGE_MAP()

CSlideAnimationDialog::CSlideAnimationDialog(const tstring& strXml)
: CSkinDialog(strXml)
{

}

void CSlideAnimationDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CSlideAnimationDialog::HandleLButtonDown(CPoint point, BOOL& bHandle)
{
	CSlideAnimationHost* pAnimationHost = static_cast<CSlideAnimationHost*>(GetChildById(IDC_LAYOUT_SLIDE_HOST));
	if(pAnimationHost && pAnimationHost->GetState() == VS_NORMAL)
	{
		pAnimationHost->Hide();
		bHandle = TRUE;
	}
	else
	{
		CSkinDialog::HandleLButtonDown(point, bHandle);
	}
}

void CSlideAnimationDialog::OnBtnClickedTest(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSlideAnimationHost* pAnimationHost = static_cast<CSlideAnimationHost*>(GetChildById(IDC_LAYOUT_SLIDE_HOST));
	if(pAnimationHost)
	{
		CSkinSlideLayout* pSlideLayout = static_cast<CSkinSlideLayout*>(GetChildById(IDC_LAYOUT_SLIDE));
		if (pSlideLayout)
		{
			pAnimationHost->Show(pSlideLayout);
		}
	}
}