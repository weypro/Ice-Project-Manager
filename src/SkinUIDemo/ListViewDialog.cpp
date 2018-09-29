#include "stdafx.h"
#include "ListViewDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CListViewDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON1, OnBtnClickedAddItem1)
	ON_SKINUI_COMMAND(IDC_BUTTON2, OnBtnClickedAddItem2)
SKINUI_END_MESSAGE_MAP()

CListViewDialog::CListViewDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pListView1(NULL)
, m_pListView2(NULL)
{

}

void CListViewDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	m_pListView1 = static_cast<CSkinListView*>(GetChildById(IDC_LISTVIEW1));
	m_pListView2 = static_cast<CSkinListView*>(GetChildById(IDC_LISTVIEW2));
}

static int nIndex1 = 6;
void CListViewDialog::OnBtnClickedAddItem1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pListView1)
	{
		CSkinListItem* pListItem = new CSkinListItem(m_pListView1);
		if(pListItem)
		{
			pListItem->SetLayoutHeight(30);
			pListItem->SetImage(_T("ListItem.png"));
			pListItem->SetLayout(_T("ListItem.xml"));
			pListItem->SetChildText(100001, _T("SkinListItem") + SkinUI::IntToString(nIndex1++));
		}
		m_pListView1->ResetScrollInfo();
		m_pListView1->ScrollBottom();
		m_pListView1->RedrawView();
	}
}

static int nIndex2 = 6;
static BOOL bMale = FALSE;
void CListViewDialog::OnBtnClickedAddItem2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pListView2)
	{
		CSkinListItem* pListItem = new CSkinListItem(m_pListView2);
		if(pListItem)
		{
			pListItem->SetLayoutHeight(30);
			pListItem->SetImage(_T("ListItem.png"));
			pListItem->SetLayout(_T("UserListItem.xml"));
			pListItem->SetChildImage(100001, bMale ? _T("Male.png") : _T("Female.png"));
			pListItem->SetChildText(100002, _T("ÐÕÃû") + SkinUI::IntToString(nIndex2++));
			pListItem->SetChildText(100003, bMale ? _T("ÄÐ") : _T("Å®"));
			bMale = !bMale;
		}
		m_pListView2->ResetScrollInfo();
		m_pListView2->ScrollBottom();
		m_pListView2->RedrawView();
	}
}