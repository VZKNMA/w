#include<stdio.h>

#define max 1000

void Eratosthenes(int array[]);

int main(void)
{
   int array[max-1];
   int m=0;

   for(int n=0;n<max-1;n++)
   {
       array[n]=n+2;
   }
   Eratosthenes(array);
   for(int n=0;n<max-1;n++)
   {
        if(array[n]!=0) 
        {
            printf("%d\n",array[n]);
            m++;
        }
   }
   printf("the number of prime numbers in 2-1000 should be 168.but you better check the number above to see if it is correct\nthe number is %d\n",m);
   return 0;
}
void Eratosthenes(int array[])
{/*
  the general idea of this function is to set the crossed-out number as 0;and do not change prime number;and then count the number
  of crossed-out numbers and the prime numbers,if it equals to the array size,that means the outer loop is over we have finished!
  */
    int startindex=0;
    int x=0;
    int o=1;/*cause we have choose 2 as first prime number*/
    int tmpindex;

    while(1)
    {
        if((x+o)>=(max-1)) break;
        /*
        for(int n=startindex+1;n<max-1;n++)
        {
            if(array[n]==0) n++;
            if(!((array[n])%(array[startindex])))
            {
                array[n]=0;
                x++;   
            }
        }
        I really don't know why this loop is wrong and the below is correct!
        */
        tmpindex=startindex+1;
        while(tmpindex<max-1)
        {
            if(array[tmpindex]%array[startindex]);
            else 
            {
                array[tmpindex]=0;
            /*    x++;   why I 
             Commenting out this sentence will contradict the basic idea of the function, but the result is correct. 
             I guess this may be related to the repeated counting of x or o. I have wasted too much time here.
             I will think about this problem another day? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
             */
             }
            tmpindex++;
        }
        tmpindex=startindex+1;
        while(1)
        {
            if(array[tmpindex]!=0)
            {
                startindex=tmpindex;
                o++;
            }
            if(array[tmpindex]!=0)
                break;
            tmpindex++;
        }
    }
}
