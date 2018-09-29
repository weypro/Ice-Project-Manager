#include "stdafx.h"
#include "EditViewDialog.h"

SKINUI_BEGIN_MESSAGE_MAP(CEditViewDialog, CSkinDialog)
	ON_SKINUI_COMMAND(IDC_BUTTON1, OnBtnClickedAppendText)
	ON_SKINUI_COMMAND(IDC_BUTTON2, OnBtnClickedAppendHyperlink)
	ON_SKINUI_COMMAND(IDC_BUTTON3, OnBtnClickedAppendImage)
	ON_SKINUI_COMMAND(IDC_BUTTON4, OnBtnClickedInsertText)
	ON_SKINUI_COMMAND(IDC_BUTTON5, OnBtnClickedInsertHyperlink)
	ON_SKINUI_COMMAND(IDC_BUTTON6, OnBtnClickedInsertImage)
	ON_SKINUI_COMMAND_RANGE(ID_COMMAND_BEGIN, ID_COMMAND_END, OnHyperlinkClicked)
SKINUI_END_MESSAGE_MAP()

CEditViewDialog::CEditViewDialog(const tstring& strXml)
: CSkinDialog(strXml)
, m_pRichEditView(NULL)
, m_nCommandId(ID_COMMAND_BEGIN)
{

}

void CEditViewDialog::OnInitDialog()
{
	CSkinDialog::OnInitDialog();
	m_pRichEditView = static_cast<CSkinEditView*>(GetChildById(IDC_EDITVIEW));
}

void CEditViewDialog::OnBtnClickedAppendText(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pRichEditView)
	{
		m_pRichEditView->AppendText(_T(" 我是文本 "));
	}
}

void CEditViewDialog::OnBtnClickedAppendHyperlink(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pRichEditView)
	{
		m_pRichEditView->AppendHyperlink(_T(" 试试点击我 "), m_nCommandId++);
	}
}

void CEditViewDialog::OnBtnClickedAppendImage(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pRichEditView)
	{
		m_pRichEditView->AppendImage(_T("Emotion.gif "));
	}
}

void CEditViewDialog::OnBtnClickedInsertText(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pRichEditView)
	{
		m_pRichEditView->InsertText(_T(" 我是文本 "));
	}
}

void CEditViewDialog::OnBtnClickedInsertHyperlink(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pRichEditView)
	{
		m_pRichEditView->InsertHyperlink(_T(" 试试点击我 "), m_nCommandId++);
	}
}

void CEditViewDialog::OnBtnClickedInsertImage(UINT uNotifyCode, int nID, CSkinView* pView)
{
	if(m_pRichEditView)
	{
		m_pRichEditView->InsertImage(_T("Emotion.gif"));
	}
}

void CEditViewDialog::OnHyperlinkClicked(UINT uNotifyCode, int nID, CSkinView* pView)
{
	MsgBox(SkinUI::StringFormat(_T("OnHyperlinkClicked，Command Id=%d！"), nID));
}