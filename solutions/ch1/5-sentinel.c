#include <stdio.h>

int main()
{
    int n,max;
    max=0;

    printf("this program display the largest value in the list which readed from user who uses the value 0 as a sentinel:\n");
    while(1)
    {
        printf("?");
        scanf("%d",&n);
        if (n==0) break;
        if (n>max) max=n;
    }
    printf("the largest number is %d\n",max);
    return(0);
}
