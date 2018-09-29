#pragma once

class CMyIEWebView : public CSkinIEView
{
public:
	CMyIEWebView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void OnFunction1Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction2Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction3Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction4Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction5Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction6Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction7Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction8Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	void OnFunction9Param(const map<tstring, JsonValue>& mapData, const tstring& strCallback);
	SKINUI_DECLARE_EXTENSION_MESSAGE_MAP()
};

class CIEWebDialog : public CSkinDialog
{
public:
	enum
	{
		IDC_WEBVIEW = 101,
		IDC_BUTTON1 = 201,
		IDC_BUTTON2 = 202,
		IDC_BUTTON3 = 203,
		IDC_BUTTON4 = 204,
		IDC_BUTTON5 = 205,
		IDC_BUTTON6 = 206,
		IDC_BUTTON7 = 207,
		IDC_BUTTON8 = 208,
		IDC_BUTTON9 = 209,
	};

public:
	CIEWebDialog(const tstring& strXml);

public:
	virtual void OnInitDialog();

protected:
	void OnBtnClicked(UINT uNotifyCode, int nID, CSkinView* pView);
	SKINUI_DECLARE_MESSAGE_MAP()

private:
	CMyIEWebView* m_pIEWebView;
};