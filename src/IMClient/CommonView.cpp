#include <stdafx.h>
#include "CommonView.h"
#include "ChatLayout.h"

SKINUI_IMPLEMENT_DYNCREATE(CAvatarView)
CAvatarView::CAvatarView(CSkinView* pParent)
: CSkinButton(pParent)
{
	SetCursor(ID_CURSOR_HAND);
}

void CAvatarView::Init(ConvId convId)
{
	m_convId = convId;
}

void CAvatarView::DrawForeground(HDC hdc)
{
	CRect rect = GetRect();
	if(rect.IsRectEmpty())
	{
		return;
	}

	tstring strAvatar;
	if(m_convId.nType == CONV_TYPE_USER)
	{
		strAvatar = _T("UserIcon.png");
	}
	else if(m_convId.nType == CONV_TYPE_GROUP)
	{
		strAvatar = _T("GroupIcon.png");
	}

	if(!strAvatar.empty())
	{
		Image* pImage = SkinUI::GetImage(strAvatar);
		if(pImage)
		{
			
			Bitmap bmp(rect.Width(), rect.Height());

			Graphics graphics(&bmp);
			graphics.SetSmoothingMode(SmoothingModeAntiAlias);
			graphics.SetCompositingQuality(CompositingQualityAssumeLinear);
			graphics.SetInterpolationMode(InterpolationModeHighQualityBicubic);
			graphics.DrawImage(pImage, Rect(0, 0, rect.Width(), rect.Height()), 0, 0, pImage->GetWidth(), pImage->GetHeight(), UnitPixel);

			SkinUI::DrawImage(hdc, GetRect(), &bmp, 3);
		}
	}
}

SKINUI_IMPLEMENT_DYNCREATE(CConversationNameView)
CConversationNameView::CConversationNameView(CSkinView* pParent)
: CSkinTextView(pParent)
{

}

void CConversationNameView::Init(ConvId convId)
{
	m_convId = convId;
	SetText(theApp.GetConversationName(convId));
}

SKINUI_IMPLEMENT_DYNCREATE(CChatInputEditView)
CChatInputEditView::CChatInputEditView(CSkinView* pParent)
: CSkinEditView(pParent)
{

}

CChatLayout* CChatInputEditView::GetChatLayout()
{
	CChatLayout* pChatLayout = dynamic_cast<CChatLayout*>(GetParent()->GetParent()->GetParent());
	if(pChatLayout)
	{
		return pChatLayout;
	}
	return NULL;
}

void CChatInputEditView::HandleKeyDown(TCHAR vkey, UINT repeats, UINT code, BOOL& bHandle)
{
	if(!bHandle)
	{
		CChatLayout* pChatLayout = GetChatLayout();
		if(pChatLayout)
		{
			pChatLayout->PreHandleKeyDown(vkey, repeats, code, bHandle);
		}
	}

	if(!bHandle)
	{
		CSkinEditView::HandleKeyDown(vkey, repeats, code, bHandle);
	}
}

SKINUI_BEGIN_MESSAGE_MAP(CSlideHost, CSlideAnimationHost)
	ON_SKINUI_COMMAND(IDC_BUTTON_CLOSE, OnBtnClickedClose)
SKINUI_END_MESSAGE_MAP()

CSlideHost::CSlideHost(CSkinView* pParent)
: CSlideAnimationHost(pParent)
{
	SetTransparent(FALSE);
}

void CSlideHost::OnBtnClickedClose(UINT uNotifyCode, int nID, CSkinView* pView)
{
	Hide();
}

SKINUI_IMPLEMENT_DYNCREATE(CTabTextView)
CTabTextView::CTabTextView(CSkinView* pParent)
: CSkinTextView(pParent)
{

}

void CTabTextView::DrawForeground(HDC hdc)
{
	tstring strFontColor = _T("ID_COLOR_TEXT");
	CSkinRadioButton* pRadioButton = static_cast<CSkinRadioButton*>(GetParent());
	if(pRadioButton)
	{
		if(pRadioButton->IsChecked() || pRadioButton->GetState() != VS_NORMAL)
		{
			strFontColor = _T("ID_COLOR_TAB_TEXT");
		}
	}
	SkinUI::DrawText(hdc, GetRect(), m_strTextDraw, GetFontStyle(), strFontColor, GetDrawTextFormat());
}

SKINUI_IMPLEMENT_DYNCREATE(CTabCtrl)
CTabCtrl::CTabCtrl(CSkinView* pParent)
: CSkinRadioGroup(pParent)
{

}

void CTabCtrl::SetRect(const CRect& rect)
{
	CSkinLayout::SetRect(rect);

	LONG nIndex = 0;
	LONG nLeft = rect.left;
	const list<CSkinView*>& lstChild = GetAllChild();
	for(list<CSkinView*>::const_iterator iter = lstChild.begin(); iter != lstChild.end(); ++iter, ++nIndex)
	{
		CRect rcView(rect);
		rcView.left = nLeft;
		if(nIndex != (lstChild.size() - 1))
		{
			rcView.right = rcView.left + rect.Width() / lstChild.size();
		}
		(*iter)->SetRect(rcView);
		nLeft = rcView.right;
	}
}