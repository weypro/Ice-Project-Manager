#pragma once

class CMainDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_BUTTON_LAYOUT_SHOW1 = 11011,
		IDC_BUTTON_LAYOUT_CODE1 = 11012,
		IDC_BUTTON_LAYOUT_SHOW2 = 11021,
		IDC_BUTTON_LAYOUT_CODE2 = 11022,
		IDC_BUTTON_LAYOUT_SHOW3 = 11031,
		IDC_BUTTON_LAYOUT_CODE3 = 11032,
		IDC_BUTTON_LAYOUT_SHOW4 = 11041,
		IDC_BUTTON_LAYOUT_CODE4 = 11042,
		IDC_BUTTON_LAYOUT_SHOW5 = 11051,
		IDC_BUTTON_LAYOUT_CODE5 = 11052,
		IDC_BUTTON_LAYOUT_SHOW6 = 11061,
		IDC_BUTTON_LAYOUT_CODE6 = 11062,
		IDC_BUTTON_LAYOUT_SHOW7 = 11071,
		IDC_BUTTON_LAYOUT_CODE7 = 11072,
		IDC_BUTTON_CONTROL_SHOW1 = 12011,
		IDC_BUTTON_CONTROL_CODE1 = 12012,
		IDC_BUTTON_CONTROL_SHOW2 = 12021,
		IDC_BUTTON_CONTROL_CODE2 = 12022,
		IDC_BUTTON_CONTROL_SHOW3 = 12031,
		IDC_BUTTON_CONTROL_CODE3 = 12032,
		IDC_BUTTON_CONTROL_SHOW4 = 12041,
		IDC_BUTTON_CONTROL_CODE4 = 12042,
		IDC_BUTTON_CONTROL_SHOW5 = 12051,
		IDC_BUTTON_CONTROL_CODE5 = 12052,
		IDC_BUTTON_CONTROL_SHOW6 = 12061,
		IDC_BUTTON_CONTROL_CODE6 = 12062,
		IDC_BUTTON_CONTROL_SHOW7 = 12071,
		IDC_BUTTON_CONTROL_CODE7 = 12072,
		IDC_BUTTON_CONTROL_SHOW8 = 12081,
		IDC_BUTTON_CONTROL_CODE8 = 12082,
		IDC_BUTTON_CONTROL_SHOW9 = 12091,
		IDC_BUTTON_CONTROL_CODE9 = 12092,
		IDC_BUTTON_CONTROL_SHOW10 = 12101,
		IDC_BUTTON_CONTROL_CODE10 = 12102,
		IDC_BUTTON_CONTROL_SHOW11 = 12111,
		IDC_BUTTON_CONTROL_CODE11 = 12112,
		IDC_BUTTON_CONTROL_SHOW12 = 12121,
		IDC_BUTTON_CONTROL_CODE12 = 12122,
		IDC_BUTTON_CONTROL_SHOW13 = 12131,
		IDC_BUTTON_CONTROL_CODE13 = 12132,
		IDC_BUTTON_CONTROL_SHOW14 = 12141,
		IDC_BUTTON_CONTROL_CODE14 = 12142,
		IDC_BUTTON_CONTROL_SHOW15 = 12151,
		IDC_BUTTON_CONTROL_CODE15 = 12152,
		IDC_BUTTON_CONTROL_SHOW16 = 12161,
		IDC_BUTTON_CONTROL_CODE16 = 12162,
		IDC_BUTTON_CONTROL_SHOW17 = 12171,
		IDC_BUTTON_CONTROL_CODE17 = 12172,
		IDC_BUTTON_CONTROL_SHOW18 = 12181,
		IDC_BUTTON_CONTROL_CODE18 = 12182,
		IDC_BUTTON_CONTROL_SHOW19 = 12191,
		IDC_BUTTON_CONTROL_CODE19 = 12192,
		IDC_BUTTON_CONTROL_SHOW20 = 12201,
		IDC_BUTTON_CONTROL_CODE20 = 12202,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW11 = 13011,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW12 = 13012,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW13 = 13013,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW14 = 13014,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW15 = 13015,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW2 = 13021,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW3 = 13031,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW4 = 13041,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW5 = 13051,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW6 = 13061,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW7 = 13071,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW8 = 13081,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW9 = 13091,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW10 = 13101,
		IDC_BUTTON_SWITCH_COMPONENT_SHOW111 = 13111,
		IDC_BUTTON_DIALOG_SHOW1 = 14011,
		IDC_BUTTON_DIALOG_SHOW2 = 14021,
		IDC_BUTTON_DIALOG_SHOW3 = 14031,
		IDC_BUTTON_DIALOG_SHOW4 = 14041,
		IDC_BUTTON_DIALOG_SHOW5 = 14051,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW11 = 15011,
		IDC_BUTTON_DIALOG_ANIMATION_CODE11 = 15021,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW12 = 15012,
		IDC_BUTTON_DIALOG_ANIMATION_CODE12 = 15022,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW13 = 15013,
		IDC_BUTTON_DIALOG_ANIMATION_CODE13 = 15023,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW14 = 15014,
		IDC_BUTTON_DIALOG_ANIMATION_CODE14 = 15024,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW15 = 15015,
		IDC_BUTTON_DIALOG_ANIMATION_CODE15 = 15025,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW21 = 15031,
		IDC_BUTTON_DIALOG_ANIMATION_CODE21 = 15041,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW22 = 15032,
		IDC_BUTTON_DIALOG_ANIMATION_CODE22 = 15042,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW23 = 15033,
		IDC_BUTTON_DIALOG_ANIMATION_CODE23 = 15043,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW31 = 15051,
		IDC_BUTTON_DIALOG_ANIMATION_CODE31 = 15061,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW32 = 15052,
		IDC_BUTTON_DIALOG_ANIMATION_CODE32 = 15062,
		IDC_BUTTON_DIALOG_ANIMATION_SHOW33 = 15053,
		IDC_BUTTON_DIALOG_ANIMATION_CODE33 = 15063,
		IDC_BUTTON_SWITCH_ANIMATION_SHOW1 = 15071,
		IDC_BUTTON_SWITCH_ANIMATION_CODE1 = 15072,
		IDC_BUTTON_SWITCH_ANIMATION_SHOW2 = 15081,
		IDC_BUTTON_SWITCH_ANIMATION_CODE2 = 15082,
		IDC_BUTTON_SLIDE_ANIMATION_SHOW1 = 15091,
		IDC_BUTTON_SLIDE_ANIMATION_CODE1 = 15092,
		IDC_BUTTON_HIDE_ANIMATION_SHOW1 = 15101,
		IDC_BUTTON_HIDE_ANIMATION_CODE1 = 15102,
		IDC_BUTTON_HIDE_ANIMATION_SHOW2 = 15111,
		IDC_BUTTON_HIDE_ANIMATION_CODE2 = 15112,
		IDC_BUTTON_FLASH_TRAY_ICON = 16011,
		IDC_COMBOBOX_LANGUAGE = 16021,
		IDC_COMBOBOX_FONT_SIZE = 16031,
	};

	enum
	{
		MENU_OFFICIAL_WEBSITE = 1000,
		MENU_OFFICIAL_BLOG = 1001,
		MENU_DOWNLOAD_CENTER = 1002,
		MENU_ABOUT = 1003,
	};

public:
	CMainDialog();

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedLayoutShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLayoutCode1(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedLayoutShow2(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLayoutCode2(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedLayoutShow3(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLayoutCode3(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedLayoutShow4(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLayoutCode4(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedLayoutShow5(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLayoutCode5(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedLayoutShow6(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLayoutCode6(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedLayoutShow7(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedLayoutCode7(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedViewShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode1(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow2(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode2(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow3(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode3(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow4(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode4(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow5(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode5(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow6(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode6(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow7(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode7(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow8(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode8(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow9(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode9(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow10(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode10(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow11(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode11(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow12(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode12(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow13(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode13(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow14(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode14(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow15(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode15(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow16(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode16(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow17(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode17(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow18(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode18(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow19(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode19(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedViewShow20(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedViewCode20(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedComponentShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow2(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow3(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow4(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow5(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow6(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow7(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow8(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow9(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow10(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedComponentShow11(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedDialogShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDialogShow2(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDialogShow3(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDialogShow4(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDialogShow5(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedDialogAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDialogAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedDialogAnimationShow2(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDialogAnimationCode2(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedDialogAnimationShow3(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDialogAnimationCode3(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedSwitchAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedSwitchAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView);

	void OnBtnClickedSwitchAnimationShow2(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedSwitchAnimationCode2(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedSlideAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedSlideAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedHideAnimationShow1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedHideAnimationCode1(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedHideAnimationShow2(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedHideAnimationCode2(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnBtnClickedFlashTrayIcon(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnMenuCommandOfficialWebsite(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnMenuCommandOfficialBlog(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnMenuCommandDownloadCenter(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnMenuCommandAbout(UINT uNotifyCode, int nID, CSkinView* pView);

protected:
	void OnNcDestroy(BOOL& bHandle);
	LRESULT OnComboBoxSelChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinComboBox*			m_pComboBoxFontSize;
	CSkinComboBox*			m_pComboBoxLanguage;
};