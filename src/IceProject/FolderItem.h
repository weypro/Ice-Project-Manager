#pragma once
#include "stdafx.h"
#include "ProjectClass.h"

#ifndef _H_FOLDERITEM_
#define _H_FOLDERITEM_

class CFolderItem : public CIceBasicListItem
{
protected:
	list<CProjectItem> m_projectItemList;
public:
	CFolderItem(const tstring strName) : CIceBasicListItem(strName)
	{
		//
	}
	list<CProjectItem> GetAllProjects();
	tstring GetProjectPathByName(const tstring strName);
	void AddNewProjectToFront(const CProjectItem MyProjectItem);
	void AddNewProjectToBack(const CProjectItem MyProjectItem);
	//void DeleteProject(const CProjectItem MyProjectItem);
	void DeleteProjectByName(const tstring strName);
	bool IsExisted(const tstring strName);
};


class CIceItemCtrl
{
private:
	//CIceItemCtrl(){}
	//static CIceItemCtrl *p;//单例模式，未保证多线程安全，可增加互斥
protected:
	list<CFolderItem> m_folderItemList;
public:
	/*static CIceItemCtrl* GetInstance()
	{
		if (p == NULL)
			p = new CIceItemCtrl();
		return p;
	}*/
	list<CFolderItem> GetAllFolders();
	list<CProjectItem> GetProjectListFromFolder(const tstring strName);
	void AddProjectToFolder(const CProjectItem MyProjectItem, const tstring strName);
	void AddNewFolder(const CFolderItem MyFolderItem);
	//void DeleteFolder(const CFolderItem MyFolderItem);
	void DeleteFolderByName(const tstring strName);
	bool IsExisted(const tstring strName);
};

#endif