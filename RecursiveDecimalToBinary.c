#include<stdio.h>

void Binary(int num)
{
	int temp;
	if(num)
	{
		temp = num % 2;
		Binary(num >>= 1);
		printf("%d",temp);
	}
}

int main()
{
	int num;
	printf("Enter a number : ");
	scanf("%d", &num);
	Binary(num);
	printf("\n");
	return(0);
}

