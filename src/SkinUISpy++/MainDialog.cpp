#include "stdafx.h"
#include "MainDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_WM_NCDESTROY()
	ON_SKINUI_WM_COPYDATA()
SKINUI_END_MESSAGE_MAP()

CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
, m_pTextView(NULL)
{

}

void CMainDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();

	m_pTextView = static_cast<CSkinTextView*>(GetChildById(IDC_TEXTVIEW));
}

void CMainDialog::OnIdle()
{
	CSkinDialog::OnIdle();

	CPoint ptPopup;
	GetCursorPos(&ptPopup);
	HWND hWnd = WindowFromPoint(ptPopup);
	HWND hWndSpy = GetHWND();
	LRESULT lResult = 0L;
	if(hWnd && hWnd != hWndSpy)
	{
		lResult = ::SendMessage(hWnd, WM_SPY_WINDOW, WPARAM(hWndSpy), LPARAM(MAKELONG(ptPopup.x, ptPopup.y)));
	}

	if(!lResult)
	{
		UpdateSpyResult(SkinUI::GetString(_T("IDS_SPY_TIPS")));
	}
}

LRESULT CMainDialog::OnCopyData(HWND hWnd, PCOPYDATASTRUCT pCopyDataStruct, BOOL& bHandle)
{
	bHandle = TRUE;
	if(!pCopyDataStruct)
	{
		return 0L;
	}

	if(pCopyDataStruct->cbData < 0)
	{
		return 0L;
	}

	if(pCopyDataStruct->dwData == COPYDATA_SPY_WINDOW)
	{
		CCopyDataPacketIn packet(pCopyDataStruct->lpData, pCopyDataStruct->cbData);
		tstring strResult = packet.UnPackWString();
		UpdateSpyResult(strResult);
		return 1L;
	}
	return 0L;
}

void CMainDialog::OnNcDestroy(BOOL& bHandle)
{
	bHandle = FALSE;
	PostQuitMessage(0);
}

void CMainDialog::UpdateSpyResult(const tstring& strResult)
{
	if(m_pTextView)
	{
		m_pTextView->SetText(strResult);
		m_pTextView->RedrawView();
	}
}