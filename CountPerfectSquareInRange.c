#include <stdio.h>
#include <math.h>

#define START 3
#define STOP 20

int main()
{
	int i=0;
	int c = 0;
	while( (i*i) < START )
		i++;
	while( (i*i) < STOP )
	{
		printf("%d ",i*i);
		c++;
		i++;
	}
	printf("\nMethod 1 : %d\n",c);
	printf("Method 2 : %d\n",(int)(floor(sqrt(STOP))-ceil(sqrt(START))+1));
	return 0;
}

