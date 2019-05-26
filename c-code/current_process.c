#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t pid=0,ppid=0;
	pid_t uid=0,euid=0;
	gid_t gid=0,egid=0;
	
	pid = getpid();
	ppid = getppid();

	uid = getuid();
	euid = geteuid();

	gid = getgid();
	egid = getegid();

	printf("id of current process:%u\n",pid);
	printf("parent id of current process:%u\n",ppid);
	printf("user id of current process:%u\n",uid);
	printf("effective userid of current process:%u\n",euid);
	printf("group id of current process:%u\n",gid);
	printf("effective group id of current process:%u\n",egid);

	return 0;
}
