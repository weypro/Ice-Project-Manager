#include "stdafx.h"
#include "MainDialog.h"
#include "MainThread.h"

SKINUI_BEGIN_MESSAGE_MAP(CMainDialog, CSkinDialog)
	ON_SKINUI_MESSAGE(WM_SETUP_NOTIFY, OnSetupNotify)
	ON_SKINUI_COMMAND(IDOK, OnBtnClickedSetupStart)
	ON_SKINUI_COMMAND(IDC_BUTTON_FINISH, OnBtnClickedSetupFinish)
	ON_SKINUI_WM_NCDESTROY()
	ON_SKINUI_WM_COPYDATA()
SKINUI_END_MESSAGE_MAP()

CMainDialog::CMainDialog()
: CSkinDialog(_T("MainDialog.xml"))
, m_pEditView(NULL)
, m_pTextView(NULL)
, m_pProgress(NULL)
{

}

void CMainDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	SwitchChildMode(WINDOW_MODE_START);

	m_pEditView = static_cast<CSkinEditView*>(GetChildById(IDC_EDITVIEW));
	m_pTextView = static_cast<CSkinTextView*>(GetChildById(IDC_TEXTVIEW));
	m_pProgress = static_cast<CSkinProgress*>(GetChildById(IDC_PROGRESS));
}

static BOOL IsValidProjectName(tstring strProjectName)
{
	if(strProjectName.empty())
	{
		return FALSE;
	}

	tstring strChar = _T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	for(size_t szIndex = 0; szIndex != strProjectName.size(); ++szIndex)
	{
		tstring strFind = tstring() + strProjectName.at(szIndex);
		if(SkinUI::StringFind(strChar, strFind) == tstring::npos)
		{
			return FALSE;
		}
	}
	return TRUE;
}

void CMainDialog::OnBtnClickedSetupStart(UINT uNotifyCode, int nID, CSkinView* pView)
{
	tstring strProjectName;
	if(m_pEditView)
	{
		strProjectName = m_pEditView->GetText();
	}

	if(!IsValidProjectName(strProjectName))
	{
		MsgBox(SkinUI::GetString(_T("IDS_INVALID_PROJECT_NAME_TIPS")));
		return;
	}
	CMainThread* pThread = new CMainThread(GetHWND(), strProjectName);
	if(pThread)
	{
		pThread->Start();
	}
	SwitchChildMode(WINDOW_MODE_ING);
}

void CMainDialog::OnBtnClickedSetupFinish(UINT uNotifyCode, int nID, CSkinView* pView)
{
	PostMessage(WM_CLOSE);
}

void CMainDialog::OnNcDestroy(BOOL& bHandle)
{
	bHandle = FALSE;
	PostQuitMessage(0);
}

LRESULT CMainDialog::OnSetupNotify(WPARAM wParam, LPARAM lParam)
{
	if(wParam == NOTIFY_RANGE)
	{
		if(m_pProgress)
		{
			m_pProgress->SetRange(lParam);
		}
	}
	else if(wParam == NOTIFY_PROGRESS)
	{
		tstring* pStrXML = (tstring*)lParam;

		LONG nPos = 0;
		tstring strText;
		CXMLNode xmlNode;
		SkinUI::StringToNode(xmlNode, *pStrXML);
		const vector<CXMLNode>& vecNode = xmlNode.GetChildNode();
		for(vector<CXMLNode>::const_iterator iter = vecNode.begin(); iter != vecNode.end(); ++iter)
		{
			if(iter->GetName() == _T("Pos"))
			{
				nPos = SkinUI::StringToLong(iter->GetValue());
			}
			else if(iter->GetName() == _T("Text"))
			{
				strText = iter->GetValue();
			}
		}
		delete pStrXML;

		if(m_pProgress)
		{
			m_pProgress->SetPos(nPos);
		}

		if(m_pTextView)
		{
			m_pTextView->SetText(strText);
		}

		if(nPos == m_pProgress->GetRange())
		{
			SwitchChildMode(WINDOW_MODE_FINISH);
		}
		else
		{
			RedrawView();
		}
	}
	return 1L;
}