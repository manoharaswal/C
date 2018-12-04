#include <stdio.h>

struct FullByte
{
	char first:4;
	char second:4;
};

union A
{
	char ch;
	struct FullByte byte;
};

int main()
{
	char ch = 100;
	union A a;

	a.ch = ch;

	printf("%d %d\n",a.byte.first,a.byte.second);
	return 0;
}
