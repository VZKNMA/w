#include <stdio.h>

int main()
{
    int N,n,rn;
    rn=0;

    printf("this program reverses the digits in an integer.\nEnter a positive integer:");
    scanf("%d",&N);
    while(N>0){
    n=N%10;
    rn=rn*10+n;
    N=N/10;
    }
    printf("The reversed number is %d\n",rn);
    return(0);
}
