#pragma once
#include "stdafx.h"

class CIceBasicListItem
{
protected:
	UINT ID;
	tstring m_strName;
public:
	CIceBasicListItem(const tstring strName)
	{
		SetName(strName);
	}
	tstring GetName()
	{
		return m_strName;
	}
	void SetName(const tstring strName)
	{
		m_strName = strName;
	}
};


class CProjectItem : public CIceBasicListItem
{
protected:
	tstring m_strPath;
	tstring m_strFolderName;
public:
	CProjectItem(const tstring strName, const tstring strPath) : CIceBasicListItem(strName)
	{
		SetProjectPath(strPath);
	}
	tstring GetProjectPath()
	{
		return m_strPath;
	}
	void SetProjectPath(const tstring strPath)
	{
		m_strPath = strPath;
	}
};
