/*
	Output will be "10 20". 
	The %.0d forces compiler to print non negative values. As c is 0, it will not be printed.
*/
#include <stdio.h>

int main()
{
	int a = 10, b = 20, c = 0;
	printf("%d %d %.0d\n", a, b, c);
	return 0;
}
