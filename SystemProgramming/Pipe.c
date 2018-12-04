#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int fd[2], ret;
	pid_t childpid;
	char string[] = "Hello, World!\n";
	char Buffer[80] = {0};

	if(pipe(fd) != 0)
	{
		perror("Error in creating a pipe");
		exit(EXIT_FAILURE);
	}

	if((childpid = fork()) < 0)
	{
		perror("Error in fork");
		exit(EXIT_FAILURE);
	}

	if(childpid == 0) //child process write to a pipe.
	{
		/*Child process closes up input side or read end of pipe*/
		close(fd[0]);

		/*Send "string" through the output side of pipe*/
		write(fd[1],string,(strlen(string) + 1)); // write returns the no. of bytes written.

		close(fd[1]);
		exit(0);
	}
	else //parents reads from a pipe.
	{
		/*Parent process closes up output side or write end of pipe*/
		close(fd[1]);

		/*Read in a string from a pipe*/
		read(fd[0],Buffer,sizeof(Buffer)); //read returns the no. of bytes read.
		printf("\nRecieved Buffer : %s\n",Buffer);
		close(fd[0]);
		exit(0);
	}
	return 0;
}
