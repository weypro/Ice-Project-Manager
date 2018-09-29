#pragma once

class CExtInfoStore
{
private:
	~CExtInfoStore();
	static CExtInfoStore* s_inst;
	void Load();

public:
	static CExtInfoStore* GetInstance();

public:
	STExtInfo* GetExtInfoById(ConvId convId);
	const map<ConvId, STExtInfo>& GetAllExtInfo();

private:
	map<ConvId, STExtInfo>		m_mapExtInfo;
};