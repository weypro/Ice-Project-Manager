#pragma once

class CUserInfoDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_LAYOUT_INFO = 40000,
	};

private:
	CUserInfoDialog(uint64 nUserId);
	~CUserInfoDialog();

private:
	static map<uint64, CUserInfoDialog*> s_mapInst;

public:
	static void Show(HWND hParentWnd, uint64 nUserId);

public:
	virtual void OnInitDialog();

private:
	uint64 m_nUserId;
};