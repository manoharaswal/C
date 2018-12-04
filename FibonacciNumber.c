#include <stdio.h>
#include <math.h>

int main()
{
	int num;
	int a,b;
	printf("Enter Number : ");
	scanf("%d",&num);
	a = sqrt(5 * num * num + 4);
	b = sqrt(5 * num * num - 4);
	if(((a * a) == (5 * num * num + 4)) || ((b * b) == (5 * num * num - 4)))
		printf("%d is Fibonacci Number\n",num);
	else
		printf("%d is not a Fibonacci Number\n",num);
	return 0;
}
