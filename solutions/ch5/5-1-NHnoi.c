#include<stdio.h>

static int NHanoiMoves(int n);

int main(void)
{
	int n;

	printf("input a small number:\n");
	scanf("%d",&n);
	printf("to move %d disks need %d times movements\n",n,NHanoiMoves(n));
	return 0;
}
static int NHanoiMoves(int n)
{
	if (n==1) return(1);
	else 
		return(2*(NHanoiMoves(n-1))+1);
}
