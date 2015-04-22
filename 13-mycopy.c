#include<stdio.h>
#include<errno.h>
#define N 64
int main(int argc,const char* argv[])
{
	FILE *fps,*fpd;
	int ret = 0;
	char buf[N] = {0};

	if(argc < 3)	{
		printf("Usage:%s <src_file> <des_file>",argv[0]);
		return -1;
	}
	if((fps = fopen(argv[1],"r")) == NULL)	{
		perror("open src_file");
		return -1;
	}
	if((fpd = fopen(argv[2],"w")) == NULL)	{
		fclose(fps);
		perror("open des_file");
		return -1;
	}
	while((ret = fread(buf,1,N,fps)) > 0)	{
		fwrite(buf,1,ret,fpd);
	}

	fclose(fps);
	fclose(fpd);

	return 0;
}
