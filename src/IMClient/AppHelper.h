#pragma once

class CChatLayout;
class CAppHelper
{
public:
	static time_t GetCurTime();
	static BOOL IsToday(uint64 unTime);
	static tstring ToTimeString(UINT nNumber);
	static tstring GetTime(uint64 unTime);
	static tstring GetDateTime(uint64 unTime);
	static tstring GetShortTime(uint64 unTime, bool bIncludeSecond = true);
	static tstring GetLongTime(uint64 unTime, bool bIncludeSecond = true);
	static tstring GetShortTimeBySecond(uint64 unSecond);
	static tstring GetMsgTimeText(time_t unTime, BOOL bShort);
	static tstring GetMonthTime(uint64 unTime);
	static tstring GetToMinuteTime(uint64 unTime);
	static void GetYearMonthDay(uint64 unTime, LONG& nYear, LONG& nMonth, LONG& nDay);
	static void GetHourMinuteSecond(uint64 unTime, LONG& nHour, LONG& nMinute, LONG& nSecond);
	static uint64 GetTime(LONG nYear, LONG nMonth, LONG nDay, LONG nHour, LONG nMinute, LONG nSecond);

	static BOOL IsInWeekEx(time_t unTime);
	static BOOL IsYesterdayEx(time_t unTime);
};