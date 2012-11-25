#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *Week[] = {
	"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"
};

char *Month[] = {
	"Jan", "Feb", "Mar", "Apr", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

int main(int argc, char *argv[])
{
	int m = getMonth();
	int d = getDay();
	int y = getYear();
	int w = getDayofWeek();
	int h = getHour();
	int mm = getMinute();
	int s = getSecond();

	printf("%d:%d:%d %s %s %d %d\n", h, mm, s, Week[w], Month[m-1], d+1, y);
	
	return 0;
}

