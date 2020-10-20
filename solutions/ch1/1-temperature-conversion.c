#include<stdio.h>
 
#define ratio (9/5.0) 
/*notice that I define ratio as a float division,because 9/5 equals integer 1*/
#define coefficient 32

int main()
{
    float ctemp;

    printf("this program convert temperature form c 2 f.P I A real number:\n");
    scanf ("%f",&ctemp);
    printf("the result of conversion is %f\n",ctemp*ratio+coefficient);
    return (0);
}
