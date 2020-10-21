/*
   This program only realizes the basic translation function, 
   but does not complete the decoupling of the functional modules that described in the title
   The general idea is to divide the number into groups of three,plus "thousand" ,reuse under1000 func deal with groups.
 */
#include<stdio.h>

#define max 999999

void under10(int n);
void under100(int n);
void under1000(int n);
void under1000000(int n);

void nhundred(int n);
void nten(int n);

void main()
{
    int n;

    printf("this program reads number(postive integer)from user and output as english text,stopping when input is negative\n?");
    scanf("%d",&n);
    while(1)
    {
        if(n<0) break;
        if(n>max) 
            printf("you are too rich,how about give me some?\n");
        else under1000000(n);
        printf("\n?");
        scanf("%d",&n);
    }
}
void under10(int n)
{
    switch(n)
    {
        case 0: printf(" zero "); break;
        case 1: printf(" one "); break;
        case 2: printf(" two "); break;
        case 3: printf(" three "); break;
        case 4: printf(" four "); break;
        case 5: printf(" five "); break;
        case 6: printf(" six "); break;
        case 7: printf(" seven "); break;
        case 8: printf(" eight "); break;
        case 9: printf(" nine "); break;
        default : printf(" Illegal call to under10"); break;
    }
}
void under100(int n)
{
    if(n<10)
        under10(n);
    else if (!(n%10))
    {
      nten(n); 
    }
    else 
    {
        if (n<20)
        {
            switch(n)
            {
                case 11: printf(" eleven "); break;
                case 12: printf(" twelve "); break;
                case 13: printf(" thirteen "); break;
                case 14: printf(" fourteen "); break;
                case 15: printf(" fifteen "); break;
                case 16: printf(" sixteen "); break;
                case 17: printf(" seventeen "); break;
                case 18: printf(" eighteen "); break;
                case 19: printf(" nineteen "); break;
            }
        }
        else
        {
            nten(n-n%10);
            under10(n%10);
        }
    }
}
void under1000(int n)
{
    if(n>100)
    {
        nhundred(n-n%100);
        if(n%100)
        {
            under100(n%100);
        }
    }
    else
        under100(n);
}
void under1000000(int n)
{
    if(n>=1000)
    {
        under1000(n/1000);
        printf("thousand");
        under1000(n%1000);
    }
    else under1000(n);
}    
void nten(int n)
{
        switch(n){
        case 10: printf(" ten "); break;
        case 20: printf(" twenty "); break;
        case 30: printf(" thirty "); break;
        case 40: printf(" forty "); break;
        case 50: printf(" fifty "); break;
        case 60: printf(" sixty "); break;
        case 70: printf(" seventy "); break;
        case 80: printf(" eighty "); break;
        case 90: printf(" ninety "); break;
        }
}
void nhundred(int n)
{
        under10(n/100);
        printf("hundred");
}
