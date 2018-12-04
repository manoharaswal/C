#include <stdio.h>
#include <time.h>

int main()
{
	time_t ltime; /* calendar time */
	ltime=time(NULL); /* get current cal time */
	printf("%s",asctime( localtime(&ltime) ) );
	return 0;
}

