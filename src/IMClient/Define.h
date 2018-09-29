#pragma once

#define ITEM_HEIGHT_40					40
#define ITEM_HEIGHT_60					60
#define MSG_MARGIN_10					10
#define MSG_MARGIN_5					5

#define MAX_GROUP_MEMBER				500
#define MAX_SYNC_MESSAGE				20

#define PRE_DAY							(60 * 60 * 24)
#define PRE_MINUTE						(60)

enum
{
	ID_MENU_OPEN_CLIENT = 1011,
	ID_MENU_QUIT_CLIENT = 1012,

	ID_MENU_PERSONAL_INFO = 1021,
	ID_MENU_SYSTEM_CONFIG = 1022,
	ID_MENU_MODIFY_PASSWORD = 1023,
	ID_MENU_QUIT_LOGIN = 1024,

	ID_MENU_SEND_ENTER = 1061,
	ID_MENU_SEND_CTRL_ENTER = 1062,
};

enum
{
	TIMER_LOGIN = 1000,
};

enum
{
	MALE = 0,
	FEMALE = 1,
};

enum
{
	CONV_TYPE_USER = 0,
	CONV_TYPE_GROUP = 1,
};

struct STUser
{
	uint64 nId;
	uint32 nDeptId;
	uint32 nGender;

	tstring strName;
	tstring strAccount;
	tstring strPosition;

	uint32 nIndex;

	STUser()
	{
		this->nId = 0;
		this->nDeptId = 0;
		this->nGender = MALE;
		this->nIndex = 999;
	}
};

struct STDept
{
	uint32 nId;
	uint32 nParentDeptId;
	tstring strName;
	uint32 nIndex;

	STDept()
	{
		this->nId = 0;
		this->nParentDeptId = 0;
		this->nIndex = 999;
	}
};

struct STGroup
{
	uint64 nId;
	uint64 nHostId;
	tstring strName;

	STGroup()
	{
		this->nId = 0;
		this->nHostId = 0;
	}
};

struct ConvId
{
	uint32 nType;
	uint64 nId;

	ConvId()
	{
		this->nType = CONV_TYPE_USER;
		this->nId = 0;
	}

	ConvId(uint32 nType, uint64 nId)
	{
		this->nType = nType;
		this->nId = nId;
	}

	bool operator==(ConvId convId)const
	{
		return this->nType == convId.nType && this->nId == convId.nId;
	}

	bool operator>(ConvId convId)const
	{
		if(this->nType == convId.nType)
		{
			return this->nId > convId.nId;
		}
		else
		{
			return this->nType > convId.nType;
		}
	}

	bool operator<(ConvId convId)const
	{
		if(this->nType == convId.nType)
		{
			return this->nId < convId.nId;
		}
		else
		{
			return this->nType < convId.nType;
		}
	}
};

struct STConv
{
	ConvId convId;
	uint64 nMsgId;
	uint32 nMsgType;
	uint64 nMsgTime;
	uint64 nMsgSender;
	tstring strMsgContent;

	STConv()
	{
		this->nMsgId = 0;
		this->nMsgTime = 0;
		this->nMsgSender = 0;
	}
};

struct STExtInfo
{
	tstring strExtInfo;

	STExtInfo()
	{

	}

	STExtInfo(const tstring& strExtInfo)
	{
		this->strExtInfo = strExtInfo;
	}
};

enum
{
	MSG_TYPE_TEXT = 0,
};

struct MsgId
{
	uint64 nServerId;
	uint64 nClientId;

	MsgId()
	{
		this->nServerId = 0;
		this->nClientId = 0;
	}

	MsgId(uint64 nServerId, uint64 nClientId)
	{
		this->nServerId = nServerId;
		this->nClientId = nClientId;
	}

	MsgId(const MsgId& msgId)
	{
		this->nServerId = msgId.nServerId;
		this->nClientId = msgId.nClientId;
	}

	bool operator==(const MsgId& msgId)const
	{
		return this->nServerId == msgId.nServerId && this->nClientId == msgId.nClientId;
	}

	bool operator!=(const MsgId& msgId)const
	{
		return this->nServerId != msgId.nServerId || this->nClientId != msgId.nClientId;
	}

	bool operator>(const MsgId& msgId)const
	{
		if(this->nServerId == msgId.nServerId)
		{
			return this->nClientId > msgId.nClientId;
		}
		else
		{
			return this->nServerId > msgId.nServerId;
		}
	}

	bool operator<(const MsgId& msgId)const
	{
		if(this->nServerId == msgId.nServerId)
		{
			return this->nClientId < msgId.nClientId;
		}
		else
		{
			return this->nServerId < msgId.nServerId;
		}
	}
};

struct STMsg
{
	MsgId msgId;

	uint32 nMsgType;
	uint64 nMsgTime;
	uint64 nMsgSender;

	tstring strMsgContent;

	STMsg()
	{
		this->nMsgType = MSG_TYPE_TEXT;
		this->nMsgTime = 0;
		this->nMsgSender = 0;
	}
};