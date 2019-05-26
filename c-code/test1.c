#include<stdio.h>
int fun (int ,int );
int main()
{	
	int a = fun(10,10);
	printf("%d\n",a);
	return 0;
} 
int fun(int a,int b)
{
	int c;
	c=a+b;
	return c;
}
