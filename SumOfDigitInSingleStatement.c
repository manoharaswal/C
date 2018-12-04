# include<stdio.h>

void main()
{
	int num = 0;
	int sum = 0;

	printf("Enter Number : ");
	scanf("%d",&num);

	for(;num>0;sum+=num%10,num/=10);
	printf("sum = [%d]\n", sum);
}

