#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int m = getMonth();
	int d = getDay();
	int y = getYear();

	printf("%d/%d/%d\n", m+1, d+1, y-2000);
	
	return 0;
}

