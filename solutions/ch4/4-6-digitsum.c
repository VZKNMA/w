#include<stdio.h>

static int digitsum(int n);

int main(void)
{
	int n;
	scanf("%d",&n);
	printf("the number is %d the digitsum is %d\n",n,digitsum(n));
	return 0;
}
static int digitsum(int n)
{
	if (n<10) return(n);
	else return(n%10+digitsum(n/10));
}
