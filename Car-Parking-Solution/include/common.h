/**
	 Header files which are common in all the files
 */

#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>


/**
	PRE DEFINE VALUES
 */
#define max_car	100
#define max_car_num	101
#define start_count	0
#define start_token	1
#define max_ans		2

/**
	FLAGS
*/

#define GET_COUNT 1
#define SET_COUNT 0


