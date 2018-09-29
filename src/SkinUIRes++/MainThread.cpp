#include "stdafx.h"
#include "MainThread.h"
#include "MainDialog.h"
#include "FileHelper.h"

struct STResFile
{
	tstring strResName;
	tstring strTableFile;
	list<tstring> lstResFile;
	uint32 unResSize;
};

CMainThread::CMainThread(HWND hMainWnd)
: m_hMainWnd(hMainWnd)
{

}

unsigned CMainThread::Run()
{
	//获取列表
	LONG nPos = 0;
	LONG nRange = 0;
	list<tstring> lstFolder;
	list<STResFile> lstResFile;

	tstring strPath = CFileHelper::GetCurModulePath() + _T("res\\");
	CFileHelper::GetChildFolder(strPath, lstFolder, TRUE);
	for(list<tstring>::iterator iter = lstFolder.begin(); iter != lstFolder.end(); ++iter)
	{
		ResHead head = {0};
		STResFile resFile;
		resFile.unResSize = 0;
		resFile.strResName = CFileHelper::GetFileName(SkinUI::StringLeft(*iter, iter->size() - 1));
		CFileHelper::GetAllChildFile(*iter, resFile.lstResFile);
		uint32 nOffset = 0;

		CXMLNode root;
		root.SetName(_T("ResTable"));
		for(list<tstring>::iterator iter = resFile.lstResFile.begin(); iter != resFile.lstResFile.end(); ++iter)
		{
			uint32 nFileSize = CFileHelper::GetFileSize(*iter);
			tstring strFileId = SkinUI::StringRight(*iter, iter->size() - strPath.size() - resFile.strResName.size() - 1);

			CXMLNode node;
			node.SetName(_T("Res"));
			node.SetAttribute(_T("Id"), strFileId);
			node.SetAttribute(_T("Size"), SkinUI::IntToString(nFileSize));
			node.SetAttribute(_T("Offset"), SkinUI::IntToString(nOffset));
			root.AddChildNode(node);

			resFile.unResSize += nFileSize;
			nOffset += nFileSize;
		}

		resFile.strTableFile = strPath + resFile.strResName + _T(".xml");
		SkinUI::NodeToFile(root, resFile.strTableFile);
		lstResFile.push_back(resFile);
		nRange += resFile.lstResFile.size();
	}
	PostMessage(m_hMainWnd, WM_SETUP_NOTIFY, NOTIFY_RANGE, nRange);

	for(list<STResFile>::iterator iter = lstResFile.begin(); iter != lstResFile.end(); ++iter)
	{
		//清理资源
		tstring strResName = iter->strResName + _T(".res");
		tstring strResPath = strPath + strResName;
		CFileHelper::DeleteFile(strResPath);

		//写入表头
		FILE* fp = _tfopen(strResPath.c_str(), _T("wb+"));
		if(fp == NULL)
			return FALSE;

		uint32 nXmlFileSize = CFileHelper::GetFileSize(iter->strTableFile);

		//create head
		ResHead head = {0};
		head.unMagic = htonl(RES_FILE_MAGIC);
		head.unHeadSize = htonl(sizeof(head));
		head.unMetaSize = htonl(nXmlFileSize);
		head.unResSize = htonl(iter->unResSize);

		//write head
		int n = fwrite(&head, 1, sizeof(head), fp);
		if(n != sizeof(head))
		{
			assert(FALSE);
			fclose(fp);
			return FALSE;
		}

		//写入列表
		WriteFile(fp, iter->strTableFile, nXmlFileSize);
		CFileHelper::DeleteFile(iter->strTableFile);

		//写入文件
		list<tstring>& lstFile = iter->lstResFile;
		for(list<tstring>::iterator iter = lstFile.begin(); iter != lstFile.end(); ++iter)
		{
			uint32 nFileSize = CFileHelper::GetFileSize(*iter);
			WriteFile(fp, *iter, nFileSize);

			tstring strFileName = CFileHelper::GetFileName(*iter);
			tstring strFormat = SkinUI::GetString(_T("IDS_WRITE_FILE_FORMAT"));
			tstring strText = SkinUI::StringFormat(strFormat.c_str(), strResName.c_str(), strFileName.c_str());
			NotifyProgress(++nPos, strText);
		}

		fclose(fp);
	}

	delete this;
	return 1L;
}

void CMainThread::NotifyProgress(LONG nPos, const tstring& strText)
{
	CXMLNode root;
	root.SetName(_T("NotifyProgress"));
	root.AddChildNode(_T("Pos"), SkinUI::IntToString(nPos));
	root.AddChildNode(_T("Text"), strText);

	tstring* pStrXML = new tstring();
	SkinUI::NodeToString(root, *pStrXML);
	PostMessage(m_hMainWnd, WM_SETUP_NOTIFY, NOTIFY_PROGRESS, (LPARAM)pStrXML);
}

BOOL CMainThread::WriteFile(FILE* fp, const tstring& sFile, uint unFileSize)
{
	HANDLE hFile = ::CreateFile(sFile.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	char buf[10240] = {0};
	uint unTotalReadSize = 0;

	while(TRUE)
	{
		DWORD dwNumberOfBytesRead;
		BOOL bRet = ::ReadFile(hFile, buf, sizeof(buf), &dwNumberOfBytesRead, NULL);
		if(!bRet)
		{
			::CloseHandle(hFile);
			hFile = INVALID_HANDLE_VALUE;
			return FALSE;
		}

		int nRet = fwrite(buf, 1, dwNumberOfBytesRead, fp);
		if(nRet !=(int)dwNumberOfBytesRead)
		{
			::CloseHandle(hFile);
			hFile = INVALID_HANDLE_VALUE;
			return FALSE;
		}

		unTotalReadSize += dwNumberOfBytesRead;

		if(dwNumberOfBytesRead < sizeof(buf))
		{
			::CloseHandle(hFile);
			hFile = INVALID_HANDLE_VALUE;
			break;
		}
	}

	if(unTotalReadSize != unFileSize)
	{
		assert(FALSE);
		return FALSE;
	}

	return TRUE;
}