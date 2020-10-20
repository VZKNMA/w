#include<stdio.h>

#define gaussStart 1
#define gaussEnd 100

int main()
{
    int n,sum ;

    for (n=gaussStart;n<gaussEnd+1;n++)
    {
        sum+=n;
    }
    printf ("this program print gauss add from 1 to 100:%d\n",sum);
    return(0);
}
