// Conditon so that neither Hello or World is printed.

/*
if(condition)
{
	printf("Hello");
}
else
{
	printf("world");
}
*/

#include<stdio.h>

int main()
{
	if(fclose(stdout))
	{
		printf("Hello");
	}
	else
	{
		printf("World");
	}
	return 0;
}
