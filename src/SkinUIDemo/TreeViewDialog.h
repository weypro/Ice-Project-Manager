#pragma once

class CTreeViewDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_TREEVIEW1 = 101,
		IDC_TREEVIEW2 = 201,
	};

public:
	CTreeViewDialog();

public:
	virtual void OnInitDialog();
};