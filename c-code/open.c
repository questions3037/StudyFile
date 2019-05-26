#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (int argc,char *argv[])
{
	int fd=0;
	if(argc!=2)
	{
		printf("Your Input Error!\n");
		exit(1);
	}
	fd = open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("open()");
		exit(1);
	}
	else
	{
		printf("Open Successful!\n");
		printf("The File Descriptor Is %d\n",fd);
	}
	exit(0);
}

