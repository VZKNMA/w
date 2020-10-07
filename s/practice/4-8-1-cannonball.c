/*前提是使用归纳法证明了序列的通项公式为n2
猜想递归公式为Cn=C(n-1)+2*(n-1)+1
故递归程序的两个前提为   1最小问题为N=1时，C1=1
  			 2通过递归公式分解问题实现递归信任*/
#include<stdio.h>

static int cannoball (int n);

void main()
{
	int num;
	printf("Please input a number as the num of the tower:\n");
	scanf("%d",&num);
	printf("And there is %d balls in the %dth floor\n",cannoball(num),
		num);	
}
static int cannoball (int n)
{
	if (n==1) return (1);
	else return(cannoball(n-1)+2*(n-1)+1);
}
