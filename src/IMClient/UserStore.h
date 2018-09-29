#pragma once

class CUserStore
{
private:
	~CUserStore();
	static CUserStore* s_inst;
	void Load();

public:
	static CUserStore* GetInstance();

public:
	STUser* GetUserById(uint64 nUserId);
	void GetChildUser(uint32 nDeptId, list<uint64>& lstChildUser);
	const map<uint64, STUser>& GetAllUser();

private:
	map<uint64, STUser>		m_mapUser;
};