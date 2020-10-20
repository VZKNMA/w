#include<stdio.h>

#define num 10000

int main()
{
    float pi4th;
    int n;

    /*&是按位与,&&是逻辑与*/
    for(n=0;n<num;n++)/*int has 4 bytes in my pc,n repersents for 1+n*2,and in c binnary num is 0b10101 oct is 0764 hex is 0xace024*/
    {
        pi4th+=((n&0x00000001)?-1:1)/(1.0+n*2);/*this place waste me a lot of time ,now the bug is because I forgot to turn 1 to 1.0
                                                 then lead to the integer division problem!!!!!!!!!!!!!!!*/
    }
    printf("the pi is %f\n",pi4th*4.0);
    return(0);
}
