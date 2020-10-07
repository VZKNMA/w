#include <stdio.h>

int gcd(int x,int y);
void main()
{
	int x,y;

	printf("Please input a number as X and Y:\n");
	scanf("%d %d",&x,&y);
	printf("and this is the result of n power k: %d\n",gcd(x,y));
}
int gcd(int x,int y)
{
	if (!(x%y)) return (y);
	else return (gcd(y,x%y));
}
