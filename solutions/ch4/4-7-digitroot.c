#include<stdio.h>

static int digitsum(int n);
static int digitroot(int n);

int main(void)
{
	int n;
	scanf("%d",&n);
	printf("the number is %d the digitroot is %d\n",n,digitroot(n));
	return 0;
}
static int digitsum(int n)
{
	if (n<10) return(n);
	else return(n%10+digitsum(n/10));
}
static int digitroot(int n)
{
	if(n<10) return(n);
	else return(digitroot(digitsum(n)));//模糊的想法逐渐清晰变成代码的过程使我非常享受
}
