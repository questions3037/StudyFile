#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int g_v = 30;
int main()
{
	int a_v = 30;
	static int s_v = 30;

	printf("pid: %d\n",getpid());

	FILE *fp = fopen("s.txt","w");
	int fd = open("s_fd.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU|S_IRWXG);
	char *s = "hello iotek";
	ssize_t size = strlen(s) * sizeof(char);
	//标准的IO函数（带缓存）
	//父进程调用
	fprintf(fp,"s:%s,pid:%d",s,getpid());//写入缓存
	//内核提供的IO系统调用（不带缓存） 
	write(fd,s,size);//直接写入

	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		perror("fork error");
	}
	else if(pid > 0){
	//父进程
	//父进程执行的代码
		g_v = 40; a_v = 40; s_v= 40;
		printf("I am parent process pid is %d,ppid is %d,fork return is %d\n",getpid(),getppid(),pid);
		printf("g_v: %p, a_v：%p, s_v: %p\n",&g_v,&a_v,&s_v);
	}else{
	//子进程
	//子进程执行的代码
		g_v = 50; a_v = 50; s_v = 50;
		printf("I am child process pid is %d,ppid is %d,fork return is %d\n",getpid(),getppid(),pid);
		
		printf("g_v: %p, a_v：%p, s_v: %p\n",&g_v,&a_v,&s_v);
	
	}
	//printf("pid : %d,g_v: %d,a_v: %d,s_v: %d\n",getpid(),g_v,a_v,s_v);
	
	fprintf(fp,"----------pid : %d,g_v: %d,a_v: %d,s_v: %d\n",getpid(),g_v,a_v,s_v);
	sleep(1);

	fclose(fp);
	close(fd);

	exit(0);
}
