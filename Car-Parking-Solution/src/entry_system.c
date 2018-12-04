#include "../include/common.h"
#include "../include/struct.h"
#include "time.h"

extern struct driver_info *driver;
extern struct entry_system *entry; 

/**
	 MUTEX LOCK INITIALIZER IN ENTRY SYSTEM
*/
pthread_mutex_t mutex1= PTHREAD_MUTEX_INITIALIZER;

/**
	Global variables
*/
static int token_num = start_token;
static int token_num1 = start_token;
static int count = start_count;
int min, hour;

/**
*	This function will fill the data from shared memory in to entry_info and also aksked for 	 new entry to fill further .
*	Accept count in variable c and number of car in entnum
*	Return type is void
*/
void create_memory_entry_info(int c,int entnum)
{
	int shmid;
	key_t key;
	struct entry_system *shm,*s;
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
	/*
	* FILL STRUCTURE
	*/	
	s = s + c;
	if(c < count - entnum)
	{
		s->car_no = (entry + c)->car_no;
		s->token_id = (entry + c)->token_id;
		s->time = (entry + c)->time;
		token_num = s->token_id + 1;
	}
	else
	{
		printf("Enter the car number(LAST FOUR NUMBER ONLY):");
		scanf("%d",&s->car_no);
		s->token_id = token_num;
		token_num++;
		s->time = hour;
	}
}
/**
* 	This function set and get the count value according to given flag
*	FLAGS - SET_COUNT/GET_COUNT
	
*/
void count_info(int flag)
{
	int c;
	int shmid;
	key_t key;
	int *shm,*s;
	/*
	*We'll name our shared memory segment
	**5678"
	*/
	key = 4999;
	/*
	*Create the segment
	*/
	if((shmid = shmget(key,sizeof(int),IPC_CREAT | 0666)) < 0)
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
	if(flag)
/*
* GET COUNT
*/
		count = *s;
	else
/*
*WRITE COUNT IN TO SHARED MEMORY
*/
		*s = count;
}

/**
*	This Function Display Driver Information according to given car is parked 
*	Accept key as an argument 
*/
void display_driver_info(key_t key)
{

	int shmid,i;
	struct driver_info *shm,*s;
	/*
	*Locate the segment.
	*/
	if((shmid = shmget(key,count * sizeof(struct driver_info),0666)) < 0)
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
	*Now read what the server put in the memory.
	*/
	driver = malloc(sizeof(struct driver_info) * count);
	for(s = shm,i=0;i < count;i++,s++)
	{
		strcpy((driver + i)->name,s->name);
		strcpy((driver + i)->mom_name,s->mom_name);
		(driver + i)->token_id = s->token_id;
	}
	printf("\n***************Driver structure Info**************\n");
	for(i = 0;i < count;i++)
	{
		printf("name = [%s]\tmom name = [%s]\ttoken id = [%d]\n",(driver + i)->name,(driver + i)->mom_name,(driver + i)->token_id);	
	}
}

/**
*	This Function Display car information present in shared memory
*/
void display_entry_info(key_t key)
{

	int shmid,i;
	struct entry_system *shm,*s;
	/*
	*Locate the segment.
	*/
	if((shmid = shmget(key,count * sizeof(struct entry_system),0666)) < 0)
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
	*Now read what the server put in the memory.
	*/
	entry = malloc(sizeof(struct entry_system) * count);
	for(s = shm,i=0;i < count;s++,i++)
	{
		(entry + i)->car_no = s->car_no;
		(entry + i)->token_id = s->token_id;
		(entry + i)->time = s->time;
	}
	printf("\n*************Structure data**************\n");
	for(i = 0;i < count;i++)
	{
		printf("car no = [%d]\ttoken id = [%d]\ttime = [%d]\n",(entry + i)->car_no,(entry + i)->token_id,(entry + i)->time);
	}
}
/**
* 	This function will copy driver data from memory in to structure and also add new information
*/
void create_memory_driver_info(int entnum)
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
		if(c < count - entnum)
		{
		/*
		*COPY DATA PRESENT IN MEMORY
		*/
			strcpy(s->name,(driver + c)->name);
			strcpy(s->mom_name,(driver + c)->mom_name);
			s->token_id = (driver + c)->token_id;
			token_num1 = s->token_id + 1;
		}
		else {
		/*
		* NEW DRIVER DATA 
		*/
			printf("\nDriver Name: ");
			scanf("%s",s->name);
			printf("Drivers mother name: ");
			scanf("%s",s->mom_name);
			s->token_id = token_num1;
			token_num1++;
		}
		create_memory_entry_info(c,entnum);
		s++;
	}
}

/**
*	Main thread for entry syatem
*	Function for registring car entry for the parking and also generate waiting list if parking is full.
*/
void car_entry()
{
	int entnum = max_car_num;
	/*
	* ENTRY TIME
	*/
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	min = timeinfo->tm_min;
	hour = timeinfo->tm_hour;
	/*
	* GET THE COUNT FROM SHARED MEMORY
	*/
	count_info(GET_COUNT);
	/*
	* ENTER NUMBER OF CAR WANT TO PARK
	*/
	while(entnum > (max_car - count) && count != max_car)
	{
		system("clear");
		printf("\nEnter Number of cars you want to park (SPACE lEFT %d): ",max_car-count);
		scanf("%d",&entnum);
	}
	if(count == max_car)
	{
		/*waiting queue function*/
	}
	if(count != 0)
	{
		display_driver_info(5000);
		display_entry_info(5678);
	}
	//printf("\n pre count = [%d]\n",count);
	count = count + entnum;
	/*
	* SET THE NEW COUNT
	*/
	count_info(SET_COUNT);
	//printf("\n new count = [%d]\n",count);
	
	/*
	* MUTEX LOCK
	*/
	pthread_mutex_lock(&mutex1);
	create_memory_driver_info(entnum);
	pthread_mutex_unlock(&mutex1);
//	create_memory_entry_info(entnum);
	
	/*
	* DISPLAY PARKING STATUS
	*/
	display_driver_info(5000);
	display_entry_info(5678);
	sleep(3);
}
