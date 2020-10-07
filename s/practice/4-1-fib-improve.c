#include <stdio.h>
#include "genlib.h"

#define minindex 0
#define maxindex 12

int fib(int n);
int additivesequence(int n,int t0,int t1);

void main()
{
	printf("this program lists the fibonacci sequence: \n");
	for (int i=minindex;i<maxindex;i++)
	{
		printf("the %dth number=",i+1);
		if (i<9) printf(" ");
		printf("%d\n",fib(i));
	}	
}
//包装函数 用来传递更加具体的参数
int fib(int n)
{
	return (additivesequence(n,0,1));
}
//除了应用递归式，fibonacci的另一种递归实现：递归缩短加法序列
int additivesequence(int n,int t0,int t1)
{
	if (n==0) return (t0);
	if (n==1) return (t1);
	else return (additivesequence(n-1,t1,t0+t1));
}

