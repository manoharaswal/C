#include "stdio.h"

int main()
{

	int *ptr = (void *)0;
	char *str = (void *)0;
	float *ftr = (void *)0;
	ptr++;
	str++;
	ftr++;
	printf("Size of int   = %d\n",(int)ptr);
	printf("Size of char  = %d\n",(int)str);
	printf("Size of float = %d\n",(int)ftr);
	return 0;
}

