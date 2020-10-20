#include<stdio.h>

#define min 1
#define max 9999

int isperfect(int n);

int main()
{
    int n=min;

    while(n<(max+1))
    {
        if(isperfect(n))
            printf("%d\n",n);
        n++;
    }
    printf("this program find perfect number,like 6=1+2+3,between 1 to 9999\n");
    return (0);
}

int isperfect(int n)
{
    int m,sum;
    sum=0;

    for(m=1;m<n;m++)
    {
        if (!(n%m)) sum+=m;
    }

    if (sum==n) return(1);
    else return (0);
}
