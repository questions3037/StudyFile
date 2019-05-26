#include<stdio.h>
#include<time.h>
#include<stdio.h>
int main()
{
	srand(time(NULL));
	int code[7];
	int i;
	for(i=0;i<7;i++)
	{
		int r = rand() % 10;
		code[i] = r;
		printf("%d\n",code[i]);
	}
	return 0;
}
