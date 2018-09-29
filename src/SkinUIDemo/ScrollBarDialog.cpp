#include "stdafx.h"
#include "ScrollBarDialog.h"

#define SHOW_IMAGE_WIDTH			760
#define SHOW_IMAGE_HEIGHT			530

SKINUI_BEGIN_MESSAGE_MAP(CScrollBarDialog, CSkinDialog)
	ON_SKINUI_WM_MOUSEWHEEL()
	ON_SKINUI_MESSAGE(WM_VSCROLL, OnVScroll)
	ON_SKINUI_MESSAGE(WM_HSCROLL, OnHScroll)
	ON_SKINUI_MESSAGE(WM_INITDIALOG_FINISH, OnInitDialogFinish)
SKINUI_END_MESSAGE_MAP()

CScrollBarDialog::CScrollBarDialog()
: CSkinDialog(_T("ControlDialog10.xml"))
, m_pScrollBarVert(NULL)
, m_pScrollBarHorz(NULL)
{

}

void CScrollBarDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
}

void CScrollBarDialog::DrawBackground(HDC hdc)
{
	CSkinDialog::DrawBackground(hdc);
	Image* pImage = SkinUI::GetImage(_T("TestImage.jpg"));
	if(pImage && m_pScrollBarVert && m_pScrollBarHorz)
	{
		Graphics graphics(hdc);
		graphics.DrawImage(pImage, Rect(32, 62, SHOW_IMAGE_WIDTH, SHOW_IMAGE_HEIGHT), m_pScrollBarHorz->GetScrollInfo().nPos, m_pScrollBarVert->GetScrollInfo().nPos, SHOW_IMAGE_WIDTH, SHOW_IMAGE_HEIGHT, UnitPixel);
	}
}

LRESULT CScrollBarDialog::OnInitDialogFinish(WPARAM wParam, LPARAM lParam)
{
	LRESULT lResult = CSkinDialog::OnInitDialogFinish(wParam, lParam);
	Image* pImage = SkinUI::GetImage(_T("TestImage.jpg"));
	if(pImage)
	{
		CRedrawLocker locker(this);
		m_pScrollBarVert = static_cast<CSkinScrollBar*>(GetChildById(IDC_SCROLLBAR_VERT));
		if(m_pScrollBarVert)
		{
			ScrollInfo info;
			info.nMax = pImage->GetHeight() - SHOW_IMAGE_HEIGHT;
			info.nPage = SHOW_IMAGE_HEIGHT;
			info.nStep = 30;
			m_pScrollBarVert->SetScrollInfo(info);
		}

		m_pScrollBarHorz = static_cast<CSkinScrollBar*>(GetChildById(IDC_SCROLLBAR_HORZ));
		if(m_pScrollBarHorz)
		{
			ScrollInfo info;
			info.nMax = pImage->GetWidth() - SHOW_IMAGE_WIDTH;
			info.nPage = SHOW_IMAGE_WIDTH;
			info.nStep = 30;
			m_pScrollBarHorz->SetScrollInfo(info);
		}
	}
	return lResult;
}


LRESULT CScrollBarDialog::OnMouseWheel(UINT nFlags, short zDelta, CPoint point, BOOL& bHandle)
{
	if((zDelta > 0) && (zDelta < WHEEL_DELTA))
	{
		zDelta = WHEEL_DELTA;
	}
	else if((zDelta < 0) && (zDelta > -WHEEL_DELTA))
	{
		zDelta = -WHEEL_DELTA;
	}

	LONG nStep = -zDelta / WHEEL_DELTA;
	CSkinScrollBar* pScrollBarCtrl = m_pScrollBarVert;
	if(SkinUI::IsShiftKeyDown())
	{
		pScrollBarCtrl = m_pScrollBarHorz;
	}

	if(pScrollBarCtrl)
	{
		CRedrawLocker locker(this);
		ScrollInfo info = pScrollBarCtrl->GetScrollInfo();
		info.nPos += nStep * info.nStep;
		info.nPos = max(info.nPos, (LONG)0);
		info.nPos = min(info.nPos, info.nMax);
		pScrollBarCtrl->SetScrollPos(info.nPos);
	}

	return 1L;
}

LRESULT CScrollBarDialog::OnVScroll(WPARAM wParam, LPARAM lParam)
{
	RedrawView();
	return 1L;
}

LRESULT CScrollBarDialog::OnHScroll(WPARAM wParam, LPARAM lParam)
{
	RedrawView();
	return 1L;
}