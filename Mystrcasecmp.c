#include <stdio.h>
#include <string.h>

static int lowercase(const char *s)
{
	return tolower(* (const unsigned char *) s);
}

static int Mystrcasecmp(const char *s1, const char *s2)
{
	int diff;
	do
	{
		diff = lowercase(s1++) - lowercase(s2++);
	} while (diff == 0 && s1[-1] != '\0');
	return diff;
}

int main()
{
	char *str1 = "Manohar";
	char *str2 = "manohar";

	if(!Mystrcasecmp(str1,str2))
		printf("Both String are same\n");
	else
		printf("Both String are different\n");
	return 0;
}
