#pragma once

class CScrollBarDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_SCROLLBAR_VERT = 100,
		IDC_SCROLLBAR_HORZ = 200,
	};

public:
	CScrollBarDialog();

public:
	virtual void OnInitDialog();
	virtual void DrawBackground(HDC hdc);

protected:
	LRESULT OnInitDialogFinish(WPARAM wParam, LPARAM lParam);
	LRESULT OnMouseWheel(UINT nFlags, short zDelta, CPoint point, BOOL& bHandle);
	LRESULT OnVScroll(WPARAM wParam, LPARAM lParam);
	LRESULT OnHScroll(WPARAM wParam, LPARAM lParam);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CSkinScrollBar*		m_pScrollBarVert;
	CSkinScrollBar*		m_pScrollBarHorz;
};