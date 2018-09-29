#pragma once

class CThread
{
public:
	CThread();

	virtual ~CThread();

	virtual unsigned Run() = 0;

public:
	bool Start(bool bSuspend = false);

	bool Stop(uint unTimeout = INFINITE);

	bool IsStop() const { return m_bStop; }

	bool Suspend();

	bool Resume();

protected:
	static unsigned WINAPI ThreadFunc(PVOID pParam);

	HANDLE m_hThread;
	bool m_bSuspend;
	bool m_bStop;
};