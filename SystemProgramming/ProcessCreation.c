#include <stdio.h>
#include <stdlib.h>

#define SLEEP_TIME 0
#define SUCCESS	0
#define FAILURE 1

int main(int argc,char *argv[])
{
	int ProcessId;
	int SleepTime;

	if(argc == 1)
		SleepTime = SLEEP_TIME;
	else
		SleepTime = atoi(argv[1]);

	ProcessId = fork();

	if(ProcessId > 0){
		printf("Parent Process Running.\n");
	}else if(ProcessId == 0){
		sleep(SleepTime);
		printf("Child Process Running.\n");
	}else
		return FAILURE;
	return SUCCESS;
}
