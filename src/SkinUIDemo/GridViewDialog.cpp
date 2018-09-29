#include "stdafx.h"
#include "GridViewDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CGridViewDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON1, OnBtnClickedAddItem1)
	ON_SKINUI_COMMAND(IDC_BUTTON2, OnBtnClickedAddItem2)
SKINUI_END_MESSAGE_MAP()

CGridViewDialog::CGridViewDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pGridView1(NULL)
, m_pGridView2(NULL)
{

}

void CGridViewDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	m_pGridView1 = static_cast<CSkinGridView*>(GetChildById(IDC_GRIDVIEW1));
	m_pGridView2 = static_cast<CSkinGridView*>(GetChildById(IDC_GRIDVIEW2));
}

static int nIndex1 = 6;
void CGridViewDialog::OnBtnClickedAddItem1(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pGridView1)
	{
		CSkinListItem* pListItem = new CSkinListItem(m_pGridView1);
		if(pListItem)
		{
			pListItem->SetLayoutHeight(30);
			pListItem->SetImage(_T("ListItem.png"));
			pListItem->SetLayout(_T("ListItem.xml"));
			pListItem->SetChildText(100001, _T("Item") + SkinUI::IntToString(nIndex1++));
		}
		m_pGridView1->ResetScrollInfo();
		m_pGridView1->ScrollBottom();
		m_pGridView1->RedrawView();
	}
}

static int nIndex2 = 6;
static BOOL bMale = FALSE;
void CGridViewDialog::OnBtnClickedAddItem2(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pGridView2)
	{
		CSkinListItem* pListItem = new CSkinListItem(m_pGridView2);
		if(pListItem)
		{
			pListItem->SetLayoutHeight(30);
			pListItem->SetImage(_T("ListItem.png"));
			pListItem->SetLayout(_T("UserListItem2.xml"));
			pListItem->SetChildImage(100001, bMale ? _T("Male.png") : _T("Female.png"));
			pListItem->SetChildText(100002, _T("ÐÕÃû") + SkinUI::IntToString(nIndex2++));
			bMale = !bMale;
		}
		m_pGridView2->ResetScrollInfo();
		m_pGridView2->ScrollBottom();
		m_pGridView2->RedrawView();
	}
}