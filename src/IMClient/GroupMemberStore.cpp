#include "stdafx.h"
#include "GroupMemberStore.h"

CGroupMemberStore* CGroupMemberStore::s_inst = NULL;
CGroupMemberStore* CGroupMemberStore::GetInstance()
{
	if(!s_inst)
	{
		s_inst = new CGroupMemberStore();
		if(s_inst)
		{
			s_inst->Load();
		}
	}
	return s_inst;
}

void CGroupMemberStore::Load()
{
	for(uint64 nId = 0; nId < 100; ++nId)
	{
		uint64 nMemberId = nId;
		m_setGroupMember.insert(nMemberId);
	}
}

const set<uint64>& CGroupMemberStore::GetGroupMember()
{
	return m_setGroupMember;
}