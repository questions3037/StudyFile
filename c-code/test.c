#include<stdio.h>
int main()
{
	printf("\a");
	int a=12,b=0;
	b=~a;
	printf("%d\n",b);
	unsigned char flag=0;
	flag|=(1u<<5);	
	printf("%d",flag);
	return 0;
}
