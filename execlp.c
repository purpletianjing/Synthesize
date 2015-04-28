#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main()
{
	int ret = 0;
	if(fork() == 0)	{
		if((ret = execlp("ls","ls","-l",NULL)) < 0)	{
			printf("execlp error!\n");
		}
	}
	return 0;
}
