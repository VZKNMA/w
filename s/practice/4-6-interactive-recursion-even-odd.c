#include<stdio.h>

int iseven(unsigned n);
int isodd(unsigned n);

void main()
{
	unsigned n;
	printf("please input a unsigned number:\n");
	scanf("%d",&n);
	printf("this is a even number you know is %d * true\n",iseven(n));
}
int iseven(unsigned n)
{
	if (n==0) return (1);
	return (isodd(n-1));
}
int isodd(unsigned n)
{
	return (!iseven(n));
}
