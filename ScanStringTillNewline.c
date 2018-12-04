#include <stdio.h>

int main()
{
	char str[256] = {0};
	printf("Enter String   : ");
	scanf("%[^\n]", str);
	printf("Entered String : %s\n",str);
	return 0;
}
