#include <stdio.h>

#define maxsize 13
void removeZeroElements(int array[],int *n);

int main(void)
{
    int effectiveSize=maxsize;
    int scores[maxsize]={65,0,95,0,0,79,82,0,84,94,86,90,0};

    removeZeroElements(scores,&effectiveSize);
    printf("this program remove zeros in array and return effective size of the compressed array,the number is supposed to be 8"
            "\nis it correct?:%d\n",effectiveSize);
    return 0;
}
void removeZeroElements(int array[],int *n)
{
    int tmp= *n;
    int tmparray[maxsize];
    int tmpindex=0;

    for(int i=0;i<tmp;i++)
    {
        if(array[i]==0)
            (*n)--;/*
                    first time I thought *n-- will make the value decrease which n pointed to,but I misunderstood the precedence of
                    operators,it goes from right to left,which is -- first to take effect;
                    */
        else
        {
           tmparray[tmpindex]=array[i];
           tmpindex++;
        }
    }
    for(int i=0;i<*n;i++)
    {
        array[i]=tmparray[i];
    }
}
