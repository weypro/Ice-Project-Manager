#include "stdafx.h"
#include "SelectUserDialog.h"
#include "AddressBookView.h"

SKINUI_BEGIN_MESSAGE_MAP(CSelectUserDialog, CSkinDialog)
	ON_SKINUI_MESSAGE(WM_SKINUI_CHECKBOX_STATE_CHANGE, OnCheckBoxStateChange)
	ON_SKINUI_UPDATE_COMMAND_UI(IDOK, OnUpdateCommandOK)
SKINUI_END_MESSAGE_MAP()

CSelectUserDialog::CSelectUserDialog(const tstring& strCaption, uint32 nMaxCount)
: CSkinDialog(_T("SelectUserDialog.xml"))
, m_nMaxCount(nMaxCount)
, m_strCaption(strCaption)
, m_pTreeViewCorp(NULL)
, m_pTextViewSelected(NULL)
, m_pListViewSelected(NULL)
{

}

void CSelectUserDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();

	m_pTreeViewCorp = static_cast<CCorpTreeView*>(GetChildById(IDC_TREEVIEW));
	if(m_pTreeViewCorp)
	{
		m_pTreeViewCorp->Load(_T("SelectUserItem.xml"), _T("SelectDeptItem.xml"));
	}

	m_pTextViewSelected = static_cast<CSkinTextView*>(GetChildById(IDC_TEXTVIEW));
	m_pListViewSelected = static_cast<CSelectedListView*>(GetChildById(IDC_LISTVIEW));
	UpdateSelectedCount();

	if(!m_strCaption.empty())
	{
		SetTitleCaption(SkinUI::GetString(m_strCaption));
	}
}

void CSelectUserDialog::OnUpdateCommandOK(CSkinView* pView)
{
	pView->SetEnable(m_setSelected.size() > 0);
}

void CSelectUserDialog::GetSelected(list<uint64>& lstMember)
{
	for(set<uint64>::iterator iter = m_setSelected.begin(); iter != m_setSelected.end(); ++iter)
	{
		lstMember.push_back(*iter);
	}
}

LRESULT CSelectUserDialog::OnCheckBoxStateChange(WPARAM wParam, LPARAM lParam)
{
	CSkinView* pSkinView = reinterpret_cast<CSkinView*>(lParam);
	if(pSkinView)
	{
		CSkinCheckBox* pCheckBox = static_cast<CSkinCheckBox*>(pSkinView);
		CSkinListItem* pSkinListItem = static_cast<CSkinListItem*>(pSkinView->GetParent());
		if(pCheckBox && pSkinListItem && pSkinListItem->GetClassName() == _T("CUserItem"))
		{
			CUserItem* pUserItem = static_cast<CUserItem*>(pSkinListItem);
			if(pUserItem)
			{
				uint64 nUserId = pUserItem->GetUserId();
				if(pCheckBox->IsChecked())
				{
					m_setSelected.insert(nUserId);
					if(m_pListViewSelected)
					{
						m_pListViewSelected->AddUserItem(nUserId);
					}
				}
				else
				{
					set<uint64>::iterator iter = m_setSelected.find(nUserId);
					if(iter != m_setSelected.end())
					{
						m_setSelected.erase(iter);
						if(m_pListViewSelected)
						{
							m_pListViewSelected->DeleteUserItem(nUserId);
						}
					}
				}
				UpdateSelectedCount();
			}
		}
	}
	return 1L;
}

void CSelectUserDialog::UpdateSelectedCount()
{
	if(m_pTextViewSelected)
	{
		tstring strFormat = SkinUI::GetString(_T("IDS_SELECT_USER_NUMBER_FORMAT"));
		m_pTextViewSelected->SetText(SkinUI::StringFormat(strFormat.c_str(), m_setSelected.size(), m_nMaxCount));
	}
}