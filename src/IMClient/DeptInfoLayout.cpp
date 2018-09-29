#include <stdafx.h>
#include "DeptInfoLayout.h"

SKINUI_IMPLEMENT_DYNCREATE(CDeptInfoLayout)
CDeptInfoLayout::CDeptInfoLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
{

}

void CDeptInfoLayout::Init(uint32 nDeptId)
{
	SetLayoutWidth(FILL_PARENT);
	SetLayoutHeight(FILL_PARENT);
	SetLayout(_T("DeptDetailLayout.xml"));

	STDept* pDept = CDeptStore::GetInstance()->GetDeptById(nDeptId);
	if(pDept)
	{
		CSkinView* pSkinView = GetChildById(IDC_TEXTVIEW_DEPT_NAME);
		if(pSkinView)
		{
			pSkinView->SetText(pDept->strName);
		}

		pSkinView = GetChildById(IDC_TEXTVIEW_DEPT_INFO);
		if(pSkinView)
		{
			uint32 nMemberCount = 0;
			tstring strFormat = SkinUI::GetString(_T("IDS_DEPT_MEMBER_COUNT_FORMAT"));
			pSkinView->SetText(SkinUI::StringFormat(strFormat.c_str(), nMemberCount));
		}
	}
}