#include "stdafx.h"
#include "Thread.h"
#include <process.h>

CThread::CThread()
: m_hThread(NULL)
, m_bSuspend(FALSE)
, m_bStop(FALSE)
{

}

CThread::~CThread()
{
	Stop();
}

bool CThread::Start(bool bSuspend)
{
	if(m_hThread != NULL)
		return false;

	unsigned unInitFlag = 0;
	if(bSuspend)
	{
		m_bSuspend = true;
		unInitFlag = CREATE_SUSPENDED;
	}
	else
	{
		m_bSuspend = false;
	}

	m_hThread = (HANDLE)::_beginthreadex(NULL, 0, ThreadFunc, this, unInitFlag, NULL);
	if(m_hThread == NULL)
		return false;

	m_bStop = false;
	return true;
}

bool CThread::Stop(uint unTimeout)
{
	if(m_hThread == NULL)
		return true;

	m_bStop = true;
	if(m_bSuspend)
	{
		Resume();
	}

	DWORD dwRet = ::WaitForSingleObject(m_hThread, unTimeout);
	if(dwRet != WAIT_OBJECT_0)
	{
		::TerminateThread(m_hThread, 0);
		::WaitForSingleObject(m_hThread, INFINITE);
	}

	::CloseHandle(m_hThread);
	m_hThread = NULL;

	return true;
}

bool CThread::Suspend()
{
	if(m_hThread == NULL)
		return false;

	m_bSuspend = true;
	DWORD dwRet = ::SuspendThread(m_hThread);
	if(dwRet == (DWORD)-1)
		return false;

	return true;
}

bool CThread::Resume()
{
	if(m_hThread == NULL)
		return false;

	m_bSuspend = false;
	DWORD dwRet = ::ResumeThread(m_hThread);
	if(dwRet == (DWORD)-1)
		return false;

	return true;
}

unsigned WINAPI CThread::ThreadFunc(PVOID pParam)
{
	if(pParam == NULL)
		return 0;

	CThread* pIMOThread = (CThread*)pParam;
	return pIMOThread->Run();
}