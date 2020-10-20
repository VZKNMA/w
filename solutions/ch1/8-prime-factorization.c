/*
this program is hard for me,I edit it for about 10 times to understand its structure.so I guess I should memerize it to make a
progress in coding.

the general idea is to make n divide prime factor p in a circule 
whenever n can't be divided evently by p,p++;
whenever p isn't prime number, p++
if n can be divided evently by prime p,print p,and decrease n by dividing p;
so the the tend is n go down ,p go up,and at last,n equals to p,and n will be divided by p to becomes 1,the p is the largest prime
factor.
 */

#include<stdio.h>

int isprime(int n);/*if n is prime number return 1.*/

int main()
{
    int n;
    int factor=2;

    printf("this program list a product of prime numers that equals to the number input by user.\nlike that:60=2x2x3x5\nP I A:");
    scanf("%d",&n);
    while(n!=1)
    {
/*
嵌套语句　无论是分支嵌套还是循环嵌套，开始部分要按照由外层到内层思考，收尾部分要按照由内层到外层的顺序思考
   */

        if(isprime(factor))
        {
            if (!(n%factor))
            {
                n/=factor;
                if (n==1)
                    printf("%d\n",factor);
                else printf("%d * ",factor);
            }
            else factor++;
        }
        else factor++;
    }
    return(0);
}
int isprime(int n)
{
    int m=2;
    while(m<n)
    {
        if(n%m) ; /*if n can be divided evently by m ,then n%m==0*/
        else return(0);
        m++;
    }
    return (1);
}
