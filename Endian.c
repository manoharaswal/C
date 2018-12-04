#include<stdio.h>

union Test
{
	unsigned int i;
	unsigned char c[2];
};

int main()
{

	union Test a = {1};

	printf("%d %d\n",a.c[0],a.c[1]);

	if(a.c[0] == 1)
		printf("Little Endian\n");
	else 
		printf("Big Endian\n");
	return 0;
}
