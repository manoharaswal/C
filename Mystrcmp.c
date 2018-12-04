#include <stdio.h>

int mystrcmp(const char *s1,const char *s2);

int main()
{
	printf("\n strcmp() = [%d]\n",mystrcmp("A","AB"));
	printf("\n strcmp() = [%d]\n",mystrcmp("A","B"));
	printf("\n strcmp() = [%d]\n",mystrcmp("B","A"));
	return(0);
}

int mystrcmp(const char *s1,const char *s2)
{
	while(*s1 == *s2)
	{
		if(*s1 == '\0')
			return(0);
		s1++;
		s2++;
	}
	return(*s1 - *s2);
}
