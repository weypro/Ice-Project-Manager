#include "stdafx.h"
#include "AppHelper.h"
#include "ChatLayout.h"

time_t CAppHelper::GetCurTime()
{
	time_t timeCur = time(NULL);
	return timeCur;
}

BOOL CAppHelper::IsToday(uint64 unTime)
{
	tm tmTime;
	{
		time_t time = unTime;
		localtime_s(&tmTime, &time);
	}

	tm tmCur;
	{
		time_t timeCur = GetCurTime();
		localtime_s(&tmCur, &timeCur);
	}

	if(tmTime.tm_year == tmCur.tm_year && tmTime.tm_mon == tmCur.tm_mon && tmTime.tm_mday == tmCur.tm_mday)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

tstring CAppHelper::ToTimeString(UINT nNumber)
{
	tstring strNumber;
	if(nNumber < 10)
	{
		strNumber += _T("0");
	}

	strNumber += SkinUI::IntToString(nNumber);
	return strNumber;
}

tstring CAppHelper::GetTime(uint64 unTime)
{
	tm tmTime;
	{
		time_t time = unTime;
		localtime_s(&tmTime, &time);
	}

	tm tmCur;
	{
		time_t timeCur = GetCurTime();
		localtime_s(&tmCur, &timeCur);
	}

	if(tmTime.tm_year == tmCur.tm_year && tmTime.tm_mon == tmCur.tm_mon && tmTime.tm_mday == tmCur.tm_mday)
	{
		return CAppHelper::GetShortTime(unTime);
	}
	else
	{
		return CAppHelper::GetLongTime(unTime);
	}
}

tstring CAppHelper::GetDateTime(uint64 unTime)
{
	tm tm;
	tstring strTime;
	time_t time = unTime;
	localtime_s(&tm, &time);

	strTime += CAppHelper::ToTimeString(tm.tm_year + 1900) + _T("-");
	strTime += CAppHelper::ToTimeString(tm.tm_mon + 1) + _T("-");
	strTime += CAppHelper::ToTimeString(tm.tm_mday);

	return strTime;
}

tstring CAppHelper::GetShortTime(uint64 unTime, bool bIncludeSecond)
{
	tm tm;
	tstring strTime;
	time_t time = unTime;
	localtime_s(&tm, &time);

	strTime += CAppHelper::ToTimeString(tm.tm_hour) + _T(":");
	strTime += CAppHelper::ToTimeString(tm.tm_min) + _T(":");
	if(bIncludeSecond)
	{
		strTime += CAppHelper::ToTimeString(tm.tm_sec);
	}

	return strTime;
}

tstring CAppHelper::GetShortTimeBySecond(uint64 unSecond)
{
	tstring strTime;
	uint64 nHour = unSecond / 3600;
	uint64 nMin = (unSecond - nHour * 3600) / 60;
	uint64 nSec = unSecond - nHour * 3600 - nMin * 60;
	strTime += CAppHelper::ToTimeString(static_cast<UINT>(nHour)) + _T(":");
	strTime += CAppHelper::ToTimeString(static_cast<UINT>(nMin)) + _T(":");
	strTime += CAppHelper::ToTimeString(static_cast<UINT>(nSec));
	return strTime;
}

static time_t GetDayTimeFirstSecond(time_t unTime)
{
	tm tmTime;
	localtime_s(&tmTime, &unTime);
	tmTime.tm_hour = 0;
	tmTime.tm_min = 0;
	tmTime.tm_sec = 0;
	return mktime(&tmTime);
}

#define TIME_ONE_DAY	(24*60*60)
static BOOL IsYesterday(time_t unTime)
{
	time_t nOffset = GetDayTimeFirstSecond(CAppHelper::GetCurTime()) - GetDayTimeFirstSecond(unTime);
	if(nOffset == TIME_ONE_DAY)
	{
		return TRUE;
	}
	return FALSE;
}

BOOL CAppHelper::IsYesterdayEx(time_t unTime)
{
	return IsYesterday(unTime);
}

static BOOL IsInWeek(time_t unTime)
{
	time_t unCurTime = CAppHelper::GetCurTime();
	time_t nOffset = GetDayTimeFirstSecond(unCurTime) - GetDayTimeFirstSecond(unTime);
	if(nOffset > 0 && nOffset <= TIME_ONE_DAY*7)
	{
		tm tmTime;
		localtime_s(&tmTime, &unTime);

		tm tmCurTime;
		localtime_s(&tmCurTime, &unCurTime);

		if(tmTime.tm_wday < tmCurTime.tm_wday)
		{
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CAppHelper::IsInWeekEx(time_t unTime)
{
	return IsInWeek(unTime);
}

tstring CAppHelper::GetMsgTimeText(time_t unTime, BOOL bShort)
{
	if(unTime == 0)
	{
		return tstring();
	}

	tm tmTime;
	localtime_s(&tmTime, &unTime);

	tstring strTime;
	//今天
	if(IsToday(unTime))
	{
		strTime += CAppHelper::ToTimeString(tmTime.tm_hour) + _T(":");
		strTime += CAppHelper::ToTimeString(tmTime.tm_min);
	}
	//昨天
	else if(IsYesterday(unTime))
	{
		strTime = SkinUI::GetString(_T("IDS_YESTERDAY"));
	}
	//本星期内
	else if(IsInWeek(unTime))
	{
		tstring strWeek = SkinUI::StringFormat(_T("IDS_WEEK%d"), tmTime.tm_wday);
		strTime = SkinUI::GetString(strWeek);
	}
	else
	{
		strTime += CAppHelper::ToTimeString(tmTime.tm_mon + 1) + _T("-");
		strTime += CAppHelper::ToTimeString(tmTime.tm_mday);
	}

	if(!bShort && !IsToday(unTime))
	{
		strTime += _T(" ");
		strTime += CAppHelper::ToTimeString(tmTime.tm_hour) + _T(":");
		strTime += CAppHelper::ToTimeString(tmTime.tm_min);
	}
	return strTime;
}

tstring CAppHelper::GetMonthTime(uint64 unTime)
{
	tm tm;
	tstring strTime;
	time_t time = unTime;
	localtime_s(&tm, &time);

	strTime += CAppHelper::ToTimeString(tm.tm_year + 1900) + _T("-");
	strTime += CAppHelper::ToTimeString(tm.tm_mon + 1);

	return strTime;
}

tstring CAppHelper::GetToMinuteTime(uint64 unTime)
{
	tm tm;
	tstring strTime;
	time_t time = unTime;
	localtime_s(&tm, &time);

	strTime += CAppHelper::ToTimeString(tm.tm_year + 1900) + _T("-");
	strTime += CAppHelper::ToTimeString(tm.tm_mon + 1) + _T("-");
	strTime += CAppHelper::ToTimeString(tm.tm_mday) + _T(" ");

	strTime += CAppHelper::ToTimeString(tm.tm_hour) + _T(":");
	strTime += CAppHelper::ToTimeString(tm.tm_min);

	return strTime;
}

tstring CAppHelper::GetLongTime(uint64 unTime, bool bIncludeSecond)
{
	tm tm;
	tstring strTime;
	time_t time = unTime;
	localtime_s(&tm, &time);

	strTime += CAppHelper::ToTimeString(tm.tm_year + 1900) + _T("-");
	strTime += CAppHelper::ToTimeString(tm.tm_mon + 1) + _T("-");
	strTime += CAppHelper::ToTimeString(tm.tm_mday) + _T(" ");
	strTime += CAppHelper::GetShortTime(unTime, bIncludeSecond);

	return strTime;
}

void CAppHelper::GetYearMonthDay(uint64 unTime, LONG& nYear, LONG& nMonth, LONG& nDay)
{
	tm tm;
	time_t time = unTime;
	localtime_s(&tm, &time);

	nYear = tm.tm_year + 1900;
	nMonth = tm.tm_mon+1;
	nDay = tm.tm_mday;
}

void CAppHelper::GetHourMinuteSecond(uint64 unTime, LONG& nHour, LONG& nMinute, LONG& nSecond)
{
	tm tm;
	time_t time = unTime;
	localtime_s(&tm, &time);

	nHour = tm.tm_hour;
	nMinute = tm.tm_min;
	nSecond = tm.tm_sec;
}

uint64 CAppHelper::GetTime(LONG nYear, LONG nMonth, LONG nDay, LONG nHour, LONG nMinute, LONG nSecond)
{
	tm tm;
	tm.tm_year = nYear - 1900;
	tm.tm_mon = nMonth - 1;
	tm.tm_mday = nDay;
	tm.tm_hour = nHour;
	tm.tm_min = nMinute;
	tm.tm_sec = nSecond;
	time_t time = mktime(&tm);
	return time;
}