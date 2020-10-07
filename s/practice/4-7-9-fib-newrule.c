#include <stdio.h>

#define minindex 1 
#define maxindex 12

static int fib(int n);

void main()
{
	printf("this program print fabonacci sequence in a new rule that a rabbit can only produce 3 babies:\n");
	for (int i=0;i<maxindex;i++)
	{
		printf("the %dth is %d\n",i+1,fib(i+1));
	}
}
static int fib(int n)
{
	int num1=0;
	int num2=1;
	int old,tmp,num;
	
	
	if (n<3)
	{
		if (n==1) return (0);
		else return (1);
	}


	old=num1;
	tmp=num2;
	for (int i=2;i<n;i++)//有问题始终无法实现新规则 无法在语言中表达停止生育的个体
	{
		num=old+tmp;
		old=tmp;
		tmp=num;		
	}
	return (num);
}
