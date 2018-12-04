#include "../include/common.h"
#include "serv.c"
#include "client.c"

/**
*	MUTEX INITIALIZER
*/
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

/**
*	Delete driver information according to given token id
*	Accept token number as an argument 
*/
void delete_driver_info(int tok_del)
{
	int c;
	int shmid;
	key_t key;
	struct driver_info *shm,*s;
	/*
	*We'll name our shared memory segment
	**5678"
	*/
	key = 5000;
	/*
	*Create the segment
	*/
	if((shmid = shmget(key,max_car * sizeof(struct driver_info),IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}
	/*
	*Now we attach the segment to our data space.
	*/
	if((shm = shmat(shmid,NULL,0)) == (void *) - 1)
	{
		perror("shmat");
		exit(1);
	}	
	/*
	*Now put some things into the memory for the 
	*other process to read.
	*/
	s = shm;
	for(c = 0;c < count;c++)
	{
		if(tok_del != (driver + c)->token_id)
		{
			strcpy(s->name,(driver + c)->name);
			strcpy(s->mom_name,(driver + c)->mom_name);
			s->token_id = (driver + c)->token_id;
			s++;
		}
	}
}

/**
* 	This Function Delete car information and increase space left
*/
void delete_entry_info(int tok_del)
{
	int c;
	int shmid;
	key_t key;
	struct entry_system *shm,*s;
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	min = timeinfo->tm_min;
	hour = timeinfo->tm_hour;
	/*
	*We'll name our shared memory segment
	**5678"
	*/
	key = 5678;
	/*
	*Create the segment
	*/
	if((shmid = shmget(key,max_car * sizeof(struct entry_system),IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}
	/*
	*Now we attach the segment to our data space.
	*/
	if((shm = shmat(shmid,NULL,0)) == (void *) - 1)
	{
		perror("shmat");
		exit(1);
	}	
	/*
	*Now put some things into the memory for the 
	*other process to read.
	*/
	s = shm;
	for(c = 0;c < count;c++)
	{
		if(tok_del != (entry + c)->token_id)
		{
			s->car_no = (entry + c)->car_no;
			s->token_id = (entry + c)->token_id;
			s->time = (entry + c)->time;
			s++;
		}
	}
	delete_driver_info(tok_del);
	count--;
	count_info(SET_COUNT);
}

/**
*	This function will take care of exit system, accept the token number from the driver and delete his car entry from the entry system.
*	This system can also find out the tokenid if driver has lost his token id by giving additional information
 */
void car_exit()
{
	int token = 0;
	char ans[max_ans];
	/*
	*Display parking information
	*/
	display_entry_info(5678);
	display_driver_info(5000);
	printf("\nDo you have owner token ID (Y / N) : ");
	scanf("%s",ans);
	if(!strcmp(ans,"N") || !strcmp(ans,"n"))
	{
		/*verify from entry point*/
		pthread_t t_id1, t_id2;
		/*Both thread will act as a client & server for each other , and return the tokenid from driver structure*/
		pthread_create(&t_id1, NULL, &serv, NULL);
		pthread_create(&t_id2, NULL, &client, NULL);
		pthread_join(t_id1,NULL);
		pthread_join(t_id2,NULL);
		sleep(5);
		token = tokenid;
		if(!token)
			printf("Invalid Informaton\n");
		else
		{
			printf("\nToken ID recieved = [%d]\n",tokenid);
			goto del;
		}
	}
	else
	{
		printf("\nShow your owner token ID : ");
		scanf("%d",&token);
	del:
		/*
		*FIND TOKEN ID AND DELETE
		*/	
		pthread_mutex_lock(&mutex);	
		delete_entry_info(token);
		pthread_mutex_unlock(&mutex);	
	}
	display_entry_info(5678);
	display_driver_info(5000);
	sleep(3);
}
