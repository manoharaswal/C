#include <stdio.h>

int main()
{
	int num;
	printf("Enter Number : ");
	scanf("%d",&num);

	if(!(num & (num - 1) && num))
		printf("Method 1 : %d is power of two.\n",num);
	else
		printf("Method 1 : %d is not power of two.\n",num);

	if(((~num + 1) & num) == num)
		printf("Method 2 : %d is power of two.\n",num);
	else
		printf("Method 2 : %d is not power of two.\n",num);

	return 0;
}
