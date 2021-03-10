#include<stdio.h>

static int cnk(int n ,int k);

int main(void)
{
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			printf("%d\t",cnk(i,j));
		}
		printf("\n");
	}
	return 0;
}
static int cnk(int n ,int k)
{
	if (n==k||k==0) return 1;
	else return(cnk(n-1,k)+cnk(n-1,k-1));
}
