#include<stdio.h>
 
#define meter2inch (10000/254.0) 
#define meter2feet (10000/(254.0*12)) 

int main()
{
    float meter;

    printf("this program convert distance form meter 2 inch.P I A real number:\n");
    scanf ("%f",&meter);
    printf("the result of conversion is %f\n",meter*meter2inch);
    printf("this program convert distance form meter 2 feet.P I A real number:\n");
    scanf ("%f",&meter);
    printf("the result of conversion is %f\n",meter*meter2feet);
    return (0);
}
