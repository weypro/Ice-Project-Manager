#include "stdafx.h"
#include "MainDialog.h"
#include "AboutDialog.h"
#include "ScrollBarDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_WM_NCDESTROY()
	ON_SKINUI_MESSAGE(WM_SKINUI_COMBOBOX_SEL_CHANGE, OnComboBoxSelChange)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_SHOW1, OnBtnClickedLayoutShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_CODE1, OnBtnClickedLayoutCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_SHOW2, OnBtnClickedLayoutShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_CODE2, OnBtnClickedLayoutCode2)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_SHOW3, OnBtnClickedLayoutShow3)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_CODE3, OnBtnClickedLayoutCode3)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_SHOW4, OnBtnClickedLayoutShow4)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_CODE4, OnBtnClickedLayoutCode4)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_SHOW5, OnBtnClickedLayoutShow5)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_CODE5, OnBtnClickedLayoutCode5)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_SHOW6, OnBtnClickedLayoutShow6)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_CODE6, OnBtnClickedLayoutCode6)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_SHOW7, OnBtnClickedLayoutShow7)
	ON_SKINUI_COMMAND(IDC_BUTTON_LAYOUT_CODE7, OnBtnClickedLayoutCode7)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW1, OnBtnClickedViewShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE1, OnBtnClickedViewCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW2, OnBtnClickedViewShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE2, OnBtnClickedViewCode2)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW3, OnBtnClickedViewShow3)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE3, OnBtnClickedViewCode3)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW4, OnBtnClickedViewShow4)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE4, OnBtnClickedViewCode4)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW5, OnBtnClickedViewShow5)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE5, OnBtnClickedViewCode5)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW6, OnBtnClickedViewShow6)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE6, OnBtnClickedViewCode6)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW7, OnBtnClickedViewShow7)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE7, OnBtnClickedViewCode7)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW8, OnBtnClickedViewShow8)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE8, OnBtnClickedViewCode8)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW9, OnBtnClickedViewShow9)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE9, OnBtnClickedViewCode9)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW10, OnBtnClickedViewShow10)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE10, OnBtnClickedViewCode10)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW11, OnBtnClickedViewShow11)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE11, OnBtnClickedViewCode11)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW12, OnBtnClickedViewShow12)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE12, OnBtnClickedViewCode12)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW13, OnBtnClickedViewShow13)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE13, OnBtnClickedViewCode13)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW14, OnBtnClickedViewShow14)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE14, OnBtnClickedViewCode14)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW15, OnBtnClickedViewShow15)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE15, OnBtnClickedViewCode15)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW16, OnBtnClickedViewShow16)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE16, OnBtnClickedViewCode16)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW17, OnBtnClickedViewShow17)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE17, OnBtnClickedViewCode17)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW18, OnBtnClickedViewShow18)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE18, OnBtnClickedViewCode18)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW19, OnBtnClickedViewShow19)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE19, OnBtnClickedViewCode19)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_SHOW20, OnBtnClickedViewShow20)
	ON_SKINUI_COMMAND(IDC_BUTTON_CONTROL_CODE20, OnBtnClickedViewCode20)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW11, OnBtnClickedComponentShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW12, OnBtnClickedComponentShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW13, OnBtnClickedComponentShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW14, OnBtnClickedComponentShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW15, OnBtnClickedComponentShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW2, OnBtnClickedComponentShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW3, OnBtnClickedComponentShow3)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW4, OnBtnClickedComponentShow4)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW5, OnBtnClickedComponentShow5)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW6, OnBtnClickedComponentShow6)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW7, OnBtnClickedComponentShow7)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW8, OnBtnClickedComponentShow8)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW9, OnBtnClickedComponentShow9)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW10, OnBtnClickedComponentShow10)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_COMPONENT_SHOW111, OnBtnClickedComponentShow11)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_SHOW1, OnBtnClickedDialogShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_SHOW2, OnBtnClickedDialogShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_SHOW3, OnBtnClickedDialogShow3)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_SHOW4, OnBtnClickedDialogShow4)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_SHOW5, OnBtnClickedDialogShow5)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW11, OnBtnClickedDialogAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE11, OnBtnClickedDialogAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW12,OnBtnClickedDialogAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE12,OnBtnClickedDialogAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW13,OnBtnClickedDialogAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE13,OnBtnClickedDialogAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW14,OnBtnClickedDialogAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE14,OnBtnClickedDialogAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW15,OnBtnClickedDialogAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE15,OnBtnClickedDialogAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW21, OnBtnClickedDialogAnimationShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE21, OnBtnClickedDialogAnimationCode2)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW22,OnBtnClickedDialogAnimationShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE22,OnBtnClickedDialogAnimationCode2)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW23,OnBtnClickedDialogAnimationShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE23,OnBtnClickedDialogAnimationCode2)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW31, OnBtnClickedDialogAnimationShow3)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE31, OnBtnClickedDialogAnimationCode3)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW32,OnBtnClickedDialogAnimationShow3)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE32,OnBtnClickedDialogAnimationCode3)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_SHOW33,OnBtnClickedDialogAnimationShow3)
	ON_SKINUI_COMMAND(IDC_BUTTON_DIALOG_ANIMATION_CODE33,OnBtnClickedDialogAnimationCode3)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_ANIMATION_SHOW1, OnBtnClickedSwitchAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_ANIMATION_CODE1, OnBtnClickedSwitchAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_ANIMATION_SHOW2, OnBtnClickedSwitchAnimationShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_SWITCH_ANIMATION_CODE2, OnBtnClickedSwitchAnimationCode2)
	ON_SKINUI_COMMAND(IDC_BUTTON_SLIDE_ANIMATION_SHOW1, OnBtnClickedSlideAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_SLIDE_ANIMATION_CODE1, OnBtnClickedSlideAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_HIDE_ANIMATION_SHOW1, OnBtnClickedHideAnimationShow1)
	ON_SKINUI_COMMAND(IDC_BUTTON_HIDE_ANIMATION_CODE1, OnBtnClickedHideAnimationCode1)
	ON_SKINUI_COMMAND(IDC_BUTTON_HIDE_ANIMATION_SHOW2, OnBtnClickedHideAnimationShow2)
	ON_SKINUI_COMMAND(IDC_BUTTON_HIDE_ANIMATION_CODE2, OnBtnClickedHideAnimationCode2)
	ON_SKINUI_COMMAND(IDC_BUTTON_FLASH_TRAY_ICON, OnBtnClickedFlashTrayIcon)
	ON_SKINUI_COMMAND(MENU_OFFICIAL_WEBSITE, OnMenuCommandOfficialWebsite)
	ON_SKINUI_COMMAND(MENU_OFFICIAL_BLOG, OnMenuCommandOfficialBlog)
	ON_SKINUI_COMMAND(MENU_DOWNLOAD_CENTER, OnMenuCommandDownloadCenter)
	ON_SKINUI_COMMAND(MENU_ABOUT, OnMenuCommandAbout)
SKINUI_END_MESSAGE_MAP()

CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
, m_pComboBoxFontSize(NULL)
, m_pComboBoxLanguage(NULL)
{

}

void CMainDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();

	m_pComboBoxLanguage = static_cast<CSkinComboBox*>(GetChildById(IDC_COMBOBOX_LANGUAGE));
	if (m_pComboBoxLanguage)
	{
		tstring strLanguage = _T("2052");
		SkinUI::GetAppConfig(APP_CONFIG_STRING_LANGUAGE, strLanguage);
		LONG nCurSel = 0;
		if (strLanguage == _T("1028"))
		{
			nCurSel = 1;
		}
		else if (strLanguage == _T("1033"))
		{
			nCurSel = 2;
		}
		m_pComboBoxLanguage->SetCurSel(nCurSel);
	}

	m_pComboBoxFontSize = static_cast<CSkinComboBox*>(GetChildById(IDC_COMBOBOX_FONT_SIZE));
	if (m_pComboBoxFontSize)
	{
		LONG nFontSize = 0;
		SkinUI::GetAppConfig(APP_CONFIG_FONT_SIZE_CHANGE, nFontSize);
		m_pComboBoxFontSize->SetCurSel(nFontSize / 2);
	}
}

void CMainDialog::OnBtnClickedLayoutShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("LayoutDialog1.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedLayoutCode1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("LayoutDialog1.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedLayoutShow2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("LayoutDialog2.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedLayoutCode2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("LayoutDialog2.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedLayoutShow3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("LayoutDialog3.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedLayoutCode3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("LayoutDialog3.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedLayoutShow4(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("LayoutDialog4.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedLayoutCode4(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("LayoutDialog4.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedLayoutShow5(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("LayoutDialog5.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedLayoutCode5(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("LayoutDialog5.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedLayoutShow6(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("LayoutDialog6.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedLayoutCode6(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("LayoutDialog6.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedLayoutShow7(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("LayoutDialog7.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedLayoutCode7(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("LayoutDialog7.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedViewShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("ControlDialog1.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog1.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedViewShow2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("ControlDialog2.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog2.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "HyperlinkDialog.h"
void CMainDialog::OnBtnClickedViewShow3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CHyperlinkDialog dlg(_T("ControlDialog3.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog3.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "ImageViewDialog.h"
void CMainDialog::OnBtnClickedViewShow4(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CImageViewDialog dlg(_T("ControlDialog4.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode4(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog4.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "ButtonDialog.h"
void CMainDialog::OnBtnClickedViewShow5(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CButtonDialog dlg(_T("ControlDialog5.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode5(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog5.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "CheckBoxDialog.h"
void CMainDialog::OnBtnClickedViewShow6(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CCheckBoxDialog dlg(_T("ControlDialog6.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode6(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog6.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "RadioButtonDialog.h"
void CMainDialog::OnBtnClickedViewShow7(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CRadioButtonDialog dlg(_T("ControlDialog7.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode7(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog7.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "EditViewDialog.h"
void CMainDialog::OnBtnClickedViewShow8(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CEditViewDialog dlg(_T("ControlDialog8.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode8(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog8.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "ComboBoxDialog.h"
void CMainDialog::OnBtnClickedViewShow9(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CComboBoxDialog dlg(_T("ControlDialog9.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode9(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog9.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedViewShow10(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CScrollBarDialog dlg;
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode10(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog10.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "ProgressDialog.h"
void CMainDialog::OnBtnClickedViewShow11(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CProgressDialog dlg(_T("ControlDialog11.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode11(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog11.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedViewShow12(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("ControlDialog12.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode12(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog12.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "SliderDialog.h"
void CMainDialog::OnBtnClickedViewShow13(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSliderDialog dlg(_T("ControlDialog13.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode13(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog13.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "DateViewDialog.h"
void CMainDialog::OnBtnClickedViewShow14(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CDateViewDialog dlg(_T("ControlDialog14.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode14(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog14.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "TimeViewDialog.h"
void CMainDialog::OnBtnClickedViewShow15(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CTimeViewDialog dlg(_T("ControlDialog15.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode15(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog15.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "ListViewDialog.h"
void CMainDialog::OnBtnClickedViewShow16(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CListViewDialog dlg(_T("ControlDialog16.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode16(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog16.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "TreeViewDialog.h"
void CMainDialog::OnBtnClickedViewShow17(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CTreeViewDialog dlg;
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode17(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog17.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "GridViewDialog.h"
void CMainDialog::OnBtnClickedViewShow18(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CGridViewDialog dlg(_T("ControlDialog18.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode18(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog18.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "IEWebDialog.h"
void CMainDialog::OnBtnClickedViewShow19(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CIEWebDialog dlg(_T("ControlDialog19.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode19(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog19.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "CefWebDialog.h"
void CMainDialog::OnBtnClickedViewShow20(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CCefWebDialog dlg(_T("ControlDialog20.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedViewCode20(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("ControlDialog20.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedComponentShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (pView)
	{
		CRect rect = pView->GetRect();
		CPoint ptOffset = pView->GetScrollOffset(CRect());
		CPoint pt(rect.left - ptOffset.x, rect.bottom - ptOffset.y);
		pView->GetOwner()->ClientToScreen(pt);

		PopupDirection direction = PD_UNKNOWN;
		if (nID == IDC_BUTTON_SWITCH_COMPONENT_SHOW12)
		{
			direction = PD_LEFT_TOP;
		}
		else if (nID == IDC_BUTTON_SWITCH_COMPONENT_SHOW13)
		{
			direction = PD_RIGHT_TOP;
		}
		else if (nID == IDC_BUTTON_SWITCH_COMPONENT_SHOW14)
		{
			direction = PD_LEFT_BOTTOM;
		}
		else if (nID == IDC_BUTTON_SWITCH_COMPONENT_SHOW15)
		{
			direction = PD_RIGHT_BOTTOM;
		}
		PopupMenu(_T("MainMenu.xml"), pt, rect.Size(), this, direction);
	}
}

void CMainDialog::OnBtnClickedComponentShow2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	MsgBox(SkinUI::GetString(_T("IDS_CONTROL_SHOW_TEXT23")));
}

void CMainDialog::OnBtnClickedComponentShow3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	MsgBoxModeless(SkinUI::GetString(_T("IDS_CONTROL_SHOW_TEXT24")));
}

void CMainDialog::OnBtnClickedComponentShow4(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strTitle = _T("提示");
	tstring strMessage = _T("这是一个提示信息！");
	tstring strButtonName = _T("确定");
	int nButtonIndex = Alert(strMessage, strTitle, strButtonName);
}

void CMainDialog::OnBtnClickedComponentShow5(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strTitle = _T("提示");
	tstring strMessage = _T("有没有收到我的消息？");
	tstring strButtonOK = _T("收到");
	tstring strButtonCancel = _T("没有");
	int nButtonIndex = Confirm(strMessage, strTitle, strButtonOK, strButtonCancel);
}

void CMainDialog::OnBtnClickedComponentShow6(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strTitle = _T("提示");
	tstring strMessage = _T("有没有收到我的消息？");
	tstring strButtonOK = _T("收到");
	tstring strButtonCancel = _T("没有");

	tstring strEditText;
	int nButtonIndex = GetOwner()->Prompt(strEditText, strMessage, strTitle, strButtonOK, strButtonCancel);
}

void CMainDialog::OnBtnClickedComponentShow7(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strTitle = _T("谁最屌？");
	tstring strButtonCancel = _T("取消");

	list<tstring> lstSheet;
	lstSheet.push_back(_T("孙悟空"));
	lstSheet.push_back(_T("猪八戒"));
	lstSheet.push_back(_T("唐僧"));
	lstSheet.push_back(_T("沙和尚"));
	int nButtonIndex = GetOwner()->ActionSheet(lstSheet, strTitle, strButtonCancel);
}

void CMainDialog::OnBtnClickedComponentShow8(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strText = _T("这是一个提示信息！");
	int nIcon = TOAST_ICON_SUCCESS;
	int nDuration = 5;
	int nDelay = 0;
	Toast(strText, nIcon, nDuration, nDelay);
}

void CMainDialog::OnBtnClickedComponentShow9(UINT uNotifyCode, int nID, CSkinView* pView)
{
	int nDuration = 2;
	ShakeWindow(nDuration);
}

void CMainDialog::OnBtnClickedComponentShow10(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strText = SkinUI::GetString(_T("IDS_LOADING"));
	ShowLoading(pView, GetRect());
}

void CMainDialog::OnBtnClickedComponentShow11(UINT uNotifyCode, int nID, CSkinView* pView)
{
	HideLoading();
}

void CMainDialog::OnBtnClickedDialogShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinColorDialog dlg(Color::Red, CC_FULLOPEN | CC_RGBINIT);
	if(dlg.DoModal(m_hWnd) == IDOK)
	{
		Color color = dlg.GetColor();
	}
}

void CMainDialog::OnBtnClickedDialogShow2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinFileDialog dlg(SkinUI::GetString(_T("IDS_SEL_FILE")), s_lpstrAllFileFilter, 5, TRUE);
	if(dlg.DoModal(m_hWnd) == IDOK)
	{
		const list<tstring>& lstFile = dlg.GetFile();
	}
}

void CMainDialog::OnBtnClickedDialogShow3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinFolderDialog dlg(SkinUI::GetString(_T("IDS_SEL_FOLDER")), TRUE);
	if(dlg.DoModal(m_hWnd) == IDOK)
	{
		tstring strFolder = dlg.GetFolder();
	}
}

void CMainDialog::OnBtnClickedDialogShow4(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinSaveAsDialog dlg(_T("123.txt"), s_lpstrAllFileFilter);
	if(dlg.DoModal(m_hWnd) == IDOK)
	{
		tstring strFolder = dlg.GetFile();
	}
}

void CMainDialog::OnBtnClickedDialogShow5(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinPicSaveAsDialog dlg(_T("123.gif"));
	if (dlg.DoModal(m_hWnd) == IDOK)
	{
		tstring strFolder = dlg.GetFile();
	}
}

void CMainDialog::OnBtnClickedDialogAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(SkinUI::StringFormat(_T("DialogAnimationDialog%d.xml"), nID - IDC_BUTTON_DIALOG_ANIMATION_SHOW11 + 11));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedDialogAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + SkinUI::StringFormat(_T("DialogAnimationDialog%d.xml"),nID - IDC_BUTTON_DIALOG_ANIMATION_CODE11 + 11);
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedDialogAnimationShow2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(SkinUI::StringFormat(_T("DialogAnimationDialog%d.xml"),nID - IDC_BUTTON_DIALOG_ANIMATION_SHOW21 + 21));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedDialogAnimationCode2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + SkinUI::StringFormat(_T("DialogAnimationDialog%d.xml"),nID - IDC_BUTTON_DIALOG_ANIMATION_CODE21 + 21);
	::ShellExecute(m_hWnd,_T("open"),strPath.c_str(),NULL,NULL,SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedDialogAnimationShow3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(SkinUI::StringFormat(_T("DialogAnimationDialog%d.xml"),nID - IDC_BUTTON_DIALOG_ANIMATION_SHOW31 + 31));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedDialogAnimationCode3(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + SkinUI::StringFormat(_T("DialogAnimationDialog%d.xml"),nID - IDC_BUTTON_DIALOG_ANIMATION_CODE31 + 31);
	::ShellExecute(m_hWnd,_T("open"),strPath.c_str(),NULL,NULL,SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedSwitchAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("SwitchAnimationDialog1.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedSwitchAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("SwitchAnimationDialog1.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedSwitchAnimationShow2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinDialog dlg(_T("SwitchAnimationDialog2.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedSwitchAnimationCode2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("SwitchAnimationDialog2.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "SlideAnimationDialog.h"
void CMainDialog::OnBtnClickedSlideAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSlideAnimationDialog dlg(_T("SlideAnimationDialog1.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedSlideAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("SlideAnimationDialog1.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#include "HideAnimationDialog.h"
void CMainDialog::OnBtnClickedHideAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CHideAnimationDialog dlg(_T("HideAnimationDialog1.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedHideAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("HideAnimationDialog1.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedHideAnimationShow2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CHideAnimationDialog dlg(_T("HideAnimationDialog2.xml"));
	dlg.DoModal(m_hWnd);
}

void CMainDialog::OnBtnClickedHideAnimationCode2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strPath = GetCurModulePath() + _T("res\\SkinUIDemo\\layout\\") + _T("HideAnimationDialog2.xml");
	::ShellExecute(m_hWnd, _T("open"), strPath.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnBtnClickedFlashTrayIcon(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSkinView* pChildView = pView->GetChildById(100001);
	if(pChildView)
	{
		tstring strFlash = SkinUI::GetString(_T("IDS_FLASH_TRAY_ICON"));
		tstring strStopFlash = SkinUI::GetString(_T("IDS_STOP_FLASH_TRAY_ICON"));
		if(pChildView->GetText() == strFlash)
		{
			FlashTrayIcon(TRUE);
			pChildView->SetText(strStopFlash);
			pView->RedrawView();
		}
		else if(pChildView->GetText() == strStopFlash)
		{
			FlashTrayIcon(FALSE);
			pChildView->SetText(strFlash);
			pView->RedrawView();
		}
		else
		{
			assert(false);
		}
	}
}

void CMainDialog::OnMenuCommandOfficialWebsite(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strUrl = _T("http://www.skinui.cn");
	::ShellExecute(m_hWnd, _T("open"), strUrl.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnMenuCommandOfficialBlog(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strUrl = _T("http://www.jianshu.com/users/cd916ef6f0b1/latest_articles");
	::ShellExecute(m_hWnd, _T("open"), strUrl.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnMenuCommandDownloadCenter(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strUrl = _T("https://pan.baidu.com/share/home?uk=2383425913#category/type=0");
	::ShellExecute(m_hWnd, _T("open"), strUrl.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void CMainDialog::OnMenuCommandAbout(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CAboutDialog dlg;
	dlg.DoModal(m_hWnd);
}

LRESULT CMainDialog::OnComboBoxSelChange(WPARAM wParam, LPARAM lParam)
{
	LONG nId = wParam;
	if (nId == IDC_COMBOBOX_FONT_SIZE)
	{
		if (m_pComboBoxFontSize)
		{
			UINT nFontSize = m_pComboBoxFontSize->GetCurSel();
			SkinUI::ChangeFontSize(nFontSize * 2);
		}
	}
	else if (nId == IDC_COMBOBOX_LANGUAGE)
	{
		if (m_pComboBoxLanguage)
		{
			UINT nCurSel = m_pComboBoxLanguage->GetCurSel();
			tstring strLanguage = _T("2052");
			if (nCurSel == 1)
			{
				strLanguage = _T("1028");
			}
			else if (nCurSel == 2)
			{
				strLanguage = _T("1033");
			}
			SkinUI::SetAppConfig(APP_CONFIG_STRING_LANGUAGE, strLanguage);
		}
	}
	return 1L;
}

void CMainDialog::OnNcDestroy(BOOL& bHandle)
{
	bHandle = FALSE;
	PostQuitMessage(0);
}