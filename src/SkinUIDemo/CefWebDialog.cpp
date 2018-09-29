#include "stdafx.h"
#include "CefWebDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CCefWebDialog, CSkinDialog)
	ON_SKINUI_COMMAND_RANGE(IDC_BUTTON1, IDC_BUTTON9, OnBtnClicked)
SKINUI_END_MESSAGE_MAP()

CCefWebDialog::CCefWebDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pCefWebView(NULL)
{

}

void CCefWebDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();

	m_pCefWebView = static_cast<CMyCefWebView*>(GetChildById(IDC_WEBVIEW));
	if(m_pCefWebView)
	{
		tstring strURL = GetCurModulePath() + _T("web\\SkinUI.html");
		m_pCefWebView->LoadURL(strURL);
	}
}

void CCefWebDialog::OnBtnClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pCefWebView)
	{
		tstring strJavaScript;
		if(nID == IDC_BUTTON1)
		{
			strJavaScript = _T("JavaScriptFunction1Param('11111');");
		}
		else if(nID == IDC_BUTTON2)
		{
			strJavaScript = _T("JavaScriptFunction2Param('11111', '22222');");
		}
		else if(nID == IDC_BUTTON3)
		{
			strJavaScript = _T("JavaScriptFunction3Param('11111', '22222', '33333');");
		}
		else if(nID == IDC_BUTTON4)
		{
			strJavaScript = _T("JavaScriptFunction4Param('11111', '22222', '33333', '44444');");
		}
		else if(nID == IDC_BUTTON5)
		{
			strJavaScript = _T("JavaScriptFunction5Param('11111', '22222', '33333', '44444', '55555');");
		}
		else if(nID == IDC_BUTTON6)
		{
			strJavaScript = _T("JavaScriptFunction6Param('11111', '22222', '33333', '44444', '555555', '66666');");
		}
		else if(nID == IDC_BUTTON7)
		{
			strJavaScript = _T("JavaScriptFunction7Param('11111', '22222', '33333', '44444', '55555', '66666', '77777');");
		}
		else if(nID == IDC_BUTTON8)
		{
			strJavaScript = _T("JavaScriptFunction8Param('11111', '22222', '33333', '44444', '55555', '66666', '77777', '88888');");
		}
		else if(nID == IDC_BUTTON9)
		{
			strJavaScript = _T("JavaScriptFunction9Param('11111', '22222', '33333', '44444', '55555', '66666', '77777', '88888', '99999');");
		}
		m_pCefWebView->RunJavaScript(strJavaScript);
	}
}