#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid,status,childpid;
	printf("Parent Process PID : %d\n",getpid());

	pid = fork();

	if(pid > 0)
	{
		printf("Parent Process with PID : %d and PPID : %d\n",getpid(),getppid());
		/*wait for a child to terminate.*/
		childpid = wait(&status);
		printf("Child wiht PID : %d terminated with exit code %d\n",childpid,status >> 8);
	}
	else if(pid == 0)
	{
		printf("Child Process with PID : %d and PPID : %d\n",getpid(),getppid());
		exit(50); 
	}
	printf("PID %d terminates.\n",pid);
}
