#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(void)
{
	//组长为父进程
	setpgid(getpid(),getpid());
	pid_t group1 = getpgid(getpid());
	pid_t group2;

	int i = 0;
	pid_t pid;
	for(;i < 3;i++){
		pid = fork();
		if(pid < 0){
			perror("fork error");
			exit(1);
		}else if(pid > 0){
			//父进程中执行和子进程相同的操作   避免父进程比子进程先结束
			if(i == 0){
				setpgid(pid,group1);
			}
			if(i == 1){
				//创建进程组  第二个子进程成为组长进程
				setpgid(pid,pid);
				group2 = getpgid(pid);
			}
			if(i == 2){
				setpgid(pid,group2);
			}
		}else if(pid == 0){
			if(i == 0){

				//加入组1
				setpgid(getpid(),group1);
			}
			if(i == 1){
				// 组2   第二子进程为组长
				setpgid(getpid(),getpid());
				group2 = getpgid(getpid());
			}
			if(i == 2){
				//加入到组2
				setpgid(getpid(),group2);
			}
			break;
			//为进程扇
		}
	}
	printf("pid : %d,ppid : %d,pgid : %d\n",getpid(),getppid(),getpgid(0));
	for(i = 0;i < 3;i++){
		wait();
	}
	exit(0);
}
