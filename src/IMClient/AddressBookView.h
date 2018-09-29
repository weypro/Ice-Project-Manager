#pragma once

class CDeptItem : public CSkinTreeItem
{
public:
	enum
	{
		IDC_NAME = 100012,
	};

public:
	CDeptItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Init(uint32 nDeptId, const tstring& strLayout);

public:
	uint32 GetDeptId() { return m_nDeptId; }

public:
	virtual void HandleBuildFinish();

private:
	uint32	m_nDeptId;
};

class CUserItem : public CSkinListItem
{
public:
	enum
	{
		IDC_AVATAR = 100011,
		IDC_NAME = 100012,
	};

public:
	CUserItem(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Init(uint64 nUserId, const tstring& strLayout);

public:
	uint64 GetUserId() { return m_nUserId; }

public:
	virtual void HandleBuildFinish();

private:
	uint64	m_nUserId;
};

class CCorpTreeView : public CSkinCheckTreeView
{
public:
	CCorpTreeView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void Load(const tstring& strLayoutUserItem, const tstring& strLayoutDeptItem);
	CDeptItem* AddDeptItem(CDeptItem* pParentDeptItem, uint32 nDeptId);
	CUserItem* AddUserItem(CDeptItem* pDeptItem, uint64 nUserId);

protected:
	tstring		m_strLayoutUserItem;
	tstring		m_strLayoutDeptItem;
};

class CSelectedListView : public CSkinListView
{
public:
	CSelectedListView(CSkinView* pParent);
	SKINUI_DECLARE_DYNCREATE()

public:
	void AddUserItem(uint64 nUserId);
	void DeleteUserItem(uint64 nUserId);
};