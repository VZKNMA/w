#include<stdio.h>

static int cannoball (int n);

void main()
{
	int num;
	printf("Please input a number as the num of the tower:\n");
	scanf("%d",&num);
	printf("And there is %d balls \n",cannoball(num),);	
}
static int cannoball (int n)
{
	if (n==1) return (1);
	else return(cannoball(n-1)+n*n);
}
