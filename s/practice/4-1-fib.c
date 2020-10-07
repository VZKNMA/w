#include<stdio.h>
#include"genlib.h"

#define minindex 0
#define maxindex 12

int fib(int n);

void main()
{
	int i;	
	
	printf("this program lists the fibonacci sequence.\n");
	for (i=minindex;i<=maxindex;i++)
	{
		printf("fib(%d)",i);
		if (i<10) printf(" ");
		printf("= %d\n",fib(i));
	}
}
int fib(int n)
{
	if (n<2) return n;
	else return (fib(n-1)+fib(n-2));

}
