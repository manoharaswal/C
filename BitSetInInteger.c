#include<stdio.h>

int countSetBits(int n)
{
	unsigned int count = 0;
	while (n)
	{
		n &= (n-1) ;
		count++;
	}
	return count;
}

int main()
{
	int i = 0;
	printf("Enter the number : ");
	scanf("%d",&i);
	printf("Number of bit set [ %d ]\n", countSetBits(i));
	return 0;
}
