#include "stdafx.h"
#include "FolderItem.h"
/****************************CFolderItem******************************/
list<CProjectItem> CFolderItem::GetAllProjects()
{
	return m_projectItemList;
}

tstring CFolderItem::GetProjectPathByName(const tstring strName)
{
	std::list<CProjectItem>::iterator iter = m_projectItemList.begin();
	for (; iter != m_projectItemList.end(); iter++)
	{
		if (iter->GetName() == strName)
		{
			return iter->GetProjectPath();
		}
	}
}

void CFolderItem::AddNewProjectToFront(const CProjectItem MyProjectItem)
{
	m_projectItemList.push_front(MyProjectItem);
}

void CFolderItem::AddNewProjectToBack(const CProjectItem MyProjectItem)
{
	m_projectItemList.push_back(MyProjectItem);
}

void CFolderItem::DeleteProjectByName(const tstring strName)
{
	std::list<CProjectItem>::iterator iter = m_projectItemList.begin();
	for (; iter != m_projectItemList.end(); iter++)
	{
		if (iter->GetName() == strName)
		{
			m_projectItemList.erase(iter);
			return;
		}
	}
}

bool CFolderItem::IsExisted(const tstring strName)
{
	std::list<CProjectItem>::iterator iter = m_projectItemList.begin();
	for (; iter != m_projectItemList.end(); iter++)
	{
		if (iter->GetName() == strName)
		{
			return true;
		}
	}
	return false;
}

/****************************CIceItemCtrl******************************/
list<CFolderItem> CIceItemCtrl::GetAllFolders()
{
	return m_folderItemList;
}

void CIceItemCtrl::AddProjectToFolder(const CProjectItem MyProjectItem, const tstring strName)
{
	std::list<CFolderItem>::iterator iter = m_folderItemList.begin();
	for (; iter != m_folderItemList.end(); iter++)
	{
		if (iter->GetName() == strName)
		{
			iter->AddNewProjectToFront(MyProjectItem);
			return;
		}
	}
}

void CIceItemCtrl::AddNewFolder(const CFolderItem MyFolderItem)
{
	m_folderItemList.push_back(MyFolderItem);
}

void CIceItemCtrl::DeleteFolderByName(const tstring strName)
{
	std::list<CFolderItem>::iterator iter = m_folderItemList.begin();
	for (; iter != m_folderItemList.end(); iter++)
	{
		if (iter->GetName() == strName)
		{
			m_folderItemList.erase(iter);
			return;
		}
	}
}

bool CIceItemCtrl::IsExisted(const tstring strName)
{
	std::list<CFolderItem>::iterator iter = m_folderItemList.begin();
	for (; iter != m_folderItemList.end(); iter++)
	{
		if (iter->GetName() == strName)
		{
			return true;
		}
	}
	return false;
}

list<CProjectItem> CIceItemCtrl::GetProjectListFromFolder(const tstring strName)
{
	std::list<CFolderItem>::iterator iter = m_folderItemList.begin();
	for (; iter != m_folderItemList.end(); iter++)
	{
		if (iter->GetName() == strName)
		{
			return iter->GetAllProjects();
		}
	}
}