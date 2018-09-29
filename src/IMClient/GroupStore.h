#pragma once

class CGroupStore
{
private:
	~CGroupStore();
	static CGroupStore* s_inst;
	void Load();

public:
	static CGroupStore* GetInstance();

public:
	STGroup* GetGroupById(uint64 nGroupId);
	const map<uint64, STGroup>& GetAllGroup();

private:
	map<uint64, STGroup>		m_mapGroup;
};