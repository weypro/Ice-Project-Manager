#include "stdafx.h"
#include "DeptStore.h"

CDeptStore* CDeptStore::s_inst = NULL;
CDeptStore* CDeptStore::GetInstance()
{
	if(!s_inst)
	{
		s_inst = new CDeptStore();
		if(s_inst)
		{
			s_inst->Load();
		}
	}
	return s_inst;
}

void CDeptStore::Load()
{
	STDept dept;
	dept.nId = 0;
	dept.nParentDeptId = 0;
	dept.strName = _T("公司名称");
	dept.nIndex = 0;
	m_mapDept[dept.nId] = dept;

	for(uint nId = 1; nId < 10; ++nId)
	{
		STDept dept;
		dept.nId = nId;
		dept.nParentDeptId = 0;
		dept.strName = _T("部门") + SkinUI::IntToString(nId);
		dept.nIndex = nId;
		m_mapDept[dept.nId] = dept;
	}
}

STDept* CDeptStore::GetDeptById(uint32 nDeptId)
{
	map<uint32, STDept>::iterator iter = m_mapDept.find(nDeptId);
	if(iter != m_mapDept.end())
	{
		return &(iter->second);
	}
	return NULL;
}

const map<uint32, STDept>& CDeptStore::GetAllDept()
{
	return m_mapDept;
}

void CDeptStore::GetChildDept(uint32 nDeptId, list<uint32>& lstChildDept)
{
	for(map<uint32, STDept>::iterator iter = m_mapDept.begin(); iter != m_mapDept.end(); ++iter)
	{
		if(iter->second.nId != 0 && iter->second.nParentDeptId == nDeptId)
		{
			lstChildDept.push_back(iter->first);
		}
	}
}