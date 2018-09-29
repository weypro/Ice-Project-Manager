#pragma once

class CIMClient : public CSkinApplication
{
public:
	CIMClient();

public:
	virtual BOOL InitInstance();
	virtual void Run(const tstring& strCmdLine, int nCmdShow);
	virtual void ExitInstance();

public:
	uint64 GetUserId();
	tstring GetConversationName(ConvId convId);
};

inline uint64 CIMClient::GetUserId()
{
	return 0;
}