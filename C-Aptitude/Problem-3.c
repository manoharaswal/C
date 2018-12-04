/*
	Output is 1. 
	Even if this is function pointer, the sizeof will get the return type and returns the size of that data type.
	Here, the return type is char, so the output is 1.
*/

#include <stdio.h>

char fun()
{
	char c = 'A';
	printf("Hello World");
	return c;
}

int main()
{
	printf("%lu\n",sizeof(fun()));
	return 0;
}
