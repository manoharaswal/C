#include <stdio.h>

int myatoi(const char *string)
{
	int value = 0;
	if(string)
	{
		while(*string && (*string <= '9' && *string >= '0'))
		{
			value = (value * 10) + (*string - '0');
			string++;
		}
	}
	return value;
}

int main(int argc,char* argv[])
{
	char str[256] = {'\0'};
	printf("Enter String : ");
	scanf("%s",str);
	printf("%d\n",myatoi(str));
	return 0;
}
