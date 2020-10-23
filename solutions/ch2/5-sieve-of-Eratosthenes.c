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

/*
  the general idea of this function is to set the crossed-out number as 0;and do not change prime number;and then count the number
  of crossed-out numbers and the prime numbers,if it equals to the array size,that means the outer loop is over we have finished!
  */

void Eratosthenes(int array[])
{
    int startindex=0;
    int xn=0;
    int on=1;/*cause we have choose 2 as first prime number*/
    int tmpindex;

                /*
                 thank god I have gdb!  
After debugging the program in gdb, I found that array[startindex] did not increase to the value 5 as I expected.
I continued to set a breakpoint when the variable increased to 3. After single-stepping, I found my mistake. 
I thought that zero cannot be divisible by any number. 
In fact, zero can be divisible by any number. The result is zero and the remainder is 0; 
this error caused the variable x to be counted repeatedly and the loop ended abnormally early.
so I write this statements to avoid this error,finally get the right answer.
            if(array[tmpindex]==0) 
            {
                tmpindex++;
                continue;
            }
by the way this is my first time to use gdb.Joy beyond words.
                 */
    while(1)
    {
        if((xn+on)>=(max-1)) break;
        tmpindex=startindex+1;
        while(tmpindex<max-1)
        {
            if(array[tmpindex]==0) 
            {
                tmpindex++;
                continue;
            }
            if(!(array[tmpindex]%array[startindex]))
            {
                array[tmpindex]=0;
                xn++;
            }
            tmpindex++;
        }
        tmpindex=startindex+1;
        while(1)
        {
            if(array[tmpindex]!=0)
            {
                startindex=tmpindex;
                on++;
            }
            if(array[tmpindex]!=0)
                break;
            tmpindex++;
        }
    }
}
/*
 let's understand why start with n^2.
 set any number n as an example
 all numbers between 2 and 1000 that can be divided  by n evently are numbers like that:
 n*1 n*2 n*3 ... n*n ... n*p (where n*p<=1000;include the first prime and cross-out)
 because the sieve start with 2,and 2^2 equals to 2*2
 so the first ergodic looks like this:
 1*2 2*2 3*2 ... n*2 ... untill 500*2=1000
 so all the n*2 type number was eliminate or crossed-out .
 and n*1 type number is itself the prime number
 so as the ergodic process goes on every outter itrarion start with n^2,because the number before n^2 was eliminated.
 */
/************************************************************************************************************************************
//the program blow from the internet csdn I copied it to see where I was wrong
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define N 1000000

bool isprime[N];//this is an array!

void initPrime(void);

int main()
{
    int i = 2;

    initPrime();
    while(1) 
    {
        if(i > 1000) break;    //start with i=2;
        if(isprime[i])
            printf("%d\n", i);
        i++;
    }
    return 0;
}

void initPrime()
{
    int n, i, j;
    int k;

//The outer loop and the inner loop fit very well, so the loop termination condition is simple and error-free.

    for(k = 0; k < N; k++)//N=1000 000=1000x1000 
        isprime[k] = true;

    n = (int)sqrt(N);    //n=1000

    for(i = 2; i <= n; i++)//the range is 2-1000 set i=1001 as loop termination condition 
    {
        if(isprime[i])      //every iteration make a verdict and false means the number has been traversed as compound number
        {
            j = i * i;
            while(j <= n)   //the inner iteration start with i^2,and every iteration with an increment of itself j+=i; 
            {                       //set the j>=n as loop termination condition
                isprime[j] = false; //starting  with i^2 to begin the realization of  the sive of Eratosthenes was what I didn't
                j +=i;                //found before!!!!!!!!!!!!!
            }
        }
    }
}
 ************************************************************************************************************************************
 **/
