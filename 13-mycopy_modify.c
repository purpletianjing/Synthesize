#include<stdio.h>
#include<errno.h>
#include<time.h>
int main(int argc,const char* argv[])
{
	FILE *fpd;
	int ret = 0;
	time_t t;

	if(argc < 2)	{
		printf("Usage:%s <des_file>",argv[0]);
		return -1;
	}
	if((fpd = fopen(argv[1],"w")) == NULL)	{
		perror("open des_file");
		return -1;
	}
	while(ret < 10)	{
		fprintf(fpd,"the %dth %s\n",ret,ctime(&t));
		ret++;
	}

	fclose(fpd);

	return 0;
}
