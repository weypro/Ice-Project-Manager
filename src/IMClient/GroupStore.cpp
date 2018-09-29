#include "stdafx.h"
#include "GroupStore.h"

CGroupStore* CGroupStore::s_inst = NULL;
CGroupStore* CGroupStore::GetInstance()
{
	if(!s_inst)
	{
		s_inst = new CGroupStore();
		if(s_inst)
		{
			s_inst->Load();
		}
	}
	return s_inst;
}

void CGroupStore::Load()
{
	for(uint64 nId = 0; nId < 100; ++nId)
	{
		STGroup group;
		group.nId = nId;
		group.nHostId = 0;
		group.strName = _T("х╨ад") + SkinUI::IntToString(nId);
		m_mapGroup[group.nId] = group;
	}
}

STGroup* CGroupStore::GetGroupById(uint64 nGroupId)
{
	map<uint64, STGroup>::iterator iter = m_mapGroup.find(nGroupId);
	if(iter != m_mapGroup.end())
	{
		return &(iter->second);
	}
	assert(false);
	return NULL;
}

const map<uint64, STGroup>& CGroupStore::GetAllGroup()
{
	return m_mapGroup;
}