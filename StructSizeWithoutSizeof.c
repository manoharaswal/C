#include <stdio.h>

struct MyStruct
{
	int i;
	int j;
	char c;
};

int main()
{
	struct MyStruct *p=0;
	int size = ((char*)(p+1))-((char*)p);
	printf("SIZE : [%d]\n", size);
	return 0;
}

