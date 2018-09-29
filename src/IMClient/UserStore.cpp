#include "stdafx.h"
#include "UserStore.h"

CUserStore* CUserStore::s_inst = NULL;
CUserStore* CUserStore::GetInstance()
{
	if(!s_inst)
	{
		s_inst = new CUserStore();
		if(s_inst)
		{
			s_inst->Load();
		}
	}
	return s_inst;
}

void CUserStore::Load()
{
	for(uint nId = 0; nId < 100; ++nId)
	{
		STUser user;
		user.nId = nId;
		user.nDeptId = nId / 10;
		user.nGender = nId % 2 ? MALE : FEMALE;
		user.strName = _T("用户") + SkinUI::IntToString(nId);
		user.strAccount = SkinUI::IntToString(nId);
		user.strPosition = _T("职位") + SkinUI::IntToString(nId % 10);
		user.nIndex = nId;
		m_mapUser[user.nId] = user;
	}
}

STUser* CUserStore::GetUserById(uint64 nUserId)
{
	map<uint64, STUser>::iterator iter = m_mapUser.find(nUserId);
	if(iter != m_mapUser.end())
	{
		return &(iter->second);
	}
	assert(false);
	return NULL;
}

const map<uint64, STUser>& CUserStore::GetAllUser()
{
	return m_mapUser;
}

void CUserStore::GetChildUser(uint32 nDeptId, list<uint64>& lstChildUser)
{
	for(map<uint64, STUser>::iterator iter = m_mapUser.begin(); iter != m_mapUser.end(); ++iter)
	{
		if(iter->second.nDeptId == nDeptId)
		{
			lstChildUser.push_back(iter->first);
		}
	}
}