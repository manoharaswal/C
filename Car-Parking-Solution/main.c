/** PROGRAM NAME : CAR PARKING SYSTEM:
* This program is developed in c programing language using ipc concepts like message queue, multithreading, mutex,shared memory etc.
*/
#include "include/common.h"
#include "src/entry_system.c"
#include "src/exit_system.c"

struct entry_system *entry = NULL;
struct driver_info *driver = NULL;

/**
* Main function which will create two processes one for entry system & another one is for exit system also execute threads within the process.
*You can select entry system or exit system from the main function.
*Entry system is having two gate and exit system have three exit gate.
*/

int main()
{
	char option;
	char EntryOption;
	char ExitOption;
	int pid;
	pthread_t pt_id1, pt_id2,et_id1,et_id2,et_id3;
	pid = 0;
	if(pid == -1)
		printf("\nProcess creation failed\n");
	/*
	*	MAIN MENU
	*/
	do
	{
		start:
		count_info(GET_COUNT);
		system("clear");
		printf("\n###################################################\n");
		printf("################ CAR PARKING SYSTEM ###############\n");
		printf("###################################################\n");
		printf("\n\n\n");
		printf("\n1. ENTRY SYSTEM");
		printf("\n2. EXIT SYSTEM");
		printf("\n3. EXIT");
		printf("\nPlease make a choice(1-3) : ");
		fflush(stdout);
		option = getchar();
	}while(option < '1' || option > '3');
	/*creating a child process using fork
	*/
	if ( pid == 0 && option == '1') {
	/*
	*	ENTRY OPTIONS
	*/
		do
		{
			system("clear");
			printf("\n###################################################\n");
			printf("############# Select the Entry Gate ###############\n");
			printf("###################################################\n");
			printf("\n\n\n");
			printf("\n1. ENTRY GATE 1");
			printf("\n2. ENTRY GATE 2");
			printf("\nPlease make a choice(1-2) : ");
			fflush(stdout);
			EntryOption = getchar();
		}while(EntryOption < '1' || EntryOption > '2');
		switch(EntryOption)
		{
			case '1':
				system("clear");
				printf("********ENTRY GATE ONE******\n");
				pthread_create(&pt_id1, NULL, (void *)&car_entry,NULL);
				pthread_join(pt_id1,NULL);
				goto start;
				break;
			case '2':
				printf("********ENTRY GATE TWO******\n");
				pthread_create(&pt_id2, NULL, (void *)&car_entry,NULL);
				pthread_join(pt_id2,NULL);
				goto start;
				break;
		}
	}
	else if( pid == 0 && option == '2'){
		/*
		*	EXIT OPTIONS
		*/
		do
		{
			system("clear");
			printf("###################################################\n");
			printf("############ Select the Exit Gate #################\n");
			printf("###################################################\n");
			printf("\n\n\n");
			printf("\n1. EXIT GATE 1:");
			printf("\n2. EXIT GATE 2:");
			printf("\n3. EXIT GATE 3:");
			printf("\nPlease make a choice(1-3):");
			fflush(stdout);
			ExitOption = getchar();
		}while(ExitOption < '1' || ExitOption > '3');
		switch(ExitOption)
		{
			case '1':
				printf("\t\t*****EXIT GATE ONE******\n");
				pthread_create(&et_id1, NULL, (void *)&car_exit,NULL);
				pthread_join(et_id1,NULL);
				goto start;
				break;
			case '2':
				printf("\t\t*****EXIT GATE TWO******\n");
				pthread_create(&et_id2, NULL, (void *)&car_exit,NULL);
				pthread_join(et_id2,NULL);
				goto start;
				break;
			case '3':
				printf("\t\t******EXIT GATE THREE******\n");
				pthread_create(&et_id3, NULL, (void *)&car_exit,NULL);
				pthread_join(et_id3,NULL);
				goto start;
				break;
		}

	}
}

//END OF MAIN
