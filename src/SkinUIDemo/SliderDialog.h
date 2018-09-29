#pragma once

class CSliderDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_SLIDER1 = 101,
		IDC_BUTTON1 = 201,
	};

public:
	CSliderDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClickedAddPos(UINT uNotifyCode, int nID, CSkinView* pView);
	LRESULT OnSliderPosChange(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinSlider*	m_pSlider1;
};