#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEC_IN_Y(Y)	(dysize(Y) * 24 * 3600)
#define SEC_IN_D	(24 * 3600)
#define getUTCTime()	time(NULL)
#define getTime()	(getUTCTime() + (3600 * 5))

int monthdays[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int monthdays_leap[] = {
	31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int getYear()
{
	time_t t = getTime(), t1 = 0;

	int i;
	for (i = 1970; ; i++) {
		t1 += SEC_IN_Y(i);
		if (t1 >= t)
			break;
	}

	return i;
}

#define MONTH_FOR_YEAR(y) (__isleap(y) ? monthdays_leap : monthdays)

int getSecForYear(int y)
{
	time_t t = 0;

	int i;
	for (i = 1970; i <= y; i++)
		t += SEC_IN_Y(i);

	return t;
}

int getSecFortoday()
{
	int y = getYear();
	int d = getDays();
	time_t t = getSecForYear(y-1);

	int i;
	for (i = 0; i < d; i++)
		t += SEC_IN_D;

	return t;
}

int getDays()
{
	time_t t = getTime();
	int days = t / SEC_IN_D;
	int days_prev_year = getSecForYear(getYear()-1) / SEC_IN_D;

	int delta = days - days_prev_year;

	return delta;
}

int getMonth()
{
	int m = 0;
	int day = getDays();
	int y = getYear();
	int *mdays = MONTH_FOR_YEAR(y);

	int i;
	for (i = 0; i < day; i += mdays[m])
		m++;

	return m-1;
}

int getDayofMonth(int m)
{
	int day = 0;
	int y = getYear();
	int *mdays = MONTH_FOR_YEAR(y);

	int i;
	for (i = 0; i < 12 && i <= m; i++) {
		day += mdays[i];
	}
	return day;
}

int getDay()
{
	int m = getMonth();
	int days_prev = getDayofMonth(m - 1);
	int days_now = getDays();

	return days_now - days_prev;
}

int getDayofWeek()
{
	int day = 0;
	int m = getMonth();
	int y = getYear();
	int d = getDay();
	int *mdays = MONTH_FOR_YEAR(y);

	int i;
	for (i = 0; i < m; i++)
		day += mdays[i];

	day += d + y + (y / 4) - 2;

	return day % 7;
}

int getHour()
{
	int t = getSecFortoday();
	int t1 = getTime();

	int d = (t1 - t) / 3600;

	return d;
}

int getMinute()
{
	int t = getSecFortoday();
	t += getHour() * 3600;

	int t1 = getTime();

	int d = (t1 - t) / 60;

	return d;
}

int getSecond()
{
	int t = getSecFortoday();
	t += getHour() * 3600;
	t += getMinute() * 60;

	int t1 = getTime();

	int d = (t1 - t);

	return d;
}

