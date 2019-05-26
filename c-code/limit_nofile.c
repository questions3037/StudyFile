#include<sys/resource.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define MODE S_IRWXU | S_IRWXG | S_IRWXO

int open_file(const char *filename)
{
	int fd = open(filename,O_RDWR | O_CREAT | O_TRUNC,MODE);
	if(fd < 0){
		perror("open error");
		exit(1);
	}
	return fd;
}

int main(int argc,char *argv[])
{
	struct rlimit limit;
	limit.rlim_cur = 5;//设置软资源限制
	limit.rlim_max = 1024l;//设置硬资源限制
	// 0 1 2 已经打开 0是标准输入 1标准输出 2标准错误
	// 设置进程打开文件的最大数
	if(setrlimit(RLIMIT_NOFILE, &limit) < 0){
		perror("setrlimit error");
		exit(1);
	}

	int fd1,fd2;
	fd1 = open_file("s1.txt");
	if(fd1 < 0){
		exit(1);
	}
	fd2 = open_file("s2.txt");
	if(fd2 < 0){
		exit(1);
	}
	close(fd1);
	close(fd2);

	return 0;
}

