#include "stdafx.h"
#include "MainDialog.h"
#include "AboutDialog.h"



SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_WM_NCDESTROY()
	ON_SKINUI_COMMAND(MENU_ABOUT, OnMenuCommandAbout)
	ON_SKINUI_COMMAND(IDC_FOLDERLISTITEM, OnFolderListItemClicked)
	ON_SKINUI_COMMAND(IDC_ADDFOLDERBUTTON, OnBtnClickedAddFolder)
	ON_SKINUI_COMMAND(IDC_ADDPROJECTBUTTON, OnBtnClickedAddProject)
	ON_SKINUI_COMMAND(IDC_OPENPROJECTBUTTON, OnBtnClickedOpenProject)
	ON_SKINUI_COMMAND(IDC_DELETEFOLDERBUTTON, OnBtnClickedDeleteFolder)
	ON_SKINUI_COMMAND(IDC_DELETEPROJECTBUTTON, OnBtnClickedDeleteProject)
SKINUI_END_MESSAGE_MAP()

CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
, m_pListView1(NULL)
, m_pListView2(NULL)
{

}

void CMainDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	//��ʼ��
	m_pListView1 = static_cast<CSkinListView*>(GetChildById(IDC_LISTVIEW1));
	m_pListView2 = static_cast<CSkinListView*>(GetChildById(IDC_LISTVIEW2));

	//��ȡ
	//ģ��
	CFolderItem tempFolder(_T("c++"));
	CProjectItem tempProject(_T("ice"), _T("666"));
	tempFolder.AddNewProjectToBack(tempProject);
	m_IceItemCtrl.AddNewFolder(tempFolder);
	AddNewItemToListView(IDC_LISTVIEW1, tempFolder.GetName());
	/*AddNewItemToListView(IDC_LISTVIEW2, tempProject.GetName());
	//Ĭ���л�����һ��
	//m_pListView1->SetChecked(m_pListView1->GetChildByIndex(0));
	/*auto a=m_pListView1->GetAllChild();
	tstring as=_T("f");
	MsgBox(as);*/
}

void CMainDialog::OnNcDestroy(BOOL& bHandle)
{
	bHandle = FALSE;
	PostQuitMessage(0);
}

void CMainDialog::OnMenuCommandAbout(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CAboutDialog dlg;
	dlg.DoModal(m_hWnd);
}

void CMainDialog::AddNewItemToListView(UINT ID, const tstring strName)
{
	switch (ID)
	{
		CSkinListItem* pListItem;

	case IDC_LISTVIEW1:
		pListItem = new CSkinListItem(m_pListView1);
		if (pListItem)
		{
			pListItem->SetId(111);
			pListItem->SetLayoutHeight(30);
			pListItem->SetLayout(_T("FolderListItem.xml"));
			pListItem->SetChildText(100001, strName);
			pListItem->SetColorChecked(_T("ID_COLOR_LIST_CHECKED"));
			pListItem->SetColorMouseOver(_T("ID_COLOR_LIST_OVER"));

			m_pListView1->ResetScrollInfo();
			m_pListView1->ScrollBottom();
			m_pListView1->RedrawView();
		}
		break;
	case IDC_LISTVIEW2:
		pListItem = new CSkinListItem(m_pListView2);
		if (pListItem)
		{
			pListItem->SetLayoutHeight(30);
			pListItem->SetLayout(_T("ProjectListItem.xml"));
			pListItem->SetChildText(100001, strName);
			pListItem->SetColorChecked(_T("ID_COLOR_LIST_CHECKED"));
			pListItem->SetColorMouseOver(_T("ID_COLOR_LIST_OVER"));
			m_pListView2->ResetScrollInfo();
			m_pListView2->ScrollBottom();
			m_pListView2->RedrawView();
		}
		break;
	}
}

void CMainDialog::OnBtnClickedAddFolder(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (m_pListView1)
	{
		tstring strTitle = SkinUI::GetString(_T("IDS_TIPS"));
		tstring strMessage = _T("�������ļ�������");
		tstring strEditText;
		tstring strTips = _T("");

	Retry:
		LONG nIndex = GetOwner()->Prompt(strEditText, strTips, strMessage, strTitle);
		if (nIndex == -1)
		{
			return;
		}
		if (strEditText == TEXT(""))
		{
			MsgBox(_T("��������������Ƿ�Ϊ��"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			goto Retry;
		}
		USES_CONVERSION;//ת��wchar
		if (strchr(W2A(strEditText.c_str()), '\n') != NULL)
		{
			MsgBox(_T("��������������Ƿ��л���"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			goto Retry;
		}
		if (m_IceItemCtrl.IsExisted(strEditText))
		{
			MsgBox(_T("�����Ѵ��ڣ�����������"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			goto Retry;
		}

		//���Ӽ�¼
		CFolderItem tempFolderItem(strEditText);
		m_IceItemCtrl.AddNewFolder(tempFolderItem);
		//����ListView
		AddNewItemToListView(IDC_LISTVIEW1, strEditText.c_str());
	}
}

void CMainDialog::OnBtnClickedAddProject(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (m_pListView2)
	{
		if (m_pListView1->GetChecked() == NULL)
		{
			MsgBox(_T("����ѡ��һ���ļ���"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			return;
		}

		tstring strTitle = SkinUI::GetString(_T("IDS_TIPS"));
		tstring strMessage = _T("��������Ŀ���ƺ�·������Ӣ�Ķ��ŷָ����������� ") + m_pListView1->GetChecked()->GetChildById(100001)->GetText() + _T(" �ļ���");
		tstring strEditText;

	Retry:
		LONG nIndex = GetOwner()->Prompt(strEditText, tstring(_T("")), strMessage, strTitle);
		if (nIndex == -1)
		{
			return;
		}
		if (strEditText == TEXT(""))
		{
			MsgBox(_T("��������������Ƿ�Ϊ��"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			goto Retry;
		}
		USES_CONVERSION;//ת��wchar
		if (strchr(W2A(strEditText.c_str()), '\n') != NULL)
		{
			MsgBox(_T("��������������Ƿ��л���"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			goto Retry;
		}
		if (strchr(W2A(strEditText.c_str()), ',') == NULL)
		{
			MsgBox(_T("�����Ƿ���������"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			goto Retry;
		}
		if (m_IceItemCtrl.IsExisted(strEditText))
		{
			MsgBox(_T("�����Ѵ��ڣ�����������"), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
			goto Retry;
		}

		//�����ַ���
		size_t a=strEditText.find(',');
		tstring tempName,tempPath;
		tempName.assign(strEditText, 0, a);
		tempPath.assign(strEditText, ++a, strEditText.size());
		//tstring tempName2, tempPath2;
		/*char tempCommand[500] = { 0 };
		tempCommand = W2A(strEditText.c_str());
		
		char *ptr, *retptr;
		char *result[2];
		int i=0;
		ptr = tempCommand;

		while ((retptr = strtok(ptr, ",")) != NULL) {
			strcpy(result[i++],retptr);
			ptr = NULL;
		}
		*/
		//���Ӽ�¼
		CProjectItem tempProjectItem(tempName, tempPath);
		m_IceItemCtrl.AddProjectToFolder(tempProjectItem, m_pListView1->GetChecked()->GetChildById(100001)->GetText());
		//����ListView
		AddNewItemToListView(IDC_LISTVIEW2, tempName);
	}
}

void CMainDialog::OnBtnClickedOpenProject(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (m_pListView2)
	{
		CSkinListItem* pListItem = m_pListView2->GetChecked();
		tstring tempPath;
		if (pListItem)
		{
			auto tempFolderList=m_IceItemCtrl.GetAllFolders();
			std::list<CFolderItem>::iterator iter = tempFolderList.begin();
			for (; iter != tempFolderList.end(); iter++)
			{
				if (iter->GetName() == m_pListView1->GetChecked()->GetChildById(100001)->GetText())
				{
					tempPath=iter->GetProjectPathByName(pListItem->GetChildById(100001)->GetText());
					break;
				}
			}
			MsgBox(TEXT("�� ") + pListItem->GetChildById(100001)->GetText() + TEXT("\n·�� ") + tempPath, SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
		}
	}
}

void CMainDialog::OnBtnClickedDeleteFolder(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (m_pListView1)
	{
		CSkinListItem* pListItem = m_pListView1->GetChecked();

		if (pListItem)
		{
			if (MsgBox(TEXT("�Ƿ�ɾ�� ") + pListItem->GetChildById(100001)->GetText() + TEXT("?\nע�⣺����������Ŀ����һ��ɾ��"), _T("��ʾ"), MB_YESNO) == 6)
			{
				m_pListView1->DeleteChild(pListItem);
			}
		}

		m_pListView1->ResetScrollInfo();
		m_pListView1->ScrollBottom();
		m_pListView1->RedrawView();
	}
}

void CMainDialog::OnBtnClickedDeleteProject(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (m_pListView2)
	{
		CSkinListItem* pListItem = m_pListView2->GetChecked();

		if (pListItem)
		{
			if (MsgBox(TEXT("�Ƿ�ɾ�� ") + pListItem->GetChildById(100001)->GetText() + TEXT("?\nע�⣺��ɾ����Ŀ��¼������ɾ���ļ�"), _T("��ʾ"), MB_YESNO) == 6)
			{
				m_pListView2->DeleteChild(pListItem);
			}
		}

		m_pListView2->ResetScrollInfo();
		m_pListView2->ScrollBottom();
		m_pListView2->RedrawView();
	}
}

void CMainDialog::OnFolderListItemClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if (m_pListView1)
	{
		CSkinListItem* pListItem = m_pListView1->GetChecked();

		if (pListItem)
		{
			m_pListView2->DeleteAllChild();
			list<CProjectItem> tempList=m_IceItemCtrl.GetProjectListFromFolder(pListItem->GetChildById(100001)->GetText());
			std::list<CProjectItem>::iterator iter = tempList.begin();
			for (; iter != tempList.end(); iter++)
			{
				AddNewItemToListView(IDC_LISTVIEW2, iter->GetName());
			}
			MsgBox(_T("�л��� ") + pListItem->GetChildById(100001)->GetText(), SkinUI::GetString(_T("IDS_TIPS")), MB_OK);
		}
	}
}