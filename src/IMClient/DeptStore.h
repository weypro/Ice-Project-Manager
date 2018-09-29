#pragma once

class CDeptStore
{
private:
	~CDeptStore();
	static CDeptStore* s_inst;
	void Load();

public:
	static CDeptStore* GetInstance();

public:
	STDept* GetDeptById(uint32 nDeptId);
	void GetChildDept(uint32 nDeptId, list<uint32>& lstChildDept);
	const map<uint32, STDept>& GetAllDept();

private:
	map<uint32, STDept> m_mapDept;
};