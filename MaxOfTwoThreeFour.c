#include <stdio.h>

#define max2(x,y) ((x)>(y)?(x):(y))

#define max3(a,b,c) (((a>b)?a:b)>c?((a>b)?a:b):c)

#define max4(a,b,c,d) max2(max2((a),(b)),max2((c),(d)))

int main()
{
	printf("Max (10,40)      : %d\n", max2(10,40));		
	printf("Max (10,40,30)   : %d\n", max3(10,40,30));		
	printf("Max (10,40,60,50): %d\n", max4(10,40,60,50));
	return 0;		
}
