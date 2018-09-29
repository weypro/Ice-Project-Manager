#pragma once
#include "AddressBookView.h"

class CGroupItem : public CSkinListItem
{
public:
	enum
	{
		IDC_AVATAR = 100011,
		IDC_NAME = 100012,
	};

public:
	CGroupItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Init(uint64 nGroupId);

public:
	uint64 GetGroupId() { return m_nGroupId; }

public:
	virtual void HandleBuildFinish();

private:
	uint64	m_nGroupId;
};

class CGroupListView : public CSkinListView
{
public:
	CGroupListView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Load();
	void AddGroupItem(uint64 nGroupId);
};

class CGroupMemberItem : public CUserItem
{
public:
	CGroupMemberItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()
};

class CGroupMemberListView : public CSkinListView
{
public:
	CGroupMemberListView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Load(uint64 nGroupId);

protected:
	void AddGroupMemberItem(uint64 nUserId);

private:
	uint64	m_nGroupId;
};