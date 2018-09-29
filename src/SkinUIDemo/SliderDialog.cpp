#include "stdafx.h"
#include "SliderDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CSliderDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON1, OnBtnClickedAddPos)
	ON_SKINUI_MESSAGE(WM_SKINUI_SLIDER_POS_CHANGE, OnSliderPosChange)
SKINUI_END_MESSAGE_MAP()

CSliderDialog::CSliderDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pSlider1(NULL)
{

}

void CSliderDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	m_pSlider1 = static_cast<CSkinSlider*>(GetChildById(IDC_SLIDER1));
}

void CSliderDialog::OnBtnClickedAddPos(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pSlider1)
	{
		m_pSlider1->SetPos(min(m_pSlider1->GetPos() + 10, m_pSlider1->GetRange()));
		m_pSlider1->SetRect(m_pSlider1->GetRect());
		m_pSlider1->RedrawView();
	}
}

LRESULT CSliderDialog::OnSliderPosChange(WPARAM wParam, LPARAM lParam)
{
	CSkinSlider* pSlider = reinterpret_cast<CSkinSlider*>(lParam);
	if(pSlider)
	{
		MsgBoxModeless(SkinUI::StringFormat(_T("OnSliderPosChange£¬Id=%d£¬CurPos=%d£¡"), wParam, pSlider->GetPos()));
	}
	return 1L;
}