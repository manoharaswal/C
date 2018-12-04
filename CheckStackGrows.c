#include <stdio.h>
#include <stdlib.h>

void stack(int *var1)
{
	int var2 = 0;

	printf("Address of first local variable : %p\n",var1);
	printf("Address of second local variable : %p",&var2);

	if(var1 < &var2)
		printf("\nStack Grows Downwards.\n");
	else
		printf("\nStack Grows Upwards.\n");
}

int main()
{
	int var1  = 0;
	stack(&var1);
	return 0;
}

