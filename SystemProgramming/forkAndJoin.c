#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	pid_t PID = fork();
	if(PID < 0){
		perror("fork() failed.!!!");
		exit(-1);
	}
	if(PID != 0){
		printf("I am parent %d, my child is %d\n",getpid(),PID);
		/*Wait for child process to join*/
		wait(NULL);
	}else{
		printf("I'm the child %d, my parent is %d\n",getpid(),getppid());
		execl("/bin/echo", "echo", "Hello, World!", NULL);
	}
	return 0;
}
