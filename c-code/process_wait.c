#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

void out_status(status)
{
	if(WIFEXITED(status)){
		printf("normal exti: %d\n",WEXITSTATUS(status));
	}else if(WIFSIGNALED(status)){
		printf("abnormal term: %d\n",WTERMSIG(status));
	}else if(WIFSTOPPED(status)){
		printf("stoppde sig: %d\n",WSTOPSIG(status));
	}else{
		printf("unknow error");
	}
}

int main()
{
	int status;
	pid_t pid;
	if((pid = fork()) <0){
		perror("fork error");
		exit(1);
	}else if(pid == 0){
		printf("pid : %d,ppid : %d\n",getpid(),getppid());
		exit(3);//子进程终止运行
	}
	//父进程调用wait（）函数阻塞，等待子进程结束并回收
	wait(&status);
	out_status(status);
	printf("--------------------------------------\n");
	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}else if(pid == 0){
		printf("pid : %d, ppid: %d\n",getpid(),getppid());

		int i = 3,j = 0;
		int k = i/j;
		printf("k: %d\n",k);
	}
	wait(&status);
	out_status(status);
	printf("--------------------------------------\n");
	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}else if(pid == 0){
		printf("pid : %d, ppid: %d\n",getpid(),getppid());
		//pause();//暂停  阻塞
		int i = 0;
		while(++i > 0){
		sleep(1);
		}
	}
//	wait(&status);
	do {
		pid = waitpid(pid,&status,WNOHANG | WUNTRACED);
		if(pid == 0) sleep(1);
	}while(pid == 0);
	out_status(status);
	printf("--------------------------------------\n");
	return 0;
}
