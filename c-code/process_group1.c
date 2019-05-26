#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	setpgid(getpid(),getpid());
	pid_t group1 = getpgid(getpid());
	pid_t group2;
	
	int i = 0;
	pid_t pid;

	for(; i < 2 ;i++){
		pid = fork();
		if(pid < 0){
			printf("fork error\n");
			exit(1);
		}else if(pid > 0){
			if(i == 0){
				setpgid(pid,pid);
			}
			if(i == 1){
				setpgid(pid,group1);
			}
			break;
		}else{	
			if(i == 0){
				setpgid(getpid(),getpid());
				group2 = getpgid(getpid());
			}
			if(i == 1){
				setpgid(getpid(),group1);
			}
		}
	}
	printf("pid : %d,ppid : %d,pgid : %d\n",getpid(),getppid(),getpgid(0));
	printf("%d\n",group2);
	wait();
	exit(0);
}
