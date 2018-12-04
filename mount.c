#include <stdio.h>
#include <stdlib.h>

#ifndef MS_BIND 
#define MS_BIND 4096
#endif

int main()
{
	int ret = mount("/home/manohar", "/home/manohar/sample", NULL, MS_BIND, NULL);
	if(ret) 
	{
		perror("mount bind /home/manohar on /home/manohar/sample");
		exit(1);
	}
}
