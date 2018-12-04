/*
	The output will be 1 2 3. 
	The above initialization technique is unique but allowed in C.
*/

#include <stdio.h>

int main()
{
	int array[] = {[0] = 1, [1] = 2, [2] = 3};
	printf("%d %d %d\n", array[0], array[1], array[2]);
	return 0;
}

