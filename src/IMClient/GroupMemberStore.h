#pragma once

class CGroupMemberStore
{
private:
	~CGroupMemberStore();
	static CGroupMemberStore* s_inst;
	void Load();

public:
	static CGroupMemberStore* GetInstance();

public:
	const set<uint64>& GetGroupMember();

private:
	set<uint64>	m_setGroupMember;
};