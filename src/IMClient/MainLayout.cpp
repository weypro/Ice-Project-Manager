#include <stdafx.h>
#include "MainLayout.h"
#include "ConversationLayout.h"
#include "AddressBookLayout.h"
#include "UserInfoDialog.h"
#include "SelectUserDialog.h"

class CSlideParentLayout : public CSkinRelativeLayout
{
public:
	CSlideParentLayout(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	virtual void HandleLButtonDown(CPoint point, BOOL& bHandle);
};

SKINUI_IMPLEMENT_DYNCREATE(CSlideParentLayout)
CSlideParentLayout::CSlideParentLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
{

}

static void GetAllVisibleSlideAnimationHost(CSkinView* pView, list<CSlideAnimationHost*>& lstVisibleSlideAnimationHost)
{
	const list<CSkinView*>& lstChild = pView->GetAllChild();
	for(list<CSkinView*>::const_iterator iter = lstChild.begin(); iter != lstChild.end(); ++iter)
	{
		if((*iter)->IsVisible())
		{
			if((*iter)->GetClassName() == _T("CSlideAnimationHost"))
			{
				lstVisibleSlideAnimationHost.push_back(static_cast<CSlideAnimationHost*>(*iter));
			}
			else
			{
				GetAllVisibleSlideAnimationHost(*iter, lstVisibleSlideAnimationHost);
			}
		}
	}
}

void CSlideParentLayout::HandleLButtonDown(CPoint point, BOOL& bHandle)
{
	list<CSlideAnimationHost*> lstVisibleSlideAnimationHost;
	GetAllVisibleSlideAnimationHost(this, lstVisibleSlideAnimationHost);
	for(list<CSlideAnimationHost*>::iterator iter = lstVisibleSlideAnimationHost.begin(); iter != lstVisibleSlideAnimationHost.end(); ++iter)
	{
		(*iter)->Hide();
	}

	CSkinRelativeLayout::HandleLButtonDown(point, bHandle);
}
SKINUI_BEGIN_MESSAGE_MAP(CMainLayout, CSkinRelativeLayout)
	ON_SKINUI_COMMAND(IDC_AVATAR, OnBtnClickedUserInfo)
	ON_SKINUI_COMMAND(IDC_BUTTON_CREATE_GROUP, OnBtnClickedCreateGroup)
SKINUI_END_MESSAGE_MAP()

SKINUI_IMPLEMENT_DYNCREATE(CMainLayout)
CMainLayout::CMainLayout(CSkinView* pParent)
: CSkinRelativeLayout(pParent)
, m_pLayoutConversation(NULL)
, m_pLayoutAddressBook(NULL)
{

}

void CMainLayout::HandleBuildFinish()
{
	CSkinRelativeLayout::HandleBuildFinish();

	m_pLayoutConversation = static_cast<CConversationLayout*>(GetChildById(IDC_LAYOUT_CONVERSATION));
	m_pLayoutAddressBook = static_cast<CAddressBookLayout*>(GetChildById(IDC_LAYOUT_ADDRESS_BOOK));

	CAvatarView* pAvatarView = static_cast<CAvatarView*>(GetChildById(IDC_AVATAR));
	if(pAvatarView)
	{
		pAvatarView->Init(ConvId(CONV_TYPE_USER, theApp.GetUserId()));
	}
}

void CMainLayout::OnBtnClickedUserInfo(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CUserInfoDialog::Show(GetOwner()->GetHWND(), theApp.GetUserId());
}

void CMainLayout::OnBtnClickedCreateGroup(UINT uNotifyCode, int nID, CSkinView* pView)
{
	CSelectUserDialog dlg(_T("IDS_CREATE_GROUP"), MAX_GROUP_MEMBER);
	if(dlg.DoModal(GetOwner()->GetHWND()) == IDOK)
	{
		//To Do
		//´´½¨ÈºÁÄ
		list<uint64> lstMember;
		dlg.GetSelected(lstMember);
	}
}