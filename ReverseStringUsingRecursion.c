#include <stdio.h>

void RecursionReverse(char *str)
{
	if( *str == '\0' )
		return;
	RecursionReverse(str+1);
	printf("%c",*str);
}

main()
{
	RecursionReverse("Manohar Singh Aswal");
}

