#include "stdafx.h"
#include "ExtInfoStore.h"

CExtInfoStore* CExtInfoStore::s_inst = NULL;
CExtInfoStore* CExtInfoStore::GetInstance()
{
	if(!s_inst)
	{
		s_inst = new CExtInfoStore();
		if(s_inst)
		{
			s_inst->Load();
		}
	}
	return s_inst;
}

void CExtInfoStore::Load()
{
	for(uint nId = 0; nId < 100; ++nId)
	{
		tstring strMobile = SkinUI::IntToString(13088880000 + nId);
		tstring strPhone = SkinUI::IntToString(37210000 + nId);
		tstring strEmail = SkinUI::StringFormat(_T("user%d@163.com"), nId);

		JsonObject obj;
		obj.AddChild(_T("mobile"), strMobile);
		obj.AddChild(_T("phone"), strPhone);
		obj.AddChild(_T("email"), strEmail);

		ConvId convId;
		convId.nType = CONV_TYPE_USER;
		convId.nId = nId;

		STExtInfo info;
		info.strExtInfo = SkinUI::ObjectToString(obj);
		m_mapExtInfo[convId] = info;
	}
}

STExtInfo* CExtInfoStore::GetExtInfoById(ConvId convId)
{
	map<ConvId, STExtInfo>::iterator iter = m_mapExtInfo.find(convId);
	if(iter != m_mapExtInfo.end())
	{
		return &(iter->second);
	}
	return NULL;
}

const map<ConvId, STExtInfo>& CExtInfoStore::GetAllExtInfo()
{
	return m_mapExtInfo;
}