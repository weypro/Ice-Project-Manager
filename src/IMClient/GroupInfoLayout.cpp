#include <stdafx.h>
#include "GroupInfoLayout.h"

SKINUI_IMPLEMENT_DYNCREATE(CGroupInfoLayout)
CGroupInfoLayout::CGroupInfoLayout(CSkinView* pParent)
: CConversationInfoLayout(pParent)
{

}

void CGroupInfoLayout::Init(ConvId convId)
{
	CConversationInfoLayout::Init(convId);

	STGroup* pGroup = CGroupStore::GetInstance()->GetGroupById(convId.nId);
	if(pGroup)
	{
		CSkinView* pSkinView = GetChildById(IDC_EDITVIEW_GROUP_HOST);
		if(pSkinView)
		{
			pSkinView->SetText(theApp.GetConversationName(ConvId(CONV_TYPE_USER, pGroup->nHostId)));
		}
	}
}

void CGroupInfoLayout::UpdateExtInfo(const map<tstring, JsonValue>& mapData)
{
	tstring strValue;
	map<tstring, JsonValue>::const_iterator iter = mapData.find(_T("notice"));
	if(iter != mapData.end())
	{
		strValue = iter->second.GetString();
		CSkinView* pSkinView = GetChildById(IDC_EDITVIEW_GROUP_NOTICE);
		if(pSkinView)
		{
			pSkinView->SetText(strValue);
		}
	}
}