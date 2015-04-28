#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>
int  main()
{
	if(fork() == 0)	{
		if(execl("/bin/ls","ls",NULL) < 0)	{
			printf("execl error!\n");
		}
	}
	return 0;
}
