#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t pid,ppid;
	pid = getpid();
	ppid = getppid();
	printf("当前的进程号是：%d\n",pid);
	printf("当前进程的父进程的进程号是：%d\n",ppid);
	return 0;
} 
