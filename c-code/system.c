#include<stdio.h>
int main()
{
	int ret;
	printf("系统分配的进程号是： %d\n");
	ret = system("ping www.baidu.com -c 2");
	printf("返回值是：%d\n",ret);
	return 0;
}
