#include<stdio.h>
#define minindex 0
#define maxindex 15

static int addsequence(int n,int t0,int t1);
static int fib01(int n);
static int fib02(int n);
static int countfib1(int n);
static int countfib2(int n);

int fib1,fib2;

int main(void)
{
	int i;
	printf("This program compares the performance of two algorithms to compute the fibonacci sequence.\n\nNumber of calls:\nN\tFib1\tFib2\n");
	for(i=minindex;i<=maxindex;i++)
	{
		printf("%d\t%d\t%d\n",i,countfib1(i),countfib2(i));
	}
	return 0;
}
static int addsequence(int n,int t0,int t1)
{
	fib2++;
	if(n == 0) return(t0);
	if(n == 1) return(t1);
	return(addsequence(n-1,t1,t0+t1));
}
static int fib01(int n)
{
	fib1++;
	if(n<2)
	{
		return(n);
	}
	else return(fib01(n-1)+fib01(n-2));
}
static int fib02(int n)
{
	fib2++;
	return(addsequence(n,0,1));
}
static int countfib1(int n)
{
	fib1=0;
	int i;
	i=fib01(n);
	return (fib1);
}
static int countfib2(int n)
{
	fib2=0;
	int i;
	i=fib02(n);
	return (fib2);
}
