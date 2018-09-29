#pragma once

#include "FolderItem.h"
class CMainDialog : public CSkinDialog
{
public:
	CMainDialog();

	enum
	{
		IDC_LISTVIEW1 = 101,
		IDC_LISTVIEW2 = 102,
		IDC_FOLDERLISTITEM = 111,
		IDC_ADDFOLDERBUTTON = 201,
		IDC_ADDPROJECTBUTTON = 202,
		IDC_OPENPROJECTBUTTON = 301,
		IDC_DELETEFOLDERBUTTON = 401,
		IDC_DELETEPROJECTBUTTON = 402,
		MENU_ABOUT = 1003,
	};


public:
	virtual void OnInitDialog();
private:
	CSkinListView*    m_pListView1;//类型listview
	CSkinListView*    m_pListView2;//项目listview
	CIceItemCtrl	  m_IceItemCtrl;//文件夹item控制

	void AddNewItemToListView(UINT ID, const tstring strName);
protected:
	void OnNcDestroy(BOOL& bHandle);
	void OnMenuCommandAbout(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnFolderListItemClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedAddFolder(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedAddProject(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedOpenProject(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDeleteFolder(UINT uNotifyCode, int nID, CSkinView* pView);
	void OnBtnClickedDeleteProject(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()
};
