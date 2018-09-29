#include "stdafx.h"
#include "ConvListStore.h"

CConvListStore* CConvListStore::s_inst = NULL;
CConvListStore* CConvListStore::GetInstance()
{
	if(!s_inst)
	{
		s_inst = new CConvListStore();
		if(s_inst)
		{
			s_inst->Load();
		}
	}
	return s_inst;
}

void CConvListStore::Load()
{
	uint64 nMsgTime = CAppHelper::GetCurTime();
	for(uint nId = 0; nId < 100; ++nId)
	{
		STConv conv;
		conv.convId.nType = nId % 2 ? CONV_TYPE_USER : CONV_TYPE_GROUP;
		conv.convId.nId = nId;
		conv.nMsgId = nId;
		conv.nMsgType = MSG_TYPE_TEXT;
		conv.nMsgTime = nMsgTime - 100 * nId;
		conv.nMsgSender = nId;
		conv.strMsgContent = _T("测试会话消息") + SkinUI::IntToString(nId);
		m_mapConv[conv.convId] = conv;
	}
}

void CConvListStore::BeginConv(ConvId convId)
{
	map<ConvId, STConv>::iterator iter = m_mapConv.find(convId);
	if(iter == m_mapConv.end())
	{
		STConv conv;
		conv.convId = convId;
		conv.nMsgTime = CAppHelper::GetCurTime();
		m_mapConv[conv.convId] = conv;
	}
}

bool CConvListStore::DeleteConv(ConvId convId)
{
	map<ConvId, STConv>::iterator iter = m_mapConv.find(convId);
	if(iter != m_mapConv.end())
	{
		m_mapConv.erase(iter);
	}
	return true;
}

STConv* CConvListStore::GetConvById(ConvId convId)
{
	map<ConvId, STConv>::iterator iter = m_mapConv.find(convId);
	if(iter != m_mapConv.end())
	{
		return &(iter->second);
	}
	return NULL;
}

const map<ConvId, STConv>& CConvListStore::GetAllConv()
{
	return m_mapConv;
}