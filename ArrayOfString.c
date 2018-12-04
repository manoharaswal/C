#include <stdio.h>
#include "stdlib.h"
#include "string.h"

/*Will be at the run time*/
#define stringNum 3 

struct StrArray
{
	char **data;
};

struct StrArray stringArray;


void arrayofstring(struct StrArray *ptr,char *string,int i)
{
	char **tmp;
	if((tmp = realloc(ptr->data,(sizeof *tmp)*(i+1)))==NULL)
		printf("reallac failed \n");
	ptr->data = tmp;
	if((ptr->data[i] = malloc(strlen(string)+1)) == NULL)
		printf("malloc failed\n");
	strcpy(ptr->data[i],string);
}

void main()
{
	int stringSize,i;
	char string[200];

	/*instead of for loop we will be reading the string from the file*/
	for (i = 0; i < stringNum; i++) 
	{
		printf("Enter string : ");
		/*string will read from the file*/
		scanf("%s",string); 
		arrayofstring(&stringArray,string,i);
	}

	for (i = 0; i < stringNum; i++)
		printf("output string %s\n",stringArray.data[i]);
}
