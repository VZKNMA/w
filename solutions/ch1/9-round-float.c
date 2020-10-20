#include <stdio.h>

int round(float x);

int main()
{
    float x;

    printf("this program is a test for rounding a float number.\nP I A:");
    scanf("%f",&x);
    printf("%f rounds to %d is it correct?\n",x,round(x));
    return(0);
}
int round(float x)
{
    if(x>=0) return ((int)(x+0.5));
    else return((int)(x-0.5));
}
