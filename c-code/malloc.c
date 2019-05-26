#include<stdio.h>
#include<stdlib.h>
int main ()
{
	char* p = (char *)malloc(84);
	*p = 10;
	printf("%d,%d\n",*p,p);
	free(p);
}
