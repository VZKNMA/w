#include<stdio.h>

int main(void)
{
    double n;
    double max=0;
    double min=10000;
    while(1)
    {
        printf("?");
        scanf("%4lf",&n);
        /*
         at first time I use scanf("%f",&n); but it seems that %f can not get -1 from the shell so I use the function above.
         */
        if(n==-1) break;
        if(max<n) max=n;
        if(min>n) min=n;
    }
    printf("the range is %f-%f\n",min,max);
    return 0;
}
