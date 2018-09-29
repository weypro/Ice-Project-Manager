#pragma once

class CConvListStore
{
private:
	~CConvListStore();
	static CConvListStore* s_inst;
	void Load();

public:
	static CConvListStore* GetInstance();

public:
	void BeginConv(ConvId convId);
	bool DeleteConv(ConvId convId);

public:
	STConv* GetConvById(ConvId convId);
	const map<ConvId, STConv>& GetAllConv();

private:
	map<ConvId, STConv>	m_mapConv;
};