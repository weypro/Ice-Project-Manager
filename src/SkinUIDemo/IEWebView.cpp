#include "stdafx.h"
#include "IEWebDialog.h"

SKINUI_IMPLEMENT_DYNCREATE(CMyIEWebView)
SKINUI_BEGIN_EXTENSION_MESSAGE_MAP(CMyIEWebView, CSkinIEView)
	ON_SKINUI_EXTENSION_MESSAGE(Function1Param, OnFunction1Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function2Param, OnFunction2Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function3Param, OnFunction3Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function4Param, OnFunction4Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function5Param, OnFunction5Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function6Param, OnFunction6Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function7Param, OnFunction7Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function8Param, OnFunction8Param)
	ON_SKINUI_EXTENSION_MESSAGE(Function9Param, OnFunction9Param)
SKINUI_END_EXTENSION_MESSAGE_MAP()

CMyIEWebView::CMyIEWebView(CSkinView* pParent)
: CSkinIEView(pParent)
{

}

void CMyIEWebView::OnFunction1Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction2Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction3Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param3"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction4Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param3"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param4"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction5Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param3"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param4"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param5"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction6Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param3"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param4"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param5"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param6"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction7Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param3"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param4"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param5"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param6"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param7"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction8Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param3"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param4"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param5"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param6"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param7"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param8"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}

void CMyIEWebView::OnFunction9Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback)
{
	tstring str;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("param1"));
	if(iter != mapData.end())
	{
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param2"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param3"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param4"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param5"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param6"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param7"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param8"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	iter = mapData.find(_T("param9"));
	if(iter != mapData.end())
	{
		str += _T("\r\n");
		str += iter->second.GetString();
	}

	GetOwner()->MsgBox(str);
	RunJavaScript(strCallback);
}