#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Compile with: gcc -Wall -Werror -o fork fork.c

int main()
{
	int x = 1;
	int RetVal = fork();
	if(RetVal < 0){
		perror("fork() Failed.!!!");
		exit(-1);
	}
	if(RetVal == 0){
		printf("Child x = %d\n",++x);
	}else{
		printf("Parent x = %d\n",--x);
	}
	printf("Exiting with x = %d\n",x);
	return 0;
}
