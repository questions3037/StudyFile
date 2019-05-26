#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

#define BUFFERSIZE 1024

typedef int fid_t;

int main(int argc,char **argv)
{
	fid_t fid=0;
	char *path=NULL;
	char *buffer=NULL;

	if(argc<2)
	{
		printf("Don't Input Filename !\n");
		exit(1);
	}

	buffer=(char *)malloc(BUFFERSIZE*sizeof(char));
	memset(buffer,0,BUFFERSIZE);

	while(*++argv)
	{
		path = *argv;
		printf("File Name:%s\n",path);

		if((fid=open(path,O_RDONLY))==-1)
		{
			perror("open():");
			printf("\n");
			continue;
		}
	}

	while(read(fid,buffer,BUFFERSIZE)>0)
	{
		printf("%s",buffer);
		memset(buffer,0,BUFFERSIZE);
		
	}
	close(fid);
	printf("\n");
	
	return 0;
} 
