#include <stdio.h>
#include <malloc.h>

#define MAXROW 3
#define MAXCOL 4

int main( )
{
	int *p,i,j;
	p = (int *)malloc(MAXROW * MAXCOL * sizeof(int));
	for(i = 0;i < MAXROW;i++)
	{
		for(j = 0;j < MAXCOL;j++)
		{
			p[i*MAXCOL+j] = i;
			printf("%d",p[i*MAXCOL+j]);
		}
		printf("\n");
	}
	return 0;
}
