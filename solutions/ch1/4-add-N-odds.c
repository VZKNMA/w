#include <stdio.h>

int main()
{
    int N,n,sum;

    printf("this program display the value of the addition of fist N odd intergers form 1\nnow you input N:\n");
    scanf("%d",&N);
    n=-1;
    while(N>0)
    {
        n+=2;
        sum+=n;
        N--;
    }
    printf("the result is %d\n",sum);
    return(0);
}
