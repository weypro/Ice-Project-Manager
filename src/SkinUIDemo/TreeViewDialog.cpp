#include "stdafx.h"
#include "TreeViewDialog.h"

CTreeViewDialog::CTreeViewDialog()
: CSkinDialog(_T("ControlDialog17.xml"))
{

}

static int nIndex = 1;
static BOOL bMale = FALSE;
void CTreeViewDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	CSkinTreeView* pTreeView = static_cast<CSkinTreeView*>(GetChildById(IDC_TREEVIEW1));
	if(pTreeView)
	{
		CSkinTreeItem* pRootItem = new CSkinTreeItem(pTreeView);
		if(pRootItem)
		{
			pRootItem->Expand(TRUE);
			pRootItem->SetLayoutHeight(30);
			pRootItem->SetLayout(_T("TreeItem.xml"));
			pRootItem->SetImage(_T("ListItem.png"));
			pRootItem->SetChildText(100002, _T("RootItem"));
			pTreeView->InsertItem(NULL, pRootItem);

			for(int j = 0; j < 3; ++j)
			{
				CSkinTreeItem* pTreeItem = new CSkinTreeItem(pTreeView);
				if(pTreeItem)
				{
					pTreeItem->SetLayoutHeight(30);
					pTreeItem->SetLayout(_T("TreeItem.xml"));
					pTreeItem->SetImage(_T("ListItem.png"));
					pTreeItem->SetChildText(100002, _T("TreeItem") + SkinUI::IntToString(j+1));
					pTreeView->InsertItem(pRootItem, pTreeItem);

					for(int k = 0; k < 5; ++k)
					{
						CSkinListItem* pListItem = new CSkinListItem(pTreeView);
						if(pListItem)
						{
							pListItem->SetLayoutHeight(30);
							pListItem->SetLayout(_T("ListItem.xml"));
							pListItem->SetImage(_T("ListItem.png"));
							pListItem->SetChildText(100001, _T("ListItem") + SkinUI::IntToString(k+1));

							CSkinView* pSkinView = pListItem->GetChildById(100001);
							if(pSkinView)
							{
								pSkinView->SetLayoutAlignParentLeft(10 + 16 * (pTreeItem->GetLevel() + 1));
							}
							pTreeView->InsertItem(pTreeItem, pListItem);
						}
					}
				}
			}
		}
	}

	pTreeView = static_cast<CSkinTreeView*>(GetChildById(IDC_TREEVIEW2));
	if(pTreeView)
	{
		CSkinTreeItem* pRootItem = new CSkinTreeItem(pTreeView);
		if(pRootItem)
		{
			pRootItem->Expand(TRUE);
			pRootItem->SetLayoutHeight(30);
			pRootItem->SetLayout(_T("TreeItem.xml"));
			pRootItem->SetImage(_T("ListItem.png"));
			pRootItem->SetChildText(100002, _T("公司名称"));
			pTreeView->InsertItem(NULL, pRootItem);

			for(int j = 0; j < 3; ++j)
			{
				CSkinTreeItem* pTreeItem = new CSkinTreeItem(pTreeView);
				if(pTreeItem)
				{
					pTreeItem->SetLayoutHeight(30);
					pTreeItem->SetLayout(_T("TreeItem.xml"));
					pTreeItem->SetImage(_T("ListItem.png"));
					pTreeItem->SetChildText(100002, _T("部门") + SkinUI::IntToString(j+1));
					pTreeView->InsertItem(pRootItem, pTreeItem);

					for(int k = 0; k < 5; ++k)
					{
						CSkinListItem* pListItem = new CSkinListItem(pTreeView);
						if(pListItem)
						{
							pListItem->SetLayoutHeight(30);
							pListItem->SetImage(_T("ListItem.png"));
							pListItem->SetLayout(_T("UserListItem.xml"));
							pListItem->SetChildImage(100001, bMale ? _T("Male.png") : _T("Female.png"));
							pListItem->SetChildText(100002, _T("成员") + SkinUI::IntToString(nIndex++));
							pListItem->SetChildText(100003, bMale ? _T("男") : _T("女"));

							CSkinView* pSkinView = *(pListItem->GetAllChild().begin());
							if(pSkinView)
							{
								pSkinView->SetLayoutAlignParentLeft(5 + 16 * (pTreeItem->GetLevel() + 1));
							}
							bMale = !bMale;
							pTreeView->InsertItem(pTreeItem, pListItem);
						}
					}
				}
			}
		}
	}
}