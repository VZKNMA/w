#include<stdio.h>

int raiseint2power(int n,int k);

void main()
{
	int n,k;

	printf("Please input a number as N and K:\n");
	scanf("%d %d",&n,&k);
	printf("and this is the result of n power k: %d\n",raiseint2power(n,k));
}
int raiseint2power(int n,int k)
{
	if (k==0) return (1);
	else return (n*raiseint2power(n,k-1));
}
