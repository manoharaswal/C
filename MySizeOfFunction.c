#include <stdio.h>

#define Mysizeof(t) (char*)(&t+1) -(char*)(&t)   

int main()
{
	char arr[40];
	int num[10];
	int i;
	char ch;
	float f;
	printf("Size of Char Array = %ld\n",Mysizeof(arr));
	printf("Size of Int Array  = %ld\n",Mysizeof(num));
	printf("Size of a Char     = %ld\n",Mysizeof(ch));
	printf("Size of an Int     = %ld\n",Mysizeof(i));
	printf("Size of an Float   = %ld\n",Mysizeof(f));
	return 0;
}
